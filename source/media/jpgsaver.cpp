/*** This file is part of FineFramework project ***/

#include "ffw/media/jpgsaver.h"
#include <jpeglib.h>
#include <setjmp.h>

///=============================================================================
METHODDEF(void) my_error_exit (j_common_ptr cinfo){
	// cinfo->err really points to a my_error_mgr struct, so coerce pointer
	//my_error_ptr myerr = (my_error_ptr) cinfo->err;

	// Always display the message.
	// We could postpone this until after returning, if we chose.
	(*cinfo->err->output_message) (cinfo);

	// Return control to the setjmp point
	//try {
		//longjmp(myerr->setjmp_buffer, 1);
	//} catch (const std::exception& e){
	//	std::cout << "JPG internal error: " << e.what() << std::endl;
	//}
}

///=============================================================================
struct ffw::JpgSaver::jpg_struct_s {
	struct my_error_mgr {
		// "public" fields
		struct jpeg_error_mgr pub;
		// for return to caller
		jmp_buf setjmp_buffer;
	};

	typedef struct my_error_mgr * my_error_ptr;

	jpeg_compress_struct cinfo;
	my_error_mgr jerr;
};

///=============================================================================
ffw::JpgSaver::JpgSaver():jpg_struct(new jpg_struct_s){
	output = NULL;
	cInfoInit = false;
	compressInit = false;
}

///=============================================================================
ffw::JpgSaver::JpgSaver(JpgSaver&& other){
	swap(other);
}

///=============================================================================
void ffw::JpgSaver::swap(JpgSaver& other){
	std::swap(jpg_struct, other.jpg_struct);
	std::swap(cInfoInit, other.cInfoInit);
	std::swap(compressInit, other.compressInit);
	std::swap(output, other.output);
}

///=============================================================================
ffw::JpgSaver& ffw::JpgSaver::operator = (JpgSaver&& other){
	if(this != &other){
		swap(other);
	}
	return *this;
}

///=============================================================================
ffw::JpgSaver::~JpgSaver(){
	Close();
	if(jpg_struct != NULL){
		delete jpg_struct;
	}
}

///=============================================================================
bool ffw::JpgSaver::Open(const std::string& path, int w, int h, ffw::ImageType type, int quality){
	if(loaded)return false;
    if(w <= 0 || h <= 0)return false;
	quality = ffw::Clamp(quality, 0, 100);

	switch(type){
		case ImageType::GRAYSCALE_8:
		case ImageType::RGB_888:
			break;
		default:
			return false;
	}

#ifdef FFW_WINDOWS
	output  = fopen(WstrToAnsi(Utf8ToWstr(path)).c_str(), "wb");
#else
	output = fopen(path.c_str(), "wb");
#endif

	if(!output){
		//std::cerr << "Cannot open file: " << path << " for writing!" << std::endl;
        return false;
    }

	// Step 1: allocate and initialize JPEG compression object

	// We have to set up the error handler first, in case the initialization
	// step fails.  (Unlikely, but it could happen if you are out of memory.)
	// This routine fills in the contents of struct jerr, and returns jerr's
	// address which we place into the link field in cinfo.

	jpg_struct->cinfo.err = jpeg_std_error(&jpg_struct->jerr.pub);
	jpg_struct->jerr.pub.error_exit = my_error_exit;

	// Establish the setjmp return context for my_error_exit to use.
	if(setjmp(jpg_struct->jerr.setjmp_buffer)) {
		// If we get here, the JPEG code has signaled an error.
		// We need to clean up the JPEG object, close the input file, and return.
		std::cerr << "Set jump failed" << std::endl;
		Close();
		return false;
	}

	// Now we can initialize the JPEG compression object.
	jpeg_create_compress(&jpg_struct->cinfo);
	cInfoInit = true;

	// Step 2: specify data destination (eg, a file)
	jpeg_stdio_dest(&jpg_struct->cinfo, output);

	// Step 3: set parameters for compression

	// First we supply a description of the input image.
	// Four fields of the cinfo struct must be filled in:

	// image width and height, in pixels
	jpg_struct->cinfo.image_width = w;
	jpg_struct->cinfo.image_height = h;

	// # of color components per pixel
	if(type == ffw::ImageType::GRAYSCALE_8){
		jpg_struct->cinfo.input_components = 1;
		jpg_struct->cinfo.in_color_space = JCS_GRAYSCALE;

	} else if(type == ffw::ImageType::RGB_888){
		jpg_struct->cinfo.input_components = 3;
		jpg_struct->cinfo.in_color_space = JCS_RGB;
	}

	// Now use the library's routine to set default compression parameters.
	// (You must set at least cinfo.in_color_space before calling this,
	// since the defaults depend on the source color space.)

	jpeg_set_defaults(&jpg_struct->cinfo);
	// Now you can set any non-default parameters you wish to.
	// Here we just illustrate the use of quality (quantization table) scaling:

	jpeg_set_quality(&jpg_struct->cinfo, quality, TRUE);

	// Step 4: Start compressor

	// TRUE ensures that we will write a complete interchange-JPEG file.
	// Pass TRUE unless you are very sure of what you're doing.

	jpeg_start_compress(&jpg_struct->cinfo, TRUE);
	compressInit = true;

    format = type;
	width = w;
	height = h;

	row = 0;
    loaded = true;
	return true;
}

///=============================================================================
void ffw::JpgSaver::Close(){
	if(jpg_struct != NULL){
		if(compressInit){
			jpeg_finish_compress(&jpg_struct->cinfo);
		}
		if(cInfoInit){
			jpeg_destroy_compress(&jpg_struct->cinfo);
		}
	}
	if(output != NULL){
		fclose(output);
	}
	output = NULL;
	compressInit = false;
	cInfoInit = false;

	width = 0;
	height = 0;
	loaded = 0;
	row = 0;
	format = ImageType::INVALID;
}

///=============================================================================
size_t ffw::JpgSaver::WriteRow(const void* src){
	if(!loaded)return 0;
    if(row >= height)return 0;
    if(src == NULL)return 0;
	
	JSAMPROW row_pointer[1];
	row_pointer[0] = (unsigned char*)src;
	if(jpeg_write_scanlines(&jpg_struct->cinfo, row_pointer, 1) != 1)return false;
	row++;

	return this->GetStrideSize();
}

///=============================================================================
bool ffw::JpgSaver::WriteFooter(){
	if(!loaded)return false;
    if(row != height)return false;

    jpeg_finish_compress(&jpg_struct->cinfo);
	compressInit = false;

    return true;
}