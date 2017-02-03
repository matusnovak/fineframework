/* This file is part of FineFramework project */
#ifndef FFW_MEDIA_IMAGE_LOADER
#define FFW_MEDIA_IMAGE_LOADER
#include "../config.h"
#include "../math.h"

namespace ffw{
	/**
	 * @ingroup media
	 */
	class FFW_API ImageReader: public ImageFormat {
	public:
		ImageReader();
		virtual ~ImageReader();

		virtual bool Open(const std::string& path) = 0;
		virtual void Close() = 0;
		virtual size_t ReadRow(void* dest) = 0;
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

