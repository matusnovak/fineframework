---
search: false
---

# tgasaver.h File Reference

**[Go to the documentation of this file.](tgasaver_8h.md)**
Source: `include/ffw/media/tgasaver.h`

    
    
    
    
    
    
    
    
      
    
    
    
```cpp
/* This file is part of FineFramework project */
#ifndef FFW_MEDIA_TGA_SAVER
#define FFW_MEDIA_TGA_SAVER
#include "imagesaver.h"
#include <fstream>

namespace ffw {
    class FFW_API TgaSaver: public ImageWriter {
    public:
        TgaSaver();
        TgaSaver(const TgaSaver& other) = delete;
        TgaSaver(TgaSaver&& other);
        void swap(TgaSaver& other);
        TgaSaver& operator = (const TgaSaver& other) = delete;
        TgaSaver& operator = (TgaSaver&& other);
        virtual ~TgaSaver();

        bool open(const std::string& path, int width, int height, ffw::ImageType type, int quality = 100, int mips = 1) override;
        size_t writeRow(const void* src) override;
        bool writeFooter() override;
        void close() override;

    private:
        ffw::SwapWrapper<std::fstream> output;
        size_t pixelsOffset;
    };
}

inline void swap(ffw::TgaSaver& first, ffw::TgaSaver& second){
    first.swap(second);
}

#endif
```


    
  
