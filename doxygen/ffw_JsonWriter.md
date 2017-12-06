JsonWriter
===================================


The documentation for this class was generated from: `include/ffw/data/jsonwriter.h`

## Detailed description

doc/markdown/tutorial-json.md 


## Classes

| Name |
|:-----|
| class [ffw::JsonWriter::FileStream](ffw_JsonWriter_FileStream.html) |
| class [ffw::JsonWriter::Stream](ffw_JsonWriter_Stream.html) |
| class [ffw::JsonWriter::StringStream](ffw_JsonWriter_StringStream.html) |


## Public Functions

| Type | Name |
| -------: | :------- |
|   | [JsonWriter](#cb7704b5) ([Stream](ffw_JsonWriter_Stream.html) * _stream_, const char * _indent_ = NULL, bool _escape_ = true)  |
|  virtual  | [~JsonWriter](#221c7a05) ()  |
|  void | [addObject](#dc60cf54) (const char * _key_ = NULL)  |
|  void | [addArray](#f59ba1a8) (const char * _key_ = NULL)  |
|  void | [stepOut](#dec0e7cd) ()  |
|  void | [addInteger](#cc008063) (int _val_, const char * _key_ = NULL)  |
|  void | [addString](#51658e8e) (const char * _val_, const char * _key_ = NULL)  |
|  void | [addBoolean](#4128d216) (bool _val_, const char * _key_ = NULL)  |
|  void | [addFloat](#fd7e7d16) (float _val_, const char * _key_ = NULL)  |
|  void | [addNull](#f7657764) (const char * _key_ = NULL)  |


## Public Functions Documentation

### _function_ <a id="cb7704b5" href="#cb7704b5">JsonWriter</a>

```cpp
 JsonWriter (
    Stream * stream,
    const char * indent = NULL,
    bool escape = true
) 
```



### _function_ <a id="221c7a05" href="#221c7a05">~JsonWriter</a>

```cpp
virtual  ~JsonWriter () 
```



### _function_ <a id="dc60cf54" href="#dc60cf54">addObject</a>

```cpp
void addObject (
    const char * key = NULL
) 
```



### _function_ <a id="f59ba1a8" href="#f59ba1a8">addArray</a>

```cpp
void addArray (
    const char * key = NULL
) 
```



### _function_ <a id="dec0e7cd" href="#dec0e7cd">stepOut</a>

```cpp
void stepOut () 
```



### _function_ <a id="cc008063" href="#cc008063">addInteger</a>

```cpp
void addInteger (
    int val,
    const char * key = NULL
) 
```



### _function_ <a id="51658e8e" href="#51658e8e">addString</a>

```cpp
void addString (
    const char * val,
    const char * key = NULL
) 
```



### _function_ <a id="4128d216" href="#4128d216">addBoolean</a>

```cpp
void addBoolean (
    bool val,
    const char * key = NULL
) 
```



### _function_ <a id="fd7e7d16" href="#fd7e7d16">addFloat</a>

```cpp
void addFloat (
    float val,
    const char * key = NULL
) 
```



### _function_ <a id="f7657764" href="#f7657764">addNull</a>

```cpp
void addNull (
    const char * key = NULL
) 
```





