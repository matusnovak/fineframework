/*** This file is part of FineFramework project ***/

#include "ffw/graphics/Shader.h"
#include "ffw/graphics/RenderContext.h"
#include "ffw/graphics/extensions.h"
#include <fstream>

///=============================================================================
static bool LoadTxt(const std::string& path, std::string* output){
	if(output == NULL)return false;

	std::ifstream input(path);
	if(!input)return false;

	input.seekg(0, std::ios::end);
	output->reserve(static_cast<size_t>(input.tellg()));
	input.seekg(0, std::ios::beg);

	output->assign((std::istreambuf_iterator<char>(input)),
				std::istreambuf_iterator<char>());

    return true;
}

///=============================================================================
bool ffw::Shader::CheckCompability(const ffw::RenderContext* renderer){
	if(renderer == NULL)return false;
	const ffw::GlextStruct* gl_ = renderer->Glext();

	return (
		gl_->glUseProgram                != NULL &&
		gl_->glCompileShader             != NULL &&
		gl_->glCreateProgram             != NULL &&
		gl_->glCreateShader              != NULL &&
		gl_->glDeleteProgram             != NULL &&
		gl_->glDeleteShader              != NULL &&
		gl_->glAttachShader              != NULL &&
		gl_->glGetShaderiv               != NULL &&
		gl_->glLinkProgram               != NULL &&
		gl_->glShaderSource              != NULL &&
		gl_->glGetProgramInfoLog         != NULL &&
		gl_->glGetShaderInfoLog          != NULL &&
		gl_->glGetProgramiv              != NULL &&
		gl_->glVertexAttribPointer       != NULL &&
		gl_->glEnableVertexAttribArray   != NULL &&
		gl_->glGetUniformLocation        != NULL &&
		gl_->glGetAttribLocation         != NULL &&
		gl_->glDrawRangeElements         != NULL &&
		gl_->glUniform1f                 != NULL &&
		gl_->glUniform1fv                != NULL &&
		gl_->glUniform1i                 != NULL &&
		gl_->glUniform1iv                != NULL &&
		gl_->glUniform2f                 != NULL &&
		gl_->glUniform2fv                != NULL &&
		gl_->glUniform2i                 != NULL &&
		gl_->glUniform2iv                != NULL &&
		gl_->glUniform3f                 != NULL &&
		gl_->glUniform3fv                != NULL &&
		gl_->glUniform3i                 != NULL &&
		gl_->glUniform3iv                != NULL &&
		gl_->glUniform4f                 != NULL &&
		gl_->glUniform4fv                != NULL &&
		gl_->glUniform4i                 != NULL &&
		gl_->glUniform4iv                != NULL &&
		gl_->glUniformMatrix2fv          != NULL &&
		gl_->glUniformMatrix3fv          != NULL &&
		gl_->glUniformMatrix4fv          != NULL &&
		gl_->glDrawArraysInstanced       != NULL &&
		gl_->glDrawElementsInstanced     != NULL &&
		gl_->glVertexAttribDivisor       != NULL
	);
}

///=============================================================================
ffw::Shader::Shader(){
    loaded_ = false;
    usinggeom_ = false;
    usingvert_ = false;
    usingfrag_ = false;
	program_ = 0;
	vertshader_ = 0;
	geomshader_ = 0;
	fragshader_ = 0;
}

///=============================================================================
ffw::Shader::~Shader(){
    Destroy();
}

///=============================================================================
bool ffw::Shader::CreateFromFile(const ffw::RenderContext* renderer, const std::string& geompath, const std::string& vertpath, const std::string& fragpath){
	if(loaded_)return false;

    errorlogstr_ = "";
    std::string geomdata;
    std::string vertdata;
    std::string fragdata;

    // If path for geometry Shader is not empty, load file
    if(geompath != ""){
        if(!::LoadTxt(geompath, &geomdata)){
            return false;
        }
    }
    // If path for vertex Shader is not empty, load file
    if(vertpath != ""){
        if(!::LoadTxt(vertpath, &vertdata)){
            return false;
        }
    }
    // If path for fragment Shader is not empty, load file
    if(fragpath != ""){
        if(!::LoadTxt(fragpath, &fragdata)){
            return false;
        }
    }

    // Now we have sources data, load them into program
    if(CreateFromData(renderer, geomdata.c_str(), vertdata.c_str(), fragdata.c_str())){
        return true;
    }
    return false;
}

///=============================================================================
bool ffw::Shader::CreateFromData(const ffw::RenderContext* renderer, const char* geomdata, const char* vertdata, const char* fragdata){
	if(loaded_)return false;
	if(!CheckCompability(renderer))return false;
	loaded_ = true;

	gl_ = renderer->Glext();

	errorlogstr_ = "";
    // Create Shader
    program_ = gl_->glCreateProgram();
    gl_->glUseProgram(program_);

    // Compile geometry Shader if source data is not empty
    if(geomdata != NULL){
        // Compile Shader
		#ifdef FFW_OSX
		if(CompileShader(geomshader_, geomdata, GL_GEOMETRY_SHADER)){
		#else
        if(CompileShader(geomshader_, geomdata, GL_GEOMETRY_SHADER_ARB)){
		#endif
            // Shader is compiled attach it to program
            gl_->glAttachShader(program_, geomshader_);
            // We are using this Shader
            usinggeom_ = true;
        } else {
            // If compilation failed, delete program
            gl_->glDeleteProgram(program_);
            // Switch back to main Shader
            gl_->glUseProgram(0);
			loaded_ = false;
            return false;
        }
    }
    // Compile vertex Shader
    if(vertdata != NULL){
        if(CompileShader(vertshader_, vertdata, GL_VERTEX_SHADER)){
            gl_->glAttachShader(program_, vertshader_);
            usingvert_ = true;
        } else {
            gl_->glDeleteProgram(program_);
            gl_->glUseProgram(0);
			loaded_ = false;
            return false;
        }
    }
    // Compile fragment Shader
    if(fragdata != NULL){
        if(CompileShader(fragshader_, fragdata, GL_FRAGMENT_SHADER)){
            gl_->glAttachShader(program_, fragshader_);
            usingfrag_ = true;
        } else {
            gl_->glDeleteProgram(program_);
            gl_->glUseProgram(0);
			loaded_ = false;
            return false;
        }
    }

    // Link program
    gl_->glLinkProgram(program_);

    // Check for program errors
    std::string errorstr;
    if(!CheckForProgramErrors(&errorstr)){
        // If there were any errors, delete Shader
        Destroy();
        // Switch back to main Shader
        gl_->glUseProgram(0);

		if (errorlogstr_.size() != 0)errorlogstr_ += "\n";
		errorlogstr_ += "Linking log: " + errorstr;
		loaded_ = false;
        return false;
    }

    // We are done, switch back to main Shader
    gl_->glUseProgram(0);
    return true;
}

///=============================================================================
bool ffw::Shader::CompileShader(GLuint& thisshader, const GLchar* data, GLenum shadertype){
    // Create Shader based on type
    thisshader = gl_->glCreateShader(shadertype);
    // Set the source data
    gl_->glShaderSource(thisshader, 1, &data, NULL);
    // Compile
    gl_->glCompileShader(thisshader);
    // Check for compilation errors
    std::string errorstr;
    if(!CheckForShaderErrors(thisshader, &errorstr)){
        // If there were any errors, delete newly loaded Shader
        gl_->glDeleteShader(thisshader);

        // Save error log
		if (errorlogstr_.size() != 0)errorlogstr_ += "\n";
        if      (shadertype == GL_GEOMETRY_SHADER_ARB)  errorlogstr_ += "Geometry Shader:\n" + errorstr;
        else if (shadertype == GL_VERTEX_SHADER)        errorlogstr_ += "Vertex Shader:\n" + errorstr;
		else if (shadertype == GL_FRAGMENT_SHADER)      errorlogstr_ += "Fragment Shader:\n" + errorstr;
        return false;
    }
    // No errors
    return true;
}

///=============================================================================
bool ffw::Shader::CheckForShaderErrors(GLuint thisshader, std::string* errorstr){

    // Check Shader compilation status
    GLint result;
    gl_->glGetShaderiv(thisshader, GL_COMPILE_STATUS, &result);
    // Shader failed to compile
    if(result == GL_FALSE) {
        // Get length of log
        GLint length;
        gl_->glGetShaderiv(thisshader, GL_INFO_LOG_LENGTH, &length);
        // Allocate memory for log
        errorstr->resize(length, ' ');
        // Get log
        gl_->glGetShaderInfoLog(thisshader, length, &result, &(*errorstr)[0]);
        return false;
    }
    // Shader compiled
    return true;
}

///=============================================================================
bool ffw::Shader::CheckForProgramErrors(std::string* errorstr){

    // Check program for linking errors
    GLint result;
    gl_->glGetProgramiv(program_, GL_LINK_STATUS, &result);
    // Program linking failed
    if(result == GL_FALSE) {
        // Get length og log
        GLint length;
        gl_->glGetProgramiv(program_, GL_INFO_LOG_LENGTH, &length);
        // Allocate memory for log
        errorstr->resize(length, ' ');
        // Get log
        gl_->glGetProgramInfoLog(program_, length, &result, &(*errorstr)[0]);
        return false;
    }
    // Program linked
    return true;
}

///=============================================================================
void ffw::Shader::Destroy(){
    // Do not continue if Shader was not loaded
    if(!loaded_)return;
    // Delete Shader if it was loaded
    if(usinggeom_)gl_->glDeleteShader(geomshader_);
    if(usingvert_)gl_->glDeleteShader(vertshader_);
    if(usingfrag_)gl_->glDeleteShader(fragshader_);
	usinggeom_ = false;
	usingvert_ = false;
	usingfrag_ = false;
    // Delete program
    gl_->glDeleteProgram(program_);
	program_ = 0;
    loaded_ = false;
}

///=============================================================================
void ffw::Shader::Bind() const {
    if(loaded_)gl_->glUseProgram(program_);
}

///=============================================================================
void ffw::Shader::Unbind() const {
    if(!loaded_)gl_->glUseProgram(0);
}

///=============================================================================
void ffw::Shader::SetAttributePointer(GLint Location, GLint Size, GLsizei Stride, const GLvoid* offset) const {
    // Enable attribute
    gl_->glEnableVertexAttribArray(Location);
    // Set the pointer of the attribute
    gl_->glVertexAttribPointer(Location, Size, GL_FLOAT, GL_FALSE, Stride, offset);
}

///=============================================================================
void ffw::Shader::SetAttributeDivisor(GLuint Index, GLuint Divisor) const {
    gl_->glVertexAttribDivisor(Index, Divisor);
}

///=============================================================================
void ffw::Shader::DrawArrays(GLenum Mode, GLint First, GLsizei Count) const {
    // Draw quad compositing of two triangles drawElements(GL_TRIANGLES, 6, 0);
    // drawElements(type to render, first vertice, number of vertices);
    glDrawArrays(Mode, First, Count);
}

///=============================================================================
void ffw::Shader::DrawArraysInstanced(GLenum Mode, GLint First, GLsizei Count, GLsizei InstanceCount) const {
    gl_->glDrawArraysInstanced(Mode, First, Count, InstanceCount);
}

///=============================================================================
void ffw::Shader::DrawElements(GLenum Mode, GLsizei Count, GLenum Type, const GLvoid * Indices) const {
    // Draw quad compositing of two triangles myShader.drawElements(GL_TRIANGLES, 6, 0);
    // Draw second triangle of quad drawElements(GL_TRIANGLES, 3, (GLvoid*) (sizeof(GLuint) * 3));
    // drawElements(type to render, number of vertices, (GLvoid*) (sizeof(GLuint) * vertice offset));
    glDrawElements(Mode, Count, Type, Indices);
}

///=============================================================================
void ffw::Shader::DrawElementsRange(GLenum Mode, GLuint Start, GLuint End, GLsizei Count, GLenum Type, const GLvoid * Indices) const {
    // Draw second triangle of quad drawElementsRange(GL_TRIANGLES, 0, 3, 3, (GLvoid*) (sizeof(GLuint) * 3));
    // drawElementsRange(type to render, min index, max index, number of vertices, (GLvoid*) (sizeof(GLuint) * vertice offset));
    gl_->glDrawRangeElements(Mode, Start, End, Count, Type, Indices);
}

///=============================================================================
void ffw::Shader::DrawElementsInstanced(GLenum Mode, GLsizei Count, GLenum Type, const GLvoid * Indices, GLsizei InstanceCount) const {
    gl_->glDrawElementsInstanced(Mode, Count, Type, Indices, InstanceCount);
}

///=============================================================================
int ffw::Shader::GetUniformLocation(const GLchar* Name) const {
    if(!loaded_)return -1;
    return gl_->glGetUniformLocation(program_, Name);
}

///=============================================================================
int ffw::Shader::GetAttributeLocation(const GLchar* Name) const {
    if(!loaded_)return -1;
    return gl_->glGetAttribLocation(program_, Name);
}
///=============================================================================
// Set 1D uniforms
void ffw::Shader::SetUniform1f(GLint location, GLfloat value) const {
    gl_->glUniform1f(location, value);
}

///=============================================================================
void ffw::Shader::SetUniform1fv(GLint location, const GLfloat* array, GLsizei length) const {
    gl_->glUniform1fv(location, length, array);
}

///=============================================================================
void ffw::Shader::SetUniform1i(GLint location, GLint value) const {
    gl_->glUniform1i(location, value);
}

///=============================================================================
void ffw::Shader::SetUniform1iv(GLint location, const GLint* array, GLsizei length) const {
    gl_->glUniform1iv(location, length, array);
}

///=============================================================================
// Set 2D uniforms
void ffw::Shader::SetUniform2f(GLint location, GLfloat x, GLfloat y) const {
    gl_->glUniform2f(location, x, y);
}

///=============================================================================
void ffw::Shader::SetUniform2fv(GLint location, const GLfloat* array, GLsizei length) const {
    gl_->glUniform2fv(location, length, array);
}

///=============================================================================
void ffw::Shader::SetUniform2i(GLint location, GLint x, GLint y) const {
    gl_->glUniform2i(location, x, y);
}

///=============================================================================
void ffw::Shader::SetUniform2iv(GLint location, const GLint* array, GLsizei length) const {
    gl_->glUniform2iv(location, length, array);
}

///=============================================================================
// Set 3D uniforms
void ffw::Shader::SetUniform3f(GLint location, GLfloat x, GLfloat y, GLfloat z) const {
    gl_->glUniform3f(location, x, y, z);
}

///=============================================================================
void ffw::Shader::SetUniform3fv(GLint location, const GLfloat* array, GLsizei length) const {
    gl_->glUniform3fv(location, length, array);
}

///=============================================================================
void ffw::Shader::SetUniform3i(GLint location, GLint x, GLint y, GLint z) const {
    gl_->glUniform3i(location, x, y, z);
}

///=============================================================================
void ffw::Shader::SetUniform3iv(GLint location, const GLint* array, GLsizei length) const {
    gl_->glUniform3iv(location, length, array);
}


///=============================================================================
// Set 4D uniforms
void ffw::Shader::SetUniform4f(GLint location, GLfloat x, GLfloat y, GLfloat z, GLfloat w) const {
    gl_->glUniform4f(location, x, y, z, w);
}

///=============================================================================
void ffw::Shader::SetUniform4fv(GLint location, const GLfloat* array, GLsizei length) const {
    gl_->glUniform4fv(location, length, array);
}

///=============================================================================
void ffw::Shader::SetUniform4i(GLint location, GLint x, GLint y, GLint z, GLint w) const {
    gl_->glUniform4i(location, x, y, z, w);
}

///=============================================================================
void ffw::Shader::SetUniform4iv(GLint location, const GLint* array, GLsizei length) const {
    gl_->glUniform4iv(location, length, array);
}

///=============================================================================
// Set 2D uniforms from vector
void ffw::Shader::SetUniform2f(GLint location, const ffw::Vec2f& vec) const {
    gl_->glUniform2f(location, vec.x, vec.y);
}

///=============================================================================
void ffw::Shader::SetUniform2fv(GLint location, const ffw::Vec2f* Array, GLsizei length) const {
	gl_->glUniform2fv(location, length, &Array[0].x);
}

///=============================================================================
void ffw::Shader::SetUniform2i(GLint location, const ffw::Vec2i& vec) const {
    gl_->glUniform2i(location, vec.x, vec.y);
}

///=============================================================================
void ffw::Shader::SetUniform2iv(GLint location, const ffw::Vec2i* Array, GLsizei length) const {
	gl_->glUniform2iv(location, length, &Array[0].x);
}

///=============================================================================
// Set 3D uniforms from vector
void ffw::Shader::SetUniform3f(GLint location, const ffw::Vec3f& vec) const {
    gl_->glUniform3f(location, vec.x, vec.y, vec.z);
}

///=============================================================================
void ffw::Shader::SetUniform3fv(GLint location, const ffw::Vec3f* Array, GLsizei length) const {
	gl_->glUniform3fv(location, length, &Array[0].x);
}

///=============================================================================
void ffw::Shader::SetUniform3i(GLint location, const ffw::Vec3i& vec) const {
    gl_->glUniform3i(location, vec.x, vec.y, vec.z);
}

///=============================================================================
void ffw::Shader::SetUniform3iv(GLint location, const ffw::Vec3i* Array, GLsizei length) const {
	gl_->glUniform3iv(location, length, &Array[0].x);
}

///=============================================================================
// Set 4D uniforms from vector
void ffw::Shader::SetUniform4f(GLint location, const ffw::Vec4f& vec) const {
    gl_->glUniform4f(location, vec.x, vec.y, vec.z, vec.w);
}

///=============================================================================
void ffw::Shader::SetUniform4fv(GLint location, const ffw::Vec4f* Array, GLsizei length) const {
	gl_->glUniform4fv(location, length, &Array[0].x);
}

///=============================================================================
void ffw::Shader::SetUniform4i(GLint location, const ffw::Vec4i& vec) const {
    gl_->glUniform4i(location, vec.x, vec.y, vec.z, vec.w);
}

///=============================================================================
void ffw::Shader::SetUniform4iv(GLint location, const ffw::Vec4i* Array, GLsizei length) const {
	gl_->glUniform4iv(location, length, &Array[0].x);
}

///=============================================================================
// Set 4D uniform from color
void ffw::Shader::SetUniform4f(GLint location, const ffw::Color& col) const {
    gl_->glUniform4f(location, col.r, col.g, col.b, col.a);
}

///=============================================================================
void ffw::Shader::SetUniform4fv(GLint location, const ffw::Color* Array, GLsizei length) const {
	gl_->glUniform4fv(location, length, &Array[0].r);
}

///=============================================================================
// Set Matrix uniforms
void ffw::Shader::SetUniformMatrix2fv(GLint location, const GLfloat* mat, GLsizei length) const {
    gl_->glUniformMatrix2fv(location, length, GL_FALSE, mat);
}

///=============================================================================
void ffw::Shader::SetUniformMatrix3fv(GLint location, const GLfloat* mat, GLsizei length) const {
    gl_->glUniformMatrix3fv(location, length, GL_FALSE, mat);
}

///=============================================================================
void ffw::Shader::SetUniformMatrix4fv(GLint location, const GLfloat* mat, GLsizei length) const {
    gl_->glUniformMatrix4fv(location, length, false, mat);
}

///=============================================================================
void ffw::Shader::SetUniformMatrix4fv(GLint location, const Mat4x4f* mat, GLsizei length) const {
    gl_->glUniformMatrix4fv(location, length, false, reinterpret_cast<const GLfloat*>(mat));
}
