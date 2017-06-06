/* This file is part of FineFramework project */
#pragma once
#ifndef FFW_XML_READER
#define FFW_XML_READER
#include "xmlexception.h"
#include "../math/var.h"
#include <list>

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace tinyxml2 {
	class XMLElement;
	class XMLDocument;
	class XMLNode;
	class XMLAttribute;
}
#endif /* DOXYGEN_SHOULD_SKIP_THIS */

namespace ffw {
	/**
	* @ingroup data
	* @ref doc/markdown/tutorial-xml.md
	*/
	class FFW_API XmlReader {
	public:
		enum class Type {
			OBJECT,
			INTEGER,
			FLOAT,
			BOOLEAN,
			STRING,
			NULLVAL,
			EMPTY,
			INVALID,
		};

		class FFW_API Value {
		public:
			virtual std::string name() const = 0;
			virtual bool isObject() const = 0;
			
			bool isEmpty() const;
			bool isString() const;
			bool isNumber() const;
			bool isInteger() const;
			bool isFloat() const;
			bool isBoolean() const;
			bool isNull() const;

			std::string toString() const;
			int toInteger() const;
			double toDouble() const;
			float toFloat() const;
			bool toBoolean() const;

			Type getType() const;

			virtual const char* rawCstr() const = 0;
		};

		class FFW_API Attribute: public Value {
		public:
			inline Attribute() {
			}

			inline Attribute(const tinyxml2::XMLAttribute* node) :attr(node) {
			}


			std::string name() const override;
			bool isObject() const override;
			const char* rawCstr() const override;

		private:
			const tinyxml2::XMLAttribute* attr;
		};

		class FFW_API Node: public Value {
		public:
			inline Node():elem(NULL),attr(NULL) {
			}

			inline Node(const tinyxml2::XMLElement* node) :elem(node),attr(NULL) {
			}

			bool getNextAttribute(Attribute* node);

			std::string name() const override;
			bool isObject() const override;
			bool hasAttributes() const;
			const char* rawCstr() const override;

			const tinyxml2::XMLElement* elem;
		private:
			const tinyxml2::XMLAttribute* attr;
		};

		XmlReader(const std::string& input);
		XmlReader(const char* input);
		virtual ~XmlReader();

		bool getNext(Node* value);
		bool stepInto(const Node* node);
		bool stepOut();
	private:
		struct Cache {
			const tinyxml2::XMLElement* child;
			const tinyxml2::XMLElement* parent;
		};
		std::list<Cache> cache;
		std::shared_ptr<tinyxml2::XMLDocument> document;
		const tinyxml2::XMLElement* child;
		const tinyxml2::XMLElement* parent;
	};
	/**
	* @ingroup data
	*/
	ffw::Var FFW_API decodeXml(const char* input);
	/**
	* @ingroup data
	*/
	ffw::Var FFW_API decodeXml(const std::string& input);
	/**
	* @ingroup data
	*/
	ffw::Var FFW_API decodeXmlFile(const std::string& path);
};

#endif