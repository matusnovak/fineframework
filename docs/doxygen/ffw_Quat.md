Quat
===================================


The documentation for this struct was generated from: `include/ffw/math/quaternion.h`



## Public Attributes

| Type | Name |
| -------: | :------- |
|  T | [x](#8ce8e492) |
|  T | [y](#a8b53932) |
|  T | [z](#c3b8df37) |
|  T | [w](#c91b3cbb) |


## Public Functions

| Type | Name |
| -------: | :------- |
|   | [Quat](#6eee787b) ()  |
|   | [Quat](#e72f4f0b) (T _X_, T _Y_, T _Z_, T _W_)  |
|   | [Quat](#41aacb95) (const [Quat](ffw_Quat.html) & _q_)  |
|  void | [set](#34223826) (T _X_, T _Y_, T _Z_, T _W_)  |
|  void | [set](#95c02aea) (const [Quat](ffw_Quat.html) & _q_)  |
|  [ffw::Quat](ffw_Quat.html)< T > & | [rotate](#f962f22b) (T _Deg_, T _X_, T _Y_, T _Z_)  |
|  [ffw::Quat](ffw_Quat.html)< T > & | [rotateRad](#57aa069c) (T _Rad_, T _X_, T _Y_, T _Z_)  |
|  [ffw::Quat](ffw_Quat.html)< T > | [operator-](#261cc9be) () const  |
|  [ffw::Quat](ffw_Quat.html)< T > | [operator*](#87cd9300) (const [Quat](ffw_Quat.html) & _q_) const  |
|  [ffw::Quat](ffw_Quat.html)< T > & | [operator*=](#6484a823) (const [Quat](ffw_Quat.html) & _q_)  |
|  [ffw::Quat](ffw_Quat.html)< T > | [operator*](#96c827d4) (T _Value_) const  |
|  [ffw::Quat](ffw_Quat.html)< T > & | [operator*=](#a1be4016) (T _Value_)  |
|  [ffw::Quat](ffw_Quat.html)< T > | [operator+](#2fa98a4d) (const [Quat](ffw_Quat.html) & _q_) const  |
|  [ffw::Quat](ffw_Quat.html)< T > & | [operator+=](#3a800830) (const [Quat](ffw_Quat.html) & _q_)  |
|  [ffw::Quat](ffw_Quat.html)< T > | [operator-](#4dc7ee53) (const [Quat](ffw_Quat.html) & _q_) const  |
|  [ffw::Quat](ffw_Quat.html)< T > & | [operator-=](#9b5f46c3) (const [Quat](ffw_Quat.html) & _q_)  |
|  [ffw::Quat](ffw_Quat.html)< T > | [operator/](#2b417d5f) (T _Value_) const  |
|  [ffw::Quat](ffw_Quat.html)< T > & | [operator/=](#b010f714) (T _Value_)  |
|  void | [normalize](#c03cd0c5) ()  |
|  void | [getEuler](#177a6837) (T * _Roll_, T * _Pitch_, T * _Yaw_) const  |
|  float | [length](#f6c395aa) () const  |
|  float | [lengthSqrd](#a41030f9) () const  |
|  [ffw::Quat](ffw_Quat.html)< T > | [getConjugate](#43ca8928) () const  |
|  [ffw::Quat](ffw_Quat.html)< T > | [getInversed](#64aa3ea2) () const  |
|  [ffw::Quat](ffw_Quat.html)< T > & | [inverse](#7f270387) ()  |


## Public Attributes Documentation

### _variable_ <a id="8ce8e492" href="#8ce8e492">x</a>

```cpp
T x
```



### _variable_ <a id="a8b53932" href="#a8b53932">y</a>

```cpp
T y
```



### _variable_ <a id="c3b8df37" href="#c3b8df37">z</a>

```cpp
T z
```



### _variable_ <a id="c91b3cbb" href="#c91b3cbb">w</a>

```cpp
T w
```





## Public Functions Documentation

### _function_ <a id="6eee787b" href="#6eee787b">Quat</a>

```cpp
inline  Quat () 
```



### _function_ <a id="e72f4f0b" href="#e72f4f0b">Quat</a>

```cpp
inline  Quat (
    T X,
    T Y,
    T Z,
    T W
) 
```



### _function_ <a id="41aacb95" href="#41aacb95">Quat</a>

```cpp
inline  Quat (
    const Quat & q
) 
```



### _function_ <a id="34223826" href="#34223826">set</a>

```cpp
inline void set (
    T X,
    T Y,
    T Z,
    T W
) 
```



### _function_ <a id="95c02aea" href="#95c02aea">set</a>

```cpp
inline void set (
    const Quat & q
) 
```



### _function_ <a id="f962f22b" href="#f962f22b">rotate</a>

```cpp
inline ffw::Quat< T > & rotate (
    T Deg,
    T X,
    T Y,
    T Z
) 
```



### _function_ <a id="57aa069c" href="#57aa069c">rotateRad</a>

```cpp
inline ffw::Quat< T > & rotateRad (
    T Rad,
    T X,
    T Y,
    T Z
) 
```



### _function_ <a id="261cc9be" href="#261cc9be">operator-</a>

```cpp
inline ffw::Quat< T > operator- () const 
```



### _function_ <a id="87cd9300" href="#87cd9300">operator*</a>

```cpp
inline ffw::Quat< T > operator* (
    const Quat & q
) const 
```



### _function_ <a id="6484a823" href="#6484a823">operator*=</a>

```cpp
inline ffw::Quat< T > & operator*= (
    const Quat & q
) 
```



### _function_ <a id="96c827d4" href="#96c827d4">operator*</a>

```cpp
inline ffw::Quat< T > operator* (
    T Value
) const 
```



### _function_ <a id="a1be4016" href="#a1be4016">operator*=</a>

```cpp
inline ffw::Quat< T > & operator*= (
    T Value
) 
```



### _function_ <a id="2fa98a4d" href="#2fa98a4d">operator+</a>

```cpp
inline ffw::Quat< T > operator+ (
    const Quat & q
) const 
```



### _function_ <a id="3a800830" href="#3a800830">operator+=</a>

```cpp
inline ffw::Quat< T > & operator+= (
    const Quat & q
) 
```



### _function_ <a id="4dc7ee53" href="#4dc7ee53">operator-</a>

```cpp
inline ffw::Quat< T > operator- (
    const Quat & q
) const 
```



### _function_ <a id="9b5f46c3" href="#9b5f46c3">operator-=</a>

```cpp
inline ffw::Quat< T > & operator-= (
    const Quat & q
) 
```



### _function_ <a id="2b417d5f" href="#2b417d5f">operator/</a>

```cpp
inline ffw::Quat< T > operator/ (
    T Value
) const 
```



### _function_ <a id="b010f714" href="#b010f714">operator/=</a>

```cpp
inline ffw::Quat< T > & operator/= (
    T Value
) 
```



### _function_ <a id="c03cd0c5" href="#c03cd0c5">normalize</a>

```cpp
inline void normalize () 
```



### _function_ <a id="177a6837" href="#177a6837">getEuler</a>

```cpp
inline void getEuler (
    T * Roll,
    T * Pitch,
    T * Yaw
) const 
```



### _function_ <a id="f6c395aa" href="#f6c395aa">length</a>

```cpp
inline float length () const 
```



### _function_ <a id="a41030f9" href="#a41030f9">lengthSqrd</a>

```cpp
inline float lengthSqrd () const 
```



### _function_ <a id="43ca8928" href="#43ca8928">getConjugate</a>

```cpp
inline ffw::Quat< T > getConjugate () const 
```



### _function_ <a id="64aa3ea2" href="#64aa3ea2">getInversed</a>

```cpp
inline ffw::Quat< T > getInversed () const 
```



### _function_ <a id="7f270387" href="#7f270387">inverse</a>

```cpp
inline ffw::Quat< T > & inverse () 
```





