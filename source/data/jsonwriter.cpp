/*** This file is part of FineFramework project ***/

#include "ffw/data/jsonwriter.h"
#include "ffw/math/stringmath.h"
#include <fstream>
#include <regex>
#include <sstream>
#include <iostream>

///=============================================================================
ffw::JsonWriter::JsonWriter(Stream* ss, const char* ind, bool esc):stream(ss),indent(ind),escape(esc) {
	count = 0;
}

///=============================================================================
ffw::JsonWriter::~JsonWriter() {

}

static const char hexes[16] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'a', 'b', 'c', 'd', 'e', 'f'};

///=============================================================================
static std::string encodeString(const char* val, bool utf8) {
	size_t total = 0;
	auto cpy = val;

	while (*cpy) {
		char c = *cpy++;

		if (utf8 && c & 0x80) {
			if ((c & 0xC0) == 0xC0) {
				// four byte sequence
				total += 6;
			}
			else if ((c & 0xE0) == 0xE0) {
				// three byte sequence
				total += 6;
			}
			else if ((c & 0xF0) == 0xF0) {
				// two byte sequence
				total += 6;
			}
			else {
				// Sequence
				//total++;
			}
		}
		else {
			switch (c) {
			case '\\':
			case '/':
			case '\"':
			case '\'':
			case '\n':
			case '\t':
			case '\v':
			case '\f':
			case '\r':
			case '\b':
			case '\0':
				total += 2;
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
						out.push_back('\\');
						out.push_back('u');
						out.push_back(hexes[(value & 0xF000) >> 12]);
						out.push_back(hexes[(value & 0x0F00) >> 8]);
						out.push_back(hexes[(value & 0x00F0) >> 4]);
						out.push_back(hexes[(value & 0x000F)]);
					}
				}
			}
		}
		else {
			switch (c) {
				case '\\':
				case '/':
				case '\"':
				case '\'':
					out.push_back('\\');
					out.push_back(c);
					break;
				case '\n':
					out.push_back('\\');
					out.push_back('n');
					break;
				case '\t':
					out.push_back('\\');
					out.push_back('t');
					break;
				case '\v':
					out.push_back('\\');
					out.push_back('v');
					break;
				case '\f':
					out.push_back('\\');
					out.push_back('f');
					break;
				case '\r':
					out.push_back('\\');
					out.push_back('r');
					break;
				case '\b':
					out.push_back('\\');
					out.push_back('b');
					break;
				case '\0':
					out.push_back('\\');
					out.push_back('0');
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
void ffw::JsonWriter::addObject(const char* key) {
	// Should add new object as a key-value pair?
	if (braces.size() > 0 && braces.back()) {
		if (key == NULL) {
			throw JsonEncodeException("Could not add object! Key value is NULL!");
		}

		if (count) {
			write(",", 1);
		}

		if (indent) {
			if(count)write("\n", 1);
			writeIndent();
		}

		write("\"", 1);
		write(key, 0);

		if (indent) {
			write("\":{\n", 4);
		}
		else {
			write("\":{", 3);
		}
	}
	// Add as simple value
	else {
		if (count) {
			if (indent) {
				write(",\n", 2);
			}
			else {
				write(",", 1);
			}
		}

		if (indent) {
			//write("\n", 1);
			writeIndent();
			write("{\n", 2);
		}
		else {
			write("{", 1);
		}
	}
	braces.push_back(true);
	count = 0;
}

///=============================================================================
void ffw::JsonWriter::addArray(const char* key) {
	// Should add new object as a key-value pair?
	if (braces.size() > 0 && braces.back()) {
		if (key == NULL) {
			throw JsonEncodeException("Could not add array! Key value is NULL!");
		}

		if (count) {
			write(",", 1);
		}

		if (indent) {
			if(count)write("\n", 1);
			writeIndent();
		}

		write("\"", 1);
		write(key, 0);

		if (indent) {
			write("\":[\n", 4);
		}
		else {
			write("\":[", 3);
		}
	}
	// Add as simple value
	else {
		if (count) {
			if (indent) {
				write(",\n", 2);
			}
			else {
				write(",", 1);
			}
		}

		if (indent) {
			write("\n", 1);
			writeIndent();
			write("[\n", 2);
		}
		else {
			write("[", 1);
		}
	}
	braces.push_back(false);
	count = 0;
}

///=============================================================================
void ffw::JsonWriter::writeIndent() {
	for (size_t i = 0; i < braces.size(); i++) {
		if (!stream->write(indent, 0)) {
			throw JsonEncodeException("Failed to write to the stream!");
		}
	}
}

///=============================================================================
inline void ffw::JsonWriter::write(const char* str, size_t len) {
	if (!stream->write(str, len)) {
		throw JsonEncodeException("Failed to write to the stream!");
	}
}

///=============================================================================
void ffw::JsonWriter::stepOut() {
	if (braces.size() > 0) {
		bool cpy = braces.back();
		braces.pop_back();

		if (indent) {
			write("\n", 1);
			writeIndent();
		}

		if (cpy) {
			write("}", 1);
		}
		else {
			write("]", 1);
		}

		count = 1;
	}
	else {
		throw JsonEncodeException("Can not step out! Already at the root level!");
	}
}

///=============================================================================
void ffw::JsonWriter::addBegin(const char* key) {
	if (braces.back()) {
		if (key == NULL) {
			throw JsonEncodeException("Could not add string! Key value is NULL!");
		}

		if (count) {
			if (indent) {
				write(",\n", 2);
			}
			else {
				write(",", 1);
			}
		}

		if(indent)
			writeIndent();

		write("\"", 1);
		write(key, 0);

		if (indent) {
			write("\":", 2);
		}
		else {
			write("\":", 2);
		}
	}
	// Add as simple value
	else {
		if (count) {
			if (indent) {
				write(",\n", 2);
			}
			else {
				write(",", 1);
			}
		}

		if(indent)
			writeIndent();

		// Do nothing
	}
}

///=============================================================================
void ffw::JsonWriter::addEnd() {
	count++;
}

///=============================================================================
void ffw::JsonWriter::addInteger(int val, const char* key) {
	addBegin(key);

	auto str = std::to_string(val);
	write(str.c_str(), str.size());

	addEnd();
}

///=============================================================================
void ffw::JsonWriter::addFloat(float val, const char* key) {
	addBegin(key);

	auto str = std::to_string(val);
	write(str.c_str(), str.size());

	addEnd();
}

///=============================================================================
void ffw::JsonWriter::addBoolean(bool val, const char* key) {
	addBegin(key);

	if (val) {
		write("true", 4);
	}
	else {
		write("false", 5);
	}

	addEnd();
}

///=============================================================================
void ffw::JsonWriter::addNull(const char* key) {
	addBegin(key);
	write("null", 4);
	addEnd();
}

///=============================================================================
void ffw::JsonWriter::addString(const char* val, const char* key) {
	addBegin(key);

	write("\"", 1);
	const auto str = encodeString(val, escape);
	write(str.c_str(), str.size());
	write("\"", 1);

	addEnd();
}

///=============================================================================
ffw::JsonWriter::StringStream::StringStream() {

}
ffw::JsonWriter::StringStream::~StringStream() {

}
bool ffw::JsonWriter::StringStream::write(const char* in, size_t len) {
	if (len == 0)len = strlen(in);

	if (str.size() + len > str.capacity()) {
		str.reserve(str.capacity() + 1024);
	}

	str.append(in);
	return true;
}
const std::string& ffw::JsonWriter::StringStream::get() const {
	return str;
}

///=============================================================================
ffw::JsonWriter::FileStream::FileStream(const std::string& path, std::ios_base::openmode mode) {
	file.open(path, mode);
}
ffw::JsonWriter::FileStream::~FileStream() {

}
bool ffw::JsonWriter::FileStream::isOpen() const {
	return file.is_open();
}
void ffw::JsonWriter::FileStream::close() {
	file.close();
}
bool ffw::JsonWriter::FileStream::write(const char* in, size_t len) {
	if (len == 0)len = strlen(in);

	if (file.write(in, len))return true;
	return false;
}

static void encodeJsonArr(ffw::JsonWriter& json, const ffw::Array& input);

///=============================================================================
static void encodeJsonObj(ffw::JsonWriter& json, const ffw::Object& input) {
	for (const auto& pair : input) {
		if (pair.second.is<ffw::Object>()) {
			json.addObject(pair.first.c_str());
			encodeJsonObj(json, pair.second.getAs<ffw::Object>());
			json.stepOut();
		}

		else if (pair.second.is<ffw::Array>()) {
			json.addArray(pair.first.c_str());
			encodeJsonArr(json, pair.second.getAs<ffw::Array>());
			json.stepOut();
		}

		else if (pair.second.isInt()) {
			json.addInteger(pair.second.toInt(), pair.first.c_str());
		}

		else if (pair.second.isString()) {
			json.addString(pair.second.toString().c_str(), pair.first.c_str());
		}

		else if (pair.second.isFloat()) {
			json.addFloat(pair.second.toFloat(), pair.first.c_str());
		}

		else if (pair.second.isBool()) {
			json.addBoolean(pair.second.toBool(), pair.first.c_str());
		}

		else if (pair.second.isBool()) {
			json.addBoolean(pair.second.toBool(), pair.first.c_str());
		}

		else if (pair.second.empty()) {
			json.addNull(pair.first.c_str());
		}

		else {
			throw ffw::JsonEncodeException("Invalid data type: " + std::string(pair.second.getTypeid().name()));
		}
	}
}

///=============================================================================
static void encodeJsonArr(ffw::JsonWriter& json, const ffw::Array& input) {
	for (const auto& element : input) {
		if (element.is<ffw::Object>()) {
			json.addObject(NULL);
			encodeJsonObj(json, element.getAs<ffw::Object>());
			json.stepOut();
		}

		else if (element.is<ffw::Array>()) {
			json.addArray(NULL);
			encodeJsonArr(json, element.getAs<ffw::Array>());
			json.stepOut();
		}

		else if (element.isInt()) {
			json.addInteger(element.toInt(), NULL);
		}

		else if (element.isString()) {
			json.addString(element.toString().c_str(), NULL);
		}

		else if (element.isFloat()) {
			json.addFloat(element.toFloat(), NULL);
		}

		else if (element.isBool()) {
			json.addBoolean(element.toBool(), NULL);
		}

		else if (element.is<std::nullptr_t>()) {
			json.addNull(NULL);
		}

		else if (element.empty()) {
			//json.addNull(NULL);
		}

		else {
			throw ffw::JsonEncodeException("Invalid data type: " + std::string(element.getTypeid().name()));
		}
	}
}

///=============================================================================
std::string ffw::encodeJson(const ffw::Var& input, const char* indent, bool escape) {
	ffw::JsonWriter::StringStream stream;
	ffw::JsonWriter json(&stream, indent, escape);

	if (input.is<ffw::Object>()) {
		json.addObject();

		encodeJsonObj(json, input.getAs<ffw::Object>());
	}
	else if (input.is<ffw::Array>()) {
		json.addArray();

		encodeJsonArr(json, input.getAs<ffw::Array>());
	}
	else {
		throw ffw::JsonEncodeException("Could not encode JSON! First node must be either an object or an array!");
	}

	json.stepOut();
	return stream.get();
}

///=============================================================================
bool ffw::encodeJsonFile(const std::string& path, const ffw::Var& input, const char* indent, bool escape) {
	ffw::JsonWriter::FileStream stream(path, std::ios::out | std::ios::binary);
	if (!stream.isOpen())return false;

	ffw::JsonWriter json(&stream, indent, escape);

	if (input.is<ffw::Object>()) {
		json.addObject();

		encodeJsonObj(json, input.getAs<ffw::Object>());

		stream.close();
	}
	else if (input.is<ffw::Array>()) {
		json.addArray();

		encodeJsonArr(json, input.getAs<ffw::Array>());

		stream.close();
	}
	else {
		throw ffw::JsonEncodeException("Could not encode JSON! First node must be either an object or an array!");
	}

	json.stepOut();
	return true;
}