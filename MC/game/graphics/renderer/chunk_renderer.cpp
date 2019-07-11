#include "chunk_renderer.h"

namespace mc {
	ChunkRenderer::ChunkRenderer() : sf(), size(0) {		
	}

	ChunkRenderer::ChunkRenderer(Shader* shader, Material* material) : sf(), 
		size(0), shader(shader), material(material) {
		initMesh();
	}

	ChunkRenderer::~ChunkRenderer() {
		delete shader;
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
		glBindBuffer(GL_ARRAY_BUFFER, 0);

		std::clog << "InitMesh complete!" << std::endl;
	}

	void ChunkRenderer::bind() {
		glBindVertexArray(VAO);
	}

	void ChunkRenderer::unbind() {
		glBindVertexArray(0);
	}

	void ChunkRenderer::setBuffers() {
		vertices.reserve(size);
		int i = 0;

		temp.clear();
		for (auto& it : textures) {
			temp.push_back(std::make_pair(it.first, it.second.size()));
			for (auto& it2 : it.second) {
				vertices.emplace_back(it2);
			}
		}

		glBindBuffer(GL_ARRAY_BUFFER, VBO);
		glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(Vertex), &vertices[0], GL_STATIC_DRAW);
		glBindBuffer(GL_ARRAY_BUFFER, 0);
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
		// Release memory (may not be necessary)
		vertices.shrink_to_fit();
		//indices.clear();
	}

	void ChunkRenderer::draw() {
		// Try to reduce the number of texture binds
		shader->use();
		material->sendToShader(shader, 0, 1);
		//setBuffers();

		int start = 0;
		for (std::pair<SpriteType, int>& i: temp) {
			Texture2D* t = sf.getTexture(i.first);

			t->bind(0);
			glDrawArrays(GL_TRIANGLES, start, i.second);
			start += i.second;
			t->unbind();
		}

		shader->unuse();
	}
}