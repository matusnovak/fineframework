/* This file is part of FineFramework project */
#ifndef FFW_MEDIA_OBJ_LOADER
#define FFW_MEDIA_OBJ_LOADER
#include "../config.h"
#include "../math/vec3.h"
#include "../math/vec2.h"
#include "../swapwrapper.h"
#include <fstream>
#include <string>
#include <vector>
namespace ffw{
	/**
	* @ingroup media
	*/
	class FFW_API ObjLoader {
	public:
		ObjLoader();
		ObjLoader(const ObjLoader& other) = delete;
		ObjLoader(ObjLoader&& other);
		~ObjLoader();
		void swap(ObjLoader& other);
		bool open(const std::string& path);
		bool getNextObject(std::string* name);
		bool getPolygon();
		size_t calculatePolyCount();
		inline bool isOpen() const {
			return loaded;
		}
		inline operator bool () const {
			return isOpen();
		}
		inline const std::string& getMtllibName() const {
			return mtllibName;
		}
		inline size_t getCurrentLineNum() const {
			return lineCount;
		}
		inline const std::string& getCurrentMaterialName() const {
			return currentMaterial;
		}
		inline bool getMaterialFoundFlag() const {
			return newMaterialFlag;
		}
		inline void resetMaterialFoundFlag() {
			newMaterialFlag = false;
		}
		inline bool objectHasNormals() const {
			return hasNormals;
		}
		inline bool objectHasTexcoords() const {
			return hasTexcoords;
		}
		inline const ffw::Vec3i& getIndex0() const {
			return lineTokens[indexes[0]];
		}
		inline const ffw::Vec3i& getIndex1() const {
			return lineTokens[indexes[1]];
		}
		inline const ffw::Vec3i& getIndex2() const {
			return lineTokens[indexes[2]];
		}
		inline const ffw::Vec3f& getVertex(size_t i) const {
			return vertices[lineTokens[indexes[i]].x - 1];
		}
		inline const ffw::Vec3f& getNormal(size_t i) const {
			return normals[lineTokens[indexes[i]].z - 1];
		}
		inline const ffw::Vec2f& getTexCoord2(size_t i) const {
			return (const ffw::Vec2f&)texcoords[lineTokens[indexes[i]].y - 1];
		}
		inline const ffw::Vec3f& getTexCoord3(size_t i) const {
			return texcoords[lineTokens[indexes[i]].y - 1];
		}
		inline bool gotObject() const {
			return objectFound;
		}
		void fillData(float* ptr, size_t vo = 0, size_t no = 3, size_t to = 6, bool ts = false, size_t stride = 8);
		void close();
		ObjLoader& operator = (ObjLoader&& Other);
		ObjLoader& operator = (const ObjLoader& Other) = delete;

	private:
		ffw::SwapWrapper<std::fstream> input;
		bool loaded;
		std::string mtllibName;
		size_t lineCount;
		std::string currentMaterial;
		bool newMaterialFlag;
		std::string line;
		bool gotLine;
		size_t previousPos;
		std::vector<ffw::Vec3i> lineTokens;
		size_t tokensRead;
		bool hasNormals;
		bool hasTexcoords;
		size_t indexes[3];
		bool objectFound;

		std::vector<ffw::Vec3f> vertices;
		std::vector<ffw::Vec3f> normals;
		std::vector<ffw::Vec3f> texcoords;
	};

	/**
	* @ingroup media
	*/
	bool FFW_API readObj(const std::string& path, float** vertices, unsigned int* numVertices);
#ifdef FFW_GRAPHICS_MODULE
	inline bool readObj(const std::string& path, const ffw::RenderContext* context, ffw::Vbo* vbo, GLenum type = GL_STATIC_DRAW) {
		unsigned int numVertices = 0;
		float* vertices = NULL;

		if (!readObj(path, &vertices, &numVertices)) {
			return false;
		}

		if (!vbo->create(context, vertices, numVertices * 8 * sizeof(float), type)) {
			//std::cerr << "readObj: Failed to create VBO!" << std::endl;
			delete[] vertices;
			return false;
		}

		delete[] vertices;
		return true;
	}
#endif
};

inline void swap(ffw::ObjLoader& first, ffw::ObjLoader& second){
	first.swap(second);
}

#endif
