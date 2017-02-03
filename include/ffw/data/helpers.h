/* This file is part of FineFramework project */
#ifndef FFW_DATA_HELPERS
#define FFW_DATA_HELPERS

#include "../config.h"
#include "../math.h"

namespace ffw {
	/**
	* @ingroup data
	*/
	bool FFW_API StringContainsWhitespace(const char* str, size_t length);
	/**
	* @ingroup data
	*/
	bool FFW_API StringIsInteger(const char* str, size_t length);
	/**
	* @ingroup data
	*/
	bool FFW_API StringIsFloat(const char* str, size_t length);
	/**
	* @ingroup data
	*/
	bool FFW_API StringIsBool(const char* str, size_t length, bool* ptr = NULL);
};

#endif