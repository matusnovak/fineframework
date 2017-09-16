Texture3D
===================================


**Inherits from:** [ffw::Texture](ffw_Texture.html)

The documentation for this class was generated from: `include/ffw/graphics/texture3d.h`



## Public Static Functions

| Type | Name |
| -------: | :------- |
|  bool | [checkCompability](#1cd454d3) (const [RenderContext](ffw_RenderContext.html) * _renderer_)  |


## Public Functions

| Type | Name |
| -------: | :------- |
|   | [Texture3D](#9c285233) ()  |
|   | [Texture3D](#f429a6e4) (const [Texture3D](ffw_Texture3D.html) & _second_) = delete  |
|   | [Texture3D](#227b8e99) ([Texture3D](ffw_Texture3D.html) && _second_)  |
|   | [~Texture3D](#b52e5503) ()  |
|  bool | [create](#523c4ba3) (const [ffw::RenderContext](ffw_RenderContext.html) * _renderer_, GLsizei _width_, GLsizei _height_, GLsizei _depth_, GLenum _internalformat_, GLenum _format_, GLenum _pixelformat_)  |
|  bool | [resize](#e0d789c3) (GLsizei _width_, GLsizei _height_, GLsizei _depth_)  |
|  bool | [setPixels](#b3bd025e) (GLint _level_, GLint _xoffset_, GLint _yoffset_, GLint _zoffset_, GLsizei _width_, GLsizei _height_, GLsizei _depth_, const void * _pixels_)  |
|  bool | [getPixels](#d7805468) (void * _pixels_)  |
|  [Texture3D](ffw_Texture3D.html) & | [operator=](#c7760e97) (const [Texture3D](ffw_Texture3D.html) & _second_) = delete  |
|  [Texture3D](ffw_Texture3D.html) & | [operator=](#594cafb2) ([Texture3D](ffw_Texture3D.html) && _second_)  |


## Public Static Functions Documentation

### <span style="opacity:0.5;">function</span> <a id="1cd454d3" href="#1cd454d3">checkCompability</a>

```cpp
static bool checkCompability (
    const RenderContext * renderer
) 
```





## Public Functions Documentation

### <span style="opacity:0.5;">function</span> <a id="9c285233" href="#9c285233">Texture3D</a>

```cpp
 Texture3D () 
```



### <span style="opacity:0.5;">function</span> <a id="f429a6e4" href="#f429a6e4">Texture3D</a>

```cpp
 Texture3D (
    const Texture3D & second
) = delete 
```



### <span style="opacity:0.5;">function</span> <a id="227b8e99" href="#227b8e99">Texture3D</a>

```cpp
 Texture3D (
    Texture3D && second
) 
```



### <span style="opacity:0.5;">function</span> <a id="b52e5503" href="#b52e5503">~Texture3D</a>

```cpp
 ~Texture3D () 
```



### <span style="opacity:0.5;">function</span> <a id="523c4ba3" href="#523c4ba3">create</a>

```cpp
bool create (
    const ffw::RenderContext * renderer,
    GLsizei width,
    GLsizei height,
    GLsizei depth,
    GLenum internalformat,
    GLenum format,
    GLenum pixelformat
) 
```



### <span style="opacity:0.5;">function</span> <a id="e0d789c3" href="#e0d789c3">resize</a>

```cpp
bool resize (
    GLsizei width,
    GLsizei height,
    GLsizei depth
) 
```



### <span style="opacity:0.5;">function</span> <a id="b3bd025e" href="#b3bd025e">setPixels</a>

```cpp
bool setPixels (
    GLint level,
    GLint xoffset,
    GLint yoffset,
    GLint zoffset,
    GLsizei width,
    GLsizei height,
    GLsizei depth,
    const void * pixels
) 
```



### <span style="opacity:0.5;">function</span> <a id="d7805468" href="#d7805468">getPixels</a>

```cpp
bool getPixels (
    void * pixels
) 
```



### <span style="opacity:0.5;">function</span> <a id="c7760e97" href="#c7760e97">operator=</a>

```cpp
Texture3D & operator= (
    const Texture3D & second
) = delete 
```



### <span style="opacity:0.5;">function</span> <a id="594cafb2" href="#594cafb2">operator=</a>

```cpp
Texture3D & operator= (
    Texture3D && second
) 
```





