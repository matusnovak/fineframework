---
search:
    keywords: ['ffw::XmlWriter::StringStream', 'StringStream', '~StringStream', 'write', 'get', 'write']
---

# class ffw::XmlWriter::StringStream



Inherits the following classes: **[ffw::XmlWriter::Stream](classffw_1_1_xml_writer_1_1_stream.md)**

## Public Functions

|Type|Name|
|-----|-----|
||[**StringStream**](classffw_1_1_xml_writer_1_1_string_stream.md#1af59212f3770f4db07ed235f19a936920) () |
|virtual |[**~StringStream**](classffw_1_1_xml_writer_1_1_string_stream.md#1a22b25bb7204c88acd9f040b9f9d310c1) () |
|virtual bool|[**write**](classffw_1_1_xml_writer_1_1_string_stream.md#1ace47f2efa0b65985d16b87ed61960556) (const char \* in, size\_t len) override |
|const std::string &|[**get**](classffw_1_1_xml_writer_1_1_string_stream.md#1ace8ef754d1573f4e4f304052e6d8bd1a) () const |


## Public Functions Documentation

### function <a id="1af59212f3770f4db07ed235f19a936920" href="#1af59212f3770f4db07ed235f19a936920">StringStream</a>

```cpp
ffw::XmlWriter::StringStream::StringStream ()
```



### function <a id="1a22b25bb7204c88acd9f040b9f9d310c1" href="#1a22b25bb7204c88acd9f040b9f9d310c1">~StringStream</a>

```cpp
virtual ffw::XmlWriter::StringStream::~StringStream ()
```



### function <a id="1ace47f2efa0b65985d16b87ed61960556" href="#1ace47f2efa0b65985d16b87ed61960556">write</a>

```cpp
virtual bool ffw::XmlWriter::StringStream::write (
    const char * in
    size_t len
)
```

Overrides **[XmlWriter::Stream::write](classffw_1_1_xml_writer_1_1_stream.md#1ac033af2cccf6d488b58d9dfe2de35206)**


### function <a id="1ace8ef754d1573f4e4f304052e6d8bd1a" href="#1ace8ef754d1573f4e4f304052e6d8bd1a">get</a>

```cpp
const std::string & ffw::XmlWriter::StringStream::get () const
```





----------------------------------------
The documentation for this class was generated from the following file: `include/ffw/data/xmlwriter.h`
