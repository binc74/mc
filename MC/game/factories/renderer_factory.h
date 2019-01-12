#ifndef RENDERER_FACTORY_H
#define RENDERER_FACTORY_H

#include "../entity_type.h"
#include "../sprite_type.h"
#include "sprite_factory.h"
#include "../renderer/cube_renderer.h"
#include "../graphics/texture2d.h"

namespace game {
	class RendererFactory {
	private:
		SpriteFactory sf;

	public:
		RendererFactory();
		~RendererFactory();

		CubeRenderer* getByType(EntityType type);
		CubeRenderer* getSoilRenderer();
		CubeRenderer* getGrassCubeRenderer();
		CubeRenderer* getCobbleStoneRenderer();
	};
}

#endif
