/* This file is part of FineFramework project */
#ifndef FFW_DATA_HELPERS
#define FFW_DATA_HELPERS

#include "../config.h"

namespace ffw {
	/**
	* @ingroup data
	*/
	bool FFW_API stringContainsWhitespace(const char* str, size_t length);
	/**
	* @ingroup data
	*/
	bool FFW_API stringisInteger(const char* str, size_t length);
	/**
	* @ingroup data
	*/
	bool FFW_API stringisFloat(const char* str, size_t length);
	/**
	* @ingroup data
	*/
	bool FFW_API stringisBool(const char* str, size_t length, bool* ptr = NULL);
};

#endif