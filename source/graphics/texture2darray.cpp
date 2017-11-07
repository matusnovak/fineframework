/*** This file is part of FineFramework project ***/

#include "ffw/graphics/texture2darray.h"
#include "ffw/graphics/rendercontext.h"
#include <ffw/graphics.h>

///=============================================================================
bool ffw::Texture2DArray::checkCompability(const ffw::RenderContext* renderer){
	if(renderer == NULL)return false;
	const ffw::RenderExtensions* gl_ = static_cast<const RenderExtensions*>(renderer);

	return (
		gl_->glTexImage3D			!= NULL &&
		gl_->glTexSubImage3D		!= NULL
	);
}

///=============================================================================
ffw::Texture2DArray::Texture2DArray():Texture(){
    textureformat_   = GL_TEXTURE_2D_ARRAY;
}

///=============================================================================
ffw::Texture2DArray::Texture2DArray(Texture2DArray&& second) : Texture2DArray() {
	Texture::swap(second);
}

///=============================================================================
ffw::Texture2DArray& ffw::Texture2DArray::operator = (ffw::Texture2DArray&& other) {
	if (this != &other) {
		Texture::swap(other);
	}
	return *this;
}

///=============================================================================
ffw::Texture2DArray::~Texture2DArray(){
}

///=============================================================================
bool ffw::Texture2DArray::create(const ffw::RenderContext* renderer, GLsizei width, GLsizei height, GLsizei layers, GLenum internalformat, GLenum format, GLenum pixelformat, const GLvoid* pixels){
    if(loaded_)return false;
	if(!checkCompability(renderer))return false;
	loaded_ = true;
    gl_ = static_cast<const RenderExtensions*>(renderer);

    glGenTextures(1, &buffer_);
    glBindTexture(GL_TEXTURE_2D_ARRAY, buffer_);

    width_           = width;
    height_          = height;
    layers_          = layers;
    depth_           = 0;
    internalformat_  = internalformat;
    format_          = format;
    pixelformat_     = pixelformat;
	samples_		 = 0;

	if (isCompressed()) {
		if (gl_->glCompressedTexImage3D == NULL) {
			destroy();
			return false;
		}
		gl_->glCompressedTexImage3D(GL_TEXTURE_2D_ARRAY, 0, internalformat_, width_, height_, layers_, 0, getBlockSize(width, height, layers), pixels);
	} else {
		gl_->glTexImage3D(GL_TEXTURE_2D_ARRAY, 0, internalformat_, width_, height_, layers_, 0, format_, pixelformat_, pixels);
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
bool ffw::Texture2DArray::resize(GLsizei width, GLsizei height, GLsizei layers){
	if(!loaded_)return false;
	width_ = width;
	height_ = height;
	layers_ = layers;
	glBindTexture(GL_TEXTURE_2D_ARRAY, buffer_);

	if(isCompressed()) {
		gl_->glCompressedTexImage3D(GL_TEXTURE_2D_ARRAY, 0, internalformat_, width_, height_, layers_, 0, getBlockSize(width, height, layers), NULL);
	} else {
		gl_->glTexImage3D(GL_TEXTURE_2D_ARRAY, 0, internalformat_, width_, height_, layers_, 0, format_, pixelformat_, NULL);
	}
	return true;
}

///=============================================================================
bool ffw::Texture2DArray::setPixels(GLint level, GLint xoffset, GLint yoffset, GLint loffset, GLsizei width, GLsizei height, const GLvoid* pixels){
    if(!loaded_)return false;

    glBindTexture(GL_TEXTURE_2D_ARRAY, buffer_);

	if(isCompressed()) {
		gl_->glCompressedTexSubImage3D(GL_TEXTURE_2D_ARRAY, level, xoffset, yoffset, loffset, width, height, 1, internalformat_, getBlockSize(width, height, 1), pixels);
	} else {
		gl_->glTexSubImage3D(GL_TEXTURE_2D_ARRAY, level, xoffset, yoffset, loffset, width, height, 1, format_, pixelformat_, pixels);
	}

    return true;
}

///=============================================================================
bool ffw::Texture2DArray::setPixels(GLint level, const GLvoid* pixels){
    if(!loaded_)return false;
    glBindTexture(GL_TEXTURE_2D_ARRAY, buffer_);

	auto w = width_ >> level;
	auto h = height_ >> level;

	if(isCompressed()) {
		gl_->glCompressedTexImage3D(GL_TEXTURE_2D_ARRAY, level, internalformat_, w, h, layers_, 0, getBlockSize(w, h, layers_), pixels);
	} else {
		gl_->glTexImage3D(GL_TEXTURE_2D_ARRAY, level, internalformat_, w, h, layers_, 0, format_, pixelformat_, pixels);
	}

    return true;
}

///=============================================================================
bool ffw::Texture2DArray::getPixels(void* pixels) const{
	if(!loaded_)return false;
	glBindTexture(GL_TEXTURE_2D_ARRAY, buffer_);
	glGetTexImage(GL_TEXTURE_2D_ARRAY, 0, format_, pixelformat_, pixels);
    return true;
}

///=============================================================================
bool ffw::Texture2DArray::setFromBuffer(const ImageBuffer& buffer, GLint level, bool inverse) {
	if (!buffer.isAllocated())return false;
	if (buffer.getDepth() > 1)return false;

	ffw::OpenGLImageType openglType = ffw::getOpenGLImageType(buffer.getImageType());
	if (!openglType) {
		return false;
	}

	if (buffer.isCompressed() && inverse)return false;

	if (isCreated()) {
		for(int m = 0; m <= buffer.getNumOfMipMaps()-1; m++) {
			
			if(inverse) {
				if (m != 0)setPixels(m, NULL); // Create mipmap
				for (int i = 0; i < buffer.getHeight(m); i++) {
					auto ptr = &buffer.getMipMapPtr(m)[buffer.getStrideSize(m) * i];
					if(!setPixels(m, 0, buffer.getHeight(m) - i - 1, level, buffer.getWidth(m), 1, ptr)) {
						return false;
					}
				}
			}
			else {
				if(!setPixels(m, 0, 0, level, buffer.getWidth(m), buffer.getHeight(m), buffer.getMipMapPtr(m))) {
					return false;
				}
			}
		}

		if(buffer.getNumOfMipMaps() > 0) {
			glTexParameteri(GL_TEXTURE_2D_ARRAY, GL_TEXTURE_BASE_LEVEL, 0);
			glTexParameteri(GL_TEXTURE_2D_ARRAY, GL_TEXTURE_MAX_LEVEL, buffer.getNumOfMipMaps()-1);
		}
	} else {
		return false;
	}

	return true;
}