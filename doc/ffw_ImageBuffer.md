ImageBuffer
===================================


**Inherits from:** [ffw::ImageFormat](ffw_ImageFormat.html)

The documentation for this class was generated from: `include/ffw/math/imagebuffer.h`



## Public Functions

| Type | Name |
| -------: | :------- |
|   | [ImageBuffer](#75d2c9a5) ()  |
|   | [ImageBuffer](#c45a439e) (const [ImageBuffer](ffw_ImageBuffer.html) & _other_) = delete  |
|   | [ImageBuffer](#e715b59d) ([ImageBuffer](ffw_ImageBuffer.html) && _other_)  |
|  virtual  | [~ImageBuffer](#b2b17a91) ()  |
|  bool | [isAllocated](#90b7e4e0) () const  |
|   | [operator bool](#70e59118) () const  |
|  void | [swap](#529afd8b) ([ImageBuffer](ffw_ImageBuffer.html) & _second_)  |
|  void | [destroy](#0260e044) ()  |
|  bool | [allocate](#612ea631) (int _w_, int _h_, [ffw::ImageType](ffw.html#fa711f90) _type_, const void * _pixels_ = NULL)  |
|  unsigned char * | [getPtr](#7e23d537) ()  |
|  const unsigned char * | [getPtr](#02685602) () const  |
|  size_t | [getSize](#4a13c42a) () const  |
|  [ImageBuffer](ffw_ImageBuffer.html) & | [operator=](#0f78aa4f) (const [ImageBuffer](ffw_ImageBuffer.html) & _other_) = delete  |
|  [ImageBuffer](ffw_ImageBuffer.html) & | [operator=](#c3d52b77) ([ImageBuffer](ffw_ImageBuffer.html) && _other_)  |


## Public Functions Documentation

### <span style="opacity:0.5;">function</span> <a id="75d2c9a5" href="#75d2c9a5">ImageBuffer</a>

```cpp
inline  ImageBuffer () 
```



### <span style="opacity:0.5;">function</span> <a id="c45a439e" href="#c45a439e">ImageBuffer</a>

```cpp
 ImageBuffer (
    const ImageBuffer & other
) = delete 
```



### <span style="opacity:0.5;">function</span> <a id="e715b59d" href="#e715b59d">ImageBuffer</a>

```cpp
inline  ImageBuffer (
    ImageBuffer && other
) 
```



### <span style="opacity:0.5;">function</span> <a id="b2b17a91" href="#b2b17a91">~ImageBuffer</a>

```cpp
inline virtual  ~ImageBuffer () 
```



### <span style="opacity:0.5;">function</span> <a id="90b7e4e0" href="#90b7e4e0">isAllocated</a>

```cpp
inline bool isAllocated () const 
```



### <span style="opacity:0.5;">function</span> <a id="70e59118" href="#70e59118">operator bool</a>

```cpp
inline  operator bool () const 
```



### <span style="opacity:0.5;">function</span> <a id="529afd8b" href="#529afd8b">swap</a>

```cpp
inline void swap (
    ImageBuffer & second
) 
```



### <span style="opacity:0.5;">function</span> <a id="0260e044" href="#0260e044">destroy</a>

```cpp
inline void destroy () 
```



### <span style="opacity:0.5;">function</span> <a id="612ea631" href="#612ea631">allocate</a>

```cpp
inline bool allocate (
    int w,
    int h,
    ffw::ImageType type,
    const void * pixels = NULL
) 
```



### <span style="opacity:0.5;">function</span> <a id="7e23d537" href="#7e23d537">getPtr</a>

```cpp
inline unsigned char * getPtr () 
```



### <span style="opacity:0.5;">function</span> <a id="02685602" href="#02685602">getPtr</a>

```cpp
inline const unsigned char * getPtr () const 
```



### <span style="opacity:0.5;">function</span> <a id="4a13c42a" href="#4a13c42a">getSize</a>

```cpp
inline size_t getSize () const 
```



### <span style="opacity:0.5;">function</span> <a id="0f78aa4f" href="#0f78aa4f">operator=</a>

```cpp
ImageBuffer & operator= (
    const ImageBuffer & other
) = delete 
```



### <span style="opacity:0.5;">function</span> <a id="c3d52b77" href="#c3d52b77">operator=</a>

```cpp
inline ImageBuffer & operator= (
    ImageBuffer && other
) 
```





