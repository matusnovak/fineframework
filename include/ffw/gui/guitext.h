/* This file is part of FineFramework project */
#ifndef FFW_GUI_RICH_TEXT
#define FFW_GUI_RICH_TEXT
#include <list>
#include "guiwidget.h"

namespace ffw {
    /**
    * @ingroup gui
    */
    class FFW_API GuiText: public GuiWidget {
    public:
        struct Style {
            GuiWidget::Style self;
        };

        struct Paragraph {
            Paragraph(const GuiFont* font, const Color& color, const std::string& str, const ffw::Vec2f& size):font(font),color(color),str(str),size(size){

            }
            const GuiFont* font;
            const Color color;
            const std::string str;
            ffw::Vec2f size;
        };

        GuiText(GuiWindow* context);
        virtual ~GuiText() = default;

        Paragraph* addParagraph(const std::string& text);
        Paragraph* addParagraph(const std::string& text, const Color& color, const GuiFont* font);
        const std::list<Paragraph>& getParagraphs() const {
            return paragraphs;
        }

        void setStyle(const GuiText::Style* style, bool defaults = false);
        ffw::Vec2f getMinimumWrapSize() override;
    private:
        void recalculateSize(float width);
        void eventRender(const ffw::Vec2f& contentoffset, const ffw::Vec2f& contentsize) override;
        void eventSize(const ffw::Vec2f& size) override;
        virtual void eventThemeChanged(const GuiTheme* theme, bool defaults) override;
        float lastCalculatedWidth;
        std::list<Paragraph> paragraphs;
    };
}
#endif
