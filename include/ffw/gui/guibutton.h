/* This file is part of FineFramework project */
#ifndef FFW_GUI_BUTTON
#define FFW_GUI_BUTTON
#include "guiwidget.h"
#include <functional>
namespace ffw {
	class FFW_API GuiButton: public GuiWidget {
	public:
		GuiButton(GuiWindow* context, const std::string& label);
		virtual ~GuiButton();
		void setLabel(const std::string& label);
		const std::string& getLabel() const;
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
