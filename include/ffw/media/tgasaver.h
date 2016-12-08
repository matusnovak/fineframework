/* This file is part of FineFramework project */
#ifndef FFW_MEDIA_TGA_SAVER
#define FFW_MEDIA_TGA_SAVER
#include "imagesaver.h"
#include <fstream>

namespace ffw {
	/**
	 * @ingroup media
	 */
	class FFW_API TgaSaver: public ImageWriter {
	public:
		TgaSaver();
		TgaSaver(const TgaSaver& other) = delete;
		TgaSaver(TgaSaver&& other);
		void swap(TgaSaver& other);
		TgaSaver& operator = (const TgaSaver& other) = delete;
		TgaSaver& operator = (TgaSaver&& other);
		virtual ~TgaSaver();

		bool Open(const std::string& path, int width, int height, ffw::ImageType type, int quality = 100) override;
		size_t WriteRow(const void* src) override;
		bool WriteFooter() override;
		virtual void Close();

	private:
		std::fstream output;
		size_t pixelsOffset;
	};
}

#endif