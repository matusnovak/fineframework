Tutorial: Decode CSV 
--------------------

This tutorial will explain how to decode CSV structure. 

**The tutorial uses ffw::Var which is essential in the following examples. You must read [Var - JSON-like data structure](md_doc_markdown_tutorial-var.html) tutorial first!**

Make sure you add `finedata` into your linker and add the following headers into your project:

```cpp
#include <ffw/math.h>
#include <ffw/data.h>
```

### Decode CSV with one function

```cpp
// Make sure the lines are separated by \n !!!
std::string str =
	"Year,Make,Model,length\n\
	1997,Ford,E350,2.34\n\
	2000,Mercury,Cougar,2.38";

ffw::Array arr = ffw::decodeCsv(str);
// No exceptions here!
```

This will return an ffw::Array that contains multiple ffw::Array (s). 

```cpp
std::cout << arr.size() << std::endl;
```

This will print number 3 as there are only 3 lines in the source CSV. it is guaranteed that each element of the `arr` will contain ffw::Array and nothing else!

```cpp
std::cout << arr[0].size() << std::endl;
```

This will print number 4 becuase there are 4 items in the first row. Now, to access individual items...

```cpp
// We do not care about the first row, it's a header... 
// Most CSV files contain a header

// Returns false becuase the "1997" is not a string
arr[1][0].is<std::string>(); // arr[1][0].isString(); also works!

// This returns true:
arr[1][0].is<int>(); // arr[1][0].isInt(); also works!

// Prints "Cougar length: 2.38"
std::cout << "Cougar length: " << arr[2][3].getAs<float>() << std::endl;

// However, this will throw std::bad_cast
std::cout << "Cougar length: " << arr[2][3].getAs<int>() << std::endl;
```

Why the following two lines below are equal?

```cpp
std::cout << arr[2].getAs<ffw::Array>()[3].getAs<float>() << std::endl;
std::cout << arr[2][3].getAs<float>() << std::endl;
```

In the first line, `arr` is already ffw::Array. However, ffw::Array holds ffw::Var which can hold any c++ data type. We know that ffw::decodeCsv returns array of arrays, so it is safe to explicitly call `getAs<ffw::Array>()`. The `[3]` returns 4th element and `getAs<float>()` gives us a reference to the float.

The second line does exactly same thing. The ffw::Var contains two [ ] operators, one for integers, one for strings. If you call the operator with an integer, it will assume you are trying to get ffw::Array and it will call `getAs<ffw::Array>()` and `[int]` at the same time for you... it's just for simplicitly. If you would put a string inside the [ ] operator, it will call `getAs<ffw::Object>()` which throws std::bad_cast because in this example we are dealing with arrays only, no objects.

### Decode CSV line by line

```cpp
ffw::Array output;
ffw::CsvLoader loader;

// First param: file path
// Second param: delimiter (some CSV use ;) default: ,
// Third param: how are string represented? default: "
if(!loader.openFromFile("file.csv", ',', '\"')){
  std::cerr << "File failed to open!" << std::endl;
}
else {
  while(!loader.eof()){
    output = loader.getRow(true);
  }
}
```

You can also use `openFromData` which acceps a string instead. The `getRow` acceps one parameter, a boolean. If you pass true, it will convert all items into their type (integer, float, std::string, bool). If you pass false, no conversion is performed and everything is stored in ffw::Array as std::string.

### Decode CSV one line only

```cpp
std::string str = "1999,Chevy,\"Venture \"\"Extended Edition, Very Large\"\"\",,5000.00";
ffw::Array arr = ffw::CsvLoader::tokenize(str, 0, str.size(), true, ',', '\"');
```

The function (static function!) acceps std::string in which you specify the start and the end. Via the 4th parameter you tell it to either decode (true) values into integers, floats, string, etc... or leave everything (false) into std::string. The 5th and 6th specify how are items separated from each other and how are string expressed. Usually in CSV files the items are separated with a comma and strings are enclosed in quotation marks. 