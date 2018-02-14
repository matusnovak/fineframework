/* This file is part of FineFramework project */
#ifndef FFW_STRING_MATH
#define FFW_STRING_MATH
#include "../config.h"
#include "third_party/utfcpp/checked.h"
#include "tokenizer.h"
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <stdexcept>
#include <cstdint>

namespace ffw {
    /**
     * @ingroup math
     */
    template<class T>
    class FileInfo {
    public:
        FileInfo() {
        }
        FileInfo(const T& name, const T& dir, const T& ext) :
            base(name), dir(dir), ext(ext) {
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
            char c = char(Value >> (i * 4));
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

        size_t back = std::min(path.find_last_of(T('\\')), std::basic_string<T, CharTrait, Allocator>::npos);
        size_t slash = std::min(path.find_last_of(T('/')), std::basic_string<T, CharTrait, Allocator>::npos);
        if (slash < back && back != std::basic_string<T, CharTrait, Allocator>::npos)slash = back;
        if (slash == std::basic_string<T, CharTrait, Allocator>::npos)slash = back;

        //size_t slash = std::min(path.find_last_of(T('\\')), path.find_last_of(T('/')));
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
            c = static_cast<char>(toupper(c));
        }
        return copy;
    }
    /**
    * @ingroup math
    */
    inline std::string toLower(const std::string& str) {
        std::string copy(str);
        for (auto& c : copy) {
            c = static_cast<char>(tolower(c));
        }
        return copy;
    }
    /**
    * @ingroup math
    */
    inline std::string unicodeToUtf8(uint32_t chr) {
        std::string result;
        utf8::utf32to8(&chr, &chr + 1, std::back_inserter(result)); // Well I hope the chr won't get bigger than 0x7FFFFFFF
        return result;
    }
    /**
    * @ingroup math
    */
    inline std::string wstrToUtf8(const std::wstring& wstr) {
        std::string str;
        utf8::utf16to8(&wstr[0], &wstr[0] + wstr.size(), std::back_inserter(str));
        return str;
    }
    /**
    * @ingroup math
    */
    inline size_t wstrToUtf8Size(const std::wstring& wstr) {
        // Taken from utf16to8() func https://github.com/nemtrif/utfcpp/blob/master/source/utf8/checked.h
        auto start = &wstr[0];
        auto end = &wstr[0] + wstr.size();
        size_t result = 0;
        while (start != end) {
            uint32_t cp = utf8::internal::mask16(*start++);
            // Take care of surrogate pairs first
            if (utf8::internal::is_lead_surrogate(cp)) {
                if (start != end) {
                    const uint32_t trail_surrogate = utf8::internal::mask16(*start++);
                    if (utf8::internal::is_trail_surrogate(trail_surrogate))
                        cp = (cp << 10) + trail_surrogate + utf8::internal::SURROGATE_OFFSET;
                    else
                        throw utf8::invalid_utf16(static_cast<uint16_t>(trail_surrogate));
                }
                else
                    throw utf8::invalid_utf16(static_cast<uint16_t>(cp));

            }
            // Lone trail surrogate
            else if (utf8::internal::is_trail_surrogate(cp))
                throw utf8::invalid_utf16(static_cast<uint16_t>(cp));

            result++;
        }
        return result;
    }
    /**
    * @ingroup math
    */
    inline std::wstring utf8ToWstr(const std::string& str) {
        std::wstring wstr;
        size_t dist = utf8::distance(&str[0], &str[0] + str.size());
        wstr.reserve(dist);
        utf8::utf8to16(&str[0], &str[0] + str.size(), std::back_inserter(wstr));
        return wstr;
    }
    /**
    * @ingroup math
    */
    inline size_t utf8ToWstrSize(const std::string& str) {
        return utf8::distance(&str[0], &str[0] + str.size());
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
    /**
    * @ingroup math
    */
    template<class T>
    inline uint32_t getNextChar(const T*& it, const T* end);
    /**
    * @ingroup math
    */
    template<>
    inline uint32_t getNextChar(const char*& it, const char* end) {
        return utf8::next(it, end);
    }
    /**
    * @ingroup math
    */
    template<>
    inline uint32_t getNextChar(const wchar_t*& it, const wchar_t* end) {
        (void)end;
        return *(it++);
    }
};
#endif
