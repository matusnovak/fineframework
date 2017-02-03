/* This file is part of FineFramework project */
#ifndef FFW_RENDER_COLLECTION_GL_3
#define FFW_RENDER_COLLECTION_GL_3
#include "rendercollection.h"

namespace ffw {
	/**
	* @ingroup graphics
	*/
	class RenderCollectionGL3 : public RenderCollection {
	public:
		RenderCollectionGL3();
		~RenderCollectionGL3();
		bool Compile() override;
		void SetDrawColor(const ffw::Color& color) override;
		void DrawQuad(int p0x, int p0y, int p1x, int p1y, int p2x, int p2y, int p3x, int p3y) override;
		void DrawPolygon(const int* arr, int num) override;
		void DrawTriangleFan(const int* arr, int num) override;
		void DrawRectangle(int posx, int posy, int width, int height) override;
		void DrawRectangleRounded(int posx, int posy, int width, int height, int leftTop, int rightTop, int bottomRight, int bottomLeft, int steps) override;
		void DrawTriangle(int p0x, int p0y, int p1x, int p1y, int p2x, int p2y) override;
		void DrawTexture2D(int posx, int posy, int width, int height, const ffw::Texture2D* texture) override;
		void DrawTexture2DMirror(int posx, int posy, int width, int height, const ffw::Texture2D* texture, bool mirrorx, bool mirrory) override;
		void DrawTexture2DSub(int posx, int posy, int width, int height, const ffw::Texture2D* texture, int subx, int suby, int subw, int subh) override;
		void DrawTexture2DSubMirror(int posx, int posy, int width, int height, const ffw::Texture2D* texture, int subx, int suby, int subw, int subh, bool mirrorx, bool mirrory) override;
		void DrawArc(int posx, int posy, int innerradius, int outerradius, double startangle, double endangle, int steps) override;
		void DrawCircle(int posx, int posy, int radius, int steps) override;
		void DrawLine(int startx, int starty, int endx, int edny) override;
		void DrawLineThick(int startx, int starty, int endx, int edny, int thickness) override;
		void DrawString(int posx, int posy, const Font* font, const std::string& str, float lineHeight = 1.25f) override;
		void DrawString(int posx, int posy, const Font* font, const std::wstring& str, float lineHeight = 1.25f) override;
		void DrawString(int posx, int posy, const Font* font, const char* str, float lineHeight = 1.25f) override;
		void DrawString(int posx, int posy, const Font* font, const char* str, size_t length, float lineHeight = 1.25f) override;
		void DrawString(int posx, int posy, const Font* font, const wchar_t* str, float lineHeight = 1.25f) override;
		void DrawString(int posx, int posy, const Font* font, const wchar_t* str, size_t length, float lineHeight = 1.25f) override;
		void DrawBezier(int startx, int starty, int cp0x, int cp0y, int cp1x, int cp1y, int endx, int endy, int steps) override;
		void DrawBezierThick(int startx, int starty, int cp0x, int cp0y, int cp1x, int cp1y, int endx, int endy, int thickness, int steps) override;
	};
};

#endif