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
bool ffw::Framebuffer::addDepthTexture(const ffw::Texture2D* depthtexture, int mip){
    if(!created_ || depthtexture == NULL)return false;
    
    bind();
    glFramebufferTexture2D(GL_FRAMEBUFFER, GL_DEPTH_ATTACHMENT, GL_TEXTURE_2D, depthtexture->getHandle(), mip);
    
    return true;
}

///=============================================================================
bool ffw::Framebuffer::addColorTexture(const ffw::Texture2D* colortexture, int mip){
    if(!created_ || colortexture == NULL)return false;

    // Check if number of color attachments is lower than the maximum
    GLint maxColorAttachments;
    glGetIntegerv(GL_MAX_COLOR_ATTACHMENTS, &maxColorAttachments);
    if (colorcount_ > maxColorAttachments){
        return false;
    }

    bind();
    glFramebufferTexture2D(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0 + colorcount_, GL_TEXTURE_2D, colortexture->getHandle(), mip);
    
    colorcount_++;
    return true;
}

///=============================================================================
bool ffw::Framebuffer::addCubemapTexture(const ffw::TextureCubemap* texture, int side, int mip) {
    if(!created_ || texture == NULL)return false;

    // Check if number of color attachments is lower than the maximum
    GLint maxColorAttachments;
    glGetIntegerv(GL_MAX_COLOR_ATTACHMENTS, &maxColorAttachments);
    if (colorcount_ > maxColorAttachments){
        return false;
    }

    bind();
    glFramebufferTexture2D(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0 + colorcount_, GL_TEXTURE_CUBE_MAP_POSITIVE_X + side, texture->getHandle(), mip);
    
    colorcount_++;
    return true;
}

///=============================================================================
bool ffw::Framebuffer::addDepthRenderbuffer(const ffw::Renderbuffer2D* depthrenderbuffer){
    if(!created_ || depthrenderbuffer == NULL)return false;
    
    bind();
    glFramebufferRenderbuffer(GL_FRAMEBUFFER, GL_DEPTH_ATTACHMENT, GL_RENDERBUFFER, depthrenderbuffer->getHandle());
    
    return true;
}

///=============================================================================
bool ffw::Framebuffer::addColorRenderbuffer(const ffw::Renderbuffer2D* colorrenderbuffer){
    if(!created_ || colorrenderbuffer == NULL)return false;

    // Check if number of color attachments is lower than the maximum
    GLint maxColorAttachments;
    glGetIntegerv(GL_MAX_COLOR_ATTACHMENTS, &maxColorAttachments);
    if (colorcount_ > maxColorAttachments){
        return false;
    }

    bind();
    glFramebufferRenderbuffer(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0 + colorcount_, GL_RENDERBUFFER, colorrenderbuffer->getHandle());
    
    colorcount_++;
    return true;
}

///=============================================================================
bool ffw::Framebuffer::addDepthTextureMS(const ffw::Texture2DMS* depthtexture, int mip){
    if(!created_ || depthtexture == NULL)return false;
    
    bind();
    glFramebufferTexture2D(GL_FRAMEBUFFER, GL_DEPTH_ATTACHMENT, GL_TEXTURE_2D_MULTISAMPLE, depthtexture->getHandle(), mip);
    
    return true;
}

///=============================================================================
bool ffw::Framebuffer::addColorTextureMS(const ffw::Texture2DMS* colortexture, int mip){
    if(!created_ || colortexture == NULL)return false;

    // Check if number of color attachments is lower than the maximum
    GLint maxColorAttachments;
    glGetIntegerv(GL_MAX_COLOR_ATTACHMENTS, &maxColorAttachments);
    if (colorcount_ > maxColorAttachments){
        return false;
    }

    bind();
    glFramebufferTexture2D(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0 + colorcount_, GL_TEXTURE_2D_MULTISAMPLE, colortexture->getHandle(), mip);
    
    colorcount_++;
    return true;
}

///=============================================================================
bool ffw::Framebuffer::addDepthRenderbufferMS(const ffw::Renderbuffer2DMS* depthrenderbuffer){
    if(!created_ || depthrenderbuffer == NULL)return false;
    
    bind();
    glFramebufferRenderbuffer(GL_FRAMEBUFFER, GL_DEPTH_ATTACHMENT, GL_RENDERBUFFER, depthrenderbuffer->getHandle());
    
    return true;
}

///=============================================================================
bool ffw::Framebuffer::addColorRenderbufferMS(const ffw::Renderbuffer2DMS* colorrenderbuffer){
    if(!created_ || colorrenderbuffer == NULL)return false;
    
    // Check if number of color attachments is lower than the maximum
    GLint maxColorAttachments;
    glGetIntegerv(GL_MAX_COLOR_ATTACHMENTS, &maxColorAttachments);
    if (colorcount_ > maxColorAttachments){
        return false;
    }

    bind();
    glFramebufferRenderbuffer(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0 + colorcount_, GL_RENDERBUFFER, colorrenderbuffer->getHandle());
    
    colorcount_++;
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
