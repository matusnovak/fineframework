---
search: false
---

# guislider.h File Reference

**[Go to the documentation of this file.](guislider_8h.md)**
Source: `include/ffw/gui/guislider.h`

    
    
    
    
    
    
    
    
    
    
    
    
    
```cpp
/* This file is part of FineFramework project */
#ifndef FFW_GUI_SLIDER
#define FFW_GUI_SLIDER
#include "guiwidget.h"
namespace ffw {
    class FFW_API GuiSlider: public GuiWidget {
    public:
        struct Style {
            GuiWidget::Style button;
            GuiWidget::Style bar;
            GuiWidget::Style self;
        };
        GuiSlider(GuiWindow* context, bool vertical);
        virtual ~GuiSlider() = default;
        bool isVertical() const;
        void setValue(float val);
        float getValue() const;
        void setBarSize(const ffw::Vec2<GuiUnits>& s);
        inline const ffw::Vec2<GuiUnits>& getBarSize() const {
            return barSize;
        }
        const ffw::Vec2f& getRange() const;
        void setRange(float min, float max);
        void setButtonSize(const ffw::Vec2<GuiUnits>& s);
        inline const ffw::Vec2<GuiUnits>& getButtonSize() const {
            return buttonSize;
        }
        void setInversed(bool inversed);
        bool getInversed() const;
        ffw::Vec2f getMinimumWrapSize() override;
        void setBarStyleGroup(const GuiWidget::Style* style);
        inline const GuiWidget::Style* getBarStyleGroup() const {
            return styleBar;
        }
        void setButtonStyleGroup(const GuiWidget::Style* style);
        inline const GuiWidget::Style* getButtonStyleGroup() const {
            return styleButton;
        }
        void setStyle(const GuiSlider::Style* style, bool defaults = false);
    protected:
        const GuiWidget::Style* styleButton;
        const GuiWidget::Style* styleBar;
        ffw::Vec2<GuiUnits> buttonSize;
        ffw::Vec2<GuiUnits> barSize;
    private:
        void calculateButtonSize(ffw::Vec2f& pos, ffw::Vec2f& size) const;
        void eventRender(const ffw::Vec2f& contentoffset, const ffw::Vec2f& contentsize) override;
        void eventHover(bool gained) override;
        void eventFocus(bool gained) override;
        void eventMouse(const ffw::Vec2f& pos) override;
        void eventMouseButton(ffw::MouseButton button, ffw::Mode mode) override;
        virtual void eventThemeChanged(const GuiTheme* theme, bool defaults) override;
        bool vertical;
        ffw::Vec2f range;
        float value;
        bool inverse;
        ffw::Vec2i clickedOffset;
    };
}
#endif
```


    
  
