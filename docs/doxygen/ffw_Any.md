Any
===================================


The documentation for this class was generated from: `include/ffw/math/any.h`



## Classes

| Name |
|:-----|
| class [ffw::Any::Content](ffw_Any_Content.html) |
| class [ffw::Any::Data](ffw_Any_Data.html) |
| class [ffw::Any::Data< T, typename std::enable_if< std::is_integral< T >::value >::type >](ffw_Any_Data__T__typename_std__enable_if__std__is_integral__T____value____type__.html) |


## Public Functions

| Type | Name |
| -------: | :------- |
|   | [Any](#505a2a2b) ()  |
|   | [Any](#68332fa2) (const [Any](ffw_Any.html) & _other_)  |
|   | [Any](#2050c50c) ([Any](ffw_Any.html) && _other_)  |
|   | [Any](#32d42b24) (T _value_)  |
|   | [Any](#7fb0c445) (std::initializer_list< std::pair< std::string, [Any](ffw_Any.html) >> _list_)  |
|   | [Any](#69d2cac2) (std::initializer_list< [Any](ffw_Any.html) > _list_)  |
|  virtual  | [~Any](#15386555) ()  |
|  bool | [empty](#162d7cb9) () const  |
|  void | [reset](#da9e4e16) ()  |
|  T & | [getAs](#f4fbe576) ()  |
|  const T & | [getAs](#f30405ae) () const  |
|  void | [set](#e79d4caf) (T _value_ = T())  |
|  bool | [is](#ce92f1f9) () const  |
|  bool | [toBool](#2bfec7fd) () const  |
|  bool | [isBool](#c07e67f9) () const  |
|  std::string | [toString](#22e6bef4) () const  |
|  bool | [isString](#a8f0b649) () const  |
|  int | [toInt](#3195692c) () const  |
|  bool | [isInt](#c3eb5021) () const  |
|  float | [toFloat](#6f76b794) () const  |
|  bool | [isFloat](#5755fcb7) () const  |
|  bool | [isObject](#dd0c59df) () const  |
|  bool | [isArray](#1739f6fb) () const  |
|  [ffw::Array](ffw_Array.html) & | [getAsArray](#a64697a2) ()  |
|  [ffw::Object](ffw_Object.html) & | [getAsObject](#616356f5) ()  |
|  const [ffw::Array](ffw_Array.html) & | [getAsArray](#63257de6) () const  |
|  const [ffw::Object](ffw_Object.html) & | [getAsObject](#f467de8a) () const  |
|  void | [clear](#ae50e60e) ()  |
|  const std::type_info & | [getTypeid](#116df88f) () const  |
|  explicit  | [operator T](#27b39cfc) () const  |
|  explicit  | [operator T &](#a8513fec) ()  |
|  explicit  | [operator const T &](#0a2ad0af) () const  |
|  void | [swap](#d029b857) ([Any](ffw_Any.html) & _other_)  |
|  [Any](ffw_Any.html) & | [operator=](#f08eb2b3) (const T & _value_)  |
|  [Any](ffw_Any.html) & | [operator=](#1bcdd8a9) (T && _value_)  |
|  [Any](ffw_Any.html) & | [operator=](#582d97bf) (const [Any](ffw_Any.html) & _other_)  |
|  [Any](ffw_Any.html) & | [operator=](#feafa4bc) ([Any](ffw_Any.html) && _other_)  |
|  [Any](ffw_Any.html) & | [operator[]](#f380a851) (const std::string & _key_)  |
|  const [Any](ffw_Any.html) & | [operator[]](#a091528a) (const std::string & _key_) const  |
|  [Any](ffw_Any.html) & | [operator[]](#23290e25) (size_t _n_)  |
|  const [Any](ffw_Any.html) & | [operator[]](#5b72f34f) (size_t _n_) const  |
|  bool | [operator==](#d6572c66) (const T & _other_) const  |
|  bool | [operator!=](#17ca5bc8) (const T & _other_) const  |
|  bool | [operator==](#0e5fb9c1) (const [Any](ffw_Any.html) & _other_) const  |
|  bool | [operator!=](#090631f7) (const [Any](ffw_Any.html) & _other_) const  |


## Public Functions Documentation

### _function_ <a id="505a2a2b" href="#505a2a2b">Any</a>

```cpp
inline  Any () 
```



### _function_ <a id="68332fa2" href="#68332fa2">Any</a>

```cpp
inline  Any (
    const Any & other
) 
```



### _function_ <a id="2050c50c" href="#2050c50c">Any</a>

```cpp
inline  Any (
    Any && other
) 
```



### _function_ <a id="32d42b24" href="#32d42b24">Any</a>

```cpp
inline  Any (
    T value
) 
```



### _function_ <a id="7fb0c445" href="#7fb0c445">Any</a>

```cpp
inline  Any (
    std::initializer_list< std::pair< std::string, Any >> list
) 
```



### _function_ <a id="69d2cac2" href="#69d2cac2">Any</a>

```cpp
inline  Any (
    std::initializer_list< Any > list
) 
```



### _function_ <a id="15386555" href="#15386555">~Any</a>

```cpp
inline virtual  ~Any () 
```



### _function_ <a id="162d7cb9" href="#162d7cb9">empty</a>

```cpp
inline bool empty () const 
```



### _function_ <a id="da9e4e16" href="#da9e4e16">reset</a>

```cpp
inline void reset () 
```



### _function_ <a id="f4fbe576" href="#f4fbe576">getAs</a>

```cpp
inline T & getAs () 
```



### _function_ <a id="f30405ae" href="#f30405ae">getAs</a>

```cpp
inline const T & getAs () const 
```



### _function_ <a id="e79d4caf" href="#e79d4caf">set</a>

```cpp
inline void set (
    T value = T()
) 
```



### _function_ <a id="ce92f1f9" href="#ce92f1f9">is</a>

```cpp
inline bool is () const 
```



### _function_ <a id="2bfec7fd" href="#2bfec7fd">toBool</a>

```cpp
inline bool toBool () const 
```



### _function_ <a id="c07e67f9" href="#c07e67f9">isBool</a>

```cpp
inline bool isBool () const 
```



### _function_ <a id="22e6bef4" href="#22e6bef4">toString</a>

```cpp
inline std::string toString () const 
```



### _function_ <a id="a8f0b649" href="#a8f0b649">isString</a>

```cpp
inline bool isString () const 
```



### _function_ <a id="3195692c" href="#3195692c">toInt</a>

```cpp
inline int toInt () const 
```



### _function_ <a id="c3eb5021" href="#c3eb5021">isInt</a>

```cpp
inline bool isInt () const 
```



### _function_ <a id="6f76b794" href="#6f76b794">toFloat</a>

```cpp
inline float toFloat () const 
```



### _function_ <a id="5755fcb7" href="#5755fcb7">isFloat</a>

```cpp
inline bool isFloat () const 
```



### _function_ <a id="dd0c59df" href="#dd0c59df">isObject</a>

```cpp
inline bool isObject () const 
```



### _function_ <a id="1739f6fb" href="#1739f6fb">isArray</a>

```cpp
inline bool isArray () const 
```



### _function_ <a id="a64697a2" href="#a64697a2">getAsArray</a>

```cpp
inline ffw::Array & getAsArray () 
```



### _function_ <a id="616356f5" href="#616356f5">getAsObject</a>

```cpp
inline ffw::Object & getAsObject () 
```



### _function_ <a id="63257de6" href="#63257de6">getAsArray</a>

```cpp
inline const ffw::Array & getAsArray () const 
```



### _function_ <a id="f467de8a" href="#f467de8a">getAsObject</a>

```cpp
inline const ffw::Object & getAsObject () const 
```



### _function_ <a id="ae50e60e" href="#ae50e60e">clear</a>

```cpp
inline void clear () 
```



### _function_ <a id="116df88f" href="#116df88f">getTypeid</a>

```cpp
inline const std::type_info & getTypeid () const 
```



### _function_ <a id="27b39cfc" href="#27b39cfc">operator T</a>

```cpp
explicit inline  operator T () const 
```



### _function_ <a id="a8513fec" href="#a8513fec">operator T &</a>

```cpp
explicit inline  operator T & () 
```



### _function_ <a id="0a2ad0af" href="#0a2ad0af">operator const T &</a>

```cpp
explicit inline  operator const T & () const 
```



### _function_ <a id="d029b857" href="#d029b857">swap</a>

```cpp
inline void swap (
    Any & other
) 
```



### _function_ <a id="f08eb2b3" href="#f08eb2b3">operator=</a>

```cpp
inline Any & operator= (
    const T & value
) 
```



### _function_ <a id="1bcdd8a9" href="#1bcdd8a9">operator=</a>

```cpp
inline Any & operator= (
    T && value
) 
```



### _function_ <a id="582d97bf" href="#582d97bf">operator=</a>

```cpp
inline Any & operator= (
    const Any & other
) 
```



### _function_ <a id="feafa4bc" href="#feafa4bc">operator=</a>

```cpp
inline Any & operator= (
    Any && other
) 
```



### _function_ <a id="f380a851" href="#f380a851">operator[]</a>

```cpp
inline Any & operator[] (
    const std::string & key
) 
```



### _function_ <a id="a091528a" href="#a091528a">operator[]</a>

```cpp
inline const Any & operator[] (
    const std::string & key
) const 
```



### _function_ <a id="23290e25" href="#23290e25">operator[]</a>

```cpp
inline Any & operator[] (
    size_t n
) 
```



### _function_ <a id="5b72f34f" href="#5b72f34f">operator[]</a>

```cpp
inline const Any & operator[] (
    size_t n
) const 
```



### _function_ <a id="d6572c66" href="#d6572c66">operator==</a>

```cpp
inline bool operator== (
    const T & other
) const 
```



### _function_ <a id="17ca5bc8" href="#17ca5bc8">operator!=</a>

```cpp
inline bool operator!= (
    const T & other
) const 
```



### _function_ <a id="0e5fb9c1" href="#0e5fb9c1">operator==</a>

```cpp
inline bool operator== (
    const Any & other
) const 
```



### _function_ <a id="090631f7" href="#090631f7">operator!=</a>

```cpp
inline bool operator!= (
    const Any & other
) const 
```





