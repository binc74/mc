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
		void initMesh();

	public:
		vector<engine::Vertex> vertices;
		vector<unsigned int> indices;
		vector<Texture> textures;
		engine::ModelMatrix* model_matrix;

		Mesh(engine::ModelMatrix* model_matrix, vector<engine::Texture> textures);
		~Mesh();	
		void update(engine::Shader* shader);
		void draw(engine::Shader* shader);
	};
}

#endif
