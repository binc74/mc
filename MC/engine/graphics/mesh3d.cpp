#include "mesh3d.h"

namespace engine {
	void Mesh3D::initMesh() {

	}

	Mesh3D::Mesh3D() : Mesh() {
	}

	Mesh3D::Mesh3D(float px, float py, float pz) : Mesh() {
		position = glm::vec3(px, py, pz);
	}

	Mesh3D::Mesh3D(engine::ModelMatrix* model_matrix) : Mesh(model_matrix) {

	}

	Mesh3D::~Mesh3D() {
		for (auto it : meshes) {
			delete it;
		}
	}

	void Mesh3D::update(engine::Shader* shader) {
		for (auto it: meshes) {
			it->update(shader);
		}
	}

	void Mesh3D::render(engine::Shader* shader, engine::Material* material) {
		for (auto it : meshes) {
			it->render(shader, material);
		}
	}
}