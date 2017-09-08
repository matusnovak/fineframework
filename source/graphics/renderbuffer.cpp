/*** This file is part of FineFramework project ***/

#include "ffw/graphics/renderbuffer.h"
#include "ffw/graphics/rendercontext.h"


///=============================================================================
ffw::Renderbuffer::Renderbuffer() {
    loaded_ = false;
    width_ = 0;
    height_ = 0;
	samples_ = 0;
    buffer_ = 0;
	internalformat_ = 0;
}

///=============================================================================
ffw::Renderbuffer::Renderbuffer(Renderbuffer&& other) {
	loaded_ = false;
	width_ = 0;
	height_ = 0;
	samples_ = 0;
	buffer_ = 0;
	internalformat_ = 0;
	swap(other);
}

///=============================================================================
void ffw::Renderbuffer::swap(Renderbuffer& other) {
	if (this != &other) {
		using std::swap;
		swap(loaded_, other.loaded_);
		swap(width_, other.width_);
		swap(height_, other.height_);
		swap(samples_, other.samples_);
		swap(buffer_, other.buffer_);
		swap(internalformat_, other.internalformat_);
	}
}

///=============================================================================
ffw::Renderbuffer& ffw::Renderbuffer::operator = (Renderbuffer&& other) {
	if(this != &other) {
		swap(other);
	}
	return *this;
}

///=============================================================================
ffw::Renderbuffer::~Renderbuffer(){
    destroy();
}

///=============================================================================
void ffw::Renderbuffer::bind() const{
    if(!loaded_)gl_->glBindRenderbuffer(GL_RENDERBUFFER, buffer_);
}

///=============================================================================
void ffw::Renderbuffer::unbind() const{
    if(loaded_)gl_->glBindRenderbuffer(GL_RENDERBUFFER, 0);
}

///=============================================================================
void ffw::Renderbuffer::destroy(){
    // Delete texture
    if(loaded_)gl_->glDeleteRenderbuffers(1, &buffer_);
    // reset variables
    buffer_ = 0;
    loaded_ = false;
    width_ = 0;
    height_ = 0;
	samples_ = 0;
	internalformat_ = 0;
}
///=============================================================================

