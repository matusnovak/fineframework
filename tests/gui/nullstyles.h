#include <ffw/gui.h>

static const ffw::GuiTheme NullTheme({
	{
		"GUI_LAYOUT",
		ffw::GuiStyleGroup(
			ffw::GuiStyle(),
			ffw::GuiStyle(),
			ffw::GuiStyle(),
			ffw::GuiStyle(),
			ffw::GuiDefaults(
				ffw::GuiStyle::Margin(0, 0, 0, 0),
				ffw::GuiStyle::Padding(0),
				ffw::GuiStyle::Align::TOP_LEFT,
				ffw::Vec2<ffw::GuiUnits>(ffw::guiPercent(100), ffw::guiWrap())
			)
		)
	},
	// GUI WINDOW BODY
	{
		"GUI_WINDOW_BODY",
		ffw::GuiStyleGroup(
			ffw::GuiStyle(),
			ffw::GuiStyle(),
			ffw::GuiStyle(),
			ffw::GuiStyle(),
			ffw::GuiDefaults(
				ffw::GuiStyle::Margin(0, 0, 0, 0),
				ffw::GuiStyle::Padding(0),
				ffw::GuiStyle::Align::TOP_LEFT,
				ffw::Vec2<ffw::GuiUnits>(ffw::guiPercent(100), ffw::guiPercent(100))
			)
		)
	},
	// GUI LABEL
	{
		"GUI_LABEL",
		ffw::GuiStyleGroup(
			ffw::GuiStyle(),
			ffw::GuiStyle(),
			ffw::GuiStyle(),
			ffw::GuiStyle(),
			ffw::GuiDefaults(
				ffw::GuiStyle::Margin(0, 0, 0, 0),
				ffw::GuiStyle::Padding(0, 0, 0, 0),
				ffw::GuiStyle::Align::TOP_LEFT,
				ffw::Vec2<ffw::GuiUnits>(ffw::guiPercent(100), ffw::guiWrap())
			)
		)
	},
	// GUI BUTTON
	{
		"GUI_BUTTON",
		ffw::GuiStyleGroup(
			ffw::GuiStyle(),
			ffw::GuiStyle(),
			ffw::GuiStyle(),
			ffw::GuiStyle(),
			ffw::GuiDefaults(
				ffw::GuiStyle::Margin(0, 0, 0, 0),
				ffw::GuiStyle::Padding(0),
				ffw::GuiStyle::Align::CENTER,
				ffw::Vec2<ffw::GuiUnits>(ffw::guiPercent(100), ffw::guiWrap())
			)
		)
	},
	{
		"GUI_BUTTON_PRIMARY",
		ffw::GuiStyleGroup(
			ffw::GuiStyle(),
			ffw::GuiStyle(),
			ffw::GuiStyle(),
			ffw::GuiStyle(),
			ffw::GuiDefaults(
				ffw::GuiStyle::Margin(0, 0, 0, 0),
				ffw::GuiStyle::Padding(0),
				ffw::GuiStyle::Align::CENTER,
				ffw::Vec2<ffw::GuiUnits>(ffw::guiPercent(100), ffw::guiWrap())
			)
		)
	},
	// GUI CHECKBOX
	{
		"GUI_CHECKBOX",
		ffw::GuiStyleGroup(
			ffw::GuiStyle(),
			ffw::GuiStyle(),
			ffw::GuiStyle(),
			ffw::GuiStyle(),
			ffw::GuiDefaults(
				ffw::GuiStyle::Margin(0, 0, 0, 0),
				ffw::GuiStyle::Padding(0),
				ffw::GuiStyle::Align::TOP_LEFT,
				ffw::Vec2<ffw::GuiUnits>(ffw::guiPercent(100), ffw::guiWrap())
			)
		)
	},
	// GUI CHECKBOX BUTTON
	{
		"GUI_CHECKBOX_BUTTON",
		ffw::GuiStyleGroup(
			ffw::GuiStyle(),
			ffw::GuiStyle(),
			ffw::GuiStyle(),
			ffw::GuiStyle(),
			ffw::GuiDefaults(
				ffw::GuiStyle::Margin(0, 0, 0, 0),
				ffw::GuiStyle::Padding(ffw::guiPercent(20)),
				ffw::GuiStyle::Align::CENTER,
				ffw::Vec2<ffw::GuiUnits>(ffw::guiPixels(16), ffw::guiPixels(16))
			)
		)
	},
	// GUI RADIO
	{
		"GUI_RADIO",
		ffw::GuiStyleGroup(
			ffw::GuiStyle(),
			ffw::GuiStyle(),
			ffw::GuiStyle(),
			ffw::GuiStyle(),
			ffw::GuiDefaults(
				ffw::GuiStyle::Margin(0, 0, 0, 0),
				ffw::GuiStyle::Padding(0),
				ffw::GuiStyle::Align::TOP_LEFT,
				ffw::Vec2<ffw::GuiUnits>(ffw::guiPercent(100), ffw::guiWrap())
			)
		)
	},
	// GUI RADIO BUTTON
	{
		"GUI_RADIO_BUTTON",
		ffw::GuiStyleGroup(
			ffw::GuiStyle(),
			ffw::GuiStyle(),
			ffw::GuiStyle(),
			ffw::GuiStyle(),
			ffw::GuiDefaults(
				ffw::GuiStyle::Margin(0, 0, 0, 0),
				ffw::GuiStyle::Padding(ffw::guiPercent(20)),
				ffw::GuiStyle::Align::CENTER,
				ffw::Vec2<ffw::GuiUnits>(ffw::guiPixels(16), ffw::guiPixels(16))
			)
		)
	},
	// GUI SLIDER
	{
		"GUI_SLIDER",
		ffw::GuiStyleGroup(
			ffw::GuiStyle(),
			ffw::GuiStyle(),
			ffw::GuiStyle(),
			ffw::GuiStyle(),
			ffw::GuiDefaults(
				ffw::GuiStyle::Margin(0, 0, 0, 0),
				ffw::GuiStyle::Padding(0),
				ffw::GuiStyle::Align::TOP_LEFT,
				ffw::Vec2<ffw::GuiUnits>(ffw::guiPercent(100), ffw::guiWrap())
			)
		)
	},
	// GUI SLIDER
	{
		"GUI_SLIDER_BAR",
		ffw::GuiStyleGroup(
			ffw::GuiStyle(),
			ffw::GuiStyle(),
			ffw::GuiStyle(),
			ffw::GuiStyle(),
			ffw::GuiDefaults(
				ffw::GuiStyle::Margin(0, 0, 0, 0),
				ffw::GuiStyle::Padding(0),
				ffw::GuiStyle::Align::TOP_LEFT,
				ffw::Vec2<ffw::GuiUnits>(ffw::guiPercent(100), ffw::guiPixels(4))
			)
		)
	},
	// GUI SLIDER BUTTON
	{
		"GUI_SLIDER_BUTTON",
		ffw::GuiStyleGroup(
			ffw::GuiStyle(),
			ffw::GuiStyle(),
			ffw::GuiStyle(),
			ffw::GuiStyle(),
			ffw::GuiDefaults(
				ffw::GuiStyle::Margin(0, 0, 0, 0),
				ffw::GuiStyle::Padding(0),
				ffw::GuiStyle::Align::TOP_LEFT,
				ffw::Vec2<ffw::GuiUnits>(ffw::guiPixels(8), ffw::guiPixels(16))
			)
		)
	},
	{
		"GUI_SCROLLBAR",
		ffw::GuiStyleGroup(
			ffw::GuiStyle(),
			ffw::GuiStyle(),
			ffw::GuiStyle(),
			ffw::GuiStyle(),
			ffw::GuiDefaults(
				ffw::GuiStyle::Margin(0, 0, 0, 0),
				ffw::GuiStyle::Padding(0),
				ffw::GuiStyle::Align::TOP_LEFT,
				ffw::Vec2<ffw::GuiUnits>(ffw::guiPercent(100), ffw::guiWrap())
			)
		)
	},
	{
		"GUI_SCROLLBAR_BUTTON_LEFT",
		ffw::GuiStyleGroup(
			ffw::GuiStyle(),
			ffw::GuiStyle(),
			ffw::GuiStyle(),
			ffw::GuiStyle()
		)
	},
	{
		"GUI_SCROLLBAR_BUTTON_RIGHT",
		ffw::GuiStyleGroup(
			ffw::GuiStyle(),
			ffw::GuiStyle(),
			ffw::GuiStyle(),
			ffw::GuiStyle()
		)
	},
	{
		"GUI_SCROLLBAR_BUTTON_TOP",
		ffw::GuiStyleGroup(
			ffw::GuiStyle(),
			ffw::GuiStyle(),
			ffw::GuiStyle(),
			ffw::GuiStyle()
		)
	},
	{
		"GUI_SCROLLBAR_BUTTON_BOTTOM",
		ffw::GuiStyleGroup(
			ffw::GuiStyle(),
			ffw::GuiStyle(),
			ffw::GuiStyle(),
			ffw::GuiStyle()
		)
	},
	{
		"GUI_SCROLLBAR_SLIDER",
		ffw::GuiStyleGroup(
			ffw::GuiStyle(),
			ffw::GuiStyle(),
			ffw::GuiStyle(),
			ffw::GuiStyle()
		)
	},
	{
		"GUI_SCROLLBAR_SLIDER_BAR",
		ffw::GuiStyleGroup(
			ffw::GuiStyle(),
			ffw::GuiStyle(),
			ffw::GuiStyle(),
			ffw::GuiStyle(),
			ffw::GuiDefaults(
				ffw::GuiStyle::Margin(0, 0, 0, 0),
				ffw::GuiStyle::Padding(0),
				ffw::GuiStyle::Align::TOP_LEFT,
				ffw::Vec2<ffw::GuiUnits>(ffw::guiPercent(100), ffw::guiPercent(100))
			)
		)
	},
	{
		"GUI_SCROLLBAR_SLIDER_BUTTON",
		ffw::GuiStyleGroup(
			ffw::GuiStyle(),
			ffw::GuiStyle(),
			ffw::GuiStyle(),
			ffw::GuiStyle(),
			ffw::GuiDefaults(
				ffw::GuiStyle::Margin(0, 0, 0, 0),
				ffw::GuiStyle::Padding(0),
				ffw::GuiStyle::Align::TOP_LEFT,
				ffw::Vec2<ffw::GuiUnits>(ffw::guiPercent(25), ffw::guiPixels(12))
			)
		)
	},
	{
		"GUI_SCROLLABLE",
		ffw::GuiStyleGroup(
			ffw::GuiStyle(),
			ffw::GuiStyle(),
			ffw::GuiStyle(),
			ffw::GuiStyle(),
			ffw::GuiDefaults(
				ffw::GuiStyle::Margin(0, 0, 0, 0),
				ffw::GuiStyle::Padding(0),
				ffw::GuiStyle::Align::TOP_LEFT,
				ffw::Vec2<ffw::GuiUnits>(ffw::guiPercent(100), ffw::guiWrap())
			)
		)
	},
	{
		"GUI_LIST",
		ffw::GuiStyleGroup(
			ffw::GuiStyle(),
			ffw::GuiStyle(),
			ffw::GuiStyle(),
			ffw::GuiStyle(),
			ffw::GuiDefaults(
				ffw::GuiStyle::Margin(0, 0, 0, 0),
				ffw::GuiStyle::Padding(0),
				ffw::GuiStyle::Align::TOP_LEFT,
				ffw::Vec2<ffw::GuiUnits>(ffw::guiPercent(100), ffw::guiWrap())
			)
		)
	},
	{
		"GUI_LIST_ITEM",
		ffw::GuiStyleGroup(
			ffw::GuiStyle(),
			ffw::GuiStyle(),
			ffw::GuiStyle(),
			ffw::GuiStyle(),
			ffw::GuiDefaults(
				ffw::GuiStyle::Margin(0, 0, 0, 0),
				ffw::GuiStyle::Padding(0, 0, 0, 0),
				ffw::GuiStyle::Align::TOP_LEFT,
				ffw::Vec2<ffw::GuiUnits>(ffw::guiPercent(100), ffw::guiWrap())
			)
		)
	},
	{
		"GUI_SWITCH",
		ffw::GuiStyleGroup(
			ffw::GuiStyle(),
			ffw::GuiStyle(),
			ffw::GuiStyle(),
			ffw::GuiStyle(),
			ffw::GuiDefaults(
				ffw::GuiStyle::Margin(0, 0, 5, 0),
				ffw::GuiStyle::Padding(0),
				ffw::GuiStyle::Align::CENTER,
				ffw::Vec2<ffw::GuiUnits>(ffw::guiPixels(32), ffw::guiPixels(16))
			)
		)
	},
	{
		"GUI_SWITCH_BUTTON",
		ffw::GuiStyleGroup(
			ffw::GuiStyle(),
			ffw::GuiStyle(),
			ffw::GuiStyle(),
			ffw::GuiStyle()
		)
	},
	{
		"GUI_TABS",
		ffw::GuiStyleGroup(
			ffw::GuiStyle(),
			ffw::GuiStyle(),
			ffw::GuiStyle(),
			ffw::GuiStyle(),
			ffw::GuiDefaults(
				ffw::GuiStyle::Margin(0, 0, 0, 0),
				ffw::GuiStyle::Padding(0),
				ffw::GuiStyle::Align::TOP_LEFT,
				ffw::Vec2<ffw::GuiUnits>(ffw::guiPercent(100), ffw::guiWrap())
			)
		)
	},
	{
		"GUI_TABS_BAR",
		ffw::GuiStyleGroup(
			ffw::GuiStyle(),
			ffw::GuiStyle(),
			ffw::GuiStyle(),
			ffw::GuiStyle(),
			ffw::GuiDefaults(
				ffw::GuiStyle::Margin(0, 0, 0, 0),
				ffw::GuiStyle::Padding(0),
				ffw::GuiStyle::Align::TOP_LEFT,
				ffw::Vec2<ffw::GuiUnits>(ffw::guiPercent(100), ffw::guiWrap())
			)
		)
	},
	{
		"GUI_TABS_CONTENT",
		ffw::GuiStyleGroup(
			ffw::GuiStyle(),
			ffw::GuiStyle(),
			ffw::GuiStyle(),
			ffw::GuiStyle(),
			ffw::GuiDefaults(
				ffw::GuiStyle::Margin(0, 0, 0, 0),
				ffw::GuiStyle::Padding(0),
				ffw::GuiStyle::Align::TOP_LEFT,
				ffw::Vec2<ffw::GuiUnits>(ffw::guiPercent(100), ffw::guiWrap())
			)
		)
	},
	{
		"GUI_TABS_BUTTON",
		ffw::GuiStyleGroup(
			ffw::GuiStyle(),
			ffw::GuiStyle(),
			ffw::GuiStyle(),
			ffw::GuiStyle(),
			ffw::GuiDefaults(
				ffw::GuiStyle::Margin(0, 0, 0, 0),
				ffw::GuiStyle::Padding(0),
				ffw::GuiStyle::Align::CENTER,
				ffw::Vec2<ffw::GuiUnits>(ffw::guiWrap(), ffw::guiWrap())
			)
		)
	},
	{
		"GUI_TEXT_AREA",
		ffw::GuiStyleGroup(
			ffw::GuiStyle(),
			ffw::GuiStyle(),
			ffw::GuiStyle(),
			ffw::GuiStyle(),
			ffw::GuiDefaults(
				ffw::GuiStyle::Margin(0, 0, 0, 0),
				ffw::GuiStyle::Padding(0),
				ffw::GuiStyle::Align::TOP_LEFT,
				ffw::Vec2<ffw::GuiUnits>(ffw::guiPercent(100), ffw::guiWrap())
			)
		)
	},
	{
		"GUI_TEXT_INPUT",
		ffw::GuiStyleGroup(
			ffw::GuiStyle(),
			ffw::GuiStyle(),
			ffw::GuiStyle(),
			ffw::GuiStyle(),
			ffw::GuiDefaults(
				ffw::GuiStyle::Margin(0, 0, 0, 0),
				ffw::GuiStyle::Padding(0),
				ffw::GuiStyle::Align::TOP_LEFT,
				ffw::Vec2<ffw::GuiUnits>(ffw::guiPercent(100), ffw::guiWrap())
			)
		)
	},
	{
		"GUI_TEXT_AREA_INNER",
		ffw::GuiStyleGroup(
			ffw::GuiStyle(),
			ffw::GuiStyle(),
			ffw::GuiStyle(),
			ffw::GuiStyle(),
			ffw::GuiDefaults(
				ffw::GuiStyle::Margin(0, 0, 0, 0),
				ffw::GuiStyle::Padding(0),
				ffw::GuiStyle::Align::TOP_LEFT,
				ffw::Vec2<ffw::GuiUnits>(ffw::guiPercent(100), ffw::guiWrap())
			)
		)
	},
	{
		"GUI_PROGRESSBAR",
		ffw::GuiStyleGroup(
			ffw::GuiStyle(),
			ffw::GuiStyle(),
			ffw::GuiStyle(),
			ffw::GuiStyle(),
			ffw::GuiDefaults(
				ffw::GuiStyle::Margin(0, 0, 0, 0),
				ffw::GuiStyle::Padding(0),
				ffw::GuiStyle::Align::TOP_LEFT,
				ffw::Vec2<ffw::GuiUnits>(ffw::guiPercent(100), ffw::guiPixels(16))
			)
		)
	},
	{
		"GUI_PROGRESSBAR_INNER",
		ffw::GuiStyleGroup(
			ffw::GuiStyle(),
			ffw::GuiStyle(),
			ffw::GuiStyle(),
			ffw::GuiStyle(),
			ffw::GuiDefaults(
				ffw::GuiStyle::Margin(0, 0, 0, 0),
				ffw::GuiStyle::Padding(0),
				ffw::GuiStyle::Align::TOP_LEFT,
				ffw::Vec2<ffw::GuiUnits>(ffw::guiPercent(100), ffw::guiPercent(100))
			)
		)
	},
	{
		"GUI_PROGRESSCIRCLE",
		ffw::GuiStyleGroup(
			ffw::GuiStyle(),
			ffw::GuiStyle(),
			ffw::GuiStyle(),
			ffw::GuiStyle(),
			ffw::GuiDefaults(
				ffw::GuiStyle::Margin(0, 0, 0, 0),
				ffw::GuiStyle::Padding(0),
				ffw::GuiStyle::Align::CENTER,
				ffw::Vec2<ffw::GuiUnits>(ffw::guiPercent(100), ffw::guiWrap())
			)
		)
	},
});