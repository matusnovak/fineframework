Node
===================================


The documentation for this class was generated from: `include/ffw/data/jsonreader.h`



## Public Attributes

| Type | Name |
| -------: | :------- |
|  const char * | [ptr](#7e1625eb) |
|  size_t | [len](#17386dc5) |


## Public Functions

| Type | Name |
| -------: | :------- |
|   | [Node](#11a7421f) (const char * _p_, size_t _l_)  |
|   | [Node](#f1ea99bc) ()  |
|  std::string | [str](#f8c0bbcf) () const  |
|  std::string | [raw](#91f7d5cf) () const  |
|  [Type](ffw_JsonReader.html#5dda529f) | [getType](#2bdadf18) () const  |
|  bool | [isString](#3f512abf) () const  |
|  bool | [isObject](#d5879ab6) () const  |
|  bool | [isArray](#03fb5cbc) () const  |
|  bool | [isEmpty](#e1c38d45) () const  |
|  bool | [isNumber](#16955881) () const  |
|  bool | [isInteger](#4619b816) () const  |
|  bool | [isFloat](#e80ad8c5) () const  |
|  bool | [isBoolean](#d840100f) () const  |
|  bool | [isNull](#c1bf0ecd) () const  |
|  std::string | [toString](#f75e334c) () const  |
|  int | [toInteger](#5add7121) () const  |
|  double | [toDouble](#11cf359b) () const  |
|  float | [toFloat](#fbaf12bc) () const  |
|  bool | [toBoolean](#b107819c) () const  |


## Public Attributes Documentation

### _variable_ <a id="7e1625eb" href="#7e1625eb">ptr</a>

```cpp
const char * ptr
```



### _variable_ <a id="17386dc5" href="#17386dc5">len</a>

```cpp
size_t len
```





## Public Functions Documentation

### _function_ <a id="11a7421f" href="#11a7421f">Node</a>

```cpp
inline  Node (
    const char * p,
    size_t l
) 
```



### _function_ <a id="f1ea99bc" href="#f1ea99bc">Node</a>

```cpp
inline  Node () 
```



### _function_ <a id="f8c0bbcf" href="#f8c0bbcf">str</a>

```cpp
inline std::string str () const 
```



### _function_ <a id="91f7d5cf" href="#91f7d5cf">raw</a>

```cpp
inline std::string raw () const 
```



### _function_ <a id="2bdadf18" href="#2bdadf18">getType</a>

```cpp
Type getType () const 
```



### _function_ <a id="3f512abf" href="#3f512abf">isString</a>

```cpp
inline bool isString () const 
```



### _function_ <a id="d5879ab6" href="#d5879ab6">isObject</a>

```cpp
inline bool isObject () const 
```



### _function_ <a id="03fb5cbc" href="#03fb5cbc">isArray</a>

```cpp
inline bool isArray () const 
```



### _function_ <a id="e1c38d45" href="#e1c38d45">isEmpty</a>

```cpp
inline bool isEmpty () const 
```



### _function_ <a id="16955881" href="#16955881">isNumber</a>

```cpp
bool isNumber () const 
```



### _function_ <a id="4619b816" href="#4619b816">isInteger</a>

```cpp
bool isInteger () const 
```



### _function_ <a id="e80ad8c5" href="#e80ad8c5">isFloat</a>

```cpp
bool isFloat () const 
```



### _function_ <a id="d840100f" href="#d840100f">isBoolean</a>

```cpp
bool isBoolean () const 
```



### _function_ <a id="c1bf0ecd" href="#c1bf0ecd">isNull</a>

```cpp
bool isNull () const 
```



### _function_ <a id="f75e334c" href="#f75e334c">toString</a>

```cpp
std::string toString () const 
```



### _function_ <a id="5add7121" href="#5add7121">toInteger</a>

```cpp
int toInteger () const 
```



### _function_ <a id="11cf359b" href="#11cf359b">toDouble</a>

```cpp
double toDouble () const 
```



### _function_ <a id="fbaf12bc" href="#fbaf12bc">toFloat</a>

```cpp
float toFloat () const 
```



### _function_ <a id="b107819c" href="#b107819c">toBoolean</a>

```cpp
bool toBoolean () const 
```





