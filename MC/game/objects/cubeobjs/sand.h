#ifndef SAND_H
#define SAND_H

#include "../cube.h"

namespace mc {
	class Sand : public Cube {
	public:
		Sand() : Cube() {
		}

		Sand(World* world, float px, float py, float pz) : Cube(world, px, py, pz) {
		}

		void pushToMesh(ChunkRenderer* cr) {
			pushVerticesData(cr, SpriteType::SAND, SpriteType::SAND, SpriteType::SAND,
				SpriteType::SAND, SpriteType::SAND, SpriteType::SAND);
		}
	};
}

#endif