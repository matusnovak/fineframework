/*** This file is part of FineFramework project ***/

#include "ffw/graphics/graphics.h"
#include "ffw/graphics/rendercontext.h"
#include "ffw/graphics/extensions.h"
#include <string.h>

///=============================================================================
void ffw::SetDrawColor(const ffw::Color& color){
	glColor4f(color.r, color.g, color.b, color.a);
}

///=============================================================================
void ffw::DrawQuad(int p0x, int p0y, int p1x, int p1y, int p2x, int p2y, int p3x, int p3y){
	int vertices[8] = {
		p0x, p0y,
		p1x, p1y,
		p2x, p2y,
		p3x, p3y
	};
	
	glEnableClientState(GL_VERTEX_ARRAY);
    glVertexPointer(2, GL_INT, 0, vertices);
    glDrawArrays(GL_QUADS, 0, 4);
	glDisableClientState(GL_VERTEX_ARRAY);
}

///=============================================================================
void ffw::DrawPolygon(const int* arr, int num){
	glEnableClientState(GL_VERTEX_ARRAY);
    glVertexPointer(2, GL_INT, 0, arr);
    glDrawArrays(GL_POLYGON, 0, num);
	glDisableClientState(GL_VERTEX_ARRAY);
}

///=============================================================================
void ffw::DrawTriangleFan(const int* arr, int num){
	glEnableClientState(GL_VERTEX_ARRAY);
    glVertexPointer(2, GL_INT, 0, arr);
    glDrawArrays(GL_TRIANGLE_FAN, 0, num);
	glDisableClientState(GL_VERTEX_ARRAY);
}

///=============================================================================
void ffw::DrawRectangle(int posx, int posy, int width, int height){
	int vertices[8] = {
		posx + width, posy,
		posx, posy,
		posx, posy + height,
		posx + width, posy + height
	};
	
	glEnableClientState(GL_VERTEX_ARRAY);
    glVertexPointer(2, GL_INT, 0, vertices);
    glDrawArrays(GL_QUADS, 0, 4);
	glDisableClientState(GL_VERTEX_ARRAY);
}

///=============================================================================
void ffw::DrawTriangle(int p0x, int p0y, int p1x, int p1y, int p2x, int p2y){
	int vertices[6] = {
		p0x, p0y,
		p1x, p1y,
		p2x, p2y
	};
	
	glEnableClientState(GL_VERTEX_ARRAY);
    glVertexPointer(2, GL_INT, 0, vertices);
    glDrawArrays(GL_TRIANGLES, 0, 3);
	glDisableClientState(GL_VERTEX_ARRAY);
}

///=============================================================================
void ffw::DrawTexture2D(int posx, int posy, int width, int height, const ffw::Texture2D* texture){
	if(texture == NULL || !texture->IsCreated())return;
    DrawTexture2DSubMirror(posx, posy, width, height, texture, 0, 0, texture->GetWidth(), texture->GetHeight(), false, false);
}

///=============================================================================
void ffw::DrawTexture2DMirror(int posx, int posy, int width, int height, const ffw::Texture2D* texture, bool mirrorx, bool mirrory){
    if(texture == NULL || !texture->IsCreated())return;
	DrawTexture2DSubMirror(posx, posy, width, height, texture, 0, 0, texture->GetWidth(), texture->GetHeight(), mirrorx, mirrory);
}

///=============================================================================
void ffw::DrawTexture2DSub(int posx, int posy, int width, int height, const ffw::Texture2D* texture, int SubX, int SubY, int SubW, int SubH){
    DrawTexture2DSubMirror(posx, posy, width, height, texture, SubX, SubY, SubW, SubH, false, false);
}

///=============================================================================
void ffw::DrawTexture2DSubMirror(int posx, int posy, int width, int height, const ffw::Texture2D* texture, int SubX, int SubY, int SubW, int SubH, bool mirrorx, bool mirrory){
	if(texture == NULL || !texture->IsCreated())return;

	int vertices[8] = {
		posx + width, posy,
		posx, posy,
		posx, posy + height,
		posx + width, posy + height
	};

	float sx = SubX / static_cast<float>(texture->GetWidth());
	float sy = SubY / static_cast<float>(texture->GetHeight());
	float sw = SubW / static_cast<float>(texture->GetWidth());
	float sh = SubH / static_cast<float>(texture->GetHeight());

	float textureCoords[8] = {
		sx + sw, sy,
		sx, sy,
		sx, sy + sh,
		sx + sw, sy + sh
	};

	if(mirrory){
		std::swap(textureCoords[0], textureCoords[6]);
		std::swap(textureCoords[1], textureCoords[7]);

		std::swap(textureCoords[2], textureCoords[4]);
		std::swap(textureCoords[3], textureCoords[5]);
	}

	if(mirrorx){
		std::swap(textureCoords[0], textureCoords[2]);
		std::swap(textureCoords[1], textureCoords[3]);

		std::swap(textureCoords[4], textureCoords[6]);
		std::swap(textureCoords[5], textureCoords[7]);
	}
	
	glEnable(GL_TEXTURE_2D);
	texture->Bind();	
	glEnableClientState(GL_VERTEX_ARRAY);
	glEnableClientState(GL_TEXTURE_COORD_ARRAY);
	glTexCoordPointer(2, GL_FLOAT, 0, textureCoords);
    glVertexPointer(2, GL_INT, 0, vertices);
    glDrawArrays(GL_QUADS, 0, 4);
	glDisableClientState(GL_TEXTURE_COORD_ARRAY);
	glDisableClientState(GL_VERTEX_ARRAY);
	glDisable(GL_TEXTURE_2D);
}

///=============================================================================
void ffw::DrawArc(int posx, int posy, int innerradius, int outerradius, float startangle, float endangle, int steps){
	if(innerradius > outerradius)std::swap(innerradius, outerradius);

	double start = double(startangle * DEG_TO_RAD);
	double end = double(endangle * DEG_TO_RAD);
	double step = double(end - start) / double(steps);
	double angle = start;

	glEnableClientState(GL_VERTEX_ARRAY);

	for(int i = 0; i < steps; i++){
		double angleNew = angle + step;
		
		double vertices[8] = {
			double(innerradius * cos(angle) + posx), double(innerradius * sin(angle) + posy),
			double(outerradius * cos(angle) + posx), double(outerradius * sin(angle) + posy),
			double(outerradius * cos(angleNew) + posx), double(outerradius * sin(angleNew) + posy),
			double(innerradius * cos(angleNew) + posx), double(innerradius * sin(angleNew) + posy),
		};

		glVertexPointer(2, GL_DOUBLE, 0, vertices);
		glDrawArrays(GL_QUADS, 0, 4);

		angle = angleNew;
	}

	glDisableClientState(GL_VERTEX_ARRAY);
}

///=============================================================================
void ffw::DrawCircle(int posx, int posy, int radius, int steps){
    DrawArc(posx, posy, 0, radius, 0, 360, steps);
}

///=============================================================================
void ffw::DrawLine(int startx, int starty, int endx, int endy){
	int vertices[4] = {
		startx, starty,
		endx, endy
	};
	
	glEnableClientState(GL_VERTEX_ARRAY);
    glVertexPointer(2, GL_INT, 0, vertices);
    glDrawArrays(GL_LINES, 0, 2);
	glDisableClientState(GL_VERTEX_ARRAY);
}

///=============================================================================
void ffw::DrawLineThick(int startx, int starty, int endx, int endy, int thickness){
	ffw::Vec2f dir(float(endx - startx), float(endy - starty));
	dir = ffw::Vec2f(dir.y, -dir.x);
	dir.Normalize();
	dir *= float(thickness/2);

	int vertices[8] = {
		int(startx + dir.x), int(starty + dir.y),
		int(endx + dir.x), int(endy + dir.y),
		int(endx - dir.x), int(endy - dir.y),
		int(startx - dir.x), int(starty - dir.y)
	};

	glEnableClientState(GL_VERTEX_ARRAY);
    glVertexPointer(2, GL_INT, 0, vertices);
    glDrawArrays(GL_QUADS, 0, 4);
	glDisableClientState(GL_VERTEX_ARRAY);
}

///=============================================================================
template <class T>
static void DrawStringFunc(int posx, int posy, const ffw::Font* font, const T* str, size_t length){
	if(font == NULL || !font->IsCreated())return;

	glEnable(GL_TEXTURE_2D);
	font->GetTexture()->Bind();	
	glEnableClientState(GL_VERTEX_ARRAY);
	glEnableClientState(GL_TEXTURE_COORD_ARRAY);

	int advance = posx;
    int height = posy;
	int lineHeight = font->GetLineHeight();
	for(size_t i = 0; i < length; i++){
		auto chr = str[i];

		if(chr == 32 || chr == 9){
            advance += font->GetCharAdvance(chr);
            continue;

        } else if(chr == 10){
            height += lineHeight;
            advance = posx;
            continue;
        } else if(chr <= 32){
			continue;
		}

		const auto chrSize = font->GetCharSize(chr);
		int offset = font->GetCharVerticalOffset(chr);

		int vertices[8] = {
			advance + chrSize.x, height + offset,
			advance, height + offset,
			advance, height + chrSize.y + offset,
			advance + chrSize.x, height + chrSize.y + offset
		};

		ffw::Vec2f t0, t1, t2, t3;
		font->GetCharTexCoords(chr, t0, t1, t2, t3);

		float textureCoords[8] = {
			t1.x, t1.y,
			t0.x, t0.y,
			t3.x, t3.y,
			t2.x, t2.y
		};

		glTexCoordPointer(2, GL_FLOAT, 0, textureCoords);
		glVertexPointer(2, GL_INT, 0, vertices);
		glDrawArrays(GL_QUADS, 0, 4);

		advance += font->GetCharAdvance(chr);
	}

	glDisableClientState(GL_TEXTURE_COORD_ARRAY);
	glDisableClientState(GL_VERTEX_ARRAY);

	glDisable(GL_TEXTURE_2D);
}

///=============================================================================
void ffw::DrawString(int posx, int posy, const ffw::Font* font, const std::string& str){
	DrawStringFunc(posx, posy, font, str.c_str(), str.size());
}

///=============================================================================
void ffw::DrawString(int posx, int posy, const ffw::Font* font, const std::wstring& str){
	DrawStringFunc(posx, posy, font, str.c_str(), str.size());
}

///=============================================================================
void ffw::DrawString(int posx, int posy, const Font* font, const char* str){
	DrawStringFunc(posx, posy, font, str, strlen(str));
}

///=============================================================================
void ffw::DrawString(int posx, int posy, const Font* font, const char* str, size_t length){
	DrawStringFunc(posx, posy, font, str, length);
}

///=============================================================================
void ffw::DrawString(int posx, int posy, const Font* font, const wchar_t* str){
	DrawStringFunc(posx, posy, font, str, wcslen(str));
}

///=============================================================================
void ffw::DrawString(int posx, int posy, const Font* font, const wchar_t* str, size_t length){
	DrawStringFunc(posx, posy, font, str, length);
}

///=============================================================================
void ffw::DrawBezier(int startx, int starty, int cp0x, int cp0y, int cp1x, int cp1y, int endx, int endy, int steps){
}

///=============================================================================
void ffw::DrawBezierThick(int startx, int starty, int cp0x, int cp0y, int cp1x, int cp1y, int endx, int endy, int thickness, int steps){
}

///=============================================================================
ffw::Vec4i ffw::ContainImage(int imgwidth, int imgheight, int maxwidth, int maxheight){
    float frameAspect = imgheight / float(imgwidth);
	ffw::Vec4i ret;

    if(maxwidth*frameAspect <= maxheight){
        ret.z = maxwidth;
        ret.w = int(maxwidth*frameAspect);
		ret.x = 0;
		ret.y = (maxheight - ret.w)/2;

    } else {
        ret.z = int(maxheight/frameAspect);
        ret.w = maxheight;
		ret.x = (maxwidth - ret.z)/2;
		ret.y = 0;
    }

	return ret;
}

///=============================================================================
ffw::Vec4i ffw::CoverImage(int imgwidth, int imgheight, int maxwidth, int maxheight){
    float imgAspect = imgheight / float(imgwidth);
	ffw::Vec4i ret;

	// Target area is vertical
    if(maxheight / float(maxwidth) >= 1.0f){
		// Image is vertical
		if(imgAspect >= 1.0f){
			ret.z = int(maxheight/imgAspect);
			ret.w = maxheight;
			if(ret.z < maxwidth){
				ret.z = maxwidth;
				ret.w = int(maxwidth*imgAspect);
			}
		// Image is horizontal
		} else {
			ret.z = int(maxheight/imgAspect);
			ret.w = maxheight;
		}
	// Target area is horizontal
	} else {
		// Image is vertical
		if(imgAspect >= 1.0f){
			ret.z = maxwidth;
			ret.w = int(maxwidth*imgAspect);
		// Image is horizontal
		} else {
			ret.z = maxwidth;
			ret.w = int(maxwidth*imgAspect);
			if(ret.w < maxheight){
				ret.z = int(maxheight/imgAspect);
				ret.w = maxheight;
			}
		}
	}
	ret.x = (ret.z - maxwidth)/-2;
	ret.y = (ret.w - maxheight)/-2;
	return ret;
}

///=============================================================================
ffw::OpenGLImageType ffw::GetOpenGLImageType(ffw::ImageType type){
	switch(type){
		case ffw::ImageType::GRAYSCALE_8:{
			return OpenGLImageType(GL_LUMINANCE8, GL_LUMINANCE, GL_UNSIGNED_BYTE);
		};
		case ffw::ImageType::GRAYSCALE_16:{
			return OpenGLImageType(GL_LUMINANCE16, GL_LUMINANCE, GL_UNSIGNED_SHORT);
		};
		case ffw::ImageType::GRAYSCALE_32:{
			return OpenGLImageType(GL_RED, GL_RED, GL_FLOAT);
		};
		case ffw::ImageType::GRAYSCALE_ALPHA_8:{
			return OpenGLImageType(GL_LUMINANCE8_ALPHA8, GL_LUMINANCE_ALPHA, GL_UNSIGNED_BYTE);
		};
		case ffw::ImageType::GRAYSCALE_ALPHA_16:{
			return OpenGLImageType(GL_LUMINANCE16_ALPHA16, GL_LUMINANCE_ALPHA, GL_UNSIGNED_SHORT);
		};
		case ffw::ImageType::RGB_ALPHA_5551:{
			return OpenGLImageType(GL_RGB5_A1, GL_RGBA, GL_UNSIGNED_SHORT_5_5_5_1);
		};
		case ffw::ImageType::RGB_ALPHA_4444:{
			return OpenGLImageType(GL_RGBA4, GL_RGBA, GL_UNSIGNED_SHORT_4_4_4_4);
		};
		case ffw::ImageType::RGB_565:{
			return OpenGLImageType(GL_RGB565, GL_RGB, GL_UNSIGNED_SHORT_5_6_5);
		};
		case ffw::ImageType::RGB_888:{
			return OpenGLImageType(GL_RGB8, GL_RGB, GL_UNSIGNED_BYTE);
		};
		case ffw::ImageType::RGB_161616:{
			return OpenGLImageType(GL_RGB16, GL_RGB, GL_UNSIGNED_SHORT);
		};
		case ffw::ImageType::RGB_323232:{
			return OpenGLImageType(GL_RGB32F, GL_RGB, GL_FLOAT);
		};
		case ffw::ImageType::RGB_ALPHA_8888:{
			return OpenGLImageType(GL_RGBA8, GL_RGBA, GL_UNSIGNED_BYTE);
		};
		case ffw::ImageType::RGB_ALPHA_16161616:{
			return OpenGLImageType(GL_RGBA16, GL_RGBA, GL_UNSIGNED_SHORT);
		};
		case ffw::ImageType::RGB_ALPHA_32323232:{
			return OpenGLImageType(GL_RGBA32F, GL_RGBA, GL_FLOAT);
		};
		default: return OpenGLImageType();
	};
}