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
        Renderbuffer2D() = default;
        virtual ~Renderbuffer2D() = default;
        Renderbuffer2D(const Renderbuffer2D& other) = delete;
        Renderbuffer2D(Renderbuffer2D&& other) NOEXCEPT;
        Renderbuffer2D& operator = (const Renderbuffer2D& other) = delete;
        Renderbuffer2D& operator = (Renderbuffer2D&& other) NOEXCEPT;

        bool create(GLsizei width, GLsizei height, GLenum internalformat);
        bool resize(GLsizei width, GLsizei height);
    };
};

inline void swap(ffw::Renderbuffer2D& first, ffw::Renderbuffer2D& second) NOEXCEPT {
    first.swap(second);
}
#endif
