---
search: false
---

# namespace utf8

## Classes

|Type|Name|
|-----|-----|
|class|[**exception**](classutf8_1_1exception.md)|
|class|[**invalid\_code\_point**](classutf8_1_1invalid__code__point.md)|
|class|[**invalid\_utf16**](classutf8_1_1invalid__utf16.md)|
|class|[**invalid\_utf8**](classutf8_1_1invalid__utf8.md)|
|class|[**iterator**](classutf8_1_1iterator.md)|
|class|[**not\_enough\_room**](classutf8_1_1not__enough__room.md)|


## Typedefs

|Type|Name|
|-----|-----|
|typedef unsigned char|[**uint8\_t**](namespaceutf8.md#1abe793b552fabe390d134b97ab81d2c7f)|
|typedef unsigned short|[**uint16\_t**](namespaceutf8.md#1ac23066b92c5a1d9d9ef177201f750936)|
|typedef unsigned int|[**uint32\_t**](namespaceutf8.md#1a846259d2f173d524282583fc9d825b00)|


## Variables

|Type|Name|
|-----|-----|
|const **[uint8\_t](namespaceutf8.md#1abe793b552fabe390d134b97ab81d2c7f)**|[**bom**](namespaceutf8.md#1ac7efcab62f51d362fc741657e60b9b1d)<br>The library API - functions intended to be called by the users. |


## Functions

|Type|Name|
|-----|-----|
|octet\_iterator|[**append**](namespaceutf8.md#1a3827e78596fc38cfdebd721e9c45c901) (**[uint32\_t](namespaceutf8.md#1a846259d2f173d524282583fc9d825b00)** cp, octet\_iterator result) <br>The library API - functions intended to be called by the users. |
|output\_iterator|[**replace\_invalid**](namespaceutf8.md#1a07dcd36a2185e5c9f0b19dd88859cd6c) (octet\_iterator start, octet\_iterator end, output\_iterator out, **[uint32\_t](namespaceutf8.md#1a846259d2f173d524282583fc9d825b00)** replacement) |
|output\_iterator|[**replace\_invalid**](namespaceutf8.md#1a13db09b6629724205302c623b76db028) (octet\_iterator start, octet\_iterator end, output\_iterator out) |
|**[uint32\_t](namespaceutf8.md#1a846259d2f173d524282583fc9d825b00)**|[**next**](namespaceutf8.md#1afc093dfde66a6f52cb4a5caefe0e580d) (octet\_iterator & it, octet\_iterator end) |
|**[uint32\_t](namespaceutf8.md#1a846259d2f173d524282583fc9d825b00)**|[**peek\_next**](namespaceutf8.md#1a42451db4241d57afe46e61f6a966ee8d) (octet\_iterator it, octet\_iterator end) |
|**[uint32\_t](namespaceutf8.md#1a846259d2f173d524282583fc9d825b00)**|[**prior**](namespaceutf8.md#1a9a599fdd8a16ce65e3e72192db9d499b) (octet\_iterator & it, octet\_iterator start) |
|**[uint32\_t](namespaceutf8.md#1a846259d2f173d524282583fc9d825b00)**|[**previous**](namespaceutf8.md#1aedaf9315740d4f25b43c188b02b5bcd0) (octet\_iterator & it, octet\_iterator pass\_start) <br>Deprecated in versions that include "prior". |
|void|[**advance**](namespaceutf8.md#1a411eec0d2919810bb26966be242c1e9e) (octet\_iterator & it, distance\_type n, octet\_iterator end) |
|std::iterator\_traits< octet\_iterator >::difference\_type|[**distance**](namespaceutf8.md#1a75394fbfe91b1122e2602a6d73c5f612) (octet\_iterator first, octet\_iterator last) |
|octet\_iterator|[**utf16to8**](namespaceutf8.md#1acb68503442bd2e797e8fc8a960f54cf8) (u16bit\_iterator start, u16bit\_iterator end, octet\_iterator result) |
|u16bit\_iterator|[**utf8to16**](namespaceutf8.md#1a6404050074139c367a42f0a911779903) (octet\_iterator start, octet\_iterator end, u16bit\_iterator result) |
|octet\_iterator|[**utf32to8**](namespaceutf8.md#1a4a1157ef2f85d4bc8366dbbea20dcb48) (u32bit\_iterator start, u32bit\_iterator end, octet\_iterator result) |
|u32bit\_iterator|[**utf8to32**](namespaceutf8.md#1a8020ed399788dca779663adf061ed718) (octet\_iterator start, octet\_iterator end, u32bit\_iterator result) |
|octet\_iterator|[**find\_invalid**](namespaceutf8.md#1ae29721faca762865e83ffea06605acc5) (octet\_iterator start, octet\_iterator end) |
|bool|[**is\_valid**](namespaceutf8.md#1add2dbec3d058aa66500ec4f97cc8174b) (octet\_iterator start, octet\_iterator end) |
|bool|[**starts\_with\_bom**](namespaceutf8.md#1a498c8e7d7a6fd92d4672ef05661dc783) (octet\_iterator it, octet\_iterator end) |
|bool|[**is\_bom**](namespaceutf8.md#1aed9555bcddc0fd46296bf4e5642229ed) (octet\_iterator it) |


## Typedefs Documentation

### typedef <a id="1abe793b552fabe390d134b97ab81d2c7f" href="#1abe793b552fabe390d134b97ab81d2c7f">uint8\_t</a>

```cpp
typedef unsigned char utf8::uint8_t;
```



### typedef <a id="1ac23066b92c5a1d9d9ef177201f750936" href="#1ac23066b92c5a1d9d9ef177201f750936">uint16\_t</a>

```cpp
typedef unsigned short utf8::uint16_t;
```



### typedef <a id="1a846259d2f173d524282583fc9d825b00" href="#1a846259d2f173d524282583fc9d825b00">uint32\_t</a>

```cpp
typedef unsigned int utf8::uint32_t;
```



## Variables Documentation

### variable <a id="1ac7efcab62f51d362fc741657e60b9b1d" href="#1ac7efcab62f51d362fc741657e60b9b1d">bom</a>

```cpp
const uint8_t utf8::bom[];
```

The library API - functions intended to be called by the users. 


## Functions Documentation

### function <a id="1a3827e78596fc38cfdebd721e9c45c901" href="#1a3827e78596fc38cfdebd721e9c45c901">append</a>

```cpp
octet_iterator utf8::append (
    uint32_t cp
    octet_iterator result
)
```

The library API - functions intended to be called by the users. 


### function <a id="1a07dcd36a2185e5c9f0b19dd88859cd6c" href="#1a07dcd36a2185e5c9f0b19dd88859cd6c">replace\_invalid</a>

```cpp
output_iterator utf8::replace_invalid (
    octet_iterator start
    octet_iterator end
    output_iterator out
    uint32_t replacement
)
```



### function <a id="1a13db09b6629724205302c623b76db028" href="#1a13db09b6629724205302c623b76db028">replace\_invalid</a>

```cpp
output_iterator utf8::replace_invalid (
    octet_iterator start
    octet_iterator end
    output_iterator out
)
```



### function <a id="1afc093dfde66a6f52cb4a5caefe0e580d" href="#1afc093dfde66a6f52cb4a5caefe0e580d">next</a>

```cpp
uint32_t utf8::next (
    octet_iterator & it
    octet_iterator end
)
```



### function <a id="1a42451db4241d57afe46e61f6a966ee8d" href="#1a42451db4241d57afe46e61f6a966ee8d">peek\_next</a>

```cpp
uint32_t utf8::peek_next (
    octet_iterator it
    octet_iterator end
)
```



### function <a id="1a9a599fdd8a16ce65e3e72192db9d499b" href="#1a9a599fdd8a16ce65e3e72192db9d499b">prior</a>

```cpp
uint32_t utf8::prior (
    octet_iterator & it
    octet_iterator start
)
```



### function <a id="1aedaf9315740d4f25b43c188b02b5bcd0" href="#1aedaf9315740d4f25b43c188b02b5bcd0">previous</a>

```cpp
uint32_t utf8::previous (
    octet_iterator & it
    octet_iterator pass_start
)
```

Deprecated in versions that include "prior". 


### function <a id="1a411eec0d2919810bb26966be242c1e9e" href="#1a411eec0d2919810bb26966be242c1e9e">advance</a>

```cpp
void utf8::advance (
    octet_iterator & it
    distance_type n
    octet_iterator end
)
```



### function <a id="1a75394fbfe91b1122e2602a6d73c5f612" href="#1a75394fbfe91b1122e2602a6d73c5f612">distance</a>

```cpp
std::iterator_traits< octet_iterator >::difference_type utf8::distance (
    octet_iterator first
    octet_iterator last
)
```



### function <a id="1acb68503442bd2e797e8fc8a960f54cf8" href="#1acb68503442bd2e797e8fc8a960f54cf8">utf16to8</a>

```cpp
octet_iterator utf8::utf16to8 (
    u16bit_iterator start
    u16bit_iterator end
    octet_iterator result
)
```



### function <a id="1a6404050074139c367a42f0a911779903" href="#1a6404050074139c367a42f0a911779903">utf8to16</a>

```cpp
u16bit_iterator utf8::utf8to16 (
    octet_iterator start
    octet_iterator end
    u16bit_iterator result
)
```



### function <a id="1a4a1157ef2f85d4bc8366dbbea20dcb48" href="#1a4a1157ef2f85d4bc8366dbbea20dcb48">utf32to8</a>

```cpp
octet_iterator utf8::utf32to8 (
    u32bit_iterator start
    u32bit_iterator end
    octet_iterator result
)
```



### function <a id="1a8020ed399788dca779663adf061ed718" href="#1a8020ed399788dca779663adf061ed718">utf8to32</a>

```cpp
u32bit_iterator utf8::utf8to32 (
    octet_iterator start
    octet_iterator end
    u32bit_iterator result
)
```



### function <a id="1ae29721faca762865e83ffea06605acc5" href="#1ae29721faca762865e83ffea06605acc5">find\_invalid</a>

```cpp
octet_iterator utf8::find_invalid (
    octet_iterator start
    octet_iterator end
)
```



### function <a id="1add2dbec3d058aa66500ec4f97cc8174b" href="#1add2dbec3d058aa66500ec4f97cc8174b">is\_valid</a>

```cpp
bool utf8::is_valid (
    octet_iterator start
    octet_iterator end
)
```



### function <a id="1a498c8e7d7a6fd92d4672ef05661dc783" href="#1a498c8e7d7a6fd92d4672ef05661dc783">starts\_with\_bom</a>

```cpp
bool utf8::starts_with_bom (
    octet_iterator it
    octet_iterator end
)
```



### function <a id="1aed9555bcddc0fd46296bf4e5642229ed" href="#1aed9555bcddc0fd46296bf4e5642229ed">is\_bom</a>

```cpp
bool utf8::is_bom (
    octet_iterator it
)
```





----------------------------------------
The documentation for this class was generated from the following file: `include/ffw/math/third\_party/utfcpp/checked.h`
