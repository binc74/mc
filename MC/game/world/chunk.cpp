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

	}

	void Chunk::removeObj(RectPrism* obj) {

	}

	void Chunk::update(float dt) {

	}

	void Chunk::draw() {

	}
}