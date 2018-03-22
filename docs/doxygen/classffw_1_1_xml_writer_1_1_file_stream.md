---
search:
    keywords: ['ffw::XmlWriter::FileStream', 'FileStream', '~FileStream', 'isOpen', 'close', 'write', 'write']
---

# class ffw::XmlWriter::FileStream



Inherits the following classes: **[ffw::XmlWriter::Stream](classffw_1_1_xml_writer_1_1_stream.md)**

## Public Functions

|Type|Name|
|-----|-----|
||[**FileStream**](classffw_1_1_xml_writer_1_1_file_stream.md#1a4fd1063bacdeeaa8ca9d8b0aa6aa9582) (const std::string & path, std::ios\_base::openmode mode) |
||[**~FileStream**](classffw_1_1_xml_writer_1_1_file_stream.md#1a3ea2f448c7c8f0cf0e681611c2fedb36) () |
|bool|[**isOpen**](classffw_1_1_xml_writer_1_1_file_stream.md#1a8afc6ee2187a47a9547fef07e55f9891) () const |
|void|[**close**](classffw_1_1_xml_writer_1_1_file_stream.md#1aae0c3794870168422054678033f526bd) () |
|virtual bool|[**write**](classffw_1_1_xml_writer_1_1_file_stream.md#1abe3748730a4ccccf1384657a0b0d8c0f) (const char \* in, size\_t len) override |


## Public Functions Documentation

### function <a id="1a4fd1063bacdeeaa8ca9d8b0aa6aa9582" href="#1a4fd1063bacdeeaa8ca9d8b0aa6aa9582">FileStream</a>

```cpp
ffw::XmlWriter::FileStream::FileStream (
    const std::string & path
    std::ios_base::openmode mode
)
```



### function <a id="1a3ea2f448c7c8f0cf0e681611c2fedb36" href="#1a3ea2f448c7c8f0cf0e681611c2fedb36">~FileStream</a>

```cpp
ffw::XmlWriter::FileStream::~FileStream ()
```



### function <a id="1a8afc6ee2187a47a9547fef07e55f9891" href="#1a8afc6ee2187a47a9547fef07e55f9891">isOpen</a>

```cpp
bool ffw::XmlWriter::FileStream::isOpen () const
```



### function <a id="1aae0c3794870168422054678033f526bd" href="#1aae0c3794870168422054678033f526bd">close</a>

```cpp
void ffw::XmlWriter::FileStream::close ()
```



### function <a id="1abe3748730a4ccccf1384657a0b0d8c0f" href="#1abe3748730a4ccccf1384657a0b0d8c0f">write</a>

```cpp
virtual bool ffw::XmlWriter::FileStream::write (
    const char * in
    size_t len
)
```

Overrides **[XmlWriter::Stream::write](classffw_1_1_xml_writer_1_1_stream.md#1ac033af2cccf6d488b58d9dfe2de35206)**




----------------------------------------
The documentation for this class was generated from the following file: `include/ffw/data/xmlwriter.h`
