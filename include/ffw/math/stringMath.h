/* This file is part of FineFramework project */
#ifndef FFW_STRING_MATH
#define FFW_STRING_MATH

#include <string>

namespace ffw{
	/**
	 * @ingroup math
	 */
    template <class T> inline T StringToVal(const std::string& Str);
    template <> inline float                StringToVal<float>              (const std::string& Str);
    template <> inline double               StringToVal<double>             (const std::string& Str);
    template <> inline long double          StringToVal<long double>        (const std::string& Str);
    template <> inline short                StringToVal<short>              (const std::string& Str);
    template <> inline int                  StringToVal<int>                (const std::string& Str);
    template <> inline long                 StringToVal<long>               (const std::string& Str);
    template <> inline long long            StringToVal<long long>          (const std::string& Str);
    template <> inline unsigned short       StringToVal<unsigned short>     (const std::string& Str);
    template <> inline unsigned int         StringToVal<unsigned int>       (const std::string& Str);
    template <> inline unsigned long        StringToVal<unsigned long>      (const std::string& Str);
    template <> inline unsigned long long   StringToVal<unsigned long long> (const std::string& Str);
	/**
	 * @ingroup math
	 */
    template <class T> inline std::string ValToString(T Value);
	/**
	 * @ingroup math
	 */
    template <class T> inline std::wstring ValToWstring(T Value);
	/**
	 * @ingroup math
	 */
    template <class T> inline std::string ValToString(T Value, unsigned int Dec);
	/**
	 * @ingroup math
	 */
	template <class T> inline std::wstring ValToWstring(T Value, unsigned int Dec);
	/**
	 * @ingroup math
	 */
    template<typename T> inline T HexToVal(const std::string& Str);
	/**
	 * @ingroup math
	 */
    template<typename T> inline std::string ValToHex(const T& Value);
	/**
	 * @ingroup math
	 */
	template<class T> inline std::vector<T> GetTokens(const T& Line, char Delim);
	/**
	 * @ingroup math
	 */
	template<class T> inline unsigned int GetTokensNum(const T& Line, char Delim);
#ifdef FFW_WINDOWS
	/**
	 * @ingroup math
	 */
    inline std::string WstrToAnsi(const std::wstring& Str);
	/**
	 * @ingroup math
	 */
	inline size_t WstrToAnsiSize(const std::wstring& Str);
	/**
	 * @ingroup math
	 */
    inline std::wstring AnsiToWstr(const std::string& Str);
	/**
	 * @ingroup math
	 */
	inline size_t AnsiToWstrSize(const std::string& Str);
#endif
	/**
	 * @ingroup math
	 */
    inline std::string WstrToUtf8(const std::wstring& Str);
	/**
	 * @ingroup math
	 */
	inline size_t WstrToUtf8Size(const std::wstring& Str);
	/**
	 * @ingroup math
	 */
    inline std::wstring Utf8ToWstr(const std::string& Str);
	/**
	 * @ingroup math
	 */
	inline size_t Utf8ToWstrSize(const std::string& Str);
	/**
	 * @ingroup math
	 */
	class FileInfo {
	public:
		inline FileInfo(){
		}
		inline FileInfo(const std::string& name, const std::string& dir, const std::string& ext):
			basename(name),dirname(dir),extension(ext){
		}
		const std::string basename;
		const std::string dirname;
		const std::string extension;
	};
	/**
	 * @ingroup math
	 */
	inline FileInfo GetFileInfo(const std::string& path);
	/**
	 * @ingroup math
	 */
	inline std::string Basename(const std::string& path);
	/**
	 * @ingroup math
	 */
	inline std::string Dirname(const std::string& path);
	/**
	 * @ingroup math
	 */
	inline std::string Extension(const std::string& path);
	/**
	 * @ingroup math
	 */
	inline std::string ToUpper(const std::string& str);
	/**
	 * @ingroup math
	 */
	inline std::string ToLower(const std::string& str);
};
#include "stringmath.inl"
#endif
