---
search:
    keywords: ['ffw::XmlWriter', 'FileStream', 'Stream', 'StringStream', 'XmlWriter', '~XmlWriter', 'addObject', 'stepOut', 'beginContent', 'addInteger', 'addString', 'addBoolean', 'addFloat', 'addNull']
---

# class ffw::XmlWriter

## Classes

|Type|Name|
|-----|-----|
|class|[**FileStream**](classffw_1_1_xml_writer_1_1_file_stream.md)|
|class|[**Stream**](classffw_1_1_xml_writer_1_1_stream.md)|
|class|[**StringStream**](classffw_1_1_xml_writer_1_1_string_stream.md)|


## Public Functions

|Type|Name|
|-----|-----|
||[**XmlWriter**](classffw_1_1_xml_writer.md#1a82bdacbba330564503c2f213d20d6127) (**[Stream](classffw_1_1_xml_writer_1_1_stream.md)** \* stream, const char \* indent = NULL, bool escape = true) |
|virtual |[**~XmlWriter**](classffw_1_1_xml_writer.md#1ac435a10fd5fbd87d2eb0084cacc333e2) () |
|void|[**addObject**](classffw_1_1_xml_writer.md#1af885ff5f4c73d21825e216788c842f7d) (const char \* key) |
|void|[**stepOut**](classffw_1_1_xml_writer.md#1aa8197dcf76f5de3d1c86044068d3c158) () |
|void|[**beginContent**](classffw_1_1_xml_writer.md#1a3f4c683ac6dba3dedbb8ee5cfb14a3c6) () |
|void|[**addInteger**](classffw_1_1_xml_writer.md#1a4cd028aba2bc71f99f4986dbbede00e3) (int val, const char \* key) |
|void|[**addString**](classffw_1_1_xml_writer.md#1ab071acf08fe35e6f83542a885a3e6607) (const char \* val, const char \* key) |
|void|[**addBoolean**](classffw_1_1_xml_writer.md#1a336b0729de733ff761bece76bbef54de) (bool val, const char \* key) |
|void|[**addFloat**](classffw_1_1_xml_writer.md#1a96bc94bef9a570d720a66f256f08ee4e) (float val, const char \* key) |
|void|[**addNull**](classffw_1_1_xml_writer.md#1a556dce28cfa8c88493bd5ebd30305bff) (const char \* key) |


## Detailed Description

doc/markdown/tutorial-xml.md 
## Public Functions Documentation

### function <a id="1a82bdacbba330564503c2f213d20d6127" href="#1a82bdacbba330564503c2f213d20d6127">XmlWriter</a>

```cpp
ffw::XmlWriter::XmlWriter (
    Stream * stream
    const char * indent = NULL
    bool escape = true
)
```



### function <a id="1ac435a10fd5fbd87d2eb0084cacc333e2" href="#1ac435a10fd5fbd87d2eb0084cacc333e2">~XmlWriter</a>

```cpp
virtual ffw::XmlWriter::~XmlWriter ()
```



### function <a id="1af885ff5f4c73d21825e216788c842f7d" href="#1af885ff5f4c73d21825e216788c842f7d">addObject</a>

```cpp
void ffw::XmlWriter::addObject (
    const char * key
)
```



### function <a id="1aa8197dcf76f5de3d1c86044068d3c158" href="#1aa8197dcf76f5de3d1c86044068d3c158">stepOut</a>

```cpp
void ffw::XmlWriter::stepOut ()
```



### function <a id="1a3f4c683ac6dba3dedbb8ee5cfb14a3c6" href="#1a3f4c683ac6dba3dedbb8ee5cfb14a3c6">beginContent</a>

```cpp
void ffw::XmlWriter::beginContent ()
```



### function <a id="1a4cd028aba2bc71f99f4986dbbede00e3" href="#1a4cd028aba2bc71f99f4986dbbede00e3">addInteger</a>

```cpp
void ffw::XmlWriter::addInteger (
    int val
    const char * key
)
```



### function <a id="1ab071acf08fe35e6f83542a885a3e6607" href="#1ab071acf08fe35e6f83542a885a3e6607">addString</a>

```cpp
void ffw::XmlWriter::addString (
    const char * val
    const char * key
)
```



### function <a id="1a336b0729de733ff761bece76bbef54de" href="#1a336b0729de733ff761bece76bbef54de">addBoolean</a>

```cpp
void ffw::XmlWriter::addBoolean (
    bool val
    const char * key
)
```



### function <a id="1a96bc94bef9a570d720a66f256f08ee4e" href="#1a96bc94bef9a570d720a66f256f08ee4e">addFloat</a>

```cpp
void ffw::XmlWriter::addFloat (
    float val
    const char * key
)
```



### function <a id="1a556dce28cfa8c88493bd5ebd30305bff" href="#1a556dce28cfa8c88493bd5ebd30305bff">addNull</a>

```cpp
void ffw::XmlWriter::addNull (
    const char * key
)
```





----------------------------------------
The documentation for this class was generated from the following file: `include/ffw/data/xmlwriter.h`
