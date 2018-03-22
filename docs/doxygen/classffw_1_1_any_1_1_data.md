---
search:
    keywords: ['ffw::Any::Data', 'Data', '~Data', 'createCopy', 'getTypeid', 'get', 'get', 'toBool', 'isInteger', 'isFloat', 'getInteger', 'getFloat', 'getDouble', 'compare', '~Content', 'createCopy', 'getTypeid', 'toBool', 'isInteger', 'isFloat', 'getInteger', 'getFloat', 'getDouble', 'compare']
---

# class ffw::Any::Data



Inherits the following classes: **[ffw::Any::Content](classffw_1_1_any_1_1_content.md)**

## Public Functions

|Type|Name|
|-----|-----|
||[**Data**](classffw_1_1_any_1_1_data.md#1a01fc1ec3cc6f9882214c56feb300e256) (Args &&... args) |
|virtual |[**~Data**](classffw_1_1_any_1_1_data.md#1a078702a1083ac7c715dac34603ef5396) () |
|virtual **[Data](classffw_1_1_any_1_1_data.md)** \*|[**createCopy**](classffw_1_1_any_1_1_data.md#1af421e5f71ed508cb6e1fc1a3161343f8) () override |
|virtual const std::type\_info &|[**getTypeid**](classffw_1_1_any_1_1_data.md#1a54e2f4ed40618ecdf4a3859f7fc5a3b2) () override const |
|T &|[**get**](classffw_1_1_any_1_1_data.md#1a91ab77d31c07b9c22f5ab1019c70f33c) () |
|const T &|[**get**](classffw_1_1_any_1_1_data.md#1a3f5fb5aece5fce286391a0b4cdfbfa95) () const |
|virtual bool|[**toBool**](classffw_1_1_any_1_1_data.md#1ae67f2fd9260182e2fb7afde185e24c41) () override const |
|virtual bool|[**isInteger**](classffw_1_1_any_1_1_data.md#1a231a99d2fb73be4f97b2d95df598cc02) () override const |
|virtual bool|[**isFloat**](classffw_1_1_any_1_1_data.md#1a90e590748acb87b10efc66348380f216) () override const |
|virtual int|[**getInteger**](classffw_1_1_any_1_1_data.md#1a609edac0cff0d477170493f3c74892c3) () override const |
|virtual float|[**getFloat**](classffw_1_1_any_1_1_data.md#1aaf44f6689b412354f7f08dacd62c5506) () override const |
|virtual double|[**getDouble**](classffw_1_1_any_1_1_data.md#1ad3753c850a3fd2abcc7fcb2c0eba9ef1) () override const |
|virtual bool|[**compare**](classffw_1_1_any_1_1_data.md#1a436e034184f08fd02ed43646678bf8c0) (const **[Content](classffw_1_1_any_1_1_content.md)** \* other) override const |


#### Public Functions inherited from [ffw::Any::Content](classffw_1_1_any_1_1_content.md)

|Type|Name|
|-----|-----|
|virtual |[**~Content**](classffw_1_1_any_1_1_content.md#1a06448918a8d9c51ec45a02dcf15b3349) () |


## Public Functions Documentation

### function <a id="1a01fc1ec3cc6f9882214c56feb300e256" href="#1a01fc1ec3cc6f9882214c56feb300e256">Data</a>

```cpp
ffw::Any::Data::Data (
    Args &&... args
)
```



### function <a id="1a078702a1083ac7c715dac34603ef5396" href="#1a078702a1083ac7c715dac34603ef5396">~Data</a>

```cpp
virtual ffw::Any::Data::~Data ()
```



### function <a id="1af421e5f71ed508cb6e1fc1a3161343f8" href="#1af421e5f71ed508cb6e1fc1a3161343f8">createCopy</a>

```cpp
virtual Data * ffw::Any::Data::createCopy ()
```

Overrides **[Any::Content::createCopy](classffw_1_1_any_1_1_content.md#1a4b3dcc940ef8415699a74ec7768ecf6d)**


### function <a id="1a54e2f4ed40618ecdf4a3859f7fc5a3b2" href="#1a54e2f4ed40618ecdf4a3859f7fc5a3b2">getTypeid</a>

```cpp
virtual const std::type_info & ffw::Any::Data::getTypeid () const
```

Overrides **[Any::Content::getTypeid](classffw_1_1_any_1_1_content.md#1a363746364db674bc9d5a6499940b3011)**


### function <a id="1a91ab77d31c07b9c22f5ab1019c70f33c" href="#1a91ab77d31c07b9c22f5ab1019c70f33c">get</a>

```cpp
T & ffw::Any::Data::get ()
```



### function <a id="1a3f5fb5aece5fce286391a0b4cdfbfa95" href="#1a3f5fb5aece5fce286391a0b4cdfbfa95">get</a>

```cpp
const T & ffw::Any::Data::get () const
```



### function <a id="1ae67f2fd9260182e2fb7afde185e24c41" href="#1ae67f2fd9260182e2fb7afde185e24c41">toBool</a>

```cpp
virtual bool ffw::Any::Data::toBool () const
```

Overrides **[Any::Content::toBool](classffw_1_1_any_1_1_content.md#1a80f4d2b4d740b2ca1cd7afeda99af5cd)**


### function <a id="1a231a99d2fb73be4f97b2d95df598cc02" href="#1a231a99d2fb73be4f97b2d95df598cc02">isInteger</a>

```cpp
virtual bool ffw::Any::Data::isInteger () const
```

Overrides **[Any::Content::isInteger](classffw_1_1_any_1_1_content.md#1a61ebd5e42e28c5843de0d7393fc14f7d)**


### function <a id="1a90e590748acb87b10efc66348380f216" href="#1a90e590748acb87b10efc66348380f216">isFloat</a>

```cpp
virtual bool ffw::Any::Data::isFloat () const
```

Overrides **[Any::Content::isFloat](classffw_1_1_any_1_1_content.md#1adb05831e42aa9350c68bfe609959541d)**


### function <a id="1a609edac0cff0d477170493f3c74892c3" href="#1a609edac0cff0d477170493f3c74892c3">getInteger</a>

```cpp
virtual int ffw::Any::Data::getInteger () const
```

Overrides **[Any::Content::getInteger](classffw_1_1_any_1_1_content.md#1a347cdb7d63d12e9f8a754275ec8e5196)**


### function <a id="1aaf44f6689b412354f7f08dacd62c5506" href="#1aaf44f6689b412354f7f08dacd62c5506">getFloat</a>

```cpp
virtual float ffw::Any::Data::getFloat () const
```

Overrides **[Any::Content::getFloat](classffw_1_1_any_1_1_content.md#1a27bf98ad2081d7ae7d20bb81e4771d8a)**


### function <a id="1ad3753c850a3fd2abcc7fcb2c0eba9ef1" href="#1ad3753c850a3fd2abcc7fcb2c0eba9ef1">getDouble</a>

```cpp
virtual double ffw::Any::Data::getDouble () const
```

Overrides **[Any::Content::getDouble](classffw_1_1_any_1_1_content.md#1ac7f4a9135af66d143ae87e607ee4c4b9)**


### function <a id="1a436e034184f08fd02ed43646678bf8c0" href="#1a436e034184f08fd02ed43646678bf8c0">compare</a>

```cpp
virtual bool ffw::Any::Data::compare (
    const Content * other
) const
```

Overrides **[Any::Content::compare](classffw_1_1_any_1_1_content.md#1a199e04f41e19344981f7b65ce118a880)**




----------------------------------------
The documentation for this class was generated from the following file: `include/ffw/math/any.h`
