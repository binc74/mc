#ifndef SOIL_H
#define SOIL_H

#include "../cube.h"

namespace mc {
	class Soil : public Cube {
	public:
		Soil() : Cube() {
		}

		Soil(World* world, float px, float py, float pz) : Cube(world, px, py, pz) {
		}

		void pushToMesh(ChunkRenderer* cr) {
			pushVerticesData(cr, SpriteType::SOIL, SpriteType::SOIL, SpriteType::SOIL,
				SpriteType::SOIL, SpriteType::SOIL, SpriteType::SOIL);
		}
	};
}

#endif