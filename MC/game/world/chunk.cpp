#include "chunk.h"

namespace game {
	Chunk::Chunk() {

	}

	Chunk::Chunk(int posx, int posy) {

	}

	Chunk::~Chunk() {
		for (RectPrism* obj: objs) {
			delete obj;
		}
	}

	void Chunk::addObj(RectPrism* obj) {

	}

	void Chunk::deleteObj(RectPrism* obj) {

	}
}