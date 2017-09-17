PbmSaver
===================================


**Inherits from:** [ffw::ImageWriter](ffw_ImageWriter.html)

The documentation for this class was generated from: `include/ffw/media/pbmsaver.h`



## Public Functions

| Type | Name |
| -------: | :------- |
|   | [PbmSaver](#c33f8e92) ()  |
|   | [PbmSaver](#d2f448e3) (const [PbmSaver](ffw_PbmSaver.html) & _other_) = delete  |
|   | [PbmSaver](#7c3d8925) ([PbmSaver](ffw_PbmSaver.html) && _other_)  |
|  void | [swap](#7ab1892c) ([PbmSaver](ffw_PbmSaver.html) & _other_)  |
|  [PbmSaver](ffw_PbmSaver.html) & | [operator=](#0cda060d) (const [PbmSaver](ffw_PbmSaver.html) & _other_) = delete  |
|  [PbmSaver](ffw_PbmSaver.html) & | [operator=](#26e21813) ([PbmSaver](ffw_PbmSaver.html) && _other_)  |
|  virtual  | [~PbmSaver](#a5d31021) ()  |
|  virtual bool | [open](#b4f34799) (const std::string & _path_, int _width_, int _height_, [ffw::ImageType](ffw.html#fa711f90) _type_, int _quality_ = 100)  |
|  virtual size_t | [writeRow](#6e4d1fe7) (const void * _src_)  |
|  virtual bool | [writeFooter](#17da0c00) ()  |
|  virtual void | [close](#de921dfa) ()  |


## Public Functions Documentation

### <span style="opacity:0.5;">function</span> <a id="c33f8e92" href="#c33f8e92">PbmSaver</a>

```cpp
 PbmSaver () 
```



### <span style="opacity:0.5;">function</span> <a id="d2f448e3" href="#d2f448e3">PbmSaver</a>

```cpp
 PbmSaver (
    const PbmSaver & other
) = delete 
```



### <span style="opacity:0.5;">function</span> <a id="7c3d8925" href="#7c3d8925">PbmSaver</a>

```cpp
 PbmSaver (
    PbmSaver && other
) 
```



### <span style="opacity:0.5;">function</span> <a id="7ab1892c" href="#7ab1892c">swap</a>

```cpp
void swap (
    PbmSaver & other
) 
```



### <span style="opacity:0.5;">function</span> <a id="0cda060d" href="#0cda060d">operator=</a>

```cpp
PbmSaver & operator= (
    const PbmSaver & other
) = delete 
```



### <span style="opacity:0.5;">function</span> <a id="26e21813" href="#26e21813">operator=</a>

```cpp
PbmSaver & operator= (
    PbmSaver && other
) 
```



### <span style="opacity:0.5;">function</span> <a id="a5d31021" href="#a5d31021">~PbmSaver</a>

```cpp
virtual  ~PbmSaver () 
```



### <span style="opacity:0.5;">function</span> <a id="b4f34799" href="#b4f34799">open</a>

```cpp
virtual bool open (
    const std::string & path,
    int width,
    int height,
    ffw::ImageType type,
    int quality = 100
) 
```



**Overrides:** [open](/doc/ffw_ImageWriter.md#c742773b) from class [ImageWriter](/doc/ffw_ImageWriter.md)

### <span style="opacity:0.5;">function</span> <a id="6e4d1fe7" href="#6e4d1fe7">writeRow</a>

```cpp
virtual size_t writeRow (
    const void * src
) 
```



**Overrides:** [writeRow](/doc/ffw_ImageWriter.md#fb673e42) from class [ImageWriter](/doc/ffw_ImageWriter.md)

### <span style="opacity:0.5;">function</span> <a id="17da0c00" href="#17da0c00">writeFooter</a>

```cpp
virtual bool writeFooter () 
```



**Overrides:** [writeFooter](/doc/ffw_ImageWriter.md#5377830a) from class [ImageWriter](/doc/ffw_ImageWriter.md)

### <span style="opacity:0.5;">function</span> <a id="de921dfa" href="#de921dfa">close</a>

```cpp
virtual void close () 
```



**Overrides:** [close](/doc/ffw_ImageWriter.md#03dcc1a2) from class [ImageWriter](/doc/ffw_ImageWriter.md)



