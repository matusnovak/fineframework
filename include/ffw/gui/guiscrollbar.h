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
	class FFW_API GuiScrollbar : public GuiWidget {
	public:
		class ButtonLeft: public GuiButton {
		public:
			ButtonLeft(GuiWindow* context);
			virtual ~ButtonLeft();
			void EventThemeChanged(const GuiTheme* theme) override;
		};

		class ButtonRight : public GuiButton {
		public:
			ButtonRight(GuiWindow* context);
			virtual ~ButtonRight();
			void EventThemeChanged(const GuiTheme* theme) override;
		};

		class Scroll : public GuiSlider {
		public:
			Scroll(GuiWindow* context, bool vertical);
			virtual ~Scroll();
			void EventThemeChanged(const GuiTheme* theme) override;
		};

		GuiScrollbar(GuiWindow* context, bool vertical);
		inline bool IsVertical() const {
			return slider->IsVertical();
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
			if(!IsDisabled())
				SetDisabled(std::abs(max - min) == 0);
		}
		inline void SetInversed(bool inversed) {
			slider->SetInversed(inversed);
		}
		inline bool GetInversed() const {
			return slider->GetInversed();
		}
		virtual ~GuiScrollbar();
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
