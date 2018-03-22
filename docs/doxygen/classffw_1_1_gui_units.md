---
search:
    keywords: ['ffw::GuiUnits', 'Type', 'value', 'GuiUnits', 'GuiUnits', 'GuiUnits', 'operator==', 'operator!=', 'operator==', 'operator!=', 'operator==', 'operator!=', 'toReal', 'setPixels', 'setPercent', 'getType', 'operator<<']
---

# class ffw::GuiUnits

## Public Types

|Type|Name|
|-----|-----|
|enum|[**Type**](classffw_1_1_gui_units.md#1abc668dedfe3c99fb9cb1aca310d626ca) { **PERCENT**, **PIXELS**, **WRAP** } |


## Public Attributes

|Type|Name|
|-----|-----|
|float|[**value**](classffw_1_1_gui_units.md#1abb35051c8539f3537024ba1ad3064d45)|


## Public Functions

|Type|Name|
|-----|-----|
||[**GuiUnits**](classffw_1_1_gui_units.md#1af6e233ce982f52b1d81768e5c59d9301) () |
||[**GuiUnits**](classffw_1_1_gui_units.md#1a00b0821be4ec7effc6924c096a629c11) (float val, bool percentage) |
||[**GuiUnits**](classffw_1_1_gui_units.md#1a3b25adc7b759b5bae0b71db08860136f) (float val) |
|bool|[**operator==**](classffw_1_1_gui_units.md#1ae878c6d347d16d9160f4c325b0af5530) (const **[GuiUnits](classffw_1_1_gui_units.md)** & other) const |
|bool|[**operator!=**](classffw_1_1_gui_units.md#1aa12c88ef7782ce02f780c8138b8151de) (const **[GuiUnits](classffw_1_1_gui_units.md)** & other) const |
|bool|[**operator==**](classffw_1_1_gui_units.md#1a65b7a0ed6f5f510e79cd0368f97f5068) (float v) const |
|bool|[**operator!=**](classffw_1_1_gui_units.md#1aefad2e7f93f9d4bdd0722fc9f766d0c9) (float v) const |
|bool|[**operator==**](classffw_1_1_gui_units.md#1a2c6e7aeccf0c1272e938e0299b2b5b76) (**[Type](classffw_1_1_gui_units.md#1abc668dedfe3c99fb9cb1aca310d626ca)** t) const |
|bool|[**operator!=**](classffw_1_1_gui_units.md#1a69481e6e9c55da65ccce7a5cfcd54567) (**[Type](classffw_1_1_gui_units.md#1abc668dedfe3c99fb9cb1aca310d626ca)** t) const |
|float|[**toReal**](classffw_1_1_gui_units.md#1a0704d9abf5a57b2e4b2e57023cb255fb) (float val) const |
|void|[**setPixels**](classffw_1_1_gui_units.md#1a5c41e3e7ebe894ff745dab8cc14fb36f) (float px) |
|void|[**setPercent**](classffw_1_1_gui_units.md#1a8f7b3716a71341705a022fe8695bb03c) (float pc) |
|**[Type](classffw_1_1_gui_units.md#1abc668dedfe3c99fb9cb1aca310d626ca)**|[**getType**](classffw_1_1_gui_units.md#1ae684eab30c5a8160d7c7163d2a4db5e8) () const |


## Friends

|Type|Name|
|-----|-----|
|friend std::ostream &|[**operator<<**](classffw_1_1_gui_units.md#1a69a2775f4f6dea7c34654eaa381e8942)|


## Public Types Documentation

### enum <a id="1abc668dedfe3c99fb9cb1aca310d626ca" href="#1abc668dedfe3c99fb9cb1aca310d626ca">Type</a>

```cpp
enum ffw::GuiUnits::Type {
    PERCENT,
    PIXELS,
    WRAP,
};
```



## Public Attributes Documentation

### variable <a id="1abb35051c8539f3537024ba1ad3064d45" href="#1abb35051c8539f3537024ba1ad3064d45">value</a>

```cpp
float ffw::GuiUnits::value;
```



## Public Functions Documentation

### function <a id="1af6e233ce982f52b1d81768e5c59d9301" href="#1af6e233ce982f52b1d81768e5c59d9301">GuiUnits</a>

```cpp
ffw::GuiUnits::GuiUnits ()
```



### function <a id="1a00b0821be4ec7effc6924c096a629c11" href="#1a00b0821be4ec7effc6924c096a629c11">GuiUnits</a>

```cpp
ffw::GuiUnits::GuiUnits (
    float val
    bool percentage
)
```



### function <a id="1a3b25adc7b759b5bae0b71db08860136f" href="#1a3b25adc7b759b5bae0b71db08860136f">GuiUnits</a>

```cpp
ffw::GuiUnits::GuiUnits (
    float val
)
```



### function <a id="1ae878c6d347d16d9160f4c325b0af5530" href="#1ae878c6d347d16d9160f4c325b0af5530">operator==</a>

```cpp
bool ffw::GuiUnits::operator== (
    const GuiUnits & other
) const
```



### function <a id="1aa12c88ef7782ce02f780c8138b8151de" href="#1aa12c88ef7782ce02f780c8138b8151de">operator!=</a>

```cpp
bool ffw::GuiUnits::operator!= (
    const GuiUnits & other
) const
```



### function <a id="1a65b7a0ed6f5f510e79cd0368f97f5068" href="#1a65b7a0ed6f5f510e79cd0368f97f5068">operator==</a>

```cpp
bool ffw::GuiUnits::operator== (
    float v
) const
```



### function <a id="1aefad2e7f93f9d4bdd0722fc9f766d0c9" href="#1aefad2e7f93f9d4bdd0722fc9f766d0c9">operator!=</a>

```cpp
bool ffw::GuiUnits::operator!= (
    float v
) const
```



### function <a id="1a2c6e7aeccf0c1272e938e0299b2b5b76" href="#1a2c6e7aeccf0c1272e938e0299b2b5b76">operator==</a>

```cpp
bool ffw::GuiUnits::operator== (
    Type t
) const
```



### function <a id="1a69481e6e9c55da65ccce7a5cfcd54567" href="#1a69481e6e9c55da65ccce7a5cfcd54567">operator!=</a>

```cpp
bool ffw::GuiUnits::operator!= (
    Type t
) const
```



### function <a id="1a0704d9abf5a57b2e4b2e57023cb255fb" href="#1a0704d9abf5a57b2e4b2e57023cb255fb">toReal</a>

```cpp
float ffw::GuiUnits::toReal (
    float val
) const
```



### function <a id="1a5c41e3e7ebe894ff745dab8cc14fb36f" href="#1a5c41e3e7ebe894ff745dab8cc14fb36f">setPixels</a>

```cpp
void ffw::GuiUnits::setPixels (
    float px
)
```



### function <a id="1a8f7b3716a71341705a022fe8695bb03c" href="#1a8f7b3716a71341705a022fe8695bb03c">setPercent</a>

```cpp
void ffw::GuiUnits::setPercent (
    float pc
)
```



### function <a id="1ae684eab30c5a8160d7c7163d2a4db5e8" href="#1ae684eab30c5a8160d7c7163d2a4db5e8">getType</a>

```cpp
Type ffw::GuiUnits::getType () const
```



## Friends Documentation

### friend <a id="1a69a2775f4f6dea7c34654eaa381e8942" href="#1a69a2775f4f6dea7c34654eaa381e8942">operator<<</a>

```cpp
friend std::ostream & operator<< (
    std::ostream & os
    const GuiUnits & V
)
```





----------------------------------------
The documentation for this class was generated from the following file: `include/ffw/gui/guistyle.h`
