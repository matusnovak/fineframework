/* This file is part of FineFramework project */
#pragma once
#ifndef FFW_GUI_WINDOW_OPENGL
#define FFW_GUI_WINDOW_OPENGL
#include "guibackend.h"
#include "guifontopengl.h"
#include "guiimageopengl.h"
#include <cmath>
#include <iomanip>

#define FLOAT_EQUAL(a, b) (std::abs(a - b) < 0.001f)

namespace ffw {
    /**
     * @ingroup gui
     */
    class GuiWindowOpenGL : public GuiWindow {
    public:
        GuiWindowOpenGL(){
        }
        virtual ~GuiWindowOpenGL(){
        }
        virtual bool create(RenderContext* ctx){
            return ((context = ctx) != NULL);
        }
        virtual void destroy(){
        }
        void resize(int width, int height) override {
        }
        void drawBackground(const ffw::Vec2f& pos, const ffw::Vec2f& size, const ffw::GuiStyle::Background& background, bool ignore) const override {            
            const auto p = pos.floor();
            const auto s = size.ceil();

            (void)ignore;
            if (!background)return;
            if (background.radius[0] > 0 ||
                background.radius[1] > 0 ||
                background.radius[2] > 0 ||
                background.radius[3] > 0) {
                drawRectangleRounded(p, s, background.color, background.radius[0], background.radius[1], background.radius[2], background.radius[3]);
            }
            else {
                drawRectangle(p, s, background.color);
            }
        }
        void drawBorder(const ffw::Vec2f& pos, const ffw::Vec2f& size, const ffw::GuiStyle::Border& border) const override {
            // Top
            context->setDrawColor(border.color[0]);
            context->beginPath(pos.x + border.radius[0], pos.y + border.size[0] / 2.0f);

            auto endX = pos.x + size.x - border.radius[1];
            auto endY = pos.y + border.size[0] / 2.0f;
            
            context->setStrokeSize(border.size[0]);
            context->drawLineTo(endX, endY);

            if (border.radius[1] > 0.1f) {
                const auto cp0 = ffw::Vec2f(endX + border.radius[1] / 2.0f, endY);
                const auto cp1 = ffw::Vec2f(pos.x + size.x - border.size[1] / 2.0f, pos.y + border.radius[1] / 2.0f);
                const auto end = ffw::Vec2f(pos.x + size.x - border.size[1] / 2.0f, pos.y + border.radius[1]);

                if (border.color[0] == border.color[1] && FLOAT_EQUAL(border.size[0], border.size[1])) {
                    context->drawBezierTo(cp0.x, cp0.y, cp1.x, cp1.y, end.x, end.y);
                }
                else {
                    const auto start = ffw::Vec2f(endX, endY);
                    const auto mid = (cp0 + cp1) / 2.0f;

                    const auto cp0A = (start + cp0) / 2.0f;
                    const auto cp0B = (cp0 + mid) / 2.0f;
                    const auto cp1A = (mid + cp1) / 2.0f;
                    const auto cp1B = (cp1 + end) / 2.0f;

                    context->drawBezierTo(cp0A.x, cp0A.y, cp0B.x, cp0B.y, mid.x, mid.y);

                    context->strokePath();
                    context->beginPath(mid.x, mid.y);
                    context->setDrawColor(border.color[1]);

                    context->drawBezierTo(cp1A.x, cp1A.y, cp1B.x, cp1B.y, end.x, end.y);
                }
            }

            endX = pos.x + size.x - border.size[1] / 2.0f;
            endY = pos.y + size.y - border.radius[2];

            context->setStrokeSize(border.size[1]);
            context->drawLineTo(endX, endY);

            if (border.radius[2] > 0.1f) {
                const auto cp0 = ffw::Vec2f(endX, endY + border.radius[2] / 2.0f);
                const auto cp1 = ffw::Vec2f(pos.x + size.x - border.radius[2] / 2.0f, pos.y + size.y - border.size[2] / 2.0f);
                const auto end = ffw::Vec2f(pos.x + size.x - border.radius[2], pos.y + size.y - border.size[2] / 2.0f);

                if (border.color[1] == border.color[2] && FLOAT_EQUAL(border.size[1], border.size[2])) {
                    context->drawBezierTo(cp0.x, cp0.y, cp1.x, cp1.y, end.x, end.y);
                }
                else {
                    const auto start = ffw::Vec2f(endX, endY);
                    const auto mid = (cp0 + cp1) / 2.0f;

                    const auto cp0A = (start + cp0) / 2.0f;
                    const auto cp0B = (cp0 + mid) / 2.0f;
                    const auto cp1A = (mid + cp1) / 2.0f;
                    const auto cp1B = (cp1 + end) / 2.0f;

                    context->drawBezierTo(cp0A.x, cp0A.y, cp0B.x, cp0B.y, mid.x, mid.y);

                    context->strokePath();
                    context->beginPath(mid.x, mid.y);
                    context->setDrawColor(border.color[2]);

                    context->drawBezierTo(cp1A.x, cp1A.y, cp1B.x, cp1B.y, end.x, end.y);
                }
            }

            endX = pos.x + border.radius[3];
            endY = pos.y + size.y - border.size[2] / 2.0f;

            context->setStrokeSize(border.size[2]);
            context->drawLineTo(endX, endY);

            if (border.radius[3] > 0.1f) {
                const auto cp0 = ffw::Vec2f(pos.x + border.radius[3] / 2.0f, endY);
                const auto cp1 = ffw::Vec2f(pos.x + border.size[3] / 2.0f, pos.y + size.y - border.radius[3] / 2.0f);
                const auto end = ffw::Vec2f(pos.x + border.size[3] / 2.0f, pos.y + size.y - border.radius[3]);

                if (border.color[2] == border.color[3] && FLOAT_EQUAL(border.size[2], border.size[3])) {
                    context->drawBezierTo(cp0.x, cp0.y, cp1.x, cp1.y, end.x, end.y);
                }
                else {
                    const auto start = ffw::Vec2f(endX, endY);
                    const auto mid = (cp0 + cp1) / 2.0f;

                    const auto cp0A = (start + cp0) / 2.0f;
                    const auto cp0B = (cp0 + mid) / 2.0f;
                    const auto cp1A = (mid + cp1) / 2.0f;
                    const auto cp1B = (cp1 + end) / 2.0f;

                    context->drawBezierTo(cp0A.x, cp0A.y, cp0B.x, cp0B.y, mid.x, mid.y);

                    context->strokePath();
                    context->beginPath(mid.x, mid.y);
                    context->setDrawColor(border.color[3]);

                    context->drawBezierTo(cp1A.x, cp1A.y, cp1B.x, cp1B.y, end.x, end.y);
                }
            }

            endX = pos.x + border.size[3] / 2.0f;
            endY = pos.y + border.radius[0];

            context->setStrokeSize(border.size[3]);
            context->drawLineTo(endX, endY);

            if (border.radius[0] > 0.1f) {
                const auto cp0 = ffw::Vec2f(pos.x + border.size[3] / 2.0f, pos.y + border.radius[0] / 2.0f);
                const auto cp1 = ffw::Vec2f(pos.x + border.radius[0] / 2.0f, pos.y + border.size[0] / 2.0f);
                const auto end = ffw::Vec2f(pos.x + border.radius[0], pos.y + border.size[0] / 2.0f);

                if (border.color[3] == border.color[0] && FLOAT_EQUAL(border.size[3], border.size[0])) {
                    context->drawBezierTo(cp0.x, cp0.y, cp1.x, cp1.y, end.x, end.y);
                }
                else {
                    const auto start = ffw::Vec2f(endX, endY);
                    const auto mid = (cp0 + cp1) / 2.0f;

                    const auto cp0A = (start + cp0) / 2.0f;
                    const auto cp0B = (cp0 + mid) / 2.0f;
                    const auto cp1A = (mid + cp1) / 2.0f;
                    const auto cp1B = (cp1 + end) / 2.0f;

                    context->drawBezierTo(cp0A.x, cp0A.y, cp0B.x, cp0B.y, mid.x, mid.y);

                    context->strokePath();
                    context->beginPath(mid.x, mid.y);
                    context->setStrokeSize(border.size[0]);
                    context->setDrawColor(border.color[0]);

                    context->drawBezierTo(cp1A.x, cp1A.y, cp1B.x, cp1B.y, end.x, end.y);
                }
            }

            context->strokePath();
            context->closePath();
        }
        void drawRectangle(const ffw::Vec2f& p, const ffw::Vec2f& s, const ffw::Color& color) const override {
            context->setDrawColor(color);
            context->drawRectangle(p.x, p.y, s.x, s.y);
        }
        void drawRectangleRounded(const ffw::Vec2f& p, const ffw::Vec2f& s, const ffw::Color& color, float tl, float tr, float br, float bl) const override {
            context->setDrawColor(color);
            context->drawRectangleRounded(p.x, p.y, s.x, s.y, tl, tr, br, bl);
        }
        void drawLine(const ffw::Vec2f& start, const ffw::Vec2f& end, const ffw::Color& color, float width) const override  {
            context->setDrawColor(color);
            context->setStrokeSize(width);
            context->drawLine(start.x, start.y, end.x, end.y);
        }
        void drawCircle(const ffw::Vec2f& p, float radius, const ffw::Color& color) const override {
            context->setDrawColor(color);
            context->drawCircle(p.x, p.y, radius);
        }
        void drawArc(const ffw::Vec2f& p, float inner, float outer, float start, float end, const ffw::Color& color) const override {
            context->setDrawColor(color);
            context->drawArc(p.x, p.y, inner, outer, start, end);
        }
        void drawQuad(const ffw::Vec2f& p0, const ffw::Vec2f& p1, const ffw::Vec2f& p2, const ffw::Vec2f& p3, const ffw::Color& color) const override {
            context->setDrawColor(color);
            context->drawQuad(p0.x, p0.y, p1.x, p1.y, p2.x, p2.y, p3.x, p3.y);
        }
        void drawString(const ffw::Vec2f& p, const ffw::GuiFont* font, const std::string::value_type* str, size_t length, const ffw::Color& color, float lineHeight = 1.25f) const override {
            context->setDrawColor(color);
            context->drawString(p.x, p.y, dynamic_cast<const ffw::TrueTypeFont*>(font), str, length, lineHeight);
        }
        void drawTriangle(const ffw::Vec2f& p0, const ffw::Vec2f& p1, const ffw::Vec2f& p2, const ffw::Color& color) const override {
            context->setDrawColor(color);
            context->drawTriangle(p0.x, p0.y, p1.x, p1.y, p2.x, p2.y);
        }
        void drawImage(const ffw::Vec2f& p, const ffw::Vec2f& s, const GuiImage* image, const ffw::Vec4i& sub, bool mirrorX, bool mirrorY, const ffw::Color& color) const override {
            context->setDrawColor(color);
            context->drawTexture2DSubMirror(p.x, p.y, s.x, s.y, dynamic_cast<const ffw::Texture2D*>(image), sub.x, sub.y, sub.z, sub.w, mirrorX, mirrorY);
        }
        virtual void startRender() override {
            context->setFillMode();
        }
        virtual void endRender() override {
        }
        virtual void setScissors(const ffw::Vec2f& p, const ffw::Vec2f& s) const override {
            context->setScissor(floor(p.x), floor(p.y), ceil(s.x), ceil(s.y));
            scissors.set(int(p.x), int(p.y), int(s.x), int(s.y));
        }
        virtual void clearWithColor(const ffw::Color& color) const override {
            ffw::Vec4i viewport;
            glGetIntegerv(GL_VIEWPORT, &viewport.x);
            // Not used
            glEnable(GL_SCISSOR_TEST);
            glScissor(scissors.x, viewport.w - scissors.y - scissors.w, scissors.z, scissors.w);
            glClearColor(color.r, color.g, color.b, color.a);
            glClear(GL_COLOR_BUFFER_BIT | GL_STENCIL_BUFFER_BIT);
            glDisable(GL_SCISSOR_TEST);
        }
    protected:
        RenderContext* context;
        mutable ffw::Vec4i scissors;
    };
    
    /**
     * @ingroup gui
     */
    class GuiWindowOpenGLFBO : public GuiWindowOpenGL {
    public:
        inline GuiWindowOpenGLFBO(){
            
        }
        
        inline virtual ~GuiWindowOpenGLFBO(){
            
        }
        inline bool create(RenderContext* ctx) override {
            if(ctx == NULL)return false;
            context = ctx;
            const auto width = std::min(int(getSize().x), 4);
            const auto height = std::min(int(getSize().x), 4);
            
            if (!fboTexture.create(width, height, GL_RGBA8, GL_RGBA, GL_UNSIGNED_BYTE))
                return false;

            if (!fboStencil.create(width, height, GL_STENCIL_INDEX8))
                return false;
            
            if (!fbo.create())
                return false;
            
            fbo.bind();
            fbo.addColorTexture(&fboTexture);
            fbo.addStencilBuffer(&fboStencil);
            fbo.unbind();
            return true;
        }
        inline void destroy() override {
            fboTexture.destroy();
            fboStencil.destroy();
            fbo.destroy();
        }
        inline void resize(int width, int height) override {
            fboTexture.resize(width, height);
            fboStencil.resize(width, height);
        }
        inline void startRender() override {
            fbo.bind();
            glGetIntegerv(GL_VIEWPORT, &viewport.x);
            glViewport(0, 0, (int)getSize().x, (int)getSize().y);
            context->setFillMode();
            context->beginFrame();
        }
        inline void endRender() override {
            context->endFrame();
            fbo.unbind();
            glViewport(viewport.x, viewport.y, viewport.z, viewport.w);
            context->beginFrame();
        }
        inline const ffw::Texture2D* getFboTexture() const {
            return &fboTexture;
        }
    private:
        ffw::Framebuffer fbo;
        ffw::Texture2D fboTexture;
        ffw::Renderbuffer2D fboStencil;
        ffw::Vec4i viewport;
    };
}
#endif
