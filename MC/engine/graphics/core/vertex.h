#ifndef VERTEX_H
#define VERTEX_H

#include <glm.hpp>

namespace engine {
	struct Vertex {
		glm::vec3 pos;
		glm::vec3 color;
		glm::vec2 texture_coord;
		glm::vec3 normal;
	};
}
#endif
