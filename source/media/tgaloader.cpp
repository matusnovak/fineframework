/*** This file is part of FineFramework project ***/

#include "ffw/media/tgaloader.h"

///=============================================================================
ffw::TgaLoader::TgaLoader(){
	pixelsOffset = 0;
}

///=============================================================================
ffw::TgaLoader::TgaLoader(TgaLoader&& other){
	swap(other);
}

///=============================================================================
void ffw::TgaLoader::swap(TgaLoader& other){
	std::swap(input, other.input);
	std::swap(pixelsOffset, other.pixelsOffset);
}

///=============================================================================
ffw::TgaLoader& ffw::TgaLoader::operator = (TgaLoader&& other){
	if(this != &other){
		swap(other);
	}
	return *this;
}

///=============================================================================
ffw::TgaLoader::~TgaLoader(){
	close();
}

///=============================================================================
bool ffw::TgaLoader::open(const std::string& path){
	if(loaded)return false;

	input->open(path, std::ios::in | std::ios::binary);

	if(!input->is_open()){
		return false;
	}

	input->seekg(0, std::ios::end);
	size_t size = (size_t)input->tellg();
	input->seekg(0, std::ios::beg);

	if(size < 18){
		close();
		return false;
	}

	uint8_t idLength;
    uint8_t colorMapType;
    uint8_t imageType;
    uint16_t colorMapEntry;
    uint16_t colorMapLength;
    uint8_t colorMapSize;
    uint16_t originX;
    uint16_t originY;
    uint16_t w;
    uint16_t h;
    uint8_t bits;
    uint8_t imageDescriptor;
    //ffw::imageType type;

    // Read header
    input->read((char*)&idLength,           sizeof(uint8_t));
    input->read((char*)&colorMapType,       sizeof(uint8_t));
    input->read((char*)&imageType,          sizeof(uint8_t));
    input->read((char*)&colorMapEntry,      sizeof(uint16_t));
    input->read((char*)&colorMapLength,     sizeof(uint16_t));
    input->read((char*)&colorMapSize,       sizeof(uint8_t));
    input->read((char*)&originX,            sizeof(uint16_t));
    input->read((char*)&originY,            sizeof(uint16_t));
    input->read((char*)&w,                  sizeof(uint16_t));
    input->read((char*)&h,                  sizeof(uint16_t));
    input->read((char*)&bits,               sizeof(uint8_t));
    input->read((char*)&imageDescriptor,    sizeof(uint8_t));

	width = w;
	height = h;
	depth = 0;
	mipmaps = 1;

	// Read extra id
    if(idLength > 0){
		char data;
		for(uint8_t i = 0; i < idLength; i++){
			input->read(&data, 1);
		}
    }

	// Check if there is no compression
    if(colorMapType != 0){
		close();
		return false;
	}

    if(!(imageType == 2 || imageType == 3)){
		close();
		return false;
	}

	// get number of channels
    if(imageType == 3){
        format = ffw::ImageType::GRAYSCALE_8;

    } else if(imageType == 2 && bits == 16 && imageDescriptor == 1){
        format = ffw::ImageType::RGB_ALPHA_5551;

    } else if(imageType == 2 && bits == 24 && imageDescriptor == 0){
        format = ffw::ImageType::RGB_888;

    } else if(imageType == 2 && bits == 32 && imageDescriptor == 8){
        format = ffw::ImageType::RGB_ALPHA_8888;

    } else {
		close();
        return false;
    }

	if(size < 18 + height * getStrideSize()){
		std::cout << "size too low" << std::endl;
		close();
		return false;
	}

	pixelsOffset = (size_t)input->tellg();

	row = 0;
	loaded = true;
	return true;
}

///=============================================================================
void ffw::TgaLoader::close(){
	input->close();
	width = 0;
	height = 0;
	loaded = 0;
	row = 0;
	depth = 0;
	mipmaps = 0;
	mipmapOffset = 0;
	format = ImageType::INVALID;
}

///=============================================================================
size_t ffw::TgaLoader::readRow(void* dest){
	if(!loaded)return 0;
    if(row >= height)return 0;
    if(dest == NULL)return 0;

	input->seekg(pixelsOffset + (height - row - 1) * getStrideSize());
	
	switch(format){
		case ffw::ImageType::GRAYSCALE_8: {
			input->read((char*)dest, width);
			break;
		}
		case ffw::ImageType::RGB_ALPHA_5551: {
			input->read((char*)dest, width*2);

			unsigned char* ptr = (unsigned char*)dest;
			for(size_t i = 0; i < (size_t)width*2; i += 2){
				std::swap(ptr[i + 0], ptr[i + 1]);
			}
			break;
		}
		case ffw::ImageType::RGB_888: {
			input->read((char*)dest, width*3);

			unsigned char* ptr = (unsigned char*)dest;
			for(size_t i = 0; i < (size_t)width*3; i += 3){
				std::swap(ptr[i + 0], ptr[i + 2]);
			}
			break;
		}
		case ffw::ImageType::RGB_ALPHA_8888: {
			input->read((char*)dest, width*4);

			unsigned char* ptr = (unsigned char*)dest;
			for(size_t i = 0; i < (size_t)width*4; i += 4){
				std::swap(ptr[i + 0], ptr[i + 2]);
			}
			break;
		}
	}
	row++;

	return this->getStrideSize();
}