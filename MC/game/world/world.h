#ifndef WORLD_H
#define WORLD_H

#include <unordered_set>

#include "../graphics/shapes/rect_prism.h"
#include "chunk.h"

namespace game {
	class World {
	private:
		std::unordered_map<long long, Chunk*> chunks;

		inline long long hashXYZ(const glm::vec3& pos) {
			long long ans = 0;

			ans += (long long)pos.x;
			ans += (long long)pos.y << 8;
			ans += (long long)pos.z << 16;

			return ans;
		}

	public:
		World();
		~World();

		void addObj(RectPrism* obj);
		void removeObj(RectPrism* obj);
		void update(float dt);
		void draw();
	};
}

#endif
