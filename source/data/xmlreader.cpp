/*** This file is part of FineFramework project ***/

#include "ffw/data/xmlreader.h"
#include "ffw/math/stringmath.h"
#include <fstream>
#include <regex>
#include <sstream>
#include <iostream>
#include <tinyxml2.h>

static const char* getErrorStr(tinyxml2::XMLError err) {
    switch (err) {
        case tinyxml2::XMLError::XML_SUCCESS: return "XML_SUCCESS";
        case tinyxml2::XMLError::XML_NO_ATTRIBUTE: return "XML_NO_ATTRIBUTE";
        case tinyxml2::XMLError::XML_WRONG_ATTRIBUTE_TYPE: return "XML_WRONG_ATTRIBUTE_TYPE";
        case tinyxml2::XMLError::XML_ERROR_FILE_NOT_FOUND: return "XML_ERROR_FILE_NOT_FOUND";
        case tinyxml2::XMLError::XML_ERROR_FILE_COULD_NOT_BE_OPENED: return "XML_ERROR_FILE_COULD_NOT_BE_OPENED";
        case tinyxml2::XMLError::XML_ERROR_FILE_READ_ERROR: return "XML_ERROR_FILE_READ_ERROR";
        case tinyxml2::XMLError::UNUSED_XML_ERROR_ELEMENT_MISMATCH: return "XML_ERROR_ELEMENT_MISMATCH";
        case tinyxml2::XMLError::XML_ERROR_PARSING_ELEMENT: return "XML_ERROR_PARSING_ELEMENT";
        case tinyxml2::XMLError::XML_ERROR_PARSING_ATTRIBUTE: return "XML_ERROR_PARSING_ATTRIBUTE";
        case tinyxml2::XMLError::UNUSED_XML_ERROR_IDENTIFYING_TAG: return "XML_ERROR_IDENTIFYING_TAG";
        case tinyxml2::XMLError::XML_ERROR_PARSING_TEXT: return "XML_ERROR_PARSING_TEXT";
        case tinyxml2::XMLError::XML_ERROR_PARSING_CDATA: return "XML_ERROR_PARSING_CDATA";
        case tinyxml2::XMLError::XML_ERROR_PARSING_COMMENT: return "XML_ERROR_PARSING_COMMENT";
        case tinyxml2::XMLError::XML_ERROR_PARSING_DECLARATION: return "XML_ERROR_PARSING_DECLARATION";
        case tinyxml2::XMLError::XML_ERROR_PARSING_UNKNOWN: return "XML_ERROR_PARSING_UNKNOWN";
        case tinyxml2::XMLError::XML_ERROR_EMPTY_DOCUMENT: return "XML_ERROR_EMPTY_DOCUMENT";
        case tinyxml2::XMLError::XML_ERROR_MISMATCHED_ELEMENT: return "XML_ERROR_MISMATCHED_ELEMENT";
        case tinyxml2::XMLError::XML_ERROR_PARSING: return "XML_ERROR_PARSING";
        case tinyxml2::XMLError::XML_CAN_NOT_CONVERT_TEXT: return "XML_CAN_NOT_CONVERT_TEXT";
        case tinyxml2::XMLError::XML_NO_TEXT_NODE: return "XML_NO_TEXT_NODE";
        case tinyxml2::XMLError::XML_ERROR_COUNT: return "XML_ERROR_COUNT";
        default: break;
    }
    return "XML_UNKNOWN_ERROR";
}

bool ffw::XmlReader::Value::isEmpty() const {
    if (isObject())return false;
    if (rawCstr() == NULL || *(rawCstr()) == '\0')return true;
    return false;
}

bool ffw::XmlReader::Value::isString() const {
    if (isObject())return false;
    if (rawCstr() != NULL && *(rawCstr()) != '\0')return true;
    return false;
}

bool ffw::XmlReader::Value::isNumber() const {
    if (rawCstr() == NULL)return false;
    return std::regex_match(rawCstr(), std::regex("^[-+]?(?:0|[1-9]\\d*)(?:\\.\\d+)?(?:[eE][+-]?\\d+)?$"));
}

bool ffw::XmlReader::Value::isInteger() const {
    if (rawCstr() == NULL)return false;
    return std::regex_match(rawCstr(), std::regex("^[-+]?\\d+([Ee][+-]?\\d+)?$"));
}

bool ffw::XmlReader::Value::isFloat() const {
    if (rawCstr() == NULL)return false;
    return std::regex_match(rawCstr(), std::regex("^[-+]?\\d*\\.{1}\\d+([Ee][+-]?\\d+)?$"));
}

bool ffw::XmlReader::Value::isBoolean() const {
    if (rawCstr() == NULL)return false;
    return std::regex_match(rawCstr(), std::regex("^(true|false)$"));
}

bool ffw::XmlReader::Value::isNull() const {
    if (rawCstr() == NULL)return false;
    return std::regex_match(rawCstr(), std::regex("^(null)$"));
}

std::string ffw::XmlReader::Value::toString() const {
    if (isEmpty()) throw XmlDecodeException("Failed to convert to a string! Node is empty!");
    return std::string(rawCstr());
}

int ffw::XmlReader::Value::toInteger() const {
    if (isEmpty()) throw XmlDecodeException("Failed to convert to a integer! Node is empty!");
    try {
        return std::stoi(rawCstr());
    }
    catch (std::exception& e) {
        (void)e;
        throw XmlDecodeException("Failed to convert: \'" + std::string(rawCstr()) + "\' to inetegr!");
    }
}

double ffw::XmlReader::Value::toDouble() const {
    if (isEmpty()) throw XmlDecodeException("Failed to convert to a double! Node is empty!");
    try {
        return std::stod(rawCstr());
    }
    catch (std::exception& e) {
        (void)e;
        throw XmlDecodeException("Failed to convert: \'" + std::string(rawCstr()) + "\' to double!");
    }
}

float ffw::XmlReader::Value::toFloat() const {
    if (isEmpty()) throw XmlDecodeException("Failed to convert to a float! Node is empty!");
    try {
        return std::stof(rawCstr());
    }
    catch (std::exception& e) {
        (void)e;
        throw XmlDecodeException("Failed to convert: \'" + std::string(rawCstr()) + "\' to float!");
    }
}

bool ffw::XmlReader::Value::toBoolean() const {
    if (isEmpty()) throw XmlDecodeException("Failed to convert to a bool! Node is empty!");
    auto ptr = rawCstr();
    auto len = strlen(ptr);
    if (len == 4 && ptr[0] == 't' && ptr[1] == 'r' && ptr[2] == 'u' && ptr[3] == 'e')return true;
    if (len == 5 && ptr[0] == 'f' && ptr[1] == 'a' && ptr[2] == 'l' && ptr[3] == 's' && ptr[4] == 'e')return false;
    throw XmlDecodeException("Failed to convert: \'" + std::string(rawCstr()) + "\' to bool!");
}

ffw::XmlReader::Type ffw::XmlReader::Value::getType() const {
    if (isObject())return Type::OBJECT;
    if (isEmpty())return Type::EMPTY;
    if (isInteger())return Type::INTEGER;
    if (isFloat())return Type::FLOAT;
    if (isBoolean())return Type::BOOLEAN;
    if (isNull())return Type::NULLVAL;
    if (isString())return Type::STRING;
    return Type::INVALID;
}

std::string ffw::XmlReader::Attribute::name() const {
    if (attr != NULL) {
        if (attr->Name())return std::string(attr->Name());
        else return "";
    }
    return "";
}

bool ffw::XmlReader::Attribute::isObject() const {
    return false;
}

const char* ffw::XmlReader::Attribute::rawCstr() const {
    if (attr != NULL) {
        return attr->Value();
    }
    return NULL;
}

bool ffw::XmlReader::Node::getNextAttribute(Attribute* value) {
    if (attr == NULL) {
        attr = elem->FirstAttribute();
        if (attr != NULL) {
            if(value != NULL)*value = Attribute(attr);
            return true;
        }
        return false;
    }
    else {
        attr = attr->Next();
        if (attr != NULL) {
            if(value != NULL)*value = Attribute(attr);
            return true;
        }
        return false;
    }
}

std::string ffw::XmlReader::Node::name() const {
    if (elem != NULL) {
        if (elem->Name())return std::string(elem->Name());
        else return "";
    }
    return "";
}

bool ffw::XmlReader::Node::isObject() const {
    if (elem != NULL) {
        // Has children?
        if (elem->FirstChildElement() != NULL) {
            return true;
        }
    }

    return false;

}

bool ffw::XmlReader::Node::hasAttributes() const {
    if (elem != NULL && elem->FirstAttribute() != NULL) {
        return true;
    }
    return false;
}

const char* ffw::XmlReader::Node::rawCstr() const {
    if (elem != NULL) {
        return elem->GetText();
    }
    return NULL;
}

ffw::XmlReader::XmlReader(const std::string& input) :document(new tinyxml2::XMLDocument()), child(NULL), parent(NULL) {
    auto err = document->Parse(input.c_str());
    if (err != tinyxml2::XMLError::XML_SUCCESS) {
        throw ffw::XmlDecodeException("Failed to parse document! Error: " + std::string(getErrorStr(err)) + " at: " + document->ErrorStr());
    }
}

ffw::XmlReader::XmlReader(const char* input) : document(new tinyxml2::XMLDocument()), child(NULL), parent(NULL) {
    auto err = document->Parse(input);
    if (err != tinyxml2::XMLError::XML_SUCCESS) {
        throw ffw::XmlDecodeException("Failed to parse document! Error: " + std::string(getErrorStr(err)) + " at: " + document->ErrorStr());
    }
}

ffw::XmlReader::~XmlReader() {

}

bool ffw::XmlReader::getNext(Node* value) {
    // Is root? First run?
    if (parent == NULL) {
        parent = child = document->RootElement();

        // No root element, document is empty
        if (parent == NULL) {
            return false;
        }

        if (value != NULL)*value = Node(child);

        return true;
    }
    else {
        if (child == NULL) {
            child = parent->FirstChildElement();

            if (child == NULL) {
                throw XmlDecodeException("Could not parse next element!");
            }
        }
        else {
            auto test = child->NextSiblingElement();
            if (test != NULL) {
                child = test;
            } 
            else {
                // No next element
                return false;
            }
        }

        if (value != NULL)*value = Node(child);
        return true;
    }

    return false;
}

bool ffw::XmlReader::stepInto(const Node* node) {
    if (node != NULL && node->elem != NULL) {
        if (node->elem->FirstChildElement()) {
            cache.push_back(Cache{child, parent});

            parent = node->elem->ToElement();
            child = NULL;

            return true;
        }
        else {
            throw XmlDecodeException("Cannot step into a node! Expected array or object! Name: " + std::string(node->elem->Name()));
        }
    }
    return false;
}

bool ffw::XmlReader::stepOut() {
    if (cache.size() > 0) {
        parent = cache.back().parent;
        child = cache.back().child;
        cache.pop_back();
        return true;
    }
    return false;
}

static ffw::Any decodeXmlAttr(ffw::XmlReader::Attribute& val) {
    if (val.isEmpty())return ffw::Any();
    if (val.isNumber()) {
        auto str = val.rawCstr();
        if (strstr(str, ".") != NULL) {
            return ffw::Any(val.toFloat());
        }
        return ffw::Any(val.toInteger());
    }
    if (val.isBoolean()) return ffw::Any(val.toBoolean());
    if (val.isNull())return ffw::Any(nullptr);
    if (val.isString())return ffw::Any(val.toString());

    throw ffw::XmlDecodeException("Could not detect value type! At: " + val.name());
}

static ffw::Any decodeXmlObject(ffw::XmlReader& xml, ffw::XmlReader::Node& node, std::string* arrKey);

static ffw::Any decodeXmlElem(ffw::XmlReader& xml, ffw::XmlReader::Node& val) {
    if (val.isEmpty()) {
        if (val.hasAttributes()) {
            return decodeXmlObject(xml, val, NULL);
        }

        return "";
    }
    if (val.isNumber()) {
        auto str = val.rawCstr();
        if (strstr(str, ".") != NULL) {
            return ffw::Any(val.toFloat());
        }
        return ffw::Any(val.toInteger());
    }
    if (val.isBoolean()) return ffw::Any(val.toBoolean());
    if (val.isNull()) return ffw::Any(nullptr);
    if (val.isString()) return ffw::Any(val.toString());

    if (val.isObject()) {
        if (xml.stepInto(&val)) {
            auto ret = decodeXmlObject(xml, val, NULL);
            xml.stepOut();
            return ret;
        }
        else {
            throw ffw::XmlDecodeException("Could not parse XML object! At: " + val.name());
        }
    }

    throw ffw::XmlDecodeException("Could not detect value type! At: " + val.name());
}

static ffw::Any decodeXmlObject(ffw::XmlReader& xml, ffw::XmlReader::Node& node, std::string* arrKey) {
    ffw::XmlReader::Attribute attr;
    ffw::XmlReader::Node child;

    if (node.isEmpty()) {
        ffw::Object out;

        while (node.getNextAttribute(&attr)) {
            out.insert(std::make_pair(attr.name(), decodeXmlAttr(attr)));
        }

        return out;
    }
    
    if (node.isObject()) {
        ffw::Object out;

        while (node.getNextAttribute(&attr)) {
            out.insert(std::make_pair(attr.name(), decodeXmlAttr(attr)));
        }

        while (xml.getNext(&child)) {
            //if (!child.isObject())continue;
            
            //std::cout << "inserting: " << child.name() << std::endl;
            if (out.has_key(child.name())) {
                auto& at = out[child.name()];

                if (!at.is<ffw::Array>()) {
                    //std::cout << "converting to array" << std::endl;
                    ffw::Any temp = at;

                    at = ffw::Array();
                    at.getAsArray().push_back(temp);
                }

                at.getAsArray().push_back(decodeXmlElem(xml, child));
            }
            else {
                out.insert(std::make_pair(child.name(), decodeXmlElem(xml, child)));
            }
        }

        return out;
    }

    throw ffw::XmlDecodeException("Expected JSON object or array! At:" + node.name());
}

ffw::Any ffw::decodeXml(const char* input) {
    ffw::XmlReader xml(input);

    ffw::XmlReader::Node node;
    if(xml.getNext(&node)) {
        if (node.isObject()) {
            if (xml.stepInto(&node)) {
                return ffw::Object{ {node.name(), decodeXmlObject(xml, node, NULL)} };
            }
            else {
                // Parser error
                throw XmlDecodeException("Could not parse a first XML object or an array! At: " + node.name());
            }
        }
        else {
            // Not object!
            throw XmlDecodeException("Could not parse first XML object! Not an object nor an array!");
        }
    }

    // Decode error or empty string!
    throw XmlDecodeException("Could not parse first XML object! Syntax error or string is empty!");
}

ffw::Any ffw::decodeXml(const std::string& input) {
    return decodeXml(input.c_str());
}

ffw::Any ffw::decodeXmlFile(const std::string& path) {
    return ffw::Any();
}