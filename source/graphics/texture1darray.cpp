/*** This file is part of FineFramework project ***/

#include "ffw/graphics/texture1darray.h"
#include "ffw/graphics/rendercontext.h"

///=============================================================================
bool ffw::Texture1DArray::checkCompability(const ffw::RenderContext* renderer){
	return true;
}

///=============================================================================
ffw::Texture1DArray::Texture1DArray():Texture(){
    textureformat_   = GL_TEXTURE_1D_ARRAY;
}

///=============================================================================
ffw::Texture1DArray::Texture1DArray(Texture1DArray&& second) : Texture1DArray() {
	Texture::swap(second);
}

///=============================================================================
ffw::Texture1DArray& ffw::Texture1DArray::operator = (ffw::Texture1DArray&& other) {
	if (this != &other) {
		Texture::swap(other);
	}
	return *this;
}

///=============================================================================
ffw::Texture1DArray::~Texture1DArray(){
}

///=============================================================================
bool ffw::Texture1DArray::create(const ffw::RenderContext* renderer, GLsizei width, GLsizei layers, GLenum internalformat, GLenum format, GLenum pixelformat, const GLvoid* pixels){
    if(loaded_)return false;
	if(!checkCompability(renderer))return false;
	loaded_ = true;
    gl_ = static_cast<const RenderExtensions*>(renderer);

    glGenTextures(1, &buffer_);
    glBindTexture(GL_TEXTURE_1D_ARRAY, buffer_);

    width_           = width;
    height_          = 1;
    layers_          = layers;
    depth_           = 0;
    internalformat_  = internalformat;
    format_          = format;
    pixelformat_     = pixelformat;
	samples_		 = 0;

	if(isCompressed()) {
		if(gl_->glCompressedTexImage2D == NULL) {
			destroy();
			return false;
		}
		gl_->glCompressedTexImage2D(GL_TEXTURE_1D_ARRAY, 0, internalformat_, width_, layers_, 0, getBlockSize(width, layers_), pixels);
	} else {
		glTexImage2D(GL_TEXTURE_1D_ARRAY, 0, internalformat_, width_, layers_, 0, format_, pixelformat_, pixels);
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
bool ffw::Texture1DArray::resize(GLsizei width, GLsizei layers){
	if(!loaded_)return false;
	width_ = width;
	layers_ = layers;
	glBindTexture(GL_TEXTURE_1D_ARRAY, buffer_);
	glTexImage2D(GL_TEXTURE_1D_ARRAY, 0, internalformat_, width_, layers_, 0, format_, pixelformat_, NULL);
	return true;
}

///=============================================================================
bool ffw::Texture1DArray::setPixels(GLint level, GLint xoffset, GLint loffset, GLsizei width, const void* pixels){
    if(!loaded_)return false;
    glBindTexture(GL_TEXTURE_1D_ARRAY, buffer_);
	if(isCompressed()) {
		gl_->glCompressedTexSubImage2D(GL_TEXTURE_1D_ARRAY, level, xoffset, loffset, width, 1, internalformat_, getBlockSize(width, 1), pixels);
	} else {
		glTexSubImage2D(GL_TEXTURE_1D_ARRAY, level, xoffset, loffset, width, 1, format_, pixelformat_, pixels);
	}
    return true;
}

///=============================================================================
bool ffw::Texture1DArray::setPixels(GLint level, const void* pixels){
    if(!loaded_)return false;
    glBindTexture(GL_TEXTURE_1D_ARRAY, buffer_);
	if(isCompressed()) {
		gl_->glCompressedTexImage2D(GL_TEXTURE_1D_ARRAY, level, internalformat_, width_, layers_, 0, getBlockSize(width_, layers_), pixels);
	} else {
		glTexImage2D(GL_TEXTURE_1D_ARRAY, level, internalformat_, width_, layers_, 0, format_, pixelformat_, pixels);
	}
    return true;
}

///=============================================================================
bool ffw::Texture1DArray::getPixels(void* pixels) const {
	if(!loaded_)return false;
	glBindTexture(GL_TEXTURE_1D_ARRAY, buffer_);
	glGetTexImage(GL_TEXTURE_1D_ARRAY, 0, format_, pixelformat_, pixels);
    return true;
}