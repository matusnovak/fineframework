/*** This file is part of FineFramework project ***/

#include "ffw/graphics/texture1d.h"
#include "ffw/graphics/rendercontext.h"

///=============================================================================
bool ffw::Texture1D::checkCompability(const ffw::RenderContext* Renderer){
	return true;
}

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
bool ffw::Texture1D::create(const ffw::RenderContext* renderer, GLsizei width, GLenum internalformat, GLenum format, GLenum pixelformat){
    if(loaded_)return false;
	if(!checkCompability(renderer))return false;
	loaded_ = true;
    gl_ = static_cast<const RenderExtensions*>(renderer);

    glGenTextures(1, &buffer_);
    glBindTexture(GL_TEXTURE_1D, buffer_);

    width_           = width;
    height_          = 1;
    layers_          = 0;
    depth_           = 0;
    internalformat_  = internalformat;
    format_          = format;
    pixelformat_     = pixelformat;
	samples_		 = 0;

	glTexImage1D(GL_TEXTURE_1D, 0, internalformat_, width_, 0, format_, pixelformat_, NULL);

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
	glTexImage1D(GL_TEXTURE_1D, 0, internalformat_, width_, 0, format_, pixelformat_, NULL);
	return true;
}

///=============================================================================
bool ffw::Texture1D::setPixels(GLint level, GLint xoffset, GLsizei width, const void* pixels){
    if(!loaded_)return false;
	glBindTexture(GL_TEXTURE_1D, buffer_);
	glTexSubImage1D(GL_TEXTURE_1D, level, xoffset, width, format_, pixelformat_, pixels);
    return true;
}

///=============================================================================
bool ffw::Texture1D::getPixels(void* pixels){
    if(!loaded_)return false;
	glBindTexture(GL_TEXTURE_1D, buffer_);
	glGetTexImage(GL_TEXTURE_1D, 0, format_, pixelformat_, pixels);
    return true;
}