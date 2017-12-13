Attribute
===================================


**Inherits from:** [ffw::XmlReader::Value](ffw_XmlReader_Value.html)

The documentation for this class was generated from: `include/ffw/data/xmlreader.h`



## Public Functions

| Type | Name |
| -------: | :------- |
|   | [Attribute](#9945bcd7) ()  |
|   | [Attribute](#4803a394) (const tinyxml2::XMLAttribute * _node_)  |
|  virtual std::string | [name](#b7a13cc2) () const  |
|  virtual bool | [isObject](#b3c6566d) () const  |
|  virtual const char * | [rawCstr](#cc9cf53e) () const  |


## Public Functions Documentation

### _function_ <a id="9945bcd7" href="#9945bcd7">Attribute</a>

```cpp
inline  Attribute () 
```



### _function_ <a id="4803a394" href="#4803a394">Attribute</a>

```cpp
inline  Attribute (
    const tinyxml2::XMLAttribute * node
) 
```



### _function_ <a id="b7a13cc2" href="#b7a13cc2">name</a>

```cpp
virtual std::string name () const 
```



**Overrides:** [name](/doxygen/ffw_XmlReader_Value.md#26734a66) from class [Value](/doxygen/ffw_XmlReader_Value.md)

### _function_ <a id="b3c6566d" href="#b3c6566d">isObject</a>

```cpp
virtual bool isObject () const 
```



**Overrides:** [isObject](/doxygen/ffw_XmlReader_Value.md#b62b9097) from class [Value](/doxygen/ffw_XmlReader_Value.md)

### _function_ <a id="cc9cf53e" href="#cc9cf53e">rawCstr</a>

```cpp
virtual const char * rawCstr () const 
```



**Overrides:** [rawCstr](/doxygen/ffw_XmlReader_Value.md#a52ffb86) from class [Value](/doxygen/ffw_XmlReader_Value.md)



