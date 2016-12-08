/*** This file is part of FineFramework project ***/

#include "ffw/gui/guitextedit.h"
#include "ffw/gui/guiwindow.h"

///=============================================================================
ffw::GuiTextEdit::TextLine::TextLine(const std::wstring& s){
	SetText(s);
}

///=============================================================================
const std::wstring& ffw::GuiTextEdit::TextLine::Get() const {
	return str;
}

///=============================================================================
const std::vector<size_t>& ffw::GuiTextEdit::TextLine::Tokens() const {
	return tokens;
}

///=============================================================================
void ffw::GuiTextEdit::TextLine::SetText(const std::wstring& s){
	tokens.clear();
	str = s;
	tokens.push_back(str.size());
}

///=============================================================================
void ffw::GuiTextEdit::TextLine::InsertAt(size_t pos, wchar_t chr){
	if(pos <= str.size()){
		str.insert(pos, 1, chr);
	}
}

///=============================================================================
void ffw::GuiTextEdit::TextLine::RemoveAt(size_t pos){
	if(pos < str.size()){
		str.erase(pos, 1);
	}
}

///=============================================================================
void ffw::GuiTextEdit::TextLine::Append(const std::wstring& s){
	str.append(s);
}

///=============================================================================
void ffw::GuiTextEdit::TextLine::Recalculate(const ffw::GuiFont* font, int width, bool ignore){
	if(!ignore){
		tokens[0] = str.size();
		return;
	}

	tokens.clear();

	int total = 0;
	int totalForLast = 0;
	size_t last = SIZE_MAX;
	for(size_t i = 0; i < str.size(); i++){
		const auto& chr = str[i];

		total += font->GetCharAdvance(chr);
		if(total > width){
			/*bool reset = false;
			if(str[last] > 32){
				reset = true;
			} */

			if(last == SIZE_MAX)tokens.push_back(i);
			else tokens.push_back(last +1);
			last = i;
			total -= totalForLast;
			totalForLast = 0;

			//if(reset)total = 0;
		}

		if(chr <= 32){
			last = i;
			totalForLast = total;
		}		
	}
	tokens.push_back(str.size());
}

///=============================================================================
ffw::GuiTextEdit::GuiTextEdit(GuiWindow* context, const std::string& str, bool multiline, bool editable):GuiTextEdit(context, Utf8ToWstr(str), multiline, editable){
}

///=============================================================================
ffw::GuiTextEdit::GuiTextEdit(GuiWindow* context, const std::wstring& str, bool multiline, bool editable):GuiWidget(context){
	ignoreinputflag = !editable;
	multi = multiline;

	SetAlign(GuiAlign::TOP_LEFT);
	SetSize(GuiUnits::Percent(100), GuiUnits::Wrap());
	SetMargin(0, 0, 5, 0);
	SetPadding(2);

	style.normal.background = true;
	style.normal.backgroundcolor = ffw::Rgb(0xFFFFFF);
	style.normal.bordersize = 1;
	style.normal.bordercolor = ffw::Rgb(0xADADAD);
	style.normal.textcolor = ffw::Rgb(0x222222);

	style.hover.background = true;
	style.hover.backgroundcolor = ffw::Rgb(0xFFFFFF);
	style.hover.bordersize = 1;
	style.hover.bordercolor = ffw::Rgb(0x0078D7);
	style.hover.textcolor = ffw::Rgb(0x222222);

	style.active.background = true;
	style.active.backgroundcolor = ffw::Rgb(0xFFFFFF);
	style.active.bordersize = 1;
	style.active.bordercolor = ffw::Rgb(0x0078D7);
	style.active.textcolor = ffw::Rgb(0x222222);

	mousedown = false;
	lineHeight = -1;
	SetValue(str);
}

///=============================================================================
ffw::GuiTextEdit::~GuiTextEdit(){
}

///=============================================================================
void ffw::GuiTextEdit::SetValue(const std::wstring& str){
	lines.clear();
	size_t pos = 0;
	size_t last = 0;
	while((pos = str.find(L'\n', pos)) != std::string::npos){
		lines.push_back(str.substr(last, pos-last));
		pos++;
		last = pos;
	}
	lines.push_back(str.substr(last, str.size()-last));

	auto font = GetCurrentFont();
	if(font != NULL){
		for(size_t i = 0; i < lines.size(); i++){
			lines[i].Recalculate(GetCurrentFont(), GetVisibleContentSize().x, multi);
		}
	}
	Redraw();
}

///=============================================================================
std::wstring ffw::GuiTextEdit::GetValue() const {
	return L"";
	if(lines.size() == 0)return L"";
	else if(lines.size() == 1)return lines[0].Get();
	else {
		std::wstring ret;
		for(size_t i = 0; i < lines.size(); i++){
			if(i != lines.size()-1)
				ret += lines[i].Get() + L"\n";
			else
				ret += lines[i].Get();
		}
		return ret;
	}
}

///=============================================================================
int ffw::GuiTextEdit::GetLineHeight() const {
	auto font = GetCurrentFont();
	if(lineHeight < 0 && font != NULL)return font->GetLineHeight();
	else if(lineHeight < 0)return 0;
	else return lineHeight;
}

///=============================================================================
void ffw::GuiTextEdit::EventRender(const ffw::Vec2i& contentoffset, const ffw::Vec2i& contentsize){
	const auto& stl = GetCurrentStyle();
	context->SetDrawColor(stl.textcolor);

	auto font = GetCurrentFont();
	auto heightPerLine = GetLineHeight();

	context->SetDrawColor(stl.textcolor);

	int height = 0;
	size_t last = 0;
	for(size_t i = 0; i < lines.size(); i++){

		const auto& tokens = lines[i].Tokens();
		last = 0;
		for(size_t t = 0; t < tokens.size(); t++){
			context->DrawString(contentoffset + ffw::Vec2i(0, height), font, lines[i].Get(), last, tokens[t] - last);
			last = tokens[t];
			height += heightPerLine;
		}
	}

	if(HasFocus()){
		//context->DrawLine(contentoffset + cursorPos, contentoffset + cursorPos + ffw::Vec2i(0, font->GetLineHeight()), 1);
		if(!selection || (selection && cursorIndex == cursorIndexEnd)){
			context->DrawLine(contentoffset + cursorPos, contentoffset + cursorPos + ffw::Vec2i(0, heightPerLine), 1);
		} else {
			context->SetDrawColor(ffw::Rgba(0x0000FF80));

			//context->DrawLine(contentoffset + cursorPosEnd, contentoffset + cursorPosEnd + ffw::Vec2i(0, font->GetLineHeight()), 1);

			ffw::Vec2i posBegin = cursorPos;
			ffw::Vec2i posEnd = cursorPosEnd;
			ffw::Vec2i indexBegin = cursorIndex;
			ffw::Vec2i indexEnd = cursorIndexEnd;

			if((indexBegin.y > indexEnd.y) || (indexBegin.y == indexEnd.y && indexBegin.x > indexEnd.x)){
				std::swap(posBegin, posEnd);
				std::swap(indexBegin, indexEnd);
			}

			// On the same line
			if(posBegin.y == posEnd.y){
				context->DrawRectangle(contentoffset + posBegin, ffw::Vec2i(posEnd.x - posBegin.x, heightPerLine));
			} else {
				context->DrawRectangle(contentoffset + posBegin, ffw::Vec2i(contentsize.x - posBegin.x, heightPerLine));

				int count = ((posEnd.y - posBegin.y) / heightPerLine) -1;
				int offset = posBegin.y + heightPerLine;

				for(int i = 0; i < count; i++){
					context->DrawRectangle(contentoffset + ffw::Vec2i(0, i * heightPerLine + offset), ffw::Vec2i(contentsize.x, heightPerLine));
				}

				context->DrawRectangle(contentoffset + ffw::Vec2i(0, posEnd.y), ffw::Vec2i(posEnd.x, heightPerLine));
			}
		}
	}
}

///=============================================================================
ffw::Vec2i ffw::GuiTextEdit::CalculateCursorPos(const ffw::Vec2i& cursor){
	ffw::Vec2i pos;
	int heightPerLine = GetLineHeight();
	auto font = GetCurrentFont();

	pos = 0;

	if(font != NULL && cursor.y >= 0 && cursor.y < int(lines.size())){
		for(int i = 0; i < cursor.y ; i++){
			pos.y += lines[i].Tokens().size() * heightPerLine;
		}
		
		const auto& line = lines[cursor.y];

		const auto& tokens = line.Tokens();
		size_t last = tokens[0];
		size_t index = 1;

		size_t counter = 0;
		while(counter < last){
			if(counter == cursor.x){
				break;
			}
			
			wchar_t chr = line.Get()[counter];
			int advance = font->GetCharAdvance(chr);

			pos.x += advance;
			counter++;

			if(counter >= last && index < tokens.size()){
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
std::pair<ffw::Vec2i, ffw::Vec2i> ffw::GuiTextEdit::CalculateCursor(const ffw::Vec2i& mouse){
	ffw::Vec2i pos;
	ffw::Vec2i cursor;
	int heightPerLine = GetLineHeight();
	auto font = GetCurrentFont();

	if(font == NULL){
		return std::make_pair(ffw::Vec2i(), ffw::Vec2i());
	}

	for(size_t i = 0; i < lines.size(); i++){
		int currentHeight = lines[i].Tokens().size() * heightPerLine;
		
		// Check Y
		if((mouse.y >= pos.y && mouse.y < pos.y + currentHeight) || (i == lines.size()-1 && mouse.y >= pos.y)){
			cursor.y = i;
			cursor.x = 0;
			// Calculate X

			const auto& line = lines[i];
			if(line.Tokens().size() != 0){
				const auto& tokens = line.Tokens();
				size_t last = tokens[0];
				size_t index = 1;

				size_t counter = 0;
				while(counter < last){
					wchar_t chr = line.Get()[counter];
					int advance = font->GetCharAdvance(chr);

					if(mouse.x >= pos.x && mouse.x <= pos.x + advance && mouse.y >= pos.y && mouse.y <= pos.y + heightPerLine){
						cursor.x = counter;
						//std::cout << "selected 0: " << cursorIndex << std::endl;
						return std::make_pair(pos, cursor);
					}

					pos.x += advance;
					counter++;

					if(counter >= last && index < tokens.size()){
						last = tokens[index];
						index++;
						pos.x = 0;
						pos.y += heightPerLine;
					}
				}
			}

			cursor.x = line.Get().size();
			//std::cout << "selected 1: " << cursorIndex << std::endl;
			return std::make_pair(pos, cursor);
		}

		pos.y += currentHeight;
	}

	cursor.y = lines.size()-1;
	cursor.x = lines.back().Get().size();
	pos = 0;

	//std::cout << "selected 2: " << cursorIndex << std::endl;
	return std::make_pair(pos, cursor);
}

///=============================================================================
void ffw::GuiTextEdit::EventPos(const ffw::Vec2i& pos){
}

///=============================================================================
void ffw::GuiTextEdit::EventSize(const ffw::Vec2i& size){
	const auto font = GetCurrentFont();
	const auto width = GetVisibleContentSize().x;
	if(font != NULL){
		for(auto& line : lines){
			line.Recalculate(GetCurrentFont(), width, multi);
		}
	}
	selection = false;
}

///=============================================================================
void ffw::GuiTextEdit::EventHover(bool gained){
}

///=============================================================================
void ffw::GuiTextEdit::EventFocus(bool gained){
	Redraw();
	
	if(!gained){
		//cursorOffset.Set(-1, -1);
		selection = false;
	}
}

///=============================================================================
void ffw::GuiTextEdit::EventMouse(const ffw::Vec2i& pos){
	if(mousedown){
		if(!ignoreFirst){
			auto ret = CalculateCursor(pos);
			//std::cout << "calculating pos: " << ret.first << std::endl;
			cursorPosEnd = ret.first;
			cursorIndexEnd = ret.second;
			selection = true;
			Redraw();
		}
		ignoreFirst = false;
	}
}

///=============================================================================
void ffw::GuiTextEdit::EventMouseButton(ffw::MouseButton button, ffw::Mode mode){
	if(button == ffw::MouseButton::LEFT){
		if(mode == ffw::Mode::PRESSED){
			auto ret = CalculateCursor(GetMousePos());
			cursorPos = ret.first;
			cursorIndex = ret.second;
			Redraw();
			mousedown = true;
			ignoreFirst = true;
			selection = false;
		} else {
			mousedown = false;
		}
	}
}

///=============================================================================
void ffw::GuiTextEdit::SplitAtCurrent(){
	if(GetCurrentFont() == NULL)return;

	if(cursorIndex.y >= 0 && cursorIndex.y < int(lines.size())){
		auto copy = lines[cursorIndex.y].Get();
		lines[cursorIndex.y].SetText(copy.substr(cursorIndex.x));
		lines[cursorIndex.y].Recalculate(GetCurrentFont(), GetVisibleContentSize().x, multi);

		lines.insert(lines.begin() + cursorIndex.y, ffw::GuiTextEdit::TextLine(copy.substr(0, cursorIndex.x)));
		lines[cursorIndex.y].Recalculate(GetCurrentFont(), GetVisibleContentSize().x, multi);
		cursorIndex.y++;
		cursorIndex.x = 0;
		cursorPos = CalculateCursorPos(cursorIndex);
		Redraw();
	}
}

///=============================================================================
void ffw::GuiTextEdit::InsertAtCurrent(wchar_t chr){
	if(GetCurrentFont() == NULL)return;
	
	if(cursorIndex.y >= 0 && cursorIndex.y < int(lines.size())){
		lines[cursorIndex.y].InsertAt(cursorIndex.x, chr);
		lines[cursorIndex.y].Recalculate(GetCurrentFont(), GetVisibleContentSize().x, multi);
		cursorIndex.x++;
		cursorPos = CalculateCursorPos(cursorIndex);
		Redraw();
	}
}

///=============================================================================
void ffw::GuiTextEdit::RemoveAtCurrent(int offset){
	if(GetCurrentFont() == NULL)return;
	
	if(cursorIndex.y >= 0 && cursorIndex.y < int(lines.size())){

		int index = int(cursorIndex.x) + offset;
		//std::cout << "delete index: " << index << " total: " << lines[cursorIndex.y].Get().size() << std::endl;

		if(index >= 0 && index < int(lines[cursorIndex.y].Get().size())){
			lines[cursorIndex.y].RemoveAt(cursorIndex.x + offset);
			lines[cursorIndex.y].Recalculate(GetCurrentFont(), GetVisibleContentSize().x, multi);
			cursorIndex.x += offset;
			cursorPos = CalculateCursorPos(cursorIndex);
			Redraw();
		} 
		
		// Deleting backwards at the start of the line
		// We need to combine our two lines
		else if(index == -1 && cursorIndex.y > 0){
			//std::cout << "minus one!" << std::endl;

			size_t len = lines[cursorIndex.y-1].Get().size();
			lines[cursorIndex.y-1].Append(lines[cursorIndex.y].Get());
			lines.erase(lines.begin() + cursorIndex.y );
			cursorIndex.y--;
			lines[cursorIndex.y].Recalculate(GetCurrentFont(), GetVisibleContentSize().x, multi);
			cursorIndex.x = len;
			cursorPos = CalculateCursorPos(cursorIndex);
			Redraw();
		}

		// Deleting forwards at the end of the line
		// We need to combine our two lines
		else if(index == int(lines[cursorIndex.y].Get().size()) && cursorIndex.y+1 < int(lines.size())){
			//std::cout << "plus one" << std::endl;

			lines[cursorIndex.y].Append(lines[cursorIndex.y+1].Get());
			lines.erase(lines.begin() + cursorIndex.y + 1);
			lines[cursorIndex.y].Recalculate(GetCurrentFont(), GetVisibleContentSize().x, multi);
			cursorPos = CalculateCursorPos(cursorIndex);
			Redraw();
		}
	}
}

///=============================================================================
void ffw::GuiTextEdit::ReplaceSection(ffw::Vec2i beg, ffw::Vec2i end, const std::wstring& s){
	if(GetCurrentFont() == NULL)return;
	
	if(beg.y > end.y || (beg.y == end.y && beg.x > end.x)){
		std::swap(beg, end);
	}

	// Replace inside of a single line?
	if(beg.y == end.y){
		auto copy1 = lines[beg.y].Get().substr(0, beg.x);
		auto copy2 = lines[end.y].Get().substr(end.x);

		lines[beg.y].SetText(copy1 + s + copy2);
		lines[beg.y].Recalculate(GetCurrentFont(), GetVisibleContentSize().x, multi);
		cursorIndex.x = beg.x + s.size();
		cursorPos = CalculateCursorPos(cursorIndex);
		Redraw();
	}
	
	else {
		auto copy1 = lines[beg.y].Get().substr(0, beg.x);
		auto copy2 = lines[end.y].Get().substr(end.x);

		size_t toRemove = end.y - beg.y;
		//std::cout << "to remove: " << (beg.y +1) << " / " << toRemove << std::endl;

		lines.erase(lines.begin() + beg.y +1, lines.begin() + beg.y + 1 + toRemove);
		lines[beg.y].SetText(copy1 + s + copy2);
		lines[beg.y].Recalculate(GetCurrentFont(), GetVisibleContentSize().x, multi);
		cursorIndex.x = beg.x + s.size();
		cursorIndex.y = beg.y;
		cursorPos = CalculateCursorPos(cursorIndex);
		Redraw();
	}
}

///=============================================================================
void ffw::GuiTextEdit::EventText(wchar_t chr){
	auto font = GetCurrentFont();

	if(!multi && (chr == '\n' || chr == '\r'))return;
	
	if(font != NULL){
		if(selection)ReplaceSection(cursorIndex, cursorIndexEnd, std::wstring(1, chr));
		else InsertAtCurrent(chr);
		selection = false;
	}
}

///=============================================================================
void ffw::GuiTextEdit::EventKey(ffw::Key key, ffw::Mode mode){
	auto font = GetCurrentFont();

	if(font != NULL && (mode == ffw::Mode::PRESSED || mode == ffw::Mode::REPEAT)){
		switch(key){
			case ffw::Key::ENTER:
			case ffw::Key::NUMPADENTER: {
				if(multi){
					if(selection)ReplaceSection(cursorIndex, cursorIndexEnd, L"");
					SplitAtCurrent();
				}
				break;
			}
			case ffw::Key::TAB: {
				if(selection)ReplaceSection(cursorIndex, cursorIndexEnd, L"\t");
				else InsertAtCurrent('\t');
				break;
			}
			case ffw::Key::BACKSPACE: {
				if(selection)ReplaceSection(cursorIndex, cursorIndexEnd, L"");
				else RemoveAtCurrent(-1);
				break;
			}
			case ffw::Key::DELETEKEY: {
				if(selection)ReplaceSection(cursorIndex, cursorIndexEnd, L"");
				else RemoveAtCurrent(0);
				break;
			}
			case ffw::Key::ARROWLEFT: {
				// Is the cursor index valid?
				if(cursorIndex.y >= 0 && cursorIndex.y < int(lines.size())){
					// Go left
					cursorIndex.x--;
					// Are we outside if the string?
					if(cursorIndex.x < 0){
						// Is this not the first line?
						if(cursorIndex.y > 0){
							// Go to the previous line at the end
							cursorIndex.x = lines[cursorIndex.y-1].Get().size();
							cursorIndex.y--;
						} else {
							// Reset indexes
							cursorIndex.x = 0;
							cursorIndex.y = 0;
						}
					}
					cursorPos = CalculateCursorPos(cursorIndex);
					Redraw();
				}
				break;
			}
			case ffw::Key::ARROWRIGHT: {
				// Is the cursor index valid?
				if(cursorIndex.y >= 0 && cursorIndex.y < int(lines.size())){
					// Go right
					cursorIndex.x++;
					// Are we outside of the string?
					if(cursorIndex.x > int(lines[cursorIndex.y].Get().size())){
						// Is this not the last line?
						if(cursorIndex.y+1 < int(lines.size())){
							// Go to the next line at the beginning
							cursorIndex.x = 0;
							cursorIndex.y++;
						} else {
							// This is the last line... reset cursor index Y
							cursorIndex.x = lines[cursorIndex.y].Get().size();
						}
					}
					cursorPos = CalculateCursorPos(cursorIndex);
					Redraw();
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
ffw::Vec2i ffw::GuiTextEdit::GetMinimumWrapSize() const {
	auto font = GetCurrentFont();
	if(font != NULL){
		return ffw::Vec2i(0, font->GetLineHeight());
	}
	else return 0;
}