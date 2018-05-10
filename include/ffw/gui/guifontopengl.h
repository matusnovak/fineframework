/* This file is part of FineFramework project */
#ifndef FFW_GUI_FONT_OPENGL
#define FFW_GUI_FONT_OPENGL
#ifndef FFW_GRAPHICS_TRUE_TYPE_FONT
#error Please add #include <ffw/graphics/truetypefont.h> before including guifontopengl.h!
#endif
#include "guifont.h"
namespace ffw {
    class RenderContext;
    /**
     * @ingroup gui
     */
    class GuiFontOpenGL: public GuiFont, public TrueTypeFont {
    public:
        inline bool isCreated() const override {
            return TrueTypeFont::isCreated();
        }
        inline void destroy() override {
            TrueTypeFont::destroy();
        }
        inline ffw::Vec2f getStringSize(const std::string& str, float maxWidth, float lineHeight = 1.25) const override {
            return static_cast<ffw::Vec2f>(TrueTypeFont::getStringSize(str, maxWidth, lineHeight));
        }
        inline float getCharAdvance(wchar_t c) const override {
            return TrueTypeFont::getChar(c).advance;
        }
        inline int getSizeInPixels() const override {
            return TrueTypeFont::getSizePixels();
        }
    };
}
#endif