---
search: false
---

# class ffw::JsonWriter

## Classes

|Type|Name|
|-----|-----|
|class|[**FileStream**](classffw_1_1_json_writer_1_1_file_stream.md)|
|class|[**Stream**](classffw_1_1_json_writer_1_1_stream.md)|
|class|[**StringStream**](classffw_1_1_json_writer_1_1_string_stream.md)|


## Public Functions

|Type|Name|
|-----|-----|
||[**JsonWriter**](classffw_1_1_json_writer.md#1a68ea355d00a1ccae20abd05a99010e89) (**[Stream](classffw_1_1_json_writer_1_1_stream.md)** \* stream, const char \* indent = NULL, bool escape = true) |
|virtual |[**~JsonWriter**](classffw_1_1_json_writer.md#1a24d1446c0c540960ec5a9c2cb034a30a) () |
|void|[**addObject**](classffw_1_1_json_writer.md#1a805abd280c38026f3f403f7167785c68) (const char \* key = NULL) |
|void|[**addArray**](classffw_1_1_json_writer.md#1a760f78d5fae1542cae286100846513e2) (const char \* key = NULL) |
|void|[**stepOut**](classffw_1_1_json_writer.md#1a5a1b77a9e624dfff40005ce7e07c1704) () |
|void|[**addInteger**](classffw_1_1_json_writer.md#1a61131c785d1d69bc3ab6a349845476b5) (int val, const char \* key = NULL) |
|void|[**addString**](classffw_1_1_json_writer.md#1a9637c8482d557fdd475b3109b9705785) (const char \* val, const char \* key = NULL) |
|void|[**addBoolean**](classffw_1_1_json_writer.md#1a01bc13786549bfca104dfeecc58f274e) (bool val, const char \* key = NULL) |
|void|[**addFloat**](classffw_1_1_json_writer.md#1a543ec61ef860ad28185914c183b2044d) (float val, const char \* key = NULL) |
|void|[**addNull**](classffw_1_1_json_writer.md#1a98a1ecff794add6c689a67cff99e600a) (const char \* key = NULL) |


## Detailed Description

doc/markdown/tutorial-json.md 
## Public Functions Documentation

### function <a id="1a68ea355d00a1ccae20abd05a99010e89" href="#1a68ea355d00a1ccae20abd05a99010e89">JsonWriter</a>

```cpp
ffw::JsonWriter::JsonWriter (
    Stream * stream
    const char * indent = NULL
    bool escape = true
)
```



### function <a id="1a24d1446c0c540960ec5a9c2cb034a30a" href="#1a24d1446c0c540960ec5a9c2cb034a30a">~JsonWriter</a>

```cpp
virtual ffw::JsonWriter::~JsonWriter ()
```



### function <a id="1a805abd280c38026f3f403f7167785c68" href="#1a805abd280c38026f3f403f7167785c68">addObject</a>

```cpp
void ffw::JsonWriter::addObject (
    const char * key = NULL
)
```



### function <a id="1a760f78d5fae1542cae286100846513e2" href="#1a760f78d5fae1542cae286100846513e2">addArray</a>

```cpp
void ffw::JsonWriter::addArray (
    const char * key = NULL
)
```



### function <a id="1a5a1b77a9e624dfff40005ce7e07c1704" href="#1a5a1b77a9e624dfff40005ce7e07c1704">stepOut</a>

```cpp
void ffw::JsonWriter::stepOut ()
```



### function <a id="1a61131c785d1d69bc3ab6a349845476b5" href="#1a61131c785d1d69bc3ab6a349845476b5">addInteger</a>

```cpp
void ffw::JsonWriter::addInteger (
    int val
    const char * key = NULL
)
```



### function <a id="1a9637c8482d557fdd475b3109b9705785" href="#1a9637c8482d557fdd475b3109b9705785">addString</a>

```cpp
void ffw::JsonWriter::addString (
    const char * val
    const char * key = NULL
)
```



### function <a id="1a01bc13786549bfca104dfeecc58f274e" href="#1a01bc13786549bfca104dfeecc58f274e">addBoolean</a>

```cpp
void ffw::JsonWriter::addBoolean (
    bool val
    const char * key = NULL
)
```



### function <a id="1a543ec61ef860ad28185914c183b2044d" href="#1a543ec61ef860ad28185914c183b2044d">addFloat</a>

```cpp
void ffw::JsonWriter::addFloat (
    float val
    const char * key = NULL
)
```



### function <a id="1a98a1ecff794add6c689a67cff99e600a" href="#1a98a1ecff794add6c689a67cff99e600a">addNull</a>

```cpp
void ffw::JsonWriter::addNull (
    const char * key = NULL
)
```





----------------------------------------
The documentation for this class was generated from the following file: `include/ffw/data/jsonwriter.h`
