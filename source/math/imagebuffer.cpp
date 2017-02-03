/* This file is part of FineFramework project */
#include "ffw/config.h"
#include "ffw/math/imagebuffer.h"

///=============================================================================
int ffw::ImageFormat::GetBitsPerPixel() const {
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

///=============================================================================
int ffw::ImageFormat::GetBitDepth() const {
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

///=============================================================================
int ffw::ImageFormat::GetNumberOfChannels() const {
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
///=============================================================================
ffw::ImageBuffer::ImageBuffer() {
	ptr = NULL;
}

///=============================================================================
ffw::ImageBuffer::ImageBuffer(ImageBuffer&& other) :ptr(other.ptr) {
	other.ptr = NULL;
	width = other.width;
	height = other.height;
	format = other.format;
}

///=============================================================================
ffw::ImageBuffer::~ImageBuffer() {
	Destroy();
}

///=============================================================================
void ffw::ImageBuffer::Destroy() {
	if (ptr != NULL) {
		delete[] ptr;
	}
	ptr = NULL;
	format = ffw::ImageType::INVALID;
	width = 0;
	height = 0;
}

///=============================================================================
bool ffw::ImageBuffer::Allocate(int w, int h, ffw::ImageType type) {
	if (w <= 0 || h <= 0)return false;
	if (type == ffw::ImageType::INVALID)return false;
	Destroy();
	width = w;
	height = h;
	format = type;
	ptr = new unsigned char[GetHeight() * GetStrideSize()];
	return true;
}

///=============================================================================
ffw::ImageBuffer& ffw::ImageBuffer::operator = (ImageBuffer&& other) {
	if (this != &other) {
		std::swap(width, other.width);
		std::swap(height, other.height);
		std::swap(format, other.format);
		std::swap(ptr, other.ptr);
	}
	return *this;
}