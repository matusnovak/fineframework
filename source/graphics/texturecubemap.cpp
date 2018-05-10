/*** This file is part of FineFramework project ***/

#include "ffw/graphics/texturecubemap.h"
#include "ffw/graphics/rendercontext.h"
#include "ffw/math/imagebuffer.h"
#include "ffw/graphics/graphics.h"

///=============================================================================
ffw::TextureCubemap::TextureCubemap(){
    textureformat = GL_TEXTURE_CUBE_MAP;
}

///=============================================================================
ffw::TextureCubemap::TextureCubemap(TextureCubemap&& other) NOEXCEPT : TextureCubemap() {
    Texture::swap(other);
}

///=============================================================================
ffw::TextureCubemap& ffw::TextureCubemap::operator = (ffw::TextureCubemap&& other) NOEXCEPT {
    if (this != &other) {
        Texture::swap(other);
    }
    return *this;
}

///=============================================================================
bool ffw::TextureCubemap::create(const GLsizei width, const GLsizei height, 
    const GLenum internalformat, const GLenum format, const GLenum pixelformat, 
    const GLvoid* pixels){

    if(loaded)return false;
    loaded = true;

    glGenTextures(1, &buffer);
    glBindTexture(GL_TEXTURE_CUBE_MAP, buffer);

    this->width           = width;
    this->height          = height;
    this->layers          = 0;
    this->depth           = 0;
    this->internalformat  = internalformat;
    this->format          = format;
    this->pixelformat     = pixelformat;
    this->samples         = 0;

    if(isCompressed() && glCompressedTexImage2D == nullptr) {
        destroy();
        return false;
    }

    for (auto i = 0; i < 6; i++) {
        if(isCompressed()) {
            glCompressedTexImage2D(
                GL_TEXTURE_CUBE_MAP_POSITIVE_X + i, 0, internalformat, width, 
                height, 0, getBlockSize(width, height), pixels
            );
        } else {
            glTexImage2D(
                GL_TEXTURE_CUBE_MAP_POSITIVE_X + i, 0, internalformat, width, 
                height, 0, format, pixelformat, pixels
            );
        }

        int test;
        glGetTexLevelParameteriv(GL_TEXTURE_CUBE_MAP_POSITIVE_X + i, 0, GL_TEXTURE_WIDTH, &test);
        if(test != width){
            destroy();
            return false;
        }
    }

    glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexParameterf(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
    glTexParameterf(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
    glTexParameterf(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_R, GL_CLAMP_TO_EDGE);
    glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_BLEND);
    return true;
}

///=============================================================================
bool ffw::TextureCubemap::resize(const GLsizei width, const GLsizei height){
    if(!loaded)return false;
    if(width <= 0)return false;
    this->width = width;
    this->height = height;
    glBindTexture(GL_TEXTURE_CUBE_MAP, buffer);
    for (auto i = 0; i < 6; i++) {
        if(isCompressed()) {
            glCompressedTexImage2D(
                GL_TEXTURE_CUBE_MAP_POSITIVE_X + i, 0, internalformat, 
                width, height, 0, getBlockSize(width, height), nullptr
            );
        } else {
            glTexImage2D(
                GL_TEXTURE_CUBE_MAP_POSITIVE_X + i, 0, internalformat, 
                width, height, 0, format, pixelformat, nullptr
            );
        }
    }
    return true;
}

///=============================================================================
bool ffw::TextureCubemap::setPixels(const GLint level, const GLint side, const GLvoid* pixels) {
    if(!loaded)return false;
    glBindTexture(GL_TEXTURE_CUBE_MAP, buffer);

    setPixelsInternal(level, side, pixels);
    return true;
}

///=============================================================================
void ffw::TextureCubemap::setPixelsInternal(const GLint level, const GLint side, 
    const GLvoid* pixels) {

    const auto w = width >> level;
    const auto h = height >> level;

    if (isCompressed()) {
        glCompressedTexImage2D(
            GL_TEXTURE_CUBE_MAP_POSITIVE_X + side, level, internalformat,
            w, h, 0, getBlockSize(w, h), pixels
        );
    }
    else {
        glTexImage2D(
            GL_TEXTURE_CUBE_MAP_POSITIVE_X + side, level, internalformat,
            w, h, 0, format, pixelformat, pixels
        );
    }
}

///=============================================================================
bool ffw::TextureCubemap::setPixels(const GLint level, const GLint xoffset, const GLint yoffset, 
    const GLsizei width, const GLsizei height, const GLint side, const GLvoid* pixels){

    if(!loaded)return false;
    if (side < 0 || side >= 6)return false;
    glBindTexture(GL_TEXTURE_CUBE_MAP, buffer);

    setPixelsInternal(level, xoffset, yoffset, width, height, side, pixels);
    return true;
}

///=============================================================================
void ffw::TextureCubemap::setPixelsInternal(const GLint level, const GLint xoffset, 
    const GLint yoffset, const GLsizei width, const GLsizei height, const GLint side, 
    const GLvoid* pixels) {

    if (isCompressed()) {
        glCompressedTexSubImage2D(
            GL_TEXTURE_CUBE_MAP_POSITIVE_X + side, level, xoffset, yoffset, width,
            height, internalformat, getBlockSize(width, height), pixels
        );
    }
    else {
        glTexSubImage2D(
            GL_TEXTURE_CUBE_MAP_POSITIVE_X + side, level, xoffset, yoffset, width,
            height, format, pixelformat, pixels
        );
    }
}

///=============================================================================
bool ffw::TextureCubemap::setFromBuffer(const ImageBuffer& image, const GLint side, 
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
                if (m != 0)setPixelsInternal(m, side, nullptr); // Create mipmap
                for (auto i = 0; i < image.getHeight(m); i++) {
                    const auto ptr = &image.getMipMapPtr(m)[image.getStrideSize(m) * i];
                    setPixelsInternal(
                        m, 0, image.getHeight(m) - i - 1, 
                        image.getWidth(m), 1, side, ptr
                    );
                }
            }
            else {
                if (m != 0)setPixelsInternal(m, side, nullptr); // Create mipmap
                setPixelsInternal(
                    m, 0, 0, image.getWidth(m), image.getHeight(m), 
                    side, image.getMipMapPtr(m)
                );
            }
        }

        if(image.getNumOfMipMaps() > 0) {
            glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_BASE_LEVEL, 0);
            glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_MAX_LEVEL, image.getNumOfMipMaps()-1);
        }
    } else {
        return false;
    }

    return true;
}

///=============================================================================
bool ffw::TextureCubemap::getPixels(GLvoid* pixels){
    if(!loaded)return false;
    glBindTexture(GL_TEXTURE_CUBE_MAP, buffer);
    glGetTexImage(GL_TEXTURE_CUBE_MAP, 0, format, pixelformat, pixels);
    return true;
}
