/*** This file is part of FineFramework project ***/

#include "ffw/media/objloader.h"
#define VECTOR_BUCKET_SIZE 256
#include <string.h>
#include <limits.h>
#include "ffw/math/functions.h"
#include "ffw/math/vec2.h"
#include "ffw/math/stringmath.h"

///=============================================================================
ffw::ObjLoader::ObjLoader(){
    loaded = false;
	lineCount = 0;
	newMaterialFlag = 0;
	gotLine = false;
	tokensRead = 0;
	indexes[0] = 0;
	indexes[1] = 0;
	indexes[2] = 0;
	objectFound = false;
}

///=============================================================================
ffw::ObjLoader::~ObjLoader(){
	close();
}

///=============================================================================
ffw::ObjLoader::ObjLoader(ffw::ObjLoader&& other){
	swap(other);
}

///=============================================================================
ffw::ObjLoader& ffw::ObjLoader::operator = (ffw::ObjLoader&& other){
	if(&other != this){
		swap(other);
	}

	return *this;
}

///=============================================================================
void ffw::ObjLoader::swap(ObjLoader& other){
	using std::swap;
	swap(input, other.input);
	swap(loaded, other.loaded);
	swap(mtllibName, other.mtllibName);
	swap(lineCount, other.lineCount);
	swap(normals, other.normals);
	swap(vertices, other.vertices);
	swap(texcoords, other.texcoords);
	swap(newMaterialFlag, other.newMaterialFlag);
	swap(currentMaterial, other.currentMaterial);
	swap(line, other.line);
	swap(gotLine, other.gotLine);
	swap(previousPos, other.previousPos);
	swap(lineTokens, other.lineTokens);
	swap(tokensRead, other.tokensRead);
	swap(hasNormals, other.hasNormals);
	swap(hasTexcoords, other.hasTexcoords);
	swap(indexes[0], other.indexes[0]);
	swap(indexes[1], other.indexes[1]);
	swap(indexes[2], other.indexes[2]);
	swap(objectFound, other.objectFound);
}

///=============================================================================
bool ffw::ObjLoader::open(const std::string& path){
	if(loaded)close();

	input->open(path, std::ios::binary | std::ios::in);
	if(!input->is_open())return false;

	// Seek down and check for mtllib
	while(std::getline(*input, line)) {
		lineCount++;
		if (line.size() == 0)continue;
		if (line[0] == '#')continue;
		if (line[0] == 'm') {
			if(line.find("mtllib") == 0) {
				mtllibName = line.substr(7);
			}
			break;
		} else {
			break;
		}
	}

	loaded = true;
	return true;
}

///=============================================================================
void ffw::ObjLoader::close(){
	loaded = false;
	lineCount = 0;
	input->close();
	texcoords.clear();
	vertices.clear();
	normals.clear();
	lineTokens.clear();
	gotLine = false;
	newMaterialFlag = false;
	currentMaterial.clear();
	mtllibName.clear();
	tokensRead = 0;
	indexes[0] = 0;
	indexes[1] = 0;
	indexes[2] = 0;
	objectFound = false;
}

inline void insetValue(std::vector<ffw::Vec3f>& vec, ffw::Vec3f& val) {
	if(vec.size() >= vec.capacity()) {
		vec.reserve(vec.capacity() + VECTOR_BUCKET_SIZE);
		//std::cout << "resized vector to: " << vec.capacity() << std::endl;
	}
	vec.push_back(val);
}

inline float fastFloat(const char* begin) {
	return (float)atof(begin);
}

inline int fastAtoi(const char* begin) {
	int val = 0;
	while (*begin) {
		if (*begin < '0' || *begin > '9')return val;
		val = val * 10 + (*begin++ - '0');
	}
	return val;
}

static bool parseIndices(const char* begin, size_t length, ffw::Vec3i& out) {
	size_t counter = 0;
	size_t last = 0;

	// Check whitespace
	bool found = true;
	for (size_t i = 0; i < length; i++) {
		if (begin[i] != ' ')found = false;
	}
	if (found)return false;
	//std::cout << "parseIndices: " << std::string(begin, length) << std::endl;

	for(size_t i = 0; i < length; i++) {
		auto c = begin[i];
		if(c == '/') {
			if (last - i > 0) {

				if (counter == 0) {
					//std::cout << "vertex1: " << std::string(begin, i) << std::endl;
					out.x = fastAtoi(begin);
				}

				else if (counter == 1) {
					//std::cout << "texture1: " << std::string(begin + last, i - last) << std::endl;
					out.y = fastAtoi(begin + last);
				}

				else if (counter == 2) {
					//std::cout << "normal1: " << std::string(begin + last, i - last) << std::endl;
					out.z = fastAtoi(begin + last);
				}
			}

			last = i+1;
			counter++;
		}
	}

	if (counter == 0) {
		//std::cout << "vertex2: " << std::string(begin + last, length - last) << std::endl;
		out.x = fastAtoi(begin + last);
	}

	else if (counter == 1) {
		//std::cout << "texture2: " << std::string(begin + last, length - last) << std::endl;
		out.y = fastAtoi(begin + last);
	}

	else if (counter == 2) {
		//std::cout << "normal2: " << std::string(begin + last, length - last) << std::endl;
		out.z = fastAtoi(begin + last);
	}

	return true;
}

static void parseLineIndices(const std::string& line, std::vector<ffw::Vec3i>& out) {
	//std::cout << "\tparsing: " << line << std::endl;
	size_t pos = 1;
	size_t last = 1;
	out.clear();
	ffw::Vec3i val(INT_MAX);
	while ((pos = line.find(' ', pos)) != std::string::npos) {
		if (last < pos) {
			//std::cout << "\tindices: " << line.substr(last, pos - last) << std::endl;
			if (parseIndices(&line[last], pos - last, val)) {
				out.push_back(val);
				val.set(INT_MAX);
			}
		}
		pos++;
		last = pos;
	}

	//std::cout << "\tindices: " << line.substr(last, line.size() - last) << std::endl;
	if (parseIndices(&line[last], line.size() - last, val)) {
		out.push_back(val);
	}
}

static void parseLineFloat(const std::string& line, ffw::Vec3f& out) {
	size_t pos = 0;
	size_t last = 0;
	size_t counter = 0;
	out.set(0.0f);
	while ((pos = line.find(' ', pos)) != std::string::npos) {
		if(last < pos) {
			//std::cout << "token: \"" << line.substr(last, pos - last) << std::endl;
			switch(counter) {
				case 0:
					break;
				case 1: 
					out.x = fastFloat(&line[last]);
					break;
				case 2:
					out.y = fastFloat(&line[last]);
					break;
				case 3: 
					out.z = fastFloat(&line[last]);
					break;
				default:
					break;
			}
			counter++;
		}
		pos++;
		last = pos;
	}

	switch (counter) {
	case 1:
		out.x = fastFloat(&line[last]);
		break;
	case 2:
		out.y = fastFloat(&line[last]);
		break;
	case 3:
		out.z = fastFloat(&line[last]);
		break;
	default:
		return;
	}
}

///=============================================================================
bool ffw::ObjLoader::getNextObject(std::string* name) {
	ffw::Vec3f val;
	while (std::getline(*input, line)) {
		lineCount++;
		if (line.size() == 0)continue;
		if (line[0] == '#')continue;
		if (line.size() <= 2)continue;

		// Vertex
		if(line[0] == 'v' && line[1] == ' ') {
			parseLineFloat(line, val);
			insetValue(vertices, val);
			//std::cout << "v " << val << std::endl;
		}

		// Normal
		else if (line[0] == 'v' && line[1] == 'n') {
			parseLineFloat(line, val);
			insetValue(normals, val);
			//std::cout << "vn " << val << std::endl;
		}

		// Texture coordinate
		else if (line[0] == 'v' && line[1] == 't') {
			parseLineFloat(line, val);
			insetValue(texcoords, val);
			//std::cout << "vt " << val << std::endl;
		}

		// Object/geometry
		else if ((line[0] == 'o' || line[0] == 'g') && line[1] == ' ') {
			if (name != NULL)*name = line.substr(2);
		}

		// Use mtl
		else if (line.size() > 6 && line[0] == 'u' && line[1] == 's') {
			currentMaterial = line.substr(7);
			newMaterialFlag = true;
		}

		// Smoothing groups
		else if (line[0] == 's' && line[1] == ' ') {
			continue;
		}

		// Face
		else if (line[0] == 'f' && line[1] == ' ') {
			parseLineIndices(line, lineTokens);
			if (lineTokens.size() == 0) {
				objectFound = false;
				return false;
			}
			hasNormals = lineTokens[0].z != INT_MAX;
			hasTexcoords = lineTokens[0].y != INT_MAX;
			tokensRead = 0;
			gotLine = true;
			objectFound = true;
			return true;
		}

		else {
			return false;
		}
	}

	objectFound = false;
	return false;
}

///=============================================================================
size_t ffw::ObjLoader::calculatePolyCount() {
	size_t ret = 0;
	if (!objectFound)return ret;

	// Calculate already parsed line
	switch(lineTokens.size()) {
		case 0: break;
		case 1: break;
		case 2: break;
		case 3: ret += 1; break;
		case 4: ret += 2; break;
		default: ret += lineTokens.size() - 2;
	}

	// Read line by line
	std::string temp;
	size_t offset = input->tellg();
	while (std::getline(*input, temp)) {
		if (temp.size() <= 2)continue;

		// Face
		if (temp[0] == 'f' && temp[1] == ' ') {
			size_t count = ffw::getTokensNum(temp, " ");
			switch (count) {
				case 1: break;
				case 2: break;
				case 3: break;
				case 4: ret += 1; break;
				case 5: ret += 2; break;
				default: ret += count - 3;
			}
		}

		if ((temp[0] == 'o' || temp[0] == 'g') && temp[1] == ' ') {
			break;
		}
	}


	input->clear();
	input->seekg(offset);
	return ret;
}

///=============================================================================
bool ffw::ObjLoader::getPolygon() {
	
	ffw::Vec3f val;

	while (!gotLine && !input->eof()) {
		previousPos = input->tellg();
		if (!std::getline(*input, line)) {
			// Failed to get a next line
			objectFound = false;
			return false;
		}
		lineCount++;
		//std::cout << "reading line: " << line << std::endl;

		if (line.size() == 0)continue;
		if (line[0] == '#')continue;
		if (line.size() <= 2)continue;

		// Face
		if (line[0] == 'f' && line[1] == ' ') {
			parseLineIndices(line, lineTokens);
			tokensRead = 0;
			gotLine = true;
			break;
		}

		// Vertex
		if (line[0] == 'v' && line[1] == ' ') {
			parseLineFloat(line, val);
			insetValue(vertices, val);
			continue;
		}

		// Normal
		if (line[0] == 'v' && line[1] == 'n') {
			parseLineFloat(line, val);
			insetValue(normals, val);
			continue;
		}

		// Texture coordinate
		if (line[0] == 'v' && line[1] == 't') {
			parseLineFloat(line, val);
			insetValue(texcoords, val);
			continue;
		}

		// Use mtl
		if (line.size() > 6 && line[0] == 'u' && line[1] == 's') {
			currentMaterial = line.substr(7);
			newMaterialFlag = true;
			continue;
		}

		// Smoothing groups
		if (line[0] == 's' && line[1] == ' ') {
			continue;
		}

		// Object/geometry
		if ((line[0] == 'o' || line[0] == 'g') && line[1] == ' ') {
			//std::cout << "new geometry found at: " << lineCount << std::endl;
			input->seekg(previousPos, std::ios_base::beg);
			objectFound = false;
			return false;
		}
	}

	if(lineTokens.size() == 3) {
		//std::cout << "parsing triangle " << tokensRead << std::endl;
		indexes[0] = 2;
		indexes[1] = 1;
		indexes[2] = 0;
		gotLine = false;
	}

	else if (lineTokens.size() == 4) {
		//std::cout << "parsing quad " << tokensRead << std::endl;
		if(tokensRead == 0) {
			indexes[0] = 0;
			indexes[1] = 3;
			indexes[2] = 1;
		} else {
			indexes[0] = 1;
			indexes[1] = 3;
			indexes[2] = 2;
			gotLine = false;
		}
	}

	else {
		//std::cout << "parsing poly " << tokensRead << std::endl;
		indexes[0] = 0;
		indexes[1] = tokensRead + 2;
		indexes[2] = tokensRead + 1;
		if(tokensRead + 3 >= lineTokens.size()) {
			gotLine = false;
		}
	}

	tokensRead++;
	return true;
}

///=============================================================================
void ffw::ObjLoader::fillData(float* ptr, size_t vo, size_t no, size_t to, bool ts, size_t stride) {
	ffw::Vec3f n;
	if (!hasNormals) {
		auto dir0 = vertices[lineTokens[indexes[0]].x - 1] - vertices[lineTokens[indexes[2]].x - 1];
		auto dir1 = vertices[lineTokens[indexes[0]].x - 1] - vertices[lineTokens[indexes[1]].x - 1];
		n = ffw::cross(dir0, dir1);
		n.normalize();
	}

	for (int i = 0; i < 3; i++) {
		memcpy(&ptr[vo], &vertices[lineTokens[indexes[i]].x - 1].x, sizeof(ffw::Vec3f));
		//ptr[0] = vertices[lineTokens[indexes[i]].x - 1].x;
		//ptr[1] = vertices[lineTokens[indexes[i]].x - 1].y;
		//ptr[2] = vertices[lineTokens[indexes[i]].x - 1].z;
		if (hasNormals) {
			memcpy(&ptr[no], &normals[lineTokens[indexes[i]].z - 1].x, sizeof(ffw::Vec3f));
		} else {
			memcpy(&ptr[no], &n.x, sizeof(ffw::Vec3f));
		}

		if (hasTexcoords) {
			if (ts) {
				memcpy(&ptr[to], &texcoords[lineTokens[indexes[i]].y - 1].x, sizeof(ffw::Vec3f));
			} else {
				memcpy(&ptr[to], &texcoords[lineTokens[indexes[i]].y - 1].x, sizeof(ffw::Vec2f));
			}
		}

		ptr += stride;
	}
}

bool ffw::readObj(const std::string& path, float** vertices, unsigned int* numVertices) {
	ffw::ObjLoader obj;

	if (!obj.open(path))return false;

	if (!obj.getNextObject(NULL))return false;

	auto total = obj.calculatePolyCount();
	if (total == 0)return false;

	if (numVertices != NULL)*numVertices = total * 3;
	if (vertices == NULL)return true;

	*vertices = new float[total * 24];
	float* ptr = *vertices;

	while (obj.getPolygon()) {
		obj.fillData(ptr);
		ptr = &ptr[24];
	}

	return true;
}