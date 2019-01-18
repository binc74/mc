#ifndef MESH2D_H
#define MESH2D_H

#include "core/vertex.h"
#include "mesh.h"

namespace game {
	class Mesh2D : public Mesh {
	protected:
		unsigned int VAO, VBO, EBO;

		void initMesh() override;

	public:
		vector<Vertex> vertices;
		vector<unsigned int> indices;

		Mesh2D();
		~Mesh2D();
	};
}

#endif
