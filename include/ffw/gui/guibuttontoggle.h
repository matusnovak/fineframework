/* This file is part of FineFramework project */
#ifndef FFW_GUI_BUTTON_TOGGLE
#define FFW_GUI_BUTTON_TOGGLE
#include "guiwidget.h"
#include <functional>
namespace ffw {
	/**
	 * @ingroup gui
	 */
	class FFW_API GuiButtonToggle: public GuiWidget {
	public:
		GuiButtonToggle(GuiWindow* context, const std::string& label);
		virtual ~GuiButtonToggle();
		void SetLabel(const std::string& label);
		const std::string& GetLabel() const;
		void SetValue(bool value);
		bool GetValue() const;
		template <typename T>
		void SetOnClickCallback(void (T::*memfuncptr)(GuiEvent), T* instance){
			onclickcallback = std::bind(memfuncptr, instance, std::placeholders::_1);
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
		std::function<void(GuiEvent)> onclickcallback;
	};
}
#endif
