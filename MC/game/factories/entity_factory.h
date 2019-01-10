#ifndef ENTITY_FACTORY_H
#define ENTITY_FACTORY_H

#include "sprite_factory.h"
#include "../../engine/graphics/shapes/rect_prism.h"
#include "../../engine/graphics/texture2d.h"

using namespace engine;

namespace game {
	class EntityFactory {
	private:
		SpriteFactory sf;

		RectPrism* getCube(float px, float py, float pz);
	public:
		EntityFactory();
		~EntityFactory();

		RectPrism* getSoil(float px, float py, float pz);
		RectPrism* getGrassCube(float px, float py, float pz);
		RectPrism* getCobbleStone(float px, float py, float pz);
	};
}

#endif
