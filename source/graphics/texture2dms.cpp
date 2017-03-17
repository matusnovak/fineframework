/*** This file is part of FineFramework project ***/

#include "ffw/graphics/texture2dms.h"
#include "ffw/graphics/rendercontext.h"

///=============================================================================
bool ffw::Texture2DMS::checkCompability(const ffw::RenderContext* renderer){
	if(renderer == NULL)return false;
	const ffw::RenderExtensions* gl_ = static_cast<const RenderExtensions*>(renderer);

	return (
		gl_->glTexImage2DMultisample != NULL
	);
}

///=============================================================================
ffw::Texture2DMS::Texture2DMS():Texture(){
    textureformat_ = GL_TEXTURE_2D_MULTISAMPLE;
}

///=============================================================================
ffw::Texture2DMS::Texture2DMS(Texture2DMS&& second) : Texture2DMS() {
	Texture::swap(second);
}

///=============================================================================
ffw::Texture2DMS& ffw::Texture2DMS::operator = (ffw::Texture2DMS&& other) {
	if (this != &other) {
		Texture::swap(other);
	}
	return *this;
}

///=============================================================================
ffw::Texture2DMS::~Texture2DMS(){
}

///=============================================================================
bool ffw::Texture2DMS::create(const ffw::RenderContext* renderer, GLsizei width, GLsizei height, GLenum internalformat, GLenum format, GLenum pixelformat, GLint samples){
    if(loaded_)return false;
	if(!checkCompability(renderer))return false;
	loaded_ = true;
    gl_ = static_cast<const RenderExtensions*>(renderer);

    glGenTextures(1, &buffer_);
    glBindTexture(GL_TEXTURE_2D_MULTISAMPLE, buffer_);

    width_           = width;
    height_          = height;
    layers_          = 0;
    depth_           = 0;
    internalformat_  = internalformat;
    format_          = format;
    pixelformat_     = pixelformat;
	samples_		 = samples;

	gl_->glTexImage2DMultisample(GL_TEXTURE_2D_MULTISAMPLE, samples_, internalformat_, width_, height_, GL_FALSE);

    int test;
    glGetTexLevelParameteriv(GL_TEXTURE_2D_MULTISAMPLE, 0, GL_TEXTURE_WIDTH, &test);
    if(test != width){
        destroy();
        return false;
    }

    glTexParameteri(GL_TEXTURE_2D_MULTISAMPLE, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D_MULTISAMPLE, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexParameterf(GL_TEXTURE_2D_MULTISAMPLE, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameterf(GL_TEXTURE_2D_MULTISAMPLE, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_BLEND);
    return true;
}

///=============================================================================
bool ffw::Texture2DMS::resize(GLsizei width, GLsizei height, GLint samples){
	if(!loaded_)return false;
	width_ = width;
	height_ = height;
	samples_ = samples;
	glBindTexture(GL_TEXTURE_2D_MULTISAMPLE, buffer_);
	gl_->glTexImage2DMultisample(GL_TEXTURE_2D_MULTISAMPLE, samples_, internalformat_, width_, height_, GL_FALSE);
	return true;
}