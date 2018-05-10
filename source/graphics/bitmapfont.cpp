/*** This file is part of FineFramework project ***/

#include "ffw/graphics/bitmapfont.h"
#include "ffw/graphics/rendercontext.h"
#include "ffw/math/imagebuffer.h"

///=============================================================================
ffw::BitmapFont::BitmapFont(){
    offsetStart = 0;
    offsetEnd = 0;
    errorChar = 0;
}

///=============================================================================
ffw::BitmapFont::BitmapFont(BitmapFont&& other) NOEXCEPT {
    offsetStart = 0;
    offsetEnd = 0;
    errorChar = 0;
    swap(other);
}

///=============================================================================
void ffw::BitmapFont::swap(BitmapFont& other) NOEXCEPT {
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
ffw::BitmapFont& ffw::BitmapFont::operator = (BitmapFont&& other) NOEXCEPT {
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
bool ffw::BitmapFont::createFromData(
    const void* pixels, 
    const int width, const int height, 
    const ffw::ImageType format, 
    const int points, const int dpi, 
    const int start, const int end) {

    if (end <= start)return false;
    if (end == 0)return false;
    if (width <= 0 || height <= 0)return false;

    sizePoints = points;
    sizeDpi = dpi;
    sizePixels = int((points / 72.0f) * dpi);
    offsetStart = start;
    offsetEnd = end;

    bool result;
    if (format == ffw::ImageType::GRAYSCALE_8) {
        alphaOnlyFlag = true;
        result = texture.create(
            width, height, GL_RED, GL_RED, GL_UNSIGNED_BYTE
        );
    }
    else if(format == ffw::ImageType::RGB_ALPHA_8888) {
        alphaOnlyFlag = false;
        result = texture.create(
            width, height, GL_RGBA8, GL_RGBA, GL_UNSIGNED_BYTE
        );
    }
    else {
        return false;
    }

    if(result) {
        texture.setPixels(0, 0, 0, width, height, pixels);
    }
    else {
        return false;
    }

    const auto total = end - start + 1;
    characters.resize(total);

    loaded = true;
    return true;
}

///=============================================================================
void ffw::BitmapFont::setCharData(const unsigned int chr, const ffw::Font::Char& data) {
    characters[chr - offsetStart] = data;
}

///=============================================================================
bool ffw::BitmapFont::updateBuffer() {
    std::vector<ffw::Vec2f> vboData;
    vboData.reserve(characters.size() * 4 * 2);

    const auto textureWidthf = float(texture.getWidth());
    const auto textureHeightf = float(texture.getHeight());

    // Upload all pixels
    for (const auto& chr : characters) {
        vboData.emplace_back(ffw::Vec2f(chr.width + chr.bearingX, 0.0f));
        vboData.emplace_back(ffw::Vec2f(
            float(chr.x + chr.width) / textureWidthf, 
            float(chr.y) / textureHeightf)
        );

        vboData.emplace_back(ffw::Vec2f(chr.bearingX, 0.0f));
        vboData.emplace_back(ffw::Vec2f(
            float(chr.x) / textureWidthf, 
            float(chr.y) / textureHeightf)
        );

        vboData.emplace_back(ffw::Vec2f(chr.bearingX, chr.height));
        vboData.emplace_back(ffw::Vec2f(
            float(chr.x) / textureWidthf, 
            float(chr.y + chr.height) / textureHeightf)
        );

        vboData.emplace_back(ffw::Vec2f(chr.width + chr.bearingX, chr.height));
        vboData.emplace_back(ffw::Vec2f(
            float(chr.x + chr.width) / textureWidthf, 
            float(chr.y + chr.height) / textureHeightf)
        );
    }

    vbo.destroy(); // Destroy data if necessary

    // create font VBO
    if (!vbo.create(
        &vboData[0], 
        vboData.size() * sizeof(ffw::Vec2f), 
        GL_STATIC_DRAW)) {

        destroy();
        return false;
    }

    return true;
}

///=============================================================================
bool ffw::BitmapFont::createFromBuffer(const ffw::ImageBuffer& buffer, 
    const int points, const int dpi, const int start, const int end) {

    return createFromData(
        buffer.getPtr(), buffer.getWidth(), 
        buffer.getHeight(), buffer.getImageType(), 
        points, dpi, start, end
    );
}

///=============================================================================
void ffw::BitmapFont::destroy() {
    texture.destroy();
    vbo.destroy();
    characters.clear();
    offsetStart = 0;
    offsetEnd = 0;
    errorChar = 0;
    loaded = false;
}

///=============================================================================
const ffw::Font::Char& ffw::BitmapFont::getChar(const unsigned int chr) const {
    // Is outside of the range?
    if (chr < unsigned(offsetStart) || chr > unsigned(offsetEnd)) return characters[errorChar];
    // Return actual character
    return characters[chr - offsetStart];
}

///=============================================================================
int ffw::BitmapFont::getCharIndex(const unsigned int chr) const {
    // Is outside of the range?
    if (chr < unsigned(offsetStart) || chr > unsigned(offsetEnd)) return 0;
    // Return actual character
    return chr - offsetStart;
}
