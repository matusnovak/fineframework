#include <ffw/math.h>
#include <ffw/data.h>
#include <cassert>

int main() {

    // Decoding XML

    //! [example0]
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
        assert(node.name() == "menu");
        assert(node.hasAttributes() == true);

        node.getNextAttribute(&attr);
        assert(attr.isString() == true);
        assert(attr.isEmpty() == false); 
        assert(attr.name() + "=" + attr.toString() == "id=file");

        node.getNextAttribute(&attr);
        assert(attr.isString() == false);
        assert(attr.isEmpty() == true);

        // Go inside of "menu"
        xml.stepInto(&node);

        // Find "popup"
        xml.getNext(&node);
        assert(node.name() == "popup");
        assert(node.isObject() == true); // Returns true because it has many child nodes

        // Go inside of "popup"
        xml.stepInto(&node);

        // Find first "menuitem"
        xml.getNext(&node);
        assert(node.name() == "menuitem");
        assert(node.isObject() == false); // Returns false, no child nodes
        assert(node.isEmpty() == true); // Returns true, does not contain anything
        assert(node.hasAttributes() == true); // Returns true, the node has 2 attributes

        node.getNextAttribute(&attr);
        assert(attr.isString() == true);
        assert(attr.name() + "=" + attr.toString() == "value=New");

        node.getNextAttribute(&attr);
        assert(attr.isString() == true); // Returns true
        assert(attr.name() + "=" + attr.toString() == "onclick=CreateNewDoc()");

        assert(node.getNextAttribute(&attr) == false); 
        // Returns false, no another attribute
        // attr remains unmodified!

        // Find second "menuitem"
        assert(xml.getNext(&node) == true);

        // Find third (last) "menuitem"
        assert(xml.getNext(&node) == true);

        assert(xml.getNext(&node) == false); 
        // Returns false, no more neighbour nodes

        // Step out and go back to the parent element
        // Returns false if you try to step out out of the root element
        assert(xml.stepOut() == true);
    }
    catch (ffw::XmlEncodeException& e) {
        std::cerr << "Something went wrong: " << e.what() << std::endl;
        assert(false);
    }
    //! [example0]

    // Encoding XML

    //! [example1]
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

        std::string xmlStr = stream.get();
        std::cout << xmlStr << std::endl;

        ffw::Object test = ffw::decodeXml(xmlStr).getAsObject();
        assert(test["menu"]["popup"]["menuitem"][2]["onclick"].toString() == "CloseDoc()");
  
    } catch (ffw::XmlEncodeException& e){
        std::cerr << "Something went wrong: " << e.what() << std::endl;
        assert(false);
    }
    //! [example1]

    return 0;
}