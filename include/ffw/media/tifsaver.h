/* This file is part of FineFramework project */
#ifndef FFW_MEDIA_TIF_SAVER
#define FFW_MEDIA_TIF_SAVER
#include "imagesaver.h"

#ifndef _TIFFIO_
typedef void* TIFFp;
#else
typedef TIFF* TIFFp;
#endif

namespace ffw {
	/**
	 * @ingroup media
	 */
	class FFW_API TifSaver: public ImageWriter {
	public:
		TifSaver();
		TifSaver(const TifSaver& other) = delete;
		TifSaver(TifSaver&& other);
		void swap(TifSaver& other);
		TifSaver& operator = (const TifSaver& other) = delete;
		TifSaver& operator = (TifSaver&& other);
		virtual ~TifSaver();

		bool Open(const std::string& path, int width, int height, ffw::ImageType type, int quality = 100) override;
		size_t WriteRow(const void* src) override;
		bool WriteFooter() override;
		virtual void Close();

	private:
		TIFFp tiff;
	};
}

inline void swap(ffw::TifSaver& first, ffw::TifSaver& second){
	first.swap(second);
}

#endif