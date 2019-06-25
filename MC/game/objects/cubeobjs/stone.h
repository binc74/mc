#ifndef STONE_H
#define STONE_H

#include "../cube.h"

namespace mc {
	class Stone : public Cube {
	public:
		Stone() : Cube() {
		}

		Stone(World* world, float px, float py, float pz) : Cube(world, px, py, pz) {
		}

		void pushToMesh(ChunkRenderer* cr) {
			pushVerticesData(cr, SpriteType::STONE, SpriteType::STONE, SpriteType::STONE,
				SpriteType::STONE, SpriteType::STONE, SpriteType::STONE);
		}
	};
}

#endif