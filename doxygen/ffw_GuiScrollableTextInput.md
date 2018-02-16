GuiScrollableTextInput
===================================


**Inherits from:** [ffw::GuiScrollable](ffw_GuiScrollable.html)

The documentation for this class was generated from: `include/ffw/gui/guitextedit.h`



## Classes

| Name |
|:-----|
| class [ffw::GuiScrollableTextInput::Inner](ffw_GuiScrollableTextInput_Inner.html) |
| struct [ffw::GuiScrollableTextInput::Style](ffw_GuiScrollableTextInput_Style.html) |


## Public Functions

| Type | Name |
| -------: | :------- |
|   | [GuiScrollableTextInput](#c6ff52dd) ([GuiWindow](ffw_GuiWindow.html) * _context_, bool _editable_ = true)  |
|  virtual  | [~GuiScrollableTextInput](#dfd20565) ()  |
|  const [GuiTextInput](ffw_GuiTextInput.html) * | [getInner](#47d11e79) () const  |
|  [GuiTextInput](ffw_GuiTextInput.html) * | [getInner](#b4d7aec2) ()  |
|  void | [setValue](#a6d058ad) (const std::string & _str_)  |
|  std::string | [getValue](#9998905b) () const  |
|  void | [appendValue](#6a3181ce) (const std::string & _str_)  |
|  const std::vector< [GuiTextInput::Line](ffw_GuiTextInput_Line.html) > & | [getLines](#70121ceb) () const  |
|  bool | [isEmpty](#66602df1) () const  |
|  void | [setStyle](#4e1a7e22) (const [GuiScrollableTextInput::Style](ffw_GuiScrollableTextInput_Style.html) * _style_, bool _defaults_ = false)  |


## Public Functions Documentation

### _function_ <a id="c6ff52dd" href="#c6ff52dd">GuiScrollableTextInput</a>

```cpp
 GuiScrollableTextInput (
    GuiWindow * context,
    bool editable = true
) 
```



### _function_ <a id="dfd20565" href="#dfd20565">~GuiScrollableTextInput</a>

```cpp
virtual  ~GuiScrollableTextInput () 
```



### _function_ <a id="47d11e79" href="#47d11e79">getInner</a>

```cpp
inline const GuiTextInput * getInner () const 
```



### _function_ <a id="b4d7aec2" href="#b4d7aec2">getInner</a>

```cpp
inline GuiTextInput * getInner () 
```



### _function_ <a id="a6d058ad" href="#a6d058ad">setValue</a>

```cpp
inline void setValue (
    const std::string & str
) 
```



### _function_ <a id="9998905b" href="#9998905b">getValue</a>

```cpp
inline std::string getValue () const 
```



### _function_ <a id="6a3181ce" href="#6a3181ce">appendValue</a>

```cpp
inline void appendValue (
    const std::string & str
) 
```



### _function_ <a id="70121ceb" href="#70121ceb">getLines</a>

```cpp
inline const std::vector< GuiTextInput::Line > & getLines () const 
```



### _function_ <a id="66602df1" href="#66602df1">isEmpty</a>

```cpp
inline bool isEmpty () const 
```



### _function_ <a id="4e1a7e22" href="#4e1a7e22">setStyle</a>

```cpp
void setStyle (
    const GuiScrollableTextInput::Style * style,
    bool defaults = false
) 
```





