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

### <span style="opacity:0.5;">function</span> <a id="9945bcd7" href="#9945bcd7">Attribute</a>

```cpp
inline  Attribute () 
```



### <span style="opacity:0.5;">function</span> <a id="4803a394" href="#4803a394">Attribute</a>

```cpp
inline  Attribute (
    const tinyxml2::XMLAttribute * node
) 
```



### <span style="opacity:0.5;">function</span> <a id="b7a13cc2" href="#b7a13cc2">name</a>

```cpp
virtual std::string name () const 
```



**Overrides:** [name](/doc/ffw_XmlReader_Value.md#26734a66)

### <span style="opacity:0.5;">function</span> <a id="b3c6566d" href="#b3c6566d">isObject</a>

```cpp
virtual bool isObject () const 
```



**Overrides:** [isObject](/doc/ffw_XmlReader_Value.md#b62b9097)

### <span style="opacity:0.5;">function</span> <a id="cc9cf53e" href="#cc9cf53e">rawCstr</a>

```cpp
virtual const char * rawCstr () const 
```



**Overrides:** [rawCstr](/doc/ffw_XmlReader_Value.md#a52ffb86)



