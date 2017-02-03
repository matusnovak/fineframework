/*** This file is part of FineFramework project ***/

#include "ffw/graphics/framebuffer.h"
#include "ffw/graphics/rendercontext.h"

///=============================================================================
bool ffw::Framebuffer::CheckCompability(const ffw::RenderContext* renderer){
	if(renderer == NULL)return false;
	const ffw::RenderExtensions* gl_ = renderer->Glext();

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
}

///=============================================================================
ffw::Framebuffer::~Framebuffer(){
    Destroy();
}

///=============================================================================
bool ffw::Framebuffer::Create(const ffw::RenderContext* renderer){
    if(created_)return false;
	if(!CheckCompability(renderer))return false;
	created_ = true;
	gl_ = renderer->Glext();

	// Create Framebuffer
	#ifdef FFW_OSX
		gl_->glGenFramebuffers(1, &fbo_);
	#else
		gl_->glGenFramebuffersEXT(1, &fbo_);
	#endif
    return true;
}

///=============================================================================
bool ffw::Framebuffer::AddDepthTexture(const ffw::Texture2D* depthtexture){
    if(!created_ || depthtexture == NULL)return false;
	#ifdef FFW_OSX
		gl_->glFramebufferTexture2D(GL_FRAMEBUFFER, GL_DEPTH_ATTACHMENT, GL_TEXTURE_2D, depthtexture->GetHandle(), 0);
	#else
		gl_->glFramebufferTexture2DEXT(GL_FRAMEBUFFER_EXT, GL_DEPTH_ATTACHMENT, GL_TEXTURE_2D, depthtexture->GetHandle(), 0);
    #endif
	
	return true;
}

///=============================================================================
bool ffw::Framebuffer::AddColorTexture(const ffw::Texture2D* colortexture){
    if(!created_ || colortexture == NULL)return false;

    // Check if number of color attachments is lower than the maximum
    GLint maxColorAttachments;
    glGetIntegerv(GL_MAX_COLOR_ATTACHMENTS, &maxColorAttachments);
	if (colorcount_ > maxColorAttachments){
        return false;
    }

	#ifdef FFW_OSX
		gl_->glFramebufferTexture2D(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0 + colorcount_, GL_TEXTURE_2D, colortexture->GetHandle(), 0);
	#else
		gl_->glFramebufferTexture2DEXT(GL_FRAMEBUFFER_EXT, GL_COLOR_ATTACHMENT0 + colorcount_, GL_TEXTURE_2D, colortexture->GetHandle(), 0);
	#endif
	
	colorcount_++;
    return true;
}

///=============================================================================
bool ffw::Framebuffer::AddDepthRenderbuffer(const ffw::Renderbuffer2D* depthrenderbuffer){
    if(!created_ || depthrenderbuffer == NULL)return false;
	#ifdef FFW_OSX
		gl_->glFramebufferRenderbuffer(GL_FRAMEBUFFER, GL_DEPTH_ATTACHMENT, GL_RENDERBUFFER, depthrenderbuffer->GetHandle());
	#else
		gl_->glFramebufferRenderbuffer(GL_FRAMEBUFFER_EXT, GL_DEPTH_ATTACHMENT, GL_RENDERBUFFER, depthrenderbuffer->GetHandle());
    #endif
	
	return true;
}

///=============================================================================
bool ffw::Framebuffer::AddColorRenderbuffer(const ffw::Renderbuffer2D* colorrenderbuffer){
    if(!created_ || colorrenderbuffer == NULL)return false;

    // Check if number of color attachments is lower than the maximum
    GLint maxColorAttachments;
    glGetIntegerv(GL_MAX_COLOR_ATTACHMENTS, &maxColorAttachments);
	if (colorcount_ > maxColorAttachments){
        return false;
    }

	#ifdef FFW_OSX
		gl_->glFramebufferRenderbuffer(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0 + colorcount_, GL_RENDERBUFFER, colorrenderbuffer->GetHandle());
	#else
		gl_->glFramebufferRenderbuffer(GL_FRAMEBUFFER_EXT, GL_COLOR_ATTACHMENT0 + colorcount_, GL_RENDERBUFFER, colorrenderbuffer->GetHandle());
	#endif
	
	colorcount_++;
    return true;
}

///=============================================================================
bool ffw::Framebuffer::AddDepthTextureMS(const ffw::Texture2DMS* depthtexture){
    if(!created_ || depthtexture == NULL)return false;
	
	#ifdef FFW_OSX
		gl_->glFramebufferTexture2D(GL_FRAMEBUFFER, GL_DEPTH_ATTACHMENT, GL_TEXTURE_2D_MULTISAMPLE, depthtexture->GetHandle(), 0);
	#else
		gl_->glFramebufferTexture2DEXT(GL_FRAMEBUFFER_EXT, GL_DEPTH_ATTACHMENT, GL_TEXTURE_2D_MULTISAMPLE, depthtexture->GetHandle(), 0);
    #endif
	
	return true;
}

///=============================================================================
bool ffw::Framebuffer::AddColorTextureMS(const ffw::Texture2DMS* colortexture){
    if(!created_ || colortexture == NULL)return false;

    // Check if number of color attachments is lower than the maximum
    GLint maxColorAttachments;
    glGetIntegerv(GL_MAX_COLOR_ATTACHMENTS, &maxColorAttachments);
	if (colorcount_ > maxColorAttachments){
        return false;
    }

	#ifdef FFW_OSX
		gl_->glFramebufferTexture2D(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0 + colorcount_, GL_TEXTURE_2D_MULTISAMPLE, colortexture->GetHandle(), 0);
	#else
		gl_->glFramebufferTexture2DEXT(GL_FRAMEBUFFER_EXT, GL_COLOR_ATTACHMENT0 + colorcount_, GL_TEXTURE_2D_MULTISAMPLE, colortexture->GetHandle(), 0);
	#endif
	
	colorcount_++;
    return true;
}

///=============================================================================
bool ffw::Framebuffer::AddDepthRenderbufferMS(const ffw::Renderbuffer2DMS* depthrenderbuffer){
    if(!created_ || depthrenderbuffer == NULL)return false;
	
	#ifdef FFW_OSX
		gl_->glFramebufferRenderbuffer(GL_FRAMEBUFFER, GL_DEPTH_ATTACHMENT, GL_RENDERBUFFER, depthrenderbuffer->GetHandle());
	#else
		gl_->glFramebufferRenderbufferEXT(GL_FRAMEBUFFER_EXT, GL_DEPTH_ATTACHMENT, GL_RENDERBUFFER, depthrenderbuffer->GetHandle());
    #endif
	
	return true;
}

///=============================================================================
bool ffw::Framebuffer::AddColorRenderbufferMS(const ffw::Renderbuffer2DMS* colorrenderbuffer){
    if(!created_ || colorrenderbuffer == NULL)return false;

    // Check if number of color attachments is lower than the maximum
    GLint maxColorAttachments;
    glGetIntegerv(GL_MAX_COLOR_ATTACHMENTS, &maxColorAttachments);
	if (colorcount_ > maxColorAttachments){
        return false;
    }

	#ifdef FFW_OSX
		gl_->glFramebufferRenderbuffer(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0 + colorcount_, GL_RENDERBUFFER, colorrenderbuffer->GetHandle());
	#else
		gl_->glFramebufferRenderbufferEXT(GL_FRAMEBUFFER_EXT, GL_COLOR_ATTACHMENT0 + colorcount_, GL_RENDERBUFFER, colorrenderbuffer->GetHandle());
	#endif
	
	colorcount_++;
    return true;
}

///=============================================================================
bool ffw::Framebuffer::CheckStatus(){
    if(!created_)return false;
	
	#ifdef FFW_OSX
		gl_->glBindFramebuffer(GL_FRAMEBUFFER, fbo_);
		GLenum status = gl_->glCheckFramebufferStatus(GL_FRAMEBUFFER);
		if (status != GL_FRAMEBUFFER_COMPLETE) {
			Destroy();
			return false;
		}
		
		gl_->glBindFramebuffer(GL_FRAMEBUFFER, 0);
	#else
		gl_->glBindFramebufferEXT(GL_FRAMEBUFFER_EXT, fbo_);
		GLenum status = gl_->glCheckFramebufferStatusEXT(GL_FRAMEBUFFER_EXT);
		if (status != GL_FRAMEBUFFER_COMPLETE) {
			Destroy();
			return false;
		}
		
		gl_->glBindFramebufferEXT(GL_FRAMEBUFFER_EXT, 0);
	#endif
    return true;
}

///=============================================================================
bool ffw::Framebuffer::Destroy(){
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
void ffw::Framebuffer::Bind() const {
	#ifdef FFW_OSX
		if(created_)gl_->glBindFramebuffer(GL_FRAMEBUFFER, fbo_);
	#else
		if(created_)gl_->glBindFramebufferEXT(GL_FRAMEBUFFER_EXT, fbo_);
	#endif
}

///=============================================================================
void ffw::Framebuffer::Unbind() const {
	#ifdef FFW_OSX
		if(created_)gl_->glBindFramebuffer(GL_FRAMEBUFFER, 0);
	#else
		if(created_)gl_->glBindFramebufferEXT(GL_FRAMEBUFFER_EXT, 0);
	#endif
}
///=============================================================================
