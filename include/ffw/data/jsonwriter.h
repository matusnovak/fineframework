/* This file is part of FineFramework project */
#pragma once
#ifndef FFW_JSON_WRITER
#define FFW_JSON_WRITER
#include "jsonexception.h"
#include "../math/var.h"
#include <sstream>
#include <fstream>

namespace ffw{
	/**
	* @ingroup data
	* @ref doc/markdown/tutorial-json.md
	*/
	class FFW_API JsonWriter {
	public:
		class FFW_API Stream {
		public:
			virtual bool write(const char* str, size_t len) = 0;
		};

		class FFW_API StringStream : public ffw::JsonWriter::Stream {
		public:
			StringStream();
			virtual ~StringStream();
			bool write(const char* in, size_t len) override;
			const std::string& get() const;
		private:
			std::string str;
		};

		class FFW_API FileStream : public ffw::JsonWriter::Stream {
		public:
			FileStream(const std::string& path, std::ios_base::openmode mode);
			virtual ~FileStream();
			bool isOpen() const;
			void close();
			bool write(const char* in, size_t len) override;
		private:
			std::ofstream file;
		};

		JsonWriter(Stream* stream, const char* indent = NULL, bool escape = true);
		virtual ~JsonWriter();

		void addObject(const char* key = NULL);
		void addArray(const char* key = NULL);
		void stepOut();

		void addInteger(int val, const char* key = NULL);
		void addString(const char* val, const char* key = NULL);
		void addBoolean(bool val, const char* key = NULL);
		void addFloat(float val, const char* key = NULL);
		void addNull(const char* key = NULL);
	private:
		void writeIndent();
		void addBegin(const char* key);
		void addEnd();
		inline void write(const char* str, size_t len);

		Stream* stream;
		std::vector<bool> braces;
		const char* indent;
		bool escape;
		int count;
	};
	/**
	* @ingroup data
	*/
	std::string FFW_API encodeJson(const ffw::Var& input, const char* indent = NULL, bool escape = false);
	/**
	* @ingroup data
	*/
	bool FFW_API encodeJsonFile(const std::string& path, const ffw::Var& input, const char* indent = NULL, bool escape = false);
};

#endif