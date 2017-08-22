/* This file is part of FineFramework project */
#ifndef FFW_GUI_RICH_TEXT
#define FFW_GUI_RICH_TEXT
#include "guiwidget.h"
#include "guitextwrapper.h"
namespace ffw {
	/**
	* @ingroup gui
	*/
	class FFW_API GuiRichText : public GuiWidget {
	public:
		GuiRichText(GuiWindow* context);
		virtual ~GuiRichText();
		void setText(const std::wstring& label);
		const std::wstring getText() const;
		ffw::Vec2f getMinimumWrapSize() override;
		void addParagraph();
		void addSection(const ffw::Color& color, ffw::GuiFont* font = NULL);
		void addSection(ffw::GuiFont* font);
		void addSectionDefault();
		void addText(const std::wstring& str);
	private:
		void eventRender(const ffw::Vec2f& contentoffset, const ffw::Vec2f& contentsize) override;
		void eventPos(const ffw::Vec2f& pos) override;
		void eventSize(const ffw::Vec2f& size) override;
		void eventHover(bool gained) override;
		void eventFocus(bool gained) override;
		void eventMouse(const ffw::Vec2f& pos) override;
		bool eventScroll(const ffw::Vec2f& scroll) override;
		void eventMouseButton(ffw::MouseButton button, ffw::Mode mode) override;
		void eventText(wchar_t chr) override;
		void eventKey(ffw::Key key, ffw::Mode mode) override;
		void eventDisabled(bool disabled) override;
		virtual void eventThemeChanged(const GuiTheme* theme) override;
		GuiTextWrapper text;
		float lastCalculatedWidth;
	};
}
#endif
