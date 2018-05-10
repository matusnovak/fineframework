/*** This file is part of FineFramework project ***/

#include "ffw/graphics/texture3d.h"
#include "ffw/graphics/rendercontext.h"

///=============================================================================
ffw::Texture3D::Texture3D(){
    textureformat = GL_TEXTURE_3D;
}

///=============================================================================
ffw::Texture3D::Texture3D(Texture3D&& other) NOEXCEPT : Texture3D() {
    Texture::swap(other);
}

///=============================================================================
ffw::Texture3D& ffw::Texture3D::operator = (ffw::Texture3D&& other) NOEXCEPT {
    if (this != &other) {
        Texture::swap(other);
    }
    return *this;
}

///=============================================================================
bool ffw::Texture3D::create(const GLsizei width, const GLsizei height, const GLsizei depth, 
    const GLenum internalformat, const GLenum format, const GLenum pixelformat, 
    const GLvoid* pixels){

    if(loaded)return false;
    loaded = true;

    glGenTextures(1, &buffer);
    glBindTexture(GL_TEXTURE_3D, buffer);

    this->width           = width;
    this->height          = height;
    this->layers          = 0;
    this->depth           = depth;
    this->internalformat  = internalformat;
    this->format          = format;
    this->pixelformat     = pixelformat;

    if(isCompressed()) {
        if(glCompressedTexImage3D == nullptr) {
            destroy();
            return false;
        }
        glCompressedTexImage3D(
            GL_TEXTURE_3D, 0, internalformat, width, height, depth, 
            0, getBlockSize(width, height, depth), pixels
        );
    } else {
        glTexImage3D(
            GL_TEXTURE_3D, 0, internalformat, width, height, depth, 
            0, format, pixelformat, pixels
        );
    }

    int test;
    glGetTexLevelParameteriv(GL_TEXTURE_3D, 0, GL_TEXTURE_WIDTH, &test);
    if(test != width){
        destroy();
        return false;
    }

    glTexParameteri(GL_TEXTURE_3D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_3D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexParameterf(GL_TEXTURE_3D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameterf(GL_TEXTURE_3D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexParameterf(GL_TEXTURE_3D, GL_TEXTURE_WRAP_R, GL_REPEAT);
    glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_BLEND);
    return true;
}

///=============================================================================
bool ffw::Texture3D::resize(const GLsizei width, const GLsizei height, const GLsizei depth,
    const GLvoid* pixels){

    if(!loaded)return false;
    this->width = width;
    this->height = height;
    this->depth = depth;
    glBindTexture(GL_TEXTURE_3D, buffer);

    if(isCompressed()) {
        glCompressedTexImage3D(
            GL_TEXTURE_3D, 0, internalformat, width, height, depth, 
            0, getBlockSize(width, height, depth), pixels
        );
    } else {
        glTexImage3D(
            GL_TEXTURE_3D, 0, internalformat, width, height, depth, 
            0, format, pixelformat, pixels
        );
    }
    return true;
}

///=============================================================================
bool ffw::Texture3D::setPixels(const GLint level, const GLint xoffset, const GLint yoffset,
    const GLint zoffset, const GLsizei width, const GLsizei height, const GLsizei depth, 
    const GLvoid* pixels){

    if(!loaded)return false;
    glBindTexture(GL_TEXTURE_3D, buffer);

    if(isCompressed()) {
        glCompressedTexSubImage3D(
            GL_TEXTURE_3D, level, xoffset, yoffset, zoffset, width, height, depth, 
            internalformat, getBlockSize(width, height, depth), pixels
        );
    } else {
        glTexSubImage3D(
            GL_TEXTURE_3D, level, xoffset, yoffset, zoffset, width, height, depth, 
            format, pixelformat, pixels
        );
    }

    return true;
}

///=============================================================================
bool ffw::Texture3D::setPixels(const GLint level, const GLvoid* pixels){
    if(!loaded)return false;
    glBindTexture(GL_TEXTURE_3D, buffer);

    const auto w = width >> level;
    const auto h = height >> level;
    const auto d = depth >> level;
    
    if(isCompressed()) {
        glCompressedTexImage3D(
            GL_TEXTURE_3D, level, internalformat, w, h, d, 
            0, getBlockSize(w, h, d), pixels
        );
    } else {
        glTexImage3D(
            GL_TEXTURE_3D, level, internalformat, w, h, d, 
            0, format, pixelformat, pixels
        );
    }
    return true;
}

///=============================================================================
bool ffw::Texture3D::getPixels(GLvoid* pixels){
    if(!loaded)return false;
    glBindTexture(GL_TEXTURE_3D, buffer);
    glGetTexImage(GL_TEXTURE_3D, 0, format, pixelformat, pixels);
    return true;
}