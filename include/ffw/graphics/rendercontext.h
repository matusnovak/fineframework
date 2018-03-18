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
    /**
    * @ingroup graphics
    */
    enum class DrawMode {
        FILL = 0,
        STROKE,
        FILL_AND_STROKE,
    };
    /**
    * @ingroup graphics
    */
    enum class DrawPathWinding {
        CCW = 1,
        CW = 2,
    };
    /**
    * @ingroup graphics
    */
    enum class LineCap {
        BUTT,
        ROUND,
        SQUARE,
        BEVEL,
        MITER,
    };
    /**
    * @ingroup graphics
    * @details A copy of NVGpaint in order to enable faster compiling
    */
    struct DrawPaint {
        float xform[6];
        float extent[2];
        float radius;
        float feather;
        ffw::Color innerColor;
        ffw::Color outerColor;
        int image;
    };
    /**
     * @ingroup graphics
     * @brief Basic render context which can be used to draw shapes using nanovg on the screen
     */
    class FFW_API RenderContext {
    public:
        RenderContext();
        virtual ~RenderContext();
        /**
         * @brief Retuns the address of the GL extension function
         * @details The pointer to the GL extension function may not 
         * be the same on different GL contexts! 
         */
        virtual void* getGlextFunc(const std::string& name) const = 0;
        /**
         * @brief Returns true if the GL extension is suported
         * @details Checks if an GLEXT extension is supported, for example "GL_ARB_debug_output"
         */
        virtual bool isGlextExtSupported(const std::string& name) const = 0;
        /**
         * @brief Initializes drawing functions
         */
        bool initDrawing();
        /**
        * @brief Begins the render frame and makes this context ready to be used with drawing function
        * @note This function must be called before every draw call
        * @code
        * // class MyRenderWindow extends ffw::GLFWRenderWindow
        * void MyRenderWindow::render(){
        *     this->beginFrame();
        *     this->setDrawColor(ffw::rgb(0xFF0000));
        *     this->drawRectangle(50, 50, 200, 100);
        *     this->endFrame();
        * }
        * @endcode
        */
        void beginFrame() const;
        /**
        * @brief Ends the render frame
        * @note This function must be called at the end of each render
        * @code
        * // class MyRenderWindow extends ffw::GLFWRenderWindow
        * void MyRenderWindow::render(){
        *     this->beginFrame();
        *     this->setDrawColor(ffw::rgb(0xFF0000));
        *     this->drawRectangle(50, 50, 200, 100);
        *     this->endFrame();
        * }
        * @endcode
        */
        void endFrame() const;
        void moveTo(float x, float y) const;
        /**
         * @brief Sets the color of the next draw commands (fill and stroke color)
         */
        void setDrawColor(const ffw::Color& color) const;
        /**
        * @brief Sets the color of the next draw commands (fill only)
        */
        void setFillColor(const ffw::Color& color) const;
        /**
        * @brief Sets the color of the next draw commands (stroke only)
        */
        void setStrokeColor(const ffw::Color& color) const;
        /**
         * @brief Sets current fill style to a paint, which can be a one of the gradients
         */
        void setFillPaint(const DrawPaint& paint) const;
        /**
         * @brief Sets current stroke style to a paint, which can be a one of the gradients
         */
        void setStrokePaint(const DrawPaint& paint) const;
        /**
         * @brief Creates and returns a linear gradient, a wrapper around nvgLinearGradient
         * @details Parameters (sx,sy)-(ex,ey) specify the start and end coordinates
         * of the linear gradient, icol specifies the start color and ocol the end color.
         * The gradient is transformed by the current transform when it is passed to setFillPaint() or setStrokePaint().
         */
        DrawPaint createLinearGradient(float sx, float sy, float ex, float ey, const ffw::Color& icol, const ffw::Color& ocol) const;
        /**
         * @brief Creates and returns a box gradient, a wrapper around nvgBoxGradient
         * @details Box gradient is a feathered rounded rectangle, it is useful for rendering
         * drop shadows or highlights for boxes. Parameters (x,y) define the top-left corner of the rectangle,
         * (w,h) define the size of the rectangle, r defines the corner radius, and f feather. Feather defines how blurry
         * the border of the rectangle is. Parameter icol specifies the inner color and ocol the outer color of the gradient.
         * The gradient is transformed by the current transform when it is passed to setFillPaint() or setStrokePaint().
         */
        DrawPaint createBoxGradient(float x, float y, float w, float h, float r, float f, const ffw::Color& icol, const ffw::Color& ocol) const;
        /**
         * @brief Creates and returns a radial gradient, a wrapper around nvgRadialGradient
         * @details Parameters (cx,cy) specify the center, inr and outr specify
         * the inner and outer radius of the gradient, icol specifies the start color and ocol the end color.
         * The gradient is transformed by the current transform when it is passed to setFillPaint() or setStrokePaint().
         */
        DrawPaint createRadialGradient(float cx, float cy, float inr, float outr, const ffw::Color& icol, const ffw::Color& ocol) const;
        /**
         * @brief Draws a quad composing of 4 points
         */
        void drawQuad(float p0x, float p0y, float p1x, float p1y, float p2x, float p2y, float p3x, float p3y) const;
        /**
         * @brief Draws a simple rectangle
         */
        void drawRectangle(float posx, float posy, float width, float height) const;
        /**
         * @brief Draws a rectangle with rounded corners
         */
        void drawRectangleRounded(float posx, float posy, float width, float height, float corners) const;
        /**
         * @brief Draws a rectangle with rounded corners
         */
        void drawRectangleRounded(float posx, float posy, float width, float height, float leftTop, float rightTop, float bottomRight, float bottomLeft) const;
        /**
         * @brief Draws a simple triangle 
         */
        void drawTriangle(float p0x, float p0y, float p1x, float p1y, float p2x, float p2y) const;
        /**
         * @brief Draws a 2D texture
         */
        void drawTexture2D(float posx, float posy, float width, float height, const ffw::Texture2D* texture) const;
        /**
         * @brief Draws a 2D texture that can be mirrored 
         */
        void drawTexture2DMirror(float posx, float posy, float width, float height, const ffw::Texture2D* texture, bool mirrorx, bool mirrory) const;
        /**
         * @brief Draws a rectangular subsection of the texture
         * @details The subsection coordinates are in pixels.
         */
        void drawTexture2DSub(float posx, float posy, float width, float height, const ffw::Texture2D* texture, int subx, int suby, int subw, int subh) const;
        /**
         * @brief Draws a mirrored rectangular subsection of the texture
         * @details The subsection coordinates are in pixels and the mirroring affects the result subsection.
         */
        void drawTexture2DSubMirror(float posx, float posy, float width, float height, const ffw::Texture2D* texture, int subx, int suby, int subw, int subh, bool mirrorx, bool mirrory) const;
        /**
         * @brief Draws an arc using starting and ending angle
         */
        void drawArc(float posx, float posy, float innerradius, float outerradius, double startangle, double endangle) const;
        /**
         * @brief Draws a simple circle
         */
        void drawCircle(float posx, float posy, float radius) const;
        /**
         * @brief Draws a line from point A to point B
         */
        void drawLine(float startx, float starty, float endx, float edny) const;
        /**
         * @brief Draws a UTF-8 string
         */
        void drawString(float posx, float posy, const Font* font, const std::string& str, float lineHeight = 1.25f) const;
        /**
         * @brief Draws a multi-byte string
         */
        void drawString(float posx, float posy, const Font* font, const std::wstring& str, float lineHeight = 1.25f) const;
        /**
         * @brief Draws a UTF-8 string
         */
        void drawString(float posx, float posy, const Font* font, const char* str, size_t length, float lineHeight = 1.25f) const;
        /**
        * @brief Draws a wide string
        */
        void drawString(float posx, float posy, const Font* font, const wchar_t* str, size_t length, float lineHeight = 1.25f) const;
        /**
        * @brief Draws a UTF-8 string wrapped inside a box with specified width
        */
        void drawStringBox(float posx, float posy, const Font* font, const std::string& str, float maxWidth, float lineHeight = 1.25f) const;
        /**
        * @brief Draws a UTF-8 string wrapped inside a box with specified width
        */
        void drawStringBox(float posx, float posy, const Font* font, const std::wstring& str, float maxWidth, float lineHeight = 1.25f) const;
        /**
        * @brief Draws a multi-byte string wrapped inside a box with specified width
        */
        void drawStringBox(float posx, float posy, const Font* font, const char* str, size_t length, float maxWidth, float lineHeight = 1.25f) const;
        /**
        * @brief Draws a multi-byte string wrapped inside a box with specified width
        */
        void drawStringBox(float posx, float posy, const Font* font, const wchar_t* str, size_t length, float maxWidth, float lineHeight = 1.25f) const;
        /**
         * @brief Draws a quadratic bezier curve
         */
        void drawBezier(float startx, float starty, float cp0x, float cp0y, float cp1x, float cp1y, float endx, float endy) const;
        /**
         * @brief Sets the mode of the next draw calls
         */
        void setDrawMode(DrawMode type) const;
        /**
        * @brief Sets the mode of the next draw calls to be filled
        */
        inline void setFillMode() const {
            setDrawMode(DrawMode::FILL);
        }
        /**
        * @brief Sets the mode of the next draw calls to be stroked
        */
        inline void setStrokeMode() const {
            setDrawMode(DrawMode::STROKE);
        }
        /**
        * @brief Sets the mode of the next draw calls to be filled and stroked
        */
        inline void setFillAndStrokeMode() const {
            setDrawMode(DrawMode::FILL_AND_STROKE);
        }
        /**
         * @brief Sets whether to draw antialias for filling and stroke
         * @details It's enabled by default.
         * @note Performs nvgShapeAntiAlias from nanovg
         */
        void setShapeAntiAlis(bool enabled) const;
        /**
         * @brief Sets the thickness of the stroke
         */
        void setStrokeSize(float width) const;
        /**
         * @brief Sets the miter limit of the stroke style
         * @details Miter limit controls when a sharp corner is beveled
         */
        void setStrokeMiterLimit(float limit) const;
        /**
         * @brief Sets how the end of the line (cap) is drawn
         */
        void setLineCap(LineCap type) const;
        /**
         * @brief Sets how sharp path corners are drawn
         */
        void setLineJoin(LineCap type) const;
        /**
         * @brief Sets the current scissor rectangle
         * @details Scissoring allows you to clip the rendering into a rectangle.
         * The scissor rectangle is transformed by the current transform.
         * @note Acts same as nvgScissor from nanovg
         */
        void setScissor(float posx, float posy, float width, float height) const;
        /**
         * @brief Intersects current scissor rectangle with the specified rectangle.
         * @details The scissor rectangle is transformed by the current transform.
         * In case the rotation of previous scissor rect differs from
         * the current one, the intersection will be done between the specified
         * rectangle and the previous scissor rectangle transformed in the current
         * transform space. The resulting shape is always rectangle.
         * @note Acts same as nvgIntersectScissor from nanovg
         */
        void setIntersectScissor(float posx, float posy, float width, float height) const;
        /**
         * @brief Reset and disables scissoring
         * @note Acts same as nvgResetScissor from nanovg
         */
        void resetScissor() const;
        /**
         * @brief Clears the current path and sub-paths and moves to position [x, y]
         * @note Performs nvgBeginPath and nvgMoveTo from nanovg
         */
        void beginPath(float x, float y) const;
        /**
         * @brief Adds line segment from the last point in the path to the specified point
         * @note Performs nvgLineTo from nanovg
         */
        void drawLineTo(float x, float y) const;
        /**
         * @brief Adds cubic bezier segment from last point in the path via two control points to the specified point
         * @note Performs nvgBezierTo from nanovg
         */
        void drawBezierTo(float cp0x, float cp0y, float cp1x, float cp1y, float endx, float endy) const;
        /**
         * @brief Adds quadratic bezier segment from last point in the path via a control point to the specified point
         * @note Performs nvgQuadTo from nanovg
         */
        void drawQuadTo(float cpx, float cpy, float endx, float endy) const;
        /**
         * @brief Adds an arc segment at the corner defined by the last path point, and two specified points
         * @note Performs nvgArcTo from nanovg
         */
        void drawArcTo(float startx, float starty, float endx, float endy, float radius) const;
        /**
         * @brief Closes current sub-path with a line segment
         * @note Performs nvgClosePath
         */
        void closePath() const;
        /**
         * @brief Fills the current path with current fill style
         * @note Performs nvgFill from nanovg
         */
        void fillPath() const;
        /**
         * @brief Fills the current path with current stroke style
         * @note Performs nvgStroke from nanovg
         */
        void strokePath() const;
        /**
        * @brief Sets the current sub-path winding
        * @note Performs nvgPathWinding from nanovg
        */
        void setPathWinding(DrawPathWinding winding) const;
        /**
         * @brief Pushes and saves the current render state into a state stack
         * @note Performs nvgStroke from nanovg
         */
        void saveDrawState() const;
        /**
        * @brief Pops and restores current render state
        * @note Performs nvgStroke from nanovg
        */
        void restoreDrawState() const;
        /**
        * @brief Resets current render state to default values
        * @note Performs nvgStroke from nanovg
        */
        void resetDrawState() const;
        /**
         * @brief Resets current transform to a identity matrix
         * @note Performs nvgStroke from nanovg
         */
        void resetTransform() const;
        /**
        * @brief Translates current coordinate system
        * @note Performs nvgTranslate from nanovg
        */
        void transformMove(float x, float y) const;
        /**
        * @brief Rotates current coordinate system in degrees
        * @note Performs nvgRotate from nanovg
        */
        void transformRotate(float degrees) const;
        /**
        * @brief Skews the current coordinate system along X axis in degrees
        * @note Performs nvgSkewX from nanovg
        */
        void transformSkewX(float degrees) const;
        /**
        * @brief Skews the current coordinate system along Y axis in degrees
        * @note Performs nvgSkewY from nanovg
        */
        void transformSkewY(float degrees) const;
        /**
        * @brief Scales the current coordinate system
        * @note Performs nvgScale from nanovg
        */
        void transformScale(float x, float y) const;
        /**
        * @brief Translates current coordinate system
        * @details The parameters are interpreted as matrix as follows
        * First row: [a c e]
        * Second row: [b d f]
        * Third row: [0 0 1]
        * @note Performs nvgTransform from nanovg
        */
        void transform(float a, float b, float c, float d, float e, float f) const;
        /**
        * @brief Stores the transform matrix into the buffer provided
        * @details Stores the top part (a-f) of the current transformation matrix in to the specified buffer.
        * There should be space for 6 floats in the return buffer for the values a-f.
        * @code
        * // | a c e |
        * // | b d f |
        * // | 0 0 1 |
        * @endcode
        * @note Performs nvgCurrentTransform from nanovg
        */
        void getTransform(float* arr) const;
        /**
        * @brief Stores the transform matrix as OpenGL matrix into the buffer provided
        * @details Similar to getTransform() but this function returns OpenGL matrix that
        * can be used within shaders. The function expects an array of 9 floats.
        */
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
