PbmLoader
===================================


**Inherits from:** [ffw::ImageReader](ffw_ImageReader.html)

The documentation for this class was generated from: `include/ffw/media/pbmloader.h`



## Public Functions

| Type | Name |
| -------: | :------- |
|   | [PbmLoader](#dc1a8d75) ()  |
|   | [PbmLoader](#b513ac90) (const [PbmLoader](ffw_PbmLoader.html) & _other_) = delete  |
|   | [PbmLoader](#e3291507) ([PbmLoader](ffw_PbmLoader.html) && _other_)  |
|  void | [swap](#8a50c831) ([PbmLoader](ffw_PbmLoader.html) & _other_)  |
|  [PbmLoader](ffw_PbmLoader.html) & | [operator=](#f8052e9a) (const [PbmLoader](ffw_PbmLoader.html) & _other_) = delete  |
|  [PbmLoader](ffw_PbmLoader.html) & | [operator=](#87e0b120) ([PbmLoader](ffw_PbmLoader.html) && _other_)  |
|  virtual  | [~PbmLoader](#50cac0df) ()  |
|  virtual bool | [open](#bcd31dd1) (const std::string & _path_)  |
|  virtual size_t | [readRow](#8713c259) (void * _dest_)  |
|  virtual void | [close](#f5d8f733) ()  |


## Public Functions Documentation

### <span style="opacity:0.5;">function</span> <a id="dc1a8d75" href="#dc1a8d75">PbmLoader</a>

```cpp
 PbmLoader () 
```



### <span style="opacity:0.5;">function</span> <a id="b513ac90" href="#b513ac90">PbmLoader</a>

```cpp
 PbmLoader (
    const PbmLoader & other
) = delete 
```



### <span style="opacity:0.5;">function</span> <a id="e3291507" href="#e3291507">PbmLoader</a>

```cpp
 PbmLoader (
    PbmLoader && other
) 
```



### <span style="opacity:0.5;">function</span> <a id="8a50c831" href="#8a50c831">swap</a>

```cpp
void swap (
    PbmLoader & other
) 
```



### <span style="opacity:0.5;">function</span> <a id="f8052e9a" href="#f8052e9a">operator=</a>

```cpp
PbmLoader & operator= (
    const PbmLoader & other
) = delete 
```



### <span style="opacity:0.5;">function</span> <a id="87e0b120" href="#87e0b120">operator=</a>

```cpp
PbmLoader & operator= (
    PbmLoader && other
) 
```



### <span style="opacity:0.5;">function</span> <a id="50cac0df" href="#50cac0df">~PbmLoader</a>

```cpp
virtual  ~PbmLoader () 
```



### <span style="opacity:0.5;">function</span> <a id="bcd31dd1" href="#bcd31dd1">open</a>

```cpp
virtual bool open (
    const std::string & path
) 
```



**Overrides:** [open](/doc/ffw_ImageReader.md#25e290f7) from class [ImageReader](/doc/ffw_ImageReader.md)

### <span style="opacity:0.5;">function</span> <a id="8713c259" href="#8713c259">readRow</a>

```cpp
virtual size_t readRow (
    void * dest
) 
```



**Overrides:** [readRow](/doc/ffw_ImageReader.md#2b7cda9d) from class [ImageReader](/doc/ffw_ImageReader.md)

### <span style="opacity:0.5;">function</span> <a id="f5d8f733" href="#f5d8f733">close</a>

```cpp
virtual void close () 
```



**Overrides:** [close](/doc/ffw_ImageReader.md#f00a5543) from class [ImageReader](/doc/ffw_ImageReader.md)



