#ifndef MESH3D_H
#define MESH3D_H

#include "mesh.h"
#include "mesh2d.h"

namespace engine {
	class Mesh3D : public Mesh {
	protected:
		vector<engine::Mesh2D*> meshes;

		void initMesh() override;
	public:
		Mesh3D();
		Mesh3D(engine::ModelMatrix* model_matrix);
		~Mesh3D();
		void update(engine::Shader* shader) override;
		void render(engine::Shader* shader, engine::Material* material) override;
	};
}

#endif