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
#include "gl3.h"
#include "glext.h"
#include "gl.h"
#else
#include "GL/gl.h"
#include "GL/glext.h"
#endif
#include <string>

namespace ffw {
    class RenderContext;
	class GlextStruct;
	class FFW_API Shader {
    public:
        static bool CheckCompability(const RenderContext* renderer);
		Shader();
        virtual ~Shader();
        bool IsCreated() const;
        inline const std::string& GetCompileLog() const {
			return errorlogstr_;
		}
        bool CreateFromFile(const RenderContext* renderer, const std::string& geompath, const std::string& vertpath, const std::string& fragpath);
        bool CreateFromData(const RenderContext* renderer, const std::string& geomdata, const std::string& vertdata, const std::string& fragdata){
			return CreateFromData(renderer, geomdata.c_str(), vertdata.c_str(), fragdata.c_str());
		}
        bool CreateFromData(const RenderContext* renderer, const char* geomdata, const char* vertdata, const char* fragdata);
        void Destroy();
        inline unsigned int GetHandle() const {
			return program_;
		}
        void SetAttributePointer(int location, int size, int stride, const GLvoid* offset) const;
        void SetAttributeDivisor(unsigned int index, unsigned int divisor) const;
        void DrawArrays(unsigned int mode, int first, int count) const;
        void DrawArraysInstanced(unsigned int mode, int First, int Count, int instancecount) const;
        void DrawElements(unsigned int mode, int count, unsigned int type, const void* indices) const;
        void DrawElementsRange(unsigned int mode, unsigned int start, unsigned int end, int count, unsigned int type, const void* indices) const;
        void DrawElementsInstanced(unsigned int mode, int count, unsigned int type, const void* indices, int instancecount) const;
        void Bind() const;
        void Unbind() const;
        int GetUniformLocation(const char* name) const;
        int GetAttributeLocation(const char* name) const;
        void SetUniform1f(int location, float value) const;
        void SetUniform1fv(int location, const float* array, int length) const;
        void SetUniform1i(int location, int value) const;
        void SetUniform1iv(int location, const int* array, int length) const;
        void SetUniform2f(int location, float x, float y) const;
        void SetUniform2fv(int location, const float* array, int length) const;
        void SetUniform2i(int location, int x, int y) const;
        void SetUniform2iv(int location, const int* array, int length) const;
        void SetUniform3f(int location, float x, float y, float z) const;
        void SetUniform3fv(int location, const float* array, int length) const;
        void SetUniform3i(int location, int x, int y, int z) const;
        void SetUniform3iv(int location, const int* array, int length) const;
        void SetUniform4f(int location, float x, float y, float z, float w) const;
        void SetUniform4fv(int location, const float* array, int length) const;
		void SetUniform4i(int location, int x, int y, int z, int w) const;
        void SetUniform4iv(int location, const int* array, int length) const;
        void SetUniform2f(int location, const ffw::Vec2f& vec) const;
        void SetUniform2fv(int location, const ffw::Vec2f* array, int length) const;
        void SetUniform2i(int location, const ffw::Vec2i& vec) const;
        void SetUniform2iv(int location, const ffw::Vec2i* array, int length) const;
        void SetUniform3f(int location, const ffw::Vec3f& vec) const;
        void SetUniform3fv(int location, const ffw::Vec3f* array, int length) const;
        void SetUniform3i(int location, const ffw::Vec3i& vec) const;
        void SetUniform3iv(int location, const  ffw::Vec3i* array, int length) const;
        void SetUniform4f(int location, const  ffw::Vec4f& vec) const;
        void SetUniform4fv(int location, const ffw::Vec4f* array, int length) const;
        void SetUniform4i(int location, const  ffw::Vec4i& vec) const;
        void SetUniform4iv(int location, const ffw::Vec4i*  array, int length) const;
        void SetUniform4f(int location, const  ffw::Color& vec) const;
        void SetUniform4fv(int location, const ffw::Color* array, int length) const;
        void SetUniformMatrix2fv(int location, const float* mat, int length) const;
        void SetUniformMatrix3fv(int location, const float* mat, int length) const;
        void SetUniformMatrix4fv(int location, const float* mat, int length) const;
        void SetUniformMatrix4fv(int location, const Mat4x4f* mat, int length) const;
    private:
        bool CompileShader(unsigned int &thisShader, const char* data, unsigned int ShaderType);
        bool CheckForShaderErrors(unsigned int thisShader, std::string* ErrorStr);
        bool CheckForProgramErrors(std::string* ErrorStr);
        bool loaded_;
        unsigned int program_;
        unsigned int geomshader_;
        unsigned int vertshader_;
        unsigned int fragshader_;
        bool usinggeom_;
        bool usingvert_;
        bool usingfrag_;
		std::string errorlogstr_;
        const GlextStruct* gl_;
    };
};
#endif
