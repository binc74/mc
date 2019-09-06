#ifndef TEXT_H
#define TEXT_H

#include <string>
#include <glew.h>
#include <glm.hpp>

namespace mc {
	struct Text {
		std::string text;
		GLfloat x, y, scale;
		glm::vec3 color;

		Text() {
		}

		Text(std::string text, GLfloat x, GLfloat y, GLfloat scale, glm::vec3 color) :
			text(text), x(x), y(y), scale(scale), color(color) {
		}
	};
}

#endif