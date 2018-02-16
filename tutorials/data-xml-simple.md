# Encode and decode XML

This tutorial will explain how to decode and encode XML structure.

**The tutorial uses ffw::Any which is essential in the following examples. You must read [Any - JSON-like data structure](math-var.html) tutorial first!** 

Make sure you add `finedata` into your linker and add the following headers into your project:

```cpp
#include <ffw/math.h>
#include <ffw/data.h>
```

## Decoding

When decoding a XML, values are converted into C++ specific data types:

* All nested objects (object that has at least one child) are converted into ffw::Object
* An object that has multiple children with a same tag name is converted into ffw::Array
* An object that does not have a child but has at least one attribute is also converted into ffw::Object
* An object that has children (or any kind of content) but also has attributes, all of it will go into ffw::Object, explained below
* Each value (both attributes and content) are tested if they represent a number (floating point or integer), or if they represent a boolean (true/false). However, in JSON, strings are explicitly encoded with quotes. In XML, that does not exist, so there is no simple way to delect if a value is supposed to be a string or something else. The algorithm tries to detect integers, floats, boolean, and if all that fails, it will mark a given value as string. For example: `<value>-123456</value>` is parsed as integer, but `<value>0x123456</value>` is treated as string.

All values (both attributes such as `id="file"` and content `<id>file</id>` ) are converted into C++ data types using ffw::Any

| XML Value/Node                        | C++ data type              |
| ------------------------------------- | -------------------------- |
| `<menu><popup>...</popup></menu>`       | ffw::Any as ffw::Object    |
| `<popup><a></a><a></a><a></a></popup>`  | ffw::Any as ffw::Array [1]   |
| `<value>Any kind of UTF-8 text</value>` | ffw::Any as std::string    |
| `<value>-123456e+2</value>`             | ffw::Any as int            |
| `<value>-1234.56e+2</value>`            | ffw::Any as float          |
| `<value>true</value>`                   | ffw::Any as bool           |
| `<value>null</value>`                   | ffw::Any as std::nullptr_t type |
| `<value></value>`                       | ffw::Any as std::string [2] |

* [1] An object that contains multiple child objects with a same tag is converted into ffw::Array
* [2] Empty node is converted into an empty std::string

Decoding can be done as the following:

[import:'example0'](../../examples/data/xml_simple.cpp)

Please note:

* If the decoding fails, an ffw::XmlDecodeException is thrown
* The [] operator with std::string assumes that you are trying to get ffw::Object
* The [] operator with int assumes that you are trying to get ffw::Array

## Encoding

The following code is a simple way to create a data structure using ffw::Any and encoding it as XML. Note that an exception can be thrown if:

* the root node of the data structure is not object, XML has to start with an object!
* any of the values contain invalid data type, only the following are valid: (ffw::Object, ffw::Array, any signed or unsigned integer, bool, std::string or const char*, any floating point). For example, you can not encode a C++ reference, or pointer, or class, etc...

[import:'example1'](../../examples/data/xml_simple.cpp)

Will create the following equivalent XML structure:

```xml
<menu>
    <id>file</id>
    <value>File</value>
    <popup>
        <menuitem>
            <value>New</value>
            <onclick>CreateNewDoc()</onclick>
        </menuitem>
        <menuitem>
            <value>Open</value>
            <onclick>OpenDoc()</onclick>
        </menuitem>
        <menuitem>
            <value>Close</value>
            <onclick>CloseDoc()</onclick>
        </menuitem>
    </popup>
</menu>
```
