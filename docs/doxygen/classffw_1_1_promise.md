---
search:
    keywords: ['ffw::Promise', 'Promise', 'Promise', 'Promise', 'Promise', '~Promise', 'operator=', 'operator=', 'swap', 'getException', 'resolve', 'resolve', 'reject', 'call', 'getResult', 'then', 'fail', 'thenOrFail', 'isResolved', 'isRejected', 'isFinished', 'getStatus', 'PromiseI', '~PromiseI', 'call', 'reject', 'rejectWith']
---

# class ffw::Promise

A simple promise class with chainable lambdas. [More...](#detailed-description)


Inherits the following classes: **[ffw::PromiseI](classffw_1_1_promise_i.md)**

## Public Functions

|Type|Name|
|-----|-----|
||[**Promise**](classffw_1_1_promise.md#1af321194a48d16a8b6c00141f3133dda5) () <br>Default constructor with no lambda function. |
||[**Promise**](classffw_1_1_promise.md#1ac3b6244d0b418e543ee0b68f1821d610) (F const & lambda) <br>Constructor that accepts lambda. |
||[**Promise**](classffw_1_1_promise.md#1acb4a8421775c9f6ed8d1741361633e23) (**[Promise](classffw_1_1_promise.md)**< T > && other) <br>Move constructor. |
||[**Promise**](classffw_1_1_promise.md#1a389f2bacf6ca596528a331e5b3b20f5e) (const **[Promise](classffw_1_1_promise.md)**< T > & other) <br>Copy constructor. |
||[**~Promise**](classffw_1_1_promise.md#1ad8cb6e01c6620f50b9e9169fe4a8ba42) () |
|**[Promise](classffw_1_1_promise.md)**< T > &|[**operator=**](classffw_1_1_promise.md#1aa6fee550e32660c8df364ccca4f09632) (const **[Promise](classffw_1_1_promise.md)**< T > & other) |
|**[Promise](classffw_1_1_promise.md)**< T > &|[**operator=**](classffw_1_1_promise.md#1a7805e9abe36608c3445a117c35a090e6) (**[Promise](classffw_1_1_promise.md)**< T > && other) <br>Move operator. |
|void|[**swap**](classffw_1_1_promise.md#1ac7197b5996f466c2ba5ca8cee8da18d2) (**[Promise](classffw_1_1_promise.md)**< T > & other) |
|const std::exception\_ptr &|[**getException**](classffw_1_1_promise.md#1a69a3bb96bccf1dfbe0c2ce185a136c36) () const <br>Returns the exception associated with this promise. |
|void|[**resolve**](classffw_1_1_promise.md#1ae7eaf71dc4980ffbfcca7f290cb9f3a4) () <br>Resolves the promise with a default value of type T. |
|void|[**resolve**](classffw_1_1_promise.md#1a5d9e203229f9474ea996a04934c7fa5f) (const **[PromiseResult](classffw_1_1_promise_result.md)**< T > & value) <br>Resolves the promise with a value of type T. |
|virtual void|[**reject**](classffw_1_1_promise.md#1ad62235d8682a6ff0d45d12198d00ff01) (const std::exception\_ptr & eptr) override <br>Rejects the promise with an exception. |
|virtual void|[**call**](classffw_1_1_promise.md#1a2981ea16e4a02e8d79ecbab4013cd7c1) () override <br>Calls the function within this promise. |
|const **[PromiseResult](classffw_1_1_promise_result.md)**< T > &|[**getResult**](classffw_1_1_promise.md#1aca6b6d532a750877153ff06dc4853504) () const |
|**[Promise](classffw_1_1_promise.md)**< R > &|[**then**](classffw_1_1_promise.md#1a4d53141c6125f75faf765139b611f0fc) (Then const & lambda) |
|**[Promise](classffw_1_1_promise.md)**< T > &|[**fail**](classffw_1_1_promise.md#1ac9af0fa7d493d0856f260073df6f4d61) (Fail const & lambdaFail) |
|**[Promise](classffw_1_1_promise.md)**< R > &|[**thenOrFail**](classffw_1_1_promise.md#1af37fbc7bab8c67707030eb9080f023d8) (Then const & lambdaThen, Fail const & lambdaFail) |
|bool|[**isResolved**](classffw_1_1_promise.md#1a0e4fd94936d132272692d35a0444b51b) () const <br>Returns true if the promise has been resolved. |
|bool|[**isRejected**](classffw_1_1_promise.md#1a147172b6ca46b0063c92d387f588322b) () const <br>Returns true if the promise has been rejected. |
|bool|[**isFinished**](classffw_1_1_promise.md#1a5e7f47e4c8163a5e9bed5ca9189eebf8) () const <br>Returns true if the promise has been either resolved or rejected. |
|**[Status](classffw_1_1_promise_i.md#1a73260cec543571ae5d4ad4fb9301d6ef)**|[**getStatus**](classffw_1_1_promise.md#1aedaea065c148ff26731d1ed68dbbf744) () const <br>Returns the status of the promise (REJECTED, RESOLVED, or WAITING) |


#### Public Functions inherited from [ffw::PromiseI](classffw_1_1_promise_i.md)

|Type|Name|
|-----|-----|
||[**PromiseI**](classffw_1_1_promise_i.md#1a02a1f66c9d4e938989de792d497bd9fc) () |
|virtual |[**~PromiseI**](classffw_1_1_promise_i.md#1a9d6f92a0485888f35f07a1211105fd64) () |
|void|[**rejectWith**](classffw_1_1_promise_i.md#1a3bf075f87cd539ddeaa86b2385d741a5) (Args &&... args) <br>Rejects this promise with an exception. |


## Additional Inherited Members

#### Public Types inherited from [ffw::PromiseI](classffw_1_1_promise_i.md)

|Type|Name|
|-----|-----|
|enum|[**Status**](classffw_1_1_promise_i.md#1a73260cec543571ae5d4ad4fb9301d6ef) { **WAITING**, **RESOLVED**, **REJECTED** } <br>The status of the promise. |


## Detailed Description

This is a very simple implementation of JavaScript like **[Promise](classffw_1_1_promise.md)**. This promise can accept any kind of template type, including void. **[Any](classffw_1_1_any.md)** further chain links can be added by creating new **[Promise](classffw_1_1_promise.md)** instances using "then" and "fail" (or "thenOrFail") methods. The template type of those new chain links is defined based on the return type of the lambda methods passed into "then" and "fail" methods. 
```cpp
// Using lambda for the first promise is optional! 
// You can always resolve promise outside!
ffw::Promise<void> promise([](ffw::Promise<void>& self) -> void {
    // Do some work
    self.resolve();
});

ffw::Promise<float>& last = promise.then([]() {
    // I am the first chain block to be executed
    // and I will produce std::string
    return std::string("Hello World!");
}).then([](std::string str) {
    // I am the second block
    // and I must accept std::string because the previous
    // chain link produces std::string
    // But I will produce size_t
    return str.size();
}).then([](size_t len) {
    // I am the third block
    // I must accept size_t but I will cast it to int for no reason
    return static_cast<int>(len);
}).fail([](std::exception& e){
    // I am the fail block
    // I will be executed if any of the blocks above (or parent promise)
    // produces exception that matches my lambda argument!
    // However, I can't return anything! But the Promise chain link I produce
    // matches the one before me, so anything after me is type of integer!
}).then([](int val) {
    // I am the last final block and I must accept integer!
    // However, I will produce float...
    return float(val * val);
});

promise.call(); // Calls the promise lambda inside of it
std::cout << "Resolved with: " << last.getResult() << std::endl;
// Prints: "Resolved with: 144"
```

 
## Public Functions Documentation

### function <a id="1af321194a48d16a8b6c00141f3133dda5" href="#1af321194a48d16a8b6c00141f3133dda5">Promise</a>

```cpp
ffw::Promise::Promise ()
```

Default constructor with no lambda function. 


### function <a id="1ac3b6244d0b418e543ee0b68f1821d610" href="#1ac3b6244d0b418e543ee0b68f1821d610">Promise</a>

```cpp
ffw::Promise::Promise (
    F const & lambda
)
```

Constructor that accepts lambda. 

The lambda must accept one parameter, a reference to a promise, which is essentially a "this" pointer. You can use the parameter to either resolve or reject the promise. 
```cpp
ffw::Promise<int> p([](ffw::Promise<int>& self){
    self.resolve(123456);
}
p.call();
```

 

### function <a id="1acb4a8421775c9f6ed8d1741361633e23" href="#1acb4a8421775c9f6ed8d1741361633e23">Promise</a>

```cpp
ffw::Promise::Promise (
    Promise< T > && other
)
```

Move constructor. 


### function <a id="1a389f2bacf6ca596528a331e5b3b20f5e" href="#1a389f2bacf6ca596528a331e5b3b20f5e">Promise</a>

```cpp
ffw::Promise::Promise (
    const Promise< T > & other
)
```

Copy constructor. 


### function <a id="1ad8cb6e01c6620f50b9e9169fe4a8ba42" href="#1ad8cb6e01c6620f50b9e9169fe4a8ba42">~Promise</a>

```cpp
ffw::Promise::~Promise ()
```



### function <a id="1aa6fee550e32660c8df364ccca4f09632" href="#1aa6fee550e32660c8df364ccca4f09632">operator=</a>

```cpp
Promise< T > & ffw::Promise::operator= (
    const Promise< T > & other
)
```



### function <a id="1a7805e9abe36608c3445a117c35a090e6" href="#1a7805e9abe36608c3445a117c35a090e6">operator=</a>

```cpp
Promise< T > & ffw::Promise::operator= (
    Promise< T > && other
)
```

Move operator. 


### function <a id="1ac7197b5996f466c2ba5ca8cee8da18d2" href="#1ac7197b5996f466c2ba5ca8cee8da18d2">swap</a>

```cpp
void ffw::Promise::swap (
    Promise< T > & other
)
```



### function <a id="1a69a3bb96bccf1dfbe0c2ce185a136c36" href="#1a69a3bb96bccf1dfbe0c2ce185a136c36">getException</a>

```cpp
const std::exception_ptr & ffw::Promise::getException () const
```

Returns the exception associated with this promise. 


### function <a id="1ae7eaf71dc4980ffbfcca7f290cb9f3a4" href="#1ae7eaf71dc4980ffbfcca7f290cb9f3a4">resolve</a>

```cpp
void ffw::Promise::resolve ()
```

Resolves the promise with a default value of type T. 

Use this parameter-less resolve function if the template argument is void 

### function <a id="1a5d9e203229f9474ea996a04934c7fa5f" href="#1a5d9e203229f9474ea996a04934c7fa5f">resolve</a>

```cpp
void ffw::Promise::resolve (
    const PromiseResult< T > & value
)
```

Resolves the promise with a value of type T. 


### function <a id="1ad62235d8682a6ff0d45d12198d00ff01" href="#1ad62235d8682a6ff0d45d12198d00ff01">reject</a>

```cpp
virtual void ffw::Promise::reject (
    const std::exception_ptr & eptr
)
```

Overrides **[PromiseI::reject](classffw_1_1_promise_i.md#1a1413b97844d303ee4c44a437c33323a6)**
Rejects the promise with an exception. 


```cpp
Promise<int> p;
try {
    throw std::runtime_error("Something went wrong");
} catch (...) {
    p.reject(std::current_exception());
}
```

 

### function <a id="1a2981ea16e4a02e8d79ecbab4013cd7c1" href="#1a2981ea16e4a02e8d79ecbab4013cd7c1">call</a>

```cpp
virtual void ffw::Promise::call ()
```

Overrides **[PromiseI::call](classffw_1_1_promise_i.md#1ac537a66eb049fa2af0b5dd770fd1dd86)**
Calls the function within this promise. 


```cpp
ffw::Promise<int> p([](ffw::Promise<int>& self){
    self.resolve(123456);
}
p.call();
```

 

### function <a id="1aca6b6d532a750877153ff06dc4853504" href="#1aca6b6d532a750877153ff06dc4853504">getResult</a>

```cpp
const PromiseResult< T > & ffw::Promise::getResult () const
```


Returns the resul of this promise 
```cpp
ffw::Promise<int> p;
p.resolve(42);

std::cout << "Result: " << p.getResult() << std::endl;
// Prints "Result: 42"

p.rejectWith<std::runtime_error>("Something went wrong");

std::cout << "Result: " << p.getResult() << std::endl;
// Will not print!
// Throws std::runtime_error

ffw::Promise<int> unresolved;

std::cout << "Result: " << p.getResult() << std::endl;
// Will not print!
// Throws PromiseException: Promise is not resolved
```

 

### function <a id="1a4d53141c6125f75faf765139b611f0fc" href="#1a4d53141c6125f75faf765139b611f0fc">then</a>

```cpp
Promise< R > & ffw::Promise::then (
    Then const & lambda
)
```


Creates a new then chain link with lambda
The lambda will be executed once the parent (the instance of the method you are calling) has been be resolved. The return value of lambda determines the template type of the **[Promise](classffw_1_1_promise.md)** returned. For example, you create a promise that performs an SQL query which returns a raw string. Your next "then" chain link can have a lambda that accepts a string and produces an instance of class. You can then extend the chain even further by another "then" which accepts the instance of class and produces bool or anything else. 
```cpp
ffw::Promise<std::string> p;

ffw::Promise<int>& next = p.then([](std::string str) -> int {
    std::cout << "Parent promise was resolved with: " << str << std::endl;
    return str.size();
});

ffw::Promise<void>& last = next.then([](int val) -> void {
    std::cout << "Received integer of: " << val << std::endl;
});

p.resolve("Hello!");
// Prints: "Parent promise was resolved with: Hello!"
//         "Received integer of: 6"

// You don't need to explicitly declare the instances of promises as above
// You can make them more simple as below:

p.then([](std::string str) -> int {
      std::cout << "Parent promise was resolved with: " << str << std::endl;
    return str.size();
}).then([](int val) -> void {
    std::cout << "Received integer of: " << val << std::endl;
});
```

 

### function <a id="1ac9af0fa7d493d0856f260073df6f4d61" href="#1ac9af0fa7d493d0856f260073df6f4d61">fail</a>

```cpp
Promise< T > & ffw::Promise::fail (
    Fail const & lambdaFail
)
```


Creates a new fail chain link with lambda
The lambda will be executed once the parent (the instance of the method you are calling) has been be rejected. 
```cpp
ffw::Promise<std::string> p;

ffw::Promise<std::string>& next = p.fail([](std::runtime_exception& e){
    std::cout << "runtime_exception has been thrown!" << std::endl;
});

ffw::Promise<std::string>& last = next.fail([](std::exception& e){
    std::cout << "raw exception has been thrown!" << std::endl;
});

ffw::Promise<std::string>& test = last.fail([](const std::exception_ptr& eptr){
    try {
        std::rethrow_exception(eptr);
    } catch (std::runtime_exception& e){
        std::cout << "Caught runtime_exception!" << std::endl;
    } catch (std::exception& e){
        std::cout << "Caught raw exception!" << std::endl;
    }
});

p.rejectWith<std::runtime_exception>("Hello!");
// Prints: "runtime_exception has been thrown!"
//         "raw exception has been thrown!"
//         "Caught runtime_exception!"
// Both first two "fail" lambdas will be called because both raw std::exception
// and std::runtime_error match the exception thrown.
// The last fail lambda will also be called because it accepts any exception in form of 
// std::exception_ptr
```

 

### function <a id="1af37fbc7bab8c67707030eb9080f023d8" href="#1af37fbc7bab8c67707030eb9080f023d8">thenOrFail</a>

```cpp
Promise< R > & ffw::Promise::thenOrFail (
    Then const & lambdaThen
    Fail const & lambdaFail
)
```


Creates a new then + fail chain link with lambda
Similarly with "then" and "fail" methods, you can combine those two and create one chain link that will contain both "then" and "fail" lambdas. 

### function <a id="1a0e4fd94936d132272692d35a0444b51b" href="#1a0e4fd94936d132272692d35a0444b51b">isResolved</a>

```cpp
bool ffw::Promise::isResolved () const
```

Returns true if the promise has been resolved. 


### function <a id="1a147172b6ca46b0063c92d387f588322b" href="#1a147172b6ca46b0063c92d387f588322b">isRejected</a>

```cpp
bool ffw::Promise::isRejected () const
```

Returns true if the promise has been rejected. 


### function <a id="1a5e7f47e4c8163a5e9bed5ca9189eebf8" href="#1a5e7f47e4c8163a5e9bed5ca9189eebf8">isFinished</a>

```cpp
bool ffw::Promise::isFinished () const
```

Returns true if the promise has been either resolved or rejected. 


### function <a id="1aedaea065c148ff26731d1ed68dbbf744" href="#1aedaea065c148ff26731d1ed68dbbf744">getStatus</a>

```cpp
Status ffw::Promise::getStatus () const
```

Returns the status of the promise (REJECTED, RESOLVED, or WAITING) 




----------------------------------------
The documentation for this class was generated from the following file: `include/ffw/math/promise.h`
