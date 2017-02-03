/* This file is part of FineFramework project */
#ifndef FFW_STRING_MATH
#define FFW_STRING_MATH

#include <string>

namespace ffw{
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
	* @exception Throws std::invalid_argument (invalid conversion) 
	* or std::out_of_range (conversion is out of the range)
	*/
	template <class T> inline T StringToVal(const std::string& str);
	/**
	* @ingroup math
	*/
	template <> inline float                StringToVal<float>(const std::string& Str) { return std::stof(Str); }
	/**
	* @ingroup math
	*/
	template <> inline double               StringToVal<double>(const std::string& Str) { return std::stod(Str); }
	/**
	* @ingroup math
	*/
	template <> inline long double          StringToVal<long double>(const std::string& Str) { return std::stold(Str); }
	/**
	* @ingroup math
	*/
	template <> inline short                StringToVal<short>(const std::string& Str) { return static_cast<short>(std::stoi(Str)); }
	/**
	* @ingroup math
	*/
	template <> inline int                  StringToVal<int>(const std::string& Str) { return std::stoi(Str); }
	/**
	* @ingroup math
	*/
	template <> inline long                 StringToVal<long>(const std::string& Str) { return std::stol(Str); }
	/**
	* @ingroup math
	*/
	template <> inline long long            StringToVal<long long>(const std::string& Str) { return std::stoll(Str); }
	/**
	* @ingroup math
	*/
	template <> inline unsigned short       StringToVal<unsigned short>(const std::string& Str) { return (unsigned short)std::stoul(Str); }
	/**
	* @ingroup math
	*/
	template <> inline unsigned int         StringToVal<unsigned int>(const std::string& Str) { return std::stoul(Str); }
	/**
	* @ingroup math
	*/
	template <> inline unsigned long        StringToVal<unsigned long>(const std::string& Str) { return std::stoul(Str); }
	/**
	* @ingroup math
	*/
	template <> inline unsigned long long   StringToVal<unsigned long long>(const std::string& Str) { return std::stoull(Str); }
	/**
	* @ingroup math
	*/
	template <class T>
	inline std::string ValToString(T Value) {
		return std::to_string(Value);
	}
	/**
	* @ingroup math
	*/
	template <class T>
	inline std::string ValToString(T Value, unsigned int Dec) {
		std::ostringstream ostr;
		ostr.precision(Dec);
		ostr << std::fixed << Value;
		return ostr.str();
	}
	/**
	* @ingroup math
	*/
	template<typename T>
	inline T HexToVal(const std::string& Str) {
		try {
			return std::stoul(Str, nullptr, 16);
		}
		catch (std::invalid_argument e) {
			return 0;
		}
		catch (std::out_of_range e) {
			return 0;
		}
		return 0;
	}
	/**
	* @ingroup math
	*/
	template<typename T>
	inline std::string ValToHex(const T& Value) {
		static const char chars[16] = { '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'a', 'b', 'c', 'd', 'e', 'f' };
		std::string str;
		str.resize(sizeof(T) * 2);
		for (size_t i = 0; i < sizeof(T) * 2; i++) {
			char c = (Value >> (i * 4));
			c = c & 0x0F;
			str[sizeof(T) * 2 - i - 1] = chars[int(c)];
		}
		return str;
	}
	/**
	* @ingroup math
	*/
	template<class T, typename CharTrait = std::char_traits<T>, typename Allocator = std::allocator<T>>
	inline size_t GetTokensFunc(
			std::vector<std::basic_string<T, CharTrait, Allocator>>* vec,
			const std::basic_string<T, CharTrait, Allocator>& str,
			const std::basic_string<T, CharTrait, Allocator>& delim) {
		size_t pos = 0;
		size_t last = 0;
		size_t count = 0;
		// Loop until all tokens found
		while ((pos = str.find(delim, pos)) != std::basic_string<T, CharTrait, Allocator>::npos) {
			// Do we have non-empty token?
			if (last < pos && pos - last > 0) {
				if(vec != NULL)vec->push_back(str.substr(last, pos - last));
				count++;
			}
			pos += delim.size();
			last = pos;
		}
		// Add the last token (will also include a whole string when no delim was found)
		if (last < str.size()) {
			if (vec != NULL)vec->push_back(str.substr(last, str.size() - last));
			count++;
		}
		return count;
	}
	/**
	* @ingroup math
	*/
	inline std::vector<std::string> GetTokens(const std::string& str, const std::string& delim) {
		std::vector<std::string> ret;
		GetTokensFunc(&ret, str, delim);
		return ret;
	}
	/**
	* @ingroup math
	*/
	inline std::vector<std::string> GetTokens(const std::string& str, char delim) {
		std::vector<std::string> ret;
		GetTokensFunc(&ret, str, std::string(1, delim));
		return ret;
	}
	/**
	* @ingroup math
	*/
	inline std::vector<std::wstring> GetTokens(const std::wstring& str, const std::wstring& delim) {
		std::vector<std::wstring> ret;
		GetTokensFunc(&ret, str, delim);
		return ret;
	}
	/**
	* @ingroup math
	*/
	inline std::vector<std::wstring> GetTokens(const std::wstring& str, wchar_t delim) {
		std::vector<std::wstring> ret;
		GetTokensFunc(&ret, str, std::wstring(1, delim));
		return ret;
	}
	/**
	* @ingroup math
	*/
	inline size_t GetTokensNum(const std::string& str, const std::string& delim) {
		return GetTokensFunc((std::vector<std::string>*)NULL, str, delim);
	}
	/**
	* @ingroup math
	*/
	inline size_t GetTokensNum(const std::string& str, char delim) {
		return GetTokensFunc((std::vector<std::string>*)NULL, str, std::string(1, delim));
	}
	/**
	* @ingroup math
	*/
	inline size_t GetTokensNum(const std::wstring& str, const std::wstring& delim) {
		return GetTokensFunc((std::vector<std::wstring>*)NULL, str, delim);
	}
	/**
	* @ingroup math
	*/
	inline size_t GetTokensNum(const std::wstring& str, wchar_t delim) {
		return GetTokensFunc((std::vector<std::wstring>*)NULL, str, std::wstring(1, delim));
	}
	/**
	* @ingroup math
	*/
	FileInfo FFW_API GetFileInfo(const std::string& path);
	/**
	* @ingroup math
	*/
	inline std::string Basename(const std::string& path) {
		return GetFileInfo(path).basename;
	}
	/**
	* @ingroup math
	*/
	inline std::string Dirname(const std::string& path) {
		return GetFileInfo(path).dirname;
	}
	/**
	* @ingroup math
	*/
	inline std::string Extension(const std::string& path) {
		return GetFileInfo(path).extension;
	}
	/**
	* @ingroup math
	*/
	inline std::string ToUpper(const std::string& str) {
		std::string copy(str);
		for (auto& c : copy) {
			c = toupper(c);
		}
		return copy;
	}
	/**
	* @ingroup math
	*/
	inline std::string ToLower(const std::string& str) {
		std::string copy(str);
		for (auto& c : copy) {
			c = tolower(c);
		}
		return copy;
	}
	/**
	* @ingroup math
	*/
	size_t FFW_API WstrToUtf8(std::string* Str, const std::wstring& Wstr);
	/**
	* @ingroup math
	*/
	inline std::string WstrToUtf8(const std::wstring& Wstr) {
		std::string str;
		str.resize(WstrToUtf8(NULL, Wstr));
		WstrToUtf8(&str, Wstr);
		return str;
	}
	/**
	* @ingroup math
	*/
	inline size_t WstrToUtf8Size(const std::wstring& Wstr) {
		return WstrToUtf8(NULL, Wstr);
	}
	/**
	* @ingroup math
	*/
	size_t FFW_API Utf8ToWstr(std::wstring* Wstr, const std::string& Str);
	/**
	* @ingroup math
	*/
	inline std::wstring Utf8ToWstr(const std::string& Str) {
		std::wstring wstr;
		wstr.resize(Utf8ToWstr(NULL, Str));
		Utf8ToWstr(&wstr, Str);
		return wstr;
	}
	/**
	* @ingroup math
	*/
	inline size_t Utf8ToWstrSize(const std::string& Str) {
		return Utf8ToWstr(NULL, Str);
	}
	/**
	* @ingroup math
	*/
	template <class T>
	inline std::wstring ValToWstring(T Value) {
		return Utf8ToWstr(ValToString(Value));
	}
	/**
	* @ingroup math
	*/
	template <class T>
	inline std::wstring ValToWstring(T Value, unsigned int Dec) {
		return Utf8ToWstr(ValToString(Value, Dec));
	}

#if defined(FFW_WINDOWS)
	/**
	* @ingroup math
	*/
	std::string FFW_API WstrToAnsi(const std::wstring& Str);
	/**
	* @ingroup math
	*/
	std::wstring FFW_API AnsiToWstr(const std::string& Str);
#endif
};
#endif
