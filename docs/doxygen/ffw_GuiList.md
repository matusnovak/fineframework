GuiList
===================================


**Inherits from:** [ffw::GuiScrollableLayout](ffw_GuiScrollableLayout.html)

The documentation for this class was generated from: `include/ffw/gui/guilist.h`



## Classes

| Name |
|:-----|
| class [ffw::GuiList::Item](ffw_GuiList_Item.html) |
| struct [ffw::GuiList::Style](ffw_GuiList_Style.html) |
| class [ffw::GuiList::Value](ffw_GuiList_Value.html) |


## Public Functions

| Type | Name |
| -------: | :------- |
|   | [GuiList](#ac9d0483) ([GuiWindow](ffw_GuiWindow.html) * _context_)  |
|  virtual  | [~GuiList](#3b564686) ()  |
|  [GuiList::Item](ffw_GuiList_Item.html) * | [addItem](#dbe62119) (const std::string & _label_)  |
|  void | [deleteAllItems](#91f94fa7) ()  |
|  bool | [deleteItem](#a671ea86) (const [GuiList::Item](ffw_GuiList_Item.html) * _item_)  |
|  void | [setSelectedIndex](#e85efdb3) (int _index_)  |
|  void | [resetSelected](#8c4e7891) ()  |
|  void | [setSelected](#7f9a1693) (const [GuiList::Item](ffw_GuiList_Item.html) * _item_)  |
|  [GuiList::Item](ffw_GuiList_Item.html) * | [getSelectedItem](#2f1eb20c) () const  |
|  int | [getSelectedIndex](#3d192788) () const  |
|  void | [setStyle](#b79ae37e) (const [GuiList::Style](ffw_GuiList_Style.html) * _style_, bool _defaults_ = false)  |


## Public Functions Documentation

### _function_ <a id="ac9d0483" href="#ac9d0483">GuiList</a>

```cpp
 GuiList (
    GuiWindow * context
) 
```



### _function_ <a id="3b564686" href="#3b564686">~GuiList</a>

```cpp
virtual  ~GuiList () 
```



### _function_ <a id="dbe62119" href="#dbe62119">addItem</a>

```cpp
GuiList::Item * addItem (
    const std::string & label
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



### _function_ <a id="e85efdb3" href="#e85efdb3">setSelectedIndex</a>

```cpp
void setSelectedIndex (
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



### _function_ <a id="3d192788" href="#3d192788">getSelectedIndex</a>

```cpp
int getSelectedIndex () const 
```



### _function_ <a id="b79ae37e" href="#b79ae37e">setStyle</a>

```cpp
void setStyle (
    const GuiList::Style * style,
    bool defaults = false
) 
```





