#ifndef TNT_H
#define TNT_H

#include "../cube.h"

namespace game {
	class Tnt : public Cube {
	public:
		Tnt() : Cube() {
		}

		Tnt(float px, float py, float pz) : Cube(px, py, pz) {
		}

		void pushToMesh(ChunkRenderer* cr) {
			pushVerticesData(cr, SpriteType::TNT_TOP, SpriteType::TNT_SIDE, SpriteType::TNT_SIDE,
				SpriteType::TNT_SIDE, SpriteType::TNT_SIDE, SpriteType::TNT_BOT);
		}
	};
}

#endif