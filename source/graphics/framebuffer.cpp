/*** This file is part of FineFramework project ***/

#include "ffw/graphics/framebuffer.h"
#include "ffw/graphics/rendercontext.h"

///=============================================================================
ffw::Framebuffer::Framebuffer(){
    created = false;
    colorcount = 0;
    fbo = 0;
}

///=============================================================================
ffw::Framebuffer::Framebuffer(Framebuffer&& other) NOEXCEPT {
    created = false;
    colorcount = 0;
    fbo = 0;
    swap(other);
}

///=============================================================================
void ffw::Framebuffer::swap(Framebuffer& other) NOEXCEPT {
    if (this != &other) {
        using std::swap;
        swap(created, other.created);
        swap(colorcount, other.colorcount);
        swap(fbo, other.fbo);
    }
}

///=============================================================================
ffw::Framebuffer& ffw::Framebuffer::operator = (Framebuffer&& other) NOEXCEPT {
    if(this != &other) {
        swap(other);
    }
    return *this;
}

///=============================================================================
ffw::Framebuffer::~Framebuffer(){
    destroy();
}

///=============================================================================
bool ffw::Framebuffer::create(){
    if(created)return false;
    created = true;

    glGenFramebuffers(1, &fbo);
    return true;
}

///=============================================================================
bool ffw::Framebuffer::addTexture(const GLenum attachment, const GLuint textype, 
    const GLuint texture, const GLint level) const {

    if (!created || texture == 0)return false;

    bind();
    glFramebufferTexture2D(GL_FRAMEBUFFER, attachment, textype, texture, level);

    return true;
}

///=============================================================================
bool ffw::Framebuffer::addRenderbuffer(const GLenum attachment, const GLuint texture) const {
    if (!created || texture == 0)return false;

    bind();
    glFramebufferRenderbuffer(GL_FRAMEBUFFER, attachment, GL_RENDERBUFFER, texture);

    return true;
}

///=============================================================================
bool ffw::Framebuffer::checkStatus(){
    if(!created)return false;
    
    bind();

    const auto status = glCheckFramebufferStatus(GL_FRAMEBUFFER);
    if (status != GL_FRAMEBUFFER_COMPLETE) {
        destroy();
        return false;
    }
    return true;
}

///=============================================================================
bool ffw::Framebuffer::destroy(){
    if(created)glDeleteFramebuffers(1, &fbo);
    colorcount = 0;
    created = false;
    return true;
}

///=============================================================================
void ffw::Framebuffer::bind() const {
    if(created)glBindFramebuffer(GL_FRAMEBUFFER, fbo);
}

///=============================================================================
void ffw::Framebuffer::unbind() const {
    if(created)glBindFramebuffer(GL_FRAMEBUFFER, 0);
}
