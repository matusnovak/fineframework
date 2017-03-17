/* This file is part of FineFramework project */
#ifndef FFW_GRAPHICS_SHADER
#define FFW_GRAPHICS_SHADER
#include "../config.h"
#include "../math.h"
#if defined(FFW_WINDOWS_MSVC)
// Evil windows.h
#define NOMINMAX
#include "windows.h"
#undef NOMINMAX
#endif
#ifdef FFW_OSX
#define GL_DO_NOT_WARN_IF_MULTI_GL_VERSION_HEADERS_INCLUDED
#include <OpenGL/gl3.h>
#include <OpenGL/glext.h>
#include <OpenGL/gl.h>
#else
#include "GL/gl.h"
#include "GL/glext.h"
#endif
#include <string>

namespace ffw {
    class RenderContext;
	class RenderExtensions;
	/**
	 * @ingroup graphics
	 */
	class FFW_API Shader {
    public:
		class CompileException: public std::exception {
		public:
			inline CompileException(const std::string& log):msg(log) {
			}
			inline const char* what() const throw() {
				return msg.c_str();
			}
			std::string msg;
		};
		class FileException : public std::exception {
		public:
			inline FileException(const std::string& file):msg("Error reading file: \"" + file + "\"") {
			}
			inline const char* what() const throw() {
				return msg.c_str();
			}
			std::string msg;
		};
        static bool checkCompability(const RenderContext* renderer);
		Shader();
		Shader(const Shader& other) = delete;
		Shader(Shader&& other);
		void swap(Shader& other);
        virtual ~Shader();
		inline bool isCreated() const {
			return loaded;
		}
		inline bool isLinked() const {
			return linked;
		}
		inline bool isUsingFrag() const {
			return usingfrag;
		}
		inline bool isUsingGeom() const {
			return usinggeom;
		}
		inline bool isUsingVert() const {
			return usingvert;
		}
		bool create(const RenderContext* renderer);
		void Link();
		void compileFragFromData(const std::string& code);
		void compileGeomFromData(const std::string& code);
		void compileVertFromData(const std::string& code);
		void createFromFile(const RenderContext* renderer, const std::string& geomfile, const std::string& vertfile, const std::string& fragfile);
		void createFromData(const RenderContext* renderer, const std::string& geomdata, const std::string& vertdata, const std::string& fragdata);
		/*bool createFromFile(const RenderContext* renderer, const std::string& geompath, const std::string& vertpath, const std::string& fragpath);
        bool createFromData(const RenderContext* renderer, const std::string& geomdata, const std::string& vertdata, const std::string& fragdata){
			return createFromData(renderer, geomdata.c_str(), vertdata.c_str(), fragdata.c_str());
		}
        bool createFromData(const RenderContext* renderer, const char* geomdata, const char* vertdata, const char* fragdata);*/
        void destroy();
        inline unsigned int getHandle() const {
			return program;
		}
        void setAttributePointerf(int location, int size, int stride, const GLvoid* offset) const;
        void setAttributeDivisor(unsigned int index, unsigned int divisor) const;
        void drawArrays(unsigned int mode, int first, int cnt) const;
        void drawArraysInstanced(unsigned int mode, int First, int count, int instancecount) const;
        void drawElements(unsigned int mode, int cnt, unsigned int type, const void* indices) const;
        void drawElementsRange(unsigned int mode, unsigned int start, unsigned int end, int cnt, unsigned int type, const void* indices) const;
        void drawElementsInstanced(unsigned int mode, int cnt, unsigned int type, const void* indices, int instancecount) const;
        void bind() const;
        void unbind() const;
        int getUniformLocation(const char* name) const;
        int getAttributeLocation(const char* name) const;
        void setUniform1f(int location, float value) const;
        void setUniform1fv(int location, const float* array, int length) const;
        void setUniform1i(int location, int value) const;
        void setUniform1iv(int location, const int* array, int length) const;
        void setUniform2f(int location, float x, float y) const;
        void setUniform2fv(int location, const float* array, int length) const;
        void setUniform2i(int location, int x, int y) const;
        void setUniform2iv(int location, const int* array, int length) const;
        void setUniform3f(int location, float x, float y, float z) const;
        void setUniform3fv(int location, const float* array, int length) const;
        void setUniform3i(int location, int x, int y, int z) const;
        void setUniform3iv(int location, const int* array, int length) const;
        void setUniform4f(int location, float x, float y, float z, float w) const;
        void setUniform4fv(int location, const float* array, int length) const;
		void setUniform4i(int location, int x, int y, int z, int w) const;
        void setUniform4iv(int location, const int* array, int length) const;
        void setUniform2f(int location, const ffw::Vec2f& vec) const;
        void setUniform2fv(int location, const ffw::Vec2f* array, int length) const;
        void setUniform2i(int location, const ffw::Vec2i& vec) const;
        void setUniform2iv(int location, const ffw::Vec2i* array, int length) const;
        void setUniform3f(int location, const ffw::Vec3f& vec) const;
        void setUniform3fv(int location, const ffw::Vec3f* array, int length) const;
        void setUniform3i(int location, const ffw::Vec3i& vec) const;
        void setUniform3iv(int location, const  ffw::Vec3i* array, int length) const;
        void setUniform4f(int location, const  ffw::Vec4f& vec) const;
        void setUniform4fv(int location, const ffw::Vec4f* array, int length) const;
        void setUniform4i(int location, const  ffw::Vec4i& vec) const;
        void setUniform4iv(int location, const ffw::Vec4i*  array, int length) const;
        void setUniform4f(int location, const  ffw::Color& vec) const;
        void setUniform4fv(int location, const ffw::Color* array, int length) const;
        void setUniformMatrix2fv(int location, const float* mat, int length) const;
        void setUniformMatrix3fv(int location, const float* mat, int length) const;
        void setUniformMatrix4fv(int location, const float* mat, int length) const;
        void setUniformMatrix4fv(int location, const Mat4x4f* mat, int length) const;

		Shader& operator = (const Shader& other) = delete;
		Shader& operator = (Shader&& other);
    private:
		void compileShader(unsigned int &thisShader, const char* data, unsigned int ShaderType);
        bool checkForShaderErrors(unsigned int thisShader, std::string* ErrorStr);
        bool checkForProgramErrors(std::string* ErrorStr);
        bool loaded;
		bool linked;
        unsigned int program;
        unsigned int geomshader;
        unsigned int vertshader;
        unsigned int fragshader;
        bool usinggeom;
        bool usingvert;
        bool usingfrag;
        const RenderExtensions* gl_;
    };
};

inline void swap(ffw::Shader& first, ffw::Shader& second) {
	first.swap(second);
}
#endif
