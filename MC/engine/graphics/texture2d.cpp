#include "texture2d.h"

namespace engine {
	Texture2D::Texture2D(const char* uri) : Texture(uri, GL_TEXTURE_2D) {
	}

	Texture2D::Texture2D(unsigned char* sprite, int width, int height) :
		Texture(sprite, width, height, GL_TEXTURE_2D) {
	}

	Texture2D::~Texture2D() {
		Texture::~Texture();
	}
}