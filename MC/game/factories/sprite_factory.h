#ifndef SPRITE_FACTORY_H
#define SPRITE_FACTORY_H

#include <unordered_map>
#include <SOIL2.h>

#include "../sprite_type.h"
#include "../graphics/texture2d.h"

namespace mc {
	class SpriteFactory {
	private:
		unsigned char* sprite_sheet;
		std::unordered_map<int, Texture2D*> cache;
		int num_row, num_col;
		int sprite_width, sprite_height;

		unsigned char* getSprite(int pos_row, int pos_col, int unit_width, int unit_height);
	public:

		SpriteFactory();
		~SpriteFactory();
		Texture2D* getTexture(mc::SpriteType type);
	};
}

#endif
