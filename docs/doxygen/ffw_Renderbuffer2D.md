Renderbuffer2D
===================================


**Inherits from:** [ffw::Renderbuffer](ffw_Renderbuffer.html)

The documentation for this class was generated from: `include/ffw/graphics/renderbuffer2d.h`



## Public Static Functions

| Type | Name |
| -------: | :------- |
|  bool | [checkCompability](#7508907a) (const [RenderContext](ffw_RenderContext.html) * _renderer_)  |


## Public Functions

| Type | Name |
| -------: | :------- |
|   | [Renderbuffer2D](#54a3a13e) ()  |
|   | [~Renderbuffer2D](#aec01f23) ()  |
|  bool | [create](#6d0fa0dd) (const [ffw::RenderContext](ffw_RenderContext.html) * _renderer_, GLsizei _width_, GLsizei _height_, GLenum _internalformat_)  |
|  bool | [resize](#8017d0ae) (GLsizei _width_, GLsizei _height_)  |


## Public Static Functions Documentation

### _function_ <a id="7508907a" href="#7508907a">checkCompability</a>

```cpp
static bool checkCompability (
    const RenderContext * renderer
) 
```





## Public Functions Documentation

### _function_ <a id="54a3a13e" href="#54a3a13e">Renderbuffer2D</a>

```cpp
 Renderbuffer2D () 
```



### _function_ <a id="aec01f23" href="#aec01f23">~Renderbuffer2D</a>

```cpp
 ~Renderbuffer2D () 
```



### _function_ <a id="6d0fa0dd" href="#6d0fa0dd">create</a>

```cpp
bool create (
    const ffw::RenderContext * renderer,
    GLsizei width,
    GLsizei height,
    GLenum internalformat
) 
```



### _function_ <a id="8017d0ae" href="#8017d0ae">resize</a>

```cpp
bool resize (
    GLsizei width,
    GLsizei height
) 
```





