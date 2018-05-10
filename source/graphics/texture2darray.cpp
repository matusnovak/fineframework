/*** This file is part of FineFramework project ***/

#include "ffw/graphics/texture2darray.h"
#include "ffw/graphics/rendercontext.h"
#include "ffw/math/imagebuffer.h"
#include "ffw/graphics/graphics.h"

///=============================================================================
ffw::Texture2DArray::Texture2DArray() {
    textureformat = GL_TEXTURE_2D_ARRAY;
}

///=============================================================================
ffw::Texture2DArray::Texture2DArray(Texture2DArray&& other) NOEXCEPT {
    Texture::swap(other);
}

///=============================================================================
ffw::Texture2DArray& ffw::Texture2DArray::operator = (ffw::Texture2DArray&& other) NOEXCEPT {
    if (this != &other) {
        Texture::swap(other);
    }
    return *this;
}

///=============================================================================
bool ffw::Texture2DArray::create(const GLsizei width, const GLsizei height, const GLsizei layers,
    const GLenum internalformat, const GLenum format, const GLenum pixelformat, 
    const GLvoid* pixels){

    if(loaded)return false;
    loaded = true;

    glGenTextures(1, &buffer);
    glBindTexture(GL_TEXTURE_2D_ARRAY, buffer);

    this->width           = width;
    this->height          = height;
    this->layers          = layers;
    this->depth           = 0;
    this->internalformat  = internalformat;
    this->format          = format;
    this->pixelformat     = pixelformat;
    this->samples         = 0;

    if (isCompressed()) {
        if (glCompressedTexImage3D == nullptr) {
            destroy();
            return false;
        }
        glCompressedTexImage3D(
            GL_TEXTURE_2D_ARRAY, 0, internalformat, width, height, layers, 0,
            getBlockSize(width, height, layers), pixels
        );
    } else {
        glTexImage3D(
            GL_TEXTURE_2D_ARRAY, 0, internalformat, width, height, layers, 0, 
            format, pixelformat, pixels
        );
    }

    int test;
    glGetTexLevelParameteriv(GL_TEXTURE_2D_ARRAY, 0, GL_TEXTURE_WIDTH, &test);
    if(test != width){
        destroy();
        return false;
    }

    glTexParameteri(GL_TEXTURE_2D_ARRAY, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D_ARRAY, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexParameterf(GL_TEXTURE_2D_ARRAY, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameterf(GL_TEXTURE_2D_ARRAY, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_BLEND);
    return true;
}

///=============================================================================
bool ffw::Texture2DArray::resize(const GLsizei width, const GLsizei height,
    const GLsizei layers, const GLvoid* pixels){

    if(!loaded)return false;
    this->width = width;
    this->height = height;
    this->layers = layers;
    glBindTexture(GL_TEXTURE_2D_ARRAY, buffer);

    if(isCompressed()) {
        glCompressedTexImage3D(
            GL_TEXTURE_2D_ARRAY, 0, internalformat, width, height, layers, 0, 
            getBlockSize(width, height, layers), pixels
        );
    } else {
        glTexImage3D(
            GL_TEXTURE_2D_ARRAY, 0, internalformat, width, height, layers, 0,
            format, pixelformat, pixels
        );
    }
    return true;
}

///=============================================================================
bool ffw::Texture2DArray::setPixels(const GLint level, const GLint xoffset, const GLint yoffset, 
    const GLint loffset, const GLsizei width, const GLsizei height, const GLvoid* pixels){

    if(!loaded)return false;

    glBindTexture(GL_TEXTURE_2D_ARRAY, buffer);

    if(isCompressed()) {
        glCompressedTexSubImage3D(
            GL_TEXTURE_2D_ARRAY, level, xoffset, yoffset, loffset, width, height, 
            1, internalformat, getBlockSize(width, height, 1), pixels
        );
    } else {
        glTexSubImage3D(
            GL_TEXTURE_2D_ARRAY, level, xoffset, yoffset, loffset, width, height, 
            1, format, pixelformat, pixels
        );
    }

    return true;
}

///=============================================================================
void ffw::Texture2DArray::setPixelsInternal(const GLint level, const GLint xoffset, 
    const GLint yoffset, const GLint loffset, const GLsizei width, 
    const GLsizei height, const GLvoid* pixels) {

    if (isCompressed()) {
        glCompressedTexSubImage3D(
            GL_TEXTURE_2D_ARRAY, level, xoffset, yoffset, loffset, width, height,
            1, internalformat, getBlockSize(width, height, 1), pixels
        );
    }
    else {
        glTexSubImage3D(
            GL_TEXTURE_2D_ARRAY, level, xoffset, yoffset, loffset, width, height,
            1, format, pixelformat, pixels
        );
    }
}

///=============================================================================
bool ffw::Texture2DArray::setPixels(const GLint level, const GLvoid* pixels){
    if(!loaded)return false;
    glBindTexture(GL_TEXTURE_2D_ARRAY, buffer);

    const auto w = width >> level;
    const auto h = height >> level;

    if(isCompressed()) {
        glCompressedTexImage3D(
            GL_TEXTURE_2D_ARRAY, level, internalformat, w, h, layers, 0, 
            getBlockSize(w, h, layers), pixels
        );
    } else {
        glTexImage3D(
            GL_TEXTURE_2D_ARRAY, level, internalformat, w, h, layers, 0, 
            format, pixelformat, pixels
        );
    }

    return true;
}

///=============================================================================
void ffw::Texture2DArray::setPixelsInternal(const GLint level, const GLvoid* pixels) {
    const auto w = width >> level;
    const auto h = height >> level;

    if (isCompressed()) {
        glCompressedTexImage3D(
            GL_TEXTURE_2D_ARRAY, level, internalformat, w, h, layers, 0,
            getBlockSize(w, h, layers), pixels
        );
    }
    else {
        glTexImage3D(
            GL_TEXTURE_2D_ARRAY, level, internalformat, w, h, layers, 0,
            format, pixelformat, pixels
        );
    }
}

///=============================================================================
bool ffw::Texture2DArray::getPixels(GLvoid* pixels) const {
    if(!loaded)return false;
    glBindTexture(GL_TEXTURE_2D_ARRAY, buffer);
    glGetTexImage(GL_TEXTURE_2D_ARRAY, 0, format, pixelformat, pixels);
    return true;
}

///=============================================================================
bool ffw::Texture2DArray::setFromBuffer(const ImageBuffer& image, const GLint layer, 
    const bool inverse) {

    if (!image.isAllocated())return false;
    if (image.getDepth() > 1)return false;

    const auto openglType = ffw::getOpenGLImageType(image.getImageType());
    if (!openglType) {
        return false;
    }

    if (image.isCompressed() && inverse)return false;

    if (isCreated()) {
        for(auto m = 0; m <= image.getNumOfMipMaps()-1; m++) {
            
            if(inverse) {
                if (m != 0)setPixelsInternal(m, nullptr); // Create mipmap
                for (auto i = 0; i < image.getHeight(m); i++) {
                    const auto ptr = &image.getMipMapPtr(m)[image.getStrideSize(m) * i];
                    setPixelsInternal(
                        m, 0, image.getHeight(m) - i - 1,
                        layer, image.getWidth(m), 1, ptr);
                }
            }
            else {
                setPixelsInternal(
                    m, 0, 0, layer, image.getWidth(m),
                    image.getHeight(m), image.getMipMapPtr(m));
            }
        }

        if(image.getNumOfMipMaps() > 0) {
            glTexParameteri(GL_TEXTURE_2D_ARRAY, GL_TEXTURE_BASE_LEVEL, 0);
            glTexParameteri(GL_TEXTURE_2D_ARRAY, GL_TEXTURE_MAX_LEVEL, image.getNumOfMipMaps()-1);
        }
    } else {
        return false;
    }

    return true;
}