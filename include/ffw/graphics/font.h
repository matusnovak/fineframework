/* This file is part of FineFramework project */
#ifndef FFW_GRAPHICS_FONT
#define FFW_GRAPHICS_FONT
#define FFW_FT_UNICODE_MAX 65535

#include "../config.h"
#include "../math.h"
#include "texture2d.h"
#include "bufferobject.h"

namespace ffw {
    class RenderContext;
	/**
	 * @ingroup graphics
	 */
    class FFW_API Font {
    public:
		struct CharStruct{
            unsigned char* pixels;
            short texWidth;
            short texHeight;
            short width;
            short height;
            short x;
            short y;
            short left;
            short bearing;
            short advance;
            unsigned short unicode;
        };

        static bool CheckCompability(const RenderContext* renderer);
		Font();
		Font(const Font& other) = delete;
		Font(Font&& other);
        virtual ~Font();
        inline bool IsCreated() const {
			return loaded;
		}
        bool Destroy();
        bool CreateFromData(const RenderContext* renderer, const unsigned char* buffer, size_t length, int points, int dpi, int start = 0x00, int end = 0x7F);
        bool CreateFromFile(const RenderContext* renderer, const std::string& path, int points, int dpi, int start = 0x00, int end = 0x7F);
        void GetCharTexCoords(unsigned short c, ffw::Vec2f& t0, ffw::Vec2f& t1, ffw::Vec2f& t2, ffw::Vec2f& t3) const;
        inline int GetCharAdvance(unsigned short C) const {
			if(!IsCreated())return 0;
			return GetChar(C).advance;
		}
        inline ffw::Vec2i GetCharSize(unsigned short c) const {
			if(!IsCreated())return 0;
			return ffw::Vec2i(GetChar(c).width, GetChar(c).height);
		}
		inline int GetCharBearing(unsigned short c) const {
			if(!IsCreated())return 0;
			return GetChar(c).bearing;
		}
		inline int GetCharVerticalOffset(unsigned short c) const {
			if(!IsCreated())return 0;
			const auto& chr = GetChar(c);
			return (GetSize() - chr.height) + (chr.height - chr.bearing);
		}
        inline void SetLineHeight(int Height){
			lineHeight = Height;
		}
        inline int GetLineHeight() const {
			return lineHeight;
		}
        inline int GetSize() const {
			return sizePoints;
		}
		inline int GetSizeInPixels() const {
			return sizePixels;
		}
        inline int GetDpi() const {
			return sizeDpi;
		}
		inline size_t GetNumOfGlyphs() const {
			return GetChars().size();
		}
		inline const CharStruct& GetChar(unsigned short c) const {
			unsigned short id = unicodePtr[c];
			if(id < characters.size())return characters[unicodePtr[c]];
			return characters[0];
		}
		inline const std::vector<CharStruct>& GetChars() const {
			return characters;
		}
        Vec2i GetStringSize(const std::string& str) const;
        Vec2i GetStringSize(const std::wstring& str) const;
		inline const ffw::Texture2D* GetTexture() const {
			return &texture;
		}

		void swap(Font& other);

		Font& operator = (const Font& other) = delete;
		Font& operator = (Font&& other);
    private:
		bool LoadFontFace(void* face, int error, int points, int dpu, int start, int end);
		bool RenderGlyph(void* face, int index, int unicode);

		std::wstring tempchar;
		const ffw::RenderContext* rendererptr;
        ffw::Texture2D texture;

		std::vector<CharStruct> characters;
		unsigned short* unicodePtr;

		int sizePoints;
		int sizePixels;
		int sizeDpi;
		int lineHeight;
		bool loaded;
		int totalWidth;
		int totalHeight;
    };
	extern FFW_API const unsigned char* defaultFont;
	extern FFW_API const size_t defaultFontSize;
};
#endif

