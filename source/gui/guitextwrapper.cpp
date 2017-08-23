/*** This file is part of FineFramework project ***/

#include "ffw/gui/guitextwrapper.h"
#include "ffw/math/stringmath.h"

///=============================================================================
ffw::GuiTextWrapper::Paragraph::Paragraph() {
	totalHeight = 0;
}

///=============================================================================
ffw::GuiTextWrapper::Paragraph::~Paragraph() {

}

///=============================================================================
void ffw::GuiTextWrapper::Paragraph::append(const std::wstring& str) {
	if(sections.size() == 0) {
		return;
	}

	text.append(str);
}

///=============================================================================
void ffw::GuiTextWrapper::Paragraph::section(const ffw::Color& color, const ffw::GuiFont* font) {
	sections.push_back(Section());
	sections.back().pos = text.size();
	sections.back().color = color;
	sections.back().font = font;
}

///=============================================================================
void ffw::GuiTextWrapper::Paragraph::recalculate(float width) {
	// Breakable whitespace characters
	static const std::wstring unicodeSpaces = L"\x0009\x0020\x00A0\x1680\x180E\x2000\x2001\x2002\x2003\x2004\x2005\x2006\x2007\x2008\x2009\x200A\x200B\x205F\x3000\xEFEF";
	
	tokens.clear();

	int currentWidth = 0;
	int lastWidth = 0;
	int newHeight = -1;
	totalHeight = 0;
	size_t lastWhitespace = SIZE_MAX;

	if (sections.size() == 0)return;

	const ffw::GuiFont* font = sections.begin()->font;
	size_t next = 0;
	size_t current = 0;
	int height = -1;

	for (size_t i = 0; i < text.size(); i++) {
		const auto& chr = text[i];

		if(i == next) {
			font = sections[current].font;
			//height = std::max(height, font->getSizeInPixels());
			//std::cout << "new font height = std::max(" << height << ", " << font->getSizeInPixels() << ")" << std::endl;
			newHeight = font->getSizeInPixels();
			if(current +1 < sections.size()) {
				next = sections[current + 1].pos;
				current += 1;
			} else {
				next = std::wstring::npos;
			}
		}

		if(height == -1) {
			height = font->getSizeInPixels();
		}

		auto test = font->getCharAdvance(chr);

		bool currentIsWhitespace = false;
		if (unicodeSpaces.find(chr) != std::wstring::npos) {
			//std::cout << "whitespace at: " << i << std::endl;
			lastWhitespace = i;
			lastWidth = currentWidth + test;
			currentIsWhitespace = true;
		}

		if (currentWidth + test > width && !currentIsWhitespace) {
			//std::cout << "current with at: " << i << " is too long!" << std::endl;
			if (lastWhitespace != SIZE_MAX) {
				//std::cout << "    got last whitespace! pushing: " << (lastWhitespace + 1) << ", " << height << std::endl;
				tokens.push_back(std::pair<size_t, int>(lastWhitespace + 1, height));
				totalHeight += height;
				height = -1;
				currentWidth -= lastWidth;
				lastWhitespace = SIZE_MAX;
			}
			else {
				//std::cout << "    no last whitespace! pushing: " << i << ", " << height << std::endl;
				tokens.push_back(std::pair<size_t, int>(i, height));
				totalHeight += height;
				height = -1;
				currentWidth = 0;
			}
			currentWidth += test;
		}
		else {
			currentWidth += test;
		}

		height = std::max(height, newHeight);
	}

	tokens.push_back(std::pair<size_t, int>(text.size(), height));
	totalHeight += height;
}

///=============================================================================
ffw::GuiTextWrapper::Stepper::Stepper(const Paragraph& paragraph):
	text(paragraph.getText()),
	sections(paragraph.getSections()),
	tokens(paragraph.getTokens()) {
	current = 0;
	nextToken = SIZE_MAX;
	nextSection = SIZE_MAX;
	if (tokens.size() > 0)nextToken = 0;
	if (sections.size() > 0)nextSection = 0;
	newline = false;
}

///=============================================================================
ffw::GuiTextWrapper::Stepper::~Stepper() {
	
}

///=============================================================================
bool ffw::GuiTextWrapper::Stepper::hasNext() const {
	return nextToken < tokens.size() && sections.size() > 0;
}

///=============================================================================
bool ffw::GuiTextWrapper::Stepper::getNext() {
	if(hasNext()) {
		ptr = &text[current];
		//length = tokens[nextToken].first;
		height = tokens[nextToken].second;
		font = sections[nextSection].font;
		color = sections[nextSection].color;

		/*if(nextToken > 0) {
			length -= tokens[nextToken -1].first;
		}*/
		if(nextSection +1 < sections.size() && sections[nextSection+1].pos < tokens[nextToken].first) {
			length = sections[nextSection + 1].pos - current;
		}
		else {
			length = tokens[nextToken].first - current;
		}

		if(nextSection+1 < sections.size() && nextToken+1 < tokens.size()) {
			//std::cout << "IF #1 ";
			if(sections[nextSection +1].pos < tokens[nextToken].first) {
				//std::cout << "section first" << std::endl;
				nextSection++;
				current = sections[nextSection].pos;
				newline = false;
			} else {
				//std::cout << "token first" << std::endl;
				nextToken++;
				current = tokens[nextToken-1].first;
				newline = true;
			}
		} 
		else if(nextSection+1 >= sections.size() && nextToken+1 < tokens.size()) {
			//std::cout << "IF #2 next token" << std::endl;
			nextToken++;
			current = tokens[nextToken-1].first;
			newline = true;
			//nextSection = SIZE_MAX;
		}
		else if (nextSection+1 < sections.size() && nextToken+1 >= tokens.size()) {
			//std::cout << "IF #3 next section" << std::endl;
			nextSection++;
			current = sections[nextSection].pos;
			newline = false;
			//nextToken = SIZE_MAX;
		} else {
			//std::cout << "IF #4 end" << std::endl;
			nextToken++;
			newline = true;
		}

		return true;
	}
	return false;
}

///=============================================================================
ffw::GuiTextWrapper::GuiTextWrapper() {
	
}

///=============================================================================
ffw::GuiTextWrapper::~GuiTextWrapper() {
	
}

///=============================================================================
void ffw::GuiTextWrapper::setValue(const std::wstring& str, const ffw::Color& color, const ffw::GuiFont* font) {
	ffw::Tokenizer<wchar_t> tokens(str, L"\n");
	while(tokens.hasNext()) {
		addParagraph();
		section(color, font);
		append(tokens.getNext());
	}
}

///=============================================================================
const std::wstring ffw::GuiTextWrapper::getValue() const {
	if (paragraphs.size() == 0) {
		return L"";
	}
	if (paragraphs.size() == 1) {
		return paragraphs[0].getText();
	}

	std::wstring ret;
	for (size_t i = 0; i < paragraphs.size(); i++) {
		if (i != paragraphs.size() - 1)
			ret.append(paragraphs[i].getText() + L"\n");
		else
			ret.append(paragraphs[i].getText());
	}
	return ret;
}

///=============================================================================
void ffw::GuiTextWrapper::recalculate(float width) {
	for(auto& p : paragraphs) {
		p.recalculate(width);
	}
}