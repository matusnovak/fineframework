GuiRadio
===================================


**Inherits from:** [ffw::GuiWidget](ffw_GuiWidget.html)

The documentation for this class was generated from: `include/ffw/gui/guiradio.h`



## Classes

| Name |
|:-----|
| class [ffw::GuiRadio::Button](ffw_GuiRadio_Button.html) |
| class [ffw::GuiRadio::Value](ffw_GuiRadio_Value.html) |


## Public Functions

| Type | Name |
| -------: | :------- |
|   | [GuiRadio](#9fb9dff3) ([GuiWindow](ffw_GuiWindow.html) * _context_, const std::string & _label_, int _base_, [GuiRadio](ffw_GuiRadio.html) * _other_ = NULL)  |
|   | [GuiRadio](#449e2be6) ([GuiWindow](ffw_GuiWindow.html) * _context_, const std::wstring & _label_, int _base_, [GuiRadio](ffw_GuiRadio.html) * _other_ = NULL)  |
|  virtual  | [~GuiRadio](#49046924) ()  |
|  void | [setLabel](#39cedeea) (const std::wstring & _label_)  |
|  const std::wstring & | [getLabel](#7774ed27) () const  |
|  int | [getBaseValue](#c93642f6) () const  |
|  void | [setValue](#2b025679) (int _value_)  |
|  int | [getValue](#04937874) () const  |
|  void | [assignValue](#696f023d) (bool _value_)  |
|  void | [setButtonSize](#c72925cc) (float _width_)  |
|  const [GuiRadio::Button](ffw_GuiRadio_Button.html) * | [getButton](#6698d94c) () const  |
|  const [GuiRadio::Button](ffw_GuiRadio_Button.html) * | [getButton](#206abf9f) ()  |
|  virtual [ffw::Vec2f](ffw.html#fcfaa6c5) | [getMinimumWrapSize](#1b50dcea) ()  |


## Public Functions Documentation

### _function_ <a id="9fb9dff3" href="#9fb9dff3">GuiRadio</a>

```cpp
 GuiRadio (
    GuiWindow * context,
    const std::string & label,
    int base,
    GuiRadio * other = NULL
) 
```



### _function_ <a id="449e2be6" href="#449e2be6">GuiRadio</a>

```cpp
 GuiRadio (
    GuiWindow * context,
    const std::wstring & label,
    int base,
    GuiRadio * other = NULL
) 
```



### _function_ <a id="49046924" href="#49046924">~GuiRadio</a>

```cpp
virtual  ~GuiRadio () 
```



### _function_ <a id="39cedeea" href="#39cedeea">setLabel</a>

```cpp
void setLabel (
    const std::wstring & label
) 
```



### _function_ <a id="7774ed27" href="#7774ed27">getLabel</a>

```cpp
const std::wstring & getLabel () const 
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



### _function_ <a id="206abf9f" href="#206abf9f">getButton</a>

```cpp
inline const GuiRadio::Button * getButton () 
```



### _function_ <a id="1b50dcea" href="#1b50dcea">getMinimumWrapSize</a>

```cpp
virtual ffw::Vec2f getMinimumWrapSize () 
```



**Overrides:** [getMinimumWrapSize](/doxygen/ffw_GuiWidget.md#c12efa3f) from class [GuiWidget](/doxygen/ffw_GuiWidget.md)



