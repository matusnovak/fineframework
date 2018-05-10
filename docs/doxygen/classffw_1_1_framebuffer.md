---
search: false
---

# class ffw::Framebuffer

## Public Functions

|Type|Name|
|-----|-----|
||[**Framebuffer**](classffw_1_1_framebuffer.md#1a934d32601dcd69dab1cbb3cab2937cad) () <br>Constructs an empty framebuffer object. |
||[**Framebuffer**](classffw_1_1_framebuffer.md#1aec740a7e58dbb78720654fb1705d18a5) (const **[Framebuffer](classffw_1_1_framebuffer.md)** & other) = delete |
||[**Framebuffer**](classffw_1_1_framebuffer.md#1a2d09f2e68864fd65e37ff1652fbcc61d) (**[Framebuffer](classffw_1_1_framebuffer.md)** && other) |
|void|[**swap**](classffw_1_1_framebuffer.md#1a4644aaf6f77e6380cff0ddeadd131a12) (**[Framebuffer](classffw_1_1_framebuffer.md)** & other) |
||[**~Framebuffer**](classffw_1_1_framebuffer.md#1a5fac7b441e2c97098b6256e0af601ae6) () |
|bool|[**isCreated**](classffw_1_1_framebuffer.md#1a7c1f98d179f746bf2f26bf1eed95f9fd) () const <br>Returns true if the framebuffer object has been created. |
|bool|[**create**](classffw_1_1_framebuffer.md#1ad5108eaf30a33c4690ac00f97cb199b8) () <br>Generate framebuffer object. |
|bool|[**addTexture**](classffw_1_1_framebuffer.md#1ad0e940baad8d3f0cf1ecc9dbdb14ce31) (**[GLenum](glcorearb_8h.md#1a7efd7809e1632cdae75603fd1fee61c0)** attachment, **[GLuint](glcorearb_8h.md#1aa311c7f0d6ec4f1a33f9235c3651b86b)** textype, **[GLuint](glcorearb_8h.md#1aa311c7f0d6ec4f1a33f9235c3651b86b)** texture, **[GLint](glcorearb_8h.md#1a5ac0f3c4d7fafd42b284b5487a791017)** level = 0) const <br>Attach a texture image to the framebuffer object. |
|bool|[**addRenderbuffer**](classffw_1_1_framebuffer.md#1a83a78395d08a14d5682ba9c9f0f04f12) (**[GLenum](glcorearb_8h.md#1a7efd7809e1632cdae75603fd1fee61c0)** attachment, **[GLuint](glcorearb_8h.md#1aa311c7f0d6ec4f1a33f9235c3651b86b)** texture) const <br>Attach a renderbuffer object to a framebuffer object. |
|bool|[**addStencilTexture**](classffw_1_1_framebuffer.md#1a6dd95eeae59a2779698cc617b10b69e0) (const **[ffw::Texture2D](classffw_1_1_texture2_d.md)** \* texture, const **[GLint](glcorearb_8h.md#1a5ac0f3c4d7fafd42b284b5487a791017)** level = 0) <br>Attach a stencil texture to the framebuffer object. |
|bool|[**addStencilBuffer**](classffw_1_1_framebuffer.md#1a6e39b52a4b09418bee8a3f9228ac8907) (const **[ffw::Renderbuffer2D](classffw_1_1_renderbuffer2_d.md)** \* texture) <br>Attach a stencil renderbuffer to the framebuffer object. |
|bool|[**addColorTexture**](classffw_1_1_framebuffer.md#1a333861ba339e5ba55588144c3c31fef8) (const **[ffw::Texture2D](classffw_1_1_texture2_d.md)** \* texture, const **[GLint](glcorearb_8h.md#1a5ac0f3c4d7fafd42b284b5487a791017)** level = 0) <br>Attach a color texture to the framebuffer object. |
|bool|[**addCubemapTexture**](classffw_1_1_framebuffer.md#1a8e3524b4a8fb6a1434e629b609163b1e) (const **[ffw::TextureCubemap](classffw_1_1_texture_cubemap.md)** \* texture, const **[GLint](glcorearb_8h.md#1a5ac0f3c4d7fafd42b284b5487a791017)** side, const **[GLint](glcorearb_8h.md#1a5ac0f3c4d7fafd42b284b5487a791017)** level = 0) <br>Attach a color cubemap texture to the framebuffer object. |
|bool|[**addDepthTexture**](classffw_1_1_framebuffer.md#1abf6daf0feeb98619ea20e888daef24b4) (const **[ffw::Texture2D](classffw_1_1_texture2_d.md)** \* texture, const **[GLint](glcorearb_8h.md#1a5ac0f3c4d7fafd42b284b5487a791017)** level = 0) <br>Attach a depth texture to the framebuffer object. |
|bool|[**addColorTextureMS**](classffw_1_1_framebuffer.md#1a938b875cdfe4d2d1a44d9704722815a5) (const **[ffw::Texture2DMS](classffw_1_1_texture2_d_m_s.md)** \* texture, const **[GLint](glcorearb_8h.md#1a5ac0f3c4d7fafd42b284b5487a791017)** level = 0) <br>Attach a color multisample texture to the framebuffer object. |
|bool|[**addDepthTextureMS**](classffw_1_1_framebuffer.md#1a9068f3f149e689db3cbc5c780eaa6e33) (const **[ffw::Texture2DMS](classffw_1_1_texture2_d_m_s.md)** \* texture, const **[GLint](glcorearb_8h.md#1a5ac0f3c4d7fafd42b284b5487a791017)** level = 0) <br>Attach a depth multisample texture to the framebuffer object. |
|bool|[**addColorRenderbuffer**](classffw_1_1_framebuffer.md#1a09a4c7ea2fb2a8351b5674416b36d295) (const **[ffw::Renderbuffer2D](classffw_1_1_renderbuffer2_d.md)** \* texture) <br>Attach a color renderbuffer to the framebuffer object. |
|bool|[**addDepthRenderbuffer**](classffw_1_1_framebuffer.md#1a4b9eff078631930f19a83bfc04b637aa) (const **[ffw::Renderbuffer2D](classffw_1_1_renderbuffer2_d.md)** \* texture) <br>Attach a depth renderbuffer to the framebuffer object. |
|bool|[**addColorRenderbufferMS**](classffw_1_1_framebuffer.md#1a9de525b69c4abc44f6186dc571d6b274) (const **[ffw::Renderbuffer2DMS](classffw_1_1_renderbuffer2_d_m_s.md)** \* texture) <br>Attach a color multisample renderbuffer to the framebuffer object. |
|bool|[**addDepthRenderbufferMS**](classffw_1_1_framebuffer.md#1a89b18d1f9fc6d6ad01866d9f385f4af3) (const **[ffw::Renderbuffer2DMS](classffw_1_1_renderbuffer2_d_m_s.md)** \* texture) <br>Attach a depth multisample renderbuffer to the framebuffer object. |
|bool|[**checkStatus**](classffw_1_1_framebuffer.md#1a9553b7deb789fd727b0287879846bc69) () <br>Check the completeness status of a framebuffer. |
|unsigned int|[**getHandle**](classffw_1_1_framebuffer.md#1a399e05f0243f71c62616d9a688a19083) () const <br>Returns the named object of the framebuffer (the handle) |
|void|[**resetColorCount**](classffw_1_1_framebuffer.md#1ae216bdc5f547f9b79232c720fa168232) () <br>Resets the color count of the color attachments. |
|bool|[**destroy**](classffw_1_1_framebuffer.md#1a7965073ccaacb74922c7ef94138d4e65) () <br>Destroys the framebuffer object. |
|void|[**bind**](classffw_1_1_framebuffer.md#1a7c6cdd2d6797d36ab523656f9abbf34d) () const <br>Binds the framebuffer object as GL\_FRAMEBUFFER. |
|void|[**unbind**](classffw_1_1_framebuffer.md#1a2c4a652b9e959f3f97c10116a9542296) () const <br>Unbinds the framebuffer object by setting the current GL\_FRAMEBUFFER to zero. |
|**[Framebuffer](classffw_1_1_framebuffer.md)** &|[**operator=**](classffw_1_1_framebuffer.md#1a9c4cc12bd66f49d23c024d983cb0491b) (const **[Framebuffer](classffw_1_1_framebuffer.md)** & other) = delete |
|**[Framebuffer](classffw_1_1_framebuffer.md)** &|[**operator=**](classffw_1_1_framebuffer.md#1a8ee569b7a1aed4e49a71aad6c93aa187) (**[Framebuffer](classffw_1_1_framebuffer.md)** && other) |


## Public Functions Documentation

### function <a id="1a934d32601dcd69dab1cbb3cab2937cad" href="#1a934d32601dcd69dab1cbb3cab2937cad">Framebuffer</a>

```cpp
ffw::Framebuffer::Framebuffer ()
```

Constructs an empty framebuffer object. 


### function <a id="1aec740a7e58dbb78720654fb1705d18a5" href="#1aec740a7e58dbb78720654fb1705d18a5">Framebuffer</a>

```cpp
ffw::Framebuffer::Framebuffer (
    const Framebuffer & other
) = delete
```



### function <a id="1a2d09f2e68864fd65e37ff1652fbcc61d" href="#1a2d09f2e68864fd65e37ff1652fbcc61d">Framebuffer</a>

```cpp
ffw::Framebuffer::Framebuffer (
    Framebuffer && other
)
```



### function <a id="1a4644aaf6f77e6380cff0ddeadd131a12" href="#1a4644aaf6f77e6380cff0ddeadd131a12">swap</a>

```cpp
void ffw::Framebuffer::swap (
    Framebuffer & other
)
```



### function <a id="1a5fac7b441e2c97098b6256e0af601ae6" href="#1a5fac7b441e2c97098b6256e0af601ae6">~Framebuffer</a>

```cpp
ffw::Framebuffer::~Framebuffer ()
```



### function <a id="1a7c1f98d179f746bf2f26bf1eed95f9fd" href="#1a7c1f98d179f746bf2f26bf1eed95f9fd">isCreated</a>

```cpp
bool ffw::Framebuffer::isCreated () const
```

Returns true if the framebuffer object has been created. 


### function <a id="1ad5108eaf30a33c4690ac00f97cb199b8" href="#1ad5108eaf30a33c4690ac00f97cb199b8">create</a>

```cpp
bool ffw::Framebuffer::create ()
```

Generate framebuffer object. 


### function <a id="1ad0e940baad8d3f0cf1ecc9dbdb14ce31" href="#1ad0e940baad8d3f0cf1ecc9dbdb14ce31">addTexture</a>

```cpp
bool ffw::Framebuffer::addTexture (
    GLenum attachment
    GLuint textype
    GLuint texture
    GLint level = 0
) const
```

Attach a texture image to the framebuffer object. 



**Parameters:**


* _attachment_ Specifies the attachment point to which an image from texture should be attached. Must be one of the GL\_COLOR\_ATTACHMENT0, GL\_DEPTH\_ATTACHMENT, or GL\_STENCIL\_ATTACHMENT. 
* _textype_ Specifies the texture target. Must be one of the GL\_TEXTURE\_2D, GL\_TEXTURE\_CUBE\_MAP\_POSITIVE\_X, GL\_TEXTURE\_CUBE\_MAP\_NEGATIVE\_X, GL\_TEXTURE\_CUBE\_MAP\_POSITIVE\_Y, GL\_TEXTURE\_CUBE\_MAP\_NEGATIVE\_Y, GL\_TEXTURE\_CUBE\_MAP\_POSITIVE\_Z, or GL\_TEXTURE\_CUBE\_MAP\_NEGATIVE\_Z. 
* _texture_ Specifies the texture object whose image is to be attached. (the handle returned by **[ffw::Texture::getHandle()](classffw_1_1_texture.md#1ab2f1590889105d77250004ac23398043)**) 
* _level_ Specifies the mipmap level of the texture image to be attached, which must be 0. 



**See also:**

**[ffw::Texture::getHandle](classffw_1_1_texture.md#1ab2f1590889105d77250004ac23398043)** 




### function <a id="1a83a78395d08a14d5682ba9c9f0f04f12" href="#1a83a78395d08a14d5682ba9c9f0f04f12">addRenderbuffer</a>

```cpp
bool ffw::Framebuffer::addRenderbuffer (
    GLenum attachment
    GLuint texture
) const
```

Attach a renderbuffer object to a framebuffer object. 



**Parameters:**


* _attachment_ Specifies the attachment point to which renderbuffer should be attached. Must be one of the GL\_COLOR\_ATTACHMENT0, GL\_DEPTH\_ATTACHMENT, or GL\_STENCIL\_ATTACHMENT. 
* _texture_ Specifies the renderbuffer object that is to be attached. (the handle returned by **[ffw::Renderbuffer::getHandle()](classffw_1_1_renderbuffer.md#1aacb48db33cee24c946aa2a4e738f4d7f)**) 



**See also:**

**[ffw::Renderbuffer::getHandle](classffw_1_1_renderbuffer.md#1aacb48db33cee24c946aa2a4e738f4d7f)** 




### function <a id="1a6dd95eeae59a2779698cc617b10b69e0" href="#1a6dd95eeae59a2779698cc617b10b69e0">addStencilTexture</a>

```cpp
bool ffw::Framebuffer::addStencilTexture (
    const ffw::Texture2D * texture
    const GLint level = 0
)
```

Attach a stencil texture to the framebuffer object. 



**Parameters:**


* _texture_ The texture that is to be attached. 
* _level_ The mipmap level, must be 0. 



### function <a id="1a6e39b52a4b09418bee8a3f9228ac8907" href="#1a6e39b52a4b09418bee8a3f9228ac8907">addStencilBuffer</a>

```cpp
bool ffw::Framebuffer::addStencilBuffer (
    const ffw::Renderbuffer2D * texture
)
```

Attach a stencil renderbuffer to the framebuffer object. 



**Parameters:**


* _texture_ The renderbuffer that is to be attached. 
* _level_ The mipmap level, must be 0. 



### function <a id="1a333861ba339e5ba55588144c3c31fef8" href="#1a333861ba339e5ba55588144c3c31fef8">addColorTexture</a>

```cpp
bool ffw::Framebuffer::addColorTexture (
    const ffw::Texture2D * texture
    const GLint level = 0
)
```

Attach a color texture to the framebuffer object. 



**Parameters:**


* _texture_ The texture that is to be attached. 
* _level_ The mipmap level, must be 0. 



### function <a id="1a8e3524b4a8fb6a1434e629b609163b1e" href="#1a8e3524b4a8fb6a1434e629b609163b1e">addCubemapTexture</a>

```cpp
bool ffw::Framebuffer::addCubemapTexture (
    const ffw::TextureCubemap * texture
    const GLint side
    const GLint level = 0
)
```

Attach a color cubemap texture to the framebuffer object. 



**Parameters:**


* _texture_ The texture that is to be attached. 
* _side_ The size of the cubemap to attach where 0 is positive X side followed by X negative (1), Y positive (2), Y negative (3), Z positive (4), Z negative (5). 
* _level_ The mipmap level, must be 0. 



### function <a id="1abf6daf0feeb98619ea20e888daef24b4" href="#1abf6daf0feeb98619ea20e888daef24b4">addDepthTexture</a>

```cpp
bool ffw::Framebuffer::addDepthTexture (
    const ffw::Texture2D * texture
    const GLint level = 0
)
```

Attach a depth texture to the framebuffer object. 



**Parameters:**


* _texture_ The texture that is to be attached. 
* _level_ The mipmap level, must be 0. 



### function <a id="1a938b875cdfe4d2d1a44d9704722815a5" href="#1a938b875cdfe4d2d1a44d9704722815a5">addColorTextureMS</a>

```cpp
bool ffw::Framebuffer::addColorTextureMS (
    const ffw::Texture2DMS * texture
    const GLint level = 0
)
```

Attach a color multisample texture to the framebuffer object. 



**Parameters:**


* _texture_ The texture that is to be attached. 
* _level_ The mipmap level, must be 0. 



### function <a id="1a9068f3f149e689db3cbc5c780eaa6e33" href="#1a9068f3f149e689db3cbc5c780eaa6e33">addDepthTextureMS</a>

```cpp
bool ffw::Framebuffer::addDepthTextureMS (
    const ffw::Texture2DMS * texture
    const GLint level = 0
)
```

Attach a depth multisample texture to the framebuffer object. 



**Parameters:**


* _texture_ The texture that is to be attached. 
* _level_ The mipmap level, must be 0. 



### function <a id="1a09a4c7ea2fb2a8351b5674416b36d295" href="#1a09a4c7ea2fb2a8351b5674416b36d295">addColorRenderbuffer</a>

```cpp
bool ffw::Framebuffer::addColorRenderbuffer (
    const ffw::Renderbuffer2D * texture
)
```

Attach a color renderbuffer to the framebuffer object. 



**Parameters:**


* _texture_ The renderbuffer that is to be attached. 



### function <a id="1a4b9eff078631930f19a83bfc04b637aa" href="#1a4b9eff078631930f19a83bfc04b637aa">addDepthRenderbuffer</a>

```cpp
bool ffw::Framebuffer::addDepthRenderbuffer (
    const ffw::Renderbuffer2D * texture
)
```

Attach a depth renderbuffer to the framebuffer object. 



**Parameters:**


* _texture_ The renderbuffer that is to be attached. 



### function <a id="1a9de525b69c4abc44f6186dc571d6b274" href="#1a9de525b69c4abc44f6186dc571d6b274">addColorRenderbufferMS</a>

```cpp
bool ffw::Framebuffer::addColorRenderbufferMS (
    const ffw::Renderbuffer2DMS * texture
)
```

Attach a color multisample renderbuffer to the framebuffer object. 



**Parameters:**


* _texture_ The renderbuffer that is to be attached. 



### function <a id="1a89b18d1f9fc6d6ad01866d9f385f4af3" href="#1a89b18d1f9fc6d6ad01866d9f385f4af3">addDepthRenderbufferMS</a>

```cpp
bool ffw::Framebuffer::addDepthRenderbufferMS (
    const ffw::Renderbuffer2DMS * texture
)
```

Attach a depth multisample renderbuffer to the framebuffer object. 



**Parameters:**


* _texture_ The renderbuffer that is to be attached. 



### function <a id="1a9553b7deb789fd727b0287879846bc69" href="#1a9553b7deb789fd727b0287879846bc69">checkStatus</a>

```cpp
bool ffw::Framebuffer::checkStatus ()
```

Check the completeness status of a framebuffer. 


### function <a id="1a399e05f0243f71c62616d9a688a19083" href="#1a399e05f0243f71c62616d9a688a19083">getHandle</a>

```cpp
unsigned int ffw::Framebuffer::getHandle () const
```

Returns the named object of the framebuffer (the handle) 


### function <a id="1ae216bdc5f547f9b79232c720fa168232" href="#1ae216bdc5f547f9b79232c720fa168232">resetColorCount</a>

```cpp
void ffw::Framebuffer::resetColorCount ()
```

Resets the color count of the color attachments. 


### function <a id="1a7965073ccaacb74922c7ef94138d4e65" href="#1a7965073ccaacb74922c7ef94138d4e65">destroy</a>

```cpp
bool ffw::Framebuffer::destroy ()
```

Destroys the framebuffer object. 


### function <a id="1a7c6cdd2d6797d36ab523656f9abbf34d" href="#1a7c6cdd2d6797d36ab523656f9abbf34d">bind</a>

```cpp
void ffw::Framebuffer::bind () const
```

Binds the framebuffer object as GL\_FRAMEBUFFER. 


### function <a id="1a2c4a652b9e959f3f97c10116a9542296" href="#1a2c4a652b9e959f3f97c10116a9542296">unbind</a>

```cpp
void ffw::Framebuffer::unbind () const
```

Unbinds the framebuffer object by setting the current GL\_FRAMEBUFFER to zero. 


### function <a id="1a9c4cc12bd66f49d23c024d983cb0491b" href="#1a9c4cc12bd66f49d23c024d983cb0491b">operator=</a>

```cpp
Framebuffer & ffw::Framebuffer::operator= (
    const Framebuffer & other
) = delete
```



### function <a id="1a8ee569b7a1aed4e49a71aad6c93aa187" href="#1a8ee569b7a1aed4e49a71aad6c93aa187">operator=</a>

```cpp
Framebuffer & ffw::Framebuffer::operator= (
    Framebuffer && other
)
```





----------------------------------------
The documentation for this class was generated from the following file: `include/ffw/graphics/framebuffer.h`
