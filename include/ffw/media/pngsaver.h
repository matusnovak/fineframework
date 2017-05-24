/* This file is part of FineFramework project */
#ifndef FFW_MEDIA_PNG_SAVER
#define FFW_MEDIA_PNG_SAVER
#include "imagesaver.h"

#ifndef PNG_H
typedef void* png_structp;
typedef void* png_infop;
#endif

namespace ffw {
	/**
	 * @ingroup media
	 */
	class FFW_API PngSaver: public ImageWriter {
	public:
		PngSaver();
		PngSaver(const PngSaver& other) = delete;
		PngSaver(PngSaver&& other);
		void swap(PngSaver& other);
		PngSaver& operator = (const PngSaver& other) = delete;
		PngSaver& operator = (PngSaver&& other);
		virtual ~PngSaver();

		bool open(const std::string& path, int width, int height, ffw::ImageType type, int quality = 100) override;
		size_t writeRow(const void* src) override;
		bool writeFooter() override;
		void close() override;

	private:
		png_structp pngPtr;
		png_infop infoPtr;
		FILE* output;
	};
}

inline void swap(ffw::PngSaver& first, ffw::PngSaver& second){
	first.swap(second);
}

#endif