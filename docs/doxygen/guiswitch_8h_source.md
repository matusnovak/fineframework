---
search: false
---

# guiswitch.h File Reference

**[Go to the documentation of this file.](guiswitch_8h.md)**
Source: `include/ffw/gui/guiswitch.h`

    
    
    
    
    
    
    
    
    
    
    
    
```cpp
/* This file is part of FineFramework project */
#ifndef FFW_GUI_SWITCH
#define FFW_GUI_SWITCH
#include "guiwidget.h"
namespace ffw {
    class FFW_API GuiSwitch : public GuiWidget {
    public:
        struct Style {
            GuiWidget::Style button;
            GuiWidget::Style self;
        };
        GuiSwitch(GuiWindow* context);
        virtual ~GuiSwitch() = default;
        void setValue(bool value);
        bool getValue() const;
        ffw::Vec2f getMinimumWrapSize() override;
        void setStyle(const GuiSwitch::Style* style, bool defaults = false);
    protected:
        const GuiWidget::Style* styleButton;
    private:
        void eventRender(const ffw::Vec2f& contentoffset, const ffw::Vec2f& contentsize) override;
        void eventHover(bool gained) override;
        void eventFocus(bool gained) override;
        virtual void eventThemeChanged(const GuiTheme* theme, bool defaults) override;
    };
}
#endif
```


    
  
