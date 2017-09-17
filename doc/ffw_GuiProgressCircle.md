GuiProgressCircle
===================================


**Inherits from:** [ffw::GuiWidget](ffw_GuiWidget.html)

The documentation for this class was generated from: `include/ffw/gui/guiprogresscircle.h`



## Protected Attributes

| Type | Name |
| -------: | :------- |
|  const [GuiStyleGroup](ffw_GuiStyleGroup.html) * | [innerStyle](#84096d24) |


## Public Functions

| Type | Name |
| -------: | :------- |
|   | [GuiProgressCircle](#c9ddbdd1) ([GuiWindow](ffw_GuiWindow.html) * _context_)  |
|  virtual  | [~GuiProgressCircle](#fd7ba3d6) ()  |
|  virtual [ffw::Vec2f](ffw.html#fcfaa6c5) | [getMinimumWrapSize](#315121e1) ()  |
|  void | [setValue](#80733d46) (float _value_)  |
|  float | [getValue](#213f73b1) () const  |
|  void | [setThickness](#7fb8165c) (float _val_)  |
|  float | [getThickness](#6bc2ab1a) () const  |


## Protected Attributes Documentation

### <span style="opacity:0.5;">variable</span> <a id="84096d24" href="#84096d24">innerStyle</a>

```cpp
const GuiStyleGroup * innerStyle
```





## Public Functions Documentation

### <span style="opacity:0.5;">function</span> <a id="c9ddbdd1" href="#c9ddbdd1">GuiProgressCircle</a>

```cpp
 GuiProgressCircle (
    GuiWindow * context
) 
```



### <span style="opacity:0.5;">function</span> <a id="fd7ba3d6" href="#fd7ba3d6">~GuiProgressCircle</a>

```cpp
virtual  ~GuiProgressCircle () 
```



### <span style="opacity:0.5;">function</span> <a id="315121e1" href="#315121e1">getMinimumWrapSize</a>

```cpp
virtual ffw::Vec2f getMinimumWrapSize () 
```



**Overrides:** [getMinimumWrapSize](/doc/ffw_GuiWidget.md#c12efa3f)

### <span style="opacity:0.5;">function</span> <a id="80733d46" href="#80733d46">setValue</a>

```cpp
inline void setValue (
    float value
) 
```



### <span style="opacity:0.5;">function</span> <a id="213f73b1" href="#213f73b1">getValue</a>

```cpp
inline float getValue () const 
```



### <span style="opacity:0.5;">function</span> <a id="7fb8165c" href="#7fb8165c">setThickness</a>

```cpp
inline void setThickness (
    float val
) 
```



### <span style="opacity:0.5;">function</span> <a id="6bc2ab1a" href="#6bc2ab1a">getThickness</a>

```cpp
inline float getThickness () const 
```





