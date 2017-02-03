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
	class FFW_API GuiScrollBar : public GuiWidget {
	public:
		class ButtonFirst: public GuiButton {
		public:
			ButtonFirst(GuiWindow* context, bool vertical);
			virtual ~ButtonFirst();
			void EventThemeChanged(const GuiTheme* theme) override;
		};

		class ButtonSecond : public GuiButton {
		public:
			ButtonSecond(GuiWindow* context, bool vertical);
			virtual ~ButtonSecond();
			void EventThemeChanged(const GuiTheme* theme) override;
		};

		class Scroll : public GuiSlider {
		public:
			Scroll(GuiWindow* context, bool vertical);
			virtual ~Scroll();
			void EventThemeChanged(const GuiTheme* theme) override;
		};

		GuiScrollBar(GuiWindow* context, bool vertical);
		inline bool IsVertical() const {
			return slider->IsVertical();
		}
		inline GuiButton* GetButtonFirst() {
			return left;
		}
		inline const GuiButton* GetButtonFirst() const {
			return left;
		}
		inline GuiButton* GetButtonSecond() {
			return right;
		}
		inline const GuiButton* GetButtonSecond() const {
			return right;
		}
		inline GuiSlider* GetSlider() {
			return slider;
		}
		inline const GuiSlider* GetSlider() const {
			return slider;
		}
		inline void SetValue(int val) {
			slider->SetValue(val);
		}
		inline int GetValue() const {
			return slider->GetValue();
		}
		inline const ffw::Vec2i& GetRange() const {
			return slider->GetRange();
		}
		inline void SetRange(int min, int max) {
			slider->SetRange(min, max);
		}
		inline void SetInversed(bool inversed) {
			slider->SetInversed(inversed);
		}
		inline bool GetInversed() const {
			return slider->GetInversed();
		}
		inline void SetIncrements(int inc) {
			increments = inc;
		}
		inline int GetIncrements() const {
			return increments;
		}
		void SetButtonLength(GuiUnits length);
		inline GuiUnits GetButtonLength() const {
			if (slider->IsVertical())return slider->GetButtonSize().y;
			else return slider->GetButtonSize().x;
		}
		virtual ~GuiScrollBar();
		ffw::Vec2i GetMinimumWrapSize() override;
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
		void EventThemeChanged(const GuiTheme* theme) override;
		void Recalculate(const ffw::Vec2i& size);
		void ButtonCallback(ffw::GuiEvent e);
		GuiButton* left;
		GuiButton* right;
		GuiSlider* slider;
		int increments;
	};
}
#endif
