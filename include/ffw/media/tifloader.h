/* This file is part of FineFramework project */
#ifndef FFW_MEDIA_TIF_LOADER
#define FFW_MEDIA_TIF_LOADER
#include "imageloader.h"

#ifndef _TIFFIO_
typedef void* TIFFp;
#else
typedef TIFF* TIFFp;
#endif

namespace ffw {
	/**
	 * @ingroup media
	 */
	class FFW_API TifLoader: public ImageReader {
	public:
		TifLoader();
		TifLoader(const TifLoader& other) = delete;
		TifLoader(TifLoader&& other);
		void swap(TifLoader& other);
		TifLoader& operator = (const TifLoader& other) = delete;
		TifLoader& operator = (TifLoader&& other);
		virtual ~TifLoader();

		bool open(const std::string& path) override;
		size_t readRow(void* dest) override;
		void close() override;

	private:
		TIFFp tiff;
	};
}

inline void swap(ffw::TifLoader& first, ffw::TifLoader& second){
	first.swap(second);
}

#endif