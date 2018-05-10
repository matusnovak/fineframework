---
search: false
---

# class ffw::Any

## Classes

|Type|Name|
|-----|-----|
|class|[**Content**](classffw_1_1_any_1_1_content.md)|
|class|[**Data**](classffw_1_1_any_1_1_data.md)|
|class|[**Data< T, typename std::enable\_if< std::is\_floating\_point< T >::value >::type >**](classffw_1_1_any_1_1_data_3_01_t_00_01typename_01std_1_1enable__if_3_01std_1_1is__floating__poin8f5cef6f752074c0b0a03a3bfed1b685.md)|
|class|[**Data< T, typename std::enable\_if< std::is\_integral< T >::value >::type >**](classffw_1_1_any_1_1_data_3_01_t_00_01typename_01std_1_1enable__if_3_01std_1_1is__integral_3_01_1e21ee7f9b88f0216578ab66ea9deac3.md)|


## Public Functions

|Type|Name|
|-----|-----|
||[**Any**](classffw_1_1_any.md#1aa6c8360bd2319591ad03280feccd9d66) () |
||[**Any**](classffw_1_1_any.md#1a28b27b8ed8c52327921476aba81767fe) (const **[Any](classffw_1_1_any.md)** & other) |
||[**Any**](classffw_1_1_any.md#1a6264c8d1193f1954da25ce1fd3b2e329) (**[Any](classffw_1_1_any.md)** && other) |
||[**Any**](classffw_1_1_any.md#1a084663ac546e9e227cee0e119a49826d) (T value) |
||[**Any**](classffw_1_1_any.md#1a8b4b29d9c552b1b08cf44936dc0bfd5f) (std::initializer\_list< std::pair< std::string, **[Any](classffw_1_1_any.md)** >> list) |
||[**Any**](classffw_1_1_any.md#1a047108240c5cdb77f0d34863191d1016) (std::initializer\_list< **[Any](classffw_1_1_any.md)** > list) |
|virtual |[**~Any**](classffw_1_1_any.md#1a3ca9e3a978d28a03c5d0cc4dfd0f3710) () |
|bool|[**empty**](classffw_1_1_any.md#1afb7ba7d2e3a61d872d0b9592959b8f9c) () const |
|void|[**reset**](classffw_1_1_any.md#1aac646a9bf7cd63c43f1c7b53f2ff17c8) () |
|T &|[**getAs**](classffw_1_1_any.md#1aca976c064da6c22373aaa8ff9918e0a2) () |
|const T &|[**getAs**](classffw_1_1_any.md#1a205141e1543108baee7c8bf41ba39f62) () const |
|void|[**set**](classffw_1_1_any.md#1a3a6129c5ba635a2f65504e6c7ddad2d4) (T value = T()) |
|bool|[**is**](classffw_1_1_any.md#1ab2cd77d7d08ed1d020df5c9a6957dbeb) () const |
|bool|[**toBool**](classffw_1_1_any.md#1a15933cec8007b6b218248b09e758c250) () const |
|bool|[**isBool**](classffw_1_1_any.md#1ab1c535fb3c374c0369d9dc3299754058) () const |
|std::string|[**toString**](classffw_1_1_any.md#1ae9a61b699218c669ca1510713c8a428d) () const |
|bool|[**isString**](classffw_1_1_any.md#1a2ff288b754c32bec2f490b65a2897d8c) () const |
|int|[**toInt**](classffw_1_1_any.md#1aed8450a1d5f11e09cebaf2110bea7961) () const |
|bool|[**isInt**](classffw_1_1_any.md#1a54349c5e2b72db8cf8ff8593c019803a) () const |
|float|[**toFloat**](classffw_1_1_any.md#1a8ae0c7aabed5e1ef2d45d8122a6f184e) () const |
|double|[**toDouble**](classffw_1_1_any.md#1a55d110d8a622cecf98578359fbc6b219) () const |
|bool|[**isFloat**](classffw_1_1_any.md#1aa1066b6ccd4b77e570b273567b027bc1) () const |
|bool|[**isNumber**](classffw_1_1_any.md#1adaa4a0bd0fb36d2ffe3ea1ab2ab89656) () const |
|bool|[**isObject**](classffw_1_1_any.md#1a3aea73710981019599ba2e42ce5721ff) () const |
|bool|[**isArray**](classffw_1_1_any.md#1a5f5c95bded174caea5e3b134e1d73808) () const |
|**[ffw::Array](classffw_1_1_array.md)** &|[**getAsArray**](classffw_1_1_any.md#1acf6f42b2be7275c8c4496d601b32efc0) () |
|**[ffw::Object](classffw_1_1_object.md)** &|[**getAsObject**](classffw_1_1_any.md#1a44211e2f05062e98f5e6835bf77a5a4a) () |
|const **[ffw::Array](classffw_1_1_array.md)** &|[**getAsArray**](classffw_1_1_any.md#1ae4da3eaa33310307b36436b291a71697) () const |
|const **[ffw::Object](classffw_1_1_object.md)** &|[**getAsObject**](classffw_1_1_any.md#1a5d54d29e57a4f57aa2587c0f5e86e4da) () const |
|void|[**clear**](classffw_1_1_any.md#1a3cb0e3d97dad3aed5b72983a19c93f70) () |
|const std::type\_info &|[**getTypeid**](classffw_1_1_any.md#1acff63f5e922cdb62b10a93185a6217ce) () const |
||[**operator T**](classffw_1_1_any.md#1aab8178d4c6c41b8063a70198a57478be) () const |
||[**operator T &**](classffw_1_1_any.md#1aa77084fb13875d22d439c7b407a53667) () |
||[**operator const T &**](classffw_1_1_any.md#1a9d2ae96f567f7c27825693bb101bef88) () const |
|void|[**swap**](classffw_1_1_any.md#1a4e5ff8e06431143aeb6f5b884147685e) (**[Any](classffw_1_1_any.md)** & other) |
|**[Any](classffw_1_1_any.md)** &|[**operator=**](classffw_1_1_any.md#1a0c5ceeb85652d19ec188c2315a98ee5c) (const T & value) |
|**[Any](classffw_1_1_any.md)** &|[**operator=**](classffw_1_1_any.md#1a154de041bb38ffde169ccb0b8653fb49) (T && value) |
|**[Any](classffw_1_1_any.md)** &|[**operator=**](classffw_1_1_any.md#1a243155c6c4f6a16a2d5881efa4874731) (const **[Any](classffw_1_1_any.md)** & other) |
|**[Any](classffw_1_1_any.md)** &|[**operator=**](classffw_1_1_any.md#1a5e9dcf512f6b05d69ab2049a36b9a150) (**[Any](classffw_1_1_any.md)** && other) |
|**[Any](classffw_1_1_any.md)** &|[**operator[]**](classffw_1_1_any.md#1a32fc6bbd4abe37cf6927c6a3cc580625) (const std::string & key) |
|const **[Any](classffw_1_1_any.md)** &|[**operator[]**](classffw_1_1_any.md#1afa3c67d2605a0af7f70d3fdea615ef4c) (const std::string & key) const |
|**[Any](classffw_1_1_any.md)** &|[**operator[]**](classffw_1_1_any.md#1aebbde4994b4a66896c8efff4fb4691d5) (size\_t n) |
|const **[Any](classffw_1_1_any.md)** &|[**operator[]**](classffw_1_1_any.md#1a87707c12d0dd29ed834346f8bb9fa71e) (size\_t n) const |
|bool|[**operator==**](classffw_1_1_any.md#1a68c26e3adb1d2ab39663f875cad39fd1) (const T & other) const |
|bool|[**operator!=**](classffw_1_1_any.md#1a49685f3f3acdc82680cf9506736ceb0e) (const T & other) const |
|bool|[**operator==**](classffw_1_1_any.md#1a2d49b4fef1d61fc1c6609b4c9bee160f) (const **[Any](classffw_1_1_any.md)** & other) const |
|bool|[**operator!=**](classffw_1_1_any.md#1a1f6b2d51721cf0e7972dd195578f61c8) (const **[Any](classffw_1_1_any.md)** & other) const |


## Public Functions Documentation

### function <a id="1aa6c8360bd2319591ad03280feccd9d66" href="#1aa6c8360bd2319591ad03280feccd9d66">Any</a>

```cpp
ffw::Any::Any ()
```



### function <a id="1a28b27b8ed8c52327921476aba81767fe" href="#1a28b27b8ed8c52327921476aba81767fe">Any</a>

```cpp
ffw::Any::Any (
    const Any & other
)
```



### function <a id="1a6264c8d1193f1954da25ce1fd3b2e329" href="#1a6264c8d1193f1954da25ce1fd3b2e329">Any</a>

```cpp
ffw::Any::Any (
    Any && other
)
```



### function <a id="1a084663ac546e9e227cee0e119a49826d" href="#1a084663ac546e9e227cee0e119a49826d">Any</a>

```cpp
ffw::Any::Any (
    T value
)
```



### function <a id="1a8b4b29d9c552b1b08cf44936dc0bfd5f" href="#1a8b4b29d9c552b1b08cf44936dc0bfd5f">Any</a>

```cpp
ffw::Any::Any (
    std::initializer_list< std::pair< std::string, Any >> list
)
```



### function <a id="1a047108240c5cdb77f0d34863191d1016" href="#1a047108240c5cdb77f0d34863191d1016">Any</a>

```cpp
ffw::Any::Any (
    std::initializer_list< Any > list
)
```



### function <a id="1a3ca9e3a978d28a03c5d0cc4dfd0f3710" href="#1a3ca9e3a978d28a03c5d0cc4dfd0f3710">~Any</a>

```cpp
virtual ffw::Any::~Any ()
```



### function <a id="1afb7ba7d2e3a61d872d0b9592959b8f9c" href="#1afb7ba7d2e3a61d872d0b9592959b8f9c">empty</a>

```cpp
bool ffw::Any::empty () const
```



### function <a id="1aac646a9bf7cd63c43f1c7b53f2ff17c8" href="#1aac646a9bf7cd63c43f1c7b53f2ff17c8">reset</a>

```cpp
void ffw::Any::reset ()
```



### function <a id="1aca976c064da6c22373aaa8ff9918e0a2" href="#1aca976c064da6c22373aaa8ff9918e0a2">getAs</a>

```cpp
T & ffw::Any::getAs ()
```



### function <a id="1a205141e1543108baee7c8bf41ba39f62" href="#1a205141e1543108baee7c8bf41ba39f62">getAs</a>

```cpp
const T & ffw::Any::getAs () const
```



### function <a id="1a3a6129c5ba635a2f65504e6c7ddad2d4" href="#1a3a6129c5ba635a2f65504e6c7ddad2d4">set</a>

```cpp
void ffw::Any::set (
    T value = T()
)
```



### function <a id="1ab2cd77d7d08ed1d020df5c9a6957dbeb" href="#1ab2cd77d7d08ed1d020df5c9a6957dbeb">is</a>

```cpp
bool ffw::Any::is () const
```



### function <a id="1a15933cec8007b6b218248b09e758c250" href="#1a15933cec8007b6b218248b09e758c250">toBool</a>

```cpp
bool ffw::Any::toBool () const
```



### function <a id="1ab1c535fb3c374c0369d9dc3299754058" href="#1ab1c535fb3c374c0369d9dc3299754058">isBool</a>

```cpp
bool ffw::Any::isBool () const
```



### function <a id="1ae9a61b699218c669ca1510713c8a428d" href="#1ae9a61b699218c669ca1510713c8a428d">toString</a>

```cpp
std::string ffw::Any::toString () const
```



### function <a id="1a2ff288b754c32bec2f490b65a2897d8c" href="#1a2ff288b754c32bec2f490b65a2897d8c">isString</a>

```cpp
bool ffw::Any::isString () const
```



### function <a id="1aed8450a1d5f11e09cebaf2110bea7961" href="#1aed8450a1d5f11e09cebaf2110bea7961">toInt</a>

```cpp
int ffw::Any::toInt () const
```



### function <a id="1a54349c5e2b72db8cf8ff8593c019803a" href="#1a54349c5e2b72db8cf8ff8593c019803a">isInt</a>

```cpp
bool ffw::Any::isInt () const
```



### function <a id="1a8ae0c7aabed5e1ef2d45d8122a6f184e" href="#1a8ae0c7aabed5e1ef2d45d8122a6f184e">toFloat</a>

```cpp
float ffw::Any::toFloat () const
```



### function <a id="1a55d110d8a622cecf98578359fbc6b219" href="#1a55d110d8a622cecf98578359fbc6b219">toDouble</a>

```cpp
double ffw::Any::toDouble () const
```



### function <a id="1aa1066b6ccd4b77e570b273567b027bc1" href="#1aa1066b6ccd4b77e570b273567b027bc1">isFloat</a>

```cpp
bool ffw::Any::isFloat () const
```



### function <a id="1adaa4a0bd0fb36d2ffe3ea1ab2ab89656" href="#1adaa4a0bd0fb36d2ffe3ea1ab2ab89656">isNumber</a>

```cpp
bool ffw::Any::isNumber () const
```



### function <a id="1a3aea73710981019599ba2e42ce5721ff" href="#1a3aea73710981019599ba2e42ce5721ff">isObject</a>

```cpp
bool ffw::Any::isObject () const
```



### function <a id="1a5f5c95bded174caea5e3b134e1d73808" href="#1a5f5c95bded174caea5e3b134e1d73808">isArray</a>

```cpp
bool ffw::Any::isArray () const
```



### function <a id="1acf6f42b2be7275c8c4496d601b32efc0" href="#1acf6f42b2be7275c8c4496d601b32efc0">getAsArray</a>

```cpp
ffw::Array & ffw::Any::getAsArray ()
```



### function <a id="1a44211e2f05062e98f5e6835bf77a5a4a" href="#1a44211e2f05062e98f5e6835bf77a5a4a">getAsObject</a>

```cpp
ffw::Object & ffw::Any::getAsObject ()
```



### function <a id="1ae4da3eaa33310307b36436b291a71697" href="#1ae4da3eaa33310307b36436b291a71697">getAsArray</a>

```cpp
const ffw::Array & ffw::Any::getAsArray () const
```



### function <a id="1a5d54d29e57a4f57aa2587c0f5e86e4da" href="#1a5d54d29e57a4f57aa2587c0f5e86e4da">getAsObject</a>

```cpp
const ffw::Object & ffw::Any::getAsObject () const
```



### function <a id="1a3cb0e3d97dad3aed5b72983a19c93f70" href="#1a3cb0e3d97dad3aed5b72983a19c93f70">clear</a>

```cpp
void ffw::Any::clear ()
```



### function <a id="1acff63f5e922cdb62b10a93185a6217ce" href="#1acff63f5e922cdb62b10a93185a6217ce">getTypeid</a>

```cpp
const std::type_info & ffw::Any::getTypeid () const
```



### function <a id="1aab8178d4c6c41b8063a70198a57478be" href="#1aab8178d4c6c41b8063a70198a57478be">operator T</a>

```cpp
explicit ffw::Any::operator T () const
```



### function <a id="1aa77084fb13875d22d439c7b407a53667" href="#1aa77084fb13875d22d439c7b407a53667">operator T &</a>

```cpp
explicit ffw::Any::operator T & ()
```



### function <a id="1a9d2ae96f567f7c27825693bb101bef88" href="#1a9d2ae96f567f7c27825693bb101bef88">operator const T &</a>

```cpp
explicit ffw::Any::operator const T & () const
```



### function <a id="1a4e5ff8e06431143aeb6f5b884147685e" href="#1a4e5ff8e06431143aeb6f5b884147685e">swap</a>

```cpp
void ffw::Any::swap (
    Any & other
)
```



### function <a id="1a0c5ceeb85652d19ec188c2315a98ee5c" href="#1a0c5ceeb85652d19ec188c2315a98ee5c">operator=</a>

```cpp
Any & ffw::Any::operator= (
    const T & value
)
```



### function <a id="1a154de041bb38ffde169ccb0b8653fb49" href="#1a154de041bb38ffde169ccb0b8653fb49">operator=</a>

```cpp
Any & ffw::Any::operator= (
    T && value
)
```



### function <a id="1a243155c6c4f6a16a2d5881efa4874731" href="#1a243155c6c4f6a16a2d5881efa4874731">operator=</a>

```cpp
Any & ffw::Any::operator= (
    const Any & other
)
```



### function <a id="1a5e9dcf512f6b05d69ab2049a36b9a150" href="#1a5e9dcf512f6b05d69ab2049a36b9a150">operator=</a>

```cpp
Any & ffw::Any::operator= (
    Any && other
)
```



### function <a id="1a32fc6bbd4abe37cf6927c6a3cc580625" href="#1a32fc6bbd4abe37cf6927c6a3cc580625">operator[]</a>

```cpp
Any & ffw::Any::operator[] (
    const std::string & key
)
```



### function <a id="1afa3c67d2605a0af7f70d3fdea615ef4c" href="#1afa3c67d2605a0af7f70d3fdea615ef4c">operator[]</a>

```cpp
const Any & ffw::Any::operator[] (
    const std::string & key
) const
```



### function <a id="1aebbde4994b4a66896c8efff4fb4691d5" href="#1aebbde4994b4a66896c8efff4fb4691d5">operator[]</a>

```cpp
Any & ffw::Any::operator[] (
    size_t n
)
```



### function <a id="1a87707c12d0dd29ed834346f8bb9fa71e" href="#1a87707c12d0dd29ed834346f8bb9fa71e">operator[]</a>

```cpp
const Any & ffw::Any::operator[] (
    size_t n
) const
```



### function <a id="1a68c26e3adb1d2ab39663f875cad39fd1" href="#1a68c26e3adb1d2ab39663f875cad39fd1">operator==</a>

```cpp
bool ffw::Any::operator== (
    const T & other
) const
```



### function <a id="1a49685f3f3acdc82680cf9506736ceb0e" href="#1a49685f3f3acdc82680cf9506736ceb0e">operator!=</a>

```cpp
bool ffw::Any::operator!= (
    const T & other
) const
```



### function <a id="1a2d49b4fef1d61fc1c6609b4c9bee160f" href="#1a2d49b4fef1d61fc1c6609b4c9bee160f">operator==</a>

```cpp
bool ffw::Any::operator== (
    const Any & other
) const
```



### function <a id="1a1f6b2d51721cf0e7972dd195578f61c8" href="#1a1f6b2d51721cf0e7972dd195578f61c8">operator!=</a>

```cpp
bool ffw::Any::operator!= (
    const Any & other
) const
```





----------------------------------------
The documentation for this class was generated from the following file: `include/ffw/math/any.h`
