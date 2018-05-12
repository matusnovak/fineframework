#include <ffw/data.h>
#include "../catch.hpp"
#include <iostream>

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

TEST_CASE("Decode XML types #1", "[XML]") {
    ffw::XmlReader xml(
        "<menu id=\"file\" value=\"\">"
          "<popup>"
            "<menuitem value=\"New\" onclick=\"CreateNewDoc()\" />"
            "<menuitem value=\"Open\" onclick=\"OpenDoc()\" />"
            "<menuitem value=\"Close\" onclick=\"CloseDoc()\" />"
          "</popup>"
          "<values>"
            "<integer attr=\"123\">123</integer>"
            "<float attr=\"+0.123e-1\">+0.123e-1</float>"
            "<boolean attr=\"true\">true</boolean>"
            "<null attr=\"null\">null</null>"
          "</values>"
        "</menu>"
    );

    ffw::XmlReader::Node node;
    ffw::XmlReader::Attribute attr;

    // Get <menu>
    REQUIRE(xml.getNext(&node) == true);
    REQUIRE(node.name() == "menu");

    REQUIRE(node.getType() == ffw::XmlReader::Type::OBJECT);
    REQUIRE(node.isObject() == true);
    REQUIRE(node.isEmpty() == false);
    REQUIRE(node.isString() == false);
    REQUIRE(node.isNumber() == false);
    REQUIRE(node.isInteger() == false);
    REQUIRE(node.isFloat() == false);
    REQUIRE(node.isBoolean() == false);
    REQUIRE(node.isNull() == false);

    {
        REQUIRE(node.getNextAttribute(&attr) == true);
        REQUIRE(attr.name() == "id");

        REQUIRE(attr.isObject() == false);
        REQUIRE(attr.isEmpty() == false);
        REQUIRE(attr.isString() == true);
        REQUIRE(attr.isNumber() == false);
        REQUIRE(attr.isInteger() == false);
        REQUIRE(attr.isFloat() == false);
        REQUIRE(attr.isBoolean() == false);
        REQUIRE(attr.isNull() == false);

        REQUIRE(node.getNextAttribute(&attr) == true);
        REQUIRE(attr.name() == "value");

        REQUIRE(attr.isObject() == false);
        REQUIRE(attr.isEmpty() == true);
        REQUIRE(attr.isString() == false);
        REQUIRE(attr.isNumber() == false);
        REQUIRE(attr.isInteger() == false);
        REQUIRE(attr.isFloat() == false);
        REQUIRE(attr.isBoolean() == false);
        REQUIRE(attr.isNull() == false);
    }

    // Stepping into <menu>
    REQUIRE(xml.stepInto(&node));

    // Get popup=
    REQUIRE(xml.getNext(&node) == true);
    REQUIRE(node.name() == "popup");

    REQUIRE(node.isObject() == true);
    REQUIRE(node.isEmpty() == false);
    REQUIRE(node.isString() == false);
    REQUIRE(node.isNumber() == false);
    REQUIRE(node.isInteger() == false);
    REQUIRE(node.isFloat() == false);
    REQUIRE(node.isBoolean() == false);
    REQUIRE(node.isNull() == false);
    REQUIRE(node.hasAttributes() == false);

    {
        REQUIRE(xml.stepInto(&node) == true);

        REQUIRE(xml.getNext(&node) == true);
        REQUIRE(node.name() == "menuitem");

        REQUIRE(node.isObject() == false);
        REQUIRE(node.isEmpty() == true);
        REQUIRE(node.isString() == false);
        REQUIRE(node.isNumber() == false);
        REQUIRE(node.isInteger() == false);
        REQUIRE(node.isFloat() == false);
        REQUIRE(node.isBoolean() == false);
        REQUIRE(node.isNull() == false);
        REQUIRE(node.hasAttributes() == true);

        {
            REQUIRE(node.getNextAttribute(&attr) == true);
            REQUIRE(attr.name() == "value");

            REQUIRE(attr.isObject() == false);
            REQUIRE(attr.isEmpty() == false);
            REQUIRE(attr.isString() == true);
            REQUIRE(attr.isNumber() == false);
            REQUIRE(attr.isInteger() == false);
            REQUIRE(attr.isFloat() == false);
            REQUIRE(attr.isBoolean() == false);
            REQUIRE(attr.isNull() == false);

            REQUIRE(node.getNextAttribute(&attr) == true);
            REQUIRE(attr.name() == "onclick");

            REQUIRE(attr.isObject() == false);
            REQUIRE(attr.isEmpty() == false);
            REQUIRE(attr.isString() == true);
            REQUIRE(attr.isNumber() == false);
            REQUIRE(attr.isInteger() == false);
            REQUIRE(attr.isFloat() == false);
            REQUIRE(attr.isBoolean() == false);
            REQUIRE(attr.isNull() == false);
        }

        REQUIRE(xml.getNext(&node) == true);
        REQUIRE(node.name() == "menuitem");

        REQUIRE(xml.getNext(&node) == true);
        REQUIRE(node.name() == "menuitem");

        REQUIRE(xml.getNext(&node) == false);

        REQUIRE(xml.stepOut());
    }

    // Get <values>
    REQUIRE(xml.getNext(&node) == true);

    REQUIRE(node.isObject() == true);
    REQUIRE(node.isEmpty() == false);
    REQUIRE(node.isString() == false);
    REQUIRE(node.isNumber() == false);
    REQUIRE(node.isInteger() == false);
    REQUIRE(node.isFloat() == false);
    REQUIRE(node.isBoolean() == false);
    REQUIRE(node.isNull() == false);

    {
        REQUIRE(xml.stepInto(&node) == true);

        REQUIRE(xml.getNext(&node) == true);
        REQUIRE(node.name() == "integer");
        REQUIRE(node.getNextAttribute(&attr) == true);
        REQUIRE(attr.name() == "attr");

        REQUIRE(node.isObject() == false);
        REQUIRE(node.isEmpty() == false);
        REQUIRE(node.isString() == true);
        REQUIRE(node.isNumber() == true);
        REQUIRE(node.isInteger() == true);
        REQUIRE(node.isFloat() == false);
        REQUIRE(node.isBoolean() == false);
        REQUIRE(node.isNull() == false);

        REQUIRE(attr.isObject() == false);
        REQUIRE(attr.isEmpty() == false);
        REQUIRE(attr.isString() == true);
        REQUIRE(attr.isNumber() == true);
        REQUIRE(attr.isInteger() == true);
        REQUIRE(attr.isFloat() == false);
        REQUIRE(attr.isBoolean() == false);
        REQUIRE(attr.isNull() == false);

        REQUIRE(xml.getNext(&node) == true);
        REQUIRE(node.name() == "float");
        REQUIRE(node.getNextAttribute(&attr) == true);
        REQUIRE(attr.name() == "attr");

        REQUIRE(node.isObject() == false);
        REQUIRE(node.isEmpty() == false);
        REQUIRE(node.isString() == true);
        REQUIRE(node.isNumber() == true);
        REQUIRE(node.isInteger() == false);
        REQUIRE(node.isFloat() == true);
        REQUIRE(node.isBoolean() == false);
        REQUIRE(node.isNull() == false);

        REQUIRE(attr.isObject() == false);
        REQUIRE(attr.isEmpty() == false);
        REQUIRE(attr.isString() == true);
        REQUIRE(attr.isNumber() == true);
        REQUIRE(attr.isInteger() == false);
        REQUIRE(attr.isFloat() == true);
        REQUIRE(attr.isBoolean() == false);
        REQUIRE(attr.isNull() == false);

        REQUIRE(xml.getNext(&node) == true);
        REQUIRE(node.name() == "boolean");
        REQUIRE(node.getNextAttribute(&attr) == true);
        REQUIRE(attr.name() == "attr");

        REQUIRE(node.isObject() == false);
        REQUIRE(node.isEmpty() == false);
        REQUIRE(node.isString() == true);
        REQUIRE(node.isNumber() == false);
        REQUIRE(node.isInteger() == false);
        REQUIRE(node.isFloat() == false);
        REQUIRE(node.isBoolean() == true);
        REQUIRE(node.isNull() == false);

        REQUIRE(attr.isObject() == false);
        REQUIRE(attr.isEmpty() == false);
        REQUIRE(attr.isString() == true);
        REQUIRE(attr.isNumber() == false);
        REQUIRE(attr.isInteger() == false);
        REQUIRE(attr.isFloat() == false);
        REQUIRE(attr.isBoolean() == true);
        REQUIRE(attr.isNull() == false);

        REQUIRE(xml.getNext(&node) == true);
        REQUIRE(node.name() == "null");
        REQUIRE(node.getNextAttribute(&attr) == true);
        REQUIRE(attr.name() == "attr");

        REQUIRE(node.isObject() == false);
        REQUIRE(node.isEmpty() == false);
        REQUIRE(node.isString() == true);
        REQUIRE(node.isNumber() == false);
        REQUIRE(node.isInteger() == false);
        REQUIRE(node.isFloat() == false);
        REQUIRE(node.isBoolean() == false);
        REQUIRE(node.isNull() == true);

        REQUIRE(attr.isObject() == false);
        REQUIRE(attr.isEmpty() == false);
        REQUIRE(attr.isString() == true);
        REQUIRE(attr.isNumber() == false);
        REQUIRE(attr.isInteger() == false);
        REQUIRE(attr.isFloat() == false);
        REQUIRE(attr.isBoolean() == false);
        REQUIRE(attr.isNull() == true);

        REQUIRE(xml.getNext(&node) == false);

        // Back to <menu>
        REQUIRE(xml.stepOut() == true);
    }

    REQUIRE(xml.getNext(&node) == false);

    // Back to root
    REQUIRE(xml.stepOut() == true);

    // Cannot get more back
    REQUIRE(xml.stepOut() == false);
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

TEST_CASE("Encode XML attributes #1", "[XML]") {
    ffw::XmlWriter::StringStream stream;
    ffw::XmlWriter xml(&stream, "    ", true);

    REQUIRE_NOTHROW(xml.addObject("menu"));
    REQUIRE_NOTHROW(xml.addString("file", "id"));
    REQUIRE_NOTHROW(xml.addString("File", "value"));
    REQUIRE_NOTHROW(xml.beginContent());

    REQUIRE_NOTHROW(xml.addObject("popup"));
    REQUIRE_NOTHROW(xml.beginContent());

    REQUIRE_NOTHROW(xml.addObject("menuitem"));
    REQUIRE_NOTHROW(xml.addString("New", "value"));
    REQUIRE_NOTHROW(xml.addString("CreateNewDoc()", "onclick"));
    REQUIRE_NOTHROW(xml.stepOut());

    REQUIRE_NOTHROW(xml.addObject("menuitem"));
    REQUIRE_NOTHROW(xml.addString("Open", "value"));
    REQUIRE_NOTHROW(xml.addString("OpenDoc()", "onclick"));
    REQUIRE_NOTHROW(xml.stepOut());

    REQUIRE_NOTHROW(xml.addObject("menuitem"));
    REQUIRE_NOTHROW(xml.addString("Close", "value"));
    REQUIRE_NOTHROW(xml.addString("CloseDoc()", "onclick"));
    REQUIRE_NOTHROW(xml.stepOut());

    REQUIRE_NOTHROW(xml.stepOut());
    REQUIRE_NOTHROW(xml.stepOut());

    ffw::Any test = ffw::decodeXml(stream.get());

    REQUIRE(compare(test, example1, true));
}

TEST_CASE("Decode XML #1", "[XML]") {
    ffw::Any xml = ffw::decodeXml(
        "<menu id=\"file\" value=\"File\">"
          "<popup>"
            "<menuitem value=\"New\" onclick=\"CreateNewDoc()\" />"
            "<menuitem value=\"Open\" onclick=\"OpenDoc()\" />"
            "<menuitem value=\"Close\" onclick=\"CloseDoc()\" />"
          "</popup>"
        "</menu>"
    );

    REQUIRE(compare(xml, example1, true));
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

TEST_CASE("Decode XML #2", "[XML]") {
    ffw::Any xml = ffw::decodeXml(
        "<widget>"
            "<debug>on</debug>"
            "<window title=\"Sample Konfabulator Widget\">"
                "<name>main_window</name>"
                "<width>500</width>"
                "<height>500</height>"
            "</window>"
            "<image src=\"Images/Sun.png\" name=\"sun1\">"
                "<hOffset>250</hOffset>"
                "<vOffset>250</vOffset>"
                "<alignment>center</alignment>"
            "</image>"
            "<text data=\"Click Here\" size=\"36\" style=\"bold\">"
                "<name>text1</name>"
                "<hOffset>250</hOffset>"
                "<vOffset>100</vOffset>"
                "<alignment>center</alignment>"
                "<onMouseUp>"
                    "sun1.opacity = (sun1.opacity / 100) * 90;"
                "</onMouseUp>"
            "</text>"
        "</widget>"
    );

    REQUIRE(compare(xml, example2, true));
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

TEST_CASE("Decode XML #3", "[XML]") {
    ffw::Any xml = ffw::decodeXml(
        "<?xml version=\"1.0\" encoding=\"UTF-8\" ?>"
        "<web-app>"
            "<servlet>"
                "<servlet-name>cofaxCDS</servlet-name>"
                "<servlet-class>org.cofax.cds.CDSServlet</servlet-class>"
                "<init-param>"
                    "<configGlossary:installationAt>Philadelphia, PA</configGlossary:installationAt>"
                    "<configGlossary:adminEmail>ksm@pobox.com</configGlossary:adminEmail>"
                    "<configGlossary:poweredBy>Cofax</configGlossary:poweredBy>"
                    "<configGlossary:poweredByIcon>/images/cofax.gif</configGlossary:poweredByIcon>"
                    "<configGlossary:staticPath>/content/static</configGlossary:staticPath>"
                    "<templateProcessorClass>org.cofax.WysiwygTemplate</templateProcessorClass>"
                    "<templateLoaderClass>org.cofax.FilesTemplateLoader</templateLoaderClass>"
                    "<templatePath>templates</templatePath>"
                    "<templateOverridePath></templateOverridePath>"
                    "<defaultListTemplate>listTemplate.htm</defaultListTemplate>"
                    "<defaultFileTemplate>articleTemplate.htm</defaultFileTemplate>"
                    "<useJSP>false</useJSP>"
                    "<jspListTemplate>listTemplate.jsp</jspListTemplate>"
                    "<jspFileTemplate>articleTemplate.jsp</jspFileTemplate>"
                    "<cachePackageTagsTrack>200</cachePackageTagsTrack>"
                    "<cachePackageTagsStore>200</cachePackageTagsStore>"
                    "<cachePackageTagsRefresh>60</cachePackageTagsRefresh>"
                    "<cacheTemplatesTrack>100</cacheTemplatesTrack>"
                    "<cacheTemplatesStore>50</cacheTemplatesStore>"
                    "<cacheTemplatesRefresh>15</cacheTemplatesRefresh>"
                    "<cachePagesTrack>200</cachePagesTrack>"
                    "<cachePagesStore>100</cachePagesStore>"
                    "<cachePagesRefresh>10</cachePagesRefresh>"
                    "<cachePagesDirtyRead>10</cachePagesDirtyRead>"
                    "<searchEngineListTemplate>forSearchEnginesList.htm</searchEngineListTemplate>"
                    "<searchEngineFileTemplate>forSearchEngines.htm</searchEngineFileTemplate>"
                    "<searchEngineRobotsDb>WEB-INF/robots.db</searchEngineRobotsDb>"
                    "<useDataStore>true</useDataStore>"
                    "<dataStoreClass>org.cofax.SqlDataStore</dataStoreClass>"
                    "<redirectionClass>org.cofax.SqlRedirection</redirectionClass>"
                    "<dataStoreName>cofax</dataStoreName>"
                    "<dataStoreDriver>com.microsoft.jdbc.sqlserver.SQLServerDriver</dataStoreDriver>"
                    "<dataStoreUrl>jdbc:microsoft:sqlserver://LOCALHOST:1433;DatabaseName=goon</dataStoreUrl>"
                    "<dataStoreUser>sa</dataStoreUser>"
                    "<dataStorePassword>dataStoreTestQuery</dataStorePassword>"
                    "<dataStoreTestQuery>SET NOCOUNT ON;select test='test';</dataStoreTestQuery>"
                    "<dataStoreLogFile>/usr/local/tomcat/logs/datastore.log</dataStoreLogFile>"
                    "<dataStoreInitConns>10</dataStoreInitConns>"
                    "<dataStoreMaxConns>100</dataStoreMaxConns>"
                    "<dataStoreConnUsageLimit>100</dataStoreConnUsageLimit>"
                    "<dataStoreLogLevel>debug</dataStoreLogLevel>"
                    "<maxUrlLength>500</maxUrlLength>"
                "</init-param>"
            "</servlet>"
            "<servlet>"
                "<servlet-name>cofaxEmail</servlet-name>"
                "<servlet-class>org.cofax.cds.EmailServlet</servlet-class>"
                "<init-param>"
                    "<mailHost>mail1</mailHost>"
                    "<mailHostOverride>mail2</mailHostOverride>"
                "</init-param>"
            "</servlet>"
            "<servlet>"
                "<servlet-name>cofaxAdmin</servlet-name>"
                "<servlet-class>org.cofax.cds.AdminServlet</servlet-class>"
            "</servlet>"
            "<servlet>"
                "<servlet-name>fileServlet</servlet-name>"
                "<servlet-class>org.cofax.cds.FileServlet</servlet-class>"
            "</servlet>"
            "<servlet>"
                "<servlet-name>cofaxTools</servlet-name>"
                "<servlet-class>org.cofax.cms.CofaxToolsServlet</servlet-class>"
                "<init-param>"
                    "<templatePath>toolstemplates/</templatePath>"
                    "<log>1</log>"
                    "<logLocation>/usr/local/tomcat/logs/CofaxTools.log</logLocation>"
                    "<logMaxSize></logMaxSize>"
                    "<dataLog>1</dataLog>"
                    "<dataLogLocation>/usr/local/tomcat/logs/dataLog.log</dataLogLocation>"
                    "<dataLogMaxSize></dataLogMaxSize>"
                    "<removePageCache>/content/admin/remove?cache=pages&amp;id=</removePageCache>"
                    "<removeTemplateCache>/content/admin/remove?cache=templates&amp;id=</removeTemplateCache>"
                    "<fileTransferFolder>/usr/local/tomcat/webapps/content/fileTransferFolder</fileTransferFolder>"
                    "<lookInContext>1</lookInContext>"
                    "<adminGroupID>4</adminGroupID>"
                    "<betaServer>true</betaServer>"
                "</init-param>"
            "</servlet>"
            "<servlet-mapping>"
                "<cofaxCDS>/</cofaxCDS>"
                "<cofaxEmail>/cofaxutil/aemail/*</cofaxEmail>"
                "<cofaxAdmin>/admin/*</cofaxAdmin>"
                "<fileServlet>/static/*</fileServlet>"
                "<cofaxTools>/tools/*</cofaxTools>"
            "</servlet-mapping>"
            "<taglib>"
                "<taglib-uri>cofax.tld</taglib-uri>"
                "<taglib-location>/WEB-INF/tlds/cofax.tld</taglib-location>"
            "</taglib>"
        "</web-app>"
    );

    REQUIRE(compare(xml, example3, true));
}


TEST_CASE("Encode XML #1", "[XML]") {
    SECTION("Formated") {
        std::string str = ffw::encodeXml(example1, "    ", true);
        ffw::Any test = ffw::decodeXml(str);
        REQUIRE(compare(example1, test, true));
    }
    SECTION("Compressed") {
        std::string str = ffw::encodeXml(example1);
        ffw::Any test = ffw::decodeXml(str);
        REQUIRE(compare(example1, test, true));
    }
}

TEST_CASE("Encode XML #2", "[XML]") {
    SECTION("Formated") {
        std::string str = ffw::encodeXml(example2, "    ", true);
        ffw::Any test = ffw::decodeXml(str);
        REQUIRE(compare(example2, test, true));
    }
    SECTION("Compressed") {
        std::string str = ffw::encodeXml(example2);
        ffw::Any test = ffw::decodeXml(str);
        REQUIRE(compare(example2, test, true));
    }
}

TEST_CASE("Encode XML #3", "[XML]") {
    SECTION("Formated") {
        std::string str = ffw::encodeXml(example3, "    ", true);
        ffw::Any test = ffw::decodeXml(str);
        REQUIRE(compare(example3, test, true));
    }
    SECTION("Compressed") {
        std::string str = ffw::encodeXml(example3);
        ffw::Any test = ffw::decodeXml(str);
        REQUIRE(compare(example3, test, true));
    }
}

TEST_CASE("Decode XML escaped character #1", "[XML]") {
    ffw::Any xml = ffw::decodeXml(
        "<document>"
            "<basic>&#x0021;&#x0022;&#x0023;&#x0024;</basic>"
            "<greek>&#x0391;&#x0392;&#x0393;&#x0394;&#x0395;&#x0396;&#x0397;&#x0398;</greek>"
            "<cyrilic>&#x0410;&#x0411;&#x0412;&#x0413;&#x0414;&#x0415;&#x0416;&#x0417;</cyrilic>"
            "<arabic>&#x06AF;&#x06AE;&#x06AD;&#x06AC;&#x06AB;&#x06AA;</arabic>"
            "<oriya>&#x0B05;&#x0B06;&#x0B07;&#x0B08;&#x0B09;&#x0B0A;&#x0B0B;</oriya>"
            "<lao>&#x0E81;&#x0E82;&#x0E84;&#x0E87;&#x0E88;&#x0E8A;&#x0E8D;</lao>"
            "<math>&#x2200;&#x2201;&#x2202;&#x2203;&#x2204;&#x2205;&#x2206;&#x2207;</math>"
            "<cjk>&#xF900;&#xF901;&#xF902;&#xF903;&#xF904;&#xF905;&#xF906;</cjk>"
        "</document>"
    );

    // https://r12a.github.io/apps/conversion/ was used for conversion
    REQUIRE(xml["document"]["basic"].toString() == "\x21\x22\x23\x24");
    REQUIRE(xml["document"]["greek"].toString() == "\xCE\x91\xCE\x92\xCE\x93\xCE\x94\xCE\x95\xCE\x96\xCE\x97\xCE\x98");
    REQUIRE(xml["document"]["cyrilic"].toString() == "\xD0\x90\xD0\x91\xD0\x92\xD0\x93\xD0\x94\xD0\x95\xD0\x96\xD0\x97");
    REQUIRE(xml["document"]["arabic"].toString() == "\xDA\xAF\xDA\xAE\xDA\xAD\xDA\xAC\xDA\xAB\xDA\xAA");
    REQUIRE(xml["document"]["oriya"].toString() == "\xE0\xAC\x85\xE0\xAC\x86\xE0\xAC\x87\xE0\xAC\x88\xE0\xAC\x89\xE0\xAC\x8A\xE0\xAC\x8B");
    REQUIRE(xml["document"]["lao"].toString() == "\xE0\xBA\x81\xE0\xBA\x82\xE0\xBA\x84\xE0\xBA\x87\xE0\xBA\x88\xE0\xBA\x8A\xE0\xBA\x8D");
    REQUIRE(xml["document"]["math"].toString() == "\xE2\x88\x80\xE2\x88\x81\xE2\x88\x82\xE2\x88\x83\xE2\x88\x84\xE2\x88\x85\xE2\x88\x86\xE2\x88\x87");
    REQUIRE(xml["document"]["cjk"].toString() == "\xEF\xA4\x80\xEF\xA4\x81\xEF\xA4\x82\xEF\xA4\x83\xEF\xA4\x84\xEF\xA4\x85\xEF\xA4\x86");
}

TEST_CASE("Encode XML escaped character #1", "[JSON]") {
    ffw::Any xml = ffw::Object{ { "document",  ffw::Object() } };

    xml["document"]["basic"] = "\x21\x22\x23\x24<>\'\"\n&";
    xml["document"]["greek"] = "\xCE\x91\xCE\x92\xCE\x93\xCE\x94\xCE\x95\xCE\x96\xCE\x97\xCE\x98";
    xml["document"]["cyrilic"] = "\xD0\x90\xD0\x91\xD0\x92\xD0\x93\xD0\x94\xD0\x95\xD0\x96\xD0\x97";
    xml["document"]["arabic"] = "\xDA\xAF\xDA\xAE\xDA\xAD\xDA\xAC\xDA\xAB\xDA\xAA";
    xml["document"]["oriya"] = "\xE0\xAC\x85\xE0\xAC\x86\xE0\xAC\x87\xE0\xAC\x88\xE0\xAC\x89\xE0\xAC\x8A\xE0\xAC\x8B";
    xml["document"]["lao"] = "\xE0\xBA\x81\xE0\xBA\x82\xE0\xBA\x84\xE0\xBA\x87\xE0\xBA\x88\xE0\xBA\x8A\xE0\xBA\x8D";
    xml["document"]["math"] = "\xE2\x88\x80\xE2\x88\x81\xE2\x88\x82\xE2\x88\x83\xE2\x88\x84\xE2\x88\x85\xE2\x88\x86\xE2\x88\x87";
    xml["document"]["cjk"] = "\xEF\xA4\x80\xEF\xA4\x81\xEF\xA4\x82\xEF\xA4\x83\xEF\xA4\x84\xEF\xA4\x85\xEF\xA4\x86";

    std::string str = ffw::encodeXml(xml, NULL, true);
    
    ffw::Any test = ffw::decodeXml(str);

    // https://r12a.github.io/apps/conversion/ was used for conversion
    REQUIRE(test["document"]["basic"].toString() == "\x21\x22\x23\x24<>\'\"\n&");
    REQUIRE(test["document"]["greek"].toString() == "\xCE\x91\xCE\x92\xCE\x93\xCE\x94\xCE\x95\xCE\x96\xCE\x97\xCE\x98");
    REQUIRE(test["document"]["cyrilic"].toString() == "\xD0\x90\xD0\x91\xD0\x92\xD0\x93\xD0\x94\xD0\x95\xD0\x96\xD0\x97");
    REQUIRE(test["document"]["arabic"].toString() == "\xDA\xAF\xDA\xAE\xDA\xAD\xDA\xAC\xDA\xAB\xDA\xAA");
    REQUIRE(test["document"]["oriya"].toString() == "\xE0\xAC\x85\xE0\xAC\x86\xE0\xAC\x87\xE0\xAC\x88\xE0\xAC\x89\xE0\xAC\x8A\xE0\xAC\x8B");
    REQUIRE(test["document"]["lao"].toString() == "\xE0\xBA\x81\xE0\xBA\x82\xE0\xBA\x84\xE0\xBA\x87\xE0\xBA\x88\xE0\xBA\x8A\xE0\xBA\x8D");
    REQUIRE(test["document"]["math"].toString() == "\xE2\x88\x80\xE2\x88\x81\xE2\x88\x82\xE2\x88\x83\xE2\x88\x84\xE2\x88\x85\xE2\x88\x86\xE2\x88\x87");
    REQUIRE(test["document"]["cjk"].toString() == "\xEF\xA4\x80\xEF\xA4\x81\xEF\xA4\x82\xEF\xA4\x83\xEF\xA4\x84\xEF\xA4\x85\xEF\xA4\x86");
}
