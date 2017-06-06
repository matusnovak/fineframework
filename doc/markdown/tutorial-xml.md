Encode and decode XML
-----------------------------------

This tutorial will explain how to decode and encode XML structure.

**The tutorial uses ffw::Var which is essential in the following examples. You must read [Var - JSON-like data structure](md_doc_markdown_tutorial-var.html) tutorial first!**

### Decode XML the easy way

When decoding a XML, values are converted into C++ specific data types:

* All nested objects (object that has at least one child) are converted into ffw::Object
* An object that has multiple children with a same tag name is converted into ffw::Array
* An object that does not have a child but has at least one attribute is also converted into ffw::Object
* An object that has children (or any kind of content) but also has attributes, all of it will go into ffw::Object, explained below
* Each value (both attributes and content) are tested if they represent a number (floating point or integer), or if they represent a boolean (true/false). However, in JSON, strings are explicitly encoded with quotes. In XML, that does not exist, so there is no simple way to delect if a value is supposed to be a string or something else. The algorithm tries to detect integers, floats, boolean, and if all that fails, it will mark a given value as string. For example: `<value>-123456</value>` is parsed as integer, but `<value>0x123456</value>` is treated as string.

All values (both attributes such as `id="file"` and content `<id>file</id>` ) are converted into C++ data types using ffw::Var

| XML Value/Node                           | C++ data type  |
| ---------------------------------------- | -------------- |
| \<menu\>\<popup\>...\</popup\>\</menu\>  | ffw::Object    |
| \<popup\>\<a\>\</a\>\<a\>\</a\>\<a\>\</a\>\</popup\> | ffw::Array *   |
| \<value\>Any kind of UTF-8 text\</value\> | std::string    |
| \<value\>-123456e+2\</value\>            | int            |
| \<value\>-1234.56e+2\</value\>           | float          |
| \<value\>true\</value\>                  | bool           |
| \<value\>null\</value\>                  | std::nullptr_t |
| \<value\>\</value\>                      | std::string ** |

* \* An object that contains multiple child objects with a same tag is converted into ffw::Array
* \*\* Empty node is converted into an empty std::string

Decoding can be done as the following:

```cpp
ffw::Var xml;
try {
  xml = ffw::decodeXml(
    "<menu id=\"file\" value=\"File\">"
      "<popup>"
        "<menuitem value=\"New\" onclick=\"CreateNewDoc()\" />"
        "<menuitem value=\"Open\" onclick=\"OpenDoc()\" />"
        "<menuitem value=\"Close\" onclick=\"CloseDoc()\" />"
      "</popup>"
    "</menu>"
  );
} catch (ffw::XmlDecodeException& e){
  std::cerr << "Error while decoding XML: " << e.what() << std::endl;
  return;
}

try {
  // Check if the root element is an object
  std::cout << xml.is<ffw::Object>() << std::endl;
  // Prints: "1"

  // Access key (returns a reference)
  std::cout << xml["menu"]["id"].getAs<std::string>() << std::endl;
  // Prints: "file"

  // Exactly same as above, but returns a copy instead
  std::cout << xml["menu"]["id"].toString() << std::endl;

  // Exactly same as above:
  std::cout << xml.getAs<ffw::Object>()["menu"].getAs<ffw::Object>()["id"].toString() << std::endl;
  // In the previous example, using ["key"] on ffw::Var 
  // will automatically call getAs<ffw::Object>()
  // Also, using [integer] on ffw::Var will do the same but will cast to ffw::Array

  // Access a chain of keys
  std::cout << xml["menu"]["popup"]["menuitem"][2]["value"].getAs<std::string>() << std::endl;
  // Prints: "Close"

  // Check if a specific value is array (can be used to detect int, float, etc...)
  std::cout << xml["menu"]["popup"]["menuitem"].is<ffw::Array>() << std::endl;
  // Prints: "1"

  // Get a reference for easier access
  ffw::Array& arr = xml["menu"]["popup"]["menuitem"].getAs<ffw::Array>();
  // Would throw std::bad_cast if the menuitem is an object instead

  // Access a value from arr
  std::cout << arr[2]["value"].getAs<std::string>() << std::endl;
  // Prints: "Close"

  // Access an incorrect data type from arr
  std::cout << arr[2]["value"].getAs<int>() << std::endl;
  // Throws std::bad_cast
  // Why? because 2nd menuitem's
  // "value" inside of <menuitem value="Open" onclick="OpenDoc()" />
  // is not an integer!

  // To use exceptions while getting keys, use at("key")
  // Throws std::out_of_range !!!!!
  std::cout << xml.getAs<ffw::Object>().at("menu").getAs<ffw::Object>().at("invalid").getAs<std::string>() << std::endl;
  
} catch (std::exception& e){
  std::cerr << "Something went wrong while accessing data: " << e.what() << std::endl;
}
```

Please note:

- If the decoding fails, an ffw::XmlDecodeException is thrown
- The [] operator with std::string assumes that you are trying to get ffw::Object
- The [] operator with int assumes that you are trying to get ffw::Array

### Encode XML the wasy way

The following code is a simple way to create a data structure using ffw::Var and encoding it as XML. Note that an exception can be thrown if:

- the root node of the data structure is not object, XML has to start with an object!
- any of the values contain invalid data type, only the following are valid: (ffw::Object, ffw::Array, any signed or unsigned integer, bool, std::string or const char*, any floating point). For example, you can not encode a C++ reference, or pointer, or class, etc...

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
  std::string str = ffw::encodeXml(obj, "    ", false);
  // If you wish to create compact XML (no new lines, no indent)
  // pass NULL as a second parameter!
  // To escape UTF-8 into unicode &#xXXXX; symbols, pass 'true'
  // as a third parameter
  
} catch (ffw::XmlEncodeException& e){
  std::cerr << "Something went wrong: " << e.what() << std::endl;
}
```

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

### Decode XML the complicated way

With this method, you can decode XML by step by step without using ffw::Var at all. It grants you the freedom you need. Any of the following commands (including constructor!) can throw ffw::XmlDecodeException at any time if the XML string is broken in any way. Exception is thrown if:

* XML syntax error
* trying to cast from into c++ data type when the XML value is something completely else (for example, XML value is clearly a string: \<ket\>Something\</key\> but you try to use node.toInt() when clearly node.isInt() gives you false)

Also, note that there is difference between integer, number, float:

- ffw::XmlReader::Node::isNumber returns true if the XML value is any kind of number (integer or float)
- ffw::XmlReader::Node::isInteger returns true if the number is not floating point (no decimal point)


- ffw::XmlReader::Node::isFloat returns true if the number is floating point (has decimal point)

Also, note that ffw::XmlReader::Node::isString returns always true, (but returns false if isEmptr() returns true!) even if toInteger returns true. This is due to the reason that in XML strings are not explicitly written (in syntax form) compared to JSON where we can exactly tell the value is a string.

```cpp
ffw::XmlReader xml(
  "<menu id=\"file\" value=\"\">"
    "<popup>"
      "<menuitem value=\"New\" onclick=\"CreateNewDoc()\" />"
      "<menuitem value=\"Open\" onclick=\"OpenDoc()\" />"
      "<menuitem value=\"Close\" onclick=\"CloseDoc()\" />"
    "</popup>"
  "</menu>"
);

try {
  ffw::XmlReader::Node node;
  ffw::XmlReader::Attribute attr;

  // Get "menu"
  xml.getNext(&node);
  std::cout << node.name() << std::endl; // Prints "menu"
  node.hasAttributes(); // Returns true

  node.getNextAttribute(&attr);
  attr.isString(); // Returns true
  attr.isEmpty(); // Returns false
  std::cout << attr.name() << "=" << attr.toString() << std::endl; 
  // Prints "id=file"

  node.getNextAttribute(&attr);
  std::cout << attr.isEmpty() << ", " << attr.isString() << std::endl;
  attr.isString(); // Returns false
  attr.isEmpty(); // Returns true

  // Go inside of "menu"
  xml.stepInto(&node);

  // Find "popup"
  xml.getNext(&node);
  std::cout << node.name() << std::endl; // Prints "popup"
  node.isObject(); // Returns true because it has many child nodes

  // Go inside of "popup"
  xml.stepInto(&node);

  // Find first "menuitem"
  xml.getNext(&node);
  std::cout << node.name() << std::endl; // Prints "menuitem"
  node.isObject(); // Returns false, no child nodes
  node.isEmpty(); // Returns true, does not contain anything
  node.hasAttributes(); // Returns true, the node has 2 attributes

  node.getNextAttribute(&attr);
  attr.isString(); // Returns true
  std::cout << attr.name() << "=" << attr.toString() << std::endl; 
  // Prints "value=New"

  node.getNextAttribute(&attr);
  attr.isString(); // Returns true
  std::cout << attr.name() << "=" << attr.toString() << std::endl; 
  // Prints "onclick=CreateNewDoc()"

  node.getNextAttribute(&attr); // Returns false, no another attribute
  // attr remains unmodified!

  // Go back into the parent node
  xml.stepOut();

  // Find second "menuitem"
  xml.getNext(&node);

  // Find third (last) "menuitem"
  xml.getNext(&node);

  xml.getNext(&node); // Returns false, no more neighbour nodes
} catch (ffw::XmlEncodeException& e){
  std::cerr << "Something went wrong: " << e.what() << std::endl;
}
```

### Encode XML the complicated way

This method si very similar to the one above and again, it does not use ffw::Var at all. An exception is thrown if:

* xml tag name is invalid
* you call xml.stepOut() too many times
* you do not call xml.beginContent() before adding new object
* when there has been an error with the stream

ffw::XmlWriter supports arbitary stream, you can create one based on ffw::XmlWriter::Stream when you override one simple method. However, ffw::XmlWriter::StringStream and ffw::XmlWriter::FileStream are provided to you.

```cpp
try {
  ffw::XmlWriter::StringStream stream;
  ffw::XmlWriter xml(&stream, "    ", false);
  // If you wish to create compact XML (no new lines, no indent)
  // pass NULL as a second parameter!
  // To escape UTF-8 into unicode &#xXXXX; symbols, pass 'true'
  // as a third parameter
  
  // Constructs <menu> with two attributes
  xml.addObject("menu");
  xml.addString("file", "id");
  // Ensures that the <menu> tag is properly closed!
  xml.beginContent();
  xml.addString("File", "value");

  // Constructs <popup> tag
  xml.addObject("popup");
  xml.beginContent();

  // Constricts first <menuitem> tag
  xml.addObject("menuitem");
  xml.addString("New", "value");
  xml.addString("CreateNewDoc()", "onclick");
  xml.stepOut();

  // Constricts second <menuitem> tag
  xml.addObject("menuitem");
  xml.addString("Open", "value");
  xml.addString("OpenDoc()", "onclick");
  xml.stepOut();

  // Constricts third <menuitem> tag
  xml.addObject("menuitem");
  xml.addString("Close", "value");
  xml.addString("CloseDoc()", "onclick");
  xml.stepOut();

  // Ends <popup> tag
  xml.stepOut();
  // Ends <menu> tag
  xml.stepOut();
  // We are done!
  
  // Any further call to xml.stepOut() would result in exception

  std::cout << stream.get() << std::endl;
  
} catch (ffw::XmlEncodeException& e){
  std::cerr << "Something went wrong: " << e.what() << std::endl;
}
```

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

