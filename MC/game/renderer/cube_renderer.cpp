#include "cube_renderer.h"

namespace game {
	CubeRenderer::CubeRenderer() {

	}

	CubeRenderer::~CubeRenderer() {
	}

	void CubeRenderer::addTexture(Texture2D* t) {
		textures.push_back(t);
	}

	void CubeRenderer::addOrder(int i1, int i2, int i3, int i4, int i5, int i6) {
		// top, front, right, back, left, bot
		order.push_back(i1);
		order.push_back(i2);
		order.push_back(i3);
		order.push_back(i4);
		order.push_back(i5);
		order.push_back(i6);
	}

	void CubeRenderer::addModel(RectPrism* model) {
		model_set.insert(model);
	}

	void CubeRenderer::render(Shader* shader, Material* material) {
		for (int i = 0; i < textures.size(); ++i) {
			textures[i]->bind(i);
		}

		std::cout << model_set.size() << std::endl;

		for (auto it: model_set) {
			it->render(shader, material, order);
		}
	}
}