---
search:
    keywords: ['ffw::Vbo', 'Vbo', 'BufferObject', 'BufferObject', 'BufferObject', 'swap', '~BufferObject', 'isCreated', 'create', 'resize', 'setData', 'mapBuffer', 'unMapBuffer', 'destroy', 'bind', 'unbind', 'getHandle', 'getSize', 'getType', 'getObjectType', 'copyFrom', 'copyFromEnabled', 'getData', 'operator=', 'operator=']
---

# class ffw::Vbo



Inherits the following classes: **[ffw::BufferObject](classffw_1_1_buffer_object.md)**

## Public Functions

|Type|Name|
|-----|-----|
||[**Vbo**](classffw_1_1_vbo.md#1aa8ac613273284a924eb48b2c892c6811) () |


#### Public Functions inherited from [ffw::BufferObject](classffw_1_1_buffer_object.md)

|Type|Name|
|-----|-----|
||[**BufferObject**](classffw_1_1_buffer_object.md#1ae76b82bc55d77073fb32e6737a183de9) (unsigned int objecttype) |
||[**BufferObject**](classffw_1_1_buffer_object.md#1ad6ff999336983d34e3c26717dc1d5fea) (const **[BufferObject](classffw_1_1_buffer_object.md)** & other) = delete |
||[**BufferObject**](classffw_1_1_buffer_object.md#1a37f7b9c01158768e2aba85b231e576a6) (**[BufferObject](classffw_1_1_buffer_object.md)** && other) |
|void|[**swap**](classffw_1_1_buffer_object.md#1aadaaee6d8097e3d458e1de6ba045a3e1) (**[BufferObject](classffw_1_1_buffer_object.md)** & other) |
|virtual |[**~BufferObject**](classffw_1_1_buffer_object.md#1a00c4c0a161af2fff85a8a13f4bc5df53) () |
|bool|[**isCreated**](classffw_1_1_buffer_object.md#1a877ea57b654445340f681833f4653554) () const |
|bool|[**create**](classffw_1_1_buffer_object.md#1a5215aed081875aa46e1aa7c72788bd7e) (const void \* data, **[GLsizei](glcorearb_8h.md#1a9289d5b99dc1f27f01480360f2e18ae0)** size, **[GLenum](glcorearb_8h.md#1a7efd7809e1632cdae75603fd1fee61c0)** type) |
|bool|[**resize**](classffw_1_1_buffer_object.md#1a32d07ef03095f5e3a914ada727356938) (const void \* data, **[GLsizei](glcorearb_8h.md#1a9289d5b99dc1f27f01480360f2e18ae0)** size) |
|bool|[**setData**](classffw_1_1_buffer_object.md#1a3ec25aa0779e2a9d10e590192b792eaa) (const void \* data, **[GLsizei](glcorearb_8h.md#1a9289d5b99dc1f27f01480360f2e18ae0)** offset, **[GLsizei](glcorearb_8h.md#1a9289d5b99dc1f27f01480360f2e18ae0)** size) |
|bool|[**mapBuffer**](classffw_1_1_buffer_object.md#1a89a846ce3802cb05992fb9f930c1e54b) (void \*\* pointer, **[GLenum](glcorearb_8h.md#1a7efd7809e1632cdae75603fd1fee61c0)** access) const |
|bool|[**unMapBuffer**](classffw_1_1_buffer_object.md#1afbded962211ca5793ce084407ff22c35) () const |
|void|[**destroy**](classffw_1_1_buffer_object.md#1a1eb4517db98b66ff15203f0d0cd5b09a) () |
|void|[**bind**](classffw_1_1_buffer_object.md#1aea63671d9f693c6579de3687d3c86522) () const |
|void|[**unbind**](classffw_1_1_buffer_object.md#1ae1b6294bf453ce5dc502e5a709a3602b) () const |
|unsigned int|[**getHandle**](classffw_1_1_buffer_object.md#1aca6f318d5daf3fe11565b7fbc9b563b1) () const |
|int|[**getSize**](classffw_1_1_buffer_object.md#1a0e1f9f700f05566472ee4689ac28ca16) () const |
|unsigned int|[**getType**](classffw_1_1_buffer_object.md#1aa38872b1e9dc1328a1b7e71c35fc9ea2) () const |
|unsigned int|[**getObjectType**](classffw_1_1_buffer_object.md#1a64eca5994300d1dbda71af9c056d821e) () const |
|bool|[**copyFrom**](classffw_1_1_buffer_object.md#1a27f6a31a9969d1df3760929a2ab52c33) (const **[BufferObject](classffw_1_1_buffer_object.md)** \* other, **[GLintptr](glcorearb_8h.md#1a0374caf1f25a139da21f84d81f637c23)** readoffset, **[GLintptr](glcorearb_8h.md#1a0374caf1f25a139da21f84d81f637c23)** writeoffset, **[GLsizeiptr](glcorearb_8h.md#1aa4edc01036f13fcf17e0b1baf6c70ea7)** size) |
|bool|[**copyFromEnabled**](classffw_1_1_buffer_object.md#1add491d5599120339473441c9a7a6fc73) () const |
|bool|[**getData**](classffw_1_1_buffer_object.md#1a7aa2ca1593bccb8611611c672cdf8b8e) (void \* data, **[GLsizei](glcorearb_8h.md#1a9289d5b99dc1f27f01480360f2e18ae0)** offset, **[GLsizei](glcorearb_8h.md#1a9289d5b99dc1f27f01480360f2e18ae0)** size) |
|**[BufferObject](classffw_1_1_buffer_object.md)** &|[**operator=**](classffw_1_1_buffer_object.md#1a91e529ace60c203a072fa90c36296330) (const **[BufferObject](classffw_1_1_buffer_object.md)** & other) = delete |
|**[BufferObject](classffw_1_1_buffer_object.md)** &|[**operator=**](classffw_1_1_buffer_object.md#1a5c27a28aff387d5695427b4516ae5b91) (**[BufferObject](classffw_1_1_buffer_object.md)** && other) |


## Additional Inherited Members

#### Protected Attributes inherited from [ffw::BufferObject](classffw_1_1_buffer_object.md)

|Type|Name|
|-----|-----|
|unsigned int|[**type\_**](classffw_1_1_buffer_object.md#1abef048bc7250a0f8832ab7a8b35cf4fd)|
|unsigned int|[**objecttype\_**](classffw_1_1_buffer_object.md#1afe269d10f30bf961c7565767044beaea)|
|bool|[**loaded\_**](classffw_1_1_buffer_object.md#1aa6600c8c8ae4d18fcde97b3ac61b51b3)|
|unsigned int|[**buffer\_**](classffw_1_1_buffer_object.md#1ace83186abbc435cc6e03362305f7111e)|
|int|[**size\_**](classffw_1_1_buffer_object.md#1a59273466d041ddd5e5a4af077f5e6c5d)|


## Public Functions Documentation

### function <a id="1aa8ac613273284a924eb48b2c892c6811" href="#1aa8ac613273284a924eb48b2c892c6811">Vbo</a>

```cpp
ffw::Vbo::Vbo ()
```





----------------------------------------
The documentation for this class was generated from the following file: `include/ffw/graphics/bufferobject.h`
