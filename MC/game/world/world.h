#ifndef WORLD_H
#define WORLD_H

#include <unordered_set>

#include "../objects/cube.h"
#include "../renderer/chunk_renderer.h"
#include "../graphics/shader.h"
#include "../graphics/material.h"
#include "chunk.h"

namespace game {
	class World {
	private:
		// Notice:: iterate performance is not that good, may need further changes
		std::unordered_map<long, Chunk*> chunks;
		ChunkRenderer* cr;

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
		World(Shader* shader, Material* material);
		~World();

		void addObj(Cube* obj);
		void removeObj(Cube* obj);
		void update(float dt);
		void draw();
	};
}

#endif
