---
search: false
---

# bitmapfont.h File Reference

**[Go to the documentation of this file.](bitmapfont_8h.md)**
Source: `include/ffw/graphics/bitmapfont.h`

    
    
    
    
    
    
    
    
      
    
    
    
```cpp
/* This file is part of FineFramework project */
#ifndef FFW_GRAPHICS_BITMAP_FONT
#define FFW_GRAPHICS_BITMAP_FONT
#include <vector>
#include "font.h"

namespace ffw {
    class RenderContext;
    class FFW_API BitmapFont: public Font {
    public:
        BitmapFont();
        BitmapFont(const BitmapFont& other) = delete;
        BitmapFont(BitmapFont&& other) NOEXCEPT;
        virtual ~BitmapFont();
        bool createFromData(
            const void* pixels, int width, int height, ffw::ImageType format, 
            int points, int dpi, int start = 0x00, int end = 0x7F);
        bool createFromBuffer(
            const ImageBuffer& buffer, int points, int dpi, 
            int start = 0x00, int end = 0x7F);
        void destroy();
        const Font::Char& getChar(unsigned int chr) const override;
        int getCharIndex(unsigned int chr) const override;
        void setCharData(unsigned int chr, const Font::Char& data);
        bool updateBuffer();

        BitmapFont& operator = (const BitmapFont& other) = delete;
        BitmapFont& operator = (BitmapFont&& other) NOEXCEPT;
        void swap(BitmapFont& other) NOEXCEPT;
    private:
        std::vector<Font::Char> characters;
        int offsetStart;
        int offsetEnd;
        int errorChar;
    };
};

inline void swap(ffw::BitmapFont& first, ffw::BitmapFont& second) NOEXCEPT {
    first.swap(second);
}
#endif

```


    
  
