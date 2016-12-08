/* This file is part of FineFramework project */
#ifndef FFW_MEDIA_PNG_LOADER
#define FFW_MEDIA_PNG_LOADER
#include "imageloader.h"

#ifndef PNG_H
typedef void* png_structp;
typedef void* png_infop;
#endif

namespace ffw {
	/**
	 * @ingroup media
	 */
	class FFW_API PngLoader: public ImageReader {
	public:
		PngLoader();
		PngLoader(const PngLoader& other) = delete;
		PngLoader(PngLoader&& other);
		void swap(PngLoader& other);
		PngLoader& operator = (const PngLoader& other) = delete;
		PngLoader& operator = (PngLoader&& other);
		virtual ~PngLoader();

		bool Open(const std::string& path) override;
		size_t ReadRow(void* dest) override;
		virtual void Close();

	private:
		png_structp pngPtr;
		png_infop infoPtr;
		FILE* input;
	};
}

#endif