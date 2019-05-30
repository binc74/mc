#include "renderer_factory.h"

namespace game {
	RendererFactory::RendererFactory() {
	}

	RendererFactory::~RendererFactory() {
	}

	CubeRenderer* RendererFactory::getByType(EntityType type) {
		switch (type) {
		case EntityType::SOIL:
			return getSoilRenderer();
		case EntityType::GRASS:
			return getGrassCubeRenderer();
		case EntityType::COBBLESTONE:
			return getCobbleStoneRenderer();
		}

		return NULL;
	}

	CubeRenderer* RendererFactory::getSoilRenderer() {
		CubeRenderer* cr = new CubeRenderer();

		cr->addTexture(sf.getTexture(SpriteType::SOIL));
		cr->addOrder(0, 0, 0, 0, 0, 0);

		return cr;
	}

	CubeRenderer* RendererFactory::getGrassCubeRenderer() {
		CubeRenderer* cr = new CubeRenderer();

		cr->addTexture(sf.getTexture(SpriteType::GRASS_SIDE));
		cr->addTexture(sf.getTexture(SpriteType::GRASS_TOP));
		cr->addTexture(sf.getTexture(SpriteType::SOIL));
		cr->addOrder(1, 0, 0, 0, 0, 2);

		return cr;
	}

	CubeRenderer* RendererFactory::getCobbleStoneRenderer() {
		CubeRenderer* cr = new CubeRenderer();

		cr->addTexture(sf.getTexture(SpriteType::COBBLESTONE));
		cr->addOrder(0, 0, 0, 0, 0, 0);

		return cr;
	}
}