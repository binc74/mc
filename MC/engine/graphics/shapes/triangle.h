#ifndef TRIANGLE_H
#define TRIANGLE_H

#include "../mesh2d.h"

namespace engine {
	class Triangle : public Mesh2D {
	private:
	public:
		Triangle(engine::ModelMatrix* model_matrix, 
			vector<engine::Vertex> vertices);
	};
}

#endif
