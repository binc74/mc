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

	public:
		GLenum type;
		int width, height;

		Texture(const char* uri, GLenum type);
		Texture(const char* uri, GLenum type, int s_width, int s_height);
		~Texture();
		static void initTextureOpt2D();
		unsigned char* getTexture(unsigned char* image, int s_width, int s_height, int posw, int posh);
		GLuint getId();
		void bind(int index);
		void unbind();
	};
}

#endif
