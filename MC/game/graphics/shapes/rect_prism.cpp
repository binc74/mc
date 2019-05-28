#include "rect_prism.h"

namespace game {
	void RectPrism::initIndices() {
		for (int i = 0; i < 24; i += 4) {
			indices.push_back(0 + i);
			indices.push_back(1 + i);
			indices.push_back(2 + i);
			indices.push_back(0 + i);
			indices.push_back(2 + i);
			indices.push_back(3 + i);
		}
	}

	RectPrism::RectPrism() {

	}

	RectPrism::RectPrism(float x, float y, float z, float length) : Mesh2D() {
		glm::vec3 color = glm::vec3(1.f, 1.f, 1.f);
		glm::vec3 normal_top = glm::vec3(0.f, 1.f, 0.f);
		glm::vec3 normal_bot = glm::vec3(0.f, -1.f, 0.f);
		glm::vec3 normal_left = glm::vec3(-1.f, 0.f, 0.f);
		glm::vec3 normal_right = glm::vec3(1.f, 0.f, 0.f);
		glm::vec3 normal_front = glm::vec3(0.f, 0.f, 1.f);
		glm::vec3 normal_back = glm::vec3(0.f, 0.f, -1.f);
		

		float len = 0.5f;
		// Order: top, front right back left bot
		// Add top face (vertices: top-front-left -> top-front-right -> top-back-right -> top-back-left)
		vertices.push_back(Vertex(glm::vec3(-len, len, -len), color, 0, 1, normal_top));		// v0 top-front-left
		vertices.push_back(Vertex(glm::vec3(-len, len, len), color, 0, 0, normal_top));	// v1 top-front-right
		vertices.push_back(Vertex(glm::vec3(len, len, len), color, 1, 0, normal_top));		// v2 top-back-right
		vertices.push_back(Vertex(glm::vec3(len, len, -len), color, 1, 1, normal_top));		// v3 top-back-left

		// Add front face (vertices: top-front-left -> bot-front-left -> bot-front-right -> top-front-right) 
		vertices.push_back(Vertex(glm::vec3(-len, len, len), color, 0, 1, normal_front));		// v4 top-front-left
		vertices.push_back(Vertex(glm::vec3(-len, -len, len), color, 0, 0, normal_front));		// v5 bot-front-left
		vertices.push_back(Vertex(glm::vec3(len, -len, len), color, 1, 0, normal_front));		// v6 bot-front-right
		vertices.push_back(Vertex(glm::vec3(len, len, len), color, 1, 1, normal_front));		// v7 top-front-right

		// Add right face
		vertices.push_back(Vertex(glm::vec3(len, len, len), color, 0, 1, normal_right));		// v8 top-front-right
		vertices.push_back(Vertex(glm::vec3(len, -len, len), color, 0, 0, normal_right));		// v9 bot-front-right
		vertices.push_back(Vertex(glm::vec3(len, -len, -len), color, 1, 0, normal_right));		// v10 bot-back-right
		vertices.push_back(Vertex(glm::vec3(len, len, -len), color, 1, 1, normal_right));		// v11 top-back-right

		// Add back face
		vertices.push_back(Vertex(glm::vec3(len, len, -len), color, 0, 1, normal_back));		// v12 top-back-right
		vertices.push_back(Vertex(glm::vec3(len, -len, -len), color, 0, 0, normal_back));		// v13 bot-back-right
		vertices.push_back(Vertex(glm::vec3(-len, -len, -len), color, 1, 0, normal_back));	// v14 bot-back-left
		vertices.push_back(Vertex(glm::vec3(-len, len, -len), color, 1, 1, normal_back));		// v15 top-back-left

		// Add left face
		vertices.push_back(Vertex(glm::vec3(-len, len, -len), color, 0, 1, normal_left));		// v16 top-back-left
		vertices.push_back(Vertex(glm::vec3(-len, -len, -len), color, 0, 0, normal_left));	// v17 bot-back-left
		vertices.push_back(Vertex(glm::vec3(-len, -len, len), color, 1, 0, normal_left));		// v18 bot-front-left
		vertices.push_back(Vertex(glm::vec3(-len, len, len), color, 1, 1, normal_left));		// v19 top-front-left

		// Add bot face
		vertices.push_back(Vertex(glm::vec3(-len, -len, len), color, 0, 1, normal_bot));		// v20 bot-front-left
		vertices.push_back(Vertex(glm::vec3(-len, -len, -len), color, 0, 0, normal_bot));	// v21 bot-back-left
		vertices.push_back(Vertex(glm::vec3(len, -len, -len), color, 1, 0, normal_bot));		// v22 bot-back-right
		vertices.push_back(Vertex(glm::vec3(len, -len, len), color, 1, 1, normal_bot));		// v23 bot-front-left

		// Init model matrix and mesh
		model_matrix->setPosition(glm::vec3(x, y, z));
		model_matrix->setRotation(glm::vec3(0.f, 0.f, 0.f));
		model_matrix->setScale(1);

		initIndices();
		initMesh();
	}

	RectPrism::~RectPrism() {
		
	}

	void RectPrism::render(Shader* shader, Material* material, std::vector<int>& order) {
		shader->setUniformMat4fv(model_matrix->getMatrix(), "model_matrix");
		glBindVertexArray(VAO);

		for (int i = 0; i < 6; ++i) {
			material->sendToShader(*shader, order[i], 1);
			glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, (void*)(i * 6 *sizeof(unsigned int)));
		}
		
		glBindVertexArray(0);
	}
}