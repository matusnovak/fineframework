TextureCubemap
===================================


**Inherits from:** [ffw::Texture](ffw_Texture.html)

The documentation for this class was generated from: `include/ffw/graphics/texturecubemap.h`



## Public Static Functions

| Type | Name |
| -------: | :------- |
|  bool | [checkCompability](#03e784ec) (const [RenderContext](ffw_RenderContext.html) * _renderer_)  |


## Public Functions

| Type | Name |
| -------: | :------- |
|   | [TextureCubemap](#006ef9ef) ()  |
|   | [TextureCubemap](#68ebeb64) (const [TextureCubemap](ffw_TextureCubemap.html) & _second_) = delete  |
|   | [TextureCubemap](#32cf2aed) ([TextureCubemap](ffw_TextureCubemap.html) && _second_)  |
|   | [~TextureCubemap](#60859573) ()  |
|  bool | [create](#d1495999) (const [ffw::RenderContext](ffw_RenderContext.html) * _renderer_, GLsizei _width_, GLsizei _height_, GLenum _internalformat_, GLenum _format_, GLenum _pixelformat_)  |
|  bool | [resize](#2a4ff149) (GLsizei _width_, GLsizei _height_)  |
|  bool | [setPixels](#0f362dae) (GLint _level_, GLint _xoffset_, GLint _yoffset_, GLsizei _width_, GLsizei _height_, int _side_, const void * _pixels_) <div style="opacity:0.8;">Sets the pixels. </div> |
|  bool | [getPixels](#9d17ed48) (void * _pixels_)  |
|  [TextureCubemap](ffw_TextureCubemap.html) & | [operator=](#c94b49e8) (const [TextureCubemap](ffw_TextureCubemap.html) & _second_) = delete  |
|  [TextureCubemap](ffw_TextureCubemap.html) & | [operator=](#6993cfe5) ([TextureCubemap](ffw_TextureCubemap.html) && _second_)  |


## Public Static Functions Documentation

### <span style="opacity:0.5;">function</span> <a id="03e784ec" href="#03e784ec">checkCompability</a>

```cpp
static bool checkCompability (
    const RenderContext * renderer
) 
```





## Public Functions Documentation

### <span style="opacity:0.5;">function</span> <a id="006ef9ef" href="#006ef9ef">TextureCubemap</a>

```cpp
 TextureCubemap () 
```



### <span style="opacity:0.5;">function</span> <a id="68ebeb64" href="#68ebeb64">TextureCubemap</a>

```cpp
 TextureCubemap (
    const TextureCubemap & second
) = delete 
```



### <span style="opacity:0.5;">function</span> <a id="32cf2aed" href="#32cf2aed">TextureCubemap</a>

```cpp
 TextureCubemap (
    TextureCubemap && second
) 
```



### <span style="opacity:0.5;">function</span> <a id="60859573" href="#60859573">~TextureCubemap</a>

```cpp
 ~TextureCubemap () 
```



### <span style="opacity:0.5;">function</span> <a id="d1495999" href="#d1495999">create</a>

```cpp
bool create (
    const ffw::RenderContext * renderer,
    GLsizei width,
    GLsizei height,
    GLenum internalformat,
    GLenum format,
    GLenum pixelformat
) 
```



### <span style="opacity:0.5;">function</span> <a id="2a4ff149" href="#2a4ff149">resize</a>

```cpp
bool resize (
    GLsizei width,
    GLsizei height
) 
```



### <span style="opacity:0.5;">function</span> <a id="0f362dae" href="#0f362dae">setPixels</a>

```cpp
bool setPixels (
    GLint level,
    GLint xoffset,
    GLint yoffset,
    GLsizei width,
    GLsizei height,
    int side,
    const void * pixels
) 
```

Sets the pixels. 

The side parameter corresponds to which side should be set. The accepted values are from 0 to 5 where each number represents:
* 0: GL_TEXTURE_CUBE_MAP_POSITIVE_X (Right)

* 1: GL_TEXTURE_CUBE_MAP_NEGATIVE_X (Left)

* 2: GL_TEXTURE_CUBE_MAP_POSITIVE_Y (Top)

* 3: GL_TEXTURE_CUBE_MAP_NEGATIVE_Y (Bottom)

* 4: GL_TEXTURE_CUBE_MAP_POSITIVE_Z (Back)

* 5: GL_TEXTURE_CUBE_MAP_NEGATIVE_Z (Front) 



### <span style="opacity:0.5;">function</span> <a id="9d17ed48" href="#9d17ed48">getPixels</a>

```cpp
bool getPixels (
    void * pixels
) 
```



### <span style="opacity:0.5;">function</span> <a id="c94b49e8" href="#c94b49e8">operator=</a>

```cpp
TextureCubemap & operator= (
    const TextureCubemap & second
) = delete 
```



### <span style="opacity:0.5;">function</span> <a id="6993cfe5" href="#6993cfe5">operator=</a>

```cpp
TextureCubemap & operator= (
    TextureCubemap && second
) 
```





