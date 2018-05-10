---
search: false
---

# class ffw::PromiseInterface

**[Promise](classffw_1_1_promise.md)** interface class. 


Inherited by the following classes: **[ffw::Promise< T >](classffw_1_1_promise.md)**

## Public Types

|Type|Name|
|-----|-----|
|enum|[**Status**](classffw_1_1_promise_interface.md#1a94e5c52cddb7f15b34b2fa0480601d1c) { **WAITING**, **RESOLVED**, **REJECTED** } <br>The status of the promise. |


## Public Functions

|Type|Name|
|-----|-----|
||[**PromiseInterface**](classffw_1_1_promise_interface.md#1ac72ff553a0327d8df9dc11e79ab36f54) () = default |
|virtual |[**~PromiseInterface**](classffw_1_1_promise_interface.md#1af0e4917bf35b192e89b5bc3b955fbcdc) () = default |
|virtual void|[**call**](classffw_1_1_promise_interface.md#1a9c9f2629454b7e18f00836a471049565) () = 0<br>Calls the function associated within the promise. |
|virtual void|[**reject**](classffw_1_1_promise_interface.md#1a4dfbf5c43cdd6310451378028f6d6802) (const std::exception\_ptr & e) = 0<br>Rejects this promise with an exception. |
|void|[**rejectWith**](classffw_1_1_promise_interface.md#1a3e56631958ba2c914e01e10dcf5de6ae) (Args &&... args) <br>Rejects this promise with an exception. |


## Public Types Documentation

### enum <a id="1a94e5c52cddb7f15b34b2fa0480601d1c" href="#1a94e5c52cddb7f15b34b2fa0480601d1c">Status</a>

```cpp
enum ffw::PromiseInterface::Status {
    WAITING,
    RESOLVED,
    REJECTED,
};
```

The status of the promise. 


## Public Functions Documentation

### function <a id="1ac72ff553a0327d8df9dc11e79ab36f54" href="#1ac72ff553a0327d8df9dc11e79ab36f54">PromiseInterface</a>

```cpp
ffw::PromiseInterface::PromiseInterface () = default
```



### function <a id="1af0e4917bf35b192e89b5bc3b955fbcdc" href="#1af0e4917bf35b192e89b5bc3b955fbcdc">~PromiseInterface</a>

```cpp
virtual ffw::PromiseInterface::~PromiseInterface () = default
```



### function <a id="1a9c9f2629454b7e18f00836a471049565" href="#1a9c9f2629454b7e18f00836a471049565">call</a>

```cpp
virtual void ffw::PromiseInterface::call () = 0
```

Calls the function associated within the promise. 


### function <a id="1a4dfbf5c43cdd6310451378028f6d6802" href="#1a4dfbf5c43cdd6310451378028f6d6802">reject</a>

```cpp
virtual void ffw::PromiseInterface::reject (
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

 

### function <a id="1a3e56631958ba2c914e01e10dcf5de6ae" href="#1a3e56631958ba2c914e01e10dcf5de6ae">rejectWith</a>

```cpp
void ffw::PromiseInterface::rejectWith (
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
