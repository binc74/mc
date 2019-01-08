#include "square.h"

namespace engine {
	Square::Square(float px, float py, float pz,
		float width, float height, float t_width_num, float t_height_num) : Mesh() {
		model_matrix = new ModelMatrix();
		vertices = vector<engine::Vertex>();
		material = Material(glm::vec3(0.1f), glm::vec3(1.f), glm::vec3(1.f));
		indices = vector<unsigned int>{
			0, 1, 2,
			0, 2, 3
		};


		// Init vertices for the square
		float h_width = width / 2, h_height = height / 2;

		vertices.push_back(Vertex(-h_width, h_height, 0, 1, 1, 1, 0, t_height_num, 0, 0, -1));
		vertices.push_back(Vertex(-h_width, -h_height, 0, 1, 1, 1, 0, 0, 0, 0, -1));
		vertices.push_back(Vertex(h_width, -h_height, 0, 1, 1, 1, t_width_num, 0, 0, 0, -1));
		vertices.push_back(Vertex(h_width, h_height, 0, 1, 1, 1, t_width_num, t_height_num, 0, 0, -1));

		// Init model matrix of ths square
		model_matrix->setPosition(px, py, pz);
		model_matrix->setRotation(0);
		model_matrix->setScale(1);

		initMesh();
	}

	Square::~Square() {
		//delete model_matrix;
		Mesh::~Mesh();
	}

	void Square::addTexture(engine::Texture* texture) {
		textures.push_back(texture);
	}

	void Square::setTopLeftColor(float r, float g, float b) {
		vertices[0].color = glm::vec3(r, g, b);
	}

	void Square::setTopRightColor(float r, float g, float b) {
		vertices[3].color = glm::vec3(r, g, b);
	}

	void Square::setBottomLeftColor(float r, float g, float b) {
		vertices[1].color = glm::vec3(r, g, b);
	}

	void Square::setBottomRightColor(float r, float g, float b) {
		vertices[2].color = glm::vec3(r, g, b);
	}
}