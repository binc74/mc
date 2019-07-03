#ifndef CHARACTER_H
#define CHARACTER_H

#include <glm.hpp>
#include <glew.h>

namespace mc {
	// From learnopengl.org
	class Character {
	public:
		GLuint textureID;
		glm::ivec2 size;
		glm::ivec2 bearing;
		signed long advance;

		Character(GLuint TextureID, glm::ivec2 Size, glm::ivec2 Bearing, signed long Advance) : 
			textureID(TextureID), size(Size), bearing(Bearing), advance(Advance) {

		}
	};
}

#endif