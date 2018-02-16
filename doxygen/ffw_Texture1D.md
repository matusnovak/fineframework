Texture1D
===================================


**Inherits from:** [ffw::Texture](ffw_Texture.html)

The documentation for this class was generated from: `include/ffw/graphics/texture1d.h`



## Public Functions

| Type | Name |
| -------: | :------- |
|   | [Texture1D](#fe4bfdb5) ()  |
|   | [Texture1D](#e0d3bc95) (const [Texture1D](ffw_Texture1D.html) & _second_) = delete  |
|   | [Texture1D](#5c5335f8) ([Texture1D](ffw_Texture1D.html) && _second_)  |
|   | [~Texture1D](#896d0709) ()  |
|  bool | [create](#bb5b4a0f) ([GLsizei]() _width_, [GLenum]() _internalformat_, [GLenum]() _format_, [GLenum]() _pixelformat_, const [GLvoid]() * _pixels_ = NULL)  |
|  bool | [resize](#7a8c5174) ([GLsizei]() _width_)  |
|  bool | [createFromBuffer](#ea6fffde) (const [ImageBuffer](ffw_ImageBuffer.html) & _buffer_)  |
|  bool | [setPixels](#5a5ecedf) ([GLint]() _level_, const [GLvoid]() * _pixels_ = NULL)  |
|  bool | [setPixels](#7e942146) ([GLint]() _level_, [GLint]() _xoffset_, [GLsizei]() _width_, const [GLvoid]() * _pixels_)  |
|  bool | [getPixels](#44725987) (void * _pixels_) const  |
|  [Texture1D](ffw_Texture1D.html) & | [operator=](#10fe2ad6) (const [Texture1D](ffw_Texture1D.html) & _second_) = delete  |
|  [Texture1D](ffw_Texture1D.html) & | [operator=](#67d2be6d) ([Texture1D](ffw_Texture1D.html) && _second_)  |


## Public Functions Documentation

### _function_ <a id="fe4bfdb5" href="#fe4bfdb5">Texture1D</a>

```cpp
 Texture1D () 
```



### _function_ <a id="e0d3bc95" href="#e0d3bc95">Texture1D</a>

```cpp
 Texture1D (
    const Texture1D & second
) = delete 
```



### _function_ <a id="5c5335f8" href="#5c5335f8">Texture1D</a>

```cpp
 Texture1D (
    Texture1D && second
) 
```



### _function_ <a id="896d0709" href="#896d0709">~Texture1D</a>

```cpp
 ~Texture1D () 
```



### _function_ <a id="bb5b4a0f" href="#bb5b4a0f">create</a>

```cpp
bool create (
    GLsizei width,
    GLenum internalformat,
    GLenum format,
    GLenum pixelformat,
    const GLvoid * pixels = NULL
) 
```



### _function_ <a id="7a8c5174" href="#7a8c5174">resize</a>

```cpp
bool resize (
    GLsizei width
) 
```



### _function_ <a id="ea6fffde" href="#ea6fffde">createFromBuffer</a>

```cpp
bool createFromBuffer (
    const ImageBuffer & buffer
) 
```



### _function_ <a id="5a5ecedf" href="#5a5ecedf">setPixels</a>

```cpp
bool setPixels (
    GLint level,
    const GLvoid * pixels = NULL
) 
```



### _function_ <a id="7e942146" href="#7e942146">setPixels</a>

```cpp
bool setPixels (
    GLint level,
    GLint xoffset,
    GLsizei width,
    const GLvoid * pixels
) 
```



### _function_ <a id="44725987" href="#44725987">getPixels</a>

```cpp
bool getPixels (
    void * pixels
) const 
```



### _function_ <a id="10fe2ad6" href="#10fe2ad6">operator=</a>

```cpp
Texture1D & operator= (
    const Texture1D & second
) = delete 
```



### _function_ <a id="67d2be6d" href="#67d2be6d">operator=</a>

```cpp
Texture1D & operator= (
    Texture1D && second
) 
```





