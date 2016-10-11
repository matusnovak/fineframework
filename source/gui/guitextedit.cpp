/*** This file is part of FineFramework project ***/

#include "ffw/gui/guitextedit.h"
#include "ffw/gui/guiwindow.h"

///=============================================================================
ffw::GuiTextEdit::GuiTextEdit(GuiWindow* context, const std::string& str, bool multiline, bool editable):GuiWidget(context){
	ignoreinputflag = !editable;
	multi = multiline;

	SetAlign(GuiAlign::TOP_LEFT);
	SetSize(GuiUnits::Percent(100), GuiUnits::Pixels(20));
	SetMargin(0, 0, 5, 0);
	SetPadding(5);

	style.normal.background = true;
	style.normal.backgroundcolor = ffw::Rgb(0xFFFFFF);
	style.normal.textcolor = ffw::Rgb(0x222222);

	style.hover.background = true;
	style.hover.backgroundcolor = ffw::Rgb(0xFFFFFF);
	style.hover.textcolor = ffw::Rgb(0x222222);

	style.active.background = true;
	style.active.backgroundcolor = ffw::Rgb(0xFFFFFF);
	style.active.textcolor = ffw::Rgb(0x222222);

	cursor.Set(-1, -1);

	SetValue(str);
}

///=============================================================================
ffw::GuiTextEdit::~GuiTextEdit(){
}

///=============================================================================
void ffw::GuiTextEdit::SetValue(const std::string& str){
	text = str;
	Redraw();
}

///=============================================================================
const std::string& ffw::GuiTextEdit::GetValue() const {
	return text;
}

///=============================================================================
void ffw::GuiTextEdit::EventRender(const ffw::Vec2i& contentoffset, const ffw::Vec2i& contentsize){
	const auto& stl = GetCurrentStyle();
	context->SetDrawColor(stl.textcolor);

	auto font = GetCurrentFont();
	if(cursor.x != -1 && cursor.y != -1 && font != NULL){
		//context->DrawStringAligned(contentoffset + cursor, 0, font, GetAlign(), "|");
		context->DrawLine(contentoffset + cursor, contentoffset + cursor + ffw::Vec2i(0, font->GetLineHeight()), 1);
	}

	context->DrawStringAligned(contentoffset, contentsize, font, GetAlign(), text);
}

///=============================================================================
void ffw::GuiTextEdit::EventPos(const ffw::Vec2i& pos){
}

///=============================================================================
void ffw::GuiTextEdit::EventSize(const ffw::Vec2i& size){
}

///=============================================================================
void ffw::GuiTextEdit::EventHover(bool gained){
}

///=============================================================================
void ffw::GuiTextEdit::EventFocus(bool gained){
	Redraw();
	
	if(!gained){
		cursor.Set(-1, -1);
	}
}

///=============================================================================
void ffw::GuiTextEdit::EventMouse(const ffw::Vec2i& pos){
	//std::cout << "pos: " << pos << std::endl;
}

///=============================================================================
void ffw::GuiTextEdit::RecalculateCursor(bool frommousepos){
	auto font = GetCurrentFont();
	if(font == NULL)return;

	ffw::Vec2i pos;
	const auto& mouse = GetMousePos();
	int lineheight = font->GetLineHeight();

	for(size_t i = 0; i < text.size(); i++){
		const auto& chr = text[i];

		int advance = font->GetCharAdvance(chr);

		if(frommousepos && pos.x + advance > mouse.x && pos.y + lineheight > mouse.y){
			cursor = pos;
			start = i;
			break;
		}

		if(chr == 32 || chr == 9){
			if(!frommousepos){
				if(i == start){
					cursor = pos;
					break;
				}
			}

			pos.x += advance;
			continue;

		} else if(chr == 10){
			pos.y += lineheight;

			if(frommousepos && mouse.y < pos.y){
				cursor = pos;
				cursor.y -= lineheight;
				start = i;
				break;
			}

			if(!frommousepos){
				if(i == start){
					cursor = pos;
					cursor.y -= lineheight;
					break;
				}
			}

			pos.x = 0;

			continue;
		} else if(chr <= 32){
			if(!frommousepos){
				if(i == start){
					cursor = pos;
					break;
				}
			}
			continue;
		}

		if(!frommousepos){
			if(i == start){
				cursor = pos;
				break;
			}
		}

		pos.x += advance;
		
		if(i == text.size()-1){
			start = i;
			cursor = pos;
			start = text.size();
		}
	}

	if(!frommousepos && start == text.size()){
		cursor = pos;
	}
}

///=============================================================================
void ffw::GuiTextEdit::EventMouseButton(ffw::MouseButton button, ffw::Mode mode){
	if(button == ffw::MouseButton::LEFT && mode == ffw::Mode::PRESSED){

		if(text.size() != 0){
			RecalculateCursor(true);
		} else {
			cursor.Set(0, 0);
		}

		Redraw();
	}
}

///=============================================================================
void ffw::GuiTextEdit::EventText(wchar_t chr){
	auto font = GetCurrentFont();

	if(!multi && chr == '\n')return;
	
	if(font != NULL){
		if(text.size() == 0){
			text = "X";
			text[0] = chr;
			start = 1;
			RecalculateCursor(false);
			Redraw();
		}
		else if(start <= text.size()){
			text.insert(start, 1, chr);
			start++;
			RecalculateCursor(false);
			Redraw();
		}
	}
}

///=============================================================================
void ffw::GuiTextEdit::EventKey(ffw::Key key, ffw::Mode mode){
	auto font = GetCurrentFont();

	if(font != NULL && (mode == ffw::Mode::PRESSED || mode == ffw::Mode::REPEAT)){
		if(text.size() == 0){
			if(multi && (key == ffw::Key::ENTER || key == ffw::Key::NUMPADENTER)){
				text = "\n";
				start = 1;
				RecalculateCursor(false);
				Redraw();
			}
		} else {
			if(multi && (key == ffw::Key::ENTER || key == ffw::Key::NUMPADENTER) && start <= text.size()){
				text.insert(start, 1, '\n');
				start++;
				RecalculateCursor(false);
				Redraw();
			}

			else if(key == ffw::Key::DELETEKEY && start < text.size()){
				text.erase(start, 1);
				RecalculateCursor(false);
				Redraw();
			}

			else if(key == ffw::Key::BACKSPACE && start > 0){
				text.erase(start-1, 1);
				start--;
				RecalculateCursor(false);
				Redraw();
			}

			else if(key == ffw::Key::ARROWLEFT && start > 0){
				start--;
				RecalculateCursor(false);
				Redraw();
			}

			else if(key == ffw::Key::ARROWRIGHT && start < text.size()){
				start++;
				RecalculateCursor(false);
				Redraw();
			}
		}
	}
}

///=============================================================================
ffw::Vec2i ffw::GuiTextEdit::GetMinimumWrapSize() const {
	return 0;
}