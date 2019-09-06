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
	class FontRenderer {
	private:
		FT_Library ft;
		FT_Face face;
		std::map<GLchar, mc::Character> map;
		GLuint VAO, VBO;
		glm::mat4 projection;
		mc::Shader* shader;
		mc::Player* player;
		int window_width, window_height;

		std::unordered_map<int, Text> texts;

		void init();

	public:
		FontRenderer(mc::Shader* shader, glm::mat4 projectoion);
		~FontRenderer();

		void addText(int tid, std::string text, GLfloat x, GLfloat y, GLfloat scale, glm::vec3 color);		
		void render();

	protected:
		void renderText(mc::Text t);
	};
}

#endif