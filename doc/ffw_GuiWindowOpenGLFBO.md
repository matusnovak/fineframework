GuiWindowOpenGLFBO
===================================


**Inherits from:** [ffw::GuiWindowOpenGL](ffw_GuiWindowOpenGL.html)

The documentation for this class was generated from: `include/ffw/gui/guiwindowopengl.h`



## Public Functions

| Type | Name |
| -------: | :------- |
|   | [GuiWindowOpenGLFBO](#54592615) ()  |
|  virtual  | [~GuiWindowOpenGLFBO](#2dc56e4a) ()  |
|  virtual bool | [create](#9d89fc93) ([RenderContext](ffw_RenderContext.html) * _ctx_)  |
|  virtual void | [destroy](#17a89158) ()  |
|  virtual void | [resize](#17470439) (int _width_, int _height_)  |
|  virtual void | [startRender](#0a4cdf90) ()  |
|  virtual void | [endRender](#222ae168) ()  |
|  const [ffw::Texture2D](ffw_Texture2D.html) * | [getFboTexture](#c45e9c10) () const  |


## Public Functions Documentation

### <span style="opacity:0.5;">function</span> <a id="54592615" href="#54592615">GuiWindowOpenGLFBO</a>

```cpp
inline  GuiWindowOpenGLFBO () 
```



### <span style="opacity:0.5;">function</span> <a id="2dc56e4a" href="#2dc56e4a">~GuiWindowOpenGLFBO</a>

```cpp
inline virtual  ~GuiWindowOpenGLFBO () 
```



### <span style="opacity:0.5;">function</span> <a id="9d89fc93" href="#9d89fc93">create</a>

```cpp
inline virtual bool create (
    RenderContext * ctx
) 
```



**Overrides:** [create](/doc/ffw_GuiWindowOpenGL.md#c7df1c0d)

### <span style="opacity:0.5;">function</span> <a id="17a89158" href="#17a89158">destroy</a>

```cpp
inline virtual void destroy () 
```



**Overrides:** [destroy](/doc/ffw_GuiWindowOpenGL.md#69b35170)

### <span style="opacity:0.5;">function</span> <a id="17470439" href="#17470439">resize</a>

```cpp
inline virtual void resize (
    int width,
    int height
) 
```



**Overrides:** [resize](/doc/ffw_GuiWindowOpenGL.md#b42ac84e)

### <span style="opacity:0.5;">function</span> <a id="0a4cdf90" href="#0a4cdf90">startRender</a>

```cpp
inline virtual void startRender () 
```



**Overrides:** [startRender](/doc/ffw_GuiWindowOpenGL.md#0ebe5781)

### <span style="opacity:0.5;">function</span> <a id="222ae168" href="#222ae168">endRender</a>

```cpp
inline virtual void endRender () 
```



**Overrides:** [endRender](/doc/ffw_GuiWindowOpenGL.md#d5a627e1)

### <span style="opacity:0.5;">function</span> <a id="c45e9c10" href="#c45e9c10">getFboTexture</a>

```cpp
inline const ffw::Texture2D * getFboTexture () const 
```





