/*** This file is part of FineFramework project ***/

#include "ffw/gui/guitext.h"
#include "ffw/gui/guiwindow.h"
#include "ffw/gui/guitheme.h"
#include "ffw/math/textwrapper.h"

///=============================================================================
ffw::GuiText::GuiText(GuiWindow* context) : GuiWidget(context),lastCalculatedWidth(0) {
    setIgnoreUserInput(true);
    setStyle(&context->getTheme()->richText, true);
}

///=============================================================================
ffw::GuiText::Paragraph* ffw::GuiText::addParagraph(const std::string& text) {
    const auto font = getCurrentFont();
    const auto strSize = font->getStringSize(text, getVisibleContentSize().x, getLineHeight());
    const auto textColor = getStyleGroup()->normal.text.color;
    paragraphs.push_back(Paragraph(font, textColor, text, strSize));
    redraw();
    return &paragraphs.back();
}

///=============================================================================
ffw::GuiText::Paragraph* ffw::GuiText::addParagraph(const std::string& text, const Color& color, const GuiFont* font) {
    const auto strSize = font->getStringSize(text, getVisibleContentSize().x, getLineHeight());
    paragraphs.push_back(Paragraph(font, color, text, strSize));
    redraw();
    return &paragraphs.back();
}

///=============================================================================
void ffw::GuiText::eventRender(const ffw::Vec2f& contentoffset, const ffw::Vec2f& contentsize) {
    (void)contentsize;
    if (getCurrentFont() == nullptr) return;

    if (!paragraphs.empty()) {
        auto p = contentoffset;
        for (const auto& para : paragraphs) {
            if (!para.str.empty()) {
                auto wrapper = TextWrapper<char>(&para.str[0], &para.str[0] + para.str.size());
                
                auto height = p.y;
                bool previousWasNewline = false;
                while (const auto token = wrapper.next(para.font, lastCalculatedWidth)) {
                    if (token.len > 0) {
                        context->drawString(ffw::Vec2f(p.x, height), para.font, token.str, token.len, para.color, getLineHeight());

                        height += getLineHeight() * para.font->getSizeInPixels();
                        previousWasNewline = false;
                    }
                    else {
                        if (previousWasNewline) {
                            height += getLineHeight() * para.font->getSizeInPixels();
                        }
                        previousWasNewline = true;
                    }
                }
            }

            p.y += para.size.y;
        }
    }
}

///=============================================================================
void ffw::GuiText::eventSize(const ffw::Vec2f& size) {
    (void)size;
    lastCalculatedWidth = getVisibleContentSize().x;
    recalculateSize(lastCalculatedWidth);
}

///=============================================================================
void ffw::GuiText::recalculateSize(const float width) {
    if (getCurrentFont() != nullptr) {
        for (auto& para : paragraphs) {
            auto f = para.font;
            if (f == nullptr)f = getCurrentFont();
            if (!para.str.empty()) {
                para.size = f->getStringSize(para.str, width, getLineHeight());
            }
            else {
                para.size = ffw::Vec2f(0.0f, para.font->getSizeInPixels() * getLineHeight());
            }
        }
    }
}

///=============================================================================
void ffw::GuiText::eventThemeChanged(const GuiTheme* theme, const bool defaults) {
    setStyle(&theme->richText, defaults);
}

///=============================================================================
void ffw::GuiText::setStyle(const GuiText::Style* style, const bool defaults) {
    widgetStyle = &style->self;
    if (defaults)setDefaults(&widgetStyle->defaults);
}

///=============================================================================
ffw::Vec2f ffw::GuiText::getMinimumWrapSize() {
    if (getCurrentFont() == nullptr) return 0;
    const auto test = getVisibleContentSize().x;;
    if(test != lastCalculatedWidth) {
        recalculateSize(test);
    }
    ffw::Vec2f ret(test, 0);
    for(const auto& para : paragraphs) {
        ret.y += para.size.y;
    }
    return ret;
}
