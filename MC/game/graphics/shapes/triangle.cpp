#include "triangle.h"

namespace game {
	Triangle::Triangle(ModelMatrix* model_matrix,
		vector<Vertex> vertices) : Mesh2D(model_matrix) {
		this->vertices = vertices;
		this->indices = vector<unsigned int> { 0, 1, 2 };

		initMesh();
	}
}