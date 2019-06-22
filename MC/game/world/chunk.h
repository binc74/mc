#ifndef CHUNK_H
#define CHUNK_H

#include <unordered_map>
#include <unordered_set>
#include <iostream>

#include "../objects/cube.h"
#include "../renderer/chunk_renderer.h"

namespace game {
	class Chunk {
	private:
		ChunkRenderer cr;
		std::unordered_set<Cube*> objs;
		std::unordered_map<int, Cube*> pos;
		int px, py, pz;

		inline int hashXYZ(const glm::vec3& pos) {
			int xi = (int)pos.x - px;
			int yi = (int)pos.y - py;
			int zi = (int)pos.z - pz;
			int hash = yi * 10000 + xi * 100 + zi;
			//std::clog << "Pos: " << pos.x << " " << pos.y << " " << pos.z << " : " << hash
			//	<< " " << yi << " " << xi << " " << zi << std::endl;

			return hash;
		}

	public:
		Chunk();
		Chunk(int px, int py, int pz);
		~Chunk();

		void addObj(Cube* obj);
		void removeObj(Cube* obj);
		void update(float dt);
		void draw(ChunkRenderer* cr);
	};
}

#endif