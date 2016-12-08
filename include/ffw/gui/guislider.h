/* This file is part of FineFramework project */
#ifndef FFW_GUI_SLIDER
#define FFW_GUI_SLIDER
#include "guiwidget.h"
#include <functional>
namespace ffw {
	/**
	 * @ingroup gui
	 */
	class FFW_API GuiSlider: public GuiWidget {
	public:
		GuiSlider(GuiWindow* context, bool vertical);
		virtual ~GuiSlider();
		bool IsVertical() const;
		void SetColor(const ffw::Color& c);
		const ffw::Color& GetColor() const;
		void SetValue(int val);
		int GetValue() const;
		const ffw::Vec2i& GetRange() const;
		void SetRange(int min, int max);
		void SetButtonSize(int size);
		int GetButtonSize() const;
		void SetThickness(int val);
		int GetThickness() const;
		void SetInversed(bool inversed);
		bool GetInversed() const;
		ffw::Vec2i GetMinimumWrapSize() const override;
		inline GuiStyleGroup& StyleBar(){
			return stylebar;
		}
		inline const GuiStyleGroup& StyleBar() const {
			return stylebar;
		}
		inline GuiStyleGroup& StyleButton(){
			return stylebutton;
		}
		inline const GuiStyleGroup& StyleButton() const {
			return stylebutton;
		}
		template<class T>
		void SetOnValueChangedCallback(void (T::*memfuncptr)(GuiEvent), T* instance){
			onvaluechangedcallback = std::bind(memfuncptr, instance, std::placeholders::_1);
		}
		template<class T>
		void SetOnClickCallback(void (T::*memfuncptr)(GuiEvent), T* instance){
			onclickcallback = std::bind(memfuncptr, instance, std::placeholders::_1);
		}
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
		bool vertical;
		ffw::Color color;
		ffw::Vec2i range;
		int value;
		int buttonsize;
		int thickness;
		bool inverse;
		std::function<void(GuiEvent)> onvaluechangedcallback;
		std::function<void(GuiEvent)> onclickcallback;
		GuiStyleGroup stylebutton;
		GuiStyleGroup stylebar;
	};
}
#endif
