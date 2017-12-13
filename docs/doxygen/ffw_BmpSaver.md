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
|  virtual bool | [open](#f4ca5495) (const std::string & _path_, int _width_, int _height_, [ffw::ImageType](ffw.html#fa711f90) _type_, int _quality_ = 100, int _mips_ = 1)  |
|  virtual size_t | [writeRow](#fb7bfe34) (const void * _src_)  |
|  virtual bool | [writeFooter](#f07405c5) ()  |
|  virtual void | [close](#62ad0f62) ()  |


## Public Functions Documentation

### _function_ <a id="62f7f143" href="#62f7f143">BmpSaver</a>

```cpp
 BmpSaver () 
```



### _function_ <a id="96ae3ec1" href="#96ae3ec1">BmpSaver</a>

```cpp
 BmpSaver (
    const BmpSaver & other
) = delete 
```



### _function_ <a id="63350de9" href="#63350de9">BmpSaver</a>

```cpp
 BmpSaver (
    BmpSaver && other
) 
```



### _function_ <a id="8ef85449" href="#8ef85449">swap</a>

```cpp
void swap (
    BmpSaver & other
) 
```



### _function_ <a id="91c62cf6" href="#91c62cf6">operator=</a>

```cpp
BmpSaver & operator= (
    const BmpSaver & other
) = delete 
```



### _function_ <a id="5a605eba" href="#5a605eba">operator=</a>

```cpp
BmpSaver & operator= (
    BmpSaver && other
) 
```



### _function_ <a id="966dca03" href="#966dca03">~BmpSaver</a>

```cpp
virtual  ~BmpSaver () 
```



### _function_ <a id="f4ca5495" href="#f4ca5495">open</a>

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



**Overrides:** [open](/doxygen/ffw_ImageWriter.md#9a8ff2c9) from class [ImageWriter](/doxygen/ffw_ImageWriter.md)

### _function_ <a id="fb7bfe34" href="#fb7bfe34">writeRow</a>

```cpp
virtual size_t writeRow (
    const void * src
) 
```



**Overrides:** [writeRow](/doxygen/ffw_ImageWriter.md#fb673e42) from class [ImageWriter](/doxygen/ffw_ImageWriter.md)

### _function_ <a id="f07405c5" href="#f07405c5">writeFooter</a>

```cpp
virtual bool writeFooter () 
```



**Overrides:** [writeFooter](/doxygen/ffw_ImageWriter.md#5377830a) from class [ImageWriter](/doxygen/ffw_ImageWriter.md)

### _function_ <a id="62ad0f62" href="#62ad0f62">close</a>

```cpp
virtual void close () 
```



**Overrides:** [close](/doxygen/ffw_ImageWriter.md#03dcc1a2) from class [ImageWriter](/doxygen/ffw_ImageWriter.md)



