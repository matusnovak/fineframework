/* This file is part of FineFramework project */
#ifndef FFW_MEDIA_TGA_LOADER
#define FFW_MEDIA_TGA_LOADER
#include "imageloader.h"
#include <fstream>

namespace ffw {
	/**
	 * @ingroup media
	 */
	class FFW_API TgaLoader: public ImageReader {
	public:
		TgaLoader();
		TgaLoader(const TgaLoader& other) = delete;
		TgaLoader(TgaLoader&& other);
		void swap(TgaLoader& other);
		TgaLoader& operator = (const TgaLoader& other) = delete;
		TgaLoader& operator = (TgaLoader&& other);
		virtual ~TgaLoader();

		bool Open(const std::string& path) override;
		size_t ReadRow(void* dest) override;
		virtual void Close();

	private:
		ffw::SwapWrapper<std::fstream> input;
		size_t pixelsOffset;
	};
}

inline void swap(ffw::TgaLoader& first, ffw::TgaLoader& second){
	first.swap(second);
}

#endif