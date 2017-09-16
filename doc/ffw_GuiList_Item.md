Item
===================================


**Inherits from:** [ffw::GuiWidget](ffw_GuiWidget.html)

The documentation for this class was generated from: `include/ffw/gui/guilist.h`



## Public Functions

| Type | Name |
| -------: | :------- |
|   | [Item](#51bc7791) ([GuiWindow](ffw_GuiWindow.html) * _context_, const std::string & _label_, int _base_, [GuiList::Value](ffw_GuiList_Value.html) * _group_)  |
|   | [Item](#03ec7993) ([GuiWindow](ffw_GuiWindow.html) * _context_, const std::wstring & _label_, int _base_, [GuiList::Value](ffw_GuiList_Value.html) * _group_)  |
|  virtual  | [~Item](#3c475a8f) ()  |
|  void | [setLabel](#88280b6f) (const std::wstring & _label_)  |
|  const std::wstring & | [getLabel](#9d8cd519) () const  |
|  int | [getBaseValue](#4952aab4) () const  |
|  bool | [isSelected](#83a96c74) () const  |
|  void | [assignValue](#293ebefe) (bool _value_)  |
|  virtual [ffw::Vec2f](ffw.html#fcfaa6c5) | [getMinimumWrapSize](#3fb64c51) ()  |


## Public Functions Documentation

### <span style="opacity:0.5;">function</span> <a id="51bc7791" href="#51bc7791">Item</a>

```cpp
 Item (
    GuiWindow * context,
    const std::string & label,
    int base,
    GuiList::Value * group
) 
```



### <span style="opacity:0.5;">function</span> <a id="03ec7993" href="#03ec7993">Item</a>

```cpp
 Item (
    GuiWindow * context,
    const std::wstring & label,
    int base,
    GuiList::Value * group
) 
```



### <span style="opacity:0.5;">function</span> <a id="3c475a8f" href="#3c475a8f">~Item</a>

```cpp
virtual  ~Item () 
```



### <span style="opacity:0.5;">function</span> <a id="88280b6f" href="#88280b6f">setLabel</a>

```cpp
void setLabel (
    const std::wstring & label
) 
```



### <span style="opacity:0.5;">function</span> <a id="9d8cd519" href="#9d8cd519">getLabel</a>

```cpp
const std::wstring & getLabel () const 
```



### <span style="opacity:0.5;">function</span> <a id="4952aab4" href="#4952aab4">getBaseValue</a>

```cpp
inline int getBaseValue () const 
```



### <span style="opacity:0.5;">function</span> <a id="83a96c74" href="#83a96c74">isSelected</a>

```cpp
bool isSelected () const 
```



### <span style="opacity:0.5;">function</span> <a id="293ebefe" href="#293ebefe">assignValue</a>

```cpp
void assignValue (
    bool value
) 
```



### <span style="opacity:0.5;">function</span> <a id="3fb64c51" href="#3fb64c51">getMinimumWrapSize</a>

```cpp
virtual ffw::Vec2f getMinimumWrapSize () 
```





