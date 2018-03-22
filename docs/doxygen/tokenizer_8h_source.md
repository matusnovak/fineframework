---
search: false
---

# tokenizer.h File Reference

**[Go to the documentation of this file.](tokenizer_8h.md)**
Source: `include/ffw/math/tokenizer.h`

    
    
    
    
    
    
    
    
    
    
    
    
```cpp
/* This file is part of FineFramework project */
#ifndef FFW_MATH_TOKENIZER
#define FFW_MATH_TOKENIZER
#include "../config.h"
#include <string>
namespace ffw {
    template<class T, typename CharTrait = std::char_traits<T>, typename Allocator = std::allocator<T>>
    class Tokenizer {
    public:
        Tokenizer(const std::basic_string<T, CharTrait, Allocator>& str, const std::basic_string<T, CharTrait, Allocator>& delim):ptr(str),del(delim) {
            pos = 0;
            last = 0;
        }

        bool getNext(std::basic_string<T, CharTrait, Allocator>* str) {
            // Loop until all tokens found
            while (del.size() > 0 && (pos = ptr.find(del, pos)) != std::basic_string<T, CharTrait, Allocator>::npos) {
                // Do we have non-empty token?
                if (last < pos && pos - last > 0) {
                    if(str != NULL)*str = ptr.substr(last, pos - last);
                    pos += del.size();
                    last = pos;
                    return true;
                }
                pos += del.size();
                last = pos;
            }
            // add the last token (will also include a whole string when no delim was found)
            if (last < ptr.size()) {
                if (str != NULL)*str = ptr.substr(last, ptr.size() - last);
                last = ptr.size();
                return true;
            }
            return false;
        }

        std::basic_string<T, CharTrait, Allocator> getNext() {
            std::basic_string<T, CharTrait, Allocator> str;
            getNext(&str);
            return str;
        }

        bool skipNext() {
            return getNext(NULL);
        }

        bool hasNext() {
            size_t tempLast = last;
            size_t tempPos = pos;
            bool result = getNext(NULL);
            last = tempLast;
            pos = tempPos;
            return result;
        }

        size_t getPos() {
            return pos;
        }

    private:
        const std::basic_string<T, CharTrait, Allocator>& ptr;
        const std::basic_string<T, CharTrait, Allocator> del;
        size_t pos = 0;
        size_t last = 0;
    };
}
#endif
```


    
  
