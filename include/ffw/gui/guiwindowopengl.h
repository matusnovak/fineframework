/* This file is part of FineFramework project */
#ifndef FFW_GUI_WINDOW_OPENGL
#define FFW_GUI_WINDOW_OPENGL
#include "guibackend.h"
#ifdef FFW_GRAPHICS_MODULE
#include "guifontopengl.h"
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
		inline bool Create(const RenderContext* ctx){
			if(ctx == NULL)return false;
			context = ctx;
			return true;
		}
		inline void Destroy(){
		}
		inline void Resize(int width, int height) override {

		}
		inline GuiFont* CreateFontFromData(const unsigned char* buffer, size_t length, int points, int dpi, int start = 0x00, int end = 0xFF) const override {
			auto* fnt = new GuiFontOpenGL();
			ffw::Font& font = fnt->Get();
			if(!font.CreateFromData(context, buffer, length, points, dpi, start, end)){
				delete fnt;
				return NULL;
			}
			return fnt;
		}
		inline GuiFont* CreateFontFromFile(const std::string& path, int points, int dpi, int start = 0x00, int end = 0xFF) const override {
			auto* fnt = new GuiFontOpenGL();
			ffw::Font& font = fnt->Get();
			if(!font.CreateFromFile(context, path, points, dpi, start, end)){
				delete fnt;
				return NULL;
			}
			return fnt;
		}
		inline void DrawRectangle(const ffw::Vec2i& pos, const ffw::Vec2i& size, const ffw::Color& color) const override {
			ffw::SetDrawColor(color);
			ffw::DrawRectangle(pos.x, pos.y, size.x, size.y);
		}
		inline void DrawCircle(const ffw::Vec2i& pos, int radius, const ffw::Color& color) const override {
			ffw::SetDrawColor(color);
			ffw::DrawCircle(pos.x, pos.y, radius, 16);
		}
		inline void DrawArc(const ffw::Vec2i& pos, int inner, int outer, float start, float end, const ffw::Color& color) const override {
			ffw::SetDrawColor(color);
			ffw::DrawArc(pos.x, pos.y, inner, outer, start, end, 8);
		}
		inline void DrawQuad(const ffw::Vec2i& p0, const ffw::Vec2i& p1, const ffw::Vec2i& p2, const ffw::Vec2i& p3, const ffw::Color& color) const override {
			ffw::SetDrawColor(color);
			ffw::DrawQuad(p0.x, p0.y, p1.x, p1.y, p2.x, p2.y, p3.x, p3.y);
		}
		void DrawString(const ffw::Vec2i& pos, const ffw::GuiFont* font, const std::wstring& str, const ffw::Color& color) const override {
			ffw::SetDrawColor(color);
			ffw::DrawString(pos.x, pos.y, &dynamic_cast<const ffw::GuiFontOpenGL*>(font)->Get(), str);
		}
		inline void StartRender() override {
			glEnable(GL_SCISSOR_TEST);
		}
		inline void EndRender() override {
			glDisable(GL_SCISSOR_TEST);
		}
		inline void SetScissors(const ffw::Vec2i& pos, const ffw::Vec2i& size) const override {
			GLint m_viewport[4];
			glGetIntegerv(GL_VIEWPORT, m_viewport);
			glScissor(pos.x, m_viewport[3] - pos.y - size.y, size.x, size.y);
		}
		inline void ClearWithColor(const ffw::Color& color) const override {
			glClearColor(color.r, color.g, color.b, color.a);
			glClear(GL_COLOR_BUFFER_BIT);
		}
	private:
		const RenderContext* context;
		ffw::Vec2i size;
		ffw::Vec2i pos;
		mutable float vertices[8 * 4 * 2 * 2];
		mutable float colors[8 * 4 * 2 * 3];
	};
}
#endif
#endif
