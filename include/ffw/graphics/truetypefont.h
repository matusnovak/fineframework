/* This file is part of FineFramework project */
#ifndef FFW_GRAPHICS_TRUE_TYPE_FONT
#define FFW_GRAPHICS_TRUE_TYPE_FONT
#include <vector>
#include "font.h"
#include "freetypeloader.h"

namespace ffw {
    class RenderContext;
    /**
     * @ingroup graphics
     */
    class FFW_API TrueTypeFont: public Font {
    public:
        TrueTypeFont();
        TrueTypeFont(const TrueTypeFont& other) = delete;
        TrueTypeFont(TrueTypeFont&& other) NOEXCEPT;
        virtual ~TrueTypeFont();

        bool createFromData(const unsigned char* buffer, size_t length, int points, int dpi, int start = 0x00, int end = 0x7F);
        bool createFromFile(const std::string& path, int points, int dpi, int start = 0x00, int end = 0x7F);
        void destroy();
        const Char& getChar(wchar_t chr) const override;
        int getCharIndex(wchar_t chr) const override;

        TrueTypeFont& operator = (const TrueTypeFont& other) = delete;
        TrueTypeFont& operator = (TrueTypeFont&& other) NOEXCEPT;
        void swap(TrueTypeFont& other) NOEXCEPT;
    private:
        bool fillData(int start, int end);
        std::vector<Font::Char> characters;
        int offsetStart;
        int offsetEnd;
        FreeTypeLoader freeType;
    };
};

inline void swap(ffw::TrueTypeFont& first, ffw::TrueTypeFont& second) NOEXCEPT {
    first.swap(second);
}
#endif

