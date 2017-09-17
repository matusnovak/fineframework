TifLoader
===================================


**Inherits from:** [ffw::ImageReader](ffw_ImageReader.html)

The documentation for this class was generated from: `include/ffw/media/tifloader.h`



## Public Functions

| Type | Name |
| -------: | :------- |
|   | [TifLoader](#76534939) ()  |
|   | [TifLoader](#d8e6aab2) (const [TifLoader](ffw_TifLoader.html) & _other_) = delete  |
|   | [TifLoader](#e7fc4b7c) ([TifLoader](ffw_TifLoader.html) && _other_)  |
|  void | [swap](#bfaf9c52) ([TifLoader](ffw_TifLoader.html) & _other_)  |
|  [TifLoader](ffw_TifLoader.html) & | [operator=](#2e24007e) (const [TifLoader](ffw_TifLoader.html) & _other_) = delete  |
|  [TifLoader](ffw_TifLoader.html) & | [operator=](#cf6bac2f) ([TifLoader](ffw_TifLoader.html) && _other_)  |
|  virtual  | [~TifLoader](#129d8322) ()  |
|  virtual bool | [open](#5ea17331) (const std::string & _path_)  |
|  virtual size_t | [readRow](#077e9616) (void * _dest_)  |
|  virtual void | [close](#63db2480) ()  |


## Public Functions Documentation

### <span style="opacity:0.5;">function</span> <a id="76534939" href="#76534939">TifLoader</a>

```cpp
 TifLoader () 
```



### <span style="opacity:0.5;">function</span> <a id="d8e6aab2" href="#d8e6aab2">TifLoader</a>

```cpp
 TifLoader (
    const TifLoader & other
) = delete 
```



### <span style="opacity:0.5;">function</span> <a id="e7fc4b7c" href="#e7fc4b7c">TifLoader</a>

```cpp
 TifLoader (
    TifLoader && other
) 
```



### <span style="opacity:0.5;">function</span> <a id="bfaf9c52" href="#bfaf9c52">swap</a>

```cpp
void swap (
    TifLoader & other
) 
```



### <span style="opacity:0.5;">function</span> <a id="2e24007e" href="#2e24007e">operator=</a>

```cpp
TifLoader & operator= (
    const TifLoader & other
) = delete 
```



### <span style="opacity:0.5;">function</span> <a id="cf6bac2f" href="#cf6bac2f">operator=</a>

```cpp
TifLoader & operator= (
    TifLoader && other
) 
```



### <span style="opacity:0.5;">function</span> <a id="129d8322" href="#129d8322">~TifLoader</a>

```cpp
virtual  ~TifLoader () 
```



### <span style="opacity:0.5;">function</span> <a id="5ea17331" href="#5ea17331">open</a>

```cpp
virtual bool open (
    const std::string & path
) 
```



**Overrides:** [open](/doc/ffw_ImageReader.md#25e290f7) from class [ImageReader](/doc/ffw_ImageReader.md)

### <span style="opacity:0.5;">function</span> <a id="077e9616" href="#077e9616">readRow</a>

```cpp
virtual size_t readRow (
    void * dest
) 
```



**Overrides:** [readRow](/doc/ffw_ImageReader.md#2b7cda9d) from class [ImageReader](/doc/ffw_ImageReader.md)

### <span style="opacity:0.5;">function</span> <a id="63db2480" href="#63db2480">close</a>

```cpp
virtual void close () 
```



**Overrides:** [close](/doc/ffw_ImageReader.md#f00a5543) from class [ImageReader](/doc/ffw_ImageReader.md)



