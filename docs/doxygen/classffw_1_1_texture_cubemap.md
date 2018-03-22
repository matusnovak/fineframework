---
search:
    keywords: ['ffw::TextureCubemap', 'TextureCubemap', 'TextureCubemap', 'TextureCubemap', '~TextureCubemap', 'create', 'resize', 'setPixels', 'setPixels', 'setFromBuffer', 'getPixels', 'operator=', 'operator=', 'Texture', 'Texture', 'Texture', 'swap', '~Texture', 'isCreated', 'destroy', 'bind', 'unbind', 'getHandle', 'getWidth', 'getHeight', 'getLayers', 'getDepth', 'getSamples', 'getInternalFormat', 'getFormat', 'getPixelFormat', 'getTextureFormat', 'isCompressed', 'setEnvParami', 'setEnvParamf', 'setTexParami', 'setTexParamiv', 'setTexParamf', 'setTexParamfv', 'generateMipmaps', 'setFiltering', 'setWrapping', 'operator=', 'operator=']
---

# class ffw::TextureCubemap



Inherits the following classes: **[ffw::Texture](classffw_1_1_texture.md)**

## Public Functions

|Type|Name|
|-----|-----|
||[**TextureCubemap**](classffw_1_1_texture_cubemap.md#1aeca3d2243994ad1a9036429bec357d39) () |
||[**TextureCubemap**](classffw_1_1_texture_cubemap.md#1aeb79b4397f36b0deaa1e5f81cd36bbe4) (const **[TextureCubemap](classffw_1_1_texture_cubemap.md)** & second) = delete |
||[**TextureCubemap**](classffw_1_1_texture_cubemap.md#1aceb18aeb74d855e3da88197898d34f5c) (**[TextureCubemap](classffw_1_1_texture_cubemap.md)** && second) |
||[**~TextureCubemap**](classffw_1_1_texture_cubemap.md#1aaa0f9906b3bd26f64c9d72cff69542c0) () |
|bool|[**create**](classffw_1_1_texture_cubemap.md#1aacac598ab190e354d0026cf32287efcb) (**[GLsizei](glcorearb_8h.md#1a9289d5b99dc1f27f01480360f2e18ae0)** width, **[GLsizei](glcorearb_8h.md#1a9289d5b99dc1f27f01480360f2e18ae0)** height, **[GLenum](glcorearb_8h.md#1a7efd7809e1632cdae75603fd1fee61c0)** internalformat, **[GLenum](glcorearb_8h.md#1a7efd7809e1632cdae75603fd1fee61c0)** format, **[GLenum](glcorearb_8h.md#1a7efd7809e1632cdae75603fd1fee61c0)** pixelformat, const **[GLvoid](glcorearb_8h.md#1a1e5eb1ac5e47603cc80ab58338b92393)** \* pixels = NULL) |
|bool|[**resize**](classffw_1_1_texture_cubemap.md#1aff9ab1564fd0532ceb37af8085f69999) (**[GLsizei](glcorearb_8h.md#1a9289d5b99dc1f27f01480360f2e18ae0)** width, **[GLsizei](glcorearb_8h.md#1a9289d5b99dc1f27f01480360f2e18ae0)** height) |
|bool|[**setPixels**](classffw_1_1_texture_cubemap.md#1a950e658c5973604ef611eadd7e46fcfe) (**[GLint](glcorearb_8h.md#1a5ac0f3c4d7fafd42b284b5487a791017)** level, **[GLint](glcorearb_8h.md#1a5ac0f3c4d7fafd42b284b5487a791017)** xoffset, **[GLint](glcorearb_8h.md#1a5ac0f3c4d7fafd42b284b5487a791017)** yoffset, **[GLsizei](glcorearb_8h.md#1a9289d5b99dc1f27f01480360f2e18ae0)** width, **[GLsizei](glcorearb_8h.md#1a9289d5b99dc1f27f01480360f2e18ae0)** height, **[GLint](glcorearb_8h.md#1a5ac0f3c4d7fafd42b284b5487a791017)** side, const **[GLvoid](glcorearb_8h.md#1a1e5eb1ac5e47603cc80ab58338b92393)** \* pixels) <br>Sets the pixels. |
|bool|[**setPixels**](classffw_1_1_texture_cubemap.md#1ac777950e550cd586efa76aa1d0b62f06) (**[GLint](glcorearb_8h.md#1a5ac0f3c4d7fafd42b284b5487a791017)** level, **[GLint](glcorearb_8h.md#1a5ac0f3c4d7fafd42b284b5487a791017)** side, const **[GLvoid](glcorearb_8h.md#1a1e5eb1ac5e47603cc80ab58338b92393)** \* pixels = NULL) |
|bool|[**setFromBuffer**](classffw_1_1_texture_cubemap.md#1ab5d6f202b8e680312cfa899e080bb343) (const **[ImageBuffer](classffw_1_1_image_buffer.md)** & buffer, **[GLint](glcorearb_8h.md#1a5ac0f3c4d7fafd42b284b5487a791017)** side, bool inverse = false) |
|bool|[**getPixels**](classffw_1_1_texture_cubemap.md#1a951ac8e4c67ca671b849598f1d7b024c) (void \* pixels) |
|**[TextureCubemap](classffw_1_1_texture_cubemap.md)** &|[**operator=**](classffw_1_1_texture_cubemap.md#1a06c4a21c717175bf9e0b0449263d2f7e) (const **[TextureCubemap](classffw_1_1_texture_cubemap.md)** & second) = delete |
|**[TextureCubemap](classffw_1_1_texture_cubemap.md)** &|[**operator=**](classffw_1_1_texture_cubemap.md#1a6e55ef13850fae3f4b866ee5b71d38ac) (**[TextureCubemap](classffw_1_1_texture_cubemap.md)** && second) |


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

### function <a id="1aeca3d2243994ad1a9036429bec357d39" href="#1aeca3d2243994ad1a9036429bec357d39">TextureCubemap</a>

```cpp
ffw::TextureCubemap::TextureCubemap ()
```



### function <a id="1aeb79b4397f36b0deaa1e5f81cd36bbe4" href="#1aeb79b4397f36b0deaa1e5f81cd36bbe4">TextureCubemap</a>

```cpp
ffw::TextureCubemap::TextureCubemap (
    const TextureCubemap & second
) = delete
```



### function <a id="1aceb18aeb74d855e3da88197898d34f5c" href="#1aceb18aeb74d855e3da88197898d34f5c">TextureCubemap</a>

```cpp
ffw::TextureCubemap::TextureCubemap (
    TextureCubemap && second
)
```



### function <a id="1aaa0f9906b3bd26f64c9d72cff69542c0" href="#1aaa0f9906b3bd26f64c9d72cff69542c0">~TextureCubemap</a>

```cpp
ffw::TextureCubemap::~TextureCubemap ()
```



### function <a id="1aacac598ab190e354d0026cf32287efcb" href="#1aacac598ab190e354d0026cf32287efcb">create</a>

```cpp
bool ffw::TextureCubemap::create (
    GLsizei width
    GLsizei height
    GLenum internalformat
    GLenum format
    GLenum pixelformat
    const GLvoid * pixels = NULL
)
```



### function <a id="1aff9ab1564fd0532ceb37af8085f69999" href="#1aff9ab1564fd0532ceb37af8085f69999">resize</a>

```cpp
bool ffw::TextureCubemap::resize (
    GLsizei width
    GLsizei height
)
```



### function <a id="1a950e658c5973604ef611eadd7e46fcfe" href="#1a950e658c5973604ef611eadd7e46fcfe">setPixels</a>

```cpp
bool ffw::TextureCubemap::setPixels (
    GLint level
    GLint xoffset
    GLint yoffset
    GLsizei width
    GLsizei height
    GLint side
    const GLvoid * pixels
)
```

Sets the pixels. 

The side parameter corresponds to which side should be set. The accepted values are from 0 to 5 where each number represents:
* 0: GL\_TEXTURE\_CUBE\_MAP\_POSITIVE\_X (Right)
* 1: GL\_TEXTURE\_CUBE\_MAP\_NEGATIVE\_X (Left)
* 2: GL\_TEXTURE\_CUBE\_MAP\_POSITIVE\_Y (Top)
* 3: GL\_TEXTURE\_CUBE\_MAP\_NEGATIVE\_Y (Bottom)
* 4: GL\_TEXTURE\_CUBE\_MAP\_POSITIVE\_Z (Back)
* 5: GL\_TEXTURE\_CUBE\_MAP\_NEGATIVE\_Z (Front) 



### function <a id="1ac777950e550cd586efa76aa1d0b62f06" href="#1ac777950e550cd586efa76aa1d0b62f06">setPixels</a>

```cpp
bool ffw::TextureCubemap::setPixels (
    GLint level
    GLint side
    const GLvoid * pixels = NULL
)
```



### function <a id="1ab5d6f202b8e680312cfa899e080bb343" href="#1ab5d6f202b8e680312cfa899e080bb343">setFromBuffer</a>

```cpp
bool ffw::TextureCubemap::setFromBuffer (
    const ImageBuffer & buffer
    GLint side
    bool inverse = false
)
```



### function <a id="1a951ac8e4c67ca671b849598f1d7b024c" href="#1a951ac8e4c67ca671b849598f1d7b024c">getPixels</a>

```cpp
bool ffw::TextureCubemap::getPixels (
    void * pixels
)
```



### function <a id="1a06c4a21c717175bf9e0b0449263d2f7e" href="#1a06c4a21c717175bf9e0b0449263d2f7e">operator=</a>

```cpp
TextureCubemap & ffw::TextureCubemap::operator= (
    const TextureCubemap & second
) = delete
```



### function <a id="1a6e55ef13850fae3f4b866ee5b71d38ac" href="#1a6e55ef13850fae3f4b866ee5b71d38ac">operator=</a>

```cpp
TextureCubemap & ffw::TextureCubemap::operator= (
    TextureCubemap && second
)
```





----------------------------------------
The documentation for this class was generated from the following file: `include/ffw/graphics/texturecubemap.h`
