#ifndef MESH2D_H
#define MESH2D_H

#include <iostream>
#include <vector>

#include "texture.h"
#include "shader.h"
#include "material.h"
#include "core/model_matrix.h"

#include "core/vertex.h"


namespace game {
	class Mesh2D {
	protected:
		unsigned int VAO, VBO, EBO;
		bool has_specular;

		void initMesh();

	public:
		std::vector<Vertex> vertices;
		std::vector<unsigned int> indices;
		ModelMatrix* model_matrix;

		Mesh2D();
		~Mesh2D();

		void setHasSpecular(bool has_specular);
	};
}

#endif
