/*** This file is part of FineFramework project ***/

#include "ffw/data/jsonfile.h"
#include <fstream>

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
    /*if(varType == typeid(std::string)){
        (*Output) += "\"" + escapeString(var.getAs<std::string>(), EscapeUnicode) + "\"";

    } else if(varType == typeid(int)){
        (*Output) += ffw::valToString(var.getAs<int>());

    } else if(varType == typeid(float)){
        (*Output) += ffw::valToString(var.getAs<float>());*/
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
static bool findInStringIgnoreWhite(const std::string& Input, const std::string& What, bool CaseSensitive, size_t Begin, size_t End){
	if(What.size() == 0)return false;
	bool gotWord = false;

	//std::cout << "find in: " << Input.substr(Begin, End-Begin) << std::endl;
	//std::cout << "case: " << CaseSensitive << std::endl;

	for(size_t i = Begin; i < End; i++){
		if(Input[i] == 32 || Input[i] == 9 || Input[i] == 13 || Input[i] == 10)continue;

		//std::cout << "testing: " << Input[i] << " / " << int(Input[i]) << std::endl;
		if(!gotWord && CaseSensitive && Input[i] == What[0] && i <= End-What.size()){
			for(size_t t = 1; t < What.size(); t++){
				if(Input[i+t] != What[t]){
					//std::cout << "incorrect: " << Input[i+t] << " vs " << What[t] << std::endl;
					return false;
				}
			}

			//std::cout << "got word" << std::endl;
			gotWord = true;
			i += What.size()-1;
			continue;
		}

		//std::cout << "Input: " << (char)tolower(Input[i]) << " what: " << (char)tolower(What[0]) << std::endl;
		//std::cout << "i: " << i << " end: " << End << " size: " << What.size() << std::endl;
		if(!gotWord && !CaseSensitive && tolower(Input[i]) == tolower(What[0]) && i <= End-What.size()){
			for(size_t t = 1; t < What.size(); t++){
				if(tolower(Input[i+t]) != tolower(What[t])){
					//std::cout << "incorrect: " << Input[i+t] << " vs " << What[t] << std::endl;
					return false;
				}
			}

			//std::cout << "got word" << std::endl;
			gotWord = true;
			i += What.size()-1;
			continue;
		}

		//std::cout << "unexpected: " << int(Input[i]) << std::endl;
		return false;
	}
	return true;
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
static bool isString(const std::string& Input, size_t Begin, size_t End, size_t* BeginNew, size_t* EndNew){
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
static bool isBoolean(const std::string& Input, size_t Begin, size_t End, bool* BoolValue){
	if(findInStringIgnoreWhite(Input, "true", false, Begin, End)){
		if(BoolValue != NULL)*BoolValue = true;
		return true;

	} else if(findInStringIgnoreWhite(Input, "false", false, Begin, End)){
		if(BoolValue != NULL)*BoolValue = false;
		return true;
	}
	return false;
}

///=============================================================================
static bool isNull(const std::string& Input, size_t Begin, size_t End){
	return findInStringIgnoreWhite(Input, "null", false, Begin, End);
}

///=============================================================================
static bool isDecimal(const std::string& Input, size_t Begin, size_t End, size_t* BeginNew, size_t* EndNew){
	size_t numberBegin = std::string::npos;
	bool isHex = false;
	bool gotDot = false;

	for(size_t i = Begin; i < End; i++){
		if(Input[i] == ' ' || Input[i] == 9 || Input[i] == 10 || Input[i] == 13)continue;
		// Numbers starting with hex prefix "0x"
		if(i < End-1 && Input[i] == '0' && (Input[i+1] == 'x' || Input[i+1] == 'X')){
			numberBegin = i+2;
			isHex = true;
			if(BeginNew != NULL)*BeginNew = i;
			break;
		}
		// Numbers starting with a decimal
		if(Input[i] >= '0' && Input[i] <= '9'){
			numberBegin = i;
			if(BeginNew != NULL)*BeginNew = i;
			break;
		}
		// Numbers starting with a dot
		if(i < End-1 && Input[i] == '.' && Input[i+1] >= '0' && Input[i+1] <= '9'){
			numberBegin = i;
			gotDot = true;
			if(BeginNew != NULL)*BeginNew = i;
			break;
		}
	}

	if(numberBegin == std::string::npos)return false;
	bool isEnd = false;

	//std::cout << "got number! isHex: " << isHex << std::endl;
	if(EndNew != NULL)*EndNew = End;

	if(isHex){
		for(size_t i = numberBegin; i < End; i++){
			if(Input[i] == ' ' || Input[i] == 9 || Input[i] == 10 || Input[i] == 13){
				if(isEnd)continue;
				if(EndNew != NULL)*EndNew = i;
				isEnd = true;

			} else if((Input[i] >= '0' && Input[i] <= '9') ||
								(Input[i] >= 'a' && Input[i] <= 'f') ||
								(Input[i] >= 'A' && Input[i] <= 'F')){
				if(isEnd){
					//std::cout << "unexpected token because it is an end! " << Input[i] << std::endl;
					return false;
				}
			} else {
				//std::cout << "unexpected token " << Input[i] << std::endl;
				return false;
			}
		}
	} else {
		for(size_t i = numberBegin; i < End; i++){
			if(Input[i] == ' ' || Input[i] == 9 || Input[i] == 10 || Input[i] == 13){
				if(isEnd)continue;
				if(EndNew != NULL)*EndNew = i;
				isEnd = true;

			} else if(Input[i] >= '0' && Input[i] <= '9'){
				if(isEnd)return false;

			// Check for multiple dots
			} else if(Input[i] == '.'){
				if(isEnd)return false;
				if(i != numberBegin){
					if(!gotDot)gotDot = true;
					else return false;
				}
			} else if(Input[i] == 'f' || Input[i] == 'F' || Input[i] == 'd' || Input[i] == 'D' || Input[i] == 'l' || Input[i] == 'L'){
				if(isEnd)return false;
				if(EndNew != NULL)*EndNew = i+1;
				isEnd = true;
			}

		}
	}
	return true;
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
		//////std::cout << "begin & end error" << std::endl;
		return;
	}

	//std::cout << "Parsing:" << std::endl;
	//std::cout << ">" << Input.substr(Begin, End-Begin) << "<" << std::endl;
	//std::cout << "previous: " << Data.typeid() << std::endl;

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
		//////std::cout << "is object!" << std::endl;
		Data = ffw::Object();
	} else if((begin = findFirstInWhitespace(Input, '[', Begin, End)) != std::string::npos &&
	          (end   = findLastInWhitespace(Input, ']', Begin, End)) != std::string::npos){
		// is array
		//////std::cout << "is array!" << std::endl;
		isArray = true;
		Data = ffw::Array();
	// Check if string
	} else if(isString(Input, Begin, End, &newBegin, &newEnd)){
		//////std::cout << "is string! \"" << Input.substr(newBegin, newEnd-newBegin) << "\"" << std::endl;
		//std::cout << "\"" << Input.substr(newBegin, newEnd-newBegin) << "\"";
		Data = parseStringSimple(Input.substr(newBegin, newEnd-newBegin));
		return;

	// Check if boolean
	} else if(isBoolean(Input, Begin, End, &boolValue)){
		//////std::cout << "is bool! " << (boolValue ? "true" : "false") << std::endl;
		//std::cout << (boolValue ? "true" : "false");
		Data = boolValue;
		return;

	// Check if decimal
	} else if(isDecimal(Input, Begin, End, &newBegin, &newEnd)){

		// Hex number?
		if((newEnd - newBegin > 1 && Input[newBegin] == '0' && Input[newBegin+1] == 'x') ||
			 (newEnd - newBegin > 1 && Input[newBegin] == '0' && Input[newBegin+1] == 'X') ||
			 (newEnd - newBegin > 0 && Input[newBegin] == 'X')){
			//////std::cout << "is hex value! \"" << Input.substr(newBegin, newEnd-newBegin) << "\"" << std::endl;
			//std::cout << Input.substr(newBegin, newEnd-newBegin);
			Data = ffw::hexToVal<int>(Input.substr(newBegin, newEnd-newBegin));
			return;
		}

		// Integer or float?
		bool isFloat = false;
		for(size_t i = newBegin; i < newEnd; i++){
			if(Input[i] == '.'){
				isFloat = true;
				break;
			}
		}

		if(isFloat){
			//////std::cout << "is float value! \"" << Input.substr(newBegin, newEnd-newBegin) << "\"" << std::endl;
			//std::cout << Input.substr(newBegin, newEnd-newBegin);
			try {
				Data = ffw::stringToVal<float>(Input.substr(newBegin, newEnd-newBegin));
			} catch(const std::exception& e){
				(void)e;
			}
			return;

		} else {
			//////std::cout << "is integer value! \"" << Input.substr(newBegin, newEnd-newBegin) << "\"" << std::endl;
			//std::cout << Input.substr(newBegin, newEnd-newBegin);
			try {
				Data = ffw::stringToVal<int>(Input.substr(newBegin, newEnd-newBegin));
			} catch(const std::exception& e){
				(void)e;
			}
			return;
		}

	} else if(isNull(Input, Begin, End)){
		//////std::cout << "is null!" << std::endl;
		Data = nullptr;
		//std::cout << "null";
		return;


	} else {
		//std::cout << "begin: " << begin << std::endl;
		//std::cout << "end: " << end << std::endl;
		//////std::cout << "is unknown!" << std::endl;
		Data = nullptr;
		//std::cout << "error";
		return;
	}
	begin++;
	end--;

	if(begin >= end){
		//////std::cout << "begin & end error" << std::endl;
		return;
	}

	// Sections
	std::vector<std::pair<size_t, size_t> > sections;
	parseCommas(Input, begin, end, sections);

	///std::cout << std::endl;

	//for(const auto& sec : sections){
		//////std::cout << "first: " << sec.first << " second: " << sec.second << std::endl;
		//////std::cout << "str: " << Input.substr(sec.first, sec.second - sec.first) << std::endl;
	//}
	////////std::cout << std::endl;

	// Parent is an array
	if(isArray){

		//std::cout << "parent is array: " << (Data.typeid() == typeid(ffw::Array)) << std::endl;

		//std::cout << "[" << std::endl;
		for(const auto& sec : sections){

			Data.getAs<ffw::Array>().push_back(ffw::Var());
			auto& child = Data.getAs<ffw::Array>().back();

			parseJsonRecursive(Input, sec.first, sec.second, child);
			//std::cout << ",";
		}
		//std::cout << std::endl << "]" << std::endl;

	// Parent is a object
	} else {

		//std::cout << "parent is object: " << (Data.typeid() == typeid(ffw::Object)) << std::endl;

		// for loop
		// get collon of each section
		// parse that section again without key
		//std::cout << "{" << std::endl;
		for(const auto& sec : sections){
			//parseJsonRecursive(Input, sec.first, sec.second, false);
			// get collon
			size_t collon = getCollon(Input, sec.first, sec.second);
			if(collon == std::string::npos)continue;

			// get key
			std::string key = getKey(Input, sec.first, collon);
			if(key.size() == 0)continue;

			//////std::cout << "got key: " << key << std::endl;
			//std::cout << "\"" << key << "\": ";

			Data.getAs<ffw::Object>().insert(std::make_pair(key, ffw::Var()));
			auto& child = Data.getAs<ffw::Object>()[key];

			parseJsonRecursive(Input, collon+1, sec.second, child);
			//std::cout << ", ";
		}
		//std::cout << std::endl << "}" << std::endl;
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
