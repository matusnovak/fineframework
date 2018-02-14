/*** This file is part of FineFramework project ***/

#include "ffw/graphics/texture3d.h"
#include "ffw/graphics/rendercontext.h"

///=============================================================================
ffw::Texture3D::Texture3D():Texture(){
    textureformat_ = GL_TEXTURE_3D;
}

///=============================================================================
ffw::Texture3D::Texture3D(Texture3D&& second) : Texture3D() {
    Texture::swap(second);
}

///=============================================================================
ffw::Texture3D& ffw::Texture3D::operator = (ffw::Texture3D&& other) {
    if (this != &other) {
        Texture::swap(other);
    }
    return *this;
}

///=============================================================================
ffw::Texture3D::~Texture3D(){
}

///=============================================================================
bool ffw::Texture3D::create(GLsizei width, GLsizei height, GLsizei depth, GLenum internalformat, GLenum format, GLenum pixelformat, const GLvoid* pixels){
    if(loaded_)return false;
    loaded_ = true;

    glGenTextures(1, &buffer_);
    glBindTexture(GL_TEXTURE_3D, buffer_);

    width_           = width;
    height_          = height;
    layers_          = 0;
    depth_           = depth;
    internalformat_  = internalformat;
    format_          = format;
    pixelformat_     = pixelformat;

    if(isCompressed()) {
        if(glCompressedTexImage3D == NULL) {
            destroy();
            return false;
        }
        glCompressedTexImage3D(GL_TEXTURE_3D, 0, internalformat_, width_, height_, depth_, 0, getBlockSize(width, height, depth), pixels);
    } else {
        glTexImage3D(GL_TEXTURE_3D, 0, internalformat_, width_, height_, depth_, 0, format_, pixelformat_, pixels);
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
bool ffw::Texture3D::resize(GLsizei width, GLsizei height, GLsizei depth){
    if(!loaded_)return false;
    width_ = width;
    height_ = height;
    depth_ = depth;
    glBindTexture(GL_TEXTURE_3D, buffer_);

    if(isCompressed()) {
        glCompressedTexImage3D(GL_TEXTURE_3D, 0, internalformat_, width_, height_, depth_, 0, getBlockSize(width, height, depth), NULL);
    } else {
        glTexImage3D(GL_TEXTURE_3D, 0, internalformat_, width_, height_, depth_, 0, format_, pixelformat_, NULL);
    }
    return true;
}

///=============================================================================
bool ffw::Texture3D::setPixels(GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, const void* pixels){
    if(!loaded_)return false;
    glBindTexture(GL_TEXTURE_3D, buffer_);

    if(isCompressed()) {
        glCompressedTexSubImage3D(GL_TEXTURE_3D, level, xoffset, yoffset, zoffset, width, height, depth, internalformat_, getBlockSize(width, height, depth), pixels);
    } else {
        glTexSubImage3D(GL_TEXTURE_3D, level, xoffset, yoffset, zoffset, width, height, depth, format_, pixelformat_, pixels);
    }

    return true;
}

///=============================================================================
bool ffw::Texture3D::setPixels(GLint level, const GLvoid* pixels){
    if(!loaded_)return false;
    glBindTexture(GL_TEXTURE_3D, buffer_);

    auto w = width_ >> level;
    auto h = height_ >> level;
    auto d = depth_ >> level;
    
    if(isCompressed()) {
        glCompressedTexImage3D(GL_TEXTURE_3D, level, internalformat_, w, h, d, 0, getBlockSize(w, h, d), pixels);
    } else {
        glTexImage3D(GL_TEXTURE_3D, level, internalformat_, w, h, d, 0, format_, pixelformat_, pixels);
    }
    return true;
}

///=============================================================================
bool ffw::Texture3D::getPixels(void* pixels){
    if(!loaded_)return false;
    glBindTexture(GL_TEXTURE_3D, buffer_);
    glGetTexImage(GL_TEXTURE_3D, 0, format_, pixelformat_, pixels);
    return true;
}