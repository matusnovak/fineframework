TgaLoader
===================================


**Inherits from:** [ffw::ImageReader](ffw_ImageReader.html)

The documentation for this class was generated from: `include/ffw/media/tgaloader.h`



## Public Functions

| Type | Name |
| -------: | :------- |
|   | [TgaLoader](#6409f265) ()  |
|   | [TgaLoader](#2bd3c60b) (const [TgaLoader](ffw_TgaLoader.html) & _other_) = delete  |
|   | [TgaLoader](#cfe2f470) ([TgaLoader](ffw_TgaLoader.html) && _other_)  |
|  void | [swap](#6a2fc0a1) ([TgaLoader](ffw_TgaLoader.html) & _other_)  |
|  [TgaLoader](ffw_TgaLoader.html) & | [operator=](#4c0e5bc6) (const [TgaLoader](ffw_TgaLoader.html) & _other_) = delete  |
|  [TgaLoader](ffw_TgaLoader.html) & | [operator=](#e45c239c) ([TgaLoader](ffw_TgaLoader.html) && _other_)  |
|  virtual  | [~TgaLoader](#6b651ea9) ()  |
|  virtual bool | [open](#b886ce95) (const std::string & _path_)  |
|  virtual size_t | [readRow](#782d795b) (void * _dest_)  |
|  virtual void | [close](#4953da27) ()  |


## Public Functions Documentation

### <span style="opacity:0.5;">function</span> <a id="6409f265" href="#6409f265">TgaLoader</a>

```cpp
 TgaLoader () 
```



### <span style="opacity:0.5;">function</span> <a id="2bd3c60b" href="#2bd3c60b">TgaLoader</a>

```cpp
 TgaLoader (
    const TgaLoader & other
) = delete 
```



### <span style="opacity:0.5;">function</span> <a id="cfe2f470" href="#cfe2f470">TgaLoader</a>

```cpp
 TgaLoader (
    TgaLoader && other
) 
```



### <span style="opacity:0.5;">function</span> <a id="6a2fc0a1" href="#6a2fc0a1">swap</a>

```cpp
void swap (
    TgaLoader & other
) 
```



### <span style="opacity:0.5;">function</span> <a id="4c0e5bc6" href="#4c0e5bc6">operator=</a>

```cpp
TgaLoader & operator= (
    const TgaLoader & other
) = delete 
```



### <span style="opacity:0.5;">function</span> <a id="e45c239c" href="#e45c239c">operator=</a>

```cpp
TgaLoader & operator= (
    TgaLoader && other
) 
```



### <span style="opacity:0.5;">function</span> <a id="6b651ea9" href="#6b651ea9">~TgaLoader</a>

```cpp
virtual  ~TgaLoader () 
```



### <span style="opacity:0.5;">function</span> <a id="b886ce95" href="#b886ce95">open</a>

```cpp
virtual bool open (
    const std::string & path
) 
```



### <span style="opacity:0.5;">function</span> <a id="782d795b" href="#782d795b">readRow</a>

```cpp
virtual size_t readRow (
    void * dest
) 
```



### <span style="opacity:0.5;">function</span> <a id="4953da27" href="#4953da27">close</a>

```cpp
virtual void close () 
```





