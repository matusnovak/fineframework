TextureCubemap
===================================


**Inherits from:** [ffw::Texture](ffw_Texture.html)

The documentation for this class was generated from: `include/ffw/graphics/texturecubemap.h`



## Public Functions

| Type | Name |
| -------: | :------- |
|   | [TextureCubemap](#006ef9ef) ()  |
|   | [TextureCubemap](#68ebeb64) (const [TextureCubemap](ffw_TextureCubemap.html) & _second_) = delete  |
|   | [TextureCubemap](#32cf2aed) ([TextureCubemap](ffw_TextureCubemap.html) && _second_)  |
|   | [~TextureCubemap](#60859573) ()  |
|  bool | [create](#5879b551) ([GLsizei]() _width_, [GLsizei]() _height_, [GLenum]() _internalformat_, [GLenum]() _format_, [GLenum]() _pixelformat_, const [GLvoid]() * _pixels_ = NULL)  |
|  bool | [resize](#2a4ff149) ([GLsizei]() _width_, [GLsizei]() _height_)  |
|  bool | [setPixels](#754cf479) ([GLint]() _level_, [GLint]() _xoffset_, [GLint]() _yoffset_, [GLsizei]() _width_, [GLsizei]() _height_, [GLint]() _side_, const [GLvoid]() * _pixels_)  _Sets the pixels._ |
|  bool | [setPixels](#115f3c21) ([GLint]() _level_, [GLint]() _side_, const [GLvoid]() * _pixels_ = NULL)  |
|  bool | [setFromBuffer](#6f60d98a) (const [ImageBuffer](ffw_ImageBuffer.html) & _buffer_, [GLint]() _side_, bool _inverse_ = false)  |
|  bool | [getPixels](#9d17ed48) (void * _pixels_)  |
|  [TextureCubemap](ffw_TextureCubemap.html) & | [operator=](#c94b49e8) (const [TextureCubemap](ffw_TextureCubemap.html) & _second_) = delete  |
|  [TextureCubemap](ffw_TextureCubemap.html) & | [operator=](#6993cfe5) ([TextureCubemap](ffw_TextureCubemap.html) && _second_)  |


## Public Functions Documentation

### _function_ <a id="006ef9ef" href="#006ef9ef">TextureCubemap</a>

```cpp
 TextureCubemap () 
```



### _function_ <a id="68ebeb64" href="#68ebeb64">TextureCubemap</a>

```cpp
 TextureCubemap (
    const TextureCubemap & second
) = delete 
```



### _function_ <a id="32cf2aed" href="#32cf2aed">TextureCubemap</a>

```cpp
 TextureCubemap (
    TextureCubemap && second
) 
```



### _function_ <a id="60859573" href="#60859573">~TextureCubemap</a>

```cpp
 ~TextureCubemap () 
```



### _function_ <a id="5879b551" href="#5879b551">create</a>

```cpp
bool create (
    GLsizei width,
    GLsizei height,
    GLenum internalformat,
    GLenum format,
    GLenum pixelformat,
    const GLvoid * pixels = NULL
) 
```



### _function_ <a id="2a4ff149" href="#2a4ff149">resize</a>

```cpp
bool resize (
    GLsizei width,
    GLsizei height
) 
```



### _function_ <a id="754cf479" href="#754cf479">setPixels</a>

```cpp
bool setPixels (
    GLint level,
    GLint xoffset,
    GLint yoffset,
    GLsizei width,
    GLsizei height,
    GLint side,
    const GLvoid * pixels
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



### _function_ <a id="115f3c21" href="#115f3c21">setPixels</a>

```cpp
bool setPixels (
    GLint level,
    GLint side,
    const GLvoid * pixels = NULL
) 
```



### _function_ <a id="6f60d98a" href="#6f60d98a">setFromBuffer</a>

```cpp
bool setFromBuffer (
    const ImageBuffer & buffer,
    GLint side,
    bool inverse = false
) 
```



### _function_ <a id="9d17ed48" href="#9d17ed48">getPixels</a>

```cpp
bool getPixels (
    void * pixels
) 
```



### _function_ <a id="c94b49e8" href="#c94b49e8">operator=</a>

```cpp
TextureCubemap & operator= (
    const TextureCubemap & second
) = delete 
```



### _function_ <a id="6993cfe5" href="#6993cfe5">operator=</a>

```cpp
TextureCubemap & operator= (
    TextureCubemap && second
) 
```





