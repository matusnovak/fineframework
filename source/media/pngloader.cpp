/*** This file is part of FineFramework project ***/

#include <png.h>
#undef HAVE_UNISTD_H
#include <zlib.h>
#include "ffw/media/pngloader.h"

///=============================================================================
static void user_error_fn(png_structp png_ptr, png_const_charp error_msg){(void)png_ptr; (void)error_msg;}
static void user_warning_fn(png_structp png_ptr, png_const_charp warning_msg){(void)png_ptr; (void)warning_msg;}

///=============================================================================
ffw::PngLoader::PngLoader(){
	pngPtr = NULL;
	infoPtr = NULL;
	input = NULL;
}

///=============================================================================
ffw::PngLoader::PngLoader(PngLoader&& other){
	swap(other);
}

///=============================================================================
void ffw::PngLoader::swap(PngLoader& other){
	std::swap(pngPtr, other.pngPtr);
	std::swap(infoPtr, other.infoPtr);
	std::swap(input, other.input);
}

///=============================================================================
ffw::PngLoader& ffw::PngLoader::operator = (PngLoader&& other){
	if(this != &other){
		swap(other);
	}
	return *this;
}

///=============================================================================
ffw::PngLoader::~PngLoader(){
	Close();
}

///=============================================================================
bool ffw::PngLoader::Open(const std::string& path){
	if(loaded)return false;

#ifdef FFW_WINDOWS
	input  = fopen(WstrToAnsi(Utf8ToWstr(path)).c_str(), "rb");
#else
	input = fopen(path.c_str(), "rb");
#endif

	if(!input){
		return false;
	}

	uint8_t* header = new uint8_t[8];
    fread(header, 1, 8, input);

	if(png_sig_cmp(header, 0, 8)){
		fclose(input);
        return false;
    }

    pngPtr = png_create_read_struct(PNG_LIBPNG_VER_STRING, NULL, user_error_fn, user_warning_fn);

    if(!pngPtr){
		fclose(input);
		//std::cout << "png_create_read_struct error" << std::endl;
        return false;
    }

    infoPtr = png_create_info_struct(pngPtr);
    if(!infoPtr){
		fclose(input);
		//std::cout << "png_create_info_struct error" << std::endl;
        return false;
    }

    if(setjmp(png_jmpbuf(pngPtr))){
		fclose(input);
		//std::cout << "setjmp error" << std::endl;
        return false;
    }

    png_init_io(pngPtr, input);
    png_set_sig_bytes(pngPtr, 8);

    png_read_info(pngPtr, infoPtr);

    width = png_get_image_width(pngPtr, infoPtr);
    height = png_get_image_height(pngPtr, infoPtr);
    png_byte colorType = png_get_color_type(pngPtr, infoPtr);
    png_byte bits = png_get_bit_depth(pngPtr, infoPtr);

    //if(bitDepth == 16)
        //png_set_strip_16(pngPtr);

    if (bits == 16)
        png_set_swap(pngPtr);

    if(colorType == PNG_COLOR_TYPE_PALETTE)
        png_set_palette_to_rgb(pngPtr);

    if(bits == 1){
        if(colorType == PNG_COLOR_TYPE_GRAY){
            format = ImageType::GRAYSCALE_8;
        } else {
			fclose(input);
            return false;
        }
    } else if(bits == 4){
        if(colorType == PNG_COLOR_TYPE_GRAY){
            format = ImageType::GRAYSCALE_8;
        } else {
			fclose(input);
            return false;
        }

    } else if(bits == 8){
        if(colorType == PNG_COLOR_TYPE_GRAY){
            format = ImageType::GRAYSCALE_8;

        } else if(colorType == PNG_COLOR_TYPE_GRAY_ALPHA){
            format = ImageType::GRAYSCALE_ALPHA_8;

        } else if(colorType == PNG_COLOR_TYPE_RGB){
            format = ImageType::RGB_888;

        } else if(colorType == PNG_COLOR_TYPE_RGB_ALPHA){
            format = ImageType::RGB_ALPHA_8888;

        } else if(colorType == PNG_COLOR_TYPE_PALETTE){
            format = ImageType::RGB_888;

        } else {
			fclose(input);
            return false;
        }

    } else if(bits == 16){
        if(colorType == PNG_COLOR_TYPE_GRAY){
            format = ImageType::GRAYSCALE_16;

        } else if(colorType == PNG_COLOR_TYPE_GRAY_ALPHA){
            format = ImageType::GRAYSCALE_ALPHA_16;

        } else if(colorType == PNG_COLOR_TYPE_RGB){
            format = ImageType::RGB_161616;

        } else if(colorType == PNG_COLOR_TYPE_RGB_ALPHA){
            format = ImageType::RGB_ALPHA_16161616;

        } else {
			fclose(input);
            return false;
        }

    } else {
		fclose(input);
        return false;
    }

    // PNG_COLOR_TYPE_GRAY_ALPHA is always 8 or 16bit depth
    /*if(colorType == PNG_COLOR_TYPE_GRAY && bits < 8){
        png_set_expand_gray_1_2_4_to_8(pngPtr);
    }*/

    /*if(png_get_valid(pngPtr, infoPtr, PNG_INFO_tRNS)){
        png_set_tRNS_to_alpha(pngPtr);
    }*/

    // Fill background color if image does not have transparency
    /*if(colorType == PNG_COLOR_TYPE_RGB || colorType == PNG_COLOR_TYPE_GRAY || colorType == PNG_COLOR_TYPE_PALETTE){
        png_set_filler(pngPtr, 0xFF, PNG_FILLER_AFTER);
    }*/

    /*if(colorType == PNG_COLOR_TYPE_GRAY || colorType == PNG_COLOR_TYPE_GRAY_ALPHA){
        png_set_gray_to_rgb(pngPtr);
    }*/

    //if(Width != NULL)*Width = width;
    //if(Height != NULL)*Height = height;
    //if(Type != NULL)*Type = type;

    /*if(Pixels == NULL){
        fclose(inputFile);
        return true;
    }*/

    png_read_update_info(pngPtr, infoPtr);

	row = 0;

	loaded = true;
	return true;
}

///=============================================================================
void ffw::PngLoader::Close(){
	if(pngPtr != NULL){
		png_destroy_read_struct(&pngPtr, &infoPtr, NULL);
	}
	if(input != NULL){
		fclose(input);
	}
	input = NULL;
	pngPtr = NULL;
	infoPtr = NULL;

	width = 0;
	height = 0;
	loaded = 0;
	row = 0;
	format = ImageType::INVALID;
}

///=============================================================================
size_t ffw::PngLoader::ReadRow(void* dest){
	if(!loaded)return 0;
    if(row >= height)return 0;
    if(dest == NULL)return 0;
	
	png_read_row(pngPtr, (png_bytep)dest, NULL);

	/*unsigned short* ptr = (unsigned short*)dest;
	size_t total = 0;
	switch(format){
		case ffw::ImageType::GRAYSCALE_16: total = width; break;
		case ffw::ImageType::GRAYSCALE_ALPHA_16: total = width*2; break;
		case ffw::ImageType::RGB_161616: total = width*3; break;
		case ffw::ImageType::RGB_ALPHA_16161616: total = width*4; break;
		default: break;
	}

	for(size_t i = 0; i < total; i++){
		ptr[i] = ffw::ByteSwap16(ptr[i]);
	}*/
	row++;

	return this->GetStrideSize();
}