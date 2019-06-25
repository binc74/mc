#ifndef COBWEB_H
#define COBWEB_H

#include "../cube.h"

namespace mc {
	class CobWeb : public Cube {
	public:
		CobWeb() : Cube() {
		}

		CobWeb(World* world, float px, float py, float pz) : Cube(world, px, py, pz) {
		}

		void pushToMesh(ChunkRenderer* cr) {
			pushVerticesData(cr, SpriteType::COBWEB, SpriteType::COBWEB, SpriteType::COBWEB,
				SpriteType::COBWEB, SpriteType::COBWEB, SpriteType::COBWEB);
		}
	};
}

#endif