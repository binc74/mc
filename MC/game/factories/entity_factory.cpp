#include "entity_factory.h"

namespace game {
	EntityFactory::EntityFactory() {
	}

	EntityFactory::~EntityFactory() {
	}

	RectPrism* EntityFactory::getCube(float px, float py, float pz) {
		return new RectPrism(px, py, pz, 1);
	}

	RectPrism* EntityFactory::getSoil(float px, float py, float pz) {
		RectPrism* rp = getCube(px, py, pz);

		rp->setTextureAll(sf.getTexture(SOIL));

		return rp;
	}

	RectPrism* EntityFactory::getGrassCube(float px, float py, float pz) {
		RectPrism* rp = getCube(px, py, pz);

		rp->setTextureAll(sf.getTexture(GRASS_SIDE));
		rp->setTextureTop(sf.getTexture(GRASS_TOP));

		return rp;
	}

	RectPrism* EntityFactory::getCobbleStone(float px, float py, float pz) {
		RectPrism* rp = getCube(px, py, pz);

		rp->setTextureAll(sf.getTexture(COBBLESTONE));

		return rp;
	}
}