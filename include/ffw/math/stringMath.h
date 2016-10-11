/* This file is part of FineFramework project */
#ifndef FFW_STRING_MATH
#define FFW_STRING_MATH

namespace ffw{
	/**
	 * @ingroup math
	 */
    template <class T> T StringToVal(const std::string& Str);
    template <> float                StringToVal<float>              (const std::string& Str);
    template <> double               StringToVal<double>             (const std::string& Str);
    template <> long double          StringToVal<long double>        (const std::string& Str);
    template <> short                StringToVal<short>              (const std::string& Str);
    template <> int                  StringToVal<int>                (const std::string& Str);
    template <> long                 StringToVal<long>               (const std::string& Str);
    template <> long long            StringToVal<long long>          (const std::string& Str);
    template <> unsigned short       StringToVal<unsigned short>     (const std::string& Str);
    template <> unsigned int         StringToVal<unsigned int>       (const std::string& Str);
    template <> unsigned long        StringToVal<unsigned long>      (const std::string& Str);
    template <> unsigned long long   StringToVal<unsigned long long> (const std::string& Str);
	/**
	 * @ingroup math
	 */
    template <class T> std::string ValToString(const T& Value);
	/**
	 * @ingroup math
	 */
    template <class T> std::string ValToString(T Value, unsigned int Dec);
	/**
	 * @ingroup math
	 */
    template<typename T> T HexToVal(const std::string& Str);
	/**
	 * @ingroup math
	 */
    template<typename T> std::string ValToHex(const T& Value);
	/**
	 * @ingroup math
	 */
	template<class T> std::vector<T> GetTokens(const T& Line, char Delim);
	/**
	 * @ingroup math
	 */
	template<class T> unsigned int GetTokensNum(const T& Line, char Delim);
#ifdef FFW_WINDOWS
	/**
	 * @ingroup math
	 */
    std::string FFW_API WstrToAnsi(const std::wstring& Str);
	/**
	 * @ingroup math
	 */
	size_t FFW_API WstrToAnsiSize(const std::wstring& Str);
	/**
	 * @ingroup math
	 */
    std::wstring FFW_API AnsiToWstr(const std::string& Str);
	/**
	 * @ingroup math
	 */
	size_t FFW_API AnsiToWstrSize(const std::string& Str);
#endif
	/**
	 * @ingroup math
	 */
    std::string FFW_API WstrToUtf8(const std::wstring& Str);
	/**
	 * @ingroup math
	 */
	size_t FFW_API WstrToUtf8Size(const std::wstring& Str);
	/**
	 * @ingroup math
	 */
    std::wstring FFW_API Utf8ToWstr(const std::string& Str);
	/**
	 * @ingroup math
	 */
	size_t FFW_API Utf8ToWstrSize(const std::string& Str);
};
#include "stringmath.inl"
#endif
