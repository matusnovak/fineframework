Texture2DArray
===================================


**Inherits from:** [ffw::Texture](ffw_Texture.html)

The documentation for this class was generated from: `include/ffw/graphics/texture2darray.h`



## Public Static Functions

| Type | Name |
| -------: | :------- |
|  bool | [checkCompability](#7e2e9515) (const [RenderContext](ffw_RenderContext.html) * _renderer_)  |


## Public Functions

| Type | Name |
| -------: | :------- |
|   | [Texture2DArray](#edb15815) ()  |
|   | [Texture2DArray](#16e0c0c5) (const [Texture2DArray](ffw_Texture2DArray.html) & _second_) = delete  |
|   | [Texture2DArray](#4f8e35bf) ([Texture2DArray](ffw_Texture2DArray.html) && _second_)  |
|   | [~Texture2DArray](#ec5d141a) ()  |
|  bool | [create](#038a94e5) (const [ffw::RenderContext](ffw_RenderContext.html) * _renderer_, GLsizei _width_, GLsizei _height_, GLsizei _layers_, GLenum _internalformat_, GLenum _format_, GLenum _pixelformat_)  |
|  bool | [resize](#bea09c02) (GLsizei _width_, GLsizei _height_, GLsizei _layers_)  |
|  bool | [setPixels](#0c652bd0) (GLint _level_, GLint _xoffset_, GLint _yoffset_, GLint _loffset_, GLsizei _width_, GLsizei _height_, const void * _pixels_)  |
|  bool | [getPixels](#f79cfc98) (void * _pixels_)  |
|  [Texture2DArray](ffw_Texture2DArray.html) & | [operator=](#0a941818) (const [Texture2DArray](ffw_Texture2DArray.html) & _second_) = delete  |
|  [Texture2DArray](ffw_Texture2DArray.html) & | [operator=](#c66d14d9) ([Texture2DArray](ffw_Texture2DArray.html) && _second_)  |


## Public Static Functions Documentation

### <span style="opacity:0.5;">function</span> <a id="7e2e9515" href="#7e2e9515">checkCompability</a>

```cpp
static bool checkCompability (
    const RenderContext * renderer
) 
```





## Public Functions Documentation

### <span style="opacity:0.5;">function</span> <a id="edb15815" href="#edb15815">Texture2DArray</a>

```cpp
 Texture2DArray () 
```



### <span style="opacity:0.5;">function</span> <a id="16e0c0c5" href="#16e0c0c5">Texture2DArray</a>

```cpp
 Texture2DArray (
    const Texture2DArray & second
) = delete 
```



### <span style="opacity:0.5;">function</span> <a id="4f8e35bf" href="#4f8e35bf">Texture2DArray</a>

```cpp
 Texture2DArray (
    Texture2DArray && second
) 
```



### <span style="opacity:0.5;">function</span> <a id="ec5d141a" href="#ec5d141a">~Texture2DArray</a>

```cpp
 ~Texture2DArray () 
```



### <span style="opacity:0.5;">function</span> <a id="038a94e5" href="#038a94e5">create</a>

```cpp
bool create (
    const ffw::RenderContext * renderer,
    GLsizei width,
    GLsizei height,
    GLsizei layers,
    GLenum internalformat,
    GLenum format,
    GLenum pixelformat
) 
```



### <span style="opacity:0.5;">function</span> <a id="bea09c02" href="#bea09c02">resize</a>

```cpp
bool resize (
    GLsizei width,
    GLsizei height,
    GLsizei layers
) 
```



### <span style="opacity:0.5;">function</span> <a id="0c652bd0" href="#0c652bd0">setPixels</a>

```cpp
bool setPixels (
    GLint level,
    GLint xoffset,
    GLint yoffset,
    GLint loffset,
    GLsizei width,
    GLsizei height,
    const void * pixels
) 
```



### <span style="opacity:0.5;">function</span> <a id="f79cfc98" href="#f79cfc98">getPixels</a>

```cpp
bool getPixels (
    void * pixels
) 
```



### <span style="opacity:0.5;">function</span> <a id="0a941818" href="#0a941818">operator=</a>

```cpp
Texture2DArray & operator= (
    const Texture2DArray & second
) = delete 
```



### <span style="opacity:0.5;">function</span> <a id="c66d14d9" href="#c66d14d9">operator=</a>

```cpp
Texture2DArray & operator= (
    Texture2DArray && second
) 
```





