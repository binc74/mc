#ifndef ENTITY_FACTORY_H
#define ENTITY_FACTORY_H

#include "../entity_type.h"
#include "../sprite_type.h"
#include "sprite_factory.h"
#include "../renderer/cube_renderer.h"
#include "../../engine/graphics/texture2d.h"

using namespace engine;

namespace game {
	

	class EntityFactory {
	private:
		SpriteFactory sf;

	public:
		EntityFactory();
		~EntityFactory();

		CubeRenderer* getByType(EntityType type);
		CubeRenderer* getSoilRenderer();
		CubeRenderer* getGrassCubeRenderer();
		CubeRenderer* getCobbleStoneRenderer();
	};
}

#endif
