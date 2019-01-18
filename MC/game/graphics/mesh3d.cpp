#include "mesh3d.h"

namespace game {
	void Mesh3D::initMesh() {

	}

	Mesh3D::Mesh3D() : Mesh() {
	}

	Mesh3D::Mesh3D(float px, float py, float pz) : Mesh() {
		position = glm::vec3(px, py, pz);
	}

	Mesh3D::~Mesh3D() {
		for (auto it : meshes) {
			delete it;
		}
	}
}