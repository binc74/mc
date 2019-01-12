#ifndef MESH_H
#define MESH_H

#include <iostream>
#include <vector>

#include "texture.h"
#include "shader.h"
#include "material.h"
#include "core/model_matrix.h"

using namespace std;

namespace game {
	class Mesh {
	protected:
		bool has_specular;
		virtual void initMesh() = 0;

	public:
		ModelMatrix* model_matrix;

		Mesh();
		Mesh(ModelMatrix* model_matrix);
		~Mesh();
		void setHasSpecular(bool has_specular);
		virtual void update(Shader* shader) = 0;
	};
}

#endif
