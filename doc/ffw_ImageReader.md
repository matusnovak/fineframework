ImageReader
===================================


**Inherits from:** [ffw::ImageFormat](ffw_ImageFormat.html)

**Implemented by:** [ffw::BmpLoader](ffw_BmpLoader.html)[ffw::JpgLoader](ffw_JpgLoader.html), [ffw::PbmLoader](ffw_PbmLoader.html), [ffw::PngLoader](ffw_PngLoader.html), [ffw::TgaLoader](ffw_TgaLoader.html), [ffw::TifLoader](ffw_TifLoader.html), 

The documentation for this class was generated from: `include/ffw/media/imageloader.h`



## Protected Attributes

| Type | Name |
| -------: | :------- |
|  bool | [loaded](#11dfc1c0) |
|  int | [row](#0deb5791) |


## Public Functions

| Type | Name |
| -------: | :------- |
|   | [ImageReader](#35af4df3) ()  |
|  virtual  | [~ImageReader](#1edd3cb9) ()  |
|  virtual bool | [open](#25e290f7) (const std::string & _path_) = 0  |
|  virtual void | [close](#f00a5543) () = 0  |
|  virtual size_t | [readRow](#2b7cda9d) (void * _dest_) = 0  |
|  bool | [eof](#59058f5f) () const  |
|   | [operator bool](#2409f778) () const  |
|  int | [getRowOffset](#2ed95c51) () const  |
|  bool | [isOpen](#dc3f3049) () const  |


## Protected Attributes Documentation

### <span style="opacity:0.5;">variable</span> <a id="11dfc1c0" href="#11dfc1c0">loaded</a>

```cpp
bool loaded
```



### <span style="opacity:0.5;">variable</span> <a id="0deb5791" href="#0deb5791">row</a>

```cpp
int row
```





## Public Functions Documentation

### <span style="opacity:0.5;">function</span> <a id="35af4df3" href="#35af4df3">ImageReader</a>

```cpp
 ImageReader () 
```



### <span style="opacity:0.5;">function</span> <a id="1edd3cb9" href="#1edd3cb9">~ImageReader</a>

```cpp
virtual  ~ImageReader () 
```



### <span style="opacity:0.5;">function</span> <a id="25e290f7" href="#25e290f7">open</a>

```cpp
virtual bool open (
    const std::string & path
) = 0 
```



### <span style="opacity:0.5;">function</span> <a id="f00a5543" href="#f00a5543">close</a>

```cpp
virtual void close () = 0 
```



### <span style="opacity:0.5;">function</span> <a id="2b7cda9d" href="#2b7cda9d">readRow</a>

```cpp
virtual size_t readRow (
    void * dest
) = 0 
```



### <span style="opacity:0.5;">function</span> <a id="59058f5f" href="#59058f5f">eof</a>

```cpp
inline bool eof () const 
```



### <span style="opacity:0.5;">function</span> <a id="2409f778" href="#2409f778">operator bool</a>

```cpp
inline  operator bool () const 
```



### <span style="opacity:0.5;">function</span> <a id="2ed95c51" href="#2ed95c51">getRowOffset</a>

```cpp
inline int getRowOffset () const 
```



### <span style="opacity:0.5;">function</span> <a id="dc3f3049" href="#dc3f3049">isOpen</a>

```cpp
inline bool isOpen () const 
```





