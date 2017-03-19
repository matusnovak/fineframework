/*** This file is part of FineFramework project ***/
#if defined(FFW_WINDOWS)
#define NOMINMAX
#include <Windows.h>
#endif
#include <stdio.h>
#include <tiffio.h>
#include "ffw/media/tifsaver.h"

///=============================================================================
static void DummyHandler(const char* module, const char* fmt, va_list ap){
    // ignore errors and warnings (or handle them your own way)
}

///=============================================================================
ffw::TifSaver::TifSaver(){
	tiff = NULL;
}

///=============================================================================
ffw::TifSaver::TifSaver(TifSaver&& other){
	swap(other);
}

///=============================================================================
void ffw::TifSaver::swap(TifSaver& other){
	std::swap(tiff, other.tiff);
}

///=============================================================================
ffw::TifSaver& ffw::TifSaver::operator = (TifSaver&& other){
	if(this != &other){
		swap(other);
	}
	return *this;
}

///=============================================================================
ffw::TifSaver::~TifSaver(){
	close();
}

///=============================================================================
bool ffw::TifSaver::open(const std::string& path, int w, int h, ffw::ImageType type, int quality){
	if(loaded)return false;
    if(w <= 0 || h <= 0)return false;
	quality = ffw::clamp(quality, 0, 100);

	switch(type){
		case ImageType::GRAYSCALE_8:
		case ImageType::GRAYSCALE_16:
		case ImageType::GRAYSCALE_32:
		case ImageType::GRAYSCALE_ALPHA_8:
		case ImageType::GRAYSCALE_ALPHA_16:
		case ImageType::GRAYSCALE_ALPHA_32:
		case ImageType::RGB_888:
		case ImageType::RGB_161616:
		case ImageType::RGB_323232:
		case ImageType::RGB_ALPHA_8888:
		case ImageType::RGB_ALPHA_16161616:
		case ImageType::RGB_ALPHA_32323232:
			break;
		default:
			return false;
	}

	TIFFSetWarningHandler(DummyHandler);

#ifdef FFW_WINDOWS
	tiff = TIFFOpen(wstrToAnsi(utf8ToWstr(path)).c_str(), "w");
#else
	tiff = TIFFOpen(path.c_str(), "w");
#endif

	if(!tiff){
		//std::cerr << "Cannot open file: " << path << " for writing!" << std::endl;
        return false;
    }

	uint16_t bitsPerPixel = 0;
    uint16_t samplesPerPixel = 0;
    uint16_t photometric = 0;
    uint16_t dataType = 0;

	switch(type){
		case ImageType::GRAYSCALE_8:{
			bitsPerPixel = 8;
			samplesPerPixel = 1;
			photometric = 1;
			dataType = 0;
			break;
		}
		case ImageType::GRAYSCALE_16:{
			bitsPerPixel = 16;
			samplesPerPixel = 1;
			photometric = 1;
			dataType = 0;
			break;
		}
		case ImageType::GRAYSCALE_32:{
			bitsPerPixel = 32;
			samplesPerPixel = 1;
			photometric = 1;
			dataType = 3;
			break;
		}
		case ImageType::GRAYSCALE_ALPHA_8:{
			bitsPerPixel = 8;
			samplesPerPixel = 2;
			photometric = 1;
			dataType = 0;
			break;
		}
		case ImageType::GRAYSCALE_ALPHA_16:{
			bitsPerPixel = 16;
			samplesPerPixel = 2;
			photometric = 1;
			dataType = 0;
			break;
		}
		case ImageType::GRAYSCALE_ALPHA_32:{
			bitsPerPixel = 32;
			samplesPerPixel = 2;
			photometric = 1;
			dataType = 3;
			break;
		}
		case ImageType::RGB_888:{
			bitsPerPixel = 8;
			samplesPerPixel = 3;
			photometric = 2;
			dataType = 0;
			break;
		}
		case ImageType::RGB_161616:{
			bitsPerPixel = 16;
			samplesPerPixel = 3;
			photometric = 2;
			dataType = 0;
			break;
		}
		case ImageType::RGB_323232:{
			bitsPerPixel = 32;
			samplesPerPixel = 3;
			photometric = 2;
			dataType = 3;
			break;
		}
		case ImageType::RGB_ALPHA_8888:{
			bitsPerPixel = 8;
			samplesPerPixel = 4;
			photometric = 2;
			dataType = 0;
			break;
		}
		case ImageType::RGB_ALPHA_16161616:{
			bitsPerPixel = 16;
			samplesPerPixel = 4;
			photometric = 2;
			dataType = 0;
			break;
		}
		case ImageType::RGB_ALPHA_32323232:{
			bitsPerPixel = 32;
			samplesPerPixel = 4;
			photometric = 2;
			dataType = 3;
			break;
		}
		default:{
			close();
			return false;
		}
	}

	format = type;
	width = w;
	height = h;

	TIFFSetField(tiff, TIFFTAG_IMAGEWIDTH, w);
    TIFFSetField(tiff, TIFFTAG_IMAGELENGTH, h);
    TIFFSetField(tiff, TIFFTAG_BITSPERSAMPLE, bitsPerPixel);
    TIFFSetField(tiff, TIFFTAG_SAMPLESPERPIXEL, samplesPerPixel);
    TIFFSetField(tiff, TIFFTAG_ORIENTATION, ORIENTATION_TOPLEFT);
    TIFFSetField(tiff, TIFFTAG_PLANARCONFIG, PLANARCONFIG_CONTIG);
    TIFFSetField(tiff, TIFFTAG_PHOTOMETRIC, photometric);
    TIFFSetField(tiff, TIFFTAG_DATATYPE, dataType);

    uint32 rowsperstrip = TIFFDefaultStripSize(tiff, static_cast<uint32>(-1));

    TIFFSetField(tiff, TIFFTAG_ROWSPERSTRIP, rowsperstrip);
    TIFFSetField(tiff, TIFFTAG_COMPRESSION, COMPRESSION_PACKBITS);

    // Start CCITTFAX3 setting

    //uint32 group3options = GROUP3OPT_FILLBITS+GROUP3OPT_2DENCODING;
    //TIFFSetField(tiff, TIFFTAG_GROUP3OPTIONS, group3options);
    //TIFFSetField(tiff, TIFFTAG_FAXMODE, FAXMODE_CLASSF);
    //TIFFSetField(tiff, TIFFTAG_ORIENTATION, ORIENTATION_TOPLEFT);
    //TIFFSetField(tiff, TIFFTAG_ROWSPERSTRIP, -1L);


    // End CCITTFAX3 setting

    //TIFFSetField(tiff, TIFFTAG_PHOTOMETRIC, PHOTOMETRIC_MINISBLACK);

    //TIFFSetField(tiff, TIFFTAG_FILLORDER, FILLORDER_MSB2LSB);
    //TIFFSetField(tiff, TIFFTAG_PLANARCONFIG, PLANARCONFIG_CONTIG);

    TIFFSetField(tiff, TIFFTAG_RESOLUTIONUNIT, RESUNIT_INCH);
    TIFFSetField(tiff, TIFFTAG_XRESOLUTION, 72.0);
    TIFFSetField(tiff, TIFFTAG_YRESOLUTION, 72.0);

    //char page_number[20];
    //sprintf(page_number, "Page %d", 1);

    //TIFFSetField(tiff, TIFFTAG_SUBFILETYPE, FILETYPE_PAGE);
    //TIFFSetField(tiff, TIFFTAG_PAGENUMBER, 1, 1);
    //TIFFSetField(tiff, TIFFTAG_PAGENAME, page_number);

	row = 0;
    loaded = true;
	return true;
}

///=============================================================================
void ffw::TifSaver::close(){
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
size_t ffw::TifSaver::writeRow(const void* src){
	if(!loaded)return 0;
    if(row >= height)return 0;
    if(src == NULL)return 0;

	if(TIFFWriteScanline(tiff, (void*)src, row, 0) == -1){
        close();
        return false;
    }
	row++;

	return this->getStrideSize();
}

///=============================================================================
bool ffw::TifSaver::writeFooter(){
	if(!loaded)return false;
    if(row != height)return false;

    return true;
}
