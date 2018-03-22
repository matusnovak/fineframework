---
search: false
---

# imageutils.h File Reference

**[Go to the documentation of this file.](imageutils_8h.md)**
Source: `include/ffw/media/imageutils.h`

    
    
    
    
    
    
    
    
    
    
```cpp
/* This file is part of FineFramework project */
#ifndef FFW_MEDIA_IMAGE_UTILS
#define FFW_MEDIA_IMAGE_UTILS
#include "../config.h"
#include "../math/imagebuffer.h"
namespace ffw {
    class ImageReader;
    class ImageWriter;
    FFW_API ImageReader* openImageReader(const std::string& path);
    FFW_API ImageWriter* openImageWriter(const std::string& path, int width, int height, ffw::ImageType type, int quality = 100);
    bool FFW_API readImage(const std::string& path, void** dest, int* width, int* height, ffw::ImageType* format, int* mips = NULL);
    bool FFW_API writeImage(const std::string& path, const void* src, int width, int height, ffw::ImageType format, int quality = 100, int mips = 1);
    bool FFW_API readImage(const std::string& path, ffw::ImageBuffer& image);
    bool FFW_API writeImage(const std::string& path, const ffw::ImageBuffer& image, int quality = 100);
}

#endif
```


    
  
