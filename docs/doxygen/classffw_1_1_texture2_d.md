---
search: false
---

# class ffw::Texture2D

OpenGL texture of type GL\_TEXTURE\_2D. 


Inherits the following classes: **[ffw::Texture](classffw_1_1_texture.md)**



Inherited by the following classes: **[ffw::GuiImageOpenGL](classffw_1_1_gui_image_open_g_l.md)**

## Public Functions

|Type|Name|
|-----|-----|
||[**Texture2D**](classffw_1_1_texture2_d.md#1a8f579304435d5bd34026b87885038e30) () |
||[**Texture2D**](classffw_1_1_texture2_d.md#1ab1f74229752cdef98d408ba38f56fd73) (const **[Texture2D](classffw_1_1_texture2_d.md)** & other) = delete |
||[**Texture2D**](classffw_1_1_texture2_d.md#1ae409b03eafb39cc91170aa74ff34b415) (**[Texture2D](classffw_1_1_texture2_d.md)** && other) |
|virtual |[**~Texture2D**](classffw_1_1_texture2_d.md#1a9f76333c719b1a4941e12d5dc70e72a6) () = default |
|bool|[**create**](classffw_1_1_texture2_d.md#1ae1b5d6231998f2d2e03a1e9a7d97f98e) (**[GLsizei](glcorearb_8h.md#1a9289d5b99dc1f27f01480360f2e18ae0)** width, **[GLsizei](glcorearb_8h.md#1a9289d5b99dc1f27f01480360f2e18ae0)** height, **[GLenum](glcorearb_8h.md#1a7efd7809e1632cdae75603fd1fee61c0)** internalformat, **[GLenum](glcorearb_8h.md#1a7efd7809e1632cdae75603fd1fee61c0)** format, **[GLenum](glcorearb_8h.md#1a7efd7809e1632cdae75603fd1fee61c0)** pixelformat, const **[GLvoid](glcorearb_8h.md#1a1e5eb1ac5e47603cc80ab58338b92393)** \* pixels = nullptr) <br>Allocates the texture. |
|bool|[**setPixels**](classffw_1_1_texture2_d.md#1a3d6529685f02dc3831a733607bcd3365) (**[GLint](glcorearb_8h.md#1a5ac0f3c4d7fafd42b284b5487a791017)** level, const **[GLvoid](glcorearb_8h.md#1a1e5eb1ac5e47603cc80ab58338b92393)** \* pixels) <br>Sets the pixels of the entire texture. |
|bool|[**createFromBuffer**](classffw_1_1_texture2_d.md#1a68b0a6516ce2e86501403fee70442a19) (const **[ImageBuffer](classffw_1_1_image_buffer.md)** & image, bool inverse = false) <br>Creates the texture using **[ImageBuffer](classffw_1_1_image_buffer.md)**. |
|bool|[**resize**](classffw_1_1_texture2_d.md#1aeed52bc3871fecc0cc1fbef629c22bd9) (**[GLsizei](glcorearb_8h.md#1a9289d5b99dc1f27f01480360f2e18ae0)** width, **[GLsizei](glcorearb_8h.md#1a9289d5b99dc1f27f01480360f2e18ae0)** height, const **[GLvoid](glcorearb_8h.md#1a1e5eb1ac5e47603cc80ab58338b92393)** \* pixels = nullptr) <br>Resizes the texture. |
|bool|[**setPixels**](classffw_1_1_texture2_d.md#1aec49370433108cae8fa835c71ea247f9) (**[GLint](glcorearb_8h.md#1a5ac0f3c4d7fafd42b284b5487a791017)** level, **[GLint](glcorearb_8h.md#1a5ac0f3c4d7fafd42b284b5487a791017)** xoffset, **[GLint](glcorearb_8h.md#1a5ac0f3c4d7fafd42b284b5487a791017)** yoffset, **[GLsizei](glcorearb_8h.md#1a9289d5b99dc1f27f01480360f2e18ae0)** width, **[GLsizei](glcorearb_8h.md#1a9289d5b99dc1f27f01480360f2e18ae0)** height, const **[GLvoid](glcorearb_8h.md#1a1e5eb1ac5e47603cc80ab58338b92393)** \* pixels) <br>Sets the pixels of the texture section. |
|bool|[**getPixels**](classffw_1_1_texture2_d.md#1ae8788a76cd3539b2ba71dab60eddf300) (void \* pixels) const <br>Returns the pixels of the entire texture. |
|**[Texture2D](classffw_1_1_texture2_d.md)** &|[**operator=**](classffw_1_1_texture2_d.md#1a795e9fa9be71b4d4428ae38b40a87e66) (const **[Texture2D](classffw_1_1_texture2_d.md)** & other) = delete |
|**[Texture2D](classffw_1_1_texture2_d.md)** &|[**operator=**](classffw_1_1_texture2_d.md#1a187623fced1b789556d54765d56014df) (**[Texture2D](classffw_1_1_texture2_d.md)** && other) |


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


## Additional Inherited Members

#### Public Types inherited from [ffw::Texture](classffw_1_1_texture.md)

|Type|Name|
|-----|-----|
|enum|[**Filtering**](classffw_1_1_texture.md#1a95ded8440101d9ca5418a2de34e76cff) { **NEAREST**, **LINEAR**, **MIPMAP\_NEAREST**, **MIPMAP\_LINEAR** } |
|enum|[**Wrapping**](classffw_1_1_texture.md#1af4ed8c06fbd5c85d6daf479489afa51f) { **REPEAT**, **MIRRORED\_REPEAT**, **CLAMP\_TO\_EDGE** } |


#### Protected Attributes inherited from [ffw::Texture](classffw_1_1_texture.md)

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


#### Protected Functions inherited from [ffw::Texture](classffw_1_1_texture.md)

|Type|Name|
|-----|-----|
|**[GLsizei](glcorearb_8h.md#1a9289d5b99dc1f27f01480360f2e18ae0)**|[**getBlockSize**](classffw_1_1_texture.md#1a5960bd362a716e6b622e1b979d7094bd) (const **[GLsizei](glcorearb_8h.md#1a9289d5b99dc1f27f01480360f2e18ae0)** width, const **[GLsizei](glcorearb_8h.md#1a9289d5b99dc1f27f01480360f2e18ae0)** height = 1, const **[GLsizei](glcorearb_8h.md#1a9289d5b99dc1f27f01480360f2e18ae0)** depth = 1) const |


## Public Functions Documentation

### function <a id="1a8f579304435d5bd34026b87885038e30" href="#1a8f579304435d5bd34026b87885038e30">Texture2D</a>

```cpp
ffw::Texture2D::Texture2D ()
```



### function <a id="1ab1f74229752cdef98d408ba38f56fd73" href="#1ab1f74229752cdef98d408ba38f56fd73">Texture2D</a>

```cpp
ffw::Texture2D::Texture2D (
    const Texture2D & other
) = delete
```



### function <a id="1ae409b03eafb39cc91170aa74ff34b415" href="#1ae409b03eafb39cc91170aa74ff34b415">Texture2D</a>

```cpp
ffw::Texture2D::Texture2D (
    Texture2D && other
)
```



### function <a id="1a9f76333c719b1a4941e12d5dc70e72a6" href="#1a9f76333c719b1a4941e12d5dc70e72a6">~Texture2D</a>

```cpp
virtual ffw::Texture2D::~Texture2D () = default
```



### function <a id="1ae1b5d6231998f2d2e03a1e9a7d97f98e" href="#1ae1b5d6231998f2d2e03a1e9a7d97f98e">create</a>

```cpp
bool ffw::Texture2D::create (
    GLsizei width
    GLsizei height
    GLenum internalformat
    GLenum format
    GLenum pixelformat
    const GLvoid * pixels = nullptr
)
```

Allocates the texture. 



**Parameters:**


* _width_ Specifies the width of the texture image. 
* _height_ Specifies the height of the texture image. 
* _internalformat_ Specifies the number of color components in the texture. 
* _format_ Specifies the format of the pixel data. The following symbolic values are accepted: GL\_RED, GL\_RG, GL\_RGB, GL\_BGR, GL\_RGBA, GL\_BGRA, GL\_RED\_INTEGER, GL\_RG\_INTEGER, GL\_RGB\_INTEGER, GL\_BGR\_INTEGER, GL\_RGBA\_INTEGER, GL\_BGRA\_INTEGER, GL\_STENCIL\_INDEX, GL\_DEPTH\_COMPONENT, GL\_DEPTH\_STENCIL. 
* _pixelformat_ Specifies the data type of the pixel data. The following symbolic values are accepted: GL\_UNSIGNED\_BYTE, GL\_BYTE, GL\_UNSIGNED\_SHORT, GL\_SHORT, GL\_UNSIGNED\_INT, GL\_INT, GL\_FLOAT, GL\_UNSIGNED\_BYTE\_3\_3\_2, GL\_UNSIGNED\_BYTE\_2\_3\_3\_REV, GL\_UNSIGNED\_SHORT\_5\_6\_5, GL\_UNSIGNED\_SHORT\_5\_6\_5\_REV, GL\_UNSIGNED\_SHORT\_4\_4\_4\_4, GL\_UNSIGNED\_SHORT\_4\_4\_4\_4\_REV, GL\_UNSIGNED\_SHORT\_5\_5\_5\_1, GL\_UNSIGNED\_SHORT\_1\_5\_5\_5\_REV, GL\_UNSIGNED\_INT\_8\_8\_8\_8, GL\_UNSIGNED\_INT\_8\_8\_8\_8\_REV, GL\_UNSIGNED\_INT\_10\_10\_10\_2, and GL\_UNSIGNED\_INT\_2\_10\_10\_10\_REV. 
* _pixels_ Optional array to the pixels buffer that will be used to initialise the texture storage. The pixel array must be correct size, otherwise a segmentation fault will occur. If null, the texture storage is not set and initialised with random data.

The following compressed internalformats are allowed: GL\_COMPRESSED\_RGB\_S3TC\_DXT1\_EXT, GL\_COMPRESSED\_RGBA\_S3TC\_DXT1\_EXT, GL\_COMPRESSED\_RGBA\_S3TC\_DXT3\_EXT, GL\_COMPRESSED\_RGBA\_S3TC\_DXT5\_EXT, GL\_COMPRESSED\_RED\_RGTC1, GL\_COMPRESSED\_RG\_RGTC2, GL\_COMPRESSED\_SIGNED\_RED\_RGTC1, GL\_COMPRESSED\_SIGNED\_RG\_RGTC2 

**Note:**

The texture is automatically destroyed once **[destroy()](classffw_1_1_texture.md#1a1d28a1db53503aca75464215787e80d2)** is called, or the instance of this texture class is freed. 




### function <a id="1a3d6529685f02dc3831a733607bcd3365" href="#1a3d6529685f02dc3831a733607bcd3365">setPixels</a>

```cpp
bool ffw::Texture2D::setPixels (
    GLint level
    const GLvoid * pixels
)
```

Sets the pixels of the entire texture. 



**Parameters:**


* _level_ The mipmap level to set. Zero by default. 
* _pixels_ Non null pointer to the array of the pixels to upload. 



### function <a id="1a68b0a6516ce2e86501403fee70442a19" href="#1a68b0a6516ce2e86501403fee70442a19">createFromBuffer</a>

```cpp
bool ffw::Texture2D::createFromBuffer (
    const ImageBuffer & image
    bool inverse = false
)
```

Creates the texture using **[ImageBuffer](classffw_1_1_image_buffer.md)**. 



**Parameters:**


* _image_ The instance of the image buffer 
* _inverse_ Specifies if the pixels should be mirrored vertically. Set to false (default) to be unchanged. 



### function <a id="1aeed52bc3871fecc0cc1fbef629c22bd9" href="#1aeed52bc3871fecc0cc1fbef629c22bd9">resize</a>

```cpp
bool ffw::Texture2D::resize (
    GLsizei width
    GLsizei height
    const GLvoid * pixels = nullptr
)
```

Resizes the texture. 



**Parameters:**


* _width_ The new width of the texture 
* _height_ The new height of the texture 
* _pixels_ Optional array to the pixels buffer that will be used to initialise the texture storage. The pixel array must be correct size, otherwise a segmentation fault will occur. If null, the texture storage is not set and initialised with random data. 



**Note:**

The format, internalformat, and pixelformat are unchanged. 




### function <a id="1aec49370433108cae8fa835c71ea247f9" href="#1aec49370433108cae8fa835c71ea247f9">setPixels</a>

```cpp
bool ffw::Texture2D::setPixels (
    GLint level
    GLint xoffset
    GLint yoffset
    GLsizei width
    GLsizei height
    const GLvoid * pixels
)
```

Sets the pixels of the texture section. 



**Parameters:**


* _level_ The mipmap level to set. Zero by default. 
* _xoffset_ The x offset of the target area to set. 
* _yoffset_ The y offset of the target area to set. 
* _width_ The width of the area to set. 
* _height_ The height of the area to set. 
* _pixels_ Non null pointer to the array of the pixels to upload. 



### function <a id="1ae8788a76cd3539b2ba71dab60eddf300" href="#1ae8788a76cd3539b2ba71dab60eddf300">getPixels</a>

```cpp
bool ffw::Texture2D::getPixels (
    void * pixels
) const
```

Returns the pixels of the entire texture. 



**Parameters:**


* _pixels_ Non null pointer to an allocated array that will hold the entire texture data. 



### function <a id="1a795e9fa9be71b4d4428ae38b40a87e66" href="#1a795e9fa9be71b4d4428ae38b40a87e66">operator=</a>

```cpp
Texture2D & ffw::Texture2D::operator= (
    const Texture2D & other
) = delete
```



### function <a id="1a187623fced1b789556d54765d56014df" href="#1a187623fced1b789556d54765d56014df">operator=</a>

```cpp
Texture2D & ffw::Texture2D::operator= (
    Texture2D && other
)
```





----------------------------------------
The documentation for this class was generated from the following file: `include/ffw/graphics/texture2d.h`
