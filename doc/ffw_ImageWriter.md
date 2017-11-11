ImageWriter
===================================


**Inherits from:** [ffw::ImageFormat](ffw_ImageFormat.html)

**Implemented by:** [ffw::BmpSaver](ffw_BmpSaver.html)[ffw::DdsSaver](ffw_DdsSaver.html), [ffw::JpgSaver](ffw_JpgSaver.html), [ffw::PbmSaver](ffw_PbmSaver.html), [ffw::PngSaver](ffw_PngSaver.html), [ffw::TgaSaver](ffw_TgaSaver.html), [ffw::TifSaver](ffw_TifSaver.html), 

The documentation for this class was generated from: `include/ffw/media/imagesaver.h`



## Protected Attributes

| Type | Name |
| -------: | :------- |
|  bool | [loaded](#c4a70ccc) |
|  int | [row](#6e1fcc70) |
|  int | [mipmapOffset](#b67861f7) |
|  int | [mipmaps](#85e80233) |


## Public Functions

| Type | Name |
| -------: | :------- |
|   | [ImageWriter](#14729590) ()  |
|  virtual  | [~ImageWriter](#07fbdfc1) ()  |
|  virtual bool | [open](#9a8ff2c9) (const std::string & _path_, int _width_, int _height_, [ffw::ImageType](ffw.html#fa711f90) _type_, int _quality_ = 100, int _mips_ = 1) = 0  |
|  virtual void | [close](#03dcc1a2) () = 0  |
|  virtual size_t | [writeRow](#fb673e42) (const void * _src_) = 0  |
|  bool | [writeAll](#f0b9e6a6) (void * _dest_)  |
|  bool | [writeAll](#0c580eae) ([ffw::ImageBuffer](ffw_ImageBuffer.html) & _buffer_)  |
|  virtual bool | [setMipMap](#473bca96) (int _level_)  |
|  virtual bool | [writeFooter](#5377830a) () = 0  |
|  bool | [eof](#65087229) () const  |
|   | [operator bool](#72dfb5cf) () const  |
|  int | [getRowOffset](#2048310e) () const  |
|  bool | [isOpen](#fa51301e) () const  |
|  int | [getNumOfMipMaps](#018b046b) () const  |
|  int | [getMipMapOffset](#5d705d7a) () const  |


## Protected Attributes Documentation

### <span style="opacity:0.5;">variable</span> <a id="c4a70ccc" href="#c4a70ccc">loaded</a>

```cpp
bool loaded
```



### <span style="opacity:0.5;">variable</span> <a id="6e1fcc70" href="#6e1fcc70">row</a>

```cpp
int row
```



### <span style="opacity:0.5;">variable</span> <a id="b67861f7" href="#b67861f7">mipmapOffset</a>

```cpp
int mipmapOffset
```



### <span style="opacity:0.5;">variable</span> <a id="85e80233" href="#85e80233">mipmaps</a>

```cpp
int mipmaps
```





## Public Functions Documentation

### <span style="opacity:0.5;">function</span> <a id="14729590" href="#14729590">ImageWriter</a>

```cpp
 ImageWriter () 
```



### <span style="opacity:0.5;">function</span> <a id="07fbdfc1" href="#07fbdfc1">~ImageWriter</a>

```cpp
virtual  ~ImageWriter () 
```



### <span style="opacity:0.5;">function</span> <a id="9a8ff2c9" href="#9a8ff2c9">open</a>

```cpp
virtual bool open (
    const std::string & path,
    int width,
    int height,
    ffw::ImageType type,
    int quality = 100,
    int mips = 1
) = 0 
```



### <span style="opacity:0.5;">function</span> <a id="03dcc1a2" href="#03dcc1a2">close</a>

```cpp
virtual void close () = 0 
```



### <span style="opacity:0.5;">function</span> <a id="fb673e42" href="#fb673e42">writeRow</a>

```cpp
virtual size_t writeRow (
    const void * src
) = 0 
```



### <span style="opacity:0.5;">function</span> <a id="f0b9e6a6" href="#f0b9e6a6">writeAll</a>

```cpp
bool writeAll (
    void * dest
) 
```



### <span style="opacity:0.5;">function</span> <a id="0c580eae" href="#0c580eae">writeAll</a>

```cpp
bool writeAll (
    ffw::ImageBuffer & buffer
) 
```



### <span style="opacity:0.5;">function</span> <a id="473bca96" href="#473bca96">setMipMap</a>

```cpp
virtual bool setMipMap (
    int level
) 
```



### <span style="opacity:0.5;">function</span> <a id="5377830a" href="#5377830a">writeFooter</a>

```cpp
virtual bool writeFooter () = 0 
```



### <span style="opacity:0.5;">function</span> <a id="65087229" href="#65087229">eof</a>

```cpp
inline bool eof () const 
```



### <span style="opacity:0.5;">function</span> <a id="72dfb5cf" href="#72dfb5cf">operator bool</a>

```cpp
inline  operator bool () const 
```



### <span style="opacity:0.5;">function</span> <a id="2048310e" href="#2048310e">getRowOffset</a>

```cpp
inline int getRowOffset () const 
```



### <span style="opacity:0.5;">function</span> <a id="fa51301e" href="#fa51301e">isOpen</a>

```cpp
inline bool isOpen () const 
```



### <span style="opacity:0.5;">function</span> <a id="018b046b" href="#018b046b">getNumOfMipMaps</a>

```cpp
inline int getNumOfMipMaps () const 
```



### <span style="opacity:0.5;">function</span> <a id="5d705d7a" href="#5d705d7a">getMipMapOffset</a>

```cpp
inline int getMipMapOffset () const 
```





