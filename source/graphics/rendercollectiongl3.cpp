/*** This file is part of FineFramework project ***/

#include "ffw/graphics/rendercollectiongl3.h"
#include "ffw/graphics/font.h"
#include "ffw/graphics/texture2d.h"

///=============================================================================
ffw::RenderCollectionGL3::RenderCollectionGL3() {
}

///=============================================================================
ffw::RenderCollectionGL3::~RenderCollectionGL3() {
}

///=============================================================================
bool ffw::RenderCollectionGL3::Compile() {
	// TODO
	return false;
}
///=============================================================================
void ffw::RenderCollectionGL3::SetDrawColor(const ffw::Color& color) {
	// TODO
}

///=============================================================================
void ffw::RenderCollectionGL3::DrawQuad(int p0x, int p0y, int p1x, int p1y, int p2x, int p2y, int p3x, int p3y) {
	// TODO
}

///=============================================================================
void ffw::RenderCollectionGL3::DrawPolygon(const int* arr, int num) {
	// TODO
}

///=============================================================================
void ffw::RenderCollectionGL3::DrawTriangleFan(const int* arr, int num) {
	// TODO
}

///=============================================================================
void ffw::RenderCollectionGL3::DrawRectangle(int posx, int posy, int width, int height) {
	// TODO
}

///=============================================================================
void ffw::RenderCollectionGL3::DrawRectangleRounded(int posx, int posy, int width, int height, int topLeft, int topRight, int bottomRight, int bottomLeft, int steps) {
	// TODO
}

///=============================================================================
void ffw::RenderCollectionGL3::DrawTriangle(int p0x, int p0y, int p1x, int p1y, int p2x, int p2y) {
	// TODO
}

///=============================================================================
void ffw::RenderCollectionGL3::DrawTexture2D(int posx, int posy, int width, int height, const ffw::Texture2D* texture) {
	if (texture == NULL || !texture->IsCreated())return;
	DrawTexture2DSubMirror(posx, posy, width, height, texture, 0, 0, texture->GetWidth(), texture->GetHeight(), false, false);
}

///=============================================================================
void ffw::RenderCollectionGL3::DrawTexture2DMirror(int posx, int posy, int width, int height, const ffw::Texture2D* texture, bool mirrorx, bool mirrory) {
	if (texture == NULL || !texture->IsCreated())return;
	DrawTexture2DSubMirror(posx, posy, width, height, texture, 0, 0, texture->GetWidth(), texture->GetHeight(), mirrorx, mirrory);
}

///=============================================================================
void ffw::RenderCollectionGL3::DrawTexture2DSub(int posx, int posy, int width, int height, const ffw::Texture2D* texture, int SubX, int SubY, int SubW, int SubH) {
	DrawTexture2DSubMirror(posx, posy, width, height, texture, SubX, SubY, SubW, SubH, false, false);
}

///=============================================================================
void ffw::RenderCollectionGL3::DrawTexture2DSubMirror(int posx, int posy, int width, int height, const ffw::Texture2D* texture, int SubX, int SubY, int SubW, int SubH, bool mirrorx, bool mirrory) {
	// TODO
}

///=============================================================================
void ffw::RenderCollectionGL3::DrawArc(int posx, int posy, int innerradius, int outerradius, double startangle, double endangle, int steps) {
	// TODO
}

///=============================================================================
void ffw::RenderCollectionGL3::DrawCircle(int posx, int posy, int radius, int steps) {
	// TODO
}

///=============================================================================
void ffw::RenderCollectionGL3::DrawLine(int startx, int starty, int endx, int endy) {
	// TODO
}

///=============================================================================
void ffw::RenderCollectionGL3::DrawLineThick(int startx, int starty, int endx, int endy, int thickness) {
	// TODO
}

///=============================================================================
template <class T>
static void DrawStringFunc(int posx, int posy, const ffw::Font* font, const T* str, size_t length, float lineHeight) {
	// TODO
}

///=============================================================================
void ffw::RenderCollectionGL3::DrawString(int posx, int posy, const ffw::Font* font, const std::string& str, float lineHeight) {
	DrawStringFunc(posx, posy, font, &str[0], str.size(), lineHeight);
}

///=============================================================================
void ffw::RenderCollectionGL3::DrawString(int posx, int posy, const ffw::Font* font, const std::wstring& str, float lineHeight) {
	DrawStringFunc(posx, posy, font, &str[0], str.size(), lineHeight);
}

///=============================================================================
void ffw::RenderCollectionGL3::DrawString(int posx, int posy, const ffw::Font* font, const char* str, float lineHeight) {
	DrawStringFunc(posx, posy, font, str, SIZE_MAX, lineHeight);
}

///=============================================================================
void ffw::RenderCollectionGL3::DrawString(int posx, int posy, const ffw::Font* font, const char* str, size_t length, float lineHeight) {
	DrawStringFunc(posx, posy, font, str, length, lineHeight);
}

///=============================================================================
void ffw::RenderCollectionGL3::DrawString(int posx, int posy, const ffw::Font* font, const wchar_t* str, float lineHeight) {
	DrawStringFunc(posx, posy, font, str, SIZE_MAX, lineHeight);
}

///=============================================================================
void ffw::RenderCollectionGL3::DrawString(int posx, int posy, const ffw::Font* font, const wchar_t* str, size_t length, float lineHeight) {
	DrawStringFunc(posx, posy, font, str, length, lineHeight);
}

///=============================================================================
void ffw::RenderCollectionGL3::DrawBezier(int startx, int starty, int cp0x, int cp0y, int cp1x, int cp1y, int endx, int endy, int steps) {
	// TODO
}

///=============================================================================
void ffw::RenderCollectionGL3::DrawBezierThick(int startx, int starty, int cp0x, int cp0y, int cp1x, int cp1y, int endx, int endy, int thickness, int steps) {
	// TODO
}
