#include "chunk_map.h"

namespace game {
	ChunkMap::ChunkMap() {

	}

	ChunkMap::~ChunkMap() {

	}

	void ChunkMap::addObj(RectPrism* obj) {
		glm::vec3 pos = obj->getPos();
		int hp = hashXY(pos);

		auto it = chunks.find(hp);

		if (it == chunks.end()) {
			Chunk c = Chunk();
			c.addObj(obj);
			chunks[hp] = c;
		}
		else {
			it->second.addObj(obj);
		}
	}

	void ChunkMap::removeObj(RectPrism* obj) {

	}
}