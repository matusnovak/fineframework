JpgSaver
===================================


**Inherits from:** [ffw::ImageWriter](ffw_ImageWriter.html)

The documentation for this class was generated from: `include/ffw/media/jpgsaver.h`



## Public Functions

| Type | Name |
| -------: | :------- |
|   | [JpgSaver](#306a181d) ()  |
|   | [JpgSaver](#bf8e4f72) (const [JpgSaver](ffw_JpgSaver.html) & _other_) = delete  |
|   | [JpgSaver](#1742c42a) ([JpgSaver](ffw_JpgSaver.html) && _other_)  |
|  void | [swap](#8e3c83d9) ([JpgSaver](ffw_JpgSaver.html) & _other_)  |
|  [JpgSaver](ffw_JpgSaver.html) & | [operator=](#7e6a34ee) (const [JpgSaver](ffw_JpgSaver.html) & _other_) = delete  |
|  [JpgSaver](ffw_JpgSaver.html) & | [operator=](#4d464c57) ([JpgSaver](ffw_JpgSaver.html) && _other_)  |
|  virtual  | [~JpgSaver](#49340bb6) ()  |
|  virtual bool | [open](#3ce59316) (const std::string & _path_, int _width_, int _height_, [ffw::ImageType](ffw.html#fa711f90) _type_, int _quality_ = 100, int _mips_ = 1)  |
|  virtual size_t | [writeRow](#5aa57ca5) (const void * _src_)  |
|  virtual bool | [writeFooter](#64344997) ()  |
|  virtual void | [close](#57e5f893) ()  |


## Public Functions Documentation

### _function_ <a id="306a181d" href="#306a181d">JpgSaver</a>

```cpp
 JpgSaver () 
```



### _function_ <a id="bf8e4f72" href="#bf8e4f72">JpgSaver</a>

```cpp
 JpgSaver (
    const JpgSaver & other
) = delete 
```



### _function_ <a id="1742c42a" href="#1742c42a">JpgSaver</a>

```cpp
 JpgSaver (
    JpgSaver && other
) 
```



### _function_ <a id="8e3c83d9" href="#8e3c83d9">swap</a>

```cpp
void swap (
    JpgSaver & other
) 
```



### _function_ <a id="7e6a34ee" href="#7e6a34ee">operator=</a>

```cpp
JpgSaver & operator= (
    const JpgSaver & other
) = delete 
```



### _function_ <a id="4d464c57" href="#4d464c57">operator=</a>

```cpp
JpgSaver & operator= (
    JpgSaver && other
) 
```



### _function_ <a id="49340bb6" href="#49340bb6">~JpgSaver</a>

```cpp
virtual  ~JpgSaver () 
```



### _function_ <a id="3ce59316" href="#3ce59316">open</a>

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

### _function_ <a id="5aa57ca5" href="#5aa57ca5">writeRow</a>

```cpp
virtual size_t writeRow (
    const void * src
) 
```



**Overrides:** [writeRow](/doxygen/ffw_ImageWriter.md#fb673e42) from class [ImageWriter](/doxygen/ffw_ImageWriter.md)

### _function_ <a id="64344997" href="#64344997">writeFooter</a>

```cpp
virtual bool writeFooter () 
```



**Overrides:** [writeFooter](/doxygen/ffw_ImageWriter.md#5377830a) from class [ImageWriter](/doxygen/ffw_ImageWriter.md)

### _function_ <a id="57e5f893" href="#57e5f893">close</a>

```cpp
virtual void close () 
```



**Overrides:** [close](/doxygen/ffw_ImageWriter.md#03dcc1a2) from class [ImageWriter](/doxygen/ffw_ImageWriter.md)



