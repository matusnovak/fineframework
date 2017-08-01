/*** This file is part of FineFramework project ***/

#include "ffw/graphics/bitmapfont.h"
#include "ffw/graphics/rendercontext.h"

///=============================================================================
ffw::BitmapFont::BitmapFont(){
	offsetStart = 0;
	offsetEnd = 0;
	errorChar = 0;
}

///=============================================================================
ffw::BitmapFont::BitmapFont(BitmapFont&& other) {
	offsetStart = 0;
	offsetEnd = 0;
	errorChar = 0;
	swap(other);
}

///=============================================================================
void ffw::BitmapFont::swap(BitmapFont& other) {
	using std::swap;
	if(this != &other) {
		swap(texture, other.texture);
		swap(sizePoints, other.sizePoints);
		swap(sizePixels, other.sizePixels);
		swap(sizeDpi, other.sizeDpi);
		swap(loaded, other.loaded);
		swap(characters, other.characters);
		swap(offsetStart, other.offsetStart);
		swap(offsetEnd, other.offsetEnd);
		swap(errorChar, other.errorChar);
	}
}

///=============================================================================
ffw::BitmapFont& ffw::BitmapFont::operator = (BitmapFont&& other) {
	if(this != &other) {
		swap(other);
	}
	return *this;
}

///=============================================================================
ffw::BitmapFont::~BitmapFont() {
	destroy();
}

///=============================================================================
bool ffw::BitmapFont::createFromData(const RenderContext* renderer, const void* pixels, int width, int height, ffw::ImageType format, int points, int dpi, int start, int end) {
	if (end <= start)return false;
	if (end == 0)return false;
	if (width <= 0 || height <= 0)return false;

	sizePoints = points;
	sizeDpi = dpi;
	sizePixels = int((points / 72.0f) * dpi);
	offsetStart = start;
	offsetEnd = end;

	bool result = false;
	if (format == ffw::ImageType::GRAYSCALE_8) {
		alphaOnlyFlag = true;
		result = texture.create(renderer, width, height, GL_ALPHA8, GL_ALPHA, GL_UNSIGNED_BYTE);
	}
	else if(format == ffw::ImageType::RGB_ALPHA_8888) {
		alphaOnlyFlag = false;
		result = texture.create(renderer, width, height, GL_RGBA8, GL_RGBA, GL_UNSIGNED_BYTE);
	}
	else {
		std::cerr << "Failed to choose correct format!" << std::endl;
		return false;
	}

	if(result) {
		texture.setPixels(0, 0, 0, width, height, pixels);
	}
	else {
		std::cerr << "Failed to create texture!" << std::endl;
		return false;
	}

	int total = end - start + 1;
	characters.resize(total);

	loaded = true;
	return true;
}

///=============================================================================
ffw::Font::Char& ffw::BitmapFont::setCharData(wchar_t chr) {
	return characters[chr - offsetStart];
}

///=============================================================================
bool ffw::BitmapFont::createFromBuffer(const RenderContext* renderer, const ffw::ImageBuffer& buffer, int points, int dpi, int start, int end) {
	return createFromData(renderer, buffer.getPtr(), buffer.getWidth(), buffer.getHeight(), buffer.getImageType(), points, dpi, start, end);
}

///=============================================================================
void ffw::BitmapFont::destroy() {
	texture.destroy();
	characters.clear();
	offsetStart = 0;
	offsetEnd = 0;
	errorChar = 0;
	loaded = false;
}

///=============================================================================
const ffw::Font::Char& ffw::BitmapFont::getChar(wchar_t chr) const {
	// Is outside of the range?
	if (chr < offsetStart || chr > offsetEnd)return characters[errorChar];
	// Is the character not rendered?
	if (characters[chr - offsetStart].x < 0)return characters[errorChar];
	// Return actual character
	return characters[chr - offsetStart];
}
