DdsLoader
===================================


**Inherits from:** [ffw::ImageReader](ffw_ImageReader.html)

The documentation for this class was generated from: `include/ffw/media/ddsloader.h`



## Public Functions

| Type | Name |
| -------: | :------- |
|   | [DdsLoader](#84b2bcfd) ()  |
|   | [DdsLoader](#5fcd6a5c) (const [DdsLoader](ffw_DdsLoader.html) & _other_) = delete  |
|   | [DdsLoader](#b9e5bf3d) ([DdsLoader](ffw_DdsLoader.html) && _other_)  |
|  void | [swap](#964f87c9) ([DdsLoader](ffw_DdsLoader.html) & _other_)  |
|  [DdsLoader](ffw_DdsLoader.html) & | [operator=](#33d48a9d) (const [DdsLoader](ffw_DdsLoader.html) & _other_) = delete  |
|  [DdsLoader](ffw_DdsLoader.html) & | [operator=](#f3529f6d) ([DdsLoader](ffw_DdsLoader.html) && _other_)  |
|  virtual  | [~DdsLoader](#b4a33cc5) ()  |
|  virtual bool | [open](#3dfc9613) (const std::string & _path_)  |
|  virtual size_t | [readRow](#c0b558f6) (void * _dest_)  |
|  virtual bool | [getMipMap](#38609e89) (int _level_)  |
|  bool | [getCubemap](#91d8e96c) (int _side_)  |
|  virtual void | [close](#a1a60864) ()  |
|  bool | [isCubemap](#240f1337) () const  |
|  int | [getCubemapOffset](#d3063c7c) () const  |


## Public Functions Documentation

### _function_ <a id="84b2bcfd" href="#84b2bcfd">DdsLoader</a>

```cpp
 DdsLoader () 
```



### _function_ <a id="5fcd6a5c" href="#5fcd6a5c">DdsLoader</a>

```cpp
 DdsLoader (
    const DdsLoader & other
) = delete 
```



### _function_ <a id="b9e5bf3d" href="#b9e5bf3d">DdsLoader</a>

```cpp
 DdsLoader (
    DdsLoader && other
) 
```



### _function_ <a id="964f87c9" href="#964f87c9">swap</a>

```cpp
void swap (
    DdsLoader & other
) 
```



### _function_ <a id="33d48a9d" href="#33d48a9d">operator=</a>

```cpp
DdsLoader & operator= (
    const DdsLoader & other
) = delete 
```



### _function_ <a id="f3529f6d" href="#f3529f6d">operator=</a>

```cpp
DdsLoader & operator= (
    DdsLoader && other
) 
```



### _function_ <a id="b4a33cc5" href="#b4a33cc5">~DdsLoader</a>

```cpp
virtual  ~DdsLoader () 
```



### _function_ <a id="3dfc9613" href="#3dfc9613">open</a>

```cpp
virtual bool open (
    const std::string & path
) 
```



**Overrides:** [open](/doxygen/ffw_ImageReader.md#25e290f7) from class [ImageReader](/doxygen/ffw_ImageReader.md)

### _function_ <a id="c0b558f6" href="#c0b558f6">readRow</a>

```cpp
virtual size_t readRow (
    void * dest
) 
```



**Overrides:** [readRow](/doxygen/ffw_ImageReader.md#2b7cda9d) from class [ImageReader](/doxygen/ffw_ImageReader.md)

### _function_ <a id="38609e89" href="#38609e89">getMipMap</a>

```cpp
virtual bool getMipMap (
    int level
) 
```



**Overrides:** [getMipMap](/doxygen/ffw_ImageReader.md#3399339e) from class [ImageReader](/doxygen/ffw_ImageReader.md)

### _function_ <a id="91d8e96c" href="#91d8e96c">getCubemap</a>

```cpp
bool getCubemap (
    int side
) 
```



### _function_ <a id="a1a60864" href="#a1a60864">close</a>

```cpp
virtual void close () 
```



**Overrides:** [close](/doxygen/ffw_ImageReader.md#f00a5543) from class [ImageReader](/doxygen/ffw_ImageReader.md)

### _function_ <a id="240f1337" href="#240f1337">isCubemap</a>

```cpp
inline bool isCubemap () const 
```



### _function_ <a id="d3063c7c" href="#d3063c7c">getCubemapOffset</a>

```cpp
inline int getCubemapOffset () const 
```





