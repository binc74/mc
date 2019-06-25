#ifndef GRASS_H
#define GRASS_H

#include "../cube.h"

namespace mc {
	class Grass : public Cube {
	public:
		Grass() : Cube() {
		}

		Grass(World* world, float px, float py, float pz) : Cube(world, px, py, pz) {
		}

		void pushToMesh(ChunkRenderer* cr) {
			pushVerticesData(cr, SpriteType::GRASS_TOP, SpriteType::GRASS_SIDE, SpriteType::GRASS_SIDE, 
				SpriteType::GRASS_SIDE, SpriteType::GRASS_SIDE, SpriteType::SOIL);
		}
	};
}

#endif