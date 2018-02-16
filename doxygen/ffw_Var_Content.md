Content
===================================


**Implemented by:** [ffw::Any::Data< T, Enable >](ffw_Var_Data.html), [ffw::Any::Data< T, typename std::enable_if< std::is_integral< T >::value >::type >](ffw_Var_Data__T__typename_std__enable_if__std__is_integral__T____value____type__.html), 

The documentation for this class was generated from: `include/ffw/math/var.h`



## Public Functions

| Type | Name |
| -------: | :------- |
|  virtual  | [~Content](#1c80577c) ()  |
|  virtual [Content](ffw_Var_Content.html) * | [createCopy](#4ecd831b) () = 0  |
|  virtual const std::type_info & | [getTypeid](#e3b1e597) () const = 0  |
|  virtual bool | [toBool](#23688855) () const = 0  |
|  virtual bool | [isInteger](#180b884d) () const = 0  |
|  virtual int | [getInteger](#9839465b) () const = 0  |
|  virtual bool | [compare](#23dddefb) (const [Content](ffw_Var_Content.html) * _other_) const = 0  |


## Public Functions Documentation

### _function_ <a id="1c80577c" href="#1c80577c">~Content</a>

```cpp
inline virtual  ~Content () 
```



### _function_ <a id="4ecd831b" href="#4ecd831b">createCopy</a>

```cpp
virtual Content * createCopy () = 0 
```



### _function_ <a id="e3b1e597" href="#e3b1e597">getTypeid</a>

```cpp
virtual const std::type_info & getTypeid () const = 0 
```



### _function_ <a id="23688855" href="#23688855">toBool</a>

```cpp
virtual bool toBool () const = 0 
```



### _function_ <a id="180b884d" href="#180b884d">isInteger</a>

```cpp
virtual bool isInteger () const = 0 
```



### _function_ <a id="9839465b" href="#9839465b">getInteger</a>

```cpp
virtual int getInteger () const = 0 
```



### _function_ <a id="23dddefb" href="#23dddefb">compare</a>

```cpp
virtual bool compare (
    const Content * other
) const = 0 
```





