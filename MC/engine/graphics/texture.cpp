#include "texture.h"

namespace engine {
	void Texture::initTextureOpt2D() {
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT); // s -> x, t -> y
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR_MIPMAP_LINEAR); // explaination on opengl.com
	}

	unsigned char* Texture::getTexture(unsigned char* image, int s_width, int s_height, int posw, int posh) {
		unsigned char* cas_image = new unsigned char[s_height * s_width];
		int pos = 0;

		for (int i = posh * s_height; i < (posh + 1) * s_height; ++i) {
			for (int j = posw * s_width; j < (posw + 1) * s_width; ++j) {
				cas_image[pos++] = image[i * width + j];
			}
		}

		return cas_image;
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

	Texture::Texture(const char* uri, GLenum type, int s_width, int s_height) {
		this->type = type;

		unsigned char* image = SOIL_load_image(uri, &width, &height,
			NULL, SOIL_LOAD_RGBA); // since png uses rgba

		//int s_height = 50, s_width = 24;

		glGenTextures(1, &id);
		glBindTexture(type, id);

		unsigned char* cas_image = getTexture(image, width / s_width, height / s_height, 1, 21);

		if (image) {
			glTexImage2D(type, 0, GL_RGBA, width / s_width, height / s_height, 0, GL_RGBA,
				GL_UNSIGNED_BYTE, cas_image);
			glGenerateMipmap(type);		// different resolution of image
		}
		else {
			std::cerr << "error loading textures from " << uri << std::endl;
		}

		delete cas_image;

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