/*** This file is part of FineFramework project ***/

#include "ffw/graphics/renderbuffer2dms.h"
#include "ffw/graphics/rendercontext.h"

///=============================================================================
bool ffw::Renderbuffer2DMS::create(const GLsizei width, const GLsizei height, const GLenum internalformat, const GLint samples){
    if(loaded)return false;
    loaded = true;

    glGenRenderbuffers(1, &buffer);
    glBindRenderbuffer(GL_RENDERBUFFER, buffer);

    this->width = width;
    this->height = height;
    this->samples = samples;
    this->internalformat = internalformat;

    glRenderbufferStorageMultisample(GL_RENDERBUFFER, samples, internalformat, width, height);

    int test;
    glGetRenderbufferParameteriv(GL_RENDERBUFFER, GL_RENDERBUFFER_INTERNAL_FORMAT, &test);
    if(test != int(internalformat)) {
        destroy();
        return false;
    }

    return true;
}

///=============================================================================
bool ffw::Renderbuffer2DMS::resize(const GLsizei width, const GLsizei height, const GLint samples){
    if(!loaded)return false;
    this->width = width;
    this->height = height;
    this->samples = samples;
    glBindRenderbuffer(GL_RENDERBUFFER, buffer);
    glRenderbufferStorageMultisample(GL_RENDERBUFFER, samples, internalformat, width, height);
    return true;
}