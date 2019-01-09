#ifndef MESH2D_H
#define MESH2D_H

#include "core/vertex.h"
#include "mesh.h"

namespace engine {
	class Mesh2D : public Mesh {
	protected:
		unsigned int VAO, VBO, EBO;
		void initMesh() override;

	public:
		vector<engine::Vertex> vertices;
		vector<unsigned int> indices;
		vector<Texture*> textures;

		Mesh2D();
		Mesh2D(engine::ModelMatrix* model_matrix);
		~Mesh2D();	

		void addTexture(engine::Texture* texture);
		void update(engine::Shader* shader) override;
		void render(engine::Shader* shader, engine::Material* material) override;
	};
}

#endif