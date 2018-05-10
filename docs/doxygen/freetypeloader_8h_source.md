---
search: false
---

# freetypeloader.h File Reference

**[Go to the documentation of this file.](freetypeloader_8h.md)**
Source: `include/ffw/graphics/freetypeloader.h`

    
    
    
    
    
    
    
    
    
    
      
    
    
    
```cpp
/* This file is part of FineFramework project */
#ifndef FFW_GRAPHICS_FREE_TYPE_LOADER
#define FFW_GRAPHICS_FREE_TYPE_LOADER

#include <string>
#include "../config.h"

#ifndef DOXYGEN_SHOULD_SKIP_THIS
#if defined(__FT_HEADER_H__) || defined(FREETYPE_H_)
// Nothing
#else
typedef void* FT_Face;
typedef void* FT_Glyph;
#endif
#endif

namespace ffw {
    class RenderContext;
    class FFW_API FreeTypeLoader {
    public:
        class CharData {
        public:
            CharData() = default;
            CharData(const CharData& other) = default;
            CharData& operator = (const CharData& other) = default;
            ~CharData() {
                delete[] pixels;
            }
            short width = 0;
            short height = 0;
            float bearingX = 0;
            float bearingY = 0;
            float advance = 0;
            unsigned char* pixels = nullptr;
        };
        FreeTypeLoader();
        FreeTypeLoader(const FreeTypeLoader& other) = delete;
        FreeTypeLoader(FreeTypeLoader&& other) NOEXCEPT;
        virtual ~FreeTypeLoader();

        bool createFromData(const unsigned char* buffer, size_t length);
        bool createFromFile(const std::string& path);
        bool setSize(int points, int dpi);
        bool findGlyph(unsigned int unicode);
        bool findErrorGlyph();
        bool getGlyphData(CharData* data);

        inline int getSizePixels() const {
            return sizePixels;
        }
        inline bool isCreated() const {
            return loaded;
        }
        void destroy();

        void swap(FreeTypeLoader& other) NOEXCEPT;
        FreeTypeLoader& operator = (const FreeTypeLoader& other) = delete;
        FreeTypeLoader& operator = (FreeTypeLoader&& other) NOEXCEPT;
    private:
        static bool checkForErrors(int error);
        bool loaded;
        FT_Face fontFace;
        FT_Glyph currentGlyph;
        int sizePixels;
    };
    extern FFW_API const unsigned char* defaultFont;
    extern FFW_API const size_t defaultFontSize;
};

inline void swap(ffw::FreeTypeLoader& first, ffw::FreeTypeLoader& second) NOEXCEPT {
    first.swap(second);
}
#endif

```


    
  
