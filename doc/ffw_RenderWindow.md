RenderWindow
===================================


**Implemented by:** [ffw::GLFWRenderWindow](ffw_GLFWRenderWindow.html), 

The documentation for this class was generated from: `include/ffw/graphics/renderwindow.h`



## Public Functions

| Type | Name |
| -------: | :------- |
|  virtual void | [setPos](#f4d09f9e) (int _posx_, int _posy_) = 0 <div style="opacity:0.8;">Sets the position of the window. </div> |
|  virtual void | [setSize](#d362b545) (int _width_, int _height_) = 0 <div style="opacity:0.8;">Sets the size of the window. </div> |
|  virtual [ffw::Vec2i](ffw.html#e4e07ebe) | [getPos](#9fd18e79) () const = 0  |
|  virtual [ffw::Vec2i](ffw.html#e4e07ebe) | [getSize](#eec3ff16) () const = 0  |
|  virtual void | [destroy](#63395a3d) () = 0  |
|  virtual bool | [shouldRender](#32f37adc) () const = 0 <div style="opacity:0.8;">Returns true if the window is not closed. </div> |
|  virtual void | [renderFrame](#f1f7eabd) () = 0 <div style="opacity:0.8;">Renders a frame. </div> |
|  virtual void | [poolEvents](#a3426c98) () = 0 <div style="opacity:0.8;">Pools all user input events, if any. </div> |
|  virtual void | [waitForEvents](#855f4a96) () = 0 <div style="opacity:0.8;">Pools all user input events and waits if there is none. </div> |
|  virtual bool | [isInitialized](#16b82494) () const = 0 <div style="opacity:0.8;">Returns true if the window is initialized. </div> |
|  virtual void | [shouldClose](#48c90ff6) (bool _close_) = 0 <div style="opacity:0.8;">Set whether the window should close or stay alive. </div> |
|  virtual void | [show](#b2af4bed) () = 0 <div style="opacity:0.8;">Shows the window if the window has been hidden. </div> |
|  virtual void | [hide](#ae91ff60) () = 0 <div style="opacity:0.8;">Hides the window if the window is visible. </div> |
|  virtual void | [iconify](#856cc4b7) () = 0 <div style="opacity:0.8;">Minimizes the window into the task bar. </div> |
|  virtual void | [restore](#17ce5fce) () = 0 <div style="opacity:0.8;">Restores minimized window into a visible window. </div> |
|  virtual void | [maximize](#beeb16ff) () = 0 <div style="opacity:0.8;">Maximizes the window in order to utilize whole screen. </div> |
|  virtual void | [setSingleBufferMode](#9fecce69) (bool _enabled_) = 0 <div style="opacity:0.8;">Sets whether the window should operate using two buffets (back and front) or only in one. </div> |


## Public Functions Documentation

### <span style="opacity:0.5;">function</span> <a id="f4d09f9e" href="#f4d09f9e">setPos</a>

```cpp
virtual void setPos (
    int posx,
    int posy
) = 0 
```

Sets the position of the window. 

### <span style="opacity:0.5;">function</span> <a id="d362b545" href="#d362b545">setSize</a>

```cpp
virtual void setSize (
    int width,
    int height
) = 0 
```

Sets the size of the window. 

### <span style="opacity:0.5;">function</span> <a id="9fd18e79" href="#9fd18e79">getPos</a>

```cpp
virtual ffw::Vec2i getPos () const = 0 
```



### <span style="opacity:0.5;">function</span> <a id="eec3ff16" href="#eec3ff16">getSize</a>

```cpp
virtual ffw::Vec2i getSize () const = 0 
```



### <span style="opacity:0.5;">function</span> <a id="63395a3d" href="#63395a3d">destroy</a>

```cpp
virtual void destroy () = 0 
```



### <span style="opacity:0.5;">function</span> <a id="32f37adc" href="#32f37adc">shouldRender</a>

```cpp
virtual bool shouldRender () const = 0 
```

Returns true if the window is not closed. 

#### Details:
When [shouldClose()](ffw_RenderWindow.html#48c90ff6) is called with a 'true' boolean value, this function will then return false 
### <span style="opacity:0.5;">function</span> <a id="f1f7eabd" href="#f1f7eabd">renderFrame</a>

```cpp
virtual void renderFrame () = 0 
```

Renders a frame. 

### <span style="opacity:0.5;">function</span> <a id="a3426c98" href="#a3426c98">poolEvents</a>

```cpp
virtual void poolEvents () = 0 
```

Pools all user input events, if any. 

#### Details:
This is blocking function that will return whenever there are any events in the queue. If you wish to wait for the user first, see [waitForEvents()](ffw_RenderWindow.html#855f4a96) 
### <span style="opacity:0.5;">function</span> <a id="855f4a96" href="#855f4a96">waitForEvents</a>

```cpp
virtual void waitForEvents () = 0 
```

Pools all user input events and waits if there is none. 

#### Details:
This is blocking function that will not return unless there is at least one user event. If you wish to have continuous rendering, even if there are no user events, use [poolEvents()](ffw_RenderWindow.html#a3426c98) 
### <span style="opacity:0.5;">function</span> <a id="16b82494" href="#16b82494">isInitialized</a>

```cpp
virtual bool isInitialized () const = 0 
```

Returns true if the window is initialized. 

### <span style="opacity:0.5;">function</span> <a id="48c90ff6" href="#48c90ff6">shouldClose</a>

```cpp
virtual void shouldClose (
    bool close
) = 0 
```

Set whether the window should close or stay alive. 

### <span style="opacity:0.5;">function</span> <a id="b2af4bed" href="#b2af4bed">show</a>

```cpp
virtual void show () = 0 
```

Shows the window if the window has been hidden. 

### <span style="opacity:0.5;">function</span> <a id="ae91ff60" href="#ae91ff60">hide</a>

```cpp
virtual void hide () = 0 
```

Hides the window if the window is visible. 

### <span style="opacity:0.5;">function</span> <a id="856cc4b7" href="#856cc4b7">iconify</a>

```cpp
virtual void iconify () = 0 
```

Minimizes the window into the task bar. 

### <span style="opacity:0.5;">function</span> <a id="17ce5fce" href="#17ce5fce">restore</a>

```cpp
virtual void restore () = 0 
```

Restores minimized window into a visible window. 

### <span style="opacity:0.5;">function</span> <a id="beeb16ff" href="#beeb16ff">maximize</a>

```cpp
virtual void maximize () = 0 
```

Maximizes the window in order to utilize whole screen. 

#### Details:
This is not the same as full screen mode! 
### <span style="opacity:0.5;">function</span> <a id="9fecce69" href="#9fecce69">setSingleBufferMode</a>

```cpp
virtual void setSingleBufferMode (
    bool enabled
) = 0 
```

Sets whether the window should operate using two buffets (back and front) or only in one. 



