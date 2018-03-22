---
search:
    keywords: ['ffw::JsonWriter::FileStream', 'FileStream', '~FileStream', 'isOpen', 'close', 'write', 'write']
---

# class ffw::JsonWriter::FileStream



Inherits the following classes: **[ffw::JsonWriter::Stream](classffw_1_1_json_writer_1_1_stream.md)**

## Public Functions

|Type|Name|
|-----|-----|
||[**FileStream**](classffw_1_1_json_writer_1_1_file_stream.md#1a5c5a6b7b156d0967de6bdfb397247c6d) (const std::string & path, std::ios\_base::openmode mode) |
|virtual |[**~FileStream**](classffw_1_1_json_writer_1_1_file_stream.md#1aabca5a2e6e8cdac1fe1799940db81872) () |
|bool|[**isOpen**](classffw_1_1_json_writer_1_1_file_stream.md#1aba816aa097c3b2850546041d42e23d78) () const |
|void|[**close**](classffw_1_1_json_writer_1_1_file_stream.md#1a326ec9a0b341b992401f6585a8fbf0d7) () |
|virtual bool|[**write**](classffw_1_1_json_writer_1_1_file_stream.md#1a8e9cb9082905690b2e35de395a829b31) (const char \* in, size\_t len) override |


## Public Functions Documentation

### function <a id="1a5c5a6b7b156d0967de6bdfb397247c6d" href="#1a5c5a6b7b156d0967de6bdfb397247c6d">FileStream</a>

```cpp
ffw::JsonWriter::FileStream::FileStream (
    const std::string & path
    std::ios_base::openmode mode
)
```



### function <a id="1aabca5a2e6e8cdac1fe1799940db81872" href="#1aabca5a2e6e8cdac1fe1799940db81872">~FileStream</a>

```cpp
virtual ffw::JsonWriter::FileStream::~FileStream ()
```



### function <a id="1aba816aa097c3b2850546041d42e23d78" href="#1aba816aa097c3b2850546041d42e23d78">isOpen</a>

```cpp
bool ffw::JsonWriter::FileStream::isOpen () const
```



### function <a id="1a326ec9a0b341b992401f6585a8fbf0d7" href="#1a326ec9a0b341b992401f6585a8fbf0d7">close</a>

```cpp
void ffw::JsonWriter::FileStream::close ()
```



### function <a id="1a8e9cb9082905690b2e35de395a829b31" href="#1a8e9cb9082905690b2e35de395a829b31">write</a>

```cpp
virtual bool ffw::JsonWriter::FileStream::write (
    const char * in
    size_t len
)
```

Overrides **[JsonWriter::Stream::write](classffw_1_1_json_writer_1_1_stream.md#1a75d12a91fa621410c2fec378fe2885e2)**




----------------------------------------
The documentation for this class was generated from the following file: `include/ffw/data/jsonwriter.h`
