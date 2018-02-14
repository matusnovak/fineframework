internal
===================================


The documentation for this namespace was generated from: `include/ffw/math/third_party/utfcpp/core.h`



## Enums

| Type | Name |
| -------: | :------- |
| enum | [utf_error](#36ae6757) |


## Variables

| Type | Name |
| -------: | :------- |
|  const [uint16_t](utf8.html#d9fcfed7) | [LEAD_SURROGATE_MIN](#56d20a76) |
|  const [uint16_t](utf8.html#d9fcfed7) | [LEAD_SURROGATE_MAX](#51cb18e5) |
|  const [uint16_t](utf8.html#d9fcfed7) | [TRAIL_SURROGATE_MIN](#6e8bb644) |
|  const [uint16_t](utf8.html#d9fcfed7) | [TRAIL_SURROGATE_MAX](#7667357f) |
|  const [uint16_t](utf8.html#d9fcfed7) | [LEAD_OFFSET](#c9dbca5b) |
|  const [uint32_t](utf8.html#b52bf0b0) | [SURROGATE_OFFSET](#4376fd27) |
|  const [uint32_t](utf8.html#b52bf0b0) | [CODE_POINT_MAX](#5cb3ba8a) |


## Functions

| Type | Name |
| -------: | :------- |
|  [uint8_t](utf8.html#0bdd8ef4) | [mask8](#85e03792) (octet_type _oc_)  |
|  [uint16_t](utf8.html#d9fcfed7) | [mask16](#6c01f057) (u16_type _oc_)  |
|  bool | [is_trail](#ae5bc1f1) (octet_type _oc_)  |
|  bool | [is_lead_surrogate](#8730678d) (u16 _cp_)  |
|  bool | [is_trail_surrogate](#d615d55a) (u16 _cp_)  |
|  bool | [is_surrogate](#e777ceaf) (u16 _cp_)  |
|  bool | [is_code_point_valid](#63bd5651) (u32 _cp_)  |
|  std::iterator_traits< octet_iterator >::difference_type | [sequence_length](#cccaa23c) (octet_iterator _lead_it_)  |
|  bool | [is_overlong_sequence](#6951635e) ([uint32_t](utf8.html#b52bf0b0) _cp_, octet_difference_type _length_)  |
|  [utf_error](utf8_internal.html#36ae6757) | [increase_safely](#781b07be) (octet_iterator & _it_, octet_iterator _end_)  _Helper for get_sequence_x._ |
|  [utf_error](utf8_internal.html#36ae6757) | [get_sequence_1](#06b81195) (octet_iterator & _it_, octet_iterator _end_, [uint32_t](utf8.html#b52bf0b0) & _code_point_)  _get_sequence_x functions decode utf-8 sequences of the length x_ |
|  [utf_error](utf8_internal.html#36ae6757) | [get_sequence_2](#3252929d) (octet_iterator & _it_, octet_iterator _end_, [uint32_t](utf8.html#b52bf0b0) & _code_point_)  |
|  [utf_error](utf8_internal.html#36ae6757) | [get_sequence_3](#de60d48a) (octet_iterator & _it_, octet_iterator _end_, [uint32_t](utf8.html#b52bf0b0) & _code_point_)  |
|  [utf_error](utf8_internal.html#36ae6757) | [get_sequence_4](#39f6d2fa) (octet_iterator & _it_, octet_iterator _end_, [uint32_t](utf8.html#b52bf0b0) & _code_point_)  |
|  [utf_error](utf8_internal.html#36ae6757) | [validate_next](#82b9f1ec) (octet_iterator & _it_, octet_iterator _end_, [uint32_t](utf8.html#b52bf0b0) & _code_point_)  |
|  [utf_error](utf8_internal.html#36ae6757) | [validate_next](#76ad708c) (octet_iterator & _it_, octet_iterator _end_)  |


## Enums Documentation

### _enum_ <a id="36ae6757" href="#36ae6757">utf_error</a>

```cpp
enum utf_error {
    UTF8_OK,
    NOT_ENOUGH_ROOM,
    INVALID_LEAD,
    INCOMPLETE_SEQUENCE,
    OVERLONG_SEQUENCE,
    INVALID_CODE_POINT,
}
```





## Variables Documentation

### _variable_ <a id="56d20a76" href="#56d20a76">LEAD_SURROGATE_MIN</a>

```cpp
const uint16_t LEAD_SURROGATE_MIN
```



### _variable_ <a id="51cb18e5" href="#51cb18e5">LEAD_SURROGATE_MAX</a>

```cpp
const uint16_t LEAD_SURROGATE_MAX
```



### _variable_ <a id="6e8bb644" href="#6e8bb644">TRAIL_SURROGATE_MIN</a>

```cpp
const uint16_t TRAIL_SURROGATE_MIN
```



### _variable_ <a id="7667357f" href="#7667357f">TRAIL_SURROGATE_MAX</a>

```cpp
const uint16_t TRAIL_SURROGATE_MAX
```



### _variable_ <a id="c9dbca5b" href="#c9dbca5b">LEAD_OFFSET</a>

```cpp
const uint16_t LEAD_OFFSET
```



### _variable_ <a id="4376fd27" href="#4376fd27">SURROGATE_OFFSET</a>

```cpp
const uint32_t SURROGATE_OFFSET
```



### _variable_ <a id="5cb3ba8a" href="#5cb3ba8a">CODE_POINT_MAX</a>

```cpp
const uint32_t CODE_POINT_MAX
```





## Functions Documentation

### _function_ <a id="85e03792" href="#85e03792">mask8</a>

```cpp
inline uint8_t mask8 (
    octet_type oc
) 
```



### _function_ <a id="6c01f057" href="#6c01f057">mask16</a>

```cpp
inline uint16_t mask16 (
    u16_type oc
) 
```



### _function_ <a id="ae5bc1f1" href="#ae5bc1f1">is_trail</a>

```cpp
inline bool is_trail (
    octet_type oc
) 
```



### _function_ <a id="8730678d" href="#8730678d">is_lead_surrogate</a>

```cpp
inline bool is_lead_surrogate (
    u16 cp
) 
```



### _function_ <a id="d615d55a" href="#d615d55a">is_trail_surrogate</a>

```cpp
inline bool is_trail_surrogate (
    u16 cp
) 
```



### _function_ <a id="e777ceaf" href="#e777ceaf">is_surrogate</a>

```cpp
inline bool is_surrogate (
    u16 cp
) 
```



### _function_ <a id="63bd5651" href="#63bd5651">is_code_point_valid</a>

```cpp
inline bool is_code_point_valid (
    u32 cp
) 
```



### _function_ <a id="cccaa23c" href="#cccaa23c">sequence_length</a>

```cpp
inline std::iterator_traits< octet_iterator >::difference_type sequence_length (
    octet_iterator lead_it
) 
```



### _function_ <a id="6951635e" href="#6951635e">is_overlong_sequence</a>

```cpp
inline bool is_overlong_sequence (
    uint32_t cp,
    octet_difference_type length
) 
```



### _function_ <a id="781b07be" href="#781b07be">increase_safely</a>

```cpp
utf_error increase_safely (
    octet_iterator & it,
    octet_iterator end
) 
```

Helper for get_sequence_x. 

### _function_ <a id="06b81195" href="#06b81195">get_sequence_1</a>

```cpp
utf_error get_sequence_1 (
    octet_iterator & it,
    octet_iterator end,
    uint32_t & code_point
) 
```

get_sequence_x functions decode utf-8 sequences of the length x 

### _function_ <a id="3252929d" href="#3252929d">get_sequence_2</a>

```cpp
utf_error get_sequence_2 (
    octet_iterator & it,
    octet_iterator end,
    uint32_t & code_point
) 
```



### _function_ <a id="de60d48a" href="#de60d48a">get_sequence_3</a>

```cpp
utf_error get_sequence_3 (
    octet_iterator & it,
    octet_iterator end,
    uint32_t & code_point
) 
```



### _function_ <a id="39f6d2fa" href="#39f6d2fa">get_sequence_4</a>

```cpp
utf_error get_sequence_4 (
    octet_iterator & it,
    octet_iterator end,
    uint32_t & code_point
) 
```



### _function_ <a id="82b9f1ec" href="#82b9f1ec">validate_next</a>

```cpp
utf_error validate_next (
    octet_iterator & it,
    octet_iterator end,
    uint32_t & code_point
) 
```



### _function_ <a id="76ad708c" href="#76ad708c">validate_next</a>

```cpp
inline utf_error validate_next (
    octet_iterator & it,
    octet_iterator end
) 
```





