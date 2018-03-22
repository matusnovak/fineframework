---
search: false
---

# guiimage.h File Reference

**[Go to the documentation of this file.](guiimage_8h.md)**
Source: `include/ffw/gui/guiimage.h`

    
    
    
    
    
    
    
    
    
    
    
```cpp
/* This file is part of FineFramework project */
#ifndef FFW_GUI_IMAGE
#define FFW_GUI_IMAGE
#include "../config.h"
namespace ffw {
    class GuiImage {
    public:
        virtual bool isCreated() const = 0;
        virtual void destroy() = 0;
        virtual int getWidth() const = 0;
        virtual int getHeight() const = 0;
    };
}
#endif
```


    
  
