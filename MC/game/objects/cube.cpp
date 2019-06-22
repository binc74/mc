#include "cube.h"

namespace game {
	Cube::Cube() : pos(0, 0, 0) {

	}

	Cube::Cube(float px, float py, float pz) : pos(px, py, pz) {

	}

	Cube::~Cube() {

	}

	void Cube::pushVerticesData(ChunkRenderer* cr, SpriteType top, SpriteType front, SpriteType right,
		SpriteType back, SpriteType left, SpriteType bot) {
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
		cr->addVertex(top, Vertex(glm::vec3(-len, len, -len) + pos, color, 0, 1, normal_top));		// v0 top-front-left
		cr->addVertex(top, Vertex(glm::vec3(-len, len, len) + pos, color, 0, 0, normal_top));	// v1 top-front-right
		cr->addVertex(top, Vertex(glm::vec3(len, len, len) + pos, color, 1, 0, normal_top));		// v2 top-back-right
		cr->addVertex(top, Vertex(glm::vec3(-len, len, -len) + pos, color, 0, 1, normal_top));		// v0 top-front-left
		cr->addVertex(top, Vertex(glm::vec3(len, len, len) + pos, color, 1, 0, normal_top));		// v2 top-back-right
		cr->addVertex(top, Vertex(glm::vec3(len, len, -len) + pos, color, 1, 1, normal_top));		// v3 top-back-left

		// Add front face (vertices: top-front-left -> bot-front-left -> bot-front-right -> top-front-right) 
		cr->addVertex(front, Vertex(glm::vec3(-len, len, len) + pos, color, 0, 1, normal_front));		// v4 top-front-left
		cr->addVertex(front, Vertex(glm::vec3(-len, -len, len) + pos, color, 0, 0, normal_front));		// v5 bot-front-left
		cr->addVertex(front, Vertex(glm::vec3(len, -len, len) + pos, color, 1, 0, normal_front));		// v6 bot-front-right
		cr->addVertex(front, Vertex(glm::vec3(-len, len, len) + pos, color, 0, 1, normal_front));		// v4 top-front-left
		cr->addVertex(front, Vertex(glm::vec3(len, -len, len) + pos, color, 1, 0, normal_front));		// v6 bot-front-right
		cr->addVertex(front, Vertex(glm::vec3(len, len, len) + pos, color, 1, 1, normal_front));		// v7 top-front-right

		// Add right face
		cr->addVertex(right, Vertex(glm::vec3(len, len, len) + pos, color, 0, 1, normal_right));		// v8 top-front-right
		cr->addVertex(right, Vertex(glm::vec3(len, -len, len) + pos, color, 0, 0, normal_right));		// v9 bot-front-right
		cr->addVertex(right, Vertex(glm::vec3(len, -len, -len) + pos, color, 1, 0, normal_right));		// v10 bot-back-right
		cr->addVertex(right, Vertex(glm::vec3(len, len, len) + pos, color, 0, 1, normal_right));		// v8 top-front-right
		cr->addVertex(right, Vertex(glm::vec3(len, -len, -len) + pos, color, 1, 0, normal_right));		// v10 bot-back-right
		cr->addVertex(right, Vertex(glm::vec3(len, len, -len) + pos, color, 1, 1, normal_right));		// v11 top-back-right

		// Add back face
		cr->addVertex(back, Vertex(glm::vec3(len, len, -len) + pos, color, 0, 1, normal_back));		// v12 top-back-right
		cr->addVertex(back, Vertex(glm::vec3(len, -len, -len) + pos, color, 0, 0, normal_back));		// v13 bot-back-right
		cr->addVertex(back, Vertex(glm::vec3(-len, -len, -len) + pos, color, 1, 0, normal_back));	// v14 bot-back-left
		cr->addVertex(back, Vertex(glm::vec3(len, len, -len) + pos, color, 0, 1, normal_back));		// v12 top-back-right
		cr->addVertex(back, Vertex(glm::vec3(-len, -len, -len) + pos, color, 1, 0, normal_back));	// v14 bot-back-left
		cr->addVertex(back, Vertex(glm::vec3(-len, len, -len) + pos, color, 1, 1, normal_back));		// v15 top-back-left

		// Add left face
		cr->addVertex(left, Vertex(glm::vec3(-len, len, -len) + pos, color, 0, 1, normal_left));		// v16 top-back-left
		cr->addVertex(left, Vertex(glm::vec3(-len, -len, -len) + pos, color, 0, 0, normal_left));	// v17 bot-back-left
		cr->addVertex(left, Vertex(glm::vec3(-len, -len, len) + pos, color, 1, 0, normal_left));		// v18 bot-front-left
		cr->addVertex(left, Vertex(glm::vec3(-len, len, -len) + pos, color, 0, 1, normal_left));		// v16 top-back-left
		cr->addVertex(left, Vertex(glm::vec3(-len, -len, len) + pos, color, 1, 0, normal_left));		// v18 bot-front-left
		cr->addVertex(left, Vertex(glm::vec3(-len, len, len) + pos, color, 1, 1, normal_left));		// v19 top-front-left

		// Add bot face
		cr->addVertex(bot, Vertex(glm::vec3(-len, -len, len) + pos, color, 0, 1, normal_bot));		// v20 bot-front-left
		cr->addVertex(bot, Vertex(glm::vec3(-len, -len, -len) + pos, color, 0, 0, normal_bot));	// v21 bot-back-left
		cr->addVertex(bot, Vertex(glm::vec3(len, -len, -len) + pos, color, 1, 0, normal_bot));		// v22 bot-back-right
		cr->addVertex(bot, Vertex(glm::vec3(-len, -len, len) + pos, color, 0, 1, normal_bot));		// v20 bot-front-left
		cr->addVertex(bot, Vertex(glm::vec3(len, -len, -len) + pos, color, 1, 0, normal_bot));		// v22 bot-back-right
		cr->addVertex(bot, Vertex(glm::vec3(len, -len, len) + pos, color, 1, 1, normal_bot));		// v23 bot-front-left
	}

	void Cube::update(float dt) {

	}
}