/*** This file is part of FineFramework project ***/

#include "ffw/graphics/texture.h"
#include "ffw/graphics/rendercontext.h"

///=============================================================================
ffw::Texture::Texture() {
    loaded = false;
    textureformat = 0;
    internalformat = 0;
    format = 0;
    pixelformat = 0;
    buffer = 0;
    width = 0;
    height = 0;
    depth = 0;
    layers = 0;
    mipmaps = false;
    initialized = false;
    samples = 0;
    compressed = false;
}

///=============================================================================
ffw::Texture::Texture(Texture&& other) NOEXCEPT {
    loaded = false;
    textureformat = 0;
    internalformat = 0;
    format = 0;
    pixelformat = 0;
    buffer = 0;
    width = 0;
    height = 0;
    depth = 0;
    layers = 0;
    mipmaps = false;
    initialized = false;
    samples = 0;
    compressed = false;
    swap(other);
}

///=============================================================================
void ffw::Texture::swap(Texture& other) NOEXCEPT {
    if (this != &other) {
        using std::swap;
        swap(loaded, other.loaded);
        swap(textureformat, other.textureformat);
        swap(internalformat, other.internalformat);
        swap(format, other.format);
        swap(pixelformat, other.pixelformat);
        swap(buffer, other.buffer);
        swap(width, other.width);
        swap(height, other.height);
        swap(depth, other.depth);
        swap(layers, other.layers);
        swap(mipmaps, other.mipmaps);
        swap(initialized, other.initialized);
        swap(samples, other.samples);
        swap(compressed, other.compressed);
    }
}

///=============================================================================
ffw::Texture& ffw::Texture::operator = (Texture&& other) NOEXCEPT {
    if (this != &other) {
        swap(other);
    }
    return *this;
}

///=============================================================================
ffw::Texture::~Texture(){
    destroy();
}

///=============================================================================
bool ffw::Texture::generateMipmaps(){
    if(!loaded)return false;
    bind();
    glGenerateMipmap(textureformat);
    mipmaps = true;
    return true;
}

///=============================================================================
void ffw::Texture::setEnvParami(const GLenum target, const GLenum name, const GLint value) const {
    glBindTexture(textureformat, buffer);
    glTexEnvi(target, name, value);
}

///=============================================================================
void ffw::Texture::setEnvParamf(const GLenum target, const GLenum name, const GLfloat value) const {
    glBindTexture(textureformat, buffer);
    glTexEnvf(target, name, value);
}

///=============================================================================
void ffw::Texture::setTexParami(const GLenum name, const GLint value) const {
    glBindTexture(textureformat, buffer);
    glTexParameteri(textureformat, name, value);
}

///=============================================================================
void ffw::Texture::setTexParamf(const GLenum name, const GLfloat value) const {
    glBindTexture(textureformat, buffer);
    glTexParameterf(textureformat, name, value);
}

///=============================================================================
void ffw::Texture::setTexParamiv(const GLenum name, const GLint* value) const {
    glBindTexture(textureformat, buffer);
    glTexParameteriv(textureformat, name, value);
}

///=============================================================================
void ffw::Texture::setTexParamfv(const GLenum name, const GLfloat* value) const {
    glBindTexture(textureformat, buffer);
    glTexParameterfv(textureformat, name, value);
}

///=============================================================================
void ffw::Texture::setFiltering(const Texture::Filtering filtering) const {
    switch (filtering) {
        case Texture::Filtering::NEAREST: {
            setTexParami(GL_TEXTURE_MAG_FILTER, GL_NEAREST);
            setTexParami(GL_TEXTURE_MIN_FILTER, GL_NEAREST);
            break;
        }
        case Texture::Filtering::LINEAR: {
            setTexParami(GL_TEXTURE_MAG_FILTER, GL_LINEAR);
            setTexParami(GL_TEXTURE_MIN_FILTER, GL_LINEAR);
            break;
        }
        case Texture::Filtering::MIPMAP_NEAREST: {
            setTexParami(GL_TEXTURE_MAG_FILTER, GL_LINEAR_MIPMAP_NEAREST);
            setTexParami(GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_NEAREST);
            break;
        }
        case Texture::Filtering::MIPMAP_LINEAR: {
            setTexParami(GL_TEXTURE_MAG_FILTER, GL_LINEAR_MIPMAP_LINEAR);
            setTexParami(GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
            break;
        }
        default: {
            break;
        }
    }
}

///=============================================================================
void ffw::Texture::setWrapping(const Texture::Wrapping wrapping) const {
    bind();
    switch (wrapping) {
        case Texture::Wrapping::REPEAT: {
            setTexParami(GL_TEXTURE_WRAP_S, GL_REPEAT);
            setTexParami(GL_TEXTURE_WRAP_T, GL_REPEAT);
            setTexParami(GL_TEXTURE_WRAP_R, GL_REPEAT);
            break;
        }
        case Texture::Wrapping::MIRRORED_REPEAT: {
            setTexParami(GL_TEXTURE_WRAP_S, GL_MIRRORED_REPEAT);
            setTexParami(GL_TEXTURE_WRAP_T, GL_MIRRORED_REPEAT);
            setTexParami(GL_TEXTURE_WRAP_R, GL_MIRRORED_REPEAT);
            break;
        }
        case Texture::Wrapping::CLAMP_TO_EDGE: {
            setTexParami(GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
            setTexParami(GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
            setTexParami(GL_TEXTURE_WRAP_R, GL_CLAMP_TO_EDGE);
            break;
        }
        default: {
            break;
        }
    }
    unbind();
}

///=============================================================================
void ffw::Texture::bind() const{
    if(loaded)glBindTexture(textureformat, buffer);
}

///=============================================================================
void ffw::Texture::unbind() const{
    if(loaded)glBindTexture(textureformat, 0);
}

///=============================================================================
void ffw::Texture::destroy(){
    // Delete texture
    if(loaded)glDeleteTextures(1, &buffer);
    // reset variables
    loaded = false;
    textureformat = 0;
    internalformat = 0;
    format = 0;
    pixelformat = 0;
    buffer = 0;
    width = 0;
    height = 0;
    depth = 0;
    layers = 0;
    mipmaps = false;
    initialized = false;
    samples = 0;
    compressed = false;
}


