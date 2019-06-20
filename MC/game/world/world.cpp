#include "world.h"

namespace game {
	World::World() {

	}

	World::~World() {

	}

	void World::addObj(RectPrism* obj) {
		glm::vec3 pos = obj->getPos();
		long long hp = hashXYZ(pos);

		auto it = chunks.find(hp);

		if (it == chunks.end()) {
			Chunk* c = new Chunk();
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

	}

	void World::draw() {

	}
}