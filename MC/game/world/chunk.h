#ifndef CHUNK_H
#define CHUNK_H

#include <unordered_map>
#include <unordered_set>
#include <iostream>

#include "../objects/cube.h"
#include "../graphics/renderer/chunk_renderer.h"

namespace mc {
	class Cube;

	class Chunk {
	private:
		mc::ChunkRenderer cr;
		std::unordered_set<Cube*> objs;
		std::unordered_map<int, Cube*> pos;	

		inline int hashXYZ(const glm::vec3& pos) {
			int xi = (int)pos.x - px;
			int yi = (int)pos.y - py;
			int zi = (int)pos.z - pz;
			int hash = yi * 10000 + xi * 100 + zi;
			//std::clog << "Pos: " << pos.x << " " << pos.y << " " << pos.z << " : " << hash
			//	<< " " << yi << " " << xi << " " << zi << std::endl;

			return hash;
		}

		inline int hashXYZ(int x, int y, int z) {
			int xi = x - px;
			int yi = y - py;
			int zi = z - pz;
			int hash = yi * 10000 + xi * 100 + zi;
			//std::clog << "Pos: " << pos.x << " " << pos.y << " " << pos.z << " : " << hash
			//	<< " " << yi << " " << xi << " " << zi << std::endl;

			return hash;
		}

	public:
		int px, py, pz;

		Chunk();
		Chunk(int px, int py, int pz);
		~Chunk();

		void addObj(mc::Cube* obj);
		void removeObj(mc::Cube* obj);
		mc::Cube* getObjAt(int x, int y, int z);
		void update(float dt);
		void draw(mc::ChunkRenderer* cr);
		void printAllPositons();
	};
}

#endif