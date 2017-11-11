SharedData
===================================


The documentation for this struct was generated from: `include/ffw/math/promise.h`



## Public Attributes

| Type | Name |
| -------: | :------- |
|  std::function< void([Promise](ffw_PromiseI.html#10b9755d)< T > &)> | [func](#f8f71087) |
|  std::list< [PromiseI](ffw_PromiseI.html) * > | [next](#d250afee) |
|  std::exception_ptr | [eptr](#1ed6f817) |
|  PromiseResult< T > | [result](#8bd68479) |
|  std::atomic< [Status](ffw_PromiseI.html#af35a7f5) > | [status](#820525d0) |


## Public Attributes Documentation

### <span style="opacity:0.5;">variable</span> <a id="f8f71087" href="#f8f71087">func</a>

```cpp
std::function< void(Promise< T > &)> func
```



### <span style="opacity:0.5;">variable</span> <a id="d250afee" href="#d250afee">next</a>

```cpp
std::list< PromiseI * > next
```



### <span style="opacity:0.5;">variable</span> <a id="1ed6f817" href="#1ed6f817">eptr</a>

```cpp
std::exception_ptr eptr
```



### <span style="opacity:0.5;">variable</span> <a id="8bd68479" href="#8bd68479">result</a>

```cpp
PromiseResult< T > result
```



### <span style="opacity:0.5;">variable</span> <a id="820525d0" href="#820525d0">status</a>

```cpp
std::atomic< Status > status
```





