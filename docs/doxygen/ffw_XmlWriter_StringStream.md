StringStream
===================================


**Inherits from:** [ffw::XmlWriter::Stream](ffw_XmlWriter_Stream.html)

The documentation for this class was generated from: `include/ffw/data/xmlwriter.h`



## Public Functions

| Type | Name |
| -------: | :------- |
|   | [StringStream](#0181aadd) ()  |
|  virtual  | [~StringStream](#9b4851e2) ()  |
|  virtual bool | [write](#53a56fef) (const char * _in_, size_t _len_)  |
|  const std::string & | [get](#a594c552) () const  |


## Public Functions Documentation

### _function_ <a id="0181aadd" href="#0181aadd">StringStream</a>

```cpp
 StringStream () 
```



### _function_ <a id="9b4851e2" href="#9b4851e2">~StringStream</a>

```cpp
virtual  ~StringStream () 
```



### _function_ <a id="53a56fef" href="#53a56fef">write</a>

```cpp
virtual bool write (
    const char * in,
    size_t len
) 
```



**Overrides:** [write](/doxygen/ffw_XmlWriter_Stream.md#26345587) from class [Stream](/doxygen/ffw_XmlWriter_Stream.md)

### _function_ <a id="a594c552" href="#a594c552">get</a>

```cpp
const std::string & get () const 
```





