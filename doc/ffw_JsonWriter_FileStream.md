FileStream
===================================


**Inherits from:** [ffw::JsonWriter::Stream](ffw_JsonWriter_Stream.html)

The documentation for this class was generated from: `include/ffw/data/jsonwriter.h`



## Public Functions

| Type | Name |
| -------: | :------- |
|   | [FileStream](#d719bdb1) (const std::string & _path_, std::ios_base::openmode _mode_)  |
|  virtual  | [~FileStream](#d46490b9) ()  |
|  bool | [isOpen](#20e6c3f6) () const  |
|  void | [close](#c049826d) ()  |
|  virtual bool | [write](#03efac69) (const char * _in_, size_t _len_)  |


## Public Functions Documentation

### <span style="opacity:0.5;">function</span> <a id="d719bdb1" href="#d719bdb1">FileStream</a>

```cpp
 FileStream (
    const std::string & path,
    std::ios_base::openmode mode
) 
```



### <span style="opacity:0.5;">function</span> <a id="d46490b9" href="#d46490b9">~FileStream</a>

```cpp
virtual  ~FileStream () 
```



### <span style="opacity:0.5;">function</span> <a id="20e6c3f6" href="#20e6c3f6">isOpen</a>

```cpp
bool isOpen () const 
```



### <span style="opacity:0.5;">function</span> <a id="c049826d" href="#c049826d">close</a>

```cpp
void close () 
```



### <span style="opacity:0.5;">function</span> <a id="03efac69" href="#03efac69">write</a>

```cpp
virtual bool write (
    const char * in,
    size_t len
) 
```



**Overrides:** [write](/doc/ffw_JsonWriter_Stream.md#a7c9ef03) from class [Stream](/doc/ffw_JsonWriter_Stream.md)



