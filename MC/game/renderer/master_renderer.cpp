#include "master_renderer.h"

namespace game {
	MasterRenderer::MasterRenderer(Shader* shader, Material* material) {
		this->shader = shader;
		this->material = material;
	}

	MasterRenderer::~MasterRenderer() {
		delete shader;
		delete material;

		for (auto it: map) {
			delete it.second;
		}
	}

	void MasterRenderer::addModel(EntityType type, RectPrism* model) {
		if (map.find(type) == map.end()) {
			map[type] = ef.getByType(type);
		}

		map[type]->addModel(model);
	}

	void MasterRenderer::render() {
		//shader->use();

		for (auto it: map) {
			it.second->render(shader, material);
		}

		//shader->unuse();
	}
}