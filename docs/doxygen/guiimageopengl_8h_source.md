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
#ifndef FFW_TEXTURE_2D
#error Please add #include <ffw/graphics/texture2d.h> before including guiimageopengl.h!
#endif
#include "guiimage.h"
namespace ffw {
    class GuiImageOpenGL: public GuiImage, public Texture2D {
    public:
        GuiImageOpenGL() {
            
        }
        virtual ~GuiImageOpenGL() {
            
        }
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


    
  
