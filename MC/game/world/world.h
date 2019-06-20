#ifndef WORLD_H
#define WORLD_H

#include <unordered_set>

#include "../graphics/shapes/rect_prism.h"
#include "chunk.h"

namespace game {
	class World {
	private:
		std::unordered_map<long, Chunk*> chunks;

		inline long hashXYZ(const glm::vec3& pos) {
			long ans = 0;

			ans += (long)pos.x >> 4;
			ans += (long)pos.y << 4;
			ans += (long)pos.z << 12;

			std::clog << "Pos: " << pos.x << " " << pos.y << " " << pos.z << " : " << ans << std::endl;

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
