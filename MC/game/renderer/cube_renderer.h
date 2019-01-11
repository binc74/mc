#ifndef CUBE_RENDERER_H
#define CUBE_RENDERER_H

#include <unordered_set>
#include <vector>
#include "../../engine/graphics/texture2d.h"
#include "../../engine/graphics/shapes/rect_prism.h"

using namespace engine;

namespace game {
	class CubeRenderer {
	private:
		std::unordered_set<RectPrism*> model_set;
		std::vector<Texture2D*> textures;
		std::vector<int> order;

	public:
		CubeRenderer();
		~CubeRenderer();

		void addTexture(Texture2D* t);
		void addOrder(int i1, int i2, int i3, int i4, int i5, int i6);
		void addModel(RectPrism* model);
		void render(Shader* shader, Material* material);
	};
}

#endif