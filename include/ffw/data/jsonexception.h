/* This file is part of FineFramework project */
#pragma once
#ifndef FFW_JSON_EXCEPTION
#define FFW_JSON_EXCEPTION
#include "../config.h"
#include <stdexcept>

namespace ffw {
	/**
	* @ingroup data
	*/
	class JsonException : public std::runtime_error {
	public:
		inline JsonException(const std::string& msg) :std::runtime_error(msg) {

		}
	};
	/**
	* @ingroup data
	*/
	class JsonDecodeException : public JsonException {
	public:
		inline JsonDecodeException(const std::string& msg) :JsonException(msg) {

		}
	};
	/**
	* @ingroup data
	*/
	class JsonEncodeException : public JsonException {
	public:
		inline JsonEncodeException(const std::string& msg) :JsonException(msg) {

		}
	};
};

#endif