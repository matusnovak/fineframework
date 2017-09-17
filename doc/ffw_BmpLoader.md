BmpLoader
===================================


**Inherits from:** [ffw::ImageReader](ffw_ImageReader.html)

The documentation for this class was generated from: `include/ffw/media/bmploader.h`



## Public Functions

| Type | Name |
| -------: | :------- |
|   | [BmpLoader](#c5c545fc) ()  |
|   | [BmpLoader](#7533bc01) (const [BmpLoader](ffw_BmpLoader.html) & _other_) = delete  |
|   | [BmpLoader](#42fdbb67) ([BmpLoader](ffw_BmpLoader.html) && _other_)  |
|  void | [swap](#68edf10b) ([BmpLoader](ffw_BmpLoader.html) & _other_)  |
|  [BmpLoader](ffw_BmpLoader.html) & | [operator=](#319149e9) (const [BmpLoader](ffw_BmpLoader.html) & _other_) = delete  |
|  [BmpLoader](ffw_BmpLoader.html) & | [operator=](#69186e13) ([BmpLoader](ffw_BmpLoader.html) && _other_)  |
|  virtual  | [~BmpLoader](#aaed4bf7) ()  |
|  virtual bool | [open](#c6782eec) (const std::string & _path_)  |
|  virtual size_t | [readRow](#f64860ea) (void * _dest_)  |
|  virtual void | [close](#977d2baa) ()  |


## Public Functions Documentation

### <span style="opacity:0.5;">function</span> <a id="c5c545fc" href="#c5c545fc">BmpLoader</a>

```cpp
 BmpLoader () 
```



### <span style="opacity:0.5;">function</span> <a id="7533bc01" href="#7533bc01">BmpLoader</a>

```cpp
 BmpLoader (
    const BmpLoader & other
) = delete 
```



### <span style="opacity:0.5;">function</span> <a id="42fdbb67" href="#42fdbb67">BmpLoader</a>

```cpp
 BmpLoader (
    BmpLoader && other
) 
```



### <span style="opacity:0.5;">function</span> <a id="68edf10b" href="#68edf10b">swap</a>

```cpp
void swap (
    BmpLoader & other
) 
```



### <span style="opacity:0.5;">function</span> <a id="319149e9" href="#319149e9">operator=</a>

```cpp
BmpLoader & operator= (
    const BmpLoader & other
) = delete 
```



### <span style="opacity:0.5;">function</span> <a id="69186e13" href="#69186e13">operator=</a>

```cpp
BmpLoader & operator= (
    BmpLoader && other
) 
```



### <span style="opacity:0.5;">function</span> <a id="aaed4bf7" href="#aaed4bf7">~BmpLoader</a>

```cpp
virtual  ~BmpLoader () 
```



### <span style="opacity:0.5;">function</span> <a id="c6782eec" href="#c6782eec">open</a>

```cpp
virtual bool open (
    const std::string & path
) 
```



**Overrides:** [open](/doc/ffw_ImageReader.md#25e290f7)

### <span style="opacity:0.5;">function</span> <a id="f64860ea" href="#f64860ea">readRow</a>

```cpp
virtual size_t readRow (
    void * dest
) 
```



**Overrides:** [readRow](/doc/ffw_ImageReader.md#2b7cda9d)

### <span style="opacity:0.5;">function</span> <a id="977d2baa" href="#977d2baa">close</a>

```cpp
virtual void close () 
```



**Overrides:** [close](/doc/ffw_ImageReader.md#f00a5543)



