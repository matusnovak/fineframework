/*** This file is part of FineFramework project ***/

#include "ffw/graphics/texture2darray.h"
#include "ffw/graphics/rendercontext.h"

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
bool ffw::Texture2DArray::create(const ffw::RenderContext* renderer, GLsizei width, GLsizei height, GLsizei layers, GLenum internalformat, GLenum format, GLenum pixelformat){
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

    gl_->glTexImage3D(GL_TEXTURE_2D_ARRAY, 0, internalformat_, width_, height_, layers_, 0, format_, pixelformat_, NULL);

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
	gl_->glTexImage3D(GL_TEXTURE_2D_ARRAY, 0, internalformat_, width_, height_, layers_, 0, format_, pixelformat_, NULL);
	return true;
}

///=============================================================================
bool ffw::Texture2DArray::setPixels(GLint level, GLint xoffset, GLint yoffset, GLint loffset, GLsizei width, GLsizei height, const void* pixels){
    if(!loaded_)return false;
    glEnable(GL_TEXTURE_2D_ARRAY);
    glBindTexture(GL_TEXTURE_2D_ARRAY, buffer_);
    gl_->glTexSubImage3D(GL_TEXTURE_2D_ARRAY, level, xoffset, yoffset, loffset, width, height, 1, format_, pixelformat_, pixels);
    glDisable(GL_TEXTURE_2D_ARRAY);
    return true;
}

///=============================================================================
bool ffw::Texture2DArray::getPixels(void* pixels){
	if(!loaded_)return false;
	glGetTexImage(GL_TEXTURE_2D_ARRAY, 0, format_, pixelformat_, pixels);
    return true;
}