# Decode CSV - Advanced

This tutorial will explain how to decode CSV structure using more advanced method with more control. 

**The tutorial uses ffw::Var which is essential in the following examples. You must read [Var - JSON-like data structure](math-var.html) tutorial first!**

Make sure you add `finedata` into your linker and add the following headers into your project:

```cpp
#include <ffw/math.h>
#include <ffw/data.h>
```

[import:'example0'](../../examples/data/csv_advanced.cpp)

You can also use `openFromData` which acceps a raw string instead. The `getRow` acceps one parameter, in which if you pass true it will convert all items into their type (integer, float, std::string, bool). If you pass false no conversion is performed and everything is stored in ffw::Array as std::string.

[import:'example1'](../../examples/data/csv_advanced.cpp)

The function ffw::CsvLoader::tokenize acceps std::string in which you specify the start and the end. Via the 4th parameter you tell it to either decode (true) values into integers, floats, string, etc... or leave everything (false) as std::string. The 5th and 6th specify how are items separated from each other and how are string expressed. Usually in CSV files the items are separated with a comma and strings are enclosed in double quotation marks. 
