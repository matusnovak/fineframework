GuiSwitch
===================================


**Inherits from:** [ffw::GuiWidget](ffw_GuiWidget.html)

The documentation for this class was generated from: `include/ffw/gui/guiswitch.h`



## Protected Attributes

| Type | Name |
| -------: | :------- |
|  const [GuiStyleGroup](ffw_GuiStyleGroup.html) * | [styleButton](#f3c6f984) |


## Public Functions

| Type | Name |
| -------: | :------- |
|   | [GuiSwitch](#04bab948) ([GuiWindow](ffw_GuiWindow.html) * _context_)  |
|  virtual  | [~GuiSwitch](#b61e48ee) ()  |
|  void | [setValue](#561f3a03) (bool _value_)  |
|  bool | [getValue](#1c90a8e7) () const  |
|  virtual [ffw::Vec2f](ffw.html#fcfaa6c5) | [getMinimumWrapSize](#73a4ffeb) ()  |


## Protected Attributes Documentation

### <span style="opacity:0.5;">variable</span> <a id="f3c6f984" href="#f3c6f984">styleButton</a>

```cpp
const GuiStyleGroup * styleButton
```





## Public Functions Documentation

### <span style="opacity:0.5;">function</span> <a id="04bab948" href="#04bab948">GuiSwitch</a>

```cpp
 GuiSwitch (
    GuiWindow * context
) 
```



### <span style="opacity:0.5;">function</span> <a id="b61e48ee" href="#b61e48ee">~GuiSwitch</a>

```cpp
virtual  ~GuiSwitch () 
```



### <span style="opacity:0.5;">function</span> <a id="561f3a03" href="#561f3a03">setValue</a>

```cpp
void setValue (
    bool value
) 
```



### <span style="opacity:0.5;">function</span> <a id="1c90a8e7" href="#1c90a8e7">getValue</a>

```cpp
bool getValue () const 
```



### <span style="opacity:0.5;">function</span> <a id="73a4ffeb" href="#73a4ffeb">getMinimumWrapSize</a>

```cpp
virtual ffw::Vec2f getMinimumWrapSize () 
```



**Overrides:** [getMinimumWrapSize](/doc/ffw_GuiWidget.md#c12efa3f)



