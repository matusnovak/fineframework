Vec
===================================


The documentation for this class was generated from: `include/ffw/math/vecx.h`



## Public Attributes

| Type | Name |
| -------: | :------- |
|  std::array< T, S > | [arr](#aa927adf) |


## Public Functions

| Type | Name |
| -------: | :------- |
|   | [Vec](#7106411b) ()  |
|   | [Vec](#bc666dec) (T _val_)  |
|   | [Vec](#174b6c3f) (const std::initializer_list< T > & _list_)  |
|   | [Vec](#97162e5b) (const [Vec](ffw_Vec.html)< T, S > & _other_)  |
|   | [Vec](#48f89e7b) ([Vec](ffw_Vec.html)< T, S > && _other_)  |
|  void | [set](#35afaa80) (T _val_)  |
|  void | [set](#41c7fa2d) (const std::initializer_list< T > & _list_)  |
|  void | [set](#6b1008af) (const [Vec](ffw_Vec.html)< T, S > & _other_)  |
|  [ffw::Vec](ffw_Vec.html)< T, S > | [operator-](#2cbeeec3) () const  |
|  [ffw::Vec](ffw_Vec.html)< T, S > & | [operator=](#627b7603) (const [Vec](ffw_Vec.html)< T, S > & _vec_)  |
|  [ffw::Vec](ffw_Vec.html)< T, S > | [operator+](#a19c6e88) (const [Vec](ffw_Vec.html)< T, S > & _vec_) const  |
|  [ffw::Vec](ffw_Vec.html)< T, S > & | [operator+=](#91194ace) (const [Vec](ffw_Vec.html)< T, S > & _vec_)  |
|  [ffw::Vec](ffw_Vec.html)< T, S > | [operator-](#7fb0ebc6) (const [Vec](ffw_Vec.html)< T, S > & _vec_) const  |
|  [ffw::Vec](ffw_Vec.html)< T, S > & | [operator-=](#cd9631d7) (const [Vec](ffw_Vec.html)< T, S > & _vec_)  |
|  [ffw::Vec](ffw_Vec.html)< T, S > | [operator/](#26d062e6) (const [Vec](ffw_Vec.html)< T, S > & _vec_) const  |
|  [ffw::Vec](ffw_Vec.html)< T, S > & | [operator/=](#87ea77cd) (const [Vec](ffw_Vec.html)< T, S > & _vec_)  |
|  [ffw::Vec](ffw_Vec.html)< T, S > | [operator*](#58208944) (const [Vec](ffw_Vec.html)< T, S > & _vec_) const  |
|  [ffw::Vec](ffw_Vec.html)< T, S > & | [operator*=](#7cd68dc9) (const [Vec](ffw_Vec.html)< T, S > & _vec_)  |
|  [ffw::Vec](ffw_Vec.html)< T, S > & | [operator=](#e2bbfe77) (const T & _val_)  |
|  [ffw::Vec](ffw_Vec.html)< T, S > | [operator+](#e5e4e234) (const T & _val_) const  |
|  [ffw::Vec](ffw_Vec.html)< T, S > & | [operator+=](#ba04f1d4) (const T & _val_)  |
|  [ffw::Vec](ffw_Vec.html)< T, S > | [operator-](#c8a7aec6) (const T & _val_) const  |
|  [ffw::Vec](ffw_Vec.html)< T, S > & | [operator-=](#4a7a7a89) (const T & _val_)  |
|  [ffw::Vec](ffw_Vec.html)< T, S > | [operator/](#8a25e92b) (const T & _val_) const  |
|  [ffw::Vec](ffw_Vec.html)< T, S > & | [operator/=](#c7c77333) (const T & _val_)  |
|  [ffw::Vec](ffw_Vec.html)< T, S > | [operator*](#6258563a) (const T & _val_) const  |
|  [ffw::Vec](ffw_Vec.html)< T, S > & | [operator*=](#6af570a0) (const T & _val_)  |
|  bool | [operator!=](#cf6a3a80) (const [Vec](ffw_Vec.html)< T, S > & _vec_) const  |
|  bool | [operator==](#53f15e92) (const [Vec](ffw_Vec.html)< T, S > & _vec_) const  |
|  [ffw::Vec](ffw_Vec.html)< T, S > & | [normalize](#4d9a119a) ()  |
|  [ffw::Vec](ffw_Vec.html)< T, S > & | [scale](#2b9b955e) (T _factor_)  |
|  float | [lengthf](#26d98f30) () const  |
|  double | [length](#4c411e47) () const  |
|  T | [lengthSqrd](#6d3ccf8e) () const  |
|  T & | [operator[]](#6dc50c5d) (size_t _i_)  |
|  const T & | [operator[]](#bdfb681f) (size_t _i_) const  |
|   | [operator ffw::Vec< X, S >](#15402ebd) () const  |
|  [Vec](ffw_Vec.html)< T, S > | [round](#bf084a43) () const  |
|  [Vec](ffw_Vec.html)< T, S > | [floor](#196752cd) () const  |
|  [Vec](ffw_Vec.html)< T, S > | [ceil](#5e1e4f3e) () const  |


## Public Attributes Documentation

### _variable_ <a id="aa927adf" href="#aa927adf">arr</a>

```cpp
std::array< T, S > arr
```





## Public Functions Documentation

### _function_ <a id="7106411b" href="#7106411b">Vec</a>

```cpp
inline  Vec () 
```



### _function_ <a id="bc666dec" href="#bc666dec">Vec</a>

```cpp
inline  Vec (
    T val
) 
```



### _function_ <a id="174b6c3f" href="#174b6c3f">Vec</a>

```cpp
inline  Vec (
    const std::initializer_list< T > & list
) 
```



### _function_ <a id="97162e5b" href="#97162e5b">Vec</a>

```cpp
inline  Vec (
    const Vec< T, S > & other
) 
```



### _function_ <a id="48f89e7b" href="#48f89e7b">Vec</a>

```cpp
inline  Vec (
    Vec< T, S > && other
) 
```



### _function_ <a id="35afaa80" href="#35afaa80">set</a>

```cpp
inline void set (
    T val
) 
```



### _function_ <a id="41c7fa2d" href="#41c7fa2d">set</a>

```cpp
inline void set (
    const std::initializer_list< T > & list
) 
```



### _function_ <a id="6b1008af" href="#6b1008af">set</a>

```cpp
inline void set (
    const Vec< T, S > & other
) 
```



### _function_ <a id="2cbeeec3" href="#2cbeeec3">operator-</a>

```cpp
inline ffw::Vec< T, S > operator- () const 
```



### _function_ <a id="627b7603" href="#627b7603">operator=</a>

```cpp
inline ffw::Vec< T, S > & operator= (
    const Vec< T, S > & vec
) 
```



### _function_ <a id="a19c6e88" href="#a19c6e88">operator+</a>

```cpp
inline ffw::Vec< T, S > operator+ (
    const Vec< T, S > & vec
) const 
```



### _function_ <a id="91194ace" href="#91194ace">operator+=</a>

```cpp
inline ffw::Vec< T, S > & operator+= (
    const Vec< T, S > & vec
) 
```



### _function_ <a id="7fb0ebc6" href="#7fb0ebc6">operator-</a>

```cpp
inline ffw::Vec< T, S > operator- (
    const Vec< T, S > & vec
) const 
```



### _function_ <a id="cd9631d7" href="#cd9631d7">operator-=</a>

```cpp
inline ffw::Vec< T, S > & operator-= (
    const Vec< T, S > & vec
) 
```



### _function_ <a id="26d062e6" href="#26d062e6">operator/</a>

```cpp
inline ffw::Vec< T, S > operator/ (
    const Vec< T, S > & vec
) const 
```



### _function_ <a id="87ea77cd" href="#87ea77cd">operator/=</a>

```cpp
inline ffw::Vec< T, S > & operator/= (
    const Vec< T, S > & vec
) 
```



### _function_ <a id="58208944" href="#58208944">operator*</a>

```cpp
inline ffw::Vec< T, S > operator* (
    const Vec< T, S > & vec
) const 
```



### _function_ <a id="7cd68dc9" href="#7cd68dc9">operator*=</a>

```cpp
inline ffw::Vec< T, S > & operator*= (
    const Vec< T, S > & vec
) 
```



### _function_ <a id="e2bbfe77" href="#e2bbfe77">operator=</a>

```cpp
inline ffw::Vec< T, S > & operator= (
    const T & val
) 
```



### _function_ <a id="e5e4e234" href="#e5e4e234">operator+</a>

```cpp
inline ffw::Vec< T, S > operator+ (
    const T & val
) const 
```



### _function_ <a id="ba04f1d4" href="#ba04f1d4">operator+=</a>

```cpp
inline ffw::Vec< T, S > & operator+= (
    const T & val
) 
```



### _function_ <a id="c8a7aec6" href="#c8a7aec6">operator-</a>

```cpp
inline ffw::Vec< T, S > operator- (
    const T & val
) const 
```



### _function_ <a id="4a7a7a89" href="#4a7a7a89">operator-=</a>

```cpp
inline ffw::Vec< T, S > & operator-= (
    const T & val
) 
```



### _function_ <a id="8a25e92b" href="#8a25e92b">operator/</a>

```cpp
inline ffw::Vec< T, S > operator/ (
    const T & val
) const 
```



### _function_ <a id="c7c77333" href="#c7c77333">operator/=</a>

```cpp
inline ffw::Vec< T, S > & operator/= (
    const T & val
) 
```



### _function_ <a id="6258563a" href="#6258563a">operator*</a>

```cpp
inline ffw::Vec< T, S > operator* (
    const T & val
) const 
```



### _function_ <a id="6af570a0" href="#6af570a0">operator*=</a>

```cpp
inline ffw::Vec< T, S > & operator*= (
    const T & val
) 
```



### _function_ <a id="cf6a3a80" href="#cf6a3a80">operator!=</a>

```cpp
inline bool operator!= (
    const Vec< T, S > & vec
) const 
```



### _function_ <a id="53f15e92" href="#53f15e92">operator==</a>

```cpp
inline bool operator== (
    const Vec< T, S > & vec
) const 
```



### _function_ <a id="4d9a119a" href="#4d9a119a">normalize</a>

```cpp
inline ffw::Vec< T, S > & normalize () 
```



### _function_ <a id="2b9b955e" href="#2b9b955e">scale</a>

```cpp
inline ffw::Vec< T, S > & scale (
    T factor
) 
```



### _function_ <a id="26d98f30" href="#26d98f30">lengthf</a>

```cpp
inline float lengthf () const 
```



### _function_ <a id="4c411e47" href="#4c411e47">length</a>

```cpp
inline double length () const 
```



### _function_ <a id="6d3ccf8e" href="#6d3ccf8e">lengthSqrd</a>

```cpp
inline T lengthSqrd () const 
```



### _function_ <a id="6dc50c5d" href="#6dc50c5d">operator[]</a>

```cpp
inline T & operator[] (
    size_t i
) 
```



### _function_ <a id="bdfb681f" href="#bdfb681f">operator[]</a>

```cpp
inline const T & operator[] (
    size_t i
) const 
```



### _function_ <a id="15402ebd" href="#15402ebd">operator ffw::Vec< X, S ></a>

```cpp
inline  operator ffw::Vec< X, S > () const 
```



### _function_ <a id="bf084a43" href="#bf084a43">round</a>

```cpp
inline Vec< T, S > round () const 
```



### _function_ <a id="196752cd" href="#196752cd">floor</a>

```cpp
inline Vec< T, S > floor () const 
```



### _function_ <a id="5e1e4f3e" href="#5e1e4f3e">ceil</a>

```cpp
inline Vec< T, S > ceil () const 
```





