#ifndef TRIANGLE_H
#define TRIANGLE_H

#include "../mesh.h"

namespace engine {
	class Triangle : public Mesh {
	private:
	public:
		Triangle(engine::ModelMatrix* model_matrix, vector<engine::Texture> textures,
			vector<engine::Vertex> vertices);
	};
}

#endif
