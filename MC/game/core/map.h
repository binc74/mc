#ifndef MAP_H
#define MAP_H

#include <unordered_set>

#include "../../engine/graphics/shapes/rect_prism.h"

using namespace engine;

namespace game {
	class Map {
	private:
		std::unordered_set<RectPrism*> objs;

	public:
		Map();
		~Map();
	};
}

#endif
