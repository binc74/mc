#include "mesh3d.h"

namespace game {
	void Mesh3D::initMesh() {

	}

	Mesh3D::Mesh3D() : Mesh() {
	}

	Mesh3D::Mesh3D(float px, float py, float pz) : Mesh() {
		position = glm::vec3(px, py, pz);
	}

	Mesh3D::Mesh3D(ModelMatrix* model_matrix) : Mesh(model_matrix) {

	}

	Mesh3D::~Mesh3D() {
		for (auto it : meshes) {
			delete it;
		}
	}

	void Mesh3D::update(Shader* shader) {
		for (auto it: meshes) {
			it->update(shader);
		}
	}
}