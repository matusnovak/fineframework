/*** This file is part of FineFramework project ***/

#include "ffw/gui/guitheme.h"

#define BACKGROUND 0x0F0F0F
#define TEXT_NORMAL 0xC8C8C8 
#define TEXT_DISABLED 0x626262
#define TEXT_PRIMARY 0x000000
#define LIST_BACKGROUND 0x000000

#define BUTTON_NORMAL 0x131313
#define BUTTON_HOVER 0x080808
#define BUTTON_FOCUS 0x262626
#define BUTTON_DISABLED 0x171717

#define BORDER_COLOR 0x666666
#define BORDER_SIZE 1
#define BORDER_RADIUS 5

#define PRIMARY_NORMAL 0xD07C27
#define PRIMARY_HOVER 0xC86A04
#define PRIMARY_FOCUS 0xDEA569
#define BORDER_PRIMARY 0x666666

#define TEXT_SELECTION 0x593613

#define BACKGROUND_DISABLED 0x353535

#define ETCHED_BACKGROUND 0x222222
#define ETCHED_BORDER 0x4A4A4A

#define BUTTON_RADIUS_LEFT ffw::GuiStyle::Attribute<int>(4, 0, 0, 4)
#define BUTTON_RADIUS_RIGHT ffw::GuiStyle::Attribute<int>(0, 4, 4, 0)
#define BUTTON_RADIUS_TOP ffw::GuiStyle::Attribute<int>(4, 4, 0, 0)
#define BUTTON_RADIUS_BOTTOM ffw::GuiStyle::Attribute<int>(0, 0, 4, 4)

#define TAB_BUTTON_BORDER ffw::GuiStyle::Attribute<int>(1, 1, 0, 1)
#define TAB_BUTTON_RADIUS ffw::GuiStyle::Attribute<int>(BORDER_RADIUS, BORDER_RADIUS, 0, 0)
#define TAB_CONTENT_RADIUS ffw::GuiStyle::Attribute<int>(0, 0, BORDER_RADIUS, BORDER_RADIUS)

///=============================================================================
const ffw::GuiTheme ffw::GuiTheme::simpleDark({
	// GUI LAYOUT
	{
		"GUI_LAYOUT",
		ffw::GuiStyleGroup(
			// Normal
			ffw::GuiStyle(
				ffw::GuiStyle::Background(0, ffw::rgb(0x000000), ffw::GuiStyle::Background::Type::NONE),
				ffw::GuiStyle::Border(0, 0, ffw::rgb(0x000000)),
				ffw::GuiStyle::Outline(0, 0, ffw::rgb(0x000000)),
				ffw::GuiStyle::Text(ffw::rgb(TEXT_NORMAL)),
				ffw::GuiStyle::Function(ffw::rgb(0xFFFFFF))
			),
			// Hover
			ffw::GuiStyle(
				ffw::GuiStyle::Background(0, ffw::rgb(0x000000), ffw::GuiStyle::Background::Type::NONE),
				ffw::GuiStyle::Border(0, 0, ffw::rgb(0x000000)),
				ffw::GuiStyle::Outline(0, 0, ffw::rgb(0x000000)),
				ffw::GuiStyle::Text(ffw::rgb(TEXT_NORMAL)),
				ffw::GuiStyle::Function(ffw::rgb(0xFFFFFF))
			),
			// Active
			ffw::GuiStyle(
				ffw::GuiStyle::Background(0, ffw::rgb(0x000000), ffw::GuiStyle::Background::Type::NONE),
				ffw::GuiStyle::Border(0, 0, ffw::rgb(0x000000)),
				ffw::GuiStyle::Outline(0, 0, ffw::rgb(0x000000)),
				ffw::GuiStyle::Text(ffw::rgb(TEXT_NORMAL)),
				ffw::GuiStyle::Function(ffw::rgb(0xFFFFFF))
			),
			// Disabled
			ffw::GuiStyle(
				ffw::GuiStyle::Background(0, ffw::rgb(0x000000), ffw::GuiStyle::Background::Type::NONE),
				ffw::GuiStyle::Border(0, 0, ffw::rgb(0x000000)),
				ffw::GuiStyle::Outline(0, 0, ffw::rgb(0x000000)),
				ffw::GuiStyle::Text(ffw::rgb(TEXT_DISABLED)),
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
				ffw::GuiStyle::Background(0, ffw::rgb(BACKGROUND), ffw::GuiStyle::Background::Type::SIMPLE),
				ffw::GuiStyle::Border(0, 0, ffw::rgb(0x000000)),
				ffw::GuiStyle::Outline(0, 0, ffw::rgb(0x000000)),
				ffw::GuiStyle::Text(ffw::rgb(TEXT_NORMAL)),
				ffw::GuiStyle::Function(ffw::rgb(0xFFFFFF))
			),
			// Hover
			ffw::GuiStyle(
				ffw::GuiStyle::Background(0, ffw::rgb(BACKGROUND), ffw::GuiStyle::Background::Type::SIMPLE),
				ffw::GuiStyle::Border(0, 0, ffw::rgb(0x000000)),
				ffw::GuiStyle::Outline(0, 0, ffw::rgb(0x000000)),
				ffw::GuiStyle::Text(ffw::rgb(TEXT_NORMAL)),
				ffw::GuiStyle::Function(ffw::rgb(0xFFFFFF))
			),
			// Active
			ffw::GuiStyle(
				ffw::GuiStyle::Background(0, ffw::rgb(BACKGROUND), ffw::GuiStyle::Background::Type::SIMPLE),
				ffw::GuiStyle::Border(0, 0, ffw::rgb(0x000000)),
				ffw::GuiStyle::Outline(0, 0, ffw::rgb(0x000000)),
				ffw::GuiStyle::Text(ffw::rgb(TEXT_NORMAL)),
				ffw::GuiStyle::Function(ffw::rgb(0xFFFFFF))
			),
			// Disabled
			ffw::GuiStyle(
				ffw::GuiStyle::Background(0, ffw::rgb(BACKGROUND), ffw::GuiStyle::Background::Type::SIMPLE),
				ffw::GuiStyle::Border(0, 0, ffw::rgb(0x000000)),
				ffw::GuiStyle::Outline(0, 0, ffw::rgb(0x000000)),
				ffw::GuiStyle::Text(ffw::rgb(TEXT_DISABLED)),
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
	// GUI LABEL
	{
		"GUI_LABEL",
		ffw::GuiStyleGroup(
			// Normal
			ffw::GuiStyle(
				ffw::GuiStyle::Background(0, ffw::rgb(0x000000), ffw::GuiStyle::Background::Type::NONE),
				ffw::GuiStyle::Border(0, 0, ffw::rgb(0x000000)),
				ffw::GuiStyle::Outline(0, 0, ffw::rgb(0x000000)),
				ffw::GuiStyle::Text(ffw::rgb(TEXT_NORMAL)),
				ffw::GuiStyle::Function(ffw::rgb(0xFFFFFF))
			),
			// Hover
			ffw::GuiStyle(
				ffw::GuiStyle::Background(0, ffw::rgb(0x000000), ffw::GuiStyle::Background::Type::NONE),
				ffw::GuiStyle::Border(0, 0, ffw::rgb(0x000000)),
				ffw::GuiStyle::Outline(0, 0, ffw::rgb(0x000000)),
				ffw::GuiStyle::Text(ffw::rgb(TEXT_NORMAL)),
				ffw::GuiStyle::Function(ffw::rgb(0xFFFFFF))
			),
			// Active
			ffw::GuiStyle(
				ffw::GuiStyle::Background(0, ffw::rgb(0x000000), ffw::GuiStyle::Background::Type::NONE),
				ffw::GuiStyle::Border(0, 0, ffw::rgb(0x000000)),
				ffw::GuiStyle::Outline(0, 0, ffw::rgb(0x000000)),
				ffw::GuiStyle::Text(ffw::rgb(TEXT_NORMAL)),
				ffw::GuiStyle::Function(ffw::rgb(0xFFFFFF))
			),
			// Disabled
			ffw::GuiStyle(
				ffw::GuiStyle::Background(0, ffw::rgb(0x000000), ffw::GuiStyle::Background::Type::NONE),
				ffw::GuiStyle::Border(0, 0, ffw::rgb(0x000000)),
				ffw::GuiStyle::Outline(0, 0, ffw::rgb(0x000000)),
				ffw::GuiStyle::Text(ffw::rgb(TEXT_DISABLED)),
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
				ffw::GuiStyle::Background(BORDER_RADIUS, ffw::rgb(BUTTON_NORMAL), ffw::GuiStyle::Background::Type::SIMPLE),
				ffw::GuiStyle::Border(BORDER_SIZE, BORDER_RADIUS, ffw::rgb(BORDER_COLOR)),
				ffw::GuiStyle::Outline(0, 0, ffw::rgb(0x000000)),
				ffw::GuiStyle::Text(ffw::rgb(TEXT_NORMAL)),
				ffw::GuiStyle::Function(ffw::rgb(0xFFFFFF))
			),
			// Hover
			ffw::GuiStyle(
				ffw::GuiStyle::Background(BORDER_RADIUS, ffw::rgb(BUTTON_HOVER), ffw::GuiStyle::Background::Type::SIMPLE),
				ffw::GuiStyle::Border(BORDER_SIZE, BORDER_RADIUS, ffw::rgb(BORDER_COLOR)),
				ffw::GuiStyle::Outline(0, 0, ffw::rgb(0x000000)),
				ffw::GuiStyle::Text(ffw::rgb(TEXT_NORMAL)),
				ffw::GuiStyle::Function(ffw::rgb(0xFFFFFF))
			),
			// Active
			ffw::GuiStyle(
				ffw::GuiStyle::Background(BORDER_RADIUS, ffw::rgb(BUTTON_FOCUS), ffw::GuiStyle::Background::Type::SIMPLE),
				ffw::GuiStyle::Border(BORDER_SIZE, BORDER_RADIUS, ffw::rgb(BORDER_COLOR)),
				ffw::GuiStyle::Outline(0, 0, ffw::rgb(0x000000)),
				ffw::GuiStyle::Text(ffw::rgb(TEXT_NORMAL)),
				ffw::GuiStyle::Function(ffw::rgb(0xFFFFFF))
			),
			// Disabled
			ffw::GuiStyle(
				ffw::GuiStyle::Background(BORDER_RADIUS, ffw::rgb(BUTTON_DISABLED), ffw::GuiStyle::Background::Type::SIMPLE),
				ffw::GuiStyle::Border(BORDER_SIZE, BORDER_RADIUS, ffw::rgb(BORDER_COLOR)),
				ffw::GuiStyle::Outline(0, 0, ffw::rgb(0x000000)),
				ffw::GuiStyle::Text(ffw::rgb(TEXT_DISABLED)),
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
				ffw::GuiStyle::Background(BORDER_RADIUS, ffw::rgb(PRIMARY_NORMAL), ffw::GuiStyle::Background::Type::SIMPLE),
				ffw::GuiStyle::Border(BORDER_SIZE, BORDER_RADIUS, ffw::rgb(BORDER_PRIMARY)),
				ffw::GuiStyle::Outline(0, 0, ffw::rgb(0x000000)),
				ffw::GuiStyle::Text(ffw::rgb(TEXT_PRIMARY)),
				ffw::GuiStyle::Function(ffw::rgb(0xFFFFFF))
			),
			// Hover
			ffw::GuiStyle(
				ffw::GuiStyle::Background(BORDER_RADIUS, ffw::rgb(PRIMARY_HOVER), ffw::GuiStyle::Background::Type::SIMPLE),
				ffw::GuiStyle::Border(BORDER_SIZE, BORDER_RADIUS, ffw::rgb(BORDER_PRIMARY)),
				ffw::GuiStyle::Outline(0, 0, ffw::rgb(0x000000)),
				ffw::GuiStyle::Text(ffw::rgb(TEXT_PRIMARY)),
				ffw::GuiStyle::Function(ffw::rgb(0xFFFFFF))
			),
			// Active
			ffw::GuiStyle(
				ffw::GuiStyle::Background(BORDER_RADIUS, ffw::rgb(PRIMARY_FOCUS), ffw::GuiStyle::Background::Type::SIMPLE),
				ffw::GuiStyle::Border(BORDER_SIZE, BORDER_RADIUS, ffw::rgb(BORDER_PRIMARY)),
				ffw::GuiStyle::Outline(0, 0, ffw::rgb(0x000000)),
				ffw::GuiStyle::Text(ffw::rgb(TEXT_PRIMARY)),
				ffw::GuiStyle::Function(ffw::rgb(0xFFFFFF))
			),
			// Disabled
			ffw::GuiStyle(
				ffw::GuiStyle::Background(BORDER_RADIUS, ffw::rgb(BUTTON_DISABLED), ffw::GuiStyle::Background::Type::SIMPLE),
				ffw::GuiStyle::Border(BORDER_SIZE, BORDER_RADIUS, ffw::rgb(BORDER_COLOR)),
				ffw::GuiStyle::Outline(0, 0, ffw::rgb(0x000000)),
				ffw::GuiStyle::Text(ffw::rgb(TEXT_DISABLED)),
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
				ffw::GuiStyle::Text(ffw::rgb(TEXT_NORMAL)),
				ffw::GuiStyle::Function(ffw::rgb(0xFFFFFF))
			),
			// Hover
			ffw::GuiStyle(
				ffw::GuiStyle::Background(0, ffw::rgb(0x000000), ffw::GuiStyle::Background::Type::NONE),
				ffw::GuiStyle::Border(0, 0, ffw::rgb(0x000000)),
				ffw::GuiStyle::Outline(0, 0, ffw::rgb(0x000000)),
				ffw::GuiStyle::Text(ffw::rgb(TEXT_NORMAL)),
				ffw::GuiStyle::Function(ffw::rgb(0xFFFFFF))
			),
			// Active
			ffw::GuiStyle(
				ffw::GuiStyle::Background(0, ffw::rgb(0x000000), ffw::GuiStyle::Background::Type::NONE),
				ffw::GuiStyle::Border(0, 0, ffw::rgb(0x000000)),
				ffw::GuiStyle::Outline(0, 0, ffw::rgb(0x000000)),
				ffw::GuiStyle::Text(ffw::rgb(TEXT_NORMAL)),
				ffw::GuiStyle::Function(ffw::rgb(0xFFFFFF))
			),
			// Disabled
			ffw::GuiStyle(
				ffw::GuiStyle::Background(0, ffw::rgb(0x000000), ffw::GuiStyle::Background::Type::NONE),
				ffw::GuiStyle::Border(0, 0, ffw::rgb(0x000000)),
				ffw::GuiStyle::Outline(0, 0, ffw::rgb(0x000000)),
				ffw::GuiStyle::Text(ffw::rgb(TEXT_DISABLED)),
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
				ffw::GuiStyle::Background(BORDER_RADIUS, ffw::rgb(0x000000), ffw::GuiStyle::Background::Type::SIMPLE),
				ffw::GuiStyle::Border(BORDER_SIZE, BORDER_RADIUS, ffw::rgb(BORDER_COLOR)),
				ffw::GuiStyle::Outline(0, 0, ffw::rgb(0x000000)),
				ffw::GuiStyle::Text(ffw::rgb(0x000000)),
				ffw::GuiStyle::Function(ffw::rgb(0x000000))
			),
			// Hover
			ffw::GuiStyle(
				ffw::GuiStyle::Background(BORDER_RADIUS, ffw::rgb(0x000000), ffw::GuiStyle::Background::Type::SIMPLE),
				ffw::GuiStyle::Border(BORDER_SIZE, BORDER_RADIUS, ffw::rgb(PRIMARY_HOVER)),
				ffw::GuiStyle::Outline(0, 0, ffw::rgb(0x000000)),
				ffw::GuiStyle::Text(ffw::rgb(0x000000)),
				ffw::GuiStyle::Function(ffw::rgb(0x000000))
			),
			// Active
			ffw::GuiStyle(
				ffw::GuiStyle::Background(BORDER_RADIUS, ffw::rgb(PRIMARY_HOVER), ffw::GuiStyle::Background::Type::SIMPLE),
				ffw::GuiStyle::Border(BORDER_SIZE, BORDER_RADIUS, ffw::rgb(BORDER_COLOR)),
				ffw::GuiStyle::Outline(0, 0, ffw::rgb(0x000000)),
				ffw::GuiStyle::Text(ffw::rgb(0x000000)),
				ffw::GuiStyle::Function(ffw::rgb(0xFFFFFF))
			),
			// Disabled
			ffw::GuiStyle(
				ffw::GuiStyle::Background(BORDER_RADIUS, ffw::rgb(BACKGROUND_DISABLED), ffw::GuiStyle::Background::Type::SIMPLE),
				ffw::GuiStyle::Border(BORDER_SIZE, BORDER_RADIUS, ffw::rgb(BORDER_COLOR)),
				ffw::GuiStyle::Outline(0, 0, ffw::rgb(0x000000)),
				ffw::GuiStyle::Text(ffw::rgb(0x000000)),
				ffw::GuiStyle::Function(ffw::rgb(BACKGROUND_DISABLED))
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
				ffw::GuiStyle::Text(ffw::rgb(TEXT_NORMAL)),
				ffw::GuiStyle::Function(ffw::rgb(0xFFFFFF))
			),
			// Hover
			ffw::GuiStyle(
				ffw::GuiStyle::Background(0, ffw::rgb(0x000000), ffw::GuiStyle::Background::Type::NONE),
				ffw::GuiStyle::Border(0, 0, ffw::rgb(0x000000)),
				ffw::GuiStyle::Outline(0, 0, ffw::rgb(0x000000)),
				ffw::GuiStyle::Text(ffw::rgb(TEXT_NORMAL)),
				ffw::GuiStyle::Function(ffw::rgb(0xFFFFFF))
			),
			// Active
			ffw::GuiStyle(
				ffw::GuiStyle::Background(0, ffw::rgb(0x000000), ffw::GuiStyle::Background::Type::NONE),
				ffw::GuiStyle::Border(0, 0, ffw::rgb(0x000000)),
				ffw::GuiStyle::Outline(0, 0, ffw::rgb(0x000000)),
				ffw::GuiStyle::Text(ffw::rgb(TEXT_NORMAL)),
				ffw::GuiStyle::Function(ffw::rgb(0xFFFFFF))
			),
			// Disabled
			ffw::GuiStyle(
				ffw::GuiStyle::Background(0, ffw::rgb(0x000000), ffw::GuiStyle::Background::Type::NONE),
				ffw::GuiStyle::Border(0, 0, ffw::rgb(0x000000)),
				ffw::GuiStyle::Outline(0, 0, ffw::rgb(0x000000)),
				ffw::GuiStyle::Text(ffw::rgb(TEXT_DISABLED)),
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
				ffw::GuiStyle::Background(8, ffw::rgb(0x000000), ffw::GuiStyle::Background::Type::SIMPLE),
				ffw::GuiStyle::Border(BORDER_SIZE, 8, ffw::rgb(BORDER_COLOR)),
				ffw::GuiStyle::Outline(0, 0, ffw::rgb(0x000000)),
				ffw::GuiStyle::Text(ffw::rgb(0x000000)),
				ffw::GuiStyle::Function(ffw::rgb(0x000000))
			),
			// Hover
			ffw::GuiStyle(
				ffw::GuiStyle::Background(8, ffw::rgb(0x000000), ffw::GuiStyle::Background::Type::SIMPLE),
				ffw::GuiStyle::Border(BORDER_SIZE, 8, ffw::rgb(PRIMARY_HOVER)),
				ffw::GuiStyle::Outline(0, 0, ffw::rgb(0x000000)),
				ffw::GuiStyle::Text(ffw::rgb(0x000000)),
				ffw::GuiStyle::Function(ffw::rgb(0x000000))
			),
			// Active
			ffw::GuiStyle(
				ffw::GuiStyle::Background(8, ffw::rgb(PRIMARY_HOVER), ffw::GuiStyle::Background::Type::SIMPLE),
				ffw::GuiStyle::Border(BORDER_SIZE, 8, ffw::rgb(BORDER_COLOR)),
				ffw::GuiStyle::Outline(0, 0, ffw::rgb(0x000000)),
				ffw::GuiStyle::Text(ffw::rgb(0x000000)),
				ffw::GuiStyle::Function(ffw::rgb(0xFFFFFF))
			),
			// Disabled
			ffw::GuiStyle(
				ffw::GuiStyle::Background(8, ffw::rgb(BACKGROUND_DISABLED), ffw::GuiStyle::Background::Type::SIMPLE),
				ffw::GuiStyle::Border(BORDER_SIZE, 8, ffw::rgb(BORDER_COLOR)),
				ffw::GuiStyle::Outline(0, 0, ffw::rgb(0x000000)),
				ffw::GuiStyle::Text(ffw::rgb(0x000000)),
				ffw::GuiStyle::Function(ffw::rgb(BACKGROUND_DISABLED))
			),
			ffw::GuiDefaults(
				ffw::GuiStyle::Margin(0, 5, 0, 0),
				ffw::GuiStyle::Padding(guiPercent(30)),
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
				ffw::GuiStyle::Background(2, ffw::rgb(ETCHED_BACKGROUND), ffw::GuiStyle::Background::Type::SIMPLE),
				ffw::GuiStyle::Border(1, 2, ffw::rgb(ETCHED_BORDER)),
				ffw::GuiStyle::Outline(0, 0, ffw::rgb(0x000000)),
				ffw::GuiStyle::Text(ffw::rgb(0xFFFFFF)),
				ffw::GuiStyle::Function(ffw::rgb(PRIMARY_HOVER))
			),
			// Hover
			ffw::GuiStyle(
				ffw::GuiStyle::Background(2, ffw::rgb(ETCHED_BACKGROUND), ffw::GuiStyle::Background::Type::SIMPLE),
				ffw::GuiStyle::Border(1, 2, ffw::rgb(ETCHED_BORDER)),
				ffw::GuiStyle::Outline(0, 0, ffw::rgb(0x000000)),
				ffw::GuiStyle::Text(ffw::rgb(0xFFFFFF)),
				ffw::GuiStyle::Function(ffw::rgb(PRIMARY_HOVER))
			),
			// Active
			ffw::GuiStyle(
				ffw::GuiStyle::Background(2, ffw::rgb(ETCHED_BACKGROUND), ffw::GuiStyle::Background::Type::SIMPLE),
				ffw::GuiStyle::Border(1, 2, ffw::rgb(ETCHED_BORDER)),
				ffw::GuiStyle::Outline(0, 0, ffw::rgb(0x000000)),
				ffw::GuiStyle::Text(ffw::rgb(0xFFFFFF)),
				ffw::GuiStyle::Function(ffw::rgb(PRIMARY_HOVER))
			),
			// Disabled
			ffw::GuiStyle(
				ffw::GuiStyle::Background(2, ffw::rgb(ETCHED_BACKGROUND), ffw::GuiStyle::Background::Type::SIMPLE),
				ffw::GuiStyle::Border(1, 2, ffw::rgb(ETCHED_BORDER)),
				ffw::GuiStyle::Outline(0, 0, ffw::rgb(0x000000)),
				ffw::GuiStyle::Text(ffw::rgb(0xFFFFFF)),
				ffw::GuiStyle::Function(ffw::rgb(TEXT_DISABLED))
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
				ffw::GuiStyle::Background(4, ffw::rgb(BUTTON_NORMAL), ffw::GuiStyle::Background::Type::SIMPLE),
				ffw::GuiStyle::Border(BORDER_SIZE, 4, ffw::rgb(BORDER_COLOR)),
				ffw::GuiStyle::Outline(0, 0, ffw::rgb(0x000000)),
				ffw::GuiStyle::Text(ffw::rgb(TEXT_NORMAL)),
				ffw::GuiStyle::Function(ffw::rgb(0xFFFFFF))
			),
			// Hover
			ffw::GuiStyle(
				ffw::GuiStyle::Background(4, ffw::rgb(BUTTON_HOVER), ffw::GuiStyle::Background::Type::SIMPLE),
				ffw::GuiStyle::Border(BORDER_SIZE, 4, ffw::rgb(BORDER_COLOR)),
				ffw::GuiStyle::Outline(0, 0, ffw::rgb(0x000000)),
				ffw::GuiStyle::Text(ffw::rgb(TEXT_NORMAL)),
				ffw::GuiStyle::Function(ffw::rgb(0xFFFFFF))
			),
			// Active
			ffw::GuiStyle(
				ffw::GuiStyle::Background(4, ffw::rgb(BUTTON_FOCUS), ffw::GuiStyle::Background::Type::SIMPLE),
				ffw::GuiStyle::Border(BORDER_SIZE, 4, ffw::rgb(BORDER_COLOR)),
				ffw::GuiStyle::Outline(0, 0, ffw::rgb(0x000000)),
				ffw::GuiStyle::Text(ffw::rgb(TEXT_NORMAL)),
				ffw::GuiStyle::Function(ffw::rgb(0xFFFFFF))
			),
			// Disabled
			ffw::GuiStyle(
				ffw::GuiStyle::Background(4, ffw::rgb(BUTTON_DISABLED), ffw::GuiStyle::Background::Type::SIMPLE),
				ffw::GuiStyle::Border(BORDER_SIZE, 4, ffw::rgb(BORDER_COLOR)),
				ffw::GuiStyle::Outline(0, 0, ffw::rgb(0x000000)),
				ffw::GuiStyle::Text(ffw::rgb(TEXT_DISABLED)),
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
				ffw::GuiStyle::Background(BUTTON_RADIUS_LEFT, ffw::rgb(BUTTON_NORMAL), ffw::GuiStyle::Background::Type::SIMPLE),
				ffw::GuiStyle::Border(BORDER_SIZE, BUTTON_RADIUS_LEFT, ffw::rgb(BORDER_COLOR)),
				ffw::GuiStyle::Outline(0, 0, ffw::rgb(0x000000)),
				ffw::GuiStyle::Text(ffw::rgb(TEXT_NORMAL)),
				ffw::GuiStyle::Function(ffw::rgb(0xFFFFFF))
			),
			// Hover
			ffw::GuiStyle(
				ffw::GuiStyle::Background(BUTTON_RADIUS_LEFT, ffw::rgb(BUTTON_HOVER), ffw::GuiStyle::Background::Type::SIMPLE),
				ffw::GuiStyle::Border(BORDER_SIZE, BUTTON_RADIUS_LEFT, ffw::rgb(BORDER_COLOR)),
				ffw::GuiStyle::Outline(0, 0, ffw::rgb(0x000000)),
				ffw::GuiStyle::Text(ffw::rgb(TEXT_NORMAL)),
				ffw::GuiStyle::Function(ffw::rgb(0xFFFFFF))
			),
			// Active
			ffw::GuiStyle(
				ffw::GuiStyle::Background(BUTTON_RADIUS_LEFT, ffw::rgb(BUTTON_FOCUS), ffw::GuiStyle::Background::Type::SIMPLE),
				ffw::GuiStyle::Border(BORDER_SIZE, BUTTON_RADIUS_LEFT, ffw::rgb(BORDER_COLOR)),
				ffw::GuiStyle::Outline(0, 0, ffw::rgb(0x000000)),
				ffw::GuiStyle::Text(ffw::rgb(TEXT_NORMAL)),
				ffw::GuiStyle::Function(ffw::rgb(0xFFFFFF))
			),
			// Disabled
			ffw::GuiStyle(
				ffw::GuiStyle::Background(BUTTON_RADIUS_LEFT, ffw::rgb(BUTTON_DISABLED), ffw::GuiStyle::Background::Type::SIMPLE),
				ffw::GuiStyle::Border(BORDER_SIZE, BUTTON_RADIUS_LEFT, ffw::rgb(BORDER_COLOR)),
				ffw::GuiStyle::Outline(0, 0, ffw::rgb(0x000000)),
				ffw::GuiStyle::Text(ffw::rgb(TEXT_DISABLED)),
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
				ffw::GuiStyle::Background(BUTTON_RADIUS_RIGHT, ffw::rgb(BUTTON_NORMAL), ffw::GuiStyle::Background::Type::SIMPLE),
				ffw::GuiStyle::Border(BORDER_SIZE, BUTTON_RADIUS_RIGHT, ffw::rgb(BORDER_COLOR)),
				ffw::GuiStyle::Outline(0, 0, ffw::rgb(0x000000)),
				ffw::GuiStyle::Text(ffw::rgb(TEXT_NORMAL)),
				ffw::GuiStyle::Function(ffw::rgb(0xFFFFFF))
			),
			// Hover
			ffw::GuiStyle(
				ffw::GuiStyle::Background(BUTTON_RADIUS_RIGHT, ffw::rgb(BUTTON_HOVER), ffw::GuiStyle::Background::Type::SIMPLE),
				ffw::GuiStyle::Border(BORDER_SIZE, BUTTON_RADIUS_RIGHT, ffw::rgb(BORDER_COLOR)),
				ffw::GuiStyle::Outline(0, 0, ffw::rgb(0x000000)),
				ffw::GuiStyle::Text(ffw::rgb(TEXT_NORMAL)),
				ffw::GuiStyle::Function(ffw::rgb(0xFFFFFF))
			),
			// Active
			ffw::GuiStyle(
				ffw::GuiStyle::Background(BUTTON_RADIUS_RIGHT, ffw::rgb(BUTTON_FOCUS), ffw::GuiStyle::Background::Type::SIMPLE),
				ffw::GuiStyle::Border(BORDER_SIZE, BUTTON_RADIUS_RIGHT, ffw::rgb(BORDER_COLOR)),
				ffw::GuiStyle::Outline(0, 0, ffw::rgb(0x000000)),
				ffw::GuiStyle::Text(ffw::rgb(TEXT_NORMAL)),
				ffw::GuiStyle::Function(ffw::rgb(0xFFFFFF))
			),
			// Disabled
			ffw::GuiStyle(
				ffw::GuiStyle::Background(BUTTON_RADIUS_RIGHT, ffw::rgb(BUTTON_DISABLED), ffw::GuiStyle::Background::Type::SIMPLE),
				ffw::GuiStyle::Border(BORDER_SIZE, BUTTON_RADIUS_RIGHT, ffw::rgb(BORDER_COLOR)),
				ffw::GuiStyle::Outline(0, 0, ffw::rgb(0x000000)),
				ffw::GuiStyle::Text(ffw::rgb(TEXT_DISABLED)),
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
				ffw::GuiStyle::Background(BUTTON_RADIUS_TOP, ffw::rgb(BUTTON_NORMAL), ffw::GuiStyle::Background::Type::SIMPLE),
				ffw::GuiStyle::Border(BORDER_SIZE, BUTTON_RADIUS_TOP, ffw::rgb(BORDER_COLOR)),
				ffw::GuiStyle::Outline(0, 0, ffw::rgb(0x000000)),
				ffw::GuiStyle::Text(ffw::rgb(TEXT_NORMAL)),
				ffw::GuiStyle::Function(ffw::rgb(0xFFFFFF))
			),
			// Hover
			ffw::GuiStyle(
				ffw::GuiStyle::Background(BUTTON_RADIUS_TOP, ffw::rgb(BUTTON_HOVER), ffw::GuiStyle::Background::Type::SIMPLE),
				ffw::GuiStyle::Border(BORDER_SIZE, BUTTON_RADIUS_TOP, ffw::rgb(BORDER_COLOR)),
				ffw::GuiStyle::Outline(0, 0, ffw::rgb(0x000000)),
				ffw::GuiStyle::Text(ffw::rgb(TEXT_NORMAL)),
				ffw::GuiStyle::Function(ffw::rgb(0xFFFFFF))
			),
			// Active
			ffw::GuiStyle(
				ffw::GuiStyle::Background(BUTTON_RADIUS_TOP, ffw::rgb(BUTTON_FOCUS), ffw::GuiStyle::Background::Type::SIMPLE),
				ffw::GuiStyle::Border(BORDER_SIZE, BUTTON_RADIUS_TOP, ffw::rgb(BORDER_COLOR)),
				ffw::GuiStyle::Outline(0, 0, ffw::rgb(0x000000)),
				ffw::GuiStyle::Text(ffw::rgb(TEXT_NORMAL)),
				ffw::GuiStyle::Function(ffw::rgb(0xFFFFFF))
			),
			// Disabled
			ffw::GuiStyle(
				ffw::GuiStyle::Background(BUTTON_RADIUS_TOP, ffw::rgb(BUTTON_DISABLED), ffw::GuiStyle::Background::Type::SIMPLE),
				ffw::GuiStyle::Border(BORDER_SIZE, BUTTON_RADIUS_TOP, ffw::rgb(BORDER_COLOR)),
				ffw::GuiStyle::Outline(0, 0, ffw::rgb(0x000000)),
				ffw::GuiStyle::Text(ffw::rgb(TEXT_DISABLED)),
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
				ffw::GuiStyle::Background(BUTTON_RADIUS_BOTTOM, ffw::rgb(BUTTON_NORMAL), ffw::GuiStyle::Background::Type::SIMPLE),
				ffw::GuiStyle::Border(BORDER_SIZE, BUTTON_RADIUS_BOTTOM, ffw::rgb(BORDER_COLOR)),
				ffw::GuiStyle::Outline(0, 0, ffw::rgb(0x000000)),
				ffw::GuiStyle::Text(ffw::rgb(TEXT_NORMAL)),
				ffw::GuiStyle::Function(ffw::rgb(0xFFFFFF))
			),
			// Hover
			ffw::GuiStyle(
				ffw::GuiStyle::Background(BUTTON_RADIUS_BOTTOM, ffw::rgb(BUTTON_HOVER), ffw::GuiStyle::Background::Type::SIMPLE),
				ffw::GuiStyle::Border(BORDER_SIZE, BUTTON_RADIUS_BOTTOM, ffw::rgb(BORDER_COLOR)),
				ffw::GuiStyle::Outline(0, 0, ffw::rgb(0x000000)),
				ffw::GuiStyle::Text(ffw::rgb(TEXT_NORMAL)),
				ffw::GuiStyle::Function(ffw::rgb(0xFFFFFF))
			),
			// Active
			ffw::GuiStyle(
				ffw::GuiStyle::Background(BUTTON_RADIUS_BOTTOM, ffw::rgb(BUTTON_FOCUS), ffw::GuiStyle::Background::Type::SIMPLE),
				ffw::GuiStyle::Border(BORDER_SIZE, BUTTON_RADIUS_BOTTOM, ffw::rgb(BORDER_COLOR)),
				ffw::GuiStyle::Outline(0, 0, ffw::rgb(0x000000)),
				ffw::GuiStyle::Text(ffw::rgb(TEXT_NORMAL)),
				ffw::GuiStyle::Function(ffw::rgb(0xFFFFFF))
			),
			// Disabled
			ffw::GuiStyle(
				ffw::GuiStyle::Background(BUTTON_RADIUS_BOTTOM, ffw::rgb(BUTTON_DISABLED), ffw::GuiStyle::Background::Type::SIMPLE),
				ffw::GuiStyle::Border(BORDER_SIZE, BUTTON_RADIUS_BOTTOM, ffw::rgb(BORDER_COLOR)),
				ffw::GuiStyle::Outline(0, 0, ffw::rgb(0x000000)),
				ffw::GuiStyle::Text(ffw::rgb(TEXT_DISABLED)),
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
			ffw::GuiStyle(
				ffw::GuiStyle::Background(0, ffw::rgb(ETCHED_BACKGROUND), ffw::GuiStyle::Background::Type::SIMPLE),
				ffw::GuiStyle::Border(1, 0, ffw::rgb(ETCHED_BORDER)),
				ffw::GuiStyle::Outline(0, 0, ffw::rgb(0x000000)),
				ffw::GuiStyle::Text(ffw::rgb(0xFFFFFF)),
				ffw::GuiStyle::Function(ffw::rgba(0xFFFFFF00))
			),
			// Hover
			ffw::GuiStyle(
				ffw::GuiStyle::Background(0, ffw::rgb(ETCHED_BACKGROUND), ffw::GuiStyle::Background::Type::SIMPLE),
				ffw::GuiStyle::Border(1, 0, ffw::rgb(ETCHED_BORDER)),
				ffw::GuiStyle::Outline(0, 0, ffw::rgb(0x000000)),
				ffw::GuiStyle::Text(ffw::rgb(0xFFFFFF)),
				ffw::GuiStyle::Function(ffw::rgba(0xFFFFFF00))
			),
			// Active
			ffw::GuiStyle(
				ffw::GuiStyle::Background(0, ffw::rgb(ETCHED_BACKGROUND), ffw::GuiStyle::Background::Type::SIMPLE),
				ffw::GuiStyle::Border(1, 0, ffw::rgb(ETCHED_BORDER)),
				ffw::GuiStyle::Outline(0, 0, ffw::rgb(0x000000)),
				ffw::GuiStyle::Text(ffw::rgb(0xFFFFFF)),
				ffw::GuiStyle::Function(ffw::rgba(0xFFFFFF00))
			),
			// Disabled
			ffw::GuiStyle(
				ffw::GuiStyle::Background(0, ffw::rgb(ETCHED_BACKGROUND), ffw::GuiStyle::Background::Type::SIMPLE),
				ffw::GuiStyle::Border(1, 0, ffw::rgb(ETCHED_BORDER)),
				ffw::GuiStyle::Outline(0, 0, ffw::rgb(0x000000)),
				ffw::GuiStyle::Text(ffw::rgb(0xFFFFFF)),
				ffw::GuiStyle::Function(ffw::rgba(0xFFFFFF00))
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
				ffw::Vec2<GuiUnits>(ffw::guiPercent(100), ffw::guiPercent(100))
			)
		)
	},
	{
		"GUI_SCROLLBAR_SLIDER_BUTTON",
		ffw::GuiStyleGroup(
			// Normal
			ffw::GuiStyle(
				ffw::GuiStyle::Background(4, ffw::rgb(BUTTON_NORMAL), ffw::GuiStyle::Background::Type::SIMPLE),
				ffw::GuiStyle::Border(BORDER_SIZE, 4, ffw::rgb(BORDER_COLOR)),
				ffw::GuiStyle::Outline(0, 0, ffw::rgb(0x000000)),
				ffw::GuiStyle::Text(ffw::rgb(0xFFFFFF)),
				ffw::GuiStyle::Function(ffw::rgba(0xFFFFFF00))
			),
			// Hover
			ffw::GuiStyle(
				ffw::GuiStyle::Background(4, ffw::rgb(BUTTON_HOVER), ffw::GuiStyle::Background::Type::SIMPLE),
				ffw::GuiStyle::Border(BORDER_SIZE, 4, ffw::rgb(BORDER_COLOR)),
				ffw::GuiStyle::Outline(0, 0, ffw::rgb(0x000000)),
				ffw::GuiStyle::Text(ffw::rgb(0xFFFFFF)),
				ffw::GuiStyle::Function(ffw::rgba(0xFFFFFF00))
			),
			// Active
			ffw::GuiStyle(
				ffw::GuiStyle::Background(4, ffw::rgb(BUTTON_FOCUS), ffw::GuiStyle::Background::Type::SIMPLE),
				ffw::GuiStyle::Border(BORDER_SIZE, 4, ffw::rgb(BORDER_COLOR)),
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
				ffw::GuiStyle::Border(BORDER_SIZE, 0, ffw::rgb(BORDER_COLOR)),
				ffw::GuiStyle::Outline(0, 0, ffw::rgb(0x000000)),
				ffw::GuiStyle::Text(ffw::rgb(0xFFFFFF)),
				ffw::GuiStyle::Function(ffw::rgb(0xFFFFFF))
			),
			// Hover
			ffw::GuiStyle(
				ffw::GuiStyle::Background(0, ffw::rgb(0x000000), ffw::GuiStyle::Background::Type::NONE),
				ffw::GuiStyle::Border(BORDER_SIZE, 0, ffw::rgb(BORDER_COLOR)),
				ffw::GuiStyle::Outline(0, 0, ffw::rgb(0x000000)),
				ffw::GuiStyle::Text(ffw::rgb(0xFFFFFF)),
				ffw::GuiStyle::Function(ffw::rgb(0xFFFFFF))
			),
			// Active
			ffw::GuiStyle(
				ffw::GuiStyle::Background(0, ffw::rgb(0x000000), ffw::GuiStyle::Background::Type::NONE),
				ffw::GuiStyle::Border(BORDER_SIZE, 0, ffw::rgb(BORDER_COLOR)),
				ffw::GuiStyle::Outline(0, 0, ffw::rgb(0x000000)),
				ffw::GuiStyle::Text(ffw::rgb(0xFFFFFF)),
				ffw::GuiStyle::Function(ffw::rgb(0xFFFFFF))
			),
			// Disabled
			ffw::GuiStyle(
				ffw::GuiStyle::Background(0, ffw::rgb(0x000000), ffw::GuiStyle::Background::Type::NONE),
				ffw::GuiStyle::Border(BORDER_SIZE, 0, ffw::rgb(BORDER_COLOR)),
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
				ffw::GuiStyle::Background(0, ffw::rgb(0x000000), ffw::GuiStyle::Background::Type::SIMPLE),
				ffw::GuiStyle::Border(BORDER_SIZE, 0, ffw::rgb(BORDER_COLOR)),
				ffw::GuiStyle::Outline(0, 0, ffw::rgb(0x000000)),
				ffw::GuiStyle::Text(ffw::rgb(0xFFFFFF)),
				ffw::GuiStyle::Function(ffw::rgb(0xFFFFFF))
			),
			// Hover
			ffw::GuiStyle(
				ffw::GuiStyle::Background(0, ffw::rgb(0x000000), ffw::GuiStyle::Background::Type::SIMPLE),
				ffw::GuiStyle::Border(BORDER_SIZE, 0, ffw::rgb(BORDER_COLOR)),
				ffw::GuiStyle::Outline(0, 0, ffw::rgb(0x000000)),
				ffw::GuiStyle::Text(ffw::rgb(0xFFFFFF)),
				ffw::GuiStyle::Function(ffw::rgb(0xFFFFFF))
			),
			// Active
			ffw::GuiStyle(
				ffw::GuiStyle::Background(0, ffw::rgb(0x000000), ffw::GuiStyle::Background::Type::SIMPLE),
				ffw::GuiStyle::Border(BORDER_SIZE, 0, ffw::rgb(BORDER_COLOR)),
				ffw::GuiStyle::Outline(0, 0, ffw::rgb(0x000000)),
				ffw::GuiStyle::Text(ffw::rgb(0xFFFFFF)),
				ffw::GuiStyle::Function(ffw::rgb(0xFFFFFF))
			),
			// Disabled
			ffw::GuiStyle(
				ffw::GuiStyle::Background(0, ffw::rgb(BACKGROUND_DISABLED), ffw::GuiStyle::Background::Type::SIMPLE),
				ffw::GuiStyle::Border(BORDER_SIZE, 0, ffw::rgb(BORDER_COLOR)),
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
				ffw::GuiStyle::Text(ffw::rgb(TEXT_NORMAL)),
				ffw::GuiStyle::Function(ffw::rgb(0xFFFFFF))
			),
			// Hover
			ffw::GuiStyle(
				ffw::GuiStyle::Background(0, ffw::rgb(TEXT_SELECTION), ffw::GuiStyle::Background::Type::SIMPLE),
				ffw::GuiStyle::Border(0, 0, ffw::rgb(0x000000)),
				ffw::GuiStyle::Outline(0, 0, ffw::rgb(0x000000)),
				ffw::GuiStyle::Text(ffw::rgb(TEXT_NORMAL)),
				ffw::GuiStyle::Function(ffw::rgb(0xFFFFFF))
			),
			// Active
			ffw::GuiStyle(
				ffw::GuiStyle::Background(0, ffw::rgb(PRIMARY_HOVER), ffw::GuiStyle::Background::Type::SIMPLE),
				ffw::GuiStyle::Border(0, 0, ffw::rgb(0x000000)),
				ffw::GuiStyle::Outline(0, 0, ffw::rgb(0x000000)),
				ffw::GuiStyle::Text(ffw::rgb(TEXT_PRIMARY)),
				ffw::GuiStyle::Function(ffw::rgb(0xFFFFFF))
			),
			// Disabled
			ffw::GuiStyle(
				ffw::GuiStyle::Background(0, ffw::rgb(0x000000), ffw::GuiStyle::Background::Type::NONE),
				ffw::GuiStyle::Border(0, 0, ffw::rgb(0x000000)),
				ffw::GuiStyle::Outline(0, 0, ffw::rgb(0x000000)),
				ffw::GuiStyle::Text(ffw::rgb(TEXT_DISABLED)),
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
				ffw::GuiStyle::Background(10, ffw::rgb(0x000000), ffw::GuiStyle::Background::Type::SIMPLE),
				ffw::GuiStyle::Border(BORDER_SIZE, 10, ffw::rgb(BORDER_COLOR)),
				ffw::GuiStyle::Outline(0, 0, ffw::rgb(0x000000)),
				ffw::GuiStyle::Text(ffw::rgb(0x000000)),
				ffw::GuiStyle::Function(ffw::rgb(0xFFFFFF))
			),
			// Hover
			ffw::GuiStyle(
				ffw::GuiStyle::Background(10, ffw::rgb(0x000000), ffw::GuiStyle::Background::Type::SIMPLE),
				ffw::GuiStyle::Border(BORDER_SIZE, 10, ffw::rgb(PRIMARY_HOVER)),
				ffw::GuiStyle::Outline(0, 0, ffw::rgb(0x000000)),
				ffw::GuiStyle::Text(ffw::rgb(0x000000)),
				ffw::GuiStyle::Function(ffw::rgb(0xFFFFFF))
			),
			// Active
			ffw::GuiStyle(
				ffw::GuiStyle::Background(10, ffw::rgb(PRIMARY_HOVER), ffw::GuiStyle::Background::Type::SIMPLE),
				ffw::GuiStyle::Border(BORDER_SIZE, 10, ffw::rgb(BORDER_COLOR)),
				ffw::GuiStyle::Outline(0, 0, ffw::rgb(0x000000)),
				ffw::GuiStyle::Text(ffw::rgb(0x000000)),
				ffw::GuiStyle::Function(ffw::rgb(0xFFFFFF))
			),
			// Disabled
			ffw::GuiStyle(
				ffw::GuiStyle::Background(10, ffw::rgb(BACKGROUND_DISABLED), ffw::GuiStyle::Background::Type::SIMPLE),
				ffw::GuiStyle::Border(BORDER_SIZE, 10, ffw::rgb(BORDER_COLOR)),
				ffw::GuiStyle::Outline(0, 0, ffw::rgb(0x000000)),
				ffw::GuiStyle::Text(ffw::rgb(0x000000)),
				ffw::GuiStyle::Function(ffw::rgb(0xFFFFFF))
			),
			ffw::GuiDefaults(
				ffw::GuiStyle::Margin(0, 0, 5, 0),
				ffw::GuiStyle::Padding(2),
				ffw::GuiStyle::Align::CENTER,
				ffw::Vec2<GuiUnits>(ffw::guiPixels(42), ffw::guiPixels(20))
			)
		)
	},
	{
		"GUI_SWITCH_BUTTON",
		ffw::GuiStyleGroup(
			// Normal
			ffw::GuiStyle(
				ffw::GuiStyle::Background(8, ffw::rgb(BUTTON_NORMAL), ffw::GuiStyle::Background::Type::SIMPLE),
				ffw::GuiStyle::Border(BORDER_SIZE, 8, ffw::rgb(BORDER_COLOR)),
				ffw::GuiStyle::Outline(0, 0, ffw::rgb(0x000000)),
				ffw::GuiStyle::Text(ffw::rgb(0x000000)),
				ffw::GuiStyle::Function(ffw::rgb(0xFFFFFF))
			),
			// Hover
			ffw::GuiStyle(
				ffw::GuiStyle::Background(8, ffw::rgb(BUTTON_HOVER), ffw::GuiStyle::Background::Type::SIMPLE),
				ffw::GuiStyle::Border(BORDER_SIZE, 8, ffw::rgb(BORDER_COLOR)),
				ffw::GuiStyle::Outline(0, 0, ffw::rgb(0x000000)),
				ffw::GuiStyle::Text(ffw::rgb(0x000000)),
				ffw::GuiStyle::Function(ffw::rgb(0xFFFFFF))
			),
			// Active
			ffw::GuiStyle(
				ffw::GuiStyle::Background(8, ffw::rgb(BUTTON_FOCUS), ffw::GuiStyle::Background::Type::SIMPLE),
				ffw::GuiStyle::Border(BORDER_SIZE, 8, ffw::rgb(BORDER_COLOR)),
				ffw::GuiStyle::Outline(0, 0, ffw::rgb(0x000000)),
				ffw::GuiStyle::Text(ffw::rgb(0x000000)),
				ffw::GuiStyle::Function(ffw::rgb(0xFFFFFF))
			),
			// Disabled
			ffw::GuiStyle(
				ffw::GuiStyle::Background(8, ffw::rgb(BUTTON_DISABLED), ffw::GuiStyle::Background::Type::SIMPLE),
				ffw::GuiStyle::Border(BORDER_SIZE, 8, ffw::rgb(BORDER_COLOR)),
				ffw::GuiStyle::Outline(0, 0, ffw::rgb(0x000000)),
				ffw::GuiStyle::Text(ffw::rgb(0x000000)),
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
				ffw::GuiStyle::Background(TAB_CONTENT_RADIUS, ffw::rgb(0x000000), ffw::GuiStyle::Background::Type::SIMPLE),
				ffw::GuiStyle::Border(BORDER_SIZE, TAB_CONTENT_RADIUS, ffw::rgb(BORDER_COLOR)),
				ffw::GuiStyle::Outline(0, 0, ffw::rgb(0x000000)),
				ffw::GuiStyle::Text(ffw::rgb(0xFFFFFF)),
				ffw::GuiStyle::Function(ffw::rgb(0xFFFFFF))
			),
			// Hover
			ffw::GuiStyle(
				ffw::GuiStyle::Background(TAB_CONTENT_RADIUS, ffw::rgb(0x000000), ffw::GuiStyle::Background::Type::SIMPLE),
				ffw::GuiStyle::Border(BORDER_SIZE, TAB_CONTENT_RADIUS, ffw::rgb(BORDER_COLOR)),
				ffw::GuiStyle::Outline(0, 0, ffw::rgb(0x000000)),
				ffw::GuiStyle::Text(ffw::rgb(0xFFFFFF)),
				ffw::GuiStyle::Function(ffw::rgb(0xFFFFFF))
			),
			// Active
			ffw::GuiStyle(
				ffw::GuiStyle::Background(TAB_CONTENT_RADIUS, ffw::rgb(0x000000), ffw::GuiStyle::Background::Type::SIMPLE),
				ffw::GuiStyle::Border(BORDER_SIZE, TAB_CONTENT_RADIUS, ffw::rgb(BORDER_COLOR)),
				ffw::GuiStyle::Outline(0, 0, ffw::rgb(0x000000)),
				ffw::GuiStyle::Text(ffw::rgb(0xFFFFFF)),
				ffw::GuiStyle::Function(ffw::rgb(0xFFFFFF))
			),
			// Disabled
			ffw::GuiStyle(
				ffw::GuiStyle::Background(TAB_CONTENT_RADIUS, ffw::rgb(0x000000), ffw::GuiStyle::Background::Type::SIMPLE),
				ffw::GuiStyle::Border(BORDER_SIZE, TAB_CONTENT_RADIUS, ffw::rgb(BORDER_COLOR)),
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
				ffw::GuiStyle::Background(TAB_BUTTON_RADIUS, ffw::rgb(BUTTON_NORMAL), ffw::GuiStyle::Background::Type::SIMPLE),
				ffw::GuiStyle::Border(TAB_BUTTON_BORDER, TAB_BUTTON_RADIUS, ffw::rgb(BORDER_COLOR)),
				ffw::GuiStyle::Outline(0, 0, ffw::rgb(0x000000)),
				ffw::GuiStyle::Text(ffw::rgb(TEXT_NORMAL)),
				ffw::GuiStyle::Function(ffw::rgb(0xFFFFFF))
			),
			// Hover
			ffw::GuiStyle(
				ffw::GuiStyle::Background(TAB_BUTTON_RADIUS, ffw::rgb(BUTTON_HOVER), ffw::GuiStyle::Background::Type::SIMPLE),
				ffw::GuiStyle::Border(TAB_BUTTON_BORDER, TAB_BUTTON_RADIUS, ffw::rgb(BORDER_COLOR)),
				ffw::GuiStyle::Outline(0, 0, ffw::rgb(0x000000)),
				ffw::GuiStyle::Text(ffw::rgb(TEXT_NORMAL)),
				ffw::GuiStyle::Function(ffw::rgb(0xFFFFFF))
			),
			// Active
			ffw::GuiStyle(
				ffw::GuiStyle::Background(TAB_BUTTON_RADIUS, ffw::rgb(BUTTON_FOCUS), ffw::GuiStyle::Background::Type::SIMPLE),
				ffw::GuiStyle::Border(TAB_BUTTON_BORDER, TAB_BUTTON_RADIUS, ffw::rgb(BORDER_COLOR)),
				ffw::GuiStyle::Outline(0, 0, ffw::rgb(0x000000)),
				ffw::GuiStyle::Text(ffw::rgb(TEXT_NORMAL)),
				ffw::GuiStyle::Function(ffw::rgb(0xFFFFFF))
			),
			// Disabled
			ffw::GuiStyle(
				ffw::GuiStyle::Background(TAB_BUTTON_RADIUS, ffw::rgb(BUTTON_DISABLED), ffw::GuiStyle::Background::Type::SIMPLE),
				ffw::GuiStyle::Border(TAB_BUTTON_BORDER, TAB_BUTTON_RADIUS, ffw::rgb(BORDER_COLOR)),
				ffw::GuiStyle::Outline(0, 0, ffw::rgb(0x000000)),
				ffw::GuiStyle::Text(ffw::rgb(TEXT_DISABLED)),
				ffw::GuiStyle::Function(ffw::rgb(0xFFFFFF))
			),
			ffw::GuiDefaults(
				ffw::GuiStyle::Margin(0, 2, 0, 0),
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
				ffw::GuiStyle::Background(0, ffw::rgb(0x000000), ffw::GuiStyle::Background::Type::SIMPLE),
				ffw::GuiStyle::Border(BORDER_SIZE, 0, ffw::rgb(BORDER_COLOR)),
				ffw::GuiStyle::Outline(0, 0, ffw::rgb(0x000000)),
				ffw::GuiStyle::Text(ffw::rgb(0xFFFFFF)),
				ffw::GuiStyle::Function(ffw::rgb(0xFFFFFF))
			),
			// Hover
			ffw::GuiStyle(
				ffw::GuiStyle::Background(0, ffw::rgb(0x000000), ffw::GuiStyle::Background::Type::SIMPLE),
				ffw::GuiStyle::Border(BORDER_SIZE, 0, ffw::rgb(BORDER_COLOR)),
				ffw::GuiStyle::Outline(0, 0, ffw::rgb(0x000000)),
				ffw::GuiStyle::Text(ffw::rgb(0xFFFFFF)),
				ffw::GuiStyle::Function(ffw::rgb(0xFFFFFF))
			),
			// Active
			ffw::GuiStyle(
				ffw::GuiStyle::Background(0, ffw::rgb(0x000000), ffw::GuiStyle::Background::Type::SIMPLE),
				ffw::GuiStyle::Border(BORDER_SIZE, 0, ffw::rgb(BORDER_COLOR)),
				ffw::GuiStyle::Outline(0, 0, ffw::rgb(0x000000)),
				ffw::GuiStyle::Text(ffw::rgb(0xFFFFFF)),
				ffw::GuiStyle::Function(ffw::rgb(0xFFFFFF))
			),
			// Disabled
			ffw::GuiStyle(
				ffw::GuiStyle::Background(0, ffw::rgb(BACKGROUND_DISABLED), ffw::GuiStyle::Background::Type::SIMPLE),
				ffw::GuiStyle::Border(BORDER_SIZE, 0, ffw::rgb(BORDER_COLOR)),
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
		"GUI_TEXT_INPUT",
		ffw::GuiStyleGroup(
			// Normal
			ffw::GuiStyle(
				ffw::GuiStyle::Background(BORDER_RADIUS, ffw::rgb(0x000000), ffw::GuiStyle::Background::Type::SIMPLE),
				ffw::GuiStyle::Border(BORDER_SIZE, BORDER_RADIUS, ffw::rgb(BORDER_COLOR)),
				ffw::GuiStyle::Outline(0, 0, ffw::rgb(0x000000)),
				ffw::GuiStyle::Text(ffw::rgb(TEXT_NORMAL)),
				ffw::GuiStyle::Function(ffw::rgb(TEXT_SELECTION))
			),
			// Hover
			ffw::GuiStyle(
				ffw::GuiStyle::Background(BORDER_RADIUS, ffw::rgb(0x000000), ffw::GuiStyle::Background::Type::SIMPLE),
				ffw::GuiStyle::Border(BORDER_SIZE, BORDER_RADIUS, ffw::rgb(PRIMARY_HOVER)),
				ffw::GuiStyle::Outline(0, 0, ffw::rgb(0x000000)),
				ffw::GuiStyle::Text(ffw::rgb(TEXT_NORMAL)),
				ffw::GuiStyle::Function(ffw::rgb(TEXT_SELECTION))
			),
			// Active
			ffw::GuiStyle(
				ffw::GuiStyle::Background(BORDER_RADIUS, ffw::rgb(0x000000), ffw::GuiStyle::Background::Type::SIMPLE),
				ffw::GuiStyle::Border(BORDER_SIZE, BORDER_RADIUS, ffw::rgb(PRIMARY_FOCUS)),
				ffw::GuiStyle::Outline(0, 0, ffw::rgb(0x000000)),
				ffw::GuiStyle::Text(ffw::rgb(TEXT_NORMAL)),
				ffw::GuiStyle::Function(ffw::rgb(TEXT_SELECTION))
			),
			// Disabled
			ffw::GuiStyle(
				ffw::GuiStyle::Background(BORDER_RADIUS, ffw::rgb(BACKGROUND_DISABLED), ffw::GuiStyle::Background::Type::SIMPLE),
				ffw::GuiStyle::Border(BORDER_SIZE, BORDER_RADIUS, ffw::rgb(BORDER_COLOR)),
				ffw::GuiStyle::Outline(0, 0, ffw::rgb(0x000000)),
				ffw::GuiStyle::Text(ffw::rgb(TEXT_DISABLED)),
				ffw::GuiStyle::Function(ffw::rgb(TEXT_SELECTION))
			),
			ffw::GuiDefaults(
				ffw::GuiStyle::Margin(0, 0, 5, 0),
				ffw::GuiStyle::Padding(3),
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
				ffw::GuiStyle::Text(ffw::rgb(TEXT_NORMAL)),
				ffw::GuiStyle::Function(ffw::rgb(TEXT_SELECTION))
			),
			// Hover
			ffw::GuiStyle(
				ffw::GuiStyle::Background(0, ffw::rgb(0x000000), ffw::GuiStyle::Background::Type::NONE),
				ffw::GuiStyle::Border(0, 0, ffw::rgb(0x000000)),
				ffw::GuiStyle::Outline(0, 0, ffw::rgb(0x000000)),
				ffw::GuiStyle::Text(ffw::rgb(TEXT_NORMAL)),
				ffw::GuiStyle::Function(ffw::rgb(TEXT_SELECTION))
			),
			// Active
			ffw::GuiStyle(
				ffw::GuiStyle::Background(0, ffw::rgb(0x000000), ffw::GuiStyle::Background::Type::NONE),
				ffw::GuiStyle::Border(0, 0, ffw::rgb(0x000000)),
				ffw::GuiStyle::Outline(0, 0, ffw::rgb(0x000000)),
				ffw::GuiStyle::Text(ffw::rgb(TEXT_NORMAL)),
				ffw::GuiStyle::Function(ffw::rgb(TEXT_SELECTION))
			),
			// Disabled
			ffw::GuiStyle(
				ffw::GuiStyle::Background(0, ffw::rgb(0x000000), ffw::GuiStyle::Background::Type::NONE),
				ffw::GuiStyle::Border(0, 0, ffw::rgb(0x000000)),
				ffw::GuiStyle::Outline(0, 0, ffw::rgb(0x000000)),
				ffw::GuiStyle::Text(ffw::rgb(TEXT_DISABLED)),
				ffw::GuiStyle::Function(ffw::rgb(TEXT_SELECTION))
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
				ffw::GuiStyle::Background(BORDER_RADIUS, ffw::rgb(ETCHED_BACKGROUND), ffw::GuiStyle::Background::Type::SIMPLE),
				ffw::GuiStyle::Border(BORDER_SIZE, BORDER_RADIUS, ffw::rgb(ETCHED_BORDER)),
				ffw::GuiStyle::Outline(0, 0, ffw::rgb(0x000000)),
				ffw::GuiStyle::Text(ffw::rgb(0xFFFFFF)),
				ffw::GuiStyle::Function(ffw::rgb(0xFFFFFF))
			),
			// Hover
			ffw::GuiStyle(
				ffw::GuiStyle::Background(BORDER_RADIUS, ffw::rgb(ETCHED_BACKGROUND), ffw::GuiStyle::Background::Type::SIMPLE),
				ffw::GuiStyle::Border(BORDER_SIZE, BORDER_RADIUS, ffw::rgb(ETCHED_BORDER)),
				ffw::GuiStyle::Outline(0, 0, ffw::rgb(0x000000)),
				ffw::GuiStyle::Text(ffw::rgb(0xFFFFFF)),
				ffw::GuiStyle::Function(ffw::rgb(0xFFFFFF))
			),
			// Active
			ffw::GuiStyle(
				ffw::GuiStyle::Background(BORDER_RADIUS, ffw::rgb(ETCHED_BACKGROUND), ffw::GuiStyle::Background::Type::SIMPLE),
				ffw::GuiStyle::Border(BORDER_SIZE, BORDER_RADIUS, ffw::rgb(ETCHED_BORDER)),
				ffw::GuiStyle::Outline(0, 0, ffw::rgb(0x000000)),
				ffw::GuiStyle::Text(ffw::rgb(0xFFFFFF)),
				ffw::GuiStyle::Function(ffw::rgb(0xFFFFFF))
			),
			// Disabled
			ffw::GuiStyle(
				ffw::GuiStyle::Background(BORDER_RADIUS, ffw::rgb(ETCHED_BACKGROUND), ffw::GuiStyle::Background::Type::SIMPLE),
				ffw::GuiStyle::Border(BORDER_SIZE, BORDER_RADIUS, ffw::rgb(ETCHED_BORDER)),
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
				ffw::GuiStyle::Background(BORDER_RADIUS, ffw::rgb(PRIMARY_HOVER), ffw::GuiStyle::Background::Type::SIMPLE),
				ffw::GuiStyle::Border(0, 0, ffw::rgb(0x000000)),
				ffw::GuiStyle::Outline(0, 0, ffw::rgb(0x000000)),
				ffw::GuiStyle::Text(ffw::rgb(0xFFFFFF)),
				ffw::GuiStyle::Function(ffw::rgb(0xFFFFFF))
			),
			// Hover
			ffw::GuiStyle(
				ffw::GuiStyle::Background(BORDER_RADIUS, ffw::rgb(PRIMARY_HOVER), ffw::GuiStyle::Background::Type::SIMPLE),
				ffw::GuiStyle::Border(0, 0, ffw::rgb(0x000000)),
				ffw::GuiStyle::Outline(0, 0, ffw::rgb(0x000000)),
				ffw::GuiStyle::Text(ffw::rgb(0xFFFFFF)),
				ffw::GuiStyle::Function(ffw::rgb(0xFFFFFF))
			),
			// Active
			ffw::GuiStyle(
				ffw::GuiStyle::Background(BORDER_RADIUS, ffw::rgb(PRIMARY_HOVER), ffw::GuiStyle::Background::Type::SIMPLE),
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
				ffw::GuiStyle::Text(ffw::rgb(TEXT_NORMAL)),
				ffw::GuiStyle::Function(ffw::rgb(PRIMARY_HOVER), ffw::rgb(0x3B3B3B))
			),
			// Hover
			ffw::GuiStyle(
				ffw::GuiStyle::Background(0, ffw::rgb(0x000000), ffw::GuiStyle::Background::Type::NONE),
				ffw::GuiStyle::Border(0, 0, ffw::rgb(0x000000)),
				ffw::GuiStyle::Outline(0, 0, ffw::rgb(0x000000)),
				ffw::GuiStyle::Text(ffw::rgb(TEXT_NORMAL)),
				ffw::GuiStyle::Function(ffw::rgb(PRIMARY_HOVER), ffw::rgb(0x3B3B3B))
			),
			// Active
			ffw::GuiStyle(
				ffw::GuiStyle::Background(0, ffw::rgb(0x000000), ffw::GuiStyle::Background::Type::NONE),
				ffw::GuiStyle::Border(0, 0, ffw::rgb(0x000000)),
				ffw::GuiStyle::Outline(0, 0, ffw::rgb(0x000000)),
				ffw::GuiStyle::Text(ffw::rgb(TEXT_NORMAL)),
				ffw::GuiStyle::Function(ffw::rgb(PRIMARY_HOVER), ffw::rgb(0x3B3B3B))
			),
			// Disabled
			ffw::GuiStyle(
				ffw::GuiStyle::Background(0, ffw::rgb(0x000000), ffw::GuiStyle::Background::Type::NONE),
				ffw::GuiStyle::Border(0, 0, ffw::rgb(0x000000)),
				ffw::GuiStyle::Outline(0, 0, ffw::rgb(0x000000)),
				ffw::GuiStyle::Text(ffw::rgb(TEXT_DISABLED)),
				ffw::GuiStyle::Function(ffw::rgb(0x3B3B3B), ffw::rgb(0x1C1C1C))
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