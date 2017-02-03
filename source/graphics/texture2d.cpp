/*** This file is part of FineFramework project ***/

#include "ffw/graphics/texture2d.h"
#include "ffw/graphics/rendercontext.h"

///=============================================================================
bool ffw::Texture2D::CheckCompability(const ffw::RenderContext* renderer){
	return true;
}

///=============================================================================
ffw::Texture2D::Texture2D():Texture(){
    textureformat_ = GL_TEXTURE_2D;
}

///=============================================================================
ffw::Texture2D::~Texture2D(){
}

///=============================================================================
bool ffw::Texture2D::Create(const ffw::RenderContext* renderer, GLsizei width, GLsizei height, GLenum internalformat, GLenum format, GLenum pixelformat){
    if(loaded_)return false;
	if(!CheckCompability(renderer))return false;
	loaded_ = true;
    gl_ = renderer->Glext();

    glGenTextures(1, &buffer_);
    glBindTexture(GL_TEXTURE_2D, buffer_);

    width_           = width;
    height_          = height;
    layers_          = 0;
    depth_           = 0;
    internalformat_  = internalformat;
    format_          = format;
    pixelformat_     = pixelformat;
	samples_		 = 0;

    glTexImage2D(GL_TEXTURE_2D, 0, internalformat_, width_, height_, 0, format_, pixelformat_, NULL);

    int test;
    glGetTexLevelParameteriv(GL_TEXTURE_2D, 0, GL_TEXTURE_WIDTH, &test);
    if(test != width){
        Destroy();
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
bool ffw::Texture2D::Resize(GLsizei width, GLsizei height){
	if(!loaded_)return false;
	width_ = width;
	height_ = height;
	glBindTexture(GL_TEXTURE_2D, buffer_);
	glTexImage2D(GL_TEXTURE_2D, 0, internalformat_, width_, height_, 0, format_, pixelformat_, NULL);
	return true;
}

///=============================================================================
bool ffw::Texture2D::SetPixels(GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, const void* pixels){
    if(!loaded_)return false;
    glTexSubImage2D(GL_TEXTURE_2D, level, xoffset, yoffset, width, height, format_, pixelformat_, pixels);
    return true;
}

///=============================================================================
bool ffw::Texture2D::GetPixels(void* pixels){
    if(!loaded_)return false;
	glGetTexImage(GL_TEXTURE_2D, 0, format_, pixelformat_, pixels);
    return true;
}
