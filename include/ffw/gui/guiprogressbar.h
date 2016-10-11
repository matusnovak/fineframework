/* This file is part of FineFramework project */
#ifndef FFW_GUI_PROGRESSBAR
#define FFW_GUI_PROGRESSBAR
#include "guiwidget.h"
namespace ffw {
	class FFW_API GuiProgressBar: public GuiWidget {
	public:
		GuiProgressBar(GuiWindow* context, const std::string& label);
		virtual ~GuiProgressBar();
		inline void SetLabel(const std::string& str){
			label = str;
			Redraw();
		}
		inline const std::string& GetLabel() const {
			return label;
		}
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
		std::string label;
		ffw::Color color;
		ffw::Vec2i range;
		int value;
	};
}
#endif
