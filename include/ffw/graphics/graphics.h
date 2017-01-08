/* This file is part of FineFramework project */
#ifndef FFW_GRAPHICS_DRAW
#define FFW_GRAPHICS_DRAW
#include "../config.h"
#include "rendercontext.h"
#include "texture2d.h"
#include "font.h"

namespace ffw{
	/**
	 * @ingroup graphics
	 * @brief Sets a color for the next draw operarion
	 */
	void FFW_API SetDrawColor(const ffw::Color& color);
	/**
	 * @ingroup graphics
	 * @brief Draws a a quad composed of four vertices
	 */
	void FFW_API DrawQuad(int p0x, int p0y, int p1x, int p1y, int p2x, int p2y, int p3x, int p3y);
	/**
	 * @ingroup graphics
	 * @brief Draws a polygon composed of multiple vertices
	 */
	void FFW_API DrawPolygon(const int* arr, int num);
	/**
	 * @ingroup graphics
	 */
	void FFW_API DrawTriangleFan(const int* arr, int num);
    /**
	 * @ingroup graphics
	 * @brief Draws a triangle
	 * @param posx Left top X position
	 * @param posy Left top Y position
	 * @param width Width of the rectangle
	 * @param height Height of the rectangle
	 */
	void FFW_API DrawRectangle(int posx, int posy, int width, int height);
    /**
	 * @ingroup graphics
	 */
	void FFW_API DrawTriangle(int p0x, int p0y, int p1x, int p1y, int p2x, int p2y);
    /**
	 * @ingroup graphics
	 */
	void FFW_API DrawTexture2D(int posx, int posy, int width, int height, const ffw::Texture2D* texture);
    /**
	 * @ingroup graphics
	 */
	void FFW_API DrawTexture2DMirror(int posx, int posy, int width, int height, const ffw::Texture2D* texture, bool mirrorx, bool mirrory);
    /**
	 * @ingroup graphics
	 */
	void FFW_API DrawTexture2DSub(int posx, int posy, int width, int height, const ffw::Texture2D* texture, int subx, int suby, int subw, int subh);
    /**
	 * @ingroup graphics
	 */
	void FFW_API DrawTexture2DSubMirror(int posx, int posy, int width, int height, const ffw::Texture2D* texture, int subx, int suby, int subw, int subh, bool mirrorx, bool mirrory);
    /**
	 * @ingroup graphics
	 */
	void FFW_API DrawArc(int posx, int posy, int innerradius, int outerradius, float startangle, float endangle, int steps);
	/**
	 * @ingroup graphics
	 */
    void FFW_API DrawCircle(int posx, int posy, int radius, int steps);
	/**
	 * @ingroup graphics
	 */
    void FFW_API DrawLine(int startx, int starty, int endx, int edny);
	/**
	 * @ingroup graphics
	 */
    void FFW_API DrawLineThick(int startx, int starty, int endx, int edny, int thickness);
	/**
	 * @ingroup graphics
	 */
	void FFW_API DrawString(int posx, int posy, const Font* font, const std::string& str);
	/**
	 * @ingroup graphics
	 */
	void FFW_API DrawString(int posx, int posy, const Font* font, const std::wstring& str);
	/**
	 * @ingroup graphics
	 */
	void FFW_API DrawString(int posx, int posy, const Font* font, const char* str);
	/**
	 * @ingroup graphics
	 */
	void FFW_API DrawString(int posx, int posy, const Font* font, const char* str, size_t length);
	/**
	 * @ingroup graphics
	 */
	void FFW_API DrawString(int posx, int posy, const Font* font, const wchar_t* str);
	/**
	 * @ingroup graphics
	 */
	void FFW_API DrawString(int posx, int posy, const Font* font, const wchar_t* str, size_t length);
	/**
	 * @ingroup graphics
	 */
	void FFW_API DrawBezier(int startx, int starty, int cp0x, int cp0y, int cp1x, int cp1y, int endx, int endy, int steps);
	/**
	 * @ingroup graphics
	 */
	void FFW_API DrawBezierThick(int startx, int starty, int cp0x, int cp0y, int cp1x, int cp1y, int endx, int endy, int thickness, int steps);
	/**
	 * @ingroup graphics
	 */
	class FFW_API OpenGLImageType {
	public:
		inline OpenGLImageType():
			internalFormat(0),
			format(0),
			type(0){
		}
		inline OpenGLImageType(GLint inter, GLenum form, GLenum typ):
			internalFormat(inter),
			format(form),
			type(typ){
		}
		const GLint internalFormat;
		const GLenum format;
		const GLenum type;
		inline operator bool () const {
			return (internalFormat != 0 && format != 0 && type != 0);
		}
	};
	/**
	 * @ingroup graphics
	 */
	ffw::OpenGLImageType FFW_API GetOpenGLImageType(ffw::ImageType type);
};
#endif
