---
search: false
---

# class ffw::BufferObject



Inherited by the following classes: **[ffw::Ibo](classffw_1_1_ibo.md)**, **[ffw::Vbo](classffw_1_1_vbo.md)**

## Protected Attributes

|Type|Name|
|-----|-----|
|**[GLenum](glcorearb_8h.md#1a7efd7809e1632cdae75603fd1fee61c0)**|[**type**](classffw_1_1_buffer_object.md#1a46d80f435e947073be9a3ac22b713a3d)|
|**[GLenum](glcorearb_8h.md#1a7efd7809e1632cdae75603fd1fee61c0)**|[**objecttype**](classffw_1_1_buffer_object.md#1a372e9b7345b0ba283a9204efe3e48bf0)|
|bool|[**loaded**](classffw_1_1_buffer_object.md#1a6e9ced3549b696dd81b944738b5216c9)|
|**[GLuint](glcorearb_8h.md#1aa311c7f0d6ec4f1a33f9235c3651b86b)**|[**buffer**](classffw_1_1_buffer_object.md#1a447868d7892c8912a42786e149c4734b)|
|**[GLsizei](glcorearb_8h.md#1a9289d5b99dc1f27f01480360f2e18ae0)**|[**size**](classffw_1_1_buffer_object.md#1acb5ab72500d6ee93fd1796cdf499f3ab)|


## Public Functions

|Type|Name|
|-----|-----|
||[**BufferObject**](classffw_1_1_buffer_object.md#1af6a7dd8584b02465d3f74bf33a53c3b3) (**[GLenum](glcorearb_8h.md#1a7efd7809e1632cdae75603fd1fee61c0)** objecttype) <br>Creates an empty buffer object with specific target type. |
||[**BufferObject**](classffw_1_1_buffer_object.md#1ad6ff999336983d34e3c26717dc1d5fea) (const **[BufferObject](classffw_1_1_buffer_object.md)** & other) = delete |
||[**BufferObject**](classffw_1_1_buffer_object.md#1a37f7b9c01158768e2aba85b231e576a6) (**[BufferObject](classffw_1_1_buffer_object.md)** && other) |
|void|[**swap**](classffw_1_1_buffer_object.md#1aadaaee6d8097e3d458e1de6ba045a3e1) (**[BufferObject](classffw_1_1_buffer_object.md)** & other) |
|virtual |[**~BufferObject**](classffw_1_1_buffer_object.md#1a00c4c0a161af2fff85a8a13f4bc5df53) () |
|bool|[**isCreated**](classffw_1_1_buffer_object.md#1a877ea57b654445340f681833f4653554) () const <br>Returns true if the object has been allocated. |
|bool|[**create**](classffw_1_1_buffer_object.md#1a605d4541122f61b255791cb5ecc3f32a) (const **[GLvoid](glcorearb_8h.md#1a1e5eb1ac5e47603cc80ab58338b92393)** \* data, **[GLsizei](glcorearb_8h.md#1a9289d5b99dc1f27f01480360f2e18ae0)** size, **[GLenum](glcorearb_8h.md#1a7efd7809e1632cdae75603fd1fee61c0)** type) <br>Allocates the buffer and copies the data. |
|bool|[**resize**](classffw_1_1_buffer_object.md#1aa9c35e57bddd038de4e3586307a202db) (const **[GLvoid](glcorearb_8h.md#1a1e5eb1ac5e47603cc80ab58338b92393)** \* data, **[GLsizei](glcorearb_8h.md#1a9289d5b99dc1f27f01480360f2e18ae0)** size) <br>Resizes the buffer and copies the data. |
|bool|[**setData**](classffw_1_1_buffer_object.md#1af604b29c8a40a0cb6a4242e8a3691edb) (const **[GLvoid](glcorearb_8h.md#1a1e5eb1ac5e47603cc80ab58338b92393)** \* data, **[GLsizei](glcorearb_8h.md#1a9289d5b99dc1f27f01480360f2e18ae0)** offset, **[GLsizei](glcorearb_8h.md#1a9289d5b99dc1f27f01480360f2e18ae0)** size) <br>Updates a subset of the buffer with data. |
|bool|[**mapBuffer**](classffw_1_1_buffer_object.md#1a82152741f657ce0b7b23f82b5b7def0e) (**[GLvoid](glcorearb_8h.md#1a1e5eb1ac5e47603cc80ab58338b92393)** \*\* pointer, **[GLenum](glcorearb_8h.md#1a7efd7809e1632cdae75603fd1fee61c0)** access) const <br>Map all of a buffer object's data store into the client's address space. |
|bool|[**mapBufferRange**](classffw_1_1_buffer_object.md#1acdb9c4d83d401afb2aa999eac18bd9ad) (**[GLvoid](glcorearb_8h.md#1a1e5eb1ac5e47603cc80ab58338b92393)** \*\* pointer, **[GLsizei](glcorearb_8h.md#1a9289d5b99dc1f27f01480360f2e18ae0)** offset, **[GLsizei](glcorearb_8h.md#1a9289d5b99dc1f27f01480360f2e18ae0)** size, **[GLenum](glcorearb_8h.md#1a7efd7809e1632cdae75603fd1fee61c0)** access) const <br>Map all or part of a buffer object's data store into the client's address space. |
|bool|[**flushMappedBufferRange**](classffw_1_1_buffer_object.md#1ab54d196e3fe00584e9a052ea4dcbba35) (**[GLsizei](glcorearb_8h.md#1a9289d5b99dc1f27f01480360f2e18ae0)** offset, **[GLsizei](glcorearb_8h.md#1a9289d5b99dc1f27f01480360f2e18ae0)** size) const <br>Indicate modifications to a range of a mapped buffer. |
|bool|[**unMapBuffer**](classffw_1_1_buffer_object.md#1afbded962211ca5793ce084407ff22c35) () const <br>Release the mapping of a buffer object's data store into the client's address space. |
|void|[**destroy**](classffw_1_1_buffer_object.md#1a1eb4517db98b66ff15203f0d0cd5b09a) () <br>Deletes the buffer. |
|void|[**bind**](classffw_1_1_buffer_object.md#1aea63671d9f693c6579de3687d3c86522) () const <br>Binds the buffer object. |
|void|[**unbind**](classffw_1_1_buffer_object.md#1ae1b6294bf453ce5dc502e5a709a3602b) () const <br>Unbinds the buffer object and sets the current buffer object to zero. |
|**[GLuint](glcorearb_8h.md#1aa311c7f0d6ec4f1a33f9235c3651b86b)**|[**getHandle**](classffw_1_1_buffer_object.md#1a91a092c89eefb6283c661286eed97c0b) () const <br>Returns the OpenGL named object (the handle) |
|**[GLsizei](glcorearb_8h.md#1a9289d5b99dc1f27f01480360f2e18ae0)**|[**getSize**](classffw_1_1_buffer_object.md#1a0826254d4cc963579df7d30be4dc6df0) () const <br>Returns the size of the buffer in bytes. |
|**[GLenum](glcorearb_8h.md#1a7efd7809e1632cdae75603fd1fee61c0)**|[**getType**](classffw_1_1_buffer_object.md#1ad65206cc6584279f50cf0c5bdf322b48) () const <br>Returns the access type of the buffer as GL\_READ\_ONLY, GL\_WRITE\_ONLY, or GL\_READ\_WRITE. |
|**[GLenum](glcorearb_8h.md#1a7efd7809e1632cdae75603fd1fee61c0)**|[**getObjectType**](classffw_1_1_buffer_object.md#1a372036e3985b38fa018a92cc1981d13a) () const <br>Returns the object type of the buffer specified during the constructor. |
|bool|[**copyFrom**](classffw_1_1_buffer_object.md#1a27f6a31a9969d1df3760929a2ab52c33) (const **[BufferObject](classffw_1_1_buffer_object.md)** \* other, **[GLintptr](glcorearb_8h.md#1a0374caf1f25a139da21f84d81f637c23)** readoffset, **[GLintptr](glcorearb_8h.md#1a0374caf1f25a139da21f84d81f637c23)** writeoffset, **[GLsizeiptr](glcorearb_8h.md#1aa4edc01036f13fcf17e0b1baf6c70ea7)** size) <br>Copy all or part of the data store of a buffer object to the data store of another buffer object. |
|bool|[**getData**](classffw_1_1_buffer_object.md#1af5c46513c50ba9c093e21e176e42b92a) (**[GLvoid](glcorearb_8h.md#1a1e5eb1ac5e47603cc80ab58338b92393)** \* data, **[GLsizei](glcorearb_8h.md#1a9289d5b99dc1f27f01480360f2e18ae0)** offset, **[GLsizei](glcorearb_8h.md#1a9289d5b99dc1f27f01480360f2e18ae0)** size) <br>Reads a subset of a buffer object's data store. |
|std::vector< uint8\_t >|[**getData**](classffw_1_1_buffer_object.md#1a0d137e4c96b18846ff983676f87f0631) (**[GLsizei](glcorearb_8h.md#1a9289d5b99dc1f27f01480360f2e18ae0)** offset, **[GLsizei](glcorearb_8h.md#1a9289d5b99dc1f27f01480360f2e18ae0)** size) <br>Returns a subset of a buffer object's data store. |
|**[BufferObject](classffw_1_1_buffer_object.md)** &|[**operator=**](classffw_1_1_buffer_object.md#1a91e529ace60c203a072fa90c36296330) (const **[BufferObject](classffw_1_1_buffer_object.md)** & other) = delete |
|**[BufferObject](classffw_1_1_buffer_object.md)** &|[**operator=**](classffw_1_1_buffer_object.md#1a5c27a28aff387d5695427b4516ae5b91) (**[BufferObject](classffw_1_1_buffer_object.md)** && other) |


## Protected Attributes Documentation

### variable <a id="1a46d80f435e947073be9a3ac22b713a3d" href="#1a46d80f435e947073be9a3ac22b713a3d">type</a>

```cpp
GLenum ffw::BufferObject::type;
```



### variable <a id="1a372e9b7345b0ba283a9204efe3e48bf0" href="#1a372e9b7345b0ba283a9204efe3e48bf0">objecttype</a>

```cpp
GLenum ffw::BufferObject::objecttype;
```



### variable <a id="1a6e9ced3549b696dd81b944738b5216c9" href="#1a6e9ced3549b696dd81b944738b5216c9">loaded</a>

```cpp
bool ffw::BufferObject::loaded;
```



### variable <a id="1a447868d7892c8912a42786e149c4734b" href="#1a447868d7892c8912a42786e149c4734b">buffer</a>

```cpp
GLuint ffw::BufferObject::buffer;
```



### variable <a id="1acb5ab72500d6ee93fd1796cdf499f3ab" href="#1acb5ab72500d6ee93fd1796cdf499f3ab">size</a>

```cpp
GLsizei ffw::BufferObject::size;
```



## Public Functions Documentation

### function <a id="1af6a7dd8584b02465d3f74bf33a53c3b3" href="#1af6a7dd8584b02465d3f74bf33a53c3b3">BufferObject</a>

```cpp
ffw::BufferObject::BufferObject (
    GLenum objecttype
)
```

Creates an empty buffer object with specific target type. 

During the constructor execution, everything is set to defaults and no actual data is allocated. 

**Parameters:**


* _objecttype_ Allowed values are GL\_ARRAY\_BUFFER, GL\_ATOMIC\_COUNTER\_BUFFER, GL\_COPY\_READ\_BUFFER, GL\_COPY\_WRITE\_BUFFER, GL\_DISPATCH\_INDIRECT\_BUFFER, GL\_DRAW\_INDIRECT\_BUFFER, GL\_ELEMENT\_ARRAY\_BUFFER, GL\_PIXEL\_PACK\_BUFFER, GL\_PIXEL\_UNPACK\_BUFFER, GL\_QUERY\_BUFFER, GL\_SHADER\_STORAGE\_BUFFER, GL\_TEXTURE\_BUFFER, GL\_TRANSFORM\_FEEDBACK\_BUFFER, or GL\_UNIFORM\_BUFFER 



### function <a id="1ad6ff999336983d34e3c26717dc1d5fea" href="#1ad6ff999336983d34e3c26717dc1d5fea">BufferObject</a>

```cpp
ffw::BufferObject::BufferObject (
    const BufferObject & other
) = delete
```



### function <a id="1a37f7b9c01158768e2aba85b231e576a6" href="#1a37f7b9c01158768e2aba85b231e576a6">BufferObject</a>

```cpp
ffw::BufferObject::BufferObject (
    BufferObject && other
)
```



### function <a id="1aadaaee6d8097e3d458e1de6ba045a3e1" href="#1aadaaee6d8097e3d458e1de6ba045a3e1">swap</a>

```cpp
void ffw::BufferObject::swap (
    BufferObject & other
)
```



### function <a id="1a00c4c0a161af2fff85a8a13f4bc5df53" href="#1a00c4c0a161af2fff85a8a13f4bc5df53">~BufferObject</a>

```cpp
virtual ffw::BufferObject::~BufferObject ()
```



### function <a id="1a877ea57b654445340f681833f4653554" href="#1a877ea57b654445340f681833f4653554">isCreated</a>

```cpp
bool ffw::BufferObject::isCreated () const
```

Returns true if the object has been allocated. 


### function <a id="1a605d4541122f61b255791cb5ecc3f32a" href="#1a605d4541122f61b255791cb5ecc3f32a">create</a>

```cpp
bool ffw::BufferObject::create (
    const GLvoid * data,
    GLsizei size,
    GLenum type
)
```

Allocates the buffer and copies the data. 



**Parameters:**


* _data_ Specifies a pointer to data that will be copied into the data store for initialization, or NULL if no data is to be copied. 
* _size_ Specifies the size in bytes of the buffer object's new data store. 
* _type_ Specifies the expected usage pattern of the data store. The symbolic constant must be GL\_STREAM\_DRAW, GL\_STREAM\_READ, GL\_STREAM\_COPY, GL\_STATIC\_DRAW, GL\_STATIC\_READ, GL\_STATIC\_COPY, GL\_DYNAMIC\_DRAW, GL\_DYNAMIC\_READ, or GL\_DYNAMIC\_COPY. 



### function <a id="1aa9c35e57bddd038de4e3586307a202db" href="#1aa9c35e57bddd038de4e3586307a202db">resize</a>

```cpp
bool ffw::BufferObject::resize (
    const GLvoid * data,
    GLsizei size
)
```

Resizes the buffer and copies the data. 



**Parameters:**


* _data_ Specifies a pointer to data that will be copied into the data store for initialization, or NULL if no data is to be copied. 
* _size_ Specifies the size in bytes of the buffer object's new data store. 



### function <a id="1af604b29c8a40a0cb6a4242e8a3691edb" href="#1af604b29c8a40a0cb6a4242e8a3691edb">setData</a>

```cpp
bool ffw::BufferObject::setData (
    const GLvoid * data,
    GLsizei offset,
    GLsizei size
)
```

Updates a subset of the buffer with data. 



**Parameters:**


* _data_ Specifies a pointer to the new data that will be copied into the data store. 
* _offset_ Specifies the offset into the buffer object's data store where data replacement will begin, measured in bytes. 
* _size_ Specifies the size in bytes of the data store region being replaced. 



### function <a id="1a82152741f657ce0b7b23f82b5b7def0e" href="#1a82152741f657ce0b7b23f82b5b7def0e">mapBuffer</a>

```cpp
bool ffw::BufferObject::mapBuffer (
    GLvoid ** pointer,
    GLenum access
) const
```

Map all of a buffer object's data store into the client's address space. 



**Parameters:**


* _pointer_ Pointer to the client space address. The data can then be directly read and/or written relative to the pointer. 
* _access_ Specifies the access policy for glMapBuffer and glMapNamedBuffer, indicating whether it will be possible to read from, write to, or both read from and write to the buffer object's mapped data store. The symbolic constant must be GL\_READ\_ONLY, GL\_WRITE\_ONLY, or GL\_READ\_WRITE. 



### function <a id="1acdb9c4d83d401afb2aa999eac18bd9ad" href="#1acdb9c4d83d401afb2aa999eac18bd9ad">mapBufferRange</a>

```cpp
bool ffw::BufferObject::mapBufferRange (
    GLvoid ** pointer,
    GLsizei offset,
    GLsizei size,
    GLenum access
) const
```

Map all or part of a buffer object's data store into the client's address space. 



**Parameters:**


* _pointer_ Pointer to the client space address. The data can then be directly read and/or written relative to the pointer. 
* _offset_ Specifies the starting offset within the buffer of the range to be mapped. 
* _size_ Specifies the length of the range to be mapped. 
* _access_ Specifies the access policy for glMapBuffer and glMapNamedBuffer, indicating whether it will be possible to read from, write to, or both read from and write to the buffer object's mapped data store. The symbolic constant must be GL\_READ\_ONLY, GL\_WRITE\_ONLY, or GL\_READ\_WRITE. 



### function <a id="1ab54d196e3fe00584e9a052ea4dcbba35" href="#1ab54d196e3fe00584e9a052ea4dcbba35">flushMappedBufferRange</a>

```cpp
bool ffw::BufferObject::flushMappedBufferRange (
    GLsizei offset,
    GLsizei size
) const
```

Indicate modifications to a range of a mapped buffer. 



**Parameters:**


* _offset_ Specifies the start of the buffer subrange, in bytes. 
* _size_ Specifies the length of the buffer subrange, in bytes. 



### function <a id="1afbded962211ca5793ce084407ff22c35" href="#1afbded962211ca5793ce084407ff22c35">unMapBuffer</a>

```cpp
bool ffw::BufferObject::unMapBuffer () const
```

Release the mapping of a buffer object's data store into the client's address space. 


### function <a id="1a1eb4517db98b66ff15203f0d0cd5b09a" href="#1a1eb4517db98b66ff15203f0d0cd5b09a">destroy</a>

```cpp
void ffw::BufferObject::destroy ()
```

Deletes the buffer. 


### function <a id="1aea63671d9f693c6579de3687d3c86522" href="#1aea63671d9f693c6579de3687d3c86522">bind</a>

```cpp
void ffw::BufferObject::bind () const
```

Binds the buffer object. 


### function <a id="1ae1b6294bf453ce5dc502e5a709a3602b" href="#1ae1b6294bf453ce5dc502e5a709a3602b">unbind</a>

```cpp
void ffw::BufferObject::unbind () const
```

Unbinds the buffer object and sets the current buffer object to zero. 


### function <a id="1a91a092c89eefb6283c661286eed97c0b" href="#1a91a092c89eefb6283c661286eed97c0b">getHandle</a>

```cpp
GLuint ffw::BufferObject::getHandle () const
```

Returns the OpenGL named object (the handle) 


### function <a id="1a0826254d4cc963579df7d30be4dc6df0" href="#1a0826254d4cc963579df7d30be4dc6df0">getSize</a>

```cpp
GLsizei ffw::BufferObject::getSize () const
```

Returns the size of the buffer in bytes. 


### function <a id="1ad65206cc6584279f50cf0c5bdf322b48" href="#1ad65206cc6584279f50cf0c5bdf322b48">getType</a>

```cpp
GLenum ffw::BufferObject::getType () const
```

Returns the access type of the buffer as GL\_READ\_ONLY, GL\_WRITE\_ONLY, or GL\_READ\_WRITE. 


### function <a id="1a372036e3985b38fa018a92cc1981d13a" href="#1a372036e3985b38fa018a92cc1981d13a">getObjectType</a>

```cpp
GLenum ffw::BufferObject::getObjectType () const
```

Returns the object type of the buffer specified during the constructor. 


### function <a id="1a27f6a31a9969d1df3760929a2ab52c33" href="#1a27f6a31a9969d1df3760929a2ab52c33">copyFrom</a>

```cpp
bool ffw::BufferObject::copyFrom (
    const BufferObject * other,
    GLintptr readoffset,
    GLintptr writeoffset,
    GLsizeiptr size
)
```

Copy all or part of the data store of a buffer object to the data store of another buffer object. 



**Parameters:**


* _other_ The other source object to copy data from 
* _readoffset_ Specifies the offset, in bytes, within the data store of the source buffer object at which data will be read. 
* _writeoffset_ Specifies the offset, in bytes, within the data store of the destination buffer object at which data will be written. 
* _size_ Specifies the size, in bytes, of the data to be copied from the source buffer object to the destination buffer object. 



### function <a id="1af5c46513c50ba9c093e21e176e42b92a" href="#1af5c46513c50ba9c093e21e176e42b92a">getData</a>

```cpp
bool ffw::BufferObject::getData (
    GLvoid * data,
    GLsizei offset,
    GLsizei size
)
```

Reads a subset of a buffer object's data store. 



**Parameters:**


* _data_ Specifies a pointer to the location where buffer object data is returned. 
* _offset_ Specifies the offset into the buffer object's data store from which data will be returned, measured in bytes. 
* _size_ Specifies the size in bytes of the data store region being returned. 



### function <a id="1a0d137e4c96b18846ff983676f87f0631" href="#1a0d137e4c96b18846ff983676f87f0631">getData</a>

```cpp
std::vector< uint8_t > ffw::BufferObject::getData (
    GLsizei offset,
    GLsizei size
)
```

Returns a subset of a buffer object's data store. 



**Parameters:**


* _offset_ Specifies the offset into the buffer object's data store from which data will be returned, measured in bytes. 
* _size_ Specifies the size in bytes of the data store region being returned. 



**Returns:**

a vector of uint8\_t 




### function <a id="1a91e529ace60c203a072fa90c36296330" href="#1a91e529ace60c203a072fa90c36296330">operator=</a>

```cpp
BufferObject & ffw::BufferObject::operator= (
    const BufferObject & other
) = delete
```



### function <a id="1a5c27a28aff387d5695427b4516ae5b91" href="#1a5c27a28aff387d5695427b4516ae5b91">operator=</a>

```cpp
BufferObject & ffw::BufferObject::operator= (
    BufferObject && other
)
```





----------------------------------------
The documentation for this class was generated from the following file: `include/ffw/graphics/bufferobject.h`
