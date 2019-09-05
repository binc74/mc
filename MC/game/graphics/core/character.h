#ifndef CHARACTER_H
#define CHARACTER_H

#include <glm.hpp>
#include <glew.h>

namespace mc {
	// From learnopengl.org
	struct Character {
	public:
		GLuint textureID;
		glm::ivec2 size;
		glm::ivec2 bearing;
		GLuint advance;

		Character() {
		}

		Character(GLuint TextureID, glm::ivec2 Size, glm::ivec2 Bearing, GLuint Advance) :
			textureID(TextureID), size(Size), bearing(Bearing), advance(Advance) {
		}
	};
}

#endif