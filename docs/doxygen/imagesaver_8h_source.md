---
search: false
---

# imagesaver.h File Reference

**[Go to the documentation of this file.](imagesaver_8h.md)**
Source: `include/ffw/media/imagesaver.h`

    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
```cpp
/* This file is part of FineFramework project */
#ifndef FFW_MEDIA_IMAGE_SAVER
#define FFW_MEDIA_IMAGE_SAVER
#include "../config.h"
#include "../math/imagebuffer.h"
#include "../swapwrapper.h"

#pragma warning( push )
#pragma warning( disable : 4275)

namespace ffw{
    class FFW_API ImageWriter: public ImageFormat {
    public:
        ImageWriter();
        virtual ~ImageWriter();
        virtual bool open(const std::string& path, int width, int height, ffw::ImageType type, int quality = 100, int mips = 1) = 0;
        virtual void close() = 0;
        virtual size_t writeRow(const void* src) = 0;
        bool writeAll(void* dest);
        bool writeAll(ffw::ImageBuffer& buffer);
        virtual bool setMipMap(int level);
        virtual bool writeFooter() = 0;
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


    
  
