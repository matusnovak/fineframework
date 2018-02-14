iterator
===================================


**Inherits from:** [std::iterator< std::bidirectional_iterator_tag, uint32_t >]()

The documentation for this class was generated from: `include/ffw/math/third_party/utfcpp/checked.h`



## Public Functions

| Type | Name |
| -------: | :------- |
|   | [iterator](#c7464811) ()  |
|  explicit  | [iterator](#3a4db1c4) (const octet_iterator & _octet_it_, const octet_iterator & _rangestart_, const octet_iterator & _rangeend_)  |
|  octet_iterator | [base](#e2a12ab0) () const  |
|  [uint32_t](utf8.html#b52bf0b0) | [operator*](#73d070e2) () const  |
|  bool | [operator==](#6fbd3b79) (const [iterator](utf8_iterator.html) & _rhs_) const  |
|  bool | [operator!=](#9f0d7898) (const [iterator](utf8_iterator.html) & _rhs_) const  |
|  [iterator](utf8_iterator.html) & | [operator++](#a7eb0bb4) ()  |
|  [iterator](utf8_iterator.html) | [operator++](#5f068972) (int)  |
|  [iterator](utf8_iterator.html) & | [operator--](#85c896fc) ()  |
|  [iterator](utf8_iterator.html) | [operator--](#6606e098) (int)  |


## Public Functions Documentation

### _function_ <a id="c7464811" href="#c7464811">iterator</a>

```cpp
inline  iterator () 
```



### _function_ <a id="3a4db1c4" href="#3a4db1c4">iterator</a>

```cpp
explicit inline  iterator (
    const octet_iterator & octet_it,
    const octet_iterator & rangestart,
    const octet_iterator & rangeend
) 
```



### _function_ <a id="e2a12ab0" href="#e2a12ab0">base</a>

```cpp
inline octet_iterator base () const 
```



### _function_ <a id="73d070e2" href="#73d070e2">operator*</a>

```cpp
inline uint32_t operator* () const 
```



### _function_ <a id="6fbd3b79" href="#6fbd3b79">operator==</a>

```cpp
inline bool operator== (
    const iterator & rhs
) const 
```



### _function_ <a id="9f0d7898" href="#9f0d7898">operator!=</a>

```cpp
inline bool operator!= (
    const iterator & rhs
) const 
```



### _function_ <a id="a7eb0bb4" href="#a7eb0bb4">operator++</a>

```cpp
inline iterator & operator++ () 
```



### _function_ <a id="5f068972" href="#5f068972">operator++</a>

```cpp
inline iterator operator++ (
    int
) 
```



### _function_ <a id="85c896fc" href="#85c896fc">operator--</a>

```cpp
inline iterator & operator-- () 
```



### _function_ <a id="6606e098" href="#6606e098">operator--</a>

```cpp
inline iterator operator-- (
    int
) 
```





