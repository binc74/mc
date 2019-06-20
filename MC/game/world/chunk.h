#ifndef CHUNK_H
#define CHUNK_H

#include <unordered_map>
#include <unordered_set>

#include "../graphics/shapes/rect_prism.h"
#include "../renderer/chunk_renderer.h"

namespace game {
	class Chunk {
	private:
		ChunkRenderer cr;
		std::unordered_set<RectPrism*> objs;
		std::unordered_map<int, RectPrism*> pos;
		int px, py, pz;

		inline int hashXYZ(const glm::vec3& pos) {
			int xi = (int)pos.x - px;
			int yi = (int)pos.y - py;
			int zi = (int)pos.z - pz;

			return yi * 10000 + xi * 100 + zi;
		}

	public:
		Chunk();
		Chunk(int px, int py, int pz);
		~Chunk();

		void addObj(RectPrism* obj);
		void removeObj(RectPrism* obj);
		void update(float dt);
		void draw();
	};
}

#endif