#ifndef STONE_H
#define STONE_H

#include "../cube.h"

namespace game {
	class Stone : public Cube {
	public:
		Stone() : Cube() {
		}

		Stone(float px, float py, float pz) : Cube(px, py, pz) {
		}

		void pushToMesh(ChunkRenderer* cr) {
			pushVerticesData(cr, SpriteType::STONE, SpriteType::STONE, SpriteType::STONE,
				SpriteType::STONE, SpriteType::STONE, SpriteType::STONE);
		}
	};
}

#endif