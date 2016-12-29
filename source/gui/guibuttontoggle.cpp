/*** This file is part of FineFramework project ***/

#include "ffw/gui/guibuttontoggle.h"
#include "ffw/gui/guiwindow.h"

///=============================================================================
ffw::GuiButtonToggle::GuiButtonToggle(GuiWindow* context, const std::string& label, const std::type_info& type):GuiButtonToggle(context, Utf8ToWstr(label), type){
}

///=============================================================================
ffw::GuiButtonToggle::GuiButtonToggle(GuiWindow* context, const std::wstring& label, const std::type_info& type):GuiButton(context, label, type){
	togglefocusflag = true;
	dropfocusflag = false;
}

///=============================================================================
ffw::GuiButtonToggle::~GuiButtonToggle(){
}
