Data
===================================


**Inherits from:** [ffw::Var::Content](ffw_Var_Content.html)

The documentation for this class was generated from: `include/ffw/math/var.h`



## Public Functions

| Type | Name |
| -------: | :------- |
|   | [Data](#6ee4ae00) (Args &&... _args_)  |
|  virtual  | [~Data](#03cf1ec5) ()  |
|  virtual [Data](ffw_Var_Data.html) * | [createCopy](#8801ac28) ()  |
|  virtual const std::type_info & | [getTypeid](#ec0c820c) () const  |
|  T & | [get](#9ff25a0c) ()  |
|  const T & | [get](#5dd38721) () const  |
|  virtual bool | [toBool](#eadd609f) () const  |
|  virtual bool | [isInteger](#0ad00ba7) () const  |
|  virtual int | [getInteger](#0f5e4842) () const  |
|  virtual bool | [compare](#db834025) (const [Content](ffw_Var_Content.html) * _other_) const  |


## Public Functions Documentation

### <span style="opacity:0.5;">function</span> <a id="6ee4ae00" href="#6ee4ae00">Data</a>

```cpp
inline  Data (
    Args &&... args
) 
```



### <span style="opacity:0.5;">function</span> <a id="03cf1ec5" href="#03cf1ec5">~Data</a>

```cpp
inline virtual  ~Data () 
```



### <span style="opacity:0.5;">function</span> <a id="8801ac28" href="#8801ac28">createCopy</a>

```cpp
inline virtual Data * createCopy () 
```



### <span style="opacity:0.5;">function</span> <a id="ec0c820c" href="#ec0c820c">getTypeid</a>

```cpp
inline virtual const std::type_info & getTypeid () const 
```



### <span style="opacity:0.5;">function</span> <a id="9ff25a0c" href="#9ff25a0c">get</a>

```cpp
inline T & get () 
```



### <span style="opacity:0.5;">function</span> <a id="5dd38721" href="#5dd38721">get</a>

```cpp
inline const T & get () const 
```



### <span style="opacity:0.5;">function</span> <a id="eadd609f" href="#eadd609f">toBool</a>

```cpp
inline virtual bool toBool () const 
```



### <span style="opacity:0.5;">function</span> <a id="0ad00ba7" href="#0ad00ba7">isInteger</a>

```cpp
inline virtual bool isInteger () const 
```



### <span style="opacity:0.5;">function</span> <a id="0f5e4842" href="#0f5e4842">getInteger</a>

```cpp
inline virtual int getInteger () const 
```



### <span style="opacity:0.5;">function</span> <a id="db834025" href="#db834025">compare</a>

```cpp
inline virtual bool compare (
    const Content * other
) const 
```





