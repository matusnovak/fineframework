GLFWRenderWindow
===================================


**Inherits from:** [ffw::RenderWindow](ffw_RenderWindow.html), [ffw::RenderContext](ffw_RenderContext.html)

The documentation for this class was generated from: `include/ffw/graphics/glfwrenderwindow.h`



## Friends

| Type | Name |
| -------: | :------- |
|  friend struct | [windowCallback](#4bc0e89f) |


## Public Static Functions

| Type | Name |
| -------: | :------- |
|  std::vector< [Monitor](ffw_Monitor.html) > | [getMonitors](#074c67e8) ()  _Returns a vector of all physical monitors available._ |
|  [Monitor](ffw_Monitor.html) | [getPrimaryMonitor](#17b52d27) ()  _Returns the primary monitor defined by the OS._ |
|  std::vector< [Monitor::Mode](ffw_Monitor_Mode.html) > | [getMonitorModes](#8fb7ed82) ([Monitor](ffw_Monitor.html) _monitor_)  _Returns all possible modes for the given monitor._ |


## Public Functions

| Type | Name |
| -------: | :------- |
|   | [GLFWRenderWindow](#3ddc7739) ()  |
|  virtual  | [~GLFWRenderWindow](#58da4a58) ()  |
|  virtual void | [setPos](#20e4ebb1) (int _posx_, int _posy_)  _Sets the position of the window._ |
|  virtual void | [setSize](#70055684) (int _width_, int _height_)  _Sets the size of the window._ |
|  virtual [ffw::Vec2i](ffw.html#e4e07ebe) | [getPos](#6e45fa20) () const  |
|  virtual [ffw::Vec2i](ffw.html#e4e07ebe) | [getSize](#70919473) () const  |
|  bool | [create](#487f0d6e) (const [GLFWRenderWindowArgs](ffw_GLFWRenderWindowArgs.html) & _args_, [GLFWRenderWindow](ffw_GLFWRenderWindow.html) * _other_, [Monitor](ffw_Monitor.html) * _monitor_ = NULL)  _Creates the window._ |
|  void | [setWindowedMode](#500484b5) ()  _Sets the window into windowed mode, if the window was in maximized mode._ |
|  void | [setWindowedMode](#1af15aab) (int _posx_, int _posy_, int _width_, int _height_)  _Sets the window into windowed mode with specific size and position._ |
|  void | [setFullscreen](#78a84d10) (const [Monitor](ffw_Monitor.html) * _monitor_)  _Sets the window into fullscreen mode._ |
|  virtual void | [destroy](#a6cd0e35) ()  _Destroys the window and it's context._ |
|  virtual bool | [shouldRender](#a7405bd4) () const  _Returns true if the window is not closed._ |
|  virtual void | [renderFrame](#72132dff) ()  _Renders a frame._ |
|  virtual void | [poolEvents](#9e15cebe) ()  _Pools all user input events, if any._ |
|  virtual void | [waitForEvents](#242fc91e) ()  _Pools all user input events and waits if there is none._ |
|  virtual bool | [isInitialized](#7ec0b6df) () const  _Returns true if the window is initialized._ |
|  virtual void * | [getGlextFunc](#aa2500a8) (const std::string & _name_) const  _Retuns the address of the GL extension function._ |
|  virtual bool | [isGlextExtSupported](#e2a22288) (const std::string & _name_) const  _Returns true if the GL extension is suported._ |
|  void | [setSwapInterval](#c327f0a5) (int _interval_)  |
|  virtual void | [shouldClose](#f26e03bc) (bool _close_)  _Set whether the window should close or stay alive._ |
|  virtual void | [show](#810c9891) ()  _Shows the window if the window has been hidden._ |
|  virtual void | [hide](#22589352) ()  _Hides the window if the window is visible._ |
|  virtual void | [iconify](#778bb08b) ()  _Minimizes the window into the task bar._ |
|  virtual void | [restore](#2d91152d) ()  _Restores minimized window into a visible window._ |
|  virtual void | [maximize](#129f289a) ()  _Maximizes the window in order to utilize whole screen._ |
|  virtual void | [setSingleBufferMode](#44d7a377) (bool _enabled_)  _Sets whether the window should operate using two buffets (back and front) or only in one._ |
|  [GLFWRenderWindow](ffw_GLFWRenderWindow.html) & | [operator=](#3e315e2e) (const [GLFWRenderWindow](ffw_GLFWRenderWindow.html) &) = delete  |
|   | [GLFWRenderWindow](#63598697) (const [GLFWRenderWindow](ffw_GLFWRenderWindow.html) &) = delete  |
|   | [GLFWRenderWindow](#004d5713) ([GLFWRenderWindow](ffw_GLFWRenderWindow.html) && _other_)  |
|  [GLFWRenderWindow](ffw_GLFWRenderWindow.html) & | [operator=](#f83749ed) ([GLFWRenderWindow](ffw_GLFWRenderWindow.html) && _other_)  |


## Protected Functions

| Type | Name |
| -------: | :------- |
|  virtual bool | [setup](#68554ce1) () = 0  _Called only once when the window is set up._ |
|  virtual void | [render](#93db1d16) () = 0  _Called every time the frame is being rendered._ |
|  virtual void | [close](#eb5dbf50) () = 0  _Called only once when the window is being destroyed._ |
|  virtual void | [textInputEvent](#707e5f61) (unsigned int _c_)  _Called when the user presses a key to type text (unicode only)_ |
|  virtual void | [keyPressedEvent](#ce25f297) ([ffw::Key](ffw.html#23661d50) _key_, [ffw::Mode](ffw.html#e03b52d5) _mode_)  _Called when the user presses a physical key._ |
|  virtual void | [mouseMovedEvent](#eaa1a6c6) (int _mousex_, int _mousey_)  _Called when the user moves a mouse._ |
|  virtual void | [mouseScrollEvent](#fbe7329a) (int _scroll_)  _Called when the user scrolls down or up._ |
|  virtual void | [mouseButtonEvent](#1e8d2373) ([ffw::MouseButton](ffw.html#f80e46cc) _button_, [ffw::Mode](ffw.html#e03b52d5) _mode_)  _Called when the user presses a mouse button._ |
|  virtual void | [windowResizedEvent](#e4b39662) (int _width_, int _height_)  _Called when the window is resized to a new size._ |
|  virtual void | [windowMovedEvent](#e57c71a5) (int _posx_, int _posy_)  _Called when the window is moved to a new position._ |
|  virtual void | [windowCloseEvent](#d1e6b4ff) ()  _Called when the user presses the [X] button on the window._ |
|  virtual void | [windowFocusEvent](#727ce05e) (bool _focus_)  _Called when the window will gain or looses focus._ |
|  virtual void | [filesDroppedEvent](#c02a201a) (std::vector< std::string > _filelist_)  _Called when the user drags and drops one or multiple files._ |


## Friends Documentation

### _friend_ <a id="4bc0e89f" href="#4bc0e89f">windowCallback</a>

```cpp
friend struct windowCallback
```





## Public Static Functions Documentation

### _function_ <a id="074c67e8" href="#074c67e8">getMonitors</a>

```cpp
static std::vector< Monitor > getMonitors () 
```

Returns a vector of all physical monitors available. 

### _function_ <a id="17b52d27" href="#17b52d27">getPrimaryMonitor</a>

```cpp
static Monitor getPrimaryMonitor () 
```

Returns the primary monitor defined by the OS. 

### _function_ <a id="8fb7ed82" href="#8fb7ed82">getMonitorModes</a>

```cpp
static std::vector< Monitor::Mode > getMonitorModes (
    Monitor monitor
) 
```

Returns all possible modes for the given monitor. 



## Public Functions Documentation

### _function_ <a id="3ddc7739" href="#3ddc7739">GLFWRenderWindow</a>

```cpp
 GLFWRenderWindow () 
```



### _function_ <a id="58da4a58" href="#58da4a58">~GLFWRenderWindow</a>

```cpp
virtual  ~GLFWRenderWindow () 
```



### _function_ <a id="20e4ebb1" href="#20e4ebb1">setPos</a>

```cpp
virtual void setPos (
    int posx,
    int posy
) 
```

Sets the position of the window. 

**Overrides:** [setPos](/doxygen/ffw_RenderWindow.md#f4d09f9e) from class [RenderWindow](/doxygen/ffw_RenderWindow.md)

### _function_ <a id="70055684" href="#70055684">setSize</a>

```cpp
virtual void setSize (
    int width,
    int height
) 
```

Sets the size of the window. 

**Overrides:** [setSize](/doxygen/ffw_RenderWindow.md#d362b545) from class [RenderWindow](/doxygen/ffw_RenderWindow.md)

### _function_ <a id="6e45fa20" href="#6e45fa20">getPos</a>

```cpp
virtual ffw::Vec2i getPos () const 
```



**Overrides:** [getPos](/doxygen/ffw_RenderWindow.md#9fd18e79) from class [RenderWindow](/doxygen/ffw_RenderWindow.md)

### _function_ <a id="70919473" href="#70919473">getSize</a>

```cpp
virtual ffw::Vec2i getSize () const 
```



**Overrides:** [getSize](/doxygen/ffw_RenderWindow.md#eec3ff16) from class [RenderWindow](/doxygen/ffw_RenderWindow.md)

### _function_ <a id="487f0d6e" href="#487f0d6e">create</a>

```cpp
bool create (
    const GLFWRenderWindowArgs & args,
    GLFWRenderWindow * other,
    Monitor * monitor = NULL
) 
```

Creates the window. 

**Params:**
* _args:_ Arguments and hints for the window 
* _other:_ If another window is provided, their OpenGL context will be shared, otherwise NULL 
* _monitor:_ If a monitor is provided, the window will be fullscreen 

**return:** Will return false if:
* The window `has` already been created `` 

* The target size (width or height) defined by args is zero or less

* The GLFW failed due to missing OpenGL or there is no display to output to (running in terminal only)

* The _OS_ OpenGL version _is_ less than 1.1

* The _target_ _size_ is not supported by the **monitor** ****(only when fullscreen) 





### _function_ <a id="500484b5" href="#500484b5">setWindowedMode</a>

```cpp
void setWindowedMode () 
```

Sets the window into windowed mode, if the window was in maximized mode. 

### _function_ <a id="1af15aab" href="#1af15aab">setWindowedMode</a>

```cpp
void setWindowedMode (
    int posx,
    int posy,
    int width,
    int height
) 
```

Sets the window into windowed mode with specific size and position. 

### _function_ <a id="78a84d10" href="#78a84d10">setFullscreen</a>

```cpp
void setFullscreen (
    const Monitor * monitor
) 
```

Sets the window into fullscreen mode. 

You will need to change the size of the window with [setSize()](ffw_GLFWRenderWindow.html#70055684) 
### _function_ <a id="a6cd0e35" href="#a6cd0e35">destroy</a>

```cpp
virtual void destroy () 
```

Destroys the window and it's context. 

**Overrides:** [destroy](/doxygen/ffw_RenderWindow.md#63395a3d) from class [RenderWindow](/doxygen/ffw_RenderWindow.md)

### _function_ <a id="a7405bd4" href="#a7405bd4">shouldRender</a>

```cpp
virtual bool shouldRender () const 
```

Returns true if the window is not closed. 

**Overrides:** [shouldRender](/doxygen/ffw_RenderWindow.md#32f37adc) from class [RenderWindow](/doxygen/ffw_RenderWindow.md)

When [shouldClose()](ffw_GLFWRenderWindow.html#f26e03bc) is called with a 'true' boolean value, this function will then return false 
### _function_ <a id="72132dff" href="#72132dff">renderFrame</a>

```cpp
virtual void renderFrame () 
```

Renders a frame. 

**Overrides:** [renderFrame](/doxygen/ffw_RenderWindow.md#f1f7eabd) from class [RenderWindow](/doxygen/ffw_RenderWindow.md)

### _function_ <a id="9e15cebe" href="#9e15cebe">poolEvents</a>

```cpp
virtual void poolEvents () 
```

Pools all user input events, if any. 

**Overrides:** [poolEvents](/doxygen/ffw_RenderWindow.md#a3426c98) from class [RenderWindow](/doxygen/ffw_RenderWindow.md)

This is blocking function that will return whenever there are any events in the queue. If you wish to wait for the user first, see [waitForEvents()](ffw_GLFWRenderWindow.html#242fc91e) 
### _function_ <a id="242fc91e" href="#242fc91e">waitForEvents</a>

```cpp
virtual void waitForEvents () 
```

Pools all user input events and waits if there is none. 

**Overrides:** [waitForEvents](/doxygen/ffw_RenderWindow.md#855f4a96) from class [RenderWindow](/doxygen/ffw_RenderWindow.md)

This is blocking function that will not return unless there is at least one user event. If you wish to have continuous rendering, even if there are no user events, use [poolEvents()](ffw_GLFWRenderWindow.html#9e15cebe) 
### _function_ <a id="7ec0b6df" href="#7ec0b6df">isInitialized</a>

```cpp
virtual bool isInitialized () const 
```

Returns true if the window is initialized. 

**Overrides:** [isInitialized](/doxygen/ffw_RenderWindow.md#16b82494) from class [RenderWindow](/doxygen/ffw_RenderWindow.md)

### _function_ <a id="aa2500a8" href="#aa2500a8">getGlextFunc</a>

```cpp
virtual void * getGlextFunc (
    const std::string & name
) const 
```

Retuns the address of the GL extension function. 

**Overrides:** [getGlextFunc](/doxygen/ffw_RenderContext.md#16d7b686) from class [RenderContext](/doxygen/ffw_RenderContext.md)

The pointer to the GL extension function may not be the same on different GL contexts! 
### _function_ <a id="e2a22288" href="#e2a22288">isGlextExtSupported</a>

```cpp
virtual bool isGlextExtSupported (
    const std::string & name
) const 
```

Returns true if the GL extension is suported. 

**Overrides:** [isGlextExtSupported](/doxygen/ffw_RenderContext.md#66742b2f) from class [RenderContext](/doxygen/ffw_RenderContext.md)

Checks if an GLEXT extension is supported, for example "GL_ARB_debug_output" 
### _function_ <a id="c327f0a5" href="#c327f0a5">setSwapInterval</a>

```cpp
void setSwapInterval (
    int interval
) 
```



### _function_ <a id="f26e03bc" href="#f26e03bc">shouldClose</a>

```cpp
virtual void shouldClose (
    bool close
) 
```

Set whether the window should close or stay alive. 

**Overrides:** [shouldClose](/doxygen/ffw_RenderWindow.md#48c90ff6) from class [RenderWindow](/doxygen/ffw_RenderWindow.md)

### _function_ <a id="810c9891" href="#810c9891">show</a>

```cpp
virtual void show () 
```

Shows the window if the window has been hidden. 

**Overrides:** [show](/doxygen/ffw_RenderWindow.md#b2af4bed) from class [RenderWindow](/doxygen/ffw_RenderWindow.md)

### _function_ <a id="22589352" href="#22589352">hide</a>

```cpp
virtual void hide () 
```

Hides the window if the window is visible. 

**Overrides:** [hide](/doxygen/ffw_RenderWindow.md#ae91ff60) from class [RenderWindow](/doxygen/ffw_RenderWindow.md)

### _function_ <a id="778bb08b" href="#778bb08b">iconify</a>

```cpp
virtual void iconify () 
```

Minimizes the window into the task bar. 

**Overrides:** [iconify](/doxygen/ffw_RenderWindow.md#856cc4b7) from class [RenderWindow](/doxygen/ffw_RenderWindow.md)

### _function_ <a id="2d91152d" href="#2d91152d">restore</a>

```cpp
virtual void restore () 
```

Restores minimized window into a visible window. 

**Overrides:** [restore](/doxygen/ffw_RenderWindow.md#17ce5fce) from class [RenderWindow](/doxygen/ffw_RenderWindow.md)

### _function_ <a id="129f289a" href="#129f289a">maximize</a>

```cpp
virtual void maximize () 
```

Maximizes the window in order to utilize whole screen. 

**Overrides:** [maximize](/doxygen/ffw_RenderWindow.md#beeb16ff) from class [RenderWindow](/doxygen/ffw_RenderWindow.md)

This is not the same as full screen mode! 
### _function_ <a id="44d7a377" href="#44d7a377">setSingleBufferMode</a>

```cpp
virtual void setSingleBufferMode (
    bool enabled
) 
```

Sets whether the window should operate using two buffets (back and front) or only in one. 

**Overrides:** [setSingleBufferMode](/doxygen/ffw_RenderWindow.md#9fecce69) from class [RenderWindow](/doxygen/ffw_RenderWindow.md)

### _function_ <a id="3e315e2e" href="#3e315e2e">operator=</a>

```cpp
GLFWRenderWindow & operator= (
    const GLFWRenderWindow &
) = delete 
```



### _function_ <a id="63598697" href="#63598697">GLFWRenderWindow</a>

```cpp
 GLFWRenderWindow (
    const GLFWRenderWindow &
) = delete 
```



### _function_ <a id="004d5713" href="#004d5713">GLFWRenderWindow</a>

```cpp
 GLFWRenderWindow (
    GLFWRenderWindow && other
) 
```



### _function_ <a id="f83749ed" href="#f83749ed">operator=</a>

```cpp
GLFWRenderWindow & operator= (
    GLFWRenderWindow && other
) 
```





## Protected Functions Documentation

### _function_ <a id="68554ce1" href="#68554ce1">setup</a>

```cpp
virtual bool setup () = 0 
```

Called only once when the window is set up. 

### _function_ <a id="93db1d16" href="#93db1d16">render</a>

```cpp
virtual void render () = 0 
```

Called every time the frame is being rendered. 

### _function_ <a id="eb5dbf50" href="#eb5dbf50">close</a>

```cpp
virtual void close () = 0 
```

Called only once when the window is being destroyed. 

### _function_ <a id="707e5f61" href="#707e5f61">textInputEvent</a>

```cpp
virtual void textInputEvent (
    unsigned int c
) 
```

Called when the user presses a key to type text (unicode only) 

### _function_ <a id="ce25f297" href="#ce25f297">keyPressedEvent</a>

```cpp
virtual void keyPressedEvent (
    ffw::Key key,
    ffw::Mode mode
) 
```

Called when the user presses a physical key. 

### _function_ <a id="eaa1a6c6" href="#eaa1a6c6">mouseMovedEvent</a>

```cpp
virtual void mouseMovedEvent (
    int mousex,
    int mousey
) 
```

Called when the user moves a mouse. 

### _function_ <a id="fbe7329a" href="#fbe7329a">mouseScrollEvent</a>

```cpp
virtual void mouseScrollEvent (
    int scroll
) 
```

Called when the user scrolls down or up. 

### _function_ <a id="1e8d2373" href="#1e8d2373">mouseButtonEvent</a>

```cpp
virtual void mouseButtonEvent (
    ffw::MouseButton button,
    ffw::Mode mode
) 
```

Called when the user presses a mouse button. 

### _function_ <a id="e4b39662" href="#e4b39662">windowResizedEvent</a>

```cpp
virtual void windowResizedEvent (
    int width,
    int height
) 
```

Called when the window is resized to a new size. 

### _function_ <a id="e57c71a5" href="#e57c71a5">windowMovedEvent</a>

```cpp
virtual void windowMovedEvent (
    int posx,
    int posy
) 
```

Called when the window is moved to a new position. 

### _function_ <a id="d1e6b4ff" href="#d1e6b4ff">windowCloseEvent</a>

```cpp
virtual void windowCloseEvent () 
```

Called when the user presses the [X] button on the window. 

### _function_ <a id="727ce05e" href="#727ce05e">windowFocusEvent</a>

```cpp
virtual void windowFocusEvent (
    bool focus
) 
```

Called when the window will gain or looses focus. 

### _function_ <a id="c02a201a" href="#c02a201a">filesDroppedEvent</a>

```cpp
virtual void filesDroppedEvent (
    std::vector< std::string > filelist
) 
```

Called when the user drags and drops one or multiple files. 

**note:** UTF-8 enabled 




