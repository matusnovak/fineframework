Var
===================================


The documentation for this class was generated from: `include/ffw/math/var.h`



## Classes

| Name |
|:-----|
| class [ffw::Var::Content](ffw_Var_Content.html) |
| class [ffw::Var::Data](ffw_Var_Data.html) |
| class [ffw::Var::Data< T, typename std::enable_if< std::is_integral< T >::value >::type >](ffw_Var_Data__T__typename_std__enable_if__std__is_integral__T____value____type__.html) |


## Public Functions

| Type | Name |
| -------: | :------- |
|   | [Var](#908517a6) ()  |
|   | [Var](#69443b49) (const [Var](ffw_Var.html) & _other_)  |
|   | [Var](#a93b32b4) ([Var](ffw_Var.html) && _other_)  |
|   | [Var](#66f2ad03) (T _value_)  |
|   | [Var](#deddea8f) (std::initializer_list< std::pair< std::string, [Var](ffw_Var.html) >> _list_)  |
|   | [Var](#231cde45) (std::initializer_list< [Var](ffw_Var.html) > _list_)  |
|  virtual  | [~Var](#7f3c6d6f) ()  |
|  bool | [empty](#b1a50abb) () const  |
|  void | [reset](#42a4bc55) ()  |
|  T & | [getAs](#1be6ba0e) ()  |
|  const T & | [getAs](#7d0c2db9) () const  |
|  void | [set](#27fd904e) (T _value_ = T())  |
|  bool | [is](#2e070581) () const  |
|  bool | [toBool](#70753066) () const  |
|  bool | [isBool](#8b978a46) () const  |
|  std::string | [toString](#1804ed51) () const  |
|  bool | [isString](#f587f1a0) () const  |
|  int | [toInt](#4321ba77) () const  |
|  bool | [isInt](#95faec1d) () const  |
|  float | [toFloat](#5d2999ad) () const  |
|  bool | [isFloat](#5bc85c4d) () const  |
|  void | [clear](#8fd2ab63) ()  |
|  const std::type_info & | [getTypeid](#faa85b7e) () const  |
|  explicit  | [operator T](#464fb31c) () const  |
|  explicit  | [operator T &](#85c15e2c) ()  |
|  explicit  | [operator const T &](#18a729a0) () const  |
|  void | [swap](#2b4f1456) ([Var](ffw_Var.html) & _other_)  |
|  [Var](ffw_Var.html) & | [operator=](#b01cc2e9) (const T & _value_)  |
|  [Var](ffw_Var.html) & | [operator=](#7dc96c8f) (T && _value_)  |
|  [Var](ffw_Var.html) & | [operator=](#c1ef422d) (const [Var](ffw_Var.html) & _other_)  |
|  [Var](ffw_Var.html) & | [operator=](#728c84f8) ([Var](ffw_Var.html) && _other_)  |
|  [Var](ffw_Var.html) & | [operator[]](#21a0229b) (const std::string & _key_)  |
|  const [Var](ffw_Var.html) & | [operator[]](#269ca2b7) (const std::string & _key_) const  |
|  [Var](ffw_Var.html) & | [operator[]](#8ed2476b) (size_t _n_)  |
|  const [Var](ffw_Var.html) & | [operator[]](#45e908a4) (size_t _n_) const  |
|  bool | [operator==](#a2fc8c80) (const T & _other_) const  |
|  bool | [operator!=](#a5f57246) (const T & _other_) const  |
|  bool | [operator==](#8c001813) (const [Var](ffw_Var.html) & _other_) const  |
|  bool | [operator!=](#ee153879) (const [Var](ffw_Var.html) & _other_) const  |


## Public Functions Documentation

### _function_ <a id="908517a6" href="#908517a6">Var</a>

```cpp
inline  Var () 
```



### _function_ <a id="69443b49" href="#69443b49">Var</a>

```cpp
inline  Var (
    const Var & other
) 
```



### _function_ <a id="a93b32b4" href="#a93b32b4">Var</a>

```cpp
inline  Var (
    Var && other
) 
```



### _function_ <a id="66f2ad03" href="#66f2ad03">Var</a>

```cpp
inline  Var (
    T value
) 
```



### _function_ <a id="deddea8f" href="#deddea8f">Var</a>

```cpp
inline  Var (
    std::initializer_list< std::pair< std::string, Var >> list
) 
```



### _function_ <a id="231cde45" href="#231cde45">Var</a>

```cpp
inline  Var (
    std::initializer_list< Var > list
) 
```



### _function_ <a id="7f3c6d6f" href="#7f3c6d6f">~Var</a>

```cpp
inline virtual  ~Var () 
```



### _function_ <a id="b1a50abb" href="#b1a50abb">empty</a>

```cpp
inline bool empty () const 
```



### _function_ <a id="42a4bc55" href="#42a4bc55">reset</a>

```cpp
inline void reset () 
```



### _function_ <a id="1be6ba0e" href="#1be6ba0e">getAs</a>

```cpp
inline T & getAs () 
```



### _function_ <a id="7d0c2db9" href="#7d0c2db9">getAs</a>

```cpp
inline const T & getAs () const 
```



### _function_ <a id="27fd904e" href="#27fd904e">set</a>

```cpp
inline void set (
    T value = T()
) 
```



### _function_ <a id="2e070581" href="#2e070581">is</a>

```cpp
inline bool is () const 
```



### _function_ <a id="70753066" href="#70753066">toBool</a>

```cpp
inline bool toBool () const 
```



### _function_ <a id="8b978a46" href="#8b978a46">isBool</a>

```cpp
inline bool isBool () const 
```



### _function_ <a id="1804ed51" href="#1804ed51">toString</a>

```cpp
inline std::string toString () const 
```



### _function_ <a id="f587f1a0" href="#f587f1a0">isString</a>

```cpp
inline bool isString () const 
```



### _function_ <a id="4321ba77" href="#4321ba77">toInt</a>

```cpp
inline int toInt () const 
```



### _function_ <a id="95faec1d" href="#95faec1d">isInt</a>

```cpp
inline bool isInt () const 
```



### _function_ <a id="5d2999ad" href="#5d2999ad">toFloat</a>

```cpp
inline float toFloat () const 
```



### _function_ <a id="5bc85c4d" href="#5bc85c4d">isFloat</a>

```cpp
inline bool isFloat () const 
```



### _function_ <a id="8fd2ab63" href="#8fd2ab63">clear</a>

```cpp
inline void clear () 
```



### _function_ <a id="faa85b7e" href="#faa85b7e">getTypeid</a>

```cpp
inline const std::type_info & getTypeid () const 
```



### _function_ <a id="464fb31c" href="#464fb31c">operator T</a>

```cpp
explicit inline  operator T () const 
```



### _function_ <a id="85c15e2c" href="#85c15e2c">operator T &</a>

```cpp
explicit inline  operator T & () 
```



### _function_ <a id="18a729a0" href="#18a729a0">operator const T &</a>

```cpp
explicit inline  operator const T & () const 
```



### _function_ <a id="2b4f1456" href="#2b4f1456">swap</a>

```cpp
inline void swap (
    Var & other
) 
```



### _function_ <a id="b01cc2e9" href="#b01cc2e9">operator=</a>

```cpp
inline Var & operator= (
    const T & value
) 
```



### _function_ <a id="7dc96c8f" href="#7dc96c8f">operator=</a>

```cpp
inline Var & operator= (
    T && value
) 
```



### _function_ <a id="c1ef422d" href="#c1ef422d">operator=</a>

```cpp
inline Var & operator= (
    const Var & other
) 
```



### _function_ <a id="728c84f8" href="#728c84f8">operator=</a>

```cpp
inline Var & operator= (
    Var && other
) 
```



### _function_ <a id="21a0229b" href="#21a0229b">operator[]</a>

```cpp
inline Var & operator[] (
    const std::string & key
) 
```



### _function_ <a id="269ca2b7" href="#269ca2b7">operator[]</a>

```cpp
inline const Var & operator[] (
    const std::string & key
) const 
```



### _function_ <a id="8ed2476b" href="#8ed2476b">operator[]</a>

```cpp
inline Var & operator[] (
    size_t n
) 
```



### _function_ <a id="45e908a4" href="#45e908a4">operator[]</a>

```cpp
inline const Var & operator[] (
    size_t n
) const 
```



### _function_ <a id="a2fc8c80" href="#a2fc8c80">operator==</a>

```cpp
inline bool operator== (
    const T & other
) const 
```



### _function_ <a id="a5f57246" href="#a5f57246">operator!=</a>

```cpp
inline bool operator!= (
    const T & other
) const 
```



### _function_ <a id="8c001813" href="#8c001813">operator==</a>

```cpp
inline bool operator== (
    const Var & other
) const 
```



### _function_ <a id="ee153879" href="#ee153879">operator!=</a>

```cpp
inline bool operator!= (
    const Var & other
) const 
```





