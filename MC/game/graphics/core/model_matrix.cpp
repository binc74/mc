#include "model_matrix.h"

namespace mc {
	static glm::vec3 direction_x = glm::vec3(1, 0, 0);
	static glm::vec3 direction_y = glm::vec3(0, 1, 0);
	static glm::vec3 direction_z = glm::vec3(0, 0, 1);

	ModelMatrix::ModelMatrix() {
	}

	ModelMatrix::ModelMatrix(float x, float y, float z) {
		position = glm::vec3(x, y, z);
	}

	ModelMatrix::~ModelMatrix() {
	}

	void ModelMatrix::setPosition(float x, float y, float z) {
		position = glm::vec3(x, y, z);
	}

	void ModelMatrix::setPosition(glm::vec3 position) {
		this->position = position;
	}

	void ModelMatrix::setRotation(float x, float y, float z) {
		rotation = glm::vec3(x, y, z);
	}

	void ModelMatrix::setRotation(float x) {
		rotation = glm::vec3(x, x, x);
	}

	void ModelMatrix::setRotation(glm::vec3 rotation) {
		this->rotation = rotation;
	}

	void ModelMatrix::setScale(float x, float y, float z) {
		scale = glm::vec3(x, y, z);
	}

	void ModelMatrix::setScale(float x) {
		scale = glm::vec3(x, x, x);
	}

	void ModelMatrix::changePosition(float dx, float dy, float dz) {
		position.x += dx;
		position.y += dy;
		position.z += dz;
	}

	void ModelMatrix::changeRotation(float dx, float dy, float dz) {
		rotation.x += dx;
		rotation.y += dy;
		rotation.z += dz;
	}

	void ModelMatrix::changeScale(float dx, float dy, float dz) {
		scale.x += dx;
		scale.y += dy;
		scale.z += dz;
	}

	glm::mat4 ModelMatrix::getMatrix() {
		glm::mat4 model_matrix(1);

		model_matrix = glm::translate(model_matrix, position);
		model_matrix = glm::rotate(model_matrix, glm::radians(rotation.x), direction_x);
		model_matrix = glm::rotate(model_matrix, glm::radians(rotation.y), direction_y);
		model_matrix = glm::rotate(model_matrix, glm::radians(rotation.z), direction_z);
		model_matrix = glm::scale(model_matrix, scale);

		return model_matrix;
	}
}