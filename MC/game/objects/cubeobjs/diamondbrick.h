#ifndef DIAMOND_BRICK_H
#define DIAMOND_BRICK_H

#include "../cube.h"

namespace mc {
	class DiamondBrick : public Cube {
	public:
		DiamondBrick() : Cube() {
		}

		DiamondBrick(World* world, float px, float py, float pz) : Cube(world, px, py, pz) {
		}

		void pushToMesh(ChunkRenderer* cr) {
			pushVerticesData(cr, SpriteType::DIAMOND_BRICK, SpriteType::DIAMOND_BRICK, SpriteType::DIAMOND_BRICK,
				SpriteType::DIAMOND_BRICK, SpriteType::DIAMOND_BRICK, SpriteType::DIAMOND_BRICK);
		}
	};
}

#endif