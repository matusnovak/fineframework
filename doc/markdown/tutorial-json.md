Encode and decode JSON
----------------------------------------

This tutorial will explain how to decode and encode JSON structure. 

**The tutorial uses ffw::Var which is essential in the following examples. You must read [Var - JSON-like data structure](md_doc_markdown_tutorial-var.html) tutorial first!**

### Decode JSON the easy way

When decoding a JSON, values are converted into C++ specific data types:

| JSON value  | C++ data type              |
| ----------- | -------------------------- |
| { }         | ffw::Object                |
| [ ]         | ffw::Array                 |
| "string"    | ffw::Var as std::string    |
| 123456      | ffw::Var as int            |
| 123.456e-10 | ffw::Var as float          |
| true false  | ffw::Var as bool           |
| null        | ffw::Var as std::nullptr_t |

The strings that contain unicode characters encoded as '\\uXXXX' will be converted into UTF-8 

Decoding can be done as the following:

```cpp
ffw::Var json;
try {
  json = ffw::decodeJson(
    "{\"menu\": {"
    "  \"id\": \"file\","
    "  \"value\": \"File\","
    "  \"popup\": {"
    "	  \"menuitem\": ["
    "	    {\"value\": \"New\", \"onclick\": \"CreateNewDoc()\"},"
    "	    {\"value\": \"Open\", \"onclick\": \"OpenDoc()\"},"
    "	    {\"value\": \"Close\", \"onclick\": \"CloseDoc()\"}"
    "	  ]"
    "  }"
    "}}"
  );
} catch (ffw::JsonDecodeException& e){
  std::cerr << "Error while decoding JSON: " << e.what() << std::endl;
  return;
}

try {
  // Check if the root element is an object
  std::cout << json.is<ffw::Object>() << std::endl;
  // Prints: "1"

  // Access key (returns a reference)
  std::cout << json["menu"]["id"].getAs<std::string>() << std::endl;
  // Prints: "file"

  // Exactly same as above, but returns a copy instead
  std::cout << json["menu"]["id"].toString() << std::endl;

  // Exactly same as above:
  std::cout << json.getAs<ffw::Object>()["menu"].getAs<ffw::Object>()["id"].toString() << std::endl;
  // In the previous example, using ["key"] on ffw::Var 
  // will automatically call getAs<ffw::Object>()
  // Also, using [integer] on ffw::Var will do the same but will cast to ffw::Array

  // Access a chain of keys
  std::cout << json["menu"]["popup"]["menuitem"][2]["value"].getAs<std::string>() << std::endl;
  // Prints: "Close"

  // Check if a specific value is array (can be used to detect int, float, etc...)
  std::cout << json["menu"]["popup"]["menuitem"].is<ffw::Array>() << std::endl;
  // Prints: "1"

  // Get a reference for easier access
  ffw::Array& arr = json["menu"]["popup"]["menuitem"].getAs<ffw::Array>();
  // Would throw std::bad_cast if the menuitem is an object instead

  // Access a value from arr
  std::cout << arr[2]["value"].getAs<std::string>() << std::endl;
  // Prints: "Close"

  // Access an incorrect data type from arr
  std::cout << arr[2]["value"].getAs<int>() << std::endl;
  // Throws std::bad_cast
  // Why? because 2nd menuitem's "value" inside of {"value": "Close", "onclick": "CloseDoc()"}
  // is not an integer!

  // To use exceptions while getting keys, use at("key")
  // Throws std::out_of_range  !!!!
  std::cout << json.getAs<ffw::Object>().at("menu").getAs<ffw::Object>().at("invalid").getAs<std::string>() << std::endl;

} catch (std::exception& e){
  std::cerr << "Something went wrong while accessing data: " << e.what() << std::endl;
}
```

Please note:

* If the decoding fails, an ffw::JsonDecodeException is thrown
* The [] operator with std::string assumes that you are trying to get ffw::Object
* The [] operator with int assumes that you are trying to get ffw::Array

### Encode JSON the easy way

The following code is a simple way to create a data structure using ffw::Var and encoding it as JSON. Note that an exception can be thrown if:

* the root node of the data structure is not object or array
* any of the values contain invalid data type, only the following are valid: (ffw::Object, ffw::Array, any signed or unsigned integer, bool, std::string or const char*, any floating point). For example, you can not encode a C++ reference, or pointer, or class, etc...

```cpp
ffw::Object obj = { 
  "menu", ffw::Object{
    {"id", "file",},
    {"value", "File",},
    {"popup", ffw::Object{
      {"menuitem", ffw::Array{
        ffw::Object{{"value", "New"}, {"onclick", "CreateNewDoc()"}},
        ffw::Object{{"value", "Open"}, {"onclick", "OpenDoc()"}},
        ffw::Object{{"value", "Close"}, {"onclick", "CloseDoc()"}}
      }},
    }},
  } 
};

try {
  std::string str = ffw::encodeJson(obj, "    ", false);
  // If you wish to create compact JSON (no new lines, no indent)
  // pass NULL as a second parameter!
  // To escape UTF-8 into unicode \uXXXX symbols, pass 'true'
  // as a third parameter
  
} catch (ffw::JsonEncodeException& e){
  std::cerr << "Something went wrong: " << e.what() << std::endl;
  return;
}
// To encode JSON in more compact way (no indent, no new lines) 
// replace second parameter with NULL
```

Will create the following equivalent JSON structure:

```json
{"menu": {
  "id": "file",
  "value": "File",
  "popup": {
	"menuitem": [
	  {"value": "New", "onclick": "CreateNewDoc()"},
	  {"value": "Open", "onclick": "OpenDoc()"},
	  {"value": "Close", "onclick": "CloseDoc()"}
	]
  }
}}
```

Please note:

* Characters such as new-line, quote, apostrophe, cariage-return will be escaped into '\\n', '\\"', '\\'', '\\r' and so on.

### Decode JSON the complicated way

With this method, you can decode JSON by step by step without using ffw::Var at all. It grants you the freedom you need. Any of the following commands (except constructor!) can throw ffw::JsonDecodeException at any time if the JSON string is broken in any way. Exception is thrown if:

* JSON syntax error
* Unpexpected control or reserved character (for example \\p does not exist, but \\n \\t etc are all good)
* trying to cast from into c++ data type when the JSON value is something completely else (for example, JSON value is clearly a string: "key": "Hello World!" but you try to use value.toInteger() when clearly value.isInteger() gives you false)

Also, note that there is difference between integer, number, float:

* ffw::JsonReader::Node::isNumber returns true if the JSON value is any kind of number (integer or float)
* ffw::JsonReader::Node::isInteger returns true if the number is not floating point (no decimal point)


* ffw::JsonReader::Node::isFloat returns true if the number is floating point (has decimal point)

```cpp
ffw::JsonReader json(
  "{\"menu\": {"
  "  \"id\": \"file\","
  "  \"value\": \"File\","
  "  \"popup\": {"
  "	  \"menuitem\": ["
  "	    {\"value\": \"New\", \"onclick\": \"CreateNewDoc()\"},"
  "	    {\"value\": \"Open\", \"onclick\": \"OpenDoc()\"},"
  "	    {\"value\": \"Close\", \"onclick\": \"CloseDoc()\"}"
  "	  ]"
  "  }"
  "}}"
);

try {
  ffw::JsonReader::Node value, key;

  // Find next available child node, in this case the root element
  json.getNext(&value, &key);
  // key remains unmodified as the root node has no key, only a value: {}

  // Go inside the root node
  json.stepInto(&value);
  json.getCurrentType(); // Returns ffw::JsonReader::Type::OBJECT

  // Find "menu" node
  json.getNext(&value, &key);
  std::cout << key.toString() << std::endl; // Prints: "menu"
  value.isObject(); // Returns true

  // Go inside the "menu" node
  json.stepInto(&value);
  json.getCurrentType(); // Returns ffw::JsonReader::Type::OBJECT

  // Find "id" node
  json.getNext(&value, &key);
  std::cout << key.toString() << std::endl; // Prints: "id"
  value.isString(); // Returns true
  value.isInteger(); // Returns false

  // Find "value"
  json.getNext(&value, &key);
  std::cout << key.toString() << std::endl; // Prints: "value"

  // Find "popup"
  json.getNext(&value, &key);
  std::cout << key.toString() << std::endl; // Prints: "popup"

  // No next node... Returns FALSE!
  // The value and key remains unmodified
  json.getNext(&value, &key);

  // Step inside of "popup"
  json.stepInto(&value);
  json.getCurrentType(); // Returns ffw::JsonReader::Type::OBJECT

  // Find "menuitem"
  json.getNext(&value, &key);
  std::cout << key.toString() << std::endl; // Prints: "menuitem"
  value.isArray(); // Returns true

  // Step inside of "menuitem"
  json.stepInto(&value);
  json.getCurrentType(); // Returns ffw::JsonReader::Type::ARRAY

  // Get next available node
  // Becuase we are inside of an array, the key remains unmodified!
  json.getNext(&value, &key);
  // json.getNext(&value, NULL); // You can pass NULL as a second parameter

  // Step inside the first node
  json.stepInto(&value);
  json.getCurrentType(); // Returns ffw::JsonReader::Type::OBJECT

  // Find first value, in this case it is "value"
  json.getNext(&value, &key);
  std::cout << key.toString() << std::endl; // Prints: "value"
  value.isString(); // Returns true
  std::cout << value.toString() << std::endl; // Prints: "New"

  // Go back one level up...
  json.stepOut();
  // We are back inside of "menuitem" array
  // The next call of getNext() will return value 
  // pointing to {"value": "Open", "onclick": "OpenDoc()"}
  // Calling the getNext() would then return the last object in the array.
  // If you call it once more time, it will return false as there is nothing left.
  // You can then use json.stepOut() to get back to the "popup" node.
} catch (ffw::JsonDecodeException& e){
  std::cerr << "Something went wrong: " << e.what() << std::endl;
}
```

### Encode JSON the complicated way

This method si very similar to the one above and again, it does not use ffw::Var at all. An exception is thrown if:

- adding a node into an object with NULL key
- you call xml.stepOut() too many times
- when there has been an error with the stream

ffw::JsonWriter supports arbitary stream, you can create one based on ffw::JsonWriter::Stream when you override one simple method. However, ffw::JsonWriter::StringStream and ffw::JsonWriter::FileStream are provided to you.

```cpp
try {
  ffw::JsonWriter::StringStream stream;
  ffw::JsonWriter json(&stream, "    ", false);
  // If you wish to create compact JSON (no new lines, no indent)
  // pass NULL as a second parameter!
  // To escape UTF-8 into unicode \uXXXX symbols, pass 'true'
  // as a third parameter

  // The root object, has no key!
  json.addObject(NULL);

  // Add menu object
  json.addObject("menu");
  json.addString("file", "id");
  json.addString("File", "value");

  // Add popup object
  json.addObject("popup");

  // Add menuitem array
  json.addArray("menuitem");

  // Add first object
  json.addObject(NULL); // Key is being ignored inside of array
  json.addString("New", "value");
  json.addString("CreateNewDoc()", "onclick");
  json.stepOut(); // Finish object

  // Add second object
  json.addObject(NULL); // Key is being ignored inside of array
  json.addString("Open", "value");
  json.addString("OpenDoc()", "onclick");
  json.stepOut(); // Finish object

  // Add third object
  json.addObject(NULL); // Key is being ignored inside of array
  json.addString("Close", "value");
  json.addString("CloseDoc()", "onclick");
  json.stepOut(); // Finish object

  // To properly finish decoding, we have to step back up to the root!
  // Otherwise the output would be invalid!
  json.stepOut(); // We are back at the "menuitem" array, close it
  json.stepOut(); // We are back at the "popup" object, close it
  json.stepOut(); // We are back at the "menu" object, close it
  json.stepOut(); // We are back at the the root, close it
  // We are done!
  
  // Any further call to json.stepOut() would result in exception

  std::cout << stream.get() << std::endl;
} catch (ffw::JsonEncodeException& e){
  std::cerr << "Something went wrong: " << e.what() << std::endl;
}
```

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

