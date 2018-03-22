---
search: false
---

# imageloader.h File Reference

**[Go to the documentation of this file.](imageloader_8h.md)**
Source: `include/ffw/media/imageloader.h`

    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
```cpp
/* This file is part of FineFramework project */
#ifndef FFW_MEDIA_IMAGE_LOADER
#define FFW_MEDIA_IMAGE_LOADER
#include "../config.h"
#include "../math/imagebuffer.h"
#include "../swapwrapper.h"

#pragma warning( push )
#pragma warning( disable : 4275)

namespace ffw{
    class FFW_API ImageReader: public ImageFormat {
    public:
        ImageReader();
        virtual ~ImageReader();

        virtual bool open(const std::string& path) = 0;
        virtual void close() = 0;
        virtual size_t readRow(void* dest) = 0;
        virtual bool getMipMap(int level);
        bool readAll(void* dest);
        bool readAll(ffw::ImageBuffer& buffer);
        inline bool eof() const {
            return row >= height;
        }
        inline operator bool() const {
            return loaded;
        }
        inline int getRowOffset() const {
            return row;
        }
        inline bool isOpen() const {
            return loaded;
        }
        inline int getNumOfMipMaps() const {
            return mipmaps;
        }
        inline int getMipMapOffset() const {
            return mipmapOffset;
        }
    protected:
        bool loaded;
        int row;
        int mipmapOffset;
        int mipmaps;
    };
};

#pragma warning( pop ) 
#endif

```


    
  
