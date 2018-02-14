/*** This file is part of FineFramework project ***/

#include "ffw/graphics/renderbuffer2d.h"
#include "ffw/graphics/rendercontext.h"

///=============================================================================
ffw::Renderbuffer2D::Renderbuffer2D() {
}

///=============================================================================
ffw::Renderbuffer2D::~Renderbuffer2D(){
}

///=============================================================================
bool ffw::Renderbuffer2D::create(GLsizei width, GLsizei height, GLenum internalformat){
    if(loaded_)return false;
    loaded_ = true;

    glGenRenderbuffers(1, &buffer_);
    glBindRenderbuffer(GL_RENDERBUFFER, buffer_);

    width_            = width;
    height_            = height;
    internalformat_    = internalformat;

    glRenderbufferStorage(GL_RENDERBUFFER, internalformat_, width_, height_);

    int test;
    glGetRenderbufferParameteriv(GL_RENDERBUFFER, GL_RENDERBUFFER_INTERNAL_FORMAT, &test);
    if(test != (int)internalformat_){
        destroy();
        return false;
    }

    return true;
}

///=============================================================================
bool ffw::Renderbuffer2D::resize(GLsizei width, GLsizei height){
    if(!loaded_)return false;
    width_ = width;
    height_ = height;
    glBindRenderbuffer(GL_RENDERBUFFER, buffer_);
    glRenderbufferStorage(GL_RENDERBUFFER, internalformat_, width_, height_);
    return true;
}