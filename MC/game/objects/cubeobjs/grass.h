#ifndef GRASS_H
#define GRASS_H

#include <iostream>

#include "../cube.h"

namespace game {
	class Grass : public Cube {
	public:
		Grass() : Cube() {
		}

		Grass(float px, float py, float pz) : Cube(px, py, pz) {
		}

		virtual void pushToMesh(ChunkRenderer* cr) {
			pushVerticesData(cr, SpriteType::GRASS_TOP, SpriteType::GRASS_SIDE, SpriteType::GRASS_SIDE, 
				SpriteType::GRASS_SIDE, SpriteType::GRASS_SIDE, SpriteType::SOIL);
		}
	};
}

#endif