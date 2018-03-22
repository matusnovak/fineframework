---
search: false
---

# guiimageopengl.h File Reference

**[Go to the documentation of this file.](guiimageopengl_8h.md)**
Source: `include/ffw/gui/guiimageopengl.h`

    
    
    
    
    
    
    
    
    
    
```cpp
/* This file is part of FineFramework project */
#ifndef FFW_GUI_IMAGE_OPENGL
#define FFW_GUI_IMAGE_OPENGL
#include "guiimage.h"
namespace ffw {
    class GuiImageOpenGL: public GuiImage, public Texture2D {
    public:
        inline bool isCreated() const override {
            return Texture2D::isCreated();
        }
        inline void destroy() override {
            Texture2D::destroy();
        }
        inline int getWidth() const override {
            return Texture2D::getWidth();
        }
        inline int getHeight() const override {
            return Texture2D::getHeight();
        }
    };
}
#endif
```


    
  
