Texture2DMS
===================================


**Inherits from:** [ffw::Texture](ffw_Texture.html)

The documentation for this class was generated from: `include/ffw/graphics/texture2dms.h`



## Public Static Functions

| Type | Name |
| -------: | :------- |
|  bool | [checkCompability](#a27c506d) (const [RenderContext](ffw_RenderContext.html) * _renderer_)  |


## Public Functions

| Type | Name |
| -------: | :------- |
|   | [Texture2DMS](#9249e866) ()  |
|   | [Texture2DMS](#33399f6a) (const [Texture2DMS](ffw_Texture2DMS.html) & _second_) = delete  |
|   | [Texture2DMS](#567cb682) ([Texture2DMS](ffw_Texture2DMS.html) && _second_)  |
|   | [~Texture2DMS](#3a6e50cb) ()  |
|  bool | [create](#ae002398) (const [ffw::RenderContext](ffw_RenderContext.html) * _renderer_, GLsizei _width_, GLsizei _height_, GLenum _internalformat_, GLenum _format_, GLenum _pixelformat_, GLint _samples_)  |
|  bool | [resize](#8246b3d4) (GLsizei _width_, GLsizei _height_, GLint _samples_)  |
|  [Texture2DMS](ffw_Texture2DMS.html) & | [operator=](#16010e30) (const [Texture2DMS](ffw_Texture2DMS.html) & _second_) = delete  |
|  [Texture2DMS](ffw_Texture2DMS.html) & | [operator=](#753f0c31) ([Texture2DMS](ffw_Texture2DMS.html) && _second_)  |


## Public Static Functions Documentation

### _function_ <a id="a27c506d" href="#a27c506d">checkCompability</a>

```cpp
static bool checkCompability (
    const RenderContext * renderer
) 
```





## Public Functions Documentation

### _function_ <a id="9249e866" href="#9249e866">Texture2DMS</a>

```cpp
 Texture2DMS () 
```



### _function_ <a id="33399f6a" href="#33399f6a">Texture2DMS</a>

```cpp
 Texture2DMS (
    const Texture2DMS & second
) = delete 
```



### _function_ <a id="567cb682" href="#567cb682">Texture2DMS</a>

```cpp
 Texture2DMS (
    Texture2DMS && second
) 
```



### _function_ <a id="3a6e50cb" href="#3a6e50cb">~Texture2DMS</a>

```cpp
 ~Texture2DMS () 
```



### _function_ <a id="ae002398" href="#ae002398">create</a>

```cpp
bool create (
    const ffw::RenderContext * renderer,
    GLsizei width,
    GLsizei height,
    GLenum internalformat,
    GLenum format,
    GLenum pixelformat,
    GLint samples
) 
```



### _function_ <a id="8246b3d4" href="#8246b3d4">resize</a>

```cpp
bool resize (
    GLsizei width,
    GLsizei height,
    GLint samples
) 
```



### _function_ <a id="16010e30" href="#16010e30">operator=</a>

```cpp
Texture2DMS & operator= (
    const Texture2DMS & second
) = delete 
```



### _function_ <a id="753f0c31" href="#753f0c31">operator=</a>

```cpp
Texture2DMS & operator= (
    Texture2DMS && second
) 
```





