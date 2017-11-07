/*** This file is part of FineFramework project ***/

#include "ffw/graphics/texture2darrayms.h"
#include "ffw/graphics/rendercontext.h"

///=============================================================================
bool ffw::Texture2DArrayMS::checkCompability(const ffw::RenderContext* renderer){
	if(renderer == NULL)return false;
	const ffw::RenderExtensions* gl_ = static_cast<const RenderExtensions*>(renderer);

	return (
		gl_->glTexImage3DMultisample != NULL
	);
}

///=============================================================================
ffw::Texture2DArrayMS::Texture2DArrayMS():Texture(){
    textureformat_   = GL_TEXTURE_2D_MULTISAMPLE_ARRAY;
}

///=============================================================================
ffw::Texture2DArrayMS::Texture2DArrayMS(Texture2DArrayMS&& second) : Texture2DArrayMS() {
	Texture::swap(second);
}

///=============================================================================
ffw::Texture2DArrayMS& ffw::Texture2DArrayMS::operator = (ffw::Texture2DArrayMS&& other) {
	if (this != &other) {
		Texture::swap(other);
	}
	return *this;
}

///=============================================================================
ffw::Texture2DArrayMS::~Texture2DArrayMS(){
}

///=============================================================================
bool ffw::Texture2DArrayMS::create(const ffw::RenderContext* renderer, GLsizei width, GLsizei height, GLsizei layers, GLenum internalformat, GLenum format, GLenum pixelformat, GLint samples){
    if(loaded_)return false;
	if(!checkCompability(renderer))return false;
	loaded_ = true;
    gl_ = static_cast<const RenderExtensions*>(renderer);

    width_           = width;
    height_          = height;
    layers_          = layers;
    depth_           = 0;
    internalformat_  = internalformat;
    format_          = format;
    pixelformat_     = pixelformat;
	samples_		 = samples;

	if(isCompressed()) {
		destroy();
		return false;
	}

	glGenTextures(1, &buffer_);
    glBindTexture(GL_TEXTURE_2D_MULTISAMPLE_ARRAY, buffer_);

	gl_->glTexImage3DMultisample(GL_TEXTURE_2D_MULTISAMPLE_ARRAY, samples_, internalformat_, width_, height_, layers_, GL_FALSE);

    int test;
    glGetTexLevelParameteriv(GL_TEXTURE_2D_MULTISAMPLE_ARRAY, 0, GL_TEXTURE_WIDTH, &test);
    if(test != width){
        destroy();
        return false;
    }

    glTexParameteri(GL_TEXTURE_2D_MULTISAMPLE_ARRAY, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D_MULTISAMPLE_ARRAY, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexParameterf(GL_TEXTURE_2D_MULTISAMPLE_ARRAY, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameterf(GL_TEXTURE_2D_MULTISAMPLE_ARRAY, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_BLEND);
    return true;
}

///=============================================================================
bool ffw::Texture2DArrayMS::resize(GLsizei width, GLsizei height, GLsizei layers, GLint samples){
	if(!loaded_)return false;
	width_ = width;
	height_ = height;
	layers_ = layers;
	samples_ = samples;
	glBindTexture(GL_TEXTURE_2D_MULTISAMPLE_ARRAY, buffer_);
	gl_->glTexImage3DMultisample(GL_TEXTURE_2D_MULTISAMPLE_ARRAY, samples_, internalformat_, width_, height_, layers_, GL_FALSE);
	return true;
}