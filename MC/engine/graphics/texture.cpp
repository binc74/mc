#include "texture.h"

namespace engine {
	void Texture::initTextureOpt2D() {
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT); // s -> x, t -> y
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR_MIPMAP_LINEAR); // explaination on opengl.com
	}

	void Texture::bindTexture(unsigned char* sprite) {
		glGenTextures(1, &id);
		glBindTexture(type, id);

		if (sprite) {
			glTexImage2D(type, 0, GL_RGBA, width, height, 0, GL_RGBA,
				GL_UNSIGNED_BYTE, sprite);
			glGenerateMipmap(type);		// different resolution of image
		}
		else {
			std::cerr << "error loading textures" << std::endl;
		}

		glActiveTexture(0);
		glBindTexture(type, 0);
	}

	Texture::Texture() {
	}

	Texture::Texture(const char* uri, GLenum type) {
		this->type = type;

		unsigned char* sprite = SOIL_load_image(uri, &width, &height,
			NULL, SOIL_LOAD_RGBA); // since png uses rgba

		bindTexture(sprite);

		SOIL_free_image_data(sprite);		// remove all data from memory
	}

	Texture::Texture(unsigned char* sprite, int width, int height, GLenum type) {
		this->type = type;
		this->width = width;
		this->height = height;

		bindTexture(sprite);
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