Texture1DArray
===================================


**Inherits from:** [ffw::Texture](ffw_Texture.html)

The documentation for this class was generated from: `include/ffw/graphics/texture1darray.h`



## Public Functions

| Type | Name |
| -------: | :------- |
|   | [Texture1DArray](#29668d50) ()  |
|   | [Texture1DArray](#696ead7a) (const [Texture1DArray](ffw_Texture1DArray.html) & _second_) = delete  |
|   | [Texture1DArray](#0ef986ae) ([Texture1DArray](ffw_Texture1DArray.html) && _second_)  |
|   | [~Texture1DArray](#84fa9c07) ()  |
|  bool | [create](#e9977f9d) ([GLsizei]() _width_, [GLsizei]() _layers_, [GLenum]() _internalformat_, [GLenum]() _format_, [GLenum]() _pixelformat_, const [GLvoid]() * _pixels_ = NULL)  |
|  bool | [resize](#208caf07) ([GLsizei]() _width_, [GLsizei]() _layers_)  |
|  bool | [setPixels](#fcbc24aa) ([GLint]() _level_, [GLint]() _xoffset_, [GLint]() _loffset_, [GLsizei]() _width_, const void * _pixels_)  |
|  bool | [setPixels](#ca4105ff) ([GLint]() _level_, const [GLvoid]() * _pixels_ = NULL)  |
|  bool | [getPixels](#97ceafb0) (void * _pixels_) const  |
|  [Texture1DArray](ffw_Texture1DArray.html) & | [operator=](#0780bf4a) (const [Texture1DArray](ffw_Texture1DArray.html) & _second_) = delete  |
|  [Texture1DArray](ffw_Texture1DArray.html) & | [operator=](#8d22d337) ([Texture1DArray](ffw_Texture1DArray.html) && _second_)  |


## Public Functions Documentation

### _function_ <a id="29668d50" href="#29668d50">Texture1DArray</a>

```cpp
 Texture1DArray () 
```



### _function_ <a id="696ead7a" href="#696ead7a">Texture1DArray</a>

```cpp
 Texture1DArray (
    const Texture1DArray & second
) = delete 
```



### _function_ <a id="0ef986ae" href="#0ef986ae">Texture1DArray</a>

```cpp
 Texture1DArray (
    Texture1DArray && second
) 
```



### _function_ <a id="84fa9c07" href="#84fa9c07">~Texture1DArray</a>

```cpp
 ~Texture1DArray () 
```



### _function_ <a id="e9977f9d" href="#e9977f9d">create</a>

```cpp
bool create (
    GLsizei width,
    GLsizei layers,
    GLenum internalformat,
    GLenum format,
    GLenum pixelformat,
    const GLvoid * pixels = NULL
) 
```



### _function_ <a id="208caf07" href="#208caf07">resize</a>

```cpp
bool resize (
    GLsizei width,
    GLsizei layers
) 
```



### _function_ <a id="fcbc24aa" href="#fcbc24aa">setPixels</a>

```cpp
bool setPixels (
    GLint level,
    GLint xoffset,
    GLint loffset,
    GLsizei width,
    const void * pixels
) 
```



### _function_ <a id="ca4105ff" href="#ca4105ff">setPixels</a>

```cpp
bool setPixels (
    GLint level,
    const GLvoid * pixels = NULL
) 
```



### _function_ <a id="97ceafb0" href="#97ceafb0">getPixels</a>

```cpp
bool getPixels (
    void * pixels
) const 
```



### _function_ <a id="0780bf4a" href="#0780bf4a">operator=</a>

```cpp
Texture1DArray & operator= (
    const Texture1DArray & second
) = delete 
```



### _function_ <a id="8d22d337" href="#8d22d337">operator=</a>

```cpp
Texture1DArray & operator= (
    Texture1DArray && second
) 
```





