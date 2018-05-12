---
search: false
---

# class ffw::JsonReader

## Classes

|Type|Name|
|-----|-----|
|struct|[**Cache**](structffw_1_1_json_reader_1_1_cache.md)|
|class|[**Node**](classffw_1_1_json_reader_1_1_node.md)|


## Public Types

|Type|Name|
|-----|-----|
|enum|[**Type**](classffw_1_1_json_reader.md#1a84e248b0f735533d7692ce091095de16) { **OBJECT**, **ARRAY**, **INTEGER**, **FLOAT**, **BOOLEAN**, **STRING**, **NULLVAL**, **EMPTY**, **INVALID** } |


## Public Functions

|Type|Name|
|-----|-----|
||[**JsonReader**](classffw_1_1_json_reader.md#1a177985d15df5521e90902245589d8ad8) (const std::string & input) |
||[**JsonReader**](classffw_1_1_json_reader.md#1a30ad5c4e52a87f808a57b2f82640237c) (const char \* input) |
|virtual |[**~JsonReader**](classffw_1_1_json_reader.md#1a69329191d2d99ccdcd71c1400538cdbe) () |
|bool|[**getNext**](classffw_1_1_json_reader.md#1a2bbde3e507ec32663d018af381f5d0f9) (**[Node](classffw_1_1_json_reader_1_1_node.md)** \* value, **[Node](classffw_1_1_json_reader_1_1_node.md)** \* key) |
|bool|[**stepInto**](classffw_1_1_json_reader.md#1a429b8a65f5f2576e6969d28415193733) (const **[Node](classffw_1_1_json_reader_1_1_node.md)** \* node) |
|bool|[**stepOut**](classffw_1_1_json_reader.md#1a7cafea216d76035cdfc4f25e09dcba82) () |
|**[Type](classffw_1_1_json_reader.md#1a84e248b0f735533d7692ce091095de16)**|[**getCurrentType**](classffw_1_1_json_reader.md#1aebfe6b881673026c218ba7fe9e837333) () const |
|const char \*|[**getCurrentPtr**](classffw_1_1_json_reader.md#1aa81990c74d70220b46db250e6f76fdaa) () const |
|size\_t|[**getCurrentLen**](classffw_1_1_json_reader.md#1abd9875f2883af5e6d0151c951ee26eb4) () const |


## Detailed Description

doc/markdown/tutorial-json.md 
## Public Types Documentation

### enum <a id="1a84e248b0f735533d7692ce091095de16" href="#1a84e248b0f735533d7692ce091095de16">Type</a>

```cpp
enum ffw::JsonReader::Type {
    OBJECT,
    ARRAY,
    INTEGER,
    FLOAT,
    BOOLEAN,
    STRING,
    NULLVAL,
    EMPTY,
    INVALID,
};
```



## Public Functions Documentation

### function <a id="1a177985d15df5521e90902245589d8ad8" href="#1a177985d15df5521e90902245589d8ad8">JsonReader</a>

```cpp
ffw::JsonReader::JsonReader (
    const std::string & input
)
```



### function <a id="1a30ad5c4e52a87f808a57b2f82640237c" href="#1a30ad5c4e52a87f808a57b2f82640237c">JsonReader</a>

```cpp
ffw::JsonReader::JsonReader (
    const char * input
)
```



### function <a id="1a69329191d2d99ccdcd71c1400538cdbe" href="#1a69329191d2d99ccdcd71c1400538cdbe">~JsonReader</a>

```cpp
virtual ffw::JsonReader::~JsonReader ()
```



### function <a id="1a2bbde3e507ec32663d018af381f5d0f9" href="#1a2bbde3e507ec32663d018af381f5d0f9">getNext</a>

```cpp
bool ffw::JsonReader::getNext (
    Node * value,
    Node * key
)
```



### function <a id="1a429b8a65f5f2576e6969d28415193733" href="#1a429b8a65f5f2576e6969d28415193733">stepInto</a>

```cpp
bool ffw::JsonReader::stepInto (
    const Node * node
)
```



### function <a id="1a7cafea216d76035cdfc4f25e09dcba82" href="#1a7cafea216d76035cdfc4f25e09dcba82">stepOut</a>

```cpp
bool ffw::JsonReader::stepOut ()
```



### function <a id="1aebfe6b881673026c218ba7fe9e837333" href="#1aebfe6b881673026c218ba7fe9e837333">getCurrentType</a>

```cpp
Type ffw::JsonReader::getCurrentType () const
```



### function <a id="1aa81990c74d70220b46db250e6f76fdaa" href="#1aa81990c74d70220b46db250e6f76fdaa">getCurrentPtr</a>

```cpp
const char * ffw::JsonReader::getCurrentPtr () const
```



### function <a id="1abd9875f2883af5e6d0151c951ee26eb4" href="#1abd9875f2883af5e6d0151c951ee26eb4">getCurrentLen</a>

```cpp
size_t ffw::JsonReader::getCurrentLen () const
```





----------------------------------------
The documentation for this class was generated from the following file: `include/ffw/data/jsonreader.h`
