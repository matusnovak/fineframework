/* This file is part of FineFramework project */
#ifndef FFW_MATH_IMAGE_BUFFER
#define FFW_MATH_IMAGE_BUFFER
#include "../config.h"
#include "../math.h"

namespace ffw {
	/**
	* @ingroup math
	*/
	class FFW_API ImageFormat {
	public:
		inline ImageType GetFormat() const {
			return format;
		}
		inline int GetWidth() const {
			return width;
		}
		inline int GetHeight() const {
			return height;
		}
		inline size_t GetStrideSize() const {
			return size_t(ceil(GetWidth() * (GetBitsPerPixel() / 8.0f)));
		}
		int GetBitsPerPixel() const;
		int GetBitDepth() const;
		int GetNumberOfChannels() const;
	protected:
		ffw::ImageType format;
		int width;
		int height;
	};
	/**
	* @ingroup math
	*/
	class FFW_API ImageBuffer: public ImageFormat {
	public:
		ImageBuffer();
		ImageBuffer(const ImageBuffer& other) = delete;
		ImageBuffer(ImageBuffer&& other);
		virtual ~ImageBuffer();
		inline bool IsAllocated() const {
			return ptr != NULL;
		}
		inline operator bool() const {
			return IsAllocated();
		}
		void Destroy();
		bool Allocate(int w, int h, ffw::ImageType type);
		inline unsigned char* GetPtr() {
			return ptr;
		}
		inline const unsigned char* GetPtr() const {
			return ptr;
		}
		inline size_t GetSize() const {
			return height * GetStrideSize();
		}
		ImageBuffer& operator = (const ImageBuffer& other) = delete;
		ImageBuffer& operator = (ImageBuffer&& other);
	private:
		unsigned char* ptr;
	};
};

#endif