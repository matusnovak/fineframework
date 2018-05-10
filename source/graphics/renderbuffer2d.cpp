/*** This file is part of FineFramework project ***/

#include "ffw/graphics/renderbuffer2d.h"
#include "ffw/graphics/rendercontext.h"

///=============================================================================
ffw::Renderbuffer2D::Renderbuffer2D(Renderbuffer2D&& other) NOEXCEPT :Renderbuffer(std::move(other)) {
}

///=============================================================================
ffw::Renderbuffer2D& ffw::Renderbuffer2D::operator=(Renderbuffer2D&& other) noexcept {
    if (this != &other) {
        swap(other);
    }
    return *this;
}

///=============================================================================
bool ffw::Renderbuffer2D::create(const GLsizei width, const GLsizei height, const GLenum internalformat){
    if(loaded)return false;
    loaded = true;

    glGenRenderbuffers(1, &buffer);
    glBindRenderbuffer(GL_RENDERBUFFER, buffer);

    this->width = width;
    this->height = height;
    this->samples = 0;
    this->internalformat = internalformat;

    glRenderbufferStorage(GL_RENDERBUFFER, internalformat, width, height);

    int test;
    glGetRenderbufferParameteriv(GL_RENDERBUFFER, GL_RENDERBUFFER_INTERNAL_FORMAT, &test);
    if(test != int(internalformat)) {
        destroy();
        return false;
    }

    return true;
}

///=============================================================================
bool ffw::Renderbuffer2D::resize(const GLsizei width, const GLsizei height){
    if(!loaded)return false;
    this->width = width;
    this->height = height;
    glBindRenderbuffer(GL_RENDERBUFFER, buffer);
    glRenderbufferStorage(GL_RENDERBUFFER, internalformat, width, height);
    return true;
}