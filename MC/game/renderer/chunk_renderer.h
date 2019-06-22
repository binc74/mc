#ifndef CHUNK_RENDERER_H
#define CHUNK_RENDERER_H

#include <vector>
#include <glew.h>
#include <unordered_map>
#include <iostream>

#include "../graphics/shader.h"
#include "../graphics/material.h"
#include "../graphics/core/vertex.h"
#include "../graphics/texture2d.h"
#include "../factories/sprite_factory.h"
#include "../sprite_type.h"

namespace game {
	class ChunkRenderer {
	private:
		unsigned int VAO, VBO;
		//unsigned int EBO;
		//std::vector<unsigned int> indices;
		std::vector<Vertex> vertices;
		std::unordered_map<SpriteType, std::vector<Vertex>> textures;
		SpriteFactory sf;
		Shader* shader;
		Material* material;
		int size;

		void initMesh();
		void setBuffers();
	public:
		ChunkRenderer();
		ChunkRenderer(Shader* shader, Material* material);
		~ChunkRenderer();

		void addVertex(SpriteType type, Vertex v);
		void bind();
		void unbind();
		void clear();
		void draw();
	};
}

#endif