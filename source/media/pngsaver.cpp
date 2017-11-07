/*** This file is part of FineFramework project ***/

#include <png.h>
#undef HAVE_UNISTD_H
#include <zlib.h>
#include "ffw/media/pngsaver.h"

///=============================================================================
static void user_error_fn(png_structp png_ptr, png_const_charp error_msg){(void)png_ptr; (void)error_msg;}
static void user_warning_fn(png_structp png_ptr, png_const_charp warning_msg){(void)png_ptr; (void)warning_msg;}

///=============================================================================
ffw::PngSaver::PngSaver(){
	pngPtr = NULL;
	infoPtr = NULL;
	output = NULL;
}

///=============================================================================
ffw::PngSaver::PngSaver(PngSaver&& other){
	swap(other);
}

///=============================================================================
void ffw::PngSaver::swap(PngSaver& other){
	std::swap(pngPtr, other.pngPtr);
	std::swap(infoPtr, other.infoPtr);
	std::swap(output, other.output);
}

///=============================================================================
ffw::PngSaver& ffw::PngSaver::operator = (PngSaver&& other){
	if(this != &other){
		swap(other);
	}
	return *this;
}

///=============================================================================
ffw::PngSaver::~PngSaver(){
	close();
}

///=============================================================================
bool ffw::PngSaver::open(const std::string& path, int w, int h, ffw::ImageType type, int quality, int mips){
	(void)mips;
	(void)quality;
	if(loaded)return false;
    if(w <= 0 || h <= 0)return false;

	switch(type){
		case ImageType::GRAYSCALE_8:
		case ImageType::GRAYSCALE_16:
		case ImageType::GRAYSCALE_ALPHA_8:
		case ImageType::GRAYSCALE_ALPHA_16:
		case ImageType::RGB_888:
		case ImageType::RGB_161616:
		case ImageType::RGB_ALPHA_8888:
		case ImageType::RGB_ALPHA_16161616:
			break;
		default:
			return false;
	}

	output = fopen(path.c_str(), "wb");

	if(!output){
		//std::cerr << "Cannot open file: " << path << " for writing!" << std::endl;
        return false;
    }

	pngPtr = png_create_write_struct(PNG_LIBPNG_VER_STRING, NULL, NULL, NULL);
    if (!pngPtr){
        fclose(output);
        return false;
    }

    infoPtr = png_create_info_struct(pngPtr);
    if (!infoPtr){
        fclose(output);
        return false;
    }

    if (setjmp(png_jmpbuf(pngPtr))){
        fclose(output);
        return false;
    }

    png_init_io(pngPtr, output);

    bool setSwap = false;
    png_byte colorType = 0;
    //int stride = 0;

    int bits;

	switch(type){
		case ImageType::GRAYSCALE_8:
			colorType = PNG_COLOR_TYPE_GRAY;
			bits = 8;
			setSwap = false;
			break;
		case ImageType::GRAYSCALE_16:
			colorType = PNG_COLOR_TYPE_GRAY;
			bits = 16;
			setSwap = true;
			break;
		case ImageType::GRAYSCALE_ALPHA_8:
			colorType = PNG_COLOR_TYPE_GRAY_ALPHA;
			bits = 8;
			setSwap = false;
			break;
		case ImageType::GRAYSCALE_ALPHA_16:
			colorType = PNG_COLOR_TYPE_GRAY_ALPHA;
			bits = 16;
			setSwap = true;
			break;
		case ImageType::RGB_888:
			colorType = PNG_COLOR_TYPE_RGB;
			bits = 8;
			setSwap = false;
			break;
		case ImageType::RGB_161616:
			colorType = PNG_COLOR_TYPE_RGB;
			bits = 16;
			setSwap = true;
			break;
		case ImageType::RGB_ALPHA_8888:
			colorType = PNG_COLOR_TYPE_RGB_ALPHA;
			bits = 8;
			setSwap = false;
			break;
		case ImageType::RGB_ALPHA_16161616:
			colorType = PNG_COLOR_TYPE_RGB_ALPHA;
			bits = 16;
			setSwap = true;
			break;
		default:
			return false;
	}

	png_set_IHDR(
        pngPtr,
        infoPtr,
        w, h,
        bits,
        colorType,
        PNG_INTERLACE_NONE,
        PNG_COMPRESSION_TYPE_DEFAULT,
        PNG_FILTER_TYPE_DEFAULT
    );

    png_write_info(pngPtr, infoPtr);

    //png_set_filler(pngPtr, 0, PNG_FILLER_AFTER);

    /*png_bytep* rowPointers = new png_bytep[Height];
    for(int y = 0; y < Height; y++){
        rowPointers[Height -y -1] = &Pixels[stride*y];
    }*/

    if(setSwap)
        png_set_swap(pngPtr);

    format = type;
	width = w;
	height = h;
	depth = 0;
	mipmaps = 1;

	row = 0;
    loaded = true;
	return true;
}

///=============================================================================
void ffw::PngSaver::close(){
	if(pngPtr != NULL){
		png_destroy_write_struct(&pngPtr, &infoPtr);
	}
	if(output != NULL){
		fclose(output);
	}
	output = NULL;
	pngPtr = NULL;
	infoPtr = NULL;

	width = 0;
	height = 0;
	loaded = 0;
	depth = 0;
	mipmaps = 0;
	row = 0;
	format = ImageType::INVALID;
}

///=============================================================================
size_t ffw::PngSaver::writeRow(const void* src){
	if(!loaded)return 0;
    if(row >= height)return 0;
    if(src == NULL)return 0;
	
	png_write_row(pngPtr, (png_bytep)src);
	row++;

	return this->getStrideSize();
}

///=============================================================================
bool ffw::PngSaver::writeFooter(){
	if(!loaded)return false;
    if(row != height)return false;

    png_write_end(pngPtr, NULL);

    return true;
}