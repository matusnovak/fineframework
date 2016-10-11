/* This file is part of FineFramework project */
#ifndef FFW_GUI_WINDOW_OPENGL
#define FFW_GUI_WINDOW_OPENGL
#include "guibackend.h"
#ifdef FFW_GRAPHICS_MODULE
#include "guifontopengl.h"
namespace ffw {
	class GuiBackendOpenGL: public GuiBackend {
	private:
		const RenderContext* context;
		ffw::Vec2i size;
		ffw::Vec2i pos;
	public:
		GuiBackendOpenGL(){
		}
		virtual ~GuiBackendOpenGL(){
		}
		bool Create(const RenderContext* context_){
			if(context_ == NULL)return false;
			context = context_;
			return true;
		}
		void Destroy(){
		}
		GuiFont* CreateFontFromData(const unsigned char* buffer, size_t length, int points, int dpi, int start = 0x00, int end = 0xFF) const override {
			auto* fnt = new GuiFontOpenGL();
			ffw::Font& font = fnt->Get();
			if(!font.CreateFromData(context, buffer, length, points, dpi, start, end)){
				delete fnt;
				return NULL;
			}
			return fnt;
		}
		GuiFont* CreateFontFromFile(const std::string& path, int points, int dpi, int start = 0x00, int end = 0xFF) const override {
			auto* fnt = new GuiFontOpenGL();
			ffw::Font& font = fnt->Get();
			if(!font.CreateFromFile(context, path, points, dpi, start, end)){
				delete fnt;
				return NULL;
			}
			return fnt;
		}
		void StartRender() override {
			glEnable(GL_SCISSOR_TEST);
		}
		void EndRender() override {
			glDisable(GL_SCISSOR_TEST);
		}
		void SetScissors(const ffw::Vec2i& pos, const ffw::Vec2i& size) const override {
			GLint m_viewport[4];
			glGetIntegerv(GL_VIEWPORT, m_viewport);
			glScissor(pos.x, m_viewport[3] - pos.y - size.y, size.x, size.y);
		}
		void ClearWithColor(const ffw::Color& color) const override {
			glClearColor(color.r, color.g, color.b, color.a);
			glClear(GL_COLOR_BUFFER_BIT);
		}
		void SetDrawColor(const ffw::Color& color) const override {
			ffw::SetDrawColor(color);
		}
		void DrawQuad(int p0x, int p0y, int p1x, int p1y, int p2x, int p2y, int p3x, int p3y) const override {
			ffw::DrawQuad(p0x, p0y, p1x, p1y, p2x, p2y, p3x, p3y);
		}
		void DrawRectangle(const ffw::Vec2i& pos, const ffw::Vec2i& size) const override {
			ffw::DrawRectangle(pos.x, pos.y, size.x, size.y);
		}
		void DrawString(const ffw::Vec2i& pos, const ffw::GuiFont* font, const std::string& str) const override {
			const ffw::GuiFontOpenGL* fnt = dynamic_cast<const ffw::GuiFontOpenGL*>(font);
			if(fnt != NULL){
				ffw::DrawString(pos.x, pos.y, &fnt->Get(), str);
			}
		}
		void DrawLine(const ffw::Vec2i& start, const ffw::Vec2i& end, int thickness) const override {
			if(thickness <= 1)ffw::DrawLine(start.x, start.y, end.x, end.y);
			else ffw::DrawLineThick(start.x, start.y, end.x, end.y, thickness);
		}
		void DrawCircle(const ffw::Vec2i& pos, int radius, int steps) const override {
			ffw::DrawCircle(pos.x, pos.y, radius, steps);
		}
		void DrawArc(const ffw::Vec2i& pos, int inner, int outer, float start, float end, int steps) const override {
			ffw::DrawArc(pos.x, pos.y, inner, outer, start, end, steps);
		}
		void DrawTriangleFan(const ffw::Vec2i* arr, int num) const {
			ffw::DrawTriangleFan(reinterpret_cast<const int*>(arr), num);
		}
		void Resize(int width, int height) override {
		}
	};
}
#endif
#endif
