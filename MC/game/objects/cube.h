#ifndef CUBE_H
#define CUBE_H

#include <glm.hpp>
#include "../renderer/chunk_renderer.h"

namespace game {
	class Cube {
	private:
		glm::vec3 pos;

	public:
		Cube();
		Cube(float px, float py, float pz);
		~Cube();

		glm::vec3& getPos();
		void virtual pushToMesh(ChunkRenderer* cr) = 0;
		void update(float dt);
	};
}

#endif
