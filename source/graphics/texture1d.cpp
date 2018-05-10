/*** This file is part of FineFramework project ***/

#include "ffw/graphics/texture1d.h"
#include "ffw/graphics/rendercontext.h"
#include "ffw/math/imagebuffer.h"
#include "ffw/graphics/graphics.h"

///=============================================================================
ffw::Texture1D::Texture1D(){
    textureformat = GL_TEXTURE_1D;
}

///=============================================================================
ffw::Texture1D::Texture1D(Texture1D&& other) NOEXCEPT : Texture1D() {
    Texture::swap(other);
}

///=============================================================================
ffw::Texture1D& ffw::Texture1D::operator = (ffw::Texture1D&& other) NOEXCEPT {
    if (this != &other) {
        Texture::swap(other);
    }
    return *this;
}

///=============================================================================
bool ffw::Texture1D::create(const GLsizei width, const GLenum internalformat, const GLenum format, 
    const GLenum pixelformat, const GLvoid* pixels){

    if(loaded)return false;
    loaded = true;

    glGenTextures(1, &buffer);
    glBindTexture(GL_TEXTURE_1D, buffer);

    this->width           = width;
    this->height          = 1;
    this->layers          = 0;
    this->depth           = 0;
    this->internalformat  = internalformat;
    this->format          = format;
    this->pixelformat     = pixelformat;
    this->samples         = 0;

    if(isCompressed()) {
        if(glCompressedTexImage1D == nullptr) {
            destroy();
            return false;
        }
        glCompressedTexImage1D(
            GL_TEXTURE_2D, 0, internalformat, 
            width, 0, getBlockSize(width), pixels
        );
    } else {
        glTexImage1D(GL_TEXTURE_1D, 0, internalformat, width, 0, format, pixelformat, pixels);
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
bool ffw::Texture1D::resize(const GLsizei width, const GLvoid* pixels){
    if(!loaded)return false;
    if(width <= 0)return false;
    this->width = width;
    glBindTexture(GL_TEXTURE_1D, buffer);
    if(isCompressed()) {
        glCompressedTexImage1D(
            GL_TEXTURE_2D, 0, internalformat, 
            width, 0, getBlockSize(width), pixels
        );
    } else {
        glTexImage1D(
            GL_TEXTURE_1D, 0, internalformat, 
            width, 0, format, pixelformat, pixels
        );
    }
    return true;
}

///=============================================================================
bool ffw::Texture1D::setPixels(const GLint level, const GLint xoffset, 
    const GLsizei width, const GLvoid* pixels){

    if(!loaded)return false;
    glBindTexture(GL_TEXTURE_1D, buffer);
    if(isCompressed()) {
        glCompressedTexSubImage1D(
            GL_TEXTURE_2D, level, xoffset, width, 
            internalformat, getBlockSize(width), pixels
        );
    } else {
        glTexSubImage1D(GL_TEXTURE_1D, level, xoffset, width, format, pixelformat, pixels);
    }
    return true;
}

///=============================================================================
bool ffw::Texture1D::setPixels(const GLint level, const GLvoid* pixels){
    if(!loaded)return false;
    glBindTexture(GL_TEXTURE_1D, buffer);

    const auto w = width >> level;

    if(isCompressed()) {
        glCompressedTexImage1D(GL_TEXTURE_2D, level, internalformat, w, 0, getBlockSize(w), pixels);
    } else {
        glTexImage1D(GL_TEXTURE_1D, level, internalformat, w, 0, format, pixelformat, pixels);
    }
    return true;
}

///=============================================================================
bool ffw::Texture1D::getPixels(void* pixels) const {
    if(!loaded)return false;
    glBindTexture(GL_TEXTURE_1D, buffer);
    glGetTexImage(GL_TEXTURE_1D, 0, format, pixelformat, pixels);
    return true;
}

///=============================================================================
bool ffw::Texture1D::createFromBuffer(const ImageBuffer& image) {
    if (!image.isAllocated())return false;
    if (image.getDepth() > 1 || image.getHeight() > 1)return false;

    const auto openglType = ffw::getOpenGLImageType(image.getImageType());
    if (!openglType) {
        return false;
    }

    if (create(image.getWidth(), openglType.internalFormat, openglType.format, openglType.type)) {
        for(int m = 0; m <= image.getNumOfMipMaps()-1; m++) {
            
            if(!setPixels(m, image.getMipMapPtr(m))) {
                return false;
            }
        }

        if(image.getNumOfMipMaps() > 0) {
            glTexParameteri(GL_TEXTURE_1D, GL_TEXTURE_BASE_LEVEL, 0);
            glTexParameteri(GL_TEXTURE_1D, GL_TEXTURE_MAX_LEVEL, image.getNumOfMipMaps()-1);
        }
    } else {
        return false;
    }

    return true;
}
