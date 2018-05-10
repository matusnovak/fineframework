---
search: false
---

# class ffw::GuiStyle::Background

## Public Types

|Type|Name|
|-----|-----|
|enum|[**Type**](classffw_1_1_gui_style_1_1_background.md#1a9d7a2924bd2ec2ec0c0fa186d543b65f) { **NONE** = 0, **SIMPLE** } |
|typedef **[Attribute](classffw_1_1_gui_style_1_1_attribute.md)**< float >|[**Radius**](classffw_1_1_gui_style_1_1_background.md#1adf8f2648fffa8c63eb359bfcff0e8ec1)|


## Public Attributes

|Type|Name|
|-----|-----|
|**[Attribute](classffw_1_1_gui_style_1_1_attribute.md)**< float >|[**radius**](classffw_1_1_gui_style_1_1_background.md#1a6ae4b560a0465514b5bb63f83af158f5)|
|**[ffw::Color](structffw_1_1_color.md)**|[**color**](classffw_1_1_gui_style_1_1_background.md#1af3fe4d79bbc63d24826483225ecfb2f9)|
|**[Type](classffw_1_1_gui_style_1_1_background.md#1a9d7a2924bd2ec2ec0c0fa186d543b65f)**|[**type**](classffw_1_1_gui_style_1_1_background.md#1af1b021ff4e52a0e10ff2b7e8236ea164)|


## Public Functions

|Type|Name|
|-----|-----|
||[**Background**](classffw_1_1_gui_style_1_1_background.md#1af97ca5c332444342e14fe9ddb04d6e25) () |
||[**Background**](classffw_1_1_gui_style_1_1_background.md#1a7fc94731c78a6704ec39d0d77c0fb4be) (const **[ffw::Color](structffw_1_1_color.md)** & c) |
||[**Background**](classffw_1_1_gui_style_1_1_background.md#1a649be822fc54f705fc2cb04cda99493d) (const **[Attribute](classffw_1_1_gui_style_1_1_attribute.md)**< float > & r, const **[ffw::Color](structffw_1_1_color.md)** & c) |
||[**operator bool**](classffw_1_1_gui_style_1_1_background.md#1ad18d6b2c3bafce48274253d024470f55) () const |


## Public Types Documentation

### enum <a id="1a9d7a2924bd2ec2ec0c0fa186d543b65f" href="#1a9d7a2924bd2ec2ec0c0fa186d543b65f">Type</a>

```cpp
enum ffw::GuiStyle::Background::Type {
    NONE = 0,
    SIMPLE,
};
```



### typedef <a id="1adf8f2648fffa8c63eb359bfcff0e8ec1" href="#1adf8f2648fffa8c63eb359bfcff0e8ec1">Radius</a>

```cpp
typedef Attribute<float> ffw::GuiStyle::Background::Radius;
```



## Public Attributes Documentation

### variable <a id="1a6ae4b560a0465514b5bb63f83af158f5" href="#1a6ae4b560a0465514b5bb63f83af158f5">radius</a>

```cpp
Attribute<float> ffw::GuiStyle::Background::radius;
```



### variable <a id="1af3fe4d79bbc63d24826483225ecfb2f9" href="#1af3fe4d79bbc63d24826483225ecfb2f9">color</a>

```cpp
ffw::Color ffw::GuiStyle::Background::color;
```



### variable <a id="1af1b021ff4e52a0e10ff2b7e8236ea164" href="#1af1b021ff4e52a0e10ff2b7e8236ea164">type</a>

```cpp
Type ffw::GuiStyle::Background::type;
```



## Public Functions Documentation

### function <a id="1af97ca5c332444342e14fe9ddb04d6e25" href="#1af97ca5c332444342e14fe9ddb04d6e25">Background</a>

```cpp
ffw::GuiStyle::Background::Background ()
```



### function <a id="1a7fc94731c78a6704ec39d0d77c0fb4be" href="#1a7fc94731c78a6704ec39d0d77c0fb4be">Background</a>

```cpp
ffw::GuiStyle::Background::Background (
    const ffw::Color & c
)
```



### function <a id="1a649be822fc54f705fc2cb04cda99493d" href="#1a649be822fc54f705fc2cb04cda99493d">Background</a>

```cpp
ffw::GuiStyle::Background::Background (
    const Attribute< float > & r
    const ffw::Color & c
)
```



### function <a id="1ad18d6b2c3bafce48274253d024470f55" href="#1ad18d6b2c3bafce48274253d024470f55">operator bool</a>

```cpp
ffw::GuiStyle::Background::operator bool () const
```





----------------------------------------
The documentation for this class was generated from the following file: `include/ffw/gui/guistyle.h`
