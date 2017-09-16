GuiList
===================================


**Inherits from:** [ffw::GuiScrollableLayout](ffw_GuiScrollableLayout.html)

The documentation for this class was generated from: `include/ffw/gui/guilist.h`



## Classes

| Name |
|:-----|
| class [ffw::GuiList::Item](ffw_GuiList_Item.html) |
| class [ffw::GuiList::Value](ffw_GuiList_Value.html) |


## Public Functions

| Type | Name |
| -------: | :------- |
|   | [GuiList](#ac9d0483) ([GuiWindow](ffw_GuiWindow.html) * _context_)  |
|  virtual  | [~GuiList](#0f3ac750) ()  |
|  [GuiList::Item](ffw_GuiList_Item.html) * | [addItem](#dbe62119) (const std::string & _label_)  |
|  [GuiList::Item](ffw_GuiList_Item.html) * | [addItem](#d8db7b91) (const std::wstring & _label_)  |
|  void | [DeleteAllItems](#acdb3ed2) ()  |
|  bool | [DeleteItem](#e7a3d0e3) (const [GuiList::Item](ffw_GuiList_Item.html) * _item_)  |
|  void | [setSelected](#622970ed) (int _index_)  |
|  void | [ResetSelected](#724a77bf) ()  |
|  void | [setSelected](#7f9a1693) (const [GuiList::Item](ffw_GuiList_Item.html) * _item_)  |
|  [GuiList::Item](ffw_GuiList_Item.html) * | [getSelectedItem](#2f1eb20c) () const  |
|  virtual void | [eventThemeChanged](#86eb2b69) (const [GuiTheme](ffw_GuiTheme.html) * _theme_)  |


## Public Functions Documentation

### <span style="opacity:0.5;">function</span> <a id="ac9d0483" href="#ac9d0483">GuiList</a>

```cpp
 GuiList (
    GuiWindow * context
) 
```



### <span style="opacity:0.5;">function</span> <a id="0f3ac750" href="#0f3ac750">~GuiList</a>

```cpp
virtual  ~GuiList () 
```



### <span style="opacity:0.5;">function</span> <a id="dbe62119" href="#dbe62119">addItem</a>

```cpp
GuiList::Item * addItem (
    const std::string & label
) 
```



### <span style="opacity:0.5;">function</span> <a id="d8db7b91" href="#d8db7b91">addItem</a>

```cpp
GuiList::Item * addItem (
    const std::wstring & label
) 
```



### <span style="opacity:0.5;">function</span> <a id="acdb3ed2" href="#acdb3ed2">DeleteAllItems</a>

```cpp
void DeleteAllItems () 
```



### <span style="opacity:0.5;">function</span> <a id="e7a3d0e3" href="#e7a3d0e3">DeleteItem</a>

```cpp
bool DeleteItem (
    const GuiList::Item * item
) 
```



### <span style="opacity:0.5;">function</span> <a id="622970ed" href="#622970ed">setSelected</a>

```cpp
void setSelected (
    int index
) 
```



### <span style="opacity:0.5;">function</span> <a id="724a77bf" href="#724a77bf">ResetSelected</a>

```cpp
void ResetSelected () 
```



### <span style="opacity:0.5;">function</span> <a id="7f9a1693" href="#7f9a1693">setSelected</a>

```cpp
void setSelected (
    const GuiList::Item * item
) 
```



### <span style="opacity:0.5;">function</span> <a id="2f1eb20c" href="#2f1eb20c">getSelectedItem</a>

```cpp
GuiList::Item * getSelectedItem () const 
```



### <span style="opacity:0.5;">function</span> <a id="86eb2b69" href="#86eb2b69">eventThemeChanged</a>

```cpp
virtual void eventThemeChanged (
    const GuiTheme * theme
) 
```





