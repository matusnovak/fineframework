/* This file is part of FineFramework project */
#ifndef FFW_GRAPHICS_BITMAP_FONT
#define FFW_GRAPHICS_BITMAP_FONT
#include <vector>
#include "font.h"

namespace ffw {
    class RenderContext;
    /**
     * @ingroup graphics
     */
    class FFW_API BitmapFont: public Font {
    public:
        BitmapFont();
        BitmapFont(const BitmapFont& other) = delete;
        BitmapFont(BitmapFont&& other);
        virtual ~BitmapFont();
        bool createFromData(const void* pixels, int width, int height, ffw::ImageType format, int points, int dpi, int start = 0x00, int end = 0x7F);
        bool createFromBuffer(const ImageBuffer& buffer, int points, int dpi, int start = 0x00, int end = 0x7F);
        void destroy() override;
        const Font::Char& getChar(wchar_t chr) const override;
        int getCharIndex(wchar_t chr) const override;
        void setCharData(wchar_t chr, Font::Char& data);
        bool updateBuffer();

        BitmapFont& operator = (const BitmapFont& other) = delete;
        BitmapFont& operator = (BitmapFont&& other);
        void swap(BitmapFont& other);
    private:
        std::vector<Font::Char> characters;
        int offsetStart;
        int offsetEnd;
        int errorChar;
    };
};

inline void swap(ffw::BitmapFont& first, ffw::BitmapFont& second) {
    first.swap(second);
}
#endif

