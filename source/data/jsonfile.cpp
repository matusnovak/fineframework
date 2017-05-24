/*** This file is part of FineFramework project ***/

#include "ffw/data/jsonfile.h"
#include "ffw/math/stringmath.h"
#include <fstream>
#include <regex>
#include <sstream>

///=============================================================================
static bool loadTxt(const std::string& path, std::string* output){
	if(output == NULL)return false;

	std::ifstream input(path);
	if(!input)return false;

	input.seekg(0, std::ios::end);
	output->reserve(static_cast<size_t>(input.tellg()));
	input.seekg(0, std::ios::beg);

	output->assign((std::istreambuf_iterator<char>(input)),
				std::istreambuf_iterator<char>());

    return true;
}

///=============================================================================
static std::string unicodeToUtf8(const std::string& Str, size_t Start){
    uint16_t value = 0;
    for(int i = 0; i < 4; i++){
        if(Str[Start+i] >= 'A' && Str[Start+i] <= 'F')value += (Str[Start+i] - 'A' + 10) * (uint16_t)pow(16, 3-i);
        else if(Str[Start+i] >= 'a' && Str[Start+i] <= 'f')value += (Str[Start+i] - 'a' + 10 )* (uint16_t)pow(16, 3-i);
        else if(Str[Start+i] >= '0' && Str[Start+i] <= '9')value += (Str[Start+i] - '0') * (uint16_t)pow(16, 3-i);
        else value += (uint16_t)pow(16, 3-i);
    }
    std::wstring wstr = L" ";
    wstr[0] = value;
    return ffw::wstrToUtf8(wstr);
}

///=============================================================================
static std::string toUnicode(uint16_t Chr){
    std::string out = "xxxx";
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
static std::string parseStringSimple(const std::string& Str){
    std::string out = Str;

	if(Str.size() == 0)return out;

    for(size_t i = 0; ; i++){
        if(out[i] == '\\' && i < out.size()-1){
            if(out[i+1] == '\"'){
                out.replace(i, 2, "\"");

            } else if(out[i+1] == '/'){
                out.replace(i, 2, "/");

            } else if(out[i+1] == '\\'){
                out.replace(i, 2, "\\");

			} else if(out[i+1] == 't'){
                out.replace(i, 2, "\t");

            } else if(out[i+1] == 'b'){
                out.replace(i, 2, " ");
                out[i] = 8;

            } else if(out[i+1] == 'f'){
                out.replace(i, 2, " ");
                out[i] = 12;

            } else if(out[i+1] == 'n'){
                out.replace(i, 2, " ");
                out[i] = 10;

            } else if(out[i+1] == 'r'){
                out.replace(i, 2, " ");
                out[i] = 13;

            } else if(out[i+1] == 'u' && i < out.size()-5){
                out.replace(i, 5, unicodeToUtf8(out, i+2));
                i++;
            }
        }
        if(i >= out.size()-1)break;
    }

    return out;
}

///=============================================================================
static std::string escapeString(std::string Str, bool EscapeUnicode){
    if(Str.size() == 0)return "";
    for(size_t i = 0; ; i++){
        if((unsigned char)Str[i] < 32){
            if(Str[i] == 8){
                Str.replace(i, 1, "\\b");
                i++;
                //continue;
            } else if(Str[i] == 9){
                Str.replace(i, 1, "\\t");
                i++;
                //continue;
            } else if(Str[i] == 10){
                Str.replace(i, 1, "\\n");
                i++;
                //continue;
            } else if(Str[i] == 12){
                Str.replace(i, 1, "\\f");
                i++;
                //continue;
            } else if(Str[i] == 13){
                Str.replace(i, 1, "\\c");
                i++;
                //continue;
            } else {
                Str.replace(i, 1, "\\u" + toUnicode((unsigned char)(Str[i])));
                i += 5;
                //std::cout << "i: " << i << std::endl;
                //continue;
            }
        } else if(uint16_t((uint8_t)Str[i]) > 127 && EscapeUnicode){
            size_t p = 0;
            while(uint16_t((uint8_t)Str[i+p]) > 127 && i+p < Str.size()){
                p++;
            }

            std::wstring mbstr = ffw::utf8ToWstr(Str.substr(i, p));
            //std::cout << "replacing: " << mstr[0] << std::endl;
            std::string unicodeStr;
            for(const auto& chr : mbstr){
                unicodeStr += "\\u" + toUnicode((uint16_t)chr);
            }
            Str.replace(i, p, unicodeStr);
            i+= unicodeStr.size();
            //continue;

        } else if(Str[i] == '\"'){
            Str.replace(i, 1, "\\\"");
            i++;
            //continue;
        } else if(Str[i] == '\\'){
            Str.replace(i, 1, "\\\\");
            i++;
            //continue;
        } else if(Str[i] == '/'){
            Str.replace(i, 1, "\\/");
            i++;
            //continue;
        }
        //i++;
        if(i >= Str.size()-1)break;
    }
    return Str;
}

///=============================================================================
static void encodeJSONFunc(std::ostream& output, const ffw::Var& var, bool Formated, std::string& Indent, bool EscapeUnicode){
	if (var.empty()) {
		output << "null";
	}
	else if(var.isString()){
		output << "\"" + escapeString(var.toString(), EscapeUnicode) + "\"";

	} else if(var.is<bool>()){
        if(var.getAs<bool>())output << "true";
        else output << "false";

	} else if(var.isInt()){
		output << ffw::valToString(var.toInt());

	} else if(var.isFloat()){
		output << ffw::valToString(var.toFloat());

    } else if(var.is<ffw::Array>()){
        if(Formated){
            output << "[\n";
            Indent += "    ";
        } else {
            output << "[";
        }

        for(size_t i = 0; i < var.getAs<ffw::Array>().size(); i++){
            if(Formated)output << Indent;
            encodeJSONFunc(output, (var.getAs<ffw::Array>()[i]), Formated, Indent, EscapeUnicode);
            if(Formated){
                if(i != var.getAs<ffw::Array>().size()-1)output << ",\n";
                else output << "\n";
            } else {
                if(i != var.getAs<ffw::Array>().size()-1)output << ",";
            }
        }
        if(Formated){
            Indent = Indent.substr(0, Indent.size()-4);
            output << Indent + "]";
        } else {
            output << "]";
        }

    } else if(var.is<ffw::Object>()){
        if(var.getAs<ffw::Object>().begin() == var.getAs<ffw::Object>().end()){
            output << "{}";
            return;
        }

        if(Formated){
            output << "{\n";
            Indent += "    ";
        } else {
            output << "{";
        }

        auto obj = var.getAs<ffw::Object>();
        size_t cnt = 0;
        for(auto it = obj.begin(); it != obj.end(); it++){
            if(Formated){
                output << Indent + "\"" + escapeString(it->first, EscapeUnicode) + "\":";
            } else {
                output << "\"" + escapeString(it->first, EscapeUnicode) + "\":";
            }

            encodeJSONFunc(output, it->second, Formated, Indent, EscapeUnicode);

            if(Formated){
                if(cnt != obj.size()-1)output << ",\n";
                else output << "\n";
            } else {
                if(cnt != obj.size()-1)output << ",";
            }

            cnt++;
        }

        if(Formated){
            Indent = Indent.substr(0, Indent.size()-4);
            output << Indent + "}";
        } else {
            output << "}";
        }
    }
}

///=============================================================================
static size_t findFirstInWhitespace(const std::string& Input, char What, size_t Begin, size_t End){
	for(size_t i = Begin; i < End; i++){
		if(Input[i] == 32 || Input[i] == 9 || Input[i] == 13 || Input[i] == 10)continue;
		else if(Input[i] == What){
			//std::cout << "found: " << int(Input[i]) << " at: " << i << std::endl;
			return i;
		} else {
			break;
		}
	}
	return std::string::npos;
}

///=============================================================================
static size_t findLastInWhitespace(const std::string& Input, char What, size_t Begin, size_t End){
	for(size_t i = End; i > Begin; i--){
		if(Input[i-1] == 32 || Input[i-1] == 9 || Input[i-1] == 13 || Input[i-1] == 10)continue;
		else if(Input[i-1] == What)return i;
		else break;
	}
	return std::string::npos;
}

///=============================================================================
static bool checkForString(const std::string& Input, size_t Begin, size_t End, size_t* BeginNew, size_t* EndNew){
	if(End == 0)return false;

	// Check starting quote
	size_t b = std::string::npos;
	for(size_t i = Begin; i < End; i++){
		if(Input[i] == ' ' || Input[i] == 9 || Input[i] == 10 || Input[i] == 13)continue;
		if(Input[i] == '\"'){
			b = i+1;
			break;
		}
		else return false;
	}

	// Check ending quote
	size_t e = std::string::npos;
	for(size_t i = End-1; i > Begin+1; i--){
		if(Input[i] == ' ' || Input[i] == 9 || Input[i] == 10 || Input[i] == 13)continue;
		if(Input[i] == '\"'){
			e = i;
			break;
		}
		else {
			return false;
		}
	}

	if(b == std::string::npos || e == std::string::npos)return false;

	if(BeginNew != NULL)*BeginNew = b;
	if(EndNew != NULL)*EndNew = e;

	return true;
}

///=============================================================================
static bool checkForBoolean(const std::string& str, size_t beg, size_t end, bool* value) {
	static std::smatch match;

	if(std::regex_match(str.begin() + beg, str.begin() + end, match, std::regex("^\\s*[Tt][Rr][Uu][Ee]\\s*$"))) {
		*value = true;
		return true;
	}

	if (std::regex_match(str.begin() + beg, str.begin() + end, match, std::regex("^\\s*[Ff][Aa][Ll][Ss][Ee]\\s*$"))) {
		*value = false;
		return true;
	}

	return false;
}

///=============================================================================
static bool checkForHex(const std::string& str, size_t beg, size_t end) {
	static std::smatch match;
	
	if (std::regex_match(str.begin() + beg, str.begin() + end, match, std::regex("^\\s*0[xX][0-9a-fA-F]+\\s*$"))) {
		return true;
	}

	return false;
}

///=============================================================================
static bool checkForFloat(const std::string& str, size_t beg, size_t end) {
	static std::smatch match;

	if (std::regex_match(str.begin() + beg, str.begin() + end, match, std::regex("^\\s*[-+]?[0-9]*\\.?[0-9]+([eE][-+]?[0-9]+)?\\s*$"))) {
		return true;
	}

	return false;
}

///=============================================================================
static bool checkForInt(const std::string& str, size_t beg, size_t end) {
	static std::smatch match;

	if (std::regex_match(str.begin() + beg, str.begin() + end, match, std::regex("^\\s*[-+]?\\d+\\s*$"))) {
		return true;
	}

	return false;
}

///=============================================================================
static bool checkForNull(const std::string& str, size_t beg, size_t end) {
	static std::smatch match;

	if (std::regex_match(str.begin() + beg, str.begin() + end, match, std::regex("^\\s*[Nn][Uu][Ll][Ll]\\s*$"))) {
		return true;
	}

	return false;
}

///=============================================================================
static void parseCommas(const std::string& Input, size_t Begin, size_t End, std::vector<std::pair<size_t, size_t> >& Sections){
	int isInside = 0;
	bool isString = false;
	size_t last = Begin;

	for(size_t i = Begin; i < End; i++){
		if(i == Begin && Input[i] == '\"')isString = true;
		else if(i > Begin && Input[i] == '\"' && Input[i-1] != '\\')isString = !isString;

		//std::cout << (isString ? "s" : "_");

		if(isString)continue;

		if(Input[i] == '{' || Input[i] == '[')isInside++;
		if(Input[i] == '}' || Input[i] == ']')isInside--;

		if(isInside != 0)continue;

		if(Input[i] == ','){
			Sections.push_back(std::make_pair(last, i));
			last = i+1;
			if(last > End)last = End;
		}
	}
	//std::cout << std::endl;
	Sections.push_back(std::make_pair(last, End));
}

///=============================================================================
static size_t getCollon(const std::string& Input, size_t Begin, size_t End){
	bool isString = false;

	for(size_t i = Begin; i < End; i++){
		if(i == Begin && Input[i] == '\"')isString = true;
		else if(i > Begin && Input[i] == '\"' && Input[i-1] != '\\')isString = !isString;

		if(isString)continue;

		if(Input[i] == ':')return i;
	}
	return std::string::npos;
}

///=============================================================================
static std::string getKey(const std::string& Input, size_t Begin, size_t Collon){
	size_t beg = std::string::npos;

	for(size_t i = Begin; i < Collon; i++){
		if(beg == std::string::npos){
			if(Input[i] == '\"')beg = i;
			continue;
		}

		if(Input[i] == '\"' && Input[i-1] != '\\'){
			return Input.substr(beg+1, i-beg-1);
		}
	}
	return "";
}

///=============================================================================
static void parseJsonRecursive(const std::string& Input, size_t Begin, size_t End, ffw::Var& Data){
	if(Begin >= End){
		return;
	}

	size_t begin = std::string::npos;
	size_t end = std::string::npos;

	bool isArray = false;
	size_t newBegin = 0;
	size_t newEnd = 0;
	bool boolValue = false;

	// Find begin
	if((begin = findFirstInWhitespace(Input, '{', Begin, End)) != std::string::npos &&
	   (end   = findLastInWhitespace(Input, '}', Begin, End)) != std::string::npos){
		// is object
		Data = ffw::Object();
	} else if((begin = findFirstInWhitespace(Input, '[', Begin, End)) != std::string::npos &&
	          (end   = findLastInWhitespace(Input, ']', Begin, End)) != std::string::npos){
		// is array
		isArray = true;
		Data = ffw::Array();
	// Check if string
	} else if(checkForString(Input, Begin, End, &newBegin, &newEnd)){
		Data = parseStringSimple(Input.substr(newBegin, newEnd-newBegin));
		return;

	}
	// Check if boolean
	else if (checkForBoolean(Input, Begin, End, &boolValue)) {
		Data = boolValue;
		return;


	} 
	// Check if hex
	else if(checkForHex(Input, Begin, End)) {
		Data = ffw::hexToVal<int>(Input.substr(Begin, End - Begin));
		return;
	}
	// Check if integer
	else if (checkForInt(Input, Begin, End)) {

		try {
			Data = ffw::stringToVal<int>(Input.substr(Begin, End - Begin));
		}
		catch (const std::exception& e) {
			Data = (int)0;
			(void)e;
		}
		return;
	}
	// Check if floating point
	else if (checkForFloat(Input, Begin, End)) {
		try {
			Data = ffw::stringToVal<float>(Input.substr(Begin, End - Begin));
		}
		catch (const std::exception& e) {
			Data = 0.0f;
			(void)e;
		}
		return;
	}
	else if(checkForNull(Input, Begin, End)){
		Data = nullptr;
		return;

	} else {
		return;
	}
	begin++;
	end--;

	if(begin >= end){
		return;
	}

	// Sections
	std::vector<std::pair<size_t, size_t> > sections;
	parseCommas(Input, begin, end, sections);

	// Parent is an array
	if(isArray){
		for(const auto& sec : sections){
			ffw::Var child;
			parseJsonRecursive(Input, sec.first, sec.second, child);
			if(!child.empty()) {
				Data.getAs<ffw::Array>().push_back(std::move(child));
			}
		}

	// Parent is a object
	} else {
		// for loop
		// get collon of each section
		// parse that section again without key
		for(const auto& sec : sections){
			//parseJsonRecursive(Input, sec.first, sec.second, false);
			// get collon
			size_t collon = getCollon(Input, sec.first, sec.second);
			if(collon == std::string::npos)continue;

			// get key
			std::string key = getKey(Input, sec.first, collon);
			if(key.size() == 0)continue;

			Data.getAs<ffw::Object>().insert(std::make_pair(key, ffw::Var()));
			auto& child = Data.getAs<ffw::Object>()[key];
			parseJsonRecursive(Input, collon+1, sec.second, child);
		}
	}
}

///=============================================================================
std::string ffw::encodeJson(const ffw::Var& input, bool formated, bool escape){
    std::stringstream stream;
	std::string indent;
    encodeJSONFunc(stream, input, formated, indent, escape);
	return stream.str();
}

///=============================================================================
void ffw::encodeJson(const ffw::Var& input, std::string& output, bool formated, bool escape){
	output = encodeJson(input, formated, escape);
}

///=============================================================================
ffw::Var ffw::decodeJson(const std::string& input){
    if(input.size() == 0)return false;

	ffw::Var var;
	parseJsonRecursive(input, 0, input.size(), var);

    return var;
}

///=============================================================================
void ffw::decodeJson(const std::string& input, ffw::Var& output){
	output = ffw::decodeJson(input);
}

///=============================================================================
bool ffw::loadJson(const std::string& Path, ffw::Var& output){
	output = ffw::Var();

    std::string buffer;
    if(!::loadTxt(Path, &buffer)){
        return false;
    }

    output = decodeJson(buffer);
	return true;
}

///=============================================================================
bool ffw::saveJson(const std::string& Path, const ffw::Var& input, bool formated, bool escape){
    std::fstream output(Path, std::ios::trunc | std::ios::out);
    if(!output){
        return false;
    }

	std::string indent;
    encodeJSONFunc(output, input, formated, indent, escape);

    //std::string encoded = encodeJson(input, formated, escape);

    //output.write(&encoded[0], encoded.size());
    output.close();
    return true;
}