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
	class GuiBackendOpenGL: public GuiBackend {
	private:
		const RenderContext* context;
		ffw::Vec2i size;
		ffw::Vec2i pos;
	public:
		inline GuiBackendOpenGL(){
		}
		inline virtual ~GuiBackendOpenGL(){
		}
		inline bool Create(const RenderContext* context_){
			if(context_ == NULL)return false;
			context = context_;
			return true;
		}
		inline void Destroy(){
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
		inline void SetDrawColor(const ffw::Color& color) const override {
			ffw::SetDrawColor(color);
		}
		inline void DrawQuad(const ffw::Vec2i& p0, const ffw::Vec2i& p1, const ffw::Vec2i& p2, const ffw::Vec2i& p3) const override {
			ffw::DrawQuad(p0.x, p0.y, p1.x, p1.y, p2.x, p2.y, p3.x, p3.y);
		}
		inline void DrawRectangle(const ffw::Vec2i& pos, const ffw::Vec2i& size) const override {
			ffw::DrawRectangle(pos.x, pos.y, size.x, size.y);
		}
		inline void DrawString(const ffw::Vec2i& pos, const ffw::GuiFont* font, const std::wstring& str, size_t beg = 0, size_t len = -1) const override {
			const ffw::GuiFontOpenGL* fnt = dynamic_cast<const ffw::GuiFontOpenGL*>(font);
			if(fnt != NULL){
				if(len == -1)
					ffw::DrawString(pos.x, pos.y, &fnt->Get(), &str[beg], str.size() - len);
				else
					ffw::DrawString(pos.x, pos.y, &fnt->Get(), &str[beg], len);
			}
		}
		inline void DrawLine(const ffw::Vec2i& start, const ffw::Vec2i& end, int thickness) const override {
			if(thickness <= 1)ffw::DrawLine(start.x, start.y, end.x, end.y);
			else ffw::DrawLineThick(start.x, start.y, end.x, end.y, thickness);
		}
		inline void DrawCircle(const ffw::Vec2i& pos, int radius, int steps) const override {
			ffw::DrawCircle(pos.x, pos.y, radius, steps);
		}
		inline void DrawArc(const ffw::Vec2i& pos, int inner, int outer, float start, float end, int steps) const override {
			ffw::DrawArc(pos.x, pos.y, inner, outer, start, end, steps);
		}
		inline void DrawTriangleFan(const ffw::Vec2i* arr, int num) const {
			ffw::DrawTriangleFan(reinterpret_cast<const int*>(arr), num);
		}
		inline void Resize(int width, int height) override {
		}
	};
}
#endif
#endif
