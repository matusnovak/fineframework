#include "ffw/graphics/renderextensionsgl.h"
#include "third_party/nanovg/nanovg.h"
#define NANOVG_GLES2_IMPLEMENTATION
#include "third_party/nanovg/nanovg_gl.h"

NVGcontext* nanovgCreateGLES2() {
    return nvgCreateGLES2(NVG_ANTIALIAS | NVG_STENCIL_STROKES);
}

void nanovgDestroyGLES2(NVGcontext* vg) {
    nvgDeleteGLES2(vg);
}
