/* This file is part of FineFramework project */
#ifndef FFW_LOAD_SAVE_XML
#define FFW_LOAD_SAVE_XML
#include "../config.h"
#include "../math.h"

namespace ffw{
	/**
	 * @ingroup data
	 */
	ffw::Var FFW_API decodeXml(const std::string& input);
	/**
	 * @ingroup data
	 */
	bool FFW_API decodeXml(const std::string& input, ffw::Var& output);
	/**
	 * @ingroup data
	 */
	std::string FFW_API encodeXml(const ffw::Var& input, bool formated = false, bool escape = true);
	/**
	 * @ingroup data
	 */
	void FFW_API encodeXml(const ffw::Var& input, std::string& output, bool formated = false, bool escape = true);
	/**
	 * @ingroup data
	 */
	bool FFW_API loadXml(const std::string& path, ffw::Var& output);
	/**
	 * @ingroup data
	 */
	bool FFW_API saveXml(const std::string& path, const ffw::Var& input, bool formated = false, bool escape = true);
};
#endif

