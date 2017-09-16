Texture1D
===================================


**Inherits from:** [ffw::Texture](ffw_Texture.html)

The documentation for this class was generated from: `include/ffw/graphics/texture1d.h`



## Public Static Functions

| Type | Name |
| -------: | :------- |
|  bool | [checkCompability](#4b8f0914) (const [RenderContext](ffw_RenderContext.html) * _renderer_)  |


## Public Functions

| Type | Name |
| -------: | :------- |
|   | [Texture1D](#fe4bfdb5) ()  |
|   | [Texture1D](#e0d3bc95) (const [Texture1D](ffw_Texture1D.html) & _second_) = delete  |
|   | [Texture1D](#5c5335f8) ([Texture1D](ffw_Texture1D.html) && _second_)  |
|   | [~Texture1D](#896d0709) ()  |
|  bool | [create](#cfddd3f8) (const [ffw::RenderContext](ffw_RenderContext.html) * _renderer_, GLsizei _width_, GLenum _internalformat_, GLenum _format_, GLenum _pixelformat_)  |
|  bool | [resize](#7a8c5174) (GLsizei _width_)  |
|  bool | [setPixels](#78f8298b) (GLint _level_, GLint _xoffset_, GLsizei _width_, const void * _pixels_)  |
|  bool | [getPixels](#f042c5df) (void * _pixels_)  |
|  [Texture1D](ffw_Texture1D.html) & | [operator=](#10fe2ad6) (const [Texture1D](ffw_Texture1D.html) & _second_) = delete  |
|  [Texture1D](ffw_Texture1D.html) & | [operator=](#67d2be6d) ([Texture1D](ffw_Texture1D.html) && _second_)  |


## Public Static Functions Documentation

### <span style="opacity:0.5;">function</span> <a id="4b8f0914" href="#4b8f0914">checkCompability</a>

```cpp
static bool checkCompability (
    const RenderContext * renderer
) 
```





## Public Functions Documentation

### <span style="opacity:0.5;">function</span> <a id="fe4bfdb5" href="#fe4bfdb5">Texture1D</a>

```cpp
 Texture1D () 
```



### <span style="opacity:0.5;">function</span> <a id="e0d3bc95" href="#e0d3bc95">Texture1D</a>

```cpp
 Texture1D (
    const Texture1D & second
) = delete 
```



### <span style="opacity:0.5;">function</span> <a id="5c5335f8" href="#5c5335f8">Texture1D</a>

```cpp
 Texture1D (
    Texture1D && second
) 
```



### <span style="opacity:0.5;">function</span> <a id="896d0709" href="#896d0709">~Texture1D</a>

```cpp
 ~Texture1D () 
```



### <span style="opacity:0.5;">function</span> <a id="cfddd3f8" href="#cfddd3f8">create</a>

```cpp
bool create (
    const ffw::RenderContext * renderer,
    GLsizei width,
    GLenum internalformat,
    GLenum format,
    GLenum pixelformat
) 
```



### <span style="opacity:0.5;">function</span> <a id="7a8c5174" href="#7a8c5174">resize</a>

```cpp
bool resize (
    GLsizei width
) 
```



### <span style="opacity:0.5;">function</span> <a id="78f8298b" href="#78f8298b">setPixels</a>

```cpp
bool setPixels (
    GLint level,
    GLint xoffset,
    GLsizei width,
    const void * pixels
) 
```



### <span style="opacity:0.5;">function</span> <a id="f042c5df" href="#f042c5df">getPixels</a>

```cpp
bool getPixels (
    void * pixels
) 
```



### <span style="opacity:0.5;">function</span> <a id="10fe2ad6" href="#10fe2ad6">operator=</a>

```cpp
Texture1D & operator= (
    const Texture1D & second
) = delete 
```



### <span style="opacity:0.5;">function</span> <a id="67d2be6d" href="#67d2be6d">operator=</a>

```cpp
Texture1D & operator= (
    Texture1D && second
) 
```





