FileStream
===================================


**Inherits from:** [ffw::XmlWriter::Stream](ffw_XmlWriter_Stream.html)

The documentation for this class was generated from: `include/ffw/data/xmlwriter.h`



## Public Functions

| Type | Name |
| -------: | :------- |
|   | [FileStream](#add93bb4) (const std::string & _path_, std::ios_base::openmode _mode_)  |
|   | [~FileStream](#ba0a3d22) ()  |
|  bool | [isOpen](#a1e5f7a4) () const  |
|  void | [close](#98cfa57d) ()  |
|  virtual bool | [write](#a7c4c126) (const char * _in_, size_t _len_)  |


## Public Functions Documentation

### <span style="opacity:0.5;">function</span> <a id="add93bb4" href="#add93bb4">FileStream</a>

```cpp
 FileStream (
    const std::string & path,
    std::ios_base::openmode mode
) 
```



### <span style="opacity:0.5;">function</span> <a id="ba0a3d22" href="#ba0a3d22">~FileStream</a>

```cpp
 ~FileStream () 
```



### <span style="opacity:0.5;">function</span> <a id="a1e5f7a4" href="#a1e5f7a4">isOpen</a>

```cpp
bool isOpen () const 
```



### <span style="opacity:0.5;">function</span> <a id="98cfa57d" href="#98cfa57d">close</a>

```cpp
void close () 
```



### <span style="opacity:0.5;">function</span> <a id="a7c4c126" href="#a7c4c126">write</a>

```cpp
virtual bool write (
    const char * in,
    size_t len
) 
```





