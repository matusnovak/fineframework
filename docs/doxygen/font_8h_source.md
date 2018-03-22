---
search: false
---

# font.h File Reference

**[Go to the documentation of this file.](font_8h.md)**
Source: `include/ffw/graphics/font.h`

    
    
    
    
    
    
    
    
    
    
    
    
    
      
    
    
    
```cpp
/* This file is part of FineFramework project */
#ifndef FFW_GRAPHICS_FONT
#define FFW_GRAPHICS_FONT
#define FFW_FT_UNICODE_MAX 65535

#include "../config.h"
#include "../math/vec2.h"
#include "texture2d.h"
#include "bufferobject.h"

namespace ffw {
    class RenderContext;
    class FFW_API Font {
    public:
        struct Char {
            unsigned short x = 0;
            unsigned short y = 0;
            unsigned short width = 0;
            unsigned short height = 0;
            float bearingX = 0;
            float bearingY = 0;
            float advance = 0;
        };

        Font();
        virtual ~Font();

        virtual void destroy() = 0;
        virtual const Char& getChar(wchar_t chr) const = 0;
        virtual int getCharIndex(wchar_t chr) const = 0;
        virtual ffw::Vec2f getStringSize(const std::string& str, float maxWidth = -1.0f, float lineHeight = 1.25f) const;
        virtual ffw::Vec2f getStringSize(const std::wstring& str, float maxWidth = -1.0f, float lineHeight = 1.25f) const;
        inline float getCharAdvance(wchar_t chr) const {
            return getChar(chr).advance;
        }
        inline int getSizePt() const {
            return sizePoints;
        }
        inline int getSizePixels() const {
            return sizePoints;
        }
        inline int getDpi() const  {
            return sizePoints;
        }
        inline const ffw::Texture2D* getTexture() const {
            return &texture;
        }
        inline const ffw::Vbo* getVbo() const {
            return &vbo;
        }
        inline bool isCreated() const {
            return loaded;
        }
        inline float getCharVerticalOffset(const Font::Char& data) const {
            return float(sizePixels - data.height) + float(data.height - data.bearingY);
        }
        inline bool isAlphaOnly() const {
            return alphaOnlyFlag;
        }
    protected:
        template<class T>
        ffw::Vec2f getStringSizeFunc(const std::basic_string<T>& str, float maxWidth = -1.0f, float lineHeight = 1.25f) const;
        ffw::Texture2D texture;
        ffw::Vbo vbo;
        int sizePoints;
        int sizePixels;
        int sizeDpi;
        bool loaded;
        bool alphaOnlyFlag;
    };
};
#endif

```


    
  
