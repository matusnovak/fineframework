/* This file is part of FineFramework project */
#ifndef FFW_RENDERBUFFER_2D
#define FFW_RENDERBUFFER_2D
#include "renderbuffer.h"

namespace ffw {
    class RenderContext;
    /**
     * @ingroup graphics
     */
    class FFW_API Renderbuffer2D: public Renderbuffer {
    public:
        Renderbuffer2D();
        ~Renderbuffer2D();
        bool create(GLsizei width, GLsizei height, GLenum internalformat);
        bool resize(GLsizei width, GLsizei height);
    };
};
#endif
