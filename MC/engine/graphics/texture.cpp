#include "texture.h"

namespace engine {
	void Texture::initTextureOpt2D() {
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT); // s -> x, t -> y
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR_MIPMAP_LINEAR); // explaination on opengl.com
	}

	Texture::Texture(const char* uri, GLenum type) {
		this->type = type;

		unsigned char* image = SOIL_load_image(uri, &width, &height,
			NULL, SOIL_LOAD_RGBA); // since png uses rgba

		glGenTextures(1, &id);
		glBindTexture(type, id);

		if (image) {
			glTexImage2D(type, 0, GL_RGBA, width, height, 0, GL_RGBA,
				GL_UNSIGNED_BYTE, image);
			glGenerateMipmap(type);		// different resolution of image
		}
		else {
			std::cerr << "error loading textures from " << uri << std::endl;
		}

		glActiveTexture(0);
		glBindTexture(type, 0);
		SOIL_free_image_data(image);		// remove all data from memory
	}

	Texture::~Texture() {
		glDeleteTextures(1, &id);
	}

	GLuint Texture::getId() {
		return id;
	}

	void Texture::bind(int index) {
		glActiveTexture(GL_TEXTURE0 + index);
		glBindTexture(type, id);
	}

	void Texture::unbind() {
		glActiveTexture(0);
		glBindTexture(type, 0);
	}
}