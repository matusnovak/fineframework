/*** This file is part of FineFramework project ***/

#include "ffw/graphics/shader.h"
#include "ffw/graphics/rendercontext.h"
#include <fstream>

///=============================================================================
static bool loadTxt(const std::string& path, std::string* output){
	if(output == NULL)return false;

	std::ifstream input(path, std::ios::in | std::ios::binary);

	if(!input)return false;

	input.seekg(0, std::ios::end);
	output->reserve(static_cast<size_t>(input.tellg()));
	input.seekg(0, std::ios::beg);

	output->assign((std::istreambuf_iterator<char>(input)),
				std::istreambuf_iterator<char>());

    return true;
}

///=============================================================================
bool ffw::Shader::checkCompability(const ffw::RenderContext* renderer){
	if(renderer == NULL)return false;
	const ffw::RenderExtensions* gl_ = static_cast<const RenderExtensions*>(renderer);

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
    loaded = false;
	linked = false;
    usinggeom = false;
    usingvert = false;
    usingfrag = false;
	program = 0;
	vertshader = 0;
	geomshader = 0;
	fragshader = 0;
	gl_ = NULL;
}

///=============================================================================
ffw::Shader::Shader(Shader&& other) {
	loaded = false;
	linked = false;
	usinggeom = false;
	usingvert = false;
	usingfrag = false;
	program = 0;
	vertshader = 0;
	geomshader = 0;
	fragshader = 0;
	gl_ = NULL;
	swap(other);
}

///=============================================================================
void ffw::Shader::swap(Shader& other) {
	if (this != &other) {
		using std::swap;
		swap(loaded, other.loaded);
		swap(linked, other.linked);
		swap(usinggeom, other.usinggeom);
		swap(usingvert, other.usingvert);
		swap(usingfrag, other.usingfrag);
		swap(program, other.program);
		swap(vertshader, other.vertshader);
		swap(geomshader, other.geomshader);
		swap(fragshader, other.fragshader);
		swap(gl_, other.gl_);
	}
}

///=============================================================================
ffw::Shader& ffw::Shader::operator = (Shader&& other) {
	if(this != &other) {
		swap(other);
	}
	return *this;
}

///=============================================================================
ffw::Shader::~Shader(){
    destroy();
}

///=============================================================================
/*bool ffw::Shader::createFromFile(const ffw::RenderContext* renderer, const std::string& geompath, const std::string& vertpath, const std::string& fragpath){
	if(loaded)return false;

    errorlogstr_ = "";
    std::string geomdata;
    std::string vertdata;
    std::string fragdata;

    // If path for geometry Shader is not empty, load file
    if(geompath != ""){
        if(!::loadTxt(geompath, &geomdata)){
            return false;
        }
    }
    // If path for vertex Shader is not empty, load file
    if(vertpath != ""){
        if(!::loadTxt(vertpath, &vertdata)){
            return false;
        }
    }
    // If path for fragment Shader is not empty, load file
    if(fragpath != ""){
        if(!::loadTxt(fragpath, &fragdata)){
            return false;
        }
    }

    // Now we have sources data, load them into program
    if(createFromData(renderer,
		(geomdata.size() > 0 ? geomdata.c_str() : NULL),
		(vertdata.size() > 0 ? vertdata.c_str() : NULL),
		(fragdata.size() > 0 ? fragdata.c_str() : NULL))
		){
        return true;
    }
    return false;
}

///=============================================================================
bool ffw::Shader::createFromData(const ffw::RenderContext* renderer, const char* geomdata, const char* vertdata, const char* fragdata){
	if(loaded)return false;
	if(!checkCompability(renderer))return false;
	loaded = true;

	gl_ = static_cast<const RenderExtensions*>(renderer);

	errorlogstr_ = "";
    // create Shader
    program = gl_->glCreateProgram();
    gl_->glUseProgram(program);

    // Compile geometry Shader if source data is not empty
    if(geomdata != NULL){
        // Compile Shader
		#ifdef FFW_OSX
		if(compileShader(geomshader_, geomdata, GL_GEOMETRY_SHADER)){
		#else
        if(compileShader(geomshader_, geomdata, GL_GEOMETRY_SHADER_ARB)){
		#endif
            // Shader is compiled attach it to program
            gl_->glAttachShader(program, geomshader_);
            // We are using this Shader
            usinggeom_ = true;
        } else {
            // If compilation failed, delete program
            gl_->glDeleteProgram(program);
            // Switch back to main Shader
            gl_->glUseProgram(0);
			loaded = false;
            return false;
        }
    }
    // Compile vertex Shader
    if(vertdata != NULL){
        if(compileShader(vertshader_, vertdata, GL_VERTEX_SHADER)){
            gl_->glAttachShader(program, vertshader_);
            usingvert_ = true;
        } else {
            gl_->glDeleteProgram(program);
            gl_->glUseProgram(0);
			loaded = false;
            return false;
        }
    }
    // Compile fragment Shader
    if(fragdata != NULL){
        if(compileShader(fragshader_, fragdata, GL_FRAGMENT_SHADER)){
            gl_->glAttachShader(program, fragshader_);
            usingfrag_ = true;
        } else {
            gl_->glDeleteProgram(program);
            gl_->glUseProgram(0);
			loaded = false;
            return false;
        }
    }

    // Link program
    gl_->glLinkProgram(program);

    // Check for program errors
    std::string errorstr;
    if(!checkForProgramErrors(&errorstr)){
        // If there were any errors, delete Shader
        destroy();
        // Switch back to main Shader
        gl_->glUseProgram(0);

		if (errorlogstr_.size() != 0)errorlogstr_ += "\n";
		errorlogstr_ += "Linking log: " + errorstr;
		loaded = false;
        return false;
    }

    // We are done, switch back to main Shader
    gl_->glUseProgram(0);
    return true;
}*/

///=============================================================================
bool ffw::Shader::create(const RenderContext* renderer) {
	if (loaded)return false;
	if (!checkCompability(renderer))return false;

	gl_ = static_cast<const RenderExtensions*>(renderer);
	// create Shader
	program = gl_->glCreateProgram();
	if (program == 0)return false;

	gl_->glUseProgram(program);
	loaded = true;
	return true;
}

///=============================================================================
void ffw::Shader::Link() {
	if (!loaded) {
		throw Shader::CompileException("Shader is not created! Did you forget to call setup(const RenderContext*)?");
	}
	// Link program
	gl_->glLinkProgram(program);

	// Check for program errors
	std::string errorstr;
	if (!checkForProgramErrors(&errorstr)) {
		// If there were any errors, delete Shader
		destroy();
		
		throw Shader::CompileException(errorstr);
	}
}

///=============================================================================
void ffw::Shader::compileFragFromData(const std::string& code) {
	compileShader(fragshader, code.c_str(), GL_FRAGMENT_SHADER);
	gl_->glAttachShader(program, fragshader);
	usingfrag = true;
}

///=============================================================================
void ffw::Shader::compileGeomFromData(const std::string& code) {
#ifdef FFW_OSX
	compileShader(geomshader, code.c_str(), GL_GEOMETRY_SHADER);
#else
	compileShader(geomshader, code.c_str(), GL_GEOMETRY_SHADER_ARB);
#endif
	gl_->glAttachShader(program, geomshader);
	usinggeom = true;
}

///=============================================================================
void ffw::Shader::compileVertFromData(const std::string& code) {
	compileShader(vertshader, code.c_str(), GL_VERTEX_SHADER);
	gl_->glAttachShader(program, vertshader);
	usingvert = true;
}

///=============================================================================
void ffw::Shader::createFromFile(const RenderContext* renderer, const std::string& geomfile, const std::string& vertfile, const std::string& fragfile) {
	std::string data;
	if (!create(renderer)) {
		throw Shader::CompileException("Failed to create shader object!");
	}

	if (geomfile.size() > 0) {
		if (loadTxt(geomfile, &data)) compileGeomFromData(data);
		else throw Shader::FileException(geomfile);
	}

	data.clear();
	if(vertfile.size() > 0){
		if (loadTxt(vertfile, &data)) compileVertFromData(data);
		else throw Shader::FileException(vertfile);
	}

	data.clear();
	if (fragfile.size() > 0) {
		if (loadTxt(fragfile, &data)) compileFragFromData(data);
		else throw Shader::FileException(fragfile);
	}

	Link();
}

///=============================================================================
void ffw::Shader::createFromData(const RenderContext* renderer, const std::string& geomdata, const std::string& vertdata, const std::string& fragdata) {
	if (!create(renderer)) {
		throw Shader::CompileException("Failed to create shader object!");
	}
	if (geomdata.size() > 0)compileGeomFromData(geomdata);
	if (vertdata.size() > 0)compileVertFromData(vertdata);
	if (fragdata.size() > 0)compileFragFromData(fragdata);
	Link();
}

///=============================================================================
void ffw::Shader::compileShader(GLuint& thisshader, const GLchar* data, GLenum shadertype){
    // create Shader based on type
    thisshader = gl_->glCreateShader(shadertype);
    // set the source data
    gl_->glShaderSource(thisshader, 1, &data, NULL);
    // Compile
    gl_->glCompileShader(thisshader);
    // Check for compilation errors
    std::string errorstr;
    if(!checkForShaderErrors(thisshader, &errorstr)){
        // If there were any errors, delete newly loaded Shader
        gl_->glDeleteShader(thisshader);
		throw Shader::CompileException(errorstr);
    }
}

///=============================================================================
bool ffw::Shader::checkForShaderErrors(GLuint thisshader, std::string* errorstr){

    // Check Shader compilation status
    GLint result;
    gl_->glGetShaderiv(thisshader, GL_COMPILE_STATUS, &result);
    // Shader failed to compile
    if(result == GL_FALSE) {
        // get length of log
        GLint length;
        gl_->glGetShaderiv(thisshader, GL_INFO_LOG_LENGTH, &length);
        // allocate memory for log
        errorstr->resize(length, ' ');
        // get log
        gl_->glGetShaderInfoLog(thisshader, length, &result, &(*errorstr)[0]);
        return false;
    }
    // Shader compiled
    return true;
}

///=============================================================================
bool ffw::Shader::checkForProgramErrors(std::string* errorstr){

    // Check program for linking errors
    GLint result;
    gl_->glGetProgramiv(program, GL_LINK_STATUS, &result);
    // Program linking failed
    if(result == GL_FALSE) {
        // get length og log
        GLint length;
        gl_->glGetProgramiv(program, GL_INFO_LOG_LENGTH, &length);
        // allocate memory for log
        errorstr->resize(length, ' ');
        // get log
        gl_->glGetProgramInfoLog(program, length, &result, &(*errorstr)[0]);
        return false;
    }
    // Program linked
    return true;
}

///=============================================================================
void ffw::Shader::destroy(){
    // Delete Shader if it was loaded
    if(usinggeom)gl_->glDeleteShader(geomshader);
    if(usingvert)gl_->glDeleteShader(vertshader);
    if(usingfrag)gl_->glDeleteShader(fragshader);
	usinggeom = false;
	usingvert = false;
	usingfrag = false;
    // Delete program
    if(program != 0)gl_->glDeleteProgram(program);
	program = 0;
    loaded = false;
	linked = false;
}

///=============================================================================
void ffw::Shader::bind() const {
    if(loaded)gl_->glUseProgram(program);
}

///=============================================================================
void ffw::Shader::unbind() const {
    if(loaded){
		// We need to disable attrib array
		// Otherwise this will mess up any old pipeline draw calls 
		gl_->glDisableVertexAttribArray(0);
		gl_->glUseProgram(0);
	}
}

///=============================================================================
void ffw::Shader::setAttributePointerf(GLint Location, GLint Size, GLsizei Stride, const GLvoid* offset) const {
    // Enable attribute
    gl_->glEnableVertexAttribArray(Location);
    // set the pointer of the attribute
    gl_->glVertexAttribPointer(Location, Size, GL_FLOAT, GL_FALSE, Stride, offset);
}

///=============================================================================
void ffw::Shader::setAttributeDivisor(GLuint Index, GLuint Divisor) const {
    gl_->glVertexAttribDivisor(Index, Divisor);
}

///=============================================================================
void ffw::Shader::drawArrays(GLenum Mode, GLint First, GLsizei count) const {
    // draw quad compositing of two triangles drawElements(GL_TRIANGLES, 6, 0);
    // drawElements(type to render, first vertice, number of vertices);
    glDrawArrays(Mode, First, count);
}

///=============================================================================
void ffw::Shader::drawArraysInstanced(GLenum Mode, GLint First, GLsizei count, GLsizei InstanceCount) const {
    gl_->glDrawArraysInstanced(Mode, First, count, InstanceCount);
}

///=============================================================================
void ffw::Shader::drawElements(GLenum Mode, GLsizei count, GLenum Type, const GLvoid * Indices) const {
    // draw quad compositing of two triangles myShader.drawElements(GL_TRIANGLES, 6, 0);
    // draw second triangle of quad drawElements(GL_TRIANGLES, 3, (GLvoid*) (sizeof(GLuint) * 3));
    // drawElements(type to render, number of vertices, (GLvoid*) (sizeof(GLuint) * vertice offset));
    glDrawElements(Mode, count, Type, Indices);
}

///=============================================================================
void ffw::Shader::drawElementsRange(GLenum Mode, GLuint Start, GLuint End, GLsizei count, GLenum Type, const GLvoid * Indices) const {
    // draw second triangle of quad drawElementsRange(GL_TRIANGLES, 0, 3, 3, (GLvoid*) (sizeof(GLuint) * 3));
    // drawElementsRange(type to render, min index, max index, number of vertices, (GLvoid*) (sizeof(GLuint) * vertice offset));
    gl_->glDrawRangeElements(Mode, Start, End, count, Type, Indices);
}

///=============================================================================
void ffw::Shader::drawElementsInstanced(GLenum Mode, GLsizei count, GLenum Type, const GLvoid * Indices, GLsizei InstanceCount) const {
    gl_->glDrawElementsInstanced(Mode, count, Type, Indices, InstanceCount);
}

///=============================================================================
int ffw::Shader::getUniformLocation(const GLchar* Name) const {
    if(!loaded)return -1;
    return gl_->glGetUniformLocation(program, Name);
}

///=============================================================================
int ffw::Shader::getAttributeLocation(const GLchar* Name) const {
    if(!loaded)return -1;
    return gl_->glGetAttribLocation(program, Name);
}
///=============================================================================
// set 1D uniforms
void ffw::Shader::setUniform1f(GLint location, GLfloat value) const {
    gl_->glUniform1f(location, value);
}

///=============================================================================
void ffw::Shader::setUniform1fv(GLint location, const GLfloat* array, GLsizei length) const {
    gl_->glUniform1fv(location, length, array);
}

///=============================================================================
void ffw::Shader::setUniform1i(GLint location, GLint value) const {
    gl_->glUniform1i(location, value);
}

///=============================================================================
void ffw::Shader::setUniform1iv(GLint location, const GLint* array, GLsizei length) const {
    gl_->glUniform1iv(location, length, array);
}

///=============================================================================
// set 2D uniforms
void ffw::Shader::setUniform2f(GLint location, GLfloat x, GLfloat y) const {
    gl_->glUniform2f(location, x, y);
}

///=============================================================================
void ffw::Shader::setUniform2fv(GLint location, const GLfloat* array, GLsizei length) const {
    gl_->glUniform2fv(location, length, array);
}

///=============================================================================
void ffw::Shader::setUniform2i(GLint location, GLint x, GLint y) const {
    gl_->glUniform2i(location, x, y);
}

///=============================================================================
void ffw::Shader::setUniform2iv(GLint location, const GLint* array, GLsizei length) const {
    gl_->glUniform2iv(location, length, array);
}

///=============================================================================
// set 3D uniforms
void ffw::Shader::setUniform3f(GLint location, GLfloat x, GLfloat y, GLfloat z) const {
    gl_->glUniform3f(location, x, y, z);
}

///=============================================================================
void ffw::Shader::setUniform3fv(GLint location, const GLfloat* array, GLsizei length) const {
    gl_->glUniform3fv(location, length, array);
}

///=============================================================================
void ffw::Shader::setUniform3i(GLint location, GLint x, GLint y, GLint z) const {
    gl_->glUniform3i(location, x, y, z);
}

///=============================================================================
void ffw::Shader::setUniform3iv(GLint location, const GLint* array, GLsizei length) const {
    gl_->glUniform3iv(location, length, array);
}


///=============================================================================
// set 4D uniforms
void ffw::Shader::setUniform4f(GLint location, GLfloat x, GLfloat y, GLfloat z, GLfloat w) const {
    gl_->glUniform4f(location, x, y, z, w);
}

///=============================================================================
void ffw::Shader::setUniform4fv(GLint location, const GLfloat* array, GLsizei length) const {
    gl_->glUniform4fv(location, length, array);
}

///=============================================================================
void ffw::Shader::setUniform4i(GLint location, GLint x, GLint y, GLint z, GLint w) const {
    gl_->glUniform4i(location, x, y, z, w);
}

///=============================================================================
void ffw::Shader::setUniform4iv(GLint location, const GLint* array, GLsizei length) const {
    gl_->glUniform4iv(location, length, array);
}

///=============================================================================
// set 2D uniforms from vector
void ffw::Shader::setUniform2f(GLint location, const ffw::Vec2f& vec) const {
    gl_->glUniform2f(location, vec.x, vec.y);
}

///=============================================================================
void ffw::Shader::setUniform2fv(GLint location, const ffw::Vec2f* Array, GLsizei length) const {
	gl_->glUniform2fv(location, length, &Array[0].x);
}

///=============================================================================
void ffw::Shader::setUniform2i(GLint location, const ffw::Vec2i& vec) const {
    gl_->glUniform2i(location, vec.x, vec.y);
}

///=============================================================================
void ffw::Shader::setUniform2iv(GLint location, const ffw::Vec2i* Array, GLsizei length) const {
	gl_->glUniform2iv(location, length, &Array[0].x);
}

///=============================================================================
// set 3D uniforms from vector
void ffw::Shader::setUniform3f(GLint location, const ffw::Vec3f& vec) const {
    gl_->glUniform3f(location, vec.x, vec.y, vec.z);
}

///=============================================================================
void ffw::Shader::setUniform3fv(GLint location, const ffw::Vec3f* Array, GLsizei length) const {
	gl_->glUniform3fv(location, length, &Array[0].x);
}

///=============================================================================
void ffw::Shader::setUniform3i(GLint location, const ffw::Vec3i& vec) const {
    gl_->glUniform3i(location, vec.x, vec.y, vec.z);
}

///=============================================================================
void ffw::Shader::setUniform3iv(GLint location, const ffw::Vec3i* Array, GLsizei length) const {
	gl_->glUniform3iv(location, length, &Array[0].x);
}

///=============================================================================
// set 4D uniforms from vector
void ffw::Shader::setUniform4f(GLint location, const ffw::Vec4f& vec) const {
    gl_->glUniform4f(location, vec.x, vec.y, vec.z, vec.w);
}

///=============================================================================
void ffw::Shader::setUniform4fv(GLint location, const ffw::Vec4f* Array, GLsizei length) const {
	gl_->glUniform4fv(location, length, &Array[0].x);
}

///=============================================================================
void ffw::Shader::setUniform4i(GLint location, const ffw::Vec4i& vec) const {
    gl_->glUniform4i(location, vec.x, vec.y, vec.z, vec.w);
}

///=============================================================================
void ffw::Shader::setUniform4iv(GLint location, const ffw::Vec4i* Array, GLsizei length) const {
	gl_->glUniform4iv(location, length, &Array[0].x);
}

///=============================================================================
// set 4D uniform from color
void ffw::Shader::setUniform4f(GLint location, const ffw::Color& col) const {
    gl_->glUniform4f(location, col.r, col.g, col.b, col.a);
}

///=============================================================================
void ffw::Shader::setUniform4fv(GLint location, const ffw::Color* Array, GLsizei length) const {
	gl_->glUniform4fv(location, length, &Array[0].r);
}

///=============================================================================
// set Matrix uniforms
void ffw::Shader::setUniformMatrix2fv(GLint location, const GLfloat* mat, GLsizei length) const {
    gl_->glUniformMatrix2fv(location, length, GL_FALSE, mat);
}

///=============================================================================
void ffw::Shader::setUniformMatrix3fv(GLint location, const GLfloat* mat, GLsizei length) const {
    gl_->glUniformMatrix3fv(location, length, GL_FALSE, mat);
}

///=============================================================================
void ffw::Shader::setUniformMatrix4fv(GLint location, const GLfloat* mat, GLsizei length) const {
    gl_->glUniformMatrix4fv(location, length, false, mat);
}

///=============================================================================
void ffw::Shader::setUniformMatrix4fv(GLint location, const Mat4x4f* mat, GLsizei length) const {
    gl_->glUniformMatrix4fv(location, length, false, reinterpret_cast<const GLfloat*>(mat));
}