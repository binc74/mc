#ifndef CHUNK_RENDERER_H
#define CHUNK_RENDERER_H

#include <vector>
#include <glew.h>
#include <unordered_map>
#include <iostream>

#include "../shader.h"
#include "../material.h"
#include "../core/vertex.h"
#include "../texture2d.h"
#include "../../factories/sprite_factory.h"
#include "../../sprite_type.h"

namespace mc {
	class ChunkRenderer {
	private:
		unsigned int VAO, VBO;
		//unsigned int EBO;
		//std::vector<unsigned int> indices;
		std::vector<Vertex> vertices;
		std::unordered_map<SpriteType, std::vector<Vertex>> textures;
		std::vector<std::pair<SpriteType, int>> temp;
		SpriteFactory sf;
		Shader* shader;
		Material* material;
		int size;

		void initMesh();		

	public:		
		ChunkRenderer();
		ChunkRenderer(Shader* shader, Material* material);
		~ChunkRenderer();

		void addVertex(SpriteType type, Vertex v);
		void setBuffers();
		void bind();
		void unbind();
		void clear();
		void draw();
	};
}

#endif