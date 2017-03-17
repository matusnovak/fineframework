/*** This file is part of FineFramework project ***/

#include "ffw/graphics/truetypefont.h"
#include "ffw/graphics/rendercontext.h"

static int totalTextureW = 7;
static int availableTextureW[7] = { 64, 128, 256, 512, 1024, 2048, 4096 };
static int pow2[7] = { 4, 8, 16, 32, 64, 128, 256 };

template<class T>
static T GetUpperMultiple(T val, T mul) {
	if(val % mul == 0) return val;
	return ((val / mul) + 1) * mul;
}

///=============================================================================
static int next_p2(int a) {
	for (int i = 0; i < 8; i++) {
		if (a < pow2[i])return pow2[i];
	}
	return 2;
}

///=============================================================================
ffw::TrueTypeFont::TrueTypeFont(){
	offsetStart = 0;
	offsetEnd = 0;
}

///=============================================================================
ffw::TrueTypeFont::TrueTypeFont(TrueTypeFont&& other) {
	offsetStart = 0;
	offsetEnd = 0;
	swap(other);
}

///=============================================================================
void ffw::TrueTypeFont::swap(TrueTypeFont& other) {
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
		swap(freeType, other.freeType);
		swap(alphaOnlyFlag, other.alphaOnlyFlag);
	}
}

///=============================================================================
ffw::TrueTypeFont& ffw::TrueTypeFont::operator = (TrueTypeFont&& other) {
	if(this != &other) {
		swap(other);
	}
	return *this;
}

///=============================================================================
ffw::TrueTypeFont::~TrueTypeFont() {
	destroy();
}

///=============================================================================
bool ffw::TrueTypeFont::createFromData(const RenderContext* renderer, const unsigned char* buffer, size_t length, int points, int dpi, int start, int end) {
	if (end <= start)return false;
	if (end == 0)return false;
	if (!freeType.createFromData(buffer, length))return false;
	if (!freeType.setSize(points, dpi))return false;
	sizePoints = points;
	sizeDpi = dpi;
	alphaOnlyFlag = true;
	return fillData(renderer, start, end);
}

///=============================================================================
bool ffw::TrueTypeFont::createFromFile(const RenderContext* renderer, const std::string& path, int points, int dpi, int start, int end) {
	if (end <= start)return false;
	if (end == 0)return false;
	if (!freeType.createFromFile(path))return false;
	if (!freeType.setSize(points, dpi))return false;
	sizePoints = points;
	sizeDpi = dpi;
	alphaOnlyFlag = true;
	return fillData(renderer, start, end);
}

///=============================================================================
bool ffw::TrueTypeFont::fillData(const RenderContext* renderer, int start, int end) {
	if(loaded) {
		characters.clear();
		texture.destroy();
	}
	sizePixels = freeType.getSizePixels();

	if(!freeType.findErrorGlyph()) {
		destroy();
		//std::cout << "find glyph 0 error" << std::endl;
		return false;
	}

	int total = end - start + 2;
	offsetEnd = end;
	offsetStart = start;

	std::vector<FreeTypeLoader::CharData> charsTemp;
	charsTemp.resize(total);
	characters.resize(total);

	// Render error glyph
	if (!freeType.getGlyphData(&charsTemp[0])) {
		destroy();
		//std::cerr << "render glyph 0 error" << std::endl;
		return false;
	}

	// Render all glyphs
	for(int i = start; i <= end; i++) {
		int index = i - start + 1;
		int unicode = i;

		if (!freeType.findGlyph(unicode)) {
			continue;
		}

		if (!freeType.getGlyphData(&charsTemp[index])) {
			destroy();
			//std::cerr << "render glyph " << unicode << " error" << std::endl;
			return false;
		}
	}

	static const int widths[] = {64, 128, 256, 512, 1024, 2048, 4096};

	int posx = 0;
	int posy = 0;
	int lineHeight = 0;
	bool found = true;
	int lastPosY = 0;
	int textureHeight = 0;
	int textureWidth = 0;

	for(int totalWidth : widths) {
		posx = 0;
		posy = 0;
		lineHeight = 0;
		found = true;
		textureHeight = totalWidth;
		textureWidth = totalWidth;

		for (size_t i = 0; i < charsTemp.size(); i++) {
			const auto& chr = charsTemp[i];
			if(chr.pixels == nullptr) {
				characters[i].x = -1;
				characters[i].y = -1;
				continue;
			}

			int texWidth = GetUpperMultiple((int)chr.width, 4);
			int texHeight = GetUpperMultiple((int)chr.height, 4);

			// Check horizontal space
			if(posx + texWidth > totalWidth) {
				posx = 0;
				posy += lineHeight;
				lineHeight = 0;

				// If we run out of rows, break and try bigger texture size
				if(posy >= totalWidth) {
					found = false;
					break;
				}
			}

			// Check vertical space
			if (posy + texHeight > totalWidth) {
				found = false;
				break;
			}

			// get highest character in row
			lineHeight = std::max(lineHeight, (int)chr.height);
			lastPosY = posy + lineHeight;

			characters[i].x = posx;
			characters[i].y = posy;

			// Move right
			posx += chr.width;
		}

		if(found) {
			break;
		}
	}

	if(!found) {
		destroy();
		//std::cerr << "Can not fit all characters even into the biggest texture! Points or DPI is too big!" << std::endl;
		return false;
	}

	// Check if we can split texture in half verticaly
	if (textureHeight / lastPosY >= 2) {
		textureHeight = textureHeight / 2;
	}

	//std::cout << "texture of size: " << textureWidth << "x" << textureHeight << " chosen" << std::endl;

	for(size_t i = 0; i < characters.size(); i++) {
		if (charsTemp[i].pixels != nullptr) {
			characters[i].width = charsTemp[i].width;
			characters[i].height = charsTemp[i].height;
			characters[i].advance = charsTemp[i].advance;
			characters[i].bearing = charsTemp[i].bearing;
		} else {
			characters[i].width = 0;
			characters[i].height = 0;
			characters[i].advance = 0;
			characters[i].bearing = 0;
		}
	}

	// create font texture
	if (!texture.create(renderer, textureWidth, textureHeight, GL_ALPHA8, GL_ALPHA, GL_UNSIGNED_BYTE)) {
		destroy();
		return false;
	}

	texture.bind();

	// Upload all pixels
	for (size_t i = 0; i < characters.size(); i++) {
		const auto& chr = characters[i];
		if (charsTemp[i].pixels == nullptr)continue;

		// Upload pixels to texture
		int texWidth = GetUpperMultiple((int)chr.width, 4);
		int texHeight = GetUpperMultiple((int)chr.height, 4);
		texture.setPixels(0, chr.x, chr.y, texWidth, texHeight, charsTemp[i].pixels);
		delete[] charsTemp[i].pixels;
		charsTemp[i].pixels = NULL;
	}

	texture.generateMipmaps();
	texture.setTexParami(GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	texture.setTexParami(GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	texture.setEnvParami(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
	texture.unbind();

	//std::cerr << "all glyphs rendered" << std::endl;
	loaded = true;
	return true;
}

///=============================================================================
void ffw::TrueTypeFont::destroy() {
	texture.destroy();
	freeType.destroy();
	characters.clear();
	offsetStart = 0;
	offsetEnd = 0;
	loaded = false;
}

///=============================================================================
const ffw::Font::Char& ffw::TrueTypeFont::getChar(wchar_t chr) const {
	// Is outside of the range?
	if (chr < offsetStart || chr > offsetEnd)return characters[0];
	// Is the character not rendered?
	if (characters[chr - offsetStart + 1].x < 0)return characters[0];
	// Return actual character
	return characters[chr - offsetStart + 1];
}
