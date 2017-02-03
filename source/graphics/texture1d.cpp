/*** This file is part of FineFramework project ***/

#include "ffw/graphics/texture1d.h"
#include "ffw/graphics/rendercontext.h"

///=============================================================================
bool ffw::Texture1D::CheckCompability(const ffw::RenderContext* Renderer){
	return true;
}

///=============================================================================
ffw::Texture1D::Texture1D():Texture(){
    textureformat_ = GL_TEXTURE_1D;
}

///=============================================================================
ffw::Texture1D::~Texture1D(){
	Destroy();
}

///=============================================================================
bool ffw::Texture1D::Create(const ffw::RenderContext* renderer, GLsizei width, GLenum internalformat, GLenum format, GLenum pixelformat){
    if(loaded_)return false;
	if(!CheckCompability(renderer))return false;
	loaded_ = true;
    gl_ = renderer->Glext();

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
        Destroy();
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
bool ffw::Texture1D::Resize(GLsizei width){
	if(!loaded_)return false;
	if(width <= 0)return false;
	width_ = width;
	glBindTexture(GL_TEXTURE_1D, buffer_);
	glTexImage1D(GL_TEXTURE_1D, 0, internalformat_, width_, 0, format_, pixelformat_, NULL);
	return true;
}

///=============================================================================
bool ffw::Texture1D::SetPixels(GLint level, GLint xoffset, GLsizei width, const void* pixels){
    if(!loaded_)return false;
	if(level < 0)return false;
	if(width <= 0)return false;
	if(xoffset <= 0 || xoffset > width)return false;
	glTexSubImage1D(GL_TEXTURE_1D, level, xoffset, width, format_, pixelformat_, pixels);
    return true;
}

///=============================================================================
bool ffw::Texture1D::GetPixels(void* pixels){
    if(!loaded_)return false;
	glGetTexImage(GL_TEXTURE_1D, 0, format_, pixelformat_, pixels);
    return true;
}