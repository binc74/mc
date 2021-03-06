#include "chunk.h"

namespace mc {
	Chunk::Chunk() {

	}

	Chunk::Chunk(int px, int py, int pz) {
		this->px = px;
		this->py = py;
		this->pz = pz;
	}

	Chunk::~Chunk() {
		for (Cube* obj: objs) {
			delete obj;
		}
	}

	void Chunk::addObj(mc::Cube* obj) {
		if (objs.find(obj) == objs.end()) {
			objs.insert(obj);
			pos[hashXYZ(obj->pos)] = obj;
		}
		else {
			std::cerr << "Error adding obj: obj already exists" << std::endl;
		}
	}

	void Chunk::removeObj(mc::Cube* obj) {
		auto it = objs.find(obj);
		if (it != objs.end()) {
			objs.erase(obj);
			pos.erase(hashXYZ(obj->pos));
		}
		else {
			std::cerr << "Error deleting obj: obj already exists" << std::endl;
		}
	}

	mc::Cube* Chunk::getObjAt(int x, int y, int z) {
		int hash = hashXYZ(x, y, z);
		auto it = pos.find(hash);
		if (it == pos.end()) {
			return NULL;
		}

		return it->second;
	}

	void Chunk::update(float dt) {

	}

	void Chunk::draw(mc::ChunkRenderer* cr) {
		//cr->clear();

		for (Cube* c: objs) {
			c->pushToMesh(cr);
		}
		
		//cr->draw();
	}

	void Chunk::printAllPositons() {	
		int i = 0;
		for (Cube* c : objs) {
			glm::vec3& pos = c->pos;
			std::clog << i++ << " (" << hashXYZ(pos) << "): " << pos.x << " " << pos.y << " " << pos.z << std::endl;
		}
		std::clog << std::endl;
	}
}