/* This file is part of FineFramework project */
#ifndef FFW_GUI_SCROLLBAR
#define FFW_GUI_SCROLLBAR
#include "guiwidget.h"
#include "guibutton.h"
#include "guislider.h"
namespace ffw {
	/**
	 * @ingroup gui
	 */
	class FFW_API GuiScrollbar: public GuiWidget {
	public:
		GuiScrollbar(GuiWindow* context, bool vertical);
		virtual ~GuiScrollbar();
		void SetValue(int val);
		int GetValue() const;
		const ffw::Vec2i& GetRange() const ;
		void SetRange(int min, int max);
		ffw::Vec2i GetMinimumWrapSize() const override;
		int GetIncrement() const;
		void SetIncrement(int inc);
		template<class T>
		void SetOnValueChangedCallback(void (T::*memfuncptr)(GuiEvent), T* instance){
			slider->SetOnValueChangedCallback(memfuncptr, instance);
		}
		template<class T>
		void SetOnClickCallback(void (T::*memfuncptr)(GuiEvent), T* instance){
			slider->SetOnClickCallback(memfuncptr, instance);
		}
		ffw::GuiStyleGroup& StyleLeft();
		ffw::GuiStyleGroup& StyleRight();
		ffw::GuiStyleGroup& StyleButton();
		const ffw::GuiStyleGroup& StyleLeft() const;
		const ffw::GuiStyleGroup& StyleRight() const;
		const ffw::GuiStyleGroup& StyleButton() const;
	private:
		void ButtonCallback(ffw::GuiEvent e);
		void EventRender(const ffw::Vec2i& contentoffset, const ffw::Vec2i& contentsize) override;
		void EventPos(const ffw::Vec2i& pos) override;
		void EventSize(const ffw::Vec2i& size) override;
		void EventHover(bool gained) override;
		void EventFocus(bool gained) override;
		void EventMouse(const ffw::Vec2i& pos) override;
		void EventMouseButton(ffw::MouseButton button, ffw::Mode mode) override;
		void EventText(wchar_t chr) override;
		void EventKey(ffw::Key key, ffw::Mode mode) override;
		ffw::GuiButton* left;
		ffw::GuiButton* right;
		ffw::GuiSlider* slider;
		int increments;
	};
}
#endif
