/*** This file is part of FineFramework project ***/

#include "ffw/gui/guitheme.h"

///=============================================================================
const ffw::GuiTheme ffw::GuiTheme::windows({
	// GUI LAYOUT
	{
		"GUI_LAYOUT",
		ffw::GuiStyleGroup(
			// Normal
			ffw::GuiStyle(
				ffw::GuiStyle::Background(0, ffw::rgb(0x000000), ffw::GuiStyle::Background::Type::NONE),
				ffw::GuiStyle::Border(0, 0, ffw::rgb(0x000000)),
				ffw::GuiStyle::Outline(0, 0, ffw::rgb(0x000000)),
				ffw::GuiStyle::Text(ffw::rgb(0xFFFFFF)),
				ffw::GuiStyle::Function(ffw::rgb(0xFFFFFF))
			),
			// Hover
			ffw::GuiStyle(
				ffw::GuiStyle::Background(0, ffw::rgb(0x000000), ffw::GuiStyle::Background::Type::NONE),
				ffw::GuiStyle::Border(0, 0, ffw::rgb(0x000000)),
				ffw::GuiStyle::Outline(0, 0, ffw::rgb(0x000000)),
				ffw::GuiStyle::Text(ffw::rgb(0xFFFFFF)),
				ffw::GuiStyle::Function(ffw::rgb(0xFFFFFF))
			),
			// Active
			ffw::GuiStyle(
				ffw::GuiStyle::Background(0, ffw::rgb(0x000000), ffw::GuiStyle::Background::Type::NONE),
				ffw::GuiStyle::Border(0, 0, ffw::rgb(0x000000)),
				ffw::GuiStyle::Outline(0, 0, ffw::rgb(0x000000)),
				ffw::GuiStyle::Text(ffw::rgb(0xFFFFFF)),
				ffw::GuiStyle::Function(ffw::rgb(0xFFFFFF))
			),
			// Disabled
			ffw::GuiStyle(
				ffw::GuiStyle::Background(0, ffw::rgb(0x000000), ffw::GuiStyle::Background::Type::NONE),
				ffw::GuiStyle::Border(0, 0, ffw::rgb(0x000000)),
				ffw::GuiStyle::Outline(0, 0, ffw::rgb(0x000000)),
				ffw::GuiStyle::Text(ffw::rgb(0xFFFFFF)),
				ffw::GuiStyle::Function(ffw::rgb(0xFFFFFF))
			),
			ffw::GuiDefaults(
				ffw::GuiStyle::Margin(0, 0, 0, 0),
				ffw::GuiStyle::Padding(0),
				ffw::GuiStyle::Align::TOP_LEFT,
				ffw::Vec2<GuiUnits>(ffw::guiPercent(100), ffw::guiWrap())
			)
		)
	},
	// GUI WINDOW BODY
	{
		"GUI_WINDOW_BODY",
		ffw::GuiStyleGroup(
			// Normal
			ffw::GuiStyle(
				ffw::GuiStyle::Background(0, ffw::rgb(0xF0F0F0), ffw::GuiStyle::Background::Type::SIMPLE),
				ffw::GuiStyle::Border(0, 0, ffw::rgb(0x000000)),
				ffw::GuiStyle::Outline(0, 0, ffw::rgb(0x000000)),
				ffw::GuiStyle::Text(ffw::rgb(0xFFFFFF)),
				ffw::GuiStyle::Function(ffw::rgb(0xFFFFFF))
			),
			// Hover
			ffw::GuiStyle(
				ffw::GuiStyle::Background(0, ffw::rgb(0xF0F0F0), ffw::GuiStyle::Background::Type::SIMPLE),
				ffw::GuiStyle::Border(0, 0, ffw::rgb(0x000000)),
				ffw::GuiStyle::Outline(0, 0, ffw::rgb(0x000000)),
				ffw::GuiStyle::Text(ffw::rgb(0xFFFFFF)),
				ffw::GuiStyle::Function(ffw::rgb(0xFFFFFF))
			),
			// Active
			ffw::GuiStyle(
				ffw::GuiStyle::Background(0, ffw::rgb(0xF0F0F0), ffw::GuiStyle::Background::Type::SIMPLE),
				ffw::GuiStyle::Border(0, 0, ffw::rgb(0x000000)),
				ffw::GuiStyle::Outline(0, 0, ffw::rgb(0x000000)),
				ffw::GuiStyle::Text(ffw::rgb(0xFFFFFF)),
				ffw::GuiStyle::Function(ffw::rgb(0xFFFFFF))
			),
			// Disabled
			ffw::GuiStyle(
				ffw::GuiStyle::Background(0, ffw::rgb(0xF0F0F0), ffw::GuiStyle::Background::Type::SIMPLE),
				ffw::GuiStyle::Border(0, 0, ffw::rgb(0x000000)),
				ffw::GuiStyle::Outline(0, 0, ffw::rgb(0x000000)),
				ffw::GuiStyle::Text(ffw::rgb(0xFFFFFF)),
				ffw::GuiStyle::Function(ffw::rgb(0xFFFFFF))
			),
			ffw::GuiDefaults(
				ffw::GuiStyle::Margin(0, 0, 0, 0),
				ffw::GuiStyle::Padding(0),
				ffw::GuiStyle::Align::TOP_LEFT,
				ffw::Vec2<GuiUnits>(ffw::guiPercent(100), ffw::guiPercent(100))
			)
		)
	},
	// GUI LABEL
	{
		"GUI_LABEL",
		ffw::GuiStyleGroup(
			// Normal
			ffw::GuiStyle(
				ffw::GuiStyle::Background(0, ffw::rgb(0x000000), ffw::GuiStyle::Background::Type::NONE),
				ffw::GuiStyle::Border(0, 0, ffw::rgb(0x000000)),
				ffw::GuiStyle::Outline(0, 0, ffw::rgb(0x000000)),
				ffw::GuiStyle::Text(ffw::rgb(0x222222)),
				ffw::GuiStyle::Function(ffw::rgb(0xFFFFFF))
			),
			// Hover
			ffw::GuiStyle(
				ffw::GuiStyle::Background(0, ffw::rgb(0x000000), ffw::GuiStyle::Background::Type::NONE),
				ffw::GuiStyle::Border(0, 0, ffw::rgb(0x000000)),
				ffw::GuiStyle::Outline(0, 0, ffw::rgb(0x000000)),
				ffw::GuiStyle::Text(ffw::rgb(0x222222)),
				ffw::GuiStyle::Function(ffw::rgb(0xFFFFFF))
			),
			// Active
			ffw::GuiStyle(
				ffw::GuiStyle::Background(0, ffw::rgb(0x000000), ffw::GuiStyle::Background::Type::NONE),
				ffw::GuiStyle::Border(0, 0, ffw::rgb(0x000000)),
				ffw::GuiStyle::Outline(0, 0, ffw::rgb(0x000000)),
				ffw::GuiStyle::Text(ffw::rgb(0x222222)),
				ffw::GuiStyle::Function(ffw::rgb(0xFFFFFF))
			),
			// Disabled
			ffw::GuiStyle(
				ffw::GuiStyle::Background(0, ffw::rgb(0x000000), ffw::GuiStyle::Background::Type::NONE),
				ffw::GuiStyle::Border(0, 0, ffw::rgb(0x000000)),
				ffw::GuiStyle::Outline(0, 0, ffw::rgb(0x000000)),
				ffw::GuiStyle::Text(ffw::rgb(0xADADAD)),
				ffw::GuiStyle::Function(ffw::rgb(0xFFFFFF))
			),
			ffw::GuiDefaults(
				ffw::GuiStyle::Margin(0, 0, 2, 0),
				ffw::GuiStyle::Padding(0, 0, 0, 0),
				ffw::GuiStyle::Align::TOP_LEFT,
				ffw::Vec2<GuiUnits>(ffw::guiPercent(100), ffw::guiWrap())
			)
		)
	},
	// GUI BUTTON
	{
		"GUI_BUTTON",
		ffw::GuiStyleGroup(
			// Normal
			ffw::GuiStyle(
				ffw::GuiStyle::Background(0, ffw::rgb(0xE1E1E1), ffw::GuiStyle::Background::Type::SIMPLE),
				ffw::GuiStyle::Border(1, 0, ffw::rgb(0xADADAD)),
				ffw::GuiStyle::Outline(0, 0, ffw::rgb(0x000000)),
				ffw::GuiStyle::Text(ffw::rgb(0x222222)),
				ffw::GuiStyle::Function(ffw::rgb(0xFFFFFF))
			),
			// Hover
			ffw::GuiStyle(
				ffw::GuiStyle::Background(0, ffw::rgb(0xE5F1FB), ffw::GuiStyle::Background::Type::SIMPLE),
				ffw::GuiStyle::Border(1, 0, ffw::rgb(0x0078D7)),
				ffw::GuiStyle::Outline(0, 0, ffw::rgb(0x000000)),
				ffw::GuiStyle::Text(ffw::rgb(0x222222)),
				ffw::GuiStyle::Function(ffw::rgb(0xFFFFFF))
			),
			// Active
			ffw::GuiStyle(
				ffw::GuiStyle::Background(0, ffw::rgb(0xCCE4F7), ffw::GuiStyle::Background::Type::SIMPLE),
				ffw::GuiStyle::Border(1, 0, ffw::rgb(0x005499)),
				ffw::GuiStyle::Outline(0, 0, ffw::rgb(0x000000)),
				ffw::GuiStyle::Text(ffw::rgb(0x222222)),
				ffw::GuiStyle::Function(ffw::rgb(0xFFFFFF))
			),
			// Disabled
			ffw::GuiStyle(
				ffw::GuiStyle::Background(0, ffw::rgb(0xCACACA), ffw::GuiStyle::Background::Type::SIMPLE),
				ffw::GuiStyle::Border(1, 0, ffw::rgb(0xBEBEBE)),
				ffw::GuiStyle::Outline(0, 0, ffw::rgb(0x000000)),
				ffw::GuiStyle::Text(ffw::rgb(0x828282)),
				ffw::GuiStyle::Function(ffw::rgb(0xFFFFFF))
			),
			ffw::GuiDefaults(
				ffw::GuiStyle::Margin(0, 0, 5, 0),
				ffw::GuiStyle::Padding(4),
				ffw::GuiStyle::Align::CENTER,
				ffw::Vec2<GuiUnits>(ffw::guiPercent(100), ffw::guiWrap())
			)
		)
	},
	{
		"GUI_BUTTON_PRIMARY",
		ffw::GuiStyleGroup(
			// Normal
			ffw::GuiStyle(
				ffw::GuiStyle::Background(0, ffw::rgb(0x3397FE), ffw::GuiStyle::Background::Type::SIMPLE),
				ffw::GuiStyle::Border(1, 0, ffw::rgb(0xADADAD)),
				ffw::GuiStyle::Outline(0, 0, ffw::rgb(0x000000)),
				ffw::GuiStyle::Text(ffw::rgb(0xFFFFFF)),
				ffw::GuiStyle::Function(ffw::rgb(0xFFFFFF))
			),
			// Hover
			ffw::GuiStyle(
				ffw::GuiStyle::Background(0, ffw::rgb(0x2C84DC), ffw::GuiStyle::Background::Type::SIMPLE),
				ffw::GuiStyle::Border(1, 0, ffw::rgb(0x0078D7)),
				ffw::GuiStyle::Outline(0, 0, ffw::rgb(0x000000)),
				ffw::GuiStyle::Text(ffw::rgb(0xFFFFFF)),
				ffw::GuiStyle::Function(ffw::rgb(0xFFFFFF))
			),
			// Active
			ffw::GuiStyle(
				ffw::GuiStyle::Background(0, ffw::rgb(0x1E5994), ffw::GuiStyle::Background::Type::SIMPLE),
				ffw::GuiStyle::Border(1, 0, ffw::rgb(0x005499)),
				ffw::GuiStyle::Outline(0, 0, ffw::rgb(0x000000)),
				ffw::GuiStyle::Text(ffw::rgb(0xFFFFFF)),
				ffw::GuiStyle::Function(ffw::rgb(0xFFFFFF))
			),
			// Disabled
			ffw::GuiStyle(
				ffw::GuiStyle::Background(0, ffw::rgb(0xCACACA), ffw::GuiStyle::Background::Type::SIMPLE),
				ffw::GuiStyle::Border(1, 0, ffw::rgb(0xBEBEBE)),
				ffw::GuiStyle::Outline(0, 0, ffw::rgb(0x000000)),
				ffw::GuiStyle::Text(ffw::rgb(0x828282)),
				ffw::GuiStyle::Function(ffw::rgb(0xFFFFFF))
			),
			ffw::GuiDefaults(
				ffw::GuiStyle::Margin(0, 0, 5, 0),
				ffw::GuiStyle::Padding(4),
				ffw::GuiStyle::Align::CENTER,
				ffw::Vec2<GuiUnits>(ffw::guiPercent(100), ffw::guiWrap())
			)
		)
	},
	// GUI CHECKBOX
	{
		"GUI_CHECKBOX",
		ffw::GuiStyleGroup(
			// Normal
			ffw::GuiStyle(
				ffw::GuiStyle::Background(0, ffw::rgb(0x000000), ffw::GuiStyle::Background::Type::NONE),
				ffw::GuiStyle::Border(0, 0, ffw::rgb(0x000000)),
				ffw::GuiStyle::Outline(0, 0, ffw::rgb(0x000000)),
				ffw::GuiStyle::Text(ffw::rgb(0x222222)),
				ffw::GuiStyle::Function(ffw::rgb(0xFFFFFF))
			),
			// Hover
			ffw::GuiStyle(
				ffw::GuiStyle::Background(0, ffw::rgb(0x000000), ffw::GuiStyle::Background::Type::NONE),
				ffw::GuiStyle::Border(0, 0, ffw::rgb(0x000000)),
				ffw::GuiStyle::Outline(0, 0, ffw::rgb(0x000000)),
				ffw::GuiStyle::Text(ffw::rgb(0x222222)),
				ffw::GuiStyle::Function(ffw::rgb(0xFFFFFF))
			),
			// Active
			ffw::GuiStyle(
				ffw::GuiStyle::Background(0, ffw::rgb(0x000000), ffw::GuiStyle::Background::Type::NONE),
				ffw::GuiStyle::Border(0, 0, ffw::rgb(0x000000)),
				ffw::GuiStyle::Outline(0, 0, ffw::rgb(0x000000)),
				ffw::GuiStyle::Text(ffw::rgb(0x222222)),
				ffw::GuiStyle::Function(ffw::rgb(0xFFFFFF))
			),
			// Disabled
			ffw::GuiStyle(
				ffw::GuiStyle::Background(0, ffw::rgb(0x000000), ffw::GuiStyle::Background::Type::NONE),
				ffw::GuiStyle::Border(0, 0, ffw::rgb(0x000000)),
				ffw::GuiStyle::Outline(0, 0, ffw::rgb(0x000000)),
				ffw::GuiStyle::Text(ffw::rgb(0x828282)),
				ffw::GuiStyle::Function(ffw::rgb(0xFFFFFF))
			),
			ffw::GuiDefaults(
				ffw::GuiStyle::Margin(0, 0, 5, 0),
				ffw::GuiStyle::Padding(0),
				ffw::GuiStyle::Align::TOP_LEFT,
				ffw::Vec2<GuiUnits>(ffw::guiPercent(100), ffw::guiWrap())
			)
		)
	},
	// GUI CHECKBOX BUTTON
	{
		"GUI_CHECKBOX_BUTTON",
		ffw::GuiStyleGroup(
			// Normal
			ffw::GuiStyle(
				ffw::GuiStyle::Background(0, ffw::rgb(0xFFFFFF), ffw::GuiStyle::Background::Type::SIMPLE),
				ffw::GuiStyle::Border(1, 0, ffw::rgb(0x222222)),
				ffw::GuiStyle::Outline(0, 0, ffw::rgb(0x000000)),
				ffw::GuiStyle::Text(ffw::rgb(0x000000)),
				ffw::GuiStyle::Function(ffw::rgb(0xFFFFFF))
			),
			// Hover
			ffw::GuiStyle(
				ffw::GuiStyle::Background(0, ffw::rgb(0xFFFFFF), ffw::GuiStyle::Background::Type::SIMPLE),
				ffw::GuiStyle::Border(1, 0, ffw::rgb(0x222222)),
				ffw::GuiStyle::Outline(0, 0, ffw::rgb(0x000000)),
				ffw::GuiStyle::Text(ffw::rgb(0x000000)),
				ffw::GuiStyle::Function(ffw::rgb(0x888888))
			),
			// Active
			ffw::GuiStyle(
				ffw::GuiStyle::Background(0, ffw::rgb(0xFFFFFF), ffw::GuiStyle::Background::Type::SIMPLE),
				ffw::GuiStyle::Border(1, 0, ffw::rgb(0x222222)),
				ffw::GuiStyle::Outline(0, 0, ffw::rgb(0x000000)),
				ffw::GuiStyle::Text(ffw::rgb(0x000000)),
				ffw::GuiStyle::Function(ffw::rgb(0x222222))
			),
			// Disabled
			ffw::GuiStyle(
				ffw::GuiStyle::Background(0, ffw::rgb(0xCACACA), ffw::GuiStyle::Background::Type::SIMPLE),
				ffw::GuiStyle::Border(1, 0, ffw::rgb(0xBEBEBE)),
				ffw::GuiStyle::Outline(0, 0, ffw::rgb(0x000000)),
				ffw::GuiStyle::Text(ffw::rgb(0x000000)),
				ffw::GuiStyle::Function(ffw::rgb(0xCACACA))
			),
			ffw::GuiDefaults(
				ffw::GuiStyle::Margin(0, 5, 0, 0),
				ffw::GuiStyle::Padding(guiPercent(20)),
				ffw::GuiStyle::Align::CENTER,
				ffw::Vec2<GuiUnits>(ffw::guiPixels(16), ffw::guiPixels(16))
			)
		)
	},
	// GUI RADIO
	{
		"GUI_RADIO",
		ffw::GuiStyleGroup(
			// Normal
			ffw::GuiStyle(
				ffw::GuiStyle::Background(0, ffw::rgb(0x000000), ffw::GuiStyle::Background::Type::NONE),
				ffw::GuiStyle::Border(0, 0, ffw::rgb(0x000000)),
				ffw::GuiStyle::Outline(0, 0, ffw::rgb(0x000000)),
				ffw::GuiStyle::Text(ffw::rgb(0x222222)),
				ffw::GuiStyle::Function(ffw::rgb(0xFFFFFF))
			),
			// Hover
			ffw::GuiStyle(
				ffw::GuiStyle::Background(0, ffw::rgb(0x000000), ffw::GuiStyle::Background::Type::NONE),
				ffw::GuiStyle::Border(0, 0, ffw::rgb(0x000000)),
				ffw::GuiStyle::Outline(0, 0, ffw::rgb(0x000000)),
				ffw::GuiStyle::Text(ffw::rgb(0x222222)),
				ffw::GuiStyle::Function(ffw::rgb(0xFFFFFF))
			),
			// Active
			ffw::GuiStyle(
				ffw::GuiStyle::Background(0, ffw::rgb(0x000000), ffw::GuiStyle::Background::Type::NONE),
				ffw::GuiStyle::Border(0, 0, ffw::rgb(0x000000)),
				ffw::GuiStyle::Outline(0, 0, ffw::rgb(0x000000)),
				ffw::GuiStyle::Text(ffw::rgb(0x222222)),
				ffw::GuiStyle::Function(ffw::rgb(0xFFFFFF))
			),
			// Disabled
			ffw::GuiStyle(
				ffw::GuiStyle::Background(0, ffw::rgb(0x000000), ffw::GuiStyle::Background::Type::NONE),
				ffw::GuiStyle::Border(0, 0, ffw::rgb(0x000000)),
				ffw::GuiStyle::Outline(0, 0, ffw::rgb(0x000000)),
				ffw::GuiStyle::Text(ffw::rgb(0x828282)),
				ffw::GuiStyle::Function(ffw::rgb(0xFFFFFF))
			),
			ffw::GuiDefaults(
				ffw::GuiStyle::Margin(0, 0, 5, 0),
				ffw::GuiStyle::Padding(0),
				ffw::GuiStyle::Align::TOP_LEFT,
				ffw::Vec2<GuiUnits>(ffw::guiPercent(100), ffw::guiWrap())
			)
		)
	},
	// GUI RADIO BUTTON
	{
		"GUI_RADIO_BUTTON",
		ffw::GuiStyleGroup(
			// Normal
			ffw::GuiStyle(
				ffw::GuiStyle::Background(8, ffw::rgb(0xFFFFFF), ffw::GuiStyle::Background::Type::SIMPLE),
				ffw::GuiStyle::Border(1, 8, ffw::rgb(0x222222)),
				ffw::GuiStyle::Outline(0, 0, ffw::rgb(0x000000)),
				ffw::GuiStyle::Text(ffw::rgb(0x000000)),
				ffw::GuiStyle::Function(ffw::rgb(0xFFFFFF))
			),
			// Hover
			ffw::GuiStyle(
				ffw::GuiStyle::Background(8, ffw::rgb(0xFFFFFF), ffw::GuiStyle::Background::Type::SIMPLE),
				ffw::GuiStyle::Border(1, 8, ffw::rgb(0x222222)),
				ffw::GuiStyle::Outline(0, 0, ffw::rgb(0x000000)),
				ffw::GuiStyle::Text(ffw::rgb(0x000000)),
				ffw::GuiStyle::Function(ffw::rgb(0x888888))
			),
			// Active
			ffw::GuiStyle(
				ffw::GuiStyle::Background(8, ffw::rgb(0xFFFFFF), ffw::GuiStyle::Background::Type::SIMPLE),
				ffw::GuiStyle::Border(1, 8, ffw::rgb(0x222222)),
				ffw::GuiStyle::Outline(0, 0, ffw::rgb(0x000000)),
				ffw::GuiStyle::Text(ffw::rgb(0x000000)),
				ffw::GuiStyle::Function(ffw::rgb(0x222222))
			),
			// Disabled
			ffw::GuiStyle(
				ffw::GuiStyle::Background(8, ffw::rgb(0xCACACA), ffw::GuiStyle::Background::Type::SIMPLE),
				ffw::GuiStyle::Border(1, 8, ffw::rgb(0xBEBEBE)),
				ffw::GuiStyle::Outline(0, 0, ffw::rgb(0x000000)),
				ffw::GuiStyle::Text(ffw::rgb(0x000000)),
				ffw::GuiStyle::Function(ffw::rgb(0xCACACA))
			),
			ffw::GuiDefaults(
				ffw::GuiStyle::Margin(0, 5, 0, 0),
				ffw::GuiStyle::Padding(guiPercent(20)),
				ffw::GuiStyle::Align::CENTER,
				ffw::Vec2<GuiUnits>(ffw::guiPixels(16), ffw::guiPixels(16))
			)
		)
	},
	// GUI SLIDER
	{
		"GUI_SLIDER",
		ffw::GuiStyleGroup(
			// Normal
			ffw::GuiStyle(
				ffw::GuiStyle::Background(0, ffw::rgb(0x000000), ffw::GuiStyle::Background::Type::NONE),
				ffw::GuiStyle::Border(0, 0, ffw::rgb(0x000000)),
				ffw::GuiStyle::Outline(0, 0, ffw::rgb(0x000000)),
				ffw::GuiStyle::Text(ffw::rgb(0xFFFFFF)),
				ffw::GuiStyle::Function(ffw::rgb(0xFFFFFF))
			),
			// Hover
			ffw::GuiStyle(
				ffw::GuiStyle::Background(0, ffw::rgb(0x000000), ffw::GuiStyle::Background::Type::NONE),
				ffw::GuiStyle::Border(0, 0, ffw::rgb(0x000000)),
				ffw::GuiStyle::Outline(0, 0, ffw::rgb(0x000000)),
				ffw::GuiStyle::Text(ffw::rgb(0xFFFFFF)),
				ffw::GuiStyle::Function(ffw::rgb(0xFFFFFF))
			),
			// Active
			ffw::GuiStyle(
				ffw::GuiStyle::Background(0, ffw::rgb(0x000000), ffw::GuiStyle::Background::Type::NONE),
				ffw::GuiStyle::Border(0, 0, ffw::rgb(0x000000)),
				ffw::GuiStyle::Outline(0, 0, ffw::rgb(0x000000)),
				ffw::GuiStyle::Text(ffw::rgb(0xFFFFFF)),
				ffw::GuiStyle::Function(ffw::rgb(0xFFFFFF))
			),
			// Disabled
			ffw::GuiStyle(
				ffw::GuiStyle::Background(0, ffw::rgb(0x000000), ffw::GuiStyle::Background::Type::NONE),
				ffw::GuiStyle::Border(0, 0, ffw::rgb(0x000000)),
				ffw::GuiStyle::Outline(0, 0, ffw::rgb(0x000000)),
				ffw::GuiStyle::Text(ffw::rgb(0xFFFFFF)),
				ffw::GuiStyle::Function(ffw::rgb(0xFFFFFF))
			),
			ffw::GuiDefaults(
				ffw::GuiStyle::Margin(0, 0, 0, 0),
				ffw::GuiStyle::Padding(2, 4, 2, 4),
				ffw::GuiStyle::Align::TOP_LEFT,
				ffw::Vec2<GuiUnits>(ffw::guiPercent(100), ffw::guiWrap())
			)
		)
	},
	// GUI SLIDER
	{
		"GUI_SLIDER_BAR",
		ffw::GuiStyleGroup(
			// Normal
			ffw::GuiStyle(
				ffw::GuiStyle::Background(0, ffw::rgb(0xE7EAEA), ffw::GuiStyle::Background::Type::SIMPLE),
				ffw::GuiStyle::Border(1, 0, ffw::rgb(0xD6D6D6)),
				ffw::GuiStyle::Outline(0, 0, ffw::rgb(0x000000)),
				ffw::GuiStyle::Text(ffw::rgb(0xFFFFFF)),
				ffw::GuiStyle::Function(ffw::rgb(0x007AD9))
			),
			// Hover
			ffw::GuiStyle(
				ffw::GuiStyle::Background(0, ffw::rgb(0xE7EAEA), ffw::GuiStyle::Background::Type::SIMPLE),
				ffw::GuiStyle::Border(1, 0, ffw::rgb(0xD6D6D6)),
				ffw::GuiStyle::Outline(0, 0, ffw::rgb(0x000000)),
				ffw::GuiStyle::Text(ffw::rgb(0xFFFFFF)),
				ffw::GuiStyle::Function(ffw::rgb(0x007AD9))
			),
			// Active
			ffw::GuiStyle(
				ffw::GuiStyle::Background(0, ffw::rgb(0xE7EAEA), ffw::GuiStyle::Background::Type::SIMPLE),
				ffw::GuiStyle::Border(1, 0, ffw::rgb(0xD6D6D6)),
				ffw::GuiStyle::Outline(0, 0, ffw::rgb(0x000000)),
				ffw::GuiStyle::Text(ffw::rgb(0xFFFFFF)),
				ffw::GuiStyle::Function(ffw::rgb(0x007AD9))
			),
			// Disabled
			ffw::GuiStyle(
				ffw::GuiStyle::Background(0, ffw::rgb(0xE7EAEA), ffw::GuiStyle::Background::Type::SIMPLE),
				ffw::GuiStyle::Border(1, 0, ffw::rgb(0xD6D6D6)),
				ffw::GuiStyle::Outline(0, 0, ffw::rgb(0x000000)),
				ffw::GuiStyle::Text(ffw::rgb(0xFFFFFF)),
				ffw::GuiStyle::Function(ffw::rgb(0xB3B3B3))
			),
			ffw::GuiDefaults(
				ffw::GuiStyle::Margin(0, 0, 0, 0),
				ffw::GuiStyle::Padding(0),
				ffw::GuiStyle::Align::TOP_LEFT,
				ffw::Vec2<GuiUnits>(ffw::guiPercent(100), ffw::guiPixels(4))
			)
		)
	},
	// GUI SLIDER BUTTON
	{
		"GUI_SLIDER_BUTTON",
		ffw::GuiStyleGroup(
			// Normal
			ffw::GuiStyle(
				ffw::GuiStyle::Background(0, ffw::rgb(0xE1E1E1), ffw::GuiStyle::Background::Type::SIMPLE),
				ffw::GuiStyle::Border(1, 0, ffw::rgb(0xADADAD)),
				ffw::GuiStyle::Outline(0, 0, ffw::rgb(0x000000)),
				ffw::GuiStyle::Text(ffw::rgb(0x222222)),
				ffw::GuiStyle::Function(ffw::rgb(0xFFFFFF))
			),
			// Hover
			ffw::GuiStyle(
				ffw::GuiStyle::Background(0, ffw::rgb(0xE5F1FB), ffw::GuiStyle::Background::Type::SIMPLE),
				ffw::GuiStyle::Border(1, 0, ffw::rgb(0x0078D7)),
				ffw::GuiStyle::Outline(0, 0, ffw::rgb(0x000000)),
				ffw::GuiStyle::Text(ffw::rgb(0x222222)),
				ffw::GuiStyle::Function(ffw::rgb(0xFFFFFF))
			),
			// Active
			ffw::GuiStyle(
				ffw::GuiStyle::Background(0, ffw::rgb(0xCCE4F7), ffw::GuiStyle::Background::Type::SIMPLE),
				ffw::GuiStyle::Border(1, 0, ffw::rgb(0x005499)),
				ffw::GuiStyle::Outline(0, 0, ffw::rgb(0x000000)),
				ffw::GuiStyle::Text(ffw::rgb(0x222222)),
				ffw::GuiStyle::Function(ffw::rgb(0xFFFFFF))
			),
			// Disabled
			ffw::GuiStyle(
				ffw::GuiStyle::Background(0, ffw::rgb(0xCACACA), ffw::GuiStyle::Background::Type::SIMPLE),
				ffw::GuiStyle::Border(1, 0, ffw::rgb(0xBEBEBE)),
				ffw::GuiStyle::Outline(0, 0, ffw::rgb(0x000000)),
				ffw::GuiStyle::Text(ffw::rgb(0x828282)),
				ffw::GuiStyle::Function(ffw::rgb(0xFFFFFF))
			),
			ffw::GuiDefaults(
				ffw::GuiStyle::Margin(0, 0, 0, 0),
				ffw::GuiStyle::Padding(0),
				ffw::GuiStyle::Align::TOP_LEFT,
				ffw::Vec2<GuiUnits>(ffw::guiPixels(8), ffw::guiPixels(16))
			)
		)
	},
	{
		"GUI_SCROLLBAR",
		ffw::GuiStyleGroup(
			// Normal
			ffw::GuiStyle(
				ffw::GuiStyle::Background(0, ffw::rgb(0xEFEFEF), ffw::GuiStyle::Background::Type::SIMPLE),
				ffw::GuiStyle::Border(0, 0, ffw::rgb(0x000000)),
				ffw::GuiStyle::Outline(0, 0, ffw::rgb(0x000000)),
				ffw::GuiStyle::Text(ffw::rgb(0xFFFFFF)),
				ffw::GuiStyle::Function(ffw::rgb(0xFFFFFF))
			),
			// Hover
			ffw::GuiStyle(
				ffw::GuiStyle::Background(0, ffw::rgb(0xEFEFEF), ffw::GuiStyle::Background::Type::SIMPLE),
				ffw::GuiStyle::Border(0, 0, ffw::rgb(0x000000)),
				ffw::GuiStyle::Outline(0, 0, ffw::rgb(0x000000)),
				ffw::GuiStyle::Text(ffw::rgb(0xFFFFFF)),
				ffw::GuiStyle::Function(ffw::rgb(0xFFFFFF))
			),
			// Active
			ffw::GuiStyle(
				ffw::GuiStyle::Background(0, ffw::rgb(0xEFEFEF), ffw::GuiStyle::Background::Type::SIMPLE),
				ffw::GuiStyle::Border(0, 0, ffw::rgb(0x000000)),
				ffw::GuiStyle::Outline(0, 0, ffw::rgb(0x000000)),
				ffw::GuiStyle::Text(ffw::rgb(0xFFFFFF)),
				ffw::GuiStyle::Function(ffw::rgb(0xFFFFFF))
			),
			// Disabled
			ffw::GuiStyle(
				ffw::GuiStyle::Background(0, ffw::rgb(0xEFEFEF), ffw::GuiStyle::Background::Type::SIMPLE),
				ffw::GuiStyle::Border(0, 0, ffw::rgb(0x000000)),
				ffw::GuiStyle::Outline(0, 0, ffw::rgb(0x000000)),
				ffw::GuiStyle::Text(ffw::rgb(0xFFFFFF)),
				ffw::GuiStyle::Function(ffw::rgb(0xFFFFFF))
			),
			ffw::GuiDefaults(
				ffw::GuiStyle::Margin(0, 0, 0, 0),
				ffw::GuiStyle::Padding(1),
				ffw::GuiStyle::Align::TOP_LEFT,
				ffw::Vec2<GuiUnits>(ffw::guiPercent(100), ffw::guiWrap())
			)
		)
	},
	{
		"GUI_SCROLLBAR_BUTTON_LEFT",
		ffw::GuiStyleGroup(
			// Normal
			ffw::GuiStyle(
				ffw::GuiStyle::Background(0, ffw::rgb(0x000000), ffw::GuiStyle::Background::Type::NONE),
				ffw::GuiStyle::Border(0, 0, ffw::rgb(0x000000)),
				ffw::GuiStyle::Outline(0, 0, ffw::rgb(0x000000)),
				ffw::GuiStyle::Text(ffw::rgb(0x616161)),
				ffw::GuiStyle::Function(ffw::rgb(0xFFFFFF))
			),
			// Hover
			ffw::GuiStyle(
				ffw::GuiStyle::Background(0, ffw::rgb(0xCECECE), ffw::GuiStyle::Background::Type::SIMPLE),
				ffw::GuiStyle::Border(0, 0, ffw::rgb(0x000000)),
				ffw::GuiStyle::Outline(0, 0, ffw::rgb(0x000000)),
				ffw::GuiStyle::Text(ffw::rgb(0x616161)),
				ffw::GuiStyle::Function(ffw::rgb(0xFFFFFF))
			),
			// Active
			ffw::GuiStyle(
				ffw::GuiStyle::Background(0, ffw::rgb(0x616161), ffw::GuiStyle::Background::Type::SIMPLE),
				ffw::GuiStyle::Border(0, 0, ffw::rgb(0x000000)),
				ffw::GuiStyle::Outline(0, 0, ffw::rgb(0x000000)),
				ffw::GuiStyle::Text(ffw::rgb(0xFFFFFF)),
				ffw::GuiStyle::Function(ffw::rgb(0xFFFFFF))
			),
			// Disabled
			ffw::GuiStyle(
				ffw::GuiStyle::Background(0, ffw::rgb(0x000000), ffw::GuiStyle::Background::Type::NONE),
				ffw::GuiStyle::Border(0, 0, ffw::rgb(0x000000)),
				ffw::GuiStyle::Outline(0, 0, ffw::rgb(0x000000)),
				ffw::GuiStyle::Text(ffw::rgb(0xCECECE)),
				ffw::GuiStyle::Function(ffw::rgb(0xFFFFFF))
			),
			ffw::GuiDefaults(
				ffw::GuiStyle::Margin(),
				ffw::GuiStyle::Padding(2),
				ffw::GuiStyle::Align::TOP_LEFT,
				ffw::Vec2<GuiUnits>()
			)
		)
	},
	{
		"GUI_SCROLLBAR_BUTTON_RIGHT",
		ffw::GuiStyleGroup(
			// Normal
			ffw::GuiStyle(
				ffw::GuiStyle::Background(0, ffw::rgb(0x000000), ffw::GuiStyle::Background::Type::NONE),
				ffw::GuiStyle::Border(0, 0, ffw::rgb(0x000000)),
				ffw::GuiStyle::Outline(0, 0, ffw::rgb(0x000000)),
				ffw::GuiStyle::Text(ffw::rgb(0x616161)),
				ffw::GuiStyle::Function(ffw::rgb(0xFFFFFF))
			),
			// Hover
			ffw::GuiStyle(
				ffw::GuiStyle::Background(0, ffw::rgb(0xCECECE), ffw::GuiStyle::Background::Type::SIMPLE),
				ffw::GuiStyle::Border(0, 0, ffw::rgb(0x000000)),
				ffw::GuiStyle::Outline(0, 0, ffw::rgb(0x000000)),
				ffw::GuiStyle::Text(ffw::rgb(0x616161)),
				ffw::GuiStyle::Function(ffw::rgb(0xFFFFFF))
			),
			// Active
			ffw::GuiStyle(
				ffw::GuiStyle::Background(0, ffw::rgb(0x616161), ffw::GuiStyle::Background::Type::SIMPLE),
				ffw::GuiStyle::Border(0, 0, ffw::rgb(0x000000)),
				ffw::GuiStyle::Outline(0, 0, ffw::rgb(0x000000)),
				ffw::GuiStyle::Text(ffw::rgb(0xFFFFFF)),
				ffw::GuiStyle::Function(ffw::rgb(0xFFFFFF))
			),
			// Disabled
			ffw::GuiStyle(
				ffw::GuiStyle::Background(0, ffw::rgb(0x000000), ffw::GuiStyle::Background::Type::NONE),
				ffw::GuiStyle::Border(0, 0, ffw::rgb(0x000000)),
				ffw::GuiStyle::Outline(0, 0, ffw::rgb(0x000000)),
				ffw::GuiStyle::Text(ffw::rgb(0xCECECE)),
				ffw::GuiStyle::Function(ffw::rgb(0xFFFFFF))
			),
			ffw::GuiDefaults(
				ffw::GuiStyle::Margin(),
				ffw::GuiStyle::Padding(2),
				ffw::GuiStyle::Align::TOP_LEFT,
				ffw::Vec2<GuiUnits>()
			)
		)
	},
	{
		"GUI_SCROLLBAR_BUTTON_TOP",
		ffw::GuiStyleGroup(
			// Normal
			ffw::GuiStyle(
				ffw::GuiStyle::Background(0, ffw::rgb(0x000000), ffw::GuiStyle::Background::Type::NONE),
				ffw::GuiStyle::Border(0, 0, ffw::rgb(0x000000)),
				ffw::GuiStyle::Outline(0, 0, ffw::rgb(0x000000)),
				ffw::GuiStyle::Text(ffw::rgb(0x616161)),
				ffw::GuiStyle::Function(ffw::rgb(0xFFFFFF))
			),
			// Hover
			ffw::GuiStyle(
				ffw::GuiStyle::Background(0, ffw::rgb(0xCECECE), ffw::GuiStyle::Background::Type::SIMPLE),
				ffw::GuiStyle::Border(0, 0, ffw::rgb(0x000000)),
				ffw::GuiStyle::Outline(0, 0, ffw::rgb(0x000000)),
				ffw::GuiStyle::Text(ffw::rgb(0x616161)),
				ffw::GuiStyle::Function(ffw::rgb(0xFFFFFF))
			),
			// Active
			ffw::GuiStyle(
				ffw::GuiStyle::Background(0, ffw::rgb(0x616161), ffw::GuiStyle::Background::Type::SIMPLE),
				ffw::GuiStyle::Border(0, 0, ffw::rgb(0x000000)),
				ffw::GuiStyle::Outline(0, 0, ffw::rgb(0x000000)),
				ffw::GuiStyle::Text(ffw::rgb(0xFFFFFF)),
				ffw::GuiStyle::Function(ffw::rgb(0xFFFFFF))
			),
			// Disabled
			ffw::GuiStyle(
				ffw::GuiStyle::Background(0, ffw::rgb(0x000000), ffw::GuiStyle::Background::Type::NONE),
				ffw::GuiStyle::Border(0, 0, ffw::rgb(0x000000)),
				ffw::GuiStyle::Outline(0, 0, ffw::rgb(0x000000)),
				ffw::GuiStyle::Text(ffw::rgb(0xCECECE)),
				ffw::GuiStyle::Function(ffw::rgb(0xFFFFFF))
			),
			ffw::GuiDefaults(
				ffw::GuiStyle::Margin(),
				ffw::GuiStyle::Padding(2),
				ffw::GuiStyle::Align::TOP_LEFT,
				ffw::Vec2<GuiUnits>()
			)
		)
	},
	{
		"GUI_SCROLLBAR_BUTTON_BOTTOM",
		ffw::GuiStyleGroup(
			// Normal
			ffw::GuiStyle(
				ffw::GuiStyle::Background(0, ffw::rgb(0x000000), ffw::GuiStyle::Background::Type::NONE),
				ffw::GuiStyle::Border(0, 0, ffw::rgb(0x000000)),
				ffw::GuiStyle::Outline(0, 0, ffw::rgb(0x000000)),
				ffw::GuiStyle::Text(ffw::rgb(0x616161)),
				ffw::GuiStyle::Function(ffw::rgb(0xFFFFFF))
			),
			// Hover
			ffw::GuiStyle(
				ffw::GuiStyle::Background(0, ffw::rgb(0xCECECE), ffw::GuiStyle::Background::Type::SIMPLE),
				ffw::GuiStyle::Border(0, 0, ffw::rgb(0x000000)),
				ffw::GuiStyle::Outline(0, 0, ffw::rgb(0x000000)),
				ffw::GuiStyle::Text(ffw::rgb(0x616161)),
				ffw::GuiStyle::Function(ffw::rgb(0xFFFFFF))
			),
			// Active
			ffw::GuiStyle(
				ffw::GuiStyle::Background(0, ffw::rgb(0x616161), ffw::GuiStyle::Background::Type::SIMPLE),
				ffw::GuiStyle::Border(0, 0, ffw::rgb(0x000000)),
				ffw::GuiStyle::Outline(0, 0, ffw::rgb(0x000000)),
				ffw::GuiStyle::Text(ffw::rgb(0xFFFFFF)),
				ffw::GuiStyle::Function(ffw::rgb(0xFFFFFF))
			),
			// Disabled
			ffw::GuiStyle(
				ffw::GuiStyle::Background(0, ffw::rgb(0x000000), ffw::GuiStyle::Background::Type::NONE),
				ffw::GuiStyle::Border(0, 0, ffw::rgb(0x000000)),
				ffw::GuiStyle::Outline(0, 0, ffw::rgb(0x000000)),
				ffw::GuiStyle::Text(ffw::rgb(0xCECECE)),
				ffw::GuiStyle::Function(ffw::rgb(0xFFFFFF))
			),
			ffw::GuiDefaults(
				ffw::GuiStyle::Margin(),
				ffw::GuiStyle::Padding(2),
				ffw::GuiStyle::Align::TOP_LEFT,
				ffw::Vec2<GuiUnits>()
			)
		)
	},
	{
		"GUI_SCROLLBAR_SLIDER",
		ffw::GuiStyleGroup(
			// Normal
			ffw::GuiStyle(
				ffw::GuiStyle::Background(0, ffw::rgb(0x000000), ffw::GuiStyle::Background::Type::NONE),
				ffw::GuiStyle::Border(0, 0, ffw::rgb(0x000000)),
				ffw::GuiStyle::Outline(0, 0, ffw::rgb(0x000000)),
				ffw::GuiStyle::Text(ffw::rgb(0xFFFFFF)),
				ffw::GuiStyle::Function(ffw::rgb(0xFFFFFF))
			),
			// Hover
			ffw::GuiStyle(
				ffw::GuiStyle::Background(0, ffw::rgb(0x000000), ffw::GuiStyle::Background::Type::NONE),
				ffw::GuiStyle::Border(0, 0, ffw::rgb(0x000000)),
				ffw::GuiStyle::Outline(0, 0, ffw::rgb(0x000000)),
				ffw::GuiStyle::Text(ffw::rgb(0xFFFFFF)),
				ffw::GuiStyle::Function(ffw::rgb(0xFFFFFF))
			),
			// Active
			ffw::GuiStyle(
				ffw::GuiStyle::Background(0, ffw::rgb(0x000000), ffw::GuiStyle::Background::Type::NONE),
				ffw::GuiStyle::Border(0, 0, ffw::rgb(0x000000)),
				ffw::GuiStyle::Outline(0, 0, ffw::rgb(0x000000)),
				ffw::GuiStyle::Text(ffw::rgb(0xFFFFFF)),
				ffw::GuiStyle::Function(ffw::rgb(0xFFFFFF))
			),
			// Disabled
			ffw::GuiStyle(
				ffw::GuiStyle::Background(0, ffw::rgb(0x000000), ffw::GuiStyle::Background::Type::NONE),
				ffw::GuiStyle::Border(0, 0, ffw::rgb(0x000000)),
				ffw::GuiStyle::Outline(0, 0, ffw::rgb(0x000000)),
				ffw::GuiStyle::Text(ffw::rgb(0xFFFFFF)),
				ffw::GuiStyle::Function(ffw::rgb(0xFFFFFF))
			)
		)
	},
	{
		"GUI_SCROLLBAR_SLIDER_BAR",
		ffw::GuiStyleGroup(
			// Normal
			ffw::GuiStyle(
				ffw::GuiStyle::Background(0, ffw::rgb(0x000000), ffw::GuiStyle::Background::Type::NONE),
				ffw::GuiStyle::Border(0, 0, ffw::rgb(0x000000)),
				ffw::GuiStyle::Outline(0, 0, ffw::rgb(0x000000)),
				ffw::GuiStyle::Text(ffw::rgb(0xFFFFFF)),
				ffw::GuiStyle::Function(ffw::rgba(0xFFFFFF00))
			),
			// Hover
			ffw::GuiStyle(
				ffw::GuiStyle::Background(0, ffw::rgb(0x000000), ffw::GuiStyle::Background::Type::NONE),
				ffw::GuiStyle::Border(0, 0, ffw::rgb(0x000000)),
				ffw::GuiStyle::Outline(0, 0, ffw::rgb(0x000000)),
				ffw::GuiStyle::Text(ffw::rgb(0xFFFFFF)),
				ffw::GuiStyle::Function(ffw::rgba(0xFFFFFF00))
			),
			// Active
			ffw::GuiStyle(
				ffw::GuiStyle::Background(0, ffw::rgb(0x000000), ffw::GuiStyle::Background::Type::NONE),
				ffw::GuiStyle::Border(0, 0, ffw::rgb(0x000000)),
				ffw::GuiStyle::Outline(0, 0, ffw::rgb(0x000000)),
				ffw::GuiStyle::Text(ffw::rgb(0xFFFFFF)),
				ffw::GuiStyle::Function(ffw::rgba(0xFFFFFF00))
			),
			// Disabled
			ffw::GuiStyle(
				ffw::GuiStyle::Background(0, ffw::rgb(0xCECECE), ffw::GuiStyle::Background::Type::SIMPLE),
				ffw::GuiStyle::Border(0, 0, ffw::rgb(0x000000)),
				ffw::GuiStyle::Outline(0, 0, ffw::rgb(0x000000)),
				ffw::GuiStyle::Text(ffw::rgb(0xFFFFFF)),
				ffw::GuiStyle::Function(ffw::rgba(0xFFFFFF00))
			),
			ffw::GuiDefaults(
				ffw::GuiStyle::Margin(0, 0, 0, 0),
				ffw::GuiStyle::Padding(0),
				ffw::GuiStyle::Align::TOP_LEFT,
				ffw::Vec2<GuiUnits>(ffw::guiPercent(100), ffw::guiPercent(100))
			)
		)
	},
	{
		"GUI_SCROLLBAR_SLIDER_BUTTON",
		ffw::GuiStyleGroup(
			// Normal
			ffw::GuiStyle(
				ffw::GuiStyle::Background(0, ffw::rgb(0xCECECE), ffw::GuiStyle::Background::Type::SIMPLE),
				ffw::GuiStyle::Border(0, 0, ffw::rgb(0x000000)),
				ffw::GuiStyle::Outline(0, 0, ffw::rgb(0x000000)),
				ffw::GuiStyle::Text(ffw::rgb(0xFFFFFF)),
				ffw::GuiStyle::Function(ffw::rgba(0xFFFFFF00))
			),
			// Hover
			ffw::GuiStyle(
				ffw::GuiStyle::Background(0, ffw::rgb(0xA6A6A6), ffw::GuiStyle::Background::Type::SIMPLE),
				ffw::GuiStyle::Border(0, 0, ffw::rgb(0x000000)),
				ffw::GuiStyle::Outline(0, 0, ffw::rgb(0x000000)),
				ffw::GuiStyle::Text(ffw::rgb(0xFFFFFF)),
				ffw::GuiStyle::Function(ffw::rgba(0xFFFFFF00))
			),
			// Active
			ffw::GuiStyle(
				ffw::GuiStyle::Background(0, ffw::rgb(0x616161), ffw::GuiStyle::Background::Type::SIMPLE),
				ffw::GuiStyle::Border(0, 0, ffw::rgb(0x000000)),
				ffw::GuiStyle::Outline(0, 0, ffw::rgb(0x000000)),
				ffw::GuiStyle::Text(ffw::rgb(0xFFFFFF)),
				ffw::GuiStyle::Function(ffw::rgba(0xFFFFFF00))
			),
			// Disabled
			ffw::GuiStyle(
				ffw::GuiStyle::Background(0, ffw::rgb(0x000000), ffw::GuiStyle::Background::Type::NONE),
				ffw::GuiStyle::Border(0, 0, ffw::rgb(0x000000)),
				ffw::GuiStyle::Outline(0, 0, ffw::rgb(0x000000)),
				ffw::GuiStyle::Text(ffw::rgb(0xFFFFFF)),
				ffw::GuiStyle::Function(ffw::rgba(0xFFFFFF00))
			),
			ffw::GuiDefaults(
				ffw::GuiStyle::Margin(0, 0, 0, 0),
				ffw::GuiStyle::Padding(0),
				ffw::GuiStyle::Align::TOP_LEFT,
				ffw::Vec2<GuiUnits>(ffw::guiPercent(25), ffw::guiPixels(12))
			)
		)
	},
	{
		"GUI_SCROLLABLE",
		ffw::GuiStyleGroup(
			// Normal
			ffw::GuiStyle(
				ffw::GuiStyle::Background(0, ffw::rgb(0x000000), ffw::GuiStyle::Background::Type::NONE),
				ffw::GuiStyle::Border(1, 0, ffw::rgb(0xADADAD)),
				ffw::GuiStyle::Outline(0, 0, ffw::rgb(0x000000)),
				ffw::GuiStyle::Text(ffw::rgb(0xFFFFFF)),
				ffw::GuiStyle::Function(ffw::rgb(0xFFFFFF))
			),
			// Hover
			ffw::GuiStyle(
				ffw::GuiStyle::Background(0, ffw::rgb(0x000000), ffw::GuiStyle::Background::Type::NONE),
				ffw::GuiStyle::Border(1, 0, ffw::rgb(0xADADAD)),
				ffw::GuiStyle::Outline(0, 0, ffw::rgb(0x000000)),
				ffw::GuiStyle::Text(ffw::rgb(0xFFFFFF)),
				ffw::GuiStyle::Function(ffw::rgb(0xFFFFFF))
			),
			// Active
			ffw::GuiStyle(
				ffw::GuiStyle::Background(0, ffw::rgb(0x000000), ffw::GuiStyle::Background::Type::NONE),
				ffw::GuiStyle::Border(1, 0, ffw::rgb(0xADADAD)),
				ffw::GuiStyle::Outline(0, 0, ffw::rgb(0x000000)),
				ffw::GuiStyle::Text(ffw::rgb(0xFFFFFF)),
				ffw::GuiStyle::Function(ffw::rgb(0xFFFFFF))
			),
			// Disabled
			ffw::GuiStyle(
				ffw::GuiStyle::Background(0, ffw::rgb(0x000000), ffw::GuiStyle::Background::Type::NONE),
				ffw::GuiStyle::Border(1, 0, ffw::rgb(0xADADAD)),
				ffw::GuiStyle::Outline(0, 0, ffw::rgb(0x000000)),
				ffw::GuiStyle::Text(ffw::rgb(0xFFFFFF)),
				ffw::GuiStyle::Function(ffw::rgb(0xFFFFFF))
			),
			ffw::GuiDefaults(
				ffw::GuiStyle::Margin(0, 0, 5, 0),
				ffw::GuiStyle::Padding(2),
				ffw::GuiStyle::Align::TOP_LEFT,
				ffw::Vec2<GuiUnits>(ffw::guiPercent(100), ffw::guiPixels(150))
			)
		)
	},
	{
		"GUI_LIST",
		ffw::GuiStyleGroup(
			// Normal
			ffw::GuiStyle(
				ffw::GuiStyle::Background(0, ffw::rgb(0xFFFFFF), ffw::GuiStyle::Background::Type::SIMPLE),
				ffw::GuiStyle::Border(1, 0, ffw::rgb(0xADADAD)),
				ffw::GuiStyle::Outline(0, 0, ffw::rgb(0x000000)),
				ffw::GuiStyle::Text(ffw::rgb(0xFFFFFF)),
				ffw::GuiStyle::Function(ffw::rgb(0xFFFFFF))
			),
			// Hover
			ffw::GuiStyle(
				ffw::GuiStyle::Background(0, ffw::rgb(0xFFFFFF), ffw::GuiStyle::Background::Type::SIMPLE),
				ffw::GuiStyle::Border(1, 0, ffw::rgb(0xADADAD)),
				ffw::GuiStyle::Outline(0, 0, ffw::rgb(0x000000)),
				ffw::GuiStyle::Text(ffw::rgb(0xFFFFFF)),
				ffw::GuiStyle::Function(ffw::rgb(0xFFFFFF))
			),
			// Active
			ffw::GuiStyle(
				ffw::GuiStyle::Background(0, ffw::rgb(0xFFFFFF), ffw::GuiStyle::Background::Type::SIMPLE),
				ffw::GuiStyle::Border(1, 0, ffw::rgb(0xADADAD)),
				ffw::GuiStyle::Outline(0, 0, ffw::rgb(0x000000)),
				ffw::GuiStyle::Text(ffw::rgb(0xFFFFFF)),
				ffw::GuiStyle::Function(ffw::rgb(0xFFFFFF))
			),
			// Disabled
			ffw::GuiStyle(
				ffw::GuiStyle::Background(0, ffw::rgb(0xFFFFFF), ffw::GuiStyle::Background::Type::SIMPLE),
				ffw::GuiStyle::Border(1, 0, ffw::rgb(0xADADAD)),
				ffw::GuiStyle::Outline(0, 0, ffw::rgb(0x000000)),
				ffw::GuiStyle::Text(ffw::rgb(0xFFFFFF)),
				ffw::GuiStyle::Function(ffw::rgb(0xFFFFFF))
			),
			ffw::GuiDefaults(
				ffw::GuiStyle::Margin(0, 0, 5, 0),
				ffw::GuiStyle::Padding(1),
				ffw::GuiStyle::Align::TOP_LEFT,
				ffw::Vec2<GuiUnits>(ffw::guiPercent(100), ffw::guiPixels(150))
			)
		)
	},
	{
		"GUI_LIST_ITEM",
		ffw::GuiStyleGroup(
			// Normal
			ffw::GuiStyle(
				ffw::GuiStyle::Background(0, ffw::rgb(0x000000), ffw::GuiStyle::Background::Type::NONE),
				ffw::GuiStyle::Border(0, 0, ffw::rgb(0x000000)),
				ffw::GuiStyle::Outline(0, 0, ffw::rgb(0x000000)),
				ffw::GuiStyle::Text(ffw::rgb(0x222222)),
				ffw::GuiStyle::Function(ffw::rgb(0xFFFFFF))
			),
			// Hover
			ffw::GuiStyle(
				ffw::GuiStyle::Background(0, ffw::rgb(0xCCE4FF), ffw::GuiStyle::Background::Type::SIMPLE),
				ffw::GuiStyle::Border(0, 0, ffw::rgb(0x000000)),
				ffw::GuiStyle::Outline(0, 0, ffw::rgb(0x000000)),
				ffw::GuiStyle::Text(ffw::rgb(0x222222)),
				ffw::GuiStyle::Function(ffw::rgb(0xFFFFFF))
			),
			// Active
			ffw::GuiStyle(
				ffw::GuiStyle::Background(0, ffw::rgb(0x3397FE), ffw::GuiStyle::Background::Type::SIMPLE),
				ffw::GuiStyle::Border(0, 0, ffw::rgb(0x000000)),
				ffw::GuiStyle::Outline(0, 0, ffw::rgb(0x000000)),
				ffw::GuiStyle::Text(ffw::rgb(0xFFFFFF)),
				ffw::GuiStyle::Function(ffw::rgb(0xFFFFFF))
			),
			// Disabled
			ffw::GuiStyle(
				ffw::GuiStyle::Background(0, ffw::rgb(0x000000), ffw::GuiStyle::Background::Type::NONE),
				ffw::GuiStyle::Border(0, 0, ffw::rgb(0x000000)),
				ffw::GuiStyle::Outline(0, 0, ffw::rgb(0x000000)),
				ffw::GuiStyle::Text(ffw::rgb(0xADADAD)),
				ffw::GuiStyle::Function(ffw::rgb(0xFFFFFF))
			),
			ffw::GuiDefaults(
				ffw::GuiStyle::Margin(0, 0, 0, 0),
				ffw::GuiStyle::Padding(0, 5, 0, 5),
				ffw::GuiStyle::Align::TOP_LEFT,
				ffw::Vec2<GuiUnits>(ffw::guiPercent(100), ffw::guiWrap())
			)
		)
	},
	{
		"GUI_SWITCH",
		ffw::GuiStyleGroup(
			// Normal
			ffw::GuiStyle(
				ffw::GuiStyle::Background(0, ffw::rgb(0x000000), ffw::GuiStyle::Background::Type::NONE),
				ffw::GuiStyle::Border(1, 0, ffw::rgb(0xADADAD)),
				ffw::GuiStyle::Outline(0, 0, ffw::rgb(0x000000)),
				ffw::GuiStyle::Text(ffw::rgb(0x000000)),
				ffw::GuiStyle::Function(ffw::rgb(0xFFFFFF))
			),
			// Hover
			ffw::GuiStyle(
				ffw::GuiStyle::Background(0, ffw::rgb(0x000000), ffw::GuiStyle::Background::Type::NONE),
				ffw::GuiStyle::Border(1, 0, ffw::rgb(0xADADAD)),
				ffw::GuiStyle::Outline(0, 0, ffw::rgb(0x000000)),
				ffw::GuiStyle::Text(ffw::rgb(0x000000)),
				ffw::GuiStyle::Function(ffw::rgb(0xFFFFFF))
			),
			// Active
			ffw::GuiStyle(
				ffw::GuiStyle::Background(0, ffw::rgb(0x000000), ffw::GuiStyle::Background::Type::NONE),
				ffw::GuiStyle::Border(1, 0, ffw::rgb(0xADADAD)),
				ffw::GuiStyle::Outline(0, 0, ffw::rgb(0x000000)),
				ffw::GuiStyle::Text(ffw::rgb(0x000000)),
				ffw::GuiStyle::Function(ffw::rgb(0xFFFFFF))
			),
			// Disabled
			ffw::GuiStyle(
				ffw::GuiStyle::Background(0, ffw::rgb(0x000000), ffw::GuiStyle::Background::Type::NONE),
				ffw::GuiStyle::Border(1, 0, ffw::rgb(0xADADAD)),
				ffw::GuiStyle::Outline(0, 0, ffw::rgb(0x000000)),
				ffw::GuiStyle::Text(ffw::rgb(0x000000)),
				ffw::GuiStyle::Function(ffw::rgb(0xFFFFFF))
			),
			ffw::GuiDefaults(
				ffw::GuiStyle::Margin(0, 0, 5, 0),
				ffw::GuiStyle::Padding(2),
				ffw::GuiStyle::Align::CENTER,
				ffw::Vec2<GuiUnits>(ffw::guiPixels(32), ffw::guiPixels(16))
			)
		)
	},
	{
		"GUI_SWITCH_BUTTON",
		ffw::GuiStyleGroup(
			// Normal
			ffw::GuiStyle(
				ffw::GuiStyle::Background(0, ffw::rgb(0xE1E1E1), ffw::GuiStyle::Background::Type::SIMPLE),
				ffw::GuiStyle::Border(1, 0, ffw::rgb(0xADADAD)),
				ffw::GuiStyle::Outline(0, 0, ffw::rgb(0x000000)),
				ffw::GuiStyle::Text(ffw::rgb(0x222222)),
				ffw::GuiStyle::Function(ffw::rgb(0xFFFFFF))
			),
			// Hover
			ffw::GuiStyle(
				ffw::GuiStyle::Background(0, ffw::rgb(0xE5F1FB), ffw::GuiStyle::Background::Type::SIMPLE),
				ffw::GuiStyle::Border(1, 0, ffw::rgb(0x0078D7)),
				ffw::GuiStyle::Outline(0, 0, ffw::rgb(0x000000)),
				ffw::GuiStyle::Text(ffw::rgb(0x222222)),
				ffw::GuiStyle::Function(ffw::rgb(0xFFFFFF))
			),
			// Active
			ffw::GuiStyle(
				ffw::GuiStyle::Background(0, ffw::rgb(0x00AB1C), ffw::GuiStyle::Background::Type::SIMPLE),
				ffw::GuiStyle::Border(1, 0, ffw::rgb(0x005499)),
				ffw::GuiStyle::Outline(0, 0, ffw::rgb(0x000000)),
				ffw::GuiStyle::Text(ffw::rgb(0x222222)),
				ffw::GuiStyle::Function(ffw::rgb(0xFFFFFF))
			),
			// Disabled
			ffw::GuiStyle(
				ffw::GuiStyle::Background(0, ffw::rgb(0xCACACA), ffw::GuiStyle::Background::Type::SIMPLE),
				ffw::GuiStyle::Border(1, 0, ffw::rgb(0xBEBEBE)),
				ffw::GuiStyle::Outline(0, 0, ffw::rgb(0x000000)),
				ffw::GuiStyle::Text(ffw::rgb(0x828282)),
				ffw::GuiStyle::Function(ffw::rgb(0xFFFFFF))
			)
		)
	},
	{
		"GUI_TABS",
		ffw::GuiStyleGroup(
			// Normal
			ffw::GuiStyle(
				ffw::GuiStyle::Background(0, ffw::rgb(0x000000), ffw::GuiStyle::Background::Type::NONE),
				ffw::GuiStyle::Border(0, 0, ffw::rgb(0x000000)),
				ffw::GuiStyle::Outline(0, 0, ffw::rgb(0x000000)),
				ffw::GuiStyle::Text(ffw::rgb(0xFFFFFF)),
				ffw::GuiStyle::Function(ffw::rgb(0xFFFFFF))
			),
			// Hover
			ffw::GuiStyle(
				ffw::GuiStyle::Background(0, ffw::rgb(0x000000), ffw::GuiStyle::Background::Type::NONE),
				ffw::GuiStyle::Border(0, 0, ffw::rgb(0x000000)),
				ffw::GuiStyle::Outline(0, 0, ffw::rgb(0x000000)),
				ffw::GuiStyle::Text(ffw::rgb(0xFFFFFF)),
				ffw::GuiStyle::Function(ffw::rgb(0xFFFFFF))
			),
			// Active
			ffw::GuiStyle(
				ffw::GuiStyle::Background(0, ffw::rgb(0x000000), ffw::GuiStyle::Background::Type::NONE),
				ffw::GuiStyle::Border(0, 0, ffw::rgb(0x000000)),
				ffw::GuiStyle::Outline(0, 0, ffw::rgb(0x000000)),
				ffw::GuiStyle::Text(ffw::rgb(0xFFFFFF)),
				ffw::GuiStyle::Function(ffw::rgb(0xFFFFFF))
			),
			// Disabled
			ffw::GuiStyle(
				ffw::GuiStyle::Background(0, ffw::rgb(0x000000), ffw::GuiStyle::Background::Type::NONE),
				ffw::GuiStyle::Border(0, 0, ffw::rgb(0x000000)),
				ffw::GuiStyle::Outline(0, 0, ffw::rgb(0x000000)),
				ffw::GuiStyle::Text(ffw::rgb(0xFFFFFF)),
				ffw::GuiStyle::Function(ffw::rgb(0xFFFFFF))
			),
			ffw::GuiDefaults(
				ffw::GuiStyle::Margin(0, 0, 5, 0),
				ffw::GuiStyle::Padding(0),
				ffw::GuiStyle::Align::TOP_LEFT,
				ffw::Vec2<GuiUnits>(ffw::guiPercent(100), ffw::guiWrap())
			)
		)
	},
	{
		"GUI_TABS_BAR",
		ffw::GuiStyleGroup(
			// Normal
			ffw::GuiStyle(
				ffw::GuiStyle::Background(0, ffw::rgb(0x000000), ffw::GuiStyle::Background::Type::NONE),
				ffw::GuiStyle::Border(0, 0, ffw::rgb(0x000000)),
				ffw::GuiStyle::Outline(0, 0, ffw::rgb(0x000000)),
				ffw::GuiStyle::Text(ffw::rgb(0xFFFFFF)),
				ffw::GuiStyle::Function(ffw::rgb(0xFFFFFF))
			),
			// Hover
			ffw::GuiStyle(
				ffw::GuiStyle::Background(0, ffw::rgb(0x000000), ffw::GuiStyle::Background::Type::NONE),
				ffw::GuiStyle::Border(0, 0, ffw::rgb(0x000000)),
				ffw::GuiStyle::Outline(0, 0, ffw::rgb(0x000000)),
				ffw::GuiStyle::Text(ffw::rgb(0xFFFFFF)),
				ffw::GuiStyle::Function(ffw::rgb(0xFFFFFF))
			),
			// Active
			ffw::GuiStyle(
				ffw::GuiStyle::Background(0, ffw::rgb(0x000000), ffw::GuiStyle::Background::Type::NONE),
				ffw::GuiStyle::Border(0, 0, ffw::rgb(0x000000)),
				ffw::GuiStyle::Outline(0, 0, ffw::rgb(0x000000)),
				ffw::GuiStyle::Text(ffw::rgb(0xFFFFFF)),
				ffw::GuiStyle::Function(ffw::rgb(0xFFFFFF))
			),
			// Disabled
			ffw::GuiStyle(
				ffw::GuiStyle::Background(0, ffw::rgb(0x000000), ffw::GuiStyle::Background::Type::NONE),
				ffw::GuiStyle::Border(0, 0, ffw::rgb(0x000000)),
				ffw::GuiStyle::Outline(0, 0, ffw::rgb(0x000000)),
				ffw::GuiStyle::Text(ffw::rgb(0xFFFFFF)),
				ffw::GuiStyle::Function(ffw::rgb(0xFFFFFF))
			),
			ffw::GuiDefaults(
				ffw::GuiStyle::Margin(0, 0, 0, 0),
				ffw::GuiStyle::Padding(0),
				ffw::GuiStyle::Align::TOP_LEFT,
				ffw::Vec2<GuiUnits>(ffw::guiPercent(100), ffw::guiWrap())
			)
		)
	},
	{
		"GUI_TABS_CONTENT",
		ffw::GuiStyleGroup(
			// Normal
			ffw::GuiStyle(
				ffw::GuiStyle::Background(0, ffw::rgb(0xFFFFFF), ffw::GuiStyle::Background::Type::SIMPLE),
				ffw::GuiStyle::Border(1, 0, ffw::rgb(0xADADAD)),
				ffw::GuiStyle::Outline(0, 0, ffw::rgb(0x000000)),
				ffw::GuiStyle::Text(ffw::rgb(0xFFFFFF)),
				ffw::GuiStyle::Function(ffw::rgb(0xFFFFFF))
			),
			// Hover
			ffw::GuiStyle(
				ffw::GuiStyle::Background(0, ffw::rgb(0xFFFFFF), ffw::GuiStyle::Background::Type::SIMPLE),
				ffw::GuiStyle::Border(1, 0, ffw::rgb(0xADADAD)),
				ffw::GuiStyle::Outline(0, 0, ffw::rgb(0x000000)),
				ffw::GuiStyle::Text(ffw::rgb(0xFFFFFF)),
				ffw::GuiStyle::Function(ffw::rgb(0xFFFFFF))
			),
			// Active
			ffw::GuiStyle(
				ffw::GuiStyle::Background(0, ffw::rgb(0xFFFFFF), ffw::GuiStyle::Background::Type::SIMPLE),
				ffw::GuiStyle::Border(1, 0, ffw::rgb(0xADADAD)),
				ffw::GuiStyle::Outline(0, 0, ffw::rgb(0x000000)),
				ffw::GuiStyle::Text(ffw::rgb(0xFFFFFF)),
				ffw::GuiStyle::Function(ffw::rgb(0xFFFFFF))
			),
			// Disabled
			ffw::GuiStyle(
				ffw::GuiStyle::Background(0, ffw::rgb(0xFFFFFF), ffw::GuiStyle::Background::Type::SIMPLE),
				ffw::GuiStyle::Border(1, 0, ffw::rgb(0xADADAD)),
				ffw::GuiStyle::Outline(0, 0, ffw::rgb(0x000000)),
				ffw::GuiStyle::Text(ffw::rgb(0xFFFFFF)),
				ffw::GuiStyle::Function(ffw::rgb(0xFFFFFF))
			),
			ffw::GuiDefaults(
				ffw::GuiStyle::Margin(0, 0, 0, 0),
				ffw::GuiStyle::Padding(5),
				ffw::GuiStyle::Align::TOP_LEFT,
				ffw::Vec2<GuiUnits>(ffw::guiPercent(100), ffw::guiWrap())
			)
		)
	},
	{
		"GUI_TABS_BUTTON",
		ffw::GuiStyleGroup(
			// Normal
			ffw::GuiStyle(
				ffw::GuiStyle::Background(0, ffw::rgb(0xE1E1E1), ffw::GuiStyle::Background::Type::SIMPLE),
				ffw::GuiStyle::Border(ffw::GuiStyle::Border::Size(1, 1, 0, 1), 0, ffw::rgb(0xADADAD)),
				ffw::GuiStyle::Outline(0, 0, ffw::rgb(0x000000)),
				ffw::GuiStyle::Text(ffw::rgb(0x222222)),
				ffw::GuiStyle::Function(ffw::rgb(0xFFFFFF))
			),
			// Hover
			ffw::GuiStyle(
				ffw::GuiStyle::Background(0, ffw::rgb(0xE5F1FB), ffw::GuiStyle::Background::Type::SIMPLE),
				ffw::GuiStyle::Border(ffw::GuiStyle::Border::Size(1, 1, 0, 1), 0, ffw::rgb(0xADADAD)),
				ffw::GuiStyle::Outline(0, 0, ffw::rgb(0x000000)),
				ffw::GuiStyle::Text(ffw::rgb(0x222222)),
				ffw::GuiStyle::Function(ffw::rgb(0xFFFFFF))
			),
			// Active
			ffw::GuiStyle(
				ffw::GuiStyle::Background(0, ffw::rgb(0xFFFFFF), ffw::GuiStyle::Background::Type::SIMPLE),
				ffw::GuiStyle::Border(ffw::GuiStyle::Border::Size(1, 1, 0, 1), 0, ffw::rgb(0xADADAD)),
				ffw::GuiStyle::Outline(0, 0, ffw::rgb(0x000000)),
				ffw::GuiStyle::Text(ffw::rgb(0x222222)),
				ffw::GuiStyle::Function(ffw::rgb(0xFFFFFF))
			),
			// Disabled
			ffw::GuiStyle(
				ffw::GuiStyle::Background(0, ffw::rgb(0xCACACA), ffw::GuiStyle::Background::Type::SIMPLE),
				ffw::GuiStyle::Border(ffw::GuiStyle::Border::Size(1, 1, 0, 1), 0, ffw::rgb(0xBEBEBE)),
				ffw::GuiStyle::Outline(0, 0, ffw::rgb(0x000000)),
				ffw::GuiStyle::Text(ffw::rgb(0x828282)),
				ffw::GuiStyle::Function(ffw::rgb(0xFFFFFF))
			),
			ffw::GuiDefaults(
				ffw::GuiStyle::Margin(0, 0, 0, 0),
				ffw::GuiStyle::Padding(2, 5, 2, 5),
				ffw::GuiStyle::Align::CENTER,
				ffw::Vec2<GuiUnits>(ffw::guiWrap(), ffw::guiWrap())
			)
		)
	},
	{
		"GUI_TEXT_AREA",
		ffw::GuiStyleGroup(
			// Normal
			ffw::GuiStyle(
				ffw::GuiStyle::Background(0, ffw::rgb(0xFFFFFF), ffw::GuiStyle::Background::Type::SIMPLE),
				ffw::GuiStyle::Border(1, 0, ffw::rgb(0xADADAD)),
				ffw::GuiStyle::Outline(0, 0, ffw::rgb(0x000000)),
				ffw::GuiStyle::Text(ffw::rgb(0xFFFFFF)),
				ffw::GuiStyle::Function(ffw::rgb(0xCCE4FF))
			),
			// Hover
			ffw::GuiStyle(
				ffw::GuiStyle::Background(0, ffw::rgb(0xFFFFFF), ffw::GuiStyle::Background::Type::SIMPLE),
				ffw::GuiStyle::Border(1, 0, ffw::rgb(0x0078D7)),
				ffw::GuiStyle::Outline(0, 0, ffw::rgb(0x000000)),
				ffw::GuiStyle::Text(ffw::rgb(0xFFFFFF)),
				ffw::GuiStyle::Function(ffw::rgb(0xCCE4FF))
			),
			// Active
			ffw::GuiStyle(
				ffw::GuiStyle::Background(0, ffw::rgb(0xFFFFFF), ffw::GuiStyle::Background::Type::SIMPLE),
				ffw::GuiStyle::Border(1, 0, ffw::rgb(0x005499)),
				ffw::GuiStyle::Outline(0, 0, ffw::rgb(0x000000)),
				ffw::GuiStyle::Text(ffw::rgb(0xFFFFFF)),
				ffw::GuiStyle::Function(ffw::rgb(0xCCE4FF))
			),
			// Disabled
			ffw::GuiStyle(
				ffw::GuiStyle::Background(0, ffw::rgb(0xCACACA), ffw::GuiStyle::Background::Type::SIMPLE),
				ffw::GuiStyle::Border(1, 0, ffw::rgb(0xBEBEBE)),
				ffw::GuiStyle::Outline(0, 0, ffw::rgb(0x000000)),
				ffw::GuiStyle::Text(ffw::rgb(0x828282)),
				ffw::GuiStyle::Function(ffw::rgb(0xFFFFFF))
			),
			ffw::GuiDefaults(
				ffw::GuiStyle::Margin(0, 0, 5, 0),
				ffw::GuiStyle::Padding(1),
				ffw::GuiStyle::Align::TOP_LEFT,
				ffw::Vec2<GuiUnits>(ffw::guiPercent(100), ffw::guiPixels(150))
			)
		)
	},
	{
		"GUI_TEXT_INPUT",
		ffw::GuiStyleGroup(
			// Normal
			ffw::GuiStyle(
				ffw::GuiStyle::Background(0, ffw::rgb(0xFFFFFF), ffw::GuiStyle::Background::Type::SIMPLE),
				ffw::GuiStyle::Border(1, 0, ffw::rgb(0xADADAD)),
				ffw::GuiStyle::Outline(0, 0, ffw::rgb(0x000000)),
				ffw::GuiStyle::Text(ffw::rgb(0x222222)),
				ffw::GuiStyle::Function(ffw::rgb(0xCCE4FF))
			),
			// Hover
			ffw::GuiStyle(
				ffw::GuiStyle::Background(0, ffw::rgb(0xFFFFFF), ffw::GuiStyle::Background::Type::SIMPLE),
				ffw::GuiStyle::Border(1, 0, ffw::rgb(0x0078D7)),
				ffw::GuiStyle::Outline(0, 0, ffw::rgb(0x000000)),
				ffw::GuiStyle::Text(ffw::rgb(0x222222)),
				ffw::GuiStyle::Function(ffw::rgb(0xCCE4FF))
			),
			// Active
			ffw::GuiStyle(
				ffw::GuiStyle::Background(0, ffw::rgb(0xFFFFFF), ffw::GuiStyle::Background::Type::SIMPLE),
				ffw::GuiStyle::Border(1, 0, ffw::rgb(0x005499)),
				ffw::GuiStyle::Outline(0, 0, ffw::rgb(0x000000)),
				ffw::GuiStyle::Text(ffw::rgb(0x222222)),
				ffw::GuiStyle::Function(ffw::rgb(0xCCE4FF))
			),
			// Disabled
			ffw::GuiStyle(
				ffw::GuiStyle::Background(0, ffw::rgb(0xCACACA), ffw::GuiStyle::Background::Type::SIMPLE),
				ffw::GuiStyle::Border(1, 0, ffw::rgb(0xBEBEBE)),
				ffw::GuiStyle::Outline(0, 0, ffw::rgb(0x000000)),
				ffw::GuiStyle::Text(ffw::rgb(0x828282)),
				ffw::GuiStyle::Function(ffw::rgb(0xFFFFFF))
			),
			ffw::GuiDefaults(
				ffw::GuiStyle::Margin(0, 0, 5, 0),
				ffw::GuiStyle::Padding(2),
				ffw::GuiStyle::Align::TOP_LEFT,
				ffw::Vec2<GuiUnits>(ffw::guiPercent(100), ffw::guiWrap())
			)
		)
	},
	{
		"GUI_TEXT_AREA_INNER",
		ffw::GuiStyleGroup(
			// Normal
			ffw::GuiStyle(
				ffw::GuiStyle::Background(0, ffw::rgb(0x000000), ffw::GuiStyle::Background::Type::NONE),
				ffw::GuiStyle::Border(0, 0, ffw::rgb(0x000000)),
				ffw::GuiStyle::Outline(0, 0, ffw::rgb(0x000000)),
				ffw::GuiStyle::Text(ffw::rgb(0x222222)),
				ffw::GuiStyle::Function(ffw::rgb(0xCCE4FF))
			),
			// Hover
			ffw::GuiStyle(
				ffw::GuiStyle::Background(0, ffw::rgb(0x000000), ffw::GuiStyle::Background::Type::NONE),
				ffw::GuiStyle::Border(0, 0, ffw::rgb(0x000000)),
				ffw::GuiStyle::Outline(0, 0, ffw::rgb(0x000000)),
				ffw::GuiStyle::Text(ffw::rgb(0x222222)),
				ffw::GuiStyle::Function(ffw::rgb(0xCCE4FF))
			),
			// Active
			ffw::GuiStyle(
				ffw::GuiStyle::Background(0, ffw::rgb(0x000000), ffw::GuiStyle::Background::Type::NONE),
				ffw::GuiStyle::Border(0, 0, ffw::rgb(0x000000)),
				ffw::GuiStyle::Outline(0, 0, ffw::rgb(0x000000)),
				ffw::GuiStyle::Text(ffw::rgb(0x222222)),
				ffw::GuiStyle::Function(ffw::rgb(0xCCE4FF))
			),
			// Disabled
			ffw::GuiStyle(
				ffw::GuiStyle::Background(0, ffw::rgb(0x000000), ffw::GuiStyle::Background::Type::NONE),
				ffw::GuiStyle::Border(0, 0, ffw::rgb(0x000000)),
				ffw::GuiStyle::Outline(0, 0, ffw::rgb(0x000000)),
				ffw::GuiStyle::Text(ffw::rgb(0x828282)),
				ffw::GuiStyle::Function(ffw::rgb(0xFFFFFF))
			),
			ffw::GuiDefaults(
				ffw::GuiStyle::Margin(0, 0, 0, 0),
				ffw::GuiStyle::Padding(1),
				ffw::GuiStyle::Align::TOP_LEFT,
				ffw::Vec2<GuiUnits>(ffw::guiPercent(100), ffw::guiWrap())
			)
		)
	},
	{
		"GUI_PROGRESSBAR",
		ffw::GuiStyleGroup(
			// Normal
			ffw::GuiStyle(
				ffw::GuiStyle::Background(0, ffw::rgb(0xE3E3E3), ffw::GuiStyle::Background::Type::SIMPLE),
				ffw::GuiStyle::Border(1, 0, ffw::rgb(0xC4C4C4)),
				ffw::GuiStyle::Outline(0, 0, ffw::rgb(0x000000)),
				ffw::GuiStyle::Text(ffw::rgb(0xFFFFFF)),
				ffw::GuiStyle::Function(ffw::rgb(0xFFFFFF))
			),
			// Hover
			ffw::GuiStyle(
				ffw::GuiStyle::Background(0, ffw::rgb(0xE3E3E3), ffw::GuiStyle::Background::Type::SIMPLE),
				ffw::GuiStyle::Border(1, 0, ffw::rgb(0xC4C4C4)),
				ffw::GuiStyle::Outline(0, 0, ffw::rgb(0x000000)),
				ffw::GuiStyle::Text(ffw::rgb(0xFFFFFF)),
				ffw::GuiStyle::Function(ffw::rgb(0xFFFFFF))
			),
			// Active
			ffw::GuiStyle(
				ffw::GuiStyle::Background(0, ffw::rgb(0xE3E3E3), ffw::GuiStyle::Background::Type::SIMPLE),
				ffw::GuiStyle::Border(1, 0, ffw::rgb(0xC4C4C4)),
				ffw::GuiStyle::Outline(0, 0, ffw::rgb(0x000000)),
				ffw::GuiStyle::Text(ffw::rgb(0xFFFFFF)),
				ffw::GuiStyle::Function(ffw::rgb(0xFFFFFF))
			),
			// Disabled
			ffw::GuiStyle(
				ffw::GuiStyle::Background(0, ffw::rgb(0xE3E3E3), ffw::GuiStyle::Background::Type::SIMPLE),
				ffw::GuiStyle::Border(1, 0, ffw::rgb(0xC4C4C4)),
				ffw::GuiStyle::Outline(0, 0, ffw::rgb(0x000000)),
				ffw::GuiStyle::Text(ffw::rgb(0xFFFFFF)),
				ffw::GuiStyle::Function(ffw::rgb(0xFFFFFF))
			),
			ffw::GuiDefaults(
				ffw::GuiStyle::Margin(0, 0, 5, 0),
				ffw::GuiStyle::Padding(1),
				ffw::GuiStyle::Align::TOP_LEFT,
				ffw::Vec2<GuiUnits>(ffw::guiPercent(100), ffw::guiPixels(16))
			)
		)
	},
	{
		"GUI_PROGRESSBAR_INNER",
		ffw::GuiStyleGroup(
			// Normal
			ffw::GuiStyle(
				ffw::GuiStyle::Background(0, ffw::rgb(0x00AD1E), ffw::GuiStyle::Background::Type::SIMPLE),
				ffw::GuiStyle::Border(0, 0, ffw::rgb(0x000000)),
				ffw::GuiStyle::Outline(0, 0, ffw::rgb(0x000000)),
				ffw::GuiStyle::Text(ffw::rgb(0xFFFFFF)),
				ffw::GuiStyle::Function(ffw::rgb(0xFFFFFF))
			),
			// Hover
			ffw::GuiStyle(
				ffw::GuiStyle::Background(0, ffw::rgb(0x00AD1E), ffw::GuiStyle::Background::Type::SIMPLE),
				ffw::GuiStyle::Border(0, 0, ffw::rgb(0x000000)),
				ffw::GuiStyle::Outline(0, 0, ffw::rgb(0x000000)),
				ffw::GuiStyle::Text(ffw::rgb(0xFFFFFF)),
				ffw::GuiStyle::Function(ffw::rgb(0xFFFFFF))
			),
			// Active
			ffw::GuiStyle(
				ffw::GuiStyle::Background(0, ffw::rgb(0x00AD1E), ffw::GuiStyle::Background::Type::SIMPLE),
				ffw::GuiStyle::Border(0, 0, ffw::rgb(0x000000)),
				ffw::GuiStyle::Outline(0, 0, ffw::rgb(0x000000)),
				ffw::GuiStyle::Text(ffw::rgb(0xFFFFFF)),
				ffw::GuiStyle::Function(ffw::rgb(0xFFFFFF))
			),
			// Disabled
			ffw::GuiStyle(
				ffw::GuiStyle::Background(0, ffw::rgb(0xC4C4C4), ffw::GuiStyle::Background::Type::SIMPLE),
				ffw::GuiStyle::Border(0, 0, ffw::rgb(0x000000)),
				ffw::GuiStyle::Outline(0, 0, ffw::rgb(0x000000)),
				ffw::GuiStyle::Text(ffw::rgb(0xFFFFFF)),
				ffw::GuiStyle::Function(ffw::rgb(0xFFFFFF))
			),
			ffw::GuiDefaults(
				ffw::GuiStyle::Margin(0, 0, 0, 0),
				ffw::GuiStyle::Padding(0),
				ffw::GuiStyle::Align::TOP_LEFT,
				ffw::Vec2<GuiUnits>(ffw::guiPercent(100), ffw::guiPercent(100))
			)
		)
	},
	{
		"GUI_PROGRESSCIRCLE",
		ffw::GuiStyleGroup(
			// Normal
			ffw::GuiStyle(
				ffw::GuiStyle::Background(0, ffw::rgb(0x000000), ffw::GuiStyle::Background::Type::NONE),
				ffw::GuiStyle::Border(0, 0, ffw::rgb(0x000000)),
				ffw::GuiStyle::Outline(0, 0, ffw::rgb(0x000000)),
				ffw::GuiStyle::Text(ffw::rgb(0x222222)),
				ffw::GuiStyle::Function(ffw::rgb(0x00AD1E), ffw::rgb(0xC4C4C4))
			),
			// Hover
			ffw::GuiStyle(
				ffw::GuiStyle::Background(0, ffw::rgb(0xE3E3E3), ffw::GuiStyle::Background::Type::NONE),
				ffw::GuiStyle::Border(0, 0, ffw::rgb(0x000000)),
				ffw::GuiStyle::Outline(0, 0, ffw::rgb(0x000000)),
				ffw::GuiStyle::Text(ffw::rgb(0x222222)),
				ffw::GuiStyle::Function(ffw::rgb(0x00AD1E), ffw::rgb(0xC4C4C4))
			),
			// Active
			ffw::GuiStyle(
				ffw::GuiStyle::Background(0, ffw::rgb(0xE3E3E3), ffw::GuiStyle::Background::Type::NONE),
				ffw::GuiStyle::Border(0, 0, ffw::rgb(0x000000)),
				ffw::GuiStyle::Outline(0, 0, ffw::rgb(0x000000)),
				ffw::GuiStyle::Text(ffw::rgb(0x222222)),
				ffw::GuiStyle::Function(ffw::rgb(0x00AD1E), ffw::rgb(0xC4C4C4))
			),
			// Disabled
			ffw::GuiStyle(
				ffw::GuiStyle::Background(0, ffw::rgb(0xE3E3E3), ffw::GuiStyle::Background::Type::NONE),
				ffw::GuiStyle::Border(0, 0, ffw::rgb(0x000000)),
				ffw::GuiStyle::Outline(0, 0, ffw::rgb(0x000000)),
				ffw::GuiStyle::Text(ffw::rgb(0x222222)),
				ffw::GuiStyle::Function(ffw::rgb(0xC4C4C4), ffw::rgb(0xE3E3E3))
			),
			ffw::GuiDefaults(
				ffw::GuiStyle::Margin(0, 0, 0, 0),
				ffw::GuiStyle::Padding(5),
				ffw::GuiStyle::Align::CENTER,
				ffw::Vec2<GuiUnits>(ffw::guiPercent(100), ffw::guiWrap())
			)
		)
	},
	{
		"GUI_IMAGE",
		ffw::GuiStyleGroup(
			// Normal
			ffw::GuiStyle(
				ffw::GuiStyle::Background(0, ffw::rgb(0x000000), ffw::GuiStyle::Background::Type::NONE),
				ffw::GuiStyle::Border(0, 0, ffw::rgb(0x000000)),
				ffw::GuiStyle::Outline(0, 0, ffw::rgb(0x000000)),
				ffw::GuiStyle::Text(ffw::rgb(0xFFFFFF)),
				ffw::GuiStyle::Function(ffw::rgb(0xFFFFFF))
			),
			// Hover
			ffw::GuiStyle(
				ffw::GuiStyle::Background(0, ffw::rgb(0x000000), ffw::GuiStyle::Background::Type::NONE),
				ffw::GuiStyle::Border(0, 0, ffw::rgb(0x000000)),
				ffw::GuiStyle::Outline(0, 0, ffw::rgb(0x000000)),
				ffw::GuiStyle::Text(ffw::rgb(0xFFFFFF)),
				ffw::GuiStyle::Function(ffw::rgb(0xFFFFFF))
			),
			// Active
			ffw::GuiStyle(
				ffw::GuiStyle::Background(0, ffw::rgb(0x000000), ffw::GuiStyle::Background::Type::NONE),
				ffw::GuiStyle::Border(0, 0, ffw::rgb(0x000000)),
				ffw::GuiStyle::Outline(0, 0, ffw::rgb(0x000000)),
				ffw::GuiStyle::Text(ffw::rgb(0xFFFFFF)),
				ffw::GuiStyle::Function(ffw::rgb(0xFFFFFF))
			),
			// Disabled
			ffw::GuiStyle(
				ffw::GuiStyle::Background(0, ffw::rgb(0x000000), ffw::GuiStyle::Background::Type::NONE),
				ffw::GuiStyle::Border(0, 0, ffw::rgb(0x000000)),
				ffw::GuiStyle::Outline(0, 0, ffw::rgb(0x000000)),
				ffw::GuiStyle::Text(ffw::rgb(0xFFFFFF)),
				ffw::GuiStyle::Function(ffw::rgb(0xFFFFFF))
			),
			ffw::GuiDefaults(
				ffw::GuiStyle::Margin(0, 0, 0, 0),
				ffw::GuiStyle::Padding(0),
				ffw::GuiStyle::Align::TOP_LEFT,
				ffw::Vec2<GuiUnits>(ffw::guiPercent(100), ffw::guiWrap())
			)
		)
	},
});