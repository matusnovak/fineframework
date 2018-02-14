/* This file is part of FineFramework project */
#ifndef FFW_GUI_BOX
#define FFW_GUI_BOX

#include "guilabel.h"
#include "guilayout.h"

namespace ffw {
    /**
     * @ingroup gui
     */
    class FFW_API GuiBox: public GuiWidget {
    public:
        struct Style {
            GuiLabel::Style label;
            GuiLayout::Style inner;
            GuiWidget::Style self;
        };

        GuiBox(GuiWindow* context, const std::string& label, GuiOrientation orient);
        virtual ~GuiBox() = default;
        void eventRender(const ffw::Vec2f& contentoffset, const ffw::Vec2f& contentsize) override;
        inline GuiLayout* getInner() {
            return widgetInner;
        }
        inline const GuiLayout* getInner() const {
            return widgetInner;
        }
        inline void setLabel(const std::string& label) {
            widgetLabel->setLabel(label);
        }
        inline const std::string& getLabel() const {
            return widgetLabel->getLabel();
        }
        inline GuiLabel* getLabelWidget() {
            return widgetLabel;
        }
        inline const GuiLabel* getLabelWidget() const {
            return widgetLabel;
        }
        void eventSize(const ffw::Vec2f& size) override;
        ffw::Vec2f getMinimumWrapSize() override;
        void setStyle(const GuiBox::Style* style, bool defaults = false);
    private:
        void eventThemeChanged(const GuiTheme* theme, bool defaults) override;
        GuiLabel* widgetLabel;
        GuiLayout* widgetInner;
    };
}

#endif