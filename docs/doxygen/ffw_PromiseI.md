PromiseI
===================================

[Promise](ffw_Promise.html) interface class. 

**Implemented by:** [ffw::Promise< T >](ffw_Promise.html), 

The documentation for this class was generated from: `include/ffw/math/promise.h`



## Public Types

| Type | Name |
| -------: | :------- |
| enum | [Status](#af35a7f5) |


## Public Functions

| Type | Name |
| -------: | :------- |
|   | [PromiseI](#f4a6edb8) ()  |
|  virtual  | [~PromiseI](#5ac1a5a0) ()  |
|  virtual void | [call](#98ff0a8e) () = 0  _Calls the function associated within the promise._ |
|  virtual void | [reject](#38460c5d) (const std::exception_ptr & _e_) = 0  _Rejects this promise with an exception._ |
|  void | [rejectWith](#7d11756a) (Args &&... _args_)  _Rejects this promise with an exception._ |


## Public Types Documentation

### _enum_ <a id="af35a7f5" href="#af35a7f5">Status</a>

```cpp
enum Status {
    WAITING,
    RESOLVED,
    REJECTED,
}
```

The status of the promise. 



## Public Functions Documentation

### _function_ <a id="f4a6edb8" href="#f4a6edb8">PromiseI</a>

```cpp
inline  PromiseI () 
```



### _function_ <a id="5ac1a5a0" href="#5ac1a5a0">~PromiseI</a>

```cpp
inline virtual  ~PromiseI () 
```



### _function_ <a id="98ff0a8e" href="#98ff0a8e">call</a>

```cpp
virtual void call () = 0 
```

Calls the function associated within the promise. 

### _function_ <a id="38460c5d" href="#38460c5d">reject</a>

```cpp
virtual void reject (
    const std::exception_ptr & e
) = 0 
```

Rejects this promise with an exception. 



**Example:**

```cpp
Promise<int> p;
try {
    throw std::runtime_error("Something went wrong");
} catch (...){
    p.reject(std::current_exception());
}
```
 
### _function_ <a id="7d11756a" href="#7d11756a">rejectWith</a>

```cpp
inline void rejectWith (
    Args &&... args
) 
```

Rejects this promise with an exception. 

This method will construct an exception based on the template and constructor arguments provided. 

**Example:**

```cpp
Promise<int> p;
p.rejectWith<std::runtime_error>("Something went wrong");
```
 


