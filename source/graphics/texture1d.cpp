/*** This file is part of FineFramework project ***/

#include "ffw/graphics/texture1d.h"
#include "ffw/graphics/rendercontext.h"
#include <ffw/graphics.h>

///=============================================================================
ffw::Texture1D::Texture1D():Texture(){
    textureformat_ = GL_TEXTURE_1D;
}

///=============================================================================
ffw::Texture1D::Texture1D(Texture1D&& second) : Texture1D() {
    Texture::swap(second);
}

///=============================================================================
ffw::Texture1D& ffw::Texture1D::operator = (ffw::Texture1D&& other) {
    if (this != &other) {
        Texture::swap(other);
    }
    return *this;
}

///=============================================================================
ffw::Texture1D::~Texture1D(){
    destroy();
}

///=============================================================================
bool ffw::Texture1D::create(GLsizei width, GLenum internalformat, GLenum format, GLenum pixelformat, const GLvoid* pixels){
    if(loaded_)return false;
    loaded_ = true;

    glGenTextures(1, &buffer_);
    glBindTexture(GL_TEXTURE_1D, buffer_);

    width_           = width;
    height_          = 1;
    layers_          = 0;
    depth_           = 0;
    internalformat_  = internalformat;
    format_          = format;
    pixelformat_     = pixelformat;
    samples_         = 0;

    if(isCompressed()) {
        if(glCompressedTexImage1D == NULL) {
            destroy();
            return false;
        }
        glCompressedTexImage1D(GL_TEXTURE_2D, 0, internalformat_, width_, 0, getBlockSize(width), pixels);
    } else {
        glTexImage1D(GL_TEXTURE_1D, 0, internalformat_, width_, 0, format_, pixelformat_, pixels);
    }

    int test;
    glGetTexLevelParameteriv(GL_TEXTURE_1D, 0, GL_TEXTURE_WIDTH, &test);
    if(test != width){
        destroy();
        return false;
    }

    glTexParameteri(GL_TEXTURE_1D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_1D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexParameterf(GL_TEXTURE_1D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameterf(GL_TEXTURE_1D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_BLEND);
    return true;
}

///=============================================================================
bool ffw::Texture1D::resize(GLsizei width){
    if(!loaded_)return false;
    if(width <= 0)return false;
    width_ = width;
    glBindTexture(GL_TEXTURE_1D, buffer_);
    if(isCompressed()) {
        glCompressedTexImage1D(GL_TEXTURE_2D, 0, internalformat_, width_, 0, getBlockSize(width), NULL);
    } else {
        glTexImage1D(GL_TEXTURE_1D, 0, internalformat_, width_, 0, format_, pixelformat_, NULL);
    }
    return true;
}

///=============================================================================
bool ffw::Texture1D::setPixels(GLint level, GLint xoffset, GLsizei width, const GLvoid* pixels){
    if(!loaded_)return false;
    glBindTexture(GL_TEXTURE_1D, buffer_);
    if(isCompressed()) {
        glCompressedTexSubImage1D(GL_TEXTURE_2D, level, xoffset, width_, internalformat_, getBlockSize(width_), pixels);
    } else {
        glTexSubImage1D(GL_TEXTURE_1D, level, xoffset, width, format_, pixelformat_, pixels);
    }
    return true;
}

///=============================================================================
bool ffw::Texture1D::setPixels(GLint level, const GLvoid* pixels){
    if(!loaded_)return false;
    glBindTexture(GL_TEXTURE_1D, buffer_);

    auto w = width_ >> level;

    if(isCompressed()) {
        glCompressedTexImage1D(GL_TEXTURE_2D, level, internalformat_, w, 0, getBlockSize(w), pixels);
    } else {
        glTexImage1D(GL_TEXTURE_1D, level, internalformat_, w, 0, format_, pixelformat_, pixels);
    }
    return true;
}

///=============================================================================
bool ffw::Texture1D::getPixels(void* pixels) const {
    if(!loaded_)return false;
    glBindTexture(GL_TEXTURE_1D, buffer_);
    glGetTexImage(GL_TEXTURE_1D, 0, format_, pixelformat_, pixels);
    return true;
}

///=============================================================================
bool ffw::Texture1D::createFromBuffer(const ImageBuffer& buffer) {
    if (!buffer.isAllocated())return false;
    if (buffer.getDepth() > 1 || buffer.getHeight() > 1)return false;

    ffw::OpenGLImageType openglType = ffw::getOpenGLImageType(buffer.getImageType());
    if (!openglType) {
        return false;
    }

    if (create(buffer.getWidth(), openglType.internalFormat, openglType.format, openglType.type)) {
        for(int m = 0; m <= buffer.getNumOfMipMaps()-1; m++) {
            
            if(!setPixels(m, buffer.getMipMapPtr(m))) {
                return false;
            }
        }

        if(buffer.getNumOfMipMaps() > 0) {
            glTexParameteri(GL_TEXTURE_1D, GL_TEXTURE_BASE_LEVEL, 0);
            glTexParameteri(GL_TEXTURE_1D, GL_TEXTURE_MAX_LEVEL, buffer.getNumOfMipMaps()-1);
        }
    } else {
        return false;
    }

    return true;
}
