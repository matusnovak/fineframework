---
search: false
---

# class ffw::Array

## Public Types

|Type|Name|
|-----|-----|
|typedef std::vector< **[Any](classffw_1_1_any.md)** >|[**Vec**](classffw_1_1_array.md#1a24954083b556757b8c4e85865537c38e)|
|typedef Vec::allocator\_type|[**allocator\_type**](classffw_1_1_array.md#1add36641423e2ae6f08bcd2f64b7c4e3f)|
|typedef Vec::reference|[**reference**](classffw_1_1_array.md#1aeec4de346488cbdbc3cc74d7b2844b36)|
|typedef Vec::const\_reference|[**const\_reference**](classffw_1_1_array.md#1a37a0d8a27dd06e6e845ff7abbc715b05)|
|typedef Vec::pointer|[**pointer**](classffw_1_1_array.md#1a2a4a22523cd2ada4a87e4e305400be92)|
|typedef Vec::const\_pointer|[**const\_pointer**](classffw_1_1_array.md#1a97595c3ffb0c6943ebbdacd7ee623b3d)|
|typedef Vec::iterator|[**iterator**](classffw_1_1_array.md#1a6f4b63a8fdf39383c9d278f34d198a8d)|
|typedef Vec::const\_iterator|[**const\_iterator**](classffw_1_1_array.md#1a8e0d18140917f3120757a94e72820f99)|
|typedef Vec::reverse\_iterator|[**reverse\_iterator**](classffw_1_1_array.md#1afa9858b6a1e5b2d37c392d1b9d2834d8)|
|typedef Vec::const\_reverse\_iterator|[**const\_reverse\_iterator**](classffw_1_1_array.md#1a6244b02699e7e2c49987b3d27bf0165f)|
|typedef Vec::difference\_type|[**difference\_type**](classffw_1_1_array.md#1aa433f1a543c6419d2d91a74a22ff4f79)|
|typedef Vec::size\_type|[**size\_type**](classffw_1_1_array.md#1a139c9c53dd6c798fe5e5d2bf2d9fd7f0)|
|typedef Vec::value\_type|[**value\_type**](classffw_1_1_array.md#1a1ca1f45384d933ba7a78984f7596c75d)|


## Public Functions

|Type|Name|
|-----|-----|
||[**Array**](classffw_1_1_array.md#1a1c637f20b46b2b26d3c6eb84ecffc444) () |
|virtual |[**~Array**](classffw_1_1_array.md#1a37f78036892f73b546c099972fa86242) () |
||[**Array**](classffw_1_1_array.md#1a8bd04975315b2eba8e03fe447f3814a9) (const **[Any](classffw_1_1_any.md)** & value) |
||[**Array**](classffw_1_1_array.md#1a8be344b8c0010f7109a618277c636160) (const **[Array](classffw_1_1_array.md)** & other) |
||[**Array**](classffw_1_1_array.md#1a7f16f5b8c9c3b8f980d9d0f3bfa81870) (**[Array](classffw_1_1_array.md)** && other) |
||[**Array**](classffw_1_1_array.md#1a6f08c30d1d6272eeb5b5493f44868917) (const std::initializer\_list< **[Any](classffw_1_1_any.md)** > & list) |
|void|[**swap**](classffw_1_1_array.md#1a548cc26039db3edb983bcfd42ea0e46f) (**[Array](classffw_1_1_array.md)** & other) |
|**[Array](classffw_1_1_array.md)** &|[**operator=**](classffw_1_1_array.md#1acab54064db500077a1b7bf71f6d08d1a) (const **[Array](classffw_1_1_array.md)** & other) |
|**[Array](classffw_1_1_array.md)** &|[**operator=**](classffw_1_1_array.md#1a9a613c9ff365749b0da6a1595ba60360) (**[Array](classffw_1_1_array.md)** && other) |
|**[Array](classffw_1_1_array.md)** &|[**operator=**](classffw_1_1_array.md#1ac946bf10d09295207d9876556ac27f81) (const std::initializer\_list< **[Any](classffw_1_1_any.md)** > & list) |
|**[Any](classffw_1_1_any.md)** &|[**operator[]**](classffw_1_1_array.md#1a9795cf66389516e92e61107cb0f23240) (**[size\_type](classffw_1_1_array.md#1a139c9c53dd6c798fe5e5d2bf2d9fd7f0)** n) |
|const **[Any](classffw_1_1_any.md)** &|[**operator[]**](classffw_1_1_array.md#1a52b0198b8cbfd77cb22b3be064aa7388) (**[size\_type](classffw_1_1_array.md#1a139c9c53dd6c798fe5e5d2bf2d9fd7f0)** n) const |
|void|[**assign**](classffw_1_1_array.md#1a54e480eb6f2d3b0c12faf42a0e970502) (It first, It last) |
|void|[**assign**](classffw_1_1_array.md#1a9180adf9470a10d1f4f71979ddd051fa) (**[size\_type](classffw_1_1_array.md#1a139c9c53dd6c798fe5e5d2bf2d9fd7f0)** n, const **[Any](classffw_1_1_any.md)** & value) |
|**[reference](classffw_1_1_array.md#1aeec4de346488cbdbc3cc74d7b2844b36)**|[**at**](classffw_1_1_array.md#1a68fda07c4d6f5311768623822c6f3624) (**[size\_type](classffw_1_1_array.md#1a139c9c53dd6c798fe5e5d2bf2d9fd7f0)** n) |
|**[const\_reference](classffw_1_1_array.md#1a37a0d8a27dd06e6e845ff7abbc715b05)**|[**at**](classffw_1_1_array.md#1a667934cf0a6bbebf9e3f5d79e8f8eb8a) (**[size\_type](classffw_1_1_array.md#1a139c9c53dd6c798fe5e5d2bf2d9fd7f0)** n) const |
|**[reference](classffw_1_1_array.md#1aeec4de346488cbdbc3cc74d7b2844b36)**|[**back**](classffw_1_1_array.md#1aaab5fdb6110eee37c6fdb57c863e6fd2) () |
|**[const\_reference](classffw_1_1_array.md#1a37a0d8a27dd06e6e845ff7abbc715b05)**|[**back**](classffw_1_1_array.md#1a6389b9680d0e2684ea03479b439575ad) () const |
|**[iterator](classffw_1_1_array.md#1a6f4b63a8fdf39383c9d278f34d198a8d)**|[**begin**](classffw_1_1_array.md#1af81ea6944f97f02a6b53b1c66a13d763) () |
|**[const\_iterator](classffw_1_1_array.md#1a8e0d18140917f3120757a94e72820f99)**|[**begin**](classffw_1_1_array.md#1abfe97e39c1433c135a34de267c0fa3f3) () const |
|**[size\_type](classffw_1_1_array.md#1a139c9c53dd6c798fe5e5d2bf2d9fd7f0)**|[**capacity**](classffw_1_1_array.md#1abe6ae19ffc6e10981cf027ac59f4bdeb) () const |
|**[const\_iterator](classffw_1_1_array.md#1a8e0d18140917f3120757a94e72820f99)**|[**cbegin**](classffw_1_1_array.md#1a804fcbfa119577959c49e503fbb1f7d7) () const |
|**[const\_iterator](classffw_1_1_array.md#1a8e0d18140917f3120757a94e72820f99)**|[**cend**](classffw_1_1_array.md#1aceb8312c93c4b82ce0193dc7f84e3ca2) () const |
|void|[**clear**](classffw_1_1_array.md#1a8b7c8ea800d4a0548678b9e2c5c3e3b9) () |
|**[const\_reverse\_iterator](classffw_1_1_array.md#1a6244b02699e7e2c49987b3d27bf0165f)**|[**crbegin**](classffw_1_1_array.md#1a9f449529d9ee00820e2280d0d680f92a) () const |
|**[const\_reverse\_iterator](classffw_1_1_array.md#1a6244b02699e7e2c49987b3d27bf0165f)**|[**crend**](classffw_1_1_array.md#1aec0700b479de1550ab94a1784b467d1c) () const |
|**[value\_type](classffw_1_1_array.md#1a1ca1f45384d933ba7a78984f7596c75d)** \*|[**data**](classffw_1_1_array.md#1a47bb7b01138b6cdca2fc1bd13748a68a) () |
|const **[value\_type](classffw_1_1_array.md#1a1ca1f45384d933ba7a78984f7596c75d)** \*|[**data**](classffw_1_1_array.md#1ade2bae1575a4a228ae86ff4ec5d3318d) () const |
|bool|[**empty**](classffw_1_1_array.md#1acffe6c8446004a22409c57892f44a65b) () const |
|**[iterator](classffw_1_1_array.md#1a6f4b63a8fdf39383c9d278f34d198a8d)**|[**end**](classffw_1_1_array.md#1a705c71b69da114358b7ee6e4df9eee5f) () |
|**[const\_iterator](classffw_1_1_array.md#1a8e0d18140917f3120757a94e72820f99)**|[**end**](classffw_1_1_array.md#1a17481082d54ab2197d888d0d0cbfea5e) () const |
|**[iterator](classffw_1_1_array.md#1a6f4b63a8fdf39383c9d278f34d198a8d)**|[**erase**](classffw_1_1_array.md#1af5e983d08644a1a33019b636bad6ab7d) (**[iterator](classffw_1_1_array.md#1a6f4b63a8fdf39383c9d278f34d198a8d)** position) |
|**[iterator](classffw_1_1_array.md#1a6f4b63a8fdf39383c9d278f34d198a8d)**|[**erase**](classffw_1_1_array.md#1a62b5e3c25d462f9318b057718aea2e59) (**[iterator](classffw_1_1_array.md#1a6f4b63a8fdf39383c9d278f34d198a8d)** first, **[iterator](classffw_1_1_array.md#1a6f4b63a8fdf39383c9d278f34d198a8d)** last) |
|**[reference](classffw_1_1_array.md#1aeec4de346488cbdbc3cc74d7b2844b36)**|[**front**](classffw_1_1_array.md#1ac51626648949b6c5c028c47c17e180b7) () |
|**[const\_reference](classffw_1_1_array.md#1a37a0d8a27dd06e6e845ff7abbc715b05)**|[**front**](classffw_1_1_array.md#1a951f874d4cad920b63fbf81d1817b9c4) () const |
|**[allocator\_type](classffw_1_1_array.md#1add36641423e2ae6f08bcd2f64b7c4e3f)**|[**get\_allocator**](classffw_1_1_array.md#1af887518e0ac610943efb0f89929d2278) () const |
|**[iterator](classffw_1_1_array.md#1a6f4b63a8fdf39383c9d278f34d198a8d)**|[**insert**](classffw_1_1_array.md#1a358c5868629be6e5795199851e6802ae) (**[iterator](classffw_1_1_array.md#1a6f4b63a8fdf39383c9d278f34d198a8d)** position, const **[value\_type](classffw_1_1_array.md#1a1ca1f45384d933ba7a78984f7596c75d)** & val) |
|void|[**insert**](classffw_1_1_array.md#1a9531bc3184894a16875967f484851684) (**[iterator](classffw_1_1_array.md#1a6f4b63a8fdf39383c9d278f34d198a8d)** position, **[size\_type](classffw_1_1_array.md#1a139c9c53dd6c798fe5e5d2bf2d9fd7f0)** n, const **[value\_type](classffw_1_1_array.md#1a1ca1f45384d933ba7a78984f7596c75d)** & val) |
|void|[**insert**](classffw_1_1_array.md#1a71a92c35d8b26caa25471f2f4eeea75e) (**[iterator](classffw_1_1_array.md#1a6f4b63a8fdf39383c9d278f34d198a8d)** position, InputIterator first, InputIterator last) |
|**[size\_type](classffw_1_1_array.md#1a139c9c53dd6c798fe5e5d2bf2d9fd7f0)**|[**max\_size**](classffw_1_1_array.md#1a46c65be9652cd7f92e516565a50ee36b) () const |
|void|[**pop\_back**](classffw_1_1_array.md#1a907e2837e92f5b496811066a5a262e00) () |
|void|[**push\_back**](classffw_1_1_array.md#1a842a64edf49724a0df96bac74975b4d6) (const **[value\_type](classffw_1_1_array.md#1a1ca1f45384d933ba7a78984f7596c75d)** & val) |
|**[reverse\_iterator](classffw_1_1_array.md#1afa9858b6a1e5b2d37c392d1b9d2834d8)**|[**rbegin**](classffw_1_1_array.md#1a166d4364a1d7a914b295f4539a641b9a) () |
|**[const\_reverse\_iterator](classffw_1_1_array.md#1a6244b02699e7e2c49987b3d27bf0165f)**|[**rbegin**](classffw_1_1_array.md#1a0f79b124c695a6f09d5617b300680ac3) () const |
|**[reverse\_iterator](classffw_1_1_array.md#1afa9858b6a1e5b2d37c392d1b9d2834d8)**|[**rend**](classffw_1_1_array.md#1a21cd94354d67295b626ede84cac9a708) () |
|**[const\_reverse\_iterator](classffw_1_1_array.md#1a6244b02699e7e2c49987b3d27bf0165f)**|[**rend**](classffw_1_1_array.md#1a1d118829efeb83d513f7cbdb1431ba08) () const |
|void|[**reserve**](classffw_1_1_array.md#1a2d99f14c66d6cbe5dbed55fc346a7284) (**[size\_type](classffw_1_1_array.md#1a139c9c53dd6c798fe5e5d2bf2d9fd7f0)** n) |
|void|[**resize**](classffw_1_1_array.md#1aa5fd1c2423718c901ba26073537d885f) (**[size\_type](classffw_1_1_array.md#1a139c9c53dd6c798fe5e5d2bf2d9fd7f0)** n, **[value\_type](classffw_1_1_array.md#1a1ca1f45384d933ba7a78984f7596c75d)** val = **[value\_type](classffw_1_1_array.md#1a1ca1f45384d933ba7a78984f7596c75d)**()) |
|**[size\_type](classffw_1_1_array.md#1a139c9c53dd6c798fe5e5d2bf2d9fd7f0)**|[**size**](classffw_1_1_array.md#1a288e09d5dc162a0c140c6a555a5f709e) () const |
|void|[**shrink\_to\_fit**](classffw_1_1_array.md#1a6710eb4109331ba13e461e54c22ae2bf) () |
|bool|[**operator==**](classffw_1_1_array.md#1ab945c3ae1d317d536f39eb2ee1f96896) (const **[Array](classffw_1_1_array.md)** & other) const |
|bool|[**operator!=**](classffw_1_1_array.md#1ac962399be1da054373030bed92d879d1) (const **[Array](classffw_1_1_array.md)** & other) const |


## Public Types Documentation

### typedef <a id="1a24954083b556757b8c4e85865537c38e" href="#1a24954083b556757b8c4e85865537c38e">Vec</a>

```cpp
typedef std::vector<Any> ffw::Array::Vec;
```



### typedef <a id="1add36641423e2ae6f08bcd2f64b7c4e3f" href="#1add36641423e2ae6f08bcd2f64b7c4e3f">allocator\_type</a>

```cpp
typedef Vec::allocator_type ffw::Array::allocator_type;
```



### typedef <a id="1aeec4de346488cbdbc3cc74d7b2844b36" href="#1aeec4de346488cbdbc3cc74d7b2844b36">reference</a>

```cpp
typedef Vec::reference ffw::Array::reference;
```



### typedef <a id="1a37a0d8a27dd06e6e845ff7abbc715b05" href="#1a37a0d8a27dd06e6e845ff7abbc715b05">const\_reference</a>

```cpp
typedef Vec::const_reference ffw::Array::const_reference;
```



### typedef <a id="1a2a4a22523cd2ada4a87e4e305400be92" href="#1a2a4a22523cd2ada4a87e4e305400be92">pointer</a>

```cpp
typedef Vec::pointer ffw::Array::pointer;
```



### typedef <a id="1a97595c3ffb0c6943ebbdacd7ee623b3d" href="#1a97595c3ffb0c6943ebbdacd7ee623b3d">const\_pointer</a>

```cpp
typedef Vec::const_pointer ffw::Array::const_pointer;
```



### typedef <a id="1a6f4b63a8fdf39383c9d278f34d198a8d" href="#1a6f4b63a8fdf39383c9d278f34d198a8d">iterator</a>

```cpp
typedef Vec::iterator ffw::Array::iterator;
```



### typedef <a id="1a8e0d18140917f3120757a94e72820f99" href="#1a8e0d18140917f3120757a94e72820f99">const\_iterator</a>

```cpp
typedef Vec::const_iterator ffw::Array::const_iterator;
```



### typedef <a id="1afa9858b6a1e5b2d37c392d1b9d2834d8" href="#1afa9858b6a1e5b2d37c392d1b9d2834d8">reverse\_iterator</a>

```cpp
typedef Vec::reverse_iterator ffw::Array::reverse_iterator;
```



### typedef <a id="1a6244b02699e7e2c49987b3d27bf0165f" href="#1a6244b02699e7e2c49987b3d27bf0165f">const\_reverse\_iterator</a>

```cpp
typedef Vec::const_reverse_iterator ffw::Array::const_reverse_iterator;
```



### typedef <a id="1aa433f1a543c6419d2d91a74a22ff4f79" href="#1aa433f1a543c6419d2d91a74a22ff4f79">difference\_type</a>

```cpp
typedef Vec::difference_type ffw::Array::difference_type;
```



### typedef <a id="1a139c9c53dd6c798fe5e5d2bf2d9fd7f0" href="#1a139c9c53dd6c798fe5e5d2bf2d9fd7f0">size\_type</a>

```cpp
typedef Vec::size_type ffw::Array::size_type;
```



### typedef <a id="1a1ca1f45384d933ba7a78984f7596c75d" href="#1a1ca1f45384d933ba7a78984f7596c75d">value\_type</a>

```cpp
typedef Vec::value_type ffw::Array::value_type;
```



## Public Functions Documentation

### function <a id="1a1c637f20b46b2b26d3c6eb84ecffc444" href="#1a1c637f20b46b2b26d3c6eb84ecffc444">Array</a>

```cpp
ffw::Array::Array ()
```



### function <a id="1a37f78036892f73b546c099972fa86242" href="#1a37f78036892f73b546c099972fa86242">~Array</a>

```cpp
virtual ffw::Array::~Array ()
```



### function <a id="1a8bd04975315b2eba8e03fe447f3814a9" href="#1a8bd04975315b2eba8e03fe447f3814a9">Array</a>

```cpp
ffw::Array::Array (
    const Any & value
)
```



### function <a id="1a8be344b8c0010f7109a618277c636160" href="#1a8be344b8c0010f7109a618277c636160">Array</a>

```cpp
ffw::Array::Array (
    const Array & other
)
```



### function <a id="1a7f16f5b8c9c3b8f980d9d0f3bfa81870" href="#1a7f16f5b8c9c3b8f980d9d0f3bfa81870">Array</a>

```cpp
ffw::Array::Array (
    Array && other
)
```



### function <a id="1a6f08c30d1d6272eeb5b5493f44868917" href="#1a6f08c30d1d6272eeb5b5493f44868917">Array</a>

```cpp
ffw::Array::Array (
    const std::initializer_list< Any > & list
)
```



### function <a id="1a548cc26039db3edb983bcfd42ea0e46f" href="#1a548cc26039db3edb983bcfd42ea0e46f">swap</a>

```cpp
void ffw::Array::swap (
    Array & other
)
```



### function <a id="1acab54064db500077a1b7bf71f6d08d1a" href="#1acab54064db500077a1b7bf71f6d08d1a">operator=</a>

```cpp
Array & ffw::Array::operator= (
    const Array & other
)
```



### function <a id="1a9a613c9ff365749b0da6a1595ba60360" href="#1a9a613c9ff365749b0da6a1595ba60360">operator=</a>

```cpp
Array & ffw::Array::operator= (
    Array && other
)
```



### function <a id="1ac946bf10d09295207d9876556ac27f81" href="#1ac946bf10d09295207d9876556ac27f81">operator=</a>

```cpp
Array & ffw::Array::operator= (
    const std::initializer_list< Any > & list
)
```



### function <a id="1a9795cf66389516e92e61107cb0f23240" href="#1a9795cf66389516e92e61107cb0f23240">operator[]</a>

```cpp
Any & ffw::Array::operator[] (
    size_type n
)
```



### function <a id="1a52b0198b8cbfd77cb22b3be064aa7388" href="#1a52b0198b8cbfd77cb22b3be064aa7388">operator[]</a>

```cpp
const Any & ffw::Array::operator[] (
    size_type n
) const
```



### function <a id="1a54e480eb6f2d3b0c12faf42a0e970502" href="#1a54e480eb6f2d3b0c12faf42a0e970502">assign</a>

```cpp
void ffw::Array::assign (
    It first,
    It last
)
```



### function <a id="1a9180adf9470a10d1f4f71979ddd051fa" href="#1a9180adf9470a10d1f4f71979ddd051fa">assign</a>

```cpp
void ffw::Array::assign (
    size_type n,
    const Any & value
)
```



### function <a id="1a68fda07c4d6f5311768623822c6f3624" href="#1a68fda07c4d6f5311768623822c6f3624">at</a>

```cpp
reference ffw::Array::at (
    size_type n
)
```



### function <a id="1a667934cf0a6bbebf9e3f5d79e8f8eb8a" href="#1a667934cf0a6bbebf9e3f5d79e8f8eb8a">at</a>

```cpp
const_reference ffw::Array::at (
    size_type n
) const
```



### function <a id="1aaab5fdb6110eee37c6fdb57c863e6fd2" href="#1aaab5fdb6110eee37c6fdb57c863e6fd2">back</a>

```cpp
reference ffw::Array::back ()
```



### function <a id="1a6389b9680d0e2684ea03479b439575ad" href="#1a6389b9680d0e2684ea03479b439575ad">back</a>

```cpp
const_reference ffw::Array::back () const
```



### function <a id="1af81ea6944f97f02a6b53b1c66a13d763" href="#1af81ea6944f97f02a6b53b1c66a13d763">begin</a>

```cpp
iterator ffw::Array::begin ()
```



### function <a id="1abfe97e39c1433c135a34de267c0fa3f3" href="#1abfe97e39c1433c135a34de267c0fa3f3">begin</a>

```cpp
const_iterator ffw::Array::begin () const
```



### function <a id="1abe6ae19ffc6e10981cf027ac59f4bdeb" href="#1abe6ae19ffc6e10981cf027ac59f4bdeb">capacity</a>

```cpp
size_type ffw::Array::capacity () const
```



### function <a id="1a804fcbfa119577959c49e503fbb1f7d7" href="#1a804fcbfa119577959c49e503fbb1f7d7">cbegin</a>

```cpp
const_iterator ffw::Array::cbegin () const
```



### function <a id="1aceb8312c93c4b82ce0193dc7f84e3ca2" href="#1aceb8312c93c4b82ce0193dc7f84e3ca2">cend</a>

```cpp
const_iterator ffw::Array::cend () const
```



### function <a id="1a8b7c8ea800d4a0548678b9e2c5c3e3b9" href="#1a8b7c8ea800d4a0548678b9e2c5c3e3b9">clear</a>

```cpp
void ffw::Array::clear ()
```



### function <a id="1a9f449529d9ee00820e2280d0d680f92a" href="#1a9f449529d9ee00820e2280d0d680f92a">crbegin</a>

```cpp
const_reverse_iterator ffw::Array::crbegin () const
```



### function <a id="1aec0700b479de1550ab94a1784b467d1c" href="#1aec0700b479de1550ab94a1784b467d1c">crend</a>

```cpp
const_reverse_iterator ffw::Array::crend () const
```



### function <a id="1a47bb7b01138b6cdca2fc1bd13748a68a" href="#1a47bb7b01138b6cdca2fc1bd13748a68a">data</a>

```cpp
value_type * ffw::Array::data ()
```



### function <a id="1ade2bae1575a4a228ae86ff4ec5d3318d" href="#1ade2bae1575a4a228ae86ff4ec5d3318d">data</a>

```cpp
const value_type * ffw::Array::data () const
```



### function <a id="1acffe6c8446004a22409c57892f44a65b" href="#1acffe6c8446004a22409c57892f44a65b">empty</a>

```cpp
bool ffw::Array::empty () const
```



### function <a id="1a705c71b69da114358b7ee6e4df9eee5f" href="#1a705c71b69da114358b7ee6e4df9eee5f">end</a>

```cpp
iterator ffw::Array::end ()
```



### function <a id="1a17481082d54ab2197d888d0d0cbfea5e" href="#1a17481082d54ab2197d888d0d0cbfea5e">end</a>

```cpp
const_iterator ffw::Array::end () const
```



### function <a id="1af5e983d08644a1a33019b636bad6ab7d" href="#1af5e983d08644a1a33019b636bad6ab7d">erase</a>

```cpp
iterator ffw::Array::erase (
    iterator position
)
```



### function <a id="1a62b5e3c25d462f9318b057718aea2e59" href="#1a62b5e3c25d462f9318b057718aea2e59">erase</a>

```cpp
iterator ffw::Array::erase (
    iterator first,
    iterator last
)
```



### function <a id="1ac51626648949b6c5c028c47c17e180b7" href="#1ac51626648949b6c5c028c47c17e180b7">front</a>

```cpp
reference ffw::Array::front ()
```



### function <a id="1a951f874d4cad920b63fbf81d1817b9c4" href="#1a951f874d4cad920b63fbf81d1817b9c4">front</a>

```cpp
const_reference ffw::Array::front () const
```



### function <a id="1af887518e0ac610943efb0f89929d2278" href="#1af887518e0ac610943efb0f89929d2278">get\_allocator</a>

```cpp
allocator_type ffw::Array::get_allocator () const
```



### function <a id="1a358c5868629be6e5795199851e6802ae" href="#1a358c5868629be6e5795199851e6802ae">insert</a>

```cpp
iterator ffw::Array::insert (
    iterator position,
    const value_type & val
)
```



### function <a id="1a9531bc3184894a16875967f484851684" href="#1a9531bc3184894a16875967f484851684">insert</a>

```cpp
void ffw::Array::insert (
    iterator position,
    size_type n,
    const value_type & val
)
```



### function <a id="1a71a92c35d8b26caa25471f2f4eeea75e" href="#1a71a92c35d8b26caa25471f2f4eeea75e">insert</a>

```cpp
void ffw::Array::insert (
    iterator position,
    InputIterator first,
    InputIterator last
)
```



### function <a id="1a46c65be9652cd7f92e516565a50ee36b" href="#1a46c65be9652cd7f92e516565a50ee36b">max\_size</a>

```cpp
size_type ffw::Array::max_size () const
```



### function <a id="1a907e2837e92f5b496811066a5a262e00" href="#1a907e2837e92f5b496811066a5a262e00">pop\_back</a>

```cpp
void ffw::Array::pop_back ()
```



### function <a id="1a842a64edf49724a0df96bac74975b4d6" href="#1a842a64edf49724a0df96bac74975b4d6">push\_back</a>

```cpp
void ffw::Array::push_back (
    const value_type & val
)
```



### function <a id="1a166d4364a1d7a914b295f4539a641b9a" href="#1a166d4364a1d7a914b295f4539a641b9a">rbegin</a>

```cpp
reverse_iterator ffw::Array::rbegin ()
```



### function <a id="1a0f79b124c695a6f09d5617b300680ac3" href="#1a0f79b124c695a6f09d5617b300680ac3">rbegin</a>

```cpp
const_reverse_iterator ffw::Array::rbegin () const
```



### function <a id="1a21cd94354d67295b626ede84cac9a708" href="#1a21cd94354d67295b626ede84cac9a708">rend</a>

```cpp
reverse_iterator ffw::Array::rend ()
```



### function <a id="1a1d118829efeb83d513f7cbdb1431ba08" href="#1a1d118829efeb83d513f7cbdb1431ba08">rend</a>

```cpp
const_reverse_iterator ffw::Array::rend () const
```



### function <a id="1a2d99f14c66d6cbe5dbed55fc346a7284" href="#1a2d99f14c66d6cbe5dbed55fc346a7284">reserve</a>

```cpp
void ffw::Array::reserve (
    size_type n
)
```



### function <a id="1aa5fd1c2423718c901ba26073537d885f" href="#1aa5fd1c2423718c901ba26073537d885f">resize</a>

```cpp
void ffw::Array::resize (
    size_type n,
    value_type val = value_type()
)
```



### function <a id="1a288e09d5dc162a0c140c6a555a5f709e" href="#1a288e09d5dc162a0c140c6a555a5f709e">size</a>

```cpp
size_type ffw::Array::size () const
```



### function <a id="1a6710eb4109331ba13e461e54c22ae2bf" href="#1a6710eb4109331ba13e461e54c22ae2bf">shrink\_to\_fit</a>

```cpp
void ffw::Array::shrink_to_fit ()
```



### function <a id="1ab945c3ae1d317d536f39eb2ee1f96896" href="#1ab945c3ae1d317d536f39eb2ee1f96896">operator==</a>

```cpp
bool ffw::Array::operator== (
    const Array & other
) const
```



### function <a id="1ac962399be1da054373030bed92d879d1" href="#1ac962399be1da054373030bed92d879d1">operator!=</a>

```cpp
bool ffw::Array::operator!= (
    const Array & other
) const
```





----------------------------------------
The documentation for this class was generated from the following file: `include/ffw/math/any.h`
