Content
===================================


**Implemented by:** [ffw::Any::Data< T, Enable >](ffw_Any_Data.html), [ffw::Any::Data< T, typename std::enable_if< std::is_integral< T >::value >::type >](ffw_Any_Data__T__typename_std__enable_if__std__is_integral__T____value____type__.html), 

The documentation for this class was generated from: `include/ffw/math/any.h`



## Public Functions

| Type | Name |
| -------: | :------- |
|  virtual  | [~Content](#627a961f) ()  |
|  virtual [Content](ffw_Any_Content.html) * | [createCopy](#a0a58250) () = 0  |
|  virtual const std::type_info & | [getTypeid](#08075bf5) () const = 0  |
|  virtual bool | [toBool](#0b222bae) () const = 0  |
|  virtual bool | [isInteger](#1aec6655) () const = 0  |
|  virtual int | [getInteger](#e38acb74) () const = 0  |
|  virtual bool | [compare](#009d067a) (const [Content](ffw_Any_Content.html) * _other_) const = 0  |


## Public Functions Documentation

### _function_ <a id="627a961f" href="#627a961f">~Content</a>

```cpp
inline virtual  ~Content () 
```



### _function_ <a id="a0a58250" href="#a0a58250">createCopy</a>

```cpp
virtual Content * createCopy () = 0 
```



### _function_ <a id="08075bf5" href="#08075bf5">getTypeid</a>

```cpp
virtual const std::type_info & getTypeid () const = 0 
```



### _function_ <a id="0b222bae" href="#0b222bae">toBool</a>

```cpp
virtual bool toBool () const = 0 
```



### _function_ <a id="1aec6655" href="#1aec6655">isInteger</a>

```cpp
virtual bool isInteger () const = 0 
```



### _function_ <a id="e38acb74" href="#e38acb74">getInteger</a>

```cpp
virtual int getInteger () const = 0 
```



### _function_ <a id="009d067a" href="#009d067a">compare</a>

```cpp
virtual bool compare (
    const Content * other
) const = 0 
```





