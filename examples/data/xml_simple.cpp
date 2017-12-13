#include <ffw/math.h>
#include <ffw/data.h>
#include <cassert>

int main() {

	// Decoding XML

	//! [example0]
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
		assert(false);
	}

	try {
		// Check if the root element is an object
		assert(xml.is<ffw::Object>() == true);

		// Access key (returns a reference)
		std::string& id = xml["menu"]["id"].getAs<std::string>();
		assert(id == "file");

		// Exactly same as above, but returns a copy instead
		assert(xml["menu"]["id"].toString() == "file");

		// Exactly same as above:
		assert(xml.getAs<ffw::Object>()["menu"].getAs<ffw::Object>()["id"].toString() == "file");
		// In the previous example, using ["key"] on ffw::Var 
		// will automatically call getAs<ffw::Object>()
		// Also, using [integer] on ffw::Var will do the same but will cast to ffw::Array

		// Access a chain of keys
		assert(xml["menu"]["popup"]["menuitem"][2]["value"].getAs<std::string>() == "Close");

		// Check if a specific value is array (can be used to detect int, float, etc...)
		assert(xml["menu"]["popup"]["menuitem"].is<ffw::Array>() == true);

		// Get a reference for easier access
		ffw::Array& arr = xml["menu"]["popup"]["menuitem"].getAs<ffw::Array>();
		// Would throw std::bad_cast if the menuitem is an object instead

		// Access a value from arr
		assert(arr[2]["value"].getAs<std::string>() == "Close");
		// Prints: "Close"

		// Access an incorrect data type from arr
		try {
			// Throws std::bad_cast
			std::cout << arr[2]["value"].getAs<int>() << std::endl;
			assert(false);
		} catch (std::bad_cast& e) {
			(void)e;
		}
		// Why? because 2nd menuitem's
		// "value" inside of <menuitem value="Open" onclick="OpenDoc()" />
		// is not an integer!

		// To use exceptions while getting keys, use at("key")
		try {
			// Throws std::out_of_range !!!!!
			std::cout << xml.getAs<ffw::Object>().at("menu").getAs<ffw::Object>().at("invalid").getAs<std::string>() << std::endl;
		} catch (std::out_of_range& e) {
			(void)e;
		}
  
	} catch (std::exception& e){
		std::cerr << "Something went wrong while accessing data: " << e.what() << std::endl;
		assert(false);
	}
	//! [example0]

	// Encoding XML

	//! [example1]
	ffw::Object obj = { 
		"menu", ffw::Object{
			{"id", "file",},
			{"value", "File",},
			{"popup", ffw::Object{
				{"menuitem", ffw::Array{
					ffw::Object{ {"value", "New"}, {"onclick", "CreateNewDoc()"} },
					ffw::Object{ {"value", "Open"}, {"onclick", "OpenDoc()"} },
					ffw::Object{ {"value", "Close"}, {"onclick", "CloseDoc()"} }
				}
				},
			}
			},
		} 
	};

	try {
		std::string xmlStr = ffw::encodeXml(obj, "    ", false);
		// If you wish to create compact XML (no new lines, no indent)
		// pass NULL as a second parameter!
		// To escape UTF-8 into unicode &#xXXXX; symbols, pass 'true'
		// as a third parameter

		std::cout << xmlStr << std::endl;

		ffw::Object test = ffw::decodeXml(xmlStr).getAs<ffw::Object>();
		assert(test["menu"]["popup"]["menuitem"][2]["onclick"].toString() == "CloseDoc()");
  
	} catch (ffw::XmlEncodeException& e){
		std::cerr << "Something went wrong: " << e.what() << std::endl;
		assert(false);
	}
	//! [example1]

	return 0;
}