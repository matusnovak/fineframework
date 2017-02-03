/*** This file is part of FineFramework project ***/

#include "ffw/graphics/texture3d.h"
#include "ffw/graphics/rendercontext.h"

///=============================================================================
bool ffw::Texture3D::CheckCompability(const ffw::RenderContext* renderer){
	if(renderer == NULL)return false;
	const ffw::RenderExtensions* gl_ = renderer->Glext();

	return (
		gl_->glTexImage3D			!= NULL &&
		gl_->glTexSubImage3D		!= NULL
	);
}

///=============================================================================
ffw::Texture3D::Texture3D():Texture(){
    textureformat_ = GL_TEXTURE_3D;
}

///=============================================================================
ffw::Texture3D::~Texture3D(){
}

///=============================================================================
bool ffw::Texture3D::Create(const ffw::RenderContext* renderer, GLsizei width, GLsizei height, GLsizei depth, GLenum internalformat, GLenum format, GLenum pixelformat){
    if(loaded_)return false;
	if(!CheckCompability(renderer))return false;
	loaded_ = true;
    gl_ = renderer->Glext();

    glGenTextures(1, &buffer_);
    glBindTexture(GL_TEXTURE_3D, buffer_);

    width_           = width;
    height_          = height;
    layers_          = 0;
    depth_           = depth;
    internalformat_  = internalformat;
    format_          = format;
    pixelformat_     = pixelformat;

    gl_->glTexImage3D(GL_TEXTURE_3D, 0, internalformat_, width_, height_, depth_, 0, format_, pixelformat_, NULL);

    int test;
    glGetTexLevelParameteriv(GL_TEXTURE_3D, 0, GL_TEXTURE_WIDTH, &test);
    if(test != width){
        Destroy();
        return false;
    }

    glTexParameteri(GL_TEXTURE_3D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_3D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexParameterf(GL_TEXTURE_3D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameterf(GL_TEXTURE_3D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameterf(GL_TEXTURE_3D, GL_TEXTURE_WRAP_R, GL_REPEAT);
    glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_BLEND);
    return true;
}

///=============================================================================
bool ffw::Texture3D::Resize(GLsizei width, GLsizei height, GLsizei depth){
	if(!loaded_)return false;
	width_ = width;
	height_ = height;
	depth_ = depth;
	glBindTexture(GL_TEXTURE_3D, buffer_);
	gl_->glTexImage3D(GL_TEXTURE_3D, 0, internalformat_, width_, height_, depth_, 0, format_, pixelformat_, NULL);
	return true;
}

///=============================================================================
bool ffw::Texture3D::SetPixels(GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, const void* pixels){
    if(!loaded_)return false;
    gl_->glTexSubImage3D(GL_TEXTURE_3D, level, xoffset, yoffset, zoffset, width, height, depth, format_, pixelformat_, pixels);
    return true;
}

///=============================================================================
bool ffw::Texture3D::GetPixels(void* pixels){
    if(!loaded_)return false;
	glGetTexImage(GL_TEXTURE_3D, 0, format_, pixelformat_, pixels);
    return true;
}