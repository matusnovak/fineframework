/* This file is part of FineFramework project */
#ifndef FFW_GUI_BUTTON_TOGGLE
#define FFW_GUI_BUTTON_TOGGLE
#include "guibutton.h"
namespace ffw {
	/**
	 * @ingroup gui
	 */
	class FFW_API GuiButtonToggle: public GuiButton {
	public:
		GuiButtonToggle(GuiWindow* context, const std::string& label);
		GuiButtonToggle(GuiWindow* context, const std::wstring& label);
		virtual ~GuiButtonToggle();
		void SetValue(bool value);
		bool GetValue() const;
	};
}
#endif
