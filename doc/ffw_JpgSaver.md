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
|  virtual bool | [open](#40412ffb) (const std::string & _path_, int _width_, int _height_, [ffw::ImageType](ffw.html#fa711f90) _type_, int _quality_ = 100)  |
|  virtual size_t | [writeRow](#5aa57ca5) (const void * _src_)  |
|  virtual bool | [writeFooter](#64344997) ()  |
|  virtual void | [close](#57e5f893) ()  |


## Public Functions Documentation

### <span style="opacity:0.5;">function</span> <a id="306a181d" href="#306a181d">JpgSaver</a>

```cpp
 JpgSaver () 
```



### <span style="opacity:0.5;">function</span> <a id="bf8e4f72" href="#bf8e4f72">JpgSaver</a>

```cpp
 JpgSaver (
    const JpgSaver & other
) = delete 
```



### <span style="opacity:0.5;">function</span> <a id="1742c42a" href="#1742c42a">JpgSaver</a>

```cpp
 JpgSaver (
    JpgSaver && other
) 
```



### <span style="opacity:0.5;">function</span> <a id="8e3c83d9" href="#8e3c83d9">swap</a>

```cpp
void swap (
    JpgSaver & other
) 
```



### <span style="opacity:0.5;">function</span> <a id="7e6a34ee" href="#7e6a34ee">operator=</a>

```cpp
JpgSaver & operator= (
    const JpgSaver & other
) = delete 
```



### <span style="opacity:0.5;">function</span> <a id="4d464c57" href="#4d464c57">operator=</a>

```cpp
JpgSaver & operator= (
    JpgSaver && other
) 
```



### <span style="opacity:0.5;">function</span> <a id="49340bb6" href="#49340bb6">~JpgSaver</a>

```cpp
virtual  ~JpgSaver () 
```



### <span style="opacity:0.5;">function</span> <a id="40412ffb" href="#40412ffb">open</a>

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

### <span style="opacity:0.5;">function</span> <a id="5aa57ca5" href="#5aa57ca5">writeRow</a>

```cpp
virtual size_t writeRow (
    const void * src
) 
```



**Overrides:** [writeRow](/doc/ffw_ImageWriter.md#fb673e42)

### <span style="opacity:0.5;">function</span> <a id="64344997" href="#64344997">writeFooter</a>

```cpp
virtual bool writeFooter () 
```



**Overrides:** [writeFooter](/doc/ffw_ImageWriter.md#5377830a)

### <span style="opacity:0.5;">function</span> <a id="57e5f893" href="#57e5f893">close</a>

```cpp
virtual void close () 
```



**Overrides:** [close](/doc/ffw_ImageWriter.md#03dcc1a2)



