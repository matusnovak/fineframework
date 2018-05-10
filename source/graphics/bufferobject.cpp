/*** This file is part of FineFramework project ***/

#include "ffw/graphics/bufferobject.h"
#include "ffw/graphics/rendercontext.h"

///=============================================================================
ffw::BufferObject::BufferObject(const GLenum objecttype):objecttype(objecttype) {
    loaded = false;
    type = GL_FALSE;
    size = 0;
    buffer = 0;
}

///=============================================================================
ffw::BufferObject::BufferObject(BufferObject&& other) NOEXCEPT :objecttype(other.objecttype) {
    loaded = false;
    type = GL_FALSE;
    size = 0;
    buffer = 0;
    swap(other);
}

///=============================================================================
void ffw::BufferObject::swap(BufferObject& other) NOEXCEPT {
    using std::swap;
    if(this != &other) {
        swap(objecttype, other.objecttype);
        swap(loaded, other.loaded);
        swap(type, other.type);
        swap(size, other.size);
        swap(buffer, other.buffer);
    }
}

///=============================================================================
ffw::BufferObject& ffw::BufferObject::operator = (BufferObject&& other) NOEXCEPT {
    if(this != &other) {
        swap(other);
    }
    return *this;
}

///=============================================================================
ffw::BufferObject::~BufferObject(){
    destroy();
}

///=============================================================================
bool ffw::BufferObject::create(const GLvoid* data, const GLsizei size, const GLenum type){
    if(loaded)return false;

    // is buffer type correct GL type?
    if(!(type == GL_STATIC_DRAW || type == GL_DYNAMIC_DRAW || type == GL_STREAM_DRAW)){
        return false;
    }

    // Remember the type of buffer we are going to create
    this->type = type;
    // Remember length of buffer
    this->size = size;
    // Generate buffer
    glGenBuffers(1, &buffer);
    // bind buffer
    glBindBuffer(objecttype, buffer);
    // set buffer initial data
    glBufferData(objecttype, size, data, type);
    // UnBind buffer
    loaded = true;
    return true;
}

///=============================================================================
bool ffw::BufferObject::resize(const GLvoid* data, const GLsizei size) {
    if (!loaded)return false;
    // bind buffer
    glBindBuffer(objecttype, buffer);
    // set buffer initial data
    glBufferData(objecttype, size, data, type);
    // Remember length of buffer
    this->size = size;
    return true;
}

///=============================================================================
bool ffw::BufferObject::setData(const GLvoid* data, const GLsizei offset, const GLsizei size) {
    if (!loaded)return false;
    // Do not upload new data if buffer is not dynamic/stream
    if(!(type == GL_STREAM_DRAW || type == GL_DYNAMIC_DRAW))return false;
    // Upload new data
    glBindBuffer(objecttype, buffer);
    glBufferSubData(objecttype, offset, size, data);
    return true;
}

///=============================================================================
bool ffw::BufferObject::getData(GLvoid* data, const GLsizei offset, const GLsizei size) {
    if (!loaded)return false;
    glBindBuffer(objecttype, buffer);
    glGetBufferSubData(objecttype, offset, size, data);
    return true;
}

///=============================================================================
std::vector<uint8_t> ffw::BufferObject::getData(const GLsizei offset, const GLsizei size) {
    std::vector<uint8_t> ret;
    if (!loaded)return ret;

    ret.resize(size);
    getData(&ret[0], offset, size);
    return ret;
}

///=============================================================================
bool ffw::BufferObject::copyFrom(const BufferObject* other, const GLintptr readoffset, 
    const GLintptr writeoffset, const GLsizeiptr size){

    if(other == nullptr)return false;
    if(!loaded)return false;
    if(!other->isCreated())return false;

    glBindBuffer(GL_COPY_READ_BUFFER, other->getHandle());
    glBindBuffer(GL_COPY_WRITE_BUFFER, buffer);

    glCopyBufferSubData(GL_COPY_READ_BUFFER, GL_COPY_WRITE_BUFFER, readoffset, writeoffset, size);

    return true;
}

///=============================================================================
bool ffw::BufferObject::mapBuffer(GLvoid** pointer, const GLenum access) const {
    if(!loaded || pointer == nullptr)return false;
    *pointer = glMapBuffer(objecttype, access);
    return true;
}

///=============================================================================
bool ffw::BufferObject::unMapBuffer() const {
    if(!loaded)return false;
    glUnmapBuffer(objecttype);
    return true;
}

///=============================================================================
bool ffw::BufferObject::mapBufferRange(GLvoid** pointer, const GLsizei offset,
    const GLsizei size, const GLenum access) const {

    if (!loaded || pointer == nullptr)return false;
    *pointer = glMapBufferRange(objecttype, offset, size, access);
    return true;
}

///=============================================================================
bool ffw::BufferObject::flushMappedBufferRange(const GLsizei offset, const GLsizei size) const {
    if (!loaded)return false;
    glFlushMappedBufferRange(objecttype, offset, size);
    return true;
}

///=============================================================================
void ffw::BufferObject::destroy(){
    // Delete buffer
    if(loaded)glDeleteBuffers(1, &buffer);
    loaded = false;
    //initialized = false;
    size = 0;
    type = GL_FALSE;
}

///=============================================================================
void ffw::BufferObject::bind() const {
    // bind buffer
    if(loaded)glBindBuffer(objecttype, buffer);
}

///=============================================================================
void ffw::BufferObject::unbind() const {
    // UnBind buffer
    glBindBuffer(objecttype, 0);
}


