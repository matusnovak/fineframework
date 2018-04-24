/*** This file is part of FineFramework project ***/

#include "ffw/graphics/font.h"
#include "ffw/graphics/rendercontext.h"
#include "ffw/math/textwrapper.h"
#include "ffw/math/stringmath.h"

///=============================================================================
ffw::Font::Font() {
    sizePoints = 0;
    sizePixels = 0;
    sizeDpi = 0;
    loaded = false;
    alphaOnlyFlag = false;
}

///=============================================================================
template<class T>
ffw::Vec2f ffw::Font::getStringSizeFunc(const std::basic_string<T>& str, 
    const float maxWidth, const float lineHeight) const {

    if (!isCreated())return ffw::Vec2i(0, 0);

    auto wrapper = ffw::TextWrapper<T>(&str[0], &str[0] + str.size());
    ffw::Vec2f ret;

    auto height = 0.0f;
    auto previousWasNewline = false;
    while (auto token = wrapper.next(this, maxWidth)) {
        auto advance = 0.0f;

        if (token.len > 0) {
            const T* ptr = token.str;
            while(ptr != token.str + token.len) {
                const auto chr = getNextChar(ptr, token.str + token.len);
                const ffw::Font::Char& chrData = this->getChar(chr);

                if (chrData.height == 0 || chrData.width == 0) {
                    advance += chrData.advance;
                    continue;
                }

                advance += chrData.advance;
            }
            height += lineHeight * this->getSizePixels();
            previousWasNewline = false;
        }
        else {
            if (previousWasNewline) {
                height += lineHeight * this->getSizePixels();
            }
            previousWasNewline = true;
        }

        ret.y = std::max(ret.y, height);
        ret.x = std::max(ret.x, advance);
    }

    return ret;
}

///=============================================================================
ffw::Vec2f ffw::Font::getStringSize(const std::wstring& str, 
    const float maxWidth, const float lineHeight) const {

    return getStringSizeFunc<wchar_t>(str, maxWidth, lineHeight);
}

///=============================================================================
ffw::Vec2f ffw::Font::getStringSize(const std::string& str, 
    const float maxWidth, const float lineHeight) const {

    return getStringSizeFunc<char>(str, maxWidth, lineHeight);
}