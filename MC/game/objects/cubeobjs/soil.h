#ifndef SOIL_H
#define SOIL_H

#include "../cube.h"

namespace game {
	class Soil : public Cube {
	public:
		Soil() : Cube() {
		}

		Soil(float px, float py, float pz) : Cube(px, py, pz) {
		}

		void pushToMesh(ChunkRenderer* cr) {
			pushVerticesData(cr, SpriteType::SOIL, SpriteType::SOIL, SpriteType::SOIL,
				SpriteType::SOIL, SpriteType::SOIL, SpriteType::SOIL);
		}
	};
}

#endif