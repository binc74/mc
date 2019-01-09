#include "triangle.h"

namespace engine {
	Triangle::Triangle(engine::ModelMatrix* model_matrix,
		vector<engine::Vertex> vertices) : Mesh2D(model_matrix) {
		this->vertices = vertices;
		this->indices = vector<unsigned int> { 0, 1, 2 };

		initMesh();
	}
}