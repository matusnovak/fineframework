---
search: false
---

# class ffw::Object

## Public Types

|Type|Name|
|-----|-----|
|typedef std::unordered\_map< std::string, **[Any](classffw_1_1_any.md)** >|[**Map**](classffw_1_1_object.md#1a93137a549bad3b1c007db4a4f5921f75)|
|typedef Map::allocator\_type|[**allocator\_type**](classffw_1_1_object.md#1af09729ed810f38c67296fd1daf40c1e4)|
|typedef Map::reference|[**reference**](classffw_1_1_object.md#1ab03501d3379ff363d3a8b1a2b4330a68)|
|typedef Map::const\_reference|[**const\_reference**](classffw_1_1_object.md#1ab3b20e8c0b70a8b8b15307e13a20f078)|
|typedef Map::pointer|[**pointer**](classffw_1_1_object.md#1a11a94d2786a97da4816dc96b93fdf208)|
|typedef Map::const\_pointer|[**const\_pointer**](classffw_1_1_object.md#1adcb2eb8ae2c17a6e456db038ff453805)|
|typedef Map::iterator|[**iterator**](classffw_1_1_object.md#1aa8a8ed6601f2997f842179c2db5765aa)|
|typedef Map::const\_iterator|[**const\_iterator**](classffw_1_1_object.md#1a62b7eca6cc316d5bd49a555cc9f8e5b0)|
|typedef Map::difference\_type|[**difference\_type**](classffw_1_1_object.md#1ae8fea9d3f29e4a3fee008b35b2f920fa)|
|typedef Map::size\_type|[**size\_type**](classffw_1_1_object.md#1abe9edac9fb3579f7bb8c761024e2c189)|
|typedef Map::key\_type|[**key\_type**](classffw_1_1_object.md#1acd7739c7f448f9d06ff4ce3548c671df)|
|typedef Map::local\_iterator|[**local\_iterator**](classffw_1_1_object.md#1ad1ff441fa411f9e725ca5ec1cb87b842)|
|typedef Map::const\_local\_iterator|[**const\_local\_iterator**](classffw_1_1_object.md#1a94ca9619805fbe6e84846de5749632ea)|
|typedef Map::mapped\_type|[**mapped\_type**](classffw_1_1_object.md#1a5a32ba751db1af804e45f96b44b0c9ff)|
|typedef Map::hasher|[**hasher**](classffw_1_1_object.md#1a6ffd3c7206ba7562dc099fcd6b390986)|
|typedef Map::value\_type|[**value\_type**](classffw_1_1_object.md#1aaf1c5e07f878134d2331638c77945b99)|
|typedef Map::key\_equal|[**key\_equal**](classffw_1_1_object.md#1a7fb12b462bde6e60a6763cec102936bf)|


## Public Functions

|Type|Name|
|-----|-----|
||[**Object**](classffw_1_1_object.md#1a120d90783c4964c47a8905ec77fefcbc) () |
|virtual |[**~Object**](classffw_1_1_object.md#1a4509ae320c8474c2efb38b34c1d49f58) () |
||[**Object**](classffw_1_1_object.md#1ae105bb1334b05b0d9d1925c27fbef60c) (const std::string & key, const **[Any](classffw_1_1_any.md)** & value) |
||[**Object**](classffw_1_1_object.md#1ad02eb8f2b01c8221773dc49f2e1cb423) (const **[Object](classffw_1_1_object.md)** & other) |
||[**Object**](classffw_1_1_object.md#1afa360a5176b48193b13b1cc78eec8e7e) (**[Object](classffw_1_1_object.md)** && other) |
||[**Object**](classffw_1_1_object.md#1a66d93b2b8fa76095ec16ffd34ddfec7c) (const std::initializer\_list< std::pair< std::string, **[Any](classffw_1_1_any.md)** >> & list) |
|bool|[**exists**](classffw_1_1_object.md#1a4e14b9ba307bdfcf2d592f495691f13f) (const std::string & key) const |
|bool|[**contains**](classffw_1_1_object.md#1a2b2fa82bc7206ce840d5e7b5fb750463) (const std::string & key) const |
|bool|[**has\_key**](classffw_1_1_object.md#1a1d47c5a1a6ec133ca8d405824834e236) (const std::string & key) const |
|void|[**swap**](classffw_1_1_object.md#1a990185c18e17c3054d1256de4dd11060) (**[Object](classffw_1_1_object.md)** & other) |
|**[Object](classffw_1_1_object.md)** &|[**operator=**](classffw_1_1_object.md#1a51bf8cd764e7bad51dedb4514d02b054) (const **[Object](classffw_1_1_object.md)** & other) |
|**[Object](classffw_1_1_object.md)** &|[**operator=**](classffw_1_1_object.md#1a0e83d7248389ea9d6ae952605dc2430b) (**[Object](classffw_1_1_object.md)** && other) |
|**[Object](classffw_1_1_object.md)** &|[**operator=**](classffw_1_1_object.md#1a9d4c464360257306055d94c4a94bec2b) (const std::initializer\_list< std::pair< std::string, **[Any](classffw_1_1_any.md)** >> & list) |
|std::pair< **[iterator](classffw_1_1_object.md#1aa8a8ed6601f2997f842179c2db5765aa)**, bool >|[**insert**](classffw_1_1_object.md#1aab793bdd31d4e5480660bad082ee058a) (const std::string & key, const **[Any](classffw_1_1_any.md)** & value) |
|**[Any](classffw_1_1_any.md)** &|[**operator[]**](classffw_1_1_object.md#1a21048b35f21effd6e5c728424fa986d2) (const **[key\_type](classffw_1_1_object.md#1acd7739c7f448f9d06ff4ce3548c671df)** & key) |
|const **[Any](classffw_1_1_any.md)** &|[**operator[]**](classffw_1_1_object.md#1a3dd5d66ecfce85b2487042adbf04acf4) (const **[key\_type](classffw_1_1_object.md#1acd7739c7f448f9d06ff4ce3548c671df)** & key) const |
|**[mapped\_type](classffw_1_1_object.md#1a5a32ba751db1af804e45f96b44b0c9ff)** &|[**at**](classffw_1_1_object.md#1a10423e314f17173234f0f4df8222d908) (const **[key\_type](classffw_1_1_object.md#1acd7739c7f448f9d06ff4ce3548c671df)** & key) |
|const **[mapped\_type](classffw_1_1_object.md#1a5a32ba751db1af804e45f96b44b0c9ff)** &|[**at**](classffw_1_1_object.md#1a084eb2881c107ad6d9cfc3a30930173f) (const **[key\_type](classffw_1_1_object.md#1acd7739c7f448f9d06ff4ce3548c671df)** & key) const |
|**[iterator](classffw_1_1_object.md#1aa8a8ed6601f2997f842179c2db5765aa)**|[**begin**](classffw_1_1_object.md#1ace693ee7ac5cf32483fed92000b135e7) () |
|**[const\_iterator](classffw_1_1_object.md#1a62b7eca6cc316d5bd49a555cc9f8e5b0)**|[**begin**](classffw_1_1_object.md#1a4cc46f46d2788c645ea526b35f46fb99) () const |
|**[local\_iterator](classffw_1_1_object.md#1ad1ff441fa411f9e725ca5ec1cb87b842)**|[**begin**](classffw_1_1_object.md#1a5329e63212344a96b88c1ad3889c03b8) (**[size\_type](classffw_1_1_object.md#1abe9edac9fb3579f7bb8c761024e2c189)** n) |
|**[const\_local\_iterator](classffw_1_1_object.md#1a94ca9619805fbe6e84846de5749632ea)**|[**begin**](classffw_1_1_object.md#1af5e3479319e00d3d86036e6ba3244d70) (**[size\_type](classffw_1_1_object.md#1abe9edac9fb3579f7bb8c761024e2c189)** n) const |
|**[size\_type](classffw_1_1_object.md#1abe9edac9fb3579f7bb8c761024e2c189)**|[**bucket**](classffw_1_1_object.md#1a1baec71b02f65c6599f63eb4202f5f62) (const **[key\_type](classffw_1_1_object.md#1acd7739c7f448f9d06ff4ce3548c671df)** & k) const |
|**[size\_type](classffw_1_1_object.md#1abe9edac9fb3579f7bb8c761024e2c189)**|[**bucket\_count**](classffw_1_1_object.md#1acde2119b7158dba673dfb0f4242112cd) () const |
|**[size\_type](classffw_1_1_object.md#1abe9edac9fb3579f7bb8c761024e2c189)**|[**bucket\_size**](classffw_1_1_object.md#1ac721e120416824c25b93d911c8073f29) (**[size\_type](classffw_1_1_object.md#1abe9edac9fb3579f7bb8c761024e2c189)** n) const |
|**[const\_iterator](classffw_1_1_object.md#1a62b7eca6cc316d5bd49a555cc9f8e5b0)**|[**cbegin**](classffw_1_1_object.md#1a827c55fe7d5ac688636b72abbecbc2ff) () const |
|**[const\_local\_iterator](classffw_1_1_object.md#1a94ca9619805fbe6e84846de5749632ea)**|[**cbegin**](classffw_1_1_object.md#1a5e56493957089dfced49f575dbcd0469) (**[size\_type](classffw_1_1_object.md#1abe9edac9fb3579f7bb8c761024e2c189)** n) const |
|**[const\_iterator](classffw_1_1_object.md#1a62b7eca6cc316d5bd49a555cc9f8e5b0)**|[**cend**](classffw_1_1_object.md#1ac261c399ff50b2ec1d65f3b6e714a7e7) () const |
|**[const\_local\_iterator](classffw_1_1_object.md#1a94ca9619805fbe6e84846de5749632ea)**|[**cend**](classffw_1_1_object.md#1a9710508f0b715cec16839f989d41a3e3) (**[size\_type](classffw_1_1_object.md#1abe9edac9fb3579f7bb8c761024e2c189)** n) const |
|void|[**clear**](classffw_1_1_object.md#1afe7cb1db0d3c397df8fa73b770d36668) () |
|**[size\_type](classffw_1_1_object.md#1abe9edac9fb3579f7bb8c761024e2c189)**|[**count**](classffw_1_1_object.md#1a72ea21f2ab73da0199a8dc127be89b69) (const **[key\_type](classffw_1_1_object.md#1acd7739c7f448f9d06ff4ce3548c671df)** & key) const |
|bool|[**empty**](classffw_1_1_object.md#1a4f159328a7ef976984ef2a26741b60d8) () const |
|**[iterator](classffw_1_1_object.md#1aa8a8ed6601f2997f842179c2db5765aa)**|[**end**](classffw_1_1_object.md#1a6f755359092b2bddd54bf0274212cf77) () |
|**[const\_iterator](classffw_1_1_object.md#1a62b7eca6cc316d5bd49a555cc9f8e5b0)**|[**end**](classffw_1_1_object.md#1ab2d0840e1eda1123b398b793c739437c) () const |
|**[local\_iterator](classffw_1_1_object.md#1ad1ff441fa411f9e725ca5ec1cb87b842)**|[**end**](classffw_1_1_object.md#1a2a2da4323b5d66b6cbf1772de270726d) (**[size\_type](classffw_1_1_object.md#1abe9edac9fb3579f7bb8c761024e2c189)** n) |
|**[const\_local\_iterator](classffw_1_1_object.md#1a94ca9619805fbe6e84846de5749632ea)**|[**end**](classffw_1_1_object.md#1ab49dd3e54856aa527fbefbc89a4878ce) (**[size\_type](classffw_1_1_object.md#1abe9edac9fb3579f7bb8c761024e2c189)** n) const |
|std::pair< **[iterator](classffw_1_1_object.md#1aa8a8ed6601f2997f842179c2db5765aa)**, **[iterator](classffw_1_1_object.md#1aa8a8ed6601f2997f842179c2db5765aa)** >|[**equal\_range**](classffw_1_1_object.md#1a4ce4bed5961281298b60b5432be2cbb9) (const **[key\_type](classffw_1_1_object.md#1acd7739c7f448f9d06ff4ce3548c671df)** & k) |
|std::pair< **[const\_iterator](classffw_1_1_object.md#1a62b7eca6cc316d5bd49a555cc9f8e5b0)**, **[const\_iterator](classffw_1_1_object.md#1a62b7eca6cc316d5bd49a555cc9f8e5b0)** >|[**equal\_range**](classffw_1_1_object.md#1a83b1c91b1b555bd97cd48db87ff62efe) (const **[key\_type](classffw_1_1_object.md#1acd7739c7f448f9d06ff4ce3548c671df)** & k) const |
|**[iterator](classffw_1_1_object.md#1aa8a8ed6601f2997f842179c2db5765aa)**|[**erase**](classffw_1_1_object.md#1a86b98d8ceb56c9536fb6ab30d08eb446) (**[const\_iterator](classffw_1_1_object.md#1a62b7eca6cc316d5bd49a555cc9f8e5b0)** position) |
|**[size\_type](classffw_1_1_object.md#1abe9edac9fb3579f7bb8c761024e2c189)**|[**erase**](classffw_1_1_object.md#1a659b5bedc4c636536cd2af1cd0b2d81e) (const **[key\_type](classffw_1_1_object.md#1acd7739c7f448f9d06ff4ce3548c671df)** & value) |
|**[iterator](classffw_1_1_object.md#1aa8a8ed6601f2997f842179c2db5765aa)**|[**erase**](classffw_1_1_object.md#1ad01161f53c4621b86390a792b8e36135) (**[const\_iterator](classffw_1_1_object.md#1a62b7eca6cc316d5bd49a555cc9f8e5b0)** first, **[const\_iterator](classffw_1_1_object.md#1a62b7eca6cc316d5bd49a555cc9f8e5b0)** last) |
|**[iterator](classffw_1_1_object.md#1aa8a8ed6601f2997f842179c2db5765aa)**|[**find**](classffw_1_1_object.md#1a649bebbeaacac45fee37693baeef70db) (const **[key\_type](classffw_1_1_object.md#1acd7739c7f448f9d06ff4ce3548c671df)** & key) |
|**[const\_iterator](classffw_1_1_object.md#1a62b7eca6cc316d5bd49a555cc9f8e5b0)**|[**find**](classffw_1_1_object.md#1afdc63bf84473c71bcf7446c44d2ed867) (const **[key\_type](classffw_1_1_object.md#1acd7739c7f448f9d06ff4ce3548c671df)** & key) const |
|**[allocator\_type](classffw_1_1_object.md#1af09729ed810f38c67296fd1daf40c1e4)**|[**get\_allocator**](classffw_1_1_object.md#1a82a4be98a819928f1b44ee6075e73ddf) () const |
|**[hasher](classffw_1_1_object.md#1a6ffd3c7206ba7562dc099fcd6b390986)**|[**hash\_function**](classffw_1_1_object.md#1a78f0054b1558ce85ffbc82c223341fea) () const |
|std::pair< **[iterator](classffw_1_1_object.md#1aa8a8ed6601f2997f842179c2db5765aa)**, bool >|[**insert**](classffw_1_1_object.md#1a4930b017fab41f0acd46de54239d9b5f) (const **[value\_type](classffw_1_1_object.md#1aaf1c5e07f878134d2331638c77945b99)** & val) |
|std::pair< **[iterator](classffw_1_1_object.md#1aa8a8ed6601f2997f842179c2db5765aa)**, bool >|[**insert**](classffw_1_1_object.md#1ac2f7ec69523355914316576d53a7632f) (P && val) |
|**[iterator](classffw_1_1_object.md#1aa8a8ed6601f2997f842179c2db5765aa)**|[**insert**](classffw_1_1_object.md#1a9752f62dd17f016469362fad5702e060) (**[const\_iterator](classffw_1_1_object.md#1a62b7eca6cc316d5bd49a555cc9f8e5b0)** hint, const **[value\_type](classffw_1_1_object.md#1aaf1c5e07f878134d2331638c77945b99)** & val) |
|**[iterator](classffw_1_1_object.md#1aa8a8ed6601f2997f842179c2db5765aa)**|[**insert**](classffw_1_1_object.md#1af82341050b5b78444c5b3784a8697b9b) (**[const\_iterator](classffw_1_1_object.md#1a62b7eca6cc316d5bd49a555cc9f8e5b0)** hint, P && val) |
|void|[**insert**](classffw_1_1_object.md#1a1dc0ddbb065e67a5d9abd12148f87a26) (InputIterator first, InputIterator last) |
|void|[**insert**](classffw_1_1_object.md#1aff02b00f576427d12fa9fd0a136a6872) (std::initializer\_list< **[value\_type](classffw_1_1_object.md#1aaf1c5e07f878134d2331638c77945b99)** > il) |
|**[key\_equal](classffw_1_1_object.md#1a7fb12b462bde6e60a6763cec102936bf)**|[**key\_eq**](classffw_1_1_object.md#1a0fbbde4ff42f36cdddcff3899d5171b5) () const |
|float|[**load\_factor**](classffw_1_1_object.md#1a6f6a730be69d1c54ce81227b0b236062) () const |
|**[size\_type](classffw_1_1_object.md#1abe9edac9fb3579f7bb8c761024e2c189)**|[**max\_bucket\_count**](classffw_1_1_object.md#1a5c8f9a876dcce9b48305de5fd105f600) () const |
|float|[**max\_load\_factor**](classffw_1_1_object.md#1a95785584310455dcbf80b1ece33d299f) () const |
|void|[**max\_load\_factor**](classffw_1_1_object.md#1a90e40f15ef2659f6f6c499c3ea15d919) (float z) |
|**[size\_type](classffw_1_1_object.md#1abe9edac9fb3579f7bb8c761024e2c189)**|[**max\_size**](classffw_1_1_object.md#1a9629104a8a4b690162cb55af3ddada8d) () const |
|void|[**rehash**](classffw_1_1_object.md#1ab0051ad427d61bf196051bf913e4ef50) (**[size\_type](classffw_1_1_object.md#1abe9edac9fb3579f7bb8c761024e2c189)** n) |
|void|[**reserve**](classffw_1_1_object.md#1ac3469ecfd53e07175b499a0f0fb45b38) (**[size\_type](classffw_1_1_object.md#1abe9edac9fb3579f7bb8c761024e2c189)** n) |
|**[size\_type](classffw_1_1_object.md#1abe9edac9fb3579f7bb8c761024e2c189)**|[**size**](classffw_1_1_object.md#1a443c436cb4ea37339274f818a1007293) () const |
|bool|[**operator==**](classffw_1_1_object.md#1ad376173f5266e9955d6e94c152003976) (const **[Object](classffw_1_1_object.md)** & other) const |
|bool|[**operator!=**](classffw_1_1_object.md#1addb3e1dab842a949326da953d71588e3) (const **[Object](classffw_1_1_object.md)** & other) const |


## Public Types Documentation

### typedef <a id="1a93137a549bad3b1c007db4a4f5921f75" href="#1a93137a549bad3b1c007db4a4f5921f75">Map</a>

```cpp
typedef std::unordered_map<std::string, Any> ffw::Object::Map;
```



### typedef <a id="1af09729ed810f38c67296fd1daf40c1e4" href="#1af09729ed810f38c67296fd1daf40c1e4">allocator\_type</a>

```cpp
typedef Map::allocator_type ffw::Object::allocator_type;
```



### typedef <a id="1ab03501d3379ff363d3a8b1a2b4330a68" href="#1ab03501d3379ff363d3a8b1a2b4330a68">reference</a>

```cpp
typedef Map::reference ffw::Object::reference;
```



### typedef <a id="1ab3b20e8c0b70a8b8b15307e13a20f078" href="#1ab3b20e8c0b70a8b8b15307e13a20f078">const\_reference</a>

```cpp
typedef Map::const_reference ffw::Object::const_reference;
```



### typedef <a id="1a11a94d2786a97da4816dc96b93fdf208" href="#1a11a94d2786a97da4816dc96b93fdf208">pointer</a>

```cpp
typedef Map::pointer ffw::Object::pointer;
```



### typedef <a id="1adcb2eb8ae2c17a6e456db038ff453805" href="#1adcb2eb8ae2c17a6e456db038ff453805">const\_pointer</a>

```cpp
typedef Map::const_pointer ffw::Object::const_pointer;
```



### typedef <a id="1aa8a8ed6601f2997f842179c2db5765aa" href="#1aa8a8ed6601f2997f842179c2db5765aa">iterator</a>

```cpp
typedef Map::iterator ffw::Object::iterator;
```



### typedef <a id="1a62b7eca6cc316d5bd49a555cc9f8e5b0" href="#1a62b7eca6cc316d5bd49a555cc9f8e5b0">const\_iterator</a>

```cpp
typedef Map::const_iterator ffw::Object::const_iterator;
```



### typedef <a id="1ae8fea9d3f29e4a3fee008b35b2f920fa" href="#1ae8fea9d3f29e4a3fee008b35b2f920fa">difference\_type</a>

```cpp
typedef Map::difference_type ffw::Object::difference_type;
```



### typedef <a id="1abe9edac9fb3579f7bb8c761024e2c189" href="#1abe9edac9fb3579f7bb8c761024e2c189">size\_type</a>

```cpp
typedef Map::size_type ffw::Object::size_type;
```



### typedef <a id="1acd7739c7f448f9d06ff4ce3548c671df" href="#1acd7739c7f448f9d06ff4ce3548c671df">key\_type</a>

```cpp
typedef Map::key_type ffw::Object::key_type;
```



### typedef <a id="1ad1ff441fa411f9e725ca5ec1cb87b842" href="#1ad1ff441fa411f9e725ca5ec1cb87b842">local\_iterator</a>

```cpp
typedef Map::local_iterator ffw::Object::local_iterator;
```



### typedef <a id="1a94ca9619805fbe6e84846de5749632ea" href="#1a94ca9619805fbe6e84846de5749632ea">const\_local\_iterator</a>

```cpp
typedef Map::const_local_iterator ffw::Object::const_local_iterator;
```



### typedef <a id="1a5a32ba751db1af804e45f96b44b0c9ff" href="#1a5a32ba751db1af804e45f96b44b0c9ff">mapped\_type</a>

```cpp
typedef Map::mapped_type ffw::Object::mapped_type;
```



### typedef <a id="1a6ffd3c7206ba7562dc099fcd6b390986" href="#1a6ffd3c7206ba7562dc099fcd6b390986">hasher</a>

```cpp
typedef Map::hasher ffw::Object::hasher;
```



### typedef <a id="1aaf1c5e07f878134d2331638c77945b99" href="#1aaf1c5e07f878134d2331638c77945b99">value\_type</a>

```cpp
typedef Map::value_type ffw::Object::value_type;
```



### typedef <a id="1a7fb12b462bde6e60a6763cec102936bf" href="#1a7fb12b462bde6e60a6763cec102936bf">key\_equal</a>

```cpp
typedef Map::key_equal ffw::Object::key_equal;
```



## Public Functions Documentation

### function <a id="1a120d90783c4964c47a8905ec77fefcbc" href="#1a120d90783c4964c47a8905ec77fefcbc">Object</a>

```cpp
ffw::Object::Object ()
```



### function <a id="1a4509ae320c8474c2efb38b34c1d49f58" href="#1a4509ae320c8474c2efb38b34c1d49f58">~Object</a>

```cpp
virtual ffw::Object::~Object ()
```



### function <a id="1ae105bb1334b05b0d9d1925c27fbef60c" href="#1ae105bb1334b05b0d9d1925c27fbef60c">Object</a>

```cpp
ffw::Object::Object (
    const std::string & key,
    const Any & value
)
```



### function <a id="1ad02eb8f2b01c8221773dc49f2e1cb423" href="#1ad02eb8f2b01c8221773dc49f2e1cb423">Object</a>

```cpp
ffw::Object::Object (
    const Object & other
)
```



### function <a id="1afa360a5176b48193b13b1cc78eec8e7e" href="#1afa360a5176b48193b13b1cc78eec8e7e">Object</a>

```cpp
ffw::Object::Object (
    Object && other
)
```



### function <a id="1a66d93b2b8fa76095ec16ffd34ddfec7c" href="#1a66d93b2b8fa76095ec16ffd34ddfec7c">Object</a>

```cpp
ffw::Object::Object (
    const std::initializer_list< std::pair< std::string, Any >> & list
)
```



### function <a id="1a4e14b9ba307bdfcf2d592f495691f13f" href="#1a4e14b9ba307bdfcf2d592f495691f13f">exists</a>

```cpp
bool ffw::Object::exists (
    const std::string & key
) const
```



### function <a id="1a2b2fa82bc7206ce840d5e7b5fb750463" href="#1a2b2fa82bc7206ce840d5e7b5fb750463">contains</a>

```cpp
bool ffw::Object::contains (
    const std::string & key
) const
```



### function <a id="1a1d47c5a1a6ec133ca8d405824834e236" href="#1a1d47c5a1a6ec133ca8d405824834e236">has\_key</a>

```cpp
bool ffw::Object::has_key (
    const std::string & key
) const
```



### function <a id="1a990185c18e17c3054d1256de4dd11060" href="#1a990185c18e17c3054d1256de4dd11060">swap</a>

```cpp
void ffw::Object::swap (
    Object & other
)
```



### function <a id="1a51bf8cd764e7bad51dedb4514d02b054" href="#1a51bf8cd764e7bad51dedb4514d02b054">operator=</a>

```cpp
Object & ffw::Object::operator= (
    const Object & other
)
```



### function <a id="1a0e83d7248389ea9d6ae952605dc2430b" href="#1a0e83d7248389ea9d6ae952605dc2430b">operator=</a>

```cpp
Object & ffw::Object::operator= (
    Object && other
)
```



### function <a id="1a9d4c464360257306055d94c4a94bec2b" href="#1a9d4c464360257306055d94c4a94bec2b">operator=</a>

```cpp
Object & ffw::Object::operator= (
    const std::initializer_list< std::pair< std::string, Any >> & list
)
```



### function <a id="1aab793bdd31d4e5480660bad082ee058a" href="#1aab793bdd31d4e5480660bad082ee058a">insert</a>

```cpp
std::pair< iterator, bool > ffw::Object::insert (
    const std::string & key,
    const Any & value
)
```



### function <a id="1a21048b35f21effd6e5c728424fa986d2" href="#1a21048b35f21effd6e5c728424fa986d2">operator[]</a>

```cpp
Any & ffw::Object::operator[] (
    const key_type & key
)
```



### function <a id="1a3dd5d66ecfce85b2487042adbf04acf4" href="#1a3dd5d66ecfce85b2487042adbf04acf4">operator[]</a>

```cpp
const Any & ffw::Object::operator[] (
    const key_type & key
) const
```



### function <a id="1a10423e314f17173234f0f4df8222d908" href="#1a10423e314f17173234f0f4df8222d908">at</a>

```cpp
mapped_type & ffw::Object::at (
    const key_type & key
)
```



### function <a id="1a084eb2881c107ad6d9cfc3a30930173f" href="#1a084eb2881c107ad6d9cfc3a30930173f">at</a>

```cpp
const mapped_type & ffw::Object::at (
    const key_type & key
) const
```



### function <a id="1ace693ee7ac5cf32483fed92000b135e7" href="#1ace693ee7ac5cf32483fed92000b135e7">begin</a>

```cpp
iterator ffw::Object::begin ()
```



### function <a id="1a4cc46f46d2788c645ea526b35f46fb99" href="#1a4cc46f46d2788c645ea526b35f46fb99">begin</a>

```cpp
const_iterator ffw::Object::begin () const
```



### function <a id="1a5329e63212344a96b88c1ad3889c03b8" href="#1a5329e63212344a96b88c1ad3889c03b8">begin</a>

```cpp
local_iterator ffw::Object::begin (
    size_type n
)
```



### function <a id="1af5e3479319e00d3d86036e6ba3244d70" href="#1af5e3479319e00d3d86036e6ba3244d70">begin</a>

```cpp
const_local_iterator ffw::Object::begin (
    size_type n
) const
```



### function <a id="1a1baec71b02f65c6599f63eb4202f5f62" href="#1a1baec71b02f65c6599f63eb4202f5f62">bucket</a>

```cpp
size_type ffw::Object::bucket (
    const key_type & k
) const
```



### function <a id="1acde2119b7158dba673dfb0f4242112cd" href="#1acde2119b7158dba673dfb0f4242112cd">bucket\_count</a>

```cpp
size_type ffw::Object::bucket_count () const
```



### function <a id="1ac721e120416824c25b93d911c8073f29" href="#1ac721e120416824c25b93d911c8073f29">bucket\_size</a>

```cpp
size_type ffw::Object::bucket_size (
    size_type n
) const
```



### function <a id="1a827c55fe7d5ac688636b72abbecbc2ff" href="#1a827c55fe7d5ac688636b72abbecbc2ff">cbegin</a>

```cpp
const_iterator ffw::Object::cbegin () const
```



### function <a id="1a5e56493957089dfced49f575dbcd0469" href="#1a5e56493957089dfced49f575dbcd0469">cbegin</a>

```cpp
const_local_iterator ffw::Object::cbegin (
    size_type n
) const
```



### function <a id="1ac261c399ff50b2ec1d65f3b6e714a7e7" href="#1ac261c399ff50b2ec1d65f3b6e714a7e7">cend</a>

```cpp
const_iterator ffw::Object::cend () const
```



### function <a id="1a9710508f0b715cec16839f989d41a3e3" href="#1a9710508f0b715cec16839f989d41a3e3">cend</a>

```cpp
const_local_iterator ffw::Object::cend (
    size_type n
) const
```



### function <a id="1afe7cb1db0d3c397df8fa73b770d36668" href="#1afe7cb1db0d3c397df8fa73b770d36668">clear</a>

```cpp
void ffw::Object::clear ()
```



### function <a id="1a72ea21f2ab73da0199a8dc127be89b69" href="#1a72ea21f2ab73da0199a8dc127be89b69">count</a>

```cpp
size_type ffw::Object::count (
    const key_type & key
) const
```



### function <a id="1a4f159328a7ef976984ef2a26741b60d8" href="#1a4f159328a7ef976984ef2a26741b60d8">empty</a>

```cpp
bool ffw::Object::empty () const
```



### function <a id="1a6f755359092b2bddd54bf0274212cf77" href="#1a6f755359092b2bddd54bf0274212cf77">end</a>

```cpp
iterator ffw::Object::end ()
```



### function <a id="1ab2d0840e1eda1123b398b793c739437c" href="#1ab2d0840e1eda1123b398b793c739437c">end</a>

```cpp
const_iterator ffw::Object::end () const
```



### function <a id="1a2a2da4323b5d66b6cbf1772de270726d" href="#1a2a2da4323b5d66b6cbf1772de270726d">end</a>

```cpp
local_iterator ffw::Object::end (
    size_type n
)
```



### function <a id="1ab49dd3e54856aa527fbefbc89a4878ce" href="#1ab49dd3e54856aa527fbefbc89a4878ce">end</a>

```cpp
const_local_iterator ffw::Object::end (
    size_type n
) const
```



### function <a id="1a4ce4bed5961281298b60b5432be2cbb9" href="#1a4ce4bed5961281298b60b5432be2cbb9">equal\_range</a>

```cpp
std::pair< iterator, iterator > ffw::Object::equal_range (
    const key_type & k
)
```



### function <a id="1a83b1c91b1b555bd97cd48db87ff62efe" href="#1a83b1c91b1b555bd97cd48db87ff62efe">equal\_range</a>

```cpp
std::pair< const_iterator, const_iterator > ffw::Object::equal_range (
    const key_type & k
) const
```



### function <a id="1a86b98d8ceb56c9536fb6ab30d08eb446" href="#1a86b98d8ceb56c9536fb6ab30d08eb446">erase</a>

```cpp
iterator ffw::Object::erase (
    const_iterator position
)
```



### function <a id="1a659b5bedc4c636536cd2af1cd0b2d81e" href="#1a659b5bedc4c636536cd2af1cd0b2d81e">erase</a>

```cpp
size_type ffw::Object::erase (
    const key_type & value
)
```



### function <a id="1ad01161f53c4621b86390a792b8e36135" href="#1ad01161f53c4621b86390a792b8e36135">erase</a>

```cpp
iterator ffw::Object::erase (
    const_iterator first,
    const_iterator last
)
```



### function <a id="1a649bebbeaacac45fee37693baeef70db" href="#1a649bebbeaacac45fee37693baeef70db">find</a>

```cpp
iterator ffw::Object::find (
    const key_type & key
)
```



### function <a id="1afdc63bf84473c71bcf7446c44d2ed867" href="#1afdc63bf84473c71bcf7446c44d2ed867">find</a>

```cpp
const_iterator ffw::Object::find (
    const key_type & key
) const
```



### function <a id="1a82a4be98a819928f1b44ee6075e73ddf" href="#1a82a4be98a819928f1b44ee6075e73ddf">get\_allocator</a>

```cpp
allocator_type ffw::Object::get_allocator () const
```



### function <a id="1a78f0054b1558ce85ffbc82c223341fea" href="#1a78f0054b1558ce85ffbc82c223341fea">hash\_function</a>

```cpp
hasher ffw::Object::hash_function () const
```



### function <a id="1a4930b017fab41f0acd46de54239d9b5f" href="#1a4930b017fab41f0acd46de54239d9b5f">insert</a>

```cpp
std::pair< iterator, bool > ffw::Object::insert (
    const value_type & val
)
```



### function <a id="1ac2f7ec69523355914316576d53a7632f" href="#1ac2f7ec69523355914316576d53a7632f">insert</a>

```cpp
std::pair< iterator, bool > ffw::Object::insert (
    P && val
)
```



### function <a id="1a9752f62dd17f016469362fad5702e060" href="#1a9752f62dd17f016469362fad5702e060">insert</a>

```cpp
iterator ffw::Object::insert (
    const_iterator hint,
    const value_type & val
)
```



### function <a id="1af82341050b5b78444c5b3784a8697b9b" href="#1af82341050b5b78444c5b3784a8697b9b">insert</a>

```cpp
iterator ffw::Object::insert (
    const_iterator hint,
    P && val
)
```



### function <a id="1a1dc0ddbb065e67a5d9abd12148f87a26" href="#1a1dc0ddbb065e67a5d9abd12148f87a26">insert</a>

```cpp
void ffw::Object::insert (
    InputIterator first,
    InputIterator last
)
```



### function <a id="1aff02b00f576427d12fa9fd0a136a6872" href="#1aff02b00f576427d12fa9fd0a136a6872">insert</a>

```cpp
void ffw::Object::insert (
    std::initializer_list< value_type > il
)
```



### function <a id="1a0fbbde4ff42f36cdddcff3899d5171b5" href="#1a0fbbde4ff42f36cdddcff3899d5171b5">key\_eq</a>

```cpp
key_equal ffw::Object::key_eq () const
```



### function <a id="1a6f6a730be69d1c54ce81227b0b236062" href="#1a6f6a730be69d1c54ce81227b0b236062">load\_factor</a>

```cpp
float ffw::Object::load_factor () const
```



### function <a id="1a5c8f9a876dcce9b48305de5fd105f600" href="#1a5c8f9a876dcce9b48305de5fd105f600">max\_bucket\_count</a>

```cpp
size_type ffw::Object::max_bucket_count () const
```



### function <a id="1a95785584310455dcbf80b1ece33d299f" href="#1a95785584310455dcbf80b1ece33d299f">max\_load\_factor</a>

```cpp
float ffw::Object::max_load_factor () const
```



### function <a id="1a90e40f15ef2659f6f6c499c3ea15d919" href="#1a90e40f15ef2659f6f6c499c3ea15d919">max\_load\_factor</a>

```cpp
void ffw::Object::max_load_factor (
    float z
)
```



### function <a id="1a9629104a8a4b690162cb55af3ddada8d" href="#1a9629104a8a4b690162cb55af3ddada8d">max\_size</a>

```cpp
size_type ffw::Object::max_size () const
```



### function <a id="1ab0051ad427d61bf196051bf913e4ef50" href="#1ab0051ad427d61bf196051bf913e4ef50">rehash</a>

```cpp
void ffw::Object::rehash (
    size_type n
)
```



### function <a id="1ac3469ecfd53e07175b499a0f0fb45b38" href="#1ac3469ecfd53e07175b499a0f0fb45b38">reserve</a>

```cpp
void ffw::Object::reserve (
    size_type n
)
```



### function <a id="1a443c436cb4ea37339274f818a1007293" href="#1a443c436cb4ea37339274f818a1007293">size</a>

```cpp
size_type ffw::Object::size () const
```



### function <a id="1ad376173f5266e9955d6e94c152003976" href="#1ad376173f5266e9955d6e94c152003976">operator==</a>

```cpp
bool ffw::Object::operator== (
    const Object & other
) const
```



### function <a id="1addb3e1dab842a949326da953d71588e3" href="#1addb3e1dab842a949326da953d71588e3">operator!=</a>

```cpp
bool ffw::Object::operator!= (
    const Object & other
) const
```





----------------------------------------
The documentation for this class was generated from the following file: `include/ffw/math/any.h`
