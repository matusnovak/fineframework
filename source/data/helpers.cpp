/*** This file is part of FineFramework project ***/

#include "ffw/data/helpers.h"

///=============================================================================
bool ffw::stringContainsWhitespace(const char* str, size_t length){
	for(size_t i = 0; i < length; i++){
		switch(str[i]){
			case 32: // Space
			case 9: // Tab
			case 10: // Line Feed
			case 13: // Carriage Return
				continue;
			default:
				return false;
		}
	}
	return true;
}

///=============================================================================
bool ffw::stringisInteger(const char* str, size_t length){
	bool foundDigit = false;
	bool enclosingSpace = false;

	if(length == 0)return false;

	for(size_t i = 0; i < length; i++){
		if(str[i] == 32 || str[i] == 9){

			if(foundDigit){
				enclosingSpace = true;
			}
			continue;
		}

		if((str[i] >= '0' && str[i] <= '9') || str[i] == '-' || str[i] == '+'){
			// True if space is dividing two sets of number, for example: "123 654"
			if(enclosingSpace){
				return false;
			}
			
			// + and - can be only at the beginning!
			if((str[i] == '-' || str[i] == '+') && foundDigit){
				return false;
			}

			foundDigit = true;
		} 
		// No other characters accepted!
		else {
			return false;
		}
	}
	return true;
}

///=============================================================================
bool ffw::stringisFloat(const char* str, size_t length){
	bool foundDigit = false;
	bool enclosingSpace = false;
	bool foundDecimal = false;

	if(length == 0)return false;

	for(size_t i = 0; i < length; i++){
		if(str[i] == 32 || str[i] == 9){

			if(foundDigit){
				enclosingSpace = true;
			}
			continue;
		}

		if((str[i] >= '0' && str[i] <= '9') || str[i] == '-' || str[i] == '+' || str[i] == '.'){
			// True if space is dividing two sets of number, for example: "123 654"
			if(enclosingSpace){
				return false;
			}

			if(str[i] == '.'){
				// Only one decimal accepted!
				if(foundDecimal){
					return false;
				}
				foundDecimal = true;
			}
			
			// + and - can be only at the beginning!
			if((str[i] == '-' || str[i] == '+') && foundDigit){
				return false;
			}

			foundDigit = true;
		} 
		// No other characters accepted!
		else {
			return false;
		}
	}
	return true;
}

///=============================================================================
bool ffw::stringisBool(const char* str, size_t length, bool* ptr ){
	if(length == 0)return false;

	size_t end = length;
	size_t begin = 0;

	for(size_t i = 0; i < length; i++){
		if(str[i] == 32){
			begin++;
			continue;
		}
		break;
	}

	if(end > 0){
		for(size_t i = end-1; i > 1; i--){
			if(str[i] == 32){
				end--;
				continue;
			}
			break;
		}
	}

	if(end-begin == 4){
		if(tolower(str[begin+0]) == 't' &&
			tolower(str[begin+1]) == 'r' &&
			tolower(str[begin+2]) == 'u' &&
			tolower(str[begin+3]) == 'e'){
			if(ptr != NULL)*ptr = true;
			return true;
		}
		return false;
	}

	if(end-begin == 5){
		if(tolower(str[begin+0]) == 'f' &&
			tolower(str[begin+1]) == 'a' &&
			tolower(str[begin+2]) == 'l' &&
			tolower(str[begin+3]) == 's' &&
			tolower(str[begin+4]) == 'e'){
			if(ptr != NULL)*ptr = false;
			return true;
		}
		return false;
	}

	//std::cout << "failed checking for bool: >" << std::string(str).substr(begin, end-begin) << "<" << std::endl;
	return false;
}