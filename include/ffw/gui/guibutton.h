/* This file is part of FineFramework project */
#ifndef FFW_GUI_BUTTON
#define FFW_GUI_BUTTON
#include "guiwidget.h"
namespace ffw {
	/**
	* @ingroup gui
	*/
	class FFW_API GuiButton : public GuiWidget {
	public:
		GuiButton(GuiWindow* context, const std::string& label);
		GuiButton(GuiWindow* context, const std::wstring& label);
		virtual ~GuiButton();
		void setLabel(const std::wstring& label);
		const std::wstring& getLabel() const;
		ffw::Vec2f getMinimumWrapSize() override;
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
		void eventThemeChanged(const GuiTheme* theme) override;
		std::wstring label;
	};
	/**
	* @ingroup gui
	*/
	class FFW_API GuiButtonPrimary : public GuiButton {
	public:
		GuiButtonPrimary(GuiWindow* context, const std::string& label);
		GuiButtonPrimary(GuiWindow* context, const std::wstring& label);
		virtual ~GuiButtonPrimary();
		void eventThemeChanged(const GuiTheme* theme) override;
	};
}
#endif
