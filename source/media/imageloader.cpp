/*** This file is part of FineFramework project ***/

#include "ffw/media/imageloader.h"

///=============================================================================
ffw::ImageReader::ImageReader(){
	format = ImageType::INVALID;
	width = 0;
	height = 0;
	loaded = 0;
	row = 0;
}

///=============================================================================
ffw::ImageReader::~ImageReader(){
}
