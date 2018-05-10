---
search: false
---

# namespace utf8::internal

## Enums

|Type|Name|
|-----|-----|
|enum|[**utf\_error**](namespaceutf8_1_1internal.md#1a9e96c2bc98b37e336b787a281090392c) { **UTF8\_OK**, **NOT\_ENOUGH\_ROOM**, **INVALID\_LEAD**, **INCOMPLETE\_SEQUENCE**, **OVERLONG\_SEQUENCE**, **INVALID\_CODE\_POINT** } |


## Variables

|Type|Name|
|-----|-----|
|const **[uint16\_t](namespaceutf8.md#1ac23066b92c5a1d9d9ef177201f750936)**|[**LEAD\_SURROGATE\_MIN**](namespaceutf8_1_1internal.md#1aca9d84aa3b40e635b086c9ce843cc4a4)|
|const **[uint16\_t](namespaceutf8.md#1ac23066b92c5a1d9d9ef177201f750936)**|[**LEAD\_SURROGATE\_MAX**](namespaceutf8_1_1internal.md#1af6038b4ebd9b71391eba050cc29720b8)|
|const **[uint16\_t](namespaceutf8.md#1ac23066b92c5a1d9d9ef177201f750936)**|[**TRAIL\_SURROGATE\_MIN**](namespaceutf8_1_1internal.md#1a836088cf3e5e29ac9a89b2ffbd91623e)|
|const **[uint16\_t](namespaceutf8.md#1ac23066b92c5a1d9d9ef177201f750936)**|[**TRAIL\_SURROGATE\_MAX**](namespaceutf8_1_1internal.md#1a37212482f99986fc6aeaa95a9079c972)|
|const **[uint16\_t](namespaceutf8.md#1ac23066b92c5a1d9d9ef177201f750936)**|[**LEAD\_OFFSET**](namespaceutf8_1_1internal.md#1a47b04bad75525ea9b01ff095c70fa081)|
|const **[uint32\_t](namespaceutf8.md#1a846259d2f173d524282583fc9d825b00)**|[**SURROGATE\_OFFSET**](namespaceutf8_1_1internal.md#1a31ff17e602e8e7e15db5ebfb5e93a3fb)|
|const **[uint32\_t](namespaceutf8.md#1a846259d2f173d524282583fc9d825b00)**|[**CODE\_POINT\_MAX**](namespaceutf8_1_1internal.md#1a0a30055cabb6e5cefb5dafc8812cb123)|


## Functions

|Type|Name|
|-----|-----|
|**[uint8\_t](namespaceutf8.md#1abe793b552fabe390d134b97ab81d2c7f)**|[**mask8**](namespaceutf8_1_1internal.md#1adf6e0469e279b9562aa461b4c3c1e7e4) (octet\_type oc) |
|**[uint16\_t](namespaceutf8.md#1ac23066b92c5a1d9d9ef177201f750936)**|[**mask16**](namespaceutf8_1_1internal.md#1ab1e3c2fe2296ac185993a183d1bd0678) (u16\_type oc) |
|bool|[**is\_trail**](namespaceutf8_1_1internal.md#1ab4820484159ba613b4901476ceb24516) (octet\_type oc) |
|bool|[**is\_lead\_surrogate**](namespaceutf8_1_1internal.md#1a1a4095fb207096e04f94f21eb23d2723) (u16 cp) |
|bool|[**is\_trail\_surrogate**](namespaceutf8_1_1internal.md#1a295b2873fce985213937e5f1193fcb13) (u16 cp) |
|bool|[**is\_surrogate**](namespaceutf8_1_1internal.md#1a31a185a6bc8b9bf454191a8a95a93595) (u16 cp) |
|bool|[**is\_code\_point\_valid**](namespaceutf8_1_1internal.md#1a97b553137aaeda6e8ca6f8d46f78fd79) (u32 cp) |
|std::iterator\_traits< octet\_iterator >::difference\_type|[**sequence\_length**](namespaceutf8_1_1internal.md#1aadbe437cba7bfcc4df2638f633e9787c) (octet\_iterator lead\_it) |
|bool|[**is\_overlong\_sequence**](namespaceutf8_1_1internal.md#1a3160f6f24dff465f64f83cb0e66995c6) (**[uint32\_t](namespaceutf8.md#1a846259d2f173d524282583fc9d825b00)** cp, octet\_difference\_type length) |
|**[utf\_error](namespaceutf8_1_1internal.md#1a9e96c2bc98b37e336b787a281090392c)**|[**increase\_safely**](namespaceutf8_1_1internal.md#1a369641e705a3d7c91eb160868a6705f7) (octet\_iterator & it, octet\_iterator end) <br>Helper for get\_sequence\_x. |
|**[utf\_error](namespaceutf8_1_1internal.md#1a9e96c2bc98b37e336b787a281090392c)**|[**get\_sequence\_1**](namespaceutf8_1_1internal.md#1a6e5df73716136aec55e8fcf3309038b6) (octet\_iterator & it, octet\_iterator end, **[uint32\_t](namespaceutf8.md#1a846259d2f173d524282583fc9d825b00)** & code\_point) <br>get\_sequence\_x functions decode utf-8 sequences of the length x |
|**[utf\_error](namespaceutf8_1_1internal.md#1a9e96c2bc98b37e336b787a281090392c)**|[**get\_sequence\_2**](namespaceutf8_1_1internal.md#1a9d641b9546be985f9f0fd4955ac42a24) (octet\_iterator & it, octet\_iterator end, **[uint32\_t](namespaceutf8.md#1a846259d2f173d524282583fc9d825b00)** & code\_point) |
|**[utf\_error](namespaceutf8_1_1internal.md#1a9e96c2bc98b37e336b787a281090392c)**|[**get\_sequence\_3**](namespaceutf8_1_1internal.md#1ac1809a1fb3fa6983d64a0d3a39646008) (octet\_iterator & it, octet\_iterator end, **[uint32\_t](namespaceutf8.md#1a846259d2f173d524282583fc9d825b00)** & code\_point) |
|**[utf\_error](namespaceutf8_1_1internal.md#1a9e96c2bc98b37e336b787a281090392c)**|[**get\_sequence\_4**](namespaceutf8_1_1internal.md#1ad1958e7c6746ba6b1fbb0d81b88b346c) (octet\_iterator & it, octet\_iterator end, **[uint32\_t](namespaceutf8.md#1a846259d2f173d524282583fc9d825b00)** & code\_point) |
|**[utf\_error](namespaceutf8_1_1internal.md#1a9e96c2bc98b37e336b787a281090392c)**|[**validate\_next**](namespaceutf8_1_1internal.md#1abe95547575fcc81911e381df03f8ebfe) (octet\_iterator & it, octet\_iterator end, **[uint32\_t](namespaceutf8.md#1a846259d2f173d524282583fc9d825b00)** & code\_point) |
|**[utf\_error](namespaceutf8_1_1internal.md#1a9e96c2bc98b37e336b787a281090392c)**|[**validate\_next**](namespaceutf8_1_1internal.md#1afd41668f94ce9f60f8e314d05804cecc) (octet\_iterator & it, octet\_iterator end) |


## Enums Documentation

### enum <a id="1a9e96c2bc98b37e336b787a281090392c" href="#1a9e96c2bc98b37e336b787a281090392c">utf\_error</a>

```cpp
enum utf8::internal::utf_error {
    UTF8_OK,
    NOT_ENOUGH_ROOM,
    INVALID_LEAD,
    INCOMPLETE_SEQUENCE,
    OVERLONG_SEQUENCE,
    INVALID_CODE_POINT,
};
```



## Variables Documentation

### variable <a id="1aca9d84aa3b40e635b086c9ce843cc4a4" href="#1aca9d84aa3b40e635b086c9ce843cc4a4">LEAD\_SURROGATE\_MIN</a>

```cpp
const uint16_t utf8::internal::LEAD_SURROGATE_MIN;
```



### variable <a id="1af6038b4ebd9b71391eba050cc29720b8" href="#1af6038b4ebd9b71391eba050cc29720b8">LEAD\_SURROGATE\_MAX</a>

```cpp
const uint16_t utf8::internal::LEAD_SURROGATE_MAX;
```



### variable <a id="1a836088cf3e5e29ac9a89b2ffbd91623e" href="#1a836088cf3e5e29ac9a89b2ffbd91623e">TRAIL\_SURROGATE\_MIN</a>

```cpp
const uint16_t utf8::internal::TRAIL_SURROGATE_MIN;
```



### variable <a id="1a37212482f99986fc6aeaa95a9079c972" href="#1a37212482f99986fc6aeaa95a9079c972">TRAIL\_SURROGATE\_MAX</a>

```cpp
const uint16_t utf8::internal::TRAIL_SURROGATE_MAX;
```



### variable <a id="1a47b04bad75525ea9b01ff095c70fa081" href="#1a47b04bad75525ea9b01ff095c70fa081">LEAD\_OFFSET</a>

```cpp
const uint16_t utf8::internal::LEAD_OFFSET;
```



### variable <a id="1a31ff17e602e8e7e15db5ebfb5e93a3fb" href="#1a31ff17e602e8e7e15db5ebfb5e93a3fb">SURROGATE\_OFFSET</a>

```cpp
const uint32_t utf8::internal::SURROGATE_OFFSET;
```



### variable <a id="1a0a30055cabb6e5cefb5dafc8812cb123" href="#1a0a30055cabb6e5cefb5dafc8812cb123">CODE\_POINT\_MAX</a>

```cpp
const uint32_t utf8::internal::CODE_POINT_MAX;
```



## Functions Documentation

### function <a id="1adf6e0469e279b9562aa461b4c3c1e7e4" href="#1adf6e0469e279b9562aa461b4c3c1e7e4">mask8</a>

```cpp
uint8_t utf8::internal::mask8 (
    octet_type oc
)
```



### function <a id="1ab1e3c2fe2296ac185993a183d1bd0678" href="#1ab1e3c2fe2296ac185993a183d1bd0678">mask16</a>

```cpp
uint16_t utf8::internal::mask16 (
    u16_type oc
)
```



### function <a id="1ab4820484159ba613b4901476ceb24516" href="#1ab4820484159ba613b4901476ceb24516">is\_trail</a>

```cpp
bool utf8::internal::is_trail (
    octet_type oc
)
```



### function <a id="1a1a4095fb207096e04f94f21eb23d2723" href="#1a1a4095fb207096e04f94f21eb23d2723">is\_lead\_surrogate</a>

```cpp
bool utf8::internal::is_lead_surrogate (
    u16 cp
)
```



### function <a id="1a295b2873fce985213937e5f1193fcb13" href="#1a295b2873fce985213937e5f1193fcb13">is\_trail\_surrogate</a>

```cpp
bool utf8::internal::is_trail_surrogate (
    u16 cp
)
```



### function <a id="1a31a185a6bc8b9bf454191a8a95a93595" href="#1a31a185a6bc8b9bf454191a8a95a93595">is\_surrogate</a>

```cpp
bool utf8::internal::is_surrogate (
    u16 cp
)
```



### function <a id="1a97b553137aaeda6e8ca6f8d46f78fd79" href="#1a97b553137aaeda6e8ca6f8d46f78fd79">is\_code\_point\_valid</a>

```cpp
bool utf8::internal::is_code_point_valid (
    u32 cp
)
```



### function <a id="1aadbe437cba7bfcc4df2638f633e9787c" href="#1aadbe437cba7bfcc4df2638f633e9787c">sequence\_length</a>

```cpp
std::iterator_traits< octet_iterator >::difference_type utf8::internal::sequence_length (
    octet_iterator lead_it
)
```



### function <a id="1a3160f6f24dff465f64f83cb0e66995c6" href="#1a3160f6f24dff465f64f83cb0e66995c6">is\_overlong\_sequence</a>

```cpp
bool utf8::internal::is_overlong_sequence (
    uint32_t cp
    octet_difference_type length
)
```



### function <a id="1a369641e705a3d7c91eb160868a6705f7" href="#1a369641e705a3d7c91eb160868a6705f7">increase\_safely</a>

```cpp
utf_error utf8::internal::increase_safely (
    octet_iterator & it
    octet_iterator end
)
```

Helper for get\_sequence\_x. 


### function <a id="1a6e5df73716136aec55e8fcf3309038b6" href="#1a6e5df73716136aec55e8fcf3309038b6">get\_sequence\_1</a>

```cpp
utf_error utf8::internal::get_sequence_1 (
    octet_iterator & it
    octet_iterator end
    uint32_t & code_point
)
```

get\_sequence\_x functions decode utf-8 sequences of the length x 


### function <a id="1a9d641b9546be985f9f0fd4955ac42a24" href="#1a9d641b9546be985f9f0fd4955ac42a24">get\_sequence\_2</a>

```cpp
utf_error utf8::internal::get_sequence_2 (
    octet_iterator & it
    octet_iterator end
    uint32_t & code_point
)
```



### function <a id="1ac1809a1fb3fa6983d64a0d3a39646008" href="#1ac1809a1fb3fa6983d64a0d3a39646008">get\_sequence\_3</a>

```cpp
utf_error utf8::internal::get_sequence_3 (
    octet_iterator & it
    octet_iterator end
    uint32_t & code_point
)
```



### function <a id="1ad1958e7c6746ba6b1fbb0d81b88b346c" href="#1ad1958e7c6746ba6b1fbb0d81b88b346c">get\_sequence\_4</a>

```cpp
utf_error utf8::internal::get_sequence_4 (
    octet_iterator & it
    octet_iterator end
    uint32_t & code_point
)
```



### function <a id="1abe95547575fcc81911e381df03f8ebfe" href="#1abe95547575fcc81911e381df03f8ebfe">validate\_next</a>

```cpp
utf_error utf8::internal::validate_next (
    octet_iterator & it
    octet_iterator end
    uint32_t & code_point
)
```



### function <a id="1afd41668f94ce9f60f8e314d05804cecc" href="#1afd41668f94ce9f60f8e314d05804cecc">validate\_next</a>

```cpp
utf_error utf8::internal::validate_next (
    octet_iterator & it
    octet_iterator end
)
```





----------------------------------------
The documentation for this class was generated from the following file: `include/ffw/math/third\_party/utfcpp/core.h`
