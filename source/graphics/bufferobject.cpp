/*** This file is part of FineFramework project ***/

#include "ffw/graphics/bufferobject.h"
#include "ffw/graphics/rendercontext.h"
#include "ffw/graphics/extensions.h"


///=============================================================================
ffw::BufferObject::BufferObject(unsigned int objecttype):objecttype_(objecttype) {
    loaded_ = false;
    type_ = GL_FALSE;
    size_ = 0;
}

///=============================================================================
ffw::BufferObject::~BufferObject(){
    Destroy();
}

///=============================================================================
bool ffw::BufferObject::CheckCompability(const ffw::RenderContext* renderer){
	if(renderer == NULL)return false;
	const ffw::GlextStruct* gl_ = renderer->Glext();

	return (
		gl_->glGenBuffers			!= NULL &&
		gl_->glBindBuffer			!= NULL &&
		gl_->glBufferData			!= NULL &&
		gl_->glBufferSubData		!= NULL &&
		gl_->glDeleteBuffers		!= NULL && 
		gl_->glBufferSubData		!= NULL &&
		//gl_->glCopyBufferSubData != NULL &&
		gl_->glMapBuffer			!= NULL &&
		gl_->glUnmapBuffer		!= NULL
	);
}

///=============================================================================
bool ffw::BufferObject::Create(const RenderContext* renderer, const void* data, GLsizei size, GLenum type){
    if(loaded_)return false;
	if(!CheckCompability(renderer))return false;
	gl_ = renderer->Glext();

    // Is buffer type correct GL type?
    if(!(type == GL_STATIC_DRAW || type == GL_DYNAMIC_DRAW || type == GL_STREAM_DRAW)){
        return false;
    }

    // Remember the type of buffer we are going to Create
    type_ = type;
    // Remember length of buffer
    size_ = size;
    // Generate buffer
    gl_->glGenBuffers(1, &buffer_);
    // Bind buffer
    gl_->glBindBuffer(objecttype_, buffer_);
    // Set buffer initial data
    gl_->glBufferData(objecttype_, size, data, type);
    // UnBind buffer
    gl_->glBindBuffer(objecttype_, 0);
    loaded_ = true;
    return true;
}

///=============================================================================
bool ffw::BufferObject::SetData(const void* data, GLsizei offset, GLsizei size){
    // Do not upload new data if buffer is not dynamic/stream
    if(!(type_ == GL_STREAM_DRAW || type_ == GL_DYNAMIC_DRAW))return false;
    // Upload new data
    gl_->glBindBuffer(objecttype_, buffer_);
    gl_->glBufferSubData(objecttype_, offset, size, data);
    gl_->glBindBuffer(objecttype_, 0);
    return true;
}

///=============================================================================
bool ffw::BufferObject::CopyFrom(const BufferObject* other, GLintptr offset1, GLintptr offset2, GLsizeiptr size){
    if(other == NULL)return false;
    if(!loaded_)return false;
    if(!other->IsCreated())return false;
	if(!gl_->glCopyBufferSubData)return false;

    gl_->glBindBuffer(GL_COPY_READ_BUFFER, other->GetHandle());
    gl_->glBindBuffer(GL_COPY_WRITE_BUFFER, buffer_);

    gl_->glCopyBufferSubData(GL_COPY_READ_BUFFER, GL_COPY_WRITE_BUFFER, offset1, offset2, size);

    return true;
}

/*///=============================================================================
ffw::BufferObject& ffw::BufferObject::operator = (const ffw::BufferObject& Other){
    if(!Other.Destroy())return *this;

    type = Other.GetType();
    size = Other.GetSize();
    objectType = Other.GetObjectType();

    if(loaded)gl_->glDeleteBuffers(1, &buffer);
    CreateBuffer(NULL, size, type);

    gl_->glBindBuffer(GL_COPY_READ_BUFFER, Other.GetHandle());
    gl_->glBindBuffer(GL_COPY_WRITE_BUFFER, buffer);

    gl_->glCopyBufferSubData(GL_COPY_READ_BUFFER, GL_COPY_WRITE_BUFFER, 0, 0, Other.GetSize());
    loaded = true;
    return *this;
}*/

///=============================================================================
bool ffw::BufferObject::MapBuffer(void** pointer, GLenum access) const {
    if(!loaded_)return true;
    *pointer = gl_->glMapBuffer(objecttype_, access);
    return true;
}

///=============================================================================
bool ffw::BufferObject::UnMapBuffer() const {
    if(!loaded_)return true;
    gl_->glUnmapBuffer(objecttype_);
    return true;
}

///=============================================================================
void ffw::BufferObject::Destroy(){
    // Delete buffer
    if(loaded_)gl_->glDeleteBuffers(1, &buffer_);
    loaded_ = false;
    //initialized = false;
    size_ = 0;
    type_ = GL_FALSE;
}

///=============================================================================
void ffw::BufferObject::Bind() const {
    // Bind buffer
    if(loaded_)gl_->glBindBuffer(objecttype_, buffer_);
}

///=============================================================================
void ffw::BufferObject::Unbind() const {
    // UnBind buffer
    gl_->glBindBuffer(objecttype_, 0);
}


