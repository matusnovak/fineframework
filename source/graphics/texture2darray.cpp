/*** This file is part of FineFramework project ***/

#include "ffw/graphics/texture2darray.h"
#include "ffw/graphics/rendercontext.h"
#include "ffw/graphics/extensions.h"


///=============================================================================
bool ffw::Texture2DArray::CheckCompability(const ffw::RenderContext* renderer){
	if(renderer == NULL)return false;
	const ffw::GlextStruct* gl_ = renderer->Glext();

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
ffw::Texture2DArray::~Texture2DArray(){
}

///=============================================================================
bool ffw::Texture2DArray::Create(const ffw::RenderContext* renderer, GLsizei width, GLsizei height, GLsizei layers, GLenum internalformat, GLenum format, GLenum pixelformat){
    if(loaded_)return false;
	if(!CheckCompability(renderer))return false;
	loaded_ = true;
    gl_ = renderer->Glext();

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
        Destroy();
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
bool ffw::Texture2DArray::Resize(GLsizei width, GLsizei height, GLsizei layers){
	if(!loaded_)return false;
	width_ = width;
	height_ = height;
	layers_ = layers;
	glBindTexture(GL_TEXTURE_2D_ARRAY, buffer_);
	gl_->glTexImage3D(GL_TEXTURE_2D_ARRAY, 0, internalformat_, width_, height_, layers_, 0, format_, pixelformat_, NULL);
	return true;
}

///=============================================================================
bool ffw::Texture2DArray::SetPixels(GLint level, GLint xoffset, GLint yoffset, GLint loffset, GLsizei width, GLsizei height, const void* pixels){
    if(!loaded_)return false;
    glEnable(GL_TEXTURE_2D_ARRAY);
    glBindTexture(GL_TEXTURE_2D_ARRAY, buffer_);
    gl_->glTexSubImage3D(GL_TEXTURE_2D_ARRAY, level, xoffset, yoffset, loffset, width, height, 1, format_, pixelformat_, pixels);
    glDisable(GL_TEXTURE_2D_ARRAY);
    return true;
}

///=============================================================================
bool ffw::Texture2DArray::GetPixels(void* pixels){
	if(!loaded_)return false;
	glGetTexImage(GL_TEXTURE_2D_ARRAY, 0, format_, pixelformat_, pixels);
    return true;
}