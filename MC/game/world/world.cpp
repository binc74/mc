#include "world.h"

namespace game {
	World::World() {
	}

	World::World(Shader* shader, Material* material) {
		cr = new ChunkRenderer(shader, material);
	}

	World::~World() {
		delete cr;
		for (auto& it: chunks) {
			delete it.second;
		}
	}

	void World::addObj(Cube* obj) {
		glm::vec3 pos = obj->pos;
		long hp = hashXYZ(pos);

		auto it = chunks.find(hp);

		if (it == chunks.end()) {
			std::clog << "Create new chunk! current size: " << chunks.size() <<std::endl;
			Chunk* c = new Chunk((int)pos.x << 4, (int)pos.y << 4, (int)pos.z << 4);
			c->addObj(obj);
			chunks[hp] = c;
		}
		else {
			it->second->addObj(obj);
		}
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
		for (const auto& it: chunks) {
			it.second->update(dt);
		}
	}

	void World::updateMesh() {
		for (auto& it : chunks) {
			//std::clog << "Drawing chunk " << it.first << std::endl;
			it.second->draw(cr);
		}

		cr->setBuffers();
	}

	void World::draw() {
		//cr->clear();
		cr->bind();		
		cr->draw();
		cr->unbind();
	}

	void World::printAllChunks() {
		int i = 0;
		for (auto& it: chunks) {
			Chunk* c = it.second;
			std::clog << "Chunk " << i++ << ": " << c->px << " " << c->py << " " << c->pz << std::endl;
			c->printAllPositons();
		}
	}
}