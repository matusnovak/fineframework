GuiWindow
===================================


**Inherits from:** [ffw::GuiBackend](ffw_GuiBackend.html)

**Implemented by:** [ffw::GuiWindowOpenGL](ffw_GuiWindowOpenGL.html)

The documentation for this class was generated from: `include/ffw/gui/guiwindow.h`



## Classes

| Name |
|:-----|
| class [ffw::GuiWindow::GuiBody](ffw_GuiWindow_GuiBody.html) |


## Public Functions

| Type | Name |
| -------: | :------- |
|   | [GuiWindow](#a822aba1) ()  |
|  virtual  | [~GuiWindow](#53e120cd) ()  |
|  void | [setSize](#db6ddb25) (float _width_, float _height_)  |
|  void | [setPos](#61a1780e) (float _posx_, float _posy_)  |
|  const [ffw::Vec2f](ffw.html#fcfaa6c5) & | [getSize](#a505427e) () const  |
|  const [ffw::Vec2f](ffw.html#fcfaa6c5) & | [getPos](#b35912fc) () const  |
|  void | [setDefaultFont](#7fd40fdb) (const [GuiFont](ffw_GuiFont.html) * _font_)  |
|  const [GuiFont](ffw_GuiFont.html) * | [getDefaultFont](#507407d4) () const  |
|  void | [injectMousePos](#3839704a) (float _posx_, float _posy_)  |
|  void | [injectScroll](#802b79e7) (float _posx_, float _posy_)  |
|  void | [injectMouseButton](#361bd42e) ([ffw::MouseButton](ffw.html#f80e46cc) _button_, [ffw::Mode](ffw.html#e03b52d5) _mode_)  |
|  void | [injectText](#b9f6c301) (wchar_t _chr_)  |
|  void | [injectKey](#f62ed06f) ([ffw::Key](ffw.html#23661d50) _key_, [ffw::Mode](ffw.html#e03b52d5) _mode_)  |
|  void | [update](#b67089c1) ()  |
|  void | [poolEvents](#7324b13c) ()  |
|  void | [render](#57028522) ()  |
|  void | [redraw](#ca2d8285) ()  |
|  void | [invalidate](#259d7ad9) ()  |
|  [GuiBody](ffw_GuiWindow_GuiBody.html) * | [getLayout](#a49898b5) ()  |
|  const [GuiBody](ffw_GuiWindow_GuiBody.html) * | [getLayout](#d07c9698) () const  |
|  void | [pushEvent](#0823111d) ([GuiCallback](ffw_GuiCallback.html) & _callback_, [GuiEvent](ffw_GuiEvent.html) _e_)  |
|  void | [setTheme](#40af0639) (const [GuiTheme](ffw_GuiTheme.html) * _thm_)  |
|  const [GuiTheme](ffw_GuiTheme.html) * | [getTheme](#85a09d54) () const  |
|  T * | [findByID](#a132c39b) (unsigned long _id_)  |


## Public Functions Documentation

### <span style="opacity:0.5;">function</span> <a id="a822aba1" href="#a822aba1">GuiWindow</a>

```cpp
 GuiWindow () 
```



### <span style="opacity:0.5;">function</span> <a id="53e120cd" href="#53e120cd">~GuiWindow</a>

```cpp
virtual  ~GuiWindow () 
```



### <span style="opacity:0.5;">function</span> <a id="db6ddb25" href="#db6ddb25">setSize</a>

```cpp
void setSize (
    float width,
    float height
) 
```



### <span style="opacity:0.5;">function</span> <a id="61a1780e" href="#61a1780e">setPos</a>

```cpp
void setPos (
    float posx,
    float posy
) 
```



### <span style="opacity:0.5;">function</span> <a id="a505427e" href="#a505427e">getSize</a>

```cpp
const ffw::Vec2f & getSize () const 
```



### <span style="opacity:0.5;">function</span> <a id="b35912fc" href="#b35912fc">getPos</a>

```cpp
const ffw::Vec2f & getPos () const 
```



### <span style="opacity:0.5;">function</span> <a id="7fd40fdb" href="#7fd40fdb">setDefaultFont</a>

```cpp
void setDefaultFont (
    const GuiFont * font
) 
```



### <span style="opacity:0.5;">function</span> <a id="507407d4" href="#507407d4">getDefaultFont</a>

```cpp
const GuiFont * getDefaultFont () const 
```



### <span style="opacity:0.5;">function</span> <a id="3839704a" href="#3839704a">injectMousePos</a>

```cpp
void injectMousePos (
    float posx,
    float posy
) 
```



### <span style="opacity:0.5;">function</span> <a id="802b79e7" href="#802b79e7">injectScroll</a>

```cpp
void injectScroll (
    float posx,
    float posy
) 
```



### <span style="opacity:0.5;">function</span> <a id="361bd42e" href="#361bd42e">injectMouseButton</a>

```cpp
void injectMouseButton (
    ffw::MouseButton button,
    ffw::Mode mode
) 
```



### <span style="opacity:0.5;">function</span> <a id="b9f6c301" href="#b9f6c301">injectText</a>

```cpp
void injectText (
    wchar_t chr
) 
```



### <span style="opacity:0.5;">function</span> <a id="f62ed06f" href="#f62ed06f">injectKey</a>

```cpp
void injectKey (
    ffw::Key key,
    ffw::Mode mode
) 
```



### <span style="opacity:0.5;">function</span> <a id="b67089c1" href="#b67089c1">update</a>

```cpp
void update () 
```



### <span style="opacity:0.5;">function</span> <a id="7324b13c" href="#7324b13c">poolEvents</a>

```cpp
void poolEvents () 
```



### <span style="opacity:0.5;">function</span> <a id="57028522" href="#57028522">render</a>

```cpp
void render () 
```



### <span style="opacity:0.5;">function</span> <a id="ca2d8285" href="#ca2d8285">redraw</a>

```cpp
void redraw () 
```



### <span style="opacity:0.5;">function</span> <a id="259d7ad9" href="#259d7ad9">invalidate</a>

```cpp
void invalidate () 
```



### <span style="opacity:0.5;">function</span> <a id="a49898b5" href="#a49898b5">getLayout</a>

```cpp
inline GuiBody * getLayout () 
```



### <span style="opacity:0.5;">function</span> <a id="d07c9698" href="#d07c9698">getLayout</a>

```cpp
inline const GuiBody * getLayout () const 
```



### <span style="opacity:0.5;">function</span> <a id="0823111d" href="#0823111d">pushEvent</a>

```cpp
void pushEvent (
    GuiCallback & callback,
    GuiEvent e
) 
```



### <span style="opacity:0.5;">function</span> <a id="40af0639" href="#40af0639">setTheme</a>

```cpp
void setTheme (
    const GuiTheme * thm
) 
```



### <span style="opacity:0.5;">function</span> <a id="85a09d54" href="#85a09d54">getTheme</a>

```cpp
const GuiTheme * getTheme () const 
```



### <span style="opacity:0.5;">function</span> <a id="a132c39b" href="#a132c39b">findByID</a>

```cpp
inline T * findByID (
    unsigned long id
) 
```





