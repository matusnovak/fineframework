Texture2D
===================================


**Inherits from:** [ffw::Texture](ffw_Texture.html)

**Implemented by:** [ffw::GuiImageOpenGL](ffw_GuiImageOpenGL.html)

The documentation for this class was generated from: `include/ffw/graphics/texture2d.h`



## Public Static Functions

| Type | Name |
| -------: | :------- |
|  bool | [checkCompability](#e9dc30f1) (const [RenderContext](ffw_RenderContext.html) * _renderer_)  |


## Public Functions

| Type | Name |
| -------: | :------- |
|   | [Texture2D](#ee0911a8) ()  |
|   | [Texture2D](#036b8e3f) (const [Texture2D](ffw_Texture2D.html) & _second_) = delete  |
|   | [Texture2D](#75e56eea) ([Texture2D](ffw_Texture2D.html) && _second_)  |
|   | [~Texture2D](#3aeb91cf) ()  |
|  bool | [create](#96d774d3) (const [ffw::RenderContext](ffw_RenderContext.html) * _renderer_, GLsizei _Width_, GLsizei _Height_, GLenum _internalformat_, GLenum _format_, GLenum _pixelformat_, const GLvoid * _pixels_ = NULL)  |
|  bool | [setPixels](#c5b92473) (GLint _level_, const GLvoid * _pixels_ = NULL)  |
|  bool | [createFromBuffer](#e0034941) (const [ffw::RenderContext](ffw_RenderContext.html) * _renderer_, const [ImageBuffer](ffw_ImageBuffer.html) & _buffer_, bool _inverse_ = false)  |
|  bool | [resize](#d5d7f904) (GLsizei _width_, GLsizei _height_)  |
|  bool | [setPixels](#32eb4d97) (GLint _level_, GLint _xoffset_, GLint _yoffset_, GLsizei _width_, GLsizei _height_, const GLvoid * _pixels_)  |
|  bool | [getPixels](#2a22fac1) (void * _pixels_) const  |
|  [Texture2D](ffw_Texture2D.html) & | [operator=](#176b4505) (const [Texture2D](ffw_Texture2D.html) & _second_) = delete  |
|  [Texture2D](ffw_Texture2D.html) & | [operator=](#0d0ce047) ([Texture2D](ffw_Texture2D.html) && _second_)  |


## Public Static Functions Documentation

### _function_ <a id="e9dc30f1" href="#e9dc30f1">checkCompability</a>

```cpp
static bool checkCompability (
    const RenderContext * renderer
) 
```





## Public Functions Documentation

### _function_ <a id="ee0911a8" href="#ee0911a8">Texture2D</a>

```cpp
 Texture2D () 
```



### _function_ <a id="036b8e3f" href="#036b8e3f">Texture2D</a>

```cpp
 Texture2D (
    const Texture2D & second
) = delete 
```



### _function_ <a id="75e56eea" href="#75e56eea">Texture2D</a>

```cpp
 Texture2D (
    Texture2D && second
) 
```



### _function_ <a id="3aeb91cf" href="#3aeb91cf">~Texture2D</a>

```cpp
 ~Texture2D () 
```



### _function_ <a id="96d774d3" href="#96d774d3">create</a>

```cpp
bool create (
    const ffw::RenderContext * renderer,
    GLsizei Width,
    GLsizei Height,
    GLenum internalformat,
    GLenum format,
    GLenum pixelformat,
    const GLvoid * pixels = NULL
) 
```



### _function_ <a id="c5b92473" href="#c5b92473">setPixels</a>

```cpp
bool setPixels (
    GLint level,
    const GLvoid * pixels = NULL
) 
```



### _function_ <a id="e0034941" href="#e0034941">createFromBuffer</a>

```cpp
bool createFromBuffer (
    const ffw::RenderContext * renderer,
    const ImageBuffer & buffer,
    bool inverse = false
) 
```



### _function_ <a id="d5d7f904" href="#d5d7f904">resize</a>

```cpp
bool resize (
    GLsizei width,
    GLsizei height
) 
```



### _function_ <a id="32eb4d97" href="#32eb4d97">setPixels</a>

```cpp
bool setPixels (
    GLint level,
    GLint xoffset,
    GLint yoffset,
    GLsizei width,
    GLsizei height,
    const GLvoid * pixels
) 
```



### _function_ <a id="2a22fac1" href="#2a22fac1">getPixels</a>

```cpp
bool getPixels (
    void * pixels
) const 
```



### _function_ <a id="176b4505" href="#176b4505">operator=</a>

```cpp
Texture2D & operator= (
    const Texture2D & second
) = delete 
```



### _function_ <a id="0d0ce047" href="#0d0ce047">operator=</a>

```cpp
Texture2D & operator= (
    Texture2D && second
) 
```





