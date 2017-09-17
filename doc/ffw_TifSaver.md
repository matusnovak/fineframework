TifSaver
===================================


**Inherits from:** [ffw::ImageWriter](ffw_ImageWriter.html)

The documentation for this class was generated from: `include/ffw/media/tifsaver.h`



## Public Functions

| Type | Name |
| -------: | :------- |
|   | [TifSaver](#df7ae89b) ()  |
|   | [TifSaver](#d7e13083) (const [TifSaver](ffw_TifSaver.html) & _other_) = delete  |
|   | [TifSaver](#354f7a37) ([TifSaver](ffw_TifSaver.html) && _other_)  |
|  void | [swap](#a0d83503) ([TifSaver](ffw_TifSaver.html) & _other_)  |
|  [TifSaver](ffw_TifSaver.html) & | [operator=](#8e95c802) (const [TifSaver](ffw_TifSaver.html) & _other_) = delete  |
|  [TifSaver](ffw_TifSaver.html) & | [operator=](#05c1b59b) ([TifSaver](ffw_TifSaver.html) && _other_)  |
|  virtual  | [~TifSaver](#5f7ef8c7) ()  |
|  virtual bool | [open](#20711313) (const std::string & _path_, int _width_, int _height_, [ffw::ImageType](ffw.html#fa711f90) _type_, int _quality_ = 100)  |
|  virtual size_t | [writeRow](#ec153889) (const void * _src_)  |
|  virtual bool | [writeFooter](#c3f9e535) ()  |
|  virtual void | [close](#26b2af61) ()  |


## Public Functions Documentation

### <span style="opacity:0.5;">function</span> <a id="df7ae89b" href="#df7ae89b">TifSaver</a>

```cpp
 TifSaver () 
```



### <span style="opacity:0.5;">function</span> <a id="d7e13083" href="#d7e13083">TifSaver</a>

```cpp
 TifSaver (
    const TifSaver & other
) = delete 
```



### <span style="opacity:0.5;">function</span> <a id="354f7a37" href="#354f7a37">TifSaver</a>

```cpp
 TifSaver (
    TifSaver && other
) 
```



### <span style="opacity:0.5;">function</span> <a id="a0d83503" href="#a0d83503">swap</a>

```cpp
void swap (
    TifSaver & other
) 
```



### <span style="opacity:0.5;">function</span> <a id="8e95c802" href="#8e95c802">operator=</a>

```cpp
TifSaver & operator= (
    const TifSaver & other
) = delete 
```



### <span style="opacity:0.5;">function</span> <a id="05c1b59b" href="#05c1b59b">operator=</a>

```cpp
TifSaver & operator= (
    TifSaver && other
) 
```



### <span style="opacity:0.5;">function</span> <a id="5f7ef8c7" href="#5f7ef8c7">~TifSaver</a>

```cpp
virtual  ~TifSaver () 
```



### <span style="opacity:0.5;">function</span> <a id="20711313" href="#20711313">open</a>

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

### <span style="opacity:0.5;">function</span> <a id="ec153889" href="#ec153889">writeRow</a>

```cpp
virtual size_t writeRow (
    const void * src
) 
```



**Overrides:** [writeRow](/doc/ffw_ImageWriter.md#fb673e42)

### <span style="opacity:0.5;">function</span> <a id="c3f9e535" href="#c3f9e535">writeFooter</a>

```cpp
virtual bool writeFooter () 
```



**Overrides:** [writeFooter](/doc/ffw_ImageWriter.md#5377830a)

### <span style="opacity:0.5;">function</span> <a id="26b2af61" href="#26b2af61">close</a>

```cpp
virtual void close () 
```



**Overrides:** [close](/doc/ffw_ImageWriter.md#03dcc1a2)



