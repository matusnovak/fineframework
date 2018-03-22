---
search:
    keywords: ['ffw::RingBuffer', 'RingBuffer', 'RingBuffer', '~RingBuffer', 'create', 'back', 'push', 'pop', 'getRange', 'range', 'getTail', 'getHead', 'getSize', 'isFull', 'isEmpty', 'clear', 'reset']
---

# class ffw::RingBuffer

## Public Functions

|Type|Name|
|-----|-----|
||[**RingBuffer**](classffw_1_1_ring_buffer.md#1a1262874544b0287e727afe49b616be56) () |
||[**RingBuffer**](classffw_1_1_ring_buffer.md#1ad29a030ebc4001c38216914bb5fd8049) (size\_t Size) |
||[**~RingBuffer**](classffw_1_1_ring_buffer.md#1a920089172e1534404517fcf805731d8c) () |
|void|[**create**](classffw_1_1_ring_buffer.md#1a6dfe7e8b0ea42e06949b93fd9c33b011) (size\_t Size) |
|T \*|[**back**](classffw_1_1_ring_buffer.md#1a6853b78e744af674294418a5cc676a5b) () |
|bool|[**push**](classffw_1_1_ring_buffer.md#1a68fe2a4b580de075ee5fbb71924417c7) (const T & Item) |
|bool|[**pop**](classffw_1_1_ring_buffer.md#1a843a34f8e404667058efdffb07df6afb) (T \* Item) |
|size\_t|[**getRange**](classffw_1_1_ring_buffer.md#1a31ce78e7a74f9aeee6195207f9343cc0) () const |
|size\_t|[**range**](classffw_1_1_ring_buffer.md#1ae676a50e8dce38c1c82a457356f5148f) () const |
|size\_t|[**getTail**](classffw_1_1_ring_buffer.md#1a4026b573a8dfa5ed9dce5339a667ce81) () const |
|size\_t|[**getHead**](classffw_1_1_ring_buffer.md#1aa6c955732e21b82c5fc75979c79a839a) () const |
|size\_t|[**getSize**](classffw_1_1_ring_buffer.md#1a6b08c5903ba906136d1e2dea6174f8a9) () const |
|bool|[**isFull**](classffw_1_1_ring_buffer.md#1afef6976b3007d3b162017fa11c49a95b) () const |
|bool|[**isEmpty**](classffw_1_1_ring_buffer.md#1ac310ea9fe8a1be50525d5b6160647ccc) () const |
|void|[**clear**](classffw_1_1_ring_buffer.md#1a229310f0840e70e03bd639f80f4af8c7) () |
|void|[**reset**](classffw_1_1_ring_buffer.md#1aa2cca36bd9a7cf0cb024c16e1706172d) () |


## Public Functions Documentation

### function <a id="1a1262874544b0287e727afe49b616be56" href="#1a1262874544b0287e727afe49b616be56">RingBuffer</a>

```cpp
ffw::RingBuffer::RingBuffer ()
```



### function <a id="1ad29a030ebc4001c38216914bb5fd8049" href="#1ad29a030ebc4001c38216914bb5fd8049">RingBuffer</a>

```cpp
ffw::RingBuffer::RingBuffer (
    size_t Size
)
```



### function <a id="1a920089172e1534404517fcf805731d8c" href="#1a920089172e1534404517fcf805731d8c">~RingBuffer</a>

```cpp
ffw::RingBuffer::~RingBuffer ()
```



### function <a id="1a6dfe7e8b0ea42e06949b93fd9c33b011" href="#1a6dfe7e8b0ea42e06949b93fd9c33b011">create</a>

```cpp
void ffw::RingBuffer::create (
    size_t Size
)
```



### function <a id="1a6853b78e744af674294418a5cc676a5b" href="#1a6853b78e744af674294418a5cc676a5b">back</a>

```cpp
T * ffw::RingBuffer::back ()
```



### function <a id="1a68fe2a4b580de075ee5fbb71924417c7" href="#1a68fe2a4b580de075ee5fbb71924417c7">push</a>

```cpp
bool ffw::RingBuffer::push (
    const T & Item
)
```



### function <a id="1a843a34f8e404667058efdffb07df6afb" href="#1a843a34f8e404667058efdffb07df6afb">pop</a>

```cpp
bool ffw::RingBuffer::pop (
    T * Item
)
```



### function <a id="1a31ce78e7a74f9aeee6195207f9343cc0" href="#1a31ce78e7a74f9aeee6195207f9343cc0">getRange</a>

```cpp
size_t ffw::RingBuffer::getRange () const
```



### function <a id="1ae676a50e8dce38c1c82a457356f5148f" href="#1ae676a50e8dce38c1c82a457356f5148f">range</a>

```cpp
size_t ffw::RingBuffer::range () const
```



### function <a id="1a4026b573a8dfa5ed9dce5339a667ce81" href="#1a4026b573a8dfa5ed9dce5339a667ce81">getTail</a>

```cpp
size_t ffw::RingBuffer::getTail () const
```



### function <a id="1aa6c955732e21b82c5fc75979c79a839a" href="#1aa6c955732e21b82c5fc75979c79a839a">getHead</a>

```cpp
size_t ffw::RingBuffer::getHead () const
```



### function <a id="1a6b08c5903ba906136d1e2dea6174f8a9" href="#1a6b08c5903ba906136d1e2dea6174f8a9">getSize</a>

```cpp
size_t ffw::RingBuffer::getSize () const
```



### function <a id="1afef6976b3007d3b162017fa11c49a95b" href="#1afef6976b3007d3b162017fa11c49a95b">isFull</a>

```cpp
bool ffw::RingBuffer::isFull () const
```



### function <a id="1ac310ea9fe8a1be50525d5b6160647ccc" href="#1ac310ea9fe8a1be50525d5b6160647ccc">isEmpty</a>

```cpp
bool ffw::RingBuffer::isEmpty () const
```



### function <a id="1a229310f0840e70e03bd639f80f4af8c7" href="#1a229310f0840e70e03bd639f80f4af8c7">clear</a>

```cpp
void ffw::RingBuffer::clear ()
```



### function <a id="1aa2cca36bd9a7cf0cb024c16e1706172d" href="#1aa2cca36bd9a7cf0cb024c16e1706172d">reset</a>

```cpp
void ffw::RingBuffer::reset ()
```





----------------------------------------
The documentation for this class was generated from the following file: `include/ffw/math/ringbuffer.h`
