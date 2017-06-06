/* This file is part of FineFramework project */
#pragma once
#ifndef FFW_XML_WRITER
#define FFW_XML_WRITER
#include "xmlexception.h"
#include "../math/var.h"
#include <sstream>
#include <fstream>
#include <list>

namespace ffw{
	/**
	* @ingroup data
	* @ref doc/markdown/tutorial-xml.md
	*/
	class FFW_API XmlWriter {
	public:
		class FFW_API Stream {
		public:
			virtual bool write(const char* str, size_t len) = 0;
		};

		class FFW_API StringStream : public ffw::XmlWriter::Stream {
		public:
			StringStream();
			virtual ~StringStream();
			bool write(const char* in, size_t len) override;
			const std::string& get() const;
		private:
			std::string str;
		};

		class FFW_API FileStream : public ffw::XmlWriter::Stream {
		public:
			FileStream(const std::string& path, std::ios_base::openmode mode);
			~FileStream();
			bool isOpen() const;
			void close();
			bool write(const char* in, size_t len) override;
		private:
			std::ofstream file;
		};

		XmlWriter(Stream* stream, const char* indent = NULL, bool escape = true);
		virtual ~XmlWriter();

		void addObject(const char* key);
		void stepOut();

		void beginContent();
		void addInteger(int val, const char* key);
		void addString(const char* val, const char* key);
		void addBoolean(bool val, const char* key);
		void addFloat(float val, const char* key);
		void addNull(const char* key);

	private:
		void addBegin(const char* key);
		void addEnd(const char* key);
		void writeIndent();
		inline void write(const char* str, size_t len);

		Stream* stream;
		const char* indent;
		bool escape;
		bool attribs;
		std::list<std::string> keys;
	};
	/**
	* @ingroup data
	*/
	std::string FFW_API encodeXml(const ffw::Var& input, const char* indent = NULL, bool escape = false);
	/**
	* @ingroup data
	*/
	bool FFW_API encodeXmlFile(const std::string& path, const ffw::Var& input, const char* indent = NULL, bool escape = false);
};

#endif