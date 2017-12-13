Texture2DArrayMS
===================================


**Inherits from:** [ffw::Texture](ffw_Texture.html)

The documentation for this class was generated from: `include/ffw/graphics/texture2darrayms.h`



## Public Static Functions

| Type | Name |
| -------: | :------- |
|  bool | [checkCompability](#bcd49afa) (const [RenderContext](ffw_RenderContext.html) * _renderer_)  |


## Public Functions

| Type | Name |
| -------: | :------- |
|   | [Texture2DArrayMS](#524ba265) ()  |
|   | [Texture2DArrayMS](#ca01d3de) (const [Texture2DArrayMS](ffw_Texture2DArrayMS.html) & _second_) = delete  |
|   | [Texture2DArrayMS](#930b64ce) ([Texture2DArrayMS](ffw_Texture2DArrayMS.html) && _second_)  |
|   | [~Texture2DArrayMS](#efefcb8b) ()  |
|  bool | [create](#a26568ce) (const [ffw::RenderContext](ffw_RenderContext.html) * _renderer_, GLsizei _width_, GLsizei _height_, GLsizei _layers_, GLenum _internalformat_, GLenum _format_, GLenum _pixelformat_, GLint _samples_)  |
|  bool | [resize](#e6b9d9f1) (GLsizei _width_, GLsizei _height_, GLsizei _layers_, GLint _samples_)  |
|  [Texture2DArrayMS](ffw_Texture2DArrayMS.html) & | [operator=](#87756faf) (const [Texture2DArrayMS](ffw_Texture2DArrayMS.html) & _second_) = delete  |
|  [Texture2DArrayMS](ffw_Texture2DArrayMS.html) & | [operator=](#0fcd3833) ([Texture2DArrayMS](ffw_Texture2DArrayMS.html) && _second_)  |


## Public Static Functions Documentation

### _function_ <a id="bcd49afa" href="#bcd49afa">checkCompability</a>

```cpp
static bool checkCompability (
    const RenderContext * renderer
) 
```





## Public Functions Documentation

### _function_ <a id="524ba265" href="#524ba265">Texture2DArrayMS</a>

```cpp
 Texture2DArrayMS () 
```



### _function_ <a id="ca01d3de" href="#ca01d3de">Texture2DArrayMS</a>

```cpp
 Texture2DArrayMS (
    const Texture2DArrayMS & second
) = delete 
```



### _function_ <a id="930b64ce" href="#930b64ce">Texture2DArrayMS</a>

```cpp
 Texture2DArrayMS (
    Texture2DArrayMS && second
) 
```



### _function_ <a id="efefcb8b" href="#efefcb8b">~Texture2DArrayMS</a>

```cpp
 ~Texture2DArrayMS () 
```



### _function_ <a id="a26568ce" href="#a26568ce">create</a>

```cpp
bool create (
    const ffw::RenderContext * renderer,
    GLsizei width,
    GLsizei height,
    GLsizei layers,
    GLenum internalformat,
    GLenum format,
    GLenum pixelformat,
    GLint samples
) 
```



### _function_ <a id="e6b9d9f1" href="#e6b9d9f1">resize</a>

```cpp
bool resize (
    GLsizei width,
    GLsizei height,
    GLsizei layers,
    GLint samples
) 
```



### _function_ <a id="87756faf" href="#87756faf">operator=</a>

```cpp
Texture2DArrayMS & operator= (
    const Texture2DArrayMS & second
) = delete 
```



### _function_ <a id="0fcd3833" href="#0fcd3833">operator=</a>

```cpp
Texture2DArrayMS & operator= (
    Texture2DArrayMS && second
) 
```





