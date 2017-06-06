/*** This file is part of FineFramework project ***/

#include "ffw/data/jsonreader.h"
#include "ffw/math/stringmath.h"
#include <fstream>
#include <regex>
#include <sstream>
#include <iostream>

///=============================================================================
static std::string parseUnicodeHex(const char* str) {
	int val = 0;
	std::string out;
	out.reserve(4);

	for (int i = 0; i < 4; i++) {
		if (str[i] >= 'a' && str[i] <= 'f') {
			val |= ((str[i] - 'a' + 10) << (4 * (3 - i)));
		}
		else if (str[i] >= 'A' && str[i] <= 'F') {
			val |= ((str[i] - 'A' + 10) << (4 * (3 - i)));
		}
		else if (str[i] >= '0' && str[i] <= '9') {
			val |= ((str[i] - '0') << (4 * (3 - i)));
		}
		else {
			throw ffw::JsonDecodeException("Unexpected character: \'" + std::string(str, 4) + " in hex sequence!");
		}
	}

	//std::cout << "converted " << str[0] << str[1] << str[2] << str[3] << " into " << val << std::endl;

	if (val <= 0x007F) {
		out.push_back(val & 0x7F);
	}
	else if (val <= 0x7FF) {
		out.push_back(0xC0 | char((val & 0x0FC0) >> 6));
		out.push_back(0x80 | char((val & 0x003F)));
	}
	else if (val <= 0xFFFF) {
		out.push_back(0xE0 | char((val & 0xF000) >> 12));
		out.push_back(0x80 | char((val & 0x0FC0) >> 6));
		out.push_back(0x80 | char((val & 0x003F)));
	}
	else {
		out.push_back(0xF0 | char((val & 0x1C0000) >> 18));
		out.push_back(0x80 | char((val & 0x03F000) >> 12));
		out.push_back(0x80 | char((val & 0x000FC0) >> 6));
		out.push_back(0x80 | char((val & 0x00003F)));
	}

	return out;
}

///=============================================================================
static std::string parseString(const char* str, size_t len) {
	std::string out;

	// The output string will never be longer than the input length,
	// unless unicode conversion will happen.
	// In the best case (no conversion) no memory allocation will be made beyond this point.
	out.reserve(len);

	for (size_t i = 0; i < len; i++) {
		switch (str[i]) {
			// Escape string
			case '\\': {
				if (i + 1 < len) {
					// Specific character
					switch (str[i+1]) {
						case '\\': {
							out.push_back('\\'); break;
						}
						case '/': {
							out.push_back('/'); break;
						}
						case 'b': {
							out.push_back('\b'); break;
						}
						case 'f': {
							out.push_back('\f'); break;
						}
						case 'n': {
							out.push_back('\n'); break;
						}
						case 'r': {
							out.push_back('\r'); break;
						}
						case 't': {
							out.push_back('\t'); break;
						}
						case 'v': {
							out.push_back('\v'); break;
						}
						case '\'': {
							out.push_back('\''); break;
						}
						case '\"': {
							out.push_back('\"'); break;
						}
						case '\0': {
							out.push_back('\0'); break;
						}
						case 'u': {
							//out.push_back('\u'); break;
							if (i + 1 + 4 < len) {
								out.append(parseUnicodeHex(&str[i+2]));
								i += 4;
							}
							break;
						}
						default: {
							throw ffw::JsonDecodeException("Unexpected control/reserved character: \'" + std::string(&str[i], 2) + "\'");
						}
					}
					i++;
				}
				break;
			}
			default:
				out.push_back(str[i]);
		}
	}

	return out;
}

///=============================================================================
ffw::JsonReader::Type ffw::JsonReader::Node::getType() const {
	if (isEmpty())return Type::EMPTY;
	if (isObject())return Type::OBJECT;
	if (isArray())return Type::ARRAY;
	if (isString())return Type::STRING;
	if (isInteger())return Type::INTEGER;
	if (isFloat())return Type::FLOAT;
	if (isBoolean())return Type::BOOLEAN;
	if (isNull())return Type::NULLVAL;
	return Type::INVALID;
}

///=============================================================================
bool ffw::JsonReader::Node::isNull() const {
	return std::regex_match(raw(), std::regex("^(null)$"));
}

///=============================================================================
bool ffw::JsonReader::Node::isNumber() const {
	return std::regex_match(raw(), std::regex("^[-+]?(?:0|[1-9]\\d*)(?:\\.\\d+)?(?:[eE][+-]?\\d+)?$"));
}

///=============================================================================
bool ffw::JsonReader::Node::isInteger() const {
	return std::regex_match(raw(), std::regex("^[-+]?\\d+([Ee][+-]?\\d+)?$"));
}

///=============================================================================
bool ffw::JsonReader::Node::isFloat() const {
	return std::regex_match(raw(), std::regex("^[-+]?\\d*\\.{1}\\d+([Ee][+-]?\\d+)?$"));
}

///=============================================================================
bool ffw::JsonReader::Node::isBoolean() const {
	return std::regex_match(raw(), std::regex("^(true|false)$"));
}

///=============================================================================
std::string ffw::JsonReader::Node::toString() const {
	if (isEmpty()) throw JsonDecodeException("Failed to convert to a string! Node is empty!");

	if (ptr[0] == '\"' && ptr[len - 1] == '\"' && len >= 2) {
		return parseString(ptr + 1, len - 2);
	}
	else {
		throw JsonDecodeException("Failed to convert: \'" + std::string(ptr + 1, len -2) + "\' to a string!");
	}
}

///=============================================================================
int ffw::JsonReader::Node::toInteger() const {
	if (isEmpty())throw JsonDecodeException("Failed to convert to integer! Node is empty!");
	auto s = str();
	try {
		return ffw::stringToVal<int>(s);
	}
	catch (std::exception& e) {
		(void)e;
		throw JsonDecodeException("Failed to convert: \'" + s + "\' to inetegr!");
	}
}

///=============================================================================
float ffw::JsonReader::Node::toFloat() const {
	if (isEmpty())throw JsonDecodeException("Failed to convert to float! Node is empty!");
	auto s = str();
	try {
		return ffw::stringToVal<float>(s);
	}
	catch (std::exception& e) {
		(void)e;
		throw JsonDecodeException("Failed to convert: \'" + s + "\' to float!");
	}
}

///=============================================================================
double ffw::JsonReader::Node::toDouble() const {
	if (isEmpty())throw JsonDecodeException("Failed to convert to float! Node is empty!");
	auto s = str();
	try {
		return ffw::stringToVal<double>(s);
	}
	catch (std::exception& e) {
		(void)e;
		throw JsonDecodeException("Failed to convert: \'" + s + "\' to double!");
	}
}

///=============================================================================
bool ffw::JsonReader::Node::toBoolean() const {
	if (isEmpty())throw JsonDecodeException("Failed to convert to bool! Node is empty!");
	if (len == 4 && ptr[0] == 't' && ptr[1] == 'r' && ptr[2] == 'u' && ptr[3] == 'e')return true;
	if (len == 5 && ptr[0] == 'f' && ptr[1] == 'a' && ptr[2] == 'l' && ptr[3] == 's' && ptr[4] == 'e')return false;
	throw JsonDecodeException("Failed to convert: \'" + str() + "\' to bool!");
}

static std::string nOrLess(const char* str, size_t n) {
	std::string out;
	out.resize(n);
	for (size_t i = 0; i < n; i++) {
		if (str[i] == '\0') {
			out.resize(i);
		}
		out[i] = str[i];
	}
	return out;
}

///=============================================================================
ffw::JsonReader::JsonReader(const std::string& in):str(in.c_str()) {
	len = std::string::npos;
	current = Type::EMPTY;
}

///=============================================================================
ffw::JsonReader::JsonReader(const char* in):str(in) {
	len = SIZE_MAX;
	current = Type::EMPTY;
}

///=============================================================================
ffw::JsonReader::~JsonReader() {

}

///=============================================================================
bool ffw::JsonReader::checkCurrent(const char* start, const char* end, Node* node) {
	//std::cout << "checkCurrent start: " << (void*)start << " end: " << (void*)end << std::endl;
	if (start > end)return false;

	if (end != NULL) {
		//if (end == start)return false;

		//std::cout << "token preprocess: \"" << std::string(start, end - start + 1) << "\"" << std::endl;

		//std::cout << "checkCurrent start: " << (void*)start << " end: " << (void*)end << std::endl;

		// Fix starting whitespace
		while (start != end) {
			if (*start != ' ' && *start != '\n' && *start != '\r' && *start != '\t' && *start != '\f' && *start != 'v') {
				break;
			}
			start++;
		}

		while (end >= start) {
			if (*end != ' ' && *end != '\n' && *end != '\r' && *end != '\t' && *end != '\f' && *end != 'v') {
				break;
			}
			end--;
		}

		//std::cout << "checking token: " << std::string(start, end - start + 1) << std::endl;

		// Check if there is anything remaining...
		if (start > end) {
			return false;
		}

		//std::cout << "token: " << std::string(start, end - start + 1) << std::endl;

		if (current == Type::EMPTY) {
			if (*end == '}') {
				current = Type::OBJECT;
			}
			else if (*end == ']') {
				current = Type::ARRAY;
			}
			else {
				return false;
			}
		}
		if (node != NULL) {
			node->ptr = start;
			node->len = end - start +1;
		}
		return true;
	}
	return false;
}

///=============================================================================
bool ffw::JsonReader::getNext(Node* value, Node* key) {
	int innerObj = 0;
	int innerArr = 0;
	bool innerStr = false;
	const char* start = str;
	const char* end = NULL;
	Node left;

	//std::cout << "getNext>>>" << std::endl;

	while (true) {
		//std::cout << "getNext loop, str: " << *str << " innerStr: " << innerStr << " len: " << len << " start: " << (int)start << std::endl;

		if (len == 0) {
			//std::cout << "End of line! end: " << (void*)end << std::endl;
			if (end == NULL) {
				end = str - 1;
			}
			return checkCurrent(start, end, value);
		}
		char c = *str++;
		len--;

		switch (c) {
			case '\"': {
				innerStr = !innerStr;
				break;
			}
			case '\\': {
				if (!innerStr) {
					throw JsonDecodeException("Unpexpected backslash outside of string at: " + nOrLess(str-1, 10));
				}
				str++;
				len--;
				break;
			}
			case ':': {
				if (innerStr) break;
				//std::cout << "Found key! Processing..." << std::endl;
				if (innerObj == 0 && innerArr == 0) {
					if (current != Type::OBJECT) {
						//std::cout << "Key found in non object data!" << std::endl;
						len = 0;
						throw JsonDecodeException("Key found in non-object value: " + nOrLess(str-1, 10));
					}

					// Got key!
					if (!checkCurrent(start, str - 2, &left)) {
						//std::cout << "Failed to get key!" << std::endl;
						len = 0;
						throw JsonDecodeException("Failed to extract key from: \'" + std::string(start, str - 2 - start));
					}
					else {
						if (!left.isString()) {
							//std::cout << "Key is not a string!" << std::endl;
							len = 0;
							throw JsonDecodeException("Key: \'" + left.str() + "\' is not a string!");
						}
						//std::cout << "got key: " << left.str() << std::endl;
						if (key != NULL)*key = left;
					}
					start = str;
				}
				break;
			}
			case '\0': {
				if (innerStr)break;

				return checkCurrent(start, end, value);
			}
			case '{': {
				if (innerStr)break;
				if (innerObj == 0 && innerArr == 0) {
					start = str - 1;
				}
				innerObj++;
				break;
			}
			case '}': {
				if (innerStr)break;
				innerObj--;
				if (innerObj == 0 && innerArr == 0) {
					// Already found braces?
					if (end != NULL) {
						len = 0;
						throw JsonDecodeException("Unpexpected curly braces! Missing a comma? At: " + nOrLess(str-1, 10));
					}
					end = str - 1;
				}
				break;
			}
			case '[': {
				if (innerStr)break;
				if (innerObj == 0 && innerArr == 0) {
					start = str - 1;
				}
				innerArr++;
				break;
			}
			case ']': {
				if (innerStr)break;
				innerArr--;
				if (innerObj == 0 && innerArr == 0) {
					// Already found braces?
					if (end != NULL) {
						len = 0;
						throw JsonDecodeException("Unpexpected braces! Missing a comma? At: " + nOrLess(str-1, 10));
					}
					end = str - 1;
				}
				break;
			}
			case ',': {
				if (innerStr) break;
				//std::cout << "got comma!" << std::endl;
				if (innerObj == 0 && innerArr == 0) {
					if (end == NULL) {
						end = str - 2;
						
					}
					if (checkCurrent(start, end, value)) {
						return true;
					}
				}
			}

			default: break;
		}
	}

	return false;
}

///=============================================================================
bool ffw::JsonReader::stepInto(const Node* node) {
	if (node != NULL && node->ptr != NULL && node->len > 0) {
		if (*node->ptr == '{' && node->ptr[node->len - 1] == '}') {
			cache.push_back(Cache{current, str, len});
			current = Type::OBJECT;
			str = node->ptr +1;
			len = node->len -2;
			return true;
		}
		else if (*node->ptr == '[' && node->ptr[node->len - 1] == ']') {
			cache.push_back(Cache{current, str, len});
			current = Type::ARRAY;
			str = node->ptr +1;
			len = node->len -2;
			return true;
		}
		else {
			throw JsonDecodeException("Cannot step into a node! Expected array or object! At: " + nOrLess(node->ptr, 10));
		}
	}
	return false;
}

bool ffw::JsonReader::stepOut() {
	if (cache.size() > 0) {
		current = cache.back().current;
		str = cache.back().str;
		len = cache.back().len;
		cache.pop_back();
		return true;
	}
	return false;
}

static ffw::Var decodeJsonObject(ffw::JsonReader& json);

///=============================================================================
static ffw::Var decodeJsonValue(ffw::JsonReader& json, ffw::JsonReader::Node& node) {
	if (node.isEmpty())return ffw::Var();
	if (node.isString())return ffw::Var(node.toString());
	if (node.isNumber()) {
		for (size_t i = 0; i < node.len; i++) {
			if (node.ptr[i] == '.') {
				return ffw::Var(node.toFloat());
			}
		}
		return ffw::Var(node.toInteger());
	}
	if (node.isBoolean()) return ffw::Var(node.toBoolean());
	if (node.isNull())return ffw::Var(nullptr);

	if (node.isObject()) {
		if (json.stepInto(&node)) {
			auto ret = decodeJsonObject(json);
			json.stepOut();
			return ret;
		}
		else {
			throw ffw::JsonDecodeException("Could not parse JSON object! At: " + nOrLess(node.ptr, 10));
		}
	}
	
	if (node.isArray()) {
		if (json.stepInto(&node)) {
			auto ret = decodeJsonObject(json);
			json.stepOut();
			return ret;
		}
		else {
			throw ffw::JsonDecodeException("Could not parse JSON array! At: " + nOrLess(node.ptr, 10));
		}
	}

	throw ffw::JsonDecodeException("Could not detect value type! At: " + nOrLess(node.ptr, 10));
}

///=============================================================================
static ffw::Var decodeJsonObject(ffw::JsonReader& json) {
	if (json.getCurrentType() == ffw::JsonReader::Type::OBJECT) {
		ffw::Object obj;
		ffw::JsonReader::Node value, key;

		while (json.getNext(&value, &key)) {
			obj.insert(std::make_pair(key.toString(), decodeJsonValue(json, value)));
		}

		return obj;
	}

	if (json.getCurrentType() == ffw::JsonReader::Type::ARRAY) {
		ffw::Array arr;
		ffw::JsonReader::Node value;

		while (json.getNext(&value, NULL)) {
			arr.push_back(decodeJsonValue(json, value));
		}

		return arr;
	}

	throw ffw::JsonDecodeException("Expected JSON object or array! At:" + nOrLess(json.getCurrentPtr(), 10));
}

///=============================================================================
ffw::Var ffw::decodeJson(const char* input) {
	ffw::JsonReader json(input);

	ffw::JsonReader::Node node;
	if(json.getNext(&node, NULL)) {
		if (node.isObject() || node.isArray()) {
			if (json.stepInto(&node)) {
				return decodeJsonObject(json);
			}
			else {
				// Parser error
				throw JsonDecodeException("Could not parse first JSON object! At: " + nOrLess(node.ptr, 10));
			}
		}
		else {
			// Not object!
			throw JsonDecodeException("Could not parse first JSON object! Not an object nor an array! At: " + nOrLess(node.ptr, 10));
		}
	}

	// Decode error or empty string!
	throw JsonDecodeException("Could not parse first JSON object! Syntax error or string is empty! At: " + nOrLess(&input[0], 10));
}

///=============================================================================
ffw::Var ffw::decodeJson(const std::string& input) {
	return decodeJson(input.c_str());
}

///=============================================================================
ffw::Var ffw::decodeJsonFile(const std::string& path) {
	std::ifstream input(path, std::ios::in | std::ios::binary);
	if (!input) {
		throw ffw::JsonEncodeException("Could not open file!");
	}

	std::string str;
	input.seekg(0, std::ios::end);
	str.reserve(static_cast<size_t>(input.tellg()));
	input.seekg(0, std::ios::beg);
	str.assign((std::istreambuf_iterator<char>(input)), std::istreambuf_iterator<char>());
	input.close();

	return decodeJson(str.c_str());
}