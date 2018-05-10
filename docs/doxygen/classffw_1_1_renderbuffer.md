---
search: false
---

# class ffw::Renderbuffer



Inherited by the following classes: **[ffw::Renderbuffer2D](classffw_1_1_renderbuffer2_d.md)**, **[ffw::Renderbuffer2DMS](classffw_1_1_renderbuffer2_d_m_s.md)**

## Protected Attributes

|Type|Name|
|-----|-----|
|bool|[**loaded**](classffw_1_1_renderbuffer.md#1a5b4440d36c14d79428f25f6e7d0c34e4)|
|**[GLenum](glcorearb_8h.md#1a7efd7809e1632cdae75603fd1fee61c0)**|[**internalformat**](classffw_1_1_renderbuffer.md#1aa71792df5c496d87bfb5ffb4cdb1638b)|
|**[GLuint](glcorearb_8h.md#1aa311c7f0d6ec4f1a33f9235c3651b86b)**|[**buffer**](classffw_1_1_renderbuffer.md#1a7daf459c62849d34404471148d7996b6)|
|**[GLsizei](glcorearb_8h.md#1a9289d5b99dc1f27f01480360f2e18ae0)**|[**width**](classffw_1_1_renderbuffer.md#1ab620da58fc35fa61c947ec91b2039e6b)|
|**[GLsizei](glcorearb_8h.md#1a9289d5b99dc1f27f01480360f2e18ae0)**|[**height**](classffw_1_1_renderbuffer.md#1a27be78c36640a6ef0a9e67b17769eac6)|
|**[GLsizei](glcorearb_8h.md#1a9289d5b99dc1f27f01480360f2e18ae0)**|[**samples**](classffw_1_1_renderbuffer.md#1a314a55d8152dbe3350976cb1992a6519)|


## Public Functions

|Type|Name|
|-----|-----|
||[**Renderbuffer**](classffw_1_1_renderbuffer.md#1a65db165157a54da0fac51d2d97db9807) () <br>Creates an empty renderbuffer storage. |
||[**Renderbuffer**](classffw_1_1_renderbuffer.md#1ad137b5468f6ae402c6ecf29d70b2fb07) (const **[Renderbuffer](classffw_1_1_renderbuffer.md)** & other) = delete |
||[**Renderbuffer**](classffw_1_1_renderbuffer.md#1aa47daf9663b63fae754d7b9ea07ea579) (**[Renderbuffer](classffw_1_1_renderbuffer.md)** && other) |
|void|[**swap**](classffw_1_1_renderbuffer.md#1ae313c164f24ace73b7d7966ad28de1df) (**[Renderbuffer](classffw_1_1_renderbuffer.md)** & other) |
|virtual |[**~Renderbuffer**](classffw_1_1_renderbuffer.md#1a8eff07b1c9fc9ec8ef1c7000ed559a07) () |
|bool|[**isCreated**](classffw_1_1_renderbuffer.md#1a552242b8116d8d678c6e89a9ffb9783e) () const <br>Returns true if the renderbuffer has been allocated. |
|void|[**destroy**](classffw_1_1_renderbuffer.md#1aaa69b089c2ac512d8a98db965d66b4cf) () <br>Destroys the renderbuffer. |
|void|[**bind**](classffw_1_1_renderbuffer.md#1a5c367ec01f6ec6148400f91b92afe927) () const <br>Binds the renderbuffer. |
|void|[**unbind**](classffw_1_1_renderbuffer.md#1a5eb9e6a65534f5cb6cf22724b47de36f) () const <br>Unbinds the texture. |
|**[GLuint](glcorearb_8h.md#1aa311c7f0d6ec4f1a33f9235c3651b86b)**|[**getHandle**](classffw_1_1_renderbuffer.md#1aacb48db33cee24c946aa2a4e738f4d7f) () const <br>Returns the OpenGL pointer, a handle to the renderbuffer. |
|**[GLsizei](glcorearb_8h.md#1a9289d5b99dc1f27f01480360f2e18ae0)**|[**getWidth**](classffw_1_1_renderbuffer.md#1a835a340fcff8b404951f2bad0b21a62b) () const |
|**[GLsizei](glcorearb_8h.md#1a9289d5b99dc1f27f01480360f2e18ae0)**|[**getHeight**](classffw_1_1_renderbuffer.md#1a885c4299038dd0f3f6f4005e49991f26) () const |
|**[GLenum](glcorearb_8h.md#1a7efd7809e1632cdae75603fd1fee61c0)**|[**getInternalFormat**](classffw_1_1_renderbuffer.md#1a01ebd58dd96a47ffaf14aba12c5120e0) () const <br>Returns the internal format used by the renderbuffer. |
|**[GLsizei](glcorearb_8h.md#1a9289d5b99dc1f27f01480360f2e18ae0)**|[**getSamples**](classffw_1_1_renderbuffer.md#1afb80bac412fc2f21736ea733895efc63) () const <br>Returns the number of samples used by the renderbuffer. |
|**[Renderbuffer](classffw_1_1_renderbuffer.md)** &|[**operator=**](classffw_1_1_renderbuffer.md#1a081c8fa6aca820251c2370ce9a46c1b1) (const **[Renderbuffer](classffw_1_1_renderbuffer.md)** & other) = delete |
|**[Renderbuffer](classffw_1_1_renderbuffer.md)** &|[**operator=**](classffw_1_1_renderbuffer.md#1ab7cd00f965b3b856c7664a1055650938) (**[Renderbuffer](classffw_1_1_renderbuffer.md)** && other) |


## Protected Attributes Documentation

### variable <a id="1a5b4440d36c14d79428f25f6e7d0c34e4" href="#1a5b4440d36c14d79428f25f6e7d0c34e4">loaded</a>

```cpp
bool ffw::Renderbuffer::loaded;
```



### variable <a id="1aa71792df5c496d87bfb5ffb4cdb1638b" href="#1aa71792df5c496d87bfb5ffb4cdb1638b">internalformat</a>

```cpp
GLenum ffw::Renderbuffer::internalformat;
```



### variable <a id="1a7daf459c62849d34404471148d7996b6" href="#1a7daf459c62849d34404471148d7996b6">buffer</a>

```cpp
GLuint ffw::Renderbuffer::buffer;
```



### variable <a id="1ab620da58fc35fa61c947ec91b2039e6b" href="#1ab620da58fc35fa61c947ec91b2039e6b">width</a>

```cpp
GLsizei ffw::Renderbuffer::width;
```



### variable <a id="1a27be78c36640a6ef0a9e67b17769eac6" href="#1a27be78c36640a6ef0a9e67b17769eac6">height</a>

```cpp
GLsizei ffw::Renderbuffer::height;
```



### variable <a id="1a314a55d8152dbe3350976cb1992a6519" href="#1a314a55d8152dbe3350976cb1992a6519">samples</a>

```cpp
GLsizei ffw::Renderbuffer::samples;
```



## Public Functions Documentation

### function <a id="1a65db165157a54da0fac51d2d97db9807" href="#1a65db165157a54da0fac51d2d97db9807">Renderbuffer</a>

```cpp
ffw::Renderbuffer::Renderbuffer ()
```

Creates an empty renderbuffer storage. 


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

Returns true if the renderbuffer has been allocated. 


### function <a id="1aaa69b089c2ac512d8a98db965d66b4cf" href="#1aaa69b089c2ac512d8a98db965d66b4cf">destroy</a>

```cpp
void ffw::Renderbuffer::destroy ()
```

Destroys the renderbuffer. 

Destroys the renderbuffer and the allocated memory to it. Calling this on already deleted texture has no effect. 

### function <a id="1a5c367ec01f6ec6148400f91b92afe927" href="#1a5c367ec01f6ec6148400f91b92afe927">bind</a>

```cpp
void ffw::Renderbuffer::bind () const
```

Binds the renderbuffer. 


### function <a id="1a5eb9e6a65534f5cb6cf22724b47de36f" href="#1a5eb9e6a65534f5cb6cf22724b47de36f">unbind</a>

```cpp
void ffw::Renderbuffer::unbind () const
```

Unbinds the texture. 



**Note:**

After the unbind the active texture will be set to no handle (zero) 




### function <a id="1aacb48db33cee24c946aa2a4e738f4d7f" href="#1aacb48db33cee24c946aa2a4e738f4d7f">getHandle</a>

```cpp
GLuint ffw::Renderbuffer::getHandle () const
```

Returns the OpenGL pointer, a handle to the renderbuffer. 


### function <a id="1a835a340fcff8b404951f2bad0b21a62b" href="#1a835a340fcff8b404951f2bad0b21a62b">getWidth</a>

```cpp
GLsizei ffw::Renderbuffer::getWidth () const
```



### function <a id="1a885c4299038dd0f3f6f4005e49991f26" href="#1a885c4299038dd0f3f6f4005e49991f26">getHeight</a>

```cpp
GLsizei ffw::Renderbuffer::getHeight () const
```



### function <a id="1a01ebd58dd96a47ffaf14aba12c5120e0" href="#1a01ebd58dd96a47ffaf14aba12c5120e0">getInternalFormat</a>

```cpp
GLenum ffw::Renderbuffer::getInternalFormat () const
```

Returns the internal format used by the renderbuffer. 


### function <a id="1afb80bac412fc2f21736ea733895efc63" href="#1afb80bac412fc2f21736ea733895efc63">getSamples</a>

```cpp
GLsizei ffw::Renderbuffer::getSamples () const
```

Returns the number of samples used by the renderbuffer. 

When **[ffw::Renderbuffer2D](classffw_1_1_renderbuffer2_d.md)** is used, the returned value is one. 

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
