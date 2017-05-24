/*** This file is part of FineFramework project ***/

#include "ffw/graphics/texture.h"
#include "ffw/graphics/rendercontext.h"

///=============================================================================
ffw::Texture::Texture() {
	loaded_ = false;
	textureformat_ = 0;
	internalformat_ = 0;
	format_ = 0;
	pixelformat_ = 0;
	buffer_ = 0;
	width_ = 0;
	height_ = 0;
	depth_ = 0;
	layers_ = 0;
	mipmaps_ = false;
	initialized_ = false;
	samples_ = 0;
	gl_ = NULL;
}

///=============================================================================
ffw::Texture::Texture(Texture&& other) {
	loaded_ = false;
	textureformat_ = 0;
	internalformat_ = 0;
	format_ = 0;
	pixelformat_ = 0;
	buffer_ = 0;
	width_ = 0;
	height_ = 0;
	depth_ = 0;
	layers_ = 0;
	mipmaps_ = false;
	initialized_ = false;
	samples_ = 0;
	gl_ = NULL;
	swap(other);
}

///=============================================================================
void ffw::Texture::swap(Texture& other) {
	if (this != &other) {
		using std::swap;
		swap(loaded_, other.loaded_);
		swap(textureformat_, other.textureformat_);
		swap(internalformat_, other.internalformat_);
		swap(format_, other.format_);
		swap(pixelformat_, other.pixelformat_);
		swap(buffer_, other.buffer_);
		swap(width_, other.width_);
		swap(height_, other.height_);
		swap(depth_, other.depth_);
		swap(layers_, other.layers_);
		swap(mipmaps_, other.mipmaps_);
		swap(initialized_, other.initialized_);
		swap(samples_, other.samples_);
		swap(gl_, other.gl_);
	}
}

///=============================================================================
ffw::Texture& ffw::Texture::operator = (Texture&& other) {
	if (this != &other) {
		swap(other);
	}
	return *this;
}

///=============================================================================
ffw::Texture::~Texture(){
    destroy();
}

///=============================================================================
bool ffw::Texture::generateMipmaps(){
    if(!loaded_)return false;
	bind();
	if(gl_->glGenerateMipmap != NULL){
		gl_->glGenerateMipmap(textureformat_);
		mipmaps_ = true;
		return true;
	}
	return false;
}

///=============================================================================
void ffw::Texture::setEnvParami(GLenum target, GLenum name, GLint value){
	glBindTexture(textureformat_, buffer_);
    glTexEnvi(target, name, value);
}

///=============================================================================
void ffw::Texture::setEnvParamf(GLenum target, GLenum name, GLfloat value){
	glBindTexture(textureformat_, buffer_);
    glTexEnvf(target, name, value);
}

///=============================================================================
void ffw::Texture::setTexParami(GLenum name, GLint value){
	glBindTexture(textureformat_, buffer_);
    glTexParameteri(textureformat_, name, value);
}

///=============================================================================
void ffw::Texture::setTexParamf(GLenum name, GLfloat value){
	glBindTexture(textureformat_, buffer_);
    glTexParameterf(textureformat_, name, value);
}

///=============================================================================
void ffw::Texture::setTexParamiv(GLenum name, GLint* value){
	glBindTexture(textureformat_, buffer_);
    glTexParameteriv(textureformat_, name, value);
}

///=============================================================================
void ffw::Texture::setTexParamfv(GLenum name, GLfloat* value){
	glBindTexture(textureformat_, buffer_);
    glTexParameterfv(textureformat_, name, value);
}

///=============================================================================
void ffw::Texture::setFiltering(Texture::Filtering filtering) {
	switch (filtering) {
		case Texture::Filtering::NEAREST: {
			setTexParami(GL_TEXTURE_MAG_FILTER, GL_NEAREST);
			setTexParami(GL_TEXTURE_MIN_FILTER, GL_NEAREST);
			break;
		}
		case Texture::Filtering::LINEAR: {
			setTexParami(GL_TEXTURE_MAG_FILTER, GL_LINEAR);
			setTexParami(GL_TEXTURE_MIN_FILTER, GL_LINEAR);
			break;
		}
		case Texture::Filtering::MIPMAP_NEAREST: {
			setTexParami(GL_TEXTURE_MAG_FILTER, GL_LINEAR_MIPMAP_NEAREST);
			setTexParami(GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_NEAREST);
			break;
		}
		case Texture::Filtering::MIPMAP_LINEAR: {
			setTexParami(GL_TEXTURE_MAG_FILTER, GL_LINEAR_MIPMAP_LINEAR);
			setTexParami(GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
			break;
		}
		default: {
			break;
		}
	}
}

///=============================================================================
void ffw::Texture::setWrapping(Texture::Wrapping wrapping){
	bind();
	switch (wrapping) {
		case Texture::Wrapping::REPEAT: {
			setTexParami(GL_TEXTURE_WRAP_S, GL_REPEAT);
			setTexParami(GL_TEXTURE_WRAP_T, GL_REPEAT);
			setTexParami(GL_TEXTURE_WRAP_R, GL_REPEAT);
			break;
		}
		case Texture::Wrapping::MIRRORED_REPEAT: {
			setTexParami(GL_TEXTURE_WRAP_S, GL_MIRRORED_REPEAT);
			setTexParami(GL_TEXTURE_WRAP_T, GL_MIRRORED_REPEAT);
			setTexParami(GL_TEXTURE_WRAP_R, GL_MIRRORED_REPEAT);
			break;
		}
		case Texture::Wrapping::CLAMP_TO_EDGE: {
			setTexParami(GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
			setTexParami(GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
			setTexParami(GL_TEXTURE_WRAP_R, GL_CLAMP_TO_EDGE);
			break;
		}
		default: {
			break;
		}
	}
	unbind();
}

///=============================================================================
void ffw::Texture::bind() const{
    if(loaded_)glBindTexture(textureformat_, buffer_);
}

///=============================================================================
void ffw::Texture::unbind() const{
    if(loaded_)glBindTexture(textureformat_, 0);
}

///=============================================================================
void ffw::Texture::destroy(){
    // Delete texture
    if(loaded_)glDeleteTextures(1, &buffer_);
    // reset variables
	loaded_ = false;
	textureformat_ = 0;
	internalformat_ = 0;
	format_ = 0;
	pixelformat_ = 0;
	buffer_ = 0;
	width_ = 0;
	height_ = 0;
	depth_ = 0;
	layers_ = 0;
	mipmaps_ = false;
	initialized_ = false;
	samples_ = 0;
}


