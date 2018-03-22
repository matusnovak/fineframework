---
search:
    keywords: ['ffw::Renderbuffer', 'loaded_', 'internalformat_', 'buffer_', 'width_', 'height_', 'samples_', 'Renderbuffer', 'Renderbuffer', 'Renderbuffer', 'swap', '~Renderbuffer', 'isCreated', 'destroy', 'bind', 'unbind', 'getHandle', 'getWidth', 'getHeight', 'getInternalFormat', 'getSamples', 'operator=', 'operator=']
---

# class ffw::Renderbuffer



Inherited by the following classes: **[ffw::Renderbuffer2D](classffw_1_1_renderbuffer2_d.md)**, **[ffw::Renderbuffer2DMS](classffw_1_1_renderbuffer2_d_m_s.md)**

## Protected Attributes

|Type|Name|
|-----|-----|
|bool|[**loaded\_**](classffw_1_1_renderbuffer.md#1a988c68ce530337f7f7f8d53de33c90fe)|
|unsigned int|[**internalformat\_**](classffw_1_1_renderbuffer.md#1a2b55653bc7296e65bdadaaba965e59ab)|
|unsigned int|[**buffer\_**](classffw_1_1_renderbuffer.md#1ae8c27524014cff2282db77f3d0b723e9)|
|int|[**width\_**](classffw_1_1_renderbuffer.md#1a3be68a1764f745f53e256329e6dbf6d4)|
|int|[**height\_**](classffw_1_1_renderbuffer.md#1a1b20781d8df0a99ff32283e0115dd98d)|
|int|[**samples\_**](classffw_1_1_renderbuffer.md#1a2543d77fb24a979bca6a019e3d86c968)|


## Public Functions

|Type|Name|
|-----|-----|
||[**Renderbuffer**](classffw_1_1_renderbuffer.md#1a65db165157a54da0fac51d2d97db9807) () |
||[**Renderbuffer**](classffw_1_1_renderbuffer.md#1ad137b5468f6ae402c6ecf29d70b2fb07) (const **[Renderbuffer](classffw_1_1_renderbuffer.md)** & other) = delete |
||[**Renderbuffer**](classffw_1_1_renderbuffer.md#1aa47daf9663b63fae754d7b9ea07ea579) (**[Renderbuffer](classffw_1_1_renderbuffer.md)** && other) |
|void|[**swap**](classffw_1_1_renderbuffer.md#1ae313c164f24ace73b7d7966ad28de1df) (**[Renderbuffer](classffw_1_1_renderbuffer.md)** & other) |
|virtual |[**~Renderbuffer**](classffw_1_1_renderbuffer.md#1a8eff07b1c9fc9ec8ef1c7000ed559a07) () |
|bool|[**isCreated**](classffw_1_1_renderbuffer.md#1a552242b8116d8d678c6e89a9ffb9783e) () const |
|void|[**destroy**](classffw_1_1_renderbuffer.md#1aaa69b089c2ac512d8a98db965d66b4cf) () |
|void|[**bind**](classffw_1_1_renderbuffer.md#1a5c367ec01f6ec6148400f91b92afe927) () const |
|void|[**unbind**](classffw_1_1_renderbuffer.md#1a5eb9e6a65534f5cb6cf22724b47de36f) () const |
|unsigned int|[**getHandle**](classffw_1_1_renderbuffer.md#1a1ada3d4ed804dea175ccd9b55bd402a1) () const |
|int|[**getWidth**](classffw_1_1_renderbuffer.md#1a1b1bb5f9dc99503c42b7c62df0e2fc14) () const |
|int|[**getHeight**](classffw_1_1_renderbuffer.md#1a2f9721ee995e6aaeed30330667d56744) () const |
|unsigned int|[**getInternalFormat**](classffw_1_1_renderbuffer.md#1acebb8692752c44c6e9abe56b77bad366) () const |
|int|[**getSamples**](classffw_1_1_renderbuffer.md#1a0d3242b593acb7066382713d419c0fd5) () const |
|**[Renderbuffer](classffw_1_1_renderbuffer.md)** &|[**operator=**](classffw_1_1_renderbuffer.md#1a081c8fa6aca820251c2370ce9a46c1b1) (const **[Renderbuffer](classffw_1_1_renderbuffer.md)** & other) = delete |
|**[Renderbuffer](classffw_1_1_renderbuffer.md)** &|[**operator=**](classffw_1_1_renderbuffer.md#1ab7cd00f965b3b856c7664a1055650938) (**[Renderbuffer](classffw_1_1_renderbuffer.md)** && other) |


## Protected Attributes Documentation

### variable <a id="1a988c68ce530337f7f7f8d53de33c90fe" href="#1a988c68ce530337f7f7f8d53de33c90fe">loaded\_</a>

```cpp
bool ffw::Renderbuffer::loaded_;
```



### variable <a id="1a2b55653bc7296e65bdadaaba965e59ab" href="#1a2b55653bc7296e65bdadaaba965e59ab">internalformat\_</a>

```cpp
unsigned int ffw::Renderbuffer::internalformat_;
```



### variable <a id="1ae8c27524014cff2282db77f3d0b723e9" href="#1ae8c27524014cff2282db77f3d0b723e9">buffer\_</a>

```cpp
unsigned int ffw::Renderbuffer::buffer_;
```



### variable <a id="1a3be68a1764f745f53e256329e6dbf6d4" href="#1a3be68a1764f745f53e256329e6dbf6d4">width\_</a>

```cpp
int ffw::Renderbuffer::width_;
```



### variable <a id="1a1b20781d8df0a99ff32283e0115dd98d" href="#1a1b20781d8df0a99ff32283e0115dd98d">height\_</a>

```cpp
int ffw::Renderbuffer::height_;
```



### variable <a id="1a2543d77fb24a979bca6a019e3d86c968" href="#1a2543d77fb24a979bca6a019e3d86c968">samples\_</a>

```cpp
int ffw::Renderbuffer::samples_;
```



## Public Functions Documentation

### function <a id="1a65db165157a54da0fac51d2d97db9807" href="#1a65db165157a54da0fac51d2d97db9807">Renderbuffer</a>

```cpp
ffw::Renderbuffer::Renderbuffer ()
```



### function <a id="1ad137b5468f6ae402c6ecf29d70b2fb07" href="#1ad137b5468f6ae402c6ecf29d70b2fb07">Renderbuffer</a>

```cpp
ffw::Renderbuffer::Renderbuffer (
    const Renderbuffer & other
) = delete
```



### function <a id="1aa47daf9663b63fae754d7b9ea07ea579" href="#1aa47daf9663b63fae754d7b9ea07ea579">Renderbuffer</a>

```cpp
ffw::Renderbuffer::Renderbuffer (
    Renderbuffer && other
)
```



### function <a id="1ae313c164f24ace73b7d7966ad28de1df" href="#1ae313c164f24ace73b7d7966ad28de1df">swap</a>

```cpp
void ffw::Renderbuffer::swap (
    Renderbuffer & other
)
```



### function <a id="1a8eff07b1c9fc9ec8ef1c7000ed559a07" href="#1a8eff07b1c9fc9ec8ef1c7000ed559a07">~Renderbuffer</a>

```cpp
virtual ffw::Renderbuffer::~Renderbuffer ()
```



### function <a id="1a552242b8116d8d678c6e89a9ffb9783e" href="#1a552242b8116d8d678c6e89a9ffb9783e">isCreated</a>

```cpp
bool ffw::Renderbuffer::isCreated () const
```



### function <a id="1aaa69b089c2ac512d8a98db965d66b4cf" href="#1aaa69b089c2ac512d8a98db965d66b4cf">destroy</a>

```cpp
void ffw::Renderbuffer::destroy ()
```



### function <a id="1a5c367ec01f6ec6148400f91b92afe927" href="#1a5c367ec01f6ec6148400f91b92afe927">bind</a>

```cpp
void ffw::Renderbuffer::bind () const
```



### function <a id="1a5eb9e6a65534f5cb6cf22724b47de36f" href="#1a5eb9e6a65534f5cb6cf22724b47de36f">unbind</a>

```cpp
void ffw::Renderbuffer::unbind () const
```



### function <a id="1a1ada3d4ed804dea175ccd9b55bd402a1" href="#1a1ada3d4ed804dea175ccd9b55bd402a1">getHandle</a>

```cpp
unsigned int ffw::Renderbuffer::getHandle () const
```



### function <a id="1a1b1bb5f9dc99503c42b7c62df0e2fc14" href="#1a1b1bb5f9dc99503c42b7c62df0e2fc14">getWidth</a>

```cpp
int ffw::Renderbuffer::getWidth () const
```



### function <a id="1a2f9721ee995e6aaeed30330667d56744" href="#1a2f9721ee995e6aaeed30330667d56744">getHeight</a>

```cpp
int ffw::Renderbuffer::getHeight () const
```



### function <a id="1acebb8692752c44c6e9abe56b77bad366" href="#1acebb8692752c44c6e9abe56b77bad366">getInternalFormat</a>

```cpp
unsigned int ffw::Renderbuffer::getInternalFormat () const
```



### function <a id="1a0d3242b593acb7066382713d419c0fd5" href="#1a0d3242b593acb7066382713d419c0fd5">getSamples</a>

```cpp
int ffw::Renderbuffer::getSamples () const
```



### function <a id="1a081c8fa6aca820251c2370ce9a46c1b1" href="#1a081c8fa6aca820251c2370ce9a46c1b1">operator=</a>

```cpp
Renderbuffer & ffw::Renderbuffer::operator= (
    const Renderbuffer & other
) = delete
```



### function <a id="1ab7cd00f965b3b856c7664a1055650938" href="#1ab7cd00f965b3b856c7664a1055650938">operator=</a>

```cpp
Renderbuffer & ffw::Renderbuffer::operator= (
    Renderbuffer && other
)
```





----------------------------------------
The documentation for this class was generated from the following file: `include/ffw/graphics/renderbuffer.h`
