/* This file is part of FineFramework project */
#ifndef FFW_LOAD_SAVE_JSON
#define FFW_LOAD_SAVE_JSON
#include "../config.h"
#include "../math.h"

namespace ffw{
	/**
	 * @ingroup data
	 */
	bool FFW_API DecodeJson(const std::string& Str, ffw::Var* Output);
	/**
	 * @ingroup data
	 */
	void FFW_API EncodeJson(std::string* Output, ffw::Var* Var, bool Formated, bool EscapeUnicode);
	/**
	 * @ingroup data
	 */
	bool FFW_API LoadJson(const std::string& Path, ffw::Var* Output);
	/**
	 * @ingroup data
	 */
	bool FFW_API SaveJson(const std::string& Path, ffw::Var* Input, bool Formated, bool EscapeUnicode);
};
#endif
