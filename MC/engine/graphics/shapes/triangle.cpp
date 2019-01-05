#include "triangle.h"

namespace engine {
	Triangle::Triangle(engine::ModelMatrix* model_matrix, vector<engine::Texture> textures,
		vector<engine::Vertex> vertices) : Mesh(model_matrix, textures) {
		this->vertices = vertices;
		this->indices = vector<unsigned int> { 0, 1, 2 };

		initMesh();
	}
}