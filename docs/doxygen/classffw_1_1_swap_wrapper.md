---
search: false
---

# class ffw::SwapWrapper

## Public Attributes

|Type|Name|
|-----|-----|
|std::unique\_ptr< T >|[**ptr**](classffw_1_1_swap_wrapper.md#1aa01f69ebe1eed7fafb92260344354737)|


## Public Functions

|Type|Name|
|-----|-----|
||[**SwapWrapper**](classffw_1_1_swap_wrapper.md#1af84300e9ded6cb0801574b80a1a063b6) (Args &&... args) |
||[**SwapWrapper**](classffw_1_1_swap_wrapper.md#1a2f392c184bb7aeaa0c7e294e621e94a5) (**[SwapWrapper](classffw_1_1_swap_wrapper.md)** && other) |
|**[SwapWrapper](classffw_1_1_swap_wrapper.md)** &|[**operator=**](classffw_1_1_swap_wrapper.md#1abf6ff8ec9c93cbc6182013473b8f0932) (**[SwapWrapper](classffw_1_1_swap_wrapper.md)** && other) |
|void|[**swap**](classffw_1_1_swap_wrapper.md#1af38befc3dd21c67e9b7a8af98f222a70) (**[SwapWrapper](classffw_1_1_swap_wrapper.md)**< T > & other) |
|T &|[**operator\***](classffw_1_1_swap_wrapper.md#1a6011f16b0341cbe081460eeda878e88e) () |
|const T &|[**operator\***](classffw_1_1_swap_wrapper.md#1a05885a7edb2cf819726488b7eb3be78e) () const |
|T \*|[**operator->**](classffw_1_1_swap_wrapper.md#1a32d98472590da3a43fa4b8dd891b1e4f) () |
|const T \*|[**operator->**](classffw_1_1_swap_wrapper.md#1acd8aae777cabec69ccfc6c115a5ea1e7) () const |


## Public Attributes Documentation

### variable <a id="1aa01f69ebe1eed7fafb92260344354737" href="#1aa01f69ebe1eed7fafb92260344354737">ptr</a>

```cpp
std::unique_ptr<T> ffw::SwapWrapper< T >::ptr;
```



## Public Functions Documentation

### function <a id="1af84300e9ded6cb0801574b80a1a063b6" href="#1af84300e9ded6cb0801574b80a1a063b6">SwapWrapper</a>

```cpp
ffw::SwapWrapper::SwapWrapper (
    Args &&... args
)
```



### function <a id="1a2f392c184bb7aeaa0c7e294e621e94a5" href="#1a2f392c184bb7aeaa0c7e294e621e94a5">SwapWrapper</a>

```cpp
ffw::SwapWrapper::SwapWrapper (
    SwapWrapper && other
)
```



### function <a id="1abf6ff8ec9c93cbc6182013473b8f0932" href="#1abf6ff8ec9c93cbc6182013473b8f0932">operator=</a>

```cpp
SwapWrapper & ffw::SwapWrapper::operator= (
    SwapWrapper && other
)
```



### function <a id="1af38befc3dd21c67e9b7a8af98f222a70" href="#1af38befc3dd21c67e9b7a8af98f222a70">swap</a>

```cpp
void ffw::SwapWrapper::swap (
    SwapWrapper< T > & other
)
```



### function <a id="1a6011f16b0341cbe081460eeda878e88e" href="#1a6011f16b0341cbe081460eeda878e88e">operator\*</a>

```cpp
T & ffw::SwapWrapper::operator* ()
```



### function <a id="1a05885a7edb2cf819726488b7eb3be78e" href="#1a05885a7edb2cf819726488b7eb3be78e">operator\*</a>

```cpp
const T & ffw::SwapWrapper::operator* () const
```



### function <a id="1a32d98472590da3a43fa4b8dd891b1e4f" href="#1a32d98472590da3a43fa4b8dd891b1e4f">operator-></a>

```cpp
T * ffw::SwapWrapper::operator-> ()
```



### function <a id="1acd8aae777cabec69ccfc6c115a5ea1e7" href="#1acd8aae777cabec69ccfc6c115a5ea1e7">operator-></a>

```cpp
const T * ffw::SwapWrapper::operator-> () const
```





----------------------------------------
The documentation for this class was generated from the following file: `include/ffw/swapwrapper.h`
