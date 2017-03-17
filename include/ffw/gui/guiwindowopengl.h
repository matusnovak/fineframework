/* This file is part of FineFramework project */
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
		inline bool create(RenderContext* ctx){
			if(ctx == NULL)return false;
			context = ctx;
			return true;
		}
		inline void destroy(){
		}
		inline void resize(int width, int height) override {

		}
		inline void drawRectangle(const ffw::Vec2i& pos, const ffw::Vec2i& size, const ffw::Color& color) const override {
			context->setDrawColor(color);
			context->drawRectangle(pos.x, pos.y, size.x, size.y);
		}
		inline void drawRectangleRounded(const ffw::Vec2i& pos, const ffw::Vec2i& size, const ffw::Color& color, int tl, int tr, int br, int bl) const override {
			context->setDrawColor(color);
			context->drawRectangleRounded(pos.x, pos.y, size.x, size.y, tl, tr, br, bl);
		}
		inline void drawLine(const ffw::Vec2i& start, const ffw::Vec2i& end, const ffw::Color& color) const override  {
			context->setDrawColor(color);
			context->drawLine(start.x, start.y, end.x, end.y);
		}
		inline void drawCircle(const ffw::Vec2i& pos, int radius, const ffw::Color& color) const override {
			context->setDrawColor(color);
			context->drawCircle(pos.x, pos.y, radius);
		}
		inline void drawArc(const ffw::Vec2i& pos, int inner, int outer, float start, float end, const ffw::Color& color) const override {
			context->setDrawColor(color);
			context->drawArc(pos.x, pos.y, inner, outer, start, end);
		}
		inline void drawQuad(const ffw::Vec2i& p0, const ffw::Vec2i& p1, const ffw::Vec2i& p2, const ffw::Vec2i& p3, const ffw::Color& color) const override {
			context->setDrawColor(color);
			context->drawQuad(p0.x, p0.y, p1.x, p1.y, p2.x, p2.y, p3.x, p3.y);
		}
		inline void drawString(const ffw::Vec2i& pos, const ffw::GuiFont* font, const std::wstring::value_type* str, size_t length, const ffw::Color& color, float lineHeight = 1.25f) const override {
			context->setDrawColor(color);
			context->drawString(pos.x, pos.y, dynamic_cast<const ffw::TrueTypeFont*>(font), str, length, lineHeight);
		}
		inline void drawTriangle(const ffw::Vec2i& p0, const ffw::Vec2i& p1, const ffw::Vec2i& p2, const ffw::Color& color) const override {
			context->setDrawColor(color);
			context->drawTriangle(p0.x, p0.y, p1.x, p1.y, p2.x, p2.y);
		}
		inline void drawImage(const ffw::Vec2i& pos, const ffw::Vec2i& size, const GuiImage* image, const ffw::Vec4i& sub, bool mirrorX, bool mirrorY, const ffw::Color& color) const override {
			context->setDrawColor(color);
			context->drawTexture2DSubMirror(pos.x, pos.y, size.x, size.y, dynamic_cast<const ffw::Texture2D*>(image), sub.x, sub.y, sub.z, sub.w, mirrorX, mirrorY);
		}
		inline void startRender() override {
			glEnable(GL_SCISSOR_TEST);
		}
		inline void endRender() override {
			glDisable(GL_SCISSOR_TEST);
		}
		inline void setScissors(const ffw::Vec2i& pos, const ffw::Vec2i& size) const override {
			GLint m_viewport[4];
			glGetIntegerv(GL_VIEWPORT, m_viewport);
			glScissor(pos.x, m_viewport[3] - pos.y - size.y, size.x, size.y);
		}
		inline void clearWithColor(const ffw::Color& color) const override {
			glClearColor(color.r, color.g, color.b, color.a);
			glClear(GL_COLOR_BUFFER_BIT);
		}
	private:
		RenderContext* context;
	};
}
#endif
