#include "ffw/graphics/renderextensionsgl.h"
#include "third_party/nanovg/nanovg.h"
#define NANOVG_GL3_IMPLEMENTATION
#include "third_party/nanovg/nanovg_gl.h"

NVGcontext* nanovgCreateGL3() {
    return nvgCreateGL3(NVG_ANTIALIAS | NVG_STENCIL_STROKES);
}

void nanovgDestroyGL3(NVGcontext* vg) {
    nvgDeleteGL3(vg);
}
