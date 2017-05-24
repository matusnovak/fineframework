/* This file is part of FineFramework project */
#ifndef FFW_MEDIA_IMAGE_UTILS
#define FFW_MEDIA_IMAGE_UTILS
#include "../config.h"
#include "../math/imagebuffer.h"
namespace ffw {
	class ImageReader;
	class ImageWriter;
	/**
	* @ingroup media
	*/
	FFW_API ImageReader* openImageReader(const std::string& path);
	/**
	* @ingroup media
	*/
	FFW_API ImageWriter* openImageWriter(const std::string& path, int width, int height, ffw::ImageType type, int quality = 100);
	/**
	* @ingroup media
	*/
	bool FFW_API readImage(const std::string& path, void** dest, int* width, int* height, ffw::ImageType* format);
	/**
	* @ingroup media
	*/
	bool FFW_API writeImage(const std::string& path, const void* src, int width, int height, ffw::ImageType format, int quality = 100);
	/**
	* @ingroup media
	*/
	bool FFW_API readImage(const std::string& path, ffw::ImageBuffer& image);
	/**
	* @ingroup media
	*/
	ffw::ImageBuffer FFW_API readImage(const std::string& path);
	/**
	* @ingroup media
	*/
	bool FFW_API writeImage(const std::string& path, const ffw::ImageBuffer& image, int quality = 100);
}

#endif