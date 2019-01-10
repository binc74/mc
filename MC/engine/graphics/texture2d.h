#ifndef TEXTURE2D_H
#define TEXTURE2D_H

#include "texture.h"

namespace engine {
	class Texture2D : public Texture {
	private:
	public:
		Texture2D(const char* uri);
		Texture2D(unsigned char* sprite, int width, int height);
		~Texture2D();
	};
}

#endif