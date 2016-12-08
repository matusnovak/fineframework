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
#include <memory>

///=============================================================================
ffw::ImageReader* ffw::OpenImageReader(const std::string& path){
	ffw::ImageReader* ret = NULL;
	
	std::string ext = ffw::ToLower(ffw::Extension(path));
	if     (ext == "png")ret = new ffw::PngLoader();
	else if(ext == "jpg")ret = new ffw::JpgLoader();
	else if(ext == "bmp")ret = new ffw::BmpLoader();
	else if(ext == "tga")ret = new ffw::TgaLoader();
	else if(ext == "pbm")ret = new ffw::PbmLoader();
	else if(ext == "tif")ret = new ffw::TifLoader();
	else if(ext == "tiff")ret = new ffw::TifLoader();
	else return NULL;

	if(!ret->Open(path)){
		delete ret;
		return NULL;
	}

	return ret;
}

///=============================================================================
ffw::ImageWriter* ffw::OpenImageWriter(const std::string& path, int width, int height, ffw::ImageType type, int quality){
	ffw::ImageWriter* ret = NULL;
	
	std::string ext = ffw::ToLower(ffw::Extension(path));
	if     (ext == "png")ret = new ffw::PngSaver();
	else if(ext == "jpg")ret = new ffw::JpgSaver();
	else if(ext == "bmp")ret = new ffw::BmpSaver();
	else if(ext == "tga")ret = new ffw::TgaSaver();
	else if(ext == "pbm")ret = new ffw::PbmSaver();
	else if(ext == "tif")ret = new ffw::TifSaver();
	else if(ext == "tiff")ret = new ffw::TifSaver();
	else return NULL;

	if(!ret->Open(path, width, height, type, quality)){
		delete ret;
		return NULL;
	}

	return ret;
}

///=============================================================================
bool ffw::ReadImage(const std::string& path, void** dest, int* width, int* height, ffw::ImageType* format){
	ffw::ImageReader* loader = OpenImageReader(path);
	if(loader == NULL)return false;

	if(width != NULL)*width = loader->GetWidth();
	if(height != NULL)*height = loader->GetHeight();
	if(format != NULL)*format = loader->GetFormat();

	if(dest == NULL){
		delete loader;
		return true;
	}

	*dest = new unsigned char[loader->GetHeight() * loader->GetStrideSize()];

	while(!loader->Eof()){
		void* ptr = &((unsigned char*)(*dest))[loader->GetRowOffset() * loader->GetStrideSize()];
		if(!loader->ReadRow(ptr)){
			//std::cerr << "Error while reading row: " << loader->GetRowOffset() << std::endl;
			delete loader;
			return false;
		}
	}

	delete loader;
	return true;
}

///=============================================================================
bool ffw::WriteImage(const std::string& path, const void* src, int width, int height, ffw::ImageType format, int quality){
	if(src == NULL)return false;

	ffw::ImageWriter* saver = OpenImageWriter(path, width, height, format, quality);
	if(saver == NULL)return false;

	while(!saver->Eof()){
		const void* ptr = &((const unsigned char*)(src))[saver->GetRowOffset() * saver->GetStrideSize()];
		if(!saver->WriteRow(ptr)){
			//std::cerr << "Error while writing row: " << saver->GetRowOffset() << std::endl;
			delete saver;
			return false;
		}
	}

	saver->WriteFooter();
	delete saver;
	return true;
}

///=============================================================================
bool ffw::ReadImage(const std::string& path, ffw::ImageBuffer* image){
	if(image == NULL)return false;
	
	ffw::ImageReader* loader = OpenImageReader(path);
	if(loader == NULL)return false;

	if(!image->Allocate(loader->GetWidth(), loader->GetHeight(), loader->GetFormat()))return false;

	unsigned char* dest = image->GetPtr();

	while(!loader->Eof()){
		void* ptr = &dest[loader->GetRowOffset() * loader->GetStrideSize()];
		if(!loader->ReadRow(ptr)){
			//std::cerr << "Error while reading row: " << loader->GetRowOffset() << std::endl;
			delete loader;
			return false;
		}
	}

	delete loader;
	return true;
}

///=============================================================================
bool ffw::WriteImage(const std::string& path, const ffw::ImageBuffer* image, int quality){
	if(image == NULL)return false;

	ffw::ImageWriter* saver = OpenImageWriter(path, image->GetWidth(), image->GetHeight(), image->GetFormat(), quality);
	if(saver == NULL)return false;

	const unsigned char* src = image->GetPtr();

	while(!saver->Eof()){
		const void* ptr = &src[saver->GetRowOffset() * saver->GetStrideSize()];
		if(!saver->WriteRow(ptr)){
			//std::cerr << "Error while writing row: " << saver->GetRowOffset() << std::endl;
			delete saver;
			return false;
		}
	}

	saver->WriteFooter();
	delete saver;
	return true;
}