/* This file is part of FineFramework project */
#ifndef FFW_GUI_FONT_OPENGL
#define FFW_GUI_FONT_OPENGL
#include "guifont.h"
namespace ffw {
	/**
	 * @ingroup gui
	 */
	class GuiFontOpenGL: public GuiFont{
	private:
		ffw::Font font;
	public:
		inline GuiFontOpenGL(){
		}
		inline ~GuiFontOpenGL(){
			Destroy();
		}
		inline bool IsCreated() const override {
			return font.IsCreated();
		}
		inline void Destroy() override {
			font.Destroy();
		}
		inline ffw::Vec2i GetStringSize(const std::wstring& str, float lineHeight = 1.25) const override {
			return font.GetStringSize(str, lineHeight);
		}
		inline ffw::Vec2i GetStringSize(const std::string& str, float lineHeight = 1.25) const override {
			return font.GetStringSize(str, lineHeight);
		}
		inline ffw::Font& Get(){
			return font;
		}
		inline const ffw::Font& Get() const {
			return font;
		}
		virtual int GetCharAdvance(wchar_t c) const override {
			return font.GetCharAdvance(c);
		}
		virtual int GetSizeInPixels() const override  {
			return font.GetSizeInPixels();
		}
	};
}
#endif
