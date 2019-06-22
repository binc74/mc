#ifndef CUBE_H
#define CUBE_H

#include <glm.hpp>

#include "../renderer/chunk_renderer.h"
#include "../sprite_type.h"

namespace game {
	class Cube {
	protected:
		glm::vec3 pos;

		void pushVerticesData(ChunkRenderer* cr, SpriteType top, SpriteType front, SpriteType right,
			SpriteType back, SpriteType left, SpriteType bot);

	public:
		Cube();
		Cube(float px, float py, float pz);
		~Cube();

		glm::vec3 getPos();
		void virtual pushToMesh(ChunkRenderer* cr) = 0;
		void update(float dt);
	};
}

#endif
