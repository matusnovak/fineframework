/*** This file is part of FineFramework project ***/

#include "ffw/data/xmlfile.h"
#include "tinyxml2.h"
#include <fstream>

static void convertXML(tinyxml2::XMLElement* XML, ffw::Var& output);
static void insertToObject(tinyxml2::XMLElement* root, ffw::Var& output);
static void insertToArray(tinyxml2::XMLElement* root, ffw::Var& output);

///=============================================================================
static bool checkIfInt(const std::string& Str){
    for(const auto& chr : Str){
        if(chr == 10 || chr == 13 || chr == 32 || chr == 9)continue;
        if(!((chr >= '0' && chr  <= '9') || chr == '-')){
            return false;
        }
    }
    return true;
}

///=============================================================================
static bool checkIfFloat(const std::string& Str){
    for(const auto& chr : Str){
        if(chr == 10 || chr == 13 || chr == 32 || chr == 9)continue;
        if(!((chr >= '0' && chr  <= '9') || chr == '-' || chr == '+' || chr == '.' || chr == 'e' || chr == 'E')){
            return false;
        }
    }
    return true;
}

///=============================================================================
static bool checkIfBool(const std::string& Str, bool* Bool){
    if(Str.size() == 4 && (Str.find("true") == 0 || Str.find("TRUE") == 0)){
        *Bool = true;
        return true;
    } else if (Str.size() == 5 && (Str.find("false") == 0 || Str.find("FALSE") == 0)){
        *Bool = false;
        return true;
    }
    return false;
}

///=============================================================================
static ffw::Var parseVariable(const std::string& Str){
    ffw::Var variable;
    bool test;
    if(checkIfInt(Str)){
        variable = ffw::StringToVal<int>(Str);
        return variable;
    } else if(checkIfFloat(Str)){
        variable = ffw::StringToVal<float>(Str);
        return variable;
    } else if(checkIfBool(Str, &test)){
        variable = test;
        return variable;
    }
    variable = Str;
    return variable;
}

///=============================================================================
static void insertToObject(tinyxml2::XMLElement* root, ffw::Var& output){
    if(root->FirstChild() != NULL){
        // Parent does have children
        if(root->GetText() != NULL){
            // Children is a simple text
            const tinyxml2::XMLAttribute* attributePtr = root->FirstAttribute();
            if(attributePtr == NULL){
                output.GetAs<ffw::Object>().insert(std::make_pair(root->Name(), parseVariable(root->GetText())));
            } else {
                auto result = output.GetAs<ffw::Object>().insert(std::make_pair(root->Name(), ffw::Object()));
                while(attributePtr != NULL){
                    result.first->second.GetAs<ffw::Object>().insert(std::pair<std::string, ffw::Var>("@" + std::string(attributePtr->Name()), parseVariable(attributePtr->Value())));
                    attributePtr = attributePtr->Next();
                }
                result.first->second.GetAs<ffw::Object>().insert(std::pair<std::string, ffw::Var>("content", parseVariable(root->GetText())));
            }

        } else {
            // Children has more elements
            const tinyxml2::XMLAttribute* attributePtr = root->FirstAttribute();
            if(attributePtr == NULL){
                auto result = output.GetAs<ffw::Object>().insert(std::make_pair(root->Name(), ffw::Object()));
                convertXML(root->FirstChildElement(), result.first->second);

            } else {
                auto result = output.GetAs<ffw::Object>().insert(std::make_pair(root->Name(), ffw::Object()));
                while(attributePtr != NULL){
                    result.first->second.GetAs<ffw::Object>().insert(std::pair<std::string, ffw::Var>("@" + std::string(attributePtr->Name()), parseVariable(attributePtr->Value())));
                    attributePtr = attributePtr->Next();
                }
                result = result.first->second.GetAs<ffw::Object>().insert(std::make_pair("content", ffw::Object()));
                convertXML(root->FirstChildElement(), result.first->second);
            }
        }
    } else {
        // Parent does not have children
        const tinyxml2::XMLAttribute* attributePtr = root->FirstAttribute();
        if(attributePtr == NULL){
            output.GetAs<ffw::Object>().insert(std::make_pair(root->Name(), ""));
        } else {
            auto result = output.GetAs<ffw::Object>().insert(std::make_pair(root->Name(), ffw::Object()));
            while(attributePtr != NULL){
                result.first->second.GetAs<ffw::Object>().insert(std::pair<std::string, ffw::Var>("@" + std::string(attributePtr->Name()), parseVariable(attributePtr->Value())));
                attributePtr = attributePtr->Next();
            }
        }
    }
}

///=============================================================================
static void insertToArray(tinyxml2::XMLElement* root, ffw::Var& output){
    if(root->FirstChild() != NULL){
        // Parent does have children
        if(root->GetText() != NULL){
            // Children is a simple text
            const tinyxml2::XMLAttribute* attributePtr = root->FirstAttribute();
            if(attributePtr == NULL){
                output.GetAs<ffw::Array>().push_back(parseVariable(root->GetText()));
            } else {
                output.GetAs<ffw::Array>().push_back(ffw::Object());
                auto result = &(output.GetAs<ffw::Array>().at(output.GetAs<ffw::Array>().size()-1));
                while(attributePtr != NULL){
                    result->GetAs<ffw::Object>().insert(std::pair<std::string, ffw::Var>("@" + std::string(attributePtr->Name()), parseVariable(attributePtr->Value())));
                    attributePtr = attributePtr->Next();
                }
                result->GetAs<ffw::Object>().insert(std::pair<std::string, ffw::Var>("content", parseVariable(root->GetText())));
            }
        } else {
            // Children has more elements
            const tinyxml2::XMLAttribute* attributePtr = root->FirstAttribute();
            if(attributePtr == NULL){
                output.GetAs<ffw::Array>().push_back(ffw::Object());
                convertXML(root->FirstChildElement(), output.GetAs<ffw::Array>().at(output.GetAs<ffw::Array>().size()-1));

            } else {
                output.GetAs<ffw::Array>().push_back(ffw::Object());
                auto result = &(output.GetAs<ffw::Array>().at(output.GetAs<ffw::Array>().size()-1));
                while(attributePtr != NULL){
                    result->GetAs<ffw::Object>().insert(std::pair<std::string, ffw::Var>("@" + std::string(attributePtr->Name()), parseVariable(attributePtr->Value())));
                    attributePtr = attributePtr->Next();
                }
                auto resultPair = result->GetAs<ffw::Object>().insert(std::make_pair("content", ffw::Object()));
                convertXML(root->FirstChildElement(), resultPair.first->second);
            }
        }
    } else {
        // Parent does not have children
        const tinyxml2::XMLAttribute* attributePtr = root->FirstAttribute();
        if(attributePtr == NULL){
            output.GetAs<ffw::Array>().push_back(parseVariable(root->Name()));
        } else {
            output.GetAs<ffw::Array>().push_back(ffw::Object());
            auto result = &(output.GetAs<ffw::Array>().at(output.GetAs<ffw::Array>().size()-1));
            while(attributePtr != NULL){
                result->GetAs<ffw::Object>().insert(std::pair<std::string, ffw::Var>("@" + std::string(attributePtr->Name()), parseVariable(attributePtr->Value())));
                attributePtr = attributePtr->Next();
            }
        }
    }
}

///=============================================================================
static void convertXML(tinyxml2::XMLElement* XML, ffw::Var& output){
    tinyxml2::XMLElement* root = XML;
    while(root != NULL){
        // Check if var is a object
        if(output.Typeid() == typeid(ffw::Object)){
            // Check if element exists in array
            auto found = output.GetAs<ffw::Object>().find(root->Name());
            if(found != output.GetAs<ffw::Object>().end()){

                if(found->second.Typeid() != typeid(ffw::Array)){
                    // Element already exists! Convert to array...
                    ffw::Var temp = found->second;
                    found->second = ffw::Array();
                    found->second.GetAs<ffw::Array>().push_back(temp);
                    //found->second.GetAs<ffw::Array>().push_back(ffw::Array());
                    insertToArray(root, found->second);
                } else {
                    // Element found but is not an array
                    insertToArray(root, found->second);
                }
            } else {
                // Element does not exists!
                insertToObject(root, output);
            }
        } else {
            // Var is array
            insertToArray(root, output);
        }

        root = root->NextSiblingElement();
    }
}

///=============================================================================
static std::string toUnicode(uint16_t Chr){
    std::string out = "xxxx;";
    char a = static_cast<char>(Chr / 4096);
    char b = static_cast<char>((Chr -(a*4096)) / 256);
    char c = static_cast<char>((Chr -(a*4096) -(b*256)) / 16);
    char d = static_cast<char>(Chr -(a*4096) -(b*256) -(c*16));
    if(a >= 10) a = 'A'+(a-10);
    else a = '0' + a;
    if(b >= 10) b = 'A'+(b-10);
    else b = '0' + b;
    if(c >= 10) c = 'A'+(c-10);
    else c = '0' + c;
    if(d >= 10) d = 'A'+(d-10);
    else d = '0' + d;
    out[0] = a;
    out[1] = b;
    out[2] = c;
    out[3] = d;
    return out;
}

///=============================================================================
static std::string escapeString(std::string Str, bool EscapeUnicode){
    if(Str.size() == 0)return "";
    for(size_t i = 0; ; i++){
        if((unsigned char)Str[i] < 32){
            if(Str[i] == 8){
                Str.replace(i, 1, "&#x0008;");
                i += 7;
            } else if(Str[i] == 9){
                Str.replace(i, 1, "&#x0009;");
                i += 7;
            } else if(Str[i] == 10){
                Str.replace(i, 1, "&#x000A;");
                i += 7;
            } else if(Str[i] == 12){
                Str.replace(i, 1, "&#x000C;");
                i += 7;
            } else if(Str[i] == 13){
                Str.replace(i, 1, "&#x000D;");
                i += 7;
            } else {
                Str.replace(i, 1, "&#x" + toUnicode((unsigned char)(Str[i])));
                i += 7;
            }
        } else if(uint16_t((uint8_t)Str[i]) > 127 && EscapeUnicode){
            /*size_t p = 0;
            while(uint16_t((uint8_t)Str[i+p]) > 127 && i+p < Str.size()){
                p++;
            }
            std::wstring mstr = ffw::utf8ToWstr(Str.substr(i, p));
            Str.replace(i, p, "&#x" + toUnicode((unsigned short)(mstr[0])));
            i += 7;*/

            size_t p = 0;
            while(uint16_t((uint8_t)Str[i+p]) > 127 && i+p < Str.size()){
                p++;
            }

            std::wstring mbstr = ffw::Utf8ToWstr(Str.substr(i, p));
            //std::cout << "replacing: " << mstr[0] << std::endl;
            std::string unicodeStr;
            for(const auto& chr : mbstr){
                unicodeStr += "&#x" + toUnicode((uint16_t)chr);
            }
            Str.replace(i, p, unicodeStr);
            i+= unicodeStr.size();

        } else if(Str[i] == '\"'){
            Str.replace(i, 1, "&quot;");
            i += 5;
        } else if(Str[i] == '\"'){
            Str.replace(i, 1, "&apos;");
            i += 5;
        } else if(Str[i] == '&'){
            Str.replace(i, 1, "&amp;");
            i += 4;
        } else if(Str[i] == '<'){
            Str.replace(i, 1, "&lt;");
            i += 3;
        } else if(Str[i] == '>'){
            Str.replace(i, 1, "&gt;");
            i += 3;
        }
        if(i >= Str.size()-1)break;
    }
    return Str;
}

///=============================================================================
static bool checkIfAttributesEmpty(const ffw::Var* Input){
    if(Input->Typeid() != typeid(ffw::Object)){
        return false;
    }

    for(auto it = Input->GetAs<ffw::Object>().begin(); it != Input->GetAs<ffw::Object>().end(); it++){
        if(it->first[0] == '@')continue;
        else return false;
    }

    return true;
}

///=============================================================================
static bool checkIfAttributesContent(const ffw::Var* Input){
    if(Input->Typeid() != typeid(ffw::Object)){
        return false;
    }

    for(auto it = Input->GetAs<ffw::Object>().begin(); it != Input->GetAs<ffw::Object>().end(); it++){
        if(it->first[0] == '@')continue;
        else if(it->first == "content")continue;
        else return false;
    }

    return true;
}

///=============================================================================
static void encodeXMLFunc(std::ostream& output, const ffw::Var& var, bool Formated, std::string& Indent, bool EscapeUnicode, const std::string& ArrayTag){
    const auto& varType = var.Typeid();

    /*if(varType == typeid(std::string)){
        output << escapeString(var.GetAs<std::string>(), EscapeUnicode);

    } else if(varType == typeid(int)){
        output << ffw::ValToString(var.GetAs<int>());

    } else if(varType == typeid(float)){
        output << ffw::ValToString(var.GetAs<float>());*/

	if(var.ContainsString()){
		output << escapeString(var.String(), EscapeUnicode);

	} else if(varType == typeid(bool)){
        if(var.GetAs<bool>())output << "true";
        else output << "false";

	} else if(var.ContainsInt()){
		output << ffw::ValToString(var.Int());

	} else if(var.ContainsFloat()){
		output << ffw::ValToString(var.Float());

    } else if(varType == typeid(std::nullptr_t)){
        output << "null";

    } else if(varType == typeid(ffw::Object)){
        //output << Indent

        for(auto it = var.GetAs<ffw::Object>().begin(); it != var.GetAs<ffw::Object>().end(); it++){
            if(checkIfAttributesEmpty(&(it->second))){
                std::string attr;
                if(Formated)
                    attr += Indent + "<" + escapeString(it->first, EscapeUnicode) + " ";
                else
                    attr += "<" + escapeString(it->first, EscapeUnicode) + " ";
                for(auto itit = it->second.GetAs<ffw::Object>().begin(); itit != it->second.GetAs<ffw::Object>().end(); itit++){
                    attr += itit->first.substr(1, itit->first.size()-1) + "=\"";
                    if     (itit->second.Typeid() == typeid(std::string))attr += escapeString(itit->second.GetAs<std::string>(), EscapeUnicode) + "\"";
                    else if(itit->second.Typeid() == typeid(int))attr += ffw::ValToString(itit->second.GetAs<int>()) + "\"";
                    else if(itit->second.Typeid() == typeid(float))attr += ffw::ValToString(itit->second.GetAs<float>()) + "\"";
                    else if(itit->second.Typeid() == typeid(bool)){
                         if(itit->second.GetAs<bool>())attr += "true\"";
                         else attr += "false\"";
                    }
                    else if(itit->second.Typeid() == typeid(std::nullptr_t))attr += "null\"";
                    else attr += "\"";
                }
                if(Formated)
                    output << attr + " />\n";
                else
                    output << attr + " />";

            } else if(checkIfAttributesContent(&(it->second))){
                std::string attr;
                if(Formated)
                    attr += Indent + "<" + escapeString(it->first, EscapeUnicode) + " ";
                else
                    attr += "<" + escapeString(it->first, EscapeUnicode) + " ";
                for(auto itit = it->second.GetAs<ffw::Object>().begin(); itit != it->second.GetAs<ffw::Object>().end(); itit++){
                    if(itit->first[0] != '@')continue;
                    attr += itit->first.substr(1, itit->first.size()-1) + "=\"";
                    if     (itit->second.Typeid() == typeid(std::string))attr += escapeString(itit->second.GetAs<std::string>(), EscapeUnicode) + "\"";
                    else if(itit->second.Typeid() == typeid(int))attr += ffw::ValToString(itit->second.GetAs<int>()) + "\"";
                    else if(itit->second.Typeid() == typeid(float))attr += ffw::ValToString(itit->second.GetAs<float>()) + "\"";
                    else if(itit->second.Typeid() == typeid(bool)){
                         if(itit->second.GetAs<bool>())attr += "true\"";
                         else attr += "false\"";
                    }
                    else if(itit->second.Typeid() == typeid(std::nullptr_t))attr += "null\"";
                    else attr += "\"";
                }

                bool isContentObject = false;
                bool isContentArray = false;

                if     (it->second.GetAs<ffw::Object>()["content"].Typeid() == typeid(ffw::Object))isContentObject = true;
                else if(it->second.GetAs<ffw::Object>()["content"].Typeid() == typeid(ffw::Array))isContentArray = true;

                if(isContentObject || isContentArray){
                    output << attr + ">\n";
                    Indent += "    ";
                }else{
                    output << attr + ">";
                }

                encodeXMLFunc(output, it->second.GetAs<ffw::Object>()["content"], Formated, Indent, EscapeUnicode, "element");

                if(Formated){
                    if(isContentObject || isContentArray){
                        Indent = Indent.substr(0, Indent.size()-4);
                        output << Indent + "</" + escapeString(it->first, EscapeUnicode) + ">\n";
                    } else {
                        output << "</" + escapeString(it->first, EscapeUnicode) + ">\n";
                    }
                } else {
                    output << "</" + escapeString(it->first, EscapeUnicode) + ">";
                }

            } else {
                bool inside = false;
                bool isArray = false;
                if(it->second.Typeid() == typeid(ffw::Array))isArray = true;

                if(Formated &&
                        ((it->second.Typeid() == typeid(ffw::Object) && it->second.GetAs<ffw::Object>().begin() != it->second.GetAs<ffw::Object>().end())
                      || (it->second.Typeid() == typeid(ffw::Array) && it->second.GetAs<ffw::Array>().size() > 0)) ){

                    if(!isArray)output << Indent + "<" + escapeString(it->first, EscapeUnicode) + ">\n";
                    if(!isArray)Indent += "    ";
                    inside = true;
                } else if(Formated){
                    if(!isArray)output << Indent + "<" + escapeString(it->first, EscapeUnicode) + ">";
                } else {
                    if(!isArray)output << "<" + escapeString(it->first, EscapeUnicode) + ">";
                }

                encodeXMLFunc(output, it->second, Formated, Indent, EscapeUnicode, escapeString(it->first, EscapeUnicode));

                if(Formated){
                    if(inside){
                        if(!isArray)Indent = Indent.substr(0, Indent.size()-4);
                        if(!isArray)output << Indent + "</" + escapeString(it->first, EscapeUnicode) + ">\n";
                    } else {
                        if(!isArray)output << "</" + escapeString(it->first, EscapeUnicode) + ">\n";
                    }
                } else {
                    if(!isArray)output << "</" + escapeString(it->first, EscapeUnicode) + ">";
                }
            }
        }
    } else if(varType == typeid(ffw::Array)){

        for(size_t i = 0; i < var.GetAs<ffw::Array>().size(); i++){
            bool inside = false;
            std::string arrayTagCopy = ArrayTag;
            if(var.GetAs<ffw::Array>().at(i).Typeid() == typeid(ffw::Array)){
                arrayTagCopy = "element";
            }

            if(Formated &&
                    ((var.GetAs<ffw::Array>().at(i).Typeid() == typeid(ffw::Object) && var.GetAs<ffw::Array>().at(i).GetAs<ffw::Object>().begin() != var.GetAs<ffw::Array>().at(i).GetAs<ffw::Object>().end())
                  || (var.GetAs<ffw::Array>().at(i).Typeid() == typeid(ffw::Array) && var.GetAs<ffw::Array>().at(i).GetAs<ffw::Array>().size() > 0)) ){
                output << Indent + "<" + arrayTagCopy + ">\n";
                Indent += "    ";
                inside = true;
            } else if(Formated){
                output << Indent + "<" + arrayTagCopy + ">";
            } else {
                output << "<" + arrayTagCopy + ">";
            }

            encodeXMLFunc(output, var.GetAs<ffw::Array>().at(i), Formated, Indent, EscapeUnicode, "element");
            if(Formated){
                if(inside){
                    Indent = Indent.substr(0, Indent.size()-4);
                    output << Indent + "</" + arrayTagCopy + ">\n";
                } else {
                    output << "</" + arrayTagCopy + ">\n";
                }
            } else {
                output << "</" + arrayTagCopy + ">";
            }
        }
    }
}

///=============================================================================
bool ffw::DecodeXml(const std::string& input, ffw::Var& output){
    tinyxml2::XMLDocument doc;
    doc.Parse(input.c_str());
    if(doc.Error())return false;

    output = ffw::Object();
    convertXML(doc.RootElement(), output);
    return true;
}

///=============================================================================
ffw::Var ffw::DecodeXml(const std::string& input){
	ffw::Var var;
	DecodeXml(input, var);
	return var;
}

///=============================================================================
void ffw::EncodeXml(const ffw::Var& input, std::string& output, bool formated, bool escape){
    std::string indent;

	std::stringstream stream;

    stream << "<?xml version=\"1.0\" encoding=\"UTF-8\"?>";
    if(formated)stream << "\n";
	stream << "<document>";
    encodeXMLFunc(stream, input, formated, indent, escape, "");
	if(formated)stream << "\n";
	stream << "</document>";

	output = stream.str();
}

///=============================================================================
std::string ffw::EncodeXml(const ffw::Var& input, bool formated, bool escape){
	std::string indent;

	std::stringstream stream;

    stream << "<?xml version=\"1.0\" encoding=\"UTF-8\"?>";
    if(formated)stream << "\n";
	stream << "<document>";
    encodeXMLFunc(stream, input, formated, indent, escape, "");
	if(formated)stream << "\n";
	stream << "</document>";

	return stream.str();
}

///=============================================================================
bool ffw::LoadXml(const std::string& path, ffw::Var& output){
    tinyxml2::XMLDocument doc;
    doc.LoadFile(path.c_str());
	if (doc.Error()){
		return false;
	}
    output = ffw::Object();
    convertXML(doc.RootElement(), output);
    return true;
}

///=============================================================================
bool ffw::SaveXml(const std::string& path, const ffw::Var& input, bool Formated, bool EscapeUnicode){
    std::fstream output(path, std::ios::trunc | std::ios::out);
    if(!output){
        return false;
    }

    std::string encoded;
    EncodeXml(input, encoded, Formated, EscapeUnicode);

    output.write(&encoded[0], encoded.size());
    output.close();
    return true;
}
