Renderbuffer
===================================


**Implemented by:** [ffw::Renderbuffer2D](ffw_Renderbuffer2D.html), [ffw::Renderbuffer2DMS](ffw_Renderbuffer2DMS.html), 

The documentation for this class was generated from: `include/ffw/graphics/renderbuffer.h`



## Protected Attributes

| Type | Name |
| -------: | :------- |
|  bool | [loaded_](#2d9a6506) |
|  unsigned int | [internalformat_](#04eb1a2f) |
|  unsigned int | [buffer_](#7a3eb2d9) |
|  int | [width_](#e83fcafd) |
|  int | [height_](#c1c92dc3) |
|  int | [samples_](#b3ddebd7) |


## Public Functions

| Type | Name |
| -------: | :------- |
|   | [Renderbuffer](#45ab54e4) ()  |
|   | [Renderbuffer](#9ac2dec2) (const [Renderbuffer](ffw_Renderbuffer.html) & _other_) = delete  |
|   | [Renderbuffer](#0ed5d2de) ([Renderbuffer](ffw_Renderbuffer.html) && _other_)  |
|  void | [swap](#784eb267) ([Renderbuffer](ffw_Renderbuffer.html) & _other_)  |
|  virtual  | [~Renderbuffer](#700cd881) ()  |
|  bool | [isCreated](#1ad9a710) () const  |
|  void | [destroy](#a92b1d7a) ()  |
|  void | [bind](#c3f8e037) () const  |
|  void | [unbind](#53211c7e) () const  |
|  unsigned int | [getHandle](#4c9d5dc4) () const  |
|  int | [getWidth](#82bd2dee) () const  |
|  int | [getHeight](#c24377d1) () const  |
|  unsigned int | [getInternalFormat](#9dca3dc1) () const  |
|  int | [getSamples](#5aac76e4) () const  |
|  [Renderbuffer](ffw_Renderbuffer.html) & | [operator=](#a7dc6b47) (const [Renderbuffer](ffw_Renderbuffer.html) & _other_) = delete  |
|  [Renderbuffer](ffw_Renderbuffer.html) & | [operator=](#e289a4f7) ([Renderbuffer](ffw_Renderbuffer.html) && _other_)  |


## Protected Attributes Documentation

### _variable_ <a id="2d9a6506" href="#2d9a6506">loaded_</a>

```cpp
bool loaded_
```



### _variable_ <a id="04eb1a2f" href="#04eb1a2f">internalformat_</a>

```cpp
unsigned int internalformat_
```



### _variable_ <a id="7a3eb2d9" href="#7a3eb2d9">buffer_</a>

```cpp
unsigned int buffer_
```



### _variable_ <a id="e83fcafd" href="#e83fcafd">width_</a>

```cpp
int width_
```



### _variable_ <a id="c1c92dc3" href="#c1c92dc3">height_</a>

```cpp
int height_
```



### _variable_ <a id="b3ddebd7" href="#b3ddebd7">samples_</a>

```cpp
int samples_
```





## Public Functions Documentation

### _function_ <a id="45ab54e4" href="#45ab54e4">Renderbuffer</a>

```cpp
 Renderbuffer () 
```



### _function_ <a id="9ac2dec2" href="#9ac2dec2">Renderbuffer</a>

```cpp
 Renderbuffer (
    const Renderbuffer & other
) = delete 
```



### _function_ <a id="0ed5d2de" href="#0ed5d2de">Renderbuffer</a>

```cpp
 Renderbuffer (
    Renderbuffer && other
) 
```



### _function_ <a id="784eb267" href="#784eb267">swap</a>

```cpp
void swap (
    Renderbuffer & other
) 
```



### _function_ <a id="700cd881" href="#700cd881">~Renderbuffer</a>

```cpp
virtual  ~Renderbuffer () 
```



### _function_ <a id="1ad9a710" href="#1ad9a710">isCreated</a>

```cpp
inline bool isCreated () const 
```



### _function_ <a id="a92b1d7a" href="#a92b1d7a">destroy</a>

```cpp
void destroy () 
```



### _function_ <a id="c3f8e037" href="#c3f8e037">bind</a>

```cpp
void bind () const 
```



### _function_ <a id="53211c7e" href="#53211c7e">unbind</a>

```cpp
void unbind () const 
```



### _function_ <a id="4c9d5dc4" href="#4c9d5dc4">getHandle</a>

```cpp
inline unsigned int getHandle () const 
```



### _function_ <a id="82bd2dee" href="#82bd2dee">getWidth</a>

```cpp
inline int getWidth () const 
```



### _function_ <a id="c24377d1" href="#c24377d1">getHeight</a>

```cpp
inline int getHeight () const 
```



### _function_ <a id="9dca3dc1" href="#9dca3dc1">getInternalFormat</a>

```cpp
inline unsigned int getInternalFormat () const 
```



### _function_ <a id="5aac76e4" href="#5aac76e4">getSamples</a>

```cpp
inline int getSamples () const 
```



### _function_ <a id="a7dc6b47" href="#a7dc6b47">operator=</a>

```cpp
Renderbuffer & operator= (
    const Renderbuffer & other
) = delete 
```



### _function_ <a id="e289a4f7" href="#e289a4f7">operator=</a>

```cpp
Renderbuffer & operator= (
    Renderbuffer && other
) 
```





