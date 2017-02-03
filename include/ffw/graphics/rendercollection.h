/* This file is part of FineFramework project */
#ifndef FFW_RENDER_COLLECTION
#define FFW_RENDER_COLLECTION
#include "renderextensionsgl.h"
#include "../math.h"

namespace ffw {
	class Font;
	class Texture2D;
	/**
	* @ingroup graphics
	*/
	class FFW_API RenderCollection: public RenderExtensions {
	public:
		RenderCollection();
		virtual ~RenderCollection();
		virtual bool Compile() = 0;
		/**
		* @brief Sets a color for the next draw operarion
		*/
		virtual void SetDrawColor(const ffw::Color& color) = 0;
		/**
		* @brief Draws a a quad composed of four vertices
		*/
		virtual void DrawQuad(int p0x, int p0y, int p1x, int p1y, int p2x, int p2y, int p3x, int p3y) = 0;
		/**
		* @brief Draws a polygon composed of multiple vertices
		*/
		virtual void DrawPolygon(const int* arr, int num) = 0;
		/**
		*/
		virtual void DrawTriangleFan(const int* arr, int num) = 0;
		/**
		* @brief Draws a triangle
		* @param posx Left top X position
		* @param posy Left top Y position
		* @param width Width of the rectangle
		* @param height Height of the rectangle
		*/
		virtual void DrawRectangle(int posx, int posy, int width, int height) = 0;
		/**
		*/
		virtual void DrawRectangleRounded(int posx, int posy, int width, int height, int leftTop, int rightTop, int bottomRight, int bottomLeft, int steps) = 0;
		/**
		*/
		virtual void DrawTriangle(int p0x, int p0y, int p1x, int p1y, int p2x, int p2y) = 0;
		/**
		*/
		virtual void DrawTexture2D(int posx, int posy, int width, int height, const ffw::Texture2D* texture) = 0;
		/**
		*/
		virtual void DrawTexture2DMirror(int posx, int posy, int width, int height, const ffw::Texture2D* texture, bool mirrorx, bool mirrory) = 0;
		/**
		*/
		virtual void DrawTexture2DSub(int posx, int posy, int width, int height, const ffw::Texture2D* texture, int subx, int suby, int subw, int subh) = 0;
		/**
		*/
		virtual void DrawTexture2DSubMirror(int posx, int posy, int width, int height, const ffw::Texture2D* texture, int subx, int suby, int subw, int subh, bool mirrorx, bool mirrory) = 0;
		/**
		*/
		virtual void DrawArc(int posx, int posy, int innerradius, int outerradius, double startangle, double endangle, int steps) = 0;
		/**
		*/
		virtual void DrawCircle(int posx, int posy, int radius, int steps) = 0;
		/**
		*/
		virtual void DrawLine(int startx, int starty, int endx, int edny) = 0;
		/**
		*/
		virtual void DrawLineThick(int startx, int starty, int endx, int edny, int thickness) = 0;
		/**
		*/
		virtual void DrawString(int posx, int posy, const Font* font, const std::string& str, float lineHeight = 1.25f) = 0;
		/**
		*/
		virtual void DrawString(int posx, int posy, const Font* font, const std::wstring& str, float lineHeight = 1.25f) = 0;
		/**
		*/
		virtual void DrawString(int posx, int posy, const Font* font, const char* str, float lineHeight = 1.25f) = 0;
		/**
		*/
		virtual void DrawString(int posx, int posy, const Font* font, const char* str, size_t length, float lineHeight = 1.25f) = 0;
		/**
		*/
		virtual void DrawString(int posx, int posy, const Font* font, const wchar_t* str, float lineHeight = 1.25f) = 0;
		/**
		*/
		virtual void DrawString(int posx, int posy, const Font* font, const wchar_t* str, size_t length, float lineHeight = 1.25f) = 0;
		/**
		*/
		virtual void DrawBezier(int startx, int starty, int cp0x, int cp0y, int cp1x, int cp1y, int endx, int endy, int steps) = 0;
		/**
		*/
		virtual void DrawBezierThick(int startx, int starty, int cp0x, int cp0y, int cp1x, int cp1y, int endx, int endy, int thickness, int steps) = 0;
	};
};
#endif