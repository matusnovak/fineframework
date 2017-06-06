/*** This file is part of FineFramework project ***/

#include "ffw/data/helpers.h"
#include <regex>

///=============================================================================
bool ffw::stringContainsWhitespace(std::string::const_iterator begin, std::string::const_iterator end){
	for (; begin != end; begin++) {
		switch(*begin){
			case ' ': // Space
			case '\t': // Tab
			case '\v': // Vertical Tab
			case '\f': // Line Feed
			case '\r': // Carriage Return
				continue;
			default:
				return false;
		}
	}
	return true;
}

///=============================================================================
bool ffw::stringisInteger(std::string::const_iterator begin, std::string::const_iterator end){
	return std::regex_match(begin, end, std::regex("^[-+]?\\d+([Ee][+-]?\\d+)?$"));
}

///=============================================================================
bool ffw::stringisFloat(std::string::const_iterator begin, std::string::const_iterator end){
	return std::regex_match(begin, end, std::regex("^[-+]?\\d*\\.{1}\\d+([Ee][+-]?\\d+)?$"));
}

///=============================================================================
bool ffw::stringisBool(std::string::const_iterator begin, std::string::const_iterator end){
	return std::regex_match(begin, end, std::regex("^(true|TRUE|True|false|False|FALSE)$"));
}