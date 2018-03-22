---
search:
    keywords: ['ffw::XmlReader::Value', 'name', 'isObject', 'isEmpty', 'isString', 'isNumber', 'isInteger', 'isFloat', 'isBoolean', 'isNull', 'toString', 'toInteger', 'toDouble', 'toFloat', 'toBoolean', 'getType', 'rawCstr']
---

# class ffw::XmlReader::Value



Inherited by the following classes: **[ffw::XmlReader::Attribute](classffw_1_1_xml_reader_1_1_attribute.md)**, **[ffw::XmlReader::Node](classffw_1_1_xml_reader_1_1_node.md)**

## Public Functions

|Type|Name|
|-----|-----|
|virtual std::string|[**name**](classffw_1_1_xml_reader_1_1_value.md#1a757d9d2bc4361f698955aef137e33468) () const = 0|
|virtual bool|[**isObject**](classffw_1_1_xml_reader_1_1_value.md#1aa11ae43e9e2e0d99bc51518df4801478) () const = 0|
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
|virtual const char \*|[**rawCstr**](classffw_1_1_xml_reader_1_1_value.md#1ac426cc42a61b45b993442905b6afaa0b) () const = 0|


## Public Functions Documentation

### function <a id="1a757d9d2bc4361f698955aef137e33468" href="#1a757d9d2bc4361f698955aef137e33468">name</a>

```cpp
virtual std::string ffw::XmlReader::Value::name () const = 0
```



### function <a id="1aa11ae43e9e2e0d99bc51518df4801478" href="#1aa11ae43e9e2e0d99bc51518df4801478">isObject</a>

```cpp
virtual bool ffw::XmlReader::Value::isObject () const = 0
```



### function <a id="1a7f6c69a6afd6d166e6a7060cc85f686d" href="#1a7f6c69a6afd6d166e6a7060cc85f686d">isEmpty</a>

```cpp
bool ffw::XmlReader::Value::isEmpty () const
```



### function <a id="1ab9a86e3bac0e4f2031a12c41e63d170f" href="#1ab9a86e3bac0e4f2031a12c41e63d170f">isString</a>

```cpp
bool ffw::XmlReader::Value::isString () const
```



### function <a id="1a36dda67412b32e89b83cc75758910deb" href="#1a36dda67412b32e89b83cc75758910deb">isNumber</a>

```cpp
bool ffw::XmlReader::Value::isNumber () const
```



### function <a id="1abcdcbc4a9b81475405032bfb025b14f3" href="#1abcdcbc4a9b81475405032bfb025b14f3">isInteger</a>

```cpp
bool ffw::XmlReader::Value::isInteger () const
```



### function <a id="1afba3f88e31c74423852dba3ff2e588c0" href="#1afba3f88e31c74423852dba3ff2e588c0">isFloat</a>

```cpp
bool ffw::XmlReader::Value::isFloat () const
```



### function <a id="1a4e61f37c8f11e8265018e21c407620a5" href="#1a4e61f37c8f11e8265018e21c407620a5">isBoolean</a>

```cpp
bool ffw::XmlReader::Value::isBoolean () const
```



### function <a id="1a3524e402c9fd38744cc7d35f2bd00add" href="#1a3524e402c9fd38744cc7d35f2bd00add">isNull</a>

```cpp
bool ffw::XmlReader::Value::isNull () const
```



### function <a id="1aac5994ffef325c9acb59161fdd5db891" href="#1aac5994ffef325c9acb59161fdd5db891">toString</a>

```cpp
std::string ffw::XmlReader::Value::toString () const
```



### function <a id="1aef9d5a2fd7153bc1808323a6903fc69c" href="#1aef9d5a2fd7153bc1808323a6903fc69c">toInteger</a>

```cpp
int ffw::XmlReader::Value::toInteger () const
```



### function <a id="1a30c805f40309216701f6e47cfae8e045" href="#1a30c805f40309216701f6e47cfae8e045">toDouble</a>

```cpp
double ffw::XmlReader::Value::toDouble () const
```



### function <a id="1af605d0fd1eb5fc502772333624b9efd2" href="#1af605d0fd1eb5fc502772333624b9efd2">toFloat</a>

```cpp
float ffw::XmlReader::Value::toFloat () const
```



### function <a id="1a3d4d61d13cbada5bf8a6eeecdf711e2a" href="#1a3d4d61d13cbada5bf8a6eeecdf711e2a">toBoolean</a>

```cpp
bool ffw::XmlReader::Value::toBoolean () const
```



### function <a id="1aa137e01cb53bdd11108a1abca4e6856e" href="#1aa137e01cb53bdd11108a1abca4e6856e">getType</a>

```cpp
Type ffw::XmlReader::Value::getType () const
```



### function <a id="1ac426cc42a61b45b993442905b6afaa0b" href="#1ac426cc42a61b45b993442905b6afaa0b">rawCstr</a>

```cpp
virtual const char * ffw::XmlReader::Value::rawCstr () const = 0
```





----------------------------------------
The documentation for this class was generated from the following file: `include/ffw/data/xmlreader.h`
