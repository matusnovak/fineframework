XmlWriter
===================================


The documentation for this class was generated from: `include/ffw/data/xmlwriter.h`

## Detailed description

doc/markdown/tutorial-xml.md 


## Classes

| Name |
|:-----|
| class [ffw::XmlWriter::FileStream](ffw_XmlWriter_FileStream.html) |
| class [ffw::XmlWriter::Stream](ffw_XmlWriter_Stream.html) |
| class [ffw::XmlWriter::StringStream](ffw_XmlWriter_StringStream.html) |


## Public Functions

| Type | Name |
| -------: | :------- |
|   | [XmlWriter](#31770d50) ([Stream](ffw_XmlWriter_Stream.html) * _stream_, const char * _indent_ = NULL, bool _escape_ = true)  |
|  virtual  | [~XmlWriter](#fddcce8d) ()  |
|  void | [addObject](#b5c0d5d6) (const char * _key_)  |
|  void | [stepOut](#6c5a5642) ()  |
|  void | [beginContent](#8c315d61) ()  |
|  void | [addInteger](#8573d4a1) (int _val_, const char * _key_)  |
|  void | [addString](#3909d12f) (const char * _val_, const char * _key_)  |
|  void | [addBoolean](#a4da7a07) (bool _val_, const char * _key_)  |
|  void | [addFloat](#2f45d5a9) (float _val_, const char * _key_)  |
|  void | [addNull](#ce6896d7) (const char * _key_)  |


## Public Functions Documentation

### _function_ <a id="31770d50" href="#31770d50">XmlWriter</a>

```cpp
 XmlWriter (
    Stream * stream,
    const char * indent = NULL,
    bool escape = true
) 
```



### _function_ <a id="fddcce8d" href="#fddcce8d">~XmlWriter</a>

```cpp
virtual  ~XmlWriter () 
```



### _function_ <a id="b5c0d5d6" href="#b5c0d5d6">addObject</a>

```cpp
void addObject (
    const char * key
) 
```



### _function_ <a id="6c5a5642" href="#6c5a5642">stepOut</a>

```cpp
void stepOut () 
```



### _function_ <a id="8c315d61" href="#8c315d61">beginContent</a>

```cpp
void beginContent () 
```



### _function_ <a id="8573d4a1" href="#8573d4a1">addInteger</a>

```cpp
void addInteger (
    int val,
    const char * key
) 
```



### _function_ <a id="3909d12f" href="#3909d12f">addString</a>

```cpp
void addString (
    const char * val,
    const char * key
) 
```



### _function_ <a id="a4da7a07" href="#a4da7a07">addBoolean</a>

```cpp
void addBoolean (
    bool val,
    const char * key
) 
```



### _function_ <a id="2f45d5a9" href="#2f45d5a9">addFloat</a>

```cpp
void addFloat (
    float val,
    const char * key
) 
```



### _function_ <a id="ce6896d7" href="#ce6896d7">addNull</a>

```cpp
void addNull (
    const char * key
) 
```





