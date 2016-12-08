/* This file is part of FineFramework project */
#ifndef FFW_GUI_PROGRESSBAR
#define FFW_GUI_PROGRESSBAR
#include "guiwidget.h"
namespace ffw {
	/**
	 * @ingroup gui
	 */
	class FFW_API GuiProgressBar: public GuiWidget {
	public:
		GuiProgressBar(GuiWindow* context, const std::string& label);
		GuiProgressBar(GuiWindow* context, const std::wstring& label);
		virtual ~GuiProgressBar();
		void SetLabel(const std::wstring& str);
		const std::wstring& GetLabel() const;
		void SetColor(const ffw::Color& c);
		const ffw::Color& GetColor() const;
		void SetValue(int val);
		int GetValue() const;
		const ffw::Vec2i& GetRange() const;
		void SetRange(int min, int max);
		ffw::Vec2i GetMinimumWrapSize() const override;
	private:
		void EventRender(const ffw::Vec2i& contentoffset, const ffw::Vec2i& contentsize) override;
		void EventPos(const ffw::Vec2i& pos) override;
		void EventSize(const ffw::Vec2i& size) override;
		void EventHover(bool gained) override;
		void EventFocus(bool gained) override;
		void EventMouse(const ffw::Vec2i& pos) override;
		void EventMouseButton(ffw::MouseButton button, ffw::Mode mode) override;
		void EventText(wchar_t chr) override;
		void EventKey(ffw::Key key, ffw::Mode mode) override;
		std::wstring label;
		ffw::Color color;
		ffw::Vec2i range;
		int value;
	};
}
#endif
