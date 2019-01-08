#include "mesh.h"

namespace engine {
	Mesh::Mesh() {
	}

	Mesh::Mesh(engine::ModelMatrix* model_matrix) {
		this->textures = textures;
		this->model_matrix = model_matrix;
	}

	Mesh::~Mesh() {
		delete model_matrix;

		for (auto it : textures)
			delete it;

		glDeleteVertexArrays(1, &VAO);
		glDeleteBuffers(1, &VBO);
		glDeleteBuffers(1, &EBO);
	}

	void Mesh::initMesh() {
		glGenVertexArrays(1, &VAO);
		glGenBuffers(1, &VBO);
		glGenBuffers(1, &EBO);

		glBindVertexArray(VAO);
		glBindBuffer(GL_ARRAY_BUFFER, VBO);
		glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(Vertex), &vertices[0], GL_STATIC_DRAW);

		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
		glBufferData(GL_ELEMENT_ARRAY_BUFFER, indices.size() * sizeof(unsigned int),
			&indices[0], GL_STATIC_DRAW);

		// Position
		glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (GLvoid*)offsetof(Vertex, pos));
		glEnableVertexAttribArray(0);

		// Color
		glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (GLvoid*)offsetof(Vertex, color));
		glEnableVertexAttribArray(1);

		// Texture
		glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, sizeof(Vertex), (GLvoid*)offsetof(Vertex, texture_coord));
		glEnableVertexAttribArray(2);

		// Normal
		glVertexAttribPointer(3, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (GLvoid*)offsetof(Vertex, normal));
		glEnableVertexAttribArray(3);

		glBindVertexArray(0);
	}

	void Mesh::update(engine::Shader* shader) {
		shader->setUniformMat4fv(model_matrix->getMatrix(), "model_matrix");
	}

	void Mesh::render(engine::Shader* shader) {
		for (int i = 0; i < textures.size(); ++i) {
			textures[i]->bind(i);
		}
		
		material.sendToShader(*shader, 0, 1);

		glBindVertexArray(VAO);
		glDrawElements(GL_TRIANGLES, indices.size(), GL_UNSIGNED_INT, 0);
		glBindVertexArray(0);
	}
}