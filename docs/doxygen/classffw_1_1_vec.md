---
search: false
---

# class ffw::Vec

## Public Attributes

|Type|Name|
|-----|-----|
|std::array< T, S >|[**arr**](classffw_1_1_vec.md#1a2613a3bff3371de1a8a1d86d8354bab1)|


## Public Functions

|Type|Name|
|-----|-----|
||[**Vec**](classffw_1_1_vec.md#1adeda8c8f02a8f7feb45c1548ce039d55) () |
||[**Vec**](classffw_1_1_vec.md#1ae683f4da74c401a287b8cc0f43043932) (T val) |
||[**Vec**](classffw_1_1_vec.md#1af995c7138c0b15a1de04758444f73735) (const std::initializer\_list< T > & list) |
||[**Vec**](classffw_1_1_vec.md#1aee3de3fbc3c5c4e98d93017207faad1b) (const **[Vec](classffw_1_1_vec.md)**< T, S > & other) |
||[**Vec**](classffw_1_1_vec.md#1ae69fe968ddc4ffdfc41d380e6c1119d9) (**[Vec](classffw_1_1_vec.md)**< T, S > && other) |
|void|[**set**](classffw_1_1_vec.md#1aaf4d3f54a98b90954423777278f58cb2) (T val) |
|void|[**set**](classffw_1_1_vec.md#1ae35feb3753c6b74a067850950430b531) (const std::initializer\_list< T > & list) |
|void|[**set**](classffw_1_1_vec.md#1a6b2ee6bf09bb11bc5f2dcf9383196b2f) (const **[Vec](classffw_1_1_vec.md)**< T, S > & other) |
|**[ffw::Vec](classffw_1_1_vec.md)**< T, S >|[**operator-**](classffw_1_1_vec.md#1a1917448e90cda6bff9998f9d03b37e46) () const |
|**[ffw::Vec](classffw_1_1_vec.md)**< T, S > &|[**operator=**](classffw_1_1_vec.md#1a4187d67af4f61d878fa870fdc19ef9b4) (const **[Vec](classffw_1_1_vec.md)**< T, S > & vec) |
|**[ffw::Vec](classffw_1_1_vec.md)**< T, S >|[**operator+**](classffw_1_1_vec.md#1a281c39f2e2604a883b507fa2bd1c9f2c) (const **[Vec](classffw_1_1_vec.md)**< T, S > & vec) const |
|**[ffw::Vec](classffw_1_1_vec.md)**< T, S > &|[**operator+=**](classffw_1_1_vec.md#1a88ef256281477075b8ba03dd9f489e9b) (const **[Vec](classffw_1_1_vec.md)**< T, S > & vec) |
|**[ffw::Vec](classffw_1_1_vec.md)**< T, S >|[**operator-**](classffw_1_1_vec.md#1a326558a3d6199f4988480832006b4241) (const **[Vec](classffw_1_1_vec.md)**< T, S > & vec) const |
|**[ffw::Vec](classffw_1_1_vec.md)**< T, S > &|[**operator-=**](classffw_1_1_vec.md#1a9a543e17ed42df9ac1cc588eb75673aa) (const **[Vec](classffw_1_1_vec.md)**< T, S > & vec) |
|**[ffw::Vec](classffw_1_1_vec.md)**< T, S >|[**operator/**](classffw_1_1_vec.md#1aee50010ba1b4410ca52b659648a28e34) (const **[Vec](classffw_1_1_vec.md)**< T, S > & vec) const |
|**[ffw::Vec](classffw_1_1_vec.md)**< T, S > &|[**operator/=**](classffw_1_1_vec.md#1a650aed6f4314bab9dba7697541f89d00) (const **[Vec](classffw_1_1_vec.md)**< T, S > & vec) |
|**[ffw::Vec](classffw_1_1_vec.md)**< T, S >|[**operator\***](classffw_1_1_vec.md#1aa1033b4f471a6d241b8d42fa1a7eca37) (const **[Vec](classffw_1_1_vec.md)**< T, S > & vec) const |
|**[ffw::Vec](classffw_1_1_vec.md)**< T, S > &|[**operator\*=**](classffw_1_1_vec.md#1aea8e2369b1e565e1d55d34f422c055fd) (const **[Vec](classffw_1_1_vec.md)**< T, S > & vec) |
|**[ffw::Vec](classffw_1_1_vec.md)**< T, S > &|[**operator=**](classffw_1_1_vec.md#1a3555b92474436ab56d8a478910087e43) (const T & val) |
|**[ffw::Vec](classffw_1_1_vec.md)**< T, S >|[**operator+**](classffw_1_1_vec.md#1a9acf96a2358328752230e61c5d14203b) (const T & val) const |
|**[ffw::Vec](classffw_1_1_vec.md)**< T, S > &|[**operator+=**](classffw_1_1_vec.md#1a2a19aa7485050ffa6a412feed4c69a98) (const T & val) |
|**[ffw::Vec](classffw_1_1_vec.md)**< T, S >|[**operator-**](classffw_1_1_vec.md#1a54bd2c4e3cb32ad163c0c76e2aaa68be) (const T & val) const |
|**[ffw::Vec](classffw_1_1_vec.md)**< T, S > &|[**operator-=**](classffw_1_1_vec.md#1a381fcf15a3f6b8f99af5dc5cafd86b44) (const T & val) |
|**[ffw::Vec](classffw_1_1_vec.md)**< T, S >|[**operator/**](classffw_1_1_vec.md#1a7923985a60959a9651bb027fe6a6cce8) (const T & val) const |
|**[ffw::Vec](classffw_1_1_vec.md)**< T, S > &|[**operator/=**](classffw_1_1_vec.md#1a99aa03d4170a138baee70575b977aab0) (const T & val) |
|**[ffw::Vec](classffw_1_1_vec.md)**< T, S >|[**operator\***](classffw_1_1_vec.md#1ab56e64253b4a4a886000f60d64d9692e) (const T & val) const |
|**[ffw::Vec](classffw_1_1_vec.md)**< T, S > &|[**operator\*=**](classffw_1_1_vec.md#1a6bb7a16a34849f0a01bd864db17b61cc) (const T & val) |
|bool|[**operator!=**](classffw_1_1_vec.md#1aee2e024079668b7b816ab20a298c236d) (const **[Vec](classffw_1_1_vec.md)**< T, S > & vec) const |
|bool|[**operator==**](classffw_1_1_vec.md#1a8ed61030e92210ca4bfc476c2a5a3f00) (const **[Vec](classffw_1_1_vec.md)**< T, S > & vec) const |
|**[ffw::Vec](classffw_1_1_vec.md)**< T, S > &|[**normalize**](classffw_1_1_vec.md#1a0c5d977a6a2beb3470c17402e099586d) () |
|**[ffw::Vec](classffw_1_1_vec.md)**< T, S > &|[**scale**](classffw_1_1_vec.md#1ae8639d57ac7f965b37ca6e4b202bae51) (T factor) |
|float|[**lengthf**](classffw_1_1_vec.md#1abd7bfe7c622abbac76d50cd3d0b781a7) () const |
|double|[**length**](classffw_1_1_vec.md#1ada0dadf2a6ba8eb6c65008ee8765c06c) () const |
|T|[**lengthSqrd**](classffw_1_1_vec.md#1a699f5bab6b13278d3b8669eeeef5350d) () const |
|T &|[**operator[]**](classffw_1_1_vec.md#1a1f79ba95c1732074e738ebdc09121b43) (size\_t i) |
|const T &|[**operator[]**](classffw_1_1_vec.md#1ab4793c212d520b8ebe43036d5d367e2b) (size\_t i) const |
||[**operator ffw::Vec< X, S >**](classffw_1_1_vec.md#1ab748d3f72d5a89d4d948ca15da483dd0) () const |
|**[Vec](classffw_1_1_vec.md)**< T, S >|[**round**](classffw_1_1_vec.md#1a292517ed5e7a630bbfb6c671029d4d9b) () const |
|**[Vec](classffw_1_1_vec.md)**< T, S >|[**floor**](classffw_1_1_vec.md#1aeb1b961553970c255d2cbec766a278a1) () const |
|**[Vec](classffw_1_1_vec.md)**< T, S >|[**ceil**](classffw_1_1_vec.md#1aff7cf34389c02d439dcef2931ea4d4a6) () const |


## Public Attributes Documentation

### variable <a id="1a2613a3bff3371de1a8a1d86d8354bab1" href="#1a2613a3bff3371de1a8a1d86d8354bab1">arr</a>

```cpp
std::array<T, S> ffw::Vec< T, S >::arr;
```



## Public Functions Documentation

### function <a id="1adeda8c8f02a8f7feb45c1548ce039d55" href="#1adeda8c8f02a8f7feb45c1548ce039d55">Vec</a>

```cpp
ffw::Vec::Vec ()
```



### function <a id="1ae683f4da74c401a287b8cc0f43043932" href="#1ae683f4da74c401a287b8cc0f43043932">Vec</a>

```cpp
ffw::Vec::Vec (
    T val
)
```



### function <a id="1af995c7138c0b15a1de04758444f73735" href="#1af995c7138c0b15a1de04758444f73735">Vec</a>

```cpp
ffw::Vec::Vec (
    const std::initializer_list< T > & list
)
```



### function <a id="1aee3de3fbc3c5c4e98d93017207faad1b" href="#1aee3de3fbc3c5c4e98d93017207faad1b">Vec</a>

```cpp
ffw::Vec::Vec (
    const Vec< T, S > & other
)
```



### function <a id="1ae69fe968ddc4ffdfc41d380e6c1119d9" href="#1ae69fe968ddc4ffdfc41d380e6c1119d9">Vec</a>

```cpp
ffw::Vec::Vec (
    Vec< T, S > && other
)
```



### function <a id="1aaf4d3f54a98b90954423777278f58cb2" href="#1aaf4d3f54a98b90954423777278f58cb2">set</a>

```cpp
void ffw::Vec::set (
    T val
)
```



### function <a id="1ae35feb3753c6b74a067850950430b531" href="#1ae35feb3753c6b74a067850950430b531">set</a>

```cpp
void ffw::Vec::set (
    const std::initializer_list< T > & list
)
```



### function <a id="1a6b2ee6bf09bb11bc5f2dcf9383196b2f" href="#1a6b2ee6bf09bb11bc5f2dcf9383196b2f">set</a>

```cpp
void ffw::Vec::set (
    const Vec< T, S > & other
)
```



### function <a id="1a1917448e90cda6bff9998f9d03b37e46" href="#1a1917448e90cda6bff9998f9d03b37e46">operator-</a>

```cpp
ffw::Vec< T, S > ffw::Vec::operator- () const
```



### function <a id="1a4187d67af4f61d878fa870fdc19ef9b4" href="#1a4187d67af4f61d878fa870fdc19ef9b4">operator=</a>

```cpp
ffw::Vec< T, S > & ffw::Vec::operator= (
    const Vec< T, S > & vec
)
```



### function <a id="1a281c39f2e2604a883b507fa2bd1c9f2c" href="#1a281c39f2e2604a883b507fa2bd1c9f2c">operator+</a>

```cpp
ffw::Vec< T, S > ffw::Vec::operator+ (
    const Vec< T, S > & vec
) const
```



### function <a id="1a88ef256281477075b8ba03dd9f489e9b" href="#1a88ef256281477075b8ba03dd9f489e9b">operator+=</a>

```cpp
ffw::Vec< T, S > & ffw::Vec::operator+= (
    const Vec< T, S > & vec
)
```



### function <a id="1a326558a3d6199f4988480832006b4241" href="#1a326558a3d6199f4988480832006b4241">operator-</a>

```cpp
ffw::Vec< T, S > ffw::Vec::operator- (
    const Vec< T, S > & vec
) const
```



### function <a id="1a9a543e17ed42df9ac1cc588eb75673aa" href="#1a9a543e17ed42df9ac1cc588eb75673aa">operator-=</a>

```cpp
ffw::Vec< T, S > & ffw::Vec::operator-= (
    const Vec< T, S > & vec
)
```



### function <a id="1aee50010ba1b4410ca52b659648a28e34" href="#1aee50010ba1b4410ca52b659648a28e34">operator/</a>

```cpp
ffw::Vec< T, S > ffw::Vec::operator/ (
    const Vec< T, S > & vec
) const
```



### function <a id="1a650aed6f4314bab9dba7697541f89d00" href="#1a650aed6f4314bab9dba7697541f89d00">operator/=</a>

```cpp
ffw::Vec< T, S > & ffw::Vec::operator/= (
    const Vec< T, S > & vec
)
```



### function <a id="1aa1033b4f471a6d241b8d42fa1a7eca37" href="#1aa1033b4f471a6d241b8d42fa1a7eca37">operator\*</a>

```cpp
ffw::Vec< T, S > ffw::Vec::operator* (
    const Vec< T, S > & vec
) const
```



### function <a id="1aea8e2369b1e565e1d55d34f422c055fd" href="#1aea8e2369b1e565e1d55d34f422c055fd">operator\*=</a>

```cpp
ffw::Vec< T, S > & ffw::Vec::operator*= (
    const Vec< T, S > & vec
)
```



### function <a id="1a3555b92474436ab56d8a478910087e43" href="#1a3555b92474436ab56d8a478910087e43">operator=</a>

```cpp
ffw::Vec< T, S > & ffw::Vec::operator= (
    const T & val
)
```



### function <a id="1a9acf96a2358328752230e61c5d14203b" href="#1a9acf96a2358328752230e61c5d14203b">operator+</a>

```cpp
ffw::Vec< T, S > ffw::Vec::operator+ (
    const T & val
) const
```



### function <a id="1a2a19aa7485050ffa6a412feed4c69a98" href="#1a2a19aa7485050ffa6a412feed4c69a98">operator+=</a>

```cpp
ffw::Vec< T, S > & ffw::Vec::operator+= (
    const T & val
)
```



### function <a id="1a54bd2c4e3cb32ad163c0c76e2aaa68be" href="#1a54bd2c4e3cb32ad163c0c76e2aaa68be">operator-</a>

```cpp
ffw::Vec< T, S > ffw::Vec::operator- (
    const T & val
) const
```



### function <a id="1a381fcf15a3f6b8f99af5dc5cafd86b44" href="#1a381fcf15a3f6b8f99af5dc5cafd86b44">operator-=</a>

```cpp
ffw::Vec< T, S > & ffw::Vec::operator-= (
    const T & val
)
```



### function <a id="1a7923985a60959a9651bb027fe6a6cce8" href="#1a7923985a60959a9651bb027fe6a6cce8">operator/</a>

```cpp
ffw::Vec< T, S > ffw::Vec::operator/ (
    const T & val
) const
```



### function <a id="1a99aa03d4170a138baee70575b977aab0" href="#1a99aa03d4170a138baee70575b977aab0">operator/=</a>

```cpp
ffw::Vec< T, S > & ffw::Vec::operator/= (
    const T & val
)
```



### function <a id="1ab56e64253b4a4a886000f60d64d9692e" href="#1ab56e64253b4a4a886000f60d64d9692e">operator\*</a>

```cpp
ffw::Vec< T, S > ffw::Vec::operator* (
    const T & val
) const
```



### function <a id="1a6bb7a16a34849f0a01bd864db17b61cc" href="#1a6bb7a16a34849f0a01bd864db17b61cc">operator\*=</a>

```cpp
ffw::Vec< T, S > & ffw::Vec::operator*= (
    const T & val
)
```



### function <a id="1aee2e024079668b7b816ab20a298c236d" href="#1aee2e024079668b7b816ab20a298c236d">operator!=</a>

```cpp
bool ffw::Vec::operator!= (
    const Vec< T, S > & vec
) const
```



### function <a id="1a8ed61030e92210ca4bfc476c2a5a3f00" href="#1a8ed61030e92210ca4bfc476c2a5a3f00">operator==</a>

```cpp
bool ffw::Vec::operator== (
    const Vec< T, S > & vec
) const
```



### function <a id="1a0c5d977a6a2beb3470c17402e099586d" href="#1a0c5d977a6a2beb3470c17402e099586d">normalize</a>

```cpp
ffw::Vec< T, S > & ffw::Vec::normalize ()
```



### function <a id="1ae8639d57ac7f965b37ca6e4b202bae51" href="#1ae8639d57ac7f965b37ca6e4b202bae51">scale</a>

```cpp
ffw::Vec< T, S > & ffw::Vec::scale (
    T factor
)
```



### function <a id="1abd7bfe7c622abbac76d50cd3d0b781a7" href="#1abd7bfe7c622abbac76d50cd3d0b781a7">lengthf</a>

```cpp
float ffw::Vec::lengthf () const
```



### function <a id="1ada0dadf2a6ba8eb6c65008ee8765c06c" href="#1ada0dadf2a6ba8eb6c65008ee8765c06c">length</a>

```cpp
double ffw::Vec::length () const
```



### function <a id="1a699f5bab6b13278d3b8669eeeef5350d" href="#1a699f5bab6b13278d3b8669eeeef5350d">lengthSqrd</a>

```cpp
T ffw::Vec::lengthSqrd () const
```



### function <a id="1a1f79ba95c1732074e738ebdc09121b43" href="#1a1f79ba95c1732074e738ebdc09121b43">operator[]</a>

```cpp
T & ffw::Vec::operator[] (
    size_t i
)
```



### function <a id="1ab4793c212d520b8ebe43036d5d367e2b" href="#1ab4793c212d520b8ebe43036d5d367e2b">operator[]</a>

```cpp
const T & ffw::Vec::operator[] (
    size_t i
) const
```



### function <a id="1ab748d3f72d5a89d4d948ca15da483dd0" href="#1ab748d3f72d5a89d4d948ca15da483dd0">operator ffw::Vec< X, S ></a>

```cpp
ffw::Vec::operator ffw::Vec< X, S > () const
```



### function <a id="1a292517ed5e7a630bbfb6c671029d4d9b" href="#1a292517ed5e7a630bbfb6c671029d4d9b">round</a>

```cpp
Vec< T, S > ffw::Vec::round () const
```



### function <a id="1aeb1b961553970c255d2cbec766a278a1" href="#1aeb1b961553970c255d2cbec766a278a1">floor</a>

```cpp
Vec< T, S > ffw::Vec::floor () const
```



### function <a id="1aff7cf34389c02d439dcef2931ea4d4a6" href="#1aff7cf34389c02d439dcef2931ea4d4a6">ceil</a>

```cpp
Vec< T, S > ffw::Vec::ceil () const
```





----------------------------------------
The documentation for this class was generated from the following file: `include/ffw/math/vecx.h`
