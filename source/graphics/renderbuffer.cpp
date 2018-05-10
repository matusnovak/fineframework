/*** This file is part of FineFramework project ***/

#include "ffw/graphics/renderbuffer.h"
#include "ffw/graphics/rendercontext.h"


///=============================================================================
ffw::Renderbuffer::Renderbuffer() {
    loaded = false;
    width = 0;
    height = 0;
    samples = 0;
    buffer = 0;
    internalformat = 0;
}

///=============================================================================
ffw::Renderbuffer::Renderbuffer(Renderbuffer&& other) NOEXCEPT {
    loaded = false;
    width= 0;
    height = 0;
    samples = 0;
    buffer = 0;
    internalformat = 0;
    swap(other);
}

///=============================================================================
void ffw::Renderbuffer::swap(Renderbuffer& other) NOEXCEPT {
    if (this != &other) {
        using std::swap;
        swap(loaded, other.loaded);
        swap(width, other.width);
        swap(height, other.height);
        swap(samples, other.samples);
        swap(buffer, other.buffer);
        swap(internalformat, other.internalformat);
    }
}

///=============================================================================
ffw::Renderbuffer& ffw::Renderbuffer::operator = (Renderbuffer&& other) NOEXCEPT {
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
    if(!loaded)glBindRenderbuffer(GL_RENDERBUFFER, buffer);
}

///=============================================================================
void ffw::Renderbuffer::unbind() const{
    if(loaded)glBindRenderbuffer(GL_RENDERBUFFER, 0);
}

///=============================================================================
void ffw::Renderbuffer::destroy(){
    // Delete texture
    if(loaded)glDeleteRenderbuffers(1, &buffer);
    // reset variables
    buffer = 0;
    loaded = false;
    width = 0;
    height = 0;
    samples = 0;
    internalformat = 0;
}
