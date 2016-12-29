/* This file is part of FineFramework project */
#ifndef FFW_GUI_BUTTON
#define FFW_GUI_BUTTON
#include "guiwidget.h"
#include <functional>
namespace ffw {
	/**
	 * @ingroup gui
	 */
	class FFW_API GuiButton: public GuiWidget {
	public:
		GuiButton(GuiWindow* context, const std::string& label, const std::type_info& type = typeid(GuiButton));
		GuiButton(GuiWindow* context, const std::wstring& label, const std::type_info& type = typeid(GuiButton));
		virtual ~GuiButton();
		void SetLabel(const std::wstring& label);
		const std::wstring& GetLabel() const;
		template <typename T>
		void SetOnClickCallback(void (T::*memfuncptr)(GuiEvent), T* instance, bool now = false){
			onclickcallback.Add(memfuncptr, instance, now);
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
		std::wstring label;
		GuiCallback onclickcallback;
	};
}
#endif
