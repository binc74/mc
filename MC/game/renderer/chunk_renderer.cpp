#include "chunk_renderer.h"

namespace game {
	ChunkRenderer::ChunkRenderer() : sf(), size(0) {

	}

	ChunkRenderer::~ChunkRenderer() {

	}

	void ChunkRenderer::initMesh() {
		glGenVertexArrays(1, &VAO);
		glGenBuffers(1, &VBO);		

		glBindVertexArray(VAO);
		glBindBuffer(GL_ARRAY_BUFFER, VBO);		

		//glGenBuffers(1, &EBO);
		//glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);	

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

	void ChunkRenderer::bind() {
		glBindVertexArray(VAO);
	}

	void ChunkRenderer::unbind() {
		glBindVertexArray(0);
	}

	void ChunkRenderer::setBuffers() {
		glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(Vertex), &vertices[0], GL_STATIC_DRAW);
		//glBufferData(GL_ELEMENT_ARRAY_BUFFER, indices.size() * sizeof(unsigned int),
		//	&indices[0], GL_STATIC_DRAW);
	}

	void ChunkRenderer::addVertex(SpriteType type, Vertex v) {
		if (textures.find(type) == textures.end()) {
			textures[type] = std::vector<Vertex>();
		}

		textures[type].push_back(v);
		size++;
	}

	void ChunkRenderer::clear() {
		size = 0;
		textures.clear();
		vertices.clear();
		//indices.clear();
	}

	void ChunkRenderer::draw() {
		// Try to reduce the number of texture binds
		vertices.resize(size);

		std::vector<std::pair<SpriteType, int>> temp;
		for (auto it: textures) {
			temp.push_back(std::make_pair(it.first, it.second.size()));
			for (Vertex v: it.second) {
				vertices.push_back(v);
			}
		}

		setBuffers();

		int start = 0;
		for (std::pair<SpriteType, int> i: temp) {
			Texture2D* t = sf.getTexture(i.first);

			t->bind(0);
			glDrawArrays(GL_TRIANGLES, start, i.second);
			start += i.second;
			t->unbind();
		}
	}
}