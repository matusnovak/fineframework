---
search:
    keywords: ['ffw::Any::Content', '~Content', 'createCopy', 'getTypeid', 'toBool', 'isInteger', 'isFloat', 'getInteger', 'getFloat', 'getDouble', 'compare']
---

# class ffw::Any::Content



Inherited by the following classes: **[ffw::Any::Data< T, Enable >](classffw_1_1_any_1_1_data.md)**, **[ffw::Any::Data< T, typename std::enable\_if< std::is\_floating\_point< T >::value >::type >](classffw_1_1_any_1_1_data_3_01_t_00_01typename_01std_1_1enable__if_3_01std_1_1is__floating__poin8f5cef6f752074c0b0a03a3bfed1b685.md)**, **[ffw::Any::Data< T, typename std::enable\_if< std::is\_integral< T >::value >::type >](classffw_1_1_any_1_1_data_3_01_t_00_01typename_01std_1_1enable__if_3_01std_1_1is__integral_3_01_1e21ee7f9b88f0216578ab66ea9deac3.md)**

## Public Functions

|Type|Name|
|-----|-----|
|virtual |[**~Content**](classffw_1_1_any_1_1_content.md#1a06448918a8d9c51ec45a02dcf15b3349) () |
|virtual **[Content](classffw_1_1_any_1_1_content.md)** \*|[**createCopy**](classffw_1_1_any_1_1_content.md#1a4b3dcc940ef8415699a74ec7768ecf6d) () = 0|
|virtual const std::type\_info &|[**getTypeid**](classffw_1_1_any_1_1_content.md#1a363746364db674bc9d5a6499940b3011) () const = 0|
|virtual bool|[**toBool**](classffw_1_1_any_1_1_content.md#1a80f4d2b4d740b2ca1cd7afeda99af5cd) () const = 0|
|virtual bool|[**isInteger**](classffw_1_1_any_1_1_content.md#1a61ebd5e42e28c5843de0d7393fc14f7d) () const = 0|
|virtual bool|[**isFloat**](classffw_1_1_any_1_1_content.md#1adb05831e42aa9350c68bfe609959541d) () const = 0|
|virtual int|[**getInteger**](classffw_1_1_any_1_1_content.md#1a347cdb7d63d12e9f8a754275ec8e5196) () const = 0|
|virtual float|[**getFloat**](classffw_1_1_any_1_1_content.md#1a27bf98ad2081d7ae7d20bb81e4771d8a) () const = 0|
|virtual double|[**getDouble**](classffw_1_1_any_1_1_content.md#1ac7f4a9135af66d143ae87e607ee4c4b9) () const = 0|
|virtual bool|[**compare**](classffw_1_1_any_1_1_content.md#1a199e04f41e19344981f7b65ce118a880) (const **[Content](classffw_1_1_any_1_1_content.md)** \* other) const = 0|


## Public Functions Documentation

### function <a id="1a06448918a8d9c51ec45a02dcf15b3349" href="#1a06448918a8d9c51ec45a02dcf15b3349">~Content</a>

```cpp
virtual ffw::Any::Content::~Content ()
```



### function <a id="1a4b3dcc940ef8415699a74ec7768ecf6d" href="#1a4b3dcc940ef8415699a74ec7768ecf6d">createCopy</a>

```cpp
virtual Content * ffw::Any::Content::createCopy () = 0
```



### function <a id="1a363746364db674bc9d5a6499940b3011" href="#1a363746364db674bc9d5a6499940b3011">getTypeid</a>

```cpp
virtual const std::type_info & ffw::Any::Content::getTypeid () const = 0
```



### function <a id="1a80f4d2b4d740b2ca1cd7afeda99af5cd" href="#1a80f4d2b4d740b2ca1cd7afeda99af5cd">toBool</a>

```cpp
virtual bool ffw::Any::Content::toBool () const = 0
```



### function <a id="1a61ebd5e42e28c5843de0d7393fc14f7d" href="#1a61ebd5e42e28c5843de0d7393fc14f7d">isInteger</a>

```cpp
virtual bool ffw::Any::Content::isInteger () const = 0
```



### function <a id="1adb05831e42aa9350c68bfe609959541d" href="#1adb05831e42aa9350c68bfe609959541d">isFloat</a>

```cpp
virtual bool ffw::Any::Content::isFloat () const = 0
```



### function <a id="1a347cdb7d63d12e9f8a754275ec8e5196" href="#1a347cdb7d63d12e9f8a754275ec8e5196">getInteger</a>

```cpp
virtual int ffw::Any::Content::getInteger () const = 0
```



### function <a id="1a27bf98ad2081d7ae7d20bb81e4771d8a" href="#1a27bf98ad2081d7ae7d20bb81e4771d8a">getFloat</a>

```cpp
virtual float ffw::Any::Content::getFloat () const = 0
```



### function <a id="1ac7f4a9135af66d143ae87e607ee4c4b9" href="#1ac7f4a9135af66d143ae87e607ee4c4b9">getDouble</a>

```cpp
virtual double ffw::Any::Content::getDouble () const = 0
```



### function <a id="1a199e04f41e19344981f7b65ce118a880" href="#1a199e04f41e19344981f7b65ce118a880">compare</a>

```cpp
virtual bool ffw::Any::Content::compare (
    const Content * other
) const = 0
```





----------------------------------------
The documentation for this class was generated from the following file: `include/ffw/math/any.h`
