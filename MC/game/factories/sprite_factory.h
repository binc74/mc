#ifndef SPRITE_FACTORY_H
#define SPRITE_FACTORY_H

#include <vector>
#include <map>
#include <SOIL2.h>

#include "../../engine/graphics/texture2d.h"

using namespace engine;

namespace game {
	enum SpriteType {
		GRASS_TOP = 0,
		COBBLESTONE,
		SOIL,
		GRASS_SIDE,
		PLANK,
		STONE_BRICK_SIDE,
		STONE_BRICK_TOP
	};

	class SpriteFactory {
	private:
		class Pair {
		public:
			int row, col;
			Pair() {
			}

			Pair(int row, int col) {
				this->row = row;
				this->col = col;
			}
		};

		unsigned char* sprite_sheet;
		std::vector<Texture2D*> cache;
		std::map<int, Pair> sprite_map;
		int num_row, num_col;
		int sprite_width, sprite_height;

		unsigned char* getSprite(int pos_row, int pos_col, int unit_width, int unit_height);
		void initSpriteMapping();
	public:

		SpriteFactory();
		~SpriteFactory();
		Texture2D* getTexture(game::SpriteType type);
	};
}

#endif
