/* This file is part of FineFramework project */
#ifndef FFW_STRING_MATH
#define FFW_STRING_MATH

#include <string>

namespace ffw{
	/**
	 * @ingroup math
	 */
	template<class T>
	class FileInfo {
	public:
		FileInfo(){
		}
		FileInfo(const T& name, const T& dir, const T& ext):
			base(name),dir(dir),ext(ext){
		}
		const T base;
		const T dir;
		const T ext;
	};
	/**
	* @ingroup math
	* @exception Throws std::invalid_argument (invalid conversion) 
	* or std::out_of_range (conversion is out of the range)
	*/
	template <class T> inline T stringToVal(const std::string& str);
	/**
	* @ingroup math
	*/
	template <> inline float                stringToVal<float>(const std::string& Str) { return std::stof(Str); }
	/**
	* @ingroup math
	*/
	template <> inline double               stringToVal<double>(const std::string& Str) { return std::stod(Str); }
	/**
	* @ingroup math
	*/
	template <> inline long double          stringToVal<long double>(const std::string& Str) { return std::stold(Str); }
	/**
	* @ingroup math
	*/
	template <> inline short                stringToVal<short>(const std::string& Str) { return static_cast<short>(std::stoi(Str)); }
	/**
	* @ingroup math
	*/
	template <> inline int                  stringToVal<int>(const std::string& Str) { return std::stoi(Str); }
	/**
	* @ingroup math
	*/
	template <> inline long                 stringToVal<long>(const std::string& Str) { return std::stol(Str); }
	/**
	* @ingroup math
	*/
	template <> inline long long            stringToVal<long long>(const std::string& Str) { return std::stoll(Str); }
	/**
	* @ingroup math
	*/
	template <> inline unsigned short       stringToVal<unsigned short>(const std::string& Str) { return (unsigned short)std::stoul(Str); }
	/**
	* @ingroup math
	*/
	template <> inline unsigned int         stringToVal<unsigned int>(const std::string& Str) { return std::stoul(Str); }
	/**
	* @ingroup math
	*/
	template <> inline unsigned long        stringToVal<unsigned long>(const std::string& Str) { return std::stoul(Str); }
	/**
	* @ingroup math
	*/
	template <> inline unsigned long long   stringToVal<unsigned long long>(const std::string& Str) { return std::stoull(Str); }
	/**
	* @ingroup math
	*/
	template <class T>
	inline std::string valToString(T Value) {
		return std::to_string(Value);
	}
	/**
	* @ingroup math
	*/
	template <class T>
	inline std::string valToString(T Value, unsigned int Dec) {
		std::ostringstream ostr;
		ostr.precision(Dec);
		ostr << std::fixed << Value;
		return ostr.str();
	}
	/**
	* @ingroup math
	*/
	template<typename T>
	inline T hexToVal(const std::string& Str) {
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
	inline std::string valToHex(const T& Value) {
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
	size_t getTokensFunc(
			std::vector<std::basic_string<T, CharTrait, Allocator>>* vec,
			const std::basic_string<T, CharTrait, Allocator>& str,
			const std::basic_string<T, CharTrait, Allocator>& delim) {
		Tokenizer<T> tokenizer(str, delim);
		std::basic_string<T, CharTrait, Allocator> temp;
		size_t cnt = 0;
		if (vec != NULL) {
			while (tokenizer.getNext(&temp)) {
				vec->push_back(temp);
				cnt++;
			}
		}
		else {
			while (tokenizer.skipNext()) {
				cnt++;
			}
		}
		return cnt;
	}
	/**
	* @ingroup math
	*/
	inline std::vector<std::string> getTokens(const std::string& str, const std::string& delim) {
		std::vector<std::string> ret;
		getTokensFunc(&ret, str, delim);
		return ret;
	}
	/**
	* @ingroup math
	*/
	inline std::vector<std::string> getTokens(const std::string& str, char delim) {
		std::vector<std::string> ret;
		getTokensFunc(&ret, str, std::string(1, delim));
		return ret;
	}
	/**
	* @ingroup math
	*/
	inline std::vector<std::wstring> getTokens(const std::wstring& str, const std::wstring& delim) {
		std::vector<std::wstring> ret;
		getTokensFunc(&ret, str, delim);
		return ret;
	}
	/**
	* @ingroup math
	*/
	inline std::vector<std::wstring> getTokens(const std::wstring& str, wchar_t delim) {
		std::vector<std::wstring> ret;
		getTokensFunc(&ret, str, std::wstring(1, delim));
		return ret;
	}
	/**
	* @ingroup math
	*/
	inline size_t getTokensNum(const std::string& str, const std::string& delim) {
		return getTokensFunc((std::vector<std::string>*)NULL, str, delim);
	}
	/**
	* @ingroup math
	*/
	inline size_t getTokensNum(const std::string& str, char delim) {
		return getTokensFunc((std::vector<std::string>*)NULL, str, std::string(1, delim));
	}
	/**
	* @ingroup math
	*/
	inline size_t getTokensNum(const std::wstring& str, const std::wstring& delim) {
		return getTokensFunc((std::vector<std::wstring>*)NULL, str, delim);
	}
	/**
	* @ingroup math
	*/
	inline size_t getTokensNum(const std::wstring& str, wchar_t delim) {
		return getTokensFunc((std::vector<std::wstring>*)NULL, str, std::wstring(1, delim));
	}
	/**
	* @ingroup math
	*/
	template<class T, typename CharTrait = std::char_traits<T>, typename Allocator = std::allocator<T>>
	FileInfo<std::basic_string<T, CharTrait, Allocator>> getFileInfo(const std::basic_string<T, CharTrait, Allocator>& path) {
		if (path.size() == 0)return FileInfo<std::basic_string<T, CharTrait, Allocator>>();

		std::basic_string<T, CharTrait, Allocator> base;
		std::basic_string<T, CharTrait, Allocator> dir;
		std::basic_string<T, CharTrait, Allocator> ext;

		size_t slash = std::min(path.find_last_of(T('\\')), path.find_last_of(T('/')));
		if (slash == std::string::npos) {
			// Check if drive
			if (path.size() == 2 && path[1] == T(':')) {
				dir = path;
			}
			else {
				// Split name only
				size_t dot = path.find_last_of(T('.'));

				if (dot == std::basic_string<T, CharTrait, Allocator>::npos) {
					base = path;

				}
				else {
					base = path.substr(0, dot);
					ext = path.substr(dot + 1, path.size() - dot - 1);
				}
			}
		}
		else {
			// Split dir and name
			dir = path.substr(0, slash + 1);
			size_t dot = path.find_last_of(T('.'));

			if (dot != std::basic_string<T, CharTrait, Allocator>::npos && dot > slash) {
				if (dot == slash + 1) {
					base = path.substr(slash + 1, path.size() - slash - 1);
				}
				else {
					base = path.substr(slash + 1, path.size() - slash - 1 - (path.size() - dot - 1) - 1);
					ext = path.substr(dot + 1, path.size() - dot - 1);
				}
			}
			else {
				base = path.substr(slash + 1, path.size() - slash - 1);
			}
		}

		return FileInfo<std::basic_string<T, CharTrait, Allocator>>(base, dir, ext);
	}
	/**
	* @ingroup math
	*/
	template<class T, typename CharTrait = std::char_traits<T>, typename Allocator = std::allocator<T>>
	std::string basename(const std::basic_string<T, CharTrait, Allocator>& path) {
		return getFileInfo(path).base;
	}
	/**
	* @ingroup math
	*/
	template<class T, typename CharTrait = std::char_traits<T>, typename Allocator = std::allocator<T>>
	std::string dirname(const std::basic_string<T, CharTrait, Allocator>& path) {
		return getFileInfo(path).dir;
	}
	/**
	* @ingroup math
	*/
	template<class T, typename CharTrait = std::char_traits<T>, typename Allocator = std::allocator<T>>
	std::string extension(const std::basic_string<T, CharTrait, Allocator>& path) {
		return getFileInfo(path).ext;
	}
	/**
	* @ingroup math
	*/
	inline std::string toUpper(const std::string& str) {
		std::string copy(str);
		for (auto& c : copy) {
			c = toupper(c);
		}
		return copy;
	}
	/**
	* @ingroup math
	*/
	inline std::string toLower(const std::string& str) {
		std::string copy(str);
		for (auto& c : copy) {
			c = tolower(c);
		}
		return copy;
	}
	/**
	* @ingroup math
	*/
	template<class SS, class WS>
	size_t wstrToUtf8(SS * Str, const WS& Wstr) {
		size_t total = 0;
		for (size_t i = 0; i < Wstr.size(); i++) {
			const auto& w = Wstr[i];
			// Only byte sequence
			if (w <= 0x007F) {
				if (Str != NULL && Str->size() > total) {
					(*Str)[total + 0] = char(w & 0x007F);
				}
				total += 1;
			}
			// Two byte sequence
			else if (w <= 0x7FF) {
				if (Str != NULL && Str->size() > total + 1) {
					(*Str)[total + 0] = 0xC0 | char((w & 0x0FC0) >> 6);
					(*Str)[total + 1] = 0x80 | char((w & 0x003F));
				}
				total += 2;
			}
			// Three byte sequence
			else if (w <= 0xFFFF) {
				if (Str != NULL && Str->size() > total + 2) {
					(*Str)[total + 0] = 0xE0 | char((w & 0xF000) >> 12);
					(*Str)[total + 1] = 0x80 | char((w & 0x0FC0) >> 6);
					(*Str)[total + 2] = 0x80 | char((w & 0x003F));
				}
				total += 3;
			}
			// Four byte sequence
			else if (w <= 0x1FFFFF) {
				if (Str != NULL && Str->size() > total + 3) {
					(*Str)[total + 0] = 0xF0 | char((w & 0x1C0000) >> 18);
					(*Str)[total + 1] = 0x80 | char((w & 0x03F000) >> 12);
					(*Str)[total + 2] = 0x80 | char((w & 0x000FC0) >> 6);
					(*Str)[total + 3] = 0x80 | char((w & 0x00003F));
				}
				total += 4;
			}
			// Five byte sequence
			else if (w <= 0x3FFFFFF) {
				if (Str != NULL && Str->size() > total + 3) {
					(*Str)[total + 0] = 0xF8 | char((w & 0x3000000) >> 24);
					(*Str)[total + 1] = 0x80 | char((w & 0x0FC0000) >> 18);
					(*Str)[total + 2] = 0x80 | char((w & 0x003F000) >> 12);
					(*Str)[total + 3] = 0x80 | char((w & 0x0000FC0) >> 6);
					(*Str)[total + 4] = 0x80 | char((w & 0x000003F));
				}
				total += 5;
			}
			// Six byte sequence
			else if (w <= 0x7FFFFFFF) {
				if (Str != NULL && Str->size() > total + 3) {
					(*Str)[total + 0] = 0xFC | char((w & 0x40000000) >> 30);
					(*Str)[total + 1] = 0x80 | char((w & 0x3F000000) >> 24);
					(*Str)[total + 2] = 0x80 | char((w & 0x00FC0000) >> 18);
					(*Str)[total + 3] = 0x80 | char((w & 0x0003F000) >> 12);
					(*Str)[total + 4] = 0x80 | char((w & 0x00000FC0) >> 6);
					(*Str)[total + 5] = 0x80 | char((w & 0x0000003F));
				}
				total += 6;
			}
		}
		return total;
	}
	/**
	* @ingroup math
	*/
	template<class WS, class SS>
	size_t utf8ToWstr(WS* Wstr, const SS& Str) {
		size_t total = 0;
		wchar_t w = 0;
		unsigned char bytes = 0;
		unsigned char sequence = 0;
		for (size_t i = 0; i < Str.size(); i++) {
			const auto& c = Str[i];
			// One byte in the sequence...
			if (!(c & 0x80)) {
				bytes = 0;
				sequence = 0;
				//w = c;
			}
			// Multiple bytes in the sequence...
			else {
				unsigned char b = 0x80;
				bytes = 0;
				while ((c & b) && bytes < 8) {
					bytes++;
					b = b >> 1;
				}
				if (bytes > 1)sequence = bytes;
			}
			// First byte 110x xxxx sequence of two bytes
			if (bytes == 2 && sequence == 2) {
				w = (c & 0x1F) << 6;
				sequence--;
			}
			// First byte 1110 xxxx  sequence of three bytes
			else if (bytes == 3 && sequence == 3) {
				w = (c & 0x0F) << 12;
				sequence--;
			}
			// First byte 1111 0xxx  sequence of four bytes
			else if (bytes == 4 && sequence == 4) {
				w = (c & 0x07) << 18;
				sequence--;
			}
			// First byte 1111 10xx  sequence of five bytes
			else if (bytes == 5 && sequence == 5) {
				w = (c & 0x03) << 24;
				sequence--;
			}
			// First byte 1111 110x  sequence of six bytes
			else if (bytes == 6 && sequence == 6) {
				w = (c & 0x01) << 30;
				sequence--;
			}
			// Continuing byte 10xx xxxx
			else if (bytes == 1 && sequence > 0) {
				w |= (c & 0x3F) << ((sequence - 1) * 6);
				sequence--;
				// We have reached the end of the sequence
				if (sequence == 0) {
					if (Wstr != NULL && Wstr->size() > total) {
						(*Wstr)[total] = w;
					}
					total++;
				}
			}
			// No sequence
			else {
				w = c;
				if (Wstr != NULL && Wstr->size() > total) {
					(*Wstr)[total] = w;
				}
				total++;
				//wstr.push_back(w);
			}
		}
		return total;
	}
	/**
	* @ingroup math
	*/
	inline std::string wstrToUtf8(const std::wstring& Wstr) {
		std::string str;
		str.resize(wstrToUtf8((std::string*)NULL, Wstr));
		wstrToUtf8(&str, Wstr);
		return str;
	}
	/**
	* @ingroup math
	*/
	inline size_t wstrToUtf8Size(const std::wstring& Wstr) {
		return wstrToUtf8((std::string*)NULL, Wstr);
	}
	/**
	* @ingroup math
	*/
	inline std::wstring utf8ToWstr(const std::string& Str) {
		std::wstring wstr;
		wstr.resize(utf8ToWstr((std::wstring*)NULL, Str));
		utf8ToWstr(&wstr, Str);
		return wstr;
	}
	/**
	* @ingroup math
	*/
	inline size_t utf8ToWstrSize(const std::string& Str) {
		return utf8ToWstr((std::wstring*)NULL, Str);
	}
	/**
	* @ingroup math
	*/
	template <class T>
	inline std::wstring valToWstring(T Value) {
		return utf8ToWstr(valToString(Value));
	}
	/**
	* @ingroup math
	*/
	template <class T>
	inline std::wstring valToWstring(T Value, unsigned int Dec) {
		return utf8ToWstr(valToString(Value, Dec));
	}

#if defined(FFW_WINDOWS)
	/**
	* @ingroup math
	*/
	inline std::string wstrToAnsi(const std::wstring& Str) {
		auto size = WideCharToMultiByte(CP_ACP, 0, Str.c_str(), (int)Str.size(), NULL, 0, NULL, NULL);
		std::string out(size, ' ');
		WideCharToMultiByte(CP_ACP, 0, Str.c_str(), (int)Str.size(), &out[0], (int)size, 0, 0);
		return out;
	}
	/**
	* @ingroup math
	*/
	inline std::wstring ansiToWstr(const std::string& Str) {
		auto size = MultiByteToWideChar(CP_ACP, 0, Str.c_str(), (int)Str.size(), NULL, 0);
		std::wstring out(size, L' ');
		MultiByteToWideChar(CP_ACP, 0, Str.c_str(), (int)Str.size(), &out[0], (int)size);
		return out;
	}
#endif
};
#endif
