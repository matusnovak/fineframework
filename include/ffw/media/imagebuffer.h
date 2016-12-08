/* This file is part of FineFramework project */
#ifndef FFW_MEDIA_IMAGE_BUFFER
#define FFW_MEDIA_IMAGE_BUFFER
#include "../config.h"
#include "../math.h"

namespace ffw{
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
		inline int GetBitsPerPixel() const {
			switch(format){
				case ImageType::BITMAP_1: return 1;
				case ImageType::GRAYSCALE_4: return 4;
				case ImageType::GRAYSCALE_ALPHA_4: return 8;
				case ImageType::GRAYSCALE_8: return 8;
				case ImageType::GRAYSCALE_ALPHA_8: return 16;
				case ImageType::GRAYSCALE_16: return 16;
				case ImageType::GRAYSCALE_ALPHA_16: return 32;
				case ImageType::GRAYSCALE_32: return 32;
				case ImageType::GRAYSCALE_ALPHA_32: return 64;
				case ImageType::RGB_565: return 16;
				case ImageType::RGB_888: return 24;
				case ImageType::RGB_161616: return 48;
				case ImageType::RGB_323232: return 96;
				case ImageType::RGB_ALPHA_5551: return 16;
				case ImageType::RGB_ALPHA_4444: return 16;
				case ImageType::RGB_ALPHA_8888: return 32;
				case ImageType::RGB_ALPHA_16161616: return 64;
				case ImageType::RGB_ALPHA_32323232: return 128;
				default: return 0;
			}
		}
		inline int GetBitDepth() const {
			switch(format){
				case ImageType::BITMAP_1: return 1;
				case ImageType::GRAYSCALE_4: return 4;
				case ImageType::GRAYSCALE_ALPHA_4: return 4;
				case ImageType::GRAYSCALE_8: return 8;
				case ImageType::GRAYSCALE_ALPHA_8: return 8;
				case ImageType::GRAYSCALE_16: return 16;
				case ImageType::GRAYSCALE_ALPHA_16: return 16;
				case ImageType::GRAYSCALE_32: return 32;
				case ImageType::GRAYSCALE_ALPHA_32: return 32;
				case ImageType::RGB_565: return 5;
				case ImageType::RGB_888: return 8;
				case ImageType::RGB_161616: return 16;
				case ImageType::RGB_323232: return 32;
				case ImageType::RGB_ALPHA_5551: return 5;
				case ImageType::RGB_ALPHA_4444: return 4;
				case ImageType::RGB_ALPHA_8888: return 8;
				case ImageType::RGB_ALPHA_16161616: return 16;
				case ImageType::RGB_ALPHA_32323232: return 32;
				default: return 0;
			}
		}
		inline int GetNumberOfChannels() const {
			switch(format){
				case ImageType::BITMAP_1: return 1;
				case ImageType::GRAYSCALE_4: return 1;
				case ImageType::GRAYSCALE_ALPHA_4: return 2;
				case ImageType::GRAYSCALE_8: return 1;
				case ImageType::GRAYSCALE_ALPHA_8: return 2;
				case ImageType::GRAYSCALE_16: return 1;
				case ImageType::GRAYSCALE_ALPHA_16: return 2;
				case ImageType::GRAYSCALE_32: return 1;
				case ImageType::GRAYSCALE_ALPHA_32: return 2;
				case ImageType::RGB_565: return 3;
				case ImageType::RGB_888: return 3;
				case ImageType::RGB_161616: return 3;
				case ImageType::RGB_323232: return 3;
				case ImageType::RGB_ALPHA_5551: return 4;
				case ImageType::RGB_ALPHA_4444: return 4;
				case ImageType::RGB_ALPHA_8888: return 4;
				case ImageType::RGB_ALPHA_16161616: return 4;
				case ImageType::RGB_ALPHA_32323232: return 4;
				default: return 0;
			}
		}
	protected:
		ffw::ImageType format;
		int width;
		int height;
	};

	class FFW_API ImageBuffer: public ImageFormat {
	public:
		ImageBuffer();
		virtual ~ImageBuffer();
		void Destroy();
		bool Allocate(int w, int h, ffw::ImageType type);
		inline unsigned char* GetPtr(){
			return ptr;
		}
		inline const unsigned char* GetPtr() const {
			return ptr;
		}
		inline size_t GetSize() const {
			return height * GetStrideSize();
		}
	private:
		unsigned char* ptr;
	};
};

#endif