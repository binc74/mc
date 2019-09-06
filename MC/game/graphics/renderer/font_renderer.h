#ifndef FONT_RENDERER_H
#define FONT_RENDERER_H

#include <ft2build.h>
#include FT_FREETYPE_H 
#include <iostream>
#include <map>
#include <glew.h>
#include <glm.hpp>
#include <unordered_map>

#include "../core/character.h"
#include "../shader.h"
#include "../../player/player.h"
#include "../core/text.h"

namespace mc {
	// From learnopengl.org
	// Using singleton design pattern
	class FontRenderer {
	private:
		FT_Library ft;
		FT_Face face;
		std::map<GLchar, mc::Character> map;
		GLuint VAO, VBO;
		glm::mat4 projection;
		mc::Shader* shader;
		int window_width, window_height;

		std::unordered_map<int, Text> texts;

		static FontRenderer* _instance;

		FontRenderer();
		~FontRenderer();

		FontRenderer(FontRenderer const&){};
		FontRenderer& operator=(FontRenderer const&) {};
		
		void renderText(mc::Text t);

	public:
		static FontRenderer* instance();

		void setShader(mc::Shader* shader);
		void setWindowParam(int window_width, int window_height);
		void init();

		void addText(int tid, std::string text, GLfloat x, GLfloat y, GLfloat scale, glm::vec3 color);		
		void changeText(int tid, std::string newText);
		void render();
	};
}

#endif