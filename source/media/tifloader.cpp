/*** This file is part of FineFramework project ***/

#include <tiffio.h>
#include "ffw/media/tifloader.h"

///=============================================================================
ffw::TifLoader::TifLoader(){
	tiff = NULL;
}

///=============================================================================
ffw::TifLoader::TifLoader(TifLoader&& other){
	swap(other);
}

///=============================================================================
void ffw::TifLoader::swap(TifLoader& other){
	std::swap(tiff, other.tiff);
}

///=============================================================================
ffw::TifLoader& ffw::TifLoader::operator = (TifLoader&& other){
	if(this != &other){
		swap(other);
	}
	return *this;
}

///=============================================================================
ffw::TifLoader::~TifLoader(){
	Close();
}

///=============================================================================
bool ffw::TifLoader::Open(const std::string& path){
	if(loaded)return false;

#ifdef FFW_WINDOWS
	tiff = TIFFOpen(WstrToAnsi(Utf8ToWstr(path)).c_str(), "rb");
#else
	tiff = TIFFOpen(path.c_str(), "rb");
#endif


	if(!tiff){
		return false;
	}

    size_t scanline;
    uint32_t w;
    uint32_t h;
    uint16_t bitsPerPixel;
    uint16_t compression;
    uint16_t dataType;
    //imageType type;

    uint16_t photometric;
    uint16_t samplesPerPixel;

    TIFFGetField(tiff, TIFFTAG_IMAGELENGTH, &h);
    TIFFGetField(tiff, TIFFTAG_IMAGEWIDTH, &w);
    TIFFGetField(tiff, TIFFTAG_BITSPERSAMPLE, &bitsPerPixel);
    TIFFGetField(tiff, TIFFTAG_COMPRESSION, &compression);
    TIFFGetField(tiff, TIFFTAG_PHOTOMETRIC, &photometric);
    TIFFGetField(tiff, TIFFTAG_SAMPLESPERPIXEL, &samplesPerPixel);
    TIFFGetField(tiff, TIFFTAG_DATATYPE, &dataType);

	scanline = TIFFScanlineSize(tiff);

	//std::cout << "bitsPerPixel: " << bitsPerPixel << std::endl;
	//std::cout << "samplesPerPixel: " << samplesPerPixel << std::endl;

	switch(bitsPerPixel){
		case 8: {
			switch(samplesPerPixel){
				case 1: {
					format = ffw::ImageType::GRAYSCALE_8;
					break;
				}
				case 2: {
					format = ffw::ImageType::GRAYSCALE_ALPHA_8;
					break;
				}
				case 3: {
					format = ffw::ImageType::RGB_888;
					break;
				}
				case 4: {
					format = ffw::ImageType::RGB_ALPHA_8888;
					break;
				}
				default: {
					Close();
					return false;
				}
			}
			break;
		}
		case 16: {
			switch(samplesPerPixel){
				case 1: {
					format = ffw::ImageType::GRAYSCALE_16;
					break;
				}
				case 2: {
					format = ffw::ImageType::GRAYSCALE_ALPHA_16;
					break;
				}
				case 3: {
					format = ffw::ImageType::RGB_161616;
					break;
				}
				case 4: {
					format = ffw::ImageType::RGB_ALPHA_16161616;
					break;
				}
				default: {
					Close();
					return false;
				}
			}
			break;
		}
		case 32: {
			switch(samplesPerPixel){
				case 1: {
					format = ffw::ImageType::GRAYSCALE_32;
					break;
				}
				case 2: {
					format = ffw::ImageType::GRAYSCALE_ALPHA_32;
					break;
				}
				case 3: {
					format = ffw::ImageType::RGB_323232;
					break;
				}
				case 4: {
					format = ffw::ImageType::RGB_ALPHA_32323232;
					break;
				}
				default: {
					Close();
					return false;
				}
			}
			break;
		}
		default: {
			Close();
			return false;
		}
	}

	width = w;
	height = h;

	row = 0;
	loaded = true;
	return true;
}

///=============================================================================
void ffw::TifLoader::Close(){
	if(tiff != NULL){
		TIFFClose(tiff);
	}
	tiff = NULL;
	width = 0;
	height = 0;
	loaded = 0;
	row = 0;
	format = ImageType::INVALID;
}

///=============================================================================
size_t ffw::TifLoader::ReadRow(void* dest){
	if(!loaded)return 0;
    if(row >= height)return 0;
    if(dest == NULL)return 0;

	TIFFReadScanline(tiff, dest, row);
	row++;

	return this->GetStrideSize();
}