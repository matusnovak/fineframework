/*** This file is part of FineFramework project ***/

#include "ffw/media/imagesaver.h"

///=============================================================================
ffw::ImageWriter::ImageWriter(){
	format = ImageType::INVALID;
	width = 0;
	height = 0;
	loaded = 0;
	row = 0;
}

///=============================================================================
ffw::ImageWriter::~ImageWriter(){
}
