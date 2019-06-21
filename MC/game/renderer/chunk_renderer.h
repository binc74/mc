#ifndef CHUNK_RENDERER_H
#define CHUNK_RENDERER_H

#include <vector>
#include <glew.h>
#include <unordered_map>

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
		int size;

		void initMesh();
		void setBuffers();
	public:
		ChunkRenderer();
		~ChunkRenderer();

		void addVertex(SpriteType type, Vertex v);
		void bind();
		void unbind();
		void clear();
		void draw();
	};
}

#endif