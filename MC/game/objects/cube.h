#ifndef CUBE_H
#define CUBE_H

#include <glm.hpp>

#include "../world/world.h"
#include "../renderer/chunk_renderer.h"
#include "../sprite_type.h"

namespace mc {
	class World;

	class Cube {
	protected:
		World* world;

		void pushVerticesData(ChunkRenderer* cr, SpriteType top, SpriteType front, SpriteType right,
			SpriteType back, SpriteType left, SpriteType bot);

	public:
		glm::vec3 pos;

		Cube();
		Cube(World* world, float px, float py, float pz);
		~Cube();

		void virtual pushToMesh(ChunkRenderer* cr) = 0;
		void update(float dt);
	};
}

#endif
