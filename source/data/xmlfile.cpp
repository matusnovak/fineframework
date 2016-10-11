/*** This file is part of FineFramework project ***/

#include "ffw/data/xmlfile.h"
#include "tinyxml2.h"
#include <fstream>

static void convertXML(tinyxml2::XMLElement* XML, ffw::Var* Output);
static void insertToObject(tinyxml2::XMLElement* root, ffw::Var* Output);
static void insertToArray(tinyxml2::XMLElement* root, ffw::Var* Output);

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
static void insertToObject(tinyxml2::XMLElement* root, ffw::Var* Output){
    if(root->FirstChild() != NULL){
        // Parent does have children
        if(root->GetText() != NULL){
            // Children is a simple text
            const tinyxml2::XMLAttribute* attributePtr = root->FirstAttribute();
            if(attributePtr == NULL){
                Output->GetAsObject().insert(std::make_pair(root->Name(), parseVariable(root->GetText())));
            } else {
                auto result = Output->GetAsObject().insert(std::make_pair(root->Name(), ffw::VarObject()));
                while(attributePtr != NULL){
                    result.first->second.GetAsObject().insert(std::pair<std::string, ffw::Var>("@" + std::string(attributePtr->Name()), parseVariable(attributePtr->Value())));
                    attributePtr = attributePtr->Next();
                }
                result.first->second.GetAsObject().insert(std::pair<std::string, ffw::Var>("content", parseVariable(root->GetText())));
            }

        } else {
            // Children has more elements
            const tinyxml2::XMLAttribute* attributePtr = root->FirstAttribute();
            if(attributePtr == NULL){
                auto result = Output->GetAsObject().insert(std::make_pair(root->Name(), ffw::VarObject()));
                convertXML(root->FirstChildElement(), &(result.first->second));

            } else {
                auto result = Output->GetAsObject().insert(std::make_pair(root->Name(), ffw::VarObject()));
                while(attributePtr != NULL){
                    result.first->second.GetAsObject().insert(std::pair<std::string, ffw::Var>("@" + std::string(attributePtr->Name()), parseVariable(attributePtr->Value())));
                    attributePtr = attributePtr->Next();
                }
                result = result.first->second.GetAsObject().insert(std::make_pair("content", ffw::VarObject()));
                convertXML(root->FirstChildElement(), &(result.first->second));
            }
        }
    } else {
        // Parent does not have children
        const tinyxml2::XMLAttribute* attributePtr = root->FirstAttribute();
        if(attributePtr == NULL){
            Output->GetAsObject().insert(std::make_pair(root->Name(), ""));
        } else {
            auto result = Output->GetAsObject().insert(std::make_pair(root->Name(), ffw::VarObject()));
            while(attributePtr != NULL){
                result.first->second.GetAsObject().insert(std::pair<std::string, ffw::Var>("@" + std::string(attributePtr->Name()), parseVariable(attributePtr->Value())));
                attributePtr = attributePtr->Next();
            }
        }
    }
}

///=============================================================================
static void insertToArray(tinyxml2::XMLElement* root, ffw::Var* Output){
    if(root->FirstChild() != NULL){
        // Parent does have children
        if(root->GetText() != NULL){
            // Children is a simple text
            const tinyxml2::XMLAttribute* attributePtr = root->FirstAttribute();
            if(attributePtr == NULL){
                Output->GetAsArray().push_back(parseVariable(root->GetText()));
            } else {
                Output->GetAsArray().push_back(ffw::VarObject());
                auto result = &(Output->GetAsArray().at(Output->GetAsArray().size()-1));
                while(attributePtr != NULL){
                    result->GetAsObject().insert(std::pair<std::string, ffw::Var>("@" + std::string(attributePtr->Name()), parseVariable(attributePtr->Value())));
                    attributePtr = attributePtr->Next();
                }
                result->GetAsObject().insert(std::pair<std::string, ffw::Var>("content", parseVariable(root->GetText())));
            }
        } else {
            // Children has more elements
            const tinyxml2::XMLAttribute* attributePtr = root->FirstAttribute();
            if(attributePtr == NULL){
                Output->GetAsArray().push_back(ffw::VarObject());
                convertXML(root->FirstChildElement(), &(Output->GetAsArray().at(Output->GetAsArray().size()-1)));

            } else {
                Output->GetAsArray().push_back(ffw::VarObject());
                auto result = &(Output->GetAsArray().at(Output->GetAsArray().size()-1));
                while(attributePtr != NULL){
                    result->GetAsObject().insert(std::pair<std::string, ffw::Var>("@" + std::string(attributePtr->Name()), parseVariable(attributePtr->Value())));
                    attributePtr = attributePtr->Next();
                }
                auto resultPair = result->GetAsObject().insert(std::make_pair("content", ffw::VarObject()));
                convertXML(root->FirstChildElement(), &(resultPair.first->second));
            }
        }
    } else {
        // Parent does not have children
        const tinyxml2::XMLAttribute* attributePtr = root->FirstAttribute();
        if(attributePtr == NULL){
            Output->GetAsArray().push_back(parseVariable(root->Name()));
        } else {
            Output->GetAsArray().push_back(ffw::VarObject());
            auto result = &(Output->GetAsArray().at(Output->GetAsArray().size()-1));
            while(attributePtr != NULL){
                result->GetAsObject().insert(std::pair<std::string, ffw::Var>("@" + std::string(attributePtr->Name()), parseVariable(attributePtr->Value())));
                attributePtr = attributePtr->Next();
            }
        }
    }
}

///=============================================================================
static void convertXML(tinyxml2::XMLElement* XML, ffw::Var* Output){
    tinyxml2::XMLElement* root = XML;
    while(root != NULL){
        // Check if var is a object
        if(Output->GetType() == ffw::Var::Type::vObject){
            // Check if element exists in array
            auto found = Output->GetAsObject().find(root->Name());
            if(found != Output->GetAsObject().end()){

                if(found->second.GetType() != ffw::Var::Type::vArray){
                    // Element already exists! Convert to array...
                    ffw::Var temp = found->second;
                    found->second = ffw::VarArray();
                    found->second.GetAsArray().push_back(temp);
                    //found->second.getAsArray().push_back(ffw::varArray());
                    insertToArray(root, &(found->second));
                } else {
                    // Element found but is not an array
                    insertToArray(root, &(found->second));
                }
            } else {
                // Element does not exists!
                insertToObject(root, Output);
            }
        } else {
            // Var is array
            insertToArray(root, Output);
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
static bool checkIfAttributesEmpty(ffw::Var* Input){
    if(Input->GetType() != ffw::Var::Type::vObject){
        return false;
    }

    for(auto it = Input->GetAsObject().begin(); it != Input->GetAsObject().end(); it++){
        if(it->first[0] == '@')continue;
        else return false;
    }

    return true;
}

///=============================================================================
static bool checkIfAttributesContent(ffw::Var* Input){
    if(Input->GetType() != ffw::Var::Type::vObject){
        return false;
    }

    for(auto it = Input->GetAsObject().begin(); it != Input->GetAsObject().end(); it++){
        if(it->first[0] == '@')continue;
        else if(it->first == "content")continue;
        else return false;
    }

    return true;
}

///=============================================================================
static void encodeXMLFunc(std::string* Output, ffw::Var* Var, bool Formated, std::string& Indent, bool EscapeUnicode, const std::string& ArrayTag){
    ffw::Var::Type varType = Var->GetType();

    if(varType == ffw::Var::Type::vString){
        (*Output) += escapeString(Var->GetAsString(), EscapeUnicode);

    } else if(varType == ffw::Var::Type::vInt){
        (*Output) += ffw::ValToString(Var->GetAsInt());

    } else if(varType == ffw::Var::Type::vFloat){
        (*Output) += ffw::ValToString(Var->GetAsFloat());

    } else if(varType == ffw::Var::Type::vBool){
        if(Var->GetAsBool())(*Output) += "true";
        else (*Output) += "false";

    } else if(varType == ffw::Var::Type::vNull){
        (*Output) += "null";

    } else if(varType == ffw::Var::Type::vObject){
        //(*Output) += Indent

        for(auto it = Var->GetAsObject().begin(); it != Var->GetAsObject().end(); it++){
            if(checkIfAttributesEmpty(&(it->second))){
                std::string attr;
                if(Formated)
                    attr += Indent + "<" + escapeString(it->first, EscapeUnicode) + " ";
                else
                    attr += "<" + escapeString(it->first, EscapeUnicode) + " ";
                for(auto itit = it->second.GetAsObject().begin(); itit != it->second.GetAsObject().end(); itit++){
                    attr += itit->first.substr(1, itit->first.size()-1) + "=\"";
                    if     (itit->second.GetType() == ffw::Var::Type::vString)attr += escapeString(itit->second.GetAsString(), EscapeUnicode) + "\"";
                    else if(itit->second.GetType() == ffw::Var::Type::vInt)attr += ffw::ValToString(itit->second.GetAsInt()) + "\"";
                    else if(itit->second.GetType() == ffw::Var::Type::vFloat)attr += ffw::ValToString(itit->second.GetAsFloat()) + "\"";
                    else if(itit->second.GetType() == ffw::Var::Type::vBool){
                         if(itit->second.GetAsBool())attr += "true\"";
                         else attr += "false\"";
                    }
                    else if(itit->second.GetType() == ffw::Var::Type::vNull)attr += "null\"";
                    else attr += "\"";
                }
                if(Formated)
                    (*Output) += attr + " />\n";
                else
                    (*Output) += attr + " />";

            } else if(checkIfAttributesContent(&(it->second))){
                std::string attr;
                if(Formated)
                    attr += Indent + "<" + escapeString(it->first, EscapeUnicode) + " ";
                else
                    attr += "<" + escapeString(it->first, EscapeUnicode) + " ";
                for(auto itit = it->second.GetAsObject().begin(); itit != it->second.GetAsObject().end(); itit++){
                    if(itit->first[0] != '@')continue;
                    attr += itit->first.substr(1, itit->first.size()-1) + "=\"";
                    if     (itit->second.GetType() == ffw::Var::Type::vString)attr += escapeString(itit->second.GetAsString(), EscapeUnicode) + "\"";
                    else if(itit->second.GetType() == ffw::Var::Type::vInt)attr += ffw::ValToString(itit->second.GetAsInt()) + "\"";
                    else if(itit->second.GetType() == ffw::Var::Type::vFloat)attr += ffw::ValToString(itit->second.GetAsFloat()) + "\"";
                    else if(itit->second.GetType() == ffw::Var::Type::vBool){
                         if(itit->second.GetAsBool())attr += "true\"";
                         else attr += "false\"";
                    }
                    else if(itit->second.GetType() == ffw::Var::Type::vNull)attr += "null\"";
                    else attr += "\"";
                }

                bool isContentObject = false;
                bool isContentArray = false;

                if     (it->second.GetAsObject()["content"].GetType() == ffw::Var::Type::vObject)isContentObject = true;
                else if(it->second.GetAsObject()["content"].GetType() == ffw::Var::Type::vArray)isContentArray = true;

                if(isContentObject || isContentArray){
                    (*Output) += attr + ">\n";
                    Indent += "    ";
                }else{
                    (*Output) += attr + ">";
                }

                encodeXMLFunc(Output, &(it->second.GetAsObject()["content"]), Formated, Indent, EscapeUnicode, "element");

                if(Formated){
                    if(isContentObject || isContentArray){
                        Indent = Indent.substr(0, Indent.size()-4);
                        (*Output) += Indent + "</" + escapeString(it->first, EscapeUnicode) + ">\n";
                    } else {
                        (*Output) += "</" + escapeString(it->first, EscapeUnicode) + ">\n";
                    }
                } else {
                    (*Output) += "</" + escapeString(it->first, EscapeUnicode) + ">";
                }

            } else {
                bool inside = false;
                bool isArray = false;
                if(it->second.GetType() == ffw::Var::Type::vArray)isArray = true;

                if(Formated &&
                        ((it->second.GetType() == ffw::Var::Type::vObject && it->second.GetAsObject().begin() != it->second.GetAsObject().end())
                      || (it->second.GetType() == ffw::Var::Type::vArray && it->second.GetAsArray().size() > 0)) ){

                    if(!isArray)(*Output) += Indent + "<" + escapeString(it->first, EscapeUnicode) + ">\n";
                    if(!isArray)Indent += "    ";
                    inside = true;
                } else if(Formated){
                    if(!isArray)(*Output) += Indent + "<" + escapeString(it->first, EscapeUnicode) + ">";
                } else {
                    if(!isArray)(*Output) += "<" + escapeString(it->first, EscapeUnicode) + ">";
                }

                encodeXMLFunc(Output, &(it->second), Formated, Indent, EscapeUnicode, escapeString(it->first, EscapeUnicode));

                if(Formated){
                    if(inside){
                        if(!isArray)Indent = Indent.substr(0, Indent.size()-4);
                        if(!isArray)(*Output) += Indent + "</" + escapeString(it->first, EscapeUnicode) + ">\n";
                    } else {
                        if(!isArray)(*Output) += "</" + escapeString(it->first, EscapeUnicode) + ">\n";
                    }
                } else {
                    if(!isArray)(*Output) += "</" + escapeString(it->first, EscapeUnicode) + ">";
                }
            }
        }
    } else if(varType == ffw::Var::Type::vArray){

        for(size_t i = 0; i < Var->GetAsArray().size(); i++){
            bool inside = false;
            std::string arrayTagCopy = ArrayTag;
            if(Var->GetAsArray().at(i).GetType() == ffw::Var::Type::vArray){
                arrayTagCopy = "element";
            }

            if(Formated &&
                    ((Var->GetAsArray().at(i).GetType() == ffw::Var::Type::vObject && Var->GetAsArray().at(i).GetAsObject().begin() != Var->GetAsArray().at(i).GetAsObject().end())
                  || (Var->GetAsArray().at(i).GetType() == ffw::Var::Type::vArray && Var->GetAsArray().at(i).GetAsArray().size() > 0)) ){
                (*Output) += Indent + "<" + arrayTagCopy + ">\n";
                Indent += "    ";
                inside = true;
            } else if(Formated){
                (*Output) += Indent + "<" + arrayTagCopy + ">";
            } else {
                (*Output) += "<" + arrayTagCopy + ">";
            }

            encodeXMLFunc(Output, &(Var->GetAsArray().at(i)), Formated, Indent, EscapeUnicode, "element");
            if(Formated){
                if(inside){
                    Indent = Indent.substr(0, Indent.size()-4);
                    (*Output) += Indent + "</" + arrayTagCopy + ">\n";
                } else {
                    (*Output) += "</" + arrayTagCopy + ">\n";
                }
            } else {
                (*Output) += "</" + arrayTagCopy + ">";
            }
        }
    }
}

///=============================================================================
bool ffw::DecodeXml(const std::string& Str, ffw::Var* Output){
    if(Output == NULL)return false;
    if(Str.size() == 0)return false;

    tinyxml2::XMLDocument doc;
    doc.Parse(Str.c_str());
    if(doc.Error())return false;
    *Output = ffw::VarObject();
    convertXML(doc.RootElement(), Output);
    return true;
}

///=============================================================================
void ffw::EncodeXml(std::string* Output, ffw::Var* Var, bool Formated, bool EscapeUnicode){
    if(Output == NULL)return;
    if(Var == NULL)return;

    std::string indent;
    Output->clear();
    (*Output) += "<?xml version=\"1.0\" encoding=\"UTF-8\"?>";
    if(Formated)(*Output) += "\n";
    encodeXMLFunc(Output, Var, Formated, indent, EscapeUnicode, "");
}

///=============================================================================
bool ffw::LoadXml(const std::string& Path, ffw::Var* Output){
    if(Output == NULL)return false;

    tinyxml2::XMLDocument doc;
    doc.LoadFile(Path.c_str());
	if (doc.Error()){
		return false;
	}
    *Output = ffw::VarObject();
    convertXML(doc.RootElement(), Output);
    return true;
}

///=============================================================================
bool ffw::SaveXml(const std::string& Path, ffw::Var* Input, bool Formated, bool EscapeUnicode){
    if(Input == NULL)return false;

    std::fstream output(Path, std::ios::trunc | std::ios::out);
    if(!output){
        return false;
    }

    std::string encoded;
    EncodeXml(&encoded, Input, Formated, EscapeUnicode);

    output.write(&encoded[0], encoded.size());
    output.close();
    return true;
}
