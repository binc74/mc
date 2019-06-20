#include "chunk.h"

namespace game {
	Chunk::Chunk() {

	}

	Chunk::Chunk(int px, int py, int pz) {
		this->px = px;
		this->py = py;
		this->pz = pz;
	}

	Chunk::~Chunk() {
		for (RectPrism* obj: objs) {
			delete obj;
		}
	}

	void Chunk::addObj(RectPrism* obj) {
		if (objs.find(obj) == objs.end()) {
			objs.insert(obj);
			pos[hashXYZ(obj->getPos())] = obj;
		}
		else {
			std::cerr << "Error adding obj: obj already exists" << std::endl;
		}
	}

	void Chunk::removeObj(RectPrism* obj) {
		auto it = objs.find(obj);
		if (it != objs.end()) {
			objs.erase(obj);
			pos.erase(hashXYZ(obj->getPos()));
		}
		else {
			std::cerr << "Error deleting obj: obj already exists" << std::endl;
		}
	}

	void Chunk::update(float dt) {

	}

	void Chunk::draw() {

	}
}