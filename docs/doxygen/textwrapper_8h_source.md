---
search: false
---

# textwrapper.h File Reference

**[Go to the documentation of this file.](textwrapper_8h.md)**
Source: `include/ffw/math/textwrapper.h`

    
    
    
    
    
    
    
    
    
    
    
    
```cpp
/* This file is part of FineFramework project */
#ifndef FFW_TEXT_WRAPPER
#define FFW_TEXT_WRAPPER
#include "../config.h"
#include "third_party/utfcpp/checked.h"

namespace ffw {
    template<class T>
    class TextWrapper {
    public:
        struct Token {
            Token(const T* str, size_t len, float width):str(str),len(len),width(width){

            }

            Token():str(nullptr),len(0),width(0.0f){

            }

            const T* str;
            size_t len;
            float width;

            operator bool() const {
                return str != nullptr;
            }
        };
        TextWrapper(const T* start, const T* end):
            start(start),end(end) {
            
        }

        template<typename FONT>
        Token next(FONT* font, float maxWidth) {
            auto width = 0.0f;
            const T* from = start;
            const T* whitespacePtr = nullptr;
            const T* lastChar = nullptr;
            const T* opportunityPtr = nullptr;
            const T* startOfWord = nullptr;
            auto previousWasWhitespace = false;
            auto opportunityWidth = 0.0f;
            auto whitespaceWidth = 0.0f;

            while(start != end) {
                try {
                    auto isNewline = false;
                    auto isWhitespace = false;
                    const T* currentPtr = start;
                    const auto chr = goto_next(start, end);
                    const auto chrWidth = font->getCharAdvance(chr);

                    switch(chr) {
                        case 9:  // \t
                        case 11: // \v
                        case 12: // \f
                        case 32: // space
                        case 13: // \r
                        case 0x00a0: // NBSP
                            whitespaceWidth = width;
                            isWhitespace = true;
                            break;
                        case 0x0085: // NEL
                        case 10: // \n
                            whitespaceWidth = width;
                            isWhitespace = true;
                            isNewline = true;
                            break;
                        case '-':
                        case '.':
                        case '_':
                        case '=':
                        case '+':
                        case '%':
                        case '>':
                        case ')':
                        case '}':
                        case ']':
                        case ',':
                        case ':':
                        case ';':
                        case '\"':
                        case '*':
                        case '/':
                        case '?':
                        case '!':
                            opportunityPtr = currentPtr;
                            opportunityWidth = width;
                            break;
                        default:
                            break;
                    }

                    if (isNewline) {
                        if (lastChar != nullptr) {
                            start = currentPtr;
                            return Token(from, size_t(getNextChar(lastChar) - from), width);
                        } else {
                            // Peek forward and check if we have \r character
                            if (start != end) {
                                const auto test = peek_next(start, end);
                                if (test == '\r') {
                                    ++start;
                                }
                            }
                            if (currentPtr == from) {
                                return Token(currentPtr, 0, 0.0f);
                            } else {
                                start = currentPtr;
                                return Token(from, currentPtr - from, width);
                            }
                        }
                    }

                    if(!isWhitespace){
                        if(previousWasWhitespace) {
                            startOfWord = currentPtr;
                        }
                        lastChar = currentPtr;
                    }

                    if (maxWidth > 0.0f && width + chrWidth > maxWidth) {
                      if(lastChar != nullptr && !isWhitespace) {
                        if(opportunityPtr != nullptr){
                            if (startOfWord != nullptr && startOfWord > opportunityPtr) {
                                start = startOfWord;
                                return Token(from, size_t(start - from), whitespaceWidth + chrWidth); 
                            }
                            if(lastChar != opportunityPtr) {
                                // A special case where there is a trailing whitespace at the end of the word
                                start = getNextChar(opportunityPtr);
                                return Token(from, size_t(start - from), opportunityWidth + chrWidth);
                            }
                        }
                        if(startOfWord != nullptr) {
                            start = startOfWord;
                            return Token(from, size_t(start - from), whitespaceWidth + chrWidth);
                        }
                        start = currentPtr;
                        return Token(from, size_t(currentPtr - from), width);
                      }
                    }

                    if(!isWhitespace){
                        previousWasWhitespace = false;
                    } else {
                        previousWasWhitespace = true;
                    }

                    if(!isNewline && chr != '\r'){
                      width += chrWidth;
                    }
                } catch (utf8::not_enough_room& e){
                    (void)e;
                    return Token();
                } catch (utf8::invalid_utf8& e) {
                    (void)e;
                    return Token();
                }
            }

            if (from != end) {
                return Token(from, size_t(end - from), width);
            }
            return Token();
        }
    private:
        inline const T* getNextChar(const T* s) const {
            if(s + 1 == end) {
                return end;
            }
            advance(s, 1, end);
            return s;
        }
        static inline void advance(const T*& it, size_t n, const T* end);
        static inline uint32_t peek_next(const T* it, const T* end);
        static inline uint32_t goto_next(const T*& it, const T* end);
        const T* start;
        const T* end;
    };

    template<>
    inline void TextWrapper<char>::advance(const char*& it, size_t n, const char* end) {
        utf8::advance(it, n, end);
    }

    template<>
    inline void TextWrapper<wchar_t>::advance(const wchar_t*& it, size_t n, const wchar_t* end) {
        it += n;
    }

    template<>
    inline uint32_t TextWrapper<char>::peek_next(const char* it, const char* end) {
        return utf8::peek_next(it, end);
    }

    template<>
    inline uint32_t TextWrapper<wchar_t>::peek_next(const wchar_t* it,  const wchar_t* end) {
        return *(it + 1);
    }

    template<>
    inline uint32_t TextWrapper<char>::goto_next(const char*& it, const char* end) {
        return utf8::next(it, end);
    }

    template<>
    inline uint32_t TextWrapper<wchar_t>::goto_next(const wchar_t*& it, const wchar_t* end) {
        (void)end;
        return *(it++);
    }
}

#endif
```


    
  
