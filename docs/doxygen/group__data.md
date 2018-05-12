---
search: false
---

# group data

Encode and decode XML, CSV, or JSON structures. [More...](#detailed-description)
## Classes

|Type|Name|
|-----|-----|
|class|[**ffw::CsvLoader**](classffw_1_1_csv_loader.md)|
|class|[**ffw::JsonException**](classffw_1_1_json_exception.md)|
|class|[**ffw::JsonDecodeException**](classffw_1_1_json_decode_exception.md)|
|class|[**ffw::JsonEncodeException**](classffw_1_1_json_encode_exception.md)|
|class|[**ffw::JsonReader**](classffw_1_1_json_reader.md)|
|class|[**ffw::JsonWriter**](classffw_1_1_json_writer.md)|
|class|[**ffw::XmlException**](classffw_1_1_xml_exception.md)|
|class|[**ffw::XmlDecodeException**](classffw_1_1_xml_decode_exception.md)|
|class|[**ffw::XmlEncodeException**](classffw_1_1_xml_encode_exception.md)|
|class|[**ffw::XmlReader**](classffw_1_1_xml_reader.md)|
|class|[**ffw::XmlWriter**](classffw_1_1_xml_writer.md)|


## Functions

|Type|Name|
|-----|-----|
|**[ffw::Array](classffw_1_1_array.md)**|[**decodeCsvFile**](group__data_.md#ga168243fb4b76721254279383fad59359) (const std::string & path) |
|**[ffw::Array](classffw_1_1_array.md)**|[**decodeCsv**](group__data_.md#ga3175e907023dd05a990340db32e2e632) (const std::string & input) |
|bool|[**stringContainsWhitespace**](group__data_.md#gabd5c09c9d45df57a4232328dfe9a06fc) (std::string::const\_iterator begin, std::string::const\_iterator end) |
|bool|[**stringisInteger**](group__data_.md#gac7c6fb6aedd4fa29a46e99d0fb2ca88e) (std::string::const\_iterator begin, std::string::const\_iterator end) |
|bool|[**stringisFloat**](group__data_.md#gaead0c558093bc2b4735d5600d7fa9591) (std::string::const\_iterator begin, std::string::const\_iterator end) |
|bool|[**stringisBool**](group__data_.md#ga6f21f9a74f57256078fa491a82d60f74) (std::string::const\_iterator begin, std::string::const\_iterator end) |
|**[ffw::Any](classffw_1_1_any.md)**|[**decodeJson**](group__data_.md#ga6481e0e2a2b68f4c30b5e278e565bff1) (const char \* input) |
|**[ffw::Any](classffw_1_1_any.md)**|[**decodeJson**](group__data_.md#gac25ee24bb87a37d1cdfbff6fd156857f) (const std::string & input) |
|**[ffw::Any](classffw_1_1_any.md)**|[**decodeJsonFile**](group__data_.md#gaf614ae4902b967935f7c3e16c159b031) (const std::string & path) |
|std::string|[**encodeJson**](group__data_.md#gada9f7c3ad3466d70b0ff1a809999b624) (const **[ffw::Any](classffw_1_1_any.md)** & input, const char \* indent = NULL, bool escape = false) |
|bool|[**encodeJsonFile**](group__data_.md#ga0bd01fb3c58ac0e3c9ce5f4a134d92b0) (const std::string & path, const **[ffw::Any](classffw_1_1_any.md)** & input, const char \* indent = NULL, bool escape = false) |
|**[ffw::Any](classffw_1_1_any.md)**|[**decodeXml**](group__data_.md#ga0ce451d306fe8e5e90d62a176afcb20a) (const char \* input) |
|**[ffw::Any](classffw_1_1_any.md)**|[**decodeXml**](group__data_.md#ga40ab60116cfb071974894e6b8b9b4c9e) (const std::string & input) |
|**[ffw::Any](classffw_1_1_any.md)**|[**decodeXmlFile**](group__data_.md#gaafbee1e48e69699545bec0939b89b2ef) (const std::string & path) |
|std::string|[**encodeXml**](group__data_.md#ga08075eb23017653926f047828e2d4ed8) (const **[ffw::Any](classffw_1_1_any.md)** & input, const char \* indent = NULL, bool escape = false) |
|bool|[**encodeXmlFile**](group__data_.md#gadf846737a7427d789c555ed7e0a5e753) (const std::string & path, const **[ffw::Any](classffw_1_1_any.md)** & input, const char \* indent = NULL, bool escape = false) |


## Detailed Description

Provides a way to load and save XML, CSV, and JSON data files. Uses third party library [tinyxml-2](https://github.com/leethomason/tinyxml2) 
## Functions Documentation

### function <a id="ga168243fb4b76721254279383fad59359" href="#ga168243fb4b76721254279383fad59359">decodeCsvFile</a>

```cpp
ffw::Array data::decodeCsvFile (
    const std::string & path
)
```



### function <a id="ga3175e907023dd05a990340db32e2e632" href="#ga3175e907023dd05a990340db32e2e632">decodeCsv</a>

```cpp
ffw::Array data::decodeCsv (
    const std::string & input
)
```



### function <a id="gabd5c09c9d45df57a4232328dfe9a06fc" href="#gabd5c09c9d45df57a4232328dfe9a06fc">stringContainsWhitespace</a>

```cpp
bool data::stringContainsWhitespace (
    std::string::const_iterator begin,
    std::string::const_iterator end
)
```



### function <a id="gac7c6fb6aedd4fa29a46e99d0fb2ca88e" href="#gac7c6fb6aedd4fa29a46e99d0fb2ca88e">stringisInteger</a>

```cpp
bool data::stringisInteger (
    std::string::const_iterator begin,
    std::string::const_iterator end
)
```



### function <a id="gaead0c558093bc2b4735d5600d7fa9591" href="#gaead0c558093bc2b4735d5600d7fa9591">stringisFloat</a>

```cpp
bool data::stringisFloat (
    std::string::const_iterator begin,
    std::string::const_iterator end
)
```



### function <a id="ga6f21f9a74f57256078fa491a82d60f74" href="#ga6f21f9a74f57256078fa491a82d60f74">stringisBool</a>

```cpp
bool data::stringisBool (
    std::string::const_iterator begin,
    std::string::const_iterator end
)
```



### function <a id="ga6481e0e2a2b68f4c30b5e278e565bff1" href="#ga6481e0e2a2b68f4c30b5e278e565bff1">decodeJson</a>

```cpp
ffw::Any data::decodeJson (
    const char * input
)
```



### function <a id="gac25ee24bb87a37d1cdfbff6fd156857f" href="#gac25ee24bb87a37d1cdfbff6fd156857f">decodeJson</a>

```cpp
ffw::Any data::decodeJson (
    const std::string & input
)
```



### function <a id="gaf614ae4902b967935f7c3e16c159b031" href="#gaf614ae4902b967935f7c3e16c159b031">decodeJsonFile</a>

```cpp
ffw::Any data::decodeJsonFile (
    const std::string & path
)
```



### function <a id="gada9f7c3ad3466d70b0ff1a809999b624" href="#gada9f7c3ad3466d70b0ff1a809999b624">encodeJson</a>

```cpp
std::string data::encodeJson (
    const ffw::Any & input,
    const char * indent = NULL,
    bool escape = false
)
```



### function <a id="ga0bd01fb3c58ac0e3c9ce5f4a134d92b0" href="#ga0bd01fb3c58ac0e3c9ce5f4a134d92b0">encodeJsonFile</a>

```cpp
bool data::encodeJsonFile (
    const std::string & path,
    const ffw::Any & input,
    const char * indent = NULL,
    bool escape = false
)
```



### function <a id="ga0ce451d306fe8e5e90d62a176afcb20a" href="#ga0ce451d306fe8e5e90d62a176afcb20a">decodeXml</a>

```cpp
ffw::Any data::decodeXml (
    const char * input
)
```



### function <a id="ga40ab60116cfb071974894e6b8b9b4c9e" href="#ga40ab60116cfb071974894e6b8b9b4c9e">decodeXml</a>

```cpp
ffw::Any data::decodeXml (
    const std::string & input
)
```



### function <a id="gaafbee1e48e69699545bec0939b89b2ef" href="#gaafbee1e48e69699545bec0939b89b2ef">decodeXmlFile</a>

```cpp
ffw::Any data::decodeXmlFile (
    const std::string & path
)
```



### function <a id="ga08075eb23017653926f047828e2d4ed8" href="#ga08075eb23017653926f047828e2d4ed8">encodeXml</a>

```cpp
std::string data::encodeXml (
    const ffw::Any & input,
    const char * indent = NULL,
    bool escape = false
)
```



### function <a id="gadf846737a7427d789c555ed7e0a5e753" href="#gadf846737a7427d789c555ed7e0a5e753">encodeXmlFile</a>

```cpp
bool data::encodeXmlFile (
    const std::string & path,
    const ffw::Any & input,
    const char * indent = NULL,
    bool escape = false
)
```



