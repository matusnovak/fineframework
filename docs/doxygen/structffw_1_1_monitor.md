---
search: false
---

# struct ffw::Monitor

## Classes

|Type|Name|
|-----|-----|
|struct|[**Mode**](structffw_1_1_monitor_1_1_mode.md)|


## Public Attributes

|Type|Name|
|-----|-----|
|std::string|[**name**](structffw_1_1_monitor.md#1a59dd9ebabd82145e87afef97c9d5c1f5)<br>Name of the physical monitor. |
|**[Vec2i](group__math_.md#ga8ac6bae8a24d96d0223a29ecfff14570)**|[**resolution**](structffw_1_1_monitor.md#1ab7bb963f40775c550aee456f60566034)<br>The current resolution. |
|**[Vec3i](group__math_.md#gafd4bb1ab82109f15d80681d443404df8)**|[**bitDepth**](structffw_1_1_monitor.md#1aa5b362a6fb5826a7e28db82fe25416d4)<br>The current bith depth. |
|int|[**refreshRate**](structffw_1_1_monitor.md#1af90abecb4bc7ceb46a0d4e26407640b1)<br>The current refresh rate (V-sync) |
|**[Vec2i](group__math_.md#ga8ac6bae8a24d96d0223a29ecfff14570)**|[**position**](structffw_1_1_monitor.md#1a0173ab6a2799bcb05b913ee8e0aa5174)<br>The relative position to the primary monitor, in pixels. |
|**[Vec2i](group__math_.md#ga8ac6bae8a24d96d0223a29ecfff14570)**|[**physicalSize**](structffw_1_1_monitor.md#1accad1d0c60217e216b1d0475d266f7c2)<br>The physical size of the monitor in millimeters. |
|void \*|[**ptr**](structffw_1_1_monitor.md#1af9d44fa06c57e02deaac79596503be16)<br>GLFW specific pointer. |


## Public Attributes Documentation

### variable <a id="1a59dd9ebabd82145e87afef97c9d5c1f5" href="#1a59dd9ebabd82145e87afef97c9d5c1f5">name</a>

```cpp
std::string ffw::Monitor::name;
```

Name of the physical monitor. 


### variable <a id="1ab7bb963f40775c550aee456f60566034" href="#1ab7bb963f40775c550aee456f60566034">resolution</a>

```cpp
Vec2i ffw::Monitor::resolution;
```

The current resolution. 


### variable <a id="1aa5b362a6fb5826a7e28db82fe25416d4" href="#1aa5b362a6fb5826a7e28db82fe25416d4">bitDepth</a>

```cpp
Vec3i ffw::Monitor::bitDepth;
```

The current bith depth. 


* .x = RED
* .y = GREEN
* .z = BLUE 



### variable <a id="1af90abecb4bc7ceb46a0d4e26407640b1" href="#1af90abecb4bc7ceb46a0d4e26407640b1">refreshRate</a>

```cpp
int ffw::Monitor::refreshRate;
```

The current refresh rate (V-sync) 


### variable <a id="1a0173ab6a2799bcb05b913ee8e0aa5174" href="#1a0173ab6a2799bcb05b913ee8e0aa5174">position</a>

```cpp
Vec2i ffw::Monitor::position;
```

The relative position to the primary monitor, in pixels. 


### variable <a id="1accad1d0c60217e216b1d0475d266f7c2" href="#1accad1d0c60217e216b1d0475d266f7c2">physicalSize</a>

```cpp
Vec2i ffw::Monitor::physicalSize;
```

The physical size of the monitor in millimeters. 


### variable <a id="1af9d44fa06c57e02deaac79596503be16" href="#1af9d44fa06c57e02deaac79596503be16">ptr</a>

```cpp
void* ffw::Monitor::ptr;
```

GLFW specific pointer. 




----------------------------------------
The documentation for this class was generated from the following file: `include/ffw/graphics/monitors.h`
