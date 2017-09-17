Texture
===================================

Base class for all texture types. 

**Implemented by:** [ffw::Texture1D](ffw_Texture1D.html), [ffw::Texture1DArray](ffw_Texture1DArray.html), [ffw::Texture2D](ffw_Texture2D.html), [ffw::Texture2DArray](ffw_Texture2DArray.html), [ffw::Texture2DArrayMS](ffw_Texture2DArrayMS.html), [ffw::Texture2DMS](ffw_Texture2DMS.html), [ffw::Texture3D](ffw_Texture3D.html), [ffw::TextureCubemap](ffw_TextureCubemap.html), 

The documentation for this class was generated from: `include/ffw/graphics/texture.h`



## Public Types

| Type | Name |
| -------: | :------- |
| enum | [Filtering](#0342016e) |
| enum | [Wrapping](#e1626a42) |


## Protected Attributes

| Type | Name |
| -------: | :------- |
|  bool | [loaded_](#3712489e) |
|  GLenum | [textureformat_](#c6a4f73a) |
|  GLenum | [internalformat_](#89c39537) |
|  GLenum | [format_](#961b7e69) |
|  GLenum | [pixelformat_](#e7781fb9) |
|  GLuint | [buffer_](#3f178b6f) |
|  GLsizei | [width_](#9bab2969) |
|  GLsizei | [height_](#e13b2a3f) |
|  GLsizei | [depth_](#703d2c08) |
|  GLsizei | [layers_](#abef61ff) |
|  bool | [mipmaps_](#68175277) |
|  bool | [initialized_](#78620727) |
|  GLsizei | [samples_](#88c51f03) |
|  const [RenderExtensions](ffw_RenderExtensions.html) * | [gl_](#52cddaa1) |


## Public Functions

| Type | Name |
| -------: | :------- |
|   | [Texture](#01b2641d) ()  |
|   | [Texture](#a988485b) (const [Texture](ffw_Texture.html) & _other_) = delete  |
|   | [Texture](#ebd529ea) ([Texture](ffw_Texture.html) && _other_)  |
|  void | [swap](#65f662f7) ([Texture](ffw_Texture.html) & _other_)  |
|  virtual  | [~Texture](#dbda44f2) ()  |
|  bool | [isCreated](#84ce8388) () const  |
|  void | [destroy](#97a0d99f) () <div style="opacity:0.8;">Destroys the texture. </div> |
|  void | [bind](#7f4f9eff) () const <div style="opacity:0.8;">Actives the texture. </div> |
|  void | [unbind](#e194da6f) () const  |
|  GLuint | [getHandle](#00fffa76) () const <div style="opacity:0.8;">Returns the OpenGL pointer, a handle to the texture. </div> |
|  GLsizei | [getWidth](#e923c54f) () const <div style="opacity:0.8;">Returns the width of the texture. </div> |
|  GLsizei | [getHeight](#7d5ac775) () const <div style="opacity:0.8;">Returns the height of the texture. </div> |
|  GLsizei | [getLayers](#14bc2e6b) () const <div style="opacity:0.8;">Returns the number of layers. </div> |
|  GLsizei | [getDepth](#5ed77603) () const <div style="opacity:0.8;">Returns the depth of the texture. </div> |
|  GLsizei | [getSamples](#386dc7e0) () const  |
|  GLenum | [getInternalFormat](#8617d7f5) () const <div style="opacity:0.8;">Returns the number of color components in the texture. </div> |
|  GLenum | [getFormat](#af4e84ce) () const <div style="opacity:0.8;">Returns the format of the pixel data. </div> |
|  GLenum | [getPixelFormat](#892d4b10) () const <div style="opacity:0.8;">Returns the data type of the pixel data. </div> |
|  GLenum | [getTextureFormat](#2175a3f9) () const <div style="opacity:0.8;">Returns the type of the texture. </div> |
|  void | [setEnvParami](#c4d7b948) (GLenum _Target_, GLenum _Name_, GLint _Value_)  |
|  void | [setEnvParamf](#06d0d348) (GLenum _Target_, GLenum _Name_, GLfloat _Value_)  |
|  void | [setTexParami](#c59b22c3) (GLenum _Name_, GLint _Value_)  |
|  void | [setTexParamiv](#2d153939) (GLenum _Name_, GLint * _Values_)  |
|  void | [setTexParamf](#70d91320) (GLenum _Name_, GLfloat _Value_)  |
|  void | [setTexParamfv](#3a3ce5aa) (GLenum _Name_, GLfloat * _Values_)  |
|  bool | [generateMipmaps](#6add236e) () <div style="opacity:0.8;">Generates mip maps. </div> |
|  void | [setFiltering](#c441998e) ([Texture::Filtering](ffw_Texture.html#0342016e) _filtering_)  |
|  void | [setWrapping](#3edc29d4) ([Texture::Wrapping](ffw_Texture.html#e1626a42) _wrapping_)  |
|  [Texture](ffw_Texture.html) & | [operator=](#eeca55f9) (const [Texture](ffw_Texture.html) & _other_) = delete  |
|  [Texture](ffw_Texture.html) & | [operator=](#24b442db) ([Texture](ffw_Texture.html) && _other_)  |


## Public Types Documentation

### <span style="opacity:0.5;">enum</span> <a id="0342016e" href="#0342016e">Filtering</a>

```cpp
enum Filtering {
    NEAREST,
    LINEAR,
    MIPMAP_NEAREST,
    MIPMAP_LINEAR,
}
```



### <span style="opacity:0.5;">enum</span> <a id="e1626a42" href="#e1626a42">Wrapping</a>

```cpp
enum Wrapping {
    REPEAT,
    MIRRORED_REPEAT,
    CLAMP_TO_EDGE,
}
```





## Protected Attributes Documentation

### <span style="opacity:0.5;">variable</span> <a id="3712489e" href="#3712489e">loaded_</a>

```cpp
bool loaded_
```



### <span style="opacity:0.5;">variable</span> <a id="c6a4f73a" href="#c6a4f73a">textureformat_</a>

```cpp
GLenum textureformat_
```



### <span style="opacity:0.5;">variable</span> <a id="89c39537" href="#89c39537">internalformat_</a>

```cpp
GLenum internalformat_
```



### <span style="opacity:0.5;">variable</span> <a id="961b7e69" href="#961b7e69">format_</a>

```cpp
GLenum format_
```



### <span style="opacity:0.5;">variable</span> <a id="e7781fb9" href="#e7781fb9">pixelformat_</a>

```cpp
GLenum pixelformat_
```



### <span style="opacity:0.5;">variable</span> <a id="3f178b6f" href="#3f178b6f">buffer_</a>

```cpp
GLuint buffer_
```



### <span style="opacity:0.5;">variable</span> <a id="9bab2969" href="#9bab2969">width_</a>

```cpp
GLsizei width_
```



### <span style="opacity:0.5;">variable</span> <a id="e13b2a3f" href="#e13b2a3f">height_</a>

```cpp
GLsizei height_
```



### <span style="opacity:0.5;">variable</span> <a id="703d2c08" href="#703d2c08">depth_</a>

```cpp
GLsizei depth_
```



### <span style="opacity:0.5;">variable</span> <a id="abef61ff" href="#abef61ff">layers_</a>

```cpp
GLsizei layers_
```



### <span style="opacity:0.5;">variable</span> <a id="68175277" href="#68175277">mipmaps_</a>

```cpp
bool mipmaps_
```



### <span style="opacity:0.5;">variable</span> <a id="78620727" href="#78620727">initialized_</a>

```cpp
bool initialized_
```



### <span style="opacity:0.5;">variable</span> <a id="88c51f03" href="#88c51f03">samples_</a>

```cpp
GLsizei samples_
```



### <span style="opacity:0.5;">variable</span> <a id="52cddaa1" href="#52cddaa1">gl_</a>

```cpp
const RenderExtensions * gl_
```





## Public Functions Documentation

### <span style="opacity:0.5;">function</span> <a id="01b2641d" href="#01b2641d">Texture</a>

```cpp
 Texture () 
```



### <span style="opacity:0.5;">function</span> <a id="a988485b" href="#a988485b">Texture</a>

```cpp
 Texture (
    const Texture & other
) = delete 
```



### <span style="opacity:0.5;">function</span> <a id="ebd529ea" href="#ebd529ea">Texture</a>

```cpp
 Texture (
    Texture && other
) 
```



### <span style="opacity:0.5;">function</span> <a id="65f662f7" href="#65f662f7">swap</a>

```cpp
void swap (
    Texture & other
) 
```



### <span style="opacity:0.5;">function</span> <a id="dbda44f2" href="#dbda44f2">~Texture</a>

```cpp
virtual  ~Texture () 
```



### <span style="opacity:0.5;">function</span> <a id="84ce8388" href="#84ce8388">isCreated</a>

```cpp
inline bool isCreated () const 
```



### <span style="opacity:0.5;">function</span> <a id="97a0d99f" href="#97a0d99f">destroy</a>

```cpp
void destroy () 
```

Destroys the texture. 

Destroys the texture and the allocated memory to it. Calling this on already deleted texture does nothing. 
### <span style="opacity:0.5;">function</span> <a id="7f4f9eff" href="#7f4f9eff">bind</a>

```cpp
void bind () const 
```

Actives the texture. 

### <span style="opacity:0.5;">function</span> <a id="e194da6f" href="#e194da6f">unbind</a>

```cpp
void unbind () const 
```



### <span style="opacity:0.5;">function</span> <a id="00fffa76" href="#00fffa76">getHandle</a>

```cpp
inline GLuint getHandle () const 
```

Returns the OpenGL pointer, a handle to the texture. 

### <span style="opacity:0.5;">function</span> <a id="e923c54f" href="#e923c54f">getWidth</a>

```cpp
inline GLsizei getWidth () const 
```

Returns the width of the texture. 

### <span style="opacity:0.5;">function</span> <a id="7d5ac775" href="#7d5ac775">getHeight</a>

```cpp
inline GLsizei getHeight () const 
```

Returns the height of the texture. 

If the texture is 1D texture, the returned type is always 1. 
### <span style="opacity:0.5;">function</span> <a id="14bc2e6b" href="#14bc2e6b">getLayers</a>

```cpp
inline GLsizei getLayers () const 
```

Returns the number of layers. 

If the texture is not an array, the returned value is always 1. 
### <span style="opacity:0.5;">function</span> <a id="5ed77603" href="#5ed77603">getDepth</a>

```cpp
inline GLsizei getDepth () const 
```

Returns the depth of the texture. 

This only applies to 3D texture, otherwise returns 1. 
### <span style="opacity:0.5;">function</span> <a id="386dc7e0" href="#386dc7e0">getSamples</a>

```cpp
inline GLsizei getSamples () const 
```



### <span style="opacity:0.5;">function</span> <a id="8617d7f5" href="#8617d7f5">getInternalFormat</a>

```cpp
inline GLenum getInternalFormat () const 
```

Returns the number of color components in the texture. 

The internal format can be GL_RGB8, GL_RGBA8, GL_RGB32F, etc... 
### <span style="opacity:0.5;">function</span> <a id="af4e84ce" href="#af4e84ce">getFormat</a>

```cpp
inline GLenum getFormat () const 
```

Returns the format of the pixel data. 

The format can be GL_RGB, GL_RED, GL_RGBA, etc... 
### <span style="opacity:0.5;">function</span> <a id="892d4b10" href="#892d4b10">getPixelFormat</a>

```cpp
inline GLenum getPixelFormat () const 
```

Returns the data type of the pixel data. 

The pixel format can be GL_UNSIGNED_BYTE, GL_FLOAT, etc... 
### <span style="opacity:0.5;">function</span> <a id="2175a3f9" href="#2175a3f9">getTextureFormat</a>

```cpp
inline GLenum getTextureFormat () const 
```

Returns the type of the texture. 

The texture format can be GL_TEXTURE_1D, GL_TEXTURE_2D, etc... 
### <span style="opacity:0.5;">function</span> <a id="c4d7b948" href="#c4d7b948">setEnvParami</a>

```cpp
void setEnvParami (
    GLenum Target,
    GLenum Name,
    GLint Value
) 
```



### <span style="opacity:0.5;">function</span> <a id="06d0d348" href="#06d0d348">setEnvParamf</a>

```cpp
void setEnvParamf (
    GLenum Target,
    GLenum Name,
    GLfloat Value
) 
```



### <span style="opacity:0.5;">function</span> <a id="c59b22c3" href="#c59b22c3">setTexParami</a>

```cpp
void setTexParami (
    GLenum Name,
    GLint Value
) 
```



### <span style="opacity:0.5;">function</span> <a id="2d153939" href="#2d153939">setTexParamiv</a>

```cpp
void setTexParamiv (
    GLenum Name,
    GLint * Values
) 
```



### <span style="opacity:0.5;">function</span> <a id="70d91320" href="#70d91320">setTexParamf</a>

```cpp
void setTexParamf (
    GLenum Name,
    GLfloat Value
) 
```



### <span style="opacity:0.5;">function</span> <a id="3a3ce5aa" href="#3a3ce5aa">setTexParamfv</a>

```cpp
void setTexParamfv (
    GLenum Name,
    GLfloat * Values
) 
```



### <span style="opacity:0.5;">function</span> <a id="6add236e" href="#6add236e">generateMipmaps</a>

```cpp
bool generateMipmaps () 
```

Generates mip maps. 

### <span style="opacity:0.5;">function</span> <a id="c441998e" href="#c441998e">setFiltering</a>

```cpp
void setFiltering (
    Texture::Filtering filtering
) 
```



### <span style="opacity:0.5;">function</span> <a id="3edc29d4" href="#3edc29d4">setWrapping</a>

```cpp
void setWrapping (
    Texture::Wrapping wrapping
) 
```



### <span style="opacity:0.5;">function</span> <a id="eeca55f9" href="#eeca55f9">operator=</a>

```cpp
Texture & operator= (
    const Texture & other
) = delete 
```



### <span style="opacity:0.5;">function</span> <a id="24b442db" href="#24b442db">operator=</a>

```cpp
Texture & operator= (
    Texture && other
) 
```





