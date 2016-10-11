/* This file is part of FineFramework project */
#ifndef FFW_LOAD_SAVE_XML
#define FFW_LOAD_SAVE_XML
#include "../config.h"
#include "../math.h"

namespace ffw{
	bool FFW_API DecodeXml(const std::string& Str, ffw::Var* Output);
	void FFW_API EncodeXml(std::string* Output, ffw::Var* Var, bool Formated, bool EscapeUnicode);
	bool FFW_API LoadXml(const std::string& Path, ffw::Var* Output);
	bool FFW_API SaveXml(const std::string& Path, ffw::Var* Input, bool Formated, bool EscapeUnicode);
};
#endif

