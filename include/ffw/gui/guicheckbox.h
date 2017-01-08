/* This file is part of FineFramework project */
#ifndef FFW_GUI_CHECKBOX
#define FFW_GUI_CHECKBOX
#include "guilabel.h"
#include <functional>
namespace ffw {
	/**
	 * @ingroup gui
	 */
	class FFW_API GuiCheckbox: public GuiWidget {
	public:
		class FFW_API Button : public GuiWidget {
		public:
			Button(GuiWindow* context);
			virtual ~Button();
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
			void EventDisabled(bool disabled) override;
			virtual void EventThemeChanged(const GuiTheme* theme) override;
		};

		GuiCheckbox(GuiWindow* context, const std::string& label);
		GuiCheckbox(GuiWindow* context, const std::wstring& label);
		virtual ~GuiCheckbox();
		void SetLabel(const std::wstring& label);
		const std::wstring& GetLabel() const;
		void SetValue(bool value);
		bool GetValue() const;
		inline const GuiCheckbox::Button* GetButton() const {
			return widgetbutton;
		}
		GuiCheckbox::Button* GetButton(){
			return widgetbutton;
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
		void EventDisabled(bool disabled) override;
		virtual void EventThemeChanged(const GuiTheme* theme) override;
		GuiCheckbox::Button* widgetbutton;
		std::wstring label;
	};
}
#endif
