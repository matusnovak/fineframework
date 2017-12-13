#include <ffw/math.h>
#include <ffw/data.h>
#include <cassert>

int main() {

	// Decoding JSON

	//! [example0]
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
		assert(json.getCurrentType() == ffw::JsonReader::Type::OBJECT);

		// Find "menu" node
		json.getNext(&value, &key);
		assert(key.toString() == "menu");
		assert(value.isObject() == true); // Returns true

		// Go inside the "menu" node
		json.stepInto(&value);
		assert(json.getCurrentType() == ffw::JsonReader::Type::OBJECT);

		// Find "id" node
		json.getNext(&value, &key);
		assert(key.toString() == "id");
		assert(value.isString() == true); // Returns true
		assert(value.isInteger() == false); // Returns false

		// Find "value"
		json.getNext(&value, &key);
		assert(key.toString() == "value");

		// Find "popup"
		json.getNext(&value, &key);
		assert(key.toString() == "popup");

		// No next node... Returns FALSE!
		// The value and key remains unmodified
		json.getNext(&value, &key);

		// Step inside of "popup"
		json.stepInto(&value);
		assert(json.getCurrentType() == ffw::JsonReader::Type::OBJECT);

		// Find "menuitem"
		json.getNext(&value, &key);
		assert(key.toString() == "menuitem");
		assert(value.isArray() == true); // Returns true

		// Step inside of "menuitem"
		json.stepInto(&value);
		assert(json.getCurrentType() == ffw::JsonReader::Type::ARRAY);

		// Get next available node
		// Becuase we are inside of an array, the key remains unmodified!
		json.getNext(&value, &key);
		// json.getNext(&value, NULL); // You can pass NULL as a second parameter

		// Step inside the first node
		json.stepInto(&value);
		assert(json.getCurrentType() == ffw::JsonReader::Type::OBJECT);

		// Find first value, in this case it is "value"
		json.getNext(&value, &key);
		assert(key.toString() == "value"); // Prints: "value"
		value.isString(); // Returns true
		assert(value.toString() == "New");

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
		assert(false);
	}
	//! [example0]

	// Encoding JSON

	//! [example1]
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

		std::string jsonStr = stream.get();
		std::cout << jsonStr << std::endl;

		ffw::Object test = ffw::decodeJson(jsonStr).getAs<ffw::Object>();
		assert(test["menu"]["popup"]["menuitem"][2]["onclick"].toString() == "CloseDoc()");

	} catch (ffw::JsonEncodeException& e){
		std::cerr << "Something went wrong: " << e.what() << std::endl;
		assert(false);
	}
	//! [example1]

	return 0;
}