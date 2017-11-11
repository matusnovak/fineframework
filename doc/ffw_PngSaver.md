PngSaver
===================================


**Inherits from:** [ffw::ImageWriter](ffw_ImageWriter.html)

The documentation for this class was generated from: `include/ffw/media/pngsaver.h`



## Public Functions

| Type | Name |
| -------: | :------- |
|   | [PngSaver](#731e57ad) ()  |
|   | [PngSaver](#9e4756ba) (const [PngSaver](ffw_PngSaver.html) & _other_) = delete  |
|   | [PngSaver](#8853d76b) ([PngSaver](ffw_PngSaver.html) && _other_)  |
|  void | [swap](#3c354715) ([PngSaver](ffw_PngSaver.html) & _other_)  |
|  [PngSaver](ffw_PngSaver.html) & | [operator=](#2fc893f6) (const [PngSaver](ffw_PngSaver.html) & _other_) = delete  |
|  [PngSaver](ffw_PngSaver.html) & | [operator=](#c6368efd) ([PngSaver](ffw_PngSaver.html) && _other_)  |
|  virtual  | [~PngSaver](#61324658) ()  |
|  virtual bool | [open](#7bd6eed8) (const std::string & _path_, int _width_, int _height_, [ffw::ImageType](ffw.html#fa711f90) _type_, int _quality_ = 100, int _mips_ = 1)  |
|  virtual size_t | [writeRow](#30f9a5a5) (const void * _src_)  |
|  virtual bool | [writeFooter](#43cf6063) ()  |
|  virtual void | [close](#84c6ad7e) ()  |


## Public Functions Documentation

### <span style="opacity:0.5;">function</span> <a id="731e57ad" href="#731e57ad">PngSaver</a>

```cpp
 PngSaver () 
```



### <span style="opacity:0.5;">function</span> <a id="9e4756ba" href="#9e4756ba">PngSaver</a>

```cpp
 PngSaver (
    const PngSaver & other
) = delete 
```



### <span style="opacity:0.5;">function</span> <a id="8853d76b" href="#8853d76b">PngSaver</a>

```cpp
 PngSaver (
    PngSaver && other
) 
```



### <span style="opacity:0.5;">function</span> <a id="3c354715" href="#3c354715">swap</a>

```cpp
void swap (
    PngSaver & other
) 
```



### <span style="opacity:0.5;">function</span> <a id="2fc893f6" href="#2fc893f6">operator=</a>

```cpp
PngSaver & operator= (
    const PngSaver & other
) = delete 
```



### <span style="opacity:0.5;">function</span> <a id="c6368efd" href="#c6368efd">operator=</a>

```cpp
PngSaver & operator= (
    PngSaver && other
) 
```



### <span style="opacity:0.5;">function</span> <a id="61324658" href="#61324658">~PngSaver</a>

```cpp
virtual  ~PngSaver () 
```



### <span style="opacity:0.5;">function</span> <a id="7bd6eed8" href="#7bd6eed8">open</a>

```cpp
virtual bool open (
    const std::string & path,
    int width,
    int height,
    ffw::ImageType type,
    int quality = 100,
    int mips = 1
) 
```



**Overrides:** [open](/doc/ffw_ImageWriter.md#9a8ff2c9) from class [ImageWriter](/doc/ffw_ImageWriter.md)

### <span style="opacity:0.5;">function</span> <a id="30f9a5a5" href="#30f9a5a5">writeRow</a>

```cpp
virtual size_t writeRow (
    const void * src
) 
```



**Overrides:** [writeRow](/doc/ffw_ImageWriter.md#fb673e42) from class [ImageWriter](/doc/ffw_ImageWriter.md)

### <span style="opacity:0.5;">function</span> <a id="43cf6063" href="#43cf6063">writeFooter</a>

```cpp
virtual bool writeFooter () 
```



**Overrides:** [writeFooter](/doc/ffw_ImageWriter.md#5377830a) from class [ImageWriter](/doc/ffw_ImageWriter.md)

### <span style="opacity:0.5;">function</span> <a id="84c6ad7e" href="#84c6ad7e">close</a>

```cpp
virtual void close () 
```



**Overrides:** [close](/doc/ffw_ImageWriter.md#03dcc1a2) from class [ImageWriter](/doc/ffw_ImageWriter.md)



