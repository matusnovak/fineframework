ObjLoader
===================================


The documentation for this class was generated from: `include/ffw/media/objloader.h`



## Public Functions

| Type | Name |
| -------: | :------- |
|   | [ObjLoader](#05620fe6) ()  |
|   | [ObjLoader](#b1cebdef) (const [ObjLoader](ffw_ObjLoader.html) & _other_) = delete  |
|   | [ObjLoader](#4be8a05c) ([ObjLoader](ffw_ObjLoader.html) && _other_)  |
|   | [~ObjLoader](#7dcb0e56) ()  |
|  void | [swap](#ef9daf1c) ([ObjLoader](ffw_ObjLoader.html) & _other_)  |
|  bool | [open](#34fe5257) (const std::string & _path_)  |
|  bool | [getNextObject](#9ec90787) (std::string * _name_)  |
|  bool | [getPolygon](#561aaf8b) ()  |
|  size_t | [calculatePolyCount](#bab9caa6) ()  |
|  bool | [isOpen](#23f9e68d) () const  |
|   | [operator bool](#774bb891) () const  |
|  const std::string & | [getMtllibName](#3b54a842) () const  |
|  size_t | [getCurrentLineNum](#32eed4b2) () const  |
|  const std::string & | [getCurrentMaterialName](#eab7d91f) () const  |
|  bool | [getMaterialFoundFlag](#60fe732c) () const  |
|  void | [resetMaterialFoundFlag](#b65ecd34) ()  |
|  bool | [objectHasNormals](#53342f45) () const  |
|  bool | [objectHasTexcoords](#02b204b3) () const  |
|  const [ffw::Vec3i](ffw.html#1bc00754) & | [getIndex0](#e49d40e5) () const  |
|  const [ffw::Vec3i](ffw.html#1bc00754) & | [getIndex1](#2a705802) () const  |
|  const [ffw::Vec3i](ffw.html#1bc00754) & | [getIndex2](#0f72fa5b) () const  |
|  const [ffw::Vec3f](ffw.html#f1b9b946) & | [getVertex](#7b0b151f) (size_t _i_) const  |
|  const [ffw::Vec3f](ffw.html#f1b9b946) & | [getNormal](#4ac26f6f) (size_t _i_) const  |
|  const [ffw::Vec2f](ffw.html#fcfaa6c5) & | [getTexCoord2](#8b0acb9a) (size_t _i_) const  |
|  const [ffw::Vec3f](ffw.html#f1b9b946) & | [getTexCoord3](#ef2fcc69) (size_t _i_) const  |
|  bool | [gotObject](#117893b8) () const  |
|  void | [fillData](#3c82e369) (float * _ptr_, size_t _vo_ = 0, size_t _no_ = 3, size_t _to_ = 6, bool _ts_ = false, size_t _stride_ = 8)  |
|  void | [close](#82d101c4) ()  |
|  [ObjLoader](ffw_ObjLoader.html) & | [operator=](#1c80e2ed) ([ObjLoader](ffw_ObjLoader.html) && _Other_)  |
|  [ObjLoader](ffw_ObjLoader.html) & | [operator=](#9aa9c5c0) (const [ObjLoader](ffw_ObjLoader.html) & _Other_) = delete  |


## Public Functions Documentation

### _function_ <a id="05620fe6" href="#05620fe6">ObjLoader</a>

```cpp
 ObjLoader () 
```



### _function_ <a id="b1cebdef" href="#b1cebdef">ObjLoader</a>

```cpp
 ObjLoader (
    const ObjLoader & other
) = delete 
```



### _function_ <a id="4be8a05c" href="#4be8a05c">ObjLoader</a>

```cpp
 ObjLoader (
    ObjLoader && other
) 
```



### _function_ <a id="7dcb0e56" href="#7dcb0e56">~ObjLoader</a>

```cpp
 ~ObjLoader () 
```



### _function_ <a id="ef9daf1c" href="#ef9daf1c">swap</a>

```cpp
void swap (
    ObjLoader & other
) 
```



### _function_ <a id="34fe5257" href="#34fe5257">open</a>

```cpp
bool open (
    const std::string & path
) 
```



### _function_ <a id="9ec90787" href="#9ec90787">getNextObject</a>

```cpp
bool getNextObject (
    std::string * name
) 
```



### _function_ <a id="561aaf8b" href="#561aaf8b">getPolygon</a>

```cpp
bool getPolygon () 
```



### _function_ <a id="bab9caa6" href="#bab9caa6">calculatePolyCount</a>

```cpp
size_t calculatePolyCount () 
```



### _function_ <a id="23f9e68d" href="#23f9e68d">isOpen</a>

```cpp
inline bool isOpen () const 
```



### _function_ <a id="774bb891" href="#774bb891">operator bool</a>

```cpp
inline  operator bool () const 
```



### _function_ <a id="3b54a842" href="#3b54a842">getMtllibName</a>

```cpp
inline const std::string & getMtllibName () const 
```



### _function_ <a id="32eed4b2" href="#32eed4b2">getCurrentLineNum</a>

```cpp
inline size_t getCurrentLineNum () const 
```



### _function_ <a id="eab7d91f" href="#eab7d91f">getCurrentMaterialName</a>

```cpp
inline const std::string & getCurrentMaterialName () const 
```



### _function_ <a id="60fe732c" href="#60fe732c">getMaterialFoundFlag</a>

```cpp
inline bool getMaterialFoundFlag () const 
```



### _function_ <a id="b65ecd34" href="#b65ecd34">resetMaterialFoundFlag</a>

```cpp
inline void resetMaterialFoundFlag () 
```



### _function_ <a id="53342f45" href="#53342f45">objectHasNormals</a>

```cpp
inline bool objectHasNormals () const 
```



### _function_ <a id="02b204b3" href="#02b204b3">objectHasTexcoords</a>

```cpp
inline bool objectHasTexcoords () const 
```



### _function_ <a id="e49d40e5" href="#e49d40e5">getIndex0</a>

```cpp
inline const ffw::Vec3i & getIndex0 () const 
```



### _function_ <a id="2a705802" href="#2a705802">getIndex1</a>

```cpp
inline const ffw::Vec3i & getIndex1 () const 
```



### _function_ <a id="0f72fa5b" href="#0f72fa5b">getIndex2</a>

```cpp
inline const ffw::Vec3i & getIndex2 () const 
```



### _function_ <a id="7b0b151f" href="#7b0b151f">getVertex</a>

```cpp
inline const ffw::Vec3f & getVertex (
    size_t i
) const 
```



### _function_ <a id="4ac26f6f" href="#4ac26f6f">getNormal</a>

```cpp
inline const ffw::Vec3f & getNormal (
    size_t i
) const 
```



### _function_ <a id="8b0acb9a" href="#8b0acb9a">getTexCoord2</a>

```cpp
inline const ffw::Vec2f & getTexCoord2 (
    size_t i
) const 
```



### _function_ <a id="ef2fcc69" href="#ef2fcc69">getTexCoord3</a>

```cpp
inline const ffw::Vec3f & getTexCoord3 (
    size_t i
) const 
```



### _function_ <a id="117893b8" href="#117893b8">gotObject</a>

```cpp
inline bool gotObject () const 
```



### _function_ <a id="3c82e369" href="#3c82e369">fillData</a>

```cpp
void fillData (
    float * ptr,
    size_t vo = 0,
    size_t no = 3,
    size_t to = 6,
    bool ts = false,
    size_t stride = 8
) 
```



### _function_ <a id="82d101c4" href="#82d101c4">close</a>

```cpp
void close () 
```



### _function_ <a id="1c80e2ed" href="#1c80e2ed">operator=</a>

```cpp
ObjLoader & operator= (
    ObjLoader && Other
) 
```



### _function_ <a id="9aa9c5c0" href="#9aa9c5c0">operator=</a>

```cpp
ObjLoader & operator= (
    const ObjLoader & Other
) = delete 
```





