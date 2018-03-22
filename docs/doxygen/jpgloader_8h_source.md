---
search: false
---

# jpgloader.h File Reference

**[Go to the documentation of this file.](jpgloader_8h.md)**
Source: `include/ffw/media/jpgloader.h`

    
    
    
    
    
    
    
      
    
    
    
```cpp
/* This file is part of FineFramework project */
#ifndef FFW_MEDIA_JPG_LOADER
#define FFW_MEDIA_JPG_LOADER
#include "imageloader.h"

namespace ffw {
    class FFW_API JpgLoader: public ImageReader {
    public:
        JpgLoader();
        JpgLoader(const JpgLoader& other) = delete;
        JpgLoader(JpgLoader&& other);
        void swap(JpgLoader& other);
        JpgLoader& operator = (const JpgLoader& other) = delete;
        JpgLoader& operator = (JpgLoader&& other);
        virtual ~JpgLoader();

        bool open(const std::string& path) override;
        size_t readRow(void* dest) override;
        void close() override;

    private:
        struct jpg_struct_s;
        jpg_struct_s* jpg_struct;
        bool cInfoInit;
        bool decompressInit;
        FILE* input;
    };
}

inline void swap(ffw::JpgLoader& first, ffw::JpgLoader& second){
    first.swap(second);
}

#endif
```


    
  
