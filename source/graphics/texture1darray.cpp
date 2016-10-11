/*** This file is part of FineFramework project ***/

#include "ffw/graphics/texture1darray.h"
#include "ffw/graphics/rendercontext.h"
#include "ffw/graphics/extensions.h"


///=============================================================================
bool ffw::Texture1DArray::CheckCompability(const ffw::RenderContext* renderer){
	return true;
}

///=============================================================================
ffw::Texture1DArray::Texture1DArray():Texture(){
    textureformat_   = GL_TEXTURE_1D_ARRAY;
}

///=============================================================================
ffw::Texture1DArray::~Texture1DArray(){
}

///=============================================================================
bool ffw::Texture1DArray::Create(const ffw::RenderContext* renderer, GLsizei width, GLsizei layers, GLenum internalformat, GLenum format, GLenum pixelformat){
    if(loaded_)return false;
	if(!CheckCompability(renderer))return false;
	loaded_ = true;
    gl_ = renderer->Glext();

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

    glTexImage2D(GL_TEXTURE_1D_ARRAY, 0, internalformat_, width_, layers_, 0, format_, pixelformat_, NULL);

    int test;
    glGetTexLevelParameteriv(GL_TEXTURE_1D_ARRAY, 0, GL_TEXTURE_WIDTH, &test);
    if(test != width){
        Destroy();
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
bool ffw::Texture1DArray::Resize(GLsizei width, GLsizei layers){
	if(!loaded_)return false;
	width_ = width;
	layers_ = layers;
	glBindTexture(GL_TEXTURE_1D_ARRAY, buffer_);
	glTexImage2D(GL_TEXTURE_1D_ARRAY, 0, internalformat_, width_, layers_, 0, format_, pixelformat_, NULL);
	return true;
}

///=============================================================================
bool ffw::Texture1DArray::SetPixels(GLint level, GLint xoffset, GLint loffset, GLsizei width, const void* pixels){
    if(!loaded_)return false;
    glEnable(GL_TEXTURE_1D_ARRAY);
    glBindTexture(GL_TEXTURE_1D_ARRAY, buffer_);
    glTexSubImage2D(GL_TEXTURE_1D_ARRAY, level, xoffset, loffset, width, 1, format_, pixelformat_, pixels);
    glDisable(GL_TEXTURE_1D_ARRAY);
    return true;
}

///=============================================================================
bool ffw::Texture1DArray::GetPixels(void* pixels){
	if(!loaded_)return false;
	glGetTexImage(GL_TEXTURE_1D_ARRAY, 0, format_, pixelformat_, pixels);
    return true;
}