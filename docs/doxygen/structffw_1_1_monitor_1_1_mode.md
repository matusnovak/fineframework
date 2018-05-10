---
search: false
---

# struct ffw::Monitor::Mode

## Public Attributes

|Type|Name|
|-----|-----|
|**[Vec2i](group__math_.md#ga8ac6bae8a24d96d0223a29ecfff14570)**|[**resolution**](structffw_1_1_monitor_1_1_mode.md#1a16b4d0fe82bf142887fd968ba61e7a44)<br>Resolution. |
|**[Vec3i](group__math_.md#gafd4bb1ab82109f15d80681d443404df8)**|[**bitDepth**](structffw_1_1_monitor_1_1_mode.md#1aaba74c9abb601ff6e597a29c2cd55975)<br>Bith depth. |
|int|[**refreshRate**](structffw_1_1_monitor_1_1_mode.md#1a0db7d21d5b47013e9e6c5650bf281aac)<br>The prefered refresh rate (V-sync) |


## Public Attributes Documentation

### variable <a id="1a16b4d0fe82bf142887fd968ba61e7a44" href="#1a16b4d0fe82bf142887fd968ba61e7a44">resolution</a>

```cpp
Vec2i ffw::Monitor::Mode::resolution;
```

Resolution. 


### variable <a id="1aaba74c9abb601ff6e597a29c2cd55975" href="#1aaba74c9abb601ff6e597a29c2cd55975">bitDepth</a>

```cpp
Vec3i ffw::Monitor::Mode::bitDepth;
```

Bith depth. 


* .x = RED
* .y = GREEN
* .z = BLUE 



### variable <a id="1a0db7d21d5b47013e9e6c5650bf281aac" href="#1a0db7d21d5b47013e9e6c5650bf281aac">refreshRate</a>

```cpp
int ffw::Monitor::Mode::refreshRate;
```

The prefered refresh rate (V-sync) 




----------------------------------------
The documentation for this class was generated from the following file: `include/ffw/graphics/monitors.h`
