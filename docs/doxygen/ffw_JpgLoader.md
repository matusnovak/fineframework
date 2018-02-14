JpgLoader
===================================


**Inherits from:** [ffw::ImageReader](ffw_ImageReader.html)

The documentation for this class was generated from: `include/ffw/media/jpgloader.h`



## Public Functions

| Type | Name |
| -------: | :------- |
|   | [JpgLoader](#c265d11f) ()  |
|   | [JpgLoader](#ce5a7726) (const [JpgLoader](ffw_JpgLoader.html) & _other_) = delete  |
|   | [JpgLoader](#037d2c93) ([JpgLoader](ffw_JpgLoader.html) && _other_)  |
|  void | [swap](#7443df93) ([JpgLoader](ffw_JpgLoader.html) & _other_)  |
|  [JpgLoader](ffw_JpgLoader.html) & | [operator=](#e6cad84c) (const [JpgLoader](ffw_JpgLoader.html) & _other_) = delete  |
|  [JpgLoader](ffw_JpgLoader.html) & | [operator=](#34d6fc05) ([JpgLoader](ffw_JpgLoader.html) && _other_)  |
|  virtual  | [~JpgLoader](#4f9771ce) ()  |
|  virtual bool | [open](#667688b0) (const std::string & _path_)  |
|  virtual size_t | [readRow](#15676853) (void * _dest_)  |
|  virtual void | [close](#fe952601) ()  |


## Public Functions Documentation

### _function_ <a id="c265d11f" href="#c265d11f">JpgLoader</a>

```cpp
 JpgLoader () 
```



### _function_ <a id="ce5a7726" href="#ce5a7726">JpgLoader</a>

```cpp
 JpgLoader (
    const JpgLoader & other
) = delete 
```



### _function_ <a id="037d2c93" href="#037d2c93">JpgLoader</a>

```cpp
 JpgLoader (
    JpgLoader && other
) 
```



### _function_ <a id="7443df93" href="#7443df93">swap</a>

```cpp
void swap (
    JpgLoader & other
) 
```



### _function_ <a id="e6cad84c" href="#e6cad84c">operator=</a>

```cpp
JpgLoader & operator= (
    const JpgLoader & other
) = delete 
```



### _function_ <a id="34d6fc05" href="#34d6fc05">operator=</a>

```cpp
JpgLoader & operator= (
    JpgLoader && other
) 
```



### _function_ <a id="4f9771ce" href="#4f9771ce">~JpgLoader</a>

```cpp
virtual  ~JpgLoader () 
```



### _function_ <a id="667688b0" href="#667688b0">open</a>

```cpp
virtual bool open (
    const std::string & path
) 
```



**Overrides:** [open](/doxygen/ffw_ImageReader.md#25e290f7) from class [ImageReader](/doxygen/ffw_ImageReader.md)

### _function_ <a id="15676853" href="#15676853">readRow</a>

```cpp
virtual size_t readRow (
    void * dest
) 
```



**Overrides:** [readRow](/doxygen/ffw_ImageReader.md#2b7cda9d) from class [ImageReader](/doxygen/ffw_ImageReader.md)

### _function_ <a id="fe952601" href="#fe952601">close</a>

```cpp
virtual void close () 
```



**Overrides:** [close](/doxygen/ffw_ImageReader.md#f00a5543) from class [ImageReader](/doxygen/ffw_ImageReader.md)



