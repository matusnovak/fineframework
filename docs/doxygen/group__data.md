data - XML, CSV, and JSON loaders
===================================

Encode and decode XML, CSV, or JSON structures. 

## Detailed description

Provides a way to load and save XML, CSV, and JSON data files. Uses third party library [tinyxml-2](https://github.com/leethomason/tinyxml2) 


## Classes

| Name |
|:-----|
| class [ffw::CsvLoader](ffw_CsvLoader.html) |
| class [ffw::JsonException](ffw_JsonException.html) |
| class [ffw::JsonDecodeException](ffw_JsonDecodeException.html) |
| class [ffw::JsonEncodeException](ffw_JsonEncodeException.html) |
| class [ffw::JsonReader](ffw_JsonReader.html) |
| class [ffw::JsonWriter](ffw_JsonWriter.html) |
| class [ffw::XmlException](ffw_XmlException.html) |
| class [ffw::XmlDecodeException](ffw_XmlDecodeException.html) |
| class [ffw::XmlEncodeException](ffw_XmlEncodeException.html) |
| class [ffw::XmlReader](ffw_XmlReader.html) |
| class [ffw::XmlWriter](ffw_XmlWriter.html) |


## Functions

| Type | Name |
| -------: | :------- |
|  [ffw::Array](ffw_Array.html) | [decodeCsvFile](#3888b141) (const std::string & _path_)  |
|  [ffw::Array](ffw_Array.html) | [decodeCsv](#b7bf6532) (const std::string & _input_)  |
|  bool | [stringContainsWhitespace](#86615814) (std::string::const_iterator _begin_, std::string::const_iterator _end_)  |
|  bool | [stringisInteger](#0f301d2c) (std::string::const_iterator _begin_, std::string::const_iterator _end_)  |
|  bool | [stringisFloat](#42754420) (std::string::const_iterator _begin_, std::string::const_iterator _end_)  |
|  bool | [stringisBool](#f795143f) (std::string::const_iterator _begin_, std::string::const_iterator _end_)  |
|  [ffw::Var](ffw_Var.html) | [decodeJson](#6d044655) (const char * _input_)  |
|  [ffw::Var](ffw_Var.html) | [decodeJson](#b4cddc87) (const std::string & _input_)  |
|  [ffw::Var](ffw_Var.html) | [decodeJsonFile](#0e979a8d) (const std::string & _path_)  |
|  std::string | [encodeJson](#3b2e9a26) (const [ffw::Var](ffw_Var.html) & _input_, const char * _indent_ = NULL, bool _escape_ = false)  |
|  bool | [encodeJsonFile](#20155556) (const std::string & _path_, const [ffw::Var](ffw_Var.html) & _input_, const char * _indent_ = NULL, bool _escape_ = false)  |
|  [ffw::Var](ffw_Var.html) | [decodeXml](#39a9cfe3) (const char * _input_)  |
|  [ffw::Var](ffw_Var.html) | [decodeXml](#1f3cceee) (const std::string & _input_)  |
|  [ffw::Var](ffw_Var.html) | [decodeXmlFile](#3e9f5d3d) (const std::string & _path_)  |
|  std::string | [encodeXml](#80464558) (const [ffw::Var](ffw_Var.html) & _input_, const char * _indent_ = NULL, bool _escape_ = false)  |
|  bool | [encodeXmlFile](#d92c62d9) (const std::string & _path_, const [ffw::Var](ffw_Var.html) & _input_, const char * _indent_ = NULL, bool _escape_ = false)  |


## Functions Documentation

### _function_ <a id="3888b141" href="#3888b141">decodeCsvFile</a>

```cpp
ffw::Array decodeCsvFile (
    const std::string & path
) 
```



### _function_ <a id="b7bf6532" href="#b7bf6532">decodeCsv</a>

```cpp
ffw::Array decodeCsv (
    const std::string & input
) 
```



### _function_ <a id="86615814" href="#86615814">stringContainsWhitespace</a>

```cpp
bool stringContainsWhitespace (
    std::string::const_iterator begin,
    std::string::const_iterator end
) 
```



### _function_ <a id="0f301d2c" href="#0f301d2c">stringisInteger</a>

```cpp
bool stringisInteger (
    std::string::const_iterator begin,
    std::string::const_iterator end
) 
```



### _function_ <a id="42754420" href="#42754420">stringisFloat</a>

```cpp
bool stringisFloat (
    std::string::const_iterator begin,
    std::string::const_iterator end
) 
```



### _function_ <a id="f795143f" href="#f795143f">stringisBool</a>

```cpp
bool stringisBool (
    std::string::const_iterator begin,
    std::string::const_iterator end
) 
```



### _function_ <a id="6d044655" href="#6d044655">decodeJson</a>

```cpp
ffw::Var decodeJson (
    const char * input
) 
```



### _function_ <a id="b4cddc87" href="#b4cddc87">decodeJson</a>

```cpp
ffw::Var decodeJson (
    const std::string & input
) 
```



### _function_ <a id="0e979a8d" href="#0e979a8d">decodeJsonFile</a>

```cpp
ffw::Var decodeJsonFile (
    const std::string & path
) 
```



### _function_ <a id="3b2e9a26" href="#3b2e9a26">encodeJson</a>

```cpp
std::string encodeJson (
    const ffw::Var & input,
    const char * indent = NULL,
    bool escape = false
) 
```



### _function_ <a id="20155556" href="#20155556">encodeJsonFile</a>

```cpp
bool encodeJsonFile (
    const std::string & path,
    const ffw::Var & input,
    const char * indent = NULL,
    bool escape = false
) 
```



### _function_ <a id="39a9cfe3" href="#39a9cfe3">decodeXml</a>

```cpp
ffw::Var decodeXml (
    const char * input
) 
```



### _function_ <a id="1f3cceee" href="#1f3cceee">decodeXml</a>

```cpp
ffw::Var decodeXml (
    const std::string & input
) 
```



### _function_ <a id="3e9f5d3d" href="#3e9f5d3d">decodeXmlFile</a>

```cpp
ffw::Var decodeXmlFile (
    const std::string & path
) 
```



### _function_ <a id="80464558" href="#80464558">encodeXml</a>

```cpp
std::string encodeXml (
    const ffw::Var & input,
    const char * indent = NULL,
    bool escape = false
) 
```



### _function_ <a id="d92c62d9" href="#d92c62d9">encodeXmlFile</a>

```cpp
bool encodeXmlFile (
    const std::string & path,
    const ffw::Var & input,
    const char * indent = NULL,
    bool escape = false
) 
```





