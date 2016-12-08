/* This file is part of FineFramework project */
#ifndef FFW_GUI_CHECKBOX
#define FFW_GUI_CHECKBOX
#include "guilabel.h"
#include <functional>
namespace ffw {
	class GuiCheckbox;
	class FFW_API GuiCheckboxBtn: public GuiWidget {
	public:
		GuiCheckboxBtn(GuiWindow* context);
		virtual ~GuiCheckboxBtn();
		void SetLabel(const std::string& label);
		const std::string& GetLabel() const;
		template <typename T>
		void SetOnClickCallback(void (T::*memfuncptr)(GuiEvent), T* instance){
			onclickcallback = std::bind(memfuncptr, instance, std::placeholders::_1);
		}
		ffw::Vec2i GetMinimumWrapSize() const override;
		GuiCheckbox* parentcheckbox;
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
		std::function<void(GuiEvent)> onclickcallback;
	};
	/**
	 * @ingroup gui
	 */
	class FFW_API GuiCheckbox: public GuiWidget {
	public:
		GuiCheckbox(GuiWindow* context, const std::string& label);
		GuiCheckbox(GuiWindow* context, const std::wstring& label);
		virtual ~GuiCheckbox();
		void SetLabel(const std::wstring& label);
		const std::wstring& GetLabel() const;
		void SetValue(bool value);
		bool GetValue() const;
		void SetIndent(int indent_);
		void SetButtonSize(int width);
		GuiStyleGroup& ButtonStyle();
		const GuiStyleGroup& ButtonStyle() const;
		template <typename T>
		void SetOnClickCallback(void (T::*memfuncptr)(GuiEvent), T* instance){
			widgetbutton->SetOnClickCallback(memfuncptr, instance);
		}
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
		GuiCheckboxBtn* widgetbutton;
		std::wstring label;
		int indent;
	};
}
#endif
