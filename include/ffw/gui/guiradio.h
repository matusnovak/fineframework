/* This file is part of FineFramework project */
#ifndef FFW_GUI_RADIO
#define FFW_GUI_RADIO
#include "guilabel.h"

namespace ffw {
	/**
	 * @ingroup gui
	 */
	class FFW_API GuiRadio: public GuiWidget {
	public:
		class FFW_API Value {
		public:
			Value();
			~Value();
			void SetValue(int value);
			int GetValue() const;
			void Assign(GuiRadio* radio);
			void Remove(GuiRadio* radio);
			void ClearAllExcept(const GuiRadio* radio);
			size_t GetNumOfAssigned() const;
		private:
			std::vector<GuiRadio*> radios;
			int value;
		};
		
		class FFW_API Button : public GuiWidget {
		public:
			Button(GuiWindow* context);
			virtual ~Button();
			ffw::Vec2i GetMinimumWrapSize() const override;
			GuiRadio::Value* group;
			GuiRadio* parentradio;
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
		
		GuiRadio(GuiWindow* context, const std::string& label, int base, GuiRadio* other = NULL);
		GuiRadio(GuiWindow* context, const std::wstring& label, int base, GuiRadio* other = NULL);
		virtual ~GuiRadio();
		void SetLabel(const std::wstring& label);
		const std::wstring& GetLabel() const;
		int GetBaseValue() const;
		void SetValue(int value);
		int GetValue() const;
		void AssignValue(bool value);
		void SetButtonSize(int width);
		inline const GuiRadio::Button* GetButton() const {
			return widgetbutton;
		}
		const GuiRadio::Button* GetButton(){
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
		GuiRadio::Button* widgetbutton;
		std::wstring label;
		int indent;
		int basevalue;
		GuiRadio::Value* group;
	};
}
#endif
