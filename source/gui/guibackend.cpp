/*** This file is part of FineFramework project ***/

#include "ffw/gui/guibackend.h"
#include "ffw/math/functions.h"
#include "ffw/math/vec4.h"
#include <iomanip>

///=============================================================================
void ffw::GuiBackend::drawStringAligned(const ffw::Vec2f& pos, const ffw::Vec2f& size, const ffw::GuiFont* font, ffw::GuiAlign align, const std::string& str, const ffw::GuiStyle::Text& text, float lineHeight) const {
    if(font == NULL)return;

    const ffw::Vec2f& strsize = font->getStringSize(str, -1.0f);
    ffw::Vec2f offset = 0;

    switch (align){
    case GuiAlign::LEFT:
        offset.y = size.y/2 - strsize.y/2;
        break;

    case GuiAlign::RIGHT:
        offset.x = size.x - strsize.x;
        offset.y = size.y/2 - strsize.y/2;
        break;

    case GuiAlign::CENTER:
        offset = size/2 - strsize/2;
        break;

    case GuiAlign::TOP_CENTER:
        offset.x = size.x/2 - strsize.x/2;
        break;

    case GuiAlign::TOP_RIGHT:
        offset.x = size.x - strsize.x;
        break;

    case GuiAlign::BOTTOM_LEFT:
        offset.y = size.y - strsize.y;
        break;

    case GuiAlign::BOTTOM_CENTER:
        offset.x = size.x/2 - strsize.x/2;
        offset.y = size.y - strsize.y;
        break;

    case GuiAlign::BOTTOM_RIGHT:
        offset.x = size.x - strsize.x;
        offset.y = size.y - strsize.y;
        break;

    case GuiAlign::TOP_LEFT:
    default:
        break;
    }

    drawString((pos + offset).floor(), font, &str[0], str.size(), text.color, lineHeight);
}