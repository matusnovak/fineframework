/*** This file is part of FineFramework project ***/

#include "ffw/graphics/texturecubemap.h"
#include "ffw/graphics/rendercontext.h"

///=============================================================================
bool ffw::TextureCubemap::checkCompability(const ffw::RenderContext* Renderer){
	return true;
}

///=============================================================================
ffw::TextureCubemap::TextureCubemap():Texture(){
    textureformat_ = GL_TEXTURE_CUBE_MAP;
}

///=============================================================================
ffw::TextureCubemap::TextureCubemap(TextureCubemap&& second) : TextureCubemap() {
	Texture::swap(second);
}

///=============================================================================
ffw::TextureCubemap& ffw::TextureCubemap::operator = (ffw::TextureCubemap&& other) {
	if (this != &other) {
		Texture::swap(other);
	}
	return *this;
}

///=============================================================================
ffw::TextureCubemap::~TextureCubemap(){
	destroy();
}

///=============================================================================
bool ffw::TextureCubemap::create(const ffw::RenderContext* renderer, GLsizei width, GLsizei height, GLenum internalformat, GLenum format, GLenum pixelformat){
    if(loaded_)return false;
	if(!checkCompability(renderer))return false;
	loaded_ = true;
    gl_ = static_cast<const RenderExtensions*>(renderer);

    glGenTextures(1, &buffer_);
    glBindTexture(GL_TEXTURE_CUBE_MAP, buffer_);

    width_           = width;
    height_          = height;
    layers_          = 0;
    depth_           = 0;
    internalformat_  = internalformat;
    format_          = format;
    pixelformat_     = pixelformat;
	samples_		 = 0;

	for (int i = 0; i < 6; i++) {
		glTexImage2D(GL_TEXTURE_CUBE_MAP_POSITIVE_X + i, 0, internalformat_, width_, height_, 0, format_, pixelformat_, NULL);

		int test;
		glGetTexLevelParameteriv(GL_TEXTURE_CUBE_MAP_POSITIVE_X + i, 0, GL_TEXTURE_WIDTH, &test);
		if(test != width){
			destroy();
			return false;
		}
	}

    glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexParameterf(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
    glTexParameterf(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
	glTexParameterf(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_R, GL_CLAMP_TO_EDGE);
    glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_BLEND);
    return true;
}

///=============================================================================
bool ffw::TextureCubemap::resize(GLsizei width, GLsizei height){
	if(!loaded_)return false;
	if(width <= 0)return false;
	width_ = width;
	height_ = height;
	glBindTexture(GL_TEXTURE_CUBE_MAP, buffer_);
	for (int i = 0; i < 6; i++) {
		glTexImage2D(GL_TEXTURE_CUBE_MAP_POSITIVE_X + i, 0, internalformat_, width_, height_, 0, format_, pixelformat_, NULL);
	}
	return true;
}

///=============================================================================
bool ffw::TextureCubemap::setPixels(GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, int side, const void* pixels){
    if(!loaded_)return false;
	if (side < 0 || side >= 6)return false;
	glBindTexture(GL_TEXTURE_CUBE_MAP, buffer_);
	glTexSubImage2D(GL_TEXTURE_CUBE_MAP_POSITIVE_X + side, level, xoffset, yoffset, width, height, format_, pixelformat_, pixels);
    return true;
}

///=============================================================================
bool ffw::TextureCubemap::getPixels(void* pixels){
    if(!loaded_)return false;
	glBindTexture(GL_TEXTURE_CUBE_MAP, buffer_);
	glGetTexImage(GL_TEXTURE_CUBE_MAP, 0, format_, pixelformat_, pixels);
    return true;
}
