/*** This file is part of FineFramework project ***/

#include "ffw/graphics/renderbuffer2dms.h"
#include "ffw/graphics/rendercontext.h"

///=============================================================================
bool ffw::Renderbuffer2DMS::CheckCompability(const ffw::RenderContext* renderer){
	if(renderer == NULL)return false;
	const ffw::RenderExtensions* gl_ = renderer->Glext();

	return (
		gl_->glGenRenderbuffers				 != NULL &&
		gl_->glBindRenderbuffer				 != NULL &&
		gl_->glRenderbufferStorageMultisample != NULL &&
		gl_->glGetRenderbufferParameteriv		 != NULL &&
		gl_->glDeleteRenderbuffers			 != NULL &&
		gl_->glBindRenderbuffer				 != NULL
	);
}

///=============================================================================
ffw::Renderbuffer2DMS::Renderbuffer2DMS() {
}

///=============================================================================
ffw::Renderbuffer2DMS::~Renderbuffer2DMS(){
}

///=============================================================================
bool ffw::Renderbuffer2DMS::Create(const ffw::RenderContext* renderer, GLsizei width, GLsizei height, GLenum internalformat, GLint samples){
	if(loaded_)return false;
	if(!CheckCompability(renderer))return false;
	loaded_ = true;
	gl_ = renderer->Glext();

	gl_->glGenRenderbuffers(1, &buffer_);
	gl_->glBindRenderbuffer(GL_RENDERBUFFER, buffer_);

	width_			= width;
	height_			= height;
	internalformat_	= internalformat;

	gl_->glRenderbufferStorageMultisample(GL_RENDERBUFFER, samples, internalformat_, width_, height_);

	int test;
    gl_->glGetRenderbufferParameteriv(GL_RENDERBUFFER, GL_RENDERBUFFER_INTERNAL_FORMAT, &test);
    if(test != (int)internalformat_){
        Destroy();
        return false;
    }

    return true;
}

