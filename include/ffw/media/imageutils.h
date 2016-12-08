/* This file is part of FineFramework project */
#ifndef FFW_MEDIA_IMAGE_UTILS
#define FFW_MEDIA_IMAGE_UTILS
#include "../config.h"
#include "../math.h"
#include "imagebuffer.h"

namespace ffw {
	class ImageReader;
	class ImageWriter;

	FFW_API ImageReader* OpenImageReader(const std::string& path);
	FFW_API ImageWriter* OpenImageWriter(const std::string& path, int width, int height, ffw::ImageType type, int quality = 100);
	bool FFW_API ReadImage(const std::string& path, void** dest, int* width, int* height, ffw::ImageType* format);
	bool FFW_API WriteImage(const std::string& path, const void* src, int width, int height, ffw::ImageType format, int quality = 100);
	bool FFW_API ReadImage(const std::string& path, ffw::ImageBuffer* image);
	bool FFW_API WriteImage(const std::string& path, const ffw::ImageBuffer* image, int quality = 100);
#ifdef FFW_GRAPHICS_MODULE
	inline bool ReadImage(const std::string& path, const ffw::RenderContext* context, ffw::Texture2D* texture){
		if(texture == NULL)return false;

		ffw::ImageReader* loader = OpenImageReader(path);
		if(loader == NULL)return false;
		
		ffw::OpenGLImageType openglType = ffw::GetOpenGLImageType(loader->GetFormat());
		if(!openglType){
			std::cerr << "Error while getting opengl type!" << std::endl;
			delete loader;
			return false;
		}

		if(!texture->Create(context, loader->GetWidth(), loader->GetHeight(), openglType.internalFormat, openglType.format, openglType.type)){
			std::cerr << "Error while creating texture!" << std::endl;
			delete loader;
			return false;
		}

		size_t strideSize = loader->GetStrideSize();
		unsigned char* pixels = new unsigned char[strideSize];
		if(pixels == NULL){
			std::cerr << "Error while allocating stride!" << std::endl;
			delete loader;
			return false;
		}

		while(!loader->Eof()){
			if(!loader->ReadRow(pixels)){
				std::cerr << "Error while reading row: " << loader->GetRowOffset() << std::endl;
				delete loader;
				return false;
			} else {
				texture->SetPixels(0, 0, loader->GetRowOffset() -1, loader->GetWidth(), 1, pixels);
			}
		}

		delete loader;
		return true;
	}
#endif
}

#endif