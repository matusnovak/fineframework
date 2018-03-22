---
search:
    keywords: ['ffw::Texture1DArray', 'Texture1DArray', 'Texture1DArray', 'Texture1DArray', '~Texture1DArray', 'create', 'resize', 'setPixels', 'setPixels', 'getPixels', 'operator=', 'operator=', 'Texture', 'Texture', 'Texture', 'swap', '~Texture', 'isCreated', 'destroy', 'bind', 'unbind', 'getHandle', 'getWidth', 'getHeight', 'getLayers', 'getDepth', 'getSamples', 'getInternalFormat', 'getFormat', 'getPixelFormat', 'getTextureFormat', 'isCompressed', 'setEnvParami', 'setEnvParamf', 'setTexParami', 'setTexParamiv', 'setTexParamf', 'setTexParamfv', 'generateMipmaps', 'setFiltering', 'setWrapping', 'operator=', 'operator=']
---

# class ffw::Texture1DArray



Inherits the following classes: **[ffw::Texture](classffw_1_1_texture.md)**

## Public Functions

|Type|Name|
|-----|-----|
||[**Texture1DArray**](classffw_1_1_texture1_d_array.md#1adac1b5b5b69676d969da38891bbfe0c4) () |
||[**Texture1DArray**](classffw_1_1_texture1_d_array.md#1ab75b6979e36fe2861a49e16a3c185555) (const **[Texture1DArray](classffw_1_1_texture1_d_array.md)** & second) = delete |
||[**Texture1DArray**](classffw_1_1_texture1_d_array.md#1a3595c220933864fa6c6d1c74f45e6cf5) (**[Texture1DArray](classffw_1_1_texture1_d_array.md)** && second) |
||[**~Texture1DArray**](classffw_1_1_texture1_d_array.md#1a1c4b3c5c766258c489cdfa90eaae8a52) () |
|bool|[**create**](classffw_1_1_texture1_d_array.md#1a1bd5211158ed4d85a64d15c47388d615) (**[GLsizei](glcorearb_8h.md#1a9289d5b99dc1f27f01480360f2e18ae0)** width, **[GLsizei](glcorearb_8h.md#1a9289d5b99dc1f27f01480360f2e18ae0)** layers, **[GLenum](glcorearb_8h.md#1a7efd7809e1632cdae75603fd1fee61c0)** internalformat, **[GLenum](glcorearb_8h.md#1a7efd7809e1632cdae75603fd1fee61c0)** format, **[GLenum](glcorearb_8h.md#1a7efd7809e1632cdae75603fd1fee61c0)** pixelformat, const **[GLvoid](glcorearb_8h.md#1a1e5eb1ac5e47603cc80ab58338b92393)** \* pixels = NULL) |
|bool|[**resize**](classffw_1_1_texture1_d_array.md#1a433f078b7fab88e93c9b47d7d39de393) (**[GLsizei](glcorearb_8h.md#1a9289d5b99dc1f27f01480360f2e18ae0)** width, **[GLsizei](glcorearb_8h.md#1a9289d5b99dc1f27f01480360f2e18ae0)** layers) |
|bool|[**setPixels**](classffw_1_1_texture1_d_array.md#1a95107c33afffaf30eaf106e159c61b78) (**[GLint](glcorearb_8h.md#1a5ac0f3c4d7fafd42b284b5487a791017)** level, **[GLint](glcorearb_8h.md#1a5ac0f3c4d7fafd42b284b5487a791017)** xoffset, **[GLint](glcorearb_8h.md#1a5ac0f3c4d7fafd42b284b5487a791017)** loffset, **[GLsizei](glcorearb_8h.md#1a9289d5b99dc1f27f01480360f2e18ae0)** width, const void \* pixels) |
|bool|[**setPixels**](classffw_1_1_texture1_d_array.md#1a49f48cf3c14645dc371de269606bcadf) (**[GLint](glcorearb_8h.md#1a5ac0f3c4d7fafd42b284b5487a791017)** level, const **[GLvoid](glcorearb_8h.md#1a1e5eb1ac5e47603cc80ab58338b92393)** \* pixels = NULL) |
|bool|[**getPixels**](classffw_1_1_texture1_d_array.md#1ad8d59441b88818246439c345ed2a9f02) (void \* pixels) const |
|**[Texture1DArray](classffw_1_1_texture1_d_array.md)** &|[**operator=**](classffw_1_1_texture1_d_array.md#1a7532d4fe78cd42cc1f005e16a4105e9a) (const **[Texture1DArray](classffw_1_1_texture1_d_array.md)** & second) = delete |
|**[Texture1DArray](classffw_1_1_texture1_d_array.md)** &|[**operator=**](classffw_1_1_texture1_d_array.md#1aa8e5addd2154d563e4c047c5c8777700) (**[Texture1DArray](classffw_1_1_texture1_d_array.md)** && second) |


#### Public Functions inherited from [ffw::Texture](classffw_1_1_texture.md)

|Type|Name|
|-----|-----|
||[**Texture**](classffw_1_1_texture.md#1a4ae7d89e43f1d931db2c2ed2b52a25d8) () |
||[**Texture**](classffw_1_1_texture.md#1a302c949852febbe8c677c686f062fc7a) (const **[Texture](classffw_1_1_texture.md)** & other) = delete |
||[**Texture**](classffw_1_1_texture.md#1ab65c3a5176c591eef9d6fd2b418b3d2a) (**[Texture](classffw_1_1_texture.md)** && other) |
|void|[**swap**](classffw_1_1_texture.md#1a3d6fcf7380b4050e496f1942898b447e) (**[Texture](classffw_1_1_texture.md)** & other) |
|virtual |[**~Texture**](classffw_1_1_texture.md#1a92f6d3f0a74b1576fc0df896a66123d8) () |
|bool|[**isCreated**](classffw_1_1_texture.md#1a4c626452bcf98127b1f90cf46e772c23) () const |
|void|[**destroy**](classffw_1_1_texture.md#1a1d28a1db53503aca75464215787e80d2) () <br>Destroys the texture. |
|void|[**bind**](classffw_1_1_texture.md#1a5323f06246ce65e8e3065a82373ae44b) () const <br>Actives the texture. |
|void|[**unbind**](classffw_1_1_texture.md#1aedaefef2e0f7b86d0c6668dce06e1526) () const |
|**[GLuint](glcorearb_8h.md#1aa311c7f0d6ec4f1a33f9235c3651b86b)**|[**getHandle**](classffw_1_1_texture.md#1ab2f1590889105d77250004ac23398043) () const <br>Returns the OpenGL pointer, a handle to the texture. |
|**[GLsizei](glcorearb_8h.md#1a9289d5b99dc1f27f01480360f2e18ae0)**|[**getWidth**](classffw_1_1_texture.md#1a3f7b57f4cdfa1b232106a68591717a1b) () const <br>Returns the width of the texture. |
|**[GLsizei](glcorearb_8h.md#1a9289d5b99dc1f27f01480360f2e18ae0)**|[**getHeight**](classffw_1_1_texture.md#1a4ba29b096c33e1b7d28a9f6317277f35) () const <br>Returns the height of the texture. |
|**[GLsizei](glcorearb_8h.md#1a9289d5b99dc1f27f01480360f2e18ae0)**|[**getLayers**](classffw_1_1_texture.md#1a011abc61ac3205b3193b29f00ba15d51) () const <br>Returns the number of layers. |
|**[GLsizei](glcorearb_8h.md#1a9289d5b99dc1f27f01480360f2e18ae0)**|[**getDepth**](classffw_1_1_texture.md#1a97776c20c07c7cc99a90263cf09d07af) () const <br>Returns the depth of the texture. |
|**[GLsizei](glcorearb_8h.md#1a9289d5b99dc1f27f01480360f2e18ae0)**|[**getSamples**](classffw_1_1_texture.md#1aa336912fd6483c1e0247ae416622535c) () const |
|**[GLenum](glcorearb_8h.md#1a7efd7809e1632cdae75603fd1fee61c0)**|[**getInternalFormat**](classffw_1_1_texture.md#1a63d0bd6aff454a6cd8d431ba99f19ef5) () const <br>Returns the number of color components in the texture. |
|**[GLenum](glcorearb_8h.md#1a7efd7809e1632cdae75603fd1fee61c0)**|[**getFormat**](classffw_1_1_texture.md#1aba182e26c97442e159aae522e0c7caf6) () const <br>Returns the format of the pixel data. |
|**[GLenum](glcorearb_8h.md#1a7efd7809e1632cdae75603fd1fee61c0)**|[**getPixelFormat**](classffw_1_1_texture.md#1ab45a9e7e41d35873b5d8fe1e1f233eab) () const <br>Returns the data type of the pixel data. |
|**[GLenum](glcorearb_8h.md#1a7efd7809e1632cdae75603fd1fee61c0)**|[**getTextureFormat**](classffw_1_1_texture.md#1af159308541e6890fbef23885af5a3a29) () const <br>Returns the type of the texture. |
|bool|[**isCompressed**](classffw_1_1_texture.md#1a41775e9136435ddc35d2d4e489538257) () const |
|void|[**setEnvParami**](classffw_1_1_texture.md#1a06b0473757276f674de0fd94f3ef935f) (**[GLenum](glcorearb_8h.md#1a7efd7809e1632cdae75603fd1fee61c0)** Target, **[GLenum](glcorearb_8h.md#1a7efd7809e1632cdae75603fd1fee61c0)** Name, **[GLint](glcorearb_8h.md#1a5ac0f3c4d7fafd42b284b5487a791017)** Value) |
|void|[**setEnvParamf**](classffw_1_1_texture.md#1a71b3c33ec227eb0081f7220df54dd5fe) (**[GLenum](glcorearb_8h.md#1a7efd7809e1632cdae75603fd1fee61c0)** Target, **[GLenum](glcorearb_8h.md#1a7efd7809e1632cdae75603fd1fee61c0)** Name, **[GLfloat](glcorearb_8h.md#1a31aeedaeef29442c9c015ab355c8f5ab)** Value) |
|void|[**setTexParami**](classffw_1_1_texture.md#1a4cf2259077d89f0aa63dcae0117b4aa7) (**[GLenum](glcorearb_8h.md#1a7efd7809e1632cdae75603fd1fee61c0)** Name, **[GLint](glcorearb_8h.md#1a5ac0f3c4d7fafd42b284b5487a791017)** Value) |
|void|[**setTexParamiv**](classffw_1_1_texture.md#1acd5e83d24ac5ce6e8bf72cb8fc975be7) (**[GLenum](glcorearb_8h.md#1a7efd7809e1632cdae75603fd1fee61c0)** Name, **[GLint](glcorearb_8h.md#1a5ac0f3c4d7fafd42b284b5487a791017)** \* Values) |
|void|[**setTexParamf**](classffw_1_1_texture.md#1ad3f3912c551e38f3b81076471d6773db) (**[GLenum](glcorearb_8h.md#1a7efd7809e1632cdae75603fd1fee61c0)** Name, **[GLfloat](glcorearb_8h.md#1a31aeedaeef29442c9c015ab355c8f5ab)** Value) |
|void|[**setTexParamfv**](classffw_1_1_texture.md#1a9a31a25b65ecf9a4295ea1a2a83e69a5) (**[GLenum](glcorearb_8h.md#1a7efd7809e1632cdae75603fd1fee61c0)** Name, **[GLfloat](glcorearb_8h.md#1a31aeedaeef29442c9c015ab355c8f5ab)** \* Values) |
|bool|[**generateMipmaps**](classffw_1_1_texture.md#1a3fd71b9f3a431b19ade9080b0770093a) () <br>Generates mip maps. |
|void|[**setFiltering**](classffw_1_1_texture.md#1a3ddca54f72c9b5d5472f56890a6e85de) (**[Texture::Filtering](classffw_1_1_texture.md#1a95ded8440101d9ca5418a2de34e76cff)** filtering) |
|void|[**setWrapping**](classffw_1_1_texture.md#1aefb80cf00f0d75f94869603e99e00eed) (**[Texture::Wrapping](classffw_1_1_texture.md#1af4ed8c06fbd5c85d6daf479489afa51f)** wrapping) |
|**[Texture](classffw_1_1_texture.md)** &|[**operator=**](classffw_1_1_texture.md#1a1a98a152f13b47387bc363547c24e623) (const **[Texture](classffw_1_1_texture.md)** & other) = delete |
|**[Texture](classffw_1_1_texture.md)** &|[**operator=**](classffw_1_1_texture.md#1a9142dbb77bd8cef188111f53ef636f3c) (**[Texture](classffw_1_1_texture.md)** && other) |


## Additional Inherited Members

#### Public Types inherited from [ffw::Texture](classffw_1_1_texture.md)

|Type|Name|
|-----|-----|
|enum|[**Filtering**](classffw_1_1_texture.md#1a95ded8440101d9ca5418a2de34e76cff) { **NEAREST**, **LINEAR**, **MIPMAP\_NEAREST**, **MIPMAP\_LINEAR** } |
|enum|[**Wrapping**](classffw_1_1_texture.md#1af4ed8c06fbd5c85d6daf479489afa51f) { **REPEAT**, **MIRRORED\_REPEAT**, **CLAMP\_TO\_EDGE** } |


#### Protected Attributes inherited from [ffw::Texture](classffw_1_1_texture.md)

|Type|Name|
|-----|-----|
|bool|[**loaded\_**](classffw_1_1_texture.md#1a4fa9b19ac847297d85b496f3955b5f24)|
|**[GLenum](glcorearb_8h.md#1a7efd7809e1632cdae75603fd1fee61c0)**|[**textureformat\_**](classffw_1_1_texture.md#1ade528cbd1bb6791279248d27c36ee1fb)|
|**[GLenum](glcorearb_8h.md#1a7efd7809e1632cdae75603fd1fee61c0)**|[**internalformat\_**](classffw_1_1_texture.md#1a8a29b9261a41fc0c27e1ff1fa8609083)|
|**[GLenum](glcorearb_8h.md#1a7efd7809e1632cdae75603fd1fee61c0)**|[**format\_**](classffw_1_1_texture.md#1a05b2711ceace763883507b0119afe0d5)|
|**[GLenum](glcorearb_8h.md#1a7efd7809e1632cdae75603fd1fee61c0)**|[**pixelformat\_**](classffw_1_1_texture.md#1a9ce795602443b97f3c849c67284f423f)|
|**[GLuint](glcorearb_8h.md#1aa311c7f0d6ec4f1a33f9235c3651b86b)**|[**buffer\_**](classffw_1_1_texture.md#1a8489fadc322df2ad19dc6d810764c7c8)|
|**[GLsizei](glcorearb_8h.md#1a9289d5b99dc1f27f01480360f2e18ae0)**|[**width\_**](classffw_1_1_texture.md#1abe084eac3a4938c96102255b4a7e54d8)|
|**[GLsizei](glcorearb_8h.md#1a9289d5b99dc1f27f01480360f2e18ae0)**|[**height\_**](classffw_1_1_texture.md#1ab5af68aeb7ae950e0f48c4069424f82b)|
|**[GLsizei](glcorearb_8h.md#1a9289d5b99dc1f27f01480360f2e18ae0)**|[**depth\_**](classffw_1_1_texture.md#1adfce6fe7991889ecf2a273f5443a13fe)|
|**[GLsizei](glcorearb_8h.md#1a9289d5b99dc1f27f01480360f2e18ae0)**|[**layers\_**](classffw_1_1_texture.md#1aafb95dd9ba881d8f86d8619091f1c68d)|
|bool|[**mipmaps\_**](classffw_1_1_texture.md#1a5eb92b144de35407966a91b8d1d8cc55)|
|bool|[**initialized\_**](classffw_1_1_texture.md#1a87020c26beb5ef768c6850e7d43c48c9)|
|**[GLsizei](glcorearb_8h.md#1a9289d5b99dc1f27f01480360f2e18ae0)**|[**samples\_**](classffw_1_1_texture.md#1a7ad86f3686b3115dca3d9475ffdc320f)|
|bool|[**compressed\_**](classffw_1_1_texture.md#1a14f94267f4b30f9989a30ed018dfd169)|


#### Protected Functions inherited from [ffw::Texture](classffw_1_1_texture.md)

|Type|Name|
|-----|-----|
|**[GLsizei](glcorearb_8h.md#1a9289d5b99dc1f27f01480360f2e18ae0)**|[**getBlockSize**](classffw_1_1_texture.md#1a7e16f150d265ba52d21581f42dc828da) (**[GLsizei](glcorearb_8h.md#1a9289d5b99dc1f27f01480360f2e18ae0)** width, **[GLsizei](glcorearb_8h.md#1a9289d5b99dc1f27f01480360f2e18ae0)** height = 1, **[GLsizei](glcorearb_8h.md#1a9289d5b99dc1f27f01480360f2e18ae0)** depth = 1) const |


## Public Functions Documentation

### function <a id="1adac1b5b5b69676d969da38891bbfe0c4" href="#1adac1b5b5b69676d969da38891bbfe0c4">Texture1DArray</a>

```cpp
ffw::Texture1DArray::Texture1DArray ()
```



### function <a id="1ab75b6979e36fe2861a49e16a3c185555" href="#1ab75b6979e36fe2861a49e16a3c185555">Texture1DArray</a>

```cpp
ffw::Texture1DArray::Texture1DArray (
    const Texture1DArray & second
) = delete
```



### function <a id="1a3595c220933864fa6c6d1c74f45e6cf5" href="#1a3595c220933864fa6c6d1c74f45e6cf5">Texture1DArray</a>

```cpp
ffw::Texture1DArray::Texture1DArray (
    Texture1DArray && second
)
```



### function <a id="1a1c4b3c5c766258c489cdfa90eaae8a52" href="#1a1c4b3c5c766258c489cdfa90eaae8a52">~Texture1DArray</a>

```cpp
ffw::Texture1DArray::~Texture1DArray ()
```



### function <a id="1a1bd5211158ed4d85a64d15c47388d615" href="#1a1bd5211158ed4d85a64d15c47388d615">create</a>

```cpp
bool ffw::Texture1DArray::create (
    GLsizei width
    GLsizei layers
    GLenum internalformat
    GLenum format
    GLenum pixelformat
    const GLvoid * pixels = NULL
)
```



### function <a id="1a433f078b7fab88e93c9b47d7d39de393" href="#1a433f078b7fab88e93c9b47d7d39de393">resize</a>

```cpp
bool ffw::Texture1DArray::resize (
    GLsizei width
    GLsizei layers
)
```



### function <a id="1a95107c33afffaf30eaf106e159c61b78" href="#1a95107c33afffaf30eaf106e159c61b78">setPixels</a>

```cpp
bool ffw::Texture1DArray::setPixels (
    GLint level
    GLint xoffset
    GLint loffset
    GLsizei width
    const void * pixels
)
```



### function <a id="1a49f48cf3c14645dc371de269606bcadf" href="#1a49f48cf3c14645dc371de269606bcadf">setPixels</a>

```cpp
bool ffw::Texture1DArray::setPixels (
    GLint level
    const GLvoid * pixels = NULL
)
```



### function <a id="1ad8d59441b88818246439c345ed2a9f02" href="#1ad8d59441b88818246439c345ed2a9f02">getPixels</a>

```cpp
bool ffw::Texture1DArray::getPixels (
    void * pixels
) const
```



### function <a id="1a7532d4fe78cd42cc1f005e16a4105e9a" href="#1a7532d4fe78cd42cc1f005e16a4105e9a">operator=</a>

```cpp
Texture1DArray & ffw::Texture1DArray::operator= (
    const Texture1DArray & second
) = delete
```



### function <a id="1aa8e5addd2154d563e4c047c5c8777700" href="#1aa8e5addd2154d563e4c047c5c8777700">operator=</a>

```cpp
Texture1DArray & ffw::Texture1DArray::operator= (
    Texture1DArray && second
)
```





----------------------------------------
The documentation for this class was generated from the following file: `include/ffw/graphics/texture1darray.h`
