/*** This file is part of FineFramework project ***/

#include "ffw/graphics/rendercollectiongl1.h"
#include "ffw/graphics/font.h"
#include "ffw/graphics/texture2d.h"

///=============================================================================
ffw::RenderCollectionGL1::RenderCollectionGL1() {
}

///=============================================================================
ffw::RenderCollectionGL1::~RenderCollectionGL1() {
}

///=============================================================================
bool ffw::RenderCollectionGL1::Compile() {
	// Nothing to compile
	return true;
}
///=============================================================================
void ffw::RenderCollectionGL1::SetDrawColor(const ffw::Color& color) {
	glColor4f(color.r, color.g, color.b, color.a);
}

///=============================================================================
void ffw::RenderCollectionGL1::DrawQuad(int p0x, int p0y, int p1x, int p1y, int p2x, int p2y, int p3x, int p3y) {
	int vertices[8] = {
		p0x, p0y,
		p1x, p1y,
		p2x, p2y,
		p3x, p3y
	};

	glEnableClientState(GL_VERTEX_ARRAY);
	glVertexPointer(2, GL_INT, 0, vertices);
	glDrawArrays(GL_QUADS, 0, 4);
	glDisableClientState(GL_VERTEX_ARRAY);
}

///=============================================================================
void ffw::RenderCollectionGL1::DrawPolygon(const int* arr, int num) {
	glEnableClientState(GL_VERTEX_ARRAY);
	glVertexPointer(2, GL_INT, 0, arr);
	glDrawArrays(GL_POLYGON, 0, num);
	glDisableClientState(GL_VERTEX_ARRAY);
}

///=============================================================================
void ffw::RenderCollectionGL1::DrawTriangleFan(const int* arr, int num) {
	glEnableClientState(GL_VERTEX_ARRAY);
	glVertexPointer(2, GL_INT, 0, arr);
	glDrawArrays(GL_TRIANGLE_FAN, 0, num);
	glDisableClientState(GL_VERTEX_ARRAY);
}

///=============================================================================
void ffw::RenderCollectionGL1::DrawRectangle(int posx, int posy, int width, int height) {
	int vertices[8] = {
		posx + width, posy,
		posx, posy,
		posx, posy + height,
		posx + width, posy + height
	};

	glEnableClientState(GL_VERTEX_ARRAY);
	glVertexPointer(2, GL_INT, 0, vertices);
	glDrawArrays(GL_QUADS, 0, 4);
	glDisableClientState(GL_VERTEX_ARRAY);
}

///=============================================================================
void ffw::RenderCollectionGL1::DrawRectangleRounded(int posx, int posy, int width, int height, int topLeft, int topRight, int bottomRight, int bottomLeft, int steps) {
	glBegin(GL_POLYGON);
	ffw::Vec2i offset(posx + topLeft, posy + topLeft);
	double angle = 180.0;
	double step = 90.0 / double(steps - 1);
	for (int i = 0; i < steps; i++) {
		glVertex2d(offset.x + topLeft * cos(angle * DEG_TO_RAD), offset.y + topLeft * sin(angle * DEG_TO_RAD));
		angle += step;
	}

	offset.Set(posx + width - topRight, posy + topRight);
	angle = 270.0;
	for (int i = 0; i < steps; i++) {
		glVertex2d(offset.x + topRight * cos(angle * DEG_TO_RAD), offset.y + topRight * sin(angle * DEG_TO_RAD));
		angle += step;
	}

	offset.Set(posx + width - bottomRight, posy + height - bottomRight);
	angle = 360.0;
	for (int i = 0; i < steps; i++) {
		glVertex2d(offset.x + bottomRight * cos(angle * DEG_TO_RAD), offset.y + bottomRight * sin(angle * DEG_TO_RAD));
		angle += step;
	}

	offset.Set(posx + bottomLeft, posy + height - bottomLeft);
	angle = 90.0;
	for (int i = 0; i < steps; i++) {
		glVertex2d(offset.x + bottomLeft * cos(angle * DEG_TO_RAD), offset.y + bottomLeft * sin(angle * DEG_TO_RAD));
		angle += step;
	}

	glEnd();
}

///=============================================================================
void ffw::RenderCollectionGL1::DrawTriangle(int p0x, int p0y, int p1x, int p1y, int p2x, int p2y) {
	int vertices[6] = {
		p0x, p0y,
		p1x, p1y,
		p2x, p2y
	};

	glEnableClientState(GL_VERTEX_ARRAY);
	glVertexPointer(2, GL_INT, 0, vertices);
	glDrawArrays(GL_TRIANGLES, 0, 3);
	glDisableClientState(GL_VERTEX_ARRAY);
}

///=============================================================================
void ffw::RenderCollectionGL1::DrawTexture2D(int posx, int posy, int width, int height, const ffw::Texture2D* texture) {
	if (texture == NULL || !texture->IsCreated())return;
	DrawTexture2DSubMirror(posx, posy, width, height, texture, 0, 0, texture->GetWidth(), texture->GetHeight(), false, false);
}

///=============================================================================
void ffw::RenderCollectionGL1::DrawTexture2DMirror(int posx, int posy, int width, int height, const ffw::Texture2D* texture, bool mirrorx, bool mirrory) {
	if (texture == NULL || !texture->IsCreated())return;
	DrawTexture2DSubMirror(posx, posy, width, height, texture, 0, 0, texture->GetWidth(), texture->GetHeight(), mirrorx, mirrory);
}

///=============================================================================
void ffw::RenderCollectionGL1::DrawTexture2DSub(int posx, int posy, int width, int height, const ffw::Texture2D* texture, int SubX, int SubY, int SubW, int SubH) {
	DrawTexture2DSubMirror(posx, posy, width, height, texture, SubX, SubY, SubW, SubH, false, false);
}

///=============================================================================
void ffw::RenderCollectionGL1::DrawTexture2DSubMirror(int posx, int posy, int width, int height, const ffw::Texture2D* texture, int SubX, int SubY, int SubW, int SubH, bool mirrorx, bool mirrory) {
	if (texture == NULL || !texture->IsCreated())return;

	int vertices[8] = {
		posx + width, posy,
		posx, posy,
		posx, posy + height,
		posx + width, posy + height
	};

	float sx = SubX / static_cast<float>(texture->GetWidth());
	float sy = SubY / static_cast<float>(texture->GetHeight());
	float sw = SubW / static_cast<float>(texture->GetWidth());
	float sh = SubH / static_cast<float>(texture->GetHeight());

	float textureCoords[8] = {
		sx + sw, sy,
		sx, sy,
		sx, sy + sh,
		sx + sw, sy + sh
	};

	if (mirrory) {
		std::swap(textureCoords[0], textureCoords[6]);
		std::swap(textureCoords[1], textureCoords[7]);

		std::swap(textureCoords[2], textureCoords[4]);
		std::swap(textureCoords[3], textureCoords[5]);
	}

	if (mirrorx) {
		std::swap(textureCoords[0], textureCoords[2]);
		std::swap(textureCoords[1], textureCoords[3]);

		std::swap(textureCoords[4], textureCoords[6]);
		std::swap(textureCoords[5], textureCoords[7]);
	}

	glEnable(GL_TEXTURE_2D);
	texture->Bind();
	glEnableClientState(GL_VERTEX_ARRAY);
	glEnableClientState(GL_TEXTURE_COORD_ARRAY);
	glTexCoordPointer(2, GL_FLOAT, 0, textureCoords);
	glVertexPointer(2, GL_INT, 0, vertices);
	glDrawArrays(GL_QUADS, 0, 4);
	glDisableClientState(GL_TEXTURE_COORD_ARRAY);
	glDisableClientState(GL_VERTEX_ARRAY);
	glDisable(GL_TEXTURE_2D);
}

///=============================================================================
void ffw::RenderCollectionGL1::DrawArc(int posx, int posy, int innerradius, int outerradius, double startangle, double endangle, int steps) {
	if (innerradius > outerradius)std::swap(innerradius, outerradius);

	double start = startangle * DEG_TO_RAD;
	double end = endangle * DEG_TO_RAD;
	double step = (end - start) / double(steps);
	double angle = start;

	glEnableClientState(GL_VERTEX_ARRAY);

	for (int i = 0; i < steps; i++) {
		double angleNew = angle + step;

		double vertices[8] = {
			double(innerradius * cos(angle) + posx), double(innerradius * sin(angle) + posy),
			double(outerradius * cos(angle) + posx), double(outerradius * sin(angle) + posy),
			double(outerradius * cos(angleNew) + posx), double(outerradius * sin(angleNew) + posy),
			double(innerradius * cos(angleNew) + posx), double(innerradius * sin(angleNew) + posy),
		};

		glVertexPointer(2, GL_DOUBLE, 0, vertices);
		glDrawArrays(GL_QUADS, 0, 4);

		angle = angleNew;
	}

	glDisableClientState(GL_VERTEX_ARRAY);
}

///=============================================================================
void ffw::RenderCollectionGL1::DrawCircle(int posx, int posy, int radius, int steps) {
	DrawArc(posx, posy, 0, radius, 0, 360, steps);
}

///=============================================================================
void ffw::RenderCollectionGL1::DrawLine(int startx, int starty, int endx, int endy) {
	int vertices[4] = {
		startx, starty,
		endx, endy
	};

	glEnableClientState(GL_VERTEX_ARRAY);
	glVertexPointer(2, GL_INT, 0, vertices);
	glDrawArrays(GL_LINES, 0, 2);
	glDisableClientState(GL_VERTEX_ARRAY);
}

///=============================================================================
void ffw::RenderCollectionGL1::DrawLineThick(int startx, int starty, int endx, int endy, int thickness) {
	ffw::Vec2f dir(float(endx - startx), float(endy - starty));
	dir = ffw::Vec2f(dir.y, -dir.x);
	dir.Normalize();
	dir *= float(thickness / 2);

	int vertices[8] = {
		int(startx + dir.x), int(starty + dir.y),
		int(endx + dir.x), int(endy + dir.y),
		int(endx - dir.x), int(endy - dir.y),
		int(startx - dir.x), int(starty - dir.y)
	};

	glEnableClientState(GL_VERTEX_ARRAY);
	glVertexPointer(2, GL_INT, 0, vertices);
	glDrawArrays(GL_QUADS, 0, 4);
	glDisableClientState(GL_VERTEX_ARRAY);
}

///=============================================================================
template <class T>
static void DrawStringFunc(int posx, int posy, const ffw::Font* font, const T* str, size_t length, float lineHeight) {
	if (font == NULL || !font->IsCreated())return;

	glEnable(GL_TEXTURE_2D);
	font->GetTexture()->Bind();
	glEnableClientState(GL_VERTEX_ARRAY);
	glEnableClientState(GL_TEXTURE_COORD_ARRAY);

	int advance = posx;
	int height = posy;
	size_t count = 0;
	while (*str != '\0' && count < length) {
		auto chr = *str;
		str++;
		count++;

		if (chr == 32 || chr == 9) {
			advance += font->GetCharAdvance(chr);
			continue;

		}
		else if (chr == 10) {
			height += int(lineHeight * font->GetSizeInPixels());
			advance = posx;
			continue;
		}
		else if (chr <= 32) {
			continue;
		}

		const auto chrSize = font->GetCharSize(chr);
		int offset = font->GetCharVerticalOffset(chr);

		int vertices[8] = {
			advance + chrSize.x, height + offset,
			advance, height + offset,
			advance, height + chrSize.y + offset,
			advance + chrSize.x, height + chrSize.y + offset
		};

		ffw::Vec2f t0, t1, t2, t3;
		font->GetCharTexCoords(chr, t0, t1, t2, t3);

		float textureCoords[8] = {
			t1.x, t1.y,
			t0.x, t0.y,
			t3.x, t3.y,
			t2.x, t2.y
		};

		glTexCoordPointer(2, GL_FLOAT, 0, textureCoords);
		glVertexPointer(2, GL_INT, 0, vertices);
		glDrawArrays(GL_QUADS, 0, 4);

		advance += font->GetCharAdvance(chr);
	}

	glDisableClientState(GL_TEXTURE_COORD_ARRAY);
	glDisableClientState(GL_VERTEX_ARRAY);

	glDisable(GL_TEXTURE_2D);
}

///=============================================================================
void ffw::RenderCollectionGL1::DrawString(int posx, int posy, const ffw::Font* font, const std::string& str, float lineHeight) {
	DrawStringFunc(posx, posy, font, &str[0], str.size(), lineHeight);
}

///=============================================================================
void ffw::RenderCollectionGL1::DrawString(int posx, int posy, const ffw::Font* font, const std::wstring& str, float lineHeight) {
	DrawStringFunc(posx, posy, font, &str[0], str.size(), lineHeight);
}

///=============================================================================
void ffw::RenderCollectionGL1::DrawString(int posx, int posy, const ffw::Font* font, const char* str, float lineHeight) {
	DrawStringFunc(posx, posy, font, str, SIZE_MAX, lineHeight);
}

///=============================================================================
void ffw::RenderCollectionGL1::DrawString(int posx, int posy, const ffw::Font* font, const char* str, size_t length, float lineHeight) {
	DrawStringFunc(posx, posy, font, str, length, lineHeight);
}

///=============================================================================
void ffw::RenderCollectionGL1::DrawString(int posx, int posy, const ffw::Font* font, const wchar_t* str, float lineHeight) {
	DrawStringFunc(posx, posy, font, str, SIZE_MAX, lineHeight);
}

///=============================================================================
void ffw::RenderCollectionGL1::DrawString(int posx, int posy, const ffw::Font* font, const wchar_t* str, size_t length, float lineHeight) {
	DrawStringFunc(posx, posy, font, str, length, lineHeight);
}

///=============================================================================
void ffw::RenderCollectionGL1::DrawBezier(int startx, int starty, int cp0x, int cp0y, int cp1x, int cp1y, int endx, int endy, int steps) {
}

///=============================================================================
void ffw::RenderCollectionGL1::DrawBezierThick(int startx, int starty, int cp0x, int cp0y, int cp1x, int cp1y, int endx, int endy, int thickness, int steps) {
}
