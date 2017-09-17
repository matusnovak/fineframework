BmpSaver
===================================


**Inherits from:** [ffw::ImageWriter](ffw_ImageWriter.html)

The documentation for this class was generated from: `include/ffw/media/bmpsaver.h`



## Public Functions

| Type | Name |
| -------: | :------- |
|   | [BmpSaver](#62f7f143) ()  |
|   | [BmpSaver](#96ae3ec1) (const [BmpSaver](ffw_BmpSaver.html) & _other_) = delete  |
|   | [BmpSaver](#63350de9) ([BmpSaver](ffw_BmpSaver.html) && _other_)  |
|  void | [swap](#8ef85449) ([BmpSaver](ffw_BmpSaver.html) & _other_)  |
|  [BmpSaver](ffw_BmpSaver.html) & | [operator=](#91c62cf6) (const [BmpSaver](ffw_BmpSaver.html) & _other_) = delete  |
|  [BmpSaver](ffw_BmpSaver.html) & | [operator=](#5a605eba) ([BmpSaver](ffw_BmpSaver.html) && _other_)  |
|  virtual  | [~BmpSaver](#966dca03) ()  |
|  virtual bool | [open](#1143a9c8) (const std::string & _path_, int _width_, int _height_, [ffw::ImageType](ffw.html#fa711f90) _type_, int _quality_ = 100)  |
|  virtual size_t | [writeRow](#fb7bfe34) (const void * _src_)  |
|  virtual bool | [writeFooter](#f07405c5) ()  |
|  virtual void | [close](#62ad0f62) ()  |


## Public Functions Documentation

### <span style="opacity:0.5;">function</span> <a id="62f7f143" href="#62f7f143">BmpSaver</a>

```cpp
 BmpSaver () 
```



### <span style="opacity:0.5;">function</span> <a id="96ae3ec1" href="#96ae3ec1">BmpSaver</a>

```cpp
 BmpSaver (
    const BmpSaver & other
) = delete 
```



### <span style="opacity:0.5;">function</span> <a id="63350de9" href="#63350de9">BmpSaver</a>

```cpp
 BmpSaver (
    BmpSaver && other
) 
```



### <span style="opacity:0.5;">function</span> <a id="8ef85449" href="#8ef85449">swap</a>

```cpp
void swap (
    BmpSaver & other
) 
```



### <span style="opacity:0.5;">function</span> <a id="91c62cf6" href="#91c62cf6">operator=</a>

```cpp
BmpSaver & operator= (
    const BmpSaver & other
) = delete 
```



### <span style="opacity:0.5;">function</span> <a id="5a605eba" href="#5a605eba">operator=</a>

```cpp
BmpSaver & operator= (
    BmpSaver && other
) 
```



### <span style="opacity:0.5;">function</span> <a id="966dca03" href="#966dca03">~BmpSaver</a>

```cpp
virtual  ~BmpSaver () 
```



### <span style="opacity:0.5;">function</span> <a id="1143a9c8" href="#1143a9c8">open</a>

```cpp
virtual bool open (
    const std::string & path,
    int width,
    int height,
    ffw::ImageType type,
    int quality = 100
) 
```



**Overrides:** [open](/doc/ffw_ImageWriter.md#c742773b)

### <span style="opacity:0.5;">function</span> <a id="fb7bfe34" href="#fb7bfe34">writeRow</a>

```cpp
virtual size_t writeRow (
    const void * src
) 
```



**Overrides:** [writeRow](/doc/ffw_ImageWriter.md#fb673e42)

### <span style="opacity:0.5;">function</span> <a id="f07405c5" href="#f07405c5">writeFooter</a>

```cpp
virtual bool writeFooter () 
```



**Overrides:** [writeFooter](/doc/ffw_ImageWriter.md#5377830a)

### <span style="opacity:0.5;">function</span> <a id="62ad0f62" href="#62ad0f62">close</a>

```cpp
virtual void close () 
```



**Overrides:** [close](/doc/ffw_ImageWriter.md#03dcc1a2)



