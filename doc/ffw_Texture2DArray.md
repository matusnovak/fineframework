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
|  bool | [create](#d3f89690) (const [ffw::RenderContext](ffw_RenderContext.html) * _renderer_, GLsizei _width_, GLsizei _height_, GLsizei _layers_, GLenum _internalformat_, GLenum _format_, GLenum _pixelformat_, const GLvoid * _pixels_ = NULL)  |
|  bool | [resize](#bea09c02) (GLsizei _width_, GLsizei _height_, GLsizei _layers_)  |
|  bool | [setFromBuffer](#c7317716) (const [ImageBuffer](ffw_ImageBuffer.html) & _buffer_, GLint _level_, bool _inverse_ = false)  |
|  bool | [setPixels](#044eeef3) (GLint _level_, const GLvoid * _pixels_ = NULL)  |
|  bool | [setPixels](#39f9a304) (GLint _level_, GLint _xoffset_, GLint _yoffset_, GLint _loffset_, GLsizei _width_, GLsizei _height_, const GLvoid * _pixels_)  |
|  bool | [getPixels](#d960542b) (void * _pixels_) const  |
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



### <span style="opacity:0.5;">function</span> <a id="d3f89690" href="#d3f89690">create</a>

```cpp
bool create (
    const ffw::RenderContext * renderer,
    GLsizei width,
    GLsizei height,
    GLsizei layers,
    GLenum internalformat,
    GLenum format,
    GLenum pixelformat,
    const GLvoid * pixels = NULL
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



### <span style="opacity:0.5;">function</span> <a id="c7317716" href="#c7317716">setFromBuffer</a>

```cpp
bool setFromBuffer (
    const ImageBuffer & buffer,
    GLint level,
    bool inverse = false
) 
```



### <span style="opacity:0.5;">function</span> <a id="044eeef3" href="#044eeef3">setPixels</a>

```cpp
bool setPixels (
    GLint level,
    const GLvoid * pixels = NULL
) 
```



### <span style="opacity:0.5;">function</span> <a id="39f9a304" href="#39f9a304">setPixels</a>

```cpp
bool setPixels (
    GLint level,
    GLint xoffset,
    GLint yoffset,
    GLint loffset,
    GLsizei width,
    GLsizei height,
    const GLvoid * pixels
) 
```



### <span style="opacity:0.5;">function</span> <a id="d960542b" href="#d960542b">getPixels</a>

```cpp
bool getPixels (
    void * pixels
) const 
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





