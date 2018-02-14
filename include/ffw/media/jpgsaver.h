/* This file is part of FineFramework project */
#ifndef FFW_MEDIA_JPG_SAVER
#define FFW_MEDIA_JPG_SAVER
#include "imagesaver.h"

namespace ffw {
    /**
     * @ingroup media
     */
    class FFW_API JpgSaver: public ImageWriter {
    public:
        JpgSaver();
        JpgSaver(const JpgSaver& other) = delete;
        JpgSaver(JpgSaver&& other);
        void swap(JpgSaver& other);
        JpgSaver& operator = (const JpgSaver& other) = delete;
        JpgSaver& operator = (JpgSaver&& other);
        virtual ~JpgSaver();

        bool open(const std::string& path, int width, int height, ffw::ImageType type, int quality = 100, int mips = 1) override;
        size_t writeRow(const void* src) override;
        bool writeFooter() override;
        void close() override;

    private:
        struct jpg_struct_s;
        jpg_struct_s* jpg_struct;
        bool cInfoInit;
        bool compressInit;
        FILE* output;
    };
}

inline void swap(ffw::JpgSaver& first, ffw::JpgSaver& second){
    first.swap(second);
}

#endif