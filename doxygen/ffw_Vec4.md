Vec4
===================================


The documentation for this struct was generated from: `include/ffw/math/vec4.h`



## Public Attributes

| Type | Name |
| -------: | :------- |
|  T | [x](#a33aa52a) |
|  T | [y](#5c9e82f0) |
|  T | [z](#20bc5b4d) |
|  T | [w](#e51ad539) |


## Public Functions

| Type | Name |
| -------: | :------- |
|   | [Vec4](#5af4eb32) ()  |
|   | [Vec4](#73d0271d) (T _compx_, T _compy_, T _compz_, T _compw_)  |
|   | [Vec4](#85265dff) (T _val_)  |
|   | [Vec4](#a21d268b) (const [Vec4](ffw_Vec4.html)< T > & _vec_)  |
|   | [Vec4](#b02b25ba) (const std::initializer_list< T > & _list_)  |
|  void | [set](#984efb39) (T _compx_, T _compy_, T _compz_, T _compw_)  |
|  void | [set](#edbc194f) (T _val_)  |
|  void | [set](#f6a3eaf1) (const [Vec4](ffw_Vec4.html)< T > & _vec_)  |
|  void | [set](#3fd2a868) (const std::initializer_list< T > & _list_)  |
|  [ffw::Vec4](ffw_Vec4.html)< T > | [operator-](#1543f381) () const  |
|  [ffw::Vec4](ffw_Vec4.html)< T > & | [operator=](#cb5cf2ad) (const [Vec4](ffw_Vec4.html)< T > & _vec_)  |
|  [ffw::Vec4](ffw_Vec4.html)< T > | [operator+](#fc6538fc) (const [Vec4](ffw_Vec4.html)< T > & _vec_) const  |
|  [ffw::Vec4](ffw_Vec4.html)< T > & | [operator+=](#5d97131e) (const [Vec4](ffw_Vec4.html)< T > & _vec_)  |
|  [ffw::Vec4](ffw_Vec4.html)< T > | [operator-](#dac45f69) (const [Vec4](ffw_Vec4.html)< T > & _vec_) const  |
|  [ffw::Vec4](ffw_Vec4.html)< T > & | [operator-=](#712758fd) (const [Vec4](ffw_Vec4.html)< T > & _vec_)  |
|  [ffw::Vec4](ffw_Vec4.html)< T > | [operator/](#516f41de) (const [Vec4](ffw_Vec4.html)< T > & _vec_) const  |
|  [ffw::Vec4](ffw_Vec4.html)< T > & | [operator/=](#60673e70) (const [Vec4](ffw_Vec4.html)< T > & _vec_)  |
|  [ffw::Vec4](ffw_Vec4.html)< T > | [operator*](#f7d36b27) (const [Vec4](ffw_Vec4.html)< T > & _vec_) const  |
|  [ffw::Vec4](ffw_Vec4.html)< T > & | [operator*=](#bfbaf79d) (const [Vec4](ffw_Vec4.html)< T > & _vec_)  |
|  [ffw::Vec4](ffw_Vec4.html)< T > & | [operator=](#068ffebf) (const T & _val_)  |
|  [ffw::Vec4](ffw_Vec4.html)< T > | [operator+](#a2b82e17) (const T & _val_) const  |
|  [ffw::Vec4](ffw_Vec4.html)< T > & | [operator+=](#26ce3c2b) (const T & _val_)  |
|  [ffw::Vec4](ffw_Vec4.html)< T > | [operator-](#9b6fdb9f) (const T & _val_) const  |
|  [ffw::Vec4](ffw_Vec4.html)< T > & | [operator-=](#135bc8b9) (const T & _val_)  |
|  [ffw::Vec4](ffw_Vec4.html)< T > | [operator/](#f5af97e4) (const T & _val_) const  |
|  [ffw::Vec4](ffw_Vec4.html)< T > & | [operator/=](#eccafc0d) (const T & _val_)  |
|  [ffw::Vec4](ffw_Vec4.html)< T > | [operator*](#2abdd2ca) (const T & _val_) const  |
|  [ffw::Vec4](ffw_Vec4.html)< T > & | [operator*=](#c358a9eb) (const T & _val_)  |
|  bool | [operator!=](#126014b6) (const [Vec4](ffw_Vec4.html)< T > & _vec_) const  |
|  bool | [operator==](#c35fd796) (const [Vec4](ffw_Vec4.html)< T > & _vec_) const  |
|  [ffw::Vec4](ffw_Vec4.html)< T > & | [normalize](#fbdf4667) ()  |
|  [ffw::Vec4](ffw_Vec4.html)< T > & | [scale](#d0da4533) (const T _val_)  |
|  double | [length](#faf493b1) () const  |
|  float | [lengthf](#2e9f9b46) () const  |
|  T | [lengthSqrd](#331fcd0f) () const  |
|  T & | [operator[]](#24349136) (size_t _i_)  |
|  const T & | [operator[]](#95747689) (size_t _i_) const  |
|   | [operator ffw::Vec4< S >](#f362ddc5) () const  |
|  [Vec4](ffw_Vec4.html)< T > | [round](#f178b84a) () const  |
|  [Vec4](ffw_Vec4.html)< T > | [floor](#dc52c271) () const  |
|  [Vec4](ffw_Vec4.html)< T > | [ceil](#afbeaef7) () const  |
|  bool | [operator==](#be855e8a) (const [Vec4](ffw_Vec4.html)< float > & _vec_) const  |
|  bool | [operator==](#5b308a41) (const [Vec4](ffw_Vec4.html)< double > & _vec_) const  |


## Public Attributes Documentation

### _variable_ <a id="a33aa52a" href="#a33aa52a">x</a>

```cpp
T x
```



### _variable_ <a id="5c9e82f0" href="#5c9e82f0">y</a>

```cpp
T y
```



### _variable_ <a id="20bc5b4d" href="#20bc5b4d">z</a>

```cpp
T z
```



### _variable_ <a id="e51ad539" href="#e51ad539">w</a>

```cpp
T w
```





## Public Functions Documentation

### _function_ <a id="5af4eb32" href="#5af4eb32">Vec4</a>

```cpp
inline  Vec4 () 
```



### _function_ <a id="73d0271d" href="#73d0271d">Vec4</a>

```cpp
inline  Vec4 (
    T compx,
    T compy,
    T compz,
    T compw
) 
```



### _function_ <a id="85265dff" href="#85265dff">Vec4</a>

```cpp
inline  Vec4 (
    T val
) 
```



### _function_ <a id="a21d268b" href="#a21d268b">Vec4</a>

```cpp
inline  Vec4 (
    const Vec4< T > & vec
) 
```



### _function_ <a id="b02b25ba" href="#b02b25ba">Vec4</a>

```cpp
inline  Vec4 (
    const std::initializer_list< T > & list
) 
```



### _function_ <a id="984efb39" href="#984efb39">set</a>

```cpp
inline void set (
    T compx,
    T compy,
    T compz,
    T compw
) 
```



### _function_ <a id="edbc194f" href="#edbc194f">set</a>

```cpp
inline void set (
    T val
) 
```



### _function_ <a id="f6a3eaf1" href="#f6a3eaf1">set</a>

```cpp
inline void set (
    const Vec4< T > & vec
) 
```



### _function_ <a id="3fd2a868" href="#3fd2a868">set</a>

```cpp
inline void set (
    const std::initializer_list< T > & list
) 
```



### _function_ <a id="1543f381" href="#1543f381">operator-</a>

```cpp
inline ffw::Vec4< T > operator- () const 
```



### _function_ <a id="cb5cf2ad" href="#cb5cf2ad">operator=</a>

```cpp
inline ffw::Vec4< T > & operator= (
    const Vec4< T > & vec
) 
```



### _function_ <a id="fc6538fc" href="#fc6538fc">operator+</a>

```cpp
inline ffw::Vec4< T > operator+ (
    const Vec4< T > & vec
) const 
```



### _function_ <a id="5d97131e" href="#5d97131e">operator+=</a>

```cpp
inline ffw::Vec4< T > & operator+= (
    const Vec4< T > & vec
) 
```



### _function_ <a id="dac45f69" href="#dac45f69">operator-</a>

```cpp
inline ffw::Vec4< T > operator- (
    const Vec4< T > & vec
) const 
```



### _function_ <a id="712758fd" href="#712758fd">operator-=</a>

```cpp
inline ffw::Vec4< T > & operator-= (
    const Vec4< T > & vec
) 
```



### _function_ <a id="516f41de" href="#516f41de">operator/</a>

```cpp
inline ffw::Vec4< T > operator/ (
    const Vec4< T > & vec
) const 
```



### _function_ <a id="60673e70" href="#60673e70">operator/=</a>

```cpp
inline ffw::Vec4< T > & operator/= (
    const Vec4< T > & vec
) 
```



### _function_ <a id="f7d36b27" href="#f7d36b27">operator*</a>

```cpp
inline ffw::Vec4< T > operator* (
    const Vec4< T > & vec
) const 
```



### _function_ <a id="bfbaf79d" href="#bfbaf79d">operator*=</a>

```cpp
inline ffw::Vec4< T > & operator*= (
    const Vec4< T > & vec
) 
```



### _function_ <a id="068ffebf" href="#068ffebf">operator=</a>

```cpp
inline ffw::Vec4< T > & operator= (
    const T & val
) 
```



### _function_ <a id="a2b82e17" href="#a2b82e17">operator+</a>

```cpp
inline ffw::Vec4< T > operator+ (
    const T & val
) const 
```



### _function_ <a id="26ce3c2b" href="#26ce3c2b">operator+=</a>

```cpp
inline ffw::Vec4< T > & operator+= (
    const T & val
) 
```



### _function_ <a id="9b6fdb9f" href="#9b6fdb9f">operator-</a>

```cpp
inline ffw::Vec4< T > operator- (
    const T & val
) const 
```



### _function_ <a id="135bc8b9" href="#135bc8b9">operator-=</a>

```cpp
inline ffw::Vec4< T > & operator-= (
    const T & val
) 
```



### _function_ <a id="f5af97e4" href="#f5af97e4">operator/</a>

```cpp
inline ffw::Vec4< T > operator/ (
    const T & val
) const 
```



### _function_ <a id="eccafc0d" href="#eccafc0d">operator/=</a>

```cpp
inline ffw::Vec4< T > & operator/= (
    const T & val
) 
```



### _function_ <a id="2abdd2ca" href="#2abdd2ca">operator*</a>

```cpp
inline ffw::Vec4< T > operator* (
    const T & val
) const 
```



### _function_ <a id="c358a9eb" href="#c358a9eb">operator*=</a>

```cpp
inline ffw::Vec4< T > & operator*= (
    const T & val
) 
```



### _function_ <a id="126014b6" href="#126014b6">operator!=</a>

```cpp
inline bool operator!= (
    const Vec4< T > & vec
) const 
```



### _function_ <a id="c35fd796" href="#c35fd796">operator==</a>

```cpp
inline bool operator== (
    const Vec4< T > & vec
) const 
```



### _function_ <a id="fbdf4667" href="#fbdf4667">normalize</a>

```cpp
inline ffw::Vec4< T > & normalize () 
```



### _function_ <a id="d0da4533" href="#d0da4533">scale</a>

```cpp
inline ffw::Vec4< T > & scale (
    const T val
) 
```



### _function_ <a id="faf493b1" href="#faf493b1">length</a>

```cpp
inline double length () const 
```



### _function_ <a id="2e9f9b46" href="#2e9f9b46">lengthf</a>

```cpp
inline float lengthf () const 
```



### _function_ <a id="331fcd0f" href="#331fcd0f">lengthSqrd</a>

```cpp
inline T lengthSqrd () const 
```



### _function_ <a id="24349136" href="#24349136">operator[]</a>

```cpp
inline T & operator[] (
    size_t i
) 
```



### _function_ <a id="95747689" href="#95747689">operator[]</a>

```cpp
inline const T & operator[] (
    size_t i
) const 
```



### _function_ <a id="f362ddc5" href="#f362ddc5">operator ffw::Vec4< S ></a>

```cpp
inline  operator ffw::Vec4< S > () const 
```



### _function_ <a id="f178b84a" href="#f178b84a">round</a>

```cpp
inline Vec4< T > round () const 
```



### _function_ <a id="dc52c271" href="#dc52c271">floor</a>

```cpp
inline Vec4< T > floor () const 
```



### _function_ <a id="afbeaef7" href="#afbeaef7">ceil</a>

```cpp
inline Vec4< T > ceil () const 
```



### _function_ <a id="be855e8a" href="#be855e8a">operator==</a>

```cpp
inline bool operator== (
    const Vec4< float > & vec
) const 
```



### _function_ <a id="5b308a41" href="#5b308a41">operator==</a>

```cpp
inline bool operator== (
    const Vec4< double > & vec
) const 
```





