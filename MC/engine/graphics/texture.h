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

		Texture(const char* uri);
		~Texture();
		static void initTextureOpt2D();
		GLuint getId();
		void bind(int index);
		void unbind();
	};
}

#endif
