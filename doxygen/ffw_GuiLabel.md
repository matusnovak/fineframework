GuiLabel
===================================


**Inherits from:** [ffw::GuiWidget](ffw_GuiWidget.html)

The documentation for this class was generated from: `include/ffw/gui/guilabel.h`



## Classes

| Name |
|:-----|
| struct [ffw::GuiLabel::Style](ffw_GuiLabel_Style.html) |


## Public Functions

| Type | Name |
| -------: | :------- |
|   | [GuiLabel](#7818ed71) ([GuiWindow](ffw_GuiWindow.html) * _context_, const std::string & _label_)  |
|  virtual  | [~GuiLabel](#abf59417) ()  |
|  void | [setLabel](#f239ef46) (const std::string & _label_)  |
|  const std::string & | [getLabel](#f235358f) () const  |
|  virtual [ffw::Vec2f](ffw.html#fcfaa6c5) | [getMinimumWrapSize](#84fc7ddb) ()  |
|  void | [setStyle](#855dc11b) (const [GuiLabel::Style](ffw_GuiLabel_Style.html) * _style_, bool _defaults_ = false)  |


## Public Functions Documentation

### _function_ <a id="7818ed71" href="#7818ed71">GuiLabel</a>

```cpp
 GuiLabel (
    GuiWindow * context,
    const std::string & label
) 
```



### _function_ <a id="abf59417" href="#abf59417">~GuiLabel</a>

```cpp
virtual  ~GuiLabel () 
```



### _function_ <a id="f239ef46" href="#f239ef46">setLabel</a>

```cpp
void setLabel (
    const std::string & label
) 
```



### _function_ <a id="f235358f" href="#f235358f">getLabel</a>

```cpp
const std::string & getLabel () const 
```



### _function_ <a id="84fc7ddb" href="#84fc7ddb">getMinimumWrapSize</a>

```cpp
virtual ffw::Vec2f getMinimumWrapSize () 
```



**Overrides:** [getMinimumWrapSize](/doxygen/ffw_GuiWidget.md#c12efa3f) from class [GuiWidget](/doxygen/ffw_GuiWidget.md)

### _function_ <a id="855dc11b" href="#855dc11b">setStyle</a>

```cpp
void setStyle (
    const GuiLabel::Style * style,
    bool defaults = false
) 
```





