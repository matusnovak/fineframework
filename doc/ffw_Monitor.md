Monitor
===================================


The documentation for this struct was generated from: `include/ffw/graphics/monitors.h`



## Classes

| Name |
|:-----|
| struct [ffw::Monitor::Mode](ffw_Monitor_Mode.html) |


## Public Attributes

| Type | Name |
| -------: | :------- |
|  std::string | [name](#70c38a08)<div style="opacity:0.8;">Name of the physical monitor. </div> |
|  [Vec2i](ffw.html#e4e07ebe) | [resolution](#a85ce62d)<div style="opacity:0.8;">The current resolution. </div> |
|  [Vec3i](ffw.html#1bc00754) | [bitDepth](#ecc395e0)<div style="opacity:0.8;">The current bith depth. </div> |
|  int | [refreshRate](#97dd1377)<div style="opacity:0.8;">The current refresh rate (V-sync) </div> |
|  [Vec2i](ffw.html#e4e07ebe) | [position](#c23aa251)<div style="opacity:0.8;">The relative position to the primary monitor, in pixels. </div> |
|  [Vec2i](ffw.html#e4e07ebe) | [physicalSize](#26e041a5)<div style="opacity:0.8;">The physical size of the monitor in millimeters. </div> |
|  void * | [ptr](#171f39ca)<div style="opacity:0.8;">GLFW specific pointer. </div> |


## Public Attributes Documentation

### <span style="opacity:0.5;">variable</span> <a id="70c38a08" href="#70c38a08">name</a>

```cpp
std::string name
```

Name of the physical monitor. 

### <span style="opacity:0.5;">variable</span> <a id="a85ce62d" href="#a85ce62d">resolution</a>

```cpp
Vec2i resolution
```

The current resolution. 

### <span style="opacity:0.5;">variable</span> <a id="ecc395e0" href="#ecc395e0">bitDepth</a>

```cpp
Vec3i bitDepth
```

The current bith depth. 

#### Details:

* .x = RED

* .y = GREEN

* .z = BLUE 



### <span style="opacity:0.5;">variable</span> <a id="97dd1377" href="#97dd1377">refreshRate</a>

```cpp
int refreshRate
```

The current refresh rate (V-sync) 

### <span style="opacity:0.5;">variable</span> <a id="c23aa251" href="#c23aa251">position</a>

```cpp
Vec2i position
```

The relative position to the primary monitor, in pixels. 

### <span style="opacity:0.5;">variable</span> <a id="26e041a5" href="#26e041a5">physicalSize</a>

```cpp
Vec2i physicalSize
```

The physical size of the monitor in millimeters. 

### <span style="opacity:0.5;">variable</span> <a id="171f39ca" href="#171f39ca">ptr</a>

```cpp
void * ptr
```

GLFW specific pointer. 



