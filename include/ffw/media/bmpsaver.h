/* This file is part of FineFramework project */
#ifndef FFW_MEDIA_BMP_SAVER
#define FFW_MEDIA_BMP_SAVER
#include "imagesaver.h"
#include <fstream>

namespace ffw {
	/**
	 * @ingroup media
	 */
	class FFW_API BmpSaver: public ImageWriter {
	public:
		BmpSaver();
		BmpSaver(const BmpSaver& other) = delete;
		BmpSaver(BmpSaver&& other);
		void swap(BmpSaver& other);
		BmpSaver& operator = (const BmpSaver& other) = delete;
		BmpSaver& operator = (BmpSaver&& other);
		virtual ~BmpSaver();

		bool Open(const std::string& path, int width, int height, ffw::ImageType type, int quality = 100) override;
		size_t WriteRow(const void* src) override;
		bool WriteFooter() override;
		virtual void Close();

	private:
		ffw::SwapWrapper<std::fstream> output;
		size_t pixelsOffset;
	};
}

inline void swap(ffw::BmpSaver& first, ffw::BmpSaver& second){
	first.swap(second);
}

#endif