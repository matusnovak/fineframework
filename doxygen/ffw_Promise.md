Promise
===================================

A simple promise class with chainable lambdas. 

**Inherits from:** [ffw::PromiseI](ffw_PromiseI.html)

The documentation for this class was generated from: `include/ffw/math/promise.h`

## Detailed description

This is a very simple implementation of JavaScript like [Promise](ffw_Promise.html). This promise can accept any kind of template type, including void. Any further chain links can be added by creating new [Promise](ffw_Promise.html) instances using "then" and "fail" (or "thenOrFail") methods. The template type of those new chain links is defined based on the return type of the lambda methods passed into "then" and "fail" methods. 

**Example:**

```cpp
// Using lambda for the first promise is optional! 
// You can always resolve promise outside!
ffw::Promise<void> promise([](ffw::Promise<void>& self) -> void {
    // Do some work
    self.resolve();
});

ffw::Promise<float> last = promise.then([]() {
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
 


## Public Functions

| Type | Name |
| -------: | :------- |
|   | [Promise](#fc73ee8d) ()  _Default constructor with no lambda function._ |
|   | [Promise](#32e21e29) (F const & _lambda_)  _Constructor that accepts lambda._ |
|   | [Promise](#06f4ff0a) (const [Promise](ffw_Promise.html)< T > & _other_)  _Copy constructor._ |
|  [Promise](ffw_Promise.html)< T > & | [operator=](#73adf2a6) (const [Promise](ffw_Promise.html)< T > & _other_)  _Copy operator._ |
|  const std::exception_ptr & | [getException](#da619b4e) ()  _Returns the exception associated with this promise._ |
|  void | [resolve](#f9f6ea9a) ()  _Resolves the promise with a default value of type T._ |
|  void | [resolve](#59d034e3) (const [PromiseResult](ffw_PromiseResult.html)< T > & _value_)  _Resolves the promise with a value of type T._ |
|  virtual void | [reject](#57c902dd) (const std::exception_ptr & _eptr_)  _Rejects the promise with an exception._ |
|  virtual void | [call](#24544a5f) ()  _Calls the function within this promise._ |
|  const [PromiseResult](ffw_PromiseResult.html)< T > & | [getResult](#867c4ace) () const  |
|  [Promise](ffw_Promise.html)< R > & | [then](#54a17815) (Then const & _lambda_)  |
|  [Promise](ffw_Promise.html)< T > & | [fail](#7056e514) (Fail const & _lambdaFail_)  |
|  [Promise](ffw_Promise.html)< R > & | [thenOrFail](#0af84968) (Then const & _lambdaThen_, Fail const & _lambdaFail_)  |
|  bool | [isResolved](#ad5042c0) () const  _Returns true if the promise has been resolved._ |
|  bool | [isRejected](#5eddfa0a) () const  _Returns true if the promise has been rejected._ |
|  bool | [isFinished](#a11bd247) () const  _Returns true if the promise has been either resolved or rejected._ |
|  [Status](ffw_PromiseI.html#af35a7f5) | [getStatus](#c4e1a4c1) () const  _Returns the status of the promise (REJECTED, RESOLVED, or WAITING)_ |


## Public Functions Documentation

### _function_ <a id="fc73ee8d" href="#fc73ee8d">Promise</a>

```cpp
inline  Promise () 
```

Default constructor with no lambda function. 

### _function_ <a id="32e21e29" href="#32e21e29">Promise</a>

```cpp
inline  Promise (
    F const & lambda
) 
```

Constructor that accepts lambda. 

The lambda must accept one parameter, a reference to a promise, which is essentially a "this" pointer. You can use the parameter to either resolve or reject the promise. 

**Example:**

```cpp
ffw::Promise<int> p([](ffw::Promise<int>& self){
    self.resolve(123456);
}
p.call();
```
 
### _function_ <a id="06f4ff0a" href="#06f4ff0a">Promise</a>

```cpp
inline  Promise (
    const Promise< T > & other
) 
```

Copy constructor. 

No real copy is being made. Instead, the data is shared between all copies. If you have two identical copies and one gets resolved/rejected, the second copy will also be resolved or rejected. 
### _function_ <a id="73adf2a6" href="#73adf2a6">operator=</a>

```cpp
inline Promise< T > & operator= (
    const Promise< T > & other
) 
```

Copy operator. 

No real copy is being made. Instead, the data is shared between all copies. If you have two identical copies and one gets resolved/rejected, the second copy will also be resolved or rejected. 
### _function_ <a id="da619b4e" href="#da619b4e">getException</a>

```cpp
inline const std::exception_ptr & getException () 
```

Returns the exception associated with this promise. 

### _function_ <a id="f9f6ea9a" href="#f9f6ea9a">resolve</a>

```cpp
inline void resolve () 
```

Resolves the promise with a default value of type T. 

Use this parameter-less resolve function if the template argument is void 
### _function_ <a id="59d034e3" href="#59d034e3">resolve</a>

```cpp
inline void resolve (
    const PromiseResult< T > & value
) 
```

Resolves the promise with a value of type T. 

### _function_ <a id="57c902dd" href="#57c902dd">reject</a>

```cpp
inline virtual void reject (
    const std::exception_ptr & eptr
) 
```

Rejects the promise with an exception. 

**Overrides:** [reject](/doxygen/ffw_PromiseI.md#38460c5d) from class [PromiseI](/doxygen/ffw_PromiseI.md)



**Example:**

```cpp
Promise<int> p;
try {
    throw std::runtime_error("Something went wrong");
} catch (...) {
    p.reject(std::current_exception());
}
```
 
### _function_ <a id="24544a5f" href="#24544a5f">call</a>

```cpp
inline virtual void call () 
```

Calls the function within this promise. 

**Overrides:** [call](/doxygen/ffw_PromiseI.md#98ff0a8e) from class [PromiseI](/doxygen/ffw_PromiseI.md)



**Example:**

```cpp
ffw::Promise<int> p([](ffw::Promise<int>& self){
    self.resolve(123456);
}
p.call();
```
 
### _function_ <a id="867c4ace" href="#867c4ace">getResult</a>

```cpp
inline const PromiseResult< T > & getResult () const 
```



Returns the resul of this promise 

**Example:**

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
 
### _function_ <a id="54a17815" href="#54a17815">then</a>

```cpp
inline Promise< R > & then (
    Then const & lambda
) 
```



Creates a new then chain link with lambda
The lambda will be executed once the parent (the instance of the method you are calling) has been be resolved. The return value of lambda determines the template type of the [Promise](ffw_Promise.html) returned. For example, you create a promise that performs an SQL query which returns a raw string. Your next "then" chain link can have a lambda that accepts a string and produces an instance of class. You can then extend the chain even further by another "then" which accepts the instance of class and produces bool or anything else. 

**Example:**

```cpp
ffw::Promise<std::string> p;

ffw::Promise<int> next = p.then([](std::string str) -> int {
    std::cout << "Parent promise was resolved with: " << str << std::endl;
    return str.size();
});

ffw::Promise<void> last = next.then([](int val) -> void {
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
 
### _function_ <a id="7056e514" href="#7056e514">fail</a>

```cpp
inline Promise< T > & fail (
    Fail const & lambdaFail
) 
```



Creates a new fail chain link with lambda
The lambda will be executed once the parent (the instance of the method you are calling) has been be rejected. 

**Example:**

```cpp
ffw::Promise<std::string> p;

ffw::Promise<std::string> next = p.fail([](std::runtime_exception& e){
    std::cout << "runtime_exception has been thrown!" << std::endl;
});

ffw::Promise<std::string> last = next.fail([](std::exception& e){
    std::cout << "raw exception has been thrown!" << std::endl;
});

ffw::Promise<std::string> test = last.fail([](const std::exception_ptr& eptr){
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
 
### _function_ <a id="0af84968" href="#0af84968">thenOrFail</a>

```cpp
inline Promise< R > & thenOrFail (
    Then const & lambdaThen,
    Fail const & lambdaFail
) 
```



Creates a new then + fail chain link with lambda
Similarly with "then" and "fail" methods, you can combine those two and create one chain link that will contain both "then" and "fail" lambdas. 
### _function_ <a id="ad5042c0" href="#ad5042c0">isResolved</a>

```cpp
inline bool isResolved () const 
```

Returns true if the promise has been resolved. 

### _function_ <a id="5eddfa0a" href="#5eddfa0a">isRejected</a>

```cpp
inline bool isRejected () const 
```

Returns true if the promise has been rejected. 

### _function_ <a id="a11bd247" href="#a11bd247">isFinished</a>

```cpp
inline bool isFinished () const 
```

Returns true if the promise has been either resolved or rejected. 

### _function_ <a id="c4e1a4c1" href="#c4e1a4c1">getStatus</a>

```cpp
inline Status getStatus () const 
```

Returns the status of the promise (REJECTED, RESOLVED, or WAITING) 



