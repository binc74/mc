#ifndef OAKWOOD_H
#define OAKWOOD_H

#include "../cube.h"

namespace game {
	class OakWood : public Cube {
	public:
		OakWood() : Cube() {
		}

		OakWood(World* world, float px, float py, float pz) : Cube(world, px, py, pz) {
		}

		void pushToMesh(ChunkRenderer* cr) {
			pushVerticesData(cr, SpriteType::OAK_WOOD_TOP, SpriteType::OAK_WOOD_SIDE, SpriteType::OAK_WOOD_SIDE,
				SpriteType::OAK_WOOD_SIDE, SpriteType::OAK_WOOD_SIDE, SpriteType::OAK_WOOD_TOP);
		}
	};
}

#endif