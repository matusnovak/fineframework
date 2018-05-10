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
bool ffw::Shader::create() {
    if (loaded)return false;

    // create Shader
    program = glCreateProgram();
    if (program == 0)return false;

    glUseProgram(program);
    loaded = true;
    return true;
}

///=============================================================================
void ffw::Shader::Link() {
    if (!loaded) {
        throw Shader::CompileException("Shader is not created! Did you forget to call setup(const RenderContext*)?");
    }
    // Link program
    glLinkProgram(program);

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
    glAttachShader(program, fragshader);
    usingfrag = true;
}

///=============================================================================
void ffw::Shader::compileGeomFromData(const std::string& code) {
#ifdef FFW_OSX
    compileShader(geomshader, code.c_str(), GL_GEOMETRY_SHADER);
#else
    compileShader(geomshader, code.c_str(), GL_GEOMETRY_SHADER_ARB);
#endif
    glAttachShader(program, geomshader);
    usinggeom = true;
}

///=============================================================================
void ffw::Shader::compileVertFromData(const std::string& code) {
    compileShader(vertshader, code.c_str(), GL_VERTEX_SHADER);
    glAttachShader(program, vertshader);
    usingvert = true;
}

///=============================================================================
void ffw::Shader::createFromFile(const std::string& geomfile, const std::string& vertfile, const std::string& fragfile) {
    std::string data;
    if (!create()) {
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
void ffw::Shader::createFromData(const std::string& geomdata, const std::string& vertdata, const std::string& fragdata) {
    if (!create()) {
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
    thisshader = glCreateShader(shadertype);
    // set the source data
    glShaderSource(thisshader, 1, &data, NULL);
    // Compile
    glCompileShader(thisshader);
    // Check for compilation errors
    std::string errorstr;
    if(!checkForShaderErrors(thisshader, &errorstr)){
        // If there were any errors, delete newly loaded Shader
        glDeleteShader(thisshader);
        throw Shader::CompileException(errorstr);
    }
}

///=============================================================================
bool ffw::Shader::checkForShaderErrors(GLuint thisshader, std::string* errorstr){

    // Check Shader compilation status
    GLint result;
    glGetShaderiv(thisshader, GL_COMPILE_STATUS, &result);
    // Shader failed to compile
    if(result == GL_FALSE) {
        // get length of log
        GLint length;
        glGetShaderiv(thisshader, GL_INFO_LOG_LENGTH, &length);
        // allocate memory for log
        errorstr->resize(length, ' ');
        // get log
        glGetShaderInfoLog(thisshader, length, &result, &(*errorstr)[0]);
        return false;
    }
    // Shader compiled
    return true;
}

///=============================================================================
bool ffw::Shader::checkForProgramErrors(std::string* errorstr){

    // Check program for linking errors
    GLint result;
    glGetProgramiv(program, GL_LINK_STATUS, &result);
    // Program linking failed
    if(result == GL_FALSE) {
        // get length og log
        GLint length;
        glGetProgramiv(program, GL_INFO_LOG_LENGTH, &length);
        // allocate memory for log
        errorstr->resize(length, ' ');
        // get log
        glGetProgramInfoLog(program, length, &result, &(*errorstr)[0]);
        return false;
    }
    // Program linked
    return true;
}

///=============================================================================
void ffw::Shader::destroy(){
    // Delete Shader if it was loaded
    if(usinggeom)glDeleteShader(geomshader);
    if(usingvert)glDeleteShader(vertshader);
    if(usingfrag)glDeleteShader(fragshader);
    usinggeom = false;
    usingvert = false;
    usingfrag = false;
    // Delete program
    if(program != 0)glDeleteProgram(program);
    program = 0;
    loaded = false;
    linked = false;
}

///=============================================================================
void ffw::Shader::bind() const {
    if(loaded)glUseProgram(program);
}

///=============================================================================
void ffw::Shader::unbind() const {
    if(loaded){
        // We need to disable attrib array
        // Otherwise this will mess up any old pipeline draw calls 
        glDisableVertexAttribArray(0);
        glUseProgram(0);
    }
}

///=============================================================================
void ffw::Shader::setAttributePointerf(GLint Location, GLint Size, GLsizei Stride, const GLvoid* offset) const {
    // Enable attribute
    glEnableVertexAttribArray(Location);
    // set the pointer of the attribute
    glVertexAttribPointer(Location, Size, GL_FLOAT, GL_FALSE, Stride, offset);
}

///=============================================================================
void ffw::Shader::setAttributeDivisor(GLuint Index, GLuint Divisor) const {
    glVertexAttribDivisor(Index, Divisor);
}

///=============================================================================
void ffw::Shader::drawArrays(GLenum Mode, GLint First, GLsizei count) const {
    // draw quad compositing of two triangles drawElements(GL_TRIANGLES, 6, 0);
    // drawElements(type to render, first vertice, number of vertices);
    glDrawArrays(Mode, First, count);
}

///=============================================================================
void ffw::Shader::drawArraysInstanced(GLenum Mode, GLint First, GLsizei count, GLsizei InstanceCount) const {
    glDrawArraysInstanced(Mode, First, count, InstanceCount);
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
    glDrawRangeElements(Mode, Start, End, count, Type, Indices);
}

///=============================================================================
void ffw::Shader::drawElementsInstanced(GLenum Mode, GLsizei count, GLenum Type, const GLvoid * Indices, GLsizei InstanceCount) const {
    glDrawElementsInstanced(Mode, count, Type, Indices, InstanceCount);
}

///=============================================================================
int ffw::Shader::getUniformLocation(const GLchar* Name) const {
    if(!loaded)return -1;
    return glGetUniformLocation(program, Name);
}

///=============================================================================
int ffw::Shader::getAttributeLocation(const GLchar* Name) const {
    if(!loaded)return -1;
    return glGetAttribLocation(program, Name);
}
///=============================================================================
// set 1D uniforms
void ffw::Shader::setUniform1f(GLint location, GLfloat value) const {
    glUniform1f(location, value);
}

///=============================================================================
void ffw::Shader::setUniform1fv(GLint location, const GLfloat* array, GLsizei length) const {
    glUniform1fv(location, length, array);
}

///=============================================================================
void ffw::Shader::setUniform1i(GLint location, GLint value) const {
    glUniform1i(location, value);
}

///=============================================================================
void ffw::Shader::setUniform1iv(GLint location, const GLint* array, GLsizei length) const {
    glUniform1iv(location, length, array);
}

///=============================================================================
// set 2D uniforms
void ffw::Shader::setUniform2f(GLint location, GLfloat x, GLfloat y) const {
    glUniform2f(location, x, y);
}

///=============================================================================
void ffw::Shader::setUniform2fv(GLint location, const GLfloat* array, GLsizei length) const {
    glUniform2fv(location, length, array);
}

///=============================================================================
void ffw::Shader::setUniform2i(GLint location, GLint x, GLint y) const {
    glUniform2i(location, x, y);
}

///=============================================================================
void ffw::Shader::setUniform2iv(GLint location, const GLint* array, GLsizei length) const {
    glUniform2iv(location, length, array);
}

///=============================================================================
// set 3D uniforms
void ffw::Shader::setUniform3f(GLint location, GLfloat x, GLfloat y, GLfloat z) const {
    glUniform3f(location, x, y, z);
}

///=============================================================================
void ffw::Shader::setUniform3fv(GLint location, const GLfloat* array, GLsizei length) const {
    glUniform3fv(location, length, array);
}

///=============================================================================
void ffw::Shader::setUniform3i(GLint location, GLint x, GLint y, GLint z) const {
    glUniform3i(location, x, y, z);
}

///=============================================================================
void ffw::Shader::setUniform3iv(GLint location, const GLint* array, GLsizei length) const {
    glUniform3iv(location, length, array);
}


///=============================================================================
// set 4D uniforms
void ffw::Shader::setUniform4f(GLint location, GLfloat x, GLfloat y, GLfloat z, GLfloat w) const {
    glUniform4f(location, x, y, z, w);
}

///=============================================================================
void ffw::Shader::setUniform4fv(GLint location, const GLfloat* array, GLsizei length) const {
    glUniform4fv(location, length, array);
}

///=============================================================================
void ffw::Shader::setUniform4i(GLint location, GLint x, GLint y, GLint z, GLint w) const {
    glUniform4i(location, x, y, z, w);
}

///=============================================================================
void ffw::Shader::setUniform4iv(GLint location, const GLint* array, GLsizei length) const {
    glUniform4iv(location, length, array);
}

///=============================================================================
// set 2D uniforms from vector
void ffw::Shader::setUniform2f(GLint location, const ffw::Vec2f& vec) const {
    glUniform2f(location, vec.x, vec.y);
}

///=============================================================================
void ffw::Shader::setUniform2fv(GLint location, const ffw::Vec2f* Array, GLsizei length) const {
    glUniform2fv(location, length, &Array[0].x);
}

///=============================================================================
void ffw::Shader::setUniform2i(GLint location, const ffw::Vec2i& vec) const {
    glUniform2i(location, vec.x, vec.y);
}

///=============================================================================
void ffw::Shader::setUniform2iv(GLint location, const ffw::Vec2i* Array, GLsizei length) const {
    glUniform2iv(location, length, &Array[0].x);
}

///=============================================================================
// set 3D uniforms from vector
void ffw::Shader::setUniform3f(GLint location, const ffw::Vec3f& vec) const {
    glUniform3f(location, vec.x, vec.y, vec.z);
}

///=============================================================================
void ffw::Shader::setUniform3fv(GLint location, const ffw::Vec3f* Array, GLsizei length) const {
    glUniform3fv(location, length, &Array[0].x);
}

///=============================================================================
void ffw::Shader::setUniform3i(GLint location, const ffw::Vec3i& vec) const {
    glUniform3i(location, vec.x, vec.y, vec.z);
}

///=============================================================================
void ffw::Shader::setUniform3iv(GLint location, const ffw::Vec3i* Array, GLsizei length) const {
    glUniform3iv(location, length, &Array[0].x);
}

///=============================================================================
// set 4D uniforms from vector
void ffw::Shader::setUniform4f(GLint location, const ffw::Vec4f& vec) const {
    glUniform4f(location, vec.x, vec.y, vec.z, vec.w);
}

///=============================================================================
void ffw::Shader::setUniform4fv(GLint location, const ffw::Vec4f* Array, GLsizei length) const {
    glUniform4fv(location, length, &Array[0].x);
}

///=============================================================================
void ffw::Shader::setUniform4i(GLint location, const ffw::Vec4i& vec) const {
    glUniform4i(location, vec.x, vec.y, vec.z, vec.w);
}

///=============================================================================
void ffw::Shader::setUniform4iv(GLint location, const ffw::Vec4i* Array, GLsizei length) const {
    glUniform4iv(location, length, &Array[0].x);
}

///=============================================================================
// set 4D uniform from color
void ffw::Shader::setUniform4f(GLint location, const ffw::Color& col) const {
    glUniform4f(location, col.r, col.g, col.b, col.a);
}

///=============================================================================
void ffw::Shader::setUniform4fv(GLint location, const ffw::Color* Array, GLsizei length) const {
    glUniform4fv(location, length, &Array[0].r);
}

///=============================================================================
// set Matrix uniforms
void ffw::Shader::setUniformMatrix2fv(GLint location, const GLfloat* mat, GLsizei length) const {
    glUniformMatrix2fv(location, length, GL_FALSE, mat);
}

///=============================================================================
void ffw::Shader::setUniformMatrix3fv(GLint location, const GLfloat* mat, GLsizei length) const {
    glUniformMatrix3fv(location, length, GL_FALSE, mat);
}

///=============================================================================
void ffw::Shader::setUniformMatrix4fv(GLint location, const GLfloat* mat, GLsizei length) const {
    glUniformMatrix4fv(location, length, false, mat);
}

///=============================================================================
void ffw::Shader::setUniformMatrix4fv(GLint location, const Mat4x4f* mat, GLsizei length) const {
    glUniformMatrix4fv(location, length, false, reinterpret_cast<const GLfloat*>(mat));
}