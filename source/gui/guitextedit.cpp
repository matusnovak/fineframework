/*** This file is part of FineFramework project ***/

#include "ffw/gui/guitextedit.h"
#include "ffw/gui/guiwindow.h"
#include <regex>

///=============================================================================
ffw::GuiTextInput::TextLine::TextLine(const std::wstring& s) {
	setText(s);
}

///=============================================================================
const std::wstring& ffw::GuiTextInput::TextLine::get() const {
	return str;
}

///=============================================================================
const std::vector<size_t>& ffw::GuiTextInput::TextLine::Tokens() const {
	return tokens;
}

///=============================================================================
void ffw::GuiTextInput::TextLine::setText(const std::wstring& s) {
	tokens.clear();
	str = s;
	tokens.push_back(str.size());
}

///=============================================================================
void ffw::GuiTextInput::TextLine::insertAt(size_t pos, wchar_t chr) {
	if (pos <= str.size()) {
		str.insert(pos, 1, chr);
	}
}

///=============================================================================
void ffw::GuiTextInput::TextLine::removeAt(size_t pos) {
	if (pos < str.size()) {
		str.erase(pos, 1);
	}
}

///=============================================================================
void ffw::GuiTextInput::TextLine::append(const std::wstring& s) {
	str.append(s);
}

///=============================================================================
void ffw::GuiTextInput::TextLine::recalculate(const ffw::GuiFont* font, int width, bool ignore) {
	if (!ignore) {
		tokens[0] = str.size();
		return;
	}

	tokens.clear();

	int currentWidth = 0;
	int lastWidth = 0;
	size_t lastWhitespace = SIZE_MAX;

	for (size_t i = 0; i < str.size(); i++) {
		const auto& chr = str[i];

		auto test = font->getCharAdvance(chr);

		if (currentWidth + test > width) {
			if (lastWhitespace != SIZE_MAX) {
				tokens.push_back(lastWhitespace + 1);
				currentWidth -= lastWidth;
				lastWhitespace = SIZE_MAX;
			}
			else {
				tokens.push_back(i);
				currentWidth = 0;
			}
			currentWidth += test;
		}
		else {
			currentWidth += test;
		}

		if (chr <= 32) {
			lastWhitespace = i;
			lastWidth = currentWidth;
		}
	}

	tokens.push_back(str.size());
}

///=============================================================================
ffw::GuiTextInput::GuiTextInput(GuiWindow* context, bool multiline, bool editable) : GuiWidget(context) {
	setIgnoreUserInput(!editable);

	// At this point, we are sure that the context and getTheme() are not NULL
	widgetStyle = &context->getTheme()->getStyleGroup("GUI_TEXT_INPUT");
	setDefaults(&widgetStyle->defaults);

	multi = multiline;

	mousedown = false;
	linesLastWidth = 0;
	setValue(L"");
}

///=============================================================================
ffw::GuiTextInput::~GuiTextInput() {
}

///=============================================================================
void ffw::GuiTextInput::setValue(const std::wstring& str) {
	lines.clear();
	size_t pos = 0;
	size_t last = 0;
	while ((pos = str.find(L'\n', pos)) != std::string::npos) {
		lines.push_back(str.substr(last, pos - last));
		pos++;
		last = pos;
	}
	lines.push_back(str.substr(last, str.size() - last));

	auto font = getCurrentFont();
	if (font != NULL) {
		linesLastWidth = getVisibleContentSize().x;
		for (size_t i = 0; i < lines.size(); i++) {
			lines[i].recalculate(getCurrentFont(), linesLastWidth, multi);
		}
	}
	invalidate();
	redraw();
}

///=============================================================================
std::wstring ffw::GuiTextInput::getValue() const {
	if (lines.size() == 0) {
		return L"";
	}
	else if (lines.size() == 1) {
		return lines[0].get();
	}
	else {
		std::wstring ret;
		for (size_t i = 0; i < lines.size(); i++) {
			if (i != lines.size() - 1)
				ret += lines[i].get() + L"\n";
			else
				ret += lines[i].get();
		}
		return ret;
	}
}

///=============================================================================
bool ffw::GuiTextInput::isEmpty() const {
	return lines.size() == 0 && lines[0].get().size() == 0;
}

///=============================================================================
void ffw::GuiTextInput::eventRender(const ffw::Vec2i& contentoffset, const ffw::Vec2i& contentsize) {
	const auto& stl = getCurrentStyle();
	//context->setDrawColor(stl.textcolor);

	auto font = getCurrentFont();
	int heightPerLine = int(getLineHeight() * font->getSizeInPixels());

	if (hasFocus()) {
		//context->drawLine(contentoffset + cursorPos, contentoffset + cursorPos + ffw::Vec2i(0, font->getLineHeight()), 1);
		if (!selection || (selection && cursorIndex == cursorIndexEnd)) {
			context->drawLine(contentoffset + cursorPos, contentoffset + cursorPos + ffw::Vec2i(0, heightPerLine), stl->text.color);
		}
		else {
			//context->setDrawColor(selectionColor);

			//context->drawLine(contentoffset + cursorPosEnd, contentoffset + cursorPosEnd + ffw::Vec2i(0, font->getLineHeight()), 1);

			ffw::Vec2i posBegin = cursorPos;
			ffw::Vec2i posEnd = cursorPosEnd;
			ffw::Vec2<size_t> indexBegin = cursorIndex;
			ffw::Vec2<size_t> indexEnd = cursorIndexEnd;

			if ((indexBegin.y > indexEnd.y) || (indexBegin.y == indexEnd.y && indexBegin.x > indexEnd.x)) {
				std::swap(posBegin, posEnd);
				std::swap(indexBegin, indexEnd);
			}

			// On the same line
			if (posBegin.y == posEnd.y) {
				context->drawRectangle(contentoffset + posBegin, ffw::Vec2i(posEnd.x - posBegin.x, heightPerLine), stl->function.color);
			}
			else {
				context->drawRectangle(contentoffset + posBegin, ffw::Vec2i(contentsize.x - posBegin.x, heightPerLine), stl->function.color);

				int cnt = ((posEnd.y - posBegin.y) / heightPerLine) - 1;
				int offset = posBegin.y + heightPerLine;

				for (int i = 0; i < cnt; i++) {
					context->drawRectangle(contentoffset + ffw::Vec2i(0, i * heightPerLine + offset), ffw::Vec2i(contentsize.x, heightPerLine), stl->function.color);
				}

				context->drawRectangle(contentoffset + ffw::Vec2i(0, posEnd.y), ffw::Vec2i(posEnd.x, heightPerLine), stl->function.color);
			}
		}
	}

	//context->setDrawColor(stl.textcolor);

	int height = 0;
	size_t last;
	for (size_t i = 0; i < lines.size(); i++) {

		const auto& tokens = lines[i].Tokens();
		last = 0;
		for (size_t t = 0; t < tokens.size(); t++) {
			context->drawString(contentoffset + ffw::Vec2i(0, height), font, &lines[i].get()[last], tokens[t] - last, stl->text.color);
			last = tokens[t];
			height += heightPerLine;
		}
	}
}

///=============================================================================
ffw::Vec2i ffw::GuiTextInput::calculateCursorPos(const ffw::Vec2i& cursor) {
	ffw::Vec2i pos;
	auto font = getCurrentFont();
	int heightPerLine = int(getLineHeight() * font->getSizeInPixels());

	pos = 0;

	if (font != NULL && cursor.y >= 0 && cursor.y < int(lines.size())) {
		for (int i = 0; i < cursor.y; i++) {
			pos.y += lines[i].Tokens().size() * heightPerLine;
		}

		const auto& line = lines[cursor.y];

		const auto& tokens = line.Tokens();
		size_t last = tokens[0];
		size_t index = 1;

		size_t counter = 0;
		while (counter < last) {
			if (counter == cursor.x) {
				break;
			}

			wchar_t chr = line.get()[counter];
			int advance = font->getCharAdvance(chr);

			pos.x += advance;
			counter++;

			if (counter >= last && index < tokens.size()) {
				last = tokens[index];
				index++;
				pos.x = 0;
				pos.y += heightPerLine;
			}
		}
	}

	return pos;
}

///=============================================================================
std::pair<ffw::Vec2i, ffw::Vec2i> ffw::GuiTextInput::calculateCursor(const ffw::Vec2i& mouse) {
	ffw::Vec2i pos;
	ffw::Vec2i cursor;
	auto font = getCurrentFont();
	int heightPerLine = int(font->getSizeInPixels() * getLineHeight());

	if (font == NULL) {
		return std::make_pair(ffw::Vec2i(), ffw::Vec2i());
	}

	for (size_t i = 0; i < lines.size(); i++) {
		int currentHeight = lines[i].Tokens().size() * heightPerLine;

		// Check Y
		if ((mouse.y >= pos.y && mouse.y < pos.y + currentHeight) || (i == lines.size() - 1 && mouse.y >= pos.y)) {
			cursor.y = i;
			cursor.x = 0;
			// calculate X

			const auto& line = lines[i];
			if (line.Tokens().size() != 0) {
				const auto& tokens = line.Tokens();
				size_t last = tokens[0];
				size_t index = 1;

				size_t counter = 0;
				while (counter < last) {
					wchar_t chr = line.get()[counter];
					int advance = font->getCharAdvance(chr);

					if (mouse.x >= pos.x && mouse.x <= pos.x + advance && mouse.y >= pos.y && mouse.y <= pos.y + heightPerLine) {
						cursor.x = counter;
						//std::cout << "selected 0: " << cursorIndex << std::endl;
						return std::make_pair(pos, cursor);
					}

					pos.x += advance;
					counter++;

					if (counter >= last && index < tokens.size()) {
						last = tokens[index];
						index++;
						pos.x = 0;
						pos.y += heightPerLine;
					}
				}
			}

			cursor.x = line.get().size();
			//std::cout << "selected 1: " << cursorIndex << std::endl;
			return std::make_pair(pos, cursor);
		}

		pos.y += currentHeight;
	}

	cursor.y = lines.size() - 1;
	cursor.x = lines.back().get().size();
	pos = 0;

	//std::cout << "selected 2: " << cursorIndex << std::endl;
	return std::make_pair(pos, cursor);
}

///=============================================================================
void ffw::GuiTextInput::eventPos(const ffw::Vec2i& pos) {
}

///=============================================================================
void ffw::GuiTextInput::eventSize(const ffw::Vec2i& size) {
	const auto font = getCurrentFont();
	const auto width = getVisibleContentSize().x;
	if (font != NULL) {
		linesLastWidth = width;
		for (auto& line : lines) {
			line.recalculate(getCurrentFont(), linesLastWidth, multi);
		}
	}
	selection = false;
}

///=============================================================================
void ffw::GuiTextInput::eventHover(bool gained) {
	redraw();
}

///=============================================================================
void ffw::GuiTextInput::eventFocus(bool gained) {
	redraw();

	if (!gained) {
		//cursorOffset.set(-1, -1);
		selection = false;
	}

	GuiEvent::Data dat;
	dat.clicked.value = gained;
	pushEvent(GuiEvent::Type::CLICKED, dat);
}

///=============================================================================
void ffw::GuiTextInput::eventMouse(const ffw::Vec2i& pos) {
	if (mousedown) {
		if (!ignoreFirst) {
			auto ret = calculateCursor(pos);
			cursorPosEnd = ret.first;
			cursorIndexEnd = ret.second;
			//cursorIndexEnd.x++;
			//cursorPosEnd = calculateCursorPos(cursorIndexEnd);
			selection = true;
			redraw();
		}
		ignoreFirst = false;
	}
}

///=============================================================================
void ffw::GuiTextInput::eventMouseButton(ffw::MouseButton button, ffw::Mode mode) {
	if (button == ffw::MouseButton::LEFT) {
		if (mode == ffw::Mode::PRESSED) {
			auto ret = calculateCursor(getMousePos());
			cursorPos = ret.first;
			cursorIndex = ret.second;
			redraw();
			mousedown = true;
			ignoreFirst = true;
			selection = false;
		}
		else {
			mousedown = false;
		}
	}
}

///=============================================================================
void ffw::GuiTextInput::splitAtCurrent() {
	if (getCurrentFont() == NULL)return;

	if (cursorIndex.y >= 0 && cursorIndex.y < lines.size()) {
		auto copy = lines[cursorIndex.y].get();
		lines[cursorIndex.y].setText(copy.substr(cursorIndex.x));
		lines[cursorIndex.y].recalculate(getCurrentFont(), getVisibleContentSize().x, multi);

		lines.insert(lines.begin() + cursorIndex.y, ffw::GuiTextInput::TextLine(copy.substr(0, cursorIndex.x)));
		lines[cursorIndex.y].recalculate(getCurrentFont(), getVisibleContentSize().x, multi);
		cursorIndex.y++;
		cursorIndex.x = 0;
		cursorPos = calculateCursorPos(cursorIndex);
		invalidate();
		redraw();
	}
}

///=============================================================================
void ffw::GuiTextInput::insertAtCurrent(wchar_t chr) {
	if (getCurrentFont() == NULL)return;

	if (cursorIndex.y >= 0 && cursorIndex.y < lines.size()) {

		// Is the regular expression empty?
		if (regexStr.size() > 0) {
			// Add the char to the index
			lines[cursorIndex.y].insertAt(cursorIndex.x, chr);

			// Get the whole text
			auto text = getValue();

			// Go back -> remove the added character
			lines[cursorIndex.y].removeAt(cursorIndex.x);

			// Test the text with temporary added character
			std::wregex reg(regexStr);
			std::wstring swap(L"");
			if (std::regex_replace(text, reg, swap).size() != 0) {
				// The whole string must be replaced by an empty string,
				// otherwise there is no match
				return;
			}
		}

		// Regex ok, continue adding the character
		lines[cursorIndex.y].insertAt(cursorIndex.x, chr);
		lines[cursorIndex.y].recalculate(getCurrentFont(), getVisibleContentSize().x, multi);
		cursorIndex.x++;
		cursorPos = calculateCursorPos(cursorIndex);
		invalidate();
		redraw();

		GuiEvent::Data dat;
		dat.input.chr = chr;
		pushEvent(GuiEvent::Type::INPUT, dat);
	}
}

///=============================================================================
void ffw::GuiTextInput::removeAtCurrent(int offset) {
	if (getCurrentFont() == NULL)return;

	if (cursorIndex.y >= 0 && cursorIndex.y < lines.size()) {

		size_t index = cursorIndex.x + offset;
		//std::cout << "delete index: " << index << " total: " << lines[cursorIndex.y].get().size() << std::endl;

		if (index >= 0 && index < lines[cursorIndex.y].get().size()) {
			lines[cursorIndex.y].removeAt(cursorIndex.x + offset);
			lines[cursorIndex.y].recalculate(getCurrentFont(), getVisibleContentSize().x, multi);
			cursorIndex.x += offset;
			cursorPos = calculateCursorPos(cursorIndex);
			redraw();
			invalidate();
		}

		// Deleting backwards at the start of the line
		// We need to combine our two lines
		else if (index == -1 && cursorIndex.y > 0) {
			//std::cout << "minus one!" << std::endl;

			size_t len = lines[cursorIndex.y - 1].get().size();
			lines[cursorIndex.y - 1].append(lines[cursorIndex.y].get());
			lines.erase(lines.begin() + cursorIndex.y);
			cursorIndex.y--;
			lines[cursorIndex.y].recalculate(getCurrentFont(), getVisibleContentSize().x, multi);
			cursorIndex.x = len;
			cursorPos = calculateCursorPos(cursorIndex);
			invalidate();
			redraw();
		}

		// Deleting forwards at the end of the line
		// We need to combine our two lines
		else if (index == lines[cursorIndex.y].get().size() && cursorIndex.y + 1 < lines.size()) {
			//std::cout << "plus one" << std::endl;

			lines[cursorIndex.y].append(lines[cursorIndex.y + 1].get());
			lines.erase(lines.begin() + cursorIndex.y + 1);
			lines[cursorIndex.y].recalculate(getCurrentFont(), getVisibleContentSize().x, multi);
			cursorPos = calculateCursorPos(cursorIndex);
			invalidate();
			redraw();
		}
	}
}

///=============================================================================
void ffw::GuiTextInput::replaceSection(ffw::Vec2i beg, ffw::Vec2i end, const std::wstring& s) {
	if (getCurrentFont() == NULL)return;

	if (beg.y > end.y || (beg.y == end.y && beg.x > end.x)) {
		std::swap(beg, end);
	}

	// Replace inside of a single line?
	if (beg.y == end.y) {
		auto copy1 = lines[beg.y].get().substr(0, beg.x);
		auto copy2 = lines[end.y].get().substr(end.x);

		lines[beg.y].setText(copy1 + s + copy2);
		lines[beg.y].recalculate(getCurrentFont(), getVisibleContentSize().x, multi);
		cursorIndex.x = beg.x + s.size();
		cursorPos = calculateCursorPos(cursorIndex);
	}

	else {
		auto copy1 = lines[beg.y].get().substr(0, beg.x);
		auto copy2 = lines[end.y].get().substr(end.x);

		size_t toremove = end.y - beg.y;
		//std::cout << "to remove: " << (beg.y +1) << " / " << toremove << std::endl;

		lines.erase(lines.begin() + beg.y + 1, lines.begin() + beg.y + 1 + toremove);
		lines[beg.y].setText(copy1 + s + copy2);
		lines[beg.y].recalculate(getCurrentFont(), getVisibleContentSize().x, multi);
		cursorIndex.x = beg.x + s.size();
		cursorIndex.y = beg.y;
		cursorPos = calculateCursorPos(cursorIndex);
	}

	invalidate();
	redraw();
}

///=============================================================================
void ffw::GuiTextInput::eventText(wchar_t chr) {
	auto font = getCurrentFont();

	if (!multi && (chr == L'\n' || chr == L'\r'))return;

	if (font != NULL) {
		if (selection)replaceSection(cursorIndex, cursorIndexEnd, std::wstring(1, chr));
		else insertAtCurrent(chr);
		selection = false;
	}
}

///=============================================================================
void ffw::GuiTextInput::eventKey(ffw::Key key, ffw::Mode mode) {
	auto font = getCurrentFont();

	if (font != NULL && (mode == ffw::Mode::PRESSED || mode == ffw::Mode::REPEAT)) {
		switch (key) {
		case ffw::Key::ENTER:
		case ffw::Key::NUMPAD_ENTER: {
			if (multi) {
				if (selection)replaceSection(cursorIndex, cursorIndexEnd, L"");
				splitAtCurrent();
			}
			break;
		}
		case ffw::Key::TAB: {
			if (selection)replaceSection(cursorIndex, cursorIndexEnd, L"\t");
			else insertAtCurrent('\t');
			break;
		}
		case ffw::Key::BACKSPACE: {
			if (selection)replaceSection(cursorIndex, cursorIndexEnd, L"");
			else removeAtCurrent(-1);
			break;
		}
		case ffw::Key::FUNCTION_DELETE: {
			if (selection)replaceSection(cursorIndex, cursorIndexEnd, L"");
			else removeAtCurrent(0);
			break;
		}
		case ffw::Key::ARROW_LEFT: {
			// is the cursor index valid?
			if (cursorIndex.y >= 0 && cursorIndex.y < lines.size()) {
				// Go left
				cursorIndex.x--;
				// Are we outside if the string?
				if (cursorIndex.x < 0) {
					// is this not the first line?
					if (cursorIndex.y > 0) {
						// Go to the previous line at the end
						cursorIndex.x = lines[cursorIndex.y - 1].get().size();
						cursorIndex.y--;
					}
					else {
						// reset indexes
						cursorIndex.x = 0;
						cursorIndex.y = 0;
					}
				}
				cursorPos = calculateCursorPos(cursorIndex);
				redraw();
			}
			break;
		}
		case ffw::Key::ARROW_RIGHT: {
			// is the cursor index valid?
			if (cursorIndex.y >= 0 && cursorIndex.y < lines.size()) {
				// Go right
				cursorIndex.x++;
				// Are we outside of the string?
				if (cursorIndex.x > lines[cursorIndex.y].get().size()) {
					// is this not the last line?
					if (cursorIndex.y + 1 < lines.size()) {
						// Go to the next line at the beginning
						cursorIndex.x = 0;
						cursorIndex.y++;
					}
					else {
						// This is the last line... reset cursor index Y
						cursorIndex.x = lines[cursorIndex.y].get().size();
					}
				}
				cursorPos = calculateCursorPos(cursorIndex);
				redraw();
			}
			break;
		}
		default: {
			break;
		}
		}
		selection = false;
	}
}

///=============================================================================
void ffw::GuiTextInput::eventDisabled(bool disabled) {
}

///=============================================================================
void ffw::GuiTextInput::eventThemeChanged(const GuiTheme* theme) {
	widgetStyle = &theme->getStyleGroup("GUI_TEXT_INPUT");
	setDefaults(&widgetStyle->defaults);
}

///=============================================================================
ffw::Vec2i ffw::GuiTextInput::getMinimumWrapSize() {
	auto font = getCurrentFont();
	if (font != NULL) {
		auto test = getVisibleContentSize().x;
		if (linesLastWidth != test) {
			linesLastWidth = test;
			for (size_t i = 0; i < lines.size(); i++) {
				lines[i].recalculate(getCurrentFont(), linesLastWidth, multi);
			}
		}

		size_t total = 0;
		for (const auto& l : lines) {
			total += l.getNumOfTokens();
		}
		if (total == 0)total = 1;
		auto ret = ffw::Vec2i(0, int(total) * int(font->getSizeInPixels() * getLineHeight()));
		return ret;
	}
	else return 0;
}

///=============================================================================
ffw::GuiTextArea::Inner::Inner(GuiWindow* context, bool editable) :
	GuiTextInput(context, true, editable) {
	widgetStyle = &context->getTheme()->getStyleGroup("GUI_TEXT_AREA_INNER");
	setDefaults(&widgetStyle->defaults);
}

///=============================================================================
ffw::GuiTextArea::Inner::~Inner() {
}

///=============================================================================
void ffw::GuiTextArea::Inner::eventThemeChanged(const GuiTheme* theme) {
	widgetStyle = &theme->getStyleGroup("GUI_TEXT_AREA_INNER");
	setDefaults(&widgetStyle->defaults);
}

///=============================================================================
ffw::GuiTextArea::GuiTextArea(GuiWindow* context, bool editable) :
	GuiScrollable(context, textinput = new GuiTextArea::Inner(context, editable), false, true) {
	//getInner()->addWidget(textinput = new GuiTextArea::Inner(context, editable));
	widgetStyle = &context->getTheme()->getStyleGroup("GUI_TEXT_AREA");
	setDefaults(&widgetStyle->defaults);
}

///=============================================================================
ffw::GuiTextArea::~GuiTextArea() {

}

///=============================================================================
void ffw::GuiTextArea::eventThemeChanged(const GuiTheme* theme) {
	widgetStyle = &theme->getStyleGroup("GUI_TEXT_AREA");
	setDefaults(&widgetStyle->defaults);
}