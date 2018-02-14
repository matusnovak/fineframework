utf8
===================================


The documentation for this namespace was generated from: `include/ffw/math/third_party/utfcpp/checked.h`



## Classes

| Name |
|:-----|
| class [utf8::exception](utf8_exception.html) |
| class [utf8::invalid_code_point](utf8_invalid_code_point.html) |
| class [utf8::invalid_utf16](utf8_invalid_utf16.html) |
| class [utf8::invalid_utf8](utf8_invalid_utf8.html) |
| class [utf8::iterator](utf8_iterator.html) |
| class [utf8::not_enough_room](utf8_not_enough_room.html) |


## Typedefs

| Type | Name |
| -------: | :------- |
| typedef unsigned char | [uint8_t](#0bdd8ef4) |
| typedef unsigned short | [uint16_t](#d9fcfed7) |
| typedef unsigned int | [uint32_t](#b52bf0b0) |


## Variables

| Type | Name |
| -------: | :------- |
|  const [uint8_t](utf8.html#0bdd8ef4) | [bom](#31f791c7) _The library API - functions intended to be called by the users._ |


## Functions

| Type | Name |
| -------: | :------- |
|  octet_iterator | [append](#776c2779) ([uint32_t](utf8.html#b52bf0b0) _cp_, octet_iterator _result_)  _The library API - functions intended to be called by the users._ |
|  output_iterator | [replace_invalid](#0778c2ab) (octet_iterator _start_, octet_iterator _end_, output_iterator _out_, [uint32_t](utf8.html#b52bf0b0) _replacement_)  |
|  output_iterator | [replace_invalid](#f54ec9e6) (octet_iterator _start_, octet_iterator _end_, output_iterator _out_)  |
|  [uint32_t](utf8.html#b52bf0b0) | [next](#fe9a070d) (octet_iterator & _it_, octet_iterator _end_)  |
|  [uint32_t](utf8.html#b52bf0b0) | [peek_next](#a6afa314) (octet_iterator _it_, octet_iterator _end_)  |
|  [uint32_t](utf8.html#b52bf0b0) | [prior](#ac5e506a) (octet_iterator & _it_, octet_iterator _start_)  |
|  [uint32_t](utf8.html#b52bf0b0) | [previous](#d3e044b4) (octet_iterator & _it_, octet_iterator _pass_start_)  _Deprecated in versions that include "prior"._ |
|  void | [advance](#f6be57ae) (octet_iterator & _it_, distance_type _n_, octet_iterator _end_)  |
|  std::iterator_traits< octet_iterator >::difference_type | [distance](#fe3dc873) (octet_iterator _first_, octet_iterator _last_)  |
|  octet_iterator | [utf16to8](#2ae8f673) (u16bit_iterator _start_, u16bit_iterator _end_, octet_iterator _result_)  |
|  u16bit_iterator | [utf8to16](#eb61aac1) (octet_iterator _start_, octet_iterator _end_, u16bit_iterator _result_)  |
|  octet_iterator | [utf32to8](#e1e205e4) (u32bit_iterator _start_, u32bit_iterator _end_, octet_iterator _result_)  |
|  u32bit_iterator | [utf8to32](#45537799) (octet_iterator _start_, octet_iterator _end_, u32bit_iterator _result_)  |
|  octet_iterator | [find_invalid](#65a40472) (octet_iterator _start_, octet_iterator _end_)  |
|  bool | [is_valid](#7b21e29d) (octet_iterator _start_, octet_iterator _end_)  |
|  bool | [starts_with_bom](#7ac21984) (octet_iterator _it_, octet_iterator _end_)  |
|  bool | [is_bom](#72547da1) (octet_iterator _it_)  |


## Typedefs Documentation

### _typedef_ <a id="0bdd8ef4" href="#0bdd8ef4">uint8_t</a>

```cpp
unsigned char uint8_t
```



### _typedef_ <a id="d9fcfed7" href="#d9fcfed7">uint16_t</a>

```cpp
unsigned short uint16_t
```



### _typedef_ <a id="b52bf0b0" href="#b52bf0b0">uint32_t</a>

```cpp
unsigned int uint32_t
```





## Variables Documentation

### _variable_ <a id="31f791c7" href="#31f791c7">bom</a>

```cpp
const uint8_t bom
```

The library API - functions intended to be called by the users. 



## Functions Documentation

### _function_ <a id="776c2779" href="#776c2779">append</a>

```cpp
octet_iterator append (
    uint32_t cp,
    octet_iterator result
) 
```

The library API - functions intended to be called by the users. 

### _function_ <a id="0778c2ab" href="#0778c2ab">replace_invalid</a>

```cpp
output_iterator replace_invalid (
    octet_iterator start,
    octet_iterator end,
    output_iterator out,
    uint32_t replacement
) 
```



### _function_ <a id="f54ec9e6" href="#f54ec9e6">replace_invalid</a>

```cpp
inline output_iterator replace_invalid (
    octet_iterator start,
    octet_iterator end,
    output_iterator out
) 
```



### _function_ <a id="fe9a070d" href="#fe9a070d">next</a>

```cpp
uint32_t next (
    octet_iterator & it,
    octet_iterator end
) 
```



### _function_ <a id="a6afa314" href="#a6afa314">peek_next</a>

```cpp
uint32_t peek_next (
    octet_iterator it,
    octet_iterator end
) 
```



### _function_ <a id="ac5e506a" href="#ac5e506a">prior</a>

```cpp
uint32_t prior (
    octet_iterator & it,
    octet_iterator start
) 
```



### _function_ <a id="d3e044b4" href="#d3e044b4">previous</a>

```cpp
uint32_t previous (
    octet_iterator & it,
    octet_iterator pass_start
) 
```

Deprecated in versions that include "prior". 

### _function_ <a id="f6be57ae" href="#f6be57ae">advance</a>

```cpp
void advance (
    octet_iterator & it,
    distance_type n,
    octet_iterator end
) 
```



### _function_ <a id="fe3dc873" href="#fe3dc873">distance</a>

```cpp
std::iterator_traits< octet_iterator >::difference_type distance (
    octet_iterator first,
    octet_iterator last
) 
```



### _function_ <a id="2ae8f673" href="#2ae8f673">utf16to8</a>

```cpp
octet_iterator utf16to8 (
    u16bit_iterator start,
    u16bit_iterator end,
    octet_iterator result
) 
```



### _function_ <a id="eb61aac1" href="#eb61aac1">utf8to16</a>

```cpp
u16bit_iterator utf8to16 (
    octet_iterator start,
    octet_iterator end,
    u16bit_iterator result
) 
```



### _function_ <a id="e1e205e4" href="#e1e205e4">utf32to8</a>

```cpp
octet_iterator utf32to8 (
    u32bit_iterator start,
    u32bit_iterator end,
    octet_iterator result
) 
```



### _function_ <a id="45537799" href="#45537799">utf8to32</a>

```cpp
u32bit_iterator utf8to32 (
    octet_iterator start,
    octet_iterator end,
    u32bit_iterator result
) 
```



### _function_ <a id="65a40472" href="#65a40472">find_invalid</a>

```cpp
octet_iterator find_invalid (
    octet_iterator start,
    octet_iterator end
) 
```



### _function_ <a id="7b21e29d" href="#7b21e29d">is_valid</a>

```cpp
inline bool is_valid (
    octet_iterator start,
    octet_iterator end
) 
```



### _function_ <a id="7ac21984" href="#7ac21984">starts_with_bom</a>

```cpp
inline bool starts_with_bom (
    octet_iterator it,
    octet_iterator end
) 
```



### _function_ <a id="72547da1" href="#72547da1">is_bom</a>

```cpp
inline bool is_bom (
    octet_iterator it
) 
```





