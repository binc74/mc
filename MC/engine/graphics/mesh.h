#ifndef MESH_H
#define MESH_H

#include <iostream>
#include <vector>

#include "core/vertex.h"
#include "texture.h"
#include "shader.h"
#include "material.h"
#include "core/model_matrix.h"

using namespace std;

namespace engine {
	class Mesh {
	protected:
		unsigned int VAO, VBO, EBO;
		bool has_specular;
		void initMesh();

	public:
		vector<engine::Vertex> vertices;
		vector<unsigned int> indices;
		vector<Texture*> textures;
		engine::ModelMatrix* model_matrix;

		Mesh();
		Mesh(engine::ModelMatrix* model_matrix);
		~Mesh();	
		void setHasSpecular(bool has_specular);
		void update(engine::Shader* shader);
		void render(engine::Shader* shader, engine::Material* material);
	};
}

#endif
