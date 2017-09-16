XmlReader
===================================


The documentation for this class was generated from: `include/ffw/data/xmlreader.h`

## Detailed description

doc/markdown/tutorial-xml.md 


## Classes

| Name |
|:-----|
| class [ffw::XmlReader::Attribute](ffw_XmlReader_Attribute.html) |
| struct [ffw::XmlReader::Cache](ffw_XmlReader_Cache.html) |
| class [ffw::XmlReader::Node](ffw_XmlReader_Node.html) |
| class [ffw::XmlReader::Value](ffw_XmlReader_Value.html) |


## Public Types

| Type | Name |
| -------: | :------- |
| enum | [Type](#ed4bf013) |


## Public Functions

| Type | Name |
| -------: | :------- |
|   | [XmlReader](#c958e25e) (const std::string & _input_)  |
|   | [XmlReader](#a9efd3bc) (const char * _input_)  |
|  virtual  | [~XmlReader](#67f9fe97) ()  |
|  bool | [getNext](#c7494114) ([Node](ffw_XmlReader_Node.html) * _value_)  |
|  bool | [stepInto](#1ff81599) (const [Node](ffw_XmlReader_Node.html) * _node_)  |
|  bool | [stepOut](#d5c48c7f) ()  |


## Public Types Documentation

### <span style="opacity:0.5;">enum</span> <a id="ed4bf013" href="#ed4bf013">Type</a>

```cpp
enum Type {
    OBJECT,
    INTEGER,
    FLOAT,
    BOOLEAN,
    STRING,
    NULLVAL,
    EMPTY,
    INVALID,
}
```





## Public Functions Documentation

### <span style="opacity:0.5;">function</span> <a id="c958e25e" href="#c958e25e">XmlReader</a>

```cpp
 XmlReader (
    const std::string & input
) 
```



### <span style="opacity:0.5;">function</span> <a id="a9efd3bc" href="#a9efd3bc">XmlReader</a>

```cpp
 XmlReader (
    const char * input
) 
```



### <span style="opacity:0.5;">function</span> <a id="67f9fe97" href="#67f9fe97">~XmlReader</a>

```cpp
virtual  ~XmlReader () 
```



### <span style="opacity:0.5;">function</span> <a id="c7494114" href="#c7494114">getNext</a>

```cpp
bool getNext (
    Node * value
) 
```



### <span style="opacity:0.5;">function</span> <a id="1ff81599" href="#1ff81599">stepInto</a>

```cpp
bool stepInto (
    const Node * node
) 
```



### <span style="opacity:0.5;">function</span> <a id="d5c48c7f" href="#d5c48c7f">stepOut</a>

```cpp
bool stepOut () 
```





