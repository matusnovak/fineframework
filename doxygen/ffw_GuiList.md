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
|  void | [deleteAllItems](#91f94fa7) ()  |
|  bool | [deleteItem](#a671ea86) (const [GuiList::Item](ffw_GuiList_Item.html) * _item_)  |
|  void | [setSelected](#622970ed) (int _index_)  |
|  void | [resetSelected](#8c4e7891) ()  |
|  void | [setSelected](#7f9a1693) (const [GuiList::Item](ffw_GuiList_Item.html) * _item_)  |
|  [GuiList::Item](ffw_GuiList_Item.html) * | [getSelectedItem](#2f1eb20c) () const  |
|  virtual void | [eventThemeChanged](#86eb2b69) (const [GuiTheme](ffw_GuiTheme.html) * _theme_)  |


## Public Functions Documentation

### _function_ <a id="ac9d0483" href="#ac9d0483">GuiList</a>

```cpp
 GuiList (
    GuiWindow * context
) 
```



### _function_ <a id="0f3ac750" href="#0f3ac750">~GuiList</a>

```cpp
virtual  ~GuiList () 
```



### _function_ <a id="dbe62119" href="#dbe62119">addItem</a>

```cpp
GuiList::Item * addItem (
    const std::string & label
) 
```



### _function_ <a id="d8db7b91" href="#d8db7b91">addItem</a>

```cpp
GuiList::Item * addItem (
    const std::wstring & label
) 
```



### _function_ <a id="91f94fa7" href="#91f94fa7">deleteAllItems</a>

```cpp
void deleteAllItems () 
```



### _function_ <a id="a671ea86" href="#a671ea86">deleteItem</a>

```cpp
bool deleteItem (
    const GuiList::Item * item
) 
```



### _function_ <a id="622970ed" href="#622970ed">setSelected</a>

```cpp
void setSelected (
    int index
) 
```



### _function_ <a id="8c4e7891" href="#8c4e7891">resetSelected</a>

```cpp
void resetSelected () 
```



### _function_ <a id="7f9a1693" href="#7f9a1693">setSelected</a>

```cpp
void setSelected (
    const GuiList::Item * item
) 
```



### _function_ <a id="2f1eb20c" href="#2f1eb20c">getSelectedItem</a>

```cpp
GuiList::Item * getSelectedItem () const 
```



### _function_ <a id="86eb2b69" href="#86eb2b69">eventThemeChanged</a>

```cpp
virtual void eventThemeChanged (
    const GuiTheme * theme
) 
```



**Overrides:** [eventThemeChanged](/doxygen/ffw_GuiWidget.md#d1726419) from class [GuiWidget](/doxygen/ffw_GuiWidget.md)



