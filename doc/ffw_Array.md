Array
===================================


The documentation for this class was generated from: `include/ffw/math/var.h`



## Public Types

| Type | Name |
| -------: | :------- |
| typedef std::vector< [Var](ffw_Var.html) > | [Vec](#c08d5335) |
| typedef Vec::allocator_type | [allocator_type](#b0fefb22) |
| typedef Vec::reference | [reference](#1edc8f67) |
| typedef Vec::const_reference | [const_reference](#b98ecfbd) |
| typedef Vec::pointer | [pointer](#3adda637) |
| typedef Vec::const_pointer | [const_pointer](#780180e5) |
| typedef Vec::iterator | [iterator](#e3646655) |
| typedef Vec::const_iterator | [const_iterator](#0cf02f2e) |
| typedef Vec::reverse_iterator | [reverse_iterator](#b8230c53) |
| typedef Vec::const_reverse_iterator | [const_reverse_iterator](#19b4d2eb) |
| typedef Vec::difference_type | [difference_type](#cccce8ae) |
| typedef Vec::size_type | [size_type](#38bb7cf4) |
| typedef Vec::value_type | [value_type](#467a4bb2) |


## Public Functions

| Type | Name |
| -------: | :------- |
|   | [Array](#442049bf) ()  |
|  virtual  | [~Array](#4c4a34a2) ()  |
|   | [Array](#b80b53e0) (const [Var](ffw_Var.html) & _value_)  |
|   | [Array](#9b8d65f7) (const [Array](ffw_Array.html) & _other_)  |
|   | [Array](#dc49b2e4) ([Array](ffw_Array.html) && _other_)  |
|   | [Array](#6e0607a4) (const std::initializer_list< [Var](ffw_Var.html) > & _list_)  |
|  void | [swap](#31b88183) ([Array](ffw_Array.html) & _other_)  |
|  [Array](ffw_Array.html) & | [operator=](#702bf49f) (const [Array](ffw_Array.html) & _other_)  |
|  [Array](ffw_Array.html) & | [operator=](#523bce17) ([Array](ffw_Array.html) && _other_)  |
|  [Array](ffw_Array.html) & | [operator=](#ae4b3e03) (const std::initializer_list< [Var](ffw_Var.html) > & _list_)  |
|  [Var](ffw_Var.html) & | [operator[]](#58408154) ([size_type](ffw_Array.html#38bb7cf4) _n_)  |
|  const [Var](ffw_Var.html) & | [operator[]](#bc70b842) ([size_type](ffw_Array.html#38bb7cf4) _n_) const  |
|  void | [assign](#49491f38) (It _first_, It _last_)  |
|  void | [assign](#cdd874c9) ([size_type](ffw_Array.html#38bb7cf4) _n_, const [Var](ffw_Var.html) & _value_)  |
|  [reference](ffw_Array.html#1edc8f67) | [at](#9f7c70b7) ([size_type](ffw_Array.html#38bb7cf4) _n_)  |
|  [const_reference](ffw_Array.html#b98ecfbd) | [at](#76c27286) ([size_type](ffw_Array.html#38bb7cf4) _n_) const  |
|  [reference](ffw_Array.html#1edc8f67) | [back](#67d72e1f) ()  |
|  [const_reference](ffw_Array.html#b98ecfbd) | [back](#555ad065) () const  |
|  [iterator](ffw_Array.html#e3646655) | [begin](#39bc88bf) ()  |
|  [const_iterator](ffw_Array.html#0cf02f2e) | [begin](#28cc186f) () const  |
|  [size_type](ffw_Array.html#38bb7cf4) | [capacity](#d9a6a78b) () const  |
|  [const_iterator](ffw_Array.html#0cf02f2e) | [cbegin](#4d2dcc42) () const  |
|  [const_iterator](ffw_Array.html#0cf02f2e) | [cend](#f182c131) () const  |
|  void | [clear](#7edc6178) ()  |
|  [const_reverse_iterator](ffw_Array.html#19b4d2eb) | [crbegin](#ff3c7157) () const  |
|  [const_reverse_iterator](ffw_Array.html#19b4d2eb) | [crend](#4c806ac1) () const  |
|  [value_type](ffw_Array.html#467a4bb2) * | [data](#b58f92b4) ()  |
|  const [value_type](ffw_Array.html#467a4bb2) * | [data](#0b2d338f) () const  |
|  bool | [empty](#169cc74b) () const  |
|  [iterator](ffw_Array.html#e3646655) | [end](#d1e4693c) ()  |
|  [const_iterator](ffw_Array.html#0cf02f2e) | [end](#697d48c9) () const  |
|  [iterator](ffw_Array.html#e3646655) | [erase](#106c24f1) ([iterator](ffw_Array.html#e3646655) _position_)  |
|  [iterator](ffw_Array.html#e3646655) | [erase](#1872466c) ([iterator](ffw_Array.html#e3646655) _first_, [iterator](ffw_Array.html#e3646655) _last_)  |
|  [reference](ffw_Array.html#1edc8f67) | [front](#414a5751) ()  |
|  [const_reference](ffw_Array.html#b98ecfbd) | [front](#58374727) () const  |
|  [allocator_type](ffw_Array.html#b0fefb22) | [get_allocator](#584296dd) () const  |
|  [iterator](ffw_Array.html#e3646655) | [insert](#f0cad0a7) ([iterator](ffw_Array.html#e3646655) _position_, const [value_type](ffw_Array.html#467a4bb2) & _val_)  |
|  void | [insert](#50a56cbc) ([iterator](ffw_Array.html#e3646655) _position_, [size_type](ffw_Array.html#38bb7cf4) _n_, const [value_type](ffw_Array.html#467a4bb2) & _val_)  |
|  void | [insert](#504fa722) ([iterator](ffw_Array.html#e3646655) _position_, InputIterator _first_, InputIterator _last_)  |
|  [size_type](ffw_Array.html#38bb7cf4) | [max_size](#3b127ba1) () const  |
|  void | [pop_back](#9551aead) ()  |
|  void | [push_back](#805fb16c) (const [value_type](ffw_Array.html#467a4bb2) & _val_)  |
|  [reverse_iterator](ffw_Array.html#b8230c53) | [rbegin](#049d4560) ()  |
|  [const_reverse_iterator](ffw_Array.html#19b4d2eb) | [rbegin](#90004a15) () const  |
|  [reverse_iterator](ffw_Array.html#b8230c53) | [rend](#319ab648) ()  |
|  [const_reverse_iterator](ffw_Array.html#19b4d2eb) | [rend](#5dba4ba8) () const  |
|  void | [reserve](#66e43035) ([size_type](ffw_Array.html#38bb7cf4) _n_)  |
|  void | [resize](#081a51e2) ([size_type](ffw_Array.html#38bb7cf4) _n_, [value_type](ffw_Array.html#467a4bb2) _val_ = [value_type](ffw_Array.html#467a4bb2)())  |
|  [size_type](ffw_Array.html#38bb7cf4) | [size](#d6795244) () const  |
|  void | [shrink_to_fit](#d847f98b) ()  |
|  bool | [operator==](#c8d4a337) (const [Array](ffw_Array.html) & _other_) const  |
|  bool | [operator!=](#99d4f51a) (const [Array](ffw_Array.html) & _other_) const  |


## Public Types Documentation

### <span style="opacity:0.5;">typedef</span> <a id="c08d5335" href="#c08d5335">Vec</a>

```cpp
std::vector< Var > Vec
```



### <span style="opacity:0.5;">typedef</span> <a id="b0fefb22" href="#b0fefb22">allocator_type</a>

```cpp
Vec::allocator_type allocator_type
```



### <span style="opacity:0.5;">typedef</span> <a id="1edc8f67" href="#1edc8f67">reference</a>

```cpp
Vec::reference reference
```



### <span style="opacity:0.5;">typedef</span> <a id="b98ecfbd" href="#b98ecfbd">const_reference</a>

```cpp
Vec::const_reference const_reference
```



### <span style="opacity:0.5;">typedef</span> <a id="3adda637" href="#3adda637">pointer</a>

```cpp
Vec::pointer pointer
```



### <span style="opacity:0.5;">typedef</span> <a id="780180e5" href="#780180e5">const_pointer</a>

```cpp
Vec::const_pointer const_pointer
```



### <span style="opacity:0.5;">typedef</span> <a id="e3646655" href="#e3646655">iterator</a>

```cpp
Vec::iterator iterator
```



### <span style="opacity:0.5;">typedef</span> <a id="0cf02f2e" href="#0cf02f2e">const_iterator</a>

```cpp
Vec::const_iterator const_iterator
```



### <span style="opacity:0.5;">typedef</span> <a id="b8230c53" href="#b8230c53">reverse_iterator</a>

```cpp
Vec::reverse_iterator reverse_iterator
```



### <span style="opacity:0.5;">typedef</span> <a id="19b4d2eb" href="#19b4d2eb">const_reverse_iterator</a>

```cpp
Vec::const_reverse_iterator const_reverse_iterator
```



### <span style="opacity:0.5;">typedef</span> <a id="cccce8ae" href="#cccce8ae">difference_type</a>

```cpp
Vec::difference_type difference_type
```



### <span style="opacity:0.5;">typedef</span> <a id="38bb7cf4" href="#38bb7cf4">size_type</a>

```cpp
Vec::size_type size_type
```



### <span style="opacity:0.5;">typedef</span> <a id="467a4bb2" href="#467a4bb2">value_type</a>

```cpp
Vec::value_type value_type
```





## Public Functions Documentation

### <span style="opacity:0.5;">function</span> <a id="442049bf" href="#442049bf">Array</a>

```cpp
inline  Array () 
```



### <span style="opacity:0.5;">function</span> <a id="4c4a34a2" href="#4c4a34a2">~Array</a>

```cpp
inline virtual  ~Array () 
```



### <span style="opacity:0.5;">function</span> <a id="b80b53e0" href="#b80b53e0">Array</a>

```cpp
inline  Array (
    const Var & value
) 
```



### <span style="opacity:0.5;">function</span> <a id="9b8d65f7" href="#9b8d65f7">Array</a>

```cpp
inline  Array (
    const Array & other
) 
```



### <span style="opacity:0.5;">function</span> <a id="dc49b2e4" href="#dc49b2e4">Array</a>

```cpp
inline  Array (
    Array && other
) 
```



### <span style="opacity:0.5;">function</span> <a id="6e0607a4" href="#6e0607a4">Array</a>

```cpp
inline  Array (
    const std::initializer_list< Var > & list
) 
```



### <span style="opacity:0.5;">function</span> <a id="31b88183" href="#31b88183">swap</a>

```cpp
inline void swap (
    Array & other
) 
```



### <span style="opacity:0.5;">function</span> <a id="702bf49f" href="#702bf49f">operator=</a>

```cpp
inline Array & operator= (
    const Array & other
) 
```



### <span style="opacity:0.5;">function</span> <a id="523bce17" href="#523bce17">operator=</a>

```cpp
inline Array & operator= (
    Array && other
) 
```



### <span style="opacity:0.5;">function</span> <a id="ae4b3e03" href="#ae4b3e03">operator=</a>

```cpp
inline Array & operator= (
    const std::initializer_list< Var > & list
) 
```



### <span style="opacity:0.5;">function</span> <a id="58408154" href="#58408154">operator[]</a>

```cpp
inline Var & operator[] (
    size_type n
) 
```



### <span style="opacity:0.5;">function</span> <a id="bc70b842" href="#bc70b842">operator[]</a>

```cpp
inline const Var & operator[] (
    size_type n
) const 
```



### <span style="opacity:0.5;">function</span> <a id="49491f38" href="#49491f38">assign</a>

```cpp
inline void assign (
    It first,
    It last
) 
```



### <span style="opacity:0.5;">function</span> <a id="cdd874c9" href="#cdd874c9">assign</a>

```cpp
inline void assign (
    size_type n,
    const Var & value
) 
```



### <span style="opacity:0.5;">function</span> <a id="9f7c70b7" href="#9f7c70b7">at</a>

```cpp
inline reference at (
    size_type n
) 
```



### <span style="opacity:0.5;">function</span> <a id="76c27286" href="#76c27286">at</a>

```cpp
inline const_reference at (
    size_type n
) const 
```



### <span style="opacity:0.5;">function</span> <a id="67d72e1f" href="#67d72e1f">back</a>

```cpp
inline reference back () 
```



### <span style="opacity:0.5;">function</span> <a id="555ad065" href="#555ad065">back</a>

```cpp
inline const_reference back () const 
```



### <span style="opacity:0.5;">function</span> <a id="39bc88bf" href="#39bc88bf">begin</a>

```cpp
inline iterator begin () 
```



### <span style="opacity:0.5;">function</span> <a id="28cc186f" href="#28cc186f">begin</a>

```cpp
inline const_iterator begin () const 
```



### <span style="opacity:0.5;">function</span> <a id="d9a6a78b" href="#d9a6a78b">capacity</a>

```cpp
inline size_type capacity () const 
```



### <span style="opacity:0.5;">function</span> <a id="4d2dcc42" href="#4d2dcc42">cbegin</a>

```cpp
inline const_iterator cbegin () const 
```



### <span style="opacity:0.5;">function</span> <a id="f182c131" href="#f182c131">cend</a>

```cpp
inline const_iterator cend () const 
```



### <span style="opacity:0.5;">function</span> <a id="7edc6178" href="#7edc6178">clear</a>

```cpp
inline void clear () 
```



### <span style="opacity:0.5;">function</span> <a id="ff3c7157" href="#ff3c7157">crbegin</a>

```cpp
inline const_reverse_iterator crbegin () const 
```



### <span style="opacity:0.5;">function</span> <a id="4c806ac1" href="#4c806ac1">crend</a>

```cpp
inline const_reverse_iterator crend () const 
```



### <span style="opacity:0.5;">function</span> <a id="b58f92b4" href="#b58f92b4">data</a>

```cpp
inline value_type * data () 
```



### <span style="opacity:0.5;">function</span> <a id="0b2d338f" href="#0b2d338f">data</a>

```cpp
inline const value_type * data () const 
```



### <span style="opacity:0.5;">function</span> <a id="169cc74b" href="#169cc74b">empty</a>

```cpp
inline bool empty () const 
```



### <span style="opacity:0.5;">function</span> <a id="d1e4693c" href="#d1e4693c">end</a>

```cpp
inline iterator end () 
```



### <span style="opacity:0.5;">function</span> <a id="697d48c9" href="#697d48c9">end</a>

```cpp
inline const_iterator end () const 
```



### <span style="opacity:0.5;">function</span> <a id="106c24f1" href="#106c24f1">erase</a>

```cpp
inline iterator erase (
    iterator position
) 
```



### <span style="opacity:0.5;">function</span> <a id="1872466c" href="#1872466c">erase</a>

```cpp
inline iterator erase (
    iterator first,
    iterator last
) 
```



### <span style="opacity:0.5;">function</span> <a id="414a5751" href="#414a5751">front</a>

```cpp
inline reference front () 
```



### <span style="opacity:0.5;">function</span> <a id="58374727" href="#58374727">front</a>

```cpp
inline const_reference front () const 
```



### <span style="opacity:0.5;">function</span> <a id="584296dd" href="#584296dd">get_allocator</a>

```cpp
inline allocator_type get_allocator () const 
```



### <span style="opacity:0.5;">function</span> <a id="f0cad0a7" href="#f0cad0a7">insert</a>

```cpp
inline iterator insert (
    iterator position,
    const value_type & val
) 
```



### <span style="opacity:0.5;">function</span> <a id="50a56cbc" href="#50a56cbc">insert</a>

```cpp
inline void insert (
    iterator position,
    size_type n,
    const value_type & val
) 
```



### <span style="opacity:0.5;">function</span> <a id="504fa722" href="#504fa722">insert</a>

```cpp
inline void insert (
    iterator position,
    InputIterator first,
    InputIterator last
) 
```



### <span style="opacity:0.5;">function</span> <a id="3b127ba1" href="#3b127ba1">max_size</a>

```cpp
inline size_type max_size () const 
```



### <span style="opacity:0.5;">function</span> <a id="9551aead" href="#9551aead">pop_back</a>

```cpp
inline void pop_back () 
```



### <span style="opacity:0.5;">function</span> <a id="805fb16c" href="#805fb16c">push_back</a>

```cpp
inline void push_back (
    const value_type & val
) 
```



### <span style="opacity:0.5;">function</span> <a id="049d4560" href="#049d4560">rbegin</a>

```cpp
inline reverse_iterator rbegin () 
```



### <span style="opacity:0.5;">function</span> <a id="90004a15" href="#90004a15">rbegin</a>

```cpp
inline const_reverse_iterator rbegin () const 
```



### <span style="opacity:0.5;">function</span> <a id="319ab648" href="#319ab648">rend</a>

```cpp
inline reverse_iterator rend () 
```



### <span style="opacity:0.5;">function</span> <a id="5dba4ba8" href="#5dba4ba8">rend</a>

```cpp
inline const_reverse_iterator rend () const 
```



### <span style="opacity:0.5;">function</span> <a id="66e43035" href="#66e43035">reserve</a>

```cpp
inline void reserve (
    size_type n
) 
```



### <span style="opacity:0.5;">function</span> <a id="081a51e2" href="#081a51e2">resize</a>

```cpp
inline void resize (
    size_type n,
    value_type val = value_type()
) 
```



### <span style="opacity:0.5;">function</span> <a id="d6795244" href="#d6795244">size</a>

```cpp
inline size_type size () const 
```



### <span style="opacity:0.5;">function</span> <a id="d847f98b" href="#d847f98b">shrink_to_fit</a>

```cpp
inline void shrink_to_fit () 
```



### <span style="opacity:0.5;">function</span> <a id="c8d4a337" href="#c8d4a337">operator==</a>

```cpp
inline bool operator== (
    const Array & other
) const 
```



### <span style="opacity:0.5;">function</span> <a id="99d4f51a" href="#99d4f51a">operator!=</a>

```cpp
inline bool operator!= (
    const Array & other
) const 
```





