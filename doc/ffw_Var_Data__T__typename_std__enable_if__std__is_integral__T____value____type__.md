Data< T, typename std::enable_if< std::is_integral< T >::value >::type >
===================================


**Inherits from:** [ffw::Var::Content](ffw_Var_Content.html)

The documentation for this class was generated from: `include/ffw/math/var.h`



## Public Functions

| Type | Name |
| -------: | :------- |
|   | [Data](#21b53ce6) (Args &&... _args_)  |
|  virtual  | [~Data](#a012e174) ()  |
|  virtual [Data](ffw_Var_Data.html) * | [createCopy](#8a0ac00b) ()  |
|  virtual const std::type_info & | [getTypeid](#5e29a44c) () const  |
|  T & | [get](#6c9f3e22) ()  |
|  const T & | [get](#f61caeb3) () const  |
|  virtual bool | [toBool](#c0fccfbe) () const  |
|  virtual bool | [isInteger](#a20ed82b) () const  |
|  virtual int | [getInteger](#140d2aa5) () const  |
|  virtual bool | [compare](#d9080e37) (const [Content](ffw_Var_Content.html) * _other_) const  |


## Public Functions Documentation

### <span style="opacity:0.5;">function</span> <a id="21b53ce6" href="#21b53ce6">Data</a>

```cpp
inline  Data (
    Args &&... args
) 
```



### <span style="opacity:0.5;">function</span> <a id="a012e174" href="#a012e174">~Data</a>

```cpp
inline virtual  ~Data () 
```



### <span style="opacity:0.5;">function</span> <a id="8a0ac00b" href="#8a0ac00b">createCopy</a>

```cpp
inline virtual Data * createCopy () 
```



**Overrides:** [createCopy](/doc/ffw_Var_Content.md#4ecd831b) from class [Content](/doc/ffw_Var_Content.md)

### <span style="opacity:0.5;">function</span> <a id="5e29a44c" href="#5e29a44c">getTypeid</a>

```cpp
inline virtual const std::type_info & getTypeid () const 
```



**Overrides:** [getTypeid](/doc/ffw_Var_Content.md#e3b1e597) from class [Content](/doc/ffw_Var_Content.md)

### <span style="opacity:0.5;">function</span> <a id="6c9f3e22" href="#6c9f3e22">get</a>

```cpp
inline T & get () 
```



### <span style="opacity:0.5;">function</span> <a id="f61caeb3" href="#f61caeb3">get</a>

```cpp
inline const T & get () const 
```



### <span style="opacity:0.5;">function</span> <a id="c0fccfbe" href="#c0fccfbe">toBool</a>

```cpp
inline virtual bool toBool () const 
```



**Overrides:** [toBool](/doc/ffw_Var_Content.md#23688855) from class [Content](/doc/ffw_Var_Content.md)

### <span style="opacity:0.5;">function</span> <a id="a20ed82b" href="#a20ed82b">isInteger</a>

```cpp
inline virtual bool isInteger () const 
```



**Overrides:** [isInteger](/doc/ffw_Var_Content.md#180b884d) from class [Content](/doc/ffw_Var_Content.md)

### <span style="opacity:0.5;">function</span> <a id="140d2aa5" href="#140d2aa5">getInteger</a>

```cpp
inline virtual int getInteger () const 
```



**Overrides:** [getInteger](/doc/ffw_Var_Content.md#9839465b) from class [Content](/doc/ffw_Var_Content.md)

### <span style="opacity:0.5;">function</span> <a id="d9080e37" href="#d9080e37">compare</a>

```cpp
inline virtual bool compare (
    const Content * other
) const 
```



**Overrides:** [compare](/doc/ffw_Var_Content.md#23dddefb) from class [Content](/doc/ffw_Var_Content.md)



