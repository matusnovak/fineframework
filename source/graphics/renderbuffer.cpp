/*** This file is part of FineFramework project ***/

#include "ffw/graphics/renderbuffer.h"
#include "ffw/graphics/rendercontext.h"


///=============================================================================
ffw::Renderbuffer::Renderbuffer() {
    loaded_ = false;
    width_ = 0;
    height_ = 0;
    buffer_ = 0;
}

///=============================================================================
ffw::Renderbuffer::~Renderbuffer(){
    Destroy();
}

///=============================================================================
void ffw::Renderbuffer::Bind() const{
    if(!loaded_)gl_->glBindRenderbuffer(GL_RENDERBUFFER, buffer_);
}

///=============================================================================
void ffw::Renderbuffer::Unbind() const{
    if(loaded_)gl_->glBindRenderbuffer(GL_RENDERBUFFER, 0);
}

///=============================================================================
void ffw::Renderbuffer::Destroy(){
    // Delete texture
    if(loaded_)gl_->glDeleteRenderbuffers(1, &buffer_);
    // Reset variables
    buffer_ = 0;
    loaded_ = false;
    width_ = 0;
    height_ = 0;
}
///=============================================================================

