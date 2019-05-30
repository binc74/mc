#ifndef TEXTURE2D_H
#define TEXTURE2D_H

#include <iostream>
#include <string>
#include <glew.h>
#include <glfw3.h>
#include <SOIL2.h>

namespace game {
	class Texture2D {
	private:
		GLuint id;

		void bindTexture(unsigned char* sprite);

	public:
		int width, height;

		Texture2D();
		Texture2D(const char* uri);
		Texture2D(unsigned char* sprite, int width, int height);
		~Texture2D();
		static void initTextureOpt2D();
		GLuint getId();
		void bind(int index);
		void unbind();	
	};
}

#endif