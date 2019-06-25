#include "texture2d.h"

namespace mc {
	void Texture2D::initTextureOpt2D() {
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT); // s -> x, t -> y
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR_MIPMAP_LINEAR); // explaination on opengl.com
	}

	void Texture2D::bindTexture(unsigned char* sprite) {
		glGenTextures(1, &id);
		glBindTexture(GL_TEXTURE_2D, id);

		if (sprite) {
			glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA,
				GL_UNSIGNED_BYTE, sprite);
			glGenerateMipmap(GL_TEXTURE_2D);		// different resolution of image
		}
		else {
			std::cerr << "error loading textures" << std::endl;
		}

		glActiveTexture(0);
		glBindTexture(GL_TEXTURE_2D, 0);
	}

	Texture2D::Texture2D() {
	}

	Texture2D::Texture2D(const char* uri) {
		unsigned char* sprite = SOIL_load_image(uri, &width, &height,
			NULL, SOIL_LOAD_RGBA); // since png uses rgba

		bindTexture(sprite);

		SOIL_free_image_data(sprite);		// remove all data from memory
	}

	Texture2D::Texture2D(unsigned char* sprite, int width, int height) {
		this->width = width;
		this->height = height;

		bindTexture(sprite);
	}

	Texture2D::~Texture2D() {
		glDeleteTextures(1, &id);
	}

	GLuint Texture2D::getId() {
		return id;
	}

	void Texture2D::bind(int index) {
		glActiveTexture(GL_TEXTURE0 + index);
		glBindTexture(GL_TEXTURE_2D, id);
	}

	void Texture2D::unbind() {
		glActiveTexture(0);
		glBindTexture(GL_TEXTURE_2D, 0);
	}
}