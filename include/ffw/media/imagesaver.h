/* This file is part of FineFramework project */
#ifndef FFW_MEDIA_IMAGE_SAVER
#define FFW_MEDIA_IMAGE_SAVER
#include "../config.h"
#include "../math/imagebuffer.h"
#include "../swapwrapper.h"
namespace ffw{
	/**
	 * @ingroup media
	 */
	class FFW_API ImageWriter: public ImageFormat {
	public:
		ImageWriter();
		virtual ~ImageWriter();
		virtual bool open(const std::string& path, int width, int height, ffw::ImageType type, int quality = 100) = 0;
		virtual void close() = 0;
		virtual size_t writeRow(const void* src) = 0;
		virtual bool writeFooter() = 0;
		inline bool eof() const {
			return row >= height;
		}
		inline operator bool() const {
			return loaded;
		}
		inline int getRowOffset() const {
			return row;
		}
		inline bool isOpen() const {
			return loaded;
		}
	protected:
		bool loaded;
		int row;
	};
};
#endif

