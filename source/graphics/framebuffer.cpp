/*** This file is part of FineFramework project ***/

#include "ffw/graphics/framebuffer.h"
#include "ffw/graphics/rendercontext.h"

///=============================================================================
ffw::Framebuffer::Framebuffer(){
    created_ = false;
    colorcount_ = 0;
    gl_ = NULL;
    fbo_ = 0;
}

///=============================================================================
ffw::Framebuffer::Framebuffer(Framebuffer&& other) {
    created_ = false;
    colorcount_ = 0;
    gl_ = NULL;
    fbo_ = 0;
    swap(other);
}

///=============================================================================
void ffw::Framebuffer::swap(Framebuffer& other) {
    if (this != &other) {
        using std::swap;
        swap(created_, other.created_);
        swap(colorcount_, other.colorcount_);
        swap(gl_, other.gl_);
        swap(fbo_, other.fbo_);
    }
}

///=============================================================================
ffw::Framebuffer& ffw::Framebuffer::operator = (Framebuffer&& other) {
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
    if(created_)return false;
    created_ = true;

    glGenFramebuffers(1, &fbo_);
    return true;
}

///=============================================================================
bool ffw::Framebuffer::addTexture(GLenum attachment, GLuint textype, GLuint texture, GLint level) const {
    if (!created_ || texture == NULL)return false;

    bind();
    glFramebufferTexture2D(GL_FRAMEBUFFER, attachment, textype, texture, level);

    return true;
}

///=============================================================================
bool ffw::Framebuffer::addRenderbuffer(GLenum attachment, GLuint texture) const {
    if (!created_ || texture == NULL)return false;

    bind();
    glFramebufferRenderbuffer(GL_FRAMEBUFFER, attachment, GL_RENDERBUFFER, texture);

    return true;
}

///=============================================================================
bool ffw::Framebuffer::checkStatus(){
    if(!created_)return false;
    
    bind();

    GLenum status = glCheckFramebufferStatus(GL_FRAMEBUFFER);
    if (status != GL_FRAMEBUFFER_COMPLETE) {
        destroy();
        return false;
    }
    return true;
}

///=============================================================================
bool ffw::Framebuffer::destroy(){
    if(created_)glDeleteFramebuffers(1, &fbo_);
    colorcount_ = 0;
    created_ = false;
    return true;
}

///=============================================================================
void ffw::Framebuffer::bind() const {
    if(created_)glBindFramebuffer(GL_FRAMEBUFFER, fbo_);
}

///=============================================================================
void ffw::Framebuffer::unbind() const {
    if(created_)glBindFramebuffer(GL_FRAMEBUFFER, 0);
}
///=============================================================================
