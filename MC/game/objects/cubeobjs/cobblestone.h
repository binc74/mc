#ifndef COBBLESTONE_H
#define COBBLESTONE_H

#include "../cube.h"

namespace game {
	class CobbleStone : public Cube {
	public:
		CobbleStone() : Cube() {
		}

		CobbleStone(World* world, float px, float py, float pz) : Cube(world, px, py, pz) {
		}

		void pushToMesh(ChunkRenderer* cr) {
			pushVerticesData(cr, SpriteType::COBBLESTONE, SpriteType::COBBLESTONE, SpriteType::COBBLESTONE,
				SpriteType::COBBLESTONE, SpriteType::COBBLESTONE, SpriteType::COBBLESTONE);
		}
	};
}

#endif