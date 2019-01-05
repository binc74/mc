#ifndef TEXTURE_H
#define TEXTURE_H

#include <iostream>
#include <string>
#include <glew.h>
#include <glfw3.h>
#include <SOIL2.h>

#define T2D GL_TEXTURE_2D
#define T3D GL_TEXTURE_3D

namespace engine {
	class Texture {
	private:
		GLuint id;		

	public:
		GLint index;
		GLenum type;
		int width, height;

		Texture(const char* uri, GLint index, GLenum type);
		~Texture();
		static void initTextureOpt2D();
		GLuint getId();
		void bind();
		void unbind();
	};
}

#endif
