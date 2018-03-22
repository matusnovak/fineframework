---
search:
    keywords: ['ffw::Texture', 'Filtering', 'Wrapping', 'loaded_', 'textureformat_', 'internalformat_', 'format_', 'pixelformat_', 'buffer_', 'width_', 'height_', 'depth_', 'layers_', 'mipmaps_', 'initialized_', 'samples_', 'compressed_', 'Texture', 'Texture', 'Texture', 'swap', '~Texture', 'isCreated', 'destroy', 'bind', 'unbind', 'getHandle', 'getWidth', 'getHeight', 'getLayers', 'getDepth', 'getSamples', 'getInternalFormat', 'getFormat', 'getPixelFormat', 'getTextureFormat', 'isCompressed', 'setEnvParami', 'setEnvParamf', 'setTexParami', 'setTexParamiv', 'setTexParamf', 'setTexParamfv', 'generateMipmaps', 'setFiltering', 'setWrapping', 'operator=', 'operator=', 'getBlockSize']
---

# class ffw::Texture

Base class for all texture types. 


Inherited by the following classes: **[ffw::Texture1D](classffw_1_1_texture1_d.md)**, **[ffw::Texture1DArray](classffw_1_1_texture1_d_array.md)**, **[ffw::Texture2D](classffw_1_1_texture2_d.md)**, **[ffw::Texture2DArray](classffw_1_1_texture2_d_array.md)**, **[ffw::Texture2DArrayMS](classffw_1_1_texture2_d_array_m_s.md)**, **[ffw::Texture2DMS](classffw_1_1_texture2_d_m_s.md)**, **[ffw::Texture3D](classffw_1_1_texture3_d.md)**, **[ffw::TextureCubemap](classffw_1_1_texture_cubemap.md)**

## Public Types

|Type|Name|
|-----|-----|
|enum|[**Filtering**](classffw_1_1_texture.md#1a95ded8440101d9ca5418a2de34e76cff) { **NEAREST**, **LINEAR**, **MIPMAP\_NEAREST**, **MIPMAP\_LINEAR** } |
|enum|[**Wrapping**](classffw_1_1_texture.md#1af4ed8c06fbd5c85d6daf479489afa51f) { **REPEAT**, **MIRRORED\_REPEAT**, **CLAMP\_TO\_EDGE** } |


## Protected Attributes

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


## Public Functions

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


## Protected Functions

|Type|Name|
|-----|-----|
|**[GLsizei](glcorearb_8h.md#1a9289d5b99dc1f27f01480360f2e18ae0)**|[**getBlockSize**](classffw_1_1_texture.md#1a7e16f150d265ba52d21581f42dc828da) (**[GLsizei](glcorearb_8h.md#1a9289d5b99dc1f27f01480360f2e18ae0)** width, **[GLsizei](glcorearb_8h.md#1a9289d5b99dc1f27f01480360f2e18ae0)** height = 1, **[GLsizei](glcorearb_8h.md#1a9289d5b99dc1f27f01480360f2e18ae0)** depth = 1) const |


## Public Types Documentation

### enum <a id="1a95ded8440101d9ca5418a2de34e76cff" href="#1a95ded8440101d9ca5418a2de34e76cff">Filtering</a>

```cpp
enum ffw::Texture::Filtering {
    NEAREST,
    LINEAR,
    MIPMAP_NEAREST,
    MIPMAP_LINEAR,
};
```



### enum <a id="1af4ed8c06fbd5c85d6daf479489afa51f" href="#1af4ed8c06fbd5c85d6daf479489afa51f">Wrapping</a>

```cpp
enum ffw::Texture::Wrapping {
    REPEAT,
    MIRRORED_REPEAT,
    CLAMP_TO_EDGE,
};
```



## Protected Attributes Documentation

### variable <a id="1a4fa9b19ac847297d85b496f3955b5f24" href="#1a4fa9b19ac847297d85b496f3955b5f24">loaded\_</a>

```cpp
bool ffw::Texture::loaded_;
```



### variable <a id="1ade528cbd1bb6791279248d27c36ee1fb" href="#1ade528cbd1bb6791279248d27c36ee1fb">textureformat\_</a>

```cpp
GLenum ffw::Texture::textureformat_;
```



### variable <a id="1a8a29b9261a41fc0c27e1ff1fa8609083" href="#1a8a29b9261a41fc0c27e1ff1fa8609083">internalformat\_</a>

```cpp
GLenum ffw::Texture::internalformat_;
```



### variable <a id="1a05b2711ceace763883507b0119afe0d5" href="#1a05b2711ceace763883507b0119afe0d5">format\_</a>

```cpp
GLenum ffw::Texture::format_;
```



### variable <a id="1a9ce795602443b97f3c849c67284f423f" href="#1a9ce795602443b97f3c849c67284f423f">pixelformat\_</a>

```cpp
GLenum ffw::Texture::pixelformat_;
```



### variable <a id="1a8489fadc322df2ad19dc6d810764c7c8" href="#1a8489fadc322df2ad19dc6d810764c7c8">buffer\_</a>

```cpp
GLuint ffw::Texture::buffer_;
```



### variable <a id="1abe084eac3a4938c96102255b4a7e54d8" href="#1abe084eac3a4938c96102255b4a7e54d8">width\_</a>

```cpp
GLsizei ffw::Texture::width_;
```



### variable <a id="1ab5af68aeb7ae950e0f48c4069424f82b" href="#1ab5af68aeb7ae950e0f48c4069424f82b">height\_</a>

```cpp
GLsizei ffw::Texture::height_;
```



### variable <a id="1adfce6fe7991889ecf2a273f5443a13fe" href="#1adfce6fe7991889ecf2a273f5443a13fe">depth\_</a>

```cpp
GLsizei ffw::Texture::depth_;
```



### variable <a id="1aafb95dd9ba881d8f86d8619091f1c68d" href="#1aafb95dd9ba881d8f86d8619091f1c68d">layers\_</a>

```cpp
GLsizei ffw::Texture::layers_;
```



### variable <a id="1a5eb92b144de35407966a91b8d1d8cc55" href="#1a5eb92b144de35407966a91b8d1d8cc55">mipmaps\_</a>

```cpp
bool ffw::Texture::mipmaps_;
```



### variable <a id="1a87020c26beb5ef768c6850e7d43c48c9" href="#1a87020c26beb5ef768c6850e7d43c48c9">initialized\_</a>

```cpp
bool ffw::Texture::initialized_;
```



### variable <a id="1a7ad86f3686b3115dca3d9475ffdc320f" href="#1a7ad86f3686b3115dca3d9475ffdc320f">samples\_</a>

```cpp
GLsizei ffw::Texture::samples_;
```



### variable <a id="1a14f94267f4b30f9989a30ed018dfd169" href="#1a14f94267f4b30f9989a30ed018dfd169">compressed\_</a>

```cpp
bool ffw::Texture::compressed_;
```



## Public Functions Documentation

### function <a id="1a4ae7d89e43f1d931db2c2ed2b52a25d8" href="#1a4ae7d89e43f1d931db2c2ed2b52a25d8">Texture</a>

```cpp
ffw::Texture::Texture ()
```



### function <a id="1a302c949852febbe8c677c686f062fc7a" href="#1a302c949852febbe8c677c686f062fc7a">Texture</a>

```cpp
ffw::Texture::Texture (
    const Texture & other
) = delete
```



### function <a id="1ab65c3a5176c591eef9d6fd2b418b3d2a" href="#1ab65c3a5176c591eef9d6fd2b418b3d2a">Texture</a>

```cpp
ffw::Texture::Texture (
    Texture && other
)
```



### function <a id="1a3d6fcf7380b4050e496f1942898b447e" href="#1a3d6fcf7380b4050e496f1942898b447e">swap</a>

```cpp
void ffw::Texture::swap (
    Texture & other
)
```



### function <a id="1a92f6d3f0a74b1576fc0df896a66123d8" href="#1a92f6d3f0a74b1576fc0df896a66123d8">~Texture</a>

```cpp
virtual ffw::Texture::~Texture ()
```



### function <a id="1a4c626452bcf98127b1f90cf46e772c23" href="#1a4c626452bcf98127b1f90cf46e772c23">isCreated</a>

```cpp
bool ffw::Texture::isCreated () const
```



### function <a id="1a1d28a1db53503aca75464215787e80d2" href="#1a1d28a1db53503aca75464215787e80d2">destroy</a>

```cpp
void ffw::Texture::destroy ()
```

Destroys the texture. 

Destroys the texture and the allocated memory to it. Calling this on already deleted texture does nothing. 

### function <a id="1a5323f06246ce65e8e3065a82373ae44b" href="#1a5323f06246ce65e8e3065a82373ae44b">bind</a>

```cpp
void ffw::Texture::bind () const
```

Actives the texture. 


### function <a id="1aedaefef2e0f7b86d0c6668dce06e1526" href="#1aedaefef2e0f7b86d0c6668dce06e1526">unbind</a>

```cpp
void ffw::Texture::unbind () const
```



### function <a id="1ab2f1590889105d77250004ac23398043" href="#1ab2f1590889105d77250004ac23398043">getHandle</a>

```cpp
GLuint ffw::Texture::getHandle () const
```

Returns the OpenGL pointer, a handle to the texture. 


### function <a id="1a3f7b57f4cdfa1b232106a68591717a1b" href="#1a3f7b57f4cdfa1b232106a68591717a1b">getWidth</a>

```cpp
GLsizei ffw::Texture::getWidth () const
```

Returns the width of the texture. 


### function <a id="1a4ba29b096c33e1b7d28a9f6317277f35" href="#1a4ba29b096c33e1b7d28a9f6317277f35">getHeight</a>

```cpp
GLsizei ffw::Texture::getHeight () const
```

Returns the height of the texture. 

If the texture is 1D texture, the returned type is always 1. 

### function <a id="1a011abc61ac3205b3193b29f00ba15d51" href="#1a011abc61ac3205b3193b29f00ba15d51">getLayers</a>

```cpp
GLsizei ffw::Texture::getLayers () const
```

Returns the number of layers. 

If the texture is not an array, the returned value is always 1. 

### function <a id="1a97776c20c07c7cc99a90263cf09d07af" href="#1a97776c20c07c7cc99a90263cf09d07af">getDepth</a>

```cpp
GLsizei ffw::Texture::getDepth () const
```

Returns the depth of the texture. 

This only applies to 3D texture, otherwise returns 1. 

### function <a id="1aa336912fd6483c1e0247ae416622535c" href="#1aa336912fd6483c1e0247ae416622535c">getSamples</a>

```cpp
GLsizei ffw::Texture::getSamples () const
```



### function <a id="1a63d0bd6aff454a6cd8d431ba99f19ef5" href="#1a63d0bd6aff454a6cd8d431ba99f19ef5">getInternalFormat</a>

```cpp
GLenum ffw::Texture::getInternalFormat () const
```

Returns the number of color components in the texture. 

The internal format can be GL\_RGB8, GL\_RGBA8, GL\_RGB32F, etc... 

### function <a id="1aba182e26c97442e159aae522e0c7caf6" href="#1aba182e26c97442e159aae522e0c7caf6">getFormat</a>

```cpp
GLenum ffw::Texture::getFormat () const
```

Returns the format of the pixel data. 

The format can be GL\_RGB, GL\_RED, GL\_RGBA, etc... 

### function <a id="1ab45a9e7e41d35873b5d8fe1e1f233eab" href="#1ab45a9e7e41d35873b5d8fe1e1f233eab">getPixelFormat</a>

```cpp
GLenum ffw::Texture::getPixelFormat () const
```

Returns the data type of the pixel data. 

The pixel format can be GL\_UNSIGNED\_BYTE, GL\_FLOAT, etc... 

### function <a id="1af159308541e6890fbef23885af5a3a29" href="#1af159308541e6890fbef23885af5a3a29">getTextureFormat</a>

```cpp
GLenum ffw::Texture::getTextureFormat () const
```

Returns the type of the texture. 

The texture format can be GL\_TEXTURE\_1D, GL\_TEXTURE\_2D, etc... 

### function <a id="1a41775e9136435ddc35d2d4e489538257" href="#1a41775e9136435ddc35d2d4e489538257">isCompressed</a>

```cpp
bool ffw::Texture::isCompressed () const
```



### function <a id="1a06b0473757276f674de0fd94f3ef935f" href="#1a06b0473757276f674de0fd94f3ef935f">setEnvParami</a>

```cpp
void ffw::Texture::setEnvParami (
    GLenum Target
    GLenum Name
    GLint Value
)
```



### function <a id="1a71b3c33ec227eb0081f7220df54dd5fe" href="#1a71b3c33ec227eb0081f7220df54dd5fe">setEnvParamf</a>

```cpp
void ffw::Texture::setEnvParamf (
    GLenum Target
    GLenum Name
    GLfloat Value
)
```



### function <a id="1a4cf2259077d89f0aa63dcae0117b4aa7" href="#1a4cf2259077d89f0aa63dcae0117b4aa7">setTexParami</a>

```cpp
void ffw::Texture::setTexParami (
    GLenum Name
    GLint Value
)
```



### function <a id="1acd5e83d24ac5ce6e8bf72cb8fc975be7" href="#1acd5e83d24ac5ce6e8bf72cb8fc975be7">setTexParamiv</a>

```cpp
void ffw::Texture::setTexParamiv (
    GLenum Name
    GLint * Values
)
```



### function <a id="1ad3f3912c551e38f3b81076471d6773db" href="#1ad3f3912c551e38f3b81076471d6773db">setTexParamf</a>

```cpp
void ffw::Texture::setTexParamf (
    GLenum Name
    GLfloat Value
)
```



### function <a id="1a9a31a25b65ecf9a4295ea1a2a83e69a5" href="#1a9a31a25b65ecf9a4295ea1a2a83e69a5">setTexParamfv</a>

```cpp
void ffw::Texture::setTexParamfv (
    GLenum Name
    GLfloat * Values
)
```



### function <a id="1a3fd71b9f3a431b19ade9080b0770093a" href="#1a3fd71b9f3a431b19ade9080b0770093a">generateMipmaps</a>

```cpp
bool ffw::Texture::generateMipmaps ()
```

Generates mip maps. 


### function <a id="1a3ddca54f72c9b5d5472f56890a6e85de" href="#1a3ddca54f72c9b5d5472f56890a6e85de">setFiltering</a>

```cpp
void ffw::Texture::setFiltering (
    Texture::Filtering filtering
)
```



### function <a id="1aefb80cf00f0d75f94869603e99e00eed" href="#1aefb80cf00f0d75f94869603e99e00eed">setWrapping</a>

```cpp
void ffw::Texture::setWrapping (
    Texture::Wrapping wrapping
)
```



### function <a id="1a1a98a152f13b47387bc363547c24e623" href="#1a1a98a152f13b47387bc363547c24e623">operator=</a>

```cpp
Texture & ffw::Texture::operator= (
    const Texture & other
) = delete
```



### function <a id="1a9142dbb77bd8cef188111f53ef636f3c" href="#1a9142dbb77bd8cef188111f53ef636f3c">operator=</a>

```cpp
Texture & ffw::Texture::operator= (
    Texture && other
)
```



## Protected Functions Documentation

### function <a id="1a7e16f150d265ba52d21581f42dc828da" href="#1a7e16f150d265ba52d21581f42dc828da">getBlockSize</a>

```cpp
GLsizei ffw::Texture::getBlockSize (
    GLsizei width
    GLsizei height = 1
    GLsizei depth = 1
) const
```





----------------------------------------
The documentation for this class was generated from the following file: `include/ffw/graphics/texture.h`
