#include "ffw/graphics/renderextensionsgl.h"
#include "third_party/nanovg/nanovg.h"
#define NANOVG_GLES3_IMPLEMENTATION
#include "third_party/nanovg/nanovg_gl.h"

NVGcontext* nanovgCreateGLES3() {
    return nvgCreateGLES3(NVG_ANTIALIAS | NVG_STENCIL_STROKES);
}

void nanovgDestroyGLES3(NVGcontext* vg) {
    nvgDeleteGLES3(vg);
}
