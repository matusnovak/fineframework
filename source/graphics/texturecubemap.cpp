/*** This file is part of FineFramework project ***/

#include "ffw/graphics/texturecubemap.h"
#include "ffw/graphics/rendercontext.h"
#include <ffw/graphics.h>

///=============================================================================
bool ffw::TextureCubemap::checkCompability(const ffw::RenderContext* Renderer){
	return true;
}

///=============================================================================
ffw::TextureCubemap::TextureCubemap():Texture(){
    textureformat_ = GL_TEXTURE_CUBE_MAP;
}

///=============================================================================
ffw::TextureCubemap::TextureCubemap(TextureCubemap&& second) : TextureCubemap() {
	Texture::swap(second);
}

///=============================================================================
ffw::TextureCubemap& ffw::TextureCubemap::operator = (ffw::TextureCubemap&& other) {
	if (this != &other) {
		Texture::swap(other);
	}
	return *this;
}

///=============================================================================
ffw::TextureCubemap::~TextureCubemap(){
	destroy();
}

///=============================================================================
bool ffw::TextureCubemap::create(const ffw::RenderContext* renderer, GLsizei width, GLsizei height, GLenum internalformat, GLenum format, GLenum pixelformat, const GLvoid* pixels){
    if(loaded_)return false;
	if(!checkCompability(renderer))return false;
	loaded_ = true;
    gl_ = static_cast<const RenderExtensions*>(renderer);

    glGenTextures(1, &buffer_);
    glBindTexture(GL_TEXTURE_CUBE_MAP, buffer_);

    width_           = width;
    height_          = height;
    layers_          = 0;
    depth_           = 0;
    internalformat_  = internalformat;
    format_          = format;
    pixelformat_     = pixelformat;
	samples_		 = 0;

	if(isCompressed() && gl_->glCompressedTexImage2D == NULL) {
		destroy();
		return false;
	}

	for (int i = 0; i < 6; i++) {
		if(isCompressed()) {
			gl_->glCompressedTexImage2D(GL_TEXTURE_CUBE_MAP_POSITIVE_X + i, 0, internalformat_, width_, height_, 0, getBlockSize(width, height), pixels);
		} else {
			glTexImage2D(GL_TEXTURE_CUBE_MAP_POSITIVE_X + i, 0, internalformat_, width_, height_, 0, format_, pixelformat_, pixels);
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
bool ffw::TextureCubemap::resize(GLsizei width, GLsizei height){
	if(!loaded_)return false;
	if(width <= 0)return false;
	width_ = width;
	height_ = height;
	glBindTexture(GL_TEXTURE_CUBE_MAP, buffer_);
	for (int i = 0; i < 6; i++) {
		if(isCompressed()) {
			gl_->glCompressedTexImage2D(GL_TEXTURE_CUBE_MAP_POSITIVE_X + i, 0, internalformat_, width_, height_, 0, getBlockSize(width, height), NULL);
		} else {
			glTexImage2D(GL_TEXTURE_CUBE_MAP_POSITIVE_X + i, 0, internalformat_, width_, height_, 0, format_, pixelformat_, NULL);
		}
	}
	return true;
}

///=============================================================================
bool ffw::TextureCubemap::setPixels(GLint level, GLint side, const void* pixels) {
	if(!loaded_)return false;
	glBindTexture(GL_TEXTURE_CUBE_MAP, buffer_);

	auto w = width_ >> level;
	auto h = height_ >> level;

	if (isCompressed()) {
		gl_->glCompressedTexImage2D(GL_TEXTURE_CUBE_MAP_POSITIVE_X + side, level, internalformat_, w, h, 0, getBlockSize(w, h), pixels);
	} else {
		glTexImage2D(GL_TEXTURE_CUBE_MAP_POSITIVE_X + side, level, internalformat_, w, h, 0, format_, pixelformat_, pixels);
	}
    return true;
}

///=============================================================================
bool ffw::TextureCubemap::setPixels(GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLint side, const void* pixels){
    if(!loaded_)return false;
	if (side < 0 || side >= 6)return false;
	glBindTexture(GL_TEXTURE_CUBE_MAP, buffer_);

	if(isCompressed()) {
		gl_->glCompressedTexSubImage2D(GL_TEXTURE_CUBE_MAP_POSITIVE_X + side, level, xoffset, yoffset, width, height, internalformat_, getBlockSize(width, height), pixels);
	} else {
		glTexSubImage2D(GL_TEXTURE_CUBE_MAP_POSITIVE_X + side, level, xoffset, yoffset, width, height, format_, pixelformat_, pixels);
	}
    return true;
}

///=============================================================================
bool ffw::TextureCubemap::setFromBuffer(const ImageBuffer& buffer, GLint side, bool inverse) {
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
				if (m != 0)setPixels(m, side, NULL); // Create mipmap
				for (int i = 0; i < buffer.getHeight(m); i++) {
					auto ptr = &buffer.getMipMapPtr(m)[buffer.getStrideSize(m) * i];
					if(!setPixels(m, 0, buffer.getHeight(m) - i - 1, buffer.getWidth(m), 1, side, ptr)) {
						return false;
					}
				}
			}
			else {
				if (m != 0)setPixels(m, side, NULL); // Create mipmap
				if(!setPixels(m, 0, 0, buffer.getWidth(m), buffer.getHeight(m), side, buffer.getMipMapPtr(m))) {
					return false;
				}
			}
		}

		if(buffer.getNumOfMipMaps() > 0) {
			glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_BASE_LEVEL, 0);
			glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_MAX_LEVEL, buffer.getNumOfMipMaps()-1);
		}
	} else {
		return false;
	}

	return true;
}

///=============================================================================
bool ffw::TextureCubemap::getPixels(void* pixels){
    if(!loaded_)return false;
	glBindTexture(GL_TEXTURE_CUBE_MAP, buffer_);
	glGetTexImage(GL_TEXTURE_CUBE_MAP, 0, format_, pixelformat_, pixels);
    return true;
}
