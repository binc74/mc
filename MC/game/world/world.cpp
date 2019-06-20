#include "world.h"

namespace game {
	World::World() {

	}

	World::~World() {

	}

	void World::addObj(RectPrism* obj) {
		glm::vec3 pos = obj->getPos();
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
	}

	void World::removeObj(RectPrism* obj) {
		glm::vec3 pos = obj->getPos();
		long long hp = hashXYZ(pos);

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
		for (auto it : chunks) {
			it.second->draw();
		}
	}
}