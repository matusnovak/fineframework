Attribute
===================================


The documentation for this class was generated from: `include/ffw/gui/guitheme.h`



## Public Attributes

| Type | Name |
| -------: | :------- |
|  T | [val](#dd62b2e9) |


## Public Functions

| Type | Name |
| -------: | :------- |
|   | [Attribute](#0b9a7c12) ()  |
|   | [Attribute](#7938b748) (T _v_)  |
|   | [Attribute](#bf980a66) (T _top_, T _right_, T _bottom_, T _left_)  |
|   | [Attribute](#4820639b) (const [Attribute](ffw_GuiStyle_Attribute.html) & _other_)  |
|  [Attribute](ffw_GuiStyle_Attribute.html) & | [operator=](#e7244f3f) (const T & _value_)  |
|  T & | [operator[]](#9aacc278) (size_t _i_)  |
|  const T & | [operator[]](#649f3382) (size_t _i_) const  |
|  bool | [operator==](#e2926310) (const [Attribute](ffw_GuiStyle_Attribute.html) & _other_) const  |
|  bool | [operator!=](#ffe5a21f) (const [Attribute](ffw_GuiStyle_Attribute.html) & _other_) const  |


## Friends

| Type | Name |
| -------: | :------- |
|  friend std::ostream & | [operator<<](#1fcecb37) (std::ostream & _os_, const [Attribute](ffw_GuiStyle_Attribute.html) & _a_)  |


## Public Attributes Documentation

### _variable_ <a id="dd62b2e9" href="#dd62b2e9">val</a>

```cpp
T val
```





## Public Functions Documentation

### _function_ <a id="0b9a7c12" href="#0b9a7c12">Attribute</a>

```cpp
inline  Attribute () 
```



### _function_ <a id="7938b748" href="#7938b748">Attribute</a>

```cpp
inline  Attribute (
    T v
) 
```



### _function_ <a id="bf980a66" href="#bf980a66">Attribute</a>

```cpp
inline  Attribute (
    T top,
    T right,
    T bottom,
    T left
) 
```



### _function_ <a id="4820639b" href="#4820639b">Attribute</a>

```cpp
inline  Attribute (
    const Attribute & other
) 
```



### _function_ <a id="e7244f3f" href="#e7244f3f">operator=</a>

```cpp
inline Attribute & operator= (
    const T & value
) 
```



### _function_ <a id="9aacc278" href="#9aacc278">operator[]</a>

```cpp
inline T & operator[] (
    size_t i
) 
```



### _function_ <a id="649f3382" href="#649f3382">operator[]</a>

```cpp
inline const T & operator[] (
    size_t i
) const 
```



### _function_ <a id="e2926310" href="#e2926310">operator==</a>

```cpp
inline bool operator== (
    const Attribute & other
) const 
```



### _function_ <a id="ffe5a21f" href="#ffe5a21f">operator!=</a>

```cpp
inline bool operator!= (
    const Attribute & other
) const 
```





## Friends Documentation

### _friend_ <a id="1fcecb37" href="#1fcecb37">operator<<</a>

```cpp
inline friend std::ostream & operator<< (
    std::ostream & os,
    const Attribute & a
) 
```





