---
search: false
---

# class ffw::Vbo

**[BufferObject](classffw_1_1_buffer_object.md)** of type GL\_ARRAY\_BUFFER. 


Inherits the following classes: **[ffw::BufferObject](classffw_1_1_buffer_object.md)**

## Public Functions

|Type|Name|
|-----|-----|
||[**Vbo**](classffw_1_1_vbo.md#1aa8ac613273284a924eb48b2c892c6811) () |


#### Public Functions inherited from [ffw::BufferObject](classffw_1_1_buffer_object.md)

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


## Additional Inherited Members

#### Protected Attributes inherited from [ffw::BufferObject](classffw_1_1_buffer_object.md)

|Type|Name|
|-----|-----|
|**[GLenum](glcorearb_8h.md#1a7efd7809e1632cdae75603fd1fee61c0)**|[**type**](classffw_1_1_buffer_object.md#1a46d80f435e947073be9a3ac22b713a3d)|
|**[GLenum](glcorearb_8h.md#1a7efd7809e1632cdae75603fd1fee61c0)**|[**objecttype**](classffw_1_1_buffer_object.md#1a372e9b7345b0ba283a9204efe3e48bf0)|
|bool|[**loaded**](classffw_1_1_buffer_object.md#1a6e9ced3549b696dd81b944738b5216c9)|
|**[GLuint](glcorearb_8h.md#1aa311c7f0d6ec4f1a33f9235c3651b86b)**|[**buffer**](classffw_1_1_buffer_object.md#1a447868d7892c8912a42786e149c4734b)|
|**[GLsizei](glcorearb_8h.md#1a9289d5b99dc1f27f01480360f2e18ae0)**|[**size**](classffw_1_1_buffer_object.md#1acb5ab72500d6ee93fd1796cdf499f3ab)|


## Public Functions Documentation

### function <a id="1aa8ac613273284a924eb48b2c892c6811" href="#1aa8ac613273284a924eb48b2c892c6811">Vbo</a>

```cpp
ffw::Vbo::Vbo ()
```





----------------------------------------
The documentation for this class was generated from the following file: `include/ffw/graphics/bufferobject.h`
