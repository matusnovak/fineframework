GuiUnits
===================================


The documentation for this class was generated from: `include/ffw/gui/guitheme.h`



## Public Types

| Type | Name |
| -------: | :------- |
| enum | [Type](#0b521588) |


## Public Attributes

| Type | Name |
| -------: | :------- |
|  float | [value](#da7a7186) |


## Public Functions

| Type | Name |
| -------: | :------- |
|   | [GuiUnits](#5a0842de) ()  |
|   | [GuiUnits](#6aeeb58b) (float _val_, bool _percentage_)  |
|   | [GuiUnits](#0c414286) (float _val_)  |
|  bool | [operator==](#3402fa02) (const [GuiUnits](ffw_GuiUnits.html) & _other_) const  |
|  bool | [operator!=](#b921036c) (const [GuiUnits](ffw_GuiUnits.html) & _other_) const  |
|  bool | [operator==](#dfd9d51f) (float _v_) const  |
|  bool | [operator!=](#06787388) (float _v_) const  |
|  bool | [operator==](#4ac94000) ([Type](ffw_GuiUnits.html#0b521588) _t_) const  |
|  bool | [operator!=](#fa61799b) ([Type](ffw_GuiUnits.html#0b521588) _t_) const  |
|  float | [toReal](#db9d9fdf) (float _val_) const  |
|  void | [setPixels](#7f4fefdc) (float _px_)  |
|  void | [setPercent](#4a25e5ef) (float _pc_)  |
|  [Type](ffw_GuiUnits.html#0b521588) | [getType](#a2a457d7) () const  |


## Friends

| Type | Name |
| -------: | :------- |
|  friend std::ostream & | [operator<<](#8d4bd139) (std::ostream & _os_, const [GuiUnits](ffw_GuiUnits.html) & _V_)  |


## Public Types Documentation

### <span style="opacity:0.5;">enum</span> <a id="0b521588" href="#0b521588">Type</a>

```cpp
enum Type {
    PERCENT,
    PIXELS,
    WRAP,
}
```





## Public Attributes Documentation

### <span style="opacity:0.5;">variable</span> <a id="da7a7186" href="#da7a7186">value</a>

```cpp
float value
```





## Public Functions Documentation

### <span style="opacity:0.5;">function</span> <a id="5a0842de" href="#5a0842de">GuiUnits</a>

```cpp
inline  GuiUnits () 
```



### <span style="opacity:0.5;">function</span> <a id="6aeeb58b" href="#6aeeb58b">GuiUnits</a>

```cpp
inline  GuiUnits (
    float val,
    bool percentage
) 
```



### <span style="opacity:0.5;">function</span> <a id="0c414286" href="#0c414286">GuiUnits</a>

```cpp
inline  GuiUnits (
    float val
) 
```



### <span style="opacity:0.5;">function</span> <a id="3402fa02" href="#3402fa02">operator==</a>

```cpp
inline bool operator== (
    const GuiUnits & other
) const 
```



### <span style="opacity:0.5;">function</span> <a id="b921036c" href="#b921036c">operator!=</a>

```cpp
inline bool operator!= (
    const GuiUnits & other
) const 
```



### <span style="opacity:0.5;">function</span> <a id="dfd9d51f" href="#dfd9d51f">operator==</a>

```cpp
inline bool operator== (
    float v
) const 
```



### <span style="opacity:0.5;">function</span> <a id="06787388" href="#06787388">operator!=</a>

```cpp
inline bool operator!= (
    float v
) const 
```



### <span style="opacity:0.5;">function</span> <a id="4ac94000" href="#4ac94000">operator==</a>

```cpp
inline bool operator== (
    Type t
) const 
```



### <span style="opacity:0.5;">function</span> <a id="fa61799b" href="#fa61799b">operator!=</a>

```cpp
inline bool operator!= (
    Type t
) const 
```



### <span style="opacity:0.5;">function</span> <a id="db9d9fdf" href="#db9d9fdf">toReal</a>

```cpp
inline float toReal (
    float val
) const 
```



### <span style="opacity:0.5;">function</span> <a id="7f4fefdc" href="#7f4fefdc">setPixels</a>

```cpp
inline void setPixels (
    float px
) 
```



### <span style="opacity:0.5;">function</span> <a id="4a25e5ef" href="#4a25e5ef">setPercent</a>

```cpp
inline void setPercent (
    float pc
) 
```



### <span style="opacity:0.5;">function</span> <a id="a2a457d7" href="#a2a457d7">getType</a>

```cpp
inline Type getType () const 
```





## Friends Documentation

### <span style="opacity:0.5;">friend</span> <a id="8d4bd139" href="#8d4bd139">operator<<</a>

```cpp
inline friend std::ostream & operator<< (
    std::ostream & os,
    const GuiUnits & V
) 
```





