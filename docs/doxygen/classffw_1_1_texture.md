---
search: false
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
|bool|[**loaded**](classffw_1_1_texture.md#1ad73c95a919b154830dabf275cb06f454)|
|**[GLenum](glcorearb_8h.md#1a7efd7809e1632cdae75603fd1fee61c0)**|[**textureformat**](classffw_1_1_texture.md#1a8b337b6301c0e75f1bd756aaae3f059b)|
|**[GLenum](glcorearb_8h.md#1a7efd7809e1632cdae75603fd1fee61c0)**|[**internalformat**](classffw_1_1_texture.md#1a6d98ce4dc95fc3a5ad93b5e0e77388be)|
|**[GLenum](glcorearb_8h.md#1a7efd7809e1632cdae75603fd1fee61c0)**|[**format**](classffw_1_1_texture.md#1a730be3ef8c1aaa7cc3d7f283f48c16ae)|
|**[GLenum](glcorearb_8h.md#1a7efd7809e1632cdae75603fd1fee61c0)**|[**pixelformat**](classffw_1_1_texture.md#1a6fd40a35948a532ad09e4ba0af676a76)|
|**[GLuint](glcorearb_8h.md#1aa311c7f0d6ec4f1a33f9235c3651b86b)**|[**buffer**](classffw_1_1_texture.md#1a8f8b0002ea889579e0a6b0f2cc40f863)|
|**[GLsizei](glcorearb_8h.md#1a9289d5b99dc1f27f01480360f2e18ae0)**|[**width**](classffw_1_1_texture.md#1ae080fd244a9eccc0ad70ac7c0e96da86)|
|**[GLsizei](glcorearb_8h.md#1a9289d5b99dc1f27f01480360f2e18ae0)**|[**height**](classffw_1_1_texture.md#1a9844e008a64fde84ad77ad277a276180)|
|**[GLsizei](glcorearb_8h.md#1a9289d5b99dc1f27f01480360f2e18ae0)**|[**depth**](classffw_1_1_texture.md#1ab452871de894b98ae3e95a38d1126e23)|
|**[GLsizei](glcorearb_8h.md#1a9289d5b99dc1f27f01480360f2e18ae0)**|[**layers**](classffw_1_1_texture.md#1ae57c3b6572bcd9e381385e54e0ca7194)|
|bool|[**mipmaps**](classffw_1_1_texture.md#1ae8069b54c3a76db8e934f48209c9fec1)|
|bool|[**initialized**](classffw_1_1_texture.md#1a13b6effbf702392f30440c6b3b6b4420)|
|**[GLsizei](glcorearb_8h.md#1a9289d5b99dc1f27f01480360f2e18ae0)**|[**samples**](classffw_1_1_texture.md#1a6c6f6c9ddc6b382491b02f7da9d0f9b3)|
|bool|[**compressed**](classffw_1_1_texture.md#1a0097135ba9fc805a46e4a6a492403086)|


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
|void|[**bind**](classffw_1_1_texture.md#1a5323f06246ce65e8e3065a82373ae44b) () const <br>Binds the texture. |
|void|[**unbind**](classffw_1_1_texture.md#1aedaefef2e0f7b86d0c6668dce06e1526) () const <br>Unbinds the texture. |
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
|void|[**setEnvParami**](classffw_1_1_texture.md#1a5d20a05faca666e58dc412e0b03c1c54) (**[GLenum](glcorearb_8h.md#1a7efd7809e1632cdae75603fd1fee61c0)** target, **[GLenum](glcorearb_8h.md#1a7efd7809e1632cdae75603fd1fee61c0)** name, **[GLint](glcorearb_8h.md#1a5ac0f3c4d7fafd42b284b5487a791017)** value) const |
|void|[**setEnvParamf**](classffw_1_1_texture.md#1a78fdaef9fd7ca20f8eaa10b42a84df47) (**[GLenum](glcorearb_8h.md#1a7efd7809e1632cdae75603fd1fee61c0)** target, **[GLenum](glcorearb_8h.md#1a7efd7809e1632cdae75603fd1fee61c0)** name, **[GLfloat](glcorearb_8h.md#1a31aeedaeef29442c9c015ab355c8f5ab)** value) const |
|void|[**setTexParami**](classffw_1_1_texture.md#1a50a65d93e33cd7950c55f90b452446e2) (**[GLenum](glcorearb_8h.md#1a7efd7809e1632cdae75603fd1fee61c0)** name, **[GLint](glcorearb_8h.md#1a5ac0f3c4d7fafd42b284b5487a791017)** value) const |
|void|[**setTexParamiv**](classffw_1_1_texture.md#1a499fc6c77ef9bd3955489d2751654df1) (**[GLenum](glcorearb_8h.md#1a7efd7809e1632cdae75603fd1fee61c0)** name, const **[GLint](glcorearb_8h.md#1a5ac0f3c4d7fafd42b284b5487a791017)** \* value) const |
|void|[**setTexParamf**](classffw_1_1_texture.md#1a532c6e914e88bd15ca03e0c08dd7b6fc) (**[GLenum](glcorearb_8h.md#1a7efd7809e1632cdae75603fd1fee61c0)** name, **[GLfloat](glcorearb_8h.md#1a31aeedaeef29442c9c015ab355c8f5ab)** value) const |
|void|[**setTexParamfv**](classffw_1_1_texture.md#1ab8e3f7f1e884f1b5c97dbdaf7b2a6339) (**[GLenum](glcorearb_8h.md#1a7efd7809e1632cdae75603fd1fee61c0)** name, const **[GLfloat](glcorearb_8h.md#1a31aeedaeef29442c9c015ab355c8f5ab)** \* value) const |
|bool|[**generateMipmaps**](classffw_1_1_texture.md#1a3fd71b9f3a431b19ade9080b0770093a) () <br>Generates mip maps. |
|void|[**setFiltering**](classffw_1_1_texture.md#1a161a46a6b95d0d339b2c391726b56218) (**[Texture::Filtering](classffw_1_1_texture.md#1a95ded8440101d9ca5418a2de34e76cff)** filtering) const |
|void|[**setWrapping**](classffw_1_1_texture.md#1a2309fb9ddb9d209266e2f3cd27592ed4) (**[Texture::Wrapping](classffw_1_1_texture.md#1af4ed8c06fbd5c85d6daf479489afa51f)** wrapping) const |
|**[Texture](classffw_1_1_texture.md)** &|[**operator=**](classffw_1_1_texture.md#1a1a98a152f13b47387bc363547c24e623) (const **[Texture](classffw_1_1_texture.md)** & other) = delete |
|**[Texture](classffw_1_1_texture.md)** &|[**operator=**](classffw_1_1_texture.md#1a9142dbb77bd8cef188111f53ef636f3c) (**[Texture](classffw_1_1_texture.md)** && other) |


## Protected Functions

|Type|Name|
|-----|-----|
|**[GLsizei](glcorearb_8h.md#1a9289d5b99dc1f27f01480360f2e18ae0)**|[**getBlockSize**](classffw_1_1_texture.md#1a5960bd362a716e6b622e1b979d7094bd) (const **[GLsizei](glcorearb_8h.md#1a9289d5b99dc1f27f01480360f2e18ae0)** width, const **[GLsizei](glcorearb_8h.md#1a9289d5b99dc1f27f01480360f2e18ae0)** height = 1, const **[GLsizei](glcorearb_8h.md#1a9289d5b99dc1f27f01480360f2e18ae0)** depth = 1) const |


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

### variable <a id="1ad73c95a919b154830dabf275cb06f454" href="#1ad73c95a919b154830dabf275cb06f454">loaded</a>

```cpp
bool ffw::Texture::loaded;
```



### variable <a id="1a8b337b6301c0e75f1bd756aaae3f059b" href="#1a8b337b6301c0e75f1bd756aaae3f059b">textureformat</a>

```cpp
GLenum ffw::Texture::textureformat;
```



### variable <a id="1a6d98ce4dc95fc3a5ad93b5e0e77388be" href="#1a6d98ce4dc95fc3a5ad93b5e0e77388be">internalformat</a>

```cpp
GLenum ffw::Texture::internalformat;
```



### variable <a id="1a730be3ef8c1aaa7cc3d7f283f48c16ae" href="#1a730be3ef8c1aaa7cc3d7f283f48c16ae">format</a>

```cpp
GLenum ffw::Texture::format;
```



### variable <a id="1a6fd40a35948a532ad09e4ba0af676a76" href="#1a6fd40a35948a532ad09e4ba0af676a76">pixelformat</a>

```cpp
GLenum ffw::Texture::pixelformat;
```



### variable <a id="1a8f8b0002ea889579e0a6b0f2cc40f863" href="#1a8f8b0002ea889579e0a6b0f2cc40f863">buffer</a>

```cpp
GLuint ffw::Texture::buffer;
```



### variable <a id="1ae080fd244a9eccc0ad70ac7c0e96da86" href="#1ae080fd244a9eccc0ad70ac7c0e96da86">width</a>

```cpp
GLsizei ffw::Texture::width;
```



### variable <a id="1a9844e008a64fde84ad77ad277a276180" href="#1a9844e008a64fde84ad77ad277a276180">height</a>

```cpp
GLsizei ffw::Texture::height;
```



### variable <a id="1ab452871de894b98ae3e95a38d1126e23" href="#1ab452871de894b98ae3e95a38d1126e23">depth</a>

```cpp
GLsizei ffw::Texture::depth;
```



### variable <a id="1ae57c3b6572bcd9e381385e54e0ca7194" href="#1ae57c3b6572bcd9e381385e54e0ca7194">layers</a>

```cpp
GLsizei ffw::Texture::layers;
```



### variable <a id="1ae8069b54c3a76db8e934f48209c9fec1" href="#1ae8069b54c3a76db8e934f48209c9fec1">mipmaps</a>

```cpp
bool ffw::Texture::mipmaps;
```



### variable <a id="1a13b6effbf702392f30440c6b3b6b4420" href="#1a13b6effbf702392f30440c6b3b6b4420">initialized</a>

```cpp
bool ffw::Texture::initialized;
```



### variable <a id="1a6c6f6c9ddc6b382491b02f7da9d0f9b3" href="#1a6c6f6c9ddc6b382491b02f7da9d0f9b3">samples</a>

```cpp
GLsizei ffw::Texture::samples;
```



### variable <a id="1a0097135ba9fc805a46e4a6a492403086" href="#1a0097135ba9fc805a46e4a6a492403086">compressed</a>

```cpp
bool ffw::Texture::compressed;
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

Destroys the texture and the allocated memory to it. Calling this on already deleted texture has no effect. 

### function <a id="1a5323f06246ce65e8e3065a82373ae44b" href="#1a5323f06246ce65e8e3065a82373ae44b">bind</a>

```cpp
void ffw::Texture::bind () const
```

Binds the texture. 


### function <a id="1aedaefef2e0f7b86d0c6668dce06e1526" href="#1aedaefef2e0f7b86d0c6668dce06e1526">unbind</a>

```cpp
void ffw::Texture::unbind () const
```

Unbinds the texture. 



**Note:**

After the unbind the active texture will be set to no handle (zero) 




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



### function <a id="1a5d20a05faca666e58dc412e0b03c1c54" href="#1a5d20a05faca666e58dc412e0b03c1c54">setEnvParami</a>

```cpp
void ffw::Texture::setEnvParami (
    GLenum target
    GLenum name
    GLint value
) const
```



### function <a id="1a78fdaef9fd7ca20f8eaa10b42a84df47" href="#1a78fdaef9fd7ca20f8eaa10b42a84df47">setEnvParamf</a>

```cpp
void ffw::Texture::setEnvParamf (
    GLenum target
    GLenum name
    GLfloat value
) const
```



### function <a id="1a50a65d93e33cd7950c55f90b452446e2" href="#1a50a65d93e33cd7950c55f90b452446e2">setTexParami</a>

```cpp
void ffw::Texture::setTexParami (
    GLenum name
    GLint value
) const
```



### function <a id="1a499fc6c77ef9bd3955489d2751654df1" href="#1a499fc6c77ef9bd3955489d2751654df1">setTexParamiv</a>

```cpp
void ffw::Texture::setTexParamiv (
    GLenum name
    const GLint * value
) const
```



### function <a id="1a532c6e914e88bd15ca03e0c08dd7b6fc" href="#1a532c6e914e88bd15ca03e0c08dd7b6fc">setTexParamf</a>

```cpp
void ffw::Texture::setTexParamf (
    GLenum name
    GLfloat value
) const
```



### function <a id="1ab8e3f7f1e884f1b5c97dbdaf7b2a6339" href="#1ab8e3f7f1e884f1b5c97dbdaf7b2a6339">setTexParamfv</a>

```cpp
void ffw::Texture::setTexParamfv (
    GLenum name
    const GLfloat * value
) const
```



### function <a id="1a3fd71b9f3a431b19ade9080b0770093a" href="#1a3fd71b9f3a431b19ade9080b0770093a">generateMipmaps</a>

```cpp
bool ffw::Texture::generateMipmaps ()
```

Generates mip maps. 


### function <a id="1a161a46a6b95d0d339b2c391726b56218" href="#1a161a46a6b95d0d339b2c391726b56218">setFiltering</a>

```cpp
void ffw::Texture::setFiltering (
    Texture::Filtering filtering
) const
```



### function <a id="1a2309fb9ddb9d209266e2f3cd27592ed4" href="#1a2309fb9ddb9d209266e2f3cd27592ed4">setWrapping</a>

```cpp
void ffw::Texture::setWrapping (
    Texture::Wrapping wrapping
) const
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

### function <a id="1a5960bd362a716e6b622e1b979d7094bd" href="#1a5960bd362a716e6b622e1b979d7094bd">getBlockSize</a>

```cpp
GLsizei ffw::Texture::getBlockSize (
    const GLsizei width
    const GLsizei height = 1
    const GLsizei depth = 1
) const
```





----------------------------------------
The documentation for this class was generated from the following file: `include/ffw/graphics/texture.h`
