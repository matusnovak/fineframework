---
search: false
---

# class ffw::JsonWriter::StringStream



Inherits the following classes: **[ffw::JsonWriter::Stream](classffw_1_1_json_writer_1_1_stream.md)**

## Public Functions

|Type|Name|
|-----|-----|
||[**StringStream**](classffw_1_1_json_writer_1_1_string_stream.md#1a67a34ddcf56eaa9570284c92571eeb09) () |
|virtual |[**~StringStream**](classffw_1_1_json_writer_1_1_string_stream.md#1a01a203238e0f5a710d2e0268223ea00f) () |
|virtual bool|[**write**](classffw_1_1_json_writer_1_1_string_stream.md#1a8a030b6c908579df83b493162b601c7f) (const char \* in, size\_t len) override |
|const std::string &|[**get**](classffw_1_1_json_writer_1_1_string_stream.md#1a7262c60a4420b41dd4a3cbe93d6ad1f7) () const |


## Public Functions Documentation

### function <a id="1a67a34ddcf56eaa9570284c92571eeb09" href="#1a67a34ddcf56eaa9570284c92571eeb09">StringStream</a>

```cpp
ffw::JsonWriter::StringStream::StringStream ()
```



### function <a id="1a01a203238e0f5a710d2e0268223ea00f" href="#1a01a203238e0f5a710d2e0268223ea00f">~StringStream</a>

```cpp
virtual ffw::JsonWriter::StringStream::~StringStream ()
```



### function <a id="1a8a030b6c908579df83b493162b601c7f" href="#1a8a030b6c908579df83b493162b601c7f">write</a>

```cpp
virtual bool ffw::JsonWriter::StringStream::write (
    const char * in
    size_t len
)
```

Overrides **[JsonWriter::Stream::write](classffw_1_1_json_writer_1_1_stream.md#1a75d12a91fa621410c2fec378fe2885e2)**


### function <a id="1a7262c60a4420b41dd4a3cbe93d6ad1f7" href="#1a7262c60a4420b41dd4a3cbe93d6ad1f7">get</a>

```cpp
const std::string & ffw::JsonWriter::StringStream::get () const
```





----------------------------------------
The documentation for this class was generated from the following file: `include/ffw/data/jsonwriter.h`
