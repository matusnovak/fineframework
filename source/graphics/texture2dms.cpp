/*** This file is part of FineFramework project ***/

#include "ffw/graphics/texture2dms.h"
#include "ffw/graphics/rendercontext.h"

///=============================================================================
ffw::Texture2DMS::Texture2DMS(){
    textureformat = GL_TEXTURE_2D_MULTISAMPLE;
}

///=============================================================================
ffw::Texture2DMS::Texture2DMS(Texture2DMS&& other) NOEXCEPT : Texture2DMS() {
    Texture::swap(other);
}

///=============================================================================
ffw::Texture2DMS& ffw::Texture2DMS::operator = (ffw::Texture2DMS&& other) NOEXCEPT {
    if (this != &other) {
        Texture::swap(other);
    }
    return *this;
}

///=============================================================================
bool ffw::Texture2DMS::create(const GLsizei width, const GLsizei height,
    const GLenum internalformat, const GLint samples){

    if(loaded)return false;
    loaded = true;

    this->width           = width;
    this->height          = height;
    this->layers          = 0;
    this->depth           = 0;
    this->internalformat  = internalformat;
    this->format          = 0;
    this->pixelformat     = 0;
    this->samples         = samples;

    if(isCompressed()) {
        destroy();
        return false;
    }

    glGenTextures(1, &buffer);
    glBindTexture(GL_TEXTURE_2D_MULTISAMPLE, buffer);

    glTexImage2DMultisample(
        GL_TEXTURE_2D_MULTISAMPLE, samples, internalformat,
        width, height, GL_FALSE
    );

    int test;
    glGetTexLevelParameteriv(GL_TEXTURE_2D_MULTISAMPLE, 0, GL_TEXTURE_WIDTH, &test);
    if(test != width){
        destroy();
        return false;
    }

    glTexParameteri(GL_TEXTURE_2D_MULTISAMPLE, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D_MULTISAMPLE, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexParameterf(GL_TEXTURE_2D_MULTISAMPLE, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameterf(GL_TEXTURE_2D_MULTISAMPLE, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_BLEND);
    return true;
}

///=============================================================================
bool ffw::Texture2DMS::resize(const GLsizei width, const GLsizei height, const GLint samples){
    if(!loaded)return false;
    this->width = width;
    this->height = height;
    this->samples = samples;
    glBindTexture(GL_TEXTURE_2D_MULTISAMPLE, buffer);
    glTexImage2DMultisample(
        GL_TEXTURE_2D_MULTISAMPLE, samples, internalformat, 
        width, height, GL_FALSE
    );
    return true;
}