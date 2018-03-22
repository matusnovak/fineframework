---
search:
    keywords: ['ffw::XmlReader', 'Attribute', 'Cache', 'Node', 'Value', 'Type', 'XmlReader', 'XmlReader', '~XmlReader', 'getNext', 'stepInto', 'stepOut']
---

# class ffw::XmlReader

## Classes

|Type|Name|
|-----|-----|
|class|[**Attribute**](classffw_1_1_xml_reader_1_1_attribute.md)|
|struct|[**Cache**](structffw_1_1_xml_reader_1_1_cache.md)|
|class|[**Node**](classffw_1_1_xml_reader_1_1_node.md)|
|class|[**Value**](classffw_1_1_xml_reader_1_1_value.md)|


## Public Types

|Type|Name|
|-----|-----|
|enum|[**Type**](classffw_1_1_xml_reader.md#1a9e191e1a49c0fe3991a7816ddcad353e) { **OBJECT**, **INTEGER**, **FLOAT**, **BOOLEAN**, **STRING**, **NULLVAL**, **EMPTY**, **INVALID** } |


## Public Functions

|Type|Name|
|-----|-----|
||[**XmlReader**](classffw_1_1_xml_reader.md#1af369a088ae3de68d1373eb8cb6306b77) (const std::string & input) |
||[**XmlReader**](classffw_1_1_xml_reader.md#1a393070952ba8bfab5564eee69e18f423) (const char \* input) |
|virtual |[**~XmlReader**](classffw_1_1_xml_reader.md#1ac572ddb7bfe7483dfced2d6fe2144e38) () |
|bool|[**getNext**](classffw_1_1_xml_reader.md#1ad11f8e20e2c957af01af67ccd01b4464) (**[Node](classffw_1_1_xml_reader_1_1_node.md)** \* value) |
|bool|[**stepInto**](classffw_1_1_xml_reader.md#1aba39045325066fdfb77161eebc9cf03d) (const **[Node](classffw_1_1_xml_reader_1_1_node.md)** \* node) |
|bool|[**stepOut**](classffw_1_1_xml_reader.md#1adfceee0f3f9adb162de4c8197d636ae5) () |


## Detailed Description

doc/markdown/tutorial-xml.md 
## Public Types Documentation

### enum <a id="1a9e191e1a49c0fe3991a7816ddcad353e" href="#1a9e191e1a49c0fe3991a7816ddcad353e">Type</a>

```cpp
enum ffw::XmlReader::Type {
    OBJECT,
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

### function <a id="1af369a088ae3de68d1373eb8cb6306b77" href="#1af369a088ae3de68d1373eb8cb6306b77">XmlReader</a>

```cpp
ffw::XmlReader::XmlReader (
    const std::string & input
)
```



### function <a id="1a393070952ba8bfab5564eee69e18f423" href="#1a393070952ba8bfab5564eee69e18f423">XmlReader</a>

```cpp
ffw::XmlReader::XmlReader (
    const char * input
)
```



### function <a id="1ac572ddb7bfe7483dfced2d6fe2144e38" href="#1ac572ddb7bfe7483dfced2d6fe2144e38">~XmlReader</a>

```cpp
virtual ffw::XmlReader::~XmlReader ()
```



### function <a id="1ad11f8e20e2c957af01af67ccd01b4464" href="#1ad11f8e20e2c957af01af67ccd01b4464">getNext</a>

```cpp
bool ffw::XmlReader::getNext (
    Node * value
)
```



### function <a id="1aba39045325066fdfb77161eebc9cf03d" href="#1aba39045325066fdfb77161eebc9cf03d">stepInto</a>

```cpp
bool ffw::XmlReader::stepInto (
    const Node * node
)
```



### function <a id="1adfceee0f3f9adb162de4c8197d636ae5" href="#1adfceee0f3f9adb162de4c8197d636ae5">stepOut</a>

```cpp
bool ffw::XmlReader::stepOut ()
```





----------------------------------------
The documentation for this class was generated from the following file: `include/ffw/data/xmlreader.h`
