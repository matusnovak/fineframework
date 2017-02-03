/* This file is part of FineFramework project */
#ifndef FFW_MEDIA_OBJ_LOADER
#define FFW_MEDIA_OBJ_LOADER
#include "../config.h"
#include "../math.h"
#include <fstream>

namespace ffw{
	/**
	* @ingroup media
	*/
	class FFW_API ObjLoader {
	public:
		struct ObjectInfo {
			std::string name;
			size_t vCount;
			size_t vtCount;
			size_t vnCount;
			size_t fCount;
			size_t vPos;
			size_t vtPos;
			size_t vnPos;
			size_t fPos;
			size_t vOffset;
			size_t vtOffset;
			size_t vnOffset;
			size_t fEnd;
		};

		struct MeshData {
			std::vector<ffw::Vec3f> vertices;
			std::vector<ffw::Vec3f> normals;
			std::vector<ffw::Vec2f> texpos;
		};
		
		ObjLoader();
		ObjLoader(const ObjLoader& other) = delete;
		ObjLoader(ObjLoader&& other);
		~ObjLoader();
		void swap(ObjLoader& other);
		bool Open(const std::string& path);
		inline bool IsOpen() const {
			return loaded;
		}
		inline operator bool () const {
			return IsOpen();
		}
		void Close();
		inline bool Eof() const {
			return eos;
		}
		bool LoadObject(unsigned int i);
		inline size_t GetObjectCount() const {
			return objects.size();
		}
		inline bool HasObjectVertices(unsigned int i) const {
			if(i >= objects.size())return false;
			else return objects[i].vCount > 0;
		}
		inline bool HasObjectNormals(unsigned int i) const {
			if(i >= objects.size())return false;
			else return objects[i].vnCount > 0;
		}
		inline bool HasObjectTexPos(unsigned int i) const {
			if(i >= objects.size())return false;
			else return objects[i].vtCount > 0;
		}
		inline const std::string& GetObjectName(unsigned int i) const {
			static const std::string empty = "";
			if(i >= objects.size())return empty;
			else return objects[i].name;
		}
		size_t CalculateObjectPolyCount();
		bool GetPolygon(float* ptr);
		ObjLoader& operator = (ObjLoader&& Other);
		ObjLoader& operator = (const ObjLoader& Other) = delete;

	private:
		std::vector<ObjectInfo> objects;
		ObjectInfo* activeObject;
		size_t fRead;
		ffw::SwapWrapper<std::fstream> input;
		bool gotLine;
		size_t tokensRead;
		size_t tokensTotal;
		std::vector<std::string> lineTokens;
		bool doubleSlash;
		bool eos;
		MeshData activeObjectMesh;
		size_t currentLineNum;
		bool gotMiddle;
		ffw::Vec3f middleV;
		ffw::Vec3f middleVN;
		ffw::Vec2f middleVT;
		bool loaded;
	};
	/**
	* @ingroup media
	*/
	bool FFW_API ReadObj(const std::string& path, float** vertices, unsigned int* numVertices);
#ifdef FFW_GRAPHICS_MODULE
	inline bool ReadObj(const std::string& path, const ffw::RenderContext* context, ffw::Vbo* vbo, GLenum type = GL_STATIC_DRAW){
		unsigned int numVertices = 0;
		float* vertices = NULL;

		if(!ReadObj(path, &vertices, &numVertices)){
			return false;
		}

		if(!vbo->Create(context, vertices, numVertices * 8 * sizeof(float), type)){
			//std::cerr << "ReadObj: Failed to create VBO!" << std::endl;
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
