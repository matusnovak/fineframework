/*** This file is part of FineFramework project ***/
#include "ffw/graphics/rendercontext.h"
#include "ffw/graphics/font.h"
#include "ffw/graphics/texture2d.h"
#include "ffw/math/mvp.h"
#include "ffw/math/mathconstants.h"
#include "ffw/math/functions.h"

#define STRINGIFY(x) #x

///=============================================================================
static const std::string defaultGenericShaderVert = "#version 130\n" STRINGIFY(
	uniform mat4x4 proj;
uniform vec2 pos[4];
uniform vec2 uvs[4];
out vec2 texPos;
void main() {
	texPos = uvs[gl_VertexID];
	gl_Position = proj * vec4(pos[gl_VertexID], 1.0f, 1.0f);
}
);

///=============================================================================
static const std::string defaultGenericShaderFrag = "#version 130\n" STRINGIFY(
	uniform vec4 color;
uniform int branch;
uniform sampler2D tex;
in vec2 texPos;
void main() {
	if (branch == 2) {
		gl_FragColor = vec4(color.r, color.g, color.b, texture2D(tex, texPos).a * color.a);
	}
	else if (branch == 1) {
		gl_FragColor = texture2D(tex, texPos) * color;
	}
	else {
		gl_FragColor = color;
	}
}
);

///=============================================================================
static const std::string defaultArcShaderVert = "#version 130\n" STRINGIFY(
	uniform mat4x4 proj;
uniform vec2 pos;
uniform vec2 inner;
uniform vec2 outer;
uniform vec2 radius;
uniform vec2 angle;
uniform int steps;
void main() {
	vec2 position = pos;
	float rad = (angle.y - angle.x) / steps;
	float step = (gl_VertexID / 2) * rad + angle.x;

	if (mod(gl_VertexID, 2) == 0) {
		position.x += outer.x*cos(step);
		position.y += outer.y*sin(step);
	}
	else {
		position.x += inner.x*cos(step);
		position.y += inner.y*sin(step);
	}
	gl_Position = proj * vec4(position.xy, 1.0f, 1.0f);
}
);

///=============================================================================
static const std::string defaultArcShaderFrag = "#version 130\n" STRINGIFY(
	uniform vec4 color;
void main() {
	gl_FragColor = color;
}
);

///=============================================================================
static const std::string defaultRectShaderVert = "#version 130\n" STRINGIFY(
uniform mat4x4 proj;
uniform vec2 pos;
uniform vec2 inner;
uniform vec2 outer;
uniform int steps;
uniform float corner[4];

const vec2 offset[4] = vec2[4](
	vec2(1, 1),
	vec2(-1, 1),
	vec2(-1, -1),
	vec2(1, -1)
	);

void main() {
	vec2 position = pos;

	int vertex = gl_VertexID / 2;
	float step = mod(vertex, steps) * (1.5708f / (steps - 1));
	int index = int(mod(vertex / steps, 4));

	vec2 weighted = vec2(corner[index], corner[index]);

	if (mod(gl_VertexID, 2) == 0) {
		weighted.x *= inner.x / float(outer.x);
		weighted.y *= inner.y / float(outer.y);
		position.x += offset[index].x * (inner.x - weighted.x) + weighted.x*cos(1.5708f * index + step);
		position.y += offset[index].y * (inner.y - weighted.y) + weighted.y*sin(1.5708f * index + step);
	}
	else {
		position.x += offset[index].x * (outer.x - weighted.x) + weighted.x*cos(1.5708f * index + step);
		position.y += offset[index].y * (outer.y - weighted.y) + weighted.y*sin(1.5708f * index + step);
	}

	gl_Position = proj * vec4(position.xy, 1.0f, 1.0f);
}
);

///=============================================================================
static const std::string defaultRectShaderFrag = "#version 130\n" STRINGIFY(
	uniform vec4 color;
void main() {
	gl_FragColor = color;
}
);

// https://en.wikipedia.org/wiki/B%C3%A9zier_curve#Cubic_B.C3.A9zier_curves
// p = p0*((1.0f - t)*(1.0f - t)*(1.0f - t)) + p1*3.0f*((1.0f - t)*(1.0f - t))*t + p2*3.0f *(1.0f - t)*t*t + p3*t*t*t;
///=============================================================================
static std::string defaultBezierShaderVert = "#version 130\n" STRINGIFY(
	uniform mat4x4 proj;
uniform vec2 points[4];
uniform int steps;

void main() {
	float t = gl_VertexID / float(steps);
	vec2 p0 = points[0] * ((1.0f - t)*(1.0f - t)*(1.0f - t));
	vec2 p1 = points[1] * 3.0f*((1.0f - t)*(1.0f - t))*t;
	vec2 p2 = points[2] * 3.0f *(1.0f - t)*t*t;
	vec2 p3 = points[3] * t*t*t;
	gl_Position = proj * vec4(p0 + p1 + p2 + p3, 1.0f, 1.0f);
}
);

///=============================================================================
static std::string defaultBezierShaderFrag = "#version 130\n" STRINGIFY(
	uniform vec4 color;
void main() {
	gl_FragColor = color;
}
);

///=============================================================================
static std::string defaultBezierAdvShaderVert = "#version 130\n" STRINGIFY(
	uniform mat4x4 proj;
uniform vec2 points[4];
uniform int steps;
uniform int thick;

vec2 getPoint(float t) {
	return points[0] * ((1.0f - t)*(1.0f - t)*(1.0f - t))
		+ points[1] * 3.0f*((1.0f - t)*(1.0f - t))*t
		+ points[2] * 3.0f *(1.0f - t)*t*t
		+ points[3] * t*t*t;
}

void main() {
	float t0 = ((gl_VertexID / 2) - 1) / float(steps);
	float t1 = ((gl_VertexID / 2)) / float(steps);
	float t2 = ((gl_VertexID / 2) + 1) / float(steps);

	t0 = clamp(t0, 0.0f, 1.0f);
	t2 = clamp(t2, 0.0f, 1.0f);

	vec2 p0 = getPoint(t0);
	vec2 p1 = getPoint(t1);
	vec2 p2 = getPoint(t2);

	vec2 n0 = p1 - p0;
	float n0x = n0.x;
	n0.x = n0.y;
	n0.y = -n0x;

	vec2 n1 = p2 - p1;
	float n1x = n1.x;
	n1.x = n1.y;
	n1.y = -n1x;

	vec2 n = n0 + n1;
	n = normalize(n);

	if (mod(gl_VertexID, 2) == 0) {
		gl_Position = proj * vec4(p1 + n*thick, 1.0f, 1.0f);
	}
	else {
		gl_Position = proj * vec4(p1 - n*thick, 1.0f, 1.0f);
	}
}
);

///=============================================================================
static std::string defaultBezierAdvShaderFrag = "#version 130\n" STRINGIFY(
	uniform vec4 color;
void main() {
	gl_FragColor = color;
}
);

///=============================================================================
ffw::RenderContext::RenderContext() {
	bezierSteps = 1;
	arcSteps = 1;
	rectSteps = 1;
	thickness = 1;
	outlineMode = false;
	usesOpenGL3 = false;
}

///=============================================================================
ffw::RenderContext::~RenderContext() {
	genericShader.destroy();
}

///=============================================================================
static bool compileShader(const ffw::RenderContext* context, ffw::Shader& shdr, const std::string& vert, const std::string& frag) {
	try {
		shdr.createFromData(context, std::string(""), vert, frag);
	}
	catch (std::exception& e) {
#ifndef NDEBUG
		std::cerr << "Failed to compile RenderContext shaders:" << std::endl << e.what() << std::endl;
#else
		(void)e;
#endif
		return false;
	}
	return true;
}

///=============================================================================
bool ffw::RenderContext::compileShaders() {
	usesOpenGL3 = compileShadersGL3();
	if (usesOpenGL3) {
		bezierSteps = 32;
		arcSteps = 64;
		rectSteps = 16;
	}
	else {
		bezierSteps = 16;
		arcSteps = 32;
		rectSteps = 8;
	}
	return true;
}

///=============================================================================
bool ffw::RenderContext::compileShadersGL3() {
	//return false;
	if (!ffw::Shader::checkCompability(this)) {
#ifndef NDEBUG
		std::cerr << "Shaders are not supported on this machine's OpenGL! Switching to OpenGL v1.1 drawing method!" << std::endl;
#endif
		return false;
	}

	bool result =
		compileShader(this, genericShader, defaultGenericShaderVert, defaultGenericShaderFrag) &&
		compileShader(this, arcShader, defaultArcShaderVert, defaultArcShaderFrag) &&
		compileShader(this, bezierShader, defaultBezierShaderVert, defaultBezierShaderFrag) &&
		compileShader(this, bezierAdvShader, defaultBezierAdvShaderVert, defaultBezierAdvShaderFrag) &&
		compileShader(this, rectShader, defaultRectShaderVert, defaultRectShaderFrag)
		;

	if (!result)return false;

	genericShaderPosLoc = genericShader.getUniformLocation("pos");
	genericShaderColorLoc = genericShader.getUniformLocation("color");
	genericShaderProjLoc = genericShader.getUniformLocation("proj");
	genericShaderUvsLoc = genericShader.getUniformLocation("uvs");
	genericShaderTexLoc = genericShader.getUniformLocation("tex");
	genericShaderBranchLoc = genericShader.getUniformLocation("branch");

	arcShaderPosLoc = arcShader.getUniformLocation("pos");
	arcShaderColorLoc = arcShader.getUniformLocation("color");
	arcShaderProjLoc = arcShader.getUniformLocation("proj");
	arcShaderInnerLoc = arcShader.getUniformLocation("inner");
	arcShaderStepsLoc = arcShader.getUniformLocation("steps");
	arcShaderAngleLoc = arcShader.getUniformLocation("angle");
	arcShaderOuterLoc = arcShader.getUniformLocation("outer");

	rectShaderPosLoc = rectShader.getUniformLocation("pos");
	rectShaderColorLoc = rectShader.getUniformLocation("color");
	rectShaderProjLoc = rectShader.getUniformLocation("proj");
	rectShaderInnerLoc = rectShader.getUniformLocation("inner");
	rectShaderStepsLoc = rectShader.getUniformLocation("steps");
	rectShaderCornerLoc = rectShader.getUniformLocation("corner");
	rectShaderOuterLoc = rectShader.getUniformLocation("outer");

	bezierShaderProjLoc = bezierShader.getUniformLocation("proj");
	bezierShaderPointsLoc = bezierShader.getUniformLocation("points");
	bezierShaderColorLoc = bezierShader.getUniformLocation("color");
	bezierShaderStepsLoc = bezierShader.getUniformLocation("steps");

	bezierAdvShaderProjLoc = bezierAdvShader.getUniformLocation("proj");
	bezierAdvShaderPointsLoc = bezierAdvShader.getUniformLocation("points");
	bezierAdvShaderColorLoc = bezierAdvShader.getUniformLocation("color");
	bezierAdvShaderStepsLoc = bezierAdvShader.getUniformLocation("steps");
	bezierAdvShaderThickLoc = bezierAdvShader.getUniformLocation("thick");



	return true;
}

///=============================================================================
void ffw::RenderContext::setViewport(int posx, int posy, int width, int height) {
	if (!usesOpenGL3) {
		glViewport(posx, posy, width, height);
		glMatrixMode(GL_MODELVIEW);
		glLoadIdentity();
		glMatrixMode(GL_PROJECTION);
		glLoadIdentity();
		glOrtho(posx, posx + width, posy + height, posy, -1, 1);
	}
	else {
		glViewport(posx, posy, width, height);
		projection = ffw::makeOrthoMatrix<float>((float)posx, (float)posx + width, (float)posy + height, (float)posy, -1, 1);
	}
}

///=============================================================================
void ffw::RenderContext::setDrawColor(const ffw::Color& color) {
	if (!usesOpenGL3) {
		glColor4f(color.r, color.g, color.b, color.a);
	}
	else {
		drawColor = color;
	}
}

///=============================================================================
void ffw::RenderContext::drawQuad(float p0x, float p0y, float p1x, float p1y, float p2x, float p2y, float p3x, float p3y) {
	vertices[0] = p0x; vertices[1] = p0y;
	vertices[2] = p1x; vertices[3] = p1y;
	vertices[4] = p2x; vertices[5] = p2y;
	vertices[6] = p3x; vertices[7] = p3y;
	
	if (!usesOpenGL3) {
		glEnableClientState(GL_VERTEX_ARRAY);
		glVertexPointer(2, GL_FLOAT, 0, vertices);
		glDrawArrays(GL_QUADS, 0, 4);
		glDisableClientState(GL_VERTEX_ARRAY);
	}
	else {
		genericShader.bind();
		genericShader.setUniform1i(genericShaderBranchLoc, 0);
		genericShader.setUniform4f(genericShaderColorLoc, drawColor);
		genericShader.setUniformMatrix4fv(genericShaderProjLoc, &projection, 1);
		genericShader.setUniform2fv(genericShaderPosLoc, vertices, 8);
		genericShader.drawArrays(GL_QUADS, 0, 4);
		//genericShader.unbind();
	}
}

///=============================================================================
void ffw::RenderContext::drawRectangle(float posx, float posy, float width, float height) {
	vertices[0] = posx; vertices[1] = posy;
	vertices[2] = posx + width; vertices[3] = posy;
	vertices[4] = posx + width; vertices[5] = posy + height;
	vertices[6] = posx; vertices[7] = posy + height;
	
	if (!usesOpenGL3) {
		if (outlineMode) {
			auto temp = rectSteps;
			rectSteps = 4;
			drawRectangleRounded(posx, posy, width, height, 0, 0, 0, 0);
			rectSteps = temp;
		}
		else {
			glEnableClientState(GL_VERTEX_ARRAY);
			glVertexPointer(2, GL_FLOAT, 0, vertices);
			glDrawArrays(GL_QUADS, 0, 4);
			glDisableClientState(GL_VERTEX_ARRAY);
		}
	}
	else {
		if (outlineMode) {
			auto temp = rectSteps;
			rectSteps = 4;
			drawRectangleRounded(posx, posy, width, height, 0, 0, 0, 0);
			rectSteps = temp;
		}
		else {
			genericShader.bind();
			genericShader.setUniform1i(genericShaderBranchLoc, 0);
			genericShader.setUniform4f(genericShaderColorLoc, drawColor);
			genericShader.setUniformMatrix4fv(genericShaderProjLoc, &projection, 1);
			genericShader.setUniform2fv(genericShaderPosLoc, vertices, 8);
			genericShader.drawArrays(GL_QUADS, 0, 4);
			//genericShader.unbind();
		}
	}
}

///=============================================================================
void ffw::RenderContext::drawRectangleRounded(float posx, float posy, float width, float height, float corners) {
	drawRectangleRounded(posx, posy, width, height, corners, corners, corners, corners);
}

///=============================================================================
void ffw::RenderContext::drawRectangleRounded(float posx, float posy, float width, float height, float topLeft, float topRight, float bottomRight, float bottomLeft) {
	if (!usesOpenGL3) {
		static const ffw::Vec2f offset[4] = {
			ffw::Vec2f(1, 1),
			ffw::Vec2f(-1, 1),
			ffw::Vec2f(-1, -1),
			ffw::Vec2f(1, -1)
		};

		const float corner[4] = {
			bottomRight,
			bottomLeft,
			topLeft,
			topRight
		};

		ffw::Vec2f outer(width / 2, height / 2);
		ffw::Vec2f inner(0, 0);

		if (outlineMode) {
			inner.set(float(width / 2 - thickness), float(height / 2 - thickness));
		}

		float rad = float(360.0f * DEG_TO_RAD) / (float)rectSteps;

		glBegin(GL_QUAD_STRIP);
		for (int i = 0; i < rectSteps * 8 + 2; i++) {
			ffw::Vec2f position(posx + width / 2, posy + height / 2);

			int vertex = i / 2;
			float step = (vertex % rectSteps) * (1.5708f / (rectSteps - 1));
			int index = int((vertex / rectSteps) % 4);

			ffw::Vec2f weighted = ffw::Vec2f(corner[index], corner[index]);

			if ((i % 2) == 0) {
				weighted.x *= inner.x / float(outer.x);
				weighted.y *= inner.y / float(outer.y);
				position.x += offset[index].x * (inner.x - weighted.x) + weighted.x*cos(1.5708f * index + step);
				position.y += offset[index].y * (inner.y - weighted.y) + weighted.y*sin(1.5708f * index + step);
			}
			else {
				position.x += offset[index].x * (outer.x - weighted.x) + weighted.x*cos(1.5708f * index + step);
				position.y += offset[index].y * (outer.y - weighted.y) + weighted.y*sin(1.5708f * index + step);
			}

			glVertex2f(position.x, position.y);
		}
		glEnd();
	}
	else {
		vertices[0] = bottomRight; 
		vertices[1] = bottomLeft; 
		vertices[2] = topLeft;
		vertices[3] = topRight;

		rectShader.bind();
		rectShader.setUniform4f(rectShaderColorLoc, drawColor);
		rectShader.setUniformMatrix4fv(rectShaderProjLoc, &projection, 1);
		rectShader.setUniform2f(rectShaderPosLoc, posx + width / 2, posy + height / 2);
		if (outlineMode)rectShader.setUniform2f(rectShaderInnerLoc, width / 2 - thickness, width / 2 - thickness);
		else rectShader.setUniform2f(rectShaderInnerLoc, 0, 0);
		rectShader.setUniform2f(rectShaderOuterLoc, width / 2, height / 2);
		rectShader.setUniform1fv(rectShaderCornerLoc, vertices, 4);
		rectShader.setUniform1i(rectShaderStepsLoc, rectSteps);
		rectShader.drawArrays(GL_QUAD_STRIP, 0, rectSteps * 8 + 2);
		//arcShader.unbind();
	}
}

///=============================================================================
void ffw::RenderContext::drawTriangle(float p0x, float p0y, float p1x, float p1y, float p2x, float p2y) {
	vertices[0] = p0x; vertices[1] = p0y;
	vertices[2] = p1x; vertices[3] = p1y;
	vertices[4] = p2x; vertices[5] = p2y;
	
	if (!usesOpenGL3) {
		glEnableClientState(GL_VERTEX_ARRAY);
		glVertexPointer(2, GL_FLOAT, 0, vertices);
		glDrawArrays(GL_TRIANGLES, 0, 3);
		glDisableClientState(GL_VERTEX_ARRAY);
	}
	else {
		genericShader.bind();
		genericShader.setUniform1i(genericShaderBranchLoc, 0);
		genericShader.setUniform4f(genericShaderColorLoc, drawColor);
		genericShader.setUniformMatrix4fv(genericShaderProjLoc, &projection, 1);
		genericShader.setUniform2fv(genericShaderPosLoc, vertices, 6);
		genericShader.drawArrays(GL_TRIANGLES, 0, 3);
		//genericShader.unbind();
	}
}

///=============================================================================
void ffw::RenderContext::drawTexture2D(float posx, float posy, float width, float height, const ffw::Texture2D* texture) {
	if (texture == NULL || !texture->isCreated())return;
	drawTexture2DSubMirror(posx, posy, width, height, texture, 0, 0, texture->getWidth(), texture->getHeight(), false, false);
}

///=============================================================================
void ffw::RenderContext::drawTexture2DMirror(float posx, float posy, float width, float height, const ffw::Texture2D* texture, bool mirrorx, bool mirrory) {
	if (texture == NULL || !texture->isCreated())return;
	drawTexture2DSubMirror(posx, posy, width, height, texture, 0, 0, texture->getWidth(), texture->getHeight(), mirrorx, mirrory);
}

///=============================================================================
void ffw::RenderContext::drawTexture2DSub(float posx, float posy, float width, float height, const ffw::Texture2D* texture, int subx, int suby, int subw, int subh) {
	drawTexture2DSubMirror(posx, posy, width, height, texture, subx, suby, subw, subh, false, false);
}

///=============================================================================
void ffw::RenderContext::drawTexture2DSubMirror(float posx, float posy, float width, float height, const ffw::Texture2D* texture, int subx, int suby, int subw, int subh, bool mirrorx, bool mirrory) {
	if (texture == NULL)return;
	texture->bind();

	float subxf = subx / (float)texture->getWidth();
	float subyf = suby / (float)texture->getHeight();
	float subwf = subw / (float)texture->getWidth();
	float subhf = subh / (float)texture->getHeight();

	if (!usesOpenGL3) {
		vertices[0] = posx + width; vertices[1] = posy;
		vertices[2] = posx; vertices[3] = posy;
		vertices[4] = posx; vertices[5] = posy + height;
		vertices[6] = posx + width; vertices[7] = posy + height;

		float uvs[8] = {
			subxf + subwf, subyf,
			subxf, subyf,
			subxf, subyf + subhf,
			subxf + subwf, subyf + subhf
		};

		if (mirrory) {
			std::swap(uvs[0], uvs[6]);
			std::swap(uvs[1], uvs[7]);

			std::swap(uvs[2], uvs[4]);
			std::swap(uvs[3], uvs[5]);
		}

		if (mirrorx) {
			std::swap(uvs[0], uvs[2]);
			std::swap(uvs[1], uvs[3]);

			std::swap(uvs[4], uvs[6]);
			std::swap(uvs[5], uvs[7]);
		}

		glEnable(GL_TEXTURE_2D);
		texture->bind();
		glEnableClientState(GL_VERTEX_ARRAY);
		glEnableClientState(GL_TEXTURE_COORD_ARRAY);
		glTexCoordPointer(2, GL_FLOAT, 0, uvs);
		glVertexPointer(2, GL_FLOAT, 0, vertices);
		glDrawArrays(GL_QUADS, 0, 4);
		glDisableClientState(GL_TEXTURE_COORD_ARRAY);
		glDisableClientState(GL_VERTEX_ARRAY);
		glDisable(GL_TEXTURE_2D);
	}
	else {
		vertices[0] = posx; vertices[1] = posy;
		vertices[2] = posx + width; vertices[3] = posy;
		vertices[4] = posx + width; vertices[5] = posy + height;
		vertices[6] = posx; vertices[7] = posy + height;

		float uvs[2 * 4] = {
			subxf, subyf, subxf + subwf, subyf,
			subxf + subwf, subyf + subhf, subxf, subyf + subhf
		};

		if (mirrorx) {
			std::swap(uvs[2], uvs[0]);
			std::swap(uvs[3], uvs[1]);

			std::swap(uvs[4], uvs[6]);
			std::swap(uvs[5], uvs[7]);
		}

		if (mirrory) {
			std::swap(uvs[6], uvs[0]);
			std::swap(uvs[7], uvs[1]);

			std::swap(uvs[4], uvs[2]);
			std::swap(uvs[5], uvs[3]);
		}

		genericShader.bind();
		genericShader.setUniform4f(genericShaderColorLoc, drawColor);
		genericShader.setUniformMatrix4fv(genericShaderProjLoc, &projection, 1);
		genericShader.setUniform1i(genericShaderBranchLoc, 1);
		genericShader.setUniform1i(genericShaderTexLoc, 0);
		genericShader.setUniform2fv(genericShaderPosLoc, vertices, 8);
		genericShader.setUniform2fv(genericShaderUvsLoc, uvs, 8);
		genericShader.drawArrays(GL_QUADS, 0, 4);
	}
}

///=============================================================================
void ffw::RenderContext::drawArc(float posx, float posy, float innerradius, float outerradius, double startangle, double endangle) {
	if (!usesOpenGL3) {
		double start = startangle * DEG_TO_RAD;
		double end = endangle * DEG_TO_RAD;
		double step = (end - start) / double(arcSteps);
		double angle = start;

		glEnableClientState(GL_VERTEX_ARRAY);

		for (int i = 0; i < arcSteps; i++) {
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
	else {
		arcShader.bind();
		arcShader.setUniform4f(arcShaderColorLoc, drawColor);
		arcShader.setUniformMatrix4fv(arcShaderProjLoc, &projection, 1);
		arcShader.setUniform2f(arcShaderPosLoc, posx, posy);
		arcShader.setUniform2f(arcShaderInnerLoc, innerradius, innerradius);
		arcShader.setUniform2f(arcShaderOuterLoc, outerradius, outerradius);
		arcShader.setUniform2f(arcShaderAngleLoc, float(startangle*DEG_TO_RAD), float(endangle*DEG_TO_RAD));
		arcShader.setUniform1i(arcShaderStepsLoc, arcSteps);
		arcShader.drawArrays(GL_QUAD_STRIP, 0, arcSteps * 2 + 2);
	}
}

///=============================================================================
void ffw::RenderContext::drawCircle(float posx, float posy, float radius) {
	if (!usesOpenGL3) {
		if (outlineMode) {
			drawArc(posx, posy, radius, radius - thickness, 0.0, 360.0);
		}
		else {
			drawArc(posx, posy, 0, radius, 0, 360);
		}
	}
	else {
		arcShader.bind();
		arcShader.setUniform4f(arcShaderColorLoc, drawColor);
		arcShader.setUniformMatrix4fv(arcShaderProjLoc, &projection, 1);
		arcShader.setUniform2f(arcShaderPosLoc, posx, posy);
		if (outlineMode)arcShader.setUniform2f(arcShaderInnerLoc, radius - thickness, radius - thickness);
		else arcShader.setUniform2f(arcShaderInnerLoc, 0, 0);
		arcShader.setUniform2f(arcShaderOuterLoc, radius, radius);
		arcShader.setUniform2f(arcShaderAngleLoc, float(0.0*DEG_TO_RAD), float(360.0*DEG_TO_RAD));
		arcShader.setUniform1i(arcShaderStepsLoc, arcSteps);
		arcShader.drawArrays(GL_QUAD_STRIP, 0, arcSteps * 2 + 2);
		//arcShader.unbind();
	}
}

///=============================================================================
void ffw::RenderContext::drawLine(float startx, float starty, float endx, float endy) {
	if (!usesOpenGL3) {
		if (thickness == 1) {
			vertices[0] = startx; vertices[1] = starty;
			vertices[2] = endx; vertices[3] = endy;

			glEnableClientState(GL_VERTEX_ARRAY);
			glVertexPointer(2, GL_FLOAT, 0, vertices);
			glDrawArrays(GL_LINES, 0, 2);
			glDisableClientState(GL_VERTEX_ARRAY);
		}
		else {
			ffw::Vec2f dir(endx - startx, endy - starty);
			dir = ffw::Vec2f(dir.y, -dir.x);
			dir.normalize();
			dir *= float(thickness / 2);

			vertices[0] = startx + dir.x;
			vertices[1] = starty + dir.y;

			vertices[2] = endx + dir.x;
			vertices[3] = endy + dir.y;

			vertices[4] = endx - dir.x;
			vertices[5] = endy - dir.y;

			vertices[6] = startx - dir.x;
			vertices[7] = starty - dir.y;

			glEnableClientState(GL_VERTEX_ARRAY);
			glVertexPointer(2, GL_FLOAT, 0, vertices);
			glDrawArrays(GL_QUADS, 0, 4);
			glDisableClientState(GL_VERTEX_ARRAY);
		}
	}
	else {
		if (thickness == 1) {
			vertices[0] = startx; vertices[1] = starty;
			vertices[2] = endx; vertices[3] = endy;

			genericShader.bind();
			genericShader.setUniform1i(genericShaderBranchLoc, 0);
			genericShader.setUniform4f(genericShaderColorLoc, drawColor);
			genericShader.setUniformMatrix4fv(genericShaderProjLoc, &projection, 1);
			genericShader.setUniform2fv(genericShaderPosLoc, vertices, 4);
			genericShader.drawArrays(GL_LINES, 0, 2);
			//genericShader.unbind();
		}
		else {
			ffw::Vec2f dir(endx - startx, endy - starty);
			dir = ffw::Vec2f(dir.y, -dir.x);
			dir.normalize();
			dir *= float(thickness / 2);

			vertices[0] = startx + dir.x;
			vertices[1] = starty + dir.y;

			vertices[2] = endx + dir.x;
			vertices[3] = endy + dir.y;

			vertices[4] = endx - dir.x;
			vertices[5] = endy - dir.y;

			vertices[6] = startx - dir.x;
			vertices[7] = starty - dir.y;

			genericShader.bind();
			genericShader.setUniform1i(genericShaderBranchLoc, 0);
			genericShader.setUniform4f(genericShaderColorLoc, drawColor);
			genericShader.setUniformMatrix4fv(genericShaderProjLoc, &projection, 1);
			genericShader.setUniform2fv(genericShaderPosLoc, vertices, 8);
			genericShader.drawArrays(GL_QUADS, 0, 4);
			genericShader.unbind();
		}
	}
}

///=============================================================================
template <class T>
void ffw::RenderContext::drawStringFunc(float posx, float posy, const ffw::Font* font, const T* str, size_t length, float lineHeight) {
	if (font == NULL || !font->isCreated())return;

	if (!usesOpenGL3) {
		glEnable(GL_TEXTURE_2D);
	}

	font->getTexture()->bind();

	if (!usesOpenGL3) {
		glEnableClientState(GL_VERTEX_ARRAY);
		glEnableClientState(GL_TEXTURE_COORD_ARRAY);
	}
	else {
		genericShader.bind();
		if(font->isAlphaOnly())
			genericShader.setUniform1i(genericShaderBranchLoc, 2);
		else
			genericShader.setUniform1i(genericShaderBranchLoc, 1);
		genericShader.setUniform4f(genericShaderColorLoc, drawColor);
		genericShader.setUniformMatrix4fv(genericShaderProjLoc, &projection, 1);
		genericShader.setUniform1i(genericShaderTexLoc, 0);
	}

	auto advance = posx;
	auto height = posy;
	size_t cnt = 0;
	float textureWidth = (float)font->getTexture()->getWidth();
	float textureHeight = (float)font->getTexture()->getHeight();

	while (*str != '\0' && cnt < length) {
		auto chr = *str;
		str += 1;
		cnt++;

		const ffw::Font::Char& chrData = font->getChar(chr);

		if (chr == 32 || chr == 9) {
			advance += chrData.advance;
			continue;
		}

		else if (chr == '\n') {
			height += lineHeight * font->getSizePixels();
			advance = posx;
			continue;
		}

		auto offset = font->getCharVerticalOffset(chrData);

		vertices[0] = floor(advance + chrData.width + chrData.bearingX); 
		vertices[1] = floor(height + offset);

		vertices[2] = floor(advance + chrData.bearingX); 
		vertices[3] = floor(height + offset);

		vertices[4] = floor(advance + chrData.bearingX);  
		vertices[5] = floor(height + chrData.height + offset);

		vertices[6] = floor(advance + chrData.width + chrData.bearingX);  
		vertices[7] = floor(height + chrData.height + offset);

		float uvs[8] = {
			(chrData.x + chrData.width) / textureWidth, chrData.y / textureHeight,
			chrData.x / textureWidth,                   chrData.y / textureHeight,
			chrData.x / textureWidth,                   (chrData.y + chrData.height) / textureHeight,
			(chrData.x + chrData.width) / textureWidth, (chrData.y + chrData.height) / textureHeight
		};

		if (!usesOpenGL3) {
			glTexCoordPointer(2, GL_FLOAT, 0, uvs);
			glVertexPointer(2, GL_FLOAT, 0, vertices);
			glDrawArrays(GL_QUADS, 0, 4);
		}
		else {
			genericShader.setUniform2fv(genericShaderPosLoc, vertices, 8);
			genericShader.setUniform2fv(genericShaderUvsLoc, uvs, 8);
			genericShader.drawArrays(GL_QUADS, 0, 4);
		}

		advance += chrData.advance;
	}

	if (!usesOpenGL3) {
		glDisableClientState(GL_TEXTURE_COORD_ARRAY);
		glDisableClientState(GL_VERTEX_ARRAY);
		glDisable(GL_TEXTURE_2D);
	}
}

///=============================================================================
void ffw::RenderContext::drawString(float posx, float posy, const ffw::Font* font, const std::string& str, float lineHeight) {
	drawStringFunc(posx, posy, font, &str[0], str.size(), lineHeight);
}

///=============================================================================
void ffw::RenderContext::drawString(float posx, float posy, const ffw::Font* font, const std::wstring& str, float lineHeight) {
	drawStringFunc(posx, posy, font, &str[0], str.size(), lineHeight);
}

///=============================================================================
void ffw::RenderContext::drawString(float posx, float posy, const ffw::Font* font, const char* str, float lineHeight) {
	drawStringFunc(posx, posy, font, str, SIZE_MAX, lineHeight);
}

///=============================================================================
void ffw::RenderContext::drawString(float posx, float posy, const ffw::Font* font, const char* str, size_t length, float lineHeight) {
	drawStringFunc(posx, posy, font, str, length, lineHeight);
}

///=============================================================================
void ffw::RenderContext::drawString(float posx, float posy, const ffw::Font* font, const wchar_t* str, float lineHeight) {
	drawStringFunc(posx, posy, font, str, SIZE_MAX, lineHeight);
}

///=============================================================================
void ffw::RenderContext::drawString(float posx, float posy, const ffw::Font* font, const wchar_t* str, size_t length, float lineHeight) {
	drawStringFunc(posx, posy, font, str, length, lineHeight);
}

///=============================================================================
static ffw::Vec2f getBezierPoint(float t, const ffw::Vec2f& point0, const ffw::Vec2f& point1, const ffw::Vec2f& point2, const ffw::Vec2f& point3) {
	return point0 * ((1.0f - t)*(1.0f - t)*(1.0f - t))
		+ point1 * 3.0f*((1.0f - t)*(1.0f - t))*t
		+ point2 * 3.0f *(1.0f - t)*t*t
		+ point3 * t*t*t;
}

///=============================================================================
void ffw::RenderContext::drawBezier(float startx, float starty, float cp0x, float cp0y, float cp1x, float cp1y, float endx, float endy) {
	if (!usesOpenGL3) {
		if (thickness == 1) {
			glBegin(GL_LINE_STRIP);
			for (int i = 0; i < bezierSteps + 1; i++) {
				float t = i / float(bezierSteps);
				auto p = ffw::Vec2f((float)startx, (float)starty) * ((1.0f - t)*(1.0f - t)*(1.0f - t)) +
					ffw::Vec2f((float)cp0x, (float)cp0y) * 3.0f*((1.0f - t)*(1.0f - t))*t +
					ffw::Vec2f((float)cp1x, (float)cp1y) * 3.0f *(1.0f - t)*t*t +
					ffw::Vec2f((float)endx, (float)endy) * t*t*t;

				glVertex2f(p.x, p.y);
			}
			glEnd();
		}
		else {
			auto point0 = ffw::Vec2f((float)startx, (float)starty);
			auto point1 = ffw::Vec2f((float)cp0x, (float)cp0y);
			auto point2 = ffw::Vec2f((float)cp1x, (float)cp1y);
			auto point3 = ffw::Vec2f((float)endx, (float)endy);

			glBegin(GL_QUAD_STRIP);
			for (int i = 0; i < bezierSteps * 2 + 2; i++) {
				float t0 = ((i / 2) - 1) / float(bezierSteps);
				float t1 = ((i / 2)) / float(bezierSteps);
				float t2 = ((i / 2) + 1) / float(bezierSteps);

				t0 = ffw::clamp(t0, 0.0f, 1.0f);
				t2 = ffw::clamp(t2, 0.0f, 1.0f);

				auto p0 = getBezierPoint(t0, point0, point1, point2, point3);
				auto p1 = getBezierPoint(t1, point0, point1, point2, point3);
				auto p2 = getBezierPoint(t2, point0, point1, point2, point3);

				auto n0 = p1 - p0;
				float n0x = n0.x;
				n0.x = n0.y;
				n0.y = -n0x;

				auto n1 = p2 - p1;
				float n1x = n1.x;
				n1.x = n1.y;
				n1.y = -n1x;

				auto n = n0 + n1;
				n = ffw::normalize(n);

				if (i % 2 == 0) {
					p1 = p1 + n * (float)thickness / 2;
				}
				else {
					p1 = p1 - n * (float)thickness / 2;
				}
				glVertex2f(p1.x, p1.y);
			}
			glEnd();
		}
	}
	else {
		vertices[0] = startx; vertices[1] = starty;
		vertices[2] = cp0x; vertices[3] = cp0y;
		vertices[4] = cp1x; vertices[5] = cp1y;
		vertices[6] = endx; vertices[7] = endy;

		if (thickness == 1) {
			bezierShader.bind();
			bezierShader.setUniform4f(bezierShaderColorLoc, drawColor);
			bezierShader.setUniformMatrix4fv(bezierShaderProjLoc, &projection, 1);
			bezierShader.setUniform2fv(bezierShaderPointsLoc, vertices, 8);
			bezierShader.setUniform1i(bezierShaderStepsLoc, bezierSteps);
			bezierShader.drawArrays(GL_LINE_STRIP, 0, bezierSteps + 1);
		}
		else {
			bezierAdvShader.bind();
			bezierAdvShader.setUniform4f(bezierAdvShaderColorLoc, drawColor);
			bezierAdvShader.setUniformMatrix4fv(bezierAdvShaderProjLoc, &projection, 1);
			bezierAdvShader.setUniform2fv(bezierAdvShaderPointsLoc, vertices, 8);
			bezierAdvShader.setUniform1i(bezierAdvShaderStepsLoc, bezierSteps);
			bezierAdvShader.setUniform1i(bezierAdvShaderThickLoc, thickness / 2);
			bezierAdvShader.drawArrays(GL_QUAD_STRIP, 0, bezierSteps * 2 + 2);
		}
	}
}