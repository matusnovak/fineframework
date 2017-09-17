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
|  std::vector< [Monitor](ffw_Monitor.html) > | [getMonitors](#074c67e8) () <div style="opacity:0.8;">Returns a vector of all physical monitors available. </div> |
|  [Monitor](ffw_Monitor.html) | [getPrimaryMonitor](#17b52d27) () <div style="opacity:0.8;">Returns the primary monitor defined by the OS. </div> |
|  std::vector< [Monitor::Mode](ffw_Monitor_Mode.html) > | [getMonitorModes](#8fb7ed82) ([Monitor](ffw_Monitor.html) _monitor_) <div style="opacity:0.8;">Returns all possible modes for the given monitor. </div> |


## Public Functions

| Type | Name |
| -------: | :------- |
|   | [GLFWRenderWindow](#3ddc7739) ()  |
|  virtual  | [~GLFWRenderWindow](#58da4a58) ()  |
|  virtual void | [setPos](#20e4ebb1) (int _posx_, int _posy_) <div style="opacity:0.8;">Sets the position of the window. </div> |
|  virtual void | [setSize](#70055684) (int _width_, int _height_) <div style="opacity:0.8;">Sets the size of the window. </div> |
|  virtual [ffw::Vec2i](ffw.html#e4e07ebe) | [getPos](#6e45fa20) () const  |
|  virtual [ffw::Vec2i](ffw.html#e4e07ebe) | [getSize](#70919473) () const  |
|  bool | [create](#487f0d6e) (const [GLFWRenderWindowArgs](ffw_GLFWRenderWindowArgs.html) & _args_, [GLFWRenderWindow](ffw_GLFWRenderWindow.html) * _other_, [Monitor](ffw_Monitor.html) * _monitor_ = NULL) <div style="opacity:0.8;">Creates the window. </div> |
|  void | [setWindowedMode](#500484b5) () <div style="opacity:0.8;">Sets the window into windowed mode, if the window was in maximized mode. </div> |
|  void | [setWindowedMode](#1af15aab) (int _posx_, int _posy_, int _width_, int _height_) <div style="opacity:0.8;">Sets the window into windowed mode with specific size and position. </div> |
|  void | [setFullscreen](#78a84d10) (const [Monitor](ffw_Monitor.html) * _monitor_) <div style="opacity:0.8;">Sets the window into fullscreen mode. </div> |
|  virtual void | [destroy](#a6cd0e35) () <div style="opacity:0.8;">Destroys the window and it's context. </div> |
|  virtual bool | [shouldRender](#a7405bd4) () const <div style="opacity:0.8;">Returns true if the window is not closed. </div> |
|  virtual void | [renderFrame](#72132dff) () <div style="opacity:0.8;">Renders a frame. </div> |
|  virtual void | [poolEvents](#9e15cebe) () <div style="opacity:0.8;">Pools all user input events, if any. </div> |
|  virtual void | [waitForEvents](#242fc91e) () <div style="opacity:0.8;">Pools all user input events and waits if there is none. </div> |
|  virtual bool | [isInitialized](#7ec0b6df) () const <div style="opacity:0.8;">Returns true if the window is initialized. </div> |
|  virtual void * | [getGlextFunc](#aa2500a8) (const std::string & _name_) const <div style="opacity:0.8;">Retuns the address of the GL extension function. </div> |
|  virtual bool | [isGlextExtSupported](#e2a22288) (const std::string & _name_) const <div style="opacity:0.8;">Returns true if the GL extension is suported. </div> |
|  void | [setSwapInterval](#c327f0a5) (int _interval_)  |
|  virtual void | [shouldClose](#f26e03bc) (bool _close_) <div style="opacity:0.8;">Set whether the window should close or stay alive. </div> |
|  virtual void | [show](#810c9891) () <div style="opacity:0.8;">Shows the window if the window has been hidden. </div> |
|  virtual void | [hide](#22589352) () <div style="opacity:0.8;">Hides the window if the window is visible. </div> |
|  virtual void | [iconify](#778bb08b) () <div style="opacity:0.8;">Minimizes the window into the task bar. </div> |
|  virtual void | [restore](#2d91152d) () <div style="opacity:0.8;">Restores minimized window into a visible window. </div> |
|  virtual void | [maximize](#129f289a) () <div style="opacity:0.8;">Maximizes the window in order to utilize whole screen. </div> |
|  virtual void | [setSingleBufferMode](#44d7a377) (bool _enabled_) <div style="opacity:0.8;">Sets whether the window should operate using two buffets (back and front) or only in one. </div> |
|  [GLFWRenderWindow](ffw_GLFWRenderWindow.html) & | [operator=](#3e315e2e) (const [GLFWRenderWindow](ffw_GLFWRenderWindow.html) &) = delete  |
|   | [GLFWRenderWindow](#63598697) (const [GLFWRenderWindow](ffw_GLFWRenderWindow.html) &) = delete  |
|   | [GLFWRenderWindow](#004d5713) ([GLFWRenderWindow](ffw_GLFWRenderWindow.html) && _other_)  |
|  [GLFWRenderWindow](ffw_GLFWRenderWindow.html) & | [operator=](#f83749ed) ([GLFWRenderWindow](ffw_GLFWRenderWindow.html) && _other_)  |


## Protected Functions

| Type | Name |
| -------: | :------- |
|  virtual bool | [setup](#68554ce1) () = 0 <div style="opacity:0.8;">Called only once when the window is set up. </div> |
|  virtual void | [render](#93db1d16) () = 0 <div style="opacity:0.8;">Called every time the frame is being rendered. </div> |
|  virtual void | [close](#eb5dbf50) () = 0 <div style="opacity:0.8;">Called only once when the window is being destroyed. </div> |
|  virtual void | [textInputEvent](#707e5f61) (unsigned int _c_) <div style="opacity:0.8;">Called when the user presses a key to type text (unicode only) </div> |
|  virtual void | [keyPressedEvent](#ce25f297) ([ffw::Key](ffw.html#23661d50) _key_, [ffw::Mode](ffw.html#e03b52d5) _mode_) <div style="opacity:0.8;">Called when the user presses a physical key. </div> |
|  virtual void | [mouseMovedEvent](#eaa1a6c6) (int _mousex_, int _mousey_) <div style="opacity:0.8;">Called when the user moves a mouse. </div> |
|  virtual void | [mouseScrollEvent](#fbe7329a) (int _scroll_) <div style="opacity:0.8;">Called when the user scrolls down or up. </div> |
|  virtual void | [mouseButtonEvent](#1e8d2373) ([ffw::MouseButton](ffw.html#f80e46cc) _button_, [ffw::Mode](ffw.html#e03b52d5) _mode_) <div style="opacity:0.8;">Called when the user presses a mouse button. </div> |
|  virtual void | [windowResizedEvent](#e4b39662) (int _width_, int _height_) <div style="opacity:0.8;">Called when the window is resized to a new size. </div> |
|  virtual void | [windowMovedEvent](#e57c71a5) (int _posx_, int _posy_) <div style="opacity:0.8;">Called when the window is moved to a new position. </div> |
|  virtual void | [windowCloseEvent](#d1e6b4ff) () <div style="opacity:0.8;">Called when the user presses the [X] button on the window. </div> |
|  virtual void | [windowFocusEvent](#727ce05e) (bool _focus_) <div style="opacity:0.8;">Called when the window will gain or looses focus. </div> |
|  virtual void | [filesDroppedEvent](#c02a201a) (std::vector< std::string > _filelist_) <div style="opacity:0.8;">Called when the user drags and drops one or multiple files. </div> |


## Friends Documentation

### <span style="opacity:0.5;">friend</span> <a id="4bc0e89f" href="#4bc0e89f">windowCallback</a>

```cpp
friend struct windowCallback
```





## Public Static Functions Documentation

### <span style="opacity:0.5;">function</span> <a id="074c67e8" href="#074c67e8">getMonitors</a>

```cpp
static std::vector< Monitor > getMonitors () 
```

Returns a vector of all physical monitors available. 

### <span style="opacity:0.5;">function</span> <a id="17b52d27" href="#17b52d27">getPrimaryMonitor</a>

```cpp
static Monitor getPrimaryMonitor () 
```

Returns the primary monitor defined by the OS. 

### <span style="opacity:0.5;">function</span> <a id="8fb7ed82" href="#8fb7ed82">getMonitorModes</a>

```cpp
static std::vector< Monitor::Mode > getMonitorModes (
    Monitor monitor
) 
```

Returns all possible modes for the given monitor. 



## Public Functions Documentation

### <span style="opacity:0.5;">function</span> <a id="3ddc7739" href="#3ddc7739">GLFWRenderWindow</a>

```cpp
 GLFWRenderWindow () 
```



### <span style="opacity:0.5;">function</span> <a id="58da4a58" href="#58da4a58">~GLFWRenderWindow</a>

```cpp
virtual  ~GLFWRenderWindow () 
```



### <span style="opacity:0.5;">function</span> <a id="20e4ebb1" href="#20e4ebb1">setPos</a>

```cpp
virtual void setPos (
    int posx,
    int posy
) 
```

Sets the position of the window. 

**Overrides:** [setPos](/doc/ffw_RenderWindow.md#f4d09f9e)

### <span style="opacity:0.5;">function</span> <a id="70055684" href="#70055684">setSize</a>

```cpp
virtual void setSize (
    int width,
    int height
) 
```

Sets the size of the window. 

**Overrides:** [setSize](/doc/ffw_RenderWindow.md#d362b545)

### <span style="opacity:0.5;">function</span> <a id="6e45fa20" href="#6e45fa20">getPos</a>

```cpp
virtual ffw::Vec2i getPos () const 
```



**Overrides:** [getPos](/doc/ffw_RenderWindow.md#9fd18e79)

### <span style="opacity:0.5;">function</span> <a id="70919473" href="#70919473">getSize</a>

```cpp
virtual ffw::Vec2i getSize () const 
```



**Overrides:** [getSize](/doc/ffw_RenderWindow.md#eec3ff16)

### <span style="opacity:0.5;">function</span> <a id="487f0d6e" href="#487f0d6e">create</a>

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





### <span style="opacity:0.5;">function</span> <a id="500484b5" href="#500484b5">setWindowedMode</a>

```cpp
void setWindowedMode () 
```

Sets the window into windowed mode, if the window was in maximized mode. 

### <span style="opacity:0.5;">function</span> <a id="1af15aab" href="#1af15aab">setWindowedMode</a>

```cpp
void setWindowedMode (
    int posx,
    int posy,
    int width,
    int height
) 
```

Sets the window into windowed mode with specific size and position. 

### <span style="opacity:0.5;">function</span> <a id="78a84d10" href="#78a84d10">setFullscreen</a>

```cpp
void setFullscreen (
    const Monitor * monitor
) 
```

Sets the window into fullscreen mode. 

You will need to change the size of the window with [setSize()](ffw_GLFWRenderWindow.html#70055684) 
### <span style="opacity:0.5;">function</span> <a id="a6cd0e35" href="#a6cd0e35">destroy</a>

```cpp
virtual void destroy () 
```

Destroys the window and it's context. 

**Overrides:** [destroy](/doc/ffw_RenderWindow.md#63395a3d)

### <span style="opacity:0.5;">function</span> <a id="a7405bd4" href="#a7405bd4">shouldRender</a>

```cpp
virtual bool shouldRender () const 
```

Returns true if the window is not closed. 

**Overrides:** [shouldRender](/doc/ffw_RenderWindow.md#32f37adc)

When [shouldClose()](ffw_GLFWRenderWindow.html#f26e03bc) is called with a 'true' boolean value, this function will then return false 
### <span style="opacity:0.5;">function</span> <a id="72132dff" href="#72132dff">renderFrame</a>

```cpp
virtual void renderFrame () 
```

Renders a frame. 

**Overrides:** [renderFrame](/doc/ffw_RenderWindow.md#f1f7eabd)

### <span style="opacity:0.5;">function</span> <a id="9e15cebe" href="#9e15cebe">poolEvents</a>

```cpp
virtual void poolEvents () 
```

Pools all user input events, if any. 

**Overrides:** [poolEvents](/doc/ffw_RenderWindow.md#a3426c98)

This is blocking function that will return whenever there are any events in the queue. If you wish to wait for the user first, see [waitForEvents()](ffw_GLFWRenderWindow.html#242fc91e) 
### <span style="opacity:0.5;">function</span> <a id="242fc91e" href="#242fc91e">waitForEvents</a>

```cpp
virtual void waitForEvents () 
```

Pools all user input events and waits if there is none. 

**Overrides:** [waitForEvents](/doc/ffw_RenderWindow.md#855f4a96)

This is blocking function that will not return unless there is at least one user event. If you wish to have continuous rendering, even if there are no user events, use [poolEvents()](ffw_GLFWRenderWindow.html#9e15cebe) 
### <span style="opacity:0.5;">function</span> <a id="7ec0b6df" href="#7ec0b6df">isInitialized</a>

```cpp
virtual bool isInitialized () const 
```

Returns true if the window is initialized. 

**Overrides:** [isInitialized](/doc/ffw_RenderWindow.md#16b82494)

### <span style="opacity:0.5;">function</span> <a id="aa2500a8" href="#aa2500a8">getGlextFunc</a>

```cpp
virtual void * getGlextFunc (
    const std::string & name
) const 
```

Retuns the address of the GL extension function. 

**Overrides:** [getGlextFunc](/doc/ffw_RenderContext.md#16d7b686)

The pointer to the GL extension function may not be the same on different GL contexts! 
### <span style="opacity:0.5;">function</span> <a id="e2a22288" href="#e2a22288">isGlextExtSupported</a>

```cpp
virtual bool isGlextExtSupported (
    const std::string & name
) const 
```

Returns true if the GL extension is suported. 

**Overrides:** [isGlextExtSupported](/doc/ffw_RenderContext.md#66742b2f)

Checks if an GLEXT extension is supported, for example "GL_ARB_debug_output" 
### <span style="opacity:0.5;">function</span> <a id="c327f0a5" href="#c327f0a5">setSwapInterval</a>

```cpp
void setSwapInterval (
    int interval
) 
```



### <span style="opacity:0.5;">function</span> <a id="f26e03bc" href="#f26e03bc">shouldClose</a>

```cpp
virtual void shouldClose (
    bool close
) 
```

Set whether the window should close or stay alive. 

**Overrides:** [shouldClose](/doc/ffw_RenderWindow.md#48c90ff6)

### <span style="opacity:0.5;">function</span> <a id="810c9891" href="#810c9891">show</a>

```cpp
virtual void show () 
```

Shows the window if the window has been hidden. 

**Overrides:** [show](/doc/ffw_RenderWindow.md#b2af4bed)

### <span style="opacity:0.5;">function</span> <a id="22589352" href="#22589352">hide</a>

```cpp
virtual void hide () 
```

Hides the window if the window is visible. 

**Overrides:** [hide](/doc/ffw_RenderWindow.md#ae91ff60)

### <span style="opacity:0.5;">function</span> <a id="778bb08b" href="#778bb08b">iconify</a>

```cpp
virtual void iconify () 
```

Minimizes the window into the task bar. 

**Overrides:** [iconify](/doc/ffw_RenderWindow.md#856cc4b7)

### <span style="opacity:0.5;">function</span> <a id="2d91152d" href="#2d91152d">restore</a>

```cpp
virtual void restore () 
```

Restores minimized window into a visible window. 

**Overrides:** [restore](/doc/ffw_RenderWindow.md#17ce5fce)

### <span style="opacity:0.5;">function</span> <a id="129f289a" href="#129f289a">maximize</a>

```cpp
virtual void maximize () 
```

Maximizes the window in order to utilize whole screen. 

**Overrides:** [maximize](/doc/ffw_RenderWindow.md#beeb16ff)

This is not the same as full screen mode! 
### <span style="opacity:0.5;">function</span> <a id="44d7a377" href="#44d7a377">setSingleBufferMode</a>

```cpp
virtual void setSingleBufferMode (
    bool enabled
) 
```

Sets whether the window should operate using two buffets (back and front) or only in one. 

**Overrides:** [setSingleBufferMode](/doc/ffw_RenderWindow.md#9fecce69)

### <span style="opacity:0.5;">function</span> <a id="3e315e2e" href="#3e315e2e">operator=</a>

```cpp
GLFWRenderWindow & operator= (
    const GLFWRenderWindow &
) = delete 
```



### <span style="opacity:0.5;">function</span> <a id="63598697" href="#63598697">GLFWRenderWindow</a>

```cpp
 GLFWRenderWindow (
    const GLFWRenderWindow &
) = delete 
```



### <span style="opacity:0.5;">function</span> <a id="004d5713" href="#004d5713">GLFWRenderWindow</a>

```cpp
 GLFWRenderWindow (
    GLFWRenderWindow && other
) 
```



### <span style="opacity:0.5;">function</span> <a id="f83749ed" href="#f83749ed">operator=</a>

```cpp
GLFWRenderWindow & operator= (
    GLFWRenderWindow && other
) 
```





## Protected Functions Documentation

### <span style="opacity:0.5;">function</span> <a id="68554ce1" href="#68554ce1">setup</a>

```cpp
virtual bool setup () = 0 
```

Called only once when the window is set up. 

### <span style="opacity:0.5;">function</span> <a id="93db1d16" href="#93db1d16">render</a>

```cpp
virtual void render () = 0 
```

Called every time the frame is being rendered. 

### <span style="opacity:0.5;">function</span> <a id="eb5dbf50" href="#eb5dbf50">close</a>

```cpp
virtual void close () = 0 
```

Called only once when the window is being destroyed. 

### <span style="opacity:0.5;">function</span> <a id="707e5f61" href="#707e5f61">textInputEvent</a>

```cpp
virtual void textInputEvent (
    unsigned int c
) 
```

Called when the user presses a key to type text (unicode only) 

### <span style="opacity:0.5;">function</span> <a id="ce25f297" href="#ce25f297">keyPressedEvent</a>

```cpp
virtual void keyPressedEvent (
    ffw::Key key,
    ffw::Mode mode
) 
```

Called when the user presses a physical key. 

### <span style="opacity:0.5;">function</span> <a id="eaa1a6c6" href="#eaa1a6c6">mouseMovedEvent</a>

```cpp
virtual void mouseMovedEvent (
    int mousex,
    int mousey
) 
```

Called when the user moves a mouse. 

### <span style="opacity:0.5;">function</span> <a id="fbe7329a" href="#fbe7329a">mouseScrollEvent</a>

```cpp
virtual void mouseScrollEvent (
    int scroll
) 
```

Called when the user scrolls down or up. 

### <span style="opacity:0.5;">function</span> <a id="1e8d2373" href="#1e8d2373">mouseButtonEvent</a>

```cpp
virtual void mouseButtonEvent (
    ffw::MouseButton button,
    ffw::Mode mode
) 
```

Called when the user presses a mouse button. 

### <span style="opacity:0.5;">function</span> <a id="e4b39662" href="#e4b39662">windowResizedEvent</a>

```cpp
virtual void windowResizedEvent (
    int width,
    int height
) 
```

Called when the window is resized to a new size. 

### <span style="opacity:0.5;">function</span> <a id="e57c71a5" href="#e57c71a5">windowMovedEvent</a>

```cpp
virtual void windowMovedEvent (
    int posx,
    int posy
) 
```

Called when the window is moved to a new position. 

### <span style="opacity:0.5;">function</span> <a id="d1e6b4ff" href="#d1e6b4ff">windowCloseEvent</a>

```cpp
virtual void windowCloseEvent () 
```

Called when the user presses the [X] button on the window. 

### <span style="opacity:0.5;">function</span> <a id="727ce05e" href="#727ce05e">windowFocusEvent</a>

```cpp
virtual void windowFocusEvent (
    bool focus
) 
```

Called when the window will gain or looses focus. 

### <span style="opacity:0.5;">function</span> <a id="c02a201a" href="#c02a201a">filesDroppedEvent</a>

```cpp
virtual void filesDroppedEvent (
    std::vector< std::string > filelist
) 
```

Called when the user drags and drops one or multiple files. 

**note:** UTF-8 enabled 




