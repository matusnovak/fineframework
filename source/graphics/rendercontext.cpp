/*** This file is part of FineFramework project ***/
#include "ffw/graphics/rendercontext.h"
#include "ffw/graphics/font.h"
#include "ffw/graphics/texture2d.h"
#include "ffw/math/mvp.h"
#include "ffw/math/mathconstants.h"
#include "ffw/math/functions.h"
#include "ffw/math/textwrapper.h"
#include "ffw/math/stringmath.h"
#include "third_party/nanovg/nanovg.h"

#define FFW_COLOR_TO_NV_COLOR(C) *reinterpret_cast<const NVGcolor*>(&C)
#define FFW_PAINT_TO_NV_PAINT(C) *reinterpret_cast<const NVGpaint*>(&C)
#define NV_PAINT_TO_FFW_PAINT(C) *reinterpret_cast<const DrawPaint*>(&C)

#define FILL_OR_STROKE(vg) \
    switch(drawType){ \
        case DrawMode::FILL: nvgFill(vg); break; \
        case DrawMode::STROKE: nvgStroke(vg); break; \
        case DrawMode::FILL_AND_STROKE: nvgFill(vg); nvgStroke(vg); break; \
    }

#define STRINGIFY(x) #x

///=============================================================================
static const std::string fontShaderVert = "#version 120\n" STRINGIFY(
uniform mat4x4 proj;
uniform mat3x3 view;
uniform vec2 offset;

attribute vec2 position;
attribute vec2 uvpos;

varying vec2 v_uvpos;

void main() {
    v_uvpos = uvpos;
    vec3 v = view * vec3(position + offset, 1.0);
    gl_Position = proj * vec4(v, 1.0);
}
);

///=============================================================================
static const std::string fontShaderFrag = "#version 120\n" STRINGIFY(
uniform sampler2D tex;
uniform vec4 color;
uniform float rgbMixer;

varying vec2 v_uvpos;

void main() {
    vec4 texel = texture2D(tex, v_uvpos);
    vec4 colored = texel * color;
    vec4 alpha = vec4(color.rgb, texel.r * color.a);
    gl_FragColor = mix(alpha, colored, rgbMixer);
}
);

///=============================================================================
static const std::string textureShaderVert = "#version 120\n" STRINGIFY(
uniform mat4x4 proj;
uniform mat3x3 view;

attribute vec2 position;
attribute vec2 uvpos;

varying vec2 v_uvpos;

void main() {
    v_uvpos = uvpos;
    vec3 v = view * vec3(position, 1.0);
    gl_Position = proj * vec4(v, 1.0);
}
);

///=============================================================================
static const std::string textureShaderFrag = "#version 120\n" STRINGIFY(
uniform sampler2D tex;
uniform vec4 color;

varying vec2 v_uvpos;

void main() {
    vec4 texel = texture2D(tex, v_uvpos);
    gl_FragColor = texel * color;
}
);

extern NVGcontext* nanovgCreateGL3();
extern NVGcontext* nanovgCreateGL2();
extern NVGcontext* nanovgCreateGLES2();
extern NVGcontext* nanovgCreateGLES3();
extern void nanovgDestroyGL2(NVGcontext* vg);
extern void nanovgDestroyGL3(NVGcontext* vg);
extern void nanovgDestroyGLES2(NVGcontext* vg);
extern void nanovgDestroyGLES3(NVGcontext* vg);

///=============================================================================
ffw::RenderContext::RenderContext():drawType(DrawMode::FILL),vg(nullptr), drawExecuted(false), initialized(false), nvgType(0) {
}

///=============================================================================
ffw::RenderContext::~RenderContext() {
    if(vg != nullptr) {
        switch (nvgType) {
            case 1: nanovgDestroyGL3(vg); break;
            case 2: nanovgDestroyGL2(vg); break;
            case 3: nanovgDestroyGLES3(vg); break;
            case 4: nanovgDestroyGLES2(vg); break;
            default: break;
        }
        vg = nullptr;
        nvgType = 0;
    }
    fontShader.destroy();
}

///=============================================================================
static bool compileShader(ffw::Shader& shdr, const std::string& vert, const std::string& frag) {
    try {
        shdr.createFromData(std::string(""), vert, frag);
    }
    catch (std::exception& e) {
#ifndef NDEBUG
        std::cerr << "Failed to compile RenderContext shaders:" << std::endl << e.what() << std::endl;
#else
        (void)e;
#endif
        return false;
    }
    return true;
}

///=============================================================================
bool ffw::RenderContext::initDrawing() {
    vg = nanovgCreateGL3();
    nvgType = 1;
    if (vg == nullptr) {
        vg = nanovgCreateGL2();
        nvgType = 2;
    }
    if (vg == nullptr) {
        vg = nanovgCreateGLES3();
        nvgType = 3;
    }
    if (vg == nullptr) {
        vg = nanovgCreateGLES2();
        nvgType = 4;
    }
    if (vg == nullptr) {
        nvgType = 0;
        return false;
    }

    setDrawColor(ffw::rgb(0xFFFFFF));
    setFillMode();

    if(!compileShader(fontShader, fontShaderVert, fontShaderFrag))return false;
    if(!compileShader(textureShader, textureShaderVert, textureShaderFrag))return false;

    fontShaderUniforms.color = fontShader.getUniformLocation("color");
    fontShaderUniforms.offset = fontShader.getUniformLocation("offset");
    fontShaderUniforms.position = fontShader.getAttributeLocation("position");
    fontShaderUniforms.proj = fontShader.getUniformLocation("proj");
    fontShaderUniforms.view = fontShader.getUniformLocation("view");
    fontShaderUniforms.rgbMixer = fontShader.getUniformLocation("rgbMixer");
    fontShaderUniforms.tex = fontShader.getUniformLocation("tex");
    fontShaderUniforms.uvpos = fontShader.getAttributeLocation("uvpos");

    textureShaderUniforms.position = textureShader.getAttributeLocation("position");
    textureShaderUniforms.color = textureShader.getUniformLocation("color");
    textureShaderUniforms.proj = textureShader.getUniformLocation("proj");
    textureShaderUniforms.uvpos = textureShader.getAttributeLocation("uvpos");
    textureShaderUniforms.tex = textureShader.getUniformLocation("tex");
    textureShaderUniforms.view = textureShader.getUniformLocation("view");

    float data[16] = {
        0.0f, 0.0f,
        0.0f, 0.0f,

        0.0f, 100.0f,
        0.0f, 1.0f,

        100.0f, 100.0f,
        1.0f, 1.0f,

        100.0f, 0.0f,
        1.0f, 0.0f
    };

    textureShaderVbo.create(data, 4 * 4 * sizeof(float), GL_DYNAMIC_DRAW);
    initialized = true;
    return true;
}

///=============================================================================
void ffw::RenderContext::beginFrame() const {
    if (!initialized)return;

    glGetIntegerv(GL_VIEWPORT, &viewport.x);
    float pxRatio = (float)viewport[2] / (float)viewport[3];
    nvgBeginFrame(vg, viewport[2], viewport[3], pxRatio);
    projection = ffw::makeOrthoMatrix<float>((float)viewport[0], (float)viewport[0] + viewport[2], (float)viewport[1] + viewport[3], (float)viewport[1], -1, 1);
    drawExecuted = false;
}

///=============================================================================
void ffw::RenderContext::endFrame() const  {
    if (!initialized)return;

    nvgEndFrame(vg);
    drawExecuted = false;
}

///=============================================================================
void ffw::RenderContext::setDrawColor(const ffw::Color& color) const {
    if (!initialized)return;

    nvgFillColor(vg, FFW_COLOR_TO_NV_COLOR(color));
    nvgStrokeColor(vg, FFW_COLOR_TO_NV_COLOR(color));
    fillColor = color;
}

///=============================================================================
void ffw::RenderContext::setFillColor(const ffw::Color& color) const {
    if (!initialized)return;

    nvgFillColor(vg, FFW_COLOR_TO_NV_COLOR(color));
    fillColor = color;
}

///=============================================================================
void ffw::RenderContext::setStrokeColor(const ffw::Color& color) const {
    if (!initialized)return;

    nvgStrokeColor(vg, FFW_COLOR_TO_NV_COLOR(color));
}

///=============================================================================
void ffw::RenderContext::drawQuad(float p0x, float p0y, float p1x, float p1y, float p2x, float p2y, float p3x, float p3y) const {
    if (!initialized)return;

    nvgBeginPath(vg);
    nvgMoveTo(vg, p0x, p0y);
    nvgLineTo(vg, p1x, p1y);
    nvgLineTo(vg, p2x, p2y);
    nvgLineTo(vg, p3x, p3y);
    nvgLineTo(vg, p0x, p0y);
    FILL_OR_STROKE(vg);
    drawExecuted = true;
}

///=============================================================================
void ffw::RenderContext::drawRectangle(float posx, float posy, float width, float height) const {
    if (!initialized)return;

    nvgBeginPath(vg);
    nvgRect(vg, posx, posy, width, height);
    FILL_OR_STROKE(vg);
    drawExecuted = true;
}

///=============================================================================
void ffw::RenderContext::drawRectangleRounded(float posx, float posy, float width, float height, float corners) const {
    if (!initialized)return;

    nvgBeginPath(vg);
    nvgRoundedRect(vg, posx, posy, width, height, corners);
    FILL_OR_STROKE(vg);
    drawExecuted = true;
}

///=============================================================================
void ffw::RenderContext::drawRectangleRounded(float posx, float posy, float width, float height, float topLeft, float topRight, float bottomRight, float bottomLeft) const {
    if (!initialized)return;

    nvgBeginPath(vg);
    nvgRoundedRectVarying(vg, posx, posy, width, height, topLeft, topRight, bottomRight, bottomLeft);
    FILL_OR_STROKE(vg);
    drawExecuted = true;
}

///=============================================================================
void ffw::RenderContext::drawTriangle(float p0x, float p0y, float p1x, float p1y, float p2x, float p2y) const  {
    if (!initialized)return;

    nvgBeginPath(vg);
    nvgMoveTo(vg, p0x, p0y);
    nvgLineTo(vg, p1x, p1y);
    nvgLineTo(vg, p2x, p2y);
    nvgLineTo(vg, p0x, p0y);
    FILL_OR_STROKE(vg);
    drawExecuted = true;
}

///=============================================================================
void ffw::RenderContext::drawTexture2D(float posx, float posy, float width, float height, const ffw::Texture2D* texture) const  {
    if (!initialized)return;
    if (texture == NULL || !texture->isCreated())return;
    drawTexture2DSubMirror(posx, posy, width, height, texture, 0, 0, texture->getWidth(), texture->getHeight(), false, false);
}

///=============================================================================
void ffw::RenderContext::drawTexture2DMirror(float posx, float posy, float width, float height, const ffw::Texture2D* texture, bool mirrorx, bool mirrory) const  {
    if (!initialized)return;
    if (texture == NULL || !texture->isCreated())return;
    drawTexture2DSubMirror(posx, posy, width, height, texture, 0, 0, texture->getWidth(), texture->getHeight(), mirrorx, mirrory);
}

///=============================================================================
void ffw::RenderContext::drawTexture2DSub(float posx, float posy, float width, float height, const ffw::Texture2D* texture, int subx, int suby, int subw, int subh) const  {
    if (!initialized)return;
    drawTexture2DSubMirror(posx, posy, width, height, texture, subx, suby, subw, subh, false, false);
}

///=============================================================================
void ffw::RenderContext::drawTexture2DSubMirror(float posx, float posy, float width, float height, const ffw::Texture2D* texture, int subx, int suby, int subw, int subh, bool mirrorx, bool mirrory) const  {
    if (!initialized)return;
    if (texture == nullptr || !texture->isCreated())return;

    const auto scissorW = vg->states->scissor.extent[0] * 2.0f;
    const auto scissorH = vg->states->scissor.extent[1] * 2.0f;
    const auto scissorX = (vg->states->scissor.xform[4] * 2.0f - scissorW) / 2.0f;
    const auto scissorY = (vg->states->scissor.xform[5] * 2.0f - scissorH) / 2.0f;

    if (drawExecuted)endFrame();

    if (scissorW > 0.0f && scissorH > 0.0f) {
        glEnable(GL_SCISSOR_TEST);
        glScissor(int(floor(scissorX)), viewport.w - int(floor(scissorY) + ceil(scissorH)), int(ceil(scissorW)), int(ceil(scissorH)));
    }

    glEnable(GL_BLEND);
    glEnable(GL_TEXTURE);
    glActiveTexture(GL_TEXTURE0);

    texture->bind();

    float view[9];
    getOpenGLTransform(view);

    textureShader.bind();
    textureShader.setUniform1i(textureShaderUniforms.tex, 0);
    textureShader.setUniform4f(textureShaderUniforms.color, fillColor);
    textureShader.setUniformMatrix4fv(textureShaderUniforms.proj, &projection, 1);
    textureShader.setUniformMatrix3fv(textureShaderUniforms.view, view, 1);

    const auto subxf = subx / float(texture->getWidth());
    const auto subyf = suby / float(texture->getHeight());
    const auto subwf = subw / float(texture->getWidth());
    const auto subhf = subh / float(texture->getHeight());

    Vec2f data[4*2] = {
        // Vertex 1
        Vec2f(posx, posy),
        Vec2f(subxf, subyf),

        // Vertex 2
        Vec2f(posx, posy + height),
        Vec2f(subxf, subyf + subhf),

        // Vertex 3
        Vec2f(posx + width, posy + height),
        Vec2f(subxf + subwf, subyf + subhf),

        // Vertex 4
        Vec2f(posx + width, posy),
        Vec2f(subxf + subwf, subyf),
    };

    if(mirrory) {
        std::swap(data[1], data[3]);
        std::swap(data[5], data[7]);
    }

    if (mirrorx) {
        std::swap(data[1], data[7]);
        std::swap(data[3], data[5]);
    }

    textureShaderVbo.bind();
    textureShaderVbo.setData(&data[0].x, 0, 4 * 4 * sizeof(float));
    textureShader.setAttributePointerf(textureShaderUniforms.position, 2, 4 * sizeof(float), (GLvoid*)(0 * sizeof(float)));
    textureShader.setAttributePointerf(textureShaderUniforms.uvpos, 2, 4 * sizeof(float), (GLvoid*)(2 * sizeof(float)));

    textureShader.drawArrays(GL_QUADS, 0, 4);
    textureShader.unbind();

    if (scissorW > 0.0f && scissorH > 0.0f) {
        glDisable(GL_SCISSOR_TEST);
    }
}

///=============================================================================
void ffw::RenderContext::drawArc(float posx, float posy, float innerradius, float outerradius, double startangle, double endangle) const  {
    if (!initialized)return;

    nvgBeginPath(vg);
    const auto p0 = ffw::Vec2f(posx, posy) + ffw::Vec2f(outerradius, 0).rotate(startangle);
    const auto p1 = ffw::Vec2f(posx, posy) + ffw::Vec2f(innerradius, 0).rotate(endangle);
    nvgMoveTo(vg, p0.x, p0.y);
    nvgArc(vg, posx, posy, outerradius, float(startangle * DEG_TO_RAD), float(endangle * DEG_TO_RAD), NVG_CW);
    nvgLineTo(vg, p1.x, p1.y);
    nvgArc(vg, posx, posy, innerradius, float(endangle * DEG_TO_RAD), float(startangle * DEG_TO_RAD), NVG_CCW);
    nvgLineTo(vg, p0.x, p0.y);
    FILL_OR_STROKE(vg);
    drawExecuted = true;
}

///=============================================================================
void ffw::RenderContext::drawCircle(float posx, float posy, float radius) const {
    if (!initialized)return;

    nvgBeginPath(vg);
    nvgCircle(vg, posx, posy, radius);
    FILL_OR_STROKE(vg);
    drawExecuted = true;
}

///=============================================================================
void ffw::RenderContext::drawLine(float startx, float starty, float endx, float endy) const  {
    if (!initialized)return;
    
    nvgBeginPath(vg);
    nvgMoveTo(vg, startx, starty);
    nvgLineTo(vg, endx, endy);
    nvgStroke(vg);
    drawExecuted = true;
}

///=============================================================================
void ffw::RenderContext::getOpenGLTransform(float* arr) const {
    if (!initialized)return;
    
    float buffer[6];

    nvgCurrentTransform(vg, buffer);

    arr[0] = buffer[0];
    arr[3] = buffer[2];
    arr[6] = buffer[4];
    arr[1] = buffer[1];
    arr[4] = buffer[3];
    arr[7] = buffer[5];

    arr[2] = 0.0f;
    arr[5] = 0.0f;
    arr[8] = 1.0f;
}

///=============================================================================
template <class T>
void ffw::RenderContext::drawStringFunc(float posx, float posy, const ffw::Font* font, const T* str, size_t length, float maxWidth, float lineHeight) const {
    if (!initialized)return;
    
    if (length == 0 || str == nullptr || font == nullptr || !font->isCreated())return;

    const auto scissorW = vg->states->scissor.extent[0] * 2.0f;
    const auto scissorH = vg->states->scissor.extent[1] * 2.0f;
    const auto scissorX = (vg->states->scissor.xform[4] * 2.0f - scissorW) / 2.0f;
    const auto scissorY = (vg->states->scissor.xform[5] * 2.0f - scissorH) / 2.0f;

    if (drawExecuted)endFrame();

    if (scissorW > 0.0f && scissorH > 0.0f) {
        glEnable(GL_SCISSOR_TEST);
        glScissor(int(floor(scissorX)), viewport.w - int(floor(scissorY) + ceil(scissorH)), int(ceil(scissorW)), int(ceil(scissorH)));
    }

    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    
    fontShader.bind();

    float view[9];
    getOpenGLTransform(view);

    font->getTexture()->bind();
    fontShader.setUniform1i(fontShaderUniforms.tex, 0);
    fontShader.setUniform1f(fontShaderUniforms.rgbMixer, font->isAlphaOnly() ? 0.0f : 1.0f);
    fontShader.setUniform4f(fontShaderUniforms.color, fillColor);
    fontShader.setUniformMatrix4fv(fontShaderUniforms.proj, &projection, 1);
    fontShader.setUniformMatrix3fv(fontShaderUniforms.view, view, 1);

    font->getVbo()->bind();
    fontShader.setAttributePointerf(fontShaderUniforms.position, 2, 4 * sizeof(float), (GLvoid*)(0 * sizeof(float)));
    fontShader.setAttributePointerf(fontShaderUniforms.uvpos, 2, 4 * sizeof(float), (GLvoid*)(2 * sizeof(float)));

    auto wrapper = ffw::TextWrapper<T>(str, str + length);

    const auto bottom = float(font->getSizePixels());
    auto height = posy;
    bool previousWasNewline = false;
    while(auto token = wrapper.next(font, maxWidth)) {
        auto advance = posx;

        if(token.len > 0) {
            const T* ptr = token.str;
            while (ptr != token.str + token.len) {
                const auto chr = getNextChar(ptr, token.str + token.len);
                const ffw::Font::Char& chrData = font->getChar(chr);

                if (chrData.height == 0 || chrData.width == 0) {
                    advance += chrData.advance;
                    continue;
                }

                fontShader.setUniform2f(fontShaderUniforms.offset, advance, height + (bottom - chrData.bearingY));
                fontShader.drawArrays(GL_QUADS, font->getCharIndex(chr) * 4, 4);

                advance += chrData.advance;
            }
            height += lineHeight * font->getSizePixels();
            previousWasNewline = false;
        } else {
            if (previousWasNewline) {
                height += lineHeight * font->getSizePixels();
            }
            previousWasNewline = true;
        }
    }

    fontShader.unbind();

    if (scissorW > 0.0f && scissorH > 0.0f) {
        glDisable(GL_SCISSOR_TEST);
    }
}

///=============================================================================
void ffw::RenderContext::drawString(float posx, float posy, const ffw::Font* font, const std::string& str, float lineHeight) const {
    if (!initialized)return;
    drawStringFunc(posx, posy, font, &str[0], str.size(), -1.0f, lineHeight);
}

///=============================================================================
void ffw::RenderContext::drawString(float posx, float posy, const ffw::Font* font, const std::wstring& str, float lineHeight) const {
    if (!initialized)return;
    drawStringFunc(posx, posy, font, &str[0], str.size(), -1.0f, lineHeight);
}

///=============================================================================
void ffw::RenderContext::drawString(float posx, float posy, const ffw::Font* font, const char* str, size_t length, float lineHeight) const  {
    if (!initialized)return;
    drawStringFunc(posx, posy, font, str, length, -1.0f, lineHeight);
}

///=============================================================================
void ffw::RenderContext::drawString(float posx, float posy, const ffw::Font* font, const wchar_t* str, size_t length, float lineHeight) const {
    if (!initialized)return;
    drawStringFunc(posx, posy, font, str, length, -1.0f, lineHeight);
}

///=============================================================================
void ffw::RenderContext::drawStringBox(float posx, float posy, const ffw::Font* font, const char* str, size_t length, float maxWidth, float lineHeight) const {
    if (!initialized)return;
    drawStringFunc(posx, posy, font, str, length, maxWidth, lineHeight);
}

///=============================================================================
void ffw::RenderContext::drawStringBox(float posx, float posy, const ffw::Font* font, const wchar_t* str, size_t length, float maxWidth, float lineHeight) const {
    if (!initialized)return;
    drawStringFunc(posx, posy, font, str, length, maxWidth, lineHeight);
}

///=============================================================================
void ffw::RenderContext::drawStringBox(float posx, float posy, const ffw::Font* font, const std::string& str, float maxWidth, float lineHeight) const {
    if (!initialized)return;
    drawStringFunc(posx, posy, font, &str[0], str.size(), maxWidth, lineHeight);
}

///=============================================================================
void ffw::RenderContext::drawStringBox(float posx, float posy, const ffw::Font* font, const std::wstring& str, float maxWidth, float lineHeight) const {
    if (!initialized)return;
    drawStringFunc(posx, posy, font, &str[0], str.size(), maxWidth, lineHeight);
}

///=============================================================================
void ffw::RenderContext::drawBezier(float startx, float starty, float cp0x, float cp0y, float cp1x, float cp1y, float endx, float endy) const  {
    if (!initialized)return;

    nvgBeginPath(vg);
    nvgMoveTo(vg, startx, starty);
    nvgBezierTo(vg, cp0x, cp0y, cp1x, cp1y, endx, endy);
    nvgStroke(vg);
    drawExecuted = true;
}

///=============================================================================
void ffw::RenderContext::setDrawMode(DrawMode type) const  {
    if (!initialized)return;
    drawType = type;
}

///=============================================================================
void ffw::RenderContext::setStrokeSize(float width) const  {
    if (!initialized)return;
    nvgStrokeWidth(vg, width);
}

///=============================================================================
void ffw::RenderContext::setShapeAntiAlis(bool enabled) const {
    if (!initialized)return;
    nvgShapeAntiAlias(vg, enabled);
}

///=============================================================================
void ffw::RenderContext::setLineCap(LineCap type) const {
    if (!initialized)return;
    nvgLineCap(vg, int(type));
}

///=============================================================================
void ffw::RenderContext::setLineJoin(LineCap type) const {
    if (!initialized)return;
    nvgLineJoin(vg, int(type));
}

///=============================================================================
void ffw::RenderContext::setStrokeMiterLimit(float limit) const {
    if (!initialized)return;
    nvgMiterLimit(vg, limit);
}

///=============================================================================
void ffw::RenderContext::beginPath(float x, float y) const {
    if (!initialized)return;
    nvgBeginPath(vg);
    nvgMoveTo(vg, x, y);
}

///=============================================================================
void ffw::RenderContext::drawLineTo(float x, float y) const {
    if (!initialized)return;
    nvgLineTo(vg, x, y);
}

///=============================================================================
void ffw::RenderContext::drawBezierTo(float cp0x, float cp0y, float cp1x, float cp1y, float endx, float endy) const {
    if (!initialized)return;
    nvgBezierTo(vg, cp0x, cp0y, cp1x, cp1y, endx, endy);
}

///=============================================================================
void ffw::RenderContext::drawQuadTo(float cpx, float cpy, float endx, float endy) const {
    if (!initialized)return;
    nvgQuadTo(vg, cpx, cpy, endx, endy);
}

///=============================================================================
void ffw::RenderContext::drawArcTo(float startx, float starty, float endx, float endy, float radius) const {
    if (!initialized)return;
    nvgArcTo(vg, startx, starty, endx, endy, radius);
}

///=============================================================================
void ffw::RenderContext::closePath() const {
    if (!initialized)return;
    nvgClosePath(vg);
}

///=============================================================================
void ffw::RenderContext::fillPath() const {
    if (!initialized)return;
    nvgFill(vg);
    drawExecuted = true;
}

///=============================================================================
void ffw::RenderContext::strokePath() const {
    if (!initialized)return;
    nvgStroke(vg);
    drawExecuted = true;
}

///=============================================================================
void ffw::RenderContext::setPathWinding(DrawPathWinding winding) const  {
    if (!initialized)return;
    nvgPathWinding(vg, int(winding));
}

///=============================================================================
void ffw::RenderContext::saveDrawState() const {
    if (!initialized)return;
    nvgSave(vg);
}

///=============================================================================
void ffw::RenderContext::restoreDrawState() const {
    if (!initialized)return;
    nvgRestore(vg);
}

///=============================================================================
void ffw::RenderContext::resetDrawState() const {
    if (!initialized)return;
    nvgReset(vg);
}

///=============================================================================
void ffw::RenderContext::setScissor(float posx, float posy, float width, float height) const {
    if (!initialized)return;
    nvgScissor(vg, posx, posy, width, height);
}

///=============================================================================
void ffw::RenderContext::setIntersectScissor(float posx, float posy, float width, float height) const {
    if (!initialized)return;
    nvgIntersectScissor(vg, posx, posy, width, height);
}

///=============================================================================
void ffw::RenderContext::resetScissor() const {
    if (!initialized)return;
    nvgResetScissor(vg);
}

///=============================================================================
void ffw::RenderContext::setFillPaint(const DrawPaint& paint) const {
    if (!initialized)return;
    nvgFillPaint(vg, FFW_PAINT_TO_NV_PAINT(paint));
}

///=============================================================================
void ffw::RenderContext::setStrokePaint(const DrawPaint& paint) const {
    if (!initialized)return;
    nvgStrokePaint(vg, FFW_PAINT_TO_NV_PAINT(paint));
}

///=============================================================================
ffw::DrawPaint ffw::RenderContext::createLinearGradient(float sx, float sy, float ex, float ey, const ffw::Color& icol, const ffw::Color& ocol) const {
    if (!initialized)return ffw::DrawPaint();
    const auto ret = nvgLinearGradient(vg, sx, sy, ex, ey, FFW_COLOR_TO_NV_COLOR(icol), FFW_COLOR_TO_NV_COLOR(ocol));
    return NV_PAINT_TO_FFW_PAINT(ret);
}

///=============================================================================
ffw::DrawPaint ffw::RenderContext::createBoxGradient(float x, float y, float w, float h, float r, float f, const ffw::Color& icol, const ffw::Color& ocol) const {
    if (!initialized)return ffw::DrawPaint();
    const auto ret = nvgBoxGradient(vg, x, y, w, h, r, f, FFW_COLOR_TO_NV_COLOR(icol), FFW_COLOR_TO_NV_COLOR(ocol));
    return NV_PAINT_TO_FFW_PAINT(ret);
}

///=============================================================================
ffw::DrawPaint ffw::RenderContext::createRadialGradient(float cx, float cy, float inr, float outr, const ffw::Color& icol, const ffw::Color& ocol) const {
    if (!initialized)return ffw::DrawPaint();
    const auto ret = nvgRadialGradient(vg, cx, cy, inr, outr, FFW_COLOR_TO_NV_COLOR(icol), FFW_COLOR_TO_NV_COLOR(ocol));
    return NV_PAINT_TO_FFW_PAINT(ret);
}

///=============================================================================
void ffw::RenderContext::resetTransform() const {
    if (!initialized)return;
    nvgResetTransform(vg);
}

///=============================================================================
void ffw::RenderContext::transformMove(float x, float y) const {
    if (!initialized)return;
    nvgTranslate(vg, x, y);
}

///=============================================================================
void ffw::RenderContext::transformRotate(float degrees) const {
    if (!initialized)return;
    nvgRotate(vg, float(degrees * DEG_TO_RAD));
}

///=============================================================================
void ffw::RenderContext::transformSkewX(float degrees) const {
    if (!initialized)return;
    nvgSkewX(vg, float(degrees * DEG_TO_RAD));
}

///=============================================================================
void ffw::RenderContext::transformSkewY(float degrees) const {
    if (!initialized)return;
    nvgSkewY(vg, float(degrees * DEG_TO_RAD));
}

///=============================================================================
void ffw::RenderContext::transformScale(float x, float y) const {
    if (!initialized)return;
    nvgScale(vg, x, y);
}

///=============================================================================
void ffw::RenderContext::transform(float a, float b, float c, float d, float e, float f) const {
    if (!initialized)return;
    nvgTransform(vg, a, b, c, d, e, f);
}

///=============================================================================
void ffw::RenderContext::getTransform(float* arr) const {
    if (!initialized)return;
    nvgCurrentTransform(vg, arr);
}
