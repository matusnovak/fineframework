---
search: false
---

# guilayout.h File Reference

**[Go to the documentation of this file.](guilayout_8h.md)**
Source: `include/ffw/gui/guilayout.h`

    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
```cpp
/* This file is part of FineFramework project */
#ifndef FFW_GUI_LAYOUT
#define FFW_GUI_LAYOUT
#include "guiwidget.h"
namespace ffw {
    class FFW_API GuiLayout: public GuiWidget {
    public:
        struct Style {
            GuiWidget::Style self;
        };

        GuiLayout(GuiWindow* context, GuiOrientation orientation);
        virtual ~GuiLayout();
        GuiWidget* addWidget(GuiWidget* widget);
        GuiWidget* addWidgetAfter(const GuiWidget* previous, GuiWidget* widget);
        GuiWidget* addWidgetBefore(const GuiWidget* next, GuiWidget* widget);
        void deleteWidgets();
        bool deleteSingleWidget(const GuiWidget* widget);
        void setOrientation(GuiOrientation orient);
        ffw::Vec2f getMinimumWrapSize() override;
        void setStyle(const GuiLayout::Style* style, bool defaults = false);
    private:
        void eventRender(const ffw::Vec2f& contentoffset, const ffw::Vec2f& contentsize) override;
        void eventThemeChanged(const GuiTheme* theme, bool defaults) override;
    };
    class GuiVerticalLayout: public GuiLayout {
    public:
        GuiVerticalLayout(GuiWindow* context):
        GuiLayout(context, GuiOrientation::VERTICAL) {
            
        }
        virtual ~GuiVerticalLayout(){}
    };
    class GuiHorizontalLayout: public GuiLayout {
    public:
        GuiHorizontalLayout(GuiWindow* context):
        GuiLayout(context, GuiOrientation::HORIZONTAL) {
            
        }
        virtual ~GuiHorizontalLayout(){}
    };
    class GuiFixedLayout: public GuiLayout {
    public:
        GuiFixedLayout(GuiWindow* context):
        GuiLayout(context, GuiOrientation::FIXED) {
            
        }
        virtual ~GuiFixedLayout(){}
    };
}
#endif
```


    
  
