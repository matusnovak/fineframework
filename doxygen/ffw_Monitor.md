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
|  std::string | [name](#70c38a08) _Name of the physical monitor._ |
|  [Vec2i](ffw.html#e4e07ebe) | [resolution](#a85ce62d) _The current resolution._ |
|  [Vec3i](ffw.html#1bc00754) | [bitDepth](#ecc395e0) _The current bith depth._ |
|  int | [refreshRate](#97dd1377) _The current refresh rate (V-sync)_ |
|  [Vec2i](ffw.html#e4e07ebe) | [position](#c23aa251) _The relative position to the primary monitor, in pixels._ |
|  [Vec2i](ffw.html#e4e07ebe) | [physicalSize](#26e041a5) _The physical size of the monitor in millimeters._ |
|  void * | [ptr](#171f39ca) _GLFW specific pointer._ |


## Public Attributes Documentation

### _variable_ <a id="70c38a08" href="#70c38a08">name</a>

```cpp
std::string name
```

Name of the physical monitor. 

### _variable_ <a id="a85ce62d" href="#a85ce62d">resolution</a>

```cpp
Vec2i resolution
```

The current resolution. 

### _variable_ <a id="ecc395e0" href="#ecc395e0">bitDepth</a>

```cpp
Vec3i bitDepth
```

The current bith depth. 


* .x = RED

* .y = GREEN

* .z = BLUE 



### _variable_ <a id="97dd1377" href="#97dd1377">refreshRate</a>

```cpp
int refreshRate
```

The current refresh rate (V-sync) 

### _variable_ <a id="c23aa251" href="#c23aa251">position</a>

```cpp
Vec2i position
```

The relative position to the primary monitor, in pixels. 

### _variable_ <a id="26e041a5" href="#26e041a5">physicalSize</a>

```cpp
Vec2i physicalSize
```

The physical size of the monitor in millimeters. 

### _variable_ <a id="171f39ca" href="#171f39ca">ptr</a>

```cpp
void * ptr
```

GLFW specific pointer. 



