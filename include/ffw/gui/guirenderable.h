/* This file is part of FineFramework project */
#ifndef FFW_GUI_RENDERABLE
#define FFW_GUI_RENDERABLE
#include "guifont.h"
#include "guitheme.h"
namespace ffw {
	class GuiWindow;
	class FFW_API GuiRenderable {
	public:
		GuiRenderable(GuiWindow* context, const std::type_info& type);
		virtual ~GuiRenderable();
		void SetTheme(const GuiTheme* theme);
		void SetStyleGroup(const GuiStyleGroup* style);
		const ffw::GuiStyle& GetCurrentStyle() const;
		inline const ffw::Vec2i& GetRealSize() const {
			return sizereal;
		}
		inline const ffw::Vec2i& GetRealPos() const {
			return posreal;
		}
	protected:
		GuiWindow* context;
		ffw::Vec2i sizereal;
		ffw::Vec2i posreal;
		bool hoverflag;
		bool focusflag;
		bool disableflag;
		const GuiStyleGroup* widgetStyle;
	private:
		const std::type_info& info;
	};
};
#endif