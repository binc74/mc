#include "rectangle.h"

namespace game {
	void Rectangle::initIndices() {		
		indices = vector<unsigned int>{
			0, 1, 2,
			0, 2, 3
		};
	}

	Rectangle::Rectangle(glm::vec3 top_left,
		glm::vec3 bot_left, glm::vec3 bot_right, float t_width_num, float t_height_num) : Mesh2D() {
		initIndices();

		// Init vertices for the square
		glm::vec3 top_right = top_left + bot_right - bot_left;
		glm::vec3 center = (bot_right - top_left) * 0.5f;
		glm::vec3 color = glm::vec3(1.f, 1.f, 1.f);
		glm::vec3 normal = glm::vec3(0.f, 0.f, 1.f);

		vertices.push_back(Vertex(top_left - center, color, 0, t_height_num, normal));
		vertices.push_back(Vertex(bot_left - center, color, 0, 0, normal));
		vertices.push_back(Vertex(bot_right - center, color, t_width_num, 0, normal));
		vertices.push_back(Vertex(top_right - center, color, t_width_num, t_height_num, normal));

		// Init model matrix of ths square
		model_matrix->setPosition(bot_left);
		model_matrix->setRotation(0);
		model_matrix->setScale(1);

		initMesh();
	}

	Rectangle::Rectangle(float px, float py, float pz, float length, glm::vec3 rotation) : Mesh2D() {
		initIndices();
		glm::vec3 color = glm::vec3(1.f, 1.f, 1.f);
		glm::vec3 normal = glm::vec3(0.f, 0.f, 1.f);

		float h_length = length / 2;
		vertices.push_back(Vertex(glm::vec3(-h_length, h_length, 0), color, 0, 1, normal));
		vertices.push_back(Vertex(glm::vec3(-h_length, -h_length, 0), color, 0, 0, normal));
		vertices.push_back(Vertex(glm::vec3(h_length, -h_length, 0), color, 1, 0, normal));
		vertices.push_back(Vertex(glm::vec3(h_length, h_length, 0), color, 1, 1, normal));

		model_matrix->setPosition(glm::vec3(px, py, pz));
		model_matrix->setRotation(rotation);
		model_matrix->setScale(1);

		initMesh();
	}

	Rectangle::~Rectangle() {
		//delete model_matrix;
		Mesh::~Mesh();
	}

	void Rectangle::setTopLeftColor(float r, float g, float b) {
		vertices[0].color = glm::vec3(r, g, b);
	}

	void Rectangle::setTopRightColor(float r, float g, float b) {
		vertices[3].color = glm::vec3(r, g, b);
	}

	void Rectangle::setBottomLeftColor(float r, float g, float b) {
		vertices[1].color = glm::vec3(r, g, b);
	}

	void Rectangle::setBottomRightColor(float r, float g, float b) {
		vertices[2].color = glm::vec3(r, g, b);
	}

	void Rectangle::render(Shader* shader, Material* material, int shader_id) {
		shader->setUniformMat4fv(model_matrix->getMatrix(), "model_matrix");
		material->sendToShader(*shader, shader_id, 1);

		glBindVertexArray(VAO);
		glDrawElements(GL_TRIANGLES, indices.size(), GL_UNSIGNED_INT, 0);
		glBindVertexArray(0);
	}
}
