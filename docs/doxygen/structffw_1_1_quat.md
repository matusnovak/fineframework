---
search:
    keywords: ['ffw::Quat', 'x', 'y', 'z', 'w', 'Quat', 'Quat', 'Quat', 'set', 'set', 'rotate', 'rotateRad', 'operator-', 'operator*', 'operator*=', 'operator*', 'operator*=', 'operator+', 'operator+=', 'operator-', 'operator-=', 'operator/', 'operator/=', 'normalize', 'getEuler', 'length', 'lengthSqrd', 'getConjugate', 'getInversed', 'inverse']
---

# struct ffw::Quat

## Public Attributes

|Type|Name|
|-----|-----|
|T|[**x**](structffw_1_1_quat.md#1a9eac92bced0865753f84d0239a044321)|
|T|[**y**](structffw_1_1_quat.md#1a4e1fb8fb99b45f6776f5cf8757259f62)|
|T|[**z**](structffw_1_1_quat.md#1a698a2473309d530c3094e592b8889adc)|
|T|[**w**](structffw_1_1_quat.md#1a05792d349097e970610cde3c39fcc1ef)|


## Public Functions

|Type|Name|
|-----|-----|
||[**Quat**](structffw_1_1_quat.md#1aa93e7f7384815f439720993f477f4422) () |
||[**Quat**](structffw_1_1_quat.md#1ac94577f690ed85d53167aab212174154) (T X, T Y, T Z, T W) |
||[**Quat**](structffw_1_1_quat.md#1a7dcdee28b055403a1b1ddaa11a68df3b) (const **[Quat](structffw_1_1_quat.md)** & q) |
|void|[**set**](structffw_1_1_quat.md#1afaeaeaac7138cf0e130cf2d8cfb75fe8) (T X, T Y, T Z, T W) |
|void|[**set**](structffw_1_1_quat.md#1a218498b4dbc4a31a728d9ce7ea4a6323) (const **[Quat](structffw_1_1_quat.md)** & q) |
|**[ffw::Quat](structffw_1_1_quat.md)**< T > &|[**rotate**](structffw_1_1_quat.md#1a5ff17a04b40a5ea1cea417139f60b543) (T Deg, T X, T Y, T Z) |
|**[ffw::Quat](structffw_1_1_quat.md)**< T > &|[**rotateRad**](structffw_1_1_quat.md#1a139669f1f329bd6f5eda4be90c4bdab1) (T Rad, T X, T Y, T Z) |
|**[ffw::Quat](structffw_1_1_quat.md)**< T >|[**operator-**](structffw_1_1_quat.md#1a1d333eddb1cfda47b1687e717622332b) () const |
|**[ffw::Quat](structffw_1_1_quat.md)**< T >|[**operator\***](structffw_1_1_quat.md#1afdb031ff3281e7079a87a4fc7bba2a43) (const **[Quat](structffw_1_1_quat.md)** & q) const |
|**[ffw::Quat](structffw_1_1_quat.md)**< T > &|[**operator\*=**](structffw_1_1_quat.md#1aca4b73145db56bb01c66423893a829cf) (const **[Quat](structffw_1_1_quat.md)** & q) |
|**[ffw::Quat](structffw_1_1_quat.md)**< T >|[**operator\***](structffw_1_1_quat.md#1aff52914655c01d7a13b97318c90fbe67) (T Value) const |
|**[ffw::Quat](structffw_1_1_quat.md)**< T > &|[**operator\*=**](structffw_1_1_quat.md#1a693eca8d4f1ac350e465c8f7a0e90b36) (T Value) |
|**[ffw::Quat](structffw_1_1_quat.md)**< T >|[**operator+**](structffw_1_1_quat.md#1a037508ee705153df71862dd9c6d274ae) (const **[Quat](structffw_1_1_quat.md)** & q) const |
|**[ffw::Quat](structffw_1_1_quat.md)**< T > &|[**operator+=**](structffw_1_1_quat.md#1add90eb8e3c07c77c3a18015a5a30bd13) (const **[Quat](structffw_1_1_quat.md)** & q) |
|**[ffw::Quat](structffw_1_1_quat.md)**< T >|[**operator-**](structffw_1_1_quat.md#1a0aa5582baf77ce1ff99b6140ee2ec39f) (const **[Quat](structffw_1_1_quat.md)** & q) const |
|**[ffw::Quat](structffw_1_1_quat.md)**< T > &|[**operator-=**](structffw_1_1_quat.md#1a8c50c0674de362d1f77de2eff3e6abf2) (const **[Quat](structffw_1_1_quat.md)** & q) |
|**[ffw::Quat](structffw_1_1_quat.md)**< T >|[**operator/**](structffw_1_1_quat.md#1ae55e5bbaa63a999b7163a17dc4fb85e7) (T Value) const |
|**[ffw::Quat](structffw_1_1_quat.md)**< T > &|[**operator/=**](structffw_1_1_quat.md#1a5472c7c386f9166641c30daff39dc0cb) (T Value) |
|void|[**normalize**](structffw_1_1_quat.md#1a7ce9e8e8c1d1f011ca80e03061f6a0b2) () |
|void|[**getEuler**](structffw_1_1_quat.md#1a216cd0c650cadc7c5e7583c08a6522d5) (T \* Roll, T \* Pitch, T \* Yaw) const |
|float|[**length**](structffw_1_1_quat.md#1abe1bca6db072c084eedb45e1fb25a138) () const |
|float|[**lengthSqrd**](structffw_1_1_quat.md#1a5136c65bdb921081dc14e9cb14fd634f) () const |
|**[ffw::Quat](structffw_1_1_quat.md)**< T >|[**getConjugate**](structffw_1_1_quat.md#1a041a2a2fb8b134425144106c04b10527) () const |
|**[ffw::Quat](structffw_1_1_quat.md)**< T >|[**getInversed**](structffw_1_1_quat.md#1a5a1169069f1e8593115db6b46cfdfddf) () const |
|**[ffw::Quat](structffw_1_1_quat.md)**< T > &|[**inverse**](structffw_1_1_quat.md#1a5d1aafac471c3e587c16ee51aa81d044) () |


## Public Attributes Documentation

### variable <a id="1a9eac92bced0865753f84d0239a044321" href="#1a9eac92bced0865753f84d0239a044321">x</a>

```cpp
T ffw::Quat< T >::x;
```



### variable <a id="1a4e1fb8fb99b45f6776f5cf8757259f62" href="#1a4e1fb8fb99b45f6776f5cf8757259f62">y</a>

```cpp
T ffw::Quat< T >::y;
```



### variable <a id="1a698a2473309d530c3094e592b8889adc" href="#1a698a2473309d530c3094e592b8889adc">z</a>

```cpp
T ffw::Quat< T >::z;
```



### variable <a id="1a05792d349097e970610cde3c39fcc1ef" href="#1a05792d349097e970610cde3c39fcc1ef">w</a>

```cpp
T ffw::Quat< T >::w;
```



## Public Functions Documentation

### function <a id="1aa93e7f7384815f439720993f477f4422" href="#1aa93e7f7384815f439720993f477f4422">Quat</a>

```cpp
ffw::Quat::Quat ()
```



### function <a id="1ac94577f690ed85d53167aab212174154" href="#1ac94577f690ed85d53167aab212174154">Quat</a>

```cpp
ffw::Quat::Quat (
    T X
    T Y
    T Z
    T W
)
```



### function <a id="1a7dcdee28b055403a1b1ddaa11a68df3b" href="#1a7dcdee28b055403a1b1ddaa11a68df3b">Quat</a>

```cpp
ffw::Quat::Quat (
    const Quat & q
)
```



### function <a id="1afaeaeaac7138cf0e130cf2d8cfb75fe8" href="#1afaeaeaac7138cf0e130cf2d8cfb75fe8">set</a>

```cpp
void ffw::Quat::set (
    T X
    T Y
    T Z
    T W
)
```



### function <a id="1a218498b4dbc4a31a728d9ce7ea4a6323" href="#1a218498b4dbc4a31a728d9ce7ea4a6323">set</a>

```cpp
void ffw::Quat::set (
    const Quat & q
)
```



### function <a id="1a5ff17a04b40a5ea1cea417139f60b543" href="#1a5ff17a04b40a5ea1cea417139f60b543">rotate</a>

```cpp
ffw::Quat< T > & ffw::Quat::rotate (
    T Deg
    T X
    T Y
    T Z
)
```



### function <a id="1a139669f1f329bd6f5eda4be90c4bdab1" href="#1a139669f1f329bd6f5eda4be90c4bdab1">rotateRad</a>

```cpp
ffw::Quat< T > & ffw::Quat::rotateRad (
    T Rad
    T X
    T Y
    T Z
)
```



### function <a id="1a1d333eddb1cfda47b1687e717622332b" href="#1a1d333eddb1cfda47b1687e717622332b">operator-</a>

```cpp
ffw::Quat< T > ffw::Quat::operator- () const
```



### function <a id="1afdb031ff3281e7079a87a4fc7bba2a43" href="#1afdb031ff3281e7079a87a4fc7bba2a43">operator\*</a>

```cpp
ffw::Quat< T > ffw::Quat::operator* (
    const Quat & q
) const
```



### function <a id="1aca4b73145db56bb01c66423893a829cf" href="#1aca4b73145db56bb01c66423893a829cf">operator\*=</a>

```cpp
ffw::Quat< T > & ffw::Quat::operator*= (
    const Quat & q
)
```



### function <a id="1aff52914655c01d7a13b97318c90fbe67" href="#1aff52914655c01d7a13b97318c90fbe67">operator\*</a>

```cpp
ffw::Quat< T > ffw::Quat::operator* (
    T Value
) const
```



### function <a id="1a693eca8d4f1ac350e465c8f7a0e90b36" href="#1a693eca8d4f1ac350e465c8f7a0e90b36">operator\*=</a>

```cpp
ffw::Quat< T > & ffw::Quat::operator*= (
    T Value
)
```



### function <a id="1a037508ee705153df71862dd9c6d274ae" href="#1a037508ee705153df71862dd9c6d274ae">operator+</a>

```cpp
ffw::Quat< T > ffw::Quat::operator+ (
    const Quat & q
) const
```



### function <a id="1add90eb8e3c07c77c3a18015a5a30bd13" href="#1add90eb8e3c07c77c3a18015a5a30bd13">operator+=</a>

```cpp
ffw::Quat< T > & ffw::Quat::operator+= (
    const Quat & q
)
```



### function <a id="1a0aa5582baf77ce1ff99b6140ee2ec39f" href="#1a0aa5582baf77ce1ff99b6140ee2ec39f">operator-</a>

```cpp
ffw::Quat< T > ffw::Quat::operator- (
    const Quat & q
) const
```



### function <a id="1a8c50c0674de362d1f77de2eff3e6abf2" href="#1a8c50c0674de362d1f77de2eff3e6abf2">operator-=</a>

```cpp
ffw::Quat< T > & ffw::Quat::operator-= (
    const Quat & q
)
```



### function <a id="1ae55e5bbaa63a999b7163a17dc4fb85e7" href="#1ae55e5bbaa63a999b7163a17dc4fb85e7">operator/</a>

```cpp
ffw::Quat< T > ffw::Quat::operator/ (
    T Value
) const
```



### function <a id="1a5472c7c386f9166641c30daff39dc0cb" href="#1a5472c7c386f9166641c30daff39dc0cb">operator/=</a>

```cpp
ffw::Quat< T > & ffw::Quat::operator/= (
    T Value
)
```



### function <a id="1a7ce9e8e8c1d1f011ca80e03061f6a0b2" href="#1a7ce9e8e8c1d1f011ca80e03061f6a0b2">normalize</a>

```cpp
void ffw::Quat::normalize ()
```



### function <a id="1a216cd0c650cadc7c5e7583c08a6522d5" href="#1a216cd0c650cadc7c5e7583c08a6522d5">getEuler</a>

```cpp
void ffw::Quat::getEuler (
    T * Roll
    T * Pitch
    T * Yaw
) const
```



### function <a id="1abe1bca6db072c084eedb45e1fb25a138" href="#1abe1bca6db072c084eedb45e1fb25a138">length</a>

```cpp
float ffw::Quat::length () const
```



### function <a id="1a5136c65bdb921081dc14e9cb14fd634f" href="#1a5136c65bdb921081dc14e9cb14fd634f">lengthSqrd</a>

```cpp
float ffw::Quat::lengthSqrd () const
```



### function <a id="1a041a2a2fb8b134425144106c04b10527" href="#1a041a2a2fb8b134425144106c04b10527">getConjugate</a>

```cpp
ffw::Quat< T > ffw::Quat::getConjugate () const
```



### function <a id="1a5a1169069f1e8593115db6b46cfdfddf" href="#1a5a1169069f1e8593115db6b46cfdfddf">getInversed</a>

```cpp
ffw::Quat< T > ffw::Quat::getInversed () const
```



### function <a id="1a5d1aafac471c3e587c16ee51aa81d044" href="#1a5d1aafac471c3e587c16ee51aa81d044">inverse</a>

```cpp
ffw::Quat< T > & ffw::Quat::inverse ()
```





----------------------------------------
The documentation for this class was generated from the following file: `include/ffw/math/quaternion.h`
