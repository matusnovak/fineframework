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
|  [ffw::Any](ffw_Any.html) | [decodeJson](#69d58e3a) (const char * _input_)  |
|  [ffw::Any](ffw_Any.html) | [decodeJson](#d294dc02) (const std::string & _input_)  |
|  [ffw::Any](ffw_Any.html) | [decodeJsonFile](#090e0ee4) (const std::string & _path_)  |
|  std::string | [encodeJson](#3f450749) (const [ffw::Any](ffw_Any.html) & _input_, const char * _indent_ = NULL, bool _escape_ = false)  |
|  bool | [encodeJsonFile](#f3a0ad96) (const std::string & _path_, const [ffw::Any](ffw_Any.html) & _input_, const char * _indent_ = NULL, bool _escape_ = false)  |
|  [ffw::Any](ffw_Any.html) | [decodeXml](#2b32ec0f) (const char * _input_)  |
|  [ffw::Any](ffw_Any.html) | [decodeXml](#14f63b6b) (const std::string & _input_)  |
|  [ffw::Any](ffw_Any.html) | [decodeXmlFile](#d542e979) (const std::string & _path_)  |
|  std::string | [encodeXml](#29241370) (const [ffw::Any](ffw_Any.html) & _input_, const char * _indent_ = NULL, bool _escape_ = false)  |
|  bool | [encodeXmlFile](#66c3b5fb) (const std::string & _path_, const [ffw::Any](ffw_Any.html) & _input_, const char * _indent_ = NULL, bool _escape_ = false)  |


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



### _function_ <a id="69d58e3a" href="#69d58e3a">decodeJson</a>

```cpp
ffw::Any decodeJson (
    const char * input
) 
```



### _function_ <a id="d294dc02" href="#d294dc02">decodeJson</a>

```cpp
ffw::Any decodeJson (
    const std::string & input
) 
```



### _function_ <a id="090e0ee4" href="#090e0ee4">decodeJsonFile</a>

```cpp
ffw::Any decodeJsonFile (
    const std::string & path
) 
```



### _function_ <a id="3f450749" href="#3f450749">encodeJson</a>

```cpp
std::string encodeJson (
    const ffw::Any & input,
    const char * indent = NULL,
    bool escape = false
) 
```



### _function_ <a id="f3a0ad96" href="#f3a0ad96">encodeJsonFile</a>

```cpp
bool encodeJsonFile (
    const std::string & path,
    const ffw::Any & input,
    const char * indent = NULL,
    bool escape = false
) 
```



### _function_ <a id="2b32ec0f" href="#2b32ec0f">decodeXml</a>

```cpp
ffw::Any decodeXml (
    const char * input
) 
```



### _function_ <a id="14f63b6b" href="#14f63b6b">decodeXml</a>

```cpp
ffw::Any decodeXml (
    const std::string & input
) 
```



### _function_ <a id="d542e979" href="#d542e979">decodeXmlFile</a>

```cpp
ffw::Any decodeXmlFile (
    const std::string & path
) 
```



### _function_ <a id="29241370" href="#29241370">encodeXml</a>

```cpp
std::string encodeXml (
    const ffw::Any & input,
    const char * indent = NULL,
    bool escape = false
) 
```



### _function_ <a id="66c3b5fb" href="#66c3b5fb">encodeXmlFile</a>

```cpp
bool encodeXmlFile (
    const std::string & path,
    const ffw::Any & input,
    const char * indent = NULL,
    bool escape = false
) 
```





