Data< T, typename std::enable_if< std::is_integral< T >::value >::type >
===================================


**Inherits from:** [ffw::Any::Content](ffw_Any_Content.html)

The documentation for this class was generated from: `include/ffw/math/any.h`



## Public Functions

| Type | Name |
| -------: | :------- |
|   | [Data](#8f42d28d) (Args &&... _args_)  |
|  virtual  | [~Data](#969df175) ()  |
|  virtual [Data](ffw_Any_Data.html) * | [createCopy](#47f32b4d) ()  |
|  virtual const std::type_info & | [getTypeid](#f2c3f713) () const  |
|  T & | [get](#c722d2ad) ()  |
|  const T & | [get](#ed123194) () const  |
|  virtual bool | [toBool](#11ae4d37) () const  |
|  virtual bool | [isInteger](#38469a15) () const  |
|  virtual int | [getInteger](#035e9ada) () const  |
|  virtual bool | [compare](#ae27bcb4) (const [Content](ffw_Any_Content.html) * _other_) const  |


## Public Functions Documentation

### _function_ <a id="8f42d28d" href="#8f42d28d">Data</a>

```cpp
inline  Data (
    Args &&... args
) 
```



### _function_ <a id="969df175" href="#969df175">~Data</a>

```cpp
inline virtual  ~Data () 
```



### _function_ <a id="47f32b4d" href="#47f32b4d">createCopy</a>

```cpp
inline virtual Data * createCopy () 
```



**Overrides:** [createCopy](/doxygen/ffw_Any_Content.md#a0a58250) from class [Content](/doxygen/ffw_Any_Content.md)

### _function_ <a id="f2c3f713" href="#f2c3f713">getTypeid</a>

```cpp
inline virtual const std::type_info & getTypeid () const 
```



**Overrides:** [getTypeid](/doxygen/ffw_Any_Content.md#08075bf5) from class [Content](/doxygen/ffw_Any_Content.md)

### _function_ <a id="c722d2ad" href="#c722d2ad">get</a>

```cpp
inline T & get () 
```



### _function_ <a id="ed123194" href="#ed123194">get</a>

```cpp
inline const T & get () const 
```



### _function_ <a id="11ae4d37" href="#11ae4d37">toBool</a>

```cpp
inline virtual bool toBool () const 
```



**Overrides:** [toBool](/doxygen/ffw_Any_Content.md#0b222bae) from class [Content](/doxygen/ffw_Any_Content.md)

### _function_ <a id="38469a15" href="#38469a15">isInteger</a>

```cpp
inline virtual bool isInteger () const 
```



**Overrides:** [isInteger](/doxygen/ffw_Any_Content.md#1aec6655) from class [Content](/doxygen/ffw_Any_Content.md)

### _function_ <a id="035e9ada" href="#035e9ada">getInteger</a>

```cpp
inline virtual int getInteger () const 
```



**Overrides:** [getInteger](/doxygen/ffw_Any_Content.md#e38acb74) from class [Content](/doxygen/ffw_Any_Content.md)

### _function_ <a id="ae27bcb4" href="#ae27bcb4">compare</a>

```cpp
inline virtual bool compare (
    const Content * other
) const 
```



**Overrides:** [compare](/doxygen/ffw_Any_Content.md#009d067a) from class [Content](/doxygen/ffw_Any_Content.md)



