Object
===================================


The documentation for this class was generated from: `include/ffw/math/any.h`



## Public Types

| Type | Name |
| -------: | :------- |
| typedef std::unordered_map< std::string, [Any](ffw_Any.html) > | [Map](#ed696246) |
| typedef Map::allocator_type | [allocator_type](#2ee589c5) |
| typedef Map::reference | [reference](#f7fca37f) |
| typedef Map::const_reference | [const_reference](#a045426f) |
| typedef Map::pointer | [pointer](#9cec6a93) |
| typedef Map::const_pointer | [const_pointer](#f87e02fe) |
| typedef Map::iterator | [iterator](#cf3ec96f) |
| typedef Map::const_iterator | [const_iterator](#3ca81679) |
| typedef Map::difference_type | [difference_type](#e5988ec0) |
| typedef Map::size_type | [size_type](#48591874) |
| typedef Map::key_type | [key_type](#34ccb6a3) |
| typedef Map::local_iterator | [local_iterator](#37e2ab96) |
| typedef Map::const_local_iterator | [const_local_iterator](#680b2d9c) |
| typedef Map::mapped_type | [mapped_type](#0ed80e48) |
| typedef Map::hasher | [hasher](#05f6ac9d) |
| typedef Map::value_type | [value_type](#def01581) |
| typedef Map::key_equal | [key_equal](#f5bbae9d) |


## Public Functions

| Type | Name |
| -------: | :------- |
|   | [Object](#90c193cc) ()  |
|  virtual  | [~Object](#2cdf4fed) ()  |
|   | [Object](#d15ef8f0) (const std::string & _key_, const [Any](ffw_Any.html) & _value_)  |
|   | [Object](#dfd5cecb) (const [Object](ffw_Object.html) & _other_)  |
|   | [Object](#45fb540b) ([Object](ffw_Object.html) && _other_)  |
|   | [Object](#9a42f51b) (const std::initializer_list< std::pair< std::string, [Any](ffw_Any.html) >> & _list_)  |
|  bool | [exists](#1906a38b) (const std::string & _key_) const  |
|  bool | [contains](#4ebd9a37) (const std::string & _key_) const  |
|  bool | [has_key](#49739af4) (const std::string & _key_) const  |
|  void | [swap](#490bed7d) ([Object](ffw_Object.html) & _other_)  |
|  [Object](ffw_Object.html) & | [operator=](#72be0bf6) (const [Object](ffw_Object.html) & _other_)  |
|  [Object](ffw_Object.html) & | [operator=](#45b31fd6) ([Object](ffw_Object.html) && _other_)  |
|  [Object](ffw_Object.html) & | [operator=](#c6f443d3) (const std::initializer_list< std::pair< std::string, [Any](ffw_Any.html) >> & _list_)  |
|  std::pair< [iterator](ffw_Object.html#cf3ec96f), bool > | [insert](#47f2a9bf) (const std::string & _key_, const [Any](ffw_Any.html) & _value_)  |
|  [Any](ffw_Any.html) & | [operator[]](#055a9716) (const [key_type](ffw_Object.html#34ccb6a3) & _key_)  |
|  const [Any](ffw_Any.html) & | [operator[]](#0ce5be20) (const [key_type](ffw_Object.html#34ccb6a3) & _key_) const  |
|  [mapped_type](ffw_Object.html#0ed80e48) & | [at](#a7ec28a3) (const [key_type](ffw_Object.html#34ccb6a3) & _key_)  |
|  const [mapped_type](ffw_Object.html#0ed80e48) & | [at](#2d5309e7) (const [key_type](ffw_Object.html#34ccb6a3) & _key_) const  |
|  [iterator](ffw_Object.html#cf3ec96f) | [begin](#6c60bd73) ()  |
|  [const_iterator](ffw_Object.html#3ca81679) | [begin](#84e92d54) () const  |
|  [local_iterator](ffw_Object.html#37e2ab96) | [begin](#681481fa) ([size_type](ffw_Object.html#48591874) _n_)  |
|  [const_local_iterator](ffw_Object.html#680b2d9c) | [begin](#ff95de74) ([size_type](ffw_Object.html#48591874) _n_) const  |
|  [size_type](ffw_Object.html#48591874) | [bucket](#c4a4cbf2) (const [key_type](ffw_Object.html#34ccb6a3) & _k_) const  |
|  [size_type](ffw_Object.html#48591874) | [bucket_count](#f678305a) () const  |
|  [size_type](ffw_Object.html#48591874) | [bucket_size](#09c09a29) ([size_type](ffw_Object.html#48591874) _n_) const  |
|  [const_iterator](ffw_Object.html#3ca81679) | [cbegin](#c067fdd0) () const  |
|  [const_local_iterator](ffw_Object.html#680b2d9c) | [cbegin](#992cc836) ([size_type](ffw_Object.html#48591874) _n_) const  |
|  [const_iterator](ffw_Object.html#3ca81679) | [cend](#89905fd6) () const  |
|  [const_local_iterator](ffw_Object.html#680b2d9c) | [cend](#f2c04d11) ([size_type](ffw_Object.html#48591874) _n_) const  |
|  void | [clear](#86e06a82) ()  |
|  [size_type](ffw_Object.html#48591874) | [count](#0ede0481) (const [key_type](ffw_Object.html#34ccb6a3) & _key_) const  |
|  bool | [empty](#ac7b4816) () const  |
|  [iterator](ffw_Object.html#cf3ec96f) | [end](#d52744c5) ()  |
|  [const_iterator](ffw_Object.html#3ca81679) | [end](#fd0fb47b) () const  |
|  [local_iterator](ffw_Object.html#37e2ab96) | [end](#b9651f98) ([size_type](ffw_Object.html#48591874) _n_)  |
|  [const_local_iterator](ffw_Object.html#680b2d9c) | [end](#8de3859c) ([size_type](ffw_Object.html#48591874) _n_) const  |
|  std::pair< [iterator](ffw_Object.html#cf3ec96f), [iterator](ffw_Object.html#cf3ec96f) > | [equal_range](#607ed7d7) (const [key_type](ffw_Object.html#34ccb6a3) & _k_)  |
|  std::pair< [const_iterator](ffw_Object.html#3ca81679), [const_iterator](ffw_Object.html#3ca81679) > | [equal_range](#b749bdfd) (const [key_type](ffw_Object.html#34ccb6a3) & _k_) const  |
|  [iterator](ffw_Object.html#cf3ec96f) | [erase](#c4f040e7) ([const_iterator](ffw_Object.html#3ca81679) _position_)  |
|  [size_type](ffw_Object.html#48591874) | [erase](#6e7d335c) (const [key_type](ffw_Object.html#34ccb6a3) & _value_)  |
|  [iterator](ffw_Object.html#cf3ec96f) | [erase](#38971d86) ([const_iterator](ffw_Object.html#3ca81679) _first_, [const_iterator](ffw_Object.html#3ca81679) _last_)  |
|  [iterator](ffw_Object.html#cf3ec96f) | [find](#90c338c1) (const [key_type](ffw_Object.html#34ccb6a3) & _key_)  |
|  [const_iterator](ffw_Object.html#3ca81679) | [find](#b57c6067) (const [key_type](ffw_Object.html#34ccb6a3) & _key_) const  |
|  [allocator_type](ffw_Object.html#2ee589c5) | [get_allocator](#5c4b1472) () const  |
|  [hasher](ffw_Object.html#05f6ac9d) | [hash_function](#c32d5e59) () const  |
|  std::pair< [iterator](ffw_Object.html#cf3ec96f), bool > | [insert](#38e93750) (const [value_type](ffw_Object.html#def01581) & _val_)  |
|  std::pair< [iterator](ffw_Object.html#cf3ec96f), bool > | [insert](#ff6d97a4) (P && _val_)  |
|  [iterator](ffw_Object.html#cf3ec96f) | [insert](#1af5a9d6) ([const_iterator](ffw_Object.html#3ca81679) _hint_, const [value_type](ffw_Object.html#def01581) & _val_)  |
|  [iterator](ffw_Object.html#cf3ec96f) | [insert](#e4861053) ([const_iterator](ffw_Object.html#3ca81679) _hint_, P && _val_)  |
|  void | [insert](#c7d8f766) (InputIterator _first_, InputIterator _last_)  |
|  void | [insert](#a4cdf65f) (std::initializer_list< [value_type](ffw_Object.html#def01581) > _il_)  |
|  [key_equal](ffw_Object.html#f5bbae9d) | [key_eq](#205d79a8) () const  |
|  float | [load_factor](#4cbad9a7) () const  |
|  [size_type](ffw_Object.html#48591874) | [max_bucket_count](#ad3d5e68) () const  |
|  float | [max_load_factor](#40e2d546) () const  |
|  void | [max_load_factor](#ee1b5afe) (float _z_)  |
|  [size_type](ffw_Object.html#48591874) | [max_size](#5a354d4a) () const  |
|  void | [rehash](#8c4c31c3) ([size_type](ffw_Object.html#48591874) _n_)  |
|  void | [reserve](#d4c27876) ([size_type](ffw_Object.html#48591874) _n_)  |
|  [size_type](ffw_Object.html#48591874) | [size](#e5a512b4) () const  |
|  bool | [operator==](#a56ad5b7) (const [Object](ffw_Object.html) & _other_) const  |
|  bool | [operator!=](#9ed29126) (const [Object](ffw_Object.html) & _other_) const  |


## Public Types Documentation

### _typedef_ <a id="ed696246" href="#ed696246">Map</a>

```cpp
std::unordered_map< std::string, Any > Map
```



### _typedef_ <a id="2ee589c5" href="#2ee589c5">allocator_type</a>

```cpp
Map::allocator_type allocator_type
```



### _typedef_ <a id="f7fca37f" href="#f7fca37f">reference</a>

```cpp
Map::reference reference
```



### _typedef_ <a id="a045426f" href="#a045426f">const_reference</a>

```cpp
Map::const_reference const_reference
```



### _typedef_ <a id="9cec6a93" href="#9cec6a93">pointer</a>

```cpp
Map::pointer pointer
```



### _typedef_ <a id="f87e02fe" href="#f87e02fe">const_pointer</a>

```cpp
Map::const_pointer const_pointer
```



### _typedef_ <a id="cf3ec96f" href="#cf3ec96f">iterator</a>

```cpp
Map::iterator iterator
```



### _typedef_ <a id="3ca81679" href="#3ca81679">const_iterator</a>

```cpp
Map::const_iterator const_iterator
```



### _typedef_ <a id="e5988ec0" href="#e5988ec0">difference_type</a>

```cpp
Map::difference_type difference_type
```



### _typedef_ <a id="48591874" href="#48591874">size_type</a>

```cpp
Map::size_type size_type
```



### _typedef_ <a id="34ccb6a3" href="#34ccb6a3">key_type</a>

```cpp
Map::key_type key_type
```



### _typedef_ <a id="37e2ab96" href="#37e2ab96">local_iterator</a>

```cpp
Map::local_iterator local_iterator
```



### _typedef_ <a id="680b2d9c" href="#680b2d9c">const_local_iterator</a>

```cpp
Map::const_local_iterator const_local_iterator
```



### _typedef_ <a id="0ed80e48" href="#0ed80e48">mapped_type</a>

```cpp
Map::mapped_type mapped_type
```



### _typedef_ <a id="05f6ac9d" href="#05f6ac9d">hasher</a>

```cpp
Map::hasher hasher
```



### _typedef_ <a id="def01581" href="#def01581">value_type</a>

```cpp
Map::value_type value_type
```



### _typedef_ <a id="f5bbae9d" href="#f5bbae9d">key_equal</a>

```cpp
Map::key_equal key_equal
```





## Public Functions Documentation

### _function_ <a id="90c193cc" href="#90c193cc">Object</a>

```cpp
inline  Object () 
```



### _function_ <a id="2cdf4fed" href="#2cdf4fed">~Object</a>

```cpp
inline virtual  ~Object () 
```



### _function_ <a id="d15ef8f0" href="#d15ef8f0">Object</a>

```cpp
inline  Object (
    const std::string & key,
    const Any & value
) 
```



### _function_ <a id="dfd5cecb" href="#dfd5cecb">Object</a>

```cpp
inline  Object (
    const Object & other
) 
```



### _function_ <a id="45fb540b" href="#45fb540b">Object</a>

```cpp
inline  Object (
    Object && other
) 
```



### _function_ <a id="9a42f51b" href="#9a42f51b">Object</a>

```cpp
inline  Object (
    const std::initializer_list< std::pair< std::string, Any >> & list
) 
```



### _function_ <a id="1906a38b" href="#1906a38b">exists</a>

```cpp
inline bool exists (
    const std::string & key
) const 
```



### _function_ <a id="4ebd9a37" href="#4ebd9a37">contains</a>

```cpp
inline bool contains (
    const std::string & key
) const 
```



### _function_ <a id="49739af4" href="#49739af4">has_key</a>

```cpp
inline bool has_key (
    const std::string & key
) const 
```



### _function_ <a id="490bed7d" href="#490bed7d">swap</a>

```cpp
inline void swap (
    Object & other
) 
```



### _function_ <a id="72be0bf6" href="#72be0bf6">operator=</a>

```cpp
inline Object & operator= (
    const Object & other
) 
```



### _function_ <a id="45b31fd6" href="#45b31fd6">operator=</a>

```cpp
inline Object & operator= (
    Object && other
) 
```



### _function_ <a id="c6f443d3" href="#c6f443d3">operator=</a>

```cpp
inline Object & operator= (
    const std::initializer_list< std::pair< std::string, Any >> & list
) 
```



### _function_ <a id="47f2a9bf" href="#47f2a9bf">insert</a>

```cpp
inline std::pair< iterator, bool > insert (
    const std::string & key,
    const Any & value
) 
```



### _function_ <a id="055a9716" href="#055a9716">operator[]</a>

```cpp
inline Any & operator[] (
    const key_type & key
) 
```



### _function_ <a id="0ce5be20" href="#0ce5be20">operator[]</a>

```cpp
inline const Any & operator[] (
    const key_type & key
) const 
```



### _function_ <a id="a7ec28a3" href="#a7ec28a3">at</a>

```cpp
inline mapped_type & at (
    const key_type & key
) 
```



### _function_ <a id="2d5309e7" href="#2d5309e7">at</a>

```cpp
inline const mapped_type & at (
    const key_type & key
) const 
```



### _function_ <a id="6c60bd73" href="#6c60bd73">begin</a>

```cpp
inline iterator begin () 
```



### _function_ <a id="84e92d54" href="#84e92d54">begin</a>

```cpp
inline const_iterator begin () const 
```



### _function_ <a id="681481fa" href="#681481fa">begin</a>

```cpp
inline local_iterator begin (
    size_type n
) 
```



### _function_ <a id="ff95de74" href="#ff95de74">begin</a>

```cpp
inline const_local_iterator begin (
    size_type n
) const 
```



### _function_ <a id="c4a4cbf2" href="#c4a4cbf2">bucket</a>

```cpp
inline size_type bucket (
    const key_type & k
) const 
```



### _function_ <a id="f678305a" href="#f678305a">bucket_count</a>

```cpp
inline size_type bucket_count () const 
```



### _function_ <a id="09c09a29" href="#09c09a29">bucket_size</a>

```cpp
inline size_type bucket_size (
    size_type n
) const 
```



### _function_ <a id="c067fdd0" href="#c067fdd0">cbegin</a>

```cpp
inline const_iterator cbegin () const 
```



### _function_ <a id="992cc836" href="#992cc836">cbegin</a>

```cpp
inline const_local_iterator cbegin (
    size_type n
) const 
```



### _function_ <a id="89905fd6" href="#89905fd6">cend</a>

```cpp
inline const_iterator cend () const 
```



### _function_ <a id="f2c04d11" href="#f2c04d11">cend</a>

```cpp
inline const_local_iterator cend (
    size_type n
) const 
```



### _function_ <a id="86e06a82" href="#86e06a82">clear</a>

```cpp
inline void clear () 
```



### _function_ <a id="0ede0481" href="#0ede0481">count</a>

```cpp
inline size_type count (
    const key_type & key
) const 
```



### _function_ <a id="ac7b4816" href="#ac7b4816">empty</a>

```cpp
inline bool empty () const 
```



### _function_ <a id="d52744c5" href="#d52744c5">end</a>

```cpp
inline iterator end () 
```



### _function_ <a id="fd0fb47b" href="#fd0fb47b">end</a>

```cpp
inline const_iterator end () const 
```



### _function_ <a id="b9651f98" href="#b9651f98">end</a>

```cpp
inline local_iterator end (
    size_type n
) 
```



### _function_ <a id="8de3859c" href="#8de3859c">end</a>

```cpp
inline const_local_iterator end (
    size_type n
) const 
```



### _function_ <a id="607ed7d7" href="#607ed7d7">equal_range</a>

```cpp
inline std::pair< iterator, iterator > equal_range (
    const key_type & k
) 
```



### _function_ <a id="b749bdfd" href="#b749bdfd">equal_range</a>

```cpp
inline std::pair< const_iterator, const_iterator > equal_range (
    const key_type & k
) const 
```



### _function_ <a id="c4f040e7" href="#c4f040e7">erase</a>

```cpp
inline iterator erase (
    const_iterator position
) 
```



### _function_ <a id="6e7d335c" href="#6e7d335c">erase</a>

```cpp
inline size_type erase (
    const key_type & value
) 
```



### _function_ <a id="38971d86" href="#38971d86">erase</a>

```cpp
inline iterator erase (
    const_iterator first,
    const_iterator last
) 
```



### _function_ <a id="90c338c1" href="#90c338c1">find</a>

```cpp
inline iterator find (
    const key_type & key
) 
```



### _function_ <a id="b57c6067" href="#b57c6067">find</a>

```cpp
inline const_iterator find (
    const key_type & key
) const 
```



### _function_ <a id="5c4b1472" href="#5c4b1472">get_allocator</a>

```cpp
inline allocator_type get_allocator () const 
```



### _function_ <a id="c32d5e59" href="#c32d5e59">hash_function</a>

```cpp
inline hasher hash_function () const 
```



### _function_ <a id="38e93750" href="#38e93750">insert</a>

```cpp
inline std::pair< iterator, bool > insert (
    const value_type & val
) 
```



### _function_ <a id="ff6d97a4" href="#ff6d97a4">insert</a>

```cpp
inline std::pair< iterator, bool > insert (
    P && val
) 
```



### _function_ <a id="1af5a9d6" href="#1af5a9d6">insert</a>

```cpp
inline iterator insert (
    const_iterator hint,
    const value_type & val
) 
```



### _function_ <a id="e4861053" href="#e4861053">insert</a>

```cpp
inline iterator insert (
    const_iterator hint,
    P && val
) 
```



### _function_ <a id="c7d8f766" href="#c7d8f766">insert</a>

```cpp
inline void insert (
    InputIterator first,
    InputIterator last
) 
```



### _function_ <a id="a4cdf65f" href="#a4cdf65f">insert</a>

```cpp
inline void insert (
    std::initializer_list< value_type > il
) 
```



### _function_ <a id="205d79a8" href="#205d79a8">key_eq</a>

```cpp
inline key_equal key_eq () const 
```



### _function_ <a id="4cbad9a7" href="#4cbad9a7">load_factor</a>

```cpp
inline float load_factor () const 
```



### _function_ <a id="ad3d5e68" href="#ad3d5e68">max_bucket_count</a>

```cpp
inline size_type max_bucket_count () const 
```



### _function_ <a id="40e2d546" href="#40e2d546">max_load_factor</a>

```cpp
inline float max_load_factor () const 
```



### _function_ <a id="ee1b5afe" href="#ee1b5afe">max_load_factor</a>

```cpp
inline void max_load_factor (
    float z
) 
```



### _function_ <a id="5a354d4a" href="#5a354d4a">max_size</a>

```cpp
inline size_type max_size () const 
```



### _function_ <a id="8c4c31c3" href="#8c4c31c3">rehash</a>

```cpp
inline void rehash (
    size_type n
) 
```



### _function_ <a id="d4c27876" href="#d4c27876">reserve</a>

```cpp
inline void reserve (
    size_type n
) 
```



### _function_ <a id="e5a512b4" href="#e5a512b4">size</a>

```cpp
inline size_type size () const 
```



### _function_ <a id="a56ad5b7" href="#a56ad5b7">operator==</a>

```cpp
inline bool operator== (
    const Object & other
) const 
```



### _function_ <a id="9ed29126" href="#9ed29126">operator!=</a>

```cpp
inline bool operator!= (
    const Object & other
) const 
```





