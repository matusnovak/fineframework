/*** This file is part of FineFramework project ***/

#include "ffw/graphics/texture1darray.h"
#include "ffw/graphics/rendercontext.h"

///=============================================================================
ffw::Texture1DArray::Texture1DArray(){
    textureformat   = GL_TEXTURE_1D_ARRAY;
}

///=============================================================================
ffw::Texture1DArray::Texture1DArray(Texture1DArray&& other) NOEXCEPT {
    Texture::swap(other);
}

///=============================================================================
ffw::Texture1DArray& ffw::Texture1DArray::operator = (ffw::Texture1DArray&& other) NOEXCEPT {
    if (this != &other) {
        Texture::swap(other);
    }
    return *this;
}

///=============================================================================
bool ffw::Texture1DArray::create(const GLsizei width, const GLsizei layers, 
    const GLenum internalformat, const GLenum format, const GLenum pixelformat, 
    const GLvoid* pixels){

    if(loaded)return false;
    loaded = true;

    glGenTextures(1, &buffer);
    glBindTexture(GL_TEXTURE_1D_ARRAY, buffer);

    this->width           = width;
    this->height          = 1;
    this->layers          = layers;
    this->depth           = 0;
    this->internalformat  = internalformat;
    this->format          = format;
    this->pixelformat     = pixelformat;
    this->samples         = 0;

    if(isCompressed()) {
        if(glCompressedTexImage2D == nullptr) {
            destroy();
            return false;
        }
        glCompressedTexImage2D(
            GL_TEXTURE_1D_ARRAY, 0, internalformat, width, layers, 0, 
            getBlockSize(width, layers), pixels
        );
    } else {
        glTexImage2D(
            GL_TEXTURE_1D_ARRAY, 0, internalformat, width, layers, 0, 
            format, pixelformat, pixels
        );
    }

    int test;
    glGetTexLevelParameteriv(GL_TEXTURE_1D_ARRAY, 0, GL_TEXTURE_WIDTH, &test);
    if(test != width){
        destroy();
        return false;
    }

    glTexParameteri(GL_TEXTURE_1D_ARRAY, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_1D_ARRAY, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexParameterf(GL_TEXTURE_1D_ARRAY, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameterf(GL_TEXTURE_1D_ARRAY, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_BLEND);
    return true;
}

///=============================================================================
bool ffw::Texture1DArray::resize(const GLsizei width, const GLsizei layers, const GLvoid* pixels){
    if(!loaded)return false;
    this->width = width;
    this->layers = layers;
    glBindTexture(GL_TEXTURE_1D_ARRAY, buffer);
    if (isCompressed()) {
        if (glCompressedTexImage2D == nullptr) return false;
        glCompressedTexImage2D(
            GL_TEXTURE_1D_ARRAY, 0, internalformat, width, layers, 0,
            getBlockSize(width, layers), pixels
        );
    }
    else {
        glTexImage2D(
            GL_TEXTURE_1D_ARRAY, 0, internalformat, width, layers, 0,
            format, pixelformat, pixels
        );
    }
    return true;
}

///=============================================================================
bool ffw::Texture1DArray::setPixels(const GLint level, const GLint xoffset, const GLint loffset, 
    const GLsizei width, const GLvoid* pixels){

    if(!loaded)return false;
    glBindTexture(GL_TEXTURE_1D_ARRAY, buffer);
    if(isCompressed()) {
        glCompressedTexSubImage2D(
            GL_TEXTURE_1D_ARRAY, level, xoffset, loffset, width, 1, 
            internalformat, getBlockSize(width, 1), pixels
        );
    } else {
        glTexSubImage2D(
            GL_TEXTURE_1D_ARRAY, level, xoffset, loffset, width, 1, 
            format, pixelformat, pixels
        );
    }
    return true;
}

///=============================================================================
bool ffw::Texture1DArray::setPixels(const GLint level, const GLvoid* pixels){
    if(!loaded)return false;
    glBindTexture(GL_TEXTURE_1D_ARRAY, buffer);
    if(isCompressed()) {
        glCompressedTexImage2D(
            GL_TEXTURE_1D_ARRAY, level, internalformat, width, layers, 
            0, getBlockSize(width, layers), pixels
        );
    } else {
        glTexImage2D(
            GL_TEXTURE_1D_ARRAY, level, internalformat, width, layers, 
            0, format, pixelformat, pixels
        );
    }
    return true;
}

///=============================================================================
bool ffw::Texture1DArray::getPixels(GLvoid* pixels) const {
    if(!loaded)return false;
    glBindTexture(GL_TEXTURE_1D_ARRAY, buffer);
    glGetTexImage(GL_TEXTURE_1D_ARRAY, 0, format, pixelformat, pixels);
    return true;
}