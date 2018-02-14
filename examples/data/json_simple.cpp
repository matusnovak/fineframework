#include <ffw/math.h>
#include <ffw/data.h>
#include <cassert>

int main() {

    // Decoding JSON

    //! [example0]
    ffw::Any json;
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
        assert(false);
    }

    try {
        // Check if the root element is an object
        assert(json.is<ffw::Object>() == true);

        // Check the type of key
        assert(json["menu"]["id"].is<const char*>() == false);
        assert(json["menu"]["id"].is<std::string>() == true);

        // Access key (returns a reference)
        assert(json["menu"]["id"].getAs<std::string>() == "file");

        // Exactly same as above:
        assert(json.getAsObject()["menu"].getAsObject()["id"].toString() == "file");
        // In the previous example, using ["key"] on ffw::Any 
        // will automatically call getAsObject()
        // Also, using [integer] on ffw::Any will do the same but will cast to ffw::Array

        // Access a chain of keys
        assert(json["menu"]["popup"]["menuitem"][2]["value"].getAs<std::string>() == "Close");

        // Check if a specific value is array (can be used to detect int, float, etc...)
        assert(json["menu"]["popup"]["menuitem"].is<ffw::Array>() == true);

        // Get a reference for easier access
        ffw::Array& arr = json["menu"]["popup"]["menuitem"].getAsArray();
        // Would throw std::bad_cast if the menuitem is an object instead

        // Access a value from arr
        assert(arr[2]["value"].getAs<std::string>() == "Close");

        // Access an incorrect data type from arr
        try {
            int test = arr[2]["value"].getAs<int>();
            assert(false);
        } catch (std::bad_cast& e) {
            (void)e;
        }
        // Throws std::bad_cast
        // Why? because 2nd menuitem's "value" inside of {"value": "Close", "onclick": "CloseDoc()"}
        // is not an integer!
        // However, using the [string] operator creates an empty object at given key

        // To use exceptions while getting keys, use at("key")
        try {
            // Throws std::out_of_range  !!!!
            json.getAsObject().at("menu").getAsObject().at("invalid").getAs<std::string>();
            assert(false);
        } catch (std::out_of_range& e) {
            (void)e;
        }

    } catch (std::exception& e){
        std::cerr << "Something went wrong while accessing data: " << e.what() << std::endl;
        assert(false);
    }
    //! [example0]

    // Encoding JSON

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
        std::string jsonStr = ffw::encodeJson(obj, "    ", false);
        // If you wish to create compact JSON (no new lines, no indent)
        // pass NULL as a second parameter!
        // The size of the indent per one level is equal to the string passed as 2nd parameter.
        // To escape UTF-8 into unicode \uXXXX symbols, pass 'true'
        // as a third parameter

        std::cout << "Encoded JSON:" << std::endl << jsonStr << std::endl;

        ffw::Object test = ffw::decodeJson(jsonStr).getAsObject();
        assert(test["menu"]["popup"]["menuitem"][2]["onclick"].toString() == "CloseDoc()");
  
    } catch (ffw::JsonEncodeException& e){
        std::cerr << "Something went wrong: " << e.what() << std::endl;
        assert(false);
    }
    //! [example1]

    return 0;
}
