#ifndef MESH_H
#define MESH_H

#include <iostream>
#include <vector>

#include "texture.h"
#include "shader.h"
#include "material.h"
#include "core/model_matrix.h"

using namespace std;

namespace engine {
	class Mesh {
	protected:
		bool has_specular;
		virtual void initMesh() = 0;

	public:
		engine::ModelMatrix* model_matrix;

		Mesh();
		Mesh(engine::ModelMatrix* model_matrix);
		~Mesh();
		void setHasSpecular(bool has_specular);
		virtual void update(engine::Shader* shader) = 0;
		virtual void render(engine::Shader* shader, engine::Material* material) = 0;
	};
}

#endif
