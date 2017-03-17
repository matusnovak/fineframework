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
			void setValue(int value);
			int getValue() const;
			void assign(GuiRadio* radio);
			void remove(GuiRadio* radio);
			void clearAllExcept(const GuiRadio* radio);
			size_t getNumOfAssigned() const;
		private:
			std::vector<GuiRadio*> radios;
			int value;
		};
		
		class FFW_API Button : public GuiWidget {
		public:
			Button(GuiWindow* context);
			virtual ~Button();
			ffw::Vec2i getMinimumWrapSize() override;
			GuiRadio::Value* group;
			GuiRadio* parentradio;
		private:
			void eventRender(const ffw::Vec2i& contentoffset, const ffw::Vec2i& contentsize) override;
			void eventPos(const ffw::Vec2i& pos) override;
			void eventSize(const ffw::Vec2i& size) override;
			void eventHover(bool gained) override;
			void eventFocus(bool gained) override;
			void eventMouse(const ffw::Vec2i& pos) override;
			void eventMouseButton(ffw::MouseButton button, ffw::Mode mode) override;
			void eventText(wchar_t chr) override;
			void eventKey(ffw::Key key, ffw::Mode mode) override;
			void eventDisabled(bool disabled) override;
			virtual void eventThemeChanged(const GuiTheme* theme) override;
		};
		
		GuiRadio(GuiWindow* context, const std::string& label, int base, GuiRadio* other = NULL);
		GuiRadio(GuiWindow* context, const std::wstring& label, int base, GuiRadio* other = NULL);
		virtual ~GuiRadio();
		void setLabel(const std::wstring& label);
		const std::wstring& getLabel() const;
		int getBaseValue() const;
		void setValue(int value);
		int getValue() const;
		void assignValue(bool value);
		void setButtonSize(int width);
		inline const GuiRadio::Button* getButton() const {
			return widgetbutton;
		}
		const GuiRadio::Button* getButton(){
			return widgetbutton;
		}
		ffw::Vec2i getMinimumWrapSize() override;
	private:
		void eventRender(const ffw::Vec2i& contentoffset, const ffw::Vec2i& contentsize) override;
		void eventPos(const ffw::Vec2i& pos) override;
		void eventSize(const ffw::Vec2i& size) override;
		void eventHover(bool gained) override;
		void eventFocus(bool gained) override;
		void eventMouse(const ffw::Vec2i& pos) override;
		void eventMouseButton(ffw::MouseButton button, ffw::Mode mode) override;
		void eventText(wchar_t chr) override;
		void eventKey(ffw::Key key, ffw::Mode mode) override;
		void eventDisabled(bool disabled) override;
		virtual void eventThemeChanged(const GuiTheme* theme) override;
		GuiRadio::Button* widgetbutton;
		std::wstring label;
		int indent;
		int basevalue;
		GuiRadio::Value* group;
	};
}
#endif
