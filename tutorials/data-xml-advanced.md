# Encode and decode XML

This tutorial will explain how to decode and encode XML structure the advanced way.

**The tutorial uses ffw::Var which is essential in the following examples. You must read [Var - JSON-like data structure](math-var.html) tutorial first!** 

Make sure you add `finedata` into your linker and add the following headers into your project:

```cpp
#include <ffw/math.h>
#include <ffw/data.h>
```

## Decoding

With this method, you can decode XML by step by step without using ffw::Var at all. It grants you the freedom you need. Any of the following commands (including constructor!) can throw ffw::XmlDecodeException at any time if the XML string is broken in any way. Exception is thrown if:

* XML syntax error
* trying to cast from into c++ data type when the XML value is something completely else (for example, XML value is clearly a string: \<ket\>Something\</key\> but you try to use node.toInt() when clearly node.isInt() gives you false)

Also, note that there is difference between integer, number, float:

* ffw::XmlReader::Node::isNumber returns true if the XML value is any kind of number (integer or float)
* ffw::XmlReader::Node::isInteger returns true if the number is not floating point (no decimal point)
* ffw::XmlReader::Node::isFloat returns true if the number is floating point (has decimal point)

Also, note that ffw::XmlReader::Node::isString returns always true, (but returns false if isEmptr() returns true!) even if toInteger returns true. This is due to the reason that in XML strings are not explicitly written (in syntax form) compared to JSON where we can exactly tell the value is a string.

[import:'example0'](../../examples/data/xml_advanced.cpp)

## Encoding

This method si very similar to the one above and again, it does not use ffw::Var at all. An exception is thrown if:

* xml tag name is invalid
* you call xml.stepOut() too many times
* you do not call xml.beginContent() before adding new object
* when there has been an error with the stream

ffw::XmlWriter supports arbitary stream, you can create one based on ffw::XmlWriter::Stream when you override one simple method. However, ffw::XmlWriter::StringStream and ffw::XmlWriter::FileStream are provided to you.

[import:'example1'](../../examples/data/xml_advanced.cpp)

Creates the following XML structure:

```xml
<menu id="file">
    <value>File</value>
    <popup>
        <menuitem value="New" onclick="CreateNewDoc()"/>
        <menuitem value="Open" onclick="OpenDoc()"/>
        <menuitem value="Close" onclick="CloseDoc()"/>
    </popup>
</menu>
```
