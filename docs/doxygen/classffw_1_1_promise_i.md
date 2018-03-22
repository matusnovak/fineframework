---
search:
    keywords: ['ffw::PromiseI', 'Status', 'PromiseI', '~PromiseI', 'call', 'reject', 'rejectWith']
---

# class ffw::PromiseI

**[Promise](classffw_1_1_promise.md)** interface class. 


Inherited by the following classes: **[ffw::Promise< T >](classffw_1_1_promise.md)**

## Public Types

|Type|Name|
|-----|-----|
|enum|[**Status**](classffw_1_1_promise_i.md#1a73260cec543571ae5d4ad4fb9301d6ef) { **WAITING**, **RESOLVED**, **REJECTED** } <br>The status of the promise. |


## Public Functions

|Type|Name|
|-----|-----|
||[**PromiseI**](classffw_1_1_promise_i.md#1a02a1f66c9d4e938989de792d497bd9fc) () |
|virtual |[**~PromiseI**](classffw_1_1_promise_i.md#1a9d6f92a0485888f35f07a1211105fd64) () |
|virtual void|[**call**](classffw_1_1_promise_i.md#1ac537a66eb049fa2af0b5dd770fd1dd86) () = 0<br>Calls the function associated within the promise. |
|virtual void|[**reject**](classffw_1_1_promise_i.md#1a1413b97844d303ee4c44a437c33323a6) (const std::exception\_ptr & e) = 0<br>Rejects this promise with an exception. |
|void|[**rejectWith**](classffw_1_1_promise_i.md#1a3bf075f87cd539ddeaa86b2385d741a5) (Args &&... args) <br>Rejects this promise with an exception. |


## Public Types Documentation

### enum <a id="1a73260cec543571ae5d4ad4fb9301d6ef" href="#1a73260cec543571ae5d4ad4fb9301d6ef">Status</a>

```cpp
enum ffw::PromiseI::Status {
    WAITING,
    RESOLVED,
    REJECTED,
};
```

The status of the promise. 


## Public Functions Documentation

### function <a id="1a02a1f66c9d4e938989de792d497bd9fc" href="#1a02a1f66c9d4e938989de792d497bd9fc">PromiseI</a>

```cpp
ffw::PromiseI::PromiseI ()
```



### function <a id="1a9d6f92a0485888f35f07a1211105fd64" href="#1a9d6f92a0485888f35f07a1211105fd64">~PromiseI</a>

```cpp
virtual ffw::PromiseI::~PromiseI ()
```



### function <a id="1ac537a66eb049fa2af0b5dd770fd1dd86" href="#1ac537a66eb049fa2af0b5dd770fd1dd86">call</a>

```cpp
virtual void ffw::PromiseI::call () = 0
```

Calls the function associated within the promise. 


### function <a id="1a1413b97844d303ee4c44a437c33323a6" href="#1a1413b97844d303ee4c44a437c33323a6">reject</a>

```cpp
virtual void ffw::PromiseI::reject (
    const std::exception_ptr & e
) = 0
```

Rejects this promise with an exception. 


```cpp
Promise<int> p;
try {
    throw std::runtime_error("Something went wrong");
} catch (...){
    p.reject(std::current_exception());
}
```

 

### function <a id="1a3bf075f87cd539ddeaa86b2385d741a5" href="#1a3bf075f87cd539ddeaa86b2385d741a5">rejectWith</a>

```cpp
void ffw::PromiseI::rejectWith (
    Args &&... args
)
```

Rejects this promise with an exception. 

This method will construct an exception based on the template and constructor arguments provided. 
```cpp
Promise<int> p;
p.rejectWith<std::runtime_error>("Something went wrong");
```

 



----------------------------------------
The documentation for this class was generated from the following file: `include/ffw/math/promise.h`
