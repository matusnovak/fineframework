/* This file is part of FineFramework project */
#ifndef FFW_MATH_IMAGE_BUFFER
#define FFW_MATH_IMAGE_BUFFER
#include "../config.h"
#include "vec4.h"
#include <cstring>

namespace ffw {
	/**
	* @ingroup math
	*/
	class FFW_API ImageFormat {
	public:
		inline ImageType getImageType() const {
			return format;
		}
		inline int getWidth() const {
			return width;
		}
		inline int getHeight() const {
			return height;
		}
		inline size_t getStrideSize() const {
			return size_t(ceil(getWidth() * (getBitsPerPixel() / 8.0f)));
		}
		inline int getBitsPerPixel() const {
			switch (format) {
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
		inline int getBitDepth() const {
			switch (format) {
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
		inline int getNumberOfChannels() const {
			switch (format) {
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
	/**
	* @ingroup math
	*/
	class FFW_API ImageBuffer: public ImageFormat {
	public:
		inline ImageBuffer() :ptr(NULL) {

		}
		ImageBuffer(const ImageBuffer& other) = delete;
		inline ImageBuffer(ImageBuffer&& other):ptr(other.ptr) {
			other.ptr = NULL;
			width = other.width;
			height = other.height;
			format = other.format;
		}
		inline virtual ~ImageBuffer() {
			destroy();
		}
		inline bool isAllocated() const {
			return ptr != NULL;
		}
		inline operator bool() const {
			return isAllocated();
		}
		void swap(ImageBuffer& second) {
			std::swap(width, second.width);
			std::swap(height, second.height);
			std::swap(format, second.format);
			std::swap(ptr, second.ptr);
		}
		inline void destroy() {
			if (ptr != NULL) {
				delete[] ptr;
			}
			ptr = NULL;
			format = ffw::ImageType::INVALID;
			width = 0;
			height = 0;
		}
		inline bool allocate(int w, int h, ffw::ImageType type, const void* pixels = NULL) {
			if (w <= 0 || h <= 0)return false;
			if (type == ffw::ImageType::INVALID)return false;

			// Test if new size is exactly same
			if (ptr != NULL) {
				size_t oldSize = getHeight() * getStrideSize();
				width = w;
				format = type;
				size_t newSize = h * getStrideSize();
				if (oldSize == newSize) {
					height = h;

					if(pixels != NULL)
						memcpy(ptr, pixels, getHeight() * getStrideSize());
					return true;
				}
			}
			// destroy image and allocate data
			destroy();
			width = w;
			height = h;
			format = type;
			ptr = new unsigned char[getHeight() * getStrideSize()];
			if (pixels != NULL)
				memcpy(ptr, pixels, getHeight() * getStrideSize());
			return true;
		}
		inline unsigned char* getPtr() {
			return ptr;
		}
		inline const unsigned char* getPtr() const {
			return ptr;
		}
		inline size_t getSize() const {
			return height * getStrideSize();
		}
		ImageBuffer& operator = (const ImageBuffer& other) = delete;
		inline ImageBuffer& operator = (ImageBuffer&& other) {
			if (this != &other) {
				swap(other);
			}
			return *this;
		}
	private:
		unsigned char* ptr;
	};
	/**
	* @ingroup math
	*/
	template<typename T>
	ffw::Vec4<T> containImage(T imgwidth, T imgheight, T maxwidth, T maxheight) {
		float frameAspect = imgheight / float(imgwidth);
		ffw::Vec4<T> ret;

		if (maxwidth*frameAspect <= maxheight) {
			ret.z = maxwidth;
			ret.w = T(maxwidth*frameAspect);
			ret.x = 0;
			ret.y = (maxheight - ret.w) / 2;

		}
		else {
			ret.z = T(maxheight / frameAspect);
			ret.w = maxheight;
			ret.x = (maxwidth - ret.z) / 2;
			ret.y = 0;
		}

		return ret;
	}
	/**
	* @ingroup math
	*/
	template<typename T>
	ffw::Vec4<T> coverImage(T imgwidth, T imgheight, T maxwidth, T maxheight) {
		float imgAspect = imgheight / float(imgwidth);
		ffw::Vec4<T> ret;

		// Target area is vertical
		if (maxheight / float(maxwidth) >= 1.0f) {
			// Image is vertical
			if (imgAspect >= 1.0f) {
				ret.z = T(maxheight / imgAspect);
				ret.w = maxheight;
				if (ret.z < maxwidth) {
					ret.z = maxwidth;
					ret.w = T(maxwidth*imgAspect);
				}
				// Image is horizontal
			}
			else {
				ret.z = T(maxheight / imgAspect);
				ret.w = maxheight;
			}
			// Target area is horizontal
		}
		else {
			// Image is vertical
			if (imgAspect >= 1.0f) {
				ret.z = maxwidth;
				ret.w = T(maxwidth*imgAspect);
				// Image is horizontal
			}
			else {
				ret.z = maxwidth;
				ret.w = T(maxwidth*imgAspect);
				if (ret.w < maxheight) {
					ret.z = T(maxheight / imgAspect);
					ret.w = maxheight;
				}
			}
		}
		ret.x = (ret.z - maxwidth) / -2;
		ret.y = (ret.w - maxheight) / -2;
		return ret;
	}
};

inline void swap(ffw::ImageBuffer& first, ffw::ImageBuffer& second) {
	first.swap(second);
}

#endif