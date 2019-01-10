#ifndef TEXTURE_H
#define TEXTURE_H

#include <iostream>
#include <string>
#include <glew.h>
#include <glfw3.h>
#include <SOIL2.h>

namespace engine {
	class Texture {
	private:
		GLuint id;		

		void bindTexture(unsigned char* sprite);

	public:
		GLenum type;
		int width, height;

		Texture();
		Texture(const char* uri, GLenum type);
		Texture(unsigned char* sprite, int width, int height, GLenum type);
		~Texture();
		static void initTextureOpt2D();
		GLuint getId();
		void bind(int index);
		void unbind();
	};
}

#endif
