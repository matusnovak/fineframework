/*** This file is part of FineFramework project ***/

#include "ffw/graphics/renderbuffer2d.h"
#include "ffw/graphics/rendercontext.h"

///=============================================================================
bool ffw::Renderbuffer2D::checkCompability(const ffw::RenderContext* renderer){
	if(renderer == NULL)return false;
	const ffw::RenderExtensions* gl_ = static_cast<const RenderExtensions*>(renderer);

	return (
		gl_->glGenRenderbuffers			 != NULL &&
		gl_->glBindRenderbuffer			 != NULL &&
		gl_->glRenderbufferStorage		 != NULL &&
		gl_->glGetRenderbufferParameteriv != NULL &&
		gl_->glDeleteRenderbuffers		 != NULL &&
		gl_->glBindRenderbuffer		     != NULL
	);
}

///=============================================================================
ffw::Renderbuffer2D::Renderbuffer2D() {
}

///=============================================================================
ffw::Renderbuffer2D::~Renderbuffer2D(){
}

///=============================================================================
bool ffw::Renderbuffer2D::create(const ffw::RenderContext* renderer, GLsizei width, GLsizei height, GLenum internalformat){
	if(loaded_)return false;
	if(!checkCompability(renderer))return false;
	loaded_ = true;
	gl_ = static_cast<const RenderExtensions*>(renderer);

	gl_->glGenRenderbuffers(1, &buffer_);
	gl_->glBindRenderbuffer(GL_RENDERBUFFER, buffer_);

	width_			= width;
	height_			= height;
	internalformat_	= internalformat;

	gl_->glRenderbufferStorage(GL_RENDERBUFFER, internalformat_, width_, height_);

	int test;
    gl_->glGetRenderbufferParameteriv(GL_RENDERBUFFER, GL_RENDERBUFFER_INTERNAL_FORMAT, &test);
    if(test != (int)internalformat_){
        destroy();
        return false;
    }

    return true;
}
