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
void ffw::GuiTheme::add(const std::pair<std::string, GuiStyleGroup>& sty) {
	styles.insert(sty);
}

///=============================================================================
const ffw::GuiStyleGroup& ffw::GuiTheme::getStyleGroup(const std::string& type) const  {
	if (styles.find(type) == styles.end()) {
		//std::cerr << "No GuiStyleGroup found for: \"" << type << "\"" << std::endl;
		throw std::invalid_argument("No GuiStyleGroup found for: \"" + type + "\"");
	}
	return styles.at(type);
}

///=============================================================================
ffw::GuiStyleGroup& ffw::GuiTheme::getStyleGroup(const std::string& type) {
	if (styles.find(type) == styles.end()) {
		//std::cerr << "No GuiStyleGroup found for: \"" << type << "\"" << std::endl;
		throw std::invalid_argument("No GuiStyleGroup found for: \"" + type + "\"");
	}
	return styles.at(type);
}
