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
	template <class T> inline T StringToVal(const std::string& str);
	template <> inline float                StringToVal<float>(const std::string& Str) { return std::stof(Str); }
	template <> inline double               StringToVal<double>(const std::string& Str) { return std::stod(Str); }
	template <> inline long double          StringToVal<long double>(const std::string& Str) { return std::stold(Str); }
	template <> inline short                StringToVal<short>(const std::string& Str) { return static_cast<short>(std::stoi(Str)); }
	template <> inline int                  StringToVal<int>(const std::string& Str) { return std::stoi(Str); }
	template <> inline long                 StringToVal<long>(const std::string& Str) { return std::stol(Str); }
	template <> inline long long            StringToVal<long long>(const std::string& Str) { return std::stoll(Str); }
	template <> inline unsigned short       StringToVal<unsigned short>(const std::string& Str) { return (unsigned short)std::stoul(Str); }
	template <> inline unsigned int         StringToVal<unsigned int>(const std::string& Str) { return std::stoul(Str); }
	template <> inline unsigned long        StringToVal<unsigned long>(const std::string& Str) { return std::stoul(Str); }
	template <> inline unsigned long long   StringToVal<unsigned long long>(const std::string& Str) { return std::stoull(Str); }
	
	template <class T>
	inline std::string ValToString(T Value) {
		return std::to_string(Value);
	}
	
	template <class T>
	inline std::string ValToString(T Value, unsigned int Dec) {
		std::ostringstream ostr;
		ostr.precision(Dec);
		ostr << std::fixed << Value;
		return ostr.str();
	}
	
	template <class T>
	inline std::wstring ValToWstring(T Value) {
		return Utf8ToWstr(ValToString(Value));
	}
	
	template <class T>
	inline std::wstring ValToWstring(T Value, unsigned int Dec) {
		return Utf8ToWstr(ValToString(Value, Dec));
	}
	
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
		
	inline std::vector<std::string> GetTokens(const std::string& str, const std::string& delim) {
		std::vector<std::string> ret;
		GetTokensFunc(&ret, str, delim);
		return ret;
	}

	inline std::vector<std::string> GetTokens(const std::string& str, char delim) {
		std::vector<std::string> ret;
		GetTokensFunc(&ret, str, std::string(1, delim));
		return ret;
	}

	inline std::vector<std::wstring> GetTokens(const std::wstring& str, const std::wstring& delim) {
		std::vector<std::wstring> ret;
		GetTokensFunc(&ret, str, delim);
		return ret;
	}

	inline std::vector<std::wstring> GetTokens(const std::wstring& str, wchar_t delim) {
		std::vector<std::wstring> ret;
		GetTokensFunc(&ret, str, std::wstring(1, delim));
		return ret;
	}

	inline size_t GetTokensNum(const std::string& str, const std::string& delim) {
		return GetTokensFunc((std::vector<std::string>*)NULL, str, delim);
	}

	inline size_t GetTokensNum(const std::string& str, char delim) {
		return GetTokensFunc((std::vector<std::string>*)NULL, str, std::string(1, delim));
	}

	inline size_t GetTokensNum(const std::wstring& str, const std::wstring& delim) {
		return GetTokensFunc((std::vector<std::wstring>*)NULL, str, delim);
	}

	inline size_t GetTokensNum(const std::wstring& str, wchar_t delim) {
		return GetTokensFunc((std::vector<std::wstring>*)NULL, str, std::wstring(1, delim));
	}
	
	inline FileInfo GetFileInfo(const std::string& path) {
		if (path.size() == 0)return FileInfo();

		std::string basename;
		std::string dirname;
		std::string extension;

		size_t slash = std::min(path.find_last_of('\\'), path.find_last_of('/'));
		if (slash == std::string::npos) {
			// Check if drive
			if (path.size() == 2 && path[1] == ':') {
				dirname = path;
			}
			else {
				// Split name only
				size_t dot = path.find_last_of('.');

				if (dot == std::string::npos) {
					basename = path;

				}
				else {
					basename = path.substr(0, dot);
					extension = path.substr(dot + 1, path.size() - dot - 1);
				}
			}
		}
		else {
			// Split dir and name
			dirname = path.substr(0, slash + 1);
			size_t dot = path.find_last_of('.');

			if (dot != std::string::npos && dot > slash) {
				if (dot == slash + 1) {
					basename = path.substr(slash + 1, path.size() - slash - 1);
				}
				else {
					basename = path.substr(slash + 1, path.size() - slash - 1 - (path.size() - dot - 1) - 1);
					extension = path.substr(dot + 1, path.size() - dot - 1);
				}
			}
			else {
				basename = path.substr(slash + 1, path.size() - slash - 1);
			}
		}

		return FileInfo(basename, dirname, extension);
	}

	
	inline std::string Basename(const std::string& path) {
		return GetFileInfo(path).basename;
	}

	
	inline std::string Dirname(const std::string& path) {
		return GetFileInfo(path).dirname;
	}

	
	inline std::string Extension(const std::string& path) {
		return GetFileInfo(path).extension;
	}

	
	inline std::string ToUpper(const std::string& str) {
		std::string copy(str);
		for (auto& c : copy) {
			c = toupper(c);
		}
		return copy;
	}

	
	inline std::string ToLower(const std::string& str) {
		std::string copy(str);
		for (auto& c : copy) {
			c = tolower(c);
		}
		return copy;
	}

	inline size_t WstrToUtf8(std::string* Str, const std::wstring& Wstr) {
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

	inline std::string WstrToUtf8(const std::wstring& Wstr) {
		std::string str;
		str.resize(WstrToUtf8(NULL, Wstr));
		WstrToUtf8(&str, Wstr);
		return str;
	}
	
	inline size_t WstrToUtf8Size(const std::wstring& Wstr) {
		return WstrToUtf8(NULL, Wstr);
	}

	inline size_t Utf8ToWstr(std::wstring* Wstr, const std::string& Str) {
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
	
	inline std::wstring Utf8ToWstr(const std::string& Str) {
		std::wstring wstr;
		wstr.resize(Utf8ToWstr(NULL, Str));
		Utf8ToWstr(&wstr, Str);
		return wstr;
	}
	
	inline size_t Utf8ToWstrSize(const std::string& Str) {
		return Utf8ToWstr(NULL, Str);
	}

#if defined(FFW_WINDOWS)
	inline std::string WstrToAnsi(const std::wstring& Str) {
		int size = WideCharToMultiByte(CP_ACP, 0, Str.c_str(), Str.size(), NULL, 0, NULL, NULL);
		std::string out(size, ' ');
		WideCharToMultiByte(CP_ACP, 0, Str.c_str(), Str.size(), &out[0], size, 0, 0);
		return out;
	}
	
	inline std::wstring AnsiToWstr(const std::string& Str) {
		int size = MultiByteToWideChar(CP_ACP, 0, Str.c_str(), Str.size(), NULL, 0);
		std::wstring out(size, L' ');
		MultiByteToWideChar(CP_ACP, 0, Str.c_str(), Str.size(), &out[0], size);
		return out;
	}
#endif
};
#endif
