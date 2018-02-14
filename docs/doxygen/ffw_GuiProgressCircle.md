GuiProgressCircle
===================================


**Inherits from:** [ffw::GuiWidget](ffw_GuiWidget.html)

The documentation for this class was generated from: `include/ffw/gui/guiprogresscircle.h`



## Classes

| Name |
|:-----|
| struct [ffw::GuiProgressCircle::Style](ffw_GuiProgressCircle_Style.html) |


## Public Functions

| Type | Name |
| -------: | :------- |
|   | [GuiProgressCircle](#c9ddbdd1) ([GuiWindow](ffw_GuiWindow.html) * _context_)  |
|  virtual  | [~GuiProgressCircle](#412bac23) ()  |
|  virtual [ffw::Vec2f](ffw.html#fcfaa6c5) | [getMinimumWrapSize](#315121e1) ()  |
|  void | [setValue](#80733d46) (float _value_)  |
|  float | [getValue](#213f73b1) () const  |
|  void | [setThickness](#7fb8165c) (float _val_)  |
|  float | [getThickness](#6bc2ab1a) () const  |
|  void | [setStyle](#5095e17b) (const [GuiProgressCircle::Style](ffw_GuiProgressCircle_Style.html) * _style_, bool _defaults_ = false)  |


## Public Functions Documentation

### _function_ <a id="c9ddbdd1" href="#c9ddbdd1">GuiProgressCircle</a>

```cpp
 GuiProgressCircle (
    GuiWindow * context
) 
```



### _function_ <a id="412bac23" href="#412bac23">~GuiProgressCircle</a>

```cpp
virtual  ~GuiProgressCircle () 
```



### _function_ <a id="315121e1" href="#315121e1">getMinimumWrapSize</a>

```cpp
virtual ffw::Vec2f getMinimumWrapSize () 
```



**Overrides:** [getMinimumWrapSize](/doxygen/ffw_GuiWidget.md#c12efa3f) from class [GuiWidget](/doxygen/ffw_GuiWidget.md)

### _function_ <a id="80733d46" href="#80733d46">setValue</a>

```cpp
void setValue (
    float value
) 
```



### _function_ <a id="213f73b1" href="#213f73b1">getValue</a>

```cpp
inline float getValue () const 
```



### _function_ <a id="7fb8165c" href="#7fb8165c">setThickness</a>

```cpp
void setThickness (
    float val
) 
```



### _function_ <a id="6bc2ab1a" href="#6bc2ab1a">getThickness</a>

```cpp
inline float getThickness () const 
```



### _function_ <a id="5095e17b" href="#5095e17b">setStyle</a>

```cpp
void setStyle (
    const GuiProgressCircle::Style * style,
    bool defaults = false
) 
```





