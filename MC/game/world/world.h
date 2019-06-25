#ifndef WORLD_H
#define WORLD_H

#include <unordered_set>

#include "../objects/cube.h"
#include "../renderer/chunk_renderer.h"
#include "../graphics/shader.h"
#include "../graphics/material.h"
#include "chunk.h"

namespace mc {
	class Cube;
	class Chunk;

	class World {
	private:
		// Notice:: iterate performance is not that good, may need further changes
		std::unordered_map<long, mc::Chunk*> chunks;
		mc::ChunkRenderer* cr;

		inline long hashXYZ(const glm::vec3& pos) {
			long ans = 0;

			long hx = (long)pos.x >> 4;
			long hy = (long)pos.y >> 4 << 8;
			long hz = (long)pos.z >> 4 << 16;
			ans = hx + hy + hz;
			//std::clog << "Pos: " << pos.x << " " << pos.y << " " << pos.z << " : " << ans 
			//	<< " " << hx << " " << hy << " " << hz << std::endl;

			return ans;
		}

		inline long hashXYZ(int x, int y, int z) {
			long ans = 0;

			long hx = (long)x >> 4;
			long hy = (long)y >> 4 << 8;
			long hz = (long)z >> 4 << 16;
			ans = hx + hy + hz;
			//std::clog << "Pos: " << pos.x << " " << pos.y << " " << pos.z << " : " << ans 
			//	<< " " << hx << " " << hy << " " << hz << std::endl;

			return ans;
		}

	public:
		World();
		World(mc::Shader* shader, mc::Material* material);
		~World();

		void addObj(mc::Cube* obj);
		void removeObj(mc::Cube* obj);
		void update(float dt);
		void draw();
		void updateMesh();		
		void printAllChunks();
		Cube* getObjAt(int x, int y, int z);
	};
}

#endif
