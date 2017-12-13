JsonReader
===================================


The documentation for this class was generated from: `include/ffw/data/jsonreader.h`

## Detailed description

doc/markdown/tutorial-json.md 


## Classes

| Name |
|:-----|
| struct [ffw::JsonReader::Cache](ffw_JsonReader_Cache.html) |
| class [ffw::JsonReader::Node](ffw_JsonReader_Node.html) |


## Public Types

| Type | Name |
| -------: | :------- |
| enum | [Type](#5dda529f) |


## Public Functions

| Type | Name |
| -------: | :------- |
|   | [JsonReader](#c63226d9) (const std::string & _input_)  |
|   | [JsonReader](#0c5e33c4) (const char * _input_)  |
|  virtual  | [~JsonReader](#d9b8c651) ()  |
|  bool | [getNext](#7d3400e2) ([Node](ffw_JsonReader_Node.html) * _value_, [Node](ffw_JsonReader_Node.html) * _key_)  |
|  bool | [stepInto](#33317b27) (const [Node](ffw_JsonReader_Node.html) * _node_)  |
|  bool | [stepOut](#4b50aeea) ()  |
|  [Type](ffw_JsonReader.html#5dda529f) | [getCurrentType](#2fed80c9) () const  |
|  const char * | [getCurrentPtr](#6eb9ed1a) () const  |
|  size_t | [getCurrentLen](#b458a9f9) () const  |


## Public Types Documentation

### _enum_ <a id="5dda529f" href="#5dda529f">Type</a>

```cpp
enum Type {
    OBJECT,
    ARRAY,
    INTEGER,
    FLOAT,
    BOOLEAN,
    STRING,
    NULLVAL,
    EMPTY,
    INVALID,
}
```





## Public Functions Documentation

### _function_ <a id="c63226d9" href="#c63226d9">JsonReader</a>

```cpp
 JsonReader (
    const std::string & input
) 
```



### _function_ <a id="0c5e33c4" href="#0c5e33c4">JsonReader</a>

```cpp
 JsonReader (
    const char * input
) 
```



### _function_ <a id="d9b8c651" href="#d9b8c651">~JsonReader</a>

```cpp
virtual  ~JsonReader () 
```



### _function_ <a id="7d3400e2" href="#7d3400e2">getNext</a>

```cpp
bool getNext (
    Node * value,
    Node * key
) 
```



### _function_ <a id="33317b27" href="#33317b27">stepInto</a>

```cpp
bool stepInto (
    const Node * node
) 
```



### _function_ <a id="4b50aeea" href="#4b50aeea">stepOut</a>

```cpp
bool stepOut () 
```



### _function_ <a id="2fed80c9" href="#2fed80c9">getCurrentType</a>

```cpp
inline Type getCurrentType () const 
```



### _function_ <a id="6eb9ed1a" href="#6eb9ed1a">getCurrentPtr</a>

```cpp
inline const char * getCurrentPtr () const 
```



### _function_ <a id="b458a9f9" href="#b458a9f9">getCurrentLen</a>

```cpp
inline size_t getCurrentLen () const 
```





