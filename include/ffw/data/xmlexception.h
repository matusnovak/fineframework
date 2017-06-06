/* This file is part of FineFramework project */
#pragma once
#ifndef FFW_XML_EXCEPTION
#define FFW_XML_EXCEPTION
#include "../config.h"
#include <stdexcept>

namespace ffw {
	/**
	* @ingroup data
	*/
	class XmlException : public std::runtime_error {
	public:
		inline XmlException(const std::string& msg) :std::runtime_error(msg) {

		}
	};
	/**
	* @ingroup data
	*/
	class XmlDecodeException : public XmlException {
	public:
		inline XmlDecodeException(const std::string& msg) :XmlException(msg) {

		}
	};
	/**
	* @ingroup data
	*/
	class XmlEncodeException : public XmlException {
	public:
		inline XmlEncodeException(const std::string& msg) :XmlException(msg) {

		}
	};
};

#endif