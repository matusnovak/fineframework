Mat4x4
===================================


The documentation for this struct was generated from: `include/ffw/math/mat4.h`



## Public Attributes

| Type | Name |
| -------: | :------- |
|  T | [ptr](#1cedf770) |


## Public Functions

| Type | Name |
| -------: | :------- |
|   | [Mat4x4](#bba2c0bc) ()  |
|   | [Mat4x4](#dd3f0259) (T _xx_, T _yx_, T _zx_, T _wx_, T _xy_, T _yy_, T _zy_, T _wy_, T _xz_, T _yz_, T _zz_, T _wz_, T _xw_, T _yw_, T _zw_, T _ww_)  |
|   | [Mat4x4](#e418c82e) (T _Val_)  |
|   | [Mat4x4](#946b3909) (std::initializer_list< T > _List_)  |
|  void | [set](#a5c8140f) (T _xx_, T _yx_, T _zx_, T _wx_, T _xy_, T _yy_, T _zy_, T _wy_, T _xz_, T _yz_, T _zz_, T _wz_, T _xw_, T _yw_, T _zw_, T _ww_)  |
|  void | [set](#0f831f87) (T _Val_)  |
|  void | [set](#9bb2d44a) (T _m_)  |
|  void | [set](#2b77d1f6) (std::initializer_list< T > _List_)  |
|  T * | [getPtr](#38ae1a38) ()  |
|  const T * | [getPtr](#2be9edc6) () const  |
|  [ffw::Mat4x4](ffw_Mat4x4.html)< T > & | [operator=](#9991ad3e) (const [ffw::Mat4x4](ffw_Mat4x4.html)< T > & _m_)  |
|  [ffw::Mat4x4](ffw_Mat4x4.html)< T > | [operator*](#a7ebde46) (const [ffw::Mat4x4](ffw_Mat4x4.html)< T > & _m_) const  |
|  [ffw::Mat4x4](ffw_Mat4x4.html)< T > & | [operator*=](#5eed972e) (const [ffw::Mat4x4](ffw_Mat4x4.html)< T > & _m_)  |
|  [ffw::Vec4](ffw_Vec4.html)< S > | [operator*](#edb84143) (const [ffw::Vec4](ffw_Vec4.html)< S > & _V_) const  |
|  [ffw::Vec3](ffw_Vec3.html)< S > | [operator*](#e53e73b8) (const [ffw::Vec3](ffw_Vec3.html)< S > & _V_) const  |
|  T & | [operator[]](#79e25541) (int _x_)  |
|  const T & | [operator[]](#fdd33926) (int _x_) const  |
|  [ffw::Mat4x4](ffw_Mat4x4.html)< T > & | [rotate](#83159838) (const [ffw::Quat](ffw_Quat.html)< T > & _Q_)  |
|  [ffw::Mat4x4](ffw_Mat4x4.html)< T > & | [translate](#46f81662) (T _X_, T _Y_, T _Z_)  |
|  [ffw::Mat4x4](ffw_Mat4x4.html)< T > & | [scale](#93910356) (T _X_, T _Y_, T _Z_)  |
|  [ffw::Mat4x4](ffw_Mat4x4.html)< T > & | [transpose](#4208fa27) ()  |
|  [ffw::Mat4x4](ffw_Mat4x4.html)< T > & | [inverse](#f3d3291e) ()  |


## Public Attributes Documentation

### _variable_ <a id="1cedf770" href="#1cedf770">ptr</a>

```cpp
T ptr
```





## Public Functions Documentation

### _function_ <a id="bba2c0bc" href="#bba2c0bc">Mat4x4</a>

```cpp
inline  Mat4x4 () 
```



### _function_ <a id="dd3f0259" href="#dd3f0259">Mat4x4</a>

```cpp
inline  Mat4x4 (
    T xx,
    T yx,
    T zx,
    T wx,
    T xy,
    T yy,
    T zy,
    T wy,
    T xz,
    T yz,
    T zz,
    T wz,
    T xw,
    T yw,
    T zw,
    T ww
) 
```



### _function_ <a id="e418c82e" href="#e418c82e">Mat4x4</a>

```cpp
inline  Mat4x4 (
    T Val
) 
```



### _function_ <a id="946b3909" href="#946b3909">Mat4x4</a>

```cpp
inline  Mat4x4 (
    std::initializer_list< T > List
) 
```



### _function_ <a id="a5c8140f" href="#a5c8140f">set</a>

```cpp
inline void set (
    T xx,
    T yx,
    T zx,
    T wx,
    T xy,
    T yy,
    T zy,
    T wy,
    T xz,
    T yz,
    T zz,
    T wz,
    T xw,
    T yw,
    T zw,
    T ww
) 
```



### _function_ <a id="0f831f87" href="#0f831f87">set</a>

```cpp
inline void set (
    T Val
) 
```



### _function_ <a id="9bb2d44a" href="#9bb2d44a">set</a>

```cpp
inline void set (
    T m
) 
```



### _function_ <a id="2b77d1f6" href="#2b77d1f6">set</a>

```cpp
inline void set (
    std::initializer_list< T > List
) 
```



### _function_ <a id="38ae1a38" href="#38ae1a38">getPtr</a>

```cpp
inline T * getPtr () 
```



### _function_ <a id="2be9edc6" href="#2be9edc6">getPtr</a>

```cpp
inline const T * getPtr () const 
```



### _function_ <a id="9991ad3e" href="#9991ad3e">operator=</a>

```cpp
inline ffw::Mat4x4< T > & operator= (
    const ffw::Mat4x4< T > & m
) 
```



### _function_ <a id="a7ebde46" href="#a7ebde46">operator*</a>

```cpp
inline ffw::Mat4x4< T > operator* (
    const ffw::Mat4x4< T > & m
) const 
```



### _function_ <a id="5eed972e" href="#5eed972e">operator*=</a>

```cpp
inline ffw::Mat4x4< T > & operator*= (
    const ffw::Mat4x4< T > & m
) 
```



### _function_ <a id="edb84143" href="#edb84143">operator*</a>

```cpp
inline ffw::Vec4< S > operator* (
    const ffw::Vec4< S > & V
) const 
```



### _function_ <a id="e53e73b8" href="#e53e73b8">operator*</a>

```cpp
inline ffw::Vec3< S > operator* (
    const ffw::Vec3< S > & V
) const 
```



### _function_ <a id="79e25541" href="#79e25541">operator[]</a>

```cpp
inline T & operator[] (
    int x
) 
```



### _function_ <a id="fdd33926" href="#fdd33926">operator[]</a>

```cpp
inline const T & operator[] (
    int x
) const 
```



### _function_ <a id="83159838" href="#83159838">rotate</a>

```cpp
inline ffw::Mat4x4< T > & rotate (
    const ffw::Quat< T > & Q
) 
```



### _function_ <a id="46f81662" href="#46f81662">translate</a>

```cpp
inline ffw::Mat4x4< T > & translate (
    T X,
    T Y,
    T Z
) 
```



### _function_ <a id="93910356" href="#93910356">scale</a>

```cpp
inline ffw::Mat4x4< T > & scale (
    T X,
    T Y,
    T Z
) 
```



### _function_ <a id="4208fa27" href="#4208fa27">transpose</a>

```cpp
inline ffw::Mat4x4< T > & transpose () 
```



### _function_ <a id="f3d3291e" href="#f3d3291e">inverse</a>

```cpp
inline ffw::Mat4x4< T > & inverse () 
```





