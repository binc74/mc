#ifndef TRIANGLE_H
#define TRIANGLE_H

#include "../mesh2d.h"

namespace game {
	class Triangle : public Mesh2D {
	private:
	public:
		Triangle(ModelMatrix* model_matrix, 
			vector<Vertex> vertices);
	};
}

#endif
