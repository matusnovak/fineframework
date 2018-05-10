---
search: false
---

# class ffw::XmlReader::Attribute



Inherits the following classes: **[ffw::XmlReader::Value](classffw_1_1_xml_reader_1_1_value.md)**

## Public Functions

|Type|Name|
|-----|-----|
||[**Attribute**](classffw_1_1_xml_reader_1_1_attribute.md#1a0f1cc32d2b777152d87a9171db0d6a36) () |
||[**Attribute**](classffw_1_1_xml_reader_1_1_attribute.md#1a7e46482dda6694a7efef5bcaa7a2ce9d) (const tinyxml2::XMLAttribute \* node) |
|virtual std::string|[**name**](classffw_1_1_xml_reader_1_1_attribute.md#1a0720eec1ad6f286ca1c93b1c061d2801) () override const |
|virtual bool|[**isObject**](classffw_1_1_xml_reader_1_1_attribute.md#1a17319f9688cc5b59beec6baa87543871) () override const |
|virtual const char \*|[**rawCstr**](classffw_1_1_xml_reader_1_1_attribute.md#1aa5730d5b3117b6bc4a0049453e372b79) () override const |


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


## Public Functions Documentation

### function <a id="1a0f1cc32d2b777152d87a9171db0d6a36" href="#1a0f1cc32d2b777152d87a9171db0d6a36">Attribute</a>

```cpp
ffw::XmlReader::Attribute::Attribute ()
```



### function <a id="1a7e46482dda6694a7efef5bcaa7a2ce9d" href="#1a7e46482dda6694a7efef5bcaa7a2ce9d">Attribute</a>

```cpp
ffw::XmlReader::Attribute::Attribute (
    const tinyxml2::XMLAttribute * node
)
```



### function <a id="1a0720eec1ad6f286ca1c93b1c061d2801" href="#1a0720eec1ad6f286ca1c93b1c061d2801">name</a>

```cpp
virtual std::string ffw::XmlReader::Attribute::name () const
```

Overrides **[XmlReader::Value::name](classffw_1_1_xml_reader_1_1_value.md#1a757d9d2bc4361f698955aef137e33468)**


### function <a id="1a17319f9688cc5b59beec6baa87543871" href="#1a17319f9688cc5b59beec6baa87543871">isObject</a>

```cpp
virtual bool ffw::XmlReader::Attribute::isObject () const
```

Overrides **[XmlReader::Value::isObject](classffw_1_1_xml_reader_1_1_value.md#1aa11ae43e9e2e0d99bc51518df4801478)**


### function <a id="1aa5730d5b3117b6bc4a0049453e372b79" href="#1aa5730d5b3117b6bc4a0049453e372b79">rawCstr</a>

```cpp
virtual const char * ffw::XmlReader::Attribute::rawCstr () const
```

Overrides **[XmlReader::Value::rawCstr](classffw_1_1_xml_reader_1_1_value.md#1ac426cc42a61b45b993442905b6afaa0b)**




----------------------------------------
The documentation for this class was generated from the following file: `include/ffw/data/xmlreader.h`
