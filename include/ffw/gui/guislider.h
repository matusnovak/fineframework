/* This file is part of FineFramework project */
#ifndef FFW_GUI_SLIDER
#define FFW_GUI_SLIDER
#include "guiwidget.h"
#include <functional>
namespace ffw {
	/**
	 * @ingroup gui
	 */
	class FFW_API GuiSlider: public GuiWidget {
	public:
		GuiSlider(GuiWindow* context, bool vertical, const std::type_info& type = typeid(GuiSlider));
		virtual ~GuiSlider();
		bool IsVertical() const;
		void SetValue(int val);
		int GetValue() const;
		const ffw::Vec2i& GetRange() const;
		void SetRange(int min, int max);
		void SetButtonSize(const ffw::Vec2i& s);
		const ffw::Vec2i& GetButtonSize() const;
		void SetInversed(bool inversed);
		bool GetInversed() const;
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
		bool vertical;
		ffw::Vec2i range;
		int value;
		ffw::Vec2i buttonsize;
		int thickness;
		bool inverse;
	};
}
#endif
