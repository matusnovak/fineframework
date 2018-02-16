GuiRadio
===================================


**Inherits from:** [ffw::GuiWidget](ffw_GuiWidget.html)

The documentation for this class was generated from: `include/ffw/gui/guiradio.h`



## Classes

| Name |
|:-----|
| class [ffw::GuiRadio::Button](ffw_GuiRadio_Button.html) |
| struct [ffw::GuiRadio::Style](ffw_GuiRadio_Style.html) |
| class [ffw::GuiRadio::Value](ffw_GuiRadio_Value.html) |


## Public Functions

| Type | Name |
| -------: | :------- |
|   | [GuiRadio](#3811fa92) ([GuiWindow](ffw_GuiWindow.html) * _context_, const std::string & _label_, int _base_, [GuiRadio](ffw_GuiRadio.html) * _other_ = nullptr)  |
|  virtual  | [~GuiRadio](#49046924) ()  |
|  void | [setLabel](#be40fd05) (const std::string & _label_)  |
|  const std::string & | [getLabel](#ed1aefce) () const  |
|  int | [getBaseValue](#c93642f6) () const  |
|  void | [setValue](#2b025679) (int _value_)  |
|  int | [getValue](#04937874) () const  |
|  void | [resetValue](#47f8eca1) ()  |
|  void | [assignValue](#696f023d) (bool _value_)  |
|  void | [setButtonSize](#c72925cc) (float _width_)  |
|  const [GuiRadio::Button](ffw_GuiRadio_Button.html) * | [getButton](#6698d94c) () const  |
|  [GuiRadio::Button](ffw_GuiRadio_Button.html) * | [getButton](#2bbba74e) ()  |
|  virtual [ffw::Vec2f](ffw.html#fcfaa6c5) | [getMinimumWrapSize](#1b50dcea) ()  |
|  void | [setStyle](#cc7dab70) (const [GuiRadio::Style](ffw_GuiRadio_Style.html) * _style_, bool _defaults_ = false)  |


## Public Functions Documentation

### _function_ <a id="3811fa92" href="#3811fa92">GuiRadio</a>

```cpp
 GuiRadio (
    GuiWindow * context,
    const std::string & label,
    int base,
    GuiRadio * other = nullptr
) 
```



### _function_ <a id="49046924" href="#49046924">~GuiRadio</a>

```cpp
virtual  ~GuiRadio () 
```



### _function_ <a id="be40fd05" href="#be40fd05">setLabel</a>

```cpp
void setLabel (
    const std::string & label
) 
```



### _function_ <a id="ed1aefce" href="#ed1aefce">getLabel</a>

```cpp
const std::string & getLabel () const 
```



### _function_ <a id="c93642f6" href="#c93642f6">getBaseValue</a>

```cpp
int getBaseValue () const 
```



### _function_ <a id="2b025679" href="#2b025679">setValue</a>

```cpp
void setValue (
    int value
) 
```



### _function_ <a id="04937874" href="#04937874">getValue</a>

```cpp
int getValue () const 
```



### _function_ <a id="47f8eca1" href="#47f8eca1">resetValue</a>

```cpp
void resetValue () 
```



### _function_ <a id="696f023d" href="#696f023d">assignValue</a>

```cpp
void assignValue (
    bool value
) 
```



### _function_ <a id="c72925cc" href="#c72925cc">setButtonSize</a>

```cpp
void setButtonSize (
    float width
) 
```



### _function_ <a id="6698d94c" href="#6698d94c">getButton</a>

```cpp
inline const GuiRadio::Button * getButton () const 
```



### _function_ <a id="2bbba74e" href="#2bbba74e">getButton</a>

```cpp
inline GuiRadio::Button * getButton () 
```



### _function_ <a id="1b50dcea" href="#1b50dcea">getMinimumWrapSize</a>

```cpp
virtual ffw::Vec2f getMinimumWrapSize () 
```



**Overrides:** [getMinimumWrapSize](/doxygen/ffw_GuiWidget.md#c12efa3f) from class [GuiWidget](/doxygen/ffw_GuiWidget.md)

### _function_ <a id="cc7dab70" href="#cc7dab70">setStyle</a>

```cpp
void setStyle (
    const GuiRadio::Style * style,
    bool defaults = false
) 
```





