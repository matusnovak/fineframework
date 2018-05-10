/*** This file is part of FineFramework project ***/

#include "ffw/graphics/texture2d.h"
#include "ffw/graphics/rendercontext.h"
#include "ffw/math/imagebuffer.h"
#include "ffw/graphics/graphics.h"

///=============================================================================
ffw::Texture2D::Texture2D() {
    textureformat = GL_TEXTURE_2D;
}

///=============================================================================
ffw::Texture2D::Texture2D(Texture2D&& other) NOEXCEPT {
    Texture::swap(other);
}

///=============================================================================
ffw::Texture2D& ffw::Texture2D::operator = (ffw::Texture2D&& other) NOEXCEPT {
    if(this != &other) {
        Texture::swap(other);
    }
    return *this;
}

///=============================================================================
bool ffw::Texture2D::create(const GLsizei width, const GLsizei height, const GLenum internalformat,
    const GLenum format, const GLenum pixelformat, const GLvoid* pixels){

    if(loaded)return false;
    loaded = true;

    glGenTextures(1, &buffer);
    glBindTexture(GL_TEXTURE_2D, buffer);

    this->width           = width;
    this->height          = height;
    this->layers          = 0;
    this->depth           = 0;
    this->internalformat  = internalformat;
    this->format          = format;
    this->pixelformat     = pixelformat;
    this->samples         = 0;

    if (width % 2 != 0) {
        glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
        glPixelStorei(GL_PACK_ALIGNMENT, 1);
    }

    if(isCompressed()) {
        if(glCompressedTexImage2D == nullptr) {
            destroy();
            return false;
        }
        glCompressedTexImage2D(
            GL_TEXTURE_2D, 0, internalformat, width, height, 
            0, getBlockSize(width, height), pixels
        );
    } else {
        glTexImage2D(
            GL_TEXTURE_2D, 0, internalformat, width, height, 
            0, format, pixelformat, pixels
        );
    }

    int test;
    glGetTexLevelParameteriv(GL_TEXTURE_2D, 0, GL_TEXTURE_WIDTH, &test);
    if(test != width){
        destroy();
        return false;
    }

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
    return true;
}

///=============================================================================
bool ffw::Texture2D::resize(const GLsizei width, const GLsizei height, const GLvoid* pixels){
    if(!loaded)return false;
    this->width = width;
    this->height = height;
    glBindTexture(GL_TEXTURE_2D, buffer);

    if(isCompressed()) {
        glCompressedTexImage2D(
            GL_TEXTURE_2D, 0, internalformat, width, height, 
            0, getBlockSize(width, height), pixels
        );
    } else {
        glTexImage2D(
            GL_TEXTURE_2D, 0, internalformat, width, height, 
            0, format, pixelformat, pixels
        );
    }
    return true;
}

///=============================================================================
bool ffw::Texture2D::setPixels(const GLint level, const GLvoid* pixels) {
    if(!loaded)return false;
    glBindTexture(GL_TEXTURE_2D, buffer);

    setPixelsInternal(level, pixels);
    return true;
}

///=============================================================================
void ffw::Texture2D::setPixelsInternal(const GLint level, const GLvoid* pixels) {
    const auto w = width >> level;
    const auto h = height >> level;

    if (isCompressed()) {
        glCompressedTexImage2D(
            GL_TEXTURE_2D, level, internalformat, w, h,
            0, getBlockSize(w, h), pixels
        );
    }
    else {
        glTexImage2D(
            GL_TEXTURE_2D, level, internalformat, w, h,
            0, format, pixelformat, pixels
        );
    }
}

///=============================================================================
bool ffw::Texture2D::setPixels(const GLint level, const GLint xoffset, const GLint yoffset,
    const GLsizei width, const GLsizei height, const GLvoid* pixels){

    if(!loaded)return false;
    glBindTexture(GL_TEXTURE_2D, buffer);

    setPixelsInternal(level, xoffset, yoffset, width, height, pixels);
    return true;
}

///=============================================================================
void ffw::Texture2D::setPixelsInternal(const GLint level, const GLint xoffset, const GLint yoffset,
    const GLsizei width, const GLsizei height, const GLvoid* pixels) {

    if (isCompressed()) {
        glCompressedTexSubImage2D(
            GL_TEXTURE_2D, level, xoffset, yoffset, width, height,
            internalformat, getBlockSize(width, height), pixels
        );
    }
    else {
        glTexSubImage2D(
            GL_TEXTURE_2D, level, xoffset, yoffset, width, height,
            format, pixelformat, pixels
        );
    }
}

///=============================================================================
bool ffw::Texture2D::getPixels(void* pixels) const {
    if(!loaded)return false;
    glBindTexture(GL_TEXTURE_2D, buffer);
    glGetTexImage(GL_TEXTURE_2D, 0, format, pixelformat, pixels);
    return true;
}

///=============================================================================
bool ffw::Texture2D::createFromBuffer(const ImageBuffer& image, const bool inverse) {
    if (!image.isAllocated())return false;
    if (image.getDepth() > 1)return false;

    const auto openglType = ffw::getOpenGLImageType(image.getImageType());
    if (!openglType) {
        return false;
    }

    if (image.isCompressed() && inverse)return false;

    if (create(image.getWidth(), image.getHeight(), 
        openglType.internalFormat, openglType.format, openglType.type)) {

        for(auto m = 0; m <= image.getNumOfMipMaps()-1; m++) {
            
            if(inverse) {
                if (m != 0)setPixelsInternal(m, nullptr); // Create mipmap
                for (auto i = 0; i < image.getHeight(m); i++) {
                    const auto ptr = &image.getMipMapPtr(m)[image.getStrideSize(m) * i];
                    setPixelsInternal(m, 0, image.getHeight(m) - i - 1, image.getWidth(m), 1, ptr);
                }
            }
            else {
                setPixelsInternal(m, image.getMipMapPtr(m));
            }
        }

        if(image.getNumOfMipMaps() > 0) {
            glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_BASE_LEVEL, 0);
            glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAX_LEVEL, image.getNumOfMipMaps()-1);
        }
    } else {
        return false;
    }

    return true;
}