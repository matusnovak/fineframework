DdsSaver
===================================


**Inherits from:** [ffw::ImageWriter](ffw_ImageWriter.html)

The documentation for this class was generated from: `include/ffw/media/ddssaver.h`



## Public Functions

| Type | Name |
| -------: | :------- |
|   | [DdsSaver](#14b378ea) ()  |
|   | [DdsSaver](#0346f9ca) (const [DdsSaver](ffw_DdsSaver.html) & _other_) = delete  |
|   | [DdsSaver](#382b4dda) ([DdsSaver](ffw_DdsSaver.html) && _other_)  |
|  void | [swap](#6504cde6) ([DdsSaver](ffw_DdsSaver.html) & _other_)  |
|  [DdsSaver](ffw_DdsSaver.html) & | [operator=](#be7b6725) (const [DdsSaver](ffw_DdsSaver.html) & _other_) = delete  |
|  [DdsSaver](ffw_DdsSaver.html) & | [operator=](#036de46b) ([DdsSaver](ffw_DdsSaver.html) && _other_)  |
|  virtual  | [~DdsSaver](#8160b410) ()  |
|  virtual bool | [open](#f0dfcbef) (const std::string & _path_, int _width_, int _height_, [ffw::ImageType](ffw.html#fa711f90) _type_, int _quality_ = 100, int _mips_ = 1)  |
|  virtual size_t | [writeRow](#dc2deec9) (const void * _src_)  |
|  virtual bool | [writeFooter](#469d90ca) ()  |
|  virtual void | [close](#6354bd30) ()  |
|  virtual bool | [setMipMap](#564c58a3) (int _level_)  |


## Public Functions Documentation

### <span style="opacity:0.5;">function</span> <a id="14b378ea" href="#14b378ea">DdsSaver</a>

```cpp
 DdsSaver () 
```



### <span style="opacity:0.5;">function</span> <a id="0346f9ca" href="#0346f9ca">DdsSaver</a>

```cpp
 DdsSaver (
    const DdsSaver & other
) = delete 
```



### <span style="opacity:0.5;">function</span> <a id="382b4dda" href="#382b4dda">DdsSaver</a>

```cpp
 DdsSaver (
    DdsSaver && other
) 
```



### <span style="opacity:0.5;">function</span> <a id="6504cde6" href="#6504cde6">swap</a>

```cpp
void swap (
    DdsSaver & other
) 
```



### <span style="opacity:0.5;">function</span> <a id="be7b6725" href="#be7b6725">operator=</a>

```cpp
DdsSaver & operator= (
    const DdsSaver & other
) = delete 
```



### <span style="opacity:0.5;">function</span> <a id="036de46b" href="#036de46b">operator=</a>

```cpp
DdsSaver & operator= (
    DdsSaver && other
) 
```



### <span style="opacity:0.5;">function</span> <a id="8160b410" href="#8160b410">~DdsSaver</a>

```cpp
virtual  ~DdsSaver () 
```



### <span style="opacity:0.5;">function</span> <a id="f0dfcbef" href="#f0dfcbef">open</a>

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

### <span style="opacity:0.5;">function</span> <a id="dc2deec9" href="#dc2deec9">writeRow</a>

```cpp
virtual size_t writeRow (
    const void * src
) 
```



**Overrides:** [writeRow](/doc/ffw_ImageWriter.md#fb673e42) from class [ImageWriter](/doc/ffw_ImageWriter.md)

### <span style="opacity:0.5;">function</span> <a id="469d90ca" href="#469d90ca">writeFooter</a>

```cpp
virtual bool writeFooter () 
```



**Overrides:** [writeFooter](/doc/ffw_ImageWriter.md#5377830a) from class [ImageWriter](/doc/ffw_ImageWriter.md)

### <span style="opacity:0.5;">function</span> <a id="6354bd30" href="#6354bd30">close</a>

```cpp
virtual void close () 
```



**Overrides:** [close](/doc/ffw_ImageWriter.md#03dcc1a2) from class [ImageWriter](/doc/ffw_ImageWriter.md)

### <span style="opacity:0.5;">function</span> <a id="564c58a3" href="#564c58a3">setMipMap</a>

```cpp
virtual bool setMipMap (
    int level
) 
```



**Overrides:** [setMipMap](/doc/ffw_ImageWriter.md#473bca96) from class [ImageWriter](/doc/ffw_ImageWriter.md)



