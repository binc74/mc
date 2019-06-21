#include "cube.h"

namespace game {
	Cube::Cube() : pos(0, 0, 0) {

	}

	Cube::Cube(float px, float py, float pz) : pos(px, py, pz) {

	}

	Cube::~Cube() {

	}

	glm::vec3& Cube::getPos() {
		return pos;
	}

	void Cube::update(float dt) {

	}
}