Item
===================================


**Inherits from:** [ffw::GuiWidget](ffw_GuiWidget.html)

The documentation for this class was generated from: `include/ffw/gui/guilist.h`



## Classes

| Name |
|:-----|
| struct [ffw::GuiList::Item::Style](ffw_GuiList_Item_Style.html) |


## Public Functions

| Type | Name |
| -------: | :------- |
|   | [Item](#51bc7791) ([GuiWindow](ffw_GuiWindow.html) * _context_, const std::string & _label_, int _base_, [GuiList::Value](ffw_GuiList_Value.html) * _group_)  |
|  virtual  | [~Item](#3c475a8f) ()  |
|  void | [setLabel](#50f46d56) (const std::string & _label_)  |
|  const std::string & | [getLabel](#ee6265a9) () const  |
|  int | [getBaseValue](#4952aab4) () const  |
|  bool | [isSelected](#83a96c74) () const  |
|  void | [assignValue](#293ebefe) (bool _value_)  |
|  virtual [ffw::Vec2f](ffw.html#fcfaa6c5) | [getMinimumWrapSize](#3fb64c51) ()  |
|  void | [setStyle](#3e7820ac) (const [Item::Style](ffw_GuiList_Item_Style.html) * _style_, bool _defaults_ = false)  |


## Public Functions Documentation

### _function_ <a id="51bc7791" href="#51bc7791">Item</a>

```cpp
 Item (
    GuiWindow * context,
    const std::string & label,
    int base,
    GuiList::Value * group
) 
```



### _function_ <a id="3c475a8f" href="#3c475a8f">~Item</a>

```cpp
virtual  ~Item () 
```



### _function_ <a id="50f46d56" href="#50f46d56">setLabel</a>

```cpp
void setLabel (
    const std::string & label
) 
```



### _function_ <a id="ee6265a9" href="#ee6265a9">getLabel</a>

```cpp
const std::string & getLabel () const 
```



### _function_ <a id="4952aab4" href="#4952aab4">getBaseValue</a>

```cpp
inline int getBaseValue () const 
```



### _function_ <a id="83a96c74" href="#83a96c74">isSelected</a>

```cpp
bool isSelected () const 
```



### _function_ <a id="293ebefe" href="#293ebefe">assignValue</a>

```cpp
void assignValue (
    bool value
) 
```



### _function_ <a id="3fb64c51" href="#3fb64c51">getMinimumWrapSize</a>

```cpp
virtual ffw::Vec2f getMinimumWrapSize () 
```



**Overrides:** [getMinimumWrapSize](/doxygen/ffw_GuiWidget.md#c12efa3f) from class [GuiWidget](/doxygen/ffw_GuiWidget.md)

### _function_ <a id="3e7820ac" href="#3e7820ac">setStyle</a>

```cpp
void setStyle (
    const Item::Style * style,
    bool defaults = false
) 
```





