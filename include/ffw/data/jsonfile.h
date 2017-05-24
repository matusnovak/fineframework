/* This file is part of FineFramework project */
#ifndef FFW_LOAD_SAVE_JSON
#define FFW_LOAD_SAVE_JSON
#include "../config.h"
#include "../math/var.h"

namespace ffw{
	/**
	 * @ingroup data
	 */
	ffw::Var FFW_API decodeJson(const std::string& input);
	/**
	 * @ingroup data
	 */
	void FFW_API decodeJson(const std::string& input, ffw::Var& output);
	/**
	 * @ingroup data
	 */
	std::string FFW_API encodeJson(const ffw::Var& input, bool formated = false, bool escape = true);
	/**
	 * @ingroup data
	 */
	void FFW_API encodeJson(const ffw::Var& input, std::string& output, bool formated = false, bool escape = true);
	/**
	 * @ingroup data
	 */
	bool FFW_API loadJson(const std::string& path, ffw::Var& output);
	/**
	 * @ingroup data
	 */
	bool FFW_API saveJson(const std::string& path, const ffw::Var& input, bool formated = false, bool escape = true);
};
#endif
