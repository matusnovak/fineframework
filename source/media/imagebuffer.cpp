/*** This file is part of FineFramework project ***/

#include "ffw/media/imagebuffer.h"

///=============================================================================
ffw::ImageBuffer::ImageBuffer(){
	ptr = NULL;
}

///=============================================================================
ffw::ImageBuffer::~ImageBuffer(){
	Destroy();
}

///=============================================================================
void ffw::ImageBuffer::Destroy(){
	if(ptr != NULL){
		delete[] ptr;
	}
	ptr = NULL;
	format = ffw::ImageType::INVALID;
	width = 0;
	height = 0;
}

///=============================================================================
bool ffw::ImageBuffer::Allocate(int w, int h, ffw::ImageType type){
	if(w <= 0 || h <= 0)return false;
	if(type == ffw::ImageType::INVALID)return false;
	Destroy();
	width = w;
	height = h;
	format = type;
	ptr = new unsigned char[GetHeight() * GetStrideSize()];
	return true;
}