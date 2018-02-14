/* This file is part of FineFramework project */
#pragma once
#ifndef FFW_JSON_READER
#define FFW_JSON_READER
#include "jsonexception.h"
#include "../math/any.h"
#include <list>

namespace ffw {
    /**
    * @ingroup data
    * @ref doc/markdown/tutorial-json.md
    */
    class FFW_API JsonReader {
    public:
        enum class Type {
            OBJECT,
            ARRAY,
            INTEGER,
            FLOAT,
            BOOLEAN,
            STRING,
            NULLVAL,
            EMPTY,
            INVALID,
        };

        class FFW_API Node {
        public:
            inline Node(const char* p, size_t l) :ptr(p), len(l) {

            }
            inline Node() : ptr(NULL), len(SIZE_MAX) {

            }
            inline std::string str() const {
                if (ptr == NULL || len == 0)return std::string();
                return std::string(ptr, len);
            }
            inline std::string raw() const {
                if (ptr == NULL || len == 0)return std::string();
                return std::string(ptr, len);
            }

            Type getType() const;
            inline bool isString() const {
                return (!isEmpty() && ptr[0] == '"' && ptr[len - 1] == '"');
            }

            inline bool isObject() const {
                return (!isEmpty() && ptr[0] == '{' && ptr[len - 1] == '}');
            }

            inline bool isArray() const {
                return (!isEmpty() && ptr[0] == '[' && ptr[len - 1] == ']');
            }

            inline bool isEmpty() const {
                return (ptr == NULL || len == 0);
            }

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

            const char* ptr;
            size_t len;
        };

        JsonReader(const std::string& input);
        JsonReader(const char* input);
        virtual ~JsonReader();

        bool getNext(Node* value, Node* key);
        bool stepInto(const Node* node);
        bool stepOut();
        inline Type getCurrentType() const {
            return current;
        }

        inline const char* getCurrentPtr() const {
            return str;
        }

        inline size_t getCurrentLen() const {
            return len;
        }
    private:
        bool checkCurrent(const char* start, const char* end, Node* node);
        struct Cache {
            Type current;
            const char* str;
            size_t len;
        };
        std::list<Cache> cache;
        Type current;
        const char* str;
        size_t len;
    };
    /**
    * @ingroup data
    */
    ffw::Any FFW_API decodeJson(const char* input);
    /**
    * @ingroup data
    */
    ffw::Any FFW_API decodeJson(const std::string& input);
    /**
    * @ingroup data
    */
    ffw::Any FFW_API decodeJsonFile(const std::string& path);
};

#endif