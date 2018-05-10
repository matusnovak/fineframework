/*** This file is part of FineFramework project ***/

#include "ffw/graphics/texture2darrayms.h"
#include "ffw/graphics/rendercontext.h"

///=============================================================================
ffw::Texture2DArrayMS::Texture2DArrayMS() {
    textureformat = GL_TEXTURE_2D_MULTISAMPLE_ARRAY;
}

///=============================================================================
ffw::Texture2DArrayMS::Texture2DArrayMS(Texture2DArrayMS&& other) NOEXCEPT : Texture2DArrayMS() {
    Texture::swap(other);
}

///=============================================================================
ffw::Texture2DArrayMS& ffw::Texture2DArrayMS::operator = (ffw::Texture2DArrayMS&& other) NOEXCEPT {
    if (this != &other) {
        Texture::swap(other);
    }
    return *this;
}

///=============================================================================
bool ffw::Texture2DArrayMS::create(const GLsizei width, const GLsizei height, const GLsizei layers,
    const GLenum internalformat, const GLint samples){

    if(loaded)return false;
    loaded = true;

    this->width           = width;
    this->height          = height;
    this->layers          = layers;
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
    glBindTexture(GL_TEXTURE_2D_MULTISAMPLE_ARRAY, buffer);

    glTexImage3DMultisample(
        GL_TEXTURE_2D_MULTISAMPLE_ARRAY, samples, internalformat, 
        width, height, layers, GL_FALSE
    );

    int test;
    glGetTexLevelParameteriv(GL_TEXTURE_2D_MULTISAMPLE_ARRAY, 0, GL_TEXTURE_WIDTH, &test);
    if(test != width){
        destroy();
        return false;
    }

    glTexParameteri(GL_TEXTURE_2D_MULTISAMPLE_ARRAY, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D_MULTISAMPLE_ARRAY, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexParameterf(GL_TEXTURE_2D_MULTISAMPLE_ARRAY, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameterf(GL_TEXTURE_2D_MULTISAMPLE_ARRAY, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_BLEND);
    return true;
}

///=============================================================================
bool ffw::Texture2DArrayMS::resize(const GLsizei width, const GLsizei height,
    const GLsizei layers, const GLint samples){

    if(!loaded)return false;
    this->width = width;
    this->height = height;
    this->layers = layers;
    this->samples = samples;
    glBindTexture(GL_TEXTURE_2D_MULTISAMPLE_ARRAY, buffer);
    glTexImage3DMultisample(
        GL_TEXTURE_2D_MULTISAMPLE_ARRAY, samples, internalformat, 
        width, height, layers, GL_FALSE
    );
    return true;
}