#ifndef CHUNK_MAP_H
#define CHUNK_MAP_H

#include <unordered_set>

#include "../graphics/shapes/rect_prism.h"
#include "chunk.h"

namespace game {
	class ChunkMap {
	private:
		std::unordered_map<int, Chunk> chunks;

		inline int hashXY(const glm::vec3& pos) {
			int xi = (int)pos.x / 16;
			int zi = (int)pos.y / 16;

			return xi * 1000 + zi * 7;
		}

	public:
		ChunkMap();
		~ChunkMap();

		void addObj(RectPrism* obj);
		void removeObj(RectPrism* obj);
	};
}

#endif
