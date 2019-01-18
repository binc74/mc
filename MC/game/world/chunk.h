#ifndef CHUNK_H
#define CHUNK_H

#include <unordered_map>
#include <unordered_set>

#include "../graphics/shapes/rect_prism.h"

namespace game {
	class Chunk {
	private:
		std::unordered_set<RectPrism*> objs;
		std::unordered_map<int, RectPrism*> pos;
		int posx, posy;

	public:
		Chunk();
		Chunk(int posx, int posy);
		~Chunk();
		void addObj(RectPrism* obj);
		void deleteObj(RectPrism* obj);
	};
}

#endif