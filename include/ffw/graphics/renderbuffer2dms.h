/* This file is part of FineFramework project */
#ifndef FFW_RENDERBUFFER_2D_MS
#define FFW_RENDERBUFFER_2D_MS
#include "renderbuffer.h"

namespace ffw {
	class RenderContext;
	class FFW_API Renderbuffer2DMS: public Renderbuffer {
    public:
        static bool CheckCompability(const RenderContext* Renderer);
		Renderbuffer2DMS();
        ~Renderbuffer2DMS();
		bool Create(const ffw::RenderContext* renderer, GLsizei width, GLsizei height, GLenum internalformat, GLint samples);
    };
};
#endif
