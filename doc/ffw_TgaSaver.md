TgaSaver
===================================


**Inherits from:** [ffw::ImageWriter](ffw_ImageWriter.html)

The documentation for this class was generated from: `include/ffw/media/tgasaver.h`



## Public Functions

| Type | Name |
| -------: | :------- |
|   | [TgaSaver](#45ccb6a3) ()  |
|   | [TgaSaver](#1ae65617) (const [TgaSaver](ffw_TgaSaver.html) & _other_) = delete  |
|   | [TgaSaver](#aa0d6361) ([TgaSaver](ffw_TgaSaver.html) && _other_)  |
|  void | [swap](#0a89451c) ([TgaSaver](ffw_TgaSaver.html) & _other_)  |
|  [TgaSaver](ffw_TgaSaver.html) & | [operator=](#d8702575) (const [TgaSaver](ffw_TgaSaver.html) & _other_) = delete  |
|  [TgaSaver](ffw_TgaSaver.html) & | [operator=](#3ca94aae) ([TgaSaver](ffw_TgaSaver.html) && _other_)  |
|  virtual  | [~TgaSaver](#a7e935b0) ()  |
|  virtual bool | [open](#46f7595a) (const std::string & _path_, int _width_, int _height_, [ffw::ImageType](ffw.html#fa711f90) _type_, int _quality_ = 100)  |
|  virtual size_t | [writeRow](#bd9fdd6c) (const void * _src_)  |
|  virtual bool | [writeFooter](#9df45474) ()  |
|  virtual void | [close](#a4424d30) ()  |


## Public Functions Documentation

### <span style="opacity:0.5;">function</span> <a id="45ccb6a3" href="#45ccb6a3">TgaSaver</a>

```cpp
 TgaSaver () 
```



### <span style="opacity:0.5;">function</span> <a id="1ae65617" href="#1ae65617">TgaSaver</a>

```cpp
 TgaSaver (
    const TgaSaver & other
) = delete 
```



### <span style="opacity:0.5;">function</span> <a id="aa0d6361" href="#aa0d6361">TgaSaver</a>

```cpp
 TgaSaver (
    TgaSaver && other
) 
```



### <span style="opacity:0.5;">function</span> <a id="0a89451c" href="#0a89451c">swap</a>

```cpp
void swap (
    TgaSaver & other
) 
```



### <span style="opacity:0.5;">function</span> <a id="d8702575" href="#d8702575">operator=</a>

```cpp
TgaSaver & operator= (
    const TgaSaver & other
) = delete 
```



### <span style="opacity:0.5;">function</span> <a id="3ca94aae" href="#3ca94aae">operator=</a>

```cpp
TgaSaver & operator= (
    TgaSaver && other
) 
```



### <span style="opacity:0.5;">function</span> <a id="a7e935b0" href="#a7e935b0">~TgaSaver</a>

```cpp
virtual  ~TgaSaver () 
```



### <span style="opacity:0.5;">function</span> <a id="46f7595a" href="#46f7595a">open</a>

```cpp
virtual bool open (
    const std::string & path,
    int width,
    int height,
    ffw::ImageType type,
    int quality = 100
) 
```



### <span style="opacity:0.5;">function</span> <a id="bd9fdd6c" href="#bd9fdd6c">writeRow</a>

```cpp
virtual size_t writeRow (
    const void * src
) 
```



### <span style="opacity:0.5;">function</span> <a id="9df45474" href="#9df45474">writeFooter</a>

```cpp
virtual bool writeFooter () 
```



### <span style="opacity:0.5;">function</span> <a id="a4424d30" href="#a4424d30">close</a>

```cpp
virtual void close () 
```





