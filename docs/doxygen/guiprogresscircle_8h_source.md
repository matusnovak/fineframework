---
search: false
---

# guiprogresscircle.h File Reference

**[Go to the documentation of this file.](guiprogresscircle_8h.md)**
Source: `include/ffw/gui/guiprogresscircle.h`

    
    
    
    
    
    
    
    
    
    
    
    
```cpp
/* This file is part of FineFramework project */
#ifndef FFW_GUI_PROGRESSCIRCLE
#define FFW_GUI_PROGRESSCIRCLE
#include "guiwidget.h"
namespace ffw {
    class FFW_API GuiProgressCircle : public GuiWidget {
    public:
        struct Style {
            GuiWidget::Style self;
        };
        GuiProgressCircle(GuiWindow* context);
        virtual ~GuiProgressCircle() = default;
        ffw::Vec2f getMinimumWrapSize() override;
        void setValue(float value);
        inline float getValue() const {
            return percent;
        }
        void setThickness(float val);
        inline float getThickness() const {
            return thickness;
        }
        void setStyle(const GuiProgressCircle::Style* style, bool defaults = false);
    private:
        void eventRender(const ffw::Vec2f& contentoffset, const ffw::Vec2f& contentsize) override;
        virtual void eventThemeChanged(const GuiTheme* theme, bool defaults) override;
        std::string label;
        float percent;
        float thickness;
    };
}
#endif
```


    
  
