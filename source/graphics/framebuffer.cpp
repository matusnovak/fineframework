/*** This file is part of FineFramework project ***/

#include "ffw/graphics/framebuffer.h"
#include "ffw/graphics/rendercontext.h"

///=============================================================================
bool ffw::Framebuffer::checkCompability(const ffw::RenderContext* renderer){
	if(renderer == NULL)return false;
	const ffw::RenderExtensions* gl_ = static_cast<const RenderExtensions*>(renderer);

	#ifdef FFW_OSX
	return (
		gl_->glGenFramebuffers != NULL &&
		gl_->glBindFramebuffer != NULL &&
		gl_->glFramebufferTexture2D != NULL &&
		gl_->glFramebufferRenderbuffer != NULL &&
		gl_->glCheckFramebufferStatus != NULL &&
		gl_->glDeleteFramebuffers != NULL
	);
	#else
	return (
		gl_->glGenFramebuffersEXT != NULL &&
		gl_->glBindFramebufferEXT != NULL &&
		gl_->glFramebufferTexture2DEXT != NULL &&
		gl_->glFramebufferRenderbufferEXT != NULL &&
		gl_->glCheckFramebufferStatusEXT != NULL &&
		gl_->glDeleteFramebuffersEXT != NULL
	);
	#endif
}

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
bool ffw::Framebuffer::create(const ffw::RenderContext* renderer){
    if(created_)return false;
	if(!checkCompability(renderer))return false;
	created_ = true;
	gl_ = static_cast<const RenderExtensions*>(renderer);

	// create Framebuffer
	#ifdef FFW_OSX
		gl_->glGenFramebuffers(1, &fbo_);
	#else
		gl_->glGenFramebuffersEXT(1, &fbo_);
	#endif
    return true;
}

///=============================================================================
bool ffw::Framebuffer::addDepthTexture(const ffw::Texture2D* depthtexture){
    if(!created_ || depthtexture == NULL)return false;
	
	bind();
	#ifdef FFW_OSX
		gl_->glFramebufferTexture2D(GL_FRAMEBUFFER, GL_DEPTH_ATTACHMENT, GL_TEXTURE_2D, depthtexture->getHandle(), 0);
	#else
		gl_->glFramebufferTexture2DEXT(GL_FRAMEBUFFER_EXT, GL_DEPTH_ATTACHMENT, GL_TEXTURE_2D, depthtexture->getHandle(), 0);
    #endif
	
	return true;
}

///=============================================================================
bool ffw::Framebuffer::addColorTexture(const ffw::Texture2D* colortexture){
    if(!created_ || colortexture == NULL)return false;

    // Check if number of color attachments is lower than the maximum
    GLint maxColorAttachments;
    glGetIntegerv(GL_MAX_COLOR_ATTACHMENTS, &maxColorAttachments);
	if (colorcount_ > maxColorAttachments){
        return false;
    }

	bind();
	#ifdef FFW_OSX
		gl_->glFramebufferTexture2D(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0 + colorcount_, GL_TEXTURE_2D, colortexture->getHandle(), 0);
	#else
		gl_->glFramebufferTexture2DEXT(GL_FRAMEBUFFER_EXT, GL_COLOR_ATTACHMENT0 + colorcount_, GL_TEXTURE_2D, colortexture->getHandle(), 0);
	#endif
	
	colorcount_++;
    return true;
}

///=============================================================================
bool ffw::Framebuffer::addDepthRenderbuffer(const ffw::Renderbuffer2D* depthrenderbuffer){
    if(!created_ || depthrenderbuffer == NULL)return false;
	
	bind();
	#ifdef FFW_OSX
		gl_->glFramebufferRenderbuffer(GL_FRAMEBUFFER, GL_DEPTH_ATTACHMENT, GL_RENDERBUFFER, depthrenderbuffer->getHandle());
	#else
		gl_->glFramebufferRenderbuffer(GL_FRAMEBUFFER_EXT, GL_DEPTH_ATTACHMENT, GL_RENDERBUFFER, depthrenderbuffer->getHandle());
    #endif
	
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
	#ifdef FFW_OSX
		gl_->glFramebufferRenderbuffer(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0 + colorcount_, GL_RENDERBUFFER, colorrenderbuffer->getHandle());
	#else
		gl_->glFramebufferRenderbuffer(GL_FRAMEBUFFER_EXT, GL_COLOR_ATTACHMENT0 + colorcount_, GL_RENDERBUFFER, colorrenderbuffer->getHandle());
	#endif
	
	colorcount_++;
    return true;
}

///=============================================================================
bool ffw::Framebuffer::addDepthTextureMS(const ffw::Texture2DMS* depthtexture){
    if(!created_ || depthtexture == NULL)return false;
	
	bind();
	#ifdef FFW_OSX
		gl_->glFramebufferTexture2D(GL_FRAMEBUFFER, GL_DEPTH_ATTACHMENT, GL_TEXTURE_2D_MULTISAMPLE, depthtexture->getHandle(), 0);
	#else
		gl_->glFramebufferTexture2DEXT(GL_FRAMEBUFFER_EXT, GL_DEPTH_ATTACHMENT, GL_TEXTURE_2D_MULTISAMPLE, depthtexture->getHandle(), 0);
    #endif
	
	return true;
}

///=============================================================================
bool ffw::Framebuffer::addColorTextureMS(const ffw::Texture2DMS* colortexture){
    if(!created_ || colortexture == NULL)return false;

    // Check if number of color attachments is lower than the maximum
    GLint maxColorAttachments;
    glGetIntegerv(GL_MAX_COLOR_ATTACHMENTS, &maxColorAttachments);
	if (colorcount_ > maxColorAttachments){
        return false;
    }

	bind();
	#ifdef FFW_OSX
		gl_->glFramebufferTexture2D(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0 + colorcount_, GL_TEXTURE_2D_MULTISAMPLE, colortexture->getHandle(), 0);
	#else
		gl_->glFramebufferTexture2DEXT(GL_FRAMEBUFFER_EXT, GL_COLOR_ATTACHMENT0 + colorcount_, GL_TEXTURE_2D_MULTISAMPLE, colortexture->getHandle(), 0);
	#endif
	
	colorcount_++;
    return true;
}

///=============================================================================
bool ffw::Framebuffer::addDepthRenderbufferMS(const ffw::Renderbuffer2DMS* depthrenderbuffer){
    if(!created_ || depthrenderbuffer == NULL)return false;
	
	bind();
	#ifdef FFW_OSX
		gl_->glFramebufferRenderbuffer(GL_FRAMEBUFFER, GL_DEPTH_ATTACHMENT, GL_RENDERBUFFER, depthrenderbuffer->getHandle());
	#else
		gl_->glFramebufferRenderbufferEXT(GL_FRAMEBUFFER_EXT, GL_DEPTH_ATTACHMENT, GL_RENDERBUFFER, depthrenderbuffer->getHandle());
    #endif
	
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
	#ifdef FFW_OSX
		gl_->glFramebufferRenderbuffer(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0 + colorcount_, GL_RENDERBUFFER, colorrenderbuffer->getHandle());
	#else
		gl_->glFramebufferRenderbufferEXT(GL_FRAMEBUFFER_EXT, GL_COLOR_ATTACHMENT0 + colorcount_, GL_RENDERBUFFER, colorrenderbuffer->getHandle());
	#endif
	
	colorcount_++;
    return true;
}

///=============================================================================
bool ffw::Framebuffer::checkStatus(){
    if(!created_)return false;
	
	bind();
	#ifdef FFW_OSX
		//gl_->glBindFramebuffer(GL_FRAMEBUFFER, fbo_);
		GLenum status = gl_->glCheckFramebufferStatus(GL_FRAMEBUFFER);
		if (status != GL_FRAMEBUFFER_COMPLETE) {
			destroy();
			return false;
		}
		
		//gl_->glBindFramebuffer(GL_FRAMEBUFFER, 0);
	#else
		//gl_->glBindFramebufferEXT(GL_FRAMEBUFFER_EXT, fbo_);
		GLenum status = gl_->glCheckFramebufferStatusEXT(GL_FRAMEBUFFER_EXT);
		if (status != GL_FRAMEBUFFER_COMPLETE) {
			destroy();
			return false;
		}
		
		//gl_->glBindFramebufferEXT(GL_FRAMEBUFFER_EXT, 0);
	#endif
    return true;
}

///=============================================================================
bool ffw::Framebuffer::destroy(){
	#ifdef FFW_OSX
		if(created_)gl_->glDeleteFramebuffers(1, &fbo_);
	#else
		if(created_)gl_->glDeleteFramebuffersEXT(1, &fbo_);
	#endif
	colorcount_ = 0;
    created_ = false;
    return true;
}

///=============================================================================
void ffw::Framebuffer::bind() const {
	#ifdef FFW_OSX
		if(created_)gl_->glBindFramebuffer(GL_FRAMEBUFFER, fbo_);
	#else
		if(created_)gl_->glBindFramebufferEXT(GL_FRAMEBUFFER_EXT, fbo_);
	#endif
}

///=============================================================================
void ffw::Framebuffer::unbind() const {
	#ifdef FFW_OSX
		if(created_)gl_->glBindFramebuffer(GL_FRAMEBUFFER, 0);
	#else
		if(created_)gl_->glBindFramebufferEXT(GL_FRAMEBUFFER_EXT, 0);
	#endif
}
///=============================================================================
