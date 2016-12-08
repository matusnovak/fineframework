/* This file is part of FineFramework project */
#ifndef FFW_DATA_HELPERS
#define FFW_DATA_HELPERS

#include "../config.h"
#include "../math.h"

namespace ffw {
	bool FFW_API StringContainsWhitespace(const char* str, size_t length);
	bool FFW_API StringIsInteger(const char* str, size_t length);
	bool FFW_API StringIsFloat(const char* str, size_t length);
	bool FFW_API StringIsBool(const char* str, size_t length, bool* ptr = NULL);
};

#endif