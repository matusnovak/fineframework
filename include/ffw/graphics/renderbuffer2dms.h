/* This file is part of FineFramework project */
#ifndef FFW_RENDERBUFFER_2D_MS
#define FFW_RENDERBUFFER_2D_MS
#include "renderbuffer.h"

namespace ffw {
    class RenderContext;
    /**
     * @ingroup graphics
     */
    class FFW_API Renderbuffer2DMS: public Renderbuffer {
    public:
        Renderbuffer2DMS();
        ~Renderbuffer2DMS();
        bool create(GLsizei width, GLsizei height, GLenum internalformat, GLint samples);
        bool resize(GLsizei width, GLsizei height, GLint samples);
    };
};
#endif
