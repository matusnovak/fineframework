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
		struct Char {
			unsigned short x = 0;
			unsigned short y = 0;
			unsigned short width = 0;
			unsigned short height = 0;
			unsigned short advance = 0;
			unsigned short bearing = 0;
		};

		Font();
		virtual ~Font();
		static bool checkCompability(const RenderContext* renderer);

		virtual void destroy() = 0;
		virtual const Char& getChar(wchar_t chr) const = 0;
		virtual ffw::Vec2i getStringSize(const std::string& str, float lineHeight = 1.25f) const;
		virtual ffw::Vec2i getStringSize(const std::wstring& str, float lineHeight = 1.25f) const;

		inline int getSizePt() const {
			return sizePoints;
		}
		inline int getSizePixels() const {
			return sizePoints;
		}
		inline int getDpi() const  {
			return sizePoints;
		}
		inline const ffw::Texture2D* getTexture() const {
			return &texture;
		}
		inline bool isCreated() const {
			return loaded;
		}
		inline int getCharVerticalOffset(const Font::Char& data) const {
			return (sizePixels - data.height) + (data.height - data.bearing);
		}
		inline bool isAlphaOnly() const {
			return alphaOnlyFlag;
		}
    protected:
		template<class T>
		ffw::Vec2i getStringSizeFunc(const std::basic_string<T>& str, float lineHeight) const;
        ffw::Texture2D texture;
		int sizePoints;
		int sizePixels;
		int sizeDpi;
		bool loaded;
		bool alphaOnlyFlag;
    };
};
#endif

