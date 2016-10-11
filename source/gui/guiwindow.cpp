/*** This file is part of FineFramework project ***/

#include "ffw/gui/guiwindow.h"

///=============================================================================
ffw::GuiWindow::GuiWindow(){
	body = new GuiLayout(this, GuiLayout::Orientation::VERTICAL);
	body->SetPos(0, 0);
	body->SetPadding(ffw::GuiUnits::Pixels(10));
	body->style.normal.background = true;
	body->style.normal.backgroundcolor = ffw::Rgb(0xF0F0F0);
	defaultfont = NULL;
	backend = NULL;

	input.chr = 0xFFFF;
	input.keymode = ffw::Mode::NONE;
	input.mousemode = ffw::Mode::NONE;
}

///=============================================================================
ffw::GuiWindow::~GuiWindow(){
	delete body;
}

///=============================================================================
void ffw::GuiWindow::SetSize(int width, int height){
	size.Set(width, height);
	body->SetSize(width, height);
	if(backend != NULL)backend->Resize(width, height);
}

///=============================================================================
void ffw::GuiWindow::SetPos(int posx, int posy){
	pos.Set(posx, posy);
}

///=============================================================================
void ffw::GuiWindow::Destroy(){
	DeleteWidgets();
}

///=============================================================================
void ffw::GuiWindow::SetBackend(GuiBackend* b){
	backend = b;
}

///=============================================================================
ffw::GuiFont* ffw::GuiWindow::CreateFontFromData(const unsigned char* buffer, size_t length, int points, int dpi, int start, int end) const {
	if(backend != NULL)return backend->CreateFontFromData(buffer, length, points, dpi, start, end);
	else return NULL;
}

///=============================================================================
ffw::GuiFont* ffw::GuiWindow::CreateFontFromFile(const std::string& path, int points, int dpi, int start, int end) const {
	if(backend != NULL)return backend->CreateFontFromFile(path, points, dpi, start, end);
	else return NULL;
}

///=============================================================================
void ffw::GuiWindow::SetScissors(const ffw::Vec2i& pos, const ffw::Vec2i& size) const {
	if(backend != NULL)backend->SetScissors(pos, size);
}

///=============================================================================
void ffw::GuiWindow::ClearWithColor(const ffw::Color& color) const {
	if(backend != NULL)backend->ClearWithColor(color);
}

///=============================================================================
void ffw::GuiWindow::SetDrawColor(const ffw::Color& color) const {
	if(backend != NULL)backend->SetDrawColor(color);
}

///=============================================================================
void ffw::GuiWindow::DrawQuad(int p0x, int p0y, int p1x, int p1y, int p2x, int p2y, int p3x, int p3y) const {
	if(backend != NULL)backend->DrawQuad(p0x, p0y, p1x, p1y, p2x, p2y, p3x, p3y);
}

///=============================================================================
void ffw::GuiWindow::DrawRectangle(const ffw::Vec2i& pos, const ffw::Vec2i& size) const {
	if(backend != NULL)backend->DrawRectangle(pos, size);
}

///=============================================================================
void ffw::GuiWindow::DrawString(const ffw::Vec2i& pos, const ffw::GuiFont* font, const std::string& str) const {
	if(backend != NULL)backend->DrawString(pos, font, str);
}

///=============================================================================
void ffw::GuiWindow::DrawLine(const ffw::Vec2i& start, const ffw::Vec2i& end, int thickness) const {
	if(backend != NULL)backend->DrawLine(start, end, thickness);
}

///=============================================================================
void ffw::GuiWindow::DrawCircle(const ffw::Vec2i& pos, int radius, int steps) const {
	if(backend != NULL)backend->DrawCircle(pos, radius, steps);
}

///=============================================================================
void ffw::GuiWindow::DrawArc(const ffw::Vec2i& pos, int inner, int outer, float start, float end, int steps) const {
	if(backend != NULL)backend->DrawArc(pos, inner, outer, start, end, steps);
}

///=============================================================================
void ffw::GuiWindow::DrawTriangleFan(const ffw::Vec2i* arr, int num) const {
	if(backend != NULL)backend->DrawTriangleFan(arr, num);
}
	
///=============================================================================
void ffw::GuiWindow::DrawStringAligned(const ffw::Vec2i& pos, const ffw::Vec2i& size, const ffw::GuiFont* font, GuiAlign align, const std::string& str) const {
	if(font == NULL)return;

	const ffw::Vec2i& strsize = font->GetStringSize(str);
	ffw::Vec2i offset = 0;

	switch (align){
	case GuiAlign::LEFT:
		offset.y = size.y/2 - strsize.y/2;
		break;

	case GuiAlign::RIGHT:
		offset.x = size.x - strsize.x;
		offset.y = size.y/2 - strsize.y/2;
		break;

	case GuiAlign::CENTER:
		offset = size/2 - strsize/2;
		break;

	case GuiAlign::TOP_CENTER:
		offset.x = size.x/2 - strsize.x/2;
		break;

	case GuiAlign::TOP_RIGHT:
		offset.x = size.x - strsize.x;
		break;

	case GuiAlign::BOTTOM_LEFT:
		offset.y = size.y - strsize.y;
		break;

	case GuiAlign::BOTTOM_CENTER:
		offset.x = size.x/2 - strsize.x/2;
		offset.y = size.y - strsize.y;
		break;

	case GuiAlign::BOTTOM_RIGHT:
		offset.x = size.x - strsize.x;
		offset.y = size.y - strsize.y;
		break;

	case GuiAlign::TOP_LEFT:
	default:
		break;
	}

	DrawString(pos + offset, font, str);
}
		
///=============================================================================
void ffw::GuiWindow::DrawBorder(const ffw::Vec2i& pos, const ffw::Vec2i& size, const GuiStyle& style) const {
	int offset[2];

	// Top
	if(style.border[0]){
		SetDrawColor(style.bordercolor[0]);
		
		int width = size.x - style.borderradius[0] - style.borderradius[1];
		ffw::Vec2i lefttop = pos;
		lefttop.x += style.borderradius[0];

		ffw::Vec2i leftbot = lefttop;
		leftbot.y += style.bordersize[0];

		ffw::Vec2i righttop = pos;
		righttop.x += size.x - style.borderradius[1];

		ffw::Vec2i rightbot = righttop;
		rightbot.y += style.bordersize[0];

		if(style.bordersize[0] > style.borderradius[0]){
			leftbot.x += (style.bordersize[0] - style.borderradius[0]);
		}

		if(style.bordersize[0] > style.borderradius[1]){
			rightbot.x -= (style.bordersize[0] - style.borderradius[1]);
		}

		if(style.borderradius[0] == 0){
			if(!style.border[3]){
				leftbot.x = pos.x;
			} else {
				leftbot.x = pos.x + style.bordersize[3];
			}
		}

		if(style.borderradius[1] == 0){
			if(!style.border[1]){
				rightbot.x = pos.x + size.x;
			} else {
				rightbot.x = pos.x + size.x - style.bordersize[1];
			}
		}

		if(width > 0){
			DrawQuad(lefttop.x, lefttop.y, righttop.x, righttop.y, rightbot.x, rightbot.y, leftbot.x, leftbot.y);
		}

		if(style.borderradius[0] > 0){
			ffw::Vec2f p1(pos.x, pos.y);
			ffw::Vec2f p2(pos.x + style.borderradius[0], pos.y);
			ffw::Vec2f po(std::max(leftbot.x, pos.x + style.borderradius[0]), std::max(leftbot.y, pos.y + style.borderradius[0]));

			p1 = p1 - po;
			p2 = p2 - po;

			float angle = ffw::Angle(p1, p2);

			if(style.borderradius[0] > style.bordersize[0]){
				DrawArc(ffw::Vec2i(pos.x + style.borderradius[0], pos.y + style.borderradius[0]), style.borderradius[0] - style.bordersize[0], style.borderradius[0], 225.0f, 225.0f + angle, 8);
			} else {
				DrawArc(ffw::Vec2i(pos.x + style.bordersize[0], pos.y + style.bordersize[0]), 0, p2.Length(), 225.0f, 225.0f + angle, 8);
			}
		}

		if(style.borderradius[1] > 0){
			ffw::Vec2f p1(pos.x + size.x, pos.y);
			ffw::Vec2f p2(pos.x + size.x - style.borderradius[1], pos.y);
			ffw::Vec2f po(std::min(rightbot.x, pos.x + size.x - style.borderradius[1]), std::max(rightbot.y, pos.y + style.borderradius[1]));

			p1 = p1 - po;
			p2 = p2 - po;

			float angle = ffw::Angle(p1, p2);

			if(style.borderradius[1] > style.bordersize[0]){
				DrawArc(ffw::Vec2i(pos.x + size.x - style.borderradius[1], pos.y + style.borderradius[1]), style.borderradius[1] - style.bordersize[0], style.borderradius[1], 315.0f - angle, 315.0f, 8);
			} else {
				DrawArc(ffw::Vec2i(pos.x + size.x - style.bordersize[0], pos.y + style.bordersize[0]), 0, p2.Length(), 315.0f - angle, 315.0f, 8);
			}
		}
	}

	// Right
	if(style.border[1]){
		SetDrawColor(style.bordercolor[1]);

		int height = size.y - style.borderradius[1] - style.borderradius[2];

		ffw::Vec2i righttop = pos;
		righttop.x += size.x;
		righttop.y += style.borderradius[1];

		ffw::Vec2i rightbot = pos;
		rightbot.x += size.x;
		rightbot.y += size.y - style.borderradius[2];

		ffw::Vec2i lefttop = righttop;
		lefttop.x -= style.bordersize[1];

		ffw::Vec2i leftbot = rightbot;
		leftbot.x -= style.bordersize[1];

		if(style.bordersize[1] > style.borderradius[1]){
			lefttop.y += (style.bordersize[1] - style.borderradius[1]);
		}

		if(style.bordersize[1] > style.borderradius[2]){
			leftbot.y -= (style.bordersize[1] - style.borderradius[2]);
		}

		if(style.borderradius[1] == 0){
			if(!style.border[0]){
				lefttop.y = pos.y;
			} else {
				lefttop.y = pos.y + style.bordersize[0];
			}
		}

		if(style.borderradius[2] == 0){
			if(!style.border[2]){
				leftbot.y = pos.y + size.y;
			} else {
				leftbot.y = pos.y + size.y - style.bordersize[2];
			}
		}

		if(height > 0){
			DrawQuad(lefttop.x, lefttop.y, righttop.x, righttop.y, rightbot.x, rightbot.y, leftbot.x, leftbot.y);
		}

		if(style.borderradius[1] > 0){
			ffw::Vec2f p1(pos.x + size.x, pos.y);
			ffw::Vec2f p2(pos.x + size.x, pos.y + style.borderradius[1]);
			ffw::Vec2f po(std::min(lefttop.x, pos.x + size.x - style.borderradius[1]), std::max(lefttop.y, pos.y + style.borderradius[1]));

			p1 = p1 - po;
			p2 = p2 - po;

			float angle = ffw::Angle(p1, p2);

			if(style.borderradius[1] > style.bordersize[1]){
				DrawArc(ffw::Vec2i(pos.x + size.x - style.borderradius[1], pos.y + style.borderradius[1]), style.borderradius[1] - style.bordersize[1], style.borderradius[1], 315.0f, 315.0f + angle, 8);
			} else {
				DrawArc(ffw::Vec2i(pos.x + size.x - style.bordersize[1], pos.y + style.bordersize[1]), 0, p2.Length(), 315.0f, 315.0f + angle, 8);
			}
		}

		if(style.borderradius[2] > 0){
			ffw::Vec2f p1(pos.x + size.x, pos.y + size.y);
			ffw::Vec2f p2(pos.x + size.x, pos.y + size.y - style.borderradius[2]);
			ffw::Vec2f po(std::min(leftbot.x, pos.x + size.x - style.borderradius[2]), std::min(leftbot.y, pos.y + size.y - style.borderradius[2]));

			p1 = p1 - po;
			p2 = p2 - po;

			float angle = ffw::Angle(p1, p2);

			if(style.borderradius[2] > style.bordersize[1]){
				DrawArc(ffw::Vec2i(pos.x + size.x - style.borderradius[2], pos.y + size.y - style.borderradius[2]), style.borderradius[2] - style.bordersize[1], style.borderradius[2], 45.0f - angle, 45.0f, 8);
			} else {
				DrawArc(ffw::Vec2i(pos.x + size.x - style.bordersize[1], pos.y + size.y - style.bordersize[1]), 0, p2.Length(), 45.0f - angle, 45.0f, 8);
			}
		}
	}

	// Bottom
	if(style.border[2]){
		SetDrawColor(style.bordercolor[2]);
		
		int width = size.x - style.borderradius[2] - style.borderradius[3];
		ffw::Vec2i lefttop = pos;
		lefttop.x += style.borderradius[3];
		lefttop.y += size.y - style.bordersize[2];

		ffw::Vec2i leftbot = pos;
		leftbot.x += style.borderradius[3];
		leftbot.y += size.y;

		ffw::Vec2i righttop = pos;
		righttop.x += size.x - style.borderradius[2];
		righttop.y += size.y - style.bordersize[2];

		ffw::Vec2i rightbot = righttop;
		rightbot.y += style.bordersize[2];

		if(style.bordersize[2] > style.borderradius[3]){
			lefttop.x += (style.bordersize[2] - style.borderradius[3]);
		}

		if(style.bordersize[2] > style.borderradius[2]){
			righttop.x -= (style.bordersize[2] - style.borderradius[2]);
		}

		if(style.borderradius[2] == 0){
			if(!style.border[1]){
				righttop.x = pos.x + size.x;
			} else {
				righttop.x = pos.x + size.x - style.bordersize[1];
			}
		}

		if(style.borderradius[3] == 0){
			if(!style.border[3]){
				lefttop.x = pos.x;
			} else {
				lefttop.x = pos.x + style.bordersize[3];
			}
		}

		if(width > 0){
			DrawQuad(lefttop.x, lefttop.y, righttop.x, righttop.y, rightbot.x, rightbot.y, leftbot.x, leftbot.y);
		}

		if(style.borderradius[2] > 0){
			ffw::Vec2f p1(pos.x + size.x, pos.y + size.y);
			ffw::Vec2f p2(pos.x + size.x - style.borderradius[2], pos.y + size.y);
			ffw::Vec2f po(std::min(righttop.x, pos.x + size.x - style.borderradius[2]), std::min(righttop.y, pos.y + size.y - style.borderradius[2]));

			p1 = p1 - po;
			p2 = p2 - po;

			float angle = ffw::Angle(p1, p2);

			if(style.borderradius[2] > style.bordersize[2]){
				DrawArc(ffw::Vec2i(pos.x + size.x - style.borderradius[2], pos.y + size.y - style.borderradius[2]), style.borderradius[2] - style.bordersize[2], style.borderradius[2], 45.0f, 45.0f + angle, 8);
			} else {
				DrawArc(ffw::Vec2i(pos.x + size.x - style.bordersize[2], pos.y + size.y - style.bordersize[2]), 0, p2.Length(), 45.0f, 45.0f + angle, 8);
			}
		}

		if(style.borderradius[3] > 0){
			ffw::Vec2f p1(pos.x, pos.y + size.y);
			ffw::Vec2f p2(pos.x + style.borderradius[3], pos.y + size.y);
			ffw::Vec2f po(std::min(righttop.x, pos.x + + style.borderradius[3]), std::min(righttop.y, pos.y + size.y - style.borderradius[3]));

			//std::cout << "p1: " << p1 << std::endl;
			//std::cout << "p2: " << p2 << std::endl;
			//std::cout << "po: " << po << std::endl;

			p1 = p1 - po;
			p2 = p2 - po;

			float angle = ffw::Angle(p1, p2);

			if(style.borderradius[3] > style.bordersize[2]){
				DrawArc(ffw::Vec2i(pos.x + style.borderradius[3], pos.y + size.y - style.borderradius[3]), style.borderradius[3] - style.bordersize[2], style.borderradius[3], 135.0f - angle, 135.0f, 8);
			} else {
				DrawArc(ffw::Vec2i(pos.x + style.bordersize[2], pos.y + size.y - style.bordersize[2]), 0, p2.Length(), 135.0f - angle, 135.0f, 8);
			}
		}
	}

	// Left
	if(style.border[3]){
		SetDrawColor(style.bordercolor[3]);

		int height = size.y - style.borderradius[3] - style.borderradius[0];

		ffw::Vec2i lefttop = pos;
		lefttop.y += style.borderradius[0];

		ffw::Vec2i leftbot = pos;
		leftbot.y += size.y - style.borderradius[3];

		ffw::Vec2i righttop = lefttop;
		righttop.x += style.bordersize[3];

		ffw::Vec2i rightbot = leftbot;
		rightbot.x += style.bordersize[3];

		if(style.bordersize[3] > style.borderradius[0]){
			righttop.y += (style.bordersize[3] - style.borderradius[0]);
		}

		if(style.bordersize[3] > style.borderradius[3]){
			rightbot.y -= (style.bordersize[3] - style.borderradius[3]);
		}

		if(style.borderradius[0] == 0){
			if(!style.border[0]){
				righttop.y = pos.y;
			} else {
				righttop.y = pos.y + style.bordersize[0];
			}
		}

		if(style.borderradius[3] == 0){
			if(!style.border[2]){
				rightbot.y = pos.y + size.y;
			} else {
				rightbot.y = pos.y + size.y - style.bordersize[2];
			}
		}

		if(height > 0){
			DrawQuad(lefttop.x, lefttop.y, righttop.x, righttop.y, rightbot.x, rightbot.y, leftbot.x, leftbot.y);
		}

		if(style.borderradius[3] > 0){
			ffw::Vec2f p1(pos.x, pos.y + size.y);
			ffw::Vec2f p2(pos.x, pos.y + size.y - style.borderradius[3]);
			ffw::Vec2f po(std::max(rightbot.x, pos.x + style.borderradius[3]), std::min(rightbot.y, pos.y + size.y - style.borderradius[3]));

			p1 = p1 - po;
			p2 = p2 - po;

			float angle = ffw::Angle(p1, p2);

			if(style.borderradius[3] > style.bordersize[1]){
				DrawArc(ffw::Vec2i(pos.x + style.borderradius[3], pos.y + size.y - style.borderradius[3]), style.borderradius[3] - style.bordersize[3], style.borderradius[3], 135.0f, 135.0f + angle, 8);
			} else {
				DrawArc(ffw::Vec2i(pos.x + style.bordersize[3], pos.y + size.y - style.bordersize[3]), 0, p2.Length(), 135.0f, 135.0f + angle, 8);
			}
		}

		if(style.borderradius[0] > 0){
			ffw::Vec2f p1(pos.x, pos.y);
			ffw::Vec2f p2(pos.x + style.borderradius[0], pos.y);
			ffw::Vec2f po(std::max(righttop.x, pos.x + style.borderradius[0]), std::max(righttop.y, pos.y + style.borderradius[0]));

			p1 = p1 - po;
			p2 = p2 - po;

			float angle = ffw::Angle(p1, p2);

			if(style.borderradius[0] > style.bordersize[3]){
				DrawArc(ffw::Vec2i(pos.x + style.borderradius[0], pos.y + style.borderradius[0]), style.borderradius[0] - style.bordersize[3], style.borderradius[0], 225.0f - angle, 225.0f, 8);
			} else {
				DrawArc(ffw::Vec2i(pos.x + style.bordersize[3], pos.y + style.bordersize[3]), 0, p2.Length(), 225.0f - angle, 225.0f, 8);
			}
		}
	}
}

///=============================================================================
void ffw::GuiWindow::DrawBackground(const ffw::Vec2i& pos, const ffw::Vec2i& size, const GuiStyle& style) const {
	SetDrawColor(style.backgroundcolor);
	if(style.borderradius[0] == 0 && style.borderradius[1] == 0 && style.borderradius[2] == 0 && style.borderradius[3] == 0){
		DrawRectangle(pos, size);
	} else {
		ffw::Vec2i points[14] = {
			{pos.x + size.x / 2, pos.y + size.y / 2},

			{pos.x, pos.y + style.borderradius[0]},
			{pos.x + style.borderradius[0], pos.y + style.borderradius[0]},
			{pos.x + style.borderradius[0], pos.y},

			{pos.x + size.x - style.borderradius[1], pos.y},
			{pos.x + size.x - style.borderradius[1], pos.y + style.borderradius[1]},
			{pos.x + size.x, pos.y + style.borderradius[1]},

			{pos.x + size.x, pos.y + size.y - style.borderradius[2]},
			{pos.x + size.x - style.borderradius[2], pos.y + size.y - style.borderradius[2]},
			{pos.x + size.x - style.borderradius[2], pos.y + size.y},

			{pos.x + style.borderradius[3], pos.y + size.y},
			{pos.x + style.borderradius[3], pos.y + size.y - style.borderradius[3]},
			{pos.x, pos.y + size.y - style.borderradius[3]},

			{pos.x, pos.y + style.borderradius[0]}
		};

		DrawTriangleFan(points, 14);

		DrawArc(ffw::Vec2i(pos.x + style.borderradius[0], pos.y + style.borderradius[0]), 0, style.borderradius[0], 180, 270, 8);

		DrawArc(ffw::Vec2i(pos.x + size.x - style.borderradius[1], pos.y + style.borderradius[1]), 0, style.borderradius[1], 270, 360, 8);

		DrawArc(ffw::Vec2i(pos.x + size.x - style.borderradius[2], pos.y + size.y - style.borderradius[2]), 0, style.borderradius[2], 0, 90, 8);

		DrawArc(ffw::Vec2i(pos.x + style.borderradius[3], pos.y + size.y - style.borderradius[3]), 0, style.borderradius[3], 90, 180, 8);
	}
}
		
///=============================================================================
void ffw::GuiWindow::SetDefaultFont(const GuiFont* font){
	defaultfont = font;
	body->Redraw();
}

///=============================================================================
const ffw::GuiFont* ffw::GuiWindow::GetDefaultFont() const {
	return defaultfont;
}

///=============================================================================
void ffw::GuiWindow::InjectMousePos(int posx, int posy){
	input.mousepos.Set(posx, posy);
}

///=============================================================================
void ffw::GuiWindow::InjectMouseButton(ffw::MouseButton button, ffw::Mode mode){
	input.mousebtn = button;
	input.mousemode = mode;
}

///=============================================================================
void ffw::GuiWindow::InjectText(wchar_t chr){
	input.chr = chr;
}

///=============================================================================
void ffw::GuiWindow::InjectKey(ffw::Key key, ffw::Mode mode){
	input.key = key;
	input.keymode = mode;
}

///=============================================================================
void ffw::GuiWindow::Update(){
	body->Update(input);
	input.mousemode = ffw::Mode::NONE;
	input.chr = 0xFFFF;
	input.keymode = ffw::Mode::NONE;
}

///=============================================================================
void ffw::GuiWindow::PoolEvents(){
	while(!eventqueue.empty()){
		auto& e = eventqueue.front();

		if(e.first != nullptr){
			e.first(e.second);
		}

		eventqueue.pop();
	}
}

///=============================================================================
void ffw::GuiWindow::Render(){
	if(backend != NULL){
		backend->StartRender();
		const auto& size = body->GetSize();
		body->Render(ffw::Vec2i(0, 0), ffw::Vec2i(size.x.value, size.y.value), ffw::Vec2i(0, 0), true);
		backend->EndRender();
	}
}

///=============================================================================
void ffw::GuiWindow::Redraw(){
	body->Redraw();
}

///=============================================================================
void ffw::GuiWindow::Invalidate(){
	body->Redraw();
}

///=============================================================================
void ffw::GuiWindow::DeleteWidgets(){
	body->DeleteWidgets();
}

///=============================================================================
void ffw::GuiWindow::AddWidget(GuiWidget* widget){
	body->AddWidget(widget);
}

///=============================================================================
void ffw::GuiWindow::PushEvent(std::function<void(GuiEvent)> callback, GuiEvent e){
	eventqueue.push(std::make_pair(callback, e));
}