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
        case ffw::ImageType::GRAYSCALE_16F:{
            return OpenGLImageType(GL_R16F, GL_LUMINANCE, GL_HALF_FLOAT);
        };
        case ffw::ImageType::GRAYSCALE_32F:{
            return OpenGLImageType(GL_RED, GL_RED, GL_FLOAT);
        };
        case ffw::ImageType::GRAYSCALE_ALPHA_8:{
            return OpenGLImageType(GL_LUMINANCE8_ALPHA8, GL_LUMINANCE_ALPHA, GL_UNSIGNED_BYTE);
        };
        case ffw::ImageType::GRAYSCALE_ALPHA_16:{
            return OpenGLImageType(GL_LUMINANCE16_ALPHA16, GL_LUMINANCE_ALPHA, GL_UNSIGNED_SHORT);
        };
        case ffw::ImageType::GRAYSCALE_ALPHA_16F:{
            return OpenGLImageType(GL_RG16F, GL_LUMINANCE_ALPHA, GL_HALF_FLOAT);
        };
        case ffw::ImageType::RG_1616:{
            return OpenGLImageType(GL_RG16, GL_RG, GL_UNSIGNED_SHORT);
        };
        case ffw::ImageType::RG_1616F:{
            return OpenGLImageType(GL_RG16F, GL_RG, GL_HALF_FLOAT);
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
        case ffw::ImageType::RGB_161616F:{
            return OpenGLImageType(GL_RGB16F, GL_RGB, GL_HALF_FLOAT);
        };
        case ffw::ImageType::RGB_323232F:{
            return OpenGLImageType(GL_RGB32F, GL_RGB, GL_FLOAT);
        };
        case ffw::ImageType::RGB_ALPHA_8888:{
            return OpenGLImageType(GL_RGBA8, GL_RGBA, GL_UNSIGNED_BYTE);
        };
        case ffw::ImageType::RGB_ALPHA_16161616:{
            return OpenGLImageType(GL_RGBA16, GL_RGBA, GL_UNSIGNED_SHORT);
        };
        case ffw::ImageType::RGB_ALPHA_16161616F:{
            return OpenGLImageType(GL_RGBA16F, GL_RGBA, GL_HALF_FLOAT);
        };
        case ffw::ImageType::RGB_ALPHA_32323232F:{
            return OpenGLImageType(GL_RGBA32F, GL_RGBA, GL_FLOAT);
        };
        case ffw::ImageType::RGB_DXT1: {
            return OpenGLImageType(GL_COMPRESSED_RGBA_S3TC_DXT1_EXT, GL_RGB, GL_UNSIGNED_BYTE);
        };
        case ffw::ImageType::RGB_ALPHA_DXT3: {
            return OpenGLImageType(GL_COMPRESSED_RGBA_S3TC_DXT3_EXT, GL_RGBA, GL_UNSIGNED_BYTE);
        };
        case ffw::ImageType::RGB_ALPHA_DXT5: {
            return OpenGLImageType(GL_COMPRESSED_RGBA_S3TC_DXT5_EXT, GL_RGBA, GL_UNSIGNED_BYTE);
        };
        case ffw::ImageType::RED_RGTC1: {
            return OpenGLImageType(GL_COMPRESSED_RED_RGTC1, GL_R, GL_UNSIGNED_BYTE);
        };
        case ffw::ImageType::RED_GREEN_RGTC2: {
            return OpenGLImageType(GL_COMPRESSED_RG_RGTC2, GL_RG, GL_UNSIGNED_BYTE);
        };
        case ffw::ImageType::SIGNED_RED_RGTC1: {
            return OpenGLImageType(GL_COMPRESSED_SIGNED_RED_RGTC1, GL_R, GL_UNSIGNED_BYTE);
        };
        case ffw::ImageType::SIGNED_RED_GREEN_RGTC2: {
            return OpenGLImageType(GL_COMPRESSED_SIGNED_RG_RGTC2, GL_RG, GL_UNSIGNED_BYTE);
        };
        default: return OpenGLImageType();
    };
}