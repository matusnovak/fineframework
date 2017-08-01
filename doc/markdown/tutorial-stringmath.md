Tutorial: Extra string functions
---------------------

This tutorial will explain how to use some of the additional components of math module regarding string manipulation. The tokenizer is inside of [math module](group__math.html) which is a header only library. All you need to do is to add `#include <ffw/math.h>` into your project.

### Extract filename/path information

Suppose you have a path to a file and you would like to get its filename and extension.

```cpp
std::string path = "C:\Some\Path\To\file.txt";

std::cout << "Directory: " << ffw::dirname(path) << std::endl;
std::cout << "Basename: " << ffw::basename(path) << std::endl;
std::cout << "Extension: " << ffw::extension(path) << std::endl;
// Prints:
// Directory: C:\Some\Path\To
// Basename: file
// Extension: txt
```

```cpp
// The following does exactly the same thing as above:
std::string path = "C:\Some\Path\To\file.txt";

auto info = ffw::getFileInfo(path);
std::cout << "Directory: " << info.dir << std::endl;
std::cout << "Basename: " << info.base << std::endl;
std::cout << "Extension: " << info.ext << std::endl;
// Prints:
// Directory: C:\Some\Path\To
// Basename: file
// Extension: txt
```

### Convert value to string and back

The ffw::stringToVal works only on integers and floating points!

```cpp
std::string msg = "The value is: ";
msg += ffw::valToString(42.05f);

std::cout << msg << std::endl;
// Prints: "The value is: 42.05"
```

To convert from string to any integer/float use ffw::valToString. Note that you have to supply a data type as a template parameter!

```cpp
int val = ffw::stringToVal<int>("-123456");
std::cout << val << std::endl;
// Prints: "-123456"
```

### Convert from hexadecimal string to int

```cpp
int val = ffw::hexToVal<int>("FFFF");
std::cout << val << std::endl;
// Prints: "65535"
```

### Convert UTF-8 to std::wstring and back

The std::wstring is not directly meant to be UTF-16 string. However, because wchar can hold up to 65535 (even more on Unix) it is perfect storage for decoding UTF-8 string. 

```cpp
// String containing 24 UTF-8 enchoded characters 
std::string str = "\x48\x65\x69\x7A\xC3\xB6\x6C\x72\xC3\xBC\x63\x6B\x73\x74\x6F\xC3\x9F\x61\x62\x64\xC3\xA4\x6D\x70\x66\x75\x6E\x67";

// Convert to multi byte string std::wstring
std::wstring wstr = ffw::utf8ToWstr(str);
std::cout << "Size: " << wstr.size() << std::endl;
std::cout << "5th symbol: " << (int)wstr[4] << std::endl;
// Prints:
// Size: 24
// 5th symbol: 246

// The 5th symbol is composed of two UTf-8 chars: 0xC3 0xB6
// Which is O-umlaut unicode character U+00F6
// https://en.wikipedia.org/wiki/%C3%96

// To convert back, use ffw::wstrToUtf8
std::string test = ffw::wstrToUtf8(wstr);

// Both the source string of UTF-8 characters and the
// "test" are equal!
std::cout << "Test: " << (test == str) << std::endl;
// Prints "1"
```

