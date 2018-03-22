---
search: false
---

# functions.h File Reference

**[Go to the documentation of this file.](functions_8h.md)**
Source: `include/ffw/math/functions.h`

    
    
    
    
    
    
    
    
    
    
    
```cpp
/* This file is part of FineFramework project */
#ifndef FFW_BASE_FUNCTIONS
#define FFW_BASE_FUNCTIONS
#include "../config.h"
#include <algorithm>

namespace ffw {
    template<class T>
    inline T clamp(T Val, T Min, T Max) {
        return std::max(Min, std::min(Val, Max));
    }
    template <class T>
    inline T lerp(const T& a, const T& b, float w) {
        return T(a*(1 - w) + b*w);
    }
    template<class T>
    inline T radians (T val){
        return static_cast<T>(val * DEG_TO_RAD);
    }
    template<class T>
    inline T degrees (T val){
        return static_cast<T>(val * RAD_TO_DEG);
    }
    template<typename T>
    inline T remap(T value, T InMin, T InMax, T OutMin, T OutMax) {
        return (value - InMin)*(OutMax - OutMin) / (InMax - InMin) + OutMin;
    }
    inline unsigned long nextPowOfTwo(unsigned long Value) {
        unsigned long P = 1;
        while (P < Value) {
            P *= 2;
        }
        return P;
    }

#ifdef FFW_WINDOWS_MSVC

    inline unsigned short byteSwap16(unsigned short Value) {
        return _byteswap_ushort(Value);
    }
    inline unsigned long byteSwap32(unsigned long Value) {
        return _byteswap_ulong(Value);
    }
    inline unsigned long long byteSwap64(unsigned long long Value) {
        return _byteswap_uint64(Value);
    }
#else

    inline unsigned short byteSwap16(unsigned short Value) {
        return __builtin_bswap16(Value);
    }
    inline unsigned long byteSwap32(unsigned long Value) {
        return __builtin_bswap32(Value);
    }
    inline unsigned long long byteSwap64(unsigned long long Value) {
        return __builtin_bswap64(Value);
    }
#endif
};
#endif
```


    
  
