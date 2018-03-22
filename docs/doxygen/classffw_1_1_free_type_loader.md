---
search:
    keywords: ['ffw::FreeTypeLoader', 'CharData', 'FreeTypeLoader', 'FreeTypeLoader', 'FreeTypeLoader', '~FreeTypeLoader', 'createFromData', 'createFromFile', 'setSize', 'findGlyph', 'findErrorGlyph', 'getGlyphData', 'getSizePixels', 'isCreated', 'destroy', 'swap', 'operator=', 'operator=']
---

# class ffw::FreeTypeLoader

## Classes

|Type|Name|
|-----|-----|
|class|[**CharData**](classffw_1_1_free_type_loader_1_1_char_data.md)|


## Public Functions

|Type|Name|
|-----|-----|
||[**FreeTypeLoader**](classffw_1_1_free_type_loader.md#1a2e6a6d31b7fd100c29611a149ff17a2c) () |
||[**FreeTypeLoader**](classffw_1_1_free_type_loader.md#1a34565a5f6609bd05f4a01cb30662feec) (const **[FreeTypeLoader](classffw_1_1_free_type_loader.md)** & other) = delete |
||[**FreeTypeLoader**](classffw_1_1_free_type_loader.md#1abfa1c7aeafa6cc8dd94c228bd72d574c) (**[FreeTypeLoader](classffw_1_1_free_type_loader.md)** && other) |
|virtual |[**~FreeTypeLoader**](classffw_1_1_free_type_loader.md#1a49e129a77fa999992765514be1eabe79) () |
|bool|[**createFromData**](classffw_1_1_free_type_loader.md#1a774613675e3439649cc0d544b6255e66) (const unsigned char \* buffer, size\_t length) |
|bool|[**createFromFile**](classffw_1_1_free_type_loader.md#1aec08f4d3792c16e87ab7f285d8e1fb14) (const std::string & path) |
|bool|[**setSize**](classffw_1_1_free_type_loader.md#1a44b2dab370e95107125c40220940947e) (int points, int dpi) |
|bool|[**findGlyph**](classffw_1_1_free_type_loader.md#1a08647648110af9e69ab5cd2a6b14242c) (int unicode) |
|bool|[**findErrorGlyph**](classffw_1_1_free_type_loader.md#1a0b7e56504393e08cb104f00f5f984bd8) () |
|bool|[**getGlyphData**](classffw_1_1_free_type_loader.md#1a2b5b2d7cdaf6608983b99aca0bcd2cec) (**[CharData](classffw_1_1_free_type_loader_1_1_char_data.md)** \* data) |
|int|[**getSizePixels**](classffw_1_1_free_type_loader.md#1a807f480e49a4b0651773c8d32acd59d2) () const |
|bool|[**isCreated**](classffw_1_1_free_type_loader.md#1a5b52f05602c263e772e5facecf22ba1c) () const |
|void|[**destroy**](classffw_1_1_free_type_loader.md#1aaec7a25ac382149a82fe1eac2116f1e7) () |
|void|[**swap**](classffw_1_1_free_type_loader.md#1a955aaa6f8e3b2c07051efb02ec3aa904) (**[FreeTypeLoader](classffw_1_1_free_type_loader.md)** & other) |
|**[FreeTypeLoader](classffw_1_1_free_type_loader.md)** &|[**operator=**](classffw_1_1_free_type_loader.md#1aace650be70feff977d30e6e7bb685762) (const **[FreeTypeLoader](classffw_1_1_free_type_loader.md)** & other) = delete |
|**[FreeTypeLoader](classffw_1_1_free_type_loader.md)** &|[**operator=**](classffw_1_1_free_type_loader.md#1a8a94b478cae502e61e380a57b0dbf829) (**[FreeTypeLoader](classffw_1_1_free_type_loader.md)** && other) |


## Public Functions Documentation

### function <a id="1a2e6a6d31b7fd100c29611a149ff17a2c" href="#1a2e6a6d31b7fd100c29611a149ff17a2c">FreeTypeLoader</a>

```cpp
ffw::FreeTypeLoader::FreeTypeLoader ()
```



### function <a id="1a34565a5f6609bd05f4a01cb30662feec" href="#1a34565a5f6609bd05f4a01cb30662feec">FreeTypeLoader</a>

```cpp
ffw::FreeTypeLoader::FreeTypeLoader (
    const FreeTypeLoader & other
) = delete
```



### function <a id="1abfa1c7aeafa6cc8dd94c228bd72d574c" href="#1abfa1c7aeafa6cc8dd94c228bd72d574c">FreeTypeLoader</a>

```cpp
ffw::FreeTypeLoader::FreeTypeLoader (
    FreeTypeLoader && other
)
```



### function <a id="1a49e129a77fa999992765514be1eabe79" href="#1a49e129a77fa999992765514be1eabe79">~FreeTypeLoader</a>

```cpp
virtual ffw::FreeTypeLoader::~FreeTypeLoader ()
```



### function <a id="1a774613675e3439649cc0d544b6255e66" href="#1a774613675e3439649cc0d544b6255e66">createFromData</a>

```cpp
bool ffw::FreeTypeLoader::createFromData (
    const unsigned char * buffer
    size_t length
)
```



### function <a id="1aec08f4d3792c16e87ab7f285d8e1fb14" href="#1aec08f4d3792c16e87ab7f285d8e1fb14">createFromFile</a>

```cpp
bool ffw::FreeTypeLoader::createFromFile (
    const std::string & path
)
```



### function <a id="1a44b2dab370e95107125c40220940947e" href="#1a44b2dab370e95107125c40220940947e">setSize</a>

```cpp
bool ffw::FreeTypeLoader::setSize (
    int points
    int dpi
)
```



### function <a id="1a08647648110af9e69ab5cd2a6b14242c" href="#1a08647648110af9e69ab5cd2a6b14242c">findGlyph</a>

```cpp
bool ffw::FreeTypeLoader::findGlyph (
    int unicode
)
```



### function <a id="1a0b7e56504393e08cb104f00f5f984bd8" href="#1a0b7e56504393e08cb104f00f5f984bd8">findErrorGlyph</a>

```cpp
bool ffw::FreeTypeLoader::findErrorGlyph ()
```



### function <a id="1a2b5b2d7cdaf6608983b99aca0bcd2cec" href="#1a2b5b2d7cdaf6608983b99aca0bcd2cec">getGlyphData</a>

```cpp
bool ffw::FreeTypeLoader::getGlyphData (
    CharData * data
)
```



### function <a id="1a807f480e49a4b0651773c8d32acd59d2" href="#1a807f480e49a4b0651773c8d32acd59d2">getSizePixels</a>

```cpp
int ffw::FreeTypeLoader::getSizePixels () const
```



### function <a id="1a5b52f05602c263e772e5facecf22ba1c" href="#1a5b52f05602c263e772e5facecf22ba1c">isCreated</a>

```cpp
bool ffw::FreeTypeLoader::isCreated () const
```



### function <a id="1aaec7a25ac382149a82fe1eac2116f1e7" href="#1aaec7a25ac382149a82fe1eac2116f1e7">destroy</a>

```cpp
void ffw::FreeTypeLoader::destroy ()
```



### function <a id="1a955aaa6f8e3b2c07051efb02ec3aa904" href="#1a955aaa6f8e3b2c07051efb02ec3aa904">swap</a>

```cpp
void ffw::FreeTypeLoader::swap (
    FreeTypeLoader & other
)
```



### function <a id="1aace650be70feff977d30e6e7bb685762" href="#1aace650be70feff977d30e6e7bb685762">operator=</a>

```cpp
FreeTypeLoader & ffw::FreeTypeLoader::operator= (
    const FreeTypeLoader & other
) = delete
```



### function <a id="1a8a94b478cae502e61e380a57b0dbf829" href="#1a8a94b478cae502e61e380a57b0dbf829">operator=</a>

```cpp
FreeTypeLoader & ffw::FreeTypeLoader::operator= (
    FreeTypeLoader && other
)
```





----------------------------------------
The documentation for this class was generated from the following file: `include/ffw/graphics/freetypeloader.h`
