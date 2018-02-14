/*** This file is part of FineFramework project ***/

#include "ffw/data/xmlwriter.h"
#include "ffw/math/stringmath.h"
#include <fstream>
#include <regex>
#include <sstream>
#include <iostream>

static const char hexes[16] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'a', 'b', 'c', 'd', 'e', 'f'};

///=============================================================================
static bool checkValidTag(const char* val) {
    if (val == NULL)return false;
    if (*val == '\0')return false;
    if ((*val >= '0' && *val <= '9') || *val == '-')return false;

    while (*++val) {
        if (*val >= 'a' && *val <= 'z')continue;
        if (*val >= 'A' && *val <= 'Z')continue;
        if (*val >= '0' && *val <= '9')continue;
        switch (*val) {
            case '.': continue;
            case '_': continue;
            case '-': continue;
            case ':': continue;
        }
        return false;
    }
    return true;
}

///=============================================================================
static std::string encodeString(const char* val, bool utf8) {
    size_t total = 0;
    auto cpy = val;

    while (*cpy) {
        char c = *cpy++;

        if (utf8 && c & 0x80) {
            if ((c & 0xC0) == 0xC0) {
                // four byte sequence
                total += 8;
            }
            else if ((c & 0xE0) == 0xE0) {
                // three byte sequence
                total += 8;
            }
            else if ((c & 0xF0) == 0xF0) {
                // two byte sequence
                total += 8;
            }
            else {
                // Sequence
                //total++;
            }
        }
        else {
            switch (c) {
            case '<':
            case '>':
                total += 4;
                break;
            case '&':
                total += 5;
                break;
            case '\"':
            case '\'':
                total += 6;
                break;
            default:
                total++;
                break;
            }
        }
    }

    std::string out;
    out.reserve(total);
    int sequence = 0;
    int value = 0;

    while (*val) {
        char c = *val++;
        if (utf8 && c & 0x80) {
            if (sequence == 0 && (c & 0xF0) == 0xF0) {
                // two byte sequence
                sequence = 3;
                value = (c & 0x0F);

            }
            else if (sequence == 0 && (c & 0xE0) == 0xE0) {
                // three byte sequence
                sequence = 2;
                value = (c & 0x1F);

            }
            else if (sequence == 0 && (c & 0xC0) == 0xC0) {
                // four byte sequence
                sequence = 1;
                value = (c & 0x3F);

            }
            else {
                // Sequence
                if (sequence > 0) {

                    value = value << 6 | (c & 0x3F);
                    sequence--;

                    if (sequence == 0) {
                        out.append("&#x");
                        out.push_back(hexes[(value & 0xF000) >> 12]);
                        out.push_back(hexes[(value & 0x0F00) >> 8]);
                        out.push_back(hexes[(value & 0x00F0) >> 4]);
                        out.push_back(hexes[(value & 0x000F)]);
                        out.push_back(';');
                    }
                }
            }
        }
        else {
            switch (c) {
                case '<':
                    out.append("&lt;");
                    break;
                case '>':
                    out.append("&gt;");
                    break;
                case '&':
                    out.append("&amp;");
                    break;
                case '\"':
                    out.append("&quot;");
                    break;
                case '\'':
                    out.append("&apos;");
                    break;
                default:
                    out.push_back(c);
                    break;
            }
        }
    }

    return out;
}

///=============================================================================
ffw::XmlWriter::XmlWriter(Stream* ss, const char* ind, bool esc):stream(ss),indent(ind),escape(esc) {
    attribs = false;
}

///=============================================================================
ffw::XmlWriter::~XmlWriter() {

}

///=============================================================================
void ffw::XmlWriter::writeIndent() {
    for (size_t i = 0; i < keys.size(); i++) {
        if (!stream->write(indent, 0)) {
            throw XmlEncodeException("Failed to write to the stream!");
        }
    }
}

///=============================================================================
inline void ffw::XmlWriter::write(const char* str, size_t len) {
    if (!stream->write(str, len)) {
        throw XmlEncodeException("Failed to write to the stream!");
    }
}

///=============================================================================
void ffw::XmlWriter::addObject(const char* key) {
    if (!checkValidTag(key)) {
        throw XmlEncodeException("Invalid XML tag: " + std::string((key ? key : "")));
    }

    if (attribs) {
        throw XmlEncodeException("To add a new XML object, you must call beginContent() first!");
    }

    if (keys.size() > 0 && indent) {
        write("\n", 1);
        writeIndent();
    }
    write("<", 1);
    write(key, 0);
    attribs = true;
    keys.push_back(key);
}

///=============================================================================
void ffw::XmlWriter::stepOut() {
    if (keys.size() > 0) {
        if (attribs) {
            attribs = false;
            keys.pop_back();
            write("/>", 2);
        }
        else {
            auto cpy = std::move(keys.back());
            keys.pop_back();
            if (indent) {
                write("\n", 1);
                writeIndent();
            }
            write("</", 2);
            write(cpy.c_str(), 0);
            write(">", 1);
            attribs = false;
        }
    }
    else {
        throw XmlEncodeException("Can not step out! Already at the root level!");
    }
}

///=============================================================================
void ffw::XmlWriter::beginContent() {
    write(">", 1);
    attribs = false;
}

///=============================================================================
void ffw::XmlWriter::addBegin(const char* key) {
    if (!checkValidTag(key)) {
        throw XmlEncodeException("Invalid XML tag: " + std::string((key ? key : "")));
    }

    if (!attribs) {
        if (indent) {
            write("\n", 1);
            writeIndent();
        }
        write("<", 1);
        write(key, 0);
        write(">", 1);
    }
    else {
        write(" ", 1);
        write(key, 0);
        write("=\"", 2);
    }
}

///=============================================================================
void ffw::XmlWriter::addEnd(const char* key) {
    if (!attribs) {
        write("</", 2);
        write(key, 0);
        write(">", 1);
    }
    else {
        write("\"", 1);
    }
}

///=============================================================================
void ffw::XmlWriter::addInteger(int val, const char* key) {
    addBegin(key);

    auto str = std::to_string(val);
    write(str.c_str(), str.size());

    addEnd(key);
}

///=============================================================================
void ffw::XmlWriter::addFloat(float val, const char* key) {
    addBegin(key);

    auto str = std::to_string(val);
    write(str.c_str(), str.size());

    addEnd(key);
}

///=============================================================================
void ffw::XmlWriter::addBoolean(bool val, const char* key) {
    addBegin(key);
    
    if (val)write("true", 4);
    else write("false", 5);

    addEnd(key);
}

///=============================================================================
void ffw::XmlWriter::addNull(const char* key) {
    addBegin(key);
    
    write("null", 4);

    addEnd(key);
}

///=============================================================================
void ffw::XmlWriter::addString(const char* val, const char* key) {
    addBegin(key);

    auto str = encodeString(val, escape);
    write(str.c_str(), str.size());
    
    addEnd(key);
}

///=============================================================================
ffw::XmlWriter::StringStream::StringStream() {

}
ffw::XmlWriter::StringStream::~StringStream() {

}
bool ffw::XmlWriter::StringStream::write(const char* in, size_t len) {
    if (len == 0)len = strlen(in);

    if (str.size() + len > str.capacity()) {
        str.reserve(str.capacity() + 1024);
    }

    str.append(in);
    return true;
}

const std::string& ffw::XmlWriter::StringStream::get() const {
    return str;
}

///=============================================================================
ffw::XmlWriter::FileStream::FileStream(const std::string& path, std::ios_base::openmode mode) {
    file.open(path, mode);
}
ffw::XmlWriter::FileStream::~FileStream() {

}
bool ffw::XmlWriter::FileStream::isOpen() const {
    return file.is_open();
}
void ffw::XmlWriter::FileStream::close() {
    file.close();
}
bool ffw::XmlWriter::FileStream::write(const char* in, size_t len) {
    if (len == 0)len = strlen(in);

    if (file.write(in, len))return true;
    return false;
}

void encodeXmlObj(ffw::XmlWriter& xml, const ffw::Object& obj);

///=============================================================================
void encodeXmlArr(ffw::XmlWriter& xml, const ffw::Any& obj) {
    if (obj.is<ffw::Array>()) {
        for (const auto& elem : obj.getAsArray()) {
            xml.addObject("element");
            xml.beginContent();

            if (elem.is<ffw::Object>()) {
                encodeXmlObj(xml, elem.getAsObject());
            }
            else {
                encodeXmlArr(xml, obj);
            }

            xml.stepOut();
        }
    }

    else if (obj.isInt()) {
        xml.addInteger(obj.toInt(), "element");
    }

    else if (obj.isFloat()) {
        xml.addFloat(obj.toFloat(), "element");
    }

    else if (obj.isBool()) {
        xml.addBoolean(obj.toBool(), "element");
    }

    else if (obj.is<std::nullptr_t>()) {
        xml.addNull("element");
    }

    else if (obj.empty()) {
        xml.addString("", "element");
    }

    else if (obj.isString()) {
        xml.addString(obj.toString().c_str(), "element");
    }

    else {
        throw ffw::XmlEncodeException("Invalid data type: " + std::string(obj.getTypeid().name()));
    }
}

///=============================================================================
void encodeXmlObj(ffw::XmlWriter& xml, const ffw::Object& obj) {
    for (const auto& pair : obj) {
        if (pair.second.is<ffw::Object>()) {
            xml.addObject(pair.first.c_str());
            xml.beginContent();
            encodeXmlObj(xml, pair.second.getAsObject());
            xml.stepOut();
        }

        else if (pair.second.is<ffw::Array>()) {
            for (const auto& elem : pair.second.getAsArray()) {
                xml.addObject(pair.first.c_str());
                xml.beginContent();

                if (elem.is<ffw::Object>()) {
                    encodeXmlObj(xml, elem.getAsObject());
                }
                else {
                    encodeXmlArr(xml, obj);
                }

                xml.stepOut();
            }
        }

        else if (pair.second.isInt()) {
            xml.addInteger(pair.second.toInt(), pair.first.c_str());
        }

        else if (pair.second.isFloat()) {
            xml.addFloat(pair.second.toFloat(), pair.first.c_str());
        }

        else if (pair.second.isBool()) {
            xml.addBoolean(pair.second.toBool(), pair.first.c_str());
        }

        else if (pair.second.is<std::nullptr_t>()) {
            xml.addNull(pair.first.c_str());
        }

        else if (pair.second.empty()) {
            xml.addString("", pair.first.c_str());
        }

        else if (pair.second.isString()) {
            xml.addString(pair.second.toString().c_str(), pair.first.c_str());
        }

        else {
            throw ffw::XmlEncodeException("Invalid data type: " + std::string(pair.second.getTypeid().name()));
        }
    }
}

///=============================================================================
std::string ffw::encodeXml(const ffw::Any& input, const char* indent, bool escape) {
    ffw::XmlWriter::StringStream stream;
    ffw::XmlWriter xml(&stream, indent, escape);

    if (input.is<ffw::Object>()) {
        encodeXmlObj(xml, input.getAsObject());
    }
    else {
        throw ffw::XmlEncodeException("Could not encode XML! First node must be either an object!");
    }

    return stream.get();
}

///=============================================================================
bool ffw::encodeXmlFile(const std::string& path, const ffw::Any& input, const char* indent, bool escape) {
    ffw::XmlWriter::FileStream stream(path, std::ios::out | std::ios::binary);
    if (!stream.isOpen())return false;

    ffw::XmlWriter xml(&stream, indent, escape);
    if (input.is<ffw::Object>()) {
        encodeXmlObj(xml, input.getAsObject());
        stream.close();
    }
    else {
        throw ffw::XmlEncodeException("Could not encode XML! First node must be either an object!");
    }

    return true;
}