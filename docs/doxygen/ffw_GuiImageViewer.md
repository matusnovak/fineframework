GuiImageViewer
===================================


**Inherits from:** [ffw::GuiWidget](ffw_GuiWidget.html)

The documentation for this class was generated from: `include/ffw/gui/guiimageviewer.h`



## Classes

| Name |
|:-----|
| struct [ffw::GuiImageViewer::Style](ffw_GuiImageViewer_Style.html) |


## Public Functions

| Type | Name |
| -------: | :------- |
|   | [GuiImageViewer](#6855d9d2) ([GuiWindow](ffw_GuiWindow.html) * _context_, const [GuiImage](ffw_GuiImage.html) * _image_)  |
|  virtual  | [~GuiImageViewer](#899a7cda) ()  |
|  void | [setImage](#1b34fe44) (const [GuiImage](ffw_GuiImage.html) * _image_)  |
|  void | [setSubsection](#9a424d79) (int _posx_, int _posy_, int _width_, int _height_)  |
|  void | [setMirror](#cfce6e50) (bool _mirrorX_, bool _mirrorY_)  |
|  const [GuiImage](ffw_GuiImage.html) * | [getImage](#a58bb1c0) () const  |
|  const [ffw::Vec4i](ffw.html#fd5627df) | [getSubsection](#5c7dd086) () const  |
|  const [ffw::Vec2](ffw_Vec2.html)< bool > | [getMirror](#6d972d68) () const  |
|  void | [setLabel](#88203e70) (const std::string & _label_)  |
|  const std::string & | [getLabel](#1be316a7) () const  |
|  virtual [ffw::Vec2f](ffw.html#fcfaa6c5) | [getMinimumWrapSize](#27d6334f) ()  |
|  void | [setStyle](#5d43b083) (const [GuiImageViewer::Style](ffw_GuiImageViewer_Style.html) * _style_, bool _defaults_ = false)  |


## Public Functions Documentation

### _function_ <a id="6855d9d2" href="#6855d9d2">GuiImageViewer</a>

```cpp
 GuiImageViewer (
    GuiWindow * context,
    const GuiImage * image
) 
```



### _function_ <a id="899a7cda" href="#899a7cda">~GuiImageViewer</a>

```cpp
virtual  ~GuiImageViewer () 
```



### _function_ <a id="1b34fe44" href="#1b34fe44">setImage</a>

```cpp
void setImage (
    const GuiImage * image
) 
```



### _function_ <a id="9a424d79" href="#9a424d79">setSubsection</a>

```cpp
void setSubsection (
    int posx,
    int posy,
    int width,
    int height
) 
```



### _function_ <a id="cfce6e50" href="#cfce6e50">setMirror</a>

```cpp
void setMirror (
    bool mirrorX,
    bool mirrorY
) 
```



### _function_ <a id="a58bb1c0" href="#a58bb1c0">getImage</a>

```cpp
inline const GuiImage * getImage () const 
```



### _function_ <a id="5c7dd086" href="#5c7dd086">getSubsection</a>

```cpp
inline const ffw::Vec4i getSubsection () const 
```



### _function_ <a id="6d972d68" href="#6d972d68">getMirror</a>

```cpp
inline const ffw::Vec2< bool > getMirror () const 
```



### _function_ <a id="88203e70" href="#88203e70">setLabel</a>

```cpp
void setLabel (
    const std::string & label
) 
```



### _function_ <a id="1be316a7" href="#1be316a7">getLabel</a>

```cpp
const std::string & getLabel () const 
```



### _function_ <a id="27d6334f" href="#27d6334f">getMinimumWrapSize</a>

```cpp
virtual ffw::Vec2f getMinimumWrapSize () 
```



**Overrides:** [getMinimumWrapSize](/doxygen/ffw_GuiWidget.md#c12efa3f) from class [GuiWidget](/doxygen/ffw_GuiWidget.md)

### _function_ <a id="5d43b083" href="#5d43b083">setStyle</a>

```cpp
void setStyle (
    const GuiImageViewer::Style * style,
    bool defaults = false
) 
```





