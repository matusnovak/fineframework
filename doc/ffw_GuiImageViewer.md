GuiImageViewer
===================================


**Inherits from:** [ffw::GuiWidget](ffw_GuiWidget.html)

The documentation for this class was generated from: `include/ffw/gui/guiimageviewer.h`



## Public Functions

| Type | Name |
| -------: | :------- |
|   | [GuiImageViewer](#6855d9d2) ([GuiWindow](ffw_GuiWindow.html) * _context_, const [GuiImage](ffw_GuiImage.html) * _image_)  |
|  virtual  | [~GuiImageViewer](#7677f6f8) ()  |
|  void | [setImage](#1b34fe44) (const [GuiImage](ffw_GuiImage.html) * _image_)  |
|  void | [setSubsection](#9a424d79) (int _posx_, int _posy_, int _width_, int _height_)  |
|  void | [setMirror](#cfce6e50) (bool _mirrorX_, bool _mirrorY_)  |
|  const [GuiImage](ffw_GuiImage.html) * | [getImage](#a58bb1c0) () const  |
|  const [ffw::Vec4i](ffw.html#fd5627df) | [getSubsection](#5c7dd086) () const  |
|  const [ffw::Vec2](ffw_Vec2.html)< bool > | [getMirror](#6d972d68) () const  |
|  void | [setLabel](#77fe8a18) (const std::wstring & _label_)  |
|  const std::wstring & | [getLabel](#d405c588) () const  |
|  virtual [ffw::Vec2f](ffw.html#fcfaa6c5) | [getMinimumWrapSize](#27d6334f) ()  |


## Public Functions Documentation

### <span style="opacity:0.5;">function</span> <a id="6855d9d2" href="#6855d9d2">GuiImageViewer</a>

```cpp
 GuiImageViewer (
    GuiWindow * context,
    const GuiImage * image
) 
```



### <span style="opacity:0.5;">function</span> <a id="7677f6f8" href="#7677f6f8">~GuiImageViewer</a>

```cpp
virtual  ~GuiImageViewer () 
```



### <span style="opacity:0.5;">function</span> <a id="1b34fe44" href="#1b34fe44">setImage</a>

```cpp
void setImage (
    const GuiImage * image
) 
```



### <span style="opacity:0.5;">function</span> <a id="9a424d79" href="#9a424d79">setSubsection</a>

```cpp
void setSubsection (
    int posx,
    int posy,
    int width,
    int height
) 
```



### <span style="opacity:0.5;">function</span> <a id="cfce6e50" href="#cfce6e50">setMirror</a>

```cpp
void setMirror (
    bool mirrorX,
    bool mirrorY
) 
```



### <span style="opacity:0.5;">function</span> <a id="a58bb1c0" href="#a58bb1c0">getImage</a>

```cpp
inline const GuiImage * getImage () const 
```



### <span style="opacity:0.5;">function</span> <a id="5c7dd086" href="#5c7dd086">getSubsection</a>

```cpp
inline const ffw::Vec4i getSubsection () const 
```



### <span style="opacity:0.5;">function</span> <a id="6d972d68" href="#6d972d68">getMirror</a>

```cpp
inline const ffw::Vec2< bool > getMirror () const 
```



### <span style="opacity:0.5;">function</span> <a id="77fe8a18" href="#77fe8a18">setLabel</a>

```cpp
void setLabel (
    const std::wstring & label
) 
```



### <span style="opacity:0.5;">function</span> <a id="d405c588" href="#d405c588">getLabel</a>

```cpp
const std::wstring & getLabel () const 
```



### <span style="opacity:0.5;">function</span> <a id="27d6334f" href="#27d6334f">getMinimumWrapSize</a>

```cpp
virtual ffw::Vec2f getMinimumWrapSize () 
```





