/* This file is part of FineFramework project */
#ifndef FFW_MEDIA_IMAGE_SAVER
#define FFW_MEDIA_IMAGE_SAVER
#include "imagebuffer.h"

namespace ffw{
	/**
	 * @ingroup media
	 */
	class FFW_API ImageWriter: public ImageFormat {
	public:
		ImageWriter();
		virtual ~ImageWriter();
		virtual bool Open(const std::string& path, int width, int height, ffw::ImageType type, int quality = 100) = 0;
		virtual void Close() = 0;
		virtual size_t WriteRow(const void* src) = 0;
		virtual bool WriteFooter() = 0;
		inline bool Eof() const {
			return row >= height;
		}
		inline operator bool() const {
			return loaded;
		}
		inline int GetRowOffset() const {
			return row;
		}
		inline bool IsOpen() const {
			return loaded;
		}
	protected:
		bool loaded;
		int row;
	};
};
#endif

