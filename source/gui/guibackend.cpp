/*** This file is part of FineFramework project ***/

#include "ffw/gui/guibackend.h"
#include "ffw/math/functions.h"

///=============================================================================
void ffw::GuiBackend::drawBackground(const ffw::Vec2f& pos_, const ffw::Vec2f& size_, const ffw::GuiStyle::Background& background, bool ignore) const {
	const auto pos = pos_.floor();
	const auto size = size_.ceil();
	
	(void)ignore;
	if (!background)return;
	if (background.radius[0] > 0 || 
		background.radius[1] > 0 || 
		background.radius[2] > 0 || 
		background.radius[3] > 0) {
		drawRectangleRounded(pos, size, background.color, background.radius[0], background.radius[1], background.radius[2], background.radius[3]);
	} else {
		drawRectangle(pos, size, background.color);
	}
}

///=============================================================================
void ffw::GuiBackend::drawBorder(const ffw::Vec2f& pos_, const ffw::Vec2f& size_, const ffw::GuiStyle::Border& border) const {
	const auto pos = pos_.floor();
	const auto size = size_.ceil();
	
	ffw::Vec4f top;
	top.x = border.radius[0];
	top.y = std::max(border.radius[0], border.size[3]);
	top.z = std::max(border.radius[1], border.size[1]);
	top.w = border.radius[1];

	if (border.size[3] > border.radius[0] && border.size[0] < border.radius[0]) {
		top.y = ffw::lerp(border.radius[0], border.size[3], border.size[0] / border.radius[0]);
	}

	if (border.size[1] > border.radius[1] && border.size[0] < border.radius[1]) {
		top.z = ffw::lerp(border.radius[1], border.size[1], border.size[0] / border.radius[1]);
	}

	ffw::Vec4f right;
	right.x = border.radius[1];
	right.y = std::max(border.radius[1], border.size[0]);
	right.z = std::max(border.radius[2], border.size[2]);
	right.w = border.radius[2];

	if (border.size[0] > border.radius[1] && border.size[1] < border.radius[1]) {
		right.y = ffw::lerp(border.radius[1], border.size[0], border.size[1] / border.radius[1]);
	}

	if (border.size[2] > border.radius[2] && border.size[1] < border.radius[2]) {
		right.z = ffw::lerp(border.radius[2], border.size[2], border.size[1] / border.radius[2]);
	}

	ffw::Vec4f bottom;
	bottom.x = border.radius[2];
	bottom.y = std::max(border.radius[2], border.size[1]);
	bottom.z = std::max(border.radius[3], border.size[3]);
	bottom.w = border.radius[3];

	if (border.size[1] > border.radius[2] && border.size[2] < border.radius[2]) {
		bottom.y = ffw::lerp(border.radius[2], border.size[1], border.size[2] / border.radius[2]);
	}

	if (border.size[3] > border.radius[3] && border.size[2] < border.radius[3]) {
		bottom.z = ffw::lerp(border.radius[3], border.size[3], border.size[2] / border.radius[3]);
	}

	ffw::Vec4f left;
	left.x = border.radius[3];
	left.y = std::max(border.radius[3], border.size[2]);
	left.z = std::max(border.radius[0], border.size[0]);
	left.w = border.radius[0];

	if (border.size[2] > border.radius[3] && border.size[3] < border.radius[3]) {
		left.y = ffw::lerp(border.radius[3], border.size[2], border.size[3] / border.radius[1]);
	}

	if (border.size[0] > border.radius[0] && border.size[3] < border.radius[0]) {
		left.z = ffw::lerp(border.radius[0], border.size[0], border.size[3] / border.radius[2]);
	}
	
	// Top border
	if(border.size[0]) {
		drawQuad(pos + ffw::Vec2f(top.x, 0),
				 pos + ffw::Vec2f(top.y, border.size[0]),
				 pos + ffw::Vec2f(size.x - top.z, border.size[0]),
				 pos + ffw::Vec2f(size.x - top.w, 0),
				 border.color[0]);
	}

	// Right border
	if (border.size[1]) {
		drawQuad(pos + ffw::Vec2f(size.x, right.x),
				 pos + ffw::Vec2f(size.x - border.size[1], right.y),
				 pos + ffw::Vec2f(size.x - border.size[1], size.y - right.z),
				 pos + ffw::Vec2f(size.x, size.y - right.w),
				 border.color[1]);
	}

	// Bottom border
	if (border.size[2]) {
		drawQuad(pos + ffw::Vec2f(size.x - bottom.x, size.y),
				 pos + ffw::Vec2f(size.x - bottom.y, size.y - border.size[2]),
				 pos + ffw::Vec2f(bottom.z, size.y - border.size[2]),
				 pos + ffw::Vec2f(bottom.w, size.y),
				 border.color[2]);
	}

	// Left border
	if (border.size[3]) {
		drawQuad(pos + ffw::Vec2f(0, size.y - left.x),
				 pos + ffw::Vec2f(border.size[3], size.y - left.y),
				 pos + ffw::Vec2f(border.size[3], left.z),
				 pos + ffw::Vec2f(0, left.w),
				 border.color[3]);
	}

	if((border.size[0] > 0 || border.size[3] > 0) && border.radius[0] > 0) {
		static int count = 0;
		ffw::Vec2f p1(pos.x + top.x, pos.y);
		ffw::Vec2f p2(pos.x, pos.y + left.w);
		ffw::Vec2f p0(std::max(pos.x + border.size[3], pos.x + border.radius[0]), std::max(pos.y + border.size[0], pos.y + border.radius[0]));
		ffw::Vec2f c(pos.x, pos.y);

		if (border.size[3] == border.size[0] && border.color[3] == border.color[0]) {
			auto angle = ffw::angle((p2 - p0), (c - p0));
			auto offset = ffw::angle((p2 - p0), ffw::Vec2f(-1.0f, 0.0f));

			auto len = ffw::distance(p2, p0);
			drawArc(p0, len - border.size[3], len, float(180.f + offset), float(180.0f + offset + angle*2), border.color[3]);
		} 
		else {
			if (border.size[0]) {
				auto angle = ffw::angle((p1 - p0), (c - p0));
				auto offset = ffw::angle((p1 - p0), ffw::Vec2f(0.0f, -1.0f));

				auto len = ffw::distance(p1, p0);
				drawArc(p0, len - border.size[0], len, float(270.f - offset - angle), float(270.0f - offset), border.color[0]);
			}

			if (border.size[3]) {
				auto angle = ffw::angle((p2 - p0), (c - p0));
				auto offset = ffw::angle((p2 - p0), ffw::Vec2f(-1.0f, 0.0f));

				auto len = ffw::distance(p2, p0);
				drawArc(p0, len - border.size[3], len, float(180.f + offset), float(180.0f + offset + angle), border.color[3]);
			}
		}
	}

	if ((border.size[0] > 0 || border.size[1] > 0) && border.radius[1] > 0) {
		ffw::Vec2f p1(pos.x + size.x - top.w, pos.y);
		ffw::Vec2f p2(pos.x + size.x, pos.y + right.x);
		ffw::Vec2f p0(std::min(pos.x + size.x - border.size[1], pos.x + size.x - border.radius[1]), std::max(pos.y + border.size[0], pos.y + border.radius[1]));
		ffw::Vec2f c(pos.x + size.x, pos.y);

		if(border.size[0] == border.size[1] && border.color[0] == border.color[1]) {
			auto angle = ffw::angle((p1 - p0), (c - p0));
			auto offset = ffw::angle((p1 - p0), ffw::Vec2f(0.0f, -1.0f));
			auto len = ffw::distance(p1, p0);
			drawArc(p0, len - border.size[0], len, float(270.f + offset), float(270.0f + offset + angle*2), border.color[0]);
		}
		else {
			if (border.size[0] > 0) {
				auto angle = ffw::angle((p1 - p0), (c - p0));
				auto offset = ffw::angle((p1 - p0), ffw::Vec2f(0.0f, -1.0f));

				auto len = ffw::distance(p1, p0);
				drawArc(p0, len - border.size[0], len, float(270.f + offset), float(270.0f + offset + angle), border.color[0]);
			}

			if (border.size[1] > 0) {
				auto angle = ffw::angle((p2 - p0), (c - p0));
				auto offset = ffw::angle((p2 - p0), ffw::Vec2f(1.0f, 0.0f));

				auto len = ffw::distance(p2, p0);
				drawArc(p0, len - border.size[1], len, float(360.0f - offset - angle), float(360.0f - offset), border.color[1]);
			}
		}
	}

	if ((border.size[1] > 0 || border.size[2] > 0) && border.radius[2] > 0) {
		ffw::Vec2f p1(pos.x + size.x, pos.y + size.y - right.w);
		ffw::Vec2f p2(pos.x + size.x - bottom.x, pos.y + size.y);
		ffw::Vec2f p0(std::min(pos.x + size.x - border.size[1], pos.x + size.x - border.radius[2]), std::min(pos.y + size.y - border.size[2], pos.y + size.y - border.radius[2]));
		ffw::Vec2f c(pos.x + size.x, pos.y + size.y);

		if (border.size[1] == border.size[2] && border.color[1] == border.color[2]) {
			auto angle = ffw::angle((p1 - p0), (c - p0));
			auto offset = ffw::angle((p1 - p0), ffw::Vec2f(1.0f, 0.0f));

			auto len = ffw::distance(p1, p0);
			drawArc(p0, len - border.size[1], len, float(offset), float(offset + angle*2), border.color[1]);
		}
		else {
			if (border.size[1] > 0) {
				auto angle = ffw::angle((p1 - p0), (c - p0));
				auto offset = ffw::angle((p1 - p0), ffw::Vec2f(1.0f, 0.0f));

				auto len = ffw::distance(p1, p0);
				drawArc(p0, len - border.size[1], len, float(offset), float(offset + angle), border.color[1]);
			}

			if (border.size[2] > 0) {
				auto angle = ffw::angle((p2 - p0), (c - p0));
				auto offset = ffw::angle((p2 - p0), ffw::Vec2f(0.0f, 1.0f));

				auto len = ffw::distance(p2, p0);
				drawArc(p0, len - border.size[2], len, float(90.0f - offset - angle), float(90.0f - offset), border.color[2]);
			}
		}
	}

	if ((border.size[2] > 0 || border.size[3] > 0) && border.radius[3] > 0) {
		ffw::Vec2f p1(pos.x + bottom.w, pos.y + size.y);
		ffw::Vec2f p2(pos.x, pos.y + size.y - left.x);
		ffw::Vec2f p0(std::max(pos.x + border.size[3], pos.x + border.radius[3]), std::min(pos.y + size.y - border.size[2], pos.y + size.y - border.radius[3]));
		ffw::Vec2f c(pos.x, pos.y + size.y);

		if (border.size[2] == border.size[3] && border.color[2] == border.color[3]) {
			auto angle = ffw::angle((p1 - p0), (c - p0));
			auto offset = ffw::angle((p1 - p0), ffw::Vec2f(0.0f, 1.0f));

			auto len = ffw::distance(p1, p0);
			drawArc(p0, len - border.size[2], len, float(90.0f + offset), float(90.0f + offset + angle*2), border.color[2]);
		}
		else {
			if (border.size[2] > 0) {
				auto angle = ffw::angle((p1 - p0), (c - p0));
				auto offset = ffw::angle((p1 - p0), ffw::Vec2f(0.0f, 1.0f));

				auto len = ffw::distance(p1, p0);
				drawArc(p0, len - border.size[2], len, float(90.0f + offset), float(90.0f + offset + angle), border.color[2]);
			}

			if (border.size[3] > 0) {
				auto angle = ffw::angle((p2 - p0), (c - p0));
				auto offset = ffw::angle((p2 - p0), ffw::Vec2f(-1.0f, 0.0f));

				auto len = ffw::distance(p2, p0);
				drawArc(p0, len - border.size[3], len, float(180.0f - offset - angle), float(180.0f - offset), border.color[3]);
			}
		}
	}
}

///=============================================================================
void ffw::GuiBackend::drawStringAligned(const ffw::Vec2f& pos, const ffw::Vec2f& size, const ffw::GuiFont* font, ffw::GuiStyle::Align align, const std::wstring& str, const ffw::GuiStyle::Text& text, float lineHeight) const {
	if(font == NULL)return;

	const ffw::Vec2f& strsize = font->getStringSize(str);
	ffw::Vec2f offset = 0;

	switch (align){
	case GuiStyle::Align::LEFT:
		offset.y = size.y/2 - strsize.y/2;
		break;

	case GuiStyle::Align::RIGHT:
		offset.x = size.x - strsize.x;
		offset.y = size.y/2 - strsize.y/2;
		break;

	case GuiStyle::Align::CENTER:
		offset = size/2 - strsize/2;
		break;

	case GuiStyle::Align::TOP_CENTER:
		offset.x = size.x/2 - strsize.x/2;
		break;

	case GuiStyle::Align::TOP_RIGHT:
		offset.x = size.x - strsize.x;
		break;

	case GuiStyle::Align::BOTTOM_LEFT:
		offset.y = size.y - strsize.y;
		break;

	case GuiStyle::Align::BOTTOM_CENTER:
		offset.x = size.x/2 - strsize.x/2;
		offset.y = size.y - strsize.y;
		break;

	case GuiStyle::Align::BOTTOM_RIGHT:
		offset.x = size.x - strsize.x;
		offset.y = size.y - strsize.y;
		break;

	case GuiStyle::Align::TOP_LEFT:
	default:
		break;
	}

	drawString((pos + offset).floor(), font, str, text.color, lineHeight);
}