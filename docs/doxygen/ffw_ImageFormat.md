ImageFormat
===================================


**Implemented by:** [ffw::ImageBuffer](ffw_ImageBuffer.html), [ffw::ImageReader](ffw_ImageReader.html), [ffw::ImageWriter](ffw_ImageWriter.html), 

The documentation for this class was generated from: `include/ffw/math/imagebuffer.h`



## Protected Attributes

| Type | Name |
| -------: | :------- |
|  [ffw::ImageType](ffw.html#fa711f90) | [format](#bbc17e53) |
|  int | [width](#78cd7bf4) |
|  int | [height](#e2245705) |
|  int | [depth](#dd478a2c) |


## Public Functions

| Type | Name |
| -------: | :------- |
|   | [ImageFormat](#98ac8dc9) ()  |
|   | [ImageFormat](#747af9a6) (int _width_, int _height_, int _depth_, [ffw::ImageType](ffw.html#fa711f90) _format_)  |
|   | [ImageFormat](#1399627d) (const [ImageFormat](ffw_ImageFormat.html) & _other_)  |
|  [ImageType](ffw.html#fa711f90) | [getImageType](#3a98c1e0) () const  |
|  int | [getWidth](#00accaab) (int _mipmap_ = 0) const  |
|  int | [getHeight](#22aa1840) (int _mipmap_ = 0) const  |
|  int | [getDepth](#dd4e53a3) (int _mipmap_ = 0) const  |
|  size_t | [getStrideSize](#f2c159a8) (int _mipmap_ = 0) const  |
|  int | [getBitsPerPixel](#4b0899a1) () const  |
|  int | [getBitDepth](#b40b4068) () const  |
|  int | [getNumberOfChannels](#c099d834) () const  |
|  bool | [isCompressed](#8c881794) () const  |
|  size_t | [getMipMapSize](#a2261bd2) (int _level_) const  |
|  size_t | [getMipMapPtrOffset](#cc7b6486) (int _level_) const  |
|  void | [swap](#8858a7dd) ([ImageFormat](ffw_ImageFormat.html) & _other_)  |
|  [ImageFormat](ffw_ImageFormat.html) & | [operator=](#bf1c97c0) (const [ImageFormat](ffw_ImageFormat.html) & _other_)  |
|  size_t | [getAllocationSize](#9c5c0692) (int _mipmaps_) const  |
|  bool | [operator==](#372d3882) (const [ImageFormat](ffw_ImageFormat.html) & _other_) const  |


## Protected Attributes Documentation

### _variable_ <a id="bbc17e53" href="#bbc17e53">format</a>

```cpp
ffw::ImageType format
```



### _variable_ <a id="78cd7bf4" href="#78cd7bf4">width</a>

```cpp
int width
```



### _variable_ <a id="e2245705" href="#e2245705">height</a>

```cpp
int height
```



### _variable_ <a id="dd478a2c" href="#dd478a2c">depth</a>

```cpp
int depth
```





## Public Functions Documentation

### _function_ <a id="98ac8dc9" href="#98ac8dc9">ImageFormat</a>

```cpp
inline  ImageFormat () 
```



### _function_ <a id="747af9a6" href="#747af9a6">ImageFormat</a>

```cpp
inline  ImageFormat (
    int width,
    int height,
    int depth,
    ffw::ImageType format
) 
```



### _function_ <a id="1399627d" href="#1399627d">ImageFormat</a>

```cpp
inline  ImageFormat (
    const ImageFormat & other
) 
```



### _function_ <a id="3a98c1e0" href="#3a98c1e0">getImageType</a>

```cpp
inline ImageType getImageType () const 
```



### _function_ <a id="00accaab" href="#00accaab">getWidth</a>

```cpp
inline int getWidth (
    int mipmap = 0
) const 
```



### _function_ <a id="22aa1840" href="#22aa1840">getHeight</a>

```cpp
inline int getHeight (
    int mipmap = 0
) const 
```



### _function_ <a id="dd4e53a3" href="#dd4e53a3">getDepth</a>

```cpp
inline int getDepth (
    int mipmap = 0
) const 
```



### _function_ <a id="f2c159a8" href="#f2c159a8">getStrideSize</a>

```cpp
inline size_t getStrideSize (
    int mipmap = 0
) const 
```



### _function_ <a id="4b0899a1" href="#4b0899a1">getBitsPerPixel</a>

```cpp
inline int getBitsPerPixel () const 
```



### _function_ <a id="b40b4068" href="#b40b4068">getBitDepth</a>

```cpp
inline int getBitDepth () const 
```



### _function_ <a id="c099d834" href="#c099d834">getNumberOfChannels</a>

```cpp
inline int getNumberOfChannels () const 
```



### _function_ <a id="8c881794" href="#8c881794">isCompressed</a>

```cpp
inline bool isCompressed () const 
```



### _function_ <a id="a2261bd2" href="#a2261bd2">getMipMapSize</a>

```cpp
inline size_t getMipMapSize (
    int level
) const 
```



### _function_ <a id="cc7b6486" href="#cc7b6486">getMipMapPtrOffset</a>

```cpp
inline size_t getMipMapPtrOffset (
    int level
) const 
```



### _function_ <a id="8858a7dd" href="#8858a7dd">swap</a>

```cpp
inline void swap (
    ImageFormat & other
) 
```



### _function_ <a id="bf1c97c0" href="#bf1c97c0">operator=</a>

```cpp
inline ImageFormat & operator= (
    const ImageFormat & other
) 
```



### _function_ <a id="9c5c0692" href="#9c5c0692">getAllocationSize</a>

```cpp
inline size_t getAllocationSize (
    int mipmaps
) const 
```



### _function_ <a id="372d3882" href="#372d3882">operator==</a>

```cpp
inline bool operator== (
    const ImageFormat & other
) const 
```





