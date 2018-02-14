#include <ffw/data.h>
#define CATCH_CONFIG_MAIN
#include "../catch.hpp"
#include <cstdio>
#include <ctime>

static std::clock_t startTime, endTime;

static void timerStart() {
    startTime = clock();
}

static void timerEnd() {
    endTime = clock();
}

static double timerGetSeconds() {
    return (endTime - startTime) / (double) CLOCKS_PER_SEC;
}

static bool compare(const ffw::Any& a, const ffw::Any& b, bool verbose) {
    if (a.empty() && b.empty())return true;
    else if (a.empty() || b.empty())return false;

    if (a.isBool() && b.isBool()) {
        if (a.toBool() == b.toBool())return true;
        else {
            if(verbose)std::cerr << "Boolean mismatch: " << a.toBool() << " vs " << b.toBool() << std::endl;
            return false;
        }
    }

    if (a.isInt() && b.isInt()) {
        if (a.toInt() == b.toInt())return true;
        else {
            if(verbose)std::cerr << "Integer mismatch: " << a.toInt() << " vs " << b.toInt() << std::endl;
            return false;
        }
    }

    if (a.isFloat() && b.isFloat()) {
        if (std::abs(a.toFloat() - b.toFloat()) < 0.0001f)return true;
        else {
            if(verbose)std::cerr << "Float mismatch: " << a.toFloat() << " vs " << b.toFloat() << std::endl;
            return false;
        }
    }

    if (a.isString() && b.isString()) {
        if (a.toString() == b.toString())return true;
        else {
            if(verbose)std::cerr << "String mismatch: " << a.toString() << " vs " << b.toString() << std::endl;
            return false;
        }
    }

    if (a.is<ffw::Object>() && b.is<ffw::Object>()) {
        auto ao = a.getAsObject();
        auto bo = b.getAsObject();

        // Check if both have same amount of pairs
        if (ao.size() != bo.size()) {
            if(verbose)std::cerr << "Objects do not have same size! " << ao.size() << " vs " << bo.size() << std::endl;
            return false;
        }

        for (const auto pair : ao) {
            // Check if both have key
            if (!bo.has_key(pair.first)) {
                if(verbose)std::cerr << "Key \"" << pair.first << "\" is missing!" << std::endl;
                return false;
            }

            if (!compare(pair.second, bo.at(pair.first), verbose)) {
                if(verbose)std::cerr << "Key \"" << pair.first << "\" has a mismatch!" << std::endl;
                return false;
            }

        }

        return true;
    }

    if (a.is<ffw::Array>() && b.is<ffw::Array>()) {
        auto ao = a.getAsArray();
        auto bo = b.getAsArray();

        // Check if both have same amount of pairs
        if (ao.size() != bo.size()) {
            if(verbose)std::cerr << "Arrays do not have same size! " << ao.size() << " vs " << bo.size() << std::endl;
            return false;
        }

        for (size_t i = 0; i < ao.size(); i++){
            if (!compare(ao[i], bo[i], verbose)) {
                if(verbose)std::cerr << "Element " << i << " has a mismatch!" << std::endl;
                return false;
            }
        }

        return true;
    }

    if (verbose)std::cerr << "Data type mismatch! First: " << a.getTypeid().name() << " second: " << b.getTypeid().name() << std::endl;
    return false;
}

TEST_CASE("Comparator #1", "[JSON]") {
    ffw::Object a = {
        {"integer", 123},
        {"float", 0.123f},
        {"boolean", true},
        {"string", "Hello World!"},
        {"object", ffw::Object{{"first", 10}, {"second", 20}}},
        {"array", ffw::Array{10, 20}},
    };

    ffw::Object b = {
        {"integer", 999999},
        {"float", 0.123f},
        {"boolean", true},
        {"string", "Hello World!"},
        {"object", ffw::Object{{"first", 10}, {"second", 20}}},
        {"array", ffw::Array{10, 20}},
    };

    REQUIRE_NOTHROW(REQUIRE(a["integer"].toInt() == 123));
    REQUIRE_NOTHROW(REQUIRE(a["float"].toFloat() == Approx(0.123f)));
    REQUIRE_NOTHROW(REQUIRE(a["object"]["second"].toInt() == 20));

    REQUIRE(compare(a, a, true) == true);
    REQUIRE(compare(a, b, false) == false);
}

TEST_CASE("Decode JSON braces #1", "[JSON]") {
    std::string str = "[[{}]]";
    ffw::JsonReader json(str);
    ffw::JsonReader::Node node;
    REQUIRE(json.getNext(&node, NULL) == true);
    REQUIRE(node.ptr != NULL);
    REQUIRE(node.str() == "[[{}]]");
    REQUIRE(json.getCurrentType() == ffw::JsonReader::Type::ARRAY);
    // REQUIRE(json.getNext(&node, NULL) == false); TODO
    // Sometimes returns true?!
}

TEST_CASE("Decode JSON braces #2", "[JSON]") {
    ffw::JsonReader json("   [  [{}]  ]   ");
    ffw::JsonReader::Node node;
    REQUIRE(json.getNext(&node, NULL) == true);
    REQUIRE(node.ptr != NULL);
    REQUIRE(node.str() == "[  [{}]  ]");
    REQUIRE(json.getCurrentType() == ffw::JsonReader::Type::ARRAY);
    REQUIRE(json.getNext(&node, NULL) == false);
}

TEST_CASE("Decode JSON step into #1", "[JSON]") {
    ffw::JsonReader json("   [  [ { }]  ]   ");
    ffw::JsonReader::Node node;
    REQUIRE(json.getNext(&node, NULL) == true);
    REQUIRE(node.str() == "[  [ { }]  ]");
    REQUIRE(json.getCurrentType() == ffw::JsonReader::Type::ARRAY);

    REQUIRE(json.stepInto(&node));
    REQUIRE(json.getNext(&node, NULL) == true);
    REQUIRE(node.str() == "[ { }]");
    REQUIRE(json.getCurrentType() == ffw::JsonReader::Type::ARRAY);


    REQUIRE(json.stepInto(&node));
    REQUIRE(json.getNext(&node, NULL) == true);
    REQUIRE(node.str() == "{ }");
    REQUIRE(json.getCurrentType() == ffw::JsonReader::Type::ARRAY);

    REQUIRE(json.stepInto(&node));
    REQUIRE(json.getCurrentType() == ffw::JsonReader::Type::OBJECT);

    REQUIRE(json.getNext(&node, NULL) == false);
}

TEST_CASE("Decode JSON commas #1", "[JSON]") {
    static const char* str = "[{},{},{},{}]";
    ffw::JsonReader json(str);
    ffw::JsonReader::Node node;

    REQUIRE(json.getNext(&node, NULL) == true);
    REQUIRE(json.getCurrentType() == ffw::JsonReader::Type::ARRAY);
    REQUIRE(node.str() == "[{},{},{},{}]");

    REQUIRE(json.getNext(&node, NULL) == false);

    REQUIRE(json.stepInto(&node));
    REQUIRE(json.getCurrentType() == ffw::JsonReader::Type::ARRAY);
    REQUIRE(json.getNext(&node, NULL) == true);
    REQUIRE(node.str() == "{}");
    REQUIRE(node.ptr == &str[1]);

    REQUIRE(json.getNext(&node, NULL) == true);
    REQUIRE(node.str() == "{}");
    REQUIRE(node.ptr == &str[4]);

    REQUIRE(json.getNext(&node, NULL) == true);
    REQUIRE(node.str() == "{}");
    REQUIRE(node.ptr == &str[7]);

    REQUIRE(json.getNext(&node, NULL) == true);
    REQUIRE(node.str() == "{}");
    REQUIRE(node.ptr == &str[10]);

    REQUIRE(json.getNext(&node, NULL) == false);

}

TEST_CASE("Decode JSON commas #2", "[JSON]") {
    static const char* str = "[  {  }  ,  {  }  ,  [  ]  ,  {  }  ]";
    ffw::JsonReader json(str);
    ffw::JsonReader::Node node;

    REQUIRE(json.getNext(&node, NULL) == true);
    REQUIRE(json.getCurrentType() == ffw::JsonReader::Type::ARRAY);
    REQUIRE(node.str() == "[  {  }  ,  {  }  ,  [  ]  ,  {  }  ]");

    REQUIRE(json.getNext(&node, NULL) == false);

    REQUIRE(json.stepInto(&node));
    REQUIRE(json.getCurrentType() == ffw::JsonReader::Type::ARRAY);
    REQUIRE(json.getNext(&node, NULL) == true);
    REQUIRE(node.str() == "{  }");
    REQUIRE(node.ptr == &str[3]);

    REQUIRE(json.getNext(&node, NULL) == true);
    REQUIRE(node.str() == "{  }");
    REQUIRE(node.ptr == &str[12]);

    REQUIRE(json.getNext(&node, NULL) == true);
    REQUIRE(node.str() == "[  ]");
    REQUIRE(node.ptr == &str[21]);

    REQUIRE(json.getNext(&node, NULL) == true);
    REQUIRE(node.str() == "{  }");
    REQUIRE(node.ptr == &str[30]);

    REQUIRE(json.getNext(&node, NULL) == false);
    
}

TEST_CASE("Decode JSON invalid commas #1", "[JSON]") {
    static const char* str = "[  {  }     {  }     [  ]     {  }  ]";
    ffw::JsonReader json(str);
    ffw::JsonReader::Node node;

    REQUIRE(json.getNext(&node, NULL) == true);
    REQUIRE(json.getCurrentType() == ffw::JsonReader::Type::ARRAY);
    REQUIRE(node.str() == "[  {  }     {  }     [  ]     {  }  ]");

    REQUIRE(json.stepInto(&node));
    REQUIRE(json.getCurrentType() == ffw::JsonReader::Type::ARRAY);
    REQUIRE_THROWS(json.getNext(&node, NULL));
}

TEST_CASE("Decode JSON qutation marks #1", "[JSON]") {
    ffw::JsonReader json("[ [   \"hello\"  ,    \"world\"   ] ]");
    ffw::JsonReader::Node node;
    REQUIRE(json.getNext(&node, NULL) == true);
    REQUIRE(node.ptr != NULL);
    REQUIRE(node.str() == "[ [   \"hello\"  ,    \"world\"   ] ]");
    REQUIRE(json.getCurrentType() == ffw::JsonReader::Type::ARRAY);

    REQUIRE(json.getNext(&node, NULL) == false);

    REQUIRE(json.stepInto(&node));
    REQUIRE(json.getCurrentType() == ffw::JsonReader::Type::ARRAY);

    REQUIRE(json.getNext(&node, NULL) == true);
    REQUIRE(node.str() == "[   \"hello\"  ,    \"world\"   ]");

    REQUIRE(json.stepInto(&node));
    REQUIRE(json.getCurrentType() == ffw::JsonReader::Type::ARRAY);

    REQUIRE(json.getNext(&node, NULL) == true);
    REQUIRE(node.str() == "\"hello\"");

    REQUIRE(json.getNext(&node, NULL) == true);
    REQUIRE(node.str() == "\"world\"");
}

TEST_CASE("Decode JSON qutation marks #2", "[JSON]") {
    ffw::JsonReader json("[ [   \"hello\"  ,    \"world\"   ] ]");
    ffw::JsonReader::Node node;
    REQUIRE(json.getNext(&node, NULL) == true);
    REQUIRE(node.ptr != NULL);
    REQUIRE(node.str() == "[ [   \"hello\"  ,    \"world\"   ] ]");
    REQUIRE(node.getType() == ffw::JsonReader::Type::ARRAY);
    REQUIRE(json.getCurrentType() == ffw::JsonReader::Type::ARRAY);

    REQUIRE(json.getNext(&node, NULL) == false);

    REQUIRE(json.stepInto(&node));
    REQUIRE(json.getCurrentType() == ffw::JsonReader::Type::ARRAY);

    REQUIRE(json.getNext(&node, NULL) == true);
    REQUIRE(node.str() == "[   \"hello\"  ,    \"world\"   ]");
    REQUIRE(node.getType() == ffw::JsonReader::Type::ARRAY);

    REQUIRE(json.stepInto(&node));
    REQUIRE(json.getCurrentType() == ffw::JsonReader::Type::ARRAY);

    REQUIRE(json.getNext(&node, NULL) == true);
    REQUIRE(node.str() == "\"hello\"");
    REQUIRE(node.getType() == ffw::JsonReader::Type::STRING);

    REQUIRE(json.getNext(&node, NULL) == true);
    REQUIRE(node.str() == "\"world\"");
    REQUIRE(node.getType() == ffw::JsonReader::Type::STRING);
}

TEST_CASE("Decode JSON pairs #1", "[JSON]") {
    ffw::JsonReader json("  { \"first\" : true , \"second\" : false }  ");
    ffw::JsonReader::Node node, key;


    REQUIRE(json.getNext(&node, NULL) == true);
    REQUIRE(node.ptr != NULL);
    REQUIRE(node.str() == "{ \"first\" : true , \"second\" : false }");
    REQUIRE(json.getCurrentType() == ffw::JsonReader::Type::OBJECT);

    REQUIRE(json.stepInto(&node));
    REQUIRE(json.getCurrentType() == ffw::JsonReader::Type::OBJECT);

    REQUIRE(json.getNext(&node, &key) == true);
    REQUIRE(key.str() == "\"first\"");
    REQUIRE(node.str() == "true");

    REQUIRE(json.getNext(&node, &key) == true);
    REQUIRE(key.str() == "\"second\"");
    REQUIRE(node.str() == "false");

    REQUIRE(json.getNext(&node, &key) == false);
}

TEST_CASE("Decode JSON pairs #2", "[JSON]") {
    ffw::JsonReader json(
        "{"
        "    \"string\": \"Hello World!\","
        "    \"integer\": -123e+1,"
        "    \"float\": +0.123e-1,"
        "    \"boolean\": true,"
        "    \"null\": null,"
        "    \"object\": {\"first\": 10, \"second\": 20},"
        "    \"array\": [10, 20]"
        "}"
    );

    ffw::JsonReader::Node node, key;
    REQUIRE(json.getNext(&node, NULL) == true);
    REQUIRE(json.getCurrentType() == ffw::JsonReader::Type::OBJECT);

    REQUIRE(json.stepInto(&node));
    REQUIRE(json.getCurrentType() == ffw::JsonReader::Type::OBJECT);

    // String
    REQUIRE(json.getNext(&node, &key) == true);
    REQUIRE(key.str() == "\"string\"");
    REQUIRE(node.str() == "\"Hello World!\"");
    REQUIRE(key.isString() == true);
    REQUIRE_NOTHROW(REQUIRE(key.toString() == "string"));

    REQUIRE(node.isEmpty()   == false);
    REQUIRE(node.isString()  == true);
    REQUIRE(node.isNumber()  == false);
    REQUIRE(node.isInteger() == false);
    REQUIRE(node.isFloat()   == false);
    REQUIRE(node.isBoolean() == false);
    REQUIRE(node.isNull()    == false);
    REQUIRE(node.isObject()  == false);
    REQUIRE(node.isArray()   == false);

    REQUIRE_THROWS(node.toInteger());
    REQUIRE_THROWS(node.toFloat());
    REQUIRE_THROWS(node.toDouble());
    REQUIRE_THROWS(node.toBoolean());
    REQUIRE_NOTHROW(REQUIRE(node.toString() == "Hello World!"));

    // Integer
    REQUIRE(json.getNext(&node, &key) == true);
    REQUIRE(key.str() == "\"integer\"");
    REQUIRE(node.str() == "-123e+1");
    REQUIRE(key.isString());
    REQUIRE_NOTHROW(REQUIRE(key.toString() == "integer"));

    REQUIRE(node.isEmpty()   == false);
    REQUIRE(node.isString()  == false);
    REQUIRE(node.isNumber()  == true);
    REQUIRE(node.isInteger() == true);
    REQUIRE(node.isFloat()   == false);
    REQUIRE(node.isBoolean() == false);
    REQUIRE(node.isNull()    == false);
    REQUIRE(node.isObject()  == false);
    REQUIRE(node.isArray()   == false);

    REQUIRE_NOTHROW(REQUIRE(node.toInteger() == -123));
    REQUIRE_NOTHROW(REQUIRE(node.toFloat() == Approx(-123e+1f)));
    REQUIRE_NOTHROW(REQUIRE(node.toDouble() == Approx(-123e+1)));
    REQUIRE_THROWS(node.toBoolean());
    REQUIRE_THROWS(node.toString());

    // Float
    REQUIRE(json.getNext(&node, &key) == true);
    REQUIRE(key.str() == "\"float\"");
    REQUIRE(node.str() == "+0.123e-1");
    REQUIRE(key.isString());
    REQUIRE_NOTHROW(REQUIRE(key.toString() == "float"));

    REQUIRE(node.isEmpty()   == false);
    REQUIRE(node.isString()  == false);
    REQUIRE(node.isNumber()  == true);
    REQUIRE(node.isInteger() == false);
    REQUIRE(node.isFloat()   == true);
    REQUIRE(node.isBoolean() == false);
    REQUIRE(node.isNull()    == false);
    REQUIRE(node.isObject()  == false);
    REQUIRE(node.isArray()   == false);

    REQUIRE_NOTHROW(REQUIRE(node.toInteger() == 0));
    REQUIRE_NOTHROW(REQUIRE(node.toFloat() == Approx(+0.123e-1)));
    REQUIRE_NOTHROW(REQUIRE(node.toDouble() == Approx(+0.123e-1)));
    REQUIRE_THROWS(node.toBoolean());
    REQUIRE_THROWS(node.toString());

    // Boolean
    REQUIRE(json.getNext(&node, &key) == true);
    REQUIRE(key.str() == "\"boolean\"");
    REQUIRE(node.str() == "true");
    REQUIRE(key.isString() == true);
    REQUIRE_NOTHROW(REQUIRE(key.toString() == "boolean"));

    REQUIRE(node.isEmpty()   == false);
    REQUIRE(node.isString()  == false);
    REQUIRE(node.isNumber()  == false);
    REQUIRE(node.isInteger() == false);
    REQUIRE(node.isFloat()   == false);
    REQUIRE(node.isBoolean() == true);
    REQUIRE(node.isNull()    == false);
    REQUIRE(node.isObject()  == false);
    REQUIRE(node.isArray()   == false);

    REQUIRE_THROWS(node.toInteger());
    REQUIRE_THROWS(node.toFloat());
    REQUIRE_THROWS(node.toDouble());
    REQUIRE_NOTHROW(REQUIRE(node.toBoolean() == true));
    REQUIRE_THROWS(node.toString());

    // Null
    REQUIRE(json.getNext(&node, &key) == true);
    REQUIRE(key.str() == "\"null\"");
    REQUIRE(node.str() == "null");
    REQUIRE(key.isString() == true);
    REQUIRE_NOTHROW(REQUIRE(key.toString() == "null"));

    REQUIRE(node.isEmpty()   == false);
    REQUIRE(node.isString()  == false);
    REQUIRE(node.isNumber()  == false);
    REQUIRE(node.isInteger() == false);
    REQUIRE(node.isFloat()   == false);
    REQUIRE(node.isBoolean() == false);
    REQUIRE(node.isNull()    == true);
    REQUIRE(node.isObject()  == false);
    REQUIRE(node.isArray()   == false);

    // Object
    REQUIRE(json.getNext(&node, &key) == true);
    REQUIRE(key.str() == "\"object\"");
    REQUIRE(node.str() == "{\"first\": 10, \"second\": 20}");
    REQUIRE(key.isString() == true);
    REQUIRE_NOTHROW(REQUIRE(key.toString() == "object"));

    REQUIRE(node.isEmpty()   == false);
    REQUIRE(node.isString()  == false);
    REQUIRE(node.isNumber()  == false);
    REQUIRE(node.isInteger() == false);
    REQUIRE(node.isFloat()   == false);
    REQUIRE(node.isBoolean() == false);
    REQUIRE(node.isNull()    == false);
    REQUIRE(node.isObject()  == true);
    REQUIRE(node.isArray()   == false);

    // Object -> first,second
    {
        REQUIRE(json.stepInto(&node));

        // First
        REQUIRE(json.getNext(&node, &key) == true);
        REQUIRE(key.str() == "\"first\"");
        REQUIRE(node.str() == "10");
        REQUIRE(key.isString() == true);
        REQUIRE_NOTHROW(REQUIRE(key.toString() == "first"));

        // Second
        REQUIRE(json.getNext(&node, &key) == true);
        REQUIRE(key.str() == "\"second\"");
        REQUIRE(node.str() == "20");
        REQUIRE(key.isString() == true);
        REQUIRE_NOTHROW(REQUIRE(key.toString() == "second"));

        REQUIRE(json.stepOut());
    }

    // Array
    REQUIRE(json.getNext(&node, &key) == true);
    REQUIRE(key.str() == "\"array\"");
    REQUIRE(node.str() == "[10, 20]");
    REQUIRE(key.isString() == true);
    REQUIRE_NOTHROW(REQUIRE(key.toString() == "array"));

    REQUIRE(node.isEmpty()   == false);
    REQUIRE(node.isString()  == false);
    REQUIRE(node.isNumber()  == false);
    REQUIRE(node.isInteger() == false);
    REQUIRE(node.isFloat()   == false);
    REQUIRE(node.isBoolean() == false);
    REQUIRE(node.isNull()    == false);
    REQUIRE(node.isObject()  == false);
    REQUIRE(node.isArray()   == true);

    // Array -> 0,1
    {
        REQUIRE(json.stepInto(&node));

        // 0
        REQUIRE(json.getNext(&node, NULL) == true);
        REQUIRE(node.str() == "10");

        // 1
        REQUIRE(json.getNext(&node, NULL) == true);
        REQUIRE(node.str() == "20");

        REQUIRE(json.stepOut());
    }
}

TEST_CASE("Decode JSON #1", "[JSON]") {
    ffw::Any json = ffw::decodeJson(
        "{"
        "    \"string\": \"Hello World!\","
        "    \"integer\": 1,"
        "    \"float\": +0.123e-1,"
        "    \"boolean\": true,"
        "    \"null\": null,"
        "    \"object\": {\"first\": 10, \"second\": 20},"
        "    \"array\": [10, 20]"
        "}"
    );

    REQUIRE_NOTHROW(REQUIRE(json.getAsObject().size() == 7));
    REQUIRE_NOTHROW(REQUIRE(json["string"].toString() == "Hello World!"));
    REQUIRE_NOTHROW(REQUIRE(json["integer"].toInt() == 1));
    REQUIRE_NOTHROW(REQUIRE(json["float"].toFloat() == Approx(+0.123e-1)));
    REQUIRE_NOTHROW(REQUIRE(json["boolean"].toBool() == true));
    REQUIRE_NOTHROW(REQUIRE(json["null"].is<std::nullptr_t>() == true));
    REQUIRE_NOTHROW(REQUIRE(json["object"].getAsObject().size() == 2));
    REQUIRE_NOTHROW(REQUIRE(json["object"]["first"].toInt() == 10));
    REQUIRE_NOTHROW(REQUIRE(json["object"]["second"].toInt() == 20));
    REQUIRE_NOTHROW(REQUIRE(json["array"].getAsArray().size() == 2));
    REQUIRE_NOTHROW(REQUIRE(json["array"][0].toInt() == 10));
    REQUIRE_NOTHROW(REQUIRE(json["array"][1].toInt() == 20));
}

static ffw::Object example1 = { 
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

TEST_CASE("Decode JSON #2", "[JSON]") {
    // Example taken from http://json.org/example.html

    ffw::Any json = ffw::decodeJson(
        "{\"menu\": {"
        "  \"id\": \"file\","
        "  \"value\": \"File\","
        "  \"popup\": {"
        "	\"menuitem\": ["
        "	  {\"value\": \"New\", \"onclick\": \"CreateNewDoc()\"},"
        "	  {\"value\": \"Open\", \"onclick\": \"OpenDoc()\"},"
        "	  {\"value\": \"Close\", \"onclick\": \"CloseDoc()\"}"
        "	]"
        "  }"
        "}}"
    );

    REQUIRE(compare(json, example1, true));
}

static ffw::Object example2 = {
    {"widget", ffw::Object{
        {"debug", "on"},
        {"window", ffw::Object{
            {"title", "Sample Konfabulator Widget"},
            {"name", "main_window"},
            {"width", 500},
            {"height", 500}
        }},
        {"image", ffw::Object{
            {"src", "Images/Sun.png"},
            {"name", "sun1"},
            {"hOffset", 250},
            {"vOffset", 250},
            {"alignment", "center"}
        }},
        {"text", ffw::Object{
            {"data", "Click Here"},
            {"size", 36},
            {"style", "bold"},
            {"name", "text1"},
            {"hOffset", 250},
            {"vOffset", 100},
            {"alignment", "center"},
            {"onMouseUp", "sun1.opacity = (sun1.opacity / 100) * 90;"}
        }},
    }},
};

TEST_CASE("Decode JSON #3", "[JSON]") {
    // Example taken from http://json.org/example.html

    ffw::Any json = ffw::decodeJson(
        "{\"widget\": {\n"
        "	\"debug\": \"on\",\n"
        "	\"window\": {\n"
        "		\"title\": \"Sample Konfabulator Widget\",\n"
        "		\"name\": \"main_window\",\n"
        "		\"width\": 500,\n"
        "		\"height\": 500\n"
        "	},\n"
        "	\"image\": { \n"
        "		\"src\": \"Images/Sun.png\",\n"
        "		\"name\": \"sun1\",\n"
        "		\"hOffset\": 250,\n"
        "		\"vOffset\": 250,\n"
        "		\"alignment\": \"center\"\n"
        "	},\n"
        "	\"text\": {\n"
        "		\"data\": \"Click Here\",\n"
        "		\"size\": 36,\n"
        "		\"style\": \"bold\",\n"
        "		\"name\": \"text1\",\n"
        "		\"hOffset\": 250,\n"
        "		\"vOffset\": 100,\n"
        "		\"alignment\": \"center\",\n"
        "		\"onMouseUp\": \"sun1.opacity = (sun1.opacity / 100) * 90;\"\n"
        "	}\n"
        "}}  \n"
    );

    REQUIRE(compare(json, example2, true));
}

static ffw::Object example3 = {
    {"web-app", ffw::Object{
        {"servlet", ffw::Array{
            ffw::Object{
                {"servlet-name", "cofaxCDS"},
                {"servlet-class", "org.cofax.cds.CDSServlet"},
                {"init-param", ffw::Object{  
                    {"configGlossary:installationAt", "Philadelphia, PA"},
                    {"configGlossary:adminEmail", "ksm@pobox.com"},
                    {"configGlossary:poweredBy", "Cofax"},
                    {"configGlossary:poweredByIcon", "/images/cofax.gif"},
                    {"configGlossary:staticPath", "/content/static"},
                    {"templateProcessorClass", "org.cofax.WysiwygTemplate"},
                    {"templateLoaderClass", "org.cofax.FilesTemplateLoader"},
                    {"templatePath", "templates"},
                    {"templateOverridePath", ""},
                    {"defaultListTemplate", "listTemplate.htm"},
                    {"defaultFileTemplate", "articleTemplate.htm"},
                    {"useJSP", false},
                    {"jspListTemplate", "listTemplate.jsp"},
                    {"jspFileTemplate", "articleTemplate.jsp"},
                    {"cachePackageTagsTrack", 200},
                    {"cachePackageTagsStore", 200},
                    {"cachePackageTagsRefresh", 60},
                    {"cacheTemplatesTrack", 100},
                    {"cacheTemplatesStore", 50},
                    {"cacheTemplatesRefresh", 15},
                    {"cachePagesTrack", 200},
                    {"cachePagesStore", 100},
                    {"cachePagesRefresh", 10},
                    {"cachePagesDirtyRead", 10},
                    {"searchEngineListTemplate", "forSearchEnginesList.htm"},
                    {"searchEngineFileTemplate", "forSearchEngines.htm"},
                    {"searchEngineRobotsDb", "WEB-INF/robots.db"},
                    {"useDataStore", true},
                    {"dataStoreClass", "org.cofax.SqlDataStore"},
                    {"redirectionClass", "org.cofax.SqlRedirection"},
                    {"dataStoreName", "cofax"},
                    {"dataStoreDriver", "com.microsoft.jdbc.sqlserver.SQLServerDriver"},
                    {"dataStoreUrl", "jdbc:microsoft:sqlserver://LOCALHOST:1433;DatabaseName=goon"},
                    {"dataStoreUser", "sa"},
                    {"dataStorePassword", "dataStoreTestQuery"},
                    {"dataStoreTestQuery", "SET NOCOUNT ON;select test='test';"},
                    {"dataStoreLogFile", "/usr/local/tomcat/logs/datastore.log"},
                    {"dataStoreInitConns", 10},
                    {"dataStoreMaxConns", 100},
                    {"dataStoreConnUsageLimit", 100},
                    {"dataStoreLogLevel", "debug"},
                    {"maxUrlLength", 500}
                }}
            },
            ffw::Object{
                {"servlet-name", "cofaxEmail"},
                {"servlet-class", "org.cofax.cds.EmailServlet"},
                {"init-param", ffw::Object{  
                    {"mailHost", "mail1"},
                    {"mailHostOverride", "mail2"}
                }}
            },
            ffw::Object{
                {"servlet-name", "cofaxAdmin"},
                {"servlet-class", "org.cofax.cds.AdminServlet"}
            },
            ffw::Object{
                {"servlet-name", "fileServlet"},
                {"servlet-class", "org.cofax.cds.FileServlet"}
            },
            ffw::Object{
                {"servlet-name", "cofaxTools"},
                {"servlet-class", "org.cofax.cms.CofaxToolsServlet"},
                {"init-param", ffw::Object{  
                    {"templatePath", "toolstemplates/"},
                    {"log", 1},
                    {"logLocation", "/usr/local/tomcat/logs/CofaxTools.log"},
                    {"logMaxSize", ""},
                    {"dataLog", 1},
                    {"dataLogLocation", "/usr/local/tomcat/logs/dataLog.log"},
                    {"dataLogMaxSize", ""},
                    {"removePageCache", "/content/admin/remove?cache=pages&id="},
                    {"removeTemplateCache", "/content/admin/remove?cache=templates&id="},
                    {"fileTransferFolder", "/usr/local/tomcat/webapps/content/fileTransferFolder"},
                    {"lookInContext", 1},
                    {"adminGroupID", 4},
                    {"betaServer", true}
                }}
            }
        }},
        {"servlet-mapping", ffw::Object{
            {"cofaxCDS", "/"},
            {"cofaxEmail", "/cofaxutil/aemail/*"},
            {"cofaxAdmin", "/admin/*"},
            {"fileServlet", "/static/*"},
            {"cofaxTools", "/tools/*"}
        }},
        {"taglib", ffw::Object{
            {"taglib-uri", "cofax.tld"},
            {"taglib-location", "/WEB-INF/tlds/cofax.tld"}
        }}
    }}
};

TEST_CASE("Decode JSON #4", "[JSON]") {
    // Example taken from http://json.org/example.html

    ffw::Any json = ffw::decodeJson(
        "{\"web-app\": {\r\n"
        "  \"servlet\": [   \r\n"
        "    {\r\n"
        "      \"servlet-name\": \"cofaxCDS\",\r\n"
        "      \"servlet-class\": \"org.cofax.cds.CDSServlet\",\r\n"
        "      \"init-param\": {\r\n"
        "        \"configGlossary:installationAt\": \"Philadelphia, PA\",\r\n"
        "        \"configGlossary:adminEmail\": \"ksm@pobox.com\",\r\n"
        "        \"configGlossary:poweredBy\": \"Cofax\",\r\n"
        "        \"configGlossary:poweredByIcon\": \"/images/cofax.gif\",\r\n"
        "        \"configGlossary:staticPath\": \"/content/static\",\r\n"
        "        \"templateProcessorClass\": \"org.cofax.WysiwygTemplate\",\r\n"
        "        \"templateLoaderClass\": \"org.cofax.FilesTemplateLoader\",\r\n"
        "        \"templatePath\": \"templates\",\r\n"
        "        \"templateOverridePath\": \"\",\r\n"
        "        \"defaultListTemplate\": \"listTemplate.htm\",\r\n"
        "        \"defaultFileTemplate\": \"articleTemplate.htm\",\r\n"
        "        \"useJSP\": false,\r\n"
        "        \"jspListTemplate\": \"listTemplate.jsp\",\r\n"
        "        \"jspFileTemplate\": \"articleTemplate.jsp\",\r\n"
        "        \"cachePackageTagsTrack\": 200,\r\n"
        "        \"cachePackageTagsStore\": 200,\r\n"
        "        \"cachePackageTagsRefresh\": 60,\r\n"
        "        \"cacheTemplatesTrack\": 100,\r\n"
        "        \"cacheTemplatesStore\": 50,\r\n"
        "        \"cacheTemplatesRefresh\": 15,\r\n"
        "        \"cachePagesTrack\": 200,\r\n"
        "        \"cachePagesStore\": 100,\r\n"
        "        \"cachePagesRefresh\": 10,\r\n"
        "        \"cachePagesDirtyRead\": 10,\r\n"
        "        \"searchEngineListTemplate\": \"forSearchEnginesList.htm\",\r\n"
        "        \"searchEngineFileTemplate\": \"forSearchEngines.htm\",\r\n"
        "        \"searchEngineRobotsDb\": \"WEB-INF/robots.db\",\r\n"
        "        \"useDataStore\": true,\r\n"
        "        \"dataStoreClass\": \"org.cofax.SqlDataStore\",\r\n"
        "        \"redirectionClass\": \"org.cofax.SqlRedirection\",\r\n"
        "        \"dataStoreName\": \"cofax\",\r\n"
        "        \"dataStoreDriver\": \"com.microsoft.jdbc.sqlserver.SQLServerDriver\",\r\n"
        "        \"dataStoreUrl\": \"jdbc:microsoft:sqlserver://LOCALHOST:1433;DatabaseName=goon\",\r\n"
        "        \"dataStoreUser\": \"sa\",\r\n"
        "        \"dataStorePassword\": \"dataStoreTestQuery\",\r\n"
        "        \"dataStoreTestQuery\": \"SET NOCOUNT ON;select test='test';\",\r\n"
        "        \"dataStoreLogFile\": \"/usr/local/tomcat/logs/datastore.log\",\r\n"
        "        \"dataStoreInitConns\": 10,\r\n"
        "        \"dataStoreMaxConns\": 100,\r\n"
        "        \"dataStoreConnUsageLimit\": 100,\r\n"
        "        \"dataStoreLogLevel\": \"debug\",\r\n"
        "        \"maxUrlLength\": 500}},\r\n"
        "    {\r\n"
        "      \"servlet-name\": \"cofaxEmail\",\r\n"
        "      \"servlet-class\": \"org.cofax.cds.EmailServlet\",\r\n"
        "      \"init-param\": {\r\n"
        "      \"mailHost\": \"mail1\",\r\n"
        "      \"mailHostOverride\": \"mail2\"}},\r\n"
        "    {\r\n"
        "      \"servlet-name\": \"cofaxAdmin\",\r\n"
        "      \"servlet-class\": \"org.cofax.cds.AdminServlet\"},\r\n"
        " \r\n"
        "    {\r\n"
        "      \"servlet-name\": \"fileServlet\",\r\n"
        "      \"servlet-class\": \"org.cofax.cds.FileServlet\"},\r\n"
        "    {\r\n"
        "      \"servlet-name\": \"cofaxTools\",\r\n"
        "      \"servlet-class\": \"org.cofax.cms.CofaxToolsServlet\",\r\n"
        "      \"init-param\": {\r\n"
        "        \"templatePath\": \"toolstemplates/\",\r\n"
        "        \"log\": 1,\r\n"
        "        \"logLocation\": \"/usr/local/tomcat/logs/CofaxTools.log\",\r\n"
        "        \"logMaxSize\": \"\",\r\n"
        "        \"dataLog\": 1,\r\n"
        "        \"dataLogLocation\": \"/usr/local/tomcat/logs/dataLog.log\",\r\n"
        "        \"dataLogMaxSize\": \"\",\r\n"
        "        \"removePageCache\": \"/content/admin/remove?cache=pages&id=\",\r\n"
        "        \"removeTemplateCache\": \"/content/admin/remove?cache=templates&id=\",\r\n"
        "        \"fileTransferFolder\": \"/usr/local/tomcat/webapps/content/fileTransferFolder\",\r\n"
        "        \"lookInContext\": 1,\r\n"
        "        \"adminGroupID\": 4,\r\n"
        "        \"betaServer\": true}}],\r\n"
        "  \"servlet-mapping\": {\r\n"
        "    \"cofaxCDS\": \"/\",\r\n"
        "    \"cofaxEmail\": \"/cofaxutil/aemail/*\",\r\n"
        "    \"cofaxAdmin\": \"/admin/*\",\r\n"
        "    \"fileServlet\": \"/static/*\",\r\n"
        "    \"cofaxTools\": \"/tools/*\"},\r\n"
        " \r\n"
        "  \"taglib\": {\r\n"
        "    \"taglib-uri\": \"cofax.tld\",\r\n"
        "    \"taglib-location\": \"/WEB-INF/tlds/cofax.tld\"}}}\r\n"
    );
          
    REQUIRE(compare(json, example3, true));
}

TEST_CASE("Decode JSON escaped character #1", "[JSON]") {
    ffw::Any json = ffw::decodeJson(
        "{"
        "\"basic\": \"\\u0021\\u0022\\u0023\\u0024\","
        "\"greek\": \"\\u0391\\u0392\\u0393\\u0394\\u0395\\u0396\\u0397\\u0398\","
        "\"cyrilic\": \"\\u0410\\u0411\\u0412\\u0413\\u0414\\u0415\\u0416\\u0417\","
        "\"arabic\": \"\\u06AF\\u06AE\\u06AD\\u06AC\\u06AB\\u06AA\","
        "\"oriya\": \"\\u0B05\\u0B06\\u0B07\\u0B08\\u0B09\\u0B0A\\u0B0B\","
        "\"lao\": \"\\u0E81\\u0E82\\u0E84\\u0E87\\u0E88\\u0E8A\\u0E8D\","
        "\"math\": \"\\u2200\\u2201\\u2202\\u2203\\u2204\\u2205\\u2206\\u2207\","
        "\"cjk\": \"\\uF900\\uF901\\uF902\\uF903\\uF904\\uF905\\uF906\""
        "}"
    );

    // https://r12a.github.io/apps/conversion/ was used for conversion
    REQUIRE(json["basic"].toString() == "\x21\x22\x23\x24");
    REQUIRE(json["greek"].toString() == "\xCE\x91\xCE\x92\xCE\x93\xCE\x94\xCE\x95\xCE\x96\xCE\x97\xCE\x98");
    REQUIRE(json["cyrilic"].toString() == "\xD0\x90\xD0\x91\xD0\x92\xD0\x93\xD0\x94\xD0\x95\xD0\x96\xD0\x97");
    REQUIRE(json["arabic"].toString() == "\xDA\xAF\xDA\xAE\xDA\xAD\xDA\xAC\xDA\xAB\xDA\xAA");
    REQUIRE(json["oriya"].toString() == "\xE0\xAC\x85\xE0\xAC\x86\xE0\xAC\x87\xE0\xAC\x88\xE0\xAC\x89\xE0\xAC\x8A\xE0\xAC\x8B");
    REQUIRE(json["lao"].toString() == "\xE0\xBA\x81\xE0\xBA\x82\xE0\xBA\x84\xE0\xBA\x87\xE0\xBA\x88\xE0\xBA\x8A\xE0\xBA\x8D");
    REQUIRE(json["math"].toString() == "\xE2\x88\x80\xE2\x88\x81\xE2\x88\x82\xE2\x88\x83\xE2\x88\x84\xE2\x88\x85\xE2\x88\x86\xE2\x88\x87");
    REQUIRE(json["cjk"].toString() == "\xEF\xA4\x80\xEF\xA4\x81\xEF\xA4\x82\xEF\xA4\x83\xEF\xA4\x84\xEF\xA4\x85\xEF\xA4\x86");
}

TEST_CASE("Encode JSON #1", "[JSON]") {
    SECTION("Formated") {
        std::string str = ffw::encodeJson(example1, "    ", true);
        ffw::Any test = ffw::decodeJson(str);
        REQUIRE(compare(example1, test, true));
    }
    SECTION("Compressed") {
        std::string str = ffw::encodeJson(example1);
        ffw::Any test = ffw::decodeJson(str);
        REQUIRE(compare(example1, test, true));
    }
}

TEST_CASE("Encode JSON #2", "[JSON]") {
    SECTION("Formated") {
        std::string str = ffw::encodeJson(example2, "    ", true);
        ffw::Any test = ffw::decodeJson(str);
        REQUIRE(compare(example2, test, true));
    }
    SECTION("Compressed") {
        std::string str = ffw::encodeJson(example2);
        ffw::Any test = ffw::decodeJson(str);
        REQUIRE(compare(example2, test, true));
    }
}

TEST_CASE("Encode JSON #3", "[JSON]") {
    SECTION("Formated") {
        std::string str = ffw::encodeJson(example3, "    ", true);
        ffw::Any test = ffw::decodeJson(str);
        REQUIRE(compare(example3, test, true));
    }
    SECTION("Compressed") {
        std::string str = ffw::encodeJson(example3);
        ffw::Any test = ffw::decodeJson(str);
        REQUIRE(compare(example3, test, true));
    }
}

TEST_CASE("Encode JSON escaped character #1", "[JSON]") {
    ffw::Any json = ffw::Object();

    json["basic"] = "\x21\x22\x23\x24";
    json["greek"] = "\xCE\x91\xCE\x92\xCE\x93\xCE\x94\xCE\x95\xCE\x96\xCE\x97\xCE\x98";
    json["cyrilic"] = "\xD0\x90\xD0\x91\xD0\x92\xD0\x93\xD0\x94\xD0\x95\xD0\x96\xD0\x97";
    json["arabic"] = "\xDA\xAF\xDA\xAE\xDA\xAD\xDA\xAC\xDA\xAB\xDA\xAA";
    json["oriya"] = "\xE0\xAC\x85\xE0\xAC\x86\xE0\xAC\x87\xE0\xAC\x88\xE0\xAC\x89\xE0\xAC\x8A\xE0\xAC\x8B";
    json["lao"] = "\xE0\xBA\x81\xE0\xBA\x82\xE0\xBA\x84\xE0\xBA\x87\xE0\xBA\x88\xE0\xBA\x8A\xE0\xBA\x8D";
    json["math"] = "\xE2\x88\x80\xE2\x88\x81\xE2\x88\x82\xE2\x88\x83\xE2\x88\x84\xE2\x88\x85\xE2\x88\x86\xE2\x88\x87";
    json["cjk"] = "\xEF\xA4\x80\xEF\xA4\x81\xEF\xA4\x82\xEF\xA4\x83\xEF\xA4\x84\xEF\xA4\x85\xEF\xA4\x86";

    std::string str = ffw::encodeJson(json, NULL, true);
    
    ffw::Any test = ffw::decodeJson(str);

    // https://r12a.github.io/apps/conversion/ was used for conversion
    REQUIRE(test["basic"].toString() == "\x21\x22\x23\x24");
    REQUIRE(test["greek"].toString() == "\xCE\x91\xCE\x92\xCE\x93\xCE\x94\xCE\x95\xCE\x96\xCE\x97\xCE\x98");
    REQUIRE(test["cyrilic"].toString() == "\xD0\x90\xD0\x91\xD0\x92\xD0\x93\xD0\x94\xD0\x95\xD0\x96\xD0\x97");
    REQUIRE(test["arabic"].toString() == "\xDA\xAF\xDA\xAE\xDA\xAD\xDA\xAC\xDA\xAB\xDA\xAA");
    REQUIRE(test["oriya"].toString() == "\xE0\xAC\x85\xE0\xAC\x86\xE0\xAC\x87\xE0\xAC\x88\xE0\xAC\x89\xE0\xAC\x8A\xE0\xAC\x8B");
    REQUIRE(test["lao"].toString() == "\xE0\xBA\x81\xE0\xBA\x82\xE0\xBA\x84\xE0\xBA\x87\xE0\xBA\x88\xE0\xBA\x8A\xE0\xBA\x8D");
    REQUIRE(test["math"].toString() == "\xE2\x88\x80\xE2\x88\x81\xE2\x88\x82\xE2\x88\x83\xE2\x88\x84\xE2\x88\x85\xE2\x88\x86\xE2\x88\x87");
    REQUIRE(test["cjk"].toString() == "\xEF\xA4\x80\xEF\xA4\x81\xEF\xA4\x82\xEF\xA4\x83\xEF\xA4\x84\xEF\xA4\x85\xEF\xA4\x86");
}

static size_t nodes = 0;
static void decodeJsonTest(ffw::JsonReader& json) {
    ffw::JsonReader::Node value, key;

    while (json.getNext(&value, &key)) {
        nodes++;

        if (value.isArray() || value.isObject()) {
            if (json.stepInto(&value)) {
                decodeJsonTest(json);
                json.stepOut();
            }
        }
    }
}

TEST_CASE("Encode JSON #4", "[JSON]") {
    std::ifstream input("MOCK_DATA.json", std::ios::in | std::ios::binary);
    if (!input) {
        throw ffw::JsonEncodeException("Could not open file MOCK_DATA.json!");
    }

    std::string str;
    input.seekg(0, std::ios::end);
    str.resize(static_cast<size_t>(input.tellg()));
    input.seekg(0, std::ios::beg);
    input.read(&str[0], str.size());
    input.close();
    
    timerStart();
    //ffw::Any test = ffw::decodeJson(str);
    ffw::JsonReader json(str);
    decodeJsonTest(json);
    timerEnd();
    std::cout << "Running this in Debug may increase time due to debugging symbols!" << std::endl;
    std::cout << "Decoding of 10MB JSON file took: " << timerGetSeconds() << " seconds! Total nodes: " << nodes << std::endl;
    //REQUIRE(compare(example3, test, true));
}