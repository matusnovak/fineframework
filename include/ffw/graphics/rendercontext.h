/* This file is part of FineFramework project */
#ifndef FFW_RENDER_CONTEXT
#define FFW_RENDER_CONTEXT
#include "renderextensionsgl.h"
#include "shader.h"
#include "texture2d.h"

namespace ffw {
	class Font;
	/**
	 * @ingroup graphics
	 */
	class FFW_API RenderContext : public RenderExtensions {
	public:
		RenderContext();
		virtual ~RenderContext();
		/**
		 * @brief Retuns the address of the GL extension function
		 * @details The pointer to the GL extension function may not 
		 * be the same on different GL contexts! 
		 */
		virtual void* getGlextFunc(const std::string& name) const = 0;
		/**
		 * @brief Returns true if the GL extension function is present
		 */
		virtual bool isGlextFuncPresent(const std::string& name) const = 0;
		/**
		 * @brief Sets the viewport dimensions and position
		 */
		void setViewport(int posx, int posy, int width, int height);
		/**
		 * @brief Sets the color of the next draw commands
		 */
		void setDrawColor(const ffw::Color& color);
		/**
		 * @brief Draws a quad composing of 4 points
		 */
		void drawQuad(float p0x, float p0y, float p1x, float p1y, float p2x, float p2y, float p3x, float p3y);
		/**
		 * @brief Draws a simple rectangle
		 */
		void drawRectangle(float posx, float posy, float width, float height);
		/**
		 * @brief Draws a rectangle with rounded corners
		 */
		void drawRectangleRounded(float posx, float posy, float width, float height, float corners);
		/**
		 * @brief Draws a rectangle with rounded corners
		 */
		void drawRectangleRounded(float posx, float posy, float width, float height, float leftTop, float rightTop, float bottomRight, float bottomLeft);
		/**
		 * @brief Draws a simple triangle 
		 */
		void drawTriangle(float p0x, float p0y, float p1x, float p1y, float p2x, float p2y);
		/**
		 * @brief Draws a 2D texture
		 */
		void drawTexture2D(float posx, float posy, float width, float height, const ffw::Texture2D* texture);
		/**
		 * @brief Draws a 2D texture that can be mirrored 
		 */
		void drawTexture2DMirror(float posx, float posy, float width, float height, const ffw::Texture2D* texture, bool mirrorx, bool mirrory);
		/**
		 * @brief Draws a rectangular subsection of the texture
		 * @details The subsection coordinates are in pixels.
		 */
		void drawTexture2DSub(float posx, float posy, float width, float height, const ffw::Texture2D* texture, int subx, int suby, int subw, int subh);
		/**
		 * @brief Draws a mirrored rectangular subsection of the texture
		 * @details The subsection coordinates are in pixels and the mirroring affects the result subsection.
		 */
		void drawTexture2DSubMirror(float posx, float posy, float width, float height, const ffw::Texture2D* texture, int subx, int suby, int subw, int subh, bool mirrorx, bool mirrory);
		/**
		 * @brief Draws an arc using starting and ending angle
		 */
		void drawArc(float posx, float posy, float innerradius, float outerradius, double startangle, double endangle);
		/**
		 * @brief Draws a simple circle
		 */
		void drawCircle(float posx, float posy, float radius);
		/**
		 * @brief Draws a line from point A to point B
		 */
		void drawLine(float startx, float starty, float endx, float edny);
		/**
		 * @brief Draws a string
		 * @details This is not UTF-8 enabled!
		 */
		void drawString(float posx, float posy, const Font* font, const std::string& str, float lineHeight = 1.25f);
		/**
		 * @brief Draws a multi-byte string
		 */
		void drawString(float posx, float posy, const Font* font, const std::wstring& str, float lineHeight = 1.25f);
		/**
		 * @brief Draws a string
		 * @details This is not UTF-8 enabled!
		 */
		void drawString(float posx, float posy, const Font* font, const char* str, float lineHeight = 1.25f);
		/**
		 * @brief Draws a string
		 * @details This is not UTF-8 enabled!
		 */
		void drawString(float posx, float posy, const Font* font, const char* str, size_t length, float lineHeight = 1.25f);
		/**
		 * @brief Draws a multi-byte string
		 */
		void drawString(float posx, float posy, const Font* font, const wchar_t* str, float lineHeight = 1.25f);
		/**
		 * @brief Draws a multi-byte string
		 */
		void drawString(float posx, float posy, const Font* font, const wchar_t* str, size_t length, float lineHeight = 1.25f);
		/**
		 * @brief Draws a quadratic bezier curve
		 */
		void drawBezier(float startx, float starty, float cp0x, float cp0y, float cp1x, float cp1y, float endx, float endy);
		/**
		 * @brief Sets the number of steps for the arc and circle
		 */
		inline void setArcSteps(int steps) {
			arcSteps = steps;
		}
		/**
		 * @brief Sets the number of steps for the bezier curve
		 */
		inline void setBezierSteps(int steps) {
			bezierSteps = steps;
		}
		/**
		 * @brief Sets the number of steps for corners of the rounded rectangle
		 */
		inline void setRectangleSteps(int steps) {
			rectSteps = steps;
		}
		/**
		 * @brief Sets if the next rendered primitive should be filled or outlined
		 */
		inline void setOutlineMode(bool enabled) {
			outlineMode = enabled;
		}
		/**
		 * @brief Sets the thickness of the outline mode
		 */
		inline void setOutlineSize(int pixels) {
			thickness = pixels;
		}
		/**
		 * @brief Returns true if the outline mode is enabled
		 */
		inline bool getOutlineMode() const {
			return outlineMode;
		}
		/**
		 * @brief Returns the thickness of the outline mode
		 */
		inline int getOutlineSize() const {
			return thickness;
		}
	protected:
		bool compileShaders();
		bool compileShadersGL3();
	private:
		template <class T>
		void drawStringFunc(float posx, float posy, const ffw::Font* font, const T* str, size_t length, float lineHeight);
		bool usesOpenGL3;
		ffw::Shader genericShader;
		ffw::Shader arcShader;
		ffw::Shader bezierShader;
		ffw::Shader bezierAdvShader;
		ffw::Shader rectShader;
		ffw::Mat4x4f projection;
		ffw::Color drawColor;
		float vertices[8 * 2];

		int genericShaderPosLoc;
		int genericShaderColorLoc;
		int genericShaderProjLoc;
		int genericShaderUvsLoc;
		int genericShaderTexLoc;
		int genericShaderBranchLoc;

		int arcShaderPosLoc;
		int arcShaderColorLoc;
		int arcShaderProjLoc;
		int arcShaderInnerLoc;
		int arcShaderOuterLoc;
		int arcShaderStepsLoc;
		int arcShaderAngleLoc;

		int rectShaderPosLoc;
		int rectShaderColorLoc;
		int rectShaderProjLoc;
		int rectShaderInnerLoc;
		int rectShaderOuterLoc;
		int rectShaderStepsLoc;
		int rectShaderCornerLoc;

		int bezierShaderProjLoc;
		int bezierShaderPointsLoc;
		int bezierShaderColorLoc;
		int bezierShaderStepsLoc;

		int bezierAdvShaderProjLoc;
		int bezierAdvShaderPointsLoc;
		int bezierAdvShaderColorLoc;
		int bezierAdvShaderStepsLoc;
		int bezierAdvShaderThickLoc;

		int arcSteps;
		int bezierSteps;
		int rectSteps;
		bool outlineMode;
		int thickness;
	};
}
#endif
