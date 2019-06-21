#ifndef GRASS_H
#define GRASS_H

#include "../cube.h"

namespace game {
	class Grass : public Cube {
	public:
		Grass() : Cube() {
		}

		Grass(float px, float py, float pz) : Cube(px, py, pz) {
		}

		virtual void pushToMesh(ChunkRenderer* cr) {

		}
	};
}

#endif