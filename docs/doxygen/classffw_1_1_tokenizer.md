---
search: false
---

# class ffw::Tokenizer

## Public Functions

|Type|Name|
|-----|-----|
||[**Tokenizer**](classffw_1_1_tokenizer.md#1a1f6453d6fc7a1c2c4792e335934ae1ae) (const std::basic\_string< T, CharTrait, Allocator > & str, const std::basic\_string< T, CharTrait, Allocator > & delim) |
|bool|[**getNext**](classffw_1_1_tokenizer.md#1afcf4a1e39fd931dc73217cf5dcff0cc4) (std::basic\_string< T, CharTrait, Allocator > \* str) |
|std::basic\_string< T, CharTrait, Allocator >|[**getNext**](classffw_1_1_tokenizer.md#1affb9ce1ed657c999d874bb5d610292a7) () |
|bool|[**skipNext**](classffw_1_1_tokenizer.md#1a32c13aac4930a717012eaa2526906e99) () |
|bool|[**hasNext**](classffw_1_1_tokenizer.md#1a84f4871708537a1328685807b7f1c874) () |
|size\_t|[**getPos**](classffw_1_1_tokenizer.md#1a26e3ad8b5ef416cc07516caf58412be6) () |


## Public Functions Documentation

### function <a id="1a1f6453d6fc7a1c2c4792e335934ae1ae" href="#1a1f6453d6fc7a1c2c4792e335934ae1ae">Tokenizer</a>

```cpp
ffw::Tokenizer::Tokenizer (
    const std::basic_string< T, CharTrait, Allocator > & str
    const std::basic_string< T, CharTrait, Allocator > & delim
)
```



### function <a id="1afcf4a1e39fd931dc73217cf5dcff0cc4" href="#1afcf4a1e39fd931dc73217cf5dcff0cc4">getNext</a>

```cpp
bool ffw::Tokenizer::getNext (
    std::basic_string< T, CharTrait, Allocator > * str
)
```



### function <a id="1affb9ce1ed657c999d874bb5d610292a7" href="#1affb9ce1ed657c999d874bb5d610292a7">getNext</a>

```cpp
std::basic_string< T, CharTrait, Allocator > ffw::Tokenizer::getNext ()
```



### function <a id="1a32c13aac4930a717012eaa2526906e99" href="#1a32c13aac4930a717012eaa2526906e99">skipNext</a>

```cpp
bool ffw::Tokenizer::skipNext ()
```



### function <a id="1a84f4871708537a1328685807b7f1c874" href="#1a84f4871708537a1328685807b7f1c874">hasNext</a>

```cpp
bool ffw::Tokenizer::hasNext ()
```



### function <a id="1a26e3ad8b5ef416cc07516caf58412be6" href="#1a26e3ad8b5ef416cc07516caf58412be6">getPos</a>

```cpp
size_t ffw::Tokenizer::getPos ()
```





----------------------------------------
The documentation for this class was generated from the following file: `include/ffw/math/tokenizer.h`
