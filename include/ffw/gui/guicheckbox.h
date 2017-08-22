/* This file is part of FineFramework project */
#ifndef FFW_GUI_CHECKBOX
#define FFW_GUI_CHECKBOX
#include "guilabel.h"
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
			virtual void eventThemeChanged(const GuiTheme* theme) override;
		};

		GuiCheckbox(GuiWindow* context, const std::string& label);
		GuiCheckbox(GuiWindow* context, const std::wstring& label);
		virtual ~GuiCheckbox();
		void setLabel(const std::wstring& label);
		const std::wstring& getLabel() const;
		void setValue(bool value);
		bool getValue() const;
		inline const GuiCheckbox::Button* getButton() const {
			return widgetbutton;
		}
		GuiCheckbox::Button* getButton(){
			return widgetbutton;
		}
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
		virtual void eventThemeChanged(const GuiTheme* theme) override;
		GuiCheckbox::Button* widgetbutton;
		std::wstring label;
	};
}
#endif
