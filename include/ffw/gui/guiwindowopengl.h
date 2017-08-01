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
		inline void drawRectangle(const ffw::Vec2i& pos, const ffw::Vec2i& size, const ffw::Color& color) const override {
			context->setDrawColor(color);
			context->drawRectangle((float)pos.x, (float)pos.y, (float)size.x, (float)size.y);
		}
		inline void drawRectangleRounded(const ffw::Vec2i& pos, const ffw::Vec2i& size, const ffw::Color& color, int tl, int tr, int br, int bl) const override {
			context->setDrawColor(color);
			context->drawRectangleRounded((float)pos.x, (float)pos.y, (float)size.x, (float)size.y, (float)tl, (float)tr, (float)br, (float)bl);
		}
		inline void drawLine(const ffw::Vec2i& start, const ffw::Vec2i& end, const ffw::Color& color) const override  {
			context->setDrawColor(color);
			context->drawLine((float)start.x, (float)start.y, (float)end.x, (float)end.y);
		}
		inline void drawCircle(const ffw::Vec2i& pos, int radius, const ffw::Color& color) const override {
			context->setDrawColor(color);
			context->drawCircle((float)pos.x, (float)pos.y, (float)radius);
		}
		inline void drawArc(const ffw::Vec2i& pos, int inner, int outer, float start, float end, const ffw::Color& color) const override {
			context->setDrawColor(color);
			context->drawArc((float)pos.x, (float)pos.y, (float)inner, (float)outer, start, end);
		}
		inline void drawQuad(const ffw::Vec2i& p0, const ffw::Vec2i& p1, const ffw::Vec2i& p2, const ffw::Vec2i& p3, const ffw::Color& color) const override {
			context->setDrawColor(color);
			context->drawQuad((float)p0.x, (float)p0.y, (float)p1.x, (float)p1.y, (float)p2.x, (float)p2.y, (float)p3.x, (float)p3.y);
		}
		inline void drawString(const ffw::Vec2i& pos, const ffw::GuiFont* font, const std::wstring::value_type* str, size_t length, const ffw::Color& color, float lineHeight = 1.25f) const override {
			context->setDrawColor(color);
			context->drawString((float)pos.x, (float)pos.y, dynamic_cast<const ffw::TrueTypeFont*>(font), str, length, lineHeight);
		}
		inline void drawTriangle(const ffw::Vec2i& p0, const ffw::Vec2i& p1, const ffw::Vec2i& p2, const ffw::Color& color) const override {
			context->setDrawColor(color);
			context->drawTriangle((float)p0.x, (float)p0.y, (float)p1.x, (float)p1.y, (float)p2.x, (float)p2.y);
		}
		inline void drawImage(const ffw::Vec2i& pos, const ffw::Vec2i& size, const GuiImage* image, const ffw::Vec4i& sub, bool mirrorX, bool mirrorY, const ffw::Color& color) const override {
			context->setDrawColor(color);
			context->drawTexture2DSubMirror((float)pos.x, (float)pos.y, (float)size.x, (float)size.y, dynamic_cast<const ffw::Texture2D*>(image), sub.x, sub.y, sub.z, sub.w, mirrorX, mirrorY);
		}
		inline virtual void startRender() override {
			glEnable(GL_SCISSOR_TEST);
		}
		inline virtual void endRender() override {
			glDisable(GL_SCISSOR_TEST);
		}
		inline virtual void setScissors(const ffw::Vec2i& pos, const ffw::Vec2i& size) const override {
			GLint m_viewport[4];
			glGetIntegerv(GL_VIEWPORT, m_viewport);
			glScissor(pos.x, m_viewport[3] - pos.y - size.y, size.x, size.y);
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
			context->setViewport(0, 0, getSize().x, getSize().y);
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
