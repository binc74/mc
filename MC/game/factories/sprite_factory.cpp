#include "sprite_factory.h"

namespace game {
	// warning: not implement unit_width/height yet!!!!!!!!!!!!!
	unsigned char* SpriteFactory::getSprite(int pos_row, int pos_col, int unit_width, int unit_height) {
		// Each pixel is stored in 4 values (r, g, b, a) as the default picture format is bmp
		int width_read = sprite_width * 4;

		unsigned char* sprite = new unsigned char[width_read * sprite_height];
		int pos = 0;

		for (int i = pos_row * sprite_height; i < (pos_row + 1) * sprite_height; ++i) {
			for (int j = pos_col * width_read; j < (pos_col + 1) * width_read; ++j) {
				sprite[pos++] = sprite_sheet[i * sprite_width * num_col * 4 + j];
			}
		}

		return sprite;
	}

	SpriteFactory::SpriteFactory() {
		int width, height;

		// the infomation about the specific spritesheet
		num_row = 50;
		num_col = 24;
		sprite_sheet = SOIL_load_image("resources/textures/mc.png", 
			&width, &height, NULL, SOIL_LOAD_RGBA);

		if (!sprite_sheet)
			std::cerr << "error: missing sprite sheet." << std::endl;

		sprite_width = width / num_col;
		sprite_height = height / num_row;

		// Book 100 places for cache.
		int cache_size = 100;
		cache = std::vector<Texture2D*> (cache_size);
		for (int i = 0; i < cache_size; ++i) {
			cache[i] = NULL;
		}
	}

	SpriteFactory::~SpriteFactory() {
		SOIL_free_image_data(sprite_sheet);

		for (auto it: cache) {
			if (it != NULL)
				delete it;
		}
	}

	Texture2D* SpriteFactory::getTexture(SpriteType type) {
		int index = (int)type;
		unsigned char* sprite = getSprite(index / num_col, index % num_col, 1, 1);
		Texture2D* t = new Texture2D(sprite, sprite_width, sprite_height);
		SOIL_free_image_data(sprite);
		//cache[0] = t;

		return t;
	}
}