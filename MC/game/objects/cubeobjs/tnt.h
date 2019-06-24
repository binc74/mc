#ifndef TNT_H
#define TNT_H

#include "../cube.h"

namespace game {
	class Tnt : public Cube {
	public:
		Tnt() : Cube() {
		}

		Tnt(World* world, float px, float py, float pz) : Cube(world, px, py, pz) {
		}

		void pushToMesh(ChunkRenderer* cr) {
			pushVerticesData(cr, SpriteType::TNT_TOP, SpriteType::TNT_SIDE, SpriteType::TNT_SIDE,
				SpriteType::TNT_SIDE, SpriteType::TNT_SIDE, SpriteType::TNT_BOT);
		}
	};
}

#endif