#ifndef VERTEX_H
#define VERTEX_H

#include <glm.hpp>

namespace mc {
	struct Vertex {
		glm::vec3 pos;
		glm::vec3 color;
		glm::vec2 texture_coord;
		glm::vec3 normal;

		Vertex() {
		}

		Vertex(const glm::vec3& pos, 
			const glm::vec3& color,
			float tx, float ty,
			const glm::vec3& normal) {
			this->pos = pos;
			this->color = color;
			texture_coord = glm::vec2(tx, ty);
			this->normal = normal;
		}
	};
}
#endif
