/* This file is part of FineFramework project */
#ifndef FFW_GRAPHICS_DRAW
#define FFW_GRAPHICS_DRAW
#include "../config.h"
#include "renderextensionsgl.h"

namespace ffw{
    /**
    * @ingroup graphics
    */
    class FFW_API OpenGLImageType {
    public:
        inline OpenGLImageType():
            internalFormat(0),
            format(0),
            type(0){
        }
        inline OpenGLImageType(const GLint inter, const GLenum form, const GLenum typ):
            internalFormat(inter),
            format(form),
            type(typ){
        }
        const GLint internalFormat;
        const GLenum format;
        const GLenum type;
        inline operator bool () const {
            return (internalFormat != 0 && format != 0 && type != 0);
        }
    };
    /**
     * @ingroup graphics
     */
    ffw::OpenGLImageType FFW_API getOpenGLImageType(ffw::ImageType type);
};
#endif
