/* This file is part of FineFramework project */
#ifndef FFW_GUI_RADIO
#define FFW_GUI_RADIO
#include "guilabel.h"
#include <functional>
namespace ffw {
	class GuiRadio;
	/**
	 * @ingroup gui
	 */
	class FFW_API GuiRadioValue {
	public:
		GuiRadioValue();
		~GuiRadioValue();
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
	class FFW_API GuiRadioBtn: public GuiWidget {
	public:
		GuiRadioBtn(GuiWindow* context);
		virtual ~GuiRadioBtn();
		void SetLabel(const std::string& label);
		const std::string& GetLabel() const;
		template <typename T>
		void SetOnClickCallback(void (T::*memfuncptr)(GuiEvent), T* instance){
			onclickcallback = std::bind(memfuncptr, instance, std::placeholders::_1);
		}
		ffw::Vec2i GetMinimumWrapSize() const override;
		GuiRadioValue* group;
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
		std::function<void(GuiEvent)> onclickcallback;
	};
	/**
	 * @ingroup gui
	 */
	class FFW_API GuiRadio: public GuiWidget {
	public:
		GuiRadio(GuiWindow* context, const std::string& label, int base, GuiRadio* other = NULL);
		virtual ~GuiRadio();
		void SetLabel(const std::string& label);
		const std::string& GetLabel() const;
		int GetBaseValue() const;
		void SetValue(int value);
		int GetValue() const;
		void AssignValue(bool value);
		inline void SetIndent(int indent_){
			indent = indent_;
			Invalidate();
		}
		inline void SetButtonSize(int width){
			widgetbutton->SetSize(width, width);
		}
		inline GuiStyleGroup& ButtonStyle() {
			return widgetbutton->style;
		}
		inline const GuiStyleGroup& ButtonStyle() const {
			return widgetbutton->style;
		}
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
		GuiRadioBtn* widgetbutton;
		std::string label;
		int indent;
		int basevalue;
		GuiRadioValue* group;
	};
}
#endif
