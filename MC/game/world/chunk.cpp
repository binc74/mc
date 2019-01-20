#include "chunk.h"

namespace game {
	Chunk::Chunk() {

	}

	Chunk::Chunk(int px, int pz) {
		this->px = px;
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
}