#include "square.h"

namespace engine {
	Square::Square(engine::ModelMatrix* model_matrix,
		vector<engine::Vertex> vertices) : Mesh() {
		this->model_matrix = model_matrix;
		this->vertices = vertices;
		this->indices = vector<unsigned int>{
			0, 1, 2,
			0, 2, 3
		};

		initMesh();
	}

	Square::Square(engine::ModelMatrix* model_matrix, vector<engine::Texture> textures,
		vector<engine::Vertex> vertices) : Mesh(model_matrix, textures) {
		this->vertices = vertices;
		this->indices = vector<unsigned int>{ 
			0, 1, 2,
			0, 2, 3
		};

		initMesh();
	}

	Square::~Square() {
		//delete model_matrix;
		Mesh::~Mesh();
	}
}