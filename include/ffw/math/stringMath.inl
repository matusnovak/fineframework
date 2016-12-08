/* This file is part of FineFramework project */
#ifdef FFW_ANDROID
//==============================================================================
template <> inline float                ffw::StringToVal<float>              (const std::string& Str){return static_cast<float>(atof(Str.c_str()));}
template <> inline double               ffw::StringToVal<double>             (const std::string& Str){return atof(Str.c_str());}
template <> inline long double          ffw::StringToVal<long double>        (const std::string& Str){return static_cast<long double>(atof(Str.c_str()));}
template <> inline short                ffw::StringToVal<short>              (const std::string& Str){return static_cast<short>(atoi(Str.c_str()));}
template <> inline int                  ffw::StringToVal<int>                (const std::string& Str){return atoi(Str.c_str());}
template <> inline long                 ffw::StringToVal<long>               (const std::string& Str){return atol(Str.c_str());}
template <> inline long long            ffw::StringToVal<long long>          (const std::string& Str){return atoll(Str.c_str());}
template <> inline unsigned short       ffw::StringToVal<unsigned short>     (const std::string& Str){return static_cast<unsigned short>(atoi(Str.c_str()));}
template <> inline unsigned int         ffw::StringToVal<unsigned int>       (const std::string& Str){return static_cast<unsigned int>(atoi(Str.c_str()));}
template <> inline unsigned long        ffw::StringToVal<unsigned long>      (const std::string& Str){return static_cast<unsigned short>(atol(Str.c_str()));}
template <> inline unsigned long long   ffw::StringToVal<unsigned long long> (const std::string& Str){return static_cast<unsigned long long>(atoll(Str.c_str()));}
#else
//==============================================================================
template <> inline float                ffw::StringToVal<float>              (const std::string& Str){return std::stof(Str);}
template <> inline double               ffw::StringToVal<double>             (const std::string& Str){return std::stod(Str);}
template <> inline long double          ffw::StringToVal<long double>        (const std::string& Str){return std::stold(Str);}
template <> inline short                ffw::StringToVal<short>              (const std::string& Str){return static_cast<short>(std::stoi(Str));}
template <> inline int                  ffw::StringToVal<int>                (const std::string& Str){return std::stoi(Str);}
template <> inline long                 ffw::StringToVal<long>               (const std::string& Str){return std::stol(Str);}
template <> inline long long            ffw::StringToVal<long long>          (const std::string& Str){return std::stoll(Str);}
template <> inline unsigned short       ffw::StringToVal<unsigned short>     (const std::string& Str){return (unsigned short)std::stoul(Str);}
template <> inline unsigned int         ffw::StringToVal<unsigned int>       (const std::string& Str){return std::stoul(Str);}
template <> inline unsigned long        ffw::StringToVal<unsigned long>      (const std::string& Str){return std::stoul(Str);}
template <> inline unsigned long long   ffw::StringToVal<unsigned long long> (const std::string& Str){return std::stoull(Str);}
#endif
//==============================================================================
template <class T>
inline std::string ffw::ValToString(T Value){
#ifdef FFW_ANDROID
    std::ostringstream ostr;
    ostr << Value;
    return ostr.str();
#else
	return std::to_string(Value);
#endif
}
//==============================================================================
template <class T>
inline std::string ffw::ValToString(T Value, unsigned int Dec){
    std::ostringstream ostr;
    ostr.precision(Dec);
    ostr << std::fixed << Value;
    return ostr.str();
}
//==============================================================================
template <class T> 
inline std::wstring ffw::ValToWstring(T Value){
	return Utf8ToWstr(ValToString(Value));
}
//==============================================================================
template <class T> 
inline std::wstring ffw::ValToWstring(T Value, unsigned int Dec){
	return Utf8ToWstr(ValToString(Value, Dec));
}
//==============================================================================
template<typename T>
inline T ffw::HexToVal(const std::string& Str) {
#ifdef FFW_ANDROID
	/*// 0000
	size_t pos = 0;
	// 0x0000
	if(Str.size() > 2 && Str[0] == '0' && (Str[1] == 'x' || Str[1] == 'X'))pos = 2;
	// x0000
	else if(Str.size() > 1 && (Str[0] == 'x' || Str[0] == 'X'))pos = 1;
	T value = 0;
	for(size_t i = pos; i < Str.size(); i++){
		if(i-pos >= sizeof(T)*2)continue;
		value
	}*/
	return 0;
#else
    try {
        return std::stoul(Str, nullptr, 16);
    } catch (std::invalid_argument e){
        return 0;
    } catch (std::out_of_range e){
        return 0;
    }
    return 0;
#endif
}
//==============================================================================
template<typename T>
inline std::string ffw::ValToHex(const T& Value) {
	static const char chars[16] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'a', 'b', 'c', 'd', 'e', 'f'};
	std::string str;
	str.resize(sizeof(T)*2);
	for(size_t i = 0; i < sizeof(T)*2; i++){
		char c = (Value >> (i*4));
		c = c & 0x0F;
		str[sizeof(T)*2 - i -1] = chars[int(c)];
	}
	return str;
}
//==============================================================================
template<class T>
inline std::vector<T> ffw::GetTokens(const T& Line, char Delim){
    std::vector<T> vec;
    T temp;
    for(unsigned int i = 0; i < Line.size(); i++){
        if(Line[i] != Delim)temp += Line[i];
        else if(temp.size() > 0){
            vec.push_back(temp);
            temp = T();
        }
        if(i == Line.size()-1 && Line[i] != Delim)vec.push_back(temp);
    }
    return vec;
}
//==============================================================================
template<class T>
inline unsigned int ffw::GetTokensNum(const T& Line, char Delim){
    int num = 0;
	int temp = 0;
    for(unsigned int i = 0; i < Line.size(); i++){
        if(Line[i] != Delim)temp++;
		else if(temp > 0){
            num++;
            temp = 0;
        }
        if(i == Line.size()-1 && Line[i] != Delim)num++;
    }
    return num;
}
#if defined(FFW_WINDOWS)
#ifndef NOMINMAX
#define NOMINMAX
#endif
#include <Windows.h>
//==============================================================================
inline std::string ffw::WstrToAnsi(const std::wstring& Str){
    int size = WideCharToMultiByte(CP_ACP, 0, Str.c_str(), Str.size(), NULL, 0, NULL, NULL);
    std::string out(size, ' ');
    WideCharToMultiByte(CP_ACP, 0, Str.c_str(), Str.size(), &out[0], size, 0, 0);
    return out;
}
//==============================================================================
inline std::wstring ffw::AnsiToWstr(const std::string& Str){
    int size = MultiByteToWideChar(CP_ACP, 0, Str.c_str(), Str.size(), NULL, 0);
    std::wstring out(size, L' ');
    MultiByteToWideChar(CP_ACP, 0, Str.c_str(), Str.size(), &out[0], size);
    return out;
}
#endif
//==============================================================================
inline size_t WstrToUtf8Func(std::string* Str, const std::wstring& Wstr){
	size_t total = 0;
	for(size_t i = 0; i < Wstr.size(); i++){
		const auto& w = Wstr[i];
		// Only byte sequence
		if(w <= 0x007F){
			if(Str != NULL && Str->size() > total){
				(*Str)[total + 0] = char(w & 0x007F);
			}
			total += 1;
		}
		// Two byte sequence
		else if(w <= 0x7FF){
			if(Str != NULL && Str->size() > total+1){
				(*Str)[total + 0] = 0xC0 | char((w & 0x0FC0) >> 6);
				(*Str)[total + 1] = 0x80 | char((w & 0x003F));
			}
			total += 2;
		}
		// Three byte sequence
		else if(w <= 0xFFF){
			if(Str != NULL && Str->size() > total+2){
				(*Str)[total + 0] = 0xE0 | char((w & 0xF000) >> 12);
				(*Str)[total + 1] = 0x80 | char((w & 0x0FC0) >> 6);
				(*Str)[total + 2] = 0x80 | char((w & 0x003F));
			}
			total += 3;
		}
		// Four byte sequence
		else if(w <= 0x1FFFFF){
			if(Str != NULL && Str->size() > total+3){
				(*Str)[total + 0] = 0xF0 | char((w & 0x1C0000) >> 18);
				(*Str)[total + 1] = 0x80 | char((w & 0x03F000) >> 12);
				(*Str)[total + 2] = 0x80 | char((w & 0x000FC0) >> 6);
				(*Str)[total + 3] = 0x80 | char((w & 0x00003F));
			}
			total += 4;
		}
		// Five byte sequence
		else if(w <= 0x3FFFFFF){
			if(Str != NULL && Str->size() > total+3){
				(*Str)[total + 0] = 0xF8 | char((w & 0x3000000) >> 24);
				(*Str)[total + 1] = 0x80 | char((w & 0x0FC0000) >> 18);
				(*Str)[total + 2] = 0x80 | char((w & 0x003F000) >> 12);
				(*Str)[total + 3] = 0x80 | char((w & 0x0000FC0) >> 6);
				(*Str)[total + 4] = 0x80 | char((w & 0x000003F));
			}
			total += 5;
		}
		// Six byte sequence
		else if(w <= 0x7FFFFFFF){
			if(Str != NULL && Str->size() > total+3){
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
//==============================================================================
inline std::string ffw::WstrToUtf8(const std::wstring& Wstr){
    std::string str;
	str.resize(WstrToUtf8Func(NULL, Wstr));
	WstrToUtf8Func(&str, Wstr);
	return str;
}
//==============================================================================
inline size_t ffw::WstrToUtf8Size(const std::wstring& Wstr){
    return WstrToUtf8Func(NULL, Wstr);
}
//==============================================================================
inline size_t Utf8ToWstrFunc(std::wstring* Wstr, const std::string& Str){
	size_t total = 0;
	wchar_t w = 0;
	unsigned char bytes = 0;
	unsigned char sequence = 0;
	for(size_t i = 0; i < Str.size(); i++){
		const auto& c = Str[i];
		// One byte in the sequence...
		if(!(c & 0x80)){
			bytes = 0;
			sequence = 0;
			//w = c;
		}
		// Multiple bytes in the sequence...
		else {
			unsigned char b = 0x80;
			bytes = 0;
			while((c & b) && bytes < 8){
				bytes++;
				b = b >> 1;
			}
			if(bytes > 1)sequence = bytes;
		}
		// First byte 110x xxxx sequence of two bytes
		if(bytes == 2 && sequence == 2){
			w = (c & 0x1F) << 6;
			sequence--;
		}
		// First byte 1110 xxxx  sequence of three bytes
		else if(bytes == 3 && sequence == 3){
			w = (c & 0x0F) << 12;
			sequence--;
		}
		// First byte 1111 0xxx  sequence of four bytes
		else if(bytes == 4 && sequence == 4){
			w = (c & 0x07) << 18;
			sequence--;
		}
		// First byte 1111 10xx  sequence of five bytes
		else if(bytes == 5 && sequence == 5){
			w = (c & 0x03) << 24;
			sequence--;
		}
		// First byte 1111 110x  sequence of six bytes
		else if(bytes == 6 && sequence == 6){
			w = (c & 0x01) << 30;
			sequence--;
		}
		// Continuing byte 10xx xxxx
		else if(bytes == 1 && sequence > 0){
			w |= (c & 0x3F) << ((sequence-1) * 6);
			sequence--;
			// We have reached the end of the sequence
			if(sequence == 0){
				if(Wstr != NULL && Wstr->size() > total){
					(*Wstr)[total] = w;
				}
				total++;
			}
		}
		// No sequence
		else {
			w = c;
			if(Wstr != NULL && Wstr->size() > total){
				(*Wstr)[total] = w;
			}
			total++;
			//wstr.push_back(w);
		}
	}
	return total;
}
//==============================================================================
inline std::wstring ffw::Utf8ToWstr(const std::string& Str){
	std::wstring wstr;
	wstr.resize(Utf8ToWstrFunc(NULL, Str));
	Utf8ToWstrFunc(&wstr, Str);
	return wstr;
}
//==============================================================================
inline size_t ffw::Utf8ToWstrSize(const std::string& Str){
	return Utf8ToWstrFunc(NULL, Str);
}

//==============================================================================
ffw::FileInfo ffw::GetFileInfo(const std::string& path){
	if(path.size() == 0)return ffw::FileInfo();

	std::string basename;
	std::string dirname;
	std::string extension;

	size_t slash = std::min(path.find_last_of('\\'), path.find_last_of('/'));
	if(slash == std::string::npos){
		// Check if drive
		if(path.size() == 2 && path[1] == ':'){
			dirname = path;
		} else {
			// Split name only
			size_t dot = path.find_last_of('.');

			if(dot == std::string::npos){
				basename = path;

			} else {
				basename = path.substr(0, dot);
				extension = path.substr(dot + 1, path.size() - dot - 1);
			}
		}
	} else {
		// Split dir and name
		dirname = path.substr(0, slash+1);
		size_t dot = path.find_last_of('.');

		if(dot != std::string::npos && dot > slash){
			if(dot == slash+1){
				basename = path.substr(slash+1, path.size() - slash -1);
			} else {
				basename = path.substr(slash+1, path.size() - slash -1 - (path.size() - dot - 1) -1);
				extension = path.substr(dot + 1, path.size() - dot -1);
			}
		} else {
			basename = path.substr(slash+1, path.size() - slash -1);
		}
	}

	return ffw::FileInfo(basename, dirname, extension);
}

//==============================================================================
inline std::string ffw::Basename(const std::string& path){
	return GetFileInfo(path).basename;
}

//==============================================================================
inline std::string ffw::Dirname(const std::string& path){
	return GetFileInfo(path).dirname;
}

//==============================================================================
inline std::string ffw::Extension(const std::string& path){
	return GetFileInfo(path).extension;
}

//==============================================================================
inline std::string ffw::ToUpper(const std::string& str){
	std::string copy(str);
	for(auto& c : copy){
		c = toupper(c);
	}
	return copy;
}

//==============================================================================
inline std::string ffw::ToLower(const std::string& str){
	std::string copy(str);
	for(auto& c : copy){
		c = tolower(c);
	}
	return copy;
}