#include "ffw/graphics/renderextensionsgl.h"
#define GL_GENERATE_MIPMAP 0x8191 // Taken from glext.h
#include "third_party/nanovg/nanovg.h"
#define NANOVG_GL2_IMPLEMENTATION
#include "third_party/nanovg/nanovg_gl.h"

NVGcontext* nanovgCreateGL2() {
    return nvgCreateGL2(NVG_ANTIALIAS | NVG_STENCIL_STROKES);
}

void nanovgDestroyGL2(NVGcontext* vg) {
    nvgDeleteGL2(vg);
}
