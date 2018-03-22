---
search:
    keywords: ['ffw::Texture1D', 'Texture1D', 'Texture1D', 'Texture1D', '~Texture1D', 'create', 'resize', 'createFromBuffer', 'setPixels', 'setPixels', 'getPixels', 'operator=', 'operator=', 'Texture', 'Texture', 'Texture', 'swap', '~Texture', 'isCreated', 'destroy', 'bind', 'unbind', 'getHandle', 'getWidth', 'getHeight', 'getLayers', 'getDepth', 'getSamples', 'getInternalFormat', 'getFormat', 'getPixelFormat', 'getTextureFormat', 'isCompressed', 'setEnvParami', 'setEnvParamf', 'setTexParami', 'setTexParamiv', 'setTexParamf', 'setTexParamfv', 'generateMipmaps', 'setFiltering', 'setWrapping', 'operator=', 'operator=']
---

# class ffw::Texture1D



Inherits the following classes: **[ffw::Texture](classffw_1_1_texture.md)**

## Public Functions

|Type|Name|
|-----|-----|
||[**Texture1D**](classffw_1_1_texture1_d.md#1ab5c6d4f175272fabe50dbc4ee70319a9) () |
||[**Texture1D**](classffw_1_1_texture1_d.md#1abe64586df97e49974bde4a1be1563f14) (const **[Texture1D](classffw_1_1_texture1_d.md)** & second) = delete |
||[**Texture1D**](classffw_1_1_texture1_d.md#1a4193b7a3308b76aec4767ffc44ed8f54) (**[Texture1D](classffw_1_1_texture1_d.md)** && second) |
||[**~Texture1D**](classffw_1_1_texture1_d.md#1ad4341cf80de7af28adf83842127df279) () |
|bool|[**create**](classffw_1_1_texture1_d.md#1ac8373b7d48936b87b6aa69e0b6c44559) (**[GLsizei](glcorearb_8h.md#1a9289d5b99dc1f27f01480360f2e18ae0)** width, **[GLenum](glcorearb_8h.md#1a7efd7809e1632cdae75603fd1fee61c0)** internalformat, **[GLenum](glcorearb_8h.md#1a7efd7809e1632cdae75603fd1fee61c0)** format, **[GLenum](glcorearb_8h.md#1a7efd7809e1632cdae75603fd1fee61c0)** pixelformat, const **[GLvoid](glcorearb_8h.md#1a1e5eb1ac5e47603cc80ab58338b92393)** \* pixels = NULL) |
|bool|[**resize**](classffw_1_1_texture1_d.md#1ab1f48f825b2854f2cad380fef1a58cf3) (**[GLsizei](glcorearb_8h.md#1a9289d5b99dc1f27f01480360f2e18ae0)** width) |
|bool|[**createFromBuffer**](classffw_1_1_texture1_d.md#1a6562e8f04ed1fe959f7c6a86068ab410) (const **[ImageBuffer](classffw_1_1_image_buffer.md)** & buffer) |
|bool|[**setPixels**](classffw_1_1_texture1_d.md#1af62d6dc86154aac186cc2173e836b9b9) (**[GLint](glcorearb_8h.md#1a5ac0f3c4d7fafd42b284b5487a791017)** level, const **[GLvoid](glcorearb_8h.md#1a1e5eb1ac5e47603cc80ab58338b92393)** \* pixels = NULL) |
|bool|[**setPixels**](classffw_1_1_texture1_d.md#1aaa28a5f9b29f2fc4ce0c4fcd2808ffb3) (**[GLint](glcorearb_8h.md#1a5ac0f3c4d7fafd42b284b5487a791017)** level, **[GLint](glcorearb_8h.md#1a5ac0f3c4d7fafd42b284b5487a791017)** xoffset, **[GLsizei](glcorearb_8h.md#1a9289d5b99dc1f27f01480360f2e18ae0)** width, const **[GLvoid](glcorearb_8h.md#1a1e5eb1ac5e47603cc80ab58338b92393)** \* pixels) |
|bool|[**getPixels**](classffw_1_1_texture1_d.md#1ac49e5a0fdbd866011bb0b739046f4cd7) (void \* pixels) const |
|**[Texture1D](classffw_1_1_texture1_d.md)** &|[**operator=**](classffw_1_1_texture1_d.md#1af58456d19cb9ddf8559393d17d66da40) (const **[Texture1D](classffw_1_1_texture1_d.md)** & second) = delete |
|**[Texture1D](classffw_1_1_texture1_d.md)** &|[**operator=**](classffw_1_1_texture1_d.md#1a6cc07391bbc96db4a5e6c112d431a4a2) (**[Texture1D](classffw_1_1_texture1_d.md)** && second) |


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

### function <a id="1ab5c6d4f175272fabe50dbc4ee70319a9" href="#1ab5c6d4f175272fabe50dbc4ee70319a9">Texture1D</a>

```cpp
ffw::Texture1D::Texture1D ()
```



### function <a id="1abe64586df97e49974bde4a1be1563f14" href="#1abe64586df97e49974bde4a1be1563f14">Texture1D</a>

```cpp
ffw::Texture1D::Texture1D (
    const Texture1D & second
) = delete
```



### function <a id="1a4193b7a3308b76aec4767ffc44ed8f54" href="#1a4193b7a3308b76aec4767ffc44ed8f54">Texture1D</a>

```cpp
ffw::Texture1D::Texture1D (
    Texture1D && second
)
```



### function <a id="1ad4341cf80de7af28adf83842127df279" href="#1ad4341cf80de7af28adf83842127df279">~Texture1D</a>

```cpp
ffw::Texture1D::~Texture1D ()
```



### function <a id="1ac8373b7d48936b87b6aa69e0b6c44559" href="#1ac8373b7d48936b87b6aa69e0b6c44559">create</a>

```cpp
bool ffw::Texture1D::create (
    GLsizei width
    GLenum internalformat
    GLenum format
    GLenum pixelformat
    const GLvoid * pixels = NULL
)
```



### function <a id="1ab1f48f825b2854f2cad380fef1a58cf3" href="#1ab1f48f825b2854f2cad380fef1a58cf3">resize</a>

```cpp
bool ffw::Texture1D::resize (
    GLsizei width
)
```



### function <a id="1a6562e8f04ed1fe959f7c6a86068ab410" href="#1a6562e8f04ed1fe959f7c6a86068ab410">createFromBuffer</a>

```cpp
bool ffw::Texture1D::createFromBuffer (
    const ImageBuffer & buffer
)
```



### function <a id="1af62d6dc86154aac186cc2173e836b9b9" href="#1af62d6dc86154aac186cc2173e836b9b9">setPixels</a>

```cpp
bool ffw::Texture1D::setPixels (
    GLint level
    const GLvoid * pixels = NULL
)
```



### function <a id="1aaa28a5f9b29f2fc4ce0c4fcd2808ffb3" href="#1aaa28a5f9b29f2fc4ce0c4fcd2808ffb3">setPixels</a>

```cpp
bool ffw::Texture1D::setPixels (
    GLint level
    GLint xoffset
    GLsizei width
    const GLvoid * pixels
)
```



### function <a id="1ac49e5a0fdbd866011bb0b739046f4cd7" href="#1ac49e5a0fdbd866011bb0b739046f4cd7">getPixels</a>

```cpp
bool ffw::Texture1D::getPixels (
    void * pixels
) const
```



### function <a id="1af58456d19cb9ddf8559393d17d66da40" href="#1af58456d19cb9ddf8559393d17d66da40">operator=</a>

```cpp
Texture1D & ffw::Texture1D::operator= (
    const Texture1D & second
) = delete
```



### function <a id="1a6cc07391bbc96db4a5e6c112d431a4a2" href="#1a6cc07391bbc96db4a5e6c112d431a4a2">operator=</a>

```cpp
Texture1D & ffw::Texture1D::operator= (
    Texture1D && second
)
```





----------------------------------------
The documentation for this class was generated from the following file: `include/ffw/graphics/texture1d.h`
