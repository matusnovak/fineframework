/*** This file is part of FineFramework project ***/

#include "ffw/graphics/graphics.h"
#include "ffw/graphics/rendercontext.h"

///=============================================================================
ffw::OpenGLImageType ffw::getOpenGLImageType(ffw::ImageType type){
	switch(type){
		case ffw::ImageType::GRAYSCALE_8:{
			return OpenGLImageType(GL_LUMINANCE8, GL_LUMINANCE, GL_UNSIGNED_BYTE);
		};
		case ffw::ImageType::GRAYSCALE_16:{
			return OpenGLImageType(GL_LUMINANCE16, GL_LUMINANCE, GL_UNSIGNED_SHORT);
		};
		case ffw::ImageType::GRAYSCALE_32:{
			return OpenGLImageType(GL_RED, GL_RED, GL_FLOAT);
		};
		case ffw::ImageType::GRAYSCALE_ALPHA_8:{
			return OpenGLImageType(GL_LUMINANCE8_ALPHA8, GL_LUMINANCE_ALPHA, GL_UNSIGNED_BYTE);
		};
		case ffw::ImageType::GRAYSCALE_ALPHA_16:{
			return OpenGLImageType(GL_LUMINANCE16_ALPHA16, GL_LUMINANCE_ALPHA, GL_UNSIGNED_SHORT);
		};
		case ffw::ImageType::RGB_ALPHA_5551:{
			return OpenGLImageType(GL_RGB5_A1, GL_RGBA, GL_UNSIGNED_SHORT_5_5_5_1);
		};
		case ffw::ImageType::RGB_ALPHA_4444:{
			return OpenGLImageType(GL_RGBA4, GL_RGBA, GL_UNSIGNED_SHORT_4_4_4_4);
		};
		case ffw::ImageType::RGB_565:{
			return OpenGLImageType(GL_RGB565, GL_RGB, GL_UNSIGNED_SHORT_5_6_5);
		};
		case ffw::ImageType::RGB_888:{
			return OpenGLImageType(GL_RGB8, GL_RGB, GL_UNSIGNED_BYTE);
		};
		case ffw::ImageType::RGB_161616:{
			return OpenGLImageType(GL_RGB16, GL_RGB, GL_UNSIGNED_SHORT);
		};
		case ffw::ImageType::RGB_323232:{
			return OpenGLImageType(GL_RGB32F, GL_RGB, GL_FLOAT);
		};
		case ffw::ImageType::RGB_ALPHA_8888:{
			return OpenGLImageType(GL_RGBA8, GL_RGBA, GL_UNSIGNED_BYTE);
		};
		case ffw::ImageType::RGB_ALPHA_16161616:{
			return OpenGLImageType(GL_RGBA16, GL_RGBA, GL_UNSIGNED_SHORT);
		};
		case ffw::ImageType::RGB_ALPHA_32323232:{
			return OpenGLImageType(GL_RGBA32F, GL_RGBA, GL_FLOAT);
		};
		default: return OpenGLImageType();
	};
}