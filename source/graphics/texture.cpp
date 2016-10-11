/*** This file is part of FineFramework project ***/

#include "ffw/graphics/texture.h"
#include "ffw/graphics/rendercontext.h"
#include "ffw/graphics/extensions.h"


///=============================================================================
ffw::Texture::Texture() {
    loaded_ = false;
    mipmaps_ = false;
    width_ = 0;
    height_ = 0;
    depth_ = 0;
    layers_ = 0;
    buffer_ = 0;
	samples_ = 0;
    initialized_ = false;
}

///=============================================================================
ffw::Texture::~Texture(){
    Destroy();
}

///=============================================================================
bool ffw::Texture::GenerateMipmaps(){
    if(!loaded_)return false;
	Bind();
	if(gl_->glGenerateMipmap != NULL){
		gl_->glGenerateMipmap(textureformat_);
		mipmaps_ = true;
		return true;
	}
	return false;
}

///=============================================================================
void ffw::Texture::SetEnvParami(GLenum target, GLenum name, GLint value){
    glTexEnvi(target, name, value);
}

///=============================================================================
void ffw::Texture::SetEnvParamf(GLenum target, GLenum name, GLfloat value){
    glTexEnvf(target, name, value);
}

///=============================================================================
void ffw::Texture::SetTexParami(GLenum name, GLint value){
    glTexParameteri(textureformat_, name, value);
}

///=============================================================================
void ffw::Texture::SetTexParamf(GLenum name, GLfloat value){
    glTexParameterf(textureformat_, name, value);
}

///=============================================================================
void ffw::Texture::SetTexParamiv(GLenum name, GLint* value){
    glTexParameteriv(textureformat_, name, value);
}

///=============================================================================
void ffw::Texture::SetTexParamfv(GLenum name, GLfloat* value){
    glTexParameterfv(textureformat_, name, value);
}

///=============================================================================
void ffw::Texture::Bind() const{
    if(loaded_)glBindTexture(textureformat_, buffer_);
}

///=============================================================================
void ffw::Texture::Unbind() const{
    if(loaded_)glBindTexture(textureformat_, 0);
}

///=============================================================================
void ffw::Texture::Destroy(){
    // Delete texture
    if(loaded_)glDeleteTextures(1, &buffer_);
    // Reset variables
    buffer_ = 0;
    loaded_ = false;
    mipmaps_ = false;
    width_ = 0;
    height_ = 0;
    depth_ = 0;
    layers_ = 0;
	samples_ = 0;
}


