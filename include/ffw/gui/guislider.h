/* This file is part of FineFramework project */
#ifndef FFW_GUI_SLIDER
#define FFW_GUI_SLIDER
#include "guiwidget.h"
namespace ffw {
	class FFW_API GuiSlider: public GuiWidget {
	public:
		GuiSlider(GuiWindow* context, bool vertical);
		virtual ~GuiSlider();
		inline void SetColor(const ffw::Color& c){
			color = c;
			Redraw();
		}
		inline const ffw::Color& GetColor() const {
			return color;
		}
		inline void SetValue(int val){
			value = val;
			Redraw();
		}
		inline int GetValue() const {
			return value;
		}
		inline const ffw::Vec2i& GetRange() const {
			return range;
		}
		inline void SetRange(int min, int max){
			range.Set(min, max);
			Redraw();
		}
		inline void SetButtonSize(int size){
			buttonsize = size;
			Redraw();
		}
		inline int GetButtonSize() const {
			return buttonsize;
		}
		inline void SetThickness(int val){
			thickness = val;
			Redraw();
		}
		inline int GetThickness() const {
			return thickness;
		}
		inline void SetInversed(bool inversed){
			inverse = inversed;
			Redraw();
		}
		inline bool GetInversed() const {
			return inverse;
		}
		ffw::Vec2i GetMinimumWrapSize() const override;
		GuiStyleGroup stylebutton;
		GuiStyleGroup stylebar;
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
	};
}
#endif
