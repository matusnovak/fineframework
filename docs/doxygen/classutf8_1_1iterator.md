---
search: false
---

# class utf8::iterator



Inherits the following classes: **std::iterator< std::bidirectional\_iterator\_tag, uint32\_t >**

## Public Functions

|Type|Name|
|-----|-----|
||[**iterator**](classutf8_1_1iterator.md#1a507000943ac3fdfe59331dac3c35c6bd) () |
||[**iterator**](classutf8_1_1iterator.md#1ae94b26da21b80560a1507fc8d2178fd7) (const octet\_iterator & octet\_it, const octet\_iterator & rangestart, const octet\_iterator & rangeend) |
|octet\_iterator|[**base**](classutf8_1_1iterator.md#1aec700ec9689fe88ebe9a7fe1feca8d2d) () const |
|**[uint32\_t](namespaceutf8.md#1a846259d2f173d524282583fc9d825b00)**|[**operator\***](classutf8_1_1iterator.md#1abbe7cf79cc5b78a375d80b0dba39fa0c) () const |
|bool|[**operator==**](classutf8_1_1iterator.md#1a0527930d64be7835f881bf649a317cfb) (const **[iterator](classutf8_1_1iterator.md)** & rhs) const |
|bool|[**operator!=**](classutf8_1_1iterator.md#1a6be99d96bf62e7e0d9f1bdc1841efb3c) (const **[iterator](classutf8_1_1iterator.md)** & rhs) const |
|**[iterator](classutf8_1_1iterator.md)** &|[**operator++**](classutf8_1_1iterator.md#1a93e9ac16a560fab545a05efb6b0a3add) () |
|**[iterator](classutf8_1_1iterator.md)**|[**operator++**](classutf8_1_1iterator.md#1aa21c39e32e3bf53c08d8ee5cde280671) (int) |
|**[iterator](classutf8_1_1iterator.md)** &|[**operator--**](classutf8_1_1iterator.md#1a7781099a85323b5a3ff4dc1015ca5af0) () |
|**[iterator](classutf8_1_1iterator.md)**|[**operator--**](classutf8_1_1iterator.md#1afc228985ba672a6b6966ea0a705a4755) (int) |


## Public Functions Documentation

### function <a id="1a507000943ac3fdfe59331dac3c35c6bd" href="#1a507000943ac3fdfe59331dac3c35c6bd">iterator</a>

```cpp
utf8::iterator::iterator ()
```



### function <a id="1ae94b26da21b80560a1507fc8d2178fd7" href="#1ae94b26da21b80560a1507fc8d2178fd7">iterator</a>

```cpp
explicit utf8::iterator::iterator (
    const octet_iterator & octet_it,
    const octet_iterator & rangestart,
    const octet_iterator & rangeend
)
```



### function <a id="1aec700ec9689fe88ebe9a7fe1feca8d2d" href="#1aec700ec9689fe88ebe9a7fe1feca8d2d">base</a>

```cpp
octet_iterator utf8::iterator::base () const
```



### function <a id="1abbe7cf79cc5b78a375d80b0dba39fa0c" href="#1abbe7cf79cc5b78a375d80b0dba39fa0c">operator\*</a>

```cpp
uint32_t utf8::iterator::operator* () const
```



### function <a id="1a0527930d64be7835f881bf649a317cfb" href="#1a0527930d64be7835f881bf649a317cfb">operator==</a>

```cpp
bool utf8::iterator::operator== (
    const iterator & rhs
) const
```



### function <a id="1a6be99d96bf62e7e0d9f1bdc1841efb3c" href="#1a6be99d96bf62e7e0d9f1bdc1841efb3c">operator!=</a>

```cpp
bool utf8::iterator::operator!= (
    const iterator & rhs
) const
```



### function <a id="1a93e9ac16a560fab545a05efb6b0a3add" href="#1a93e9ac16a560fab545a05efb6b0a3add">operator++</a>

```cpp
iterator & utf8::iterator::operator++ ()
```



### function <a id="1aa21c39e32e3bf53c08d8ee5cde280671" href="#1aa21c39e32e3bf53c08d8ee5cde280671">operator++</a>

```cpp
iterator utf8::iterator::operator++ (
    int 
)
```



### function <a id="1a7781099a85323b5a3ff4dc1015ca5af0" href="#1a7781099a85323b5a3ff4dc1015ca5af0">operator--</a>

```cpp
iterator & utf8::iterator::operator-- ()
```



### function <a id="1afc228985ba672a6b6966ea0a705a4755" href="#1afc228985ba672a6b6966ea0a705a4755">operator--</a>

```cpp
iterator utf8::iterator::operator-- (
    int 
)
```





----------------------------------------
The documentation for this class was generated from the following file: `include/ffw/math/third\_party/utfcpp/checked.h`
