Renderbuffer2DMS
===================================


**Inherits from:** [ffw::Renderbuffer](ffw_Renderbuffer.html)

The documentation for this class was generated from: `include/ffw/graphics/renderbuffer2dms.h`



## Public Static Functions

| Type | Name |
| -------: | :------- |
|  bool | [checkCompability](#c20342c8) (const [RenderContext](ffw_RenderContext.html) * _Renderer_)  |


## Public Functions

| Type | Name |
| -------: | :------- |
|   | [Renderbuffer2DMS](#c1971c15) ()  |
|   | [~Renderbuffer2DMS](#f686be4f) ()  |
|  bool | [create](#24ae7e80) (const [ffw::RenderContext](ffw_RenderContext.html) * _renderer_, GLsizei _width_, GLsizei _height_, GLenum _internalformat_, GLint _samples_)  |
|  bool | [resize](#8fb1c9a3) (GLsizei _width_, GLsizei _height_, GLint _samples_)  |


## Public Static Functions Documentation

### _function_ <a id="c20342c8" href="#c20342c8">checkCompability</a>

```cpp
static bool checkCompability (
    const RenderContext * Renderer
) 
```





## Public Functions Documentation

### _function_ <a id="c1971c15" href="#c1971c15">Renderbuffer2DMS</a>

```cpp
 Renderbuffer2DMS () 
```



### _function_ <a id="f686be4f" href="#f686be4f">~Renderbuffer2DMS</a>

```cpp
 ~Renderbuffer2DMS () 
```



### _function_ <a id="24ae7e80" href="#24ae7e80">create</a>

```cpp
bool create (
    const ffw::RenderContext * renderer,
    GLsizei width,
    GLsizei height,
    GLenum internalformat,
    GLint samples
) 
```



### _function_ <a id="8fb1c9a3" href="#8fb1c9a3">resize</a>

```cpp
bool resize (
    GLsizei width,
    GLsizei height,
    GLint samples
) 
```





