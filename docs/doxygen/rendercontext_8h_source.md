---
search: false
---

# rendercontext.h File Reference

**[Go to the documentation of this file.](rendercontext_8h.md)**
Source: `include/ffw/graphics/rendercontext.h`

    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
```cpp
/* This file is part of FineFramework project */
#ifndef FFW_RENDER_CONTEXT
#define FFW_RENDER_CONTEXT
#include "../math/color.h"
#include "../math/mat4.h"
#include "renderextensionsgl.h"
#include "shader.h"
#include "texture2d.h"
#include "bufferobject.h"

struct NVGcontext;

namespace ffw {
    class Texture2DArray;
    class Font;
    enum class DrawMode {
        FILL = 0,
        STROKE,
        FILL_AND_STROKE,
    };
    enum class DrawPathWinding {
        CCW = 1,
        CW = 2,
    };
    enum class LineCap {
        BUTT,
        ROUND,
        SQUARE,
        BEVEL,
        MITER,
    };
    struct DrawPaint {
        float xform[6];
        float extent[2];
        float radius;
        float feather;
        ffw::Color innerColor;
        ffw::Color outerColor;
        int image;
    };
    class FFW_API RenderContext {
    public:
        RenderContext();
        virtual ~RenderContext();
        virtual void* getGlextFunc(const std::string& name) const = 0;
        virtual bool isGlextExtSupported(const std::string& name) const = 0;
        bool initDrawing();
        void beginFrame() const;
        void endFrame() const;
        void moveTo(float x, float y) const;
        void setDrawColor(const ffw::Color& color) const;
        void setFillColor(const ffw::Color& color) const;
        void setStrokeColor(const ffw::Color& color) const;
        void setFillPaint(const DrawPaint& paint) const;
        void setStrokePaint(const DrawPaint& paint) const;
        DrawPaint createLinearGradient(float sx, float sy, float ex, float ey, const ffw::Color& icol, const ffw::Color& ocol) const;
        DrawPaint createBoxGradient(float x, float y, float w, float h, float r, float f, const ffw::Color& icol, const ffw::Color& ocol) const;
        DrawPaint createRadialGradient(float cx, float cy, float inr, float outr, const ffw::Color& icol, const ffw::Color& ocol) const;
        void drawQuad(float p0x, float p0y, float p1x, float p1y, float p2x, float p2y, float p3x, float p3y) const;
        void drawRectangle(float posx, float posy, float width, float height) const;
        void drawRectangleRounded(float posx, float posy, float width, float height, float corners) const;
        void drawRectangleRounded(float posx, float posy, float width, float height, float leftTop, float rightTop, float bottomRight, float bottomLeft) const;
        void drawTriangle(float p0x, float p0y, float p1x, float p1y, float p2x, float p2y) const;
        void drawTexture2D(float posx, float posy, float width, float height, const ffw::Texture2D* texture) const;
        void drawTexture2DMirror(float posx, float posy, float width, float height, const ffw::Texture2D* texture, bool mirrorx, bool mirrory) const;
        void drawTexture2DSub(float posx, float posy, float width, float height, const ffw::Texture2D* texture, int subx, int suby, int subw, int subh) const;
        void drawTexture2DSubMirror(float posx, float posy, float width, float height, const ffw::Texture2D* texture, int subx, int suby, int subw, int subh, bool mirrorx, bool mirrory) const;
        void drawArc(float posx, float posy, float innerradius, float outerradius, double startangle, double endangle) const;
        void drawCircle(float posx, float posy, float radius) const;
        void drawLine(float startx, float starty, float endx, float edny) const;
        void drawString(float posx, float posy, const Font* font, const std::string& str, float lineHeight = 1.25f) const;
        void drawString(float posx, float posy, const Font* font, const std::wstring& str, float lineHeight = 1.25f) const;
        void drawString(float posx, float posy, const Font* font, const char* str, size_t length, float lineHeight = 1.25f) const;
        void drawString(float posx, float posy, const Font* font, const wchar_t* str, size_t length, float lineHeight = 1.25f) const;
        void drawStringBox(float posx, float posy, const Font* font, const std::string& str, float maxWidth, float lineHeight = 1.25f) const;
        void drawStringBox(float posx, float posy, const Font* font, const std::wstring& str, float maxWidth, float lineHeight = 1.25f) const;
        void drawStringBox(float posx, float posy, const Font* font, const char* str, size_t length, float maxWidth, float lineHeight = 1.25f) const;
        void drawStringBox(float posx, float posy, const Font* font, const wchar_t* str, size_t length, float maxWidth, float lineHeight = 1.25f) const;
        void drawBezier(float startx, float starty, float cp0x, float cp0y, float cp1x, float cp1y, float endx, float endy) const;
        void setDrawMode(DrawMode type) const;
        inline void setFillMode() const {
            setDrawMode(DrawMode::FILL);
        }
        inline void setStrokeMode() const {
            setDrawMode(DrawMode::STROKE);
        }
        inline void setFillAndStrokeMode() const {
            setDrawMode(DrawMode::FILL_AND_STROKE);
        }
        void setShapeAntiAlis(bool enabled) const;
        void setStrokeSize(float width) const;
        void setStrokeMiterLimit(float limit) const;
        void setLineCap(LineCap type) const;
        void setLineJoin(LineCap type) const;
        void setScissor(float posx, float posy, float width, float height) const;
        void setIntersectScissor(float posx, float posy, float width, float height) const;
        void resetScissor() const;
        void beginPath(float x, float y) const;
        void drawLineTo(float x, float y) const;
        void drawBezierTo(float cp0x, float cp0y, float cp1x, float cp1y, float endx, float endy) const;
        void drawQuadTo(float cpx, float cpy, float endx, float endy) const;
        void drawArcTo(float startx, float starty, float endx, float endy, float radius) const;
        void closePath() const;
        void fillPath() const;
        void strokePath() const;
        void setPathWinding(DrawPathWinding winding) const;
        void saveDrawState() const;
        void restoreDrawState() const;
        void resetDrawState() const;
        void resetTransform() const;
        void transformMove(float x, float y) const;
        void transformRotate(float degrees) const;
        void transformSkewX(float degrees) const;
        void transformSkewY(float degrees) const;
        void transformScale(float x, float y) const;
        void transform(float a, float b, float c, float d, float e, float f) const;
        void getTransform(float* arr) const;
        void getOpenGLTransform(float* arr) const;
    private:
        template <class T>
        void drawStringFunc(float posx, float posy, const ffw::Font* font, const T* str, size_t length, float maxWidth, float lineHeight) const;

        int nvgType;
        bool initialized;
        mutable DrawMode drawType;
        mutable ffw::Mat4x4f projection;
        mutable ffw::Color fillColor;
        mutable bool drawExecuted;
        mutable ffw::Vec4i viewport;
        NVGcontext* vg;
        ffw::Shader fontShader;
        ffw::Shader textureShader;
        mutable ffw::Vbo textureShaderVbo;

        struct {
            int position;
            int rgbMixer;
            int color;
            int proj;
            int uvpos;
            int tex;
            int offset;
            int view;
        } fontShaderUniforms;

        struct {
            int position;
            int color;
            int proj;
            int uvpos;
            int tex;
            int view;
        } textureShaderUniforms;
    };
}
#endif
```


    
  
