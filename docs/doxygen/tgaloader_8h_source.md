---
search: false
---

# tgaloader.h File Reference

**[Go to the documentation of this file.](tgaloader_8h.md)**
Source: `include/ffw/media/tgaloader.h`

    
    
    
    
    
    
    
    
      
    
    
    
```cpp
/* This file is part of FineFramework project */
#ifndef FFW_MEDIA_TGA_LOADER
#define FFW_MEDIA_TGA_LOADER
#include "imageloader.h"
#include <fstream>

namespace ffw {
    class FFW_API TgaLoader: public ImageReader {
    public:
        TgaLoader();
        TgaLoader(const TgaLoader& other) = delete;
        TgaLoader(TgaLoader&& other);
        void swap(TgaLoader& other);
        TgaLoader& operator = (const TgaLoader& other) = delete;
        TgaLoader& operator = (TgaLoader&& other);
        virtual ~TgaLoader();

        bool open(const std::string& path) override;
        size_t readRow(void* dest) override;
        void close() override;

    private:
        ffw::SwapWrapper<std::fstream> input;
        size_t pixelsOffset;
    };
}

inline void swap(ffw::TgaLoader& first, ffw::TgaLoader& second){
    first.swap(second);
}

#endif
```


    
  
