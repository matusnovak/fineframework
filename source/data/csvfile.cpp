/*** This file is part of FineFramework project ***/

#include "ffw/data/csvfile.h"
#include "ffw/data/helpers.h"
#include "ffw/math/stringmath.h"

///=============================================================================
ffw::CsvLoader::CsvLoader(){
	stream = NULL;
}

///=============================================================================
ffw::CsvLoader::~CsvLoader(){
	close();
}

///=============================================================================
bool ffw::CsvLoader::openFromData(const std::string& input, char delim, char quote){
	if(isOpen())return false;
	stream = &input;
	pos = 0;
	del = delim;
	quot = quote;
	return true;
}

///=============================================================================
bool ffw::CsvLoader::openFromFile(const std::string& path, char delim, char quote){
	if(isOpen())return false;
	del = delim;
	quot = quote;

	file.open(path, std::ifstream::in);
	if(!file.is_open()){
		//std::cout << "file not open!" << std::endl;

		return false;
	}

	return true;
}

///=============================================================================
bool ffw::CsvLoader::isOpen() const {
	return (stream != NULL || file.is_open());
}

///=============================================================================
void ffw::CsvLoader::close(){
	if(file.is_open()){
		file.close();
	}
	stream = NULL;
}

///=============================================================================
static void fixDoubleQuotes(std::string& str){
	size_t pos = 0;
	while((pos = str.find("\"\"", pos)) != std::string::npos){
		str.replace(pos, 2, "\"");
	}
}

///=============================================================================
static ffw::Var parseToken(const std::string& str, size_t begin, size_t end, bool convert, char quot){
	//std::cout << "parsing: " << begin << " / " << end << std::endl;

	if(begin != end && end > begin){
		for(size_t i = begin; i < end; i++){
			if(str[i] == 32 || str[i] == 9)continue;
			if(str[i] == quot){
				begin = i+1;
			}
			break;
		}

		for(size_t i = end-1; i > begin; i--){
			if(str[i] == 32 || str[i] == 9)continue;
			if(str[i] == quot){
				end = i;
			}
			break;
		}

		if(begin == end){
			return ffw::Var("");
		}

		if(convert){
			bool value = 0;
			if(ffw::stringisInteger(&str[begin], end-begin)){
				return ffw::Var(ffw::stringToVal<int>(str.substr(begin, end-begin)));

			} else if(ffw::stringisFloat(&str[begin], end-begin)){
				return ffw::Var(ffw::stringToVal<float>(str.substr(begin, end-begin)));

			} else if(ffw::stringisBool(&str[begin], end-begin, &value)){
				return ffw::Var(value);

			} else {
				std::string s = str.substr(begin, end-begin);
				fixDoubleQuotes(s);
				return ffw::Var(s);
			}
		} else {
			std::string s = str.substr(begin, end-begin);
			fixDoubleQuotes(s);
			return ffw::Var(s);
		}
	}

	if(!convert)return ffw::Var("");
	return ffw::Var();
}

///=============================================================================
ffw::Array ffw::CsvLoader::tokenize(const std::string& str, size_t begin, size_t end, bool convert, char del, char quot){
	//std::cout << "ROW: " << str.substr(begin, end-begin) << std::endl;
	//std::cout << "begin: " << begin << " end: " << end << std::endl;
	bool inside = false;
	size_t first = begin;
	size_t last = begin;

	ffw::Array arr;

	for(size_t i = begin; i <= end; i++){
		if(i < end){
			const auto& c = str[i];

			if(c == quot){
				if(i < end-1 && str[i+1] == quot){
					// Do nothing
					i++;
				} else {
					inside = !inside;
				}
			}

			if(c == del && !inside){
				arr.push_back(parseToken(str, first, i, convert, quot));
				first = i+1;
			}
		} else {
			arr.push_back(parseToken(str, first, i, convert, quot));
		}
	}

	//std::cout << "returning " << arr.size() << std::endl;
	return arr;
}

///=============================================================================
ffw::Array ffw::CsvLoader::getRow(bool convert){
	std::string str = getRowRaw();
	return tokenize(&str[0], 0, str.size(), convert, del, quot);
}

///=============================================================================
std::string ffw::CsvLoader::getRowRaw(){
	if(!isOpen())return "";

	//std::cout << "getting row..." << std::endl;

	std::string row;
	std::string* ptr = NULL;

	if(file.is_open() && !file.eof()){

		while(!file.eof()){
			if(!std::getline(file, row)){
				file.close();
				return "";
			}

			// Check if row is not empty
			if(stringContainsWhitespace(&row[0], row.size())){
				//std::cout << row << " contains only whitespace!" << std::endl;
				continue;
			}
			break;
		}

		//return tokenize(row, 0, row.size());
		return row;

	} else if(stream != NULL){
		size_t begin = pos;
		size_t end = pos;

		while(pos < stream->size()){
			// Find line...
			while((end = stream->find('\n', pos)) != std::string::npos){
				if(end == begin){
					pos = end+1;
					begin = pos;
					continue;
				}
				break;
			}

			// Last line...
			if(end == std::string::npos && pos < stream->size() && begin <= pos){
				end = stream->size();
			}

			pos = end+1;

			if(begin == end || begin >= stream->size()){
				file.close();
				return "";
			}

			// Check if row is not empty
			if(stringContainsWhitespace(&(*stream)[begin], end - begin)){
				//std::cout << stream->substr(begin, end - begin) << " contains only whitespace!" << std::endl;
				begin = pos;
				continue;
			}
			break;
		}

		//return tokenize(*stream, begin, end);
		return stream->substr(begin, end - begin);
	}

	return "";
}

///=============================================================================
bool ffw::CsvLoader::eof() const {
	if(file.is_open()){
		return file.eof();
	} else if(stream != NULL){
		return pos >= stream->size();
	}
	return true;
}

///=============================================================================
bool ffw::loadCsv(const std::string& path, ffw::Array& output){
	CsvLoader loader;
	if(!loader.openFromFile(path))return false;

	while(!loader.eof()){
		output.push_back(loader.getRow());
	}

	return true;
}

///=============================================================================
ffw::Array ffw::decodeCsv(const std::string& input){
	ffw::Array output;

	CsvLoader loader;
	if(!loader.openFromData(input))return output;

	while(!loader.eof()){
		output.push_back(loader.getRow());
	}

	return output;
}
