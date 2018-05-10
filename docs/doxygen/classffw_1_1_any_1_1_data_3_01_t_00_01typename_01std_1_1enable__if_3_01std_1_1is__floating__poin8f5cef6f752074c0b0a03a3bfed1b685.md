---
search: false
---

# class ffw::Any::Data< T, typename std::enable\_if< std::is\_floating\_point< T >::value >::type >



Inherits the following classes: **[ffw::Any::Content](classffw_1_1_any_1_1_content.md)**

## Public Functions

|Type|Name|
|-----|-----|
||[**Data**](classffw_1_1_any_1_1_data_3_01_t_00_01typename_01std_1_1enable__if_3_01std_1_1is__floating__poin8f5cef6f752074c0b0a03a3bfed1b685.md#1aaee2bf991128d5dbd95f49798a5e232e) (Args &&... args) |
|virtual |[**~Data**](classffw_1_1_any_1_1_data_3_01_t_00_01typename_01std_1_1enable__if_3_01std_1_1is__floating__poin8f5cef6f752074c0b0a03a3bfed1b685.md#1aa7bf55ab5255972933286e958408c204) () |
|virtual **[Data](classffw_1_1_any_1_1_data.md)** \*|[**createCopy**](classffw_1_1_any_1_1_data_3_01_t_00_01typename_01std_1_1enable__if_3_01std_1_1is__floating__poin8f5cef6f752074c0b0a03a3bfed1b685.md#1a6763cb820aff0d0b9d17cf9d0564a22e) () override |
|virtual const std::type\_info &|[**getTypeid**](classffw_1_1_any_1_1_data_3_01_t_00_01typename_01std_1_1enable__if_3_01std_1_1is__floating__poin8f5cef6f752074c0b0a03a3bfed1b685.md#1a48aeadff190f71c6b58392b2729b291d) () override const |
|T &|[**get**](classffw_1_1_any_1_1_data_3_01_t_00_01typename_01std_1_1enable__if_3_01std_1_1is__floating__poin8f5cef6f752074c0b0a03a3bfed1b685.md#1ac4386627ba3e7a44ca2e7fd5441337c5) () |
|const T &|[**get**](classffw_1_1_any_1_1_data_3_01_t_00_01typename_01std_1_1enable__if_3_01std_1_1is__floating__poin8f5cef6f752074c0b0a03a3bfed1b685.md#1ab96205fd35db6bbb976bef3a2e521acb) () const |
|virtual bool|[**toBool**](classffw_1_1_any_1_1_data_3_01_t_00_01typename_01std_1_1enable__if_3_01std_1_1is__floating__poin8f5cef6f752074c0b0a03a3bfed1b685.md#1a492799b21bcff63fda792110251e901b) () override const |
|virtual bool|[**isInteger**](classffw_1_1_any_1_1_data_3_01_t_00_01typename_01std_1_1enable__if_3_01std_1_1is__floating__poin8f5cef6f752074c0b0a03a3bfed1b685.md#1aba05f805934ebdc42feb1801e00804d8) () override const |
|virtual bool|[**isFloat**](classffw_1_1_any_1_1_data_3_01_t_00_01typename_01std_1_1enable__if_3_01std_1_1is__floating__poin8f5cef6f752074c0b0a03a3bfed1b685.md#1a7abc1dbf1ad55d8b877bd0f2673a6548) () override const |
|virtual int|[**getInteger**](classffw_1_1_any_1_1_data_3_01_t_00_01typename_01std_1_1enable__if_3_01std_1_1is__floating__poin8f5cef6f752074c0b0a03a3bfed1b685.md#1af3eb83a931b3fffdf09ff35f34987e94) () override const |
|virtual float|[**getFloat**](classffw_1_1_any_1_1_data_3_01_t_00_01typename_01std_1_1enable__if_3_01std_1_1is__floating__poin8f5cef6f752074c0b0a03a3bfed1b685.md#1a00c3e50ea0bb3354f649c787de859dec) () override const |
|virtual double|[**getDouble**](classffw_1_1_any_1_1_data_3_01_t_00_01typename_01std_1_1enable__if_3_01std_1_1is__floating__poin8f5cef6f752074c0b0a03a3bfed1b685.md#1a09bdb6686187e9b7436be80f8a5dd055) () override const |
|virtual bool|[**compare**](classffw_1_1_any_1_1_data_3_01_t_00_01typename_01std_1_1enable__if_3_01std_1_1is__floating__poin8f5cef6f752074c0b0a03a3bfed1b685.md#1ac50460a7160261c6d8974822ec0fb8ef) (const **[Content](classffw_1_1_any_1_1_content.md)** \* other) override const |


#### Public Functions inherited from [ffw::Any::Content](classffw_1_1_any_1_1_content.md)

|Type|Name|
|-----|-----|
|virtual |[**~Content**](classffw_1_1_any_1_1_content.md#1a06448918a8d9c51ec45a02dcf15b3349) () |


## Public Functions Documentation

### function <a id="1aaee2bf991128d5dbd95f49798a5e232e" href="#1aaee2bf991128d5dbd95f49798a5e232e">Data</a>

```cpp
ffw::Any::Data< T, typename std::enable_if< std::is_floating_point< T >::value >::type >::Data (
    Args &&... args
)
```



### function <a id="1aa7bf55ab5255972933286e958408c204" href="#1aa7bf55ab5255972933286e958408c204">~Data</a>

```cpp
virtual ffw::Any::Data< T, typename std::enable_if< std::is_floating_point< T >::value >::type >::~Data ()
```



### function <a id="1a6763cb820aff0d0b9d17cf9d0564a22e" href="#1a6763cb820aff0d0b9d17cf9d0564a22e">createCopy</a>

```cpp
virtual Data * ffw::Any::Data< T, typename std::enable_if< std::is_floating_point< T >::value >::type >::createCopy ()
```

Overrides **[Any::Content::createCopy](classffw_1_1_any_1_1_content.md#1a4b3dcc940ef8415699a74ec7768ecf6d)**


### function <a id="1a48aeadff190f71c6b58392b2729b291d" href="#1a48aeadff190f71c6b58392b2729b291d">getTypeid</a>

```cpp
virtual const std::type_info & ffw::Any::Data< T, typename std::enable_if< std::is_floating_point< T >::value >::type >::getTypeid () const
```

Overrides **[Any::Content::getTypeid](classffw_1_1_any_1_1_content.md#1a363746364db674bc9d5a6499940b3011)**


### function <a id="1ac4386627ba3e7a44ca2e7fd5441337c5" href="#1ac4386627ba3e7a44ca2e7fd5441337c5">get</a>

```cpp
T & ffw::Any::Data< T, typename std::enable_if< std::is_floating_point< T >::value >::type >::get ()
```



### function <a id="1ab96205fd35db6bbb976bef3a2e521acb" href="#1ab96205fd35db6bbb976bef3a2e521acb">get</a>

```cpp
const T & ffw::Any::Data< T, typename std::enable_if< std::is_floating_point< T >::value >::type >::get () const
```



### function <a id="1a492799b21bcff63fda792110251e901b" href="#1a492799b21bcff63fda792110251e901b">toBool</a>

```cpp
virtual bool ffw::Any::Data< T, typename std::enable_if< std::is_floating_point< T >::value >::type >::toBool () const
```

Overrides **[Any::Content::toBool](classffw_1_1_any_1_1_content.md#1a80f4d2b4d740b2ca1cd7afeda99af5cd)**


### function <a id="1aba05f805934ebdc42feb1801e00804d8" href="#1aba05f805934ebdc42feb1801e00804d8">isInteger</a>

```cpp
virtual bool ffw::Any::Data< T, typename std::enable_if< std::is_floating_point< T >::value >::type >::isInteger () const
```

Overrides **[Any::Content::isInteger](classffw_1_1_any_1_1_content.md#1a61ebd5e42e28c5843de0d7393fc14f7d)**


### function <a id="1a7abc1dbf1ad55d8b877bd0f2673a6548" href="#1a7abc1dbf1ad55d8b877bd0f2673a6548">isFloat</a>

```cpp
virtual bool ffw::Any::Data< T, typename std::enable_if< std::is_floating_point< T >::value >::type >::isFloat () const
```

Overrides **[Any::Content::isFloat](classffw_1_1_any_1_1_content.md#1adb05831e42aa9350c68bfe609959541d)**


### function <a id="1af3eb83a931b3fffdf09ff35f34987e94" href="#1af3eb83a931b3fffdf09ff35f34987e94">getInteger</a>

```cpp
virtual int ffw::Any::Data< T, typename std::enable_if< std::is_floating_point< T >::value >::type >::getInteger () const
```

Overrides **[Any::Content::getInteger](classffw_1_1_any_1_1_content.md#1a347cdb7d63d12e9f8a754275ec8e5196)**


### function <a id="1a00c3e50ea0bb3354f649c787de859dec" href="#1a00c3e50ea0bb3354f649c787de859dec">getFloat</a>

```cpp
virtual float ffw::Any::Data< T, typename std::enable_if< std::is_floating_point< T >::value >::type >::getFloat () const
```

Overrides **[Any::Content::getFloat](classffw_1_1_any_1_1_content.md#1a27bf98ad2081d7ae7d20bb81e4771d8a)**


### function <a id="1a09bdb6686187e9b7436be80f8a5dd055" href="#1a09bdb6686187e9b7436be80f8a5dd055">getDouble</a>

```cpp
virtual double ffw::Any::Data< T, typename std::enable_if< std::is_floating_point< T >::value >::type >::getDouble () const
```

Overrides **[Any::Content::getDouble](classffw_1_1_any_1_1_content.md#1ac7f4a9135af66d143ae87e607ee4c4b9)**


### function <a id="1ac50460a7160261c6d8974822ec0fb8ef" href="#1ac50460a7160261c6d8974822ec0fb8ef">compare</a>

```cpp
virtual bool ffw::Any::Data< T, typename std::enable_if< std::is_floating_point< T >::value >::type >::compare (
    const Content * other
) const
```

Overrides **[Any::Content::compare](classffw_1_1_any_1_1_content.md#1a199e04f41e19344981f7b65ce118a880)**




----------------------------------------
The documentation for this class was generated from the following file: `include/ffw/math/any.h`
