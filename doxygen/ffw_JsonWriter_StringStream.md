StringStream
===================================


**Inherits from:** [ffw::JsonWriter::Stream](ffw_JsonWriter_Stream.html)

The documentation for this class was generated from: `include/ffw/data/jsonwriter.h`



## Public Functions

| Type | Name |
| -------: | :------- |
|   | [StringStream](#6e84ea96) ()  |
|  virtual  | [~StringStream](#1e02e3fe) ()  |
|  virtual bool | [write](#9a160ff6) (const char * _in_, size_t _len_)  |
|  const std::string & | [get](#b0bf021d) () const  |


## Public Functions Documentation

### _function_ <a id="6e84ea96" href="#6e84ea96">StringStream</a>

```cpp
 StringStream () 
```



### _function_ <a id="1e02e3fe" href="#1e02e3fe">~StringStream</a>

```cpp
virtual  ~StringStream () 
```



### _function_ <a id="9a160ff6" href="#9a160ff6">write</a>

```cpp
virtual bool write (
    const char * in,
    size_t len
) 
```



**Overrides:** [write](/doxygen/ffw_JsonWriter_Stream.md#a7c9ef03) from class [Stream](/doxygen/ffw_JsonWriter_Stream.md)

### _function_ <a id="b0bf021d" href="#b0bf021d">get</a>

```cpp
const std::string & get () const 
```





