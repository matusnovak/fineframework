/*** This file is part of FineFramework project ***/

#include "ffw/gui/guibuttontoggle.h"
#include "ffw/gui/guiwindow.h"

///=============================================================================
ffw::GuiButtonToggle::GuiButtonToggle(GuiWindow* context, const std::string& label):GuiButtonToggle(context, Utf8ToWstr(label)){
}

///=============================================================================
ffw::GuiButtonToggle::GuiButtonToggle(GuiWindow* context, const std::wstring& label):GuiButton(context, label){
	togglefocusflag = true;
	dropfocusflag = false;
}

///=============================================================================
ffw::GuiButtonToggle::~GuiButtonToggle(){
}

///=============================================================================
void ffw::GuiButtonToggle::SetValue(bool value) {
	SetFocus(value);
}

///=============================================================================
bool ffw::GuiButtonToggle::GetValue() const {
	return HasFocus();
}