/*** This file is part of FineFramework project ***/

#include "ffw/graphics/renderbuffer2dms.h"
#include "ffw/graphics/rendercontext.h"

///=============================================================================
ffw::Renderbuffer2DMS::Renderbuffer2DMS() {
}

///=============================================================================
ffw::Renderbuffer2DMS::~Renderbuffer2DMS(){
}

///=============================================================================
bool ffw::Renderbuffer2DMS::create(GLsizei width, GLsizei height, GLenum internalformat, GLint samples){
    if(loaded_)return false;
    loaded_ = true;

    glGenRenderbuffers(1, &buffer_);
    glBindRenderbuffer(GL_RENDERBUFFER, buffer_);

    width_            = width;
    height_            = height;
    samples_        = samples;
    internalformat_    = internalformat;

    glRenderbufferStorageMultisample(GL_RENDERBUFFER, samples_, internalformat_, width_, height_);

    int test;
    glGetRenderbufferParameteriv(GL_RENDERBUFFER, GL_RENDERBUFFER_INTERNAL_FORMAT, &test);
    if(test != (int)internalformat_){
        destroy();
        return false;
    }

    return true;
}

///=============================================================================
bool ffw::Renderbuffer2DMS::resize(GLsizei width, GLsizei height, GLint samples){
    if(!loaded_)return false;
    width_ = width;
    height_ = height;
    samples_ = samples;
    glBindRenderbuffer(GL_RENDERBUFFER, buffer_);
    glRenderbufferStorageMultisample(GL_RENDERBUFFER, samples_, internalformat_, width_, height_);
    return true;
}