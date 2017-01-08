/*** This file is part of FineFramework project ***/

#include "ffw/gui/guitheme.h"

///=============================================================================
ffw::GuiTheme::GuiTheme(const std::initializer_list<std::pair<std::string, GuiStyleGroup>>& list) {
	for(const auto& p : list) {
		styles.insert(p);
	}
}

///=============================================================================
ffw::GuiTheme::~GuiTheme() {
}

///=============================================================================
void ffw::GuiTheme::Add(const std::pair<std::string, GuiStyleGroup>& sty) {
	styles.insert(sty);
}

///=============================================================================
const ffw::GuiStyleGroup& ffw::GuiTheme::GetStyleGroup(const std::string& type) const  {
	if (styles.find(type) == styles.end()) {
		std::cerr << "No GuiStyleGroup found for: \"" << type << "\"" << std::endl;
		throw std::runtime_error("No GuiStyleGroup found for: \"" + type + "\"");
	}
	return styles.at(type);
}

///=============================================================================
ffw::GuiStyleGroup& ffw::GuiTheme::GetStyleGroup(const std::string& type) {
	if (styles.find(type) == styles.end()) {
		std::cerr << "No GuiStyleGroup found for: \"" << type << "\"" << std::endl;
		throw std::runtime_error("No GuiStyleGroup found for: \"" + type + "\"");
	}
	return styles.at(type);
}

///=============================================================================
const ffw::GuiTheme ffw::GuiTheme::Windows({
	// GUI LAYOUT
	{
		"GUI_LAYOUT",
		ffw::GuiStyleGroup (
			// Normal
			ffw::GuiStyle(
				ffw::GuiStyle::Background(0, ffw::Rgb(0x000000), ffw::Rgb(0x000000), ffw::GuiStyle::Background::Type::NONE),
				ffw::GuiStyle::Border(0, 0, ffw::Rgb(0x000000)),
				ffw::GuiStyle::Outline(0, 0, ffw::Rgb(0x000000)),
				ffw::GuiStyle::Text(ffw::Rgb(0xFFFFFF)),
				ffw::GuiStyle::Function(ffw::Rgb(0xFFFFFF))
			),
			// Hover
			ffw::GuiStyle(
				ffw::GuiStyle::Background(0, ffw::Rgb(0x000000), ffw::Rgb(0x000000), ffw::GuiStyle::Background::Type::NONE),
				ffw::GuiStyle::Border(0, 0, ffw::Rgb(0x000000)),
				ffw::GuiStyle::Outline(0, 0, ffw::Rgb(0x000000)),
				ffw::GuiStyle::Text(ffw::Rgb(0xFFFFFF)),
				ffw::GuiStyle::Function(ffw::Rgb(0xFFFFFF))
			),
			// Active
			ffw::GuiStyle(
				ffw::GuiStyle::Background(0, ffw::Rgb(0x000000), ffw::Rgb(0x000000), ffw::GuiStyle::Background::Type::NONE),
				ffw::GuiStyle::Border(0, 0, ffw::Rgb(0x000000)),
				ffw::GuiStyle::Outline(0, 0, ffw::Rgb(0x000000)),
				ffw::GuiStyle::Text(ffw::Rgb(0xFFFFFF)),
				ffw::GuiStyle::Function(ffw::Rgb(0xFFFFFF))
			),
			// Disabled
			ffw::GuiStyle(
				ffw::GuiStyle::Background(0, ffw::Rgb(0x000000), ffw::Rgb(0x000000), ffw::GuiStyle::Background::Type::NONE),
				ffw::GuiStyle::Border(0, 0, ffw::Rgb(0x000000)),
				ffw::GuiStyle::Outline(0, 0, ffw::Rgb(0x000000)),
				ffw::GuiStyle::Text(ffw::Rgb(0xFFFFFF)),
				ffw::GuiStyle::Function(ffw::Rgb(0xFFFFFF))
			),
			ffw::GuiDefaults(
				ffw::GuiStyle::Margin(0, 0, 0, 0),
				ffw::GuiStyle::Padding(0),
				ffw::GuiStyle::Align::TOP_LEFT,
				ffw::Vec2<GuiUnits>(ffw::GuiPercent(100), ffw::GuiWrap())
			)
		)
	},
	// GUI WINDOW BODY
	{
		"GUI_WINDOW_BODY",
		ffw::GuiStyleGroup(
			// Normal
			ffw::GuiStyle(
				ffw::GuiStyle::Background(0, ffw::Rgb(0xF0F0F0), ffw::Rgb(0x000000), ffw::GuiStyle::Background::Type::SIMPLE),
				ffw::GuiStyle::Border(0, 0, ffw::Rgb(0x000000)),
				ffw::GuiStyle::Outline(0, 0, ffw::Rgb(0x000000)),
				ffw::GuiStyle::Text(ffw::Rgb(0xFFFFFF)),
				ffw::GuiStyle::Function(ffw::Rgb(0xFFFFFF))
			),
			// Hover
			ffw::GuiStyle(
				ffw::GuiStyle::Background(0, ffw::Rgb(0xF0F0F0), ffw::Rgb(0x000000), ffw::GuiStyle::Background::Type::SIMPLE),
				ffw::GuiStyle::Border(0, 0, ffw::Rgb(0x000000)),
				ffw::GuiStyle::Outline(0, 0, ffw::Rgb(0x000000)),
				ffw::GuiStyle::Text(ffw::Rgb(0xFFFFFF)),
				ffw::GuiStyle::Function(ffw::Rgb(0xFFFFFF))
			),
			// Active
			ffw::GuiStyle(
				ffw::GuiStyle::Background(0, ffw::Rgb(0xF0F0F0), ffw::Rgb(0x000000), ffw::GuiStyle::Background::Type::SIMPLE),
				ffw::GuiStyle::Border(0, 0, ffw::Rgb(0x000000)),
				ffw::GuiStyle::Outline(0, 0, ffw::Rgb(0x000000)),
				ffw::GuiStyle::Text(ffw::Rgb(0xFFFFFF)),
				ffw::GuiStyle::Function(ffw::Rgb(0xFFFFFF))
			),
			// Disabled
			ffw::GuiStyle(
				ffw::GuiStyle::Background(0, ffw::Rgb(0xF0F0F0), ffw::Rgb(0x000000), ffw::GuiStyle::Background::Type::SIMPLE),
				ffw::GuiStyle::Border(0, 0, ffw::Rgb(0x000000)),
				ffw::GuiStyle::Outline(0, 0, ffw::Rgb(0x000000)),
				ffw::GuiStyle::Text(ffw::Rgb(0xFFFFFF)),
				ffw::GuiStyle::Function(ffw::Rgb(0xFFFFFF))
			),
			ffw::GuiDefaults(
				ffw::GuiStyle::Margin(0, 0, 0, 0),
				ffw::GuiStyle::Padding(0),
				ffw::GuiStyle::Align::TOP_LEFT,
				ffw::Vec2<GuiUnits>(ffw::GuiPercent(100), ffw::GuiWrap())
			)
		)
	},
	// GUI LABEL
	{
		"GUI_LABEL",
		ffw::GuiStyleGroup(
			// Normal
			ffw::GuiStyle(
				ffw::GuiStyle::Background(0, ffw::Rgb(0x000000), ffw::Rgb(0x000000), ffw::GuiStyle::Background::Type::NONE),
				ffw::GuiStyle::Border(0, 0, ffw::Rgb(0x000000)),
				ffw::GuiStyle::Outline(0, 0, ffw::Rgb(0x000000)),
				ffw::GuiStyle::Text(ffw::Rgb(0x222222)),
				ffw::GuiStyle::Function(ffw::Rgb(0xFFFFFF))
			),
			// Hover
			ffw::GuiStyle(
				ffw::GuiStyle::Background(0, ffw::Rgb(0x000000), ffw::Rgb(0x000000), ffw::GuiStyle::Background::Type::NONE),
				ffw::GuiStyle::Border(0, 0, ffw::Rgb(0x000000)),
				ffw::GuiStyle::Outline(0, 0, ffw::Rgb(0x000000)),
				ffw::GuiStyle::Text(ffw::Rgb(0x222222)),
				ffw::GuiStyle::Function(ffw::Rgb(0xFFFFFF))
			),
			// Active
			ffw::GuiStyle(
				ffw::GuiStyle::Background(0, ffw::Rgb(0x000000), ffw::Rgb(0x000000), ffw::GuiStyle::Background::Type::NONE),
				ffw::GuiStyle::Border(0, 0, ffw::Rgb(0x000000)),
				ffw::GuiStyle::Outline(0, 0, ffw::Rgb(0x000000)),
				ffw::GuiStyle::Text(ffw::Rgb(0x222222)),
				ffw::GuiStyle::Function(ffw::Rgb(0xFFFFFF))
			),
			// Disabled
			ffw::GuiStyle(
				ffw::GuiStyle::Background(0, ffw::Rgb(0x000000), ffw::Rgb(0x000000), ffw::GuiStyle::Background::Type::NONE),
				ffw::GuiStyle::Border(0, 0, ffw::Rgb(0x000000)),
				ffw::GuiStyle::Outline(0, 0, ffw::Rgb(0x000000)),
				ffw::GuiStyle::Text(ffw::Rgb(0xADADAD)),
				ffw::GuiStyle::Function(ffw::Rgb(0xFFFFFF))
			),
			ffw::GuiDefaults(
				ffw::GuiStyle::Margin(0, 0, 5, 0),
				ffw::GuiStyle::Padding(0, 0, 5, 0),
				ffw::GuiStyle::Align::TOP_LEFT,
				ffw::Vec2<GuiUnits>(ffw::GuiPercent(100), ffw::GuiWrap())
			)
		)
	},
	// GUI BUTTON
	{
		"GUI_BUTTON",
		ffw::GuiStyleGroup(
			// Normal
			ffw::GuiStyle(
				ffw::GuiStyle::Background(0, ffw::Rgb(0xE1E1E1), ffw::Rgb(0x000000), ffw::GuiStyle::Background::Type::SIMPLE),
				ffw::GuiStyle::Border(1, 0, ffw::Rgb(0xADADAD)),
				ffw::GuiStyle::Outline(0, 0, ffw::Rgb(0x000000)),
				ffw::GuiStyle::Text(ffw::Rgb(0x222222)),
				ffw::GuiStyle::Function(ffw::Rgb(0xFFFFFF))
			),
			// Hover
			ffw::GuiStyle(
				ffw::GuiStyle::Background(0, ffw::Rgb(0xE5F1FB), ffw::Rgb(0x000000), ffw::GuiStyle::Background::Type::SIMPLE),
				ffw::GuiStyle::Border(1, 0, ffw::Rgb(0x0078D7)),
				ffw::GuiStyle::Outline(0, 0, ffw::Rgb(0x000000)),
				ffw::GuiStyle::Text(ffw::Rgb(0x222222)),
				ffw::GuiStyle::Function(ffw::Rgb(0xFFFFFF))
			),
			// Active
			ffw::GuiStyle(
				ffw::GuiStyle::Background(0, ffw::Rgb(0xCCE4F7), ffw::Rgb(0x000000), ffw::GuiStyle::Background::Type::SIMPLE),
				ffw::GuiStyle::Border(1, 0, ffw::Rgb(0x005499)),
				ffw::GuiStyle::Outline(0, 0, ffw::Rgb(0x000000)),
				ffw::GuiStyle::Text(ffw::Rgb(0x222222)),
				ffw::GuiStyle::Function(ffw::Rgb(0xFFFFFF))
			),
			// Disabled
			ffw::GuiStyle(
				ffw::GuiStyle::Background(0, ffw::Rgb(0xCACACA), ffw::Rgb(0x000000), ffw::GuiStyle::Background::Type::SIMPLE),
				ffw::GuiStyle::Border(1, 0, ffw::Rgb(0xBEBEBE)),
				ffw::GuiStyle::Outline(0, 0, ffw::Rgb(0x000000)),
				ffw::GuiStyle::Text(ffw::Rgb(0x828282)),
				ffw::GuiStyle::Function(ffw::Rgb(0xFFFFFF))
			),
			ffw::GuiDefaults(
				ffw::GuiStyle::Margin(0, 0, 5, 0),
				ffw::GuiStyle::Padding(5),
				ffw::GuiStyle::Align::CENTER,
				ffw::Vec2<GuiUnits>(ffw::GuiPercent(100), ffw::GuiWrap())
			)
		)
	},
	// GUI CHECKBOX
	{
		"GUI_CHECKBOX",
		ffw::GuiStyleGroup(
			// Normal
			ffw::GuiStyle(
				ffw::GuiStyle::Background(0, ffw::Rgb(0x000000), ffw::Rgb(0x000000), ffw::GuiStyle::Background::Type::NONE),
				ffw::GuiStyle::Border(0, 0, ffw::Rgb(0x000000)),
				ffw::GuiStyle::Outline(0, 0, ffw::Rgb(0x000000)),
				ffw::GuiStyle::Text(ffw::Rgb(0x222222)),
				ffw::GuiStyle::Function(ffw::Rgb(0xFFFFFF))
			),
			// Hover
			ffw::GuiStyle(
				ffw::GuiStyle::Background(0, ffw::Rgb(0x000000), ffw::Rgb(0x000000), ffw::GuiStyle::Background::Type::NONE),
				ffw::GuiStyle::Border(0, 0, ffw::Rgb(0x000000)),
				ffw::GuiStyle::Outline(0, 0, ffw::Rgb(0x000000)),
				ffw::GuiStyle::Text(ffw::Rgb(0x222222)),
				ffw::GuiStyle::Function(ffw::Rgb(0xFFFFFF))
			),
			// Active
			ffw::GuiStyle(
				ffw::GuiStyle::Background(0, ffw::Rgb(0x000000), ffw::Rgb(0x000000), ffw::GuiStyle::Background::Type::NONE),
				ffw::GuiStyle::Border(0, 0, ffw::Rgb(0x000000)),
				ffw::GuiStyle::Outline(0, 0, ffw::Rgb(0x000000)),
				ffw::GuiStyle::Text(ffw::Rgb(0x222222)),
				ffw::GuiStyle::Function(ffw::Rgb(0xFFFFFF))
			),
			// Disabled
			ffw::GuiStyle(
				ffw::GuiStyle::Background(0, ffw::Rgb(0x000000), ffw::Rgb(0x000000), ffw::GuiStyle::Background::Type::NONE),
				ffw::GuiStyle::Border(0, 0, ffw::Rgb(0x000000)),
				ffw::GuiStyle::Outline(0, 0, ffw::Rgb(0x000000)),
				ffw::GuiStyle::Text(ffw::Rgb(0x828282)),
				ffw::GuiStyle::Function(ffw::Rgb(0xFFFFFF))
			),
			ffw::GuiDefaults(
				ffw::GuiStyle::Margin(0, 0, 5, 0),
				ffw::GuiStyle::Padding(0),
				ffw::GuiStyle::Align::TOP_LEFT,
				ffw::Vec2<GuiUnits>(ffw::GuiPercent(100), ffw::GuiWrap())
			)
		)
	},
	// GUI CHECKBOX BUTTON
	{
		"GUI_CHECKBOX_BUTTON",
		ffw::GuiStyleGroup(
			// Normal
			ffw::GuiStyle(
				ffw::GuiStyle::Background(0, ffw::Rgb(0xFFFFFF), ffw::Rgb(0x000000), ffw::GuiStyle::Background::Type::SIMPLE),
				ffw::GuiStyle::Border(1, 0, ffw::Rgb(0x222222)),
				ffw::GuiStyle::Outline(0, 0, ffw::Rgb(0x000000)),
				ffw::GuiStyle::Text(ffw::Rgb(0x000000)),
				ffw::GuiStyle::Function(ffw::Rgb(0xFFFFFF))
			),
			// Hover
			ffw::GuiStyle(
				ffw::GuiStyle::Background(0, ffw::Rgb(0xFFFFFF), ffw::Rgb(0x000000), ffw::GuiStyle::Background::Type::SIMPLE),
				ffw::GuiStyle::Border(1, 0, ffw::Rgb(0x222222)),
				ffw::GuiStyle::Outline(0, 0, ffw::Rgb(0x000000)),
				ffw::GuiStyle::Text(ffw::Rgb(0x000000)),
				ffw::GuiStyle::Function(ffw::Rgb(0x888888))
			),
			// Active
			ffw::GuiStyle(
				ffw::GuiStyle::Background(0, ffw::Rgb(0xFFFFFF), ffw::Rgb(0x000000), ffw::GuiStyle::Background::Type::SIMPLE),
				ffw::GuiStyle::Border(1, 0, ffw::Rgb(0x222222)),
				ffw::GuiStyle::Outline(0, 0, ffw::Rgb(0x000000)),
				ffw::GuiStyle::Text(ffw::Rgb(0x000000)),
				ffw::GuiStyle::Function(ffw::Rgb(0x222222))
			),
			// Disabled
			ffw::GuiStyle(
				ffw::GuiStyle::Background(0, ffw::Rgb(0xCACACA), ffw::Rgb(0x000000), ffw::GuiStyle::Background::Type::SIMPLE),
				ffw::GuiStyle::Border(1, 0, ffw::Rgb(0xBEBEBE)),
				ffw::GuiStyle::Outline(0, 0, ffw::Rgb(0x000000)),
				ffw::GuiStyle::Text(ffw::Rgb(0x000000)),
				ffw::GuiStyle::Function(ffw::Rgb(0xCACACA))
			),
			ffw::GuiDefaults(
				ffw::GuiStyle::Margin(0, 5, 0, 0),
				ffw::GuiStyle::Padding(GuiPercent(20)),
				ffw::GuiStyle::Align::CENTER,
				ffw::Vec2<GuiUnits>(ffw::GuiPixels(16), ffw::GuiPixels(16))
			)
		)
	},
	// GUI RADIO
	{
		"GUI_RADIO",
		ffw::GuiStyleGroup(
			// Normal
			ffw::GuiStyle(
				ffw::GuiStyle::Background(0, ffw::Rgb(0x000000), ffw::Rgb(0x000000), ffw::GuiStyle::Background::Type::NONE),
				ffw::GuiStyle::Border(0, 0, ffw::Rgb(0x000000)),
				ffw::GuiStyle::Outline(0, 0, ffw::Rgb(0x000000)),
				ffw::GuiStyle::Text(ffw::Rgb(0x222222)),
				ffw::GuiStyle::Function(ffw::Rgb(0xFFFFFF))
			),
			// Hover
			ffw::GuiStyle(
				ffw::GuiStyle::Background(0, ffw::Rgb(0x000000), ffw::Rgb(0x000000), ffw::GuiStyle::Background::Type::NONE),
				ffw::GuiStyle::Border(0, 0, ffw::Rgb(0x000000)),
				ffw::GuiStyle::Outline(0, 0, ffw::Rgb(0x000000)),
				ffw::GuiStyle::Text(ffw::Rgb(0x222222)),
				ffw::GuiStyle::Function(ffw::Rgb(0xFFFFFF))
			),
			// Active
			ffw::GuiStyle(
				ffw::GuiStyle::Background(0, ffw::Rgb(0x000000), ffw::Rgb(0x000000), ffw::GuiStyle::Background::Type::NONE),
				ffw::GuiStyle::Border(0, 0, ffw::Rgb(0x000000)),
				ffw::GuiStyle::Outline(0, 0, ffw::Rgb(0x000000)),
				ffw::GuiStyle::Text(ffw::Rgb(0x222222)),
				ffw::GuiStyle::Function(ffw::Rgb(0xFFFFFF))
			),
			// Disabled
			ffw::GuiStyle(
				ffw::GuiStyle::Background(0, ffw::Rgb(0x000000), ffw::Rgb(0x000000), ffw::GuiStyle::Background::Type::NONE),
				ffw::GuiStyle::Border(0, 0, ffw::Rgb(0x000000)),
				ffw::GuiStyle::Outline(0, 0, ffw::Rgb(0x000000)),
				ffw::GuiStyle::Text(ffw::Rgb(0x828282)),
				ffw::GuiStyle::Function(ffw::Rgb(0xFFFFFF))
			),
			ffw::GuiDefaults(
				ffw::GuiStyle::Margin(0, 0, 5, 0),
				ffw::GuiStyle::Padding(0),
				ffw::GuiStyle::Align::TOP_LEFT,
				ffw::Vec2<GuiUnits>(ffw::GuiPercent(100), ffw::GuiWrap())
			)
		)
	},
	// GUI RADIO BUTTON
	{
		"GUI_RADIO_BUTTON",
		ffw::GuiStyleGroup(
			// Normal
			ffw::GuiStyle(
				ffw::GuiStyle::Background(8, ffw::Rgb(0xFFFFFF), ffw::Rgb(0x000000), ffw::GuiStyle::Background::Type::SIMPLE),
				ffw::GuiStyle::Border(1, 8, ffw::Rgb(0x222222)),
				ffw::GuiStyle::Outline(0, 0, ffw::Rgb(0x000000)),
				ffw::GuiStyle::Text(ffw::Rgb(0x000000)),
				ffw::GuiStyle::Function(ffw::Rgb(0xFFFFFF))
			),
			// Hover
			ffw::GuiStyle(
				ffw::GuiStyle::Background(8, ffw::Rgb(0xFFFFFF), ffw::Rgb(0x000000), ffw::GuiStyle::Background::Type::SIMPLE),
				ffw::GuiStyle::Border(1, 8, ffw::Rgb(0x222222)),
				ffw::GuiStyle::Outline(0, 0, ffw::Rgb(0x000000)),
				ffw::GuiStyle::Text(ffw::Rgb(0x000000)),
				ffw::GuiStyle::Function(ffw::Rgb(0x888888))
			),
			// Active
			ffw::GuiStyle(
				ffw::GuiStyle::Background(8, ffw::Rgb(0xFFFFFF), ffw::Rgb(0x000000), ffw::GuiStyle::Background::Type::SIMPLE),
				ffw::GuiStyle::Border(1, 8, ffw::Rgb(0x222222)),
				ffw::GuiStyle::Outline(0, 0, ffw::Rgb(0x000000)),
				ffw::GuiStyle::Text(ffw::Rgb(0x000000)),
				ffw::GuiStyle::Function(ffw::Rgb(0x222222))
			),
			// Disabled
			ffw::GuiStyle(
				ffw::GuiStyle::Background(8, ffw::Rgb(0xCACACA), ffw::Rgb(0x000000), ffw::GuiStyle::Background::Type::SIMPLE),
				ffw::GuiStyle::Border(1, 8, ffw::Rgb(0xBEBEBE)),
				ffw::GuiStyle::Outline(0, 0, ffw::Rgb(0x000000)),
				ffw::GuiStyle::Text(ffw::Rgb(0x000000)),
				ffw::GuiStyle::Function(ffw::Rgb(0xCACACA))
			),
			ffw::GuiDefaults(
				ffw::GuiStyle::Margin(0, 5, 0, 0),
				ffw::GuiStyle::Padding(GuiPercent(20)),
				ffw::GuiStyle::Align::CENTER,
				ffw::Vec2<GuiUnits>(ffw::GuiPixels(16), ffw::GuiPixels(16))
			)
		)
	},
	// GUI SLIDER
	{
		"GUI_SLIDER",
		ffw::GuiStyleGroup(
			// Normal
			ffw::GuiStyle(
				ffw::GuiStyle::Background(0, ffw::Rgb(0x000000), ffw::Rgb(0x000000), ffw::GuiStyle::Background::Type::NONE),
				ffw::GuiStyle::Border(0, 0, ffw::Rgb(0x000000)),
				ffw::GuiStyle::Outline(0, 0, ffw::Rgb(0x000000)),
				ffw::GuiStyle::Text(ffw::Rgb(0xFFFFFF)),
				ffw::GuiStyle::Function(ffw::Rgb(0xFFFFFF))
			),
			// Hover
			ffw::GuiStyle(
				ffw::GuiStyle::Background(0, ffw::Rgb(0x000000), ffw::Rgb(0x000000), ffw::GuiStyle::Background::Type::NONE),
				ffw::GuiStyle::Border(0, 0, ffw::Rgb(0x000000)),
				ffw::GuiStyle::Outline(0, 0, ffw::Rgb(0x000000)),
				ffw::GuiStyle::Text(ffw::Rgb(0xFFFFFF)),
				ffw::GuiStyle::Function(ffw::Rgb(0xFFFFFF))
			),
			// Active
			ffw::GuiStyle(
				ffw::GuiStyle::Background(0, ffw::Rgb(0x000000), ffw::Rgb(0x000000), ffw::GuiStyle::Background::Type::NONE),
				ffw::GuiStyle::Border(0, 0, ffw::Rgb(0x000000)),
				ffw::GuiStyle::Outline(0, 0, ffw::Rgb(0x000000)),
				ffw::GuiStyle::Text(ffw::Rgb(0xFFFFFF)),
				ffw::GuiStyle::Function(ffw::Rgb(0xFFFFFF))
			),
			// Disabled
			ffw::GuiStyle(
				ffw::GuiStyle::Background(0, ffw::Rgb(0x000000), ffw::Rgb(0x000000), ffw::GuiStyle::Background::Type::NONE),
				ffw::GuiStyle::Border(0, 0, ffw::Rgb(0x000000)),
				ffw::GuiStyle::Outline(0, 0, ffw::Rgb(0x000000)),
				ffw::GuiStyle::Text(ffw::Rgb(0xFFFFFF)),
				ffw::GuiStyle::Function(ffw::Rgb(0xFFFFFF))
			),
			ffw::GuiDefaults(
				ffw::GuiStyle::Margin(0, 0, 0, 0),
				ffw::GuiStyle::Padding(0),
				ffw::GuiStyle::Align::TOP_LEFT,
				ffw::Vec2<GuiUnits>(ffw::GuiPercent(100), ffw::GuiWrap())
			)
		)
	},
	// GUI SLIDER
	{
		"GUI_SLIDER_BAR",
		ffw::GuiStyleGroup(
			// Normal
			ffw::GuiStyle(
				ffw::GuiStyle::Background(0, ffw::Rgb(0xE7EAEA), ffw::Rgb(0x000000), ffw::GuiStyle::Background::Type::SIMPLE),
				ffw::GuiStyle::Border(1, 0, ffw::Rgb(0xD6D6D6)),
				ffw::GuiStyle::Outline(0, 0, ffw::Rgb(0x000000)),
				ffw::GuiStyle::Text(ffw::Rgb(0xFFFFFF)),
				ffw::GuiStyle::Function(ffw::Rgb(0x007AD9))
			),
			// Hover
			ffw::GuiStyle(
				ffw::GuiStyle::Background(0, ffw::Rgb(0xE7EAEA), ffw::Rgb(0x000000), ffw::GuiStyle::Background::Type::SIMPLE),
				ffw::GuiStyle::Border(1, 0, ffw::Rgb(0xD6D6D6)),
				ffw::GuiStyle::Outline(0, 0, ffw::Rgb(0x000000)),
				ffw::GuiStyle::Text(ffw::Rgb(0xFFFFFF)),
				ffw::GuiStyle::Function(ffw::Rgb(0x007AD9))
			),
			// Active
			ffw::GuiStyle(
				ffw::GuiStyle::Background(0, ffw::Rgb(0xE7EAEA), ffw::Rgb(0x000000), ffw::GuiStyle::Background::Type::SIMPLE),
				ffw::GuiStyle::Border(1, 0, ffw::Rgb(0xD6D6D6)),
				ffw::GuiStyle::Outline(0, 0, ffw::Rgb(0x000000)),
				ffw::GuiStyle::Text(ffw::Rgb(0xFFFFFF)),
				ffw::GuiStyle::Function(ffw::Rgb(0x007AD9))
			),
			// Disabled
			ffw::GuiStyle(
				ffw::GuiStyle::Background(0, ffw::Rgb(0xE7EAEA), ffw::Rgb(0x000000), ffw::GuiStyle::Background::Type::SIMPLE),
				ffw::GuiStyle::Border(1, 0, ffw::Rgb(0xD6D6D6)),
				ffw::GuiStyle::Outline(0, 0, ffw::Rgb(0x000000)),
				ffw::GuiStyle::Text(ffw::Rgb(0xFFFFFF)),
				ffw::GuiStyle::Function(ffw::Rgb(0xB3B3B3))
			),
			ffw::GuiDefaults(
				ffw::GuiStyle::Margin(0, 0, 0, 0),
				ffw::GuiStyle::Padding(0),
				ffw::GuiStyle::Align::TOP_LEFT,
				ffw::Vec2<GuiUnits>(ffw::GuiPercent(100), ffw::GuiPixels(4))
			)
		)
	},
	// GUI SLIDER BUTTON
	{
		"GUI_SLIDER_BUTTON",
		ffw::GuiStyleGroup(
			// Normal
			ffw::GuiStyle(
				ffw::GuiStyle::Background(0, ffw::Rgb(0xE1E1E1), ffw::Rgb(0x000000), ffw::GuiStyle::Background::Type::SIMPLE),
				ffw::GuiStyle::Border(1, 0, ffw::Rgb(0xADADAD)),
				ffw::GuiStyle::Outline(0, 0, ffw::Rgb(0x000000)),
				ffw::GuiStyle::Text(ffw::Rgb(0x222222)),
				ffw::GuiStyle::Function(ffw::Rgb(0xFFFFFF))
			),
			// Hover
			ffw::GuiStyle(
				ffw::GuiStyle::Background(0, ffw::Rgb(0xE5F1FB), ffw::Rgb(0x000000), ffw::GuiStyle::Background::Type::SIMPLE),
				ffw::GuiStyle::Border(1, 0, ffw::Rgb(0x0078D7)),
				ffw::GuiStyle::Outline(0, 0, ffw::Rgb(0x000000)),
				ffw::GuiStyle::Text(ffw::Rgb(0x222222)),
				ffw::GuiStyle::Function(ffw::Rgb(0xFFFFFF))
			),
			// Active
			ffw::GuiStyle(
				ffw::GuiStyle::Background(0, ffw::Rgb(0xCCE4F7), ffw::Rgb(0x000000), ffw::GuiStyle::Background::Type::SIMPLE),
				ffw::GuiStyle::Border(1, 0, ffw::Rgb(0x005499)),
				ffw::GuiStyle::Outline(0, 0, ffw::Rgb(0x000000)),
				ffw::GuiStyle::Text(ffw::Rgb(0x222222)),
				ffw::GuiStyle::Function(ffw::Rgb(0xFFFFFF))
			),
			// Disabled
			ffw::GuiStyle(
				ffw::GuiStyle::Background(0, ffw::Rgb(0xCACACA), ffw::Rgb(0x000000), ffw::GuiStyle::Background::Type::SIMPLE),
				ffw::GuiStyle::Border(1, 0, ffw::Rgb(0xBEBEBE)),
				ffw::GuiStyle::Outline(0, 0, ffw::Rgb(0x000000)),
				ffw::GuiStyle::Text(ffw::Rgb(0x828282)),
				ffw::GuiStyle::Function(ffw::Rgb(0xFFFFFF))
			),
			ffw::GuiDefaults(
				ffw::GuiStyle::Margin(0, 0, 0, 0),
				ffw::GuiStyle::Padding(0),
				ffw::GuiStyle::Align::TOP_LEFT,
				ffw::Vec2<GuiUnits>(ffw::GuiPixels(8), ffw::GuiPixels(16))
			)
		)
	},
	{
		"GUI_SCROLLBAR",
		ffw::GuiStyleGroup(
			// Normal
			ffw::GuiStyle(
				ffw::GuiStyle::Background(0, ffw::Rgb(0xEFEFEF), ffw::Rgb(0x000000), ffw::GuiStyle::Background::Type::SIMPLE),
				ffw::GuiStyle::Border(0, 0, ffw::Rgb(0x000000)),
				ffw::GuiStyle::Outline(0, 0, ffw::Rgb(0x000000)),
				ffw::GuiStyle::Text(ffw::Rgb(0xFFFFFF)),
				ffw::GuiStyle::Function(ffw::Rgb(0xFFFFFF))
			),
			// Hover
			ffw::GuiStyle(
				ffw::GuiStyle::Background(0, ffw::Rgb(0xEFEFEF), ffw::Rgb(0x000000), ffw::GuiStyle::Background::Type::SIMPLE),
				ffw::GuiStyle::Border(0, 0, ffw::Rgb(0x000000)),
				ffw::GuiStyle::Outline(0, 0, ffw::Rgb(0x000000)),
				ffw::GuiStyle::Text(ffw::Rgb(0xFFFFFF)),
				ffw::GuiStyle::Function(ffw::Rgb(0xFFFFFF))
			),
			// Active
			ffw::GuiStyle(
				ffw::GuiStyle::Background(0, ffw::Rgb(0xEFEFEF), ffw::Rgb(0x000000), ffw::GuiStyle::Background::Type::SIMPLE),
				ffw::GuiStyle::Border(0, 0, ffw::Rgb(0x000000)),
				ffw::GuiStyle::Outline(0, 0, ffw::Rgb(0x000000)),
				ffw::GuiStyle::Text(ffw::Rgb(0xFFFFFF)),
				ffw::GuiStyle::Function(ffw::Rgb(0xFFFFFF))
			),
			// Disabled
			ffw::GuiStyle(
				ffw::GuiStyle::Background(0, ffw::Rgb(0xEFEFEF), ffw::Rgb(0x000000), ffw::GuiStyle::Background::Type::SIMPLE),
				ffw::GuiStyle::Border(0, 0, ffw::Rgb(0x000000)),
				ffw::GuiStyle::Outline(0, 0, ffw::Rgb(0x000000)),
				ffw::GuiStyle::Text(ffw::Rgb(0xFFFFFF)),
				ffw::GuiStyle::Function(ffw::Rgb(0xFFFFFF))
			),
			ffw::GuiDefaults(
				ffw::GuiStyle::Margin(0, 0, 0, 0),
				ffw::GuiStyle::Padding(1),
				ffw::GuiStyle::Align::TOP_LEFT,
				ffw::Vec2<GuiUnits>(ffw::GuiPercent(100), ffw::GuiWrap())
			)
		)
	},
	{
		"GUI_SCROLLBAR_BUTTON_LEFT",
		ffw::GuiStyleGroup(
			// Normal
			ffw::GuiStyle(
				ffw::GuiStyle::Background(0, ffw::Rgb(0x000000), ffw::Rgb(0x000000), ffw::GuiStyle::Background::Type::NONE),
				ffw::GuiStyle::Border(0, 0, ffw::Rgb(0x000000)),
				ffw::GuiStyle::Outline(0, 0, ffw::Rgb(0x000000)),
				ffw::GuiStyle::Text(ffw::Rgb(0x616161)),
				ffw::GuiStyle::Function(ffw::Rgb(0xFFFFFF))
			),
			// Hover
			ffw::GuiStyle(
				ffw::GuiStyle::Background(0, ffw::Rgb(0xCECECE), ffw::Rgb(0x000000), ffw::GuiStyle::Background::Type::SIMPLE),
				ffw::GuiStyle::Border(0, 0, ffw::Rgb(0x000000)),
				ffw::GuiStyle::Outline(0, 0, ffw::Rgb(0x000000)),
				ffw::GuiStyle::Text(ffw::Rgb(0x616161)),
				ffw::GuiStyle::Function(ffw::Rgb(0xFFFFFF))
			),
			// Active
			ffw::GuiStyle(
				ffw::GuiStyle::Background(0, ffw::Rgb(0x616161), ffw::Rgb(0x000000), ffw::GuiStyle::Background::Type::SIMPLE),
				ffw::GuiStyle::Border(0, 0, ffw::Rgb(0x000000)),
				ffw::GuiStyle::Outline(0, 0, ffw::Rgb(0x000000)),
				ffw::GuiStyle::Text(ffw::Rgb(0xFFFFFF)),
				ffw::GuiStyle::Function(ffw::Rgb(0xFFFFFF))
			),
			// Disabled
			ffw::GuiStyle(
				ffw::GuiStyle::Background(0, ffw::Rgb(0x000000), ffw::Rgb(0x000000), ffw::GuiStyle::Background::Type::NONE),
				ffw::GuiStyle::Border(0, 0, ffw::Rgb(0x000000)),
				ffw::GuiStyle::Outline(0, 0, ffw::Rgb(0x000000)),
				ffw::GuiStyle::Text(ffw::Rgb(0xCECECE)),
				ffw::GuiStyle::Function(ffw::Rgb(0xFFFFFF))
			)
		)
	},
	{
		"GUI_SCROLLBAR_BUTTON_RIGHT",
		ffw::GuiStyleGroup(
			// Normal
			ffw::GuiStyle(
				ffw::GuiStyle::Background(0, ffw::Rgb(0x000000), ffw::Rgb(0x000000), ffw::GuiStyle::Background::Type::NONE),
				ffw::GuiStyle::Border(0, 0, ffw::Rgb(0x000000)),
				ffw::GuiStyle::Outline(0, 0, ffw::Rgb(0x000000)),
				ffw::GuiStyle::Text(ffw::Rgb(0x616161)),
				ffw::GuiStyle::Function(ffw::Rgb(0xFFFFFF))
			),
			// Hover
			ffw::GuiStyle(
				ffw::GuiStyle::Background(0, ffw::Rgb(0xCECECE), ffw::Rgb(0x000000), ffw::GuiStyle::Background::Type::SIMPLE),
				ffw::GuiStyle::Border(0, 0, ffw::Rgb(0x000000)),
				ffw::GuiStyle::Outline(0, 0, ffw::Rgb(0x000000)),
				ffw::GuiStyle::Text(ffw::Rgb(0x616161)),
				ffw::GuiStyle::Function(ffw::Rgb(0xFFFFFF))
			),
			// Active
			ffw::GuiStyle(
				ffw::GuiStyle::Background(0, ffw::Rgb(0x616161), ffw::Rgb(0x000000), ffw::GuiStyle::Background::Type::SIMPLE),
				ffw::GuiStyle::Border(0, 0, ffw::Rgb(0x000000)),
				ffw::GuiStyle::Outline(0, 0, ffw::Rgb(0x000000)),
				ffw::GuiStyle::Text(ffw::Rgb(0xFFFFFF)),
				ffw::GuiStyle::Function(ffw::Rgb(0xFFFFFF))
			),
			// Disabled
			ffw::GuiStyle(
				ffw::GuiStyle::Background(0, ffw::Rgb(0x000000), ffw::Rgb(0x000000), ffw::GuiStyle::Background::Type::NONE),
				ffw::GuiStyle::Border(0, 0, ffw::Rgb(0x000000)),
				ffw::GuiStyle::Outline(0, 0, ffw::Rgb(0x000000)),
				ffw::GuiStyle::Text(ffw::Rgb(0xCECECE)),
				ffw::GuiStyle::Function(ffw::Rgb(0xFFFFFF))
			)
		)
	},
	{
		"GUI_SCROLLBAR_SLIDER",
		ffw::GuiStyleGroup(
			// Normal
			ffw::GuiStyle(
				ffw::GuiStyle::Background(0, ffw::Rgb(0x000000), ffw::Rgb(0x000000), ffw::GuiStyle::Background::Type::NONE),
				ffw::GuiStyle::Border(0, 0, ffw::Rgb(0x000000)),
				ffw::GuiStyle::Outline(0, 0, ffw::Rgb(0x000000)),
				ffw::GuiStyle::Text(ffw::Rgb(0xFFFFFF)),
				ffw::GuiStyle::Function(ffw::Rgb(0xFFFFFF))
			),
			// Hover
			ffw::GuiStyle(
				ffw::GuiStyle::Background(0, ffw::Rgb(0x000000), ffw::Rgb(0x000000), ffw::GuiStyle::Background::Type::NONE),
				ffw::GuiStyle::Border(0, 0, ffw::Rgb(0x000000)),
				ffw::GuiStyle::Outline(0, 0, ffw::Rgb(0x000000)),
				ffw::GuiStyle::Text(ffw::Rgb(0xFFFFFF)),
				ffw::GuiStyle::Function(ffw::Rgb(0xFFFFFF))
			),
			// Active
			ffw::GuiStyle(
				ffw::GuiStyle::Background(0, ffw::Rgb(0x000000), ffw::Rgb(0x000000), ffw::GuiStyle::Background::Type::NONE),
				ffw::GuiStyle::Border(0, 0, ffw::Rgb(0x000000)),
				ffw::GuiStyle::Outline(0, 0, ffw::Rgb(0x000000)),
				ffw::GuiStyle::Text(ffw::Rgb(0xFFFFFF)),
				ffw::GuiStyle::Function(ffw::Rgb(0xFFFFFF))
			),
			// Disabled
			ffw::GuiStyle(
				ffw::GuiStyle::Background(0, ffw::Rgb(0x000000), ffw::Rgb(0x000000), ffw::GuiStyle::Background::Type::NONE),
				ffw::GuiStyle::Border(0, 0, ffw::Rgb(0x000000)),
				ffw::GuiStyle::Outline(0, 0, ffw::Rgb(0x000000)),
				ffw::GuiStyle::Text(ffw::Rgb(0xFFFFFF)),
				ffw::GuiStyle::Function(ffw::Rgb(0xFFFFFF))
			)
		)
	},
	{
		"GUI_SCROLLBAR_SLIDER_BAR",
		ffw::GuiStyleGroup(
			// Normal
			ffw::GuiStyle(
				ffw::GuiStyle::Background(0, ffw::Rgb(0x000000), ffw::Rgb(0x000000), ffw::GuiStyle::Background::Type::NONE),
				ffw::GuiStyle::Border(0, 0, ffw::Rgb(0x000000)),
				ffw::GuiStyle::Outline(0, 0, ffw::Rgb(0x000000)),
				ffw::GuiStyle::Text(ffw::Rgb(0xFFFFFF)),
				ffw::GuiStyle::Function(ffw::Rgba(0xFFFFFF00))
			),
			// Hover
			ffw::GuiStyle(
				ffw::GuiStyle::Background(0, ffw::Rgb(0x000000), ffw::Rgb(0x000000), ffw::GuiStyle::Background::Type::NONE),
				ffw::GuiStyle::Border(0, 0, ffw::Rgb(0x000000)),
				ffw::GuiStyle::Outline(0, 0, ffw::Rgb(0x000000)),
				ffw::GuiStyle::Text(ffw::Rgb(0xFFFFFF)),
				ffw::GuiStyle::Function(ffw::Rgba(0xFFFFFF00))
			),
			// Active
			ffw::GuiStyle(
				ffw::GuiStyle::Background(0, ffw::Rgb(0x000000), ffw::Rgb(0x000000), ffw::GuiStyle::Background::Type::NONE),
				ffw::GuiStyle::Border(0, 0, ffw::Rgb(0x000000)),
				ffw::GuiStyle::Outline(0, 0, ffw::Rgb(0x000000)),
				ffw::GuiStyle::Text(ffw::Rgb(0xFFFFFF)),
				ffw::GuiStyle::Function(ffw::Rgba(0xFFFFFF00))
			),
			// Disabled
			ffw::GuiStyle(
				ffw::GuiStyle::Background(0, ffw::Rgb(0x000000), ffw::Rgb(0x000000), ffw::GuiStyle::Background::Type::NONE),
				ffw::GuiStyle::Border(0, 0, ffw::Rgb(0x000000)),
				ffw::GuiStyle::Outline(0, 0, ffw::Rgb(0x000000)),
				ffw::GuiStyle::Text(ffw::Rgb(0xFFFFFF)),
				ffw::GuiStyle::Function(ffw::Rgba(0xFFFFFF00))
			)
		)
	},
	{
		"GUI_SCROLLBAR_SLIDER_BUTTON",
		ffw::GuiStyleGroup(
			// Normal
			ffw::GuiStyle(
				ffw::GuiStyle::Background(0, ffw::Rgb(0xCECECE), ffw::Rgb(0x000000), ffw::GuiStyle::Background::Type::SIMPLE),
				ffw::GuiStyle::Border(0, 0, ffw::Rgb(0x000000)),
				ffw::GuiStyle::Outline(0, 0, ffw::Rgb(0x000000)),
				ffw::GuiStyle::Text(ffw::Rgb(0xFFFFFF)),
				ffw::GuiStyle::Function(ffw::Rgba(0xFFFFFF00))
			),
			// Hover
			ffw::GuiStyle(
				ffw::GuiStyle::Background(0, ffw::Rgb(0xA6A6A6), ffw::Rgb(0x000000), ffw::GuiStyle::Background::Type::SIMPLE),
				ffw::GuiStyle::Border(0, 0, ffw::Rgb(0x000000)),
				ffw::GuiStyle::Outline(0, 0, ffw::Rgb(0x000000)),
				ffw::GuiStyle::Text(ffw::Rgb(0xFFFFFF)),
				ffw::GuiStyle::Function(ffw::Rgba(0xFFFFFF00))
			),
			// Active
			ffw::GuiStyle(
				ffw::GuiStyle::Background(0, ffw::Rgb(0x616161), ffw::Rgb(0x000000), ffw::GuiStyle::Background::Type::SIMPLE),
				ffw::GuiStyle::Border(0, 0, ffw::Rgb(0x000000)),
				ffw::GuiStyle::Outline(0, 0, ffw::Rgb(0x000000)),
				ffw::GuiStyle::Text(ffw::Rgb(0xFFFFFF)),
				ffw::GuiStyle::Function(ffw::Rgba(0xFFFFFF00))
			),
			// Disabled
			ffw::GuiStyle(
				ffw::GuiStyle::Background(0, ffw::Rgb(0x000000), ffw::Rgb(0x000000), ffw::GuiStyle::Background::Type::NONE),
				ffw::GuiStyle::Border(0, 0, ffw::Rgb(0x000000)),
				ffw::GuiStyle::Outline(0, 0, ffw::Rgb(0x000000)),
				ffw::GuiStyle::Text(ffw::Rgb(0xFFFFFF)),
				ffw::GuiStyle::Function(ffw::Rgba(0xFFFFFF00))
			)
		)
	},
	{
		"GUI_SCROLLABLE",
		ffw::GuiStyleGroup(
			// Normal
			ffw::GuiStyle(
				ffw::GuiStyle::Background(0, ffw::Rgb(0x000000), ffw::Rgb(0x000000), ffw::GuiStyle::Background::Type::NONE),
				ffw::GuiStyle::Border(1, 0, ffw::Rgb(0xADADAD)),
				ffw::GuiStyle::Outline(0, 0, ffw::Rgb(0x000000)),
				ffw::GuiStyle::Text(ffw::Rgb(0xFFFFFF)),
				ffw::GuiStyle::Function(ffw::Rgb(0xFFFFFF))
			),
			// Hover
			ffw::GuiStyle(
				ffw::GuiStyle::Background(0, ffw::Rgb(0x000000), ffw::Rgb(0x000000), ffw::GuiStyle::Background::Type::NONE),
				ffw::GuiStyle::Border(1, 0, ffw::Rgb(0xADADAD)),
				ffw::GuiStyle::Outline(0, 0, ffw::Rgb(0x000000)),
				ffw::GuiStyle::Text(ffw::Rgb(0xFFFFFF)),
				ffw::GuiStyle::Function(ffw::Rgb(0xFFFFFF))
			),
			// Active
			ffw::GuiStyle(
				ffw::GuiStyle::Background(0, ffw::Rgb(0x000000), ffw::Rgb(0x000000), ffw::GuiStyle::Background::Type::NONE),
				ffw::GuiStyle::Border(1, 0, ffw::Rgb(0xADADAD)),
				ffw::GuiStyle::Outline(0, 0, ffw::Rgb(0x000000)),
				ffw::GuiStyle::Text(ffw::Rgb(0xFFFFFF)),
				ffw::GuiStyle::Function(ffw::Rgb(0xFFFFFF))
			),
			// Disabled
			ffw::GuiStyle(
				ffw::GuiStyle::Background(0, ffw::Rgb(0x000000), ffw::Rgb(0x000000), ffw::GuiStyle::Background::Type::NONE),
				ffw::GuiStyle::Border(1, 0, ffw::Rgb(0xADADAD)),
				ffw::GuiStyle::Outline(0, 0, ffw::Rgb(0x000000)),
				ffw::GuiStyle::Text(ffw::Rgb(0xFFFFFF)),
				ffw::GuiStyle::Function(ffw::Rgb(0xFFFFFF))
			)
		)
	},
});