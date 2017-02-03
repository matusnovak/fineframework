/*** This file is part of FineFramework project ***/

#include "ffw/media/objloader.h"

///=============================================================================
static bool LoadVertices(std::fstream& input, ffw::ObjLoader::ObjectInfo& object, ffw::ObjLoader::MeshData& mesh){
	if(object.vCount == 0)return true;

	//std::cout << "LoadVertices" << std::endl;
	size_t total = 0;
	mesh.vertices.resize(object.vCount);
	std::string line;
	std::vector<std::string> tokens;

	input.seekg(object.vPos);
	while(!input.eof() && total < object.vCount){
		//std::cout << "total: " << total << std::endl;
		std::getline(input, line);
		if(line[0] != 'v' || line[1] != ' ')continue;

		tokens = ffw::GetTokens(line, ' ');
		if(tokens.size() >= 3){
			try {
				mesh.vertices[total].x = ffw::StringToVal<float>(tokens[1]);
				mesh.vertices[total].y = ffw::StringToVal<float>(tokens[2]);
				mesh.vertices[total].z = ffw::StringToVal<float>(tokens[3]);
			} catch (std::exception e){
			}
		}
		total++;
	}
	//std::cout << "vertices loaded" << std::endl;
	return true;
}

///=============================================================================
static bool LoadNormals(std::fstream& input, ffw::ObjLoader::ObjectInfo& object, ffw::ObjLoader::MeshData& mesh){
	if(object.vnCount == 0)return true;

	//std::cout << "LoadNormals" << std::endl;
	size_t total = 0;
	mesh.normals.resize(object.vnCount);
	std::string line;
	std::vector<std::string> tokens;

	input.seekg(object.vnPos);
	while(!input.eof() && total < object.vnCount){
		//std::cout << "total: " << total << std::endl;
		std::getline(input, line);
		if(line[0] != 'v' || line[1] != 'n')continue;

		tokens = ffw::GetTokens(line, ' ');
		if(tokens.size() >= 3){
			try {
				mesh.normals[total].x = ffw::StringToVal<float>(tokens[1]);
				mesh.normals[total].y = ffw::StringToVal<float>(tokens[2]);
				mesh.normals[total].z = ffw::StringToVal<float>(tokens[3]);
			} catch (std::exception e){
			}
		}
		total++;
	}
	//std::cout << "normals loaded" << std::endl;
	return true;
}

///=============================================================================
static bool LoadTexpos(std::fstream& input, ffw::ObjLoader::ObjectInfo& object, ffw::ObjLoader::MeshData& mesh){
	if(object.vtCount == 0)return true;

	//std::cout << "LoadTexpos" << std::endl;
	size_t total = 0;
	mesh.texpos.resize(object.vtCount);
	std::string line;
	std::vector<std::string> tokens;

	input.seekg(object.vtPos);
	while(!input.eof() && total < object.vtCount){
		//std::cout << "total: " << total << std::endl;
		std::getline(input, line);
		if(line[0] != 'v' || line[1] != 't')continue;

		tokens = ffw::GetTokens(line, ' ');
		if(tokens.size() >= 2){
			try {
				mesh.texpos[total].x = ffw::StringToVal<float>(tokens[1]);
				mesh.texpos[total].y = ffw::StringToVal<float>(tokens[2]);
			} catch (std::exception e){
			}
		}
		total++;
	}
	//std::cout << "texpos loaded" << std::endl;
	return true;
}

///=============================================================================
ffw::ObjLoader::ObjLoader(){
    loaded = false;
}

///=============================================================================
ffw::ObjLoader::~ObjLoader(){
	Close();
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
	swap(objects, other.objects);
	swap(activeObject, other.activeObject);
	swap(fRead, other.fRead);
	swap(input, other.input);
	swap(gotLine, other.gotLine);
	swap(tokensRead, other.tokensRead);
	swap(tokensTotal, other.tokensTotal);
	swap(lineTokens, other.lineTokens);
	swap(doubleSlash, other.doubleSlash);
	swap(eos, other.eos);
	swap(activeObjectMesh, other.activeObjectMesh);
	swap(currentLineNum, other.currentLineNum);
	swap(gotMiddle, other.gotMiddle);
	swap(middleV, other.middleV);
	swap(middleVN, other.middleVN);
	swap(middleVT, other.middleVT);
	swap(loaded, other.loaded);
}

///=============================================================================
bool ffw::ObjLoader::Open(const std::string& path){
	if(loaded)Close();

	input->open(path, std::ios::binary | std::ios::in);
	if(!input->is_open())return false;

	size_t lineNum = 0;
	ObjectInfo* currentObject = NULL;
	size_t vTotal = 0;
	size_t vtTotal = 0;
	size_t vnTotal = 0;

	objects.push_back(ObjectInfo());
	currentObject = &objects.back();
	currentObject->vCount = 0;
	currentObject->vtCount = 0;
	currentObject->vnCount = 0;
	currentObject->fCount = 0;
	currentObject->vPos = 0;
	currentObject->vtPos = 0;
	currentObject->vnPos = 0;
	currentObject->fPos = 0;
	currentObject->fEnd = 0;
	currentObject->vOffset = vTotal;
	currentObject->vtOffset = vtTotal;
	currentObject->vnOffset = vnTotal;

	bool gotFaces = false;

	while(!input->eof()){
		std::string line;
		lineNum++;

		size_t pos = (size_t)input->tellg();
		std::getline(*input, line);

		// New set of vertices, must be a new object
		if(((line[0] == 'v' && line[1] == ' ') || (line[0] == 'o' && line[1] == ' ')) && gotFaces){
			vTotal += currentObject->vCount;
			vtTotal += currentObject->vtCount;
			vnTotal += currentObject->vnCount;
			currentObject->fEnd = pos;
			objects.push_back(ObjectInfo());
			currentObject = &objects.back();
			currentObject->vCount = 0;
			currentObject->vtCount = 0;
			currentObject->vnCount = 0;
			currentObject->fCount = 0;
			currentObject->vPos = 0;
			currentObject->vtPos = 0;
			currentObject->vnPos = 0;
			currentObject->fPos = 0;
			currentObject->vOffset = vTotal;
			currentObject->vtOffset = vtTotal;
			currentObject->vnOffset = vnTotal;
			gotFaces = false;
		}

		// object name
		if((line[0] == 'o' || line[0] == 'g') && line.size() > 2){
			currentObject->name = line.substr(2, line.size());
			continue;
		}

		// object vertices
		if(line[0] == 'v' && line[1] == ' ' && currentObject != NULL && currentObject->vPos == 0){
			currentObject->vPos = pos;
			currentObject->vCount++;
			continue;
		} else if(line[0] == 'v' && line[1] == ' ' && currentObject != NULL){
			currentObject->vCount++;
			continue;
		}

		// object uvs
		if(line[0] == 'v' && line[1] == 't' && currentObject != NULL && currentObject->vtPos == 0){
			currentObject->vtPos = pos;
			currentObject->vtCount++;
			continue;
		} else if(line[0] == 'v' && line[1] == 't' && currentObject != NULL){
			currentObject->vtCount++;
			continue;
		}

		// object normals
		if(line[0] == 'v' && line[1] == 'n' && currentObject != NULL && currentObject->vnPos == 0){
			currentObject->vnPos = pos;
			currentObject->vnCount++;
			continue;
		} else if(line[0] == 'v' && line[1] == 'n' && currentObject != NULL){
			currentObject->vnCount++;
			continue;
		}

		if(gotFaces && currentObject != NULL){
			currentObject->fEnd = pos;
		}

		// object faces
		if(line[0] == 'f' && line[1] == ' ' && currentObject != NULL && currentObject->fPos == 0){
			gotFaces = true;
			currentObject->fPos = pos;
			currentObject->fCount++;
			continue;
		} else if(line[0] == 'f' && line[1] == ' ' && currentObject != NULL){
			currentObject->fCount++;
			continue;
		}
	}

	input->clear();
	input->seekg(0, std::ios::beg);
	fRead = 0;
	gotLine = false;
	eos = true;
	activeObject = NULL;
	loaded = true;
	return true;
}

///=============================================================================
bool ffw::ObjLoader::LoadObject(unsigned int i){
	if(i >= objects.size())return false;
	activeObject = &objects[i];
	input->clear();
	input->seekg(0, std::ios::beg);

	bool result =
	LoadVertices(*input, *activeObject, activeObjectMesh) &&
	LoadNormals(*input, *activeObject, activeObjectMesh) &&
	LoadTexpos(*input, *activeObject, activeObjectMesh);

	//std::cout << "done loadgin!" << std::endl;
	input->clear();
	input->seekg(0, std::ios::beg);
	if(result)input->seekg(activeObject->fPos);
	gotLine = false;
	eos = false;
	currentLineNum = 0;
	gotMiddle = false;

	if(!result){
		activeObject = NULL;
	}

	return result;
}

///=============================================================================
size_t ffw::ObjLoader::CalculateObjectPolyCount(){ 
	if(activeObject == NULL)return 0;

	size_t total = 0;

	//std::cout << "CalculateObjectPolyCount" << std::endl;
	while(input->tellg() < activeObject->fEnd){
		//std::cout << "tellg: " << input->tellg() << " end: " << activeObject->fEnd << std::endl;
		std::string line;
		std::getline(*input, line);
		if(line[0] != 'f' || line[1] != ' '){
			//std::cout << "continue" << std::endl;
			continue;
		}
		unsigned int tokens = ffw::GetTokensNum(line, ' ');
		if(tokens == 4)total += 1;
		else if(tokens == 5)total += 2;
		else if(tokens > 5){
			total += tokens-1;
		}
		//std::cout << "polys: " << total << std::endl;
	}

	//std::cout << "CalculateObjectPolyCount done" << std::endl;
	input->clear();
	input->seekg(0, std::ios::beg);
	input->seekg(activeObject->fPos);

	return total;
}

///=============================================================================
bool ffw::ObjLoader::GetPolygon(float* ptr){
	float* P0 = &ptr[0];
	float* N0 = &ptr[3];
	float* T0 = &ptr[6];

	float* P1 = &ptr[8];
	float* N1 = &ptr[11];
	float* T1 = &ptr[14];

	float* P2 = &ptr[16];
	float* N2 = &ptr[19];
	float* T2 = &ptr[22];
	
	if(activeObject == NULL)return false;

	std::string line;
	while(!gotLine && input->tellg() <= activeObject->fEnd){
		std::getline(*input, line);
		currentLineNum++;

		if(line[0] != 'f' || line[1] != ' ')continue;

		lineTokens = ffw::GetTokens(line, ' ');
		if(lineTokens.size() <= 3){
			return false;
		}

		tokensTotal = lineTokens.size() -1;
		doubleSlash = (line.find("//") != std::string::npos);
		tokensRead = 0;
		gotLine = true;
	}

	// End of stream?
	if(!gotLine){
		eos = true;
		return false;
	}

	int v0i = 0;
	int v1i = 0;
	int v2i = 0;
	int vt0i = 0;
	int vt1i = 0;
	int vt2i = 0;
	int vn0i = 0;
	int vn1i = 0;
	int vn2i = 0;

	std::vector<std::string> v0Tokens;
	std::vector<std::string> v1Tokens;
	std::vector<std::string> v2Tokens;

	bool useMiddle = false;

	// Triangle
	if(lineTokens.size() == 4){

		std::string& v0 = lineTokens[1];
		std::string& v1 = lineTokens[2];
		std::string& v2 = lineTokens[3];

		v0Tokens = ffw::GetTokens(v0, '/');
		v1Tokens = ffw::GetTokens(v1, '/');
		v2Tokens = ffw::GetTokens(v2, '/');

		gotLine = false;
		tokensRead = 1;
	}

	// Quad
	if(lineTokens.size() == 5){

		std::string* v0;
		std::string* v1;
		std::string* v2;

		if(tokensRead == 0){
			v0 = &lineTokens[1];
			v1 = &lineTokens[2];
			v2 = &lineTokens[4];
		} else {
			v0 = &lineTokens[4];
			v1 = &lineTokens[2];
			v2 = &lineTokens[3];
		}

		v0Tokens = ffw::GetTokens(*v0, '/');
		v1Tokens = ffw::GetTokens(*v1, '/');
		v2Tokens = ffw::GetTokens(*v2, '/');

		tokensRead++;
		if(tokensRead >= 2)gotLine = false;
	}

	// Poly
	if(lineTokens.size() > 5){
		if(!gotMiddle){
			std::vector<std::string> tempTokens;
			int tv = 0;
			int tvn = 0;
			int tvt = 0;
			middleV = 0.0f;
			middleVN = 0.0f;
			middleVT = 0.0f;
			try {
				for(unsigned int i = 1; i < lineTokens.size(); i++){
					tempTokens = ffw::GetTokens(lineTokens[i], '/');

					if(tempTokens.size() == 1){
						tv = ffw::StringToVal<int>(tempTokens[0]);
						tvn = 0;
						tvt = 0;

					} else if(tempTokens.size() == 2 && doubleSlash){
						tv = ffw::StringToVal<int>(tempTokens[0]);
						tvn = ffw::StringToVal<int>(tempTokens[1]);
						tvt = 0;

					} else if(tempTokens.size() == 2){
						tv = ffw::StringToVal<int>(tempTokens[0]);
						tvt = ffw::StringToVal<int>(tempTokens[1]);
						tvn = 0;

					} else if(tempTokens.size() == 3){
						tv = ffw::StringToVal<int>(tempTokens[0]);
						tvn = ffw::StringToVal<int>(tempTokens[1]);
						tvt = ffw::StringToVal<int>(tempTokens[2]);
					}

					if(tv > 0 && activeObject->vCount > 0)middleV += activeObjectMesh.vertices[tv - activeObject->vOffset -1];
					if(tvn > 0 && activeObject->vnCount > 0)middleVN += activeObjectMesh.normals[tvn - activeObject->vnOffset -1];
					if(tvt > 0 && activeObject->vtCount > 0)middleVT += activeObjectMesh.texpos[tvt - activeObject->vtOffset -1];
				}
				middleV /= float(tokensTotal -1);
				middleVN /= float(tokensTotal -1);
				middleVT /= float(tokensTotal -1);

			} catch (std::exception e){
			}
			gotMiddle = true;
		}

		if(tokensRead == lineTokens.size()-2){
			v0Tokens = ffw::GetTokens(lineTokens[tokensRead+1], '/');
			v1Tokens = ffw::GetTokens(lineTokens[1], '/');
		} else {
			v0Tokens = ffw::GetTokens(lineTokens[tokensRead+1], '/');
			v1Tokens = ffw::GetTokens(lineTokens[tokensRead+2], '/');
		}
		useMiddle = true;

		tokensRead++;
		if(tokensRead >= tokensTotal){gotLine = false; gotMiddle = false;}
	}

	// Check if we have tokens for each vertex
	if(useMiddle && (v0Tokens.size() == 0 || v1Tokens.size() == 0))return false;
	if(!useMiddle && (v0Tokens.size() == 0 || v1Tokens.size() == 0 || v2Tokens.size() == 0))return false;

	if(useMiddle && v0Tokens.size() != v1Tokens.size())return false;
	if(!useMiddle && (v0Tokens.size() != v1Tokens.size() || v1Tokens.size() != v2Tokens.size()))return false;

	try {
		v2i = ffw::StringToVal<int>(v0Tokens[0]);
		v1i = ffw::StringToVal<int>(v1Tokens[0]);
		if(!useMiddle)
			v0i = ffw::StringToVal<int>(v2Tokens[0]);

		// V/VT/VN
		if(v0Tokens.size() == 3){
			vt2i = ffw::StringToVal<int>(v0Tokens[1]);
			vt1i = ffw::StringToVal<int>(v1Tokens[1]);
			if(!useMiddle)
				vt0i = ffw::StringToVal<int>(v2Tokens[1]);

			vn2i = ffw::StringToVal<int>(v0Tokens[2]);
			vn1i = ffw::StringToVal<int>(v1Tokens[2]);
			if(!useMiddle)
				vn0i = ffw::StringToVal<int>(v2Tokens[2]);

		// V//VN
		} else if(v0Tokens.size() == 2 && doubleSlash){
			vn2i = ffw::StringToVal<int>(v0Tokens[1]);
			vn1i = ffw::StringToVal<int>(v1Tokens[1]);
			if(!useMiddle)
				vn0i = ffw::StringToVal<int>(v2Tokens[1]);

			vt0i = 0;
			vt1i = 0;
			vt2i = 0;

		// V/VT
		} else if(v0Tokens.size() == 2){
			vt2i = ffw::StringToVal<int>(v0Tokens[1]);
			vt1i = ffw::StringToVal<int>(v1Tokens[1]);
			if(!useMiddle)
				vt0i = ffw::StringToVal<int>(v2Tokens[1]);

			vn0i = 0;
			vn1i = 0;
			vn2i = 0;

		} else {
			vt0i = 0;
			vt1i = 0;
			vt2i = 0;

			vn0i = 0;
			vn1i = 0;
			vn2i = 0;
		}
	} catch (std::exception e){
		return false;
	}

	if(!gotLine && currentLineNum >= activeObject->fCount)eos = true;

	if(activeObject->vCount > 0){
		if(!useMiddle && v0i > 0){
			P0[0] = activeObjectMesh.vertices[v0i - activeObject->vOffset -1].x;
			P0[1] = activeObjectMesh.vertices[v0i - activeObject->vOffset -1].y;
			P0[2] = activeObjectMesh.vertices[v0i - activeObject->vOffset -1].z;

		} else if(useMiddle){
			P0[0] = middleV.x;
			P0[1] = middleV.y;
			P0[2] = middleV.z;
		}
		if(v1i > 0){
			P1[0] = activeObjectMesh.vertices[v1i - activeObject->vOffset -1].x;
			P1[1] = activeObjectMesh.vertices[v1i - activeObject->vOffset -1].y;
			P1[2] = activeObjectMesh.vertices[v1i - activeObject->vOffset -1].z;
		}
		if(v2i > 0){
			P2[0] = activeObjectMesh.vertices[v2i - activeObject->vOffset -1].x;
			P2[1] = activeObjectMesh.vertices[v2i - activeObject->vOffset -1].y;
			P2[2] = activeObjectMesh.vertices[v2i - activeObject->vOffset -1].z;
		}
	}

	if(activeObject->vnCount > 0){
		if(!useMiddle && vn0i > 0){
			N0[0] = activeObjectMesh.normals[vn0i - activeObject->vnOffset -1].x;
			N0[1] = activeObjectMesh.normals[vn0i - activeObject->vnOffset -1].y;
			N0[2] = activeObjectMesh.normals[vn0i - activeObject->vnOffset -1].z;
		}else if(useMiddle){
			N0[0] = middleVN.x;
			N0[1] = middleVN.y;
			N0[2] = middleVN.z;
		}
		if(vn1i > 0){
			N1[0] = activeObjectMesh.normals[vn1i - activeObject->vnOffset -1].x;
			N1[1] = activeObjectMesh.normals[vn1i - activeObject->vnOffset -1].y;
			N1[2] = activeObjectMesh.normals[vn1i - activeObject->vnOffset -1].z;
		}
		if(vn2i > 0){
			N2[0] = activeObjectMesh.normals[vn2i - activeObject->vnOffset -1].x;
			N2[1] = activeObjectMesh.normals[vn2i - activeObject->vnOffset -1].y;
			N2[2] = activeObjectMesh.normals[vn2i - activeObject->vnOffset -1].z;
		}
	}

	if(activeObject->vtCount > 0){
		if(!useMiddle && vt0i > 0){
			T0[0] = activeObjectMesh.texpos[vt0i - activeObject->vtOffset -1].x;
			T0[1] = activeObjectMesh.texpos[vt0i - activeObject->vtOffset -1].y;
		}else if(useMiddle){
			T0[0] = middleVT.x;
			T0[1] = middleVT.y;
		}
		if(vt1i > 0){
			T1[0] = activeObjectMesh.texpos[vt1i - activeObject->vtOffset -1].x;
			T1[1] = activeObjectMesh.texpos[vt1i - activeObject->vtOffset -1].y;
		}
		if(vt2i > 0){
			T2[0] = activeObjectMesh.texpos[vt2i - activeObject->vtOffset -1].x;
			T2[1] = activeObjectMesh.texpos[vt2i - activeObject->vtOffset -1].y;
		}
	}

	return true;
}

///=============================================================================
void ffw::ObjLoader::Close(){
	loaded = false;
	input->close();
	objects.clear();
	activeObjectMesh.vertices.clear();
	activeObjectMesh.normals.clear();
	activeObjectMesh.texpos.clear();
	activeObject = NULL;
}

///=============================================================================
bool ffw::ReadObj(const std::string& path, float** vertices, unsigned int* numVertices){
	ffw::ObjLoader obj;

	//std::cout << "Openning object..." << std::endl;
	if(!obj.Open(path))return false;

	//std::cout << "Loading object..." << std::endl;
	if(!obj.LoadObject(0))return false;

	auto total = obj.CalculateObjectPolyCount();
	//std::cout << "Total vertices: " << total << std::endl;

	if(numVertices != NULL)*numVertices = total*3;
	if(vertices == NULL)return true;

	*vertices = new float [total*24];
	float* ptr = *vertices;

	bool genNormals = !obj.HasObjectNormals(0);
	bool genTexpos = !obj.HasObjectTexPos(0);

	ffw::Vec3f dir0;
	ffw::Vec3f dir1;
	ffw::Vec3f c;

	while(!obj.Eof()){
		ffw::Vec3f* p0 = reinterpret_cast<ffw::Vec3f*>(&ptr[0]);
		ffw::Vec3f* p1 = reinterpret_cast<ffw::Vec3f*>(&ptr[3]);
		ffw::Vec3f* p2 = reinterpret_cast<ffw::Vec3f*>(&ptr[6]);

		ffw::Vec3f* n0 = reinterpret_cast<ffw::Vec3f*>(&ptr[8]);
		ffw::Vec3f* n1 = reinterpret_cast<ffw::Vec3f*>(&ptr[11]);
		ffw::Vec3f* n2 = reinterpret_cast<ffw::Vec3f*>(&ptr[14]);

		ffw::Vec2f* t0 = reinterpret_cast<ffw::Vec2f*>(&ptr[16]);
		ffw::Vec2f* t1 = reinterpret_cast<ffw::Vec2f*>(&ptr[19]);
		ffw::Vec2f* t2 = reinterpret_cast<ffw::Vec2f*>(&ptr[22]);

		//std::cout << "reading vertices..." << ptr << std::endl;
		obj.GetPolygon(ptr);

		if(genNormals){
			dir0 = *p0 - *p2;
			dir1 = *p0 - *p1;
			c = ffw::Cross(dir0, dir1);
			c.Normalize();
			*n0 = c;
			*n1 = c;
			*n2 = c;
		}

		if(genTexpos){
			*t0 = 0.0f;
			*t1 = 0.0f;
			*t2 = 0.0f;
		}

		ptr = &ptr[24];
	}

    return true;
}
