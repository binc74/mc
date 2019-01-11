#ifndef MASTER_RENDERER
#define MASTER_RENDERER

#include <unordered_map>

#include "cube_renderer.h"
#include "../factories/entity_factory.h"
#include "../entity_type.h"
#include "../../engine/graphics/shapes/rect_prism.h"
#include "../../engine/graphics/shader.h"

using namespace engine;

namespace game {
	class MasterRenderer {
	private:
		Shader* shader;
		Material* material;
		std::unordered_map<EntityType, CubeRenderer*> map;
		EntityFactory ef;

	public:
		MasterRenderer(Shader* shader, Material* material);
		~MasterRenderer();

		void addModel(EntityType type, RectPrism* model);
		void render();
	};
}

#endif
