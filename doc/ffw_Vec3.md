Vec3
===================================


The documentation for this struct was generated from: `include/ffw/math/vec3.h`



## Public Attributes

| Type | Name |
| -------: | :------- |
|  T | [x](#37cde167) |
|  T | [y](#09579a12) |
|  T | [z](#9105e095) |


## Public Functions

| Type | Name |
| -------: | :------- |
|   | [Vec3](#1693263b) ()  |
|   | [Vec3](#b1d4eb0a) (T _compx_, T _compy_, T _compz_)  |
|   | [Vec3](#d5eae5ca) (T _Value_)  |
|   | [Vec3](#23b20ae9) (const [Vec3](ffw_Vec3.html)< T > & _vec_)  |
|   | [Vec3](#64b9cec1) (const std::initializer_list< T > & _list_)  |
|  void | [set](#b50315a5) (T _compx_, T _compy_, T _compz_)  |
|  void | [set](#1e664b24) (T _Value_)  |
|  void | [set](#cca3b619) (const [Vec3](ffw_Vec3.html)< T > & _vec_)  |
|  void | [set](#26cb70a2) (const std::initializer_list< T > & _list_)  |
|  [ffw::Vec3](ffw_Vec3.html)< T > | [operator-](#da695ef1) () const  |
|  [ffw::Vec3](ffw_Vec3.html)< T > & | [operator=](#566ee37e) (const [Vec3](ffw_Vec3.html)< T > & _vec_)  |
|  [ffw::Vec3](ffw_Vec3.html)< T > | [operator+](#6b5af011) (const [Vec3](ffw_Vec3.html)< T > & _vec_) const  |
|  [ffw::Vec3](ffw_Vec3.html)< T > & | [operator+=](#a2e85559) (const [Vec3](ffw_Vec3.html)< T > & _vec_)  |
|  [ffw::Vec3](ffw_Vec3.html)< T > | [operator-](#761776e7) (const [Vec3](ffw_Vec3.html)< T > & _vec_) const  |
|  [ffw::Vec3](ffw_Vec3.html)< T > & | [operator-=](#19140f89) (const [Vec3](ffw_Vec3.html)< T > & _vec_)  |
|  [ffw::Vec3](ffw_Vec3.html)< T > | [operator/](#c8baf9d8) (const [Vec3](ffw_Vec3.html)< T > & _vec_) const  |
|  [ffw::Vec3](ffw_Vec3.html)< T > & | [operator/=](#7112ac87) (const [Vec3](ffw_Vec3.html)< T > & _vec_)  |
|  [ffw::Vec3](ffw_Vec3.html)< T > | [operator*](#8fe86d2c) (const [Vec3](ffw_Vec3.html)< T > & _vec_) const  |
|  [ffw::Vec3](ffw_Vec3.html)< T > & | [operator*=](#b7121412) (const [Vec3](ffw_Vec3.html)< T > & _vec_)  |
|  [ffw::Vec3](ffw_Vec3.html)< T > & | [operator=](#fb45de75) (const T & _val_)  |
|  [ffw::Vec3](ffw_Vec3.html)< T > | [operator+](#3f5dfa51) (const T & _val_) const  |
|  [ffw::Vec3](ffw_Vec3.html)< T > & | [operator+=](#28f8aeb5) (const T & _val_)  |
|  [ffw::Vec3](ffw_Vec3.html)< T > | [operator-](#a51adcaa) (const T & _val_) const  |
|  [ffw::Vec3](ffw_Vec3.html)< T > & | [operator-=](#f4a05210) (const T & _val_)  |
|  [ffw::Vec3](ffw_Vec3.html)< T > | [operator/](#dbb52ff0) (const T & _val_) const  |
|  [ffw::Vec3](ffw_Vec3.html)< T > & | [operator/=](#8098da86) (const T & _val_)  |
|  [ffw::Vec3](ffw_Vec3.html)< T > | [operator*](#09965989) (const T & _val_) const  |
|  [ffw::Vec3](ffw_Vec3.html)< T > & | [operator*=](#bf5f60e4) (const T & _val_)  |
|  bool | [operator!=](#fe96e57d) (const [Vec3](ffw_Vec3.html)< T > & _vec_) const  |
|  bool | [operator==](#18845606) (const [Vec3](ffw_Vec3.html)< T > & _vec_) const  |
|  [ffw::Vec3](ffw_Vec3.html)< T > & | [rotateByAxis](#982aa729) (double _deg_, [Vec3](ffw_Vec3.html)< T > _axis_)  |
|  [ffw::Vec3](ffw_Vec3.html)< T > & | [rotateByAxisRad](#ba278b23) (double _rad_, [Vec3](ffw_Vec3.html)< T > _axis_)  |
|  [ffw::Vec3](ffw_Vec3.html)< T > & | [rotateX](#afb73b48) (double _deg_)  |
|  [ffw::Vec3](ffw_Vec3.html)< T > & | [rotateY](#e79e0f62) (double _deg_)  |
|  [ffw::Vec3](ffw_Vec3.html)< T > & | [rotateZ](#1cd47d2c) (double _deg_)  |
|  [ffw::Vec3](ffw_Vec3.html)< T > & | [rotateXRad](#9f0f5c48) (double _rad_)  |
|  [ffw::Vec3](ffw_Vec3.html)< T > & | [rotateYRad](#1c536bc4) (double _rad_)  |
|  [ffw::Vec3](ffw_Vec3.html)< T > & | [rotateZRad](#bb26da74) (double _rad_)  |
|  [ffw::Vec3](ffw_Vec3.html)< T > & | [rotateByQuaternion](#59495d3f) (const [ffw::Quat](ffw_Quat.html)< S > & _quat_)  |
|  [ffw::Vec3](ffw_Vec3.html)< T > & | [normalize](#6e67f5d4) ()  |
|  [ffw::Vec3](ffw_Vec3.html)< T > & | [scale](#f0191e0e) (T _val_)  |
|  double | [length](#2f1632a1) () const  |
|  float | [lengthf](#1b455bbe) () const  |
|  T | [lengthSqrd](#74bd32fe) () const  |
|  T & | [operator[]](#d2550245) (size_t _i_)  |
|  const T & | [operator[]](#c0c868c7) (size_t _i_) const  |
|   | [operator ffw::Vec3< S >](#1a0119fe) () const  |
|  [Vec3](ffw_Vec3.html)< T > | [round](#789c0b31) () const  |
|  [Vec3](ffw_Vec3.html)< T > | [floor](#50a828f8) () const  |
|  [Vec3](ffw_Vec3.html)< T > | [ceil](#592abb7c) () const  |
|  bool | [operator==](#04ae56d2) (const [Vec3](ffw_Vec3.html)< float > & _vec_) const  |
|  bool | [operator==](#cfc22b49) (const [Vec3](ffw_Vec3.html)< double > & _vec_) const  |


## Public Attributes Documentation

### <span style="opacity:0.5;">variable</span> <a id="37cde167" href="#37cde167">x</a>

```cpp
T x
```



### <span style="opacity:0.5;">variable</span> <a id="09579a12" href="#09579a12">y</a>

```cpp
T y
```



### <span style="opacity:0.5;">variable</span> <a id="9105e095" href="#9105e095">z</a>

```cpp
T z
```





## Public Functions Documentation

### <span style="opacity:0.5;">function</span> <a id="1693263b" href="#1693263b">Vec3</a>

```cpp
inline  Vec3 () 
```



### <span style="opacity:0.5;">function</span> <a id="b1d4eb0a" href="#b1d4eb0a">Vec3</a>

```cpp
inline  Vec3 (
    T compx,
    T compy,
    T compz
) 
```



### <span style="opacity:0.5;">function</span> <a id="d5eae5ca" href="#d5eae5ca">Vec3</a>

```cpp
inline  Vec3 (
    T Value
) 
```



### <span style="opacity:0.5;">function</span> <a id="23b20ae9" href="#23b20ae9">Vec3</a>

```cpp
inline  Vec3 (
    const Vec3< T > & vec
) 
```



### <span style="opacity:0.5;">function</span> <a id="64b9cec1" href="#64b9cec1">Vec3</a>

```cpp
inline  Vec3 (
    const std::initializer_list< T > & list
) 
```



### <span style="opacity:0.5;">function</span> <a id="b50315a5" href="#b50315a5">set</a>

```cpp
inline void set (
    T compx,
    T compy,
    T compz
) 
```



### <span style="opacity:0.5;">function</span> <a id="1e664b24" href="#1e664b24">set</a>

```cpp
inline void set (
    T Value
) 
```



### <span style="opacity:0.5;">function</span> <a id="cca3b619" href="#cca3b619">set</a>

```cpp
inline void set (
    const Vec3< T > & vec
) 
```



### <span style="opacity:0.5;">function</span> <a id="26cb70a2" href="#26cb70a2">set</a>

```cpp
inline void set (
    const std::initializer_list< T > & list
) 
```



### <span style="opacity:0.5;">function</span> <a id="da695ef1" href="#da695ef1">operator-</a>

```cpp
inline ffw::Vec3< T > operator- () const 
```



### <span style="opacity:0.5;">function</span> <a id="566ee37e" href="#566ee37e">operator=</a>

```cpp
inline ffw::Vec3< T > & operator= (
    const Vec3< T > & vec
) 
```



### <span style="opacity:0.5;">function</span> <a id="6b5af011" href="#6b5af011">operator+</a>

```cpp
inline ffw::Vec3< T > operator+ (
    const Vec3< T > & vec
) const 
```



### <span style="opacity:0.5;">function</span> <a id="a2e85559" href="#a2e85559">operator+=</a>

```cpp
inline ffw::Vec3< T > & operator+= (
    const Vec3< T > & vec
) 
```



### <span style="opacity:0.5;">function</span> <a id="761776e7" href="#761776e7">operator-</a>

```cpp
inline ffw::Vec3< T > operator- (
    const Vec3< T > & vec
) const 
```



### <span style="opacity:0.5;">function</span> <a id="19140f89" href="#19140f89">operator-=</a>

```cpp
inline ffw::Vec3< T > & operator-= (
    const Vec3< T > & vec
) 
```



### <span style="opacity:0.5;">function</span> <a id="c8baf9d8" href="#c8baf9d8">operator/</a>

```cpp
inline ffw::Vec3< T > operator/ (
    const Vec3< T > & vec
) const 
```



### <span style="opacity:0.5;">function</span> <a id="7112ac87" href="#7112ac87">operator/=</a>

```cpp
inline ffw::Vec3< T > & operator/= (
    const Vec3< T > & vec
) 
```



### <span style="opacity:0.5;">function</span> <a id="8fe86d2c" href="#8fe86d2c">operator*</a>

```cpp
inline ffw::Vec3< T > operator* (
    const Vec3< T > & vec
) const 
```



### <span style="opacity:0.5;">function</span> <a id="b7121412" href="#b7121412">operator*=</a>

```cpp
inline ffw::Vec3< T > & operator*= (
    const Vec3< T > & vec
) 
```



### <span style="opacity:0.5;">function</span> <a id="fb45de75" href="#fb45de75">operator=</a>

```cpp
inline ffw::Vec3< T > & operator= (
    const T & val
) 
```



### <span style="opacity:0.5;">function</span> <a id="3f5dfa51" href="#3f5dfa51">operator+</a>

```cpp
inline ffw::Vec3< T > operator+ (
    const T & val
) const 
```



### <span style="opacity:0.5;">function</span> <a id="28f8aeb5" href="#28f8aeb5">operator+=</a>

```cpp
inline ffw::Vec3< T > & operator+= (
    const T & val
) 
```



### <span style="opacity:0.5;">function</span> <a id="a51adcaa" href="#a51adcaa">operator-</a>

```cpp
inline ffw::Vec3< T > operator- (
    const T & val
) const 
```



### <span style="opacity:0.5;">function</span> <a id="f4a05210" href="#f4a05210">operator-=</a>

```cpp
inline ffw::Vec3< T > & operator-= (
    const T & val
) 
```



### <span style="opacity:0.5;">function</span> <a id="dbb52ff0" href="#dbb52ff0">operator/</a>

```cpp
inline ffw::Vec3< T > operator/ (
    const T & val
) const 
```



### <span style="opacity:0.5;">function</span> <a id="8098da86" href="#8098da86">operator/=</a>

```cpp
inline ffw::Vec3< T > & operator/= (
    const T & val
) 
```



### <span style="opacity:0.5;">function</span> <a id="09965989" href="#09965989">operator*</a>

```cpp
inline ffw::Vec3< T > operator* (
    const T & val
) const 
```



### <span style="opacity:0.5;">function</span> <a id="bf5f60e4" href="#bf5f60e4">operator*=</a>

```cpp
inline ffw::Vec3< T > & operator*= (
    const T & val
) 
```



### <span style="opacity:0.5;">function</span> <a id="fe96e57d" href="#fe96e57d">operator!=</a>

```cpp
inline bool operator!= (
    const Vec3< T > & vec
) const 
```



### <span style="opacity:0.5;">function</span> <a id="18845606" href="#18845606">operator==</a>

```cpp
inline bool operator== (
    const Vec3< T > & vec
) const 
```



### <span style="opacity:0.5;">function</span> <a id="982aa729" href="#982aa729">rotateByAxis</a>

```cpp
inline ffw::Vec3< T > & rotateByAxis (
    double deg,
    Vec3< T > axis
) 
```



### <span style="opacity:0.5;">function</span> <a id="ba278b23" href="#ba278b23">rotateByAxisRad</a>

```cpp
inline ffw::Vec3< T > & rotateByAxisRad (
    double rad,
    Vec3< T > axis
) 
```



### <span style="opacity:0.5;">function</span> <a id="afb73b48" href="#afb73b48">rotateX</a>

```cpp
inline ffw::Vec3< T > & rotateX (
    double deg
) 
```



### <span style="opacity:0.5;">function</span> <a id="e79e0f62" href="#e79e0f62">rotateY</a>

```cpp
inline ffw::Vec3< T > & rotateY (
    double deg
) 
```



### <span style="opacity:0.5;">function</span> <a id="1cd47d2c" href="#1cd47d2c">rotateZ</a>

```cpp
inline ffw::Vec3< T > & rotateZ (
    double deg
) 
```



### <span style="opacity:0.5;">function</span> <a id="9f0f5c48" href="#9f0f5c48">rotateXRad</a>

```cpp
inline ffw::Vec3< T > & rotateXRad (
    double rad
) 
```



### <span style="opacity:0.5;">function</span> <a id="1c536bc4" href="#1c536bc4">rotateYRad</a>

```cpp
inline ffw::Vec3< T > & rotateYRad (
    double rad
) 
```



### <span style="opacity:0.5;">function</span> <a id="bb26da74" href="#bb26da74">rotateZRad</a>

```cpp
inline ffw::Vec3< T > & rotateZRad (
    double rad
) 
```



### <span style="opacity:0.5;">function</span> <a id="59495d3f" href="#59495d3f">rotateByQuaternion</a>

```cpp
inline ffw::Vec3< T > & rotateByQuaternion (
    const ffw::Quat< S > & quat
) 
```



### <span style="opacity:0.5;">function</span> <a id="6e67f5d4" href="#6e67f5d4">normalize</a>

```cpp
inline ffw::Vec3< T > & normalize () 
```



### <span style="opacity:0.5;">function</span> <a id="f0191e0e" href="#f0191e0e">scale</a>

```cpp
inline ffw::Vec3< T > & scale (
    T val
) 
```



### <span style="opacity:0.5;">function</span> <a id="2f1632a1" href="#2f1632a1">length</a>

```cpp
inline double length () const 
```



### <span style="opacity:0.5;">function</span> <a id="1b455bbe" href="#1b455bbe">lengthf</a>

```cpp
inline float lengthf () const 
```



### <span style="opacity:0.5;">function</span> <a id="74bd32fe" href="#74bd32fe">lengthSqrd</a>

```cpp
inline T lengthSqrd () const 
```



### <span style="opacity:0.5;">function</span> <a id="d2550245" href="#d2550245">operator[]</a>

```cpp
inline T & operator[] (
    size_t i
) 
```



### <span style="opacity:0.5;">function</span> <a id="c0c868c7" href="#c0c868c7">operator[]</a>

```cpp
inline const T & operator[] (
    size_t i
) const 
```



### <span style="opacity:0.5;">function</span> <a id="1a0119fe" href="#1a0119fe">operator ffw::Vec3< S ></a>

```cpp
inline  operator ffw::Vec3< S > () const 
```



### <span style="opacity:0.5;">function</span> <a id="789c0b31" href="#789c0b31">round</a>

```cpp
inline Vec3< T > round () const 
```



### <span style="opacity:0.5;">function</span> <a id="50a828f8" href="#50a828f8">floor</a>

```cpp
inline Vec3< T > floor () const 
```



### <span style="opacity:0.5;">function</span> <a id="592abb7c" href="#592abb7c">ceil</a>

```cpp
inline Vec3< T > ceil () const 
```



### <span style="opacity:0.5;">function</span> <a id="04ae56d2" href="#04ae56d2">operator==</a>

```cpp
inline bool operator== (
    const Vec3< float > & vec
) const 
```



### <span style="opacity:0.5;">function</span> <a id="cfc22b49" href="#cfc22b49">operator==</a>

```cpp
inline bool operator== (
    const Vec3< double > & vec
) const 
```





