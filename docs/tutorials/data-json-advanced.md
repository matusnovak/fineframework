# Encode and decode JSON

This tutorial will explain how to decode and encode JSON structure the more complicated way.

**The tutorial uses ffw::Var which is essential in the following examples. You must read [Var - JSON-like data structure](math-var.html) tutorial first!**

Make sure you add `finedata` into your linker and add the following headers into your project:

```cpp
#include <ffw/math.h>
#include <ffw/data.h>
```

## Decoding

With this more complicated method, you can decode JSON by step by step without using ffw::Var at all. It grants you the freedom you need. Any of the following commands (except constructor!) can throw ffw::JsonDecodeException at any time if the JSON string is broken in any way. Exception is thrown if:

* JSON syntax error
* Unpexpected control or reserved character (for example \\p does not exist, but \\n \\t etc are all good)
* trying to cast from into c++ data type when the JSON value is something completely else (for example, JSON value is clearly a string: "key": "Hello World!" but if you try to use value.toInteger() throws)

Also, note that there is difference between integer, number, float:

* ffw::JsonReader::Node::isNumber returns true if the JSON value is any kind of number (integer or float)
* ffw::JsonReader::Node::isInteger returns true if the number is not floating point (no decimal point)
* ffw::JsonReader::Node::isFloat returns true if the number is floating point (has decimal point)

[import:'example0'](../../examples/data/json_advanced.cpp)

This method si very similar to the one above and again, it does not use ffw::Var at all. An exception is thrown if:

* adding a node into an object with NULL key
* you call xml.stepOut() too many times
* when there has been an error with the stream

ffw::JsonWriter supports arbitary stream, you can create one based on ffw::JsonWriter::Stream when you override one simple method. However, ffw::JsonWriter::StringStream and ffw::JsonWriter::FileStream are provided to you.

[import:'example1'](../../examples/data/json_advanced.cpp)

Creates the following JSON structure:

```json
{
    "menu":{
        "id":"file",
        "value":"File",
        "popup":{
            "menuitem":[
                {
                    "value":"New",
                    "onclick":"CreateNewDoc()"
                },
                {
                    "value":"Open",
                    "onclick":"OpenDoc()"
                },
                {
                    "value":"Close",
                    "onclick":"CloseDoc()"
                }
            ]
        }
    }
}
```
