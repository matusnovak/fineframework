/*** This file is part of FineFramework project ***/

#include "ffw/graphics/texture2d.h"
#include "ffw/graphics/rendercontext.h"
#include "ffw/graphics/graphics.h"

///=============================================================================
ffw::Texture2D::Texture2D():Texture(){
    textureformat_ = GL_TEXTURE_2D;
}

///=============================================================================
ffw::Texture2D::Texture2D(Texture2D&& second):Texture2D() {
    Texture::swap(second);
}

///=============================================================================
ffw::Texture2D& ffw::Texture2D::operator = (ffw::Texture2D&& other){
    if(this != &other) {
        Texture::swap(other);
    }
    return *this;
}

///=============================================================================
ffw::Texture2D::~Texture2D(){
}

///=============================================================================
bool ffw::Texture2D::create(GLsizei width, GLsizei height, GLenum internalformat, GLenum format, GLenum pixelformat, const GLvoid* data){
    if(loaded_)return false;
    loaded_ = true;

    glGenTextures(1, &buffer_);
    glBindTexture(GL_TEXTURE_2D, buffer_);

    width_           = width;
    height_          = height;
    layers_          = 0;
    depth_           = 0;
    internalformat_  = internalformat;
    format_          = format;
    pixelformat_     = pixelformat;
    samples_         = 0;

    if (width % 2 != 0) {
        glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
        glPixelStorei(GL_PACK_ALIGNMENT, 1);
    }

    if(isCompressed()) {
        if(glCompressedTexImage2D == NULL) {
            destroy();
            return false;
        }
        glCompressedTexImage2D(GL_TEXTURE_2D, 0, internalformat_, width_, height_, 0, getBlockSize(width, height), data);
    } else {
        glTexImage2D(GL_TEXTURE_2D, 0, internalformat_, width_, height_, 0, format_, pixelformat_, data);
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
    glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE); // GL_MODULATE
    return true;
}

///=============================================================================
bool ffw::Texture2D::resize(GLsizei width, GLsizei height){
    if(!loaded_)return false;
    width_ = width;
    height_ = height;
    glBindTexture(GL_TEXTURE_2D, buffer_);

    if(isCompressed()) {
        glCompressedTexImage2D(GL_TEXTURE_2D, 0, internalformat_, width_, height_, 0, getBlockSize(width, height), NULL);
    } else {
        glTexImage2D(GL_TEXTURE_2D, 0, internalformat_, width_, height_, 0, format_, pixelformat_, NULL);
    }
    return true;
}

///=============================================================================
bool ffw::Texture2D::setPixels(GLint level, const void* pixels) {
    if(!loaded_)return false;
    glBindTexture(GL_TEXTURE_2D, buffer_);

    auto w = width_ >> level;
    auto h = height_ >> level;

    if (isCompressed()) {
        glCompressedTexImage2D(GL_TEXTURE_2D, level, internalformat_, w, h, 0, getBlockSize(w, h), pixels);
    } else {
        glTexImage2D(GL_TEXTURE_2D, level, internalformat_, w, h, 0, format_, pixelformat_, pixels);
    }
    return true;
}

///=============================================================================
bool ffw::Texture2D::setPixels(GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, const void* pixels){
    if(!loaded_)return false;
    glBindTexture(GL_TEXTURE_2D, buffer_);

    if (isCompressed()) {
        glCompressedTexSubImage2D(GL_TEXTURE_2D, level, xoffset, yoffset, width, height, internalformat_, getBlockSize(width, height), pixels);
    } else {
        glTexSubImage2D(GL_TEXTURE_2D, level, xoffset, yoffset, width, height, format_, pixelformat_, pixels);
    }
    return true;
}

///=============================================================================
bool ffw::Texture2D::getPixels(void* pixels) const {
    if(!loaded_)return false;
    glBindTexture(GL_TEXTURE_2D, buffer_);
    glGetTexImage(GL_TEXTURE_2D, 0, format_, pixelformat_, pixels);
    return true;
}

///=============================================================================
bool ffw::Texture2D::createFromBuffer(const ImageBuffer& buffer, bool inverse) {
    if (!buffer.isAllocated())return false;
    if (buffer.getDepth() > 1)return false;

    ffw::OpenGLImageType openglType = ffw::getOpenGLImageType(buffer.getImageType());
    if (!openglType) {
        return false;
    }

    if (buffer.isCompressed() && inverse)return false;

    if (create(buffer.getWidth(), buffer.getHeight(), openglType.internalFormat, openglType.format, openglType.type)) {
        for(int m = 0; m <= buffer.getNumOfMipMaps()-1; m++) {
            
            if(inverse) {
                if (m != 0)setPixels(m, NULL); // Create mipmap
                for (int i = 0; i < buffer.getHeight(m); i++) {
                    auto ptr = &buffer.getMipMapPtr(m)[buffer.getStrideSize(m) * i];
                    if(!setPixels(m, 0, buffer.getHeight(m) - i - 1, buffer.getWidth(m), 1, ptr)) {
                        return false;
                    }
                }
            }
            else {
                if(!setPixels(m, buffer.getMipMapPtr(m))) {
                    return false;
                }
            }
        }

        if(buffer.getNumOfMipMaps() > 0) {
            glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_BASE_LEVEL, 0);
            glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAX_LEVEL, buffer.getNumOfMipMaps()-1);
        }
    } else {
        return false;
    }

    return true;
}