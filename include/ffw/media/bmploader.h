/* This file is part of FineFramework project */
#ifndef FFW_MEDIA_BMP_LOADER
#define FFW_MEDIA_BMP_LOADER
#include "imageloader.h"
#include <fstream>

namespace ffw {
	/**
	 * @ingroup media
	 */
	class FFW_API BmpLoader: public ImageReader {
	public:
		BmpLoader();
		BmpLoader(const BmpLoader& other) = delete;
		BmpLoader(BmpLoader&& other);
		void swap(BmpLoader& other);
		BmpLoader& operator = (const BmpLoader& other) = delete;
		BmpLoader& operator = (BmpLoader&& other);
		virtual ~BmpLoader();

		bool Open(const std::string& path) override;
		size_t ReadRow(void* dest) override;
		virtual void Close();
	private:
		ffw::SwapWrapper<std::fstream> input;
		size_t pixelsOffset;
		bool invertBits;
	};
}

inline void swap(ffw::BmpLoader& first, ffw::BmpLoader& second){
	first.swap(second);
}

#endif