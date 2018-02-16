RingBuffer
===================================


The documentation for this class was generated from: `include/ffw/math/ringbuffer.h`



## Public Functions

| Type | Name |
| -------: | :------- |
|   | [RingBuffer](#91519e12) ()  |
|   | [RingBuffer](#db3d26e2) (size_t _Size_)  |
|   | [~RingBuffer](#6ad6a8a6) ()  |
|  void | [create](#6ab0a3d8) (size_t _Size_)  |
|  T * | [back](#646485c3) ()  |
|  bool | [push](#c69cbd1a) (const T & _Item_)  |
|  bool | [pop](#e5773a86) (T * _Item_)  |
|  size_t | [getRange](#afe3e91f) () const  |
|  size_t | [range](#02580383) () const  |
|  size_t | [getTail](#d7947e2f) () const  |
|  size_t | [getHead](#e07d3ea5) () const  |
|  size_t | [getSize](#26269c4f) () const  |
|  bool | [isFull](#fbd41f03) () const  |
|  bool | [isEmpty](#7a05d019) () const  |
|  void | [clear](#59528c4a) ()  |
|  void | [reset](#f0df74ce) ()  |


## Public Functions Documentation

### _function_ <a id="91519e12" href="#91519e12">RingBuffer</a>

```cpp
inline  RingBuffer () 
```



### _function_ <a id="db3d26e2" href="#db3d26e2">RingBuffer</a>

```cpp
inline  RingBuffer (
    size_t Size
) 
```



### _function_ <a id="6ad6a8a6" href="#6ad6a8a6">~RingBuffer</a>

```cpp
inline  ~RingBuffer () 
```



### _function_ <a id="6ab0a3d8" href="#6ab0a3d8">create</a>

```cpp
inline void create (
    size_t Size
) 
```



### _function_ <a id="646485c3" href="#646485c3">back</a>

```cpp
inline T * back () 
```



### _function_ <a id="c69cbd1a" href="#c69cbd1a">push</a>

```cpp
inline bool push (
    const T & Item
) 
```



### _function_ <a id="e5773a86" href="#e5773a86">pop</a>

```cpp
inline bool pop (
    T * Item
) 
```



### _function_ <a id="afe3e91f" href="#afe3e91f">getRange</a>

```cpp
inline size_t getRange () const 
```



### _function_ <a id="02580383" href="#02580383">range</a>

```cpp
inline size_t range () const 
```



### _function_ <a id="d7947e2f" href="#d7947e2f">getTail</a>

```cpp
inline size_t getTail () const 
```



### _function_ <a id="e07d3ea5" href="#e07d3ea5">getHead</a>

```cpp
inline size_t getHead () const 
```



### _function_ <a id="26269c4f" href="#26269c4f">getSize</a>

```cpp
inline size_t getSize () const 
```



### _function_ <a id="fbd41f03" href="#fbd41f03">isFull</a>

```cpp
inline bool isFull () const 
```



### _function_ <a id="7a05d019" href="#7a05d019">isEmpty</a>

```cpp
inline bool isEmpty () const 
```



### _function_ <a id="59528c4a" href="#59528c4a">clear</a>

```cpp
inline void clear () 
```



### _function_ <a id="f0df74ce" href="#f0df74ce">reset</a>

```cpp
inline void reset () 
```





