/*** This file is part of FineFramework project ***/

#include "ffw/graphics/font.h"
#include "ffw/graphics/rendercontext.h"

///=============================================================================
ffw::Font::Font() {
	sizePoints = 0;
	sizePixels = 0;
	sizeDpi = 0;
	loaded = 0;
}

///=============================================================================
ffw::Font::~Font() {
}

///=============================================================================
bool ffw::Font::checkCompability(const RenderContext* renderer) {
	return (ffw::Texture2D::checkCompability(renderer));
}

///=============================================================================
template<class T>
ffw::Vec2i ffw::Font::getStringSizeFunc(const std::basic_string<T>& str, float lineHeight) const {
	if (!isCreated())return ffw::Vec2i(0, 0);

	int height = int(getSizePixels() * lineHeight);
	ffw::Vec2i size(0, height);
	int width = 0;

	for(size_t i = 0; i < str.size(); i++) {
		if(str[i] == '\n') {
			size.y += height;
			size.x = std::max(width, size.x);
			width = 0;
			continue;
		}

		const Font::Char& chr = getChar(str[i]);
		size.x += chr.advance;
	}

	size.x = std::max(width, size.x);
	return size;
}

///=============================================================================
ffw::Vec2i ffw::Font::getStringSize(const std::wstring& str, float lineHeight) const {
	return getStringSizeFunc<wchar_t>(str, lineHeight);
}

///=============================================================================
ffw::Vec2i ffw::Font::getStringSize(const std::string& str, float lineHeight) const {
	return getStringSizeFunc<char>(str, lineHeight);
}