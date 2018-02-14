/* This file is part of FineFramework project */
#ifndef FFW_GUI_BACKEND
#define FFW_GUI_BACKEND
#include "../config.h"
#include "guistyle.h"
#include "guifont.h"
#include "ffw/math/vec4.h"

namespace ffw {
    class GuiImage;
    class GuiFont;
    /**
     * @ingroup gui
     */
    class FFW_API GuiBackend {
    public:
        // The following must be implemented!
        virtual void resize(int width, int height) = 0;
        virtual void startRender() = 0;
        virtual void endRender() = 0;
        virtual void setScissors(const ffw::Vec2f& pos, const ffw::Vec2f& size) const = 0;
        virtual void clearWithColor(const ffw::Color& color) const = 0;
        virtual void drawRectangle(const ffw::Vec2f& pos, const ffw::Vec2f& size, const ffw::Color& color) const = 0;
        virtual void drawRectangleRounded(const ffw::Vec2f& pos, const ffw::Vec2f& size, const ffw::Color& color, float tl, float tr, float br, float bl) const = 0;
        virtual void drawLine(const ffw::Vec2f& start, const ffw::Vec2f& end, const ffw::Color& color) const = 0;
        virtual void drawCircle(const ffw::Vec2f& pos, float radius, const ffw::Color& color) const = 0;
        virtual void drawArc(const ffw::Vec2f& pos, float inner, float outer, float start, float end, const ffw::Color& color) const = 0;
        virtual void drawQuad(const ffw::Vec2f& p0, const ffw::Vec2f& p1, const ffw::Vec2f& p2, const ffw::Vec2f& p3, const ffw::Color& color) const = 0;
        virtual void drawString(const ffw::Vec2f& pos, const ffw::GuiFont* font, const std::string::value_type* str, size_t length, const ffw::Color& color, float lineHeight = 1.25f) const = 0;
        virtual void drawTriangle(const ffw::Vec2f& p0, const ffw::Vec2f& p1, const ffw::Vec2f& p2, const ffw::Color& color) const = 0;
        virtual void drawImage(const ffw::Vec2f& pos, const ffw::Vec2f& size, const GuiImage* image, const ffw::Vec4i& sub, bool mirrorX, bool mirrorY, const ffw::Color& color) const = 0;

        // The following can be overriden
        virtual void drawBackground(const ffw::Vec2f& pos, const ffw::Vec2f& size, const ffw::GuiStyle::Background& background, bool ignore = false) const;
        virtual void drawBorder(const ffw::Vec2f& pos, const ffw::Vec2f& size, const ffw::GuiStyle::Border& border) const;
        virtual void drawStringAligned(const ffw::Vec2f& pos, const ffw::Vec2f& size, const ffw::GuiFont* font, ffw::GuiAlign align, const std::string& str, const ffw::GuiStyle::Text& text, float lineHeight = 1.25f) const;
    };
}
#endif
