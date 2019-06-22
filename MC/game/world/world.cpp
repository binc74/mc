#include "world.h"

namespace game {
	World::World() {
		cr = new ChunkRenderer();
	}

	World::World(Shader* shader, Material* material) {
		cr = new ChunkRenderer(shader, material);
	}

	World::~World() {
		delete cr;
		for (auto it: chunks) {
			delete it.second;
		}
	}

	void World::addObj(Cube* obj) {
		glm::vec3 pos = obj->pos;
		long hp = hashXYZ(pos);

		auto it = chunks.find(hp);

		if (it == chunks.end()) {
			Chunk* c = new Chunk((int)pos.x << 4, (int)pos.y << 4, (int)pos.z << 4);
			c->addObj(obj);
			chunks[hp] = c;
		}
		else {
			it->second->addObj(obj);
		}

		std::cout << "Current Chunk Size: " << chunks.size() << std::endl;
	}

	void World::removeObj(Cube* obj) {
		glm::vec3 pos = obj->pos;
		long hp = hashXYZ(pos);

		auto it = chunks.find(hp);

		if (it == chunks.end()) {
			std::cerr << "Error: Cant find the obj in chunk map" << std::endl;
		}
		else {
			chunks.erase(it);
		}
	}

	void World::update(float dt) {
		for (auto it: chunks) {
			it.second->update(dt);
		}
	}

	void World::draw() {
		cr->bind();
		for (auto it : chunks) {
			it.second->draw(cr);
		}
		cr->unbind();
	}
}