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
		int px, pz;

		inline int hashXYZ(const glm::vec3& pos) {
			int xi = (int)pos.x - px;
			int zi = (int)pos.y;
			int yi = (int)pos.z - pz;

			return yi * 10000 + xi * 100 + zi;
		}

	public:
		Chunk();
		Chunk(int px, int pz);
		~Chunk();

		void addObj(RectPrism* obj);
		void removeObj(RectPrism* obj);
	};
}

#endif