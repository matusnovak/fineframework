---
search: false
---

# guitheme.h File Reference

**[Go to the documentation of this file.](guitheme_8h.md)**
Source: `include/ffw/gui/guitheme.h`

    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
```cpp
/* This file is part of FineFramework project */
#ifndef FFW_GUI_THEME
#define FFW_GUI_THEME

#include "guibody.h"
#include "guibox.h"
#include "guibutton.h"
#include "guibuttontoggle.h"
#include "guicheckbox.h"
#include "guiimageviewer.h"
#include "guilabel.h"
#include "guilayout.h"
#include "guilist.h"
#include "guiprogressbar.h"
#include "guiprogresscircle.h"
#include "guiradio.h"
#include "guitext.h"
#include "guiscrollable.h"
#include "guiscrollbar.h"
#include "guislider.h"
#include "guiswitch.h"
#include "guitab.h"
#include "guitextedit.h"

namespace ffw {
    class FFW_API GuiTheme {
    public:
        GuiBody::Style body;
        GuiBox::Style box;
        GuiButton::Style button;
        GuiButtonPrimary::Style buttonPrimary;
        GuiCheckbox::Style checkbox;
        GuiImageViewer::Style imageViewer;
        GuiLabel::Style label;
        GuiLayout::Style layout;
        GuiList::Style list;
        GuiProgressBar::Style progressBar;
        GuiProgressCircle::Style progressCircle;
        GuiRadio::Style radio;
        GuiText::Style richText;
        GuiScrollable::Style scrollable;
        GuiScrollableLayout::Style scrollableLayout;
        GuiScrollBar::Style scrollbar;
        GuiSlider::Style slider;
        GuiSwitch::Style swtch;
        GuiTabs::Style tabs;
        GuiScrollableTextInput::Style textArea;
        GuiTextInput::Style textInput;
    };

    class FFW_API GuiThemeSimpleLight: public GuiTheme {
    public:
        GuiThemeSimpleLight();
        static GuiThemeSimpleLight singleton;
    };

    class FFW_API GuiThemeSimpleDark : public GuiTheme {
    public:
        GuiThemeSimpleDark();
        static GuiThemeSimpleDark singleton;
    };

    class FFW_API GuiThemeFlatLight : public GuiTheme {
    public:
        GuiThemeFlatLight();
        static GuiThemeFlatLight singleton;
    };

    class FFW_API GuiThemeFlatDark : public GuiTheme {
    public:
        GuiThemeFlatDark();
        static GuiThemeFlatDark singleton;
    };
};
#endif
```


    
  
