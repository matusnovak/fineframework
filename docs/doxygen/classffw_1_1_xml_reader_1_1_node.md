---
search:
    keywords: ['ffw::XmlReader::Node', 'elem', 'Node', 'Node', 'getNextAttribute', 'name', 'isObject', 'hasAttributes', 'rawCstr', 'name', 'isObject', 'isEmpty', 'isString', 'isNumber', 'isInteger', 'isFloat', 'isBoolean', 'isNull', 'toString', 'toInteger', 'toDouble', 'toFloat', 'toBoolean', 'getType', 'rawCstr']
---

# class ffw::XmlReader::Node



Inherits the following classes: **[ffw::XmlReader::Value](classffw_1_1_xml_reader_1_1_value.md)**

## Public Attributes

|Type|Name|
|-----|-----|
|const tinyxml2::XMLElement \*|[**elem**](classffw_1_1_xml_reader_1_1_node.md#1a005ff222b38bf3a29db9fe1027a545c5)|


## Public Functions

|Type|Name|
|-----|-----|
||[**Node**](classffw_1_1_xml_reader_1_1_node.md#1ad3d2ed3c2ada8e1fa87bab4304c05393) () |
||[**Node**](classffw_1_1_xml_reader_1_1_node.md#1ae2419cc71d8ad197b904f31d2160ff46) (const tinyxml2::XMLElement \* node) |
|bool|[**getNextAttribute**](classffw_1_1_xml_reader_1_1_node.md#1acbb9f6e71063d65b161427d9609720ba) (**[Attribute](classffw_1_1_xml_reader_1_1_attribute.md)** \* node) |
|virtual std::string|[**name**](classffw_1_1_xml_reader_1_1_node.md#1ae3a30bac0b014df45a1d7e6722d90773) () override const |
|virtual bool|[**isObject**](classffw_1_1_xml_reader_1_1_node.md#1af5855e40022c69c4d8bd44c2b9c935e7) () override const |
|bool|[**hasAttributes**](classffw_1_1_xml_reader_1_1_node.md#1a7b426046792bf29a03198846ff487d98) () const |
|virtual const char \*|[**rawCstr**](classffw_1_1_xml_reader_1_1_node.md#1a790fd584fd03b0b127245d5c31c403eb) () override const |


#### Public Functions inherited from [ffw::XmlReader::Value](classffw_1_1_xml_reader_1_1_value.md)

|Type|Name|
|-----|-----|
|bool|[**isEmpty**](classffw_1_1_xml_reader_1_1_value.md#1a7f6c69a6afd6d166e6a7060cc85f686d) () const |
|bool|[**isString**](classffw_1_1_xml_reader_1_1_value.md#1ab9a86e3bac0e4f2031a12c41e63d170f) () const |
|bool|[**isNumber**](classffw_1_1_xml_reader_1_1_value.md#1a36dda67412b32e89b83cc75758910deb) () const |
|bool|[**isInteger**](classffw_1_1_xml_reader_1_1_value.md#1abcdcbc4a9b81475405032bfb025b14f3) () const |
|bool|[**isFloat**](classffw_1_1_xml_reader_1_1_value.md#1afba3f88e31c74423852dba3ff2e588c0) () const |
|bool|[**isBoolean**](classffw_1_1_xml_reader_1_1_value.md#1a4e61f37c8f11e8265018e21c407620a5) () const |
|bool|[**isNull**](classffw_1_1_xml_reader_1_1_value.md#1a3524e402c9fd38744cc7d35f2bd00add) () const |
|std::string|[**toString**](classffw_1_1_xml_reader_1_1_value.md#1aac5994ffef325c9acb59161fdd5db891) () const |
|int|[**toInteger**](classffw_1_1_xml_reader_1_1_value.md#1aef9d5a2fd7153bc1808323a6903fc69c) () const |
|double|[**toDouble**](classffw_1_1_xml_reader_1_1_value.md#1a30c805f40309216701f6e47cfae8e045) () const |
|float|[**toFloat**](classffw_1_1_xml_reader_1_1_value.md#1af605d0fd1eb5fc502772333624b9efd2) () const |
|bool|[**toBoolean**](classffw_1_1_xml_reader_1_1_value.md#1a3d4d61d13cbada5bf8a6eeecdf711e2a) () const |
|**[Type](classffw_1_1_xml_reader.md#1a9e191e1a49c0fe3991a7816ddcad353e)**|[**getType**](classffw_1_1_xml_reader_1_1_value.md#1aa137e01cb53bdd11108a1abca4e6856e) () const |


## Public Attributes Documentation

### variable <a id="1a005ff222b38bf3a29db9fe1027a545c5" href="#1a005ff222b38bf3a29db9fe1027a545c5">elem</a>

```cpp
const tinyxml2::XMLElement* ffw::XmlReader::Node::elem;
```



## Public Functions Documentation

### function <a id="1ad3d2ed3c2ada8e1fa87bab4304c05393" href="#1ad3d2ed3c2ada8e1fa87bab4304c05393">Node</a>

```cpp
ffw::XmlReader::Node::Node ()
```



### function <a id="1ae2419cc71d8ad197b904f31d2160ff46" href="#1ae2419cc71d8ad197b904f31d2160ff46">Node</a>

```cpp
ffw::XmlReader::Node::Node (
    const tinyxml2::XMLElement * node
)
```



### function <a id="1acbb9f6e71063d65b161427d9609720ba" href="#1acbb9f6e71063d65b161427d9609720ba">getNextAttribute</a>

```cpp
bool ffw::XmlReader::Node::getNextAttribute (
    Attribute * node
)
```



### function <a id="1ae3a30bac0b014df45a1d7e6722d90773" href="#1ae3a30bac0b014df45a1d7e6722d90773">name</a>

```cpp
virtual std::string ffw::XmlReader::Node::name () const
```

Overrides **[XmlReader::Value::name](classffw_1_1_xml_reader_1_1_value.md#1a757d9d2bc4361f698955aef137e33468)**


### function <a id="1af5855e40022c69c4d8bd44c2b9c935e7" href="#1af5855e40022c69c4d8bd44c2b9c935e7">isObject</a>

```cpp
virtual bool ffw::XmlReader::Node::isObject () const
```

Overrides **[XmlReader::Value::isObject](classffw_1_1_xml_reader_1_1_value.md#1aa11ae43e9e2e0d99bc51518df4801478)**


### function <a id="1a7b426046792bf29a03198846ff487d98" href="#1a7b426046792bf29a03198846ff487d98">hasAttributes</a>

```cpp
bool ffw::XmlReader::Node::hasAttributes () const
```



### function <a id="1a790fd584fd03b0b127245d5c31c403eb" href="#1a790fd584fd03b0b127245d5c31c403eb">rawCstr</a>

```cpp
virtual const char * ffw::XmlReader::Node::rawCstr () const
```

Overrides **[XmlReader::Value::rawCstr](classffw_1_1_xml_reader_1_1_value.md#1ac426cc42a61b45b993442905b6afaa0b)**




----------------------------------------
The documentation for this class was generated from the following file: `include/ffw/data/xmlreader.h`
