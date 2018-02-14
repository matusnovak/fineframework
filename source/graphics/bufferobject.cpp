/*** This file is part of FineFramework project ***/

#include "ffw/graphics/bufferobject.h"
#include "ffw/graphics/rendercontext.h"

///=============================================================================
ffw::BufferObject::BufferObject(unsigned int objecttype):objecttype_(objecttype) {
    loaded_ = false;
    type_ = GL_FALSE;
    size_ = 0;
    buffer_ = 0;
}

///=============================================================================
ffw::BufferObject::BufferObject(BufferObject&& other):objecttype_(other.objecttype_) {
    loaded_ = false;
    type_ = GL_FALSE;
    size_ = 0;
    buffer_ = 0;
    swap(other);
}

///=============================================================================
void ffw::BufferObject::swap(BufferObject& other) {
    using std::swap;
    if(this != &other) {
        swap(objecttype_, other.objecttype_);
        swap(loaded_, other.loaded_);
        swap(type_, other.type_);
        swap(size_, other.size_);
        swap(buffer_, other.buffer_);
    }
}

///=============================================================================
ffw::BufferObject& ffw::BufferObject::operator = (BufferObject&& other) {
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
bool ffw::BufferObject::create(const void* data, GLsizei size, GLenum type){
    if(loaded_)return false;

    // is buffer type correct GL type?
    if(!(type == GL_STATIC_DRAW || type == GL_DYNAMIC_DRAW || type == GL_STREAM_DRAW)){
        return false;
    }

    // Remember the type of buffer we are going to create
    type_ = type;
    // Remember length of buffer
    size_ = size;
    // Generate buffer
    glGenBuffers(1, &buffer_);
    // bind buffer
    glBindBuffer(objecttype_, buffer_);
    // set buffer initial data
    glBufferData(objecttype_, size, data, type);
    // UnBind buffer
    //gl_->glBindBuffer(objecttype_, 0);
    loaded_ = true;
    return true;
}

///=============================================================================
bool ffw::BufferObject::resize(const void* data, GLsizei size) {
    if (!loaded_)return false;
    // bind buffer
    glBindBuffer(objecttype_, buffer_);
    // set buffer initial data
    glBufferData(objecttype_, size, data, type_);
    // Remember length of buffer
    size_ = size;
    return true;
}

///=============================================================================
bool ffw::BufferObject::setData(const void* data, GLsizei offset, GLsizei size){
    if (!loaded_)return false;
    // Do not upload new data if buffer is not dynamic/stream
    if(!(type_ == GL_STREAM_DRAW || type_ == GL_DYNAMIC_DRAW))return false;
    // Upload new data
    glBindBuffer(objecttype_, buffer_);
    glBufferSubData(objecttype_, offset, size, data);
    //gl_->glBindBuffer(objecttype_, 0);
    return true;
}

///=============================================================================
bool ffw::BufferObject::getData(void* data, GLsizei offset, GLsizei size) {
    if (!loaded_)return false;
    glBindBuffer(objecttype_, buffer_);
    glGetBufferSubData(objecttype_, offset, size, data);
    return true;
}

///=============================================================================
bool ffw::BufferObject::copyFrom(const BufferObject* other, GLintptr readoffset, GLintptr writeoffset, GLsizeiptr size){
    if(other == NULL)return false;
    if(!loaded_)return false;
    if(!other->isCreated())return false;

    glBindBuffer(GL_COPY_READ_BUFFER, other->getHandle());
    glBindBuffer(GL_COPY_WRITE_BUFFER, buffer_);

    glCopyBufferSubData(GL_COPY_READ_BUFFER, GL_COPY_WRITE_BUFFER, readoffset, writeoffset, size);

    return true;
}

/*///=============================================================================
ffw::BufferObject& ffw::BufferObject::operator = (const ffw::BufferObject& Other){
    if(!Other.destroy())return *this;

    type = Other.getType();
    size = Other.getSize();
    objectType = Other.getObjectType();

    if(loaded)gl_->glDeleteBuffers(1, &buffer);
    CreateBuffer(NULL, size, type);

    gl_->glBindBuffer(GL_COPY_READ_BUFFER, Other.getHandle());
    gl_->glBindBuffer(GL_COPY_WRITE_BUFFER, buffer);

    gl_->glCopyBufferSubData(GL_COPY_READ_BUFFER, GL_COPY_WRITE_BUFFER, 0, 0, Other.getSize());
    loaded = true;
    return *this;
}*/

///=============================================================================
bool ffw::BufferObject::mapBuffer(void** pointer, GLenum access) const {
    if(!loaded_)return true;
    *pointer = glMapBuffer(objecttype_, access);
    return true;
}

///=============================================================================
bool ffw::BufferObject::unMapBuffer() const {
    if(!loaded_)return true;
    glUnmapBuffer(objecttype_);
    return true;
}

///=============================================================================
void ffw::BufferObject::destroy(){
    // Delete buffer
    if(loaded_)glDeleteBuffers(1, &buffer_);
    loaded_ = false;
    //initialized = false;
    size_ = 0;
    type_ = GL_FALSE;
}

///=============================================================================
void ffw::BufferObject::bind() const {
    // bind buffer
    if(loaded_)glBindBuffer(objecttype_, buffer_);
}

///=============================================================================
void ffw::BufferObject::unbind() const {
    // UnBind buffer
    glBindBuffer(objecttype_, 0);
}


