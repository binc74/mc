#ifndef GRAVEL_H
#define GRAVEL_H

#include "../cube.h"

namespace mc {
	class Gravel : public Cube {
	public:
		Gravel() : Cube() {
		}

		Gravel(World* world, float px, float py, float pz) : Cube(world, px, py, pz) {
		}

		void pushToMesh(ChunkRenderer* cr) {
			pushVerticesData(cr, SpriteType::GRAVEL, SpriteType::GRAVEL, SpriteType::GRAVEL,
				SpriteType::GRAVEL, SpriteType::GRAVEL, SpriteType::GRAVEL);
		}
	};
}

#endif