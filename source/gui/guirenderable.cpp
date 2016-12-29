/*** This file is part of FineFramework project ***/

#include "ffw/gui/guirenderable.h"
#include "ffw/gui/guiwindow.h"

///=============================================================================
ffw::GuiRenderable::GuiRenderable(GuiWindow* ctx, const std::type_info& type):info(type){
	assert(context != NULL);
	context = ctx;
	assert(context->GetTheme() != NULL);
	SetTheme(context->GetTheme());
	posreal.Set(0, 0);
	sizereal.Set(0, 0);
}

///=============================================================================
void ffw::GuiRenderable::SetTheme(const GuiTheme* theme) {
	if (theme == NULL)return;
	widgetStyle = &context->GetTheme()->GetByType(info);
}

///=============================================================================
void ffw::GuiRenderable::SetStyleGroup(const GuiStyleGroup* style) {
	if (style == NULL)return;
	widgetStyle = style;
}

///=============================================================================
const ffw::GuiStyle& ffw::GuiRenderable::GetCurrentStyle() const {
	if (disableflag)return widgetStyle->disabled;
	if (focusflag)return widgetStyle->active;
	if (hoverflag)return widgetStyle->hover;
	return widgetStyle->normal;
}

///=============================================================================
ffw::GuiRenderable::~GuiRenderable() {
}