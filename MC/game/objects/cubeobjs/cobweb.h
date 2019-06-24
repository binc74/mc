#ifndef COBWEB_H
#define COBWEB_H

#include "../cube.h"

namespace game {
	class CobWeb : public Cube {
	public:
		CobWeb() : Cube() {
		}

		CobWeb(float px, float py, float pz) : Cube(px, py, pz) {
		}

		void pushToMesh(ChunkRenderer* cr) {
			pushVerticesData(cr, SpriteType::COBWEB, SpriteType::COBWEB, SpriteType::COBWEB,
				SpriteType::COBWEB, SpriteType::COBWEB, SpriteType::COBWEB);
		}
	};
}

#endif