/*** This file is part of FineFramework project ***/

#include "ffw/media/imageutils.h"
#include "ffw/media/pngloader.h"
#include "ffw/media/pngsaver.h"
#include "ffw/media/bmploader.h"
#include "ffw/media/bmpsaver.h"
#include "ffw/media/jpgloader.h"
#include "ffw/media/jpgsaver.h"
#include "ffw/media/pbmloader.h"
#include "ffw/media/pbmsaver.h"
#include "ffw/media/tgaloader.h"
#include "ffw/media/tgasaver.h"
#include "ffw/media/tifloader.h"
#include "ffw/media/tifsaver.h"
#include "ffw/math/stringmath.h"
#include "ffw/media/ddsloader.h"
#include <memory>
#include "ffw/media/ddssaver.h"

///=============================================================================
ffw::ImageReader* ffw::openImageReader(const std::string& path){
	ffw::ImageReader* ret = NULL;
	
	std::string ext = ffw::toLower(ffw::extension(path));
	if     (ext == "png")ret = new ffw::PngLoader();
	else if(ext == "jpg")ret = new ffw::JpgLoader();
	else if(ext == "bmp")ret = new ffw::BmpLoader();
	else if(ext == "tga")ret = new ffw::TgaLoader();
	else if(ext == "pbm")ret = new ffw::PbmLoader();
	else if(ext == "tif")ret = new ffw::TifLoader();
	else if(ext == "tiff")ret = new ffw::TifLoader();
	else if(ext == "dds")ret = new ffw::DdsLoader();
	else return NULL;

	if(!ret->open(path)){
		delete ret;
		return NULL;
	}

	return ret;
}

///=============================================================================
ffw::ImageWriter* ffw::openImageWriter(const std::string& path, int width, int height, ffw::ImageType type, int quality){
	ffw::ImageWriter* ret = NULL;
	
	std::string ext = ffw::toLower(ffw::extension(path));
	if     (ext == "png")ret = new ffw::PngSaver();
	else if(ext == "jpg")ret = new ffw::JpgSaver();
	else if(ext == "bmp")ret = new ffw::BmpSaver();
	else if(ext == "tga")ret = new ffw::TgaSaver();
	else if(ext == "pbm")ret = new ffw::PbmSaver();
	else if(ext == "tif")ret = new ffw::TifSaver();
	else if(ext == "tiff")ret = new ffw::TifSaver();
	else if(ext == "dds")ret = new ffw::DdsSaver();
	else return NULL;

	if(!ret->open(path, width, height, type, quality)){
		delete ret;
		return NULL;
	}

	return ret;
}

///=============================================================================
bool ffw::readImage(const std::string& path, void** dest, int* width, int* height, ffw::ImageType* format, int* mips){
	ffw::ImageReader* loader = openImageReader(path);
	if(loader == NULL)return false;

	bool res = true;
	if (dest) {
		*dest = new unsigned char[loader->getAllocationSize(loader->getNumOfMipMaps())];

		res = loader->readAll(*dest);
		if (!res)delete[] (unsigned char*)*dest;
	}

	if (width)*width = loader->getWidth();
	if (height)*height = loader->getHeight();
	if (format)*format = loader->getImageType();
	if (mips)*mips = loader->getNumOfMipMaps();

	delete loader;
	return res;
}

///=============================================================================
bool ffw::writeImage(const std::string& path, const void* src, int width, int height, ffw::ImageType format, int quality, int mips){
	if(src == NULL)return false;

	ffw::ImageWriter* saver = openImageWriter(path, width, height, format, quality);
	if(saver == NULL)return false;

	while(!saver->eof()){
		const void* ptr = &((const unsigned char*)(src))[saver->getRowOffset() * saver->getStrideSize()];
		if(!saver->writeRow(ptr)){
			//std::cerr << "Error while writing row: " << saver->getRowOffset() << std::endl;
			delete saver;
			return false;
		}
	}

	saver->writeFooter();
	delete saver;
	return true;
}

///=============================================================================
bool ffw::readImage(const std::string& path, ffw::ImageBuffer& image){
	ffw::ImageReader* loader = openImageReader(path);
	if(loader == NULL)return false;

	bool res = loader->readAll(image);

	delete loader;
	return res;
}

///=============================================================================
bool ffw::writeImage(const std::string& path, const ffw::ImageBuffer& image, int quality){
	if(!image.isAllocated())return false;

	ffw::ImageWriter* saver = openImageWriter(path, image.getWidth(), image.getHeight(), image.getImageType(), quality);
	if(saver == NULL)return false;

	const unsigned char* src = image.getPtr();

	while(!saver->eof()){
		const void* ptr = &src[saver->getRowOffset() * saver->getStrideSize()];
		if(!saver->writeRow(ptr)){
			//std::cerr << "Error while writing row: " << saver->getRowOffset() << std::endl;
			delete saver;
			return false;
		}
	}

	saver->writeFooter();
	delete saver;
	return true;
}