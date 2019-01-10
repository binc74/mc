#include "mesh2d.h"

namespace engine {
	Mesh2D::Mesh2D() : Mesh() {
		model_matrix = new ModelMatrix();
		has_set_texture = false;
		has_set_specular = false;
	}

	Mesh2D::Mesh2D(engine::ModelMatrix* model_matrix) : Mesh(model_matrix) {
		has_set_texture = false;
		has_set_specular = false;
	}

	Mesh2D::~Mesh2D() {
		glDeleteVertexArrays(1, &VAO);
		glDeleteBuffers(1, &VBO);
		glDeleteBuffers(1, &EBO);
	}

	void Mesh2D::initMesh() {
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

	void Mesh2D::setTexture(engine::Texture* texture) {
		this->texture = *texture;
		has_set_texture = true;
	}

	void Mesh2D::setSpecularTexture(engine::Texture* texture) {
		specular_texture = *texture;
		has_set_specular = true;
	}

	void Mesh2D::update(engine::Shader* shader) {
		
	}

	void Mesh2D::render(engine::Shader* shader, engine::Material* material) {
		if (has_set_texture)
			texture.bind(0);
		if (has_set_specular)
			specular_texture.bind(1);

		shader->setUniformMat4fv(model_matrix->getMatrix(), "model_matrix");
		material->sendToShader(*shader, 0, 1);

		glBindVertexArray(VAO);
		glDrawElements(GL_TRIANGLES, indices.size(), GL_UNSIGNED_INT, 0);
		glBindVertexArray(0);
	}
}