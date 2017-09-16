Vec2
===================================


The documentation for this struct was generated from: `include/ffw/math/vec2.h`



## Public Attributes

| Type | Name |
| -------: | :------- |
|  T | [x](#b2ccd122) |
|  T | [y](#370d6d90) |


## Public Functions

| Type | Name |
| -------: | :------- |
|   | [Vec2](#55998eb7) ()  |
|   | [Vec2](#63dd63a8) (T _compx_, T _compy_)  |
|   | [Vec2](#eaa24666) (T _Value_)  |
|   | [Vec2](#8a18c790) (const [Vec2](ffw_Vec2.html)< T > & _vec_)  |
|   | [Vec2](#593b20df) (std::initializer_list< T > _list_)  |
|  void | [set](#e49a9b9e) (T _compx_, T _compy_)  |
|  void | [set](#ad2a55f6) (T _Value_)  |
|  void | [set](#91d8483a) (const [Vec2](ffw_Vec2.html)< T > & _vec_)  |
|  void | [set](#8dd9ed8f) (const std::initializer_list< T > & _list_)  |
|  [ffw::Vec2](ffw_Vec2.html)< T > | [operator-](#f5bbd432) () const  |
|  [ffw::Vec2](ffw_Vec2.html)< T > & | [operator=](#b71a7527) (const [Vec2](ffw_Vec2.html)< T > & _vec_)  |
|  [ffw::Vec2](ffw_Vec2.html)< T > | [operator+](#d9341865) (const [Vec2](ffw_Vec2.html)< T > & _vec_) const  |
|  [ffw::Vec2](ffw_Vec2.html)< T > & | [operator+=](#2e38d858) (const [Vec2](ffw_Vec2.html)< T > & _vec_)  |
|  [ffw::Vec2](ffw_Vec2.html)< T > | [operator-](#70bfbfac) (const [Vec2](ffw_Vec2.html)< T > & _vec_) const  |
|  [ffw::Vec2](ffw_Vec2.html)< T > & | [operator-=](#20c61381) (const [Vec2](ffw_Vec2.html)< T > & _vec_)  |
|  [ffw::Vec2](ffw_Vec2.html)< T > | [operator/](#873343a5) (const [Vec2](ffw_Vec2.html)< T > & _vec_) const  |
|  [ffw::Vec2](ffw_Vec2.html)< T > & | [operator/=](#82a0824a) (const [Vec2](ffw_Vec2.html)< T > & _vec_)  |
|  [ffw::Vec2](ffw_Vec2.html)< T > | [operator*](#46a88ad5) (const [Vec2](ffw_Vec2.html)< T > & _vec_) const  |
|  [ffw::Vec2](ffw_Vec2.html)< T > & | [operator*=](#eabec3dd) (const [Vec2](ffw_Vec2.html)< T > & _vec_)  |
|  [ffw::Vec2](ffw_Vec2.html)< T > & | [operator=](#08f3bcf0) (const T & _val_)  |
|  [ffw::Vec2](ffw_Vec2.html)< T > | [operator+](#7d16dab1) (const T & _val_) const  |
|  [ffw::Vec2](ffw_Vec2.html)< T > & | [operator+=](#5886c2d4) (const T & _val_)  |
|  [ffw::Vec2](ffw_Vec2.html)< T > | [operator-](#df5d5bf9) (const T & _val_) const  |
|  [ffw::Vec2](ffw_Vec2.html)< T > & | [operator-=](#c1b157de) (const T & _val_)  |
|  [ffw::Vec2](ffw_Vec2.html)< T > | [operator/](#67a2f1bf) (const T & _val_) const  |
|  [ffw::Vec2](ffw_Vec2.html)< T > & | [operator/=](#0699fa0a) (const T & _val_)  |
|  [ffw::Vec2](ffw_Vec2.html)< T > | [operator*](#9e1c7b99) (const T & _val_) const  |
|  [ffw::Vec2](ffw_Vec2.html)< T > & | [operator*=](#634cb185) (const T & _val_)  |
|  bool | [operator!=](#9966e575) (const [Vec2](ffw_Vec2.html)< T > & _vec_) const  |
|  bool | [operator==](#94e4a2bc) (const [Vec2](ffw_Vec2.html)< T > & _vec_) const  |
|  [ffw::Vec2](ffw_Vec2.html)< T > & | [rotate](#dd178631) (double _deg_)  |
|  [ffw::Vec2](ffw_Vec2.html)< T > & | [rotateRad](#0378eb56) (double _rad_)  |
|  [ffw::Vec2](ffw_Vec2.html)< T > & | [normalize](#cd498889) ()  |
|  [ffw::Vec2](ffw_Vec2.html)< T > & | [scale](#780cfd6f) (T _val_)  |
|  double | [length](#38c7d4a7) () const  |
|  float | [lengthf](#777f5251) () const  |
|  T | [lengthSqrd](#de22a6f8) () const  |
|  T & | [operator[]](#58194e1f) (size_t _i_)  |
|  const T & | [operator[]](#277a59fc) (size_t _i_) const  |
|   | [operator ffw::Vec2< S >](#fd140ec8) () const  |
|  [Vec2](ffw_Vec2.html)< T > | [round](#21f4f3fb) () const  |
|  [Vec2](ffw_Vec2.html)< T > | [floor](#f26bd077) () const  |
|  [Vec2](ffw_Vec2.html)< T > | [ceil](#3006effd) () const  |
|  bool | [operator==](#fed7c9e0) (const [Vec2](ffw_Vec2.html)< float > & _vec_) const  |
|  bool | [operator==](#d413f83f) (const [Vec2](ffw_Vec2.html)< double > & _vec_) const  |


## Public Attributes Documentation

### <span style="opacity:0.5;">variable</span> <a id="b2ccd122" href="#b2ccd122">x</a>

```cpp
T x
```



### <span style="opacity:0.5;">variable</span> <a id="370d6d90" href="#370d6d90">y</a>

```cpp
T y
```





## Public Functions Documentation

### <span style="opacity:0.5;">function</span> <a id="55998eb7" href="#55998eb7">Vec2</a>

```cpp
inline  Vec2 () 
```



### <span style="opacity:0.5;">function</span> <a id="63dd63a8" href="#63dd63a8">Vec2</a>

```cpp
inline  Vec2 (
    T compx,
    T compy
) 
```



### <span style="opacity:0.5;">function</span> <a id="eaa24666" href="#eaa24666">Vec2</a>

```cpp
inline  Vec2 (
    T Value
) 
```



### <span style="opacity:0.5;">function</span> <a id="8a18c790" href="#8a18c790">Vec2</a>

```cpp
inline  Vec2 (
    const Vec2< T > & vec
) 
```



### <span style="opacity:0.5;">function</span> <a id="593b20df" href="#593b20df">Vec2</a>

```cpp
inline  Vec2 (
    std::initializer_list< T > list
) 
```



### <span style="opacity:0.5;">function</span> <a id="e49a9b9e" href="#e49a9b9e">set</a>

```cpp
inline void set (
    T compx,
    T compy
) 
```



### <span style="opacity:0.5;">function</span> <a id="ad2a55f6" href="#ad2a55f6">set</a>

```cpp
inline void set (
    T Value
) 
```



### <span style="opacity:0.5;">function</span> <a id="91d8483a" href="#91d8483a">set</a>

```cpp
inline void set (
    const Vec2< T > & vec
) 
```



### <span style="opacity:0.5;">function</span> <a id="8dd9ed8f" href="#8dd9ed8f">set</a>

```cpp
inline void set (
    const std::initializer_list< T > & list
) 
```



### <span style="opacity:0.5;">function</span> <a id="f5bbd432" href="#f5bbd432">operator-</a>

```cpp
inline ffw::Vec2< T > operator- () const 
```



### <span style="opacity:0.5;">function</span> <a id="b71a7527" href="#b71a7527">operator=</a>

```cpp
inline ffw::Vec2< T > & operator= (
    const Vec2< T > & vec
) 
```



### <span style="opacity:0.5;">function</span> <a id="d9341865" href="#d9341865">operator+</a>

```cpp
inline ffw::Vec2< T > operator+ (
    const Vec2< T > & vec
) const 
```



### <span style="opacity:0.5;">function</span> <a id="2e38d858" href="#2e38d858">operator+=</a>

```cpp
inline ffw::Vec2< T > & operator+= (
    const Vec2< T > & vec
) 
```



### <span style="opacity:0.5;">function</span> <a id="70bfbfac" href="#70bfbfac">operator-</a>

```cpp
inline ffw::Vec2< T > operator- (
    const Vec2< T > & vec
) const 
```



### <span style="opacity:0.5;">function</span> <a id="20c61381" href="#20c61381">operator-=</a>

```cpp
inline ffw::Vec2< T > & operator-= (
    const Vec2< T > & vec
) 
```



### <span style="opacity:0.5;">function</span> <a id="873343a5" href="#873343a5">operator/</a>

```cpp
inline ffw::Vec2< T > operator/ (
    const Vec2< T > & vec
) const 
```



### <span style="opacity:0.5;">function</span> <a id="82a0824a" href="#82a0824a">operator/=</a>

```cpp
inline ffw::Vec2< T > & operator/= (
    const Vec2< T > & vec
) 
```



### <span style="opacity:0.5;">function</span> <a id="46a88ad5" href="#46a88ad5">operator*</a>

```cpp
inline ffw::Vec2< T > operator* (
    const Vec2< T > & vec
) const 
```



### <span style="opacity:0.5;">function</span> <a id="eabec3dd" href="#eabec3dd">operator*=</a>

```cpp
inline ffw::Vec2< T > & operator*= (
    const Vec2< T > & vec
) 
```



### <span style="opacity:0.5;">function</span> <a id="08f3bcf0" href="#08f3bcf0">operator=</a>

```cpp
inline ffw::Vec2< T > & operator= (
    const T & val
) 
```



### <span style="opacity:0.5;">function</span> <a id="7d16dab1" href="#7d16dab1">operator+</a>

```cpp
inline ffw::Vec2< T > operator+ (
    const T & val
) const 
```



### <span style="opacity:0.5;">function</span> <a id="5886c2d4" href="#5886c2d4">operator+=</a>

```cpp
inline ffw::Vec2< T > & operator+= (
    const T & val
) 
```



### <span style="opacity:0.5;">function</span> <a id="df5d5bf9" href="#df5d5bf9">operator-</a>

```cpp
inline ffw::Vec2< T > operator- (
    const T & val
) const 
```



### <span style="opacity:0.5;">function</span> <a id="c1b157de" href="#c1b157de">operator-=</a>

```cpp
inline ffw::Vec2< T > & operator-= (
    const T & val
) 
```



### <span style="opacity:0.5;">function</span> <a id="67a2f1bf" href="#67a2f1bf">operator/</a>

```cpp
inline ffw::Vec2< T > operator/ (
    const T & val
) const 
```



### <span style="opacity:0.5;">function</span> <a id="0699fa0a" href="#0699fa0a">operator/=</a>

```cpp
inline ffw::Vec2< T > & operator/= (
    const T & val
) 
```



### <span style="opacity:0.5;">function</span> <a id="9e1c7b99" href="#9e1c7b99">operator*</a>

```cpp
inline ffw::Vec2< T > operator* (
    const T & val
) const 
```



### <span style="opacity:0.5;">function</span> <a id="634cb185" href="#634cb185">operator*=</a>

```cpp
inline ffw::Vec2< T > & operator*= (
    const T & val
) 
```



### <span style="opacity:0.5;">function</span> <a id="9966e575" href="#9966e575">operator!=</a>

```cpp
inline bool operator!= (
    const Vec2< T > & vec
) const 
```



### <span style="opacity:0.5;">function</span> <a id="94e4a2bc" href="#94e4a2bc">operator==</a>

```cpp
inline bool operator== (
    const Vec2< T > & vec
) const 
```



### <span style="opacity:0.5;">function</span> <a id="dd178631" href="#dd178631">rotate</a>

```cpp
inline ffw::Vec2< T > & rotate (
    double deg
) 
```



### <span style="opacity:0.5;">function</span> <a id="0378eb56" href="#0378eb56">rotateRad</a>

```cpp
inline ffw::Vec2< T > & rotateRad (
    double rad
) 
```



### <span style="opacity:0.5;">function</span> <a id="cd498889" href="#cd498889">normalize</a>

```cpp
inline ffw::Vec2< T > & normalize () 
```



### <span style="opacity:0.5;">function</span> <a id="780cfd6f" href="#780cfd6f">scale</a>

```cpp
inline ffw::Vec2< T > & scale (
    T val
) 
```



### <span style="opacity:0.5;">function</span> <a id="38c7d4a7" href="#38c7d4a7">length</a>

```cpp
inline double length () const 
```



### <span style="opacity:0.5;">function</span> <a id="777f5251" href="#777f5251">lengthf</a>

```cpp
inline float lengthf () const 
```



### <span style="opacity:0.5;">function</span> <a id="de22a6f8" href="#de22a6f8">lengthSqrd</a>

```cpp
inline T lengthSqrd () const 
```



### <span style="opacity:0.5;">function</span> <a id="58194e1f" href="#58194e1f">operator[]</a>

```cpp
inline T & operator[] (
    size_t i
) 
```



### <span style="opacity:0.5;">function</span> <a id="277a59fc" href="#277a59fc">operator[]</a>

```cpp
inline const T & operator[] (
    size_t i
) const 
```



### <span style="opacity:0.5;">function</span> <a id="fd140ec8" href="#fd140ec8">operator ffw::Vec2< S ></a>

```cpp
inline  operator ffw::Vec2< S > () const 
```



### <span style="opacity:0.5;">function</span> <a id="21f4f3fb" href="#21f4f3fb">round</a>

```cpp
inline Vec2< T > round () const 
```



### <span style="opacity:0.5;">function</span> <a id="f26bd077" href="#f26bd077">floor</a>

```cpp
inline Vec2< T > floor () const 
```



### <span style="opacity:0.5;">function</span> <a id="3006effd" href="#3006effd">ceil</a>

```cpp
inline Vec2< T > ceil () const 
```



### <span style="opacity:0.5;">function</span> <a id="fed7c9e0" href="#fed7c9e0">operator==</a>

```cpp
inline bool operator== (
    const Vec2< float > & vec
) const 
```



### <span style="opacity:0.5;">function</span> <a id="d413f83f" href="#d413f83f">operator==</a>

```cpp
inline bool operator== (
    const Vec2< double > & vec
) const 
```





