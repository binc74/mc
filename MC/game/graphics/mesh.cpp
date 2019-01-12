#include "mesh.h"

namespace game {
	Mesh::Mesh() {
		has_specular = true;
	}

	Mesh::Mesh(ModelMatrix* model_matrix) {
		has_specular = true;
		this->model_matrix = model_matrix;
	}

	Mesh::~Mesh() {
		delete model_matrix;
	}

	void Mesh::setHasSpecular(bool has_specular) {
		this->has_specular = has_specular;
	}
}