---
search: false
---

# renderwindow.h File Reference

**[Go to the documentation of this file.](renderwindow_8h.md)**
Source: `include/ffw/graphics/renderwindow.h`

    
    
    
    
    
    
    
    
    
    
```cpp
/* This file is part of FineFramework project */
#ifndef FFW_GRAPHICS_RENDER_WINDOW
#define FFW_GRAPHICS_RENDER_WINDOW
#include "rendercontext.h"

namespace ffw {
    class FFW_API RenderWindow {
    public:
        virtual void setPos(int posx, int posy) = 0;
        virtual void setSize(int width, int height) = 0;
        virtual ffw::Vec2i getPos() const = 0;
        virtual ffw::Vec2i getSize() const = 0;
        virtual void destroy() = 0;
        virtual bool shouldRender() const = 0;
        virtual void renderFrame() = 0;
        virtual void poolEvents() = 0;
        virtual void waitForEvents() = 0;
        virtual bool isInitialized() const = 0;
        virtual void shouldClose(bool close) = 0;
        virtual void show() = 0;
        virtual void hide() = 0;
        virtual void iconify() = 0;
        virtual void restore() = 0;
        virtual void maximize() = 0;
        virtual void setSingleBufferMode(bool enabled) = 0;
    };
};

#endif
```


    
  
