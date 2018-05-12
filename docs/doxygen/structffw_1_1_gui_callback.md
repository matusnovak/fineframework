---
search: false
---

# struct ffw::GuiCallback

## Public Attributes

|Type|Name|
|-----|-----|
|std::function< void(**[GuiEvent](classffw_1_1_gui_event.md)**)>|[**func**](structffw_1_1_gui_callback.md#1a15488ee35be1960e8a10062166988bc4)|
|bool|[**now**](structffw_1_1_gui_callback.md#1adccf1c619aa65258f28284257483d347)|
|**[GuiEventType](group__gui_.md#ga1e47d35cdb8925a93ca0dec3f77be4f0)**|[**type**](structffw_1_1_gui_callback.md#1a25610c8490d2f0ef58f7317c9aaa9d0b)|


## Public Static Functions

|Type|Name|
|-----|-----|
|static **[GuiCallback](structffw_1_1_gui_callback.md)**|[**make**](structffw_1_1_gui_callback.md#1afaf1288eebd252fb734b93f8ce5a7f71) (void(T::\*)(**[GuiEvent](classffw_1_1_gui_event.md)**) memfuncptr, T \* instance, **[GuiEventType](group__gui_.md#ga1e47d35cdb8925a93ca0dec3f77be4f0)** type = **[GuiEventType::ALL](group__gui_1gga1e47d35cdb8925a93ca0dec3f77be4.md#0a5fb1f955b45e38e31789286a1790398d)**, bool instant = false) |
|static **[GuiCallback](structffw_1_1_gui_callback.md)**|[**make**](structffw_1_1_gui_callback.md#1afbcff72df569f5b93ba9f2e0c2ce2a4c) (const std::function< void(**[GuiEvent](classffw_1_1_gui_event.md)**)> & function, **[GuiEventType](group__gui_.md#ga1e47d35cdb8925a93ca0dec3f77be4f0)** type = **[GuiEventType::ALL](group__gui_1gga1e47d35cdb8925a93ca0dec3f77be4.md#0a5fb1f955b45e38e31789286a1790398d)**, bool instant = false) |
|static **[GuiCallback](structffw_1_1_gui_callback.md)**|[**make**](structffw_1_1_gui_callback.md#1a8fd6ffc56e1d92f387cfae32c12c1302) (const F & lambda, **[GuiEventType](group__gui_.md#ga1e47d35cdb8925a93ca0dec3f77be4f0)** type = **[GuiEventType::ALL](group__gui_1gga1e47d35cdb8925a93ca0dec3f77be4.md#0a5fb1f955b45e38e31789286a1790398d)**, bool instant = false) |


## Public Attributes Documentation

### variable <a id="1a15488ee35be1960e8a10062166988bc4" href="#1a15488ee35be1960e8a10062166988bc4">func</a>

```cpp
std::function<void(GuiEvent)> ffw::GuiCallback::func;
```



### variable <a id="1adccf1c619aa65258f28284257483d347" href="#1adccf1c619aa65258f28284257483d347">now</a>

```cpp
bool ffw::GuiCallback::now;
```



### variable <a id="1a25610c8490d2f0ef58f7317c9aaa9d0b" href="#1a25610c8490d2f0ef58f7317c9aaa9d0b">type</a>

```cpp
GuiEventType ffw::GuiCallback::type;
```



## Public Static Functions Documentation

### function <a id="1afaf1288eebd252fb734b93f8ce5a7f71" href="#1afaf1288eebd252fb734b93f8ce5a7f71">make</a>

```cpp
static GuiCallback ffw::GuiCallback::make (
    void(T::*)(GuiEvent) memfuncptr,
    T * instance,
    GuiEventType type = GuiEventType::ALL,
    bool instant = false
)
```



### function <a id="1afbcff72df569f5b93ba9f2e0c2ce2a4c" href="#1afbcff72df569f5b93ba9f2e0c2ce2a4c">make</a>

```cpp
static GuiCallback ffw::GuiCallback::make (
    const std::function< void(GuiEvent)> & function,
    GuiEventType type = GuiEventType::ALL,
    bool instant = false
)
```



### function <a id="1a8fd6ffc56e1d92f387cfae32c12c1302" href="#1a8fd6ffc56e1d92f387cfae32c12c1302">make</a>

```cpp
static GuiCallback ffw::GuiCallback::make (
    const F & lambda,
    GuiEventType type = GuiEventType::ALL,
    bool instant = false
)
```





----------------------------------------
The documentation for this class was generated from the following file: `include/ffw/gui/guiwidget.h`
