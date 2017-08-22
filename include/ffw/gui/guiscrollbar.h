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
			void eventThemeChanged(const GuiTheme* theme) override;
		private:
			void eventRender(const ffw::Vec2f& contentoffset, const ffw::Vec2f& contentsize) override;
			bool top;
		};

		class ButtonSecond : public GuiButton {
		public:
			ButtonSecond(GuiWindow* context, bool vertical);
			virtual ~ButtonSecond();
			void eventThemeChanged(const GuiTheme* theme) override;
		private:
			void eventRender(const ffw::Vec2f& contentoffset, const ffw::Vec2f& contentsize) override;
			bool bot;
		};

		class Scroll : public GuiSlider {
		public:
			Scroll(GuiWindow* context, bool vertical);
			virtual ~Scroll();
			void eventThemeChanged(const GuiTheme* theme) override;
		};

		GuiScrollBar(GuiWindow* context, bool vertical);
		inline bool isVertical() const {
			return slider->isVertical();
		}
		inline GuiButton* getButtonFirst() {
			return left;
		}
		inline const GuiButton* getButtonFirst() const {
			return left;
		}
		inline GuiButton* getButtonSecond() {
			return right;
		}
		inline const GuiButton* getButtonSecond() const {
			return right;
		}
		inline GuiSlider* getSlider() {
			return slider;
		}
		inline const GuiSlider* getSlider() const {
			return slider;
		}
		inline void setValue(float val) {
			slider->setValue(val);
		}
		inline float getValue() const {
			return slider->getValue();
		}
		inline const ffw::Vec2f& getRange() const {
			return slider->getRange();
		}
		inline void setRange(float min, float max) {
			slider->setRange(min, max);
		}
		inline void setInversed(bool inversed) {
			slider->setInversed(inversed);
		}
		inline bool getInversed() const {
			return slider->getInversed();
		}
		inline void setIncrements(float inc) {
			increments = inc;
		}
		inline float getIncrements() const {
			return increments;
		}
		void setButtonLength(GuiUnits length);
		inline GuiUnits getButtonLength() const {
			if (slider->isVertical())return slider->getButtonSize().y;
			else return slider->getButtonSize().x;
		}
		virtual ~GuiScrollBar();
		ffw::Vec2f getMinimumWrapSize() override;
	private:
		void eventRender(const ffw::Vec2f& contentoffset, const ffw::Vec2f& contentsize) override;
		void eventPos(const ffw::Vec2f& pos) override;
		void eventSize(const ffw::Vec2f& size) override;
		void eventHover(bool gained) override;
		void eventFocus(bool gained) override;
		void eventMouse(const ffw::Vec2f& pos) override;
		bool eventScroll(const ffw::Vec2f& scroll) override;
		void eventMouseButton(ffw::MouseButton button, ffw::Mode mode) override;
		void eventText(wchar_t chr) override;
		void eventKey(ffw::Key key, ffw::Mode mode) override;
		void eventDisabled(bool disabled) override;
		void eventThemeChanged(const GuiTheme* theme) override;
		void recalculate(const ffw::Vec2f& size);
		void ButtonCallback(ffw::GuiEvent e);
		GuiButton* left;
		GuiButton* right;
		GuiSlider* slider;
		float increments;
	};
}
#endif
