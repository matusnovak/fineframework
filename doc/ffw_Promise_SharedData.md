SharedData
===================================


The documentation for this struct was generated from: `include/ffw/math/promise.h`



## Public Attributes

| Type | Name |
| -------: | :------- |
|  std::function< void([Promise](ffw_Promise.html)< T > &)> | [func](#8432328a) |
|  std::list< [PromiseI](ffw_PromiseI.html) * > | [next](#f8813965) |
|  std::exception_ptr | [eptr](#c108ba0a) |
|  [PromiseResult](ffw_PromiseResult.html)< T > | [result](#2646c438) |
|  std::atomic< [Status](ffw_PromiseI.html#af35a7f5) > | [status](#77b0c244) |


## Public Attributes Documentation

### <span style="opacity:0.5;">variable</span> <a id="8432328a" href="#8432328a">func</a>

```cpp
std::function< void(Promise< T > &)> func
```



### <span style="opacity:0.5;">variable</span> <a id="f8813965" href="#f8813965">next</a>

```cpp
std::list< PromiseI * > next
```



### <span style="opacity:0.5;">variable</span> <a id="c108ba0a" href="#c108ba0a">eptr</a>

```cpp
std::exception_ptr eptr
```



### <span style="opacity:0.5;">variable</span> <a id="2646c438" href="#2646c438">result</a>

```cpp
PromiseResult< T > result
```



### <span style="opacity:0.5;">variable</span> <a id="77b0c244" href="#77b0c244">status</a>

```cpp
std::atomic< Status > status
```





