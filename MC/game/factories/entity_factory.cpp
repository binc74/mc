#include "entity_factory.h"

namespace game {
	EntityFactory::EntityFactory() {
	}

	EntityFactory::~EntityFactory() {
	}

	CubeRenderer EntityFactory::getByType(EntityType type) {
		switch (type) {
		case EntityType::SOIL:
			return getSoilRenderer();
		case EntityType::GRASS:
			return getGrassCubeRenderer();
		case EntityType::COBBLESTONE:
			return getCobbleStoneRenderer();
		}
	}

	CubeRenderer EntityFactory::getSoilRenderer() {
		CubeRenderer cr = CubeRenderer();

		cr.addTexture(sf.getTexture(SpriteType::SOIL));
		cr.addOrder(0, 0, 0, 0, 0, 0);

		return cr;
	}

	CubeRenderer EntityFactory::getGrassCubeRenderer() {
		CubeRenderer cr = CubeRenderer();

		cr.addTexture(sf.getTexture(SpriteType::GRASS_SIDE));
		cr.addTexture(sf.getTexture(SpriteType::GRASS_TOP));
		cr.addTexture(sf.getTexture(SpriteType::SOIL));
		cr.addOrder(1, 0, 0, 0, 0, 2);

		return cr;
	}

	CubeRenderer EntityFactory::getCobbleStoneRenderer() {
		CubeRenderer cr = CubeRenderer();

		cr.addTexture(sf.getTexture(SpriteType::COBBLESTONE));
		cr.addOrder(0, 0, 0, 0, 0, 0);

		return cr;
	}
}