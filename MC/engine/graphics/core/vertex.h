#ifndef VERTEX_H
#define VERTEX_H

#include <glm.hpp>

namespace engine {
	struct Vertex {
		glm::vec3 pos;
		glm::vec3 color;
		glm::vec2 texture_coord;
		glm::vec3 normal;

		Vertex(float px, float py, float pz, 
			float cx, float cy, float cz,
			float tx, float ty,
			float nx, float ny, float nz) {
			pos = glm::vec3(px, py, pz);
			color = glm::vec3(cx, cy, cz);
			texture_coord = glm::vec2(tx, ty);
			normal = glm::vec3(nx, ny, nz);
		}
	};
}
#endif
