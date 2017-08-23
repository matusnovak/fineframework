/* This file is part of FineFramework project */
#pragma once
#ifndef FFW_GUI_WINDOW_OPENGL
#define FFW_GUI_WINDOW_OPENGL
#include "guibackend.h"
#include "guifontopengl.h"
#include "guiimageopengl.h"
#include <cmath>
namespace ffw {
	/**
	 * @ingroup gui
	 */
	class GuiWindowOpenGL : public GuiWindow {
	public:
		inline GuiWindowOpenGL(){
		}
		inline virtual ~GuiWindowOpenGL(){
		}
		inline virtual bool create(RenderContext* ctx){
			return ((context = ctx) != NULL);
		}
		inline virtual void destroy(){
		}
		inline virtual void resize(int width, int height) override {
		}
		inline void drawRectangle(const ffw::Vec2f& p, const ffw::Vec2f& s, const ffw::Color& color) const override {
			context->setDrawColor(color);
			context->drawRectangle(p.x, p.y, s.x, s.y);
		}
		inline void drawRectangleRounded(const ffw::Vec2f& p, const ffw::Vec2f& s, const ffw::Color& color, float tl, float tr, float br, float bl) const override {
			context->setDrawColor(color);
			context->drawRectangleRounded(p.x, p.y, s.x, s.y, tl, tr, br, bl);
		}
		inline void drawLine(const ffw::Vec2f& start, const ffw::Vec2f& end, const ffw::Color& color) const override  {
			context->setDrawColor(color);
			context->drawLine(start.x, start.y, end.x, end.y);
		}
		inline void drawCircle(const ffw::Vec2f& p, float radius, const ffw::Color& color) const override {
			context->setDrawColor(color);
			context->drawCircle(p.x, p.y, radius);
		}
		inline void drawArc(const ffw::Vec2f& p, float inner, float outer, float start, float end, const ffw::Color& color) const override {
			context->setDrawColor(color);
			context->drawArc(p.x, p.y, inner, outer, start, end);
		}
		inline void drawQuad(const ffw::Vec2f& p0, const ffw::Vec2f& p1, const ffw::Vec2f& p2, const ffw::Vec2f& p3, const ffw::Color& color) const override {
			context->setDrawColor(color);
			context->drawQuad(p0.x, p0.y, p1.x, p1.y, p2.x, p2.y, p3.x, p3.y);
		}
		inline void drawString(const ffw::Vec2f& p, const ffw::GuiFont* font, const std::wstring::value_type* str, size_t length, const ffw::Color& color, float lineHeight = 1.25f) const override {
			context->setDrawColor(color);
			context->drawString(p.x, p.y, dynamic_cast<const ffw::TrueTypeFont*>(font), str, length, lineHeight);
		}
		inline void drawTriangle(const ffw::Vec2f& p0, const ffw::Vec2f& p1, const ffw::Vec2f& p2, const ffw::Color& color) const override {
			context->setDrawColor(color);
			context->drawTriangle(p0.x, p0.y, p1.x, p1.y, p2.x, p2.y);
		}
		inline void drawImage(const ffw::Vec2f& p, const ffw::Vec2f& s, const GuiImage* image, const ffw::Vec4i& sub, bool mirrorX, bool mirrorY, const ffw::Color& color) const override {
			context->setDrawColor(color);
			context->drawTexture2DSubMirror(p.x, p.y, s.x, s.y, dynamic_cast<const ffw::Texture2D*>(image), sub.x, sub.y, sub.z, sub.w, mirrorX, mirrorY);
		}
		inline virtual void startRender() override {
			glEnable(GL_SCISSOR_TEST);
		}
		inline virtual void endRender() override {
			glDisable(GL_SCISSOR_TEST);
		}
		inline virtual void setScissors(const ffw::Vec2f& p, const ffw::Vec2f& s) const override {
			GLint m_viewport[4];
			glGetIntegerv(GL_VIEWPORT, m_viewport);
			glScissor((int)floor(p.x), m_viewport[3] - (int)floor(p.y) - (int)ceil(s.y), (int)ceil(s.x), (int)ceil(s.y));
		}
		inline virtual void clearWithColor(const ffw::Color& color) const override {
			glClearColor(color.r, color.g, color.b, color.a);
			glClear(GL_COLOR_BUFFER_BIT);
		}
	protected:
		RenderContext* context;
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
			
			if(!fboTexture.create(context, 128, 128, GL_RGBA8, GL_RGBA, GL_UNSIGNED_BYTE))
				return false;
			
			if(!fbo.create(ctx))
				return false;
			
			fbo.bind();
			if(!fbo.addColorTexture(&fboTexture))
				return false;
			
			fbo.unbind();
			return true;
		}
		inline void destroy(){
			fboTexture.destroy();
			fbo.destroy();
		}
		inline void resize(int width, int height) override {
			fboTexture.resize(width, height);
		}
		inline void startRender() override {
			fbo.bind();
			glGetIntegerv(GL_VIEWPORT, &viewport.x);
			context->setViewport(0, 0, (int)getSize().x, (int)getSize().y);
			glEnable(GL_SCISSOR_TEST);
		}
		inline void endRender() override {
			glDisable(GL_SCISSOR_TEST);
			fbo.unbind();
			context->setViewport(viewport.x, viewport.y, viewport.z, viewport.w);
		}
		inline const ffw::Texture2D* getFboTexture() const {
			return &fboTexture;
		}
	private:
		ffw::Framebuffer fbo;
		ffw::Texture2D fboTexture;
		ffw::Vec4i viewport;
	};
}
#endif
