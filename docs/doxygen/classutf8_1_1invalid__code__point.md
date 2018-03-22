---
search:
    keywords: ['utf8::invalid_code_point', 'invalid_code_point', 'what', 'code_point']
---

# class utf8::invalid\_code\_point



Inherits the following classes: **[utf8::exception](classutf8_1_1exception.md)**

## Public Functions

|Type|Name|
|-----|-----|
||[**invalid\_code\_point**](classutf8_1_1invalid__code__point.md#1a98b38215537157dc782b4efc9335c124) (**[uint32\_t](namespaceutf8.md#1a846259d2f173d524282583fc9d825b00)** codepoint) |
|virtual const char \*|[**what**](classutf8_1_1invalid__code__point.md#1ada45ed42142e57e7e1693bbac6985dce) () const |
|**[uint32\_t](namespaceutf8.md#1a846259d2f173d524282583fc9d825b00)**|[**code\_point**](classutf8_1_1invalid__code__point.md#1a07539c0ef6aa826178f56b9d53d475af) () const |


## Public Functions Documentation

### function <a id="1a98b38215537157dc782b4efc9335c124" href="#1a98b38215537157dc782b4efc9335c124">invalid\_code\_point</a>

```cpp
utf8::invalid_code_point::invalid_code_point (
    uint32_t codepoint
)
```



### function <a id="1ada45ed42142e57e7e1693bbac6985dce" href="#1ada45ed42142e57e7e1693bbac6985dce">what</a>

```cpp
virtual const char * utf8::invalid_code_point::what () const
```



### function <a id="1a07539c0ef6aa826178f56b9d53d475af" href="#1a07539c0ef6aa826178f56b9d53d475af">code\_point</a>

```cpp
uint32_t utf8::invalid_code_point::code_point () const
```





----------------------------------------
The documentation for this class was generated from the following file: `include/ffw/math/third\_party/utfcpp/checked.h`
