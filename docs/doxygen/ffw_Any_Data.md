Data
===================================


**Inherits from:** [ffw::Any::Content](ffw_Any_Content.html)

The documentation for this class was generated from: `include/ffw/math/any.h`



## Public Functions

| Type | Name |
| -------: | :------- |
|   | [Data](#88fe26a3) (Args &&... _args_)  |
|  virtual  | [~Data](#37bec39b) ()  |
|  virtual [Data](ffw_Any_Data.html) * | [createCopy](#23e877be) ()  |
|  virtual const std::type_info & | [getTypeid](#fe7f132f) () const  |
|  T & | [get](#0f710392) ()  |
|  const T & | [get](#8cc30473) () const  |
|  virtual bool | [toBool](#cd49491a) () const  |
|  virtual bool | [isInteger](#01f0c767) () const  |
|  virtual int | [getInteger](#39013431) () const  |
|  virtual bool | [compare](#e4a93c9f) (const [Content](ffw_Any_Content.html) * _other_) const  |


## Public Functions Documentation

### _function_ <a id="88fe26a3" href="#88fe26a3">Data</a>

```cpp
inline  Data (
    Args &&... args
) 
```



### _function_ <a id="37bec39b" href="#37bec39b">~Data</a>

```cpp
inline virtual  ~Data () 
```



### _function_ <a id="23e877be" href="#23e877be">createCopy</a>

```cpp
inline virtual Data * createCopy () 
```



**Overrides:** [createCopy](/doxygen/ffw_Any_Content.md#a0a58250) from class [Content](/doxygen/ffw_Any_Content.md)

### _function_ <a id="fe7f132f" href="#fe7f132f">getTypeid</a>

```cpp
inline virtual const std::type_info & getTypeid () const 
```



**Overrides:** [getTypeid](/doxygen/ffw_Any_Content.md#08075bf5) from class [Content](/doxygen/ffw_Any_Content.md)

### _function_ <a id="0f710392" href="#0f710392">get</a>

```cpp
inline T & get () 
```



### _function_ <a id="8cc30473" href="#8cc30473">get</a>

```cpp
inline const T & get () const 
```



### _function_ <a id="cd49491a" href="#cd49491a">toBool</a>

```cpp
inline virtual bool toBool () const 
```



**Overrides:** [toBool](/doxygen/ffw_Any_Content.md#0b222bae) from class [Content](/doxygen/ffw_Any_Content.md)

### _function_ <a id="01f0c767" href="#01f0c767">isInteger</a>

```cpp
inline virtual bool isInteger () const 
```



**Overrides:** [isInteger](/doxygen/ffw_Any_Content.md#1aec6655) from class [Content](/doxygen/ffw_Any_Content.md)

### _function_ <a id="39013431" href="#39013431">getInteger</a>

```cpp
inline virtual int getInteger () const 
```



**Overrides:** [getInteger](/doxygen/ffw_Any_Content.md#e38acb74) from class [Content](/doxygen/ffw_Any_Content.md)

### _function_ <a id="e4a93c9f" href="#e4a93c9f">compare</a>

```cpp
inline virtual bool compare (
    const Content * other
) const 
```



**Overrides:** [compare](/doxygen/ffw_Any_Content.md#009d067a) from class [Content](/doxygen/ffw_Any_Content.md)



