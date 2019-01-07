#include "texture2d.h"

namespace engine {
	Texture2D::Texture2D(const char* uri) : Texture(uri) {
		type = GL_TEXTURE_2D;
	}

	Texture2D::~Texture2D() {
		Texture::~Texture();
	}
}