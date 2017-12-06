PngLoader
===================================


**Inherits from:** [ffw::ImageReader](ffw_ImageReader.html)

The documentation for this class was generated from: `include/ffw/media/pngloader.h`



## Public Functions

| Type | Name |
| -------: | :------- |
|   | [PngLoader](#f5970b9a) ()  |
|   | [PngLoader](#e7e2d979) (const [PngLoader](ffw_PngLoader.html) & _other_) = delete  |
|   | [PngLoader](#c4abff21) ([PngLoader](ffw_PngLoader.html) && _other_)  |
|  void | [swap](#b7dbd795) ([PngLoader](ffw_PngLoader.html) & _other_)  |
|  [PngLoader](ffw_PngLoader.html) & | [operator=](#19704a43) (const [PngLoader](ffw_PngLoader.html) & _other_) = delete  |
|  [PngLoader](ffw_PngLoader.html) & | [operator=](#a6a60e5d) ([PngLoader](ffw_PngLoader.html) && _other_)  |
|  virtual  | [~PngLoader](#84e647a8) ()  |
|  virtual bool | [open](#130d6b5b) (const std::string & _path_)  |
|  virtual size_t | [readRow](#733c9634) (void * _dest_)  |
|  virtual void | [close](#fe4bce58) ()  |


## Public Functions Documentation

### _function_ <a id="f5970b9a" href="#f5970b9a">PngLoader</a>

```cpp
 PngLoader () 
```



### _function_ <a id="e7e2d979" href="#e7e2d979">PngLoader</a>

```cpp
 PngLoader (
    const PngLoader & other
) = delete 
```



### _function_ <a id="c4abff21" href="#c4abff21">PngLoader</a>

```cpp
 PngLoader (
    PngLoader && other
) 
```



### _function_ <a id="b7dbd795" href="#b7dbd795">swap</a>

```cpp
void swap (
    PngLoader & other
) 
```



### _function_ <a id="19704a43" href="#19704a43">operator=</a>

```cpp
PngLoader & operator= (
    const PngLoader & other
) = delete 
```



### _function_ <a id="a6a60e5d" href="#a6a60e5d">operator=</a>

```cpp
PngLoader & operator= (
    PngLoader && other
) 
```



### _function_ <a id="84e647a8" href="#84e647a8">~PngLoader</a>

```cpp
virtual  ~PngLoader () 
```



### _function_ <a id="130d6b5b" href="#130d6b5b">open</a>

```cpp
virtual bool open (
    const std::string & path
) 
```



**Overrides:** [open](/doxygen/ffw_ImageReader.md#25e290f7) from class [ImageReader](/doxygen/ffw_ImageReader.md)

### _function_ <a id="733c9634" href="#733c9634">readRow</a>

```cpp
virtual size_t readRow (
    void * dest
) 
```



**Overrides:** [readRow](/doxygen/ffw_ImageReader.md#2b7cda9d) from class [ImageReader](/doxygen/ffw_ImageReader.md)

### _function_ <a id="fe4bce58" href="#fe4bce58">close</a>

```cpp
virtual void close () 
```



**Overrides:** [close](/doxygen/ffw_ImageReader.md#f00a5543) from class [ImageReader](/doxygen/ffw_ImageReader.md)



