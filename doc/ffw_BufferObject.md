BufferObject
===================================


**Implemented by:** [ffw::Ibo](ffw_Ibo.html), [ffw::Vbo](ffw_Vbo.html), 

The documentation for this class was generated from: `include/ffw/graphics/bufferobject.h`



## Protected Attributes

| Type | Name |
| -------: | :------- |
|  unsigned int | [type_](#75bf4e90) |
|  unsigned int | [objecttype_](#bb186efa) |
|  bool | [loaded_](#ead20c4d) |
|  unsigned int | [buffer_](#9ef21590) |
|  int | [size_](#4282e25d) |
|  const [RenderExtensions](ffw_RenderExtensions.html) * | [gl_](#935bafbe) |


## Public Static Functions

| Type | Name |
| -------: | :------- |
|  bool | [checkCompability](#a098027f) (const [RenderContext](ffw_RenderContext.html) * _renderer_)  |


## Public Functions

| Type | Name |
| -------: | :------- |
|   | [BufferObject](#5d082b74) (unsigned int _objecttype_)  |
|   | [BufferObject](#6ccb4976) (const [BufferObject](ffw_BufferObject.html) & _other_) = delete  |
|   | [BufferObject](#fe3d161e) ([BufferObject](ffw_BufferObject.html) && _other_)  |
|  void | [swap](#3754b15c) ([BufferObject](ffw_BufferObject.html) & _other_)  |
|  virtual  | [~BufferObject](#628c58a6) ()  |
|  bool | [isCreated](#498c595c) () const  |
|  bool | [create](#8278afb4) (const [RenderContext](ffw_RenderContext.html) * _renderer_, const void * _data_, GLsizei _size_, GLenum _type_)  |
|  bool | [resize](#94cb7030) (const void * _data_, GLsizei _size_)  |
|  bool | [setData](#7bc1a9da) (const void * _data_, GLsizei _offset_, GLsizei _size_)  |
|  bool | [mapBuffer](#b7b7a0b7) (void ** _pointer_, GLenum _access_) const  |
|  bool | [unMapBuffer](#19c8510b) () const  |
|  void | [destroy](#5b2b7a5e) ()  |
|  void | [bind](#cb82a7e8) () const  |
|  void | [unbind](#1870fdc0) () const  |
|  unsigned int | [getHandle](#079b455a) () const  |
|  int | [getSize](#8f7c040b) () const  |
|  unsigned int | [getType](#e815cc4a) () const  |
|  unsigned int | [getObjectType](#9e1d37f4) () const  |
|  bool | [copyFrom](#69f17217) (const [BufferObject](ffw_BufferObject.html) * _other_, GLintptr _readoffset_, GLintptr _writeoffset_, GLsizeiptr _size_)  |
|  bool | [copyFromEnabled](#d94efb57) () const  |
|  bool | [getData](#9e9300e1) (void * _data_, GLsizei _offset_, GLsizei _size_)  |
|  [BufferObject](ffw_BufferObject.html) & | [operator=](#7568e2c7) (const [BufferObject](ffw_BufferObject.html) & _other_) = delete  |
|  [BufferObject](ffw_BufferObject.html) & | [operator=](#ccdf3d53) ([BufferObject](ffw_BufferObject.html) && _other_)  |


## Protected Attributes Documentation

### <span style="opacity:0.5;">variable</span> <a id="75bf4e90" href="#75bf4e90">type_</a>

```cpp
unsigned int type_
```



### <span style="opacity:0.5;">variable</span> <a id="bb186efa" href="#bb186efa">objecttype_</a>

```cpp
unsigned int objecttype_
```



### <span style="opacity:0.5;">variable</span> <a id="ead20c4d" href="#ead20c4d">loaded_</a>

```cpp
bool loaded_
```



### <span style="opacity:0.5;">variable</span> <a id="9ef21590" href="#9ef21590">buffer_</a>

```cpp
unsigned int buffer_
```



### <span style="opacity:0.5;">variable</span> <a id="4282e25d" href="#4282e25d">size_</a>

```cpp
int size_
```



### <span style="opacity:0.5;">variable</span> <a id="935bafbe" href="#935bafbe">gl_</a>

```cpp
const RenderExtensions * gl_
```





## Public Static Functions Documentation

### <span style="opacity:0.5;">function</span> <a id="a098027f" href="#a098027f">checkCompability</a>

```cpp
static bool checkCompability (
    const RenderContext * renderer
) 
```





## Public Functions Documentation

### <span style="opacity:0.5;">function</span> <a id="5d082b74" href="#5d082b74">BufferObject</a>

```cpp
 BufferObject (
    unsigned int objecttype
) 
```



### <span style="opacity:0.5;">function</span> <a id="6ccb4976" href="#6ccb4976">BufferObject</a>

```cpp
 BufferObject (
    const BufferObject & other
) = delete 
```



### <span style="opacity:0.5;">function</span> <a id="fe3d161e" href="#fe3d161e">BufferObject</a>

```cpp
 BufferObject (
    BufferObject && other
) 
```



### <span style="opacity:0.5;">function</span> <a id="3754b15c" href="#3754b15c">swap</a>

```cpp
void swap (
    BufferObject & other
) 
```



### <span style="opacity:0.5;">function</span> <a id="628c58a6" href="#628c58a6">~BufferObject</a>

```cpp
virtual  ~BufferObject () 
```



### <span style="opacity:0.5;">function</span> <a id="498c595c" href="#498c595c">isCreated</a>

```cpp
inline bool isCreated () const 
```



### <span style="opacity:0.5;">function</span> <a id="8278afb4" href="#8278afb4">create</a>

```cpp
bool create (
    const RenderContext * renderer,
    const void * data,
    GLsizei size,
    GLenum type
) 
```



### <span style="opacity:0.5;">function</span> <a id="94cb7030" href="#94cb7030">resize</a>

```cpp
bool resize (
    const void * data,
    GLsizei size
) 
```



### <span style="opacity:0.5;">function</span> <a id="7bc1a9da" href="#7bc1a9da">setData</a>

```cpp
bool setData (
    const void * data,
    GLsizei offset,
    GLsizei size
) 
```



### <span style="opacity:0.5;">function</span> <a id="b7b7a0b7" href="#b7b7a0b7">mapBuffer</a>

```cpp
bool mapBuffer (
    void ** pointer,
    GLenum access
) const 
```



### <span style="opacity:0.5;">function</span> <a id="19c8510b" href="#19c8510b">unMapBuffer</a>

```cpp
bool unMapBuffer () const 
```



### <span style="opacity:0.5;">function</span> <a id="5b2b7a5e" href="#5b2b7a5e">destroy</a>

```cpp
void destroy () 
```



### <span style="opacity:0.5;">function</span> <a id="cb82a7e8" href="#cb82a7e8">bind</a>

```cpp
void bind () const 
```



### <span style="opacity:0.5;">function</span> <a id="1870fdc0" href="#1870fdc0">unbind</a>

```cpp
void unbind () const 
```



### <span style="opacity:0.5;">function</span> <a id="079b455a" href="#079b455a">getHandle</a>

```cpp
inline unsigned int getHandle () const 
```



### <span style="opacity:0.5;">function</span> <a id="8f7c040b" href="#8f7c040b">getSize</a>

```cpp
inline int getSize () const 
```



### <span style="opacity:0.5;">function</span> <a id="e815cc4a" href="#e815cc4a">getType</a>

```cpp
inline unsigned int getType () const 
```



### <span style="opacity:0.5;">function</span> <a id="9e1d37f4" href="#9e1d37f4">getObjectType</a>

```cpp
inline unsigned int getObjectType () const 
```



### <span style="opacity:0.5;">function</span> <a id="69f17217" href="#69f17217">copyFrom</a>

```cpp
bool copyFrom (
    const BufferObject * other,
    GLintptr readoffset,
    GLintptr writeoffset,
    GLsizeiptr size
) 
```



### <span style="opacity:0.5;">function</span> <a id="d94efb57" href="#d94efb57">copyFromEnabled</a>

```cpp
bool copyFromEnabled () const 
```



### <span style="opacity:0.5;">function</span> <a id="9e9300e1" href="#9e9300e1">getData</a>

```cpp
bool getData (
    void * data,
    GLsizei offset,
    GLsizei size
) 
```



### <span style="opacity:0.5;">function</span> <a id="7568e2c7" href="#7568e2c7">operator=</a>

```cpp
BufferObject & operator= (
    const BufferObject & other
) = delete 
```



### <span style="opacity:0.5;">function</span> <a id="ccdf3d53" href="#ccdf3d53">operator=</a>

```cpp
BufferObject & operator= (
    BufferObject && other
) 
```





