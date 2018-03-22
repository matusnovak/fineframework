---
search: false
---

# guiimageviewer.h File Reference

**[Go to the documentation of this file.](guiimageviewer_8h.md)**
Source: `include/ffw/gui/guiimageviewer.h`

    
    
    
    
    
    
    
    
    
    
    
    
    
```cpp
/* This file is part of FineFramework project */
#ifndef FFW_GUI_IMAGE_VIEWER
#define FFW_GUI_IMAGE_VIEWER
#include "guiwidget.h"
#include "ffw/math/vec4.h"

namespace ffw {
    class GuiImage;

    class FFW_API GuiImageViewer : public GuiWidget {
    public:
        struct Style {
            GuiWidget::Style self;
        };

        GuiImageViewer(GuiWindow* context, const GuiImage* image);
        virtual ~GuiImageViewer() = default;
        void setImage(const GuiImage* image);
        void setSubsection(int posx, int posy, int width, int height);
        void setMirror(bool mirrorX, bool mirrorY);
        inline const GuiImage* getImage() const {
            return img;
        }
        inline const ffw::Vec4i getSubsection() const {
            return sub;
        }
        inline const ffw::Vec2<bool> getMirror() const {
            return mirror;
        }
        void setLabel(const std::string& label);
        const std::string& getLabel() const;
        ffw::Vec2f getMinimumWrapSize() override;
        void setStyle(const GuiImageViewer::Style* style, bool defaults = false);
    private:
        void eventRender(const ffw::Vec2f& contentoffset, const ffw::Vec2f& contentsize) override;
        void eventHover(bool gained) override;
        void eventFocus(bool gained) override;
        virtual void eventThemeChanged(const GuiTheme* theme, bool defaults) override;
        const GuiImage* img;
        ffw::Vec4i sub;
        ffw::Vec2<bool> mirror;
        std::string label;
    };
}
#endif
```


    
  
