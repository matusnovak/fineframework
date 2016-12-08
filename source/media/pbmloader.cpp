/*** This file is part of FineFramework project ***/

#include "ffw/media/pbmloader.h"

///=============================================================================
ffw::PbmLoader::PbmLoader(){
}

///=============================================================================
ffw::PbmLoader::PbmLoader(PbmLoader&& other){
	swap(other);
}

///=============================================================================
void ffw::PbmLoader::swap(PbmLoader& other){
	std::swap(input, other.input);
}

///=============================================================================
ffw::PbmLoader& ffw::PbmLoader::operator = (PbmLoader&& other){
	if(this != &other){
		swap(other);
	}
	return *this;
}

///=============================================================================
ffw::PbmLoader::~PbmLoader(){
	Close();
}

///=============================================================================
bool ffw::PbmLoader::Open(const std::string& path){
	if(loaded)return false;

#ifdef FFW_WINDOWS
	input.open(WstrToAnsi(Utf8ToWstr(path)), std::ios::in | std::ios::binary);
#else
	input.open(path, std::ios::in | std::ios::binary);
#endif

	if(!input){
		return false;
	}

	std::string header[4];
	
	for(int i = 0; i < 4; i++){
		if(!std::getline(input, header[i])){
			Close();
			return false;
		}

		if(header[i].size() == 0){
			Close();
			return false;
		}
	}

	try{
        width = StringToVal<unsigned long>(header[1]);
        height = StringToVal<unsigned long>(header[2]);
    } catch(std::exception e){
		Close();
        return false;
    }

	size_t offset = (size_t)input.tellg();
	input.seekg(0, std::ios::end);
	size_t size = (size_t)input.tellg();
	input.seekg(offset);
    size_t dataLength = 0;

    if(header[0] == "P6" && header[3] == "255"){
        format = ffw::ImageType::RGB_888;
        dataLength = width*height*3;

    } else if(header[0] == "P6" && header[3] == "65535"){
        format = ffw::ImageType::RGB_161616;
        dataLength = width*height*6;

    } else if(header[0] == "PF" && header[3] == "-1.0000"){
        format = ffw::ImageType::RGB_323232;
        dataLength = width*height*12;

    } else if(header[0] == "P5" && header[3] == "255"){
        format = ffw::ImageType::GRAYSCALE_8;
        dataLength = width*height;

    } else if(header[0] == "P5" && header[3] == "65535"){
        format = ffw::ImageType::GRAYSCALE_16;
        dataLength = width*height*2;

    } else if(header[0] == "Pf" && header[3] == "-1.0000"){
        format = ffw::ImageType::GRAYSCALE_32;
        dataLength = width*height*4;

    } else {
		Close();
        return false;
    }

	if(dataLength + offset > size){
		Close();
		return false;
	}

	row = 0;
	loaded = true;
	return true;
}

///=============================================================================
void ffw::PbmLoader::Close(){
	input.close();
	width = 0;
	height = 0;
	loaded = 0;
	row = 0;
	format = ImageType::INVALID;
}

///=============================================================================
size_t ffw::PbmLoader::ReadRow(void* dest){
	if(!loaded)return 0;
    if(row >= height)return 0;
    if(dest == NULL)return 0;
	
	switch(format){
		case ffw::ImageType::GRAYSCALE_8: {
			input.read((char*)dest, width);
			break;
		}
		case ffw::ImageType::GRAYSCALE_16: {
			input.read((char*)dest, width*2);
			unsigned short* ptr = (unsigned short*)dest;
			for(size_t i = 0; i < (size_t)width; i++){
				ptr[i] = ByteSwap16(ptr[i]);
			}
			break;
		}
		case ffw::ImageType::GRAYSCALE_32: {
			input.read((char*)dest, width*4);
			break;
		}
		case ffw::ImageType::RGB_888: {
			input.read((char*)dest, width*3);
			break;
		}
		case ffw::ImageType::RGB_161616: {
			input.read((char*)dest, width*2*3);
			unsigned short* ptr = (unsigned short*)dest;
			for(size_t i = 0; i < (size_t)width*3; i++){
				ptr[i] = ByteSwap16(ptr[i]);
			}
			break;
		}
		case ffw::ImageType::RGB_323232: {
			input.read((char*)dest, width*4*3);
			break;
		}
	}
	row++;

	return this->GetStrideSize();
}