---
search:
    keywords: ['ffw::Any::Data< T, typename std::enable_if< std::is_integral< T >::value >::type >', 'Data', '~Data', 'createCopy', 'getTypeid', 'get', 'get', 'toBool', 'isInteger', 'isFloat', 'getInteger', 'getFloat', 'getDouble', 'compare', '~Content', 'createCopy', 'getTypeid', 'toBool', 'isInteger', 'isFloat', 'getInteger', 'getFloat', 'getDouble', 'compare']
---

# class ffw::Any::Data< T, typename std::enable\_if< std::is\_integral< T >::value >::type >



Inherits the following classes: **[ffw::Any::Content](classffw_1_1_any_1_1_content.md)**

## Public Functions

|Type|Name|
|-----|-----|
||[**Data**](classffw_1_1_any_1_1_data_3_01_t_00_01typename_01std_1_1enable__if_3_01std_1_1is__integral_3_01_1e21ee7f9b88f0216578ab66ea9deac3.md#1ac796cb0a477746b04fe66303523e50ac) (Args &&... args) |
|virtual |[**~Data**](classffw_1_1_any_1_1_data_3_01_t_00_01typename_01std_1_1enable__if_3_01std_1_1is__integral_3_01_1e21ee7f9b88f0216578ab66ea9deac3.md#1a5ac4f368eaebca9d0f3e67a10dba270b) () |
|virtual **[Data](classffw_1_1_any_1_1_data.md)** \*|[**createCopy**](classffw_1_1_any_1_1_data_3_01_t_00_01typename_01std_1_1enable__if_3_01std_1_1is__integral_3_01_1e21ee7f9b88f0216578ab66ea9deac3.md#1ab6098f01a87edcc1854c76f54a4505c4) () override |
|virtual const std::type\_info &|[**getTypeid**](classffw_1_1_any_1_1_data_3_01_t_00_01typename_01std_1_1enable__if_3_01std_1_1is__integral_3_01_1e21ee7f9b88f0216578ab66ea9deac3.md#1aaa4160806e71a357fc19861d0602e318) () override const |
|T &|[**get**](classffw_1_1_any_1_1_data_3_01_t_00_01typename_01std_1_1enable__if_3_01std_1_1is__integral_3_01_1e21ee7f9b88f0216578ab66ea9deac3.md#1a05ea0521add12105c93adca80073ba1a) () |
|const T &|[**get**](classffw_1_1_any_1_1_data_3_01_t_00_01typename_01std_1_1enable__if_3_01std_1_1is__integral_3_01_1e21ee7f9b88f0216578ab66ea9deac3.md#1acfb91b42adbd53b5f5160827b18f37f5) () const |
|virtual bool|[**toBool**](classffw_1_1_any_1_1_data_3_01_t_00_01typename_01std_1_1enable__if_3_01std_1_1is__integral_3_01_1e21ee7f9b88f0216578ab66ea9deac3.md#1a8535137ac802b5475ab686e506f3377c) () override const |
|virtual bool|[**isInteger**](classffw_1_1_any_1_1_data_3_01_t_00_01typename_01std_1_1enable__if_3_01std_1_1is__integral_3_01_1e21ee7f9b88f0216578ab66ea9deac3.md#1a16fe5a6cee9cf3fee4287ffc9823abac) () override const |
|virtual bool|[**isFloat**](classffw_1_1_any_1_1_data_3_01_t_00_01typename_01std_1_1enable__if_3_01std_1_1is__integral_3_01_1e21ee7f9b88f0216578ab66ea9deac3.md#1a4085ddbeaa601a14480909eb14a38a12) () override const |
|virtual int|[**getInteger**](classffw_1_1_any_1_1_data_3_01_t_00_01typename_01std_1_1enable__if_3_01std_1_1is__integral_3_01_1e21ee7f9b88f0216578ab66ea9deac3.md#1ad30e1e79e450be421531a3c5ac23bc85) () override const |
|virtual float|[**getFloat**](classffw_1_1_any_1_1_data_3_01_t_00_01typename_01std_1_1enable__if_3_01std_1_1is__integral_3_01_1e21ee7f9b88f0216578ab66ea9deac3.md#1a9df25a72d171d437a6fcb898dca62fef) () override const |
|virtual double|[**getDouble**](classffw_1_1_any_1_1_data_3_01_t_00_01typename_01std_1_1enable__if_3_01std_1_1is__integral_3_01_1e21ee7f9b88f0216578ab66ea9deac3.md#1ad9e18fc247f8a12a6c1b3f7f8e26b8bc) () override const |
|virtual bool|[**compare**](classffw_1_1_any_1_1_data_3_01_t_00_01typename_01std_1_1enable__if_3_01std_1_1is__integral_3_01_1e21ee7f9b88f0216578ab66ea9deac3.md#1ab159f7fa35248a8bb6694b475da0ee14) (const **[Content](classffw_1_1_any_1_1_content.md)** \* other) override const |


#### Public Functions inherited from [ffw::Any::Content](classffw_1_1_any_1_1_content.md)

|Type|Name|
|-----|-----|
|virtual |[**~Content**](classffw_1_1_any_1_1_content.md#1a06448918a8d9c51ec45a02dcf15b3349) () |


## Public Functions Documentation

### function <a id="1ac796cb0a477746b04fe66303523e50ac" href="#1ac796cb0a477746b04fe66303523e50ac">Data</a>

```cpp
ffw::Any::Data< T, typename std::enable_if< std::is_integral< T >::value >::type >::Data (
    Args &&... args
)
```



### function <a id="1a5ac4f368eaebca9d0f3e67a10dba270b" href="#1a5ac4f368eaebca9d0f3e67a10dba270b">~Data</a>

```cpp
virtual ffw::Any::Data< T, typename std::enable_if< std::is_integral< T >::value >::type >::~Data ()
```



### function <a id="1ab6098f01a87edcc1854c76f54a4505c4" href="#1ab6098f01a87edcc1854c76f54a4505c4">createCopy</a>

```cpp
virtual Data * ffw::Any::Data< T, typename std::enable_if< std::is_integral< T >::value >::type >::createCopy ()
```

Overrides **[Any::Content::createCopy](classffw_1_1_any_1_1_content.md#1a4b3dcc940ef8415699a74ec7768ecf6d)**


### function <a id="1aaa4160806e71a357fc19861d0602e318" href="#1aaa4160806e71a357fc19861d0602e318">getTypeid</a>

```cpp
virtual const std::type_info & ffw::Any::Data< T, typename std::enable_if< std::is_integral< T >::value >::type >::getTypeid () const
```

Overrides **[Any::Content::getTypeid](classffw_1_1_any_1_1_content.md#1a363746364db674bc9d5a6499940b3011)**


### function <a id="1a05ea0521add12105c93adca80073ba1a" href="#1a05ea0521add12105c93adca80073ba1a">get</a>

```cpp
T & ffw::Any::Data< T, typename std::enable_if< std::is_integral< T >::value >::type >::get ()
```



### function <a id="1acfb91b42adbd53b5f5160827b18f37f5" href="#1acfb91b42adbd53b5f5160827b18f37f5">get</a>

```cpp
const T & ffw::Any::Data< T, typename std::enable_if< std::is_integral< T >::value >::type >::get () const
```



### function <a id="1a8535137ac802b5475ab686e506f3377c" href="#1a8535137ac802b5475ab686e506f3377c">toBool</a>

```cpp
virtual bool ffw::Any::Data< T, typename std::enable_if< std::is_integral< T >::value >::type >::toBool () const
```

Overrides **[Any::Content::toBool](classffw_1_1_any_1_1_content.md#1a80f4d2b4d740b2ca1cd7afeda99af5cd)**


### function <a id="1a16fe5a6cee9cf3fee4287ffc9823abac" href="#1a16fe5a6cee9cf3fee4287ffc9823abac">isInteger</a>

```cpp
virtual bool ffw::Any::Data< T, typename std::enable_if< std::is_integral< T >::value >::type >::isInteger () const
```

Overrides **[Any::Content::isInteger](classffw_1_1_any_1_1_content.md#1a61ebd5e42e28c5843de0d7393fc14f7d)**


### function <a id="1a4085ddbeaa601a14480909eb14a38a12" href="#1a4085ddbeaa601a14480909eb14a38a12">isFloat</a>

```cpp
virtual bool ffw::Any::Data< T, typename std::enable_if< std::is_integral< T >::value >::type >::isFloat () const
```

Overrides **[Any::Content::isFloat](classffw_1_1_any_1_1_content.md#1adb05831e42aa9350c68bfe609959541d)**


### function <a id="1ad30e1e79e450be421531a3c5ac23bc85" href="#1ad30e1e79e450be421531a3c5ac23bc85">getInteger</a>

```cpp
virtual int ffw::Any::Data< T, typename std::enable_if< std::is_integral< T >::value >::type >::getInteger () const
```

Overrides **[Any::Content::getInteger](classffw_1_1_any_1_1_content.md#1a347cdb7d63d12e9f8a754275ec8e5196)**


### function <a id="1a9df25a72d171d437a6fcb898dca62fef" href="#1a9df25a72d171d437a6fcb898dca62fef">getFloat</a>

```cpp
virtual float ffw::Any::Data< T, typename std::enable_if< std::is_integral< T >::value >::type >::getFloat () const
```

Overrides **[Any::Content::getFloat](classffw_1_1_any_1_1_content.md#1a27bf98ad2081d7ae7d20bb81e4771d8a)**


### function <a id="1ad9e18fc247f8a12a6c1b3f7f8e26b8bc" href="#1ad9e18fc247f8a12a6c1b3f7f8e26b8bc">getDouble</a>

```cpp
virtual double ffw::Any::Data< T, typename std::enable_if< std::is_integral< T >::value >::type >::getDouble () const
```

Overrides **[Any::Content::getDouble](classffw_1_1_any_1_1_content.md#1ac7f4a9135af66d143ae87e607ee4c4b9)**


### function <a id="1ab159f7fa35248a8bb6694b475da0ee14" href="#1ab159f7fa35248a8bb6694b475da0ee14">compare</a>

```cpp
virtual bool ffw::Any::Data< T, typename std::enable_if< std::is_integral< T >::value >::type >::compare (
    const Content * other
) const
```

Overrides **[Any::Content::compare](classffw_1_1_any_1_1_content.md#1a199e04f41e19344981f7b65ce118a880)**




----------------------------------------
The documentation for this class was generated from the following file: `include/ffw/math/any.h`
