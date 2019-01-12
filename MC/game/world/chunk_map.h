#ifndef CHUNK_MAP_H
#define CHUNK_MAP_H

#include <unordered_set>

#include "../graphics/shapes/rect_prism.h"

namespace game {
	class ChunkMap {
	private:
		std::unordered_set<RectPrism*> objs;

	public:
		ChunkMap();
		~ChunkMap();
	};
}

#endif
