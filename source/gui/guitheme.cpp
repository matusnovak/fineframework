/*** This file is part of FineFramework project ***/

#include "ffw/gui/guitheme.h"
#include "ffw/gui/guiwindow.h"
#include "ffw/gui/guilayout.h"
#include "ffw/gui/guibutton.h"
#include "ffw/gui/guicheckbox.h"
#include "ffw/gui/guiradio.h"
#include "ffw/gui/guilabel.h"

///=============================================================================
ffw::GuiTheme::GuiTheme(const std::initializer_list<std::pair<size_t, GuiStyleGroup>>& list) {
	for(const auto& p : list) {
		styles.insert(p);
	}
}

///=============================================================================
ffw::GuiTheme::~GuiTheme() {
}

///=============================================================================
void ffw::GuiTheme::Add(const std::pair<size_t, GuiStyleGroup>& sty) {
	styles.insert(sty);
}

///=============================================================================
const ffw::GuiStyleGroup& ffw::GuiTheme::GetByType(const std::type_info& type) const  {
	auto hash = type.hash_code();
	if (styles.find(hash) == styles.end())std::cerr << "No style found for: " << type.name() << std::endl;
	assert(styles.find(hash) != styles.end());
	return styles.at(hash);
}

///=============================================================================
ffw::GuiStyleGroup& ffw::GuiTheme::GetByType(const std::type_info& type){
	auto hash = type.hash_code();
	if (styles.find(hash) == styles.end())std::cerr << "No style found for: " << type.name() << std::endl;
	assert(styles.find(hash) != styles.end());
	return styles.at(hash);
}

///=============================================================================
ffw::GuiTheme ffw::GuiTheme::Windows({
	// GUI LAYOUT
	{
	typeid(ffw::GuiLayout).hash_code(),
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
			)
		)
	},
	// GUI WINDOW BODY
	{
	typeid(ffw::GuiWindow::GuiBody).hash_code(),
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
			)
		)
	},
	// GUI LABEL
	{
		typeid(ffw::GuiLabel).hash_code(),
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
			)
		)
	},
	// GUI BUTTON
	{
		typeid(ffw::GuiButton).hash_code(),
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
				ffw::GuiStyle::Background(0, ffw::Rgb(0xECECEC), ffw::Rgb(0x000000), ffw::GuiStyle::Background::Type::SIMPLE),
				ffw::GuiStyle::Border(1, 0, ffw::Rgb(0xD5D5D5)),
				ffw::GuiStyle::Outline(0, 0, ffw::Rgb(0x000000)),
				ffw::GuiStyle::Text(ffw::Rgb(0xADADAD)),
				ffw::GuiStyle::Function(ffw::Rgb(0xFFFFFF))
			)
		)
	},
	// GUI CHECKBOX
	{
		typeid(ffw::GuiCheckbox).hash_code(),
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
			)
		)
	},
	// GUI CHECKBOX BUTTON
	{
		typeid(ffw::GuiCheckbox::Button).hash_code(),
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
				ffw::GuiStyle::Background(0, ffw::Rgb(0xECECEC), ffw::Rgb(0x000000), ffw::GuiStyle::Background::Type::SIMPLE),
				ffw::GuiStyle::Border(1, 0, ffw::Rgb(0x222222)),
				ffw::GuiStyle::Outline(0, 0, ffw::Rgb(0x000000)),
				ffw::GuiStyle::Text(ffw::Rgb(0x000000)),
				ffw::GuiStyle::Function(ffw::Rgb(0xADADAD))
			)
		)
	},
	// GUI RADIO
	{
		typeid(ffw::GuiRadio).hash_code(),
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
				ffw::GuiStyle::Text(ffw::Rgb(0x222222)),
				ffw::GuiStyle::Function(ffw::Rgb(0xFFFFFF))
			)
		)
	},
	// GUI RADIO BUTTON
	{
		typeid(ffw::GuiRadio::Button).hash_code(),
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
				ffw::GuiStyle::Background(8, ffw::Rgb(0xECECEC), ffw::Rgb(0x000000), ffw::GuiStyle::Background::Type::SIMPLE),
				ffw::GuiStyle::Border(1, 8, ffw::Rgb(0x222222)),
				ffw::GuiStyle::Outline(0, 0, ffw::Rgb(0x000000)),
				ffw::GuiStyle::Text(ffw::Rgb(0x000000)),
				ffw::GuiStyle::Function(ffw::Rgb(0xADADAD))
			)
		)
	}

});