#ifndef MESH3D_H
#define MESH3D_H

#include "mesh.h"
#include "shapes/rectangle.h"

namespace engine {
	class Mesh3D : public Mesh {
	protected:
		vector<engine::Rectangle*> meshes;
		glm::vec3 position;

		void initMesh() override;
	public:
		Mesh3D();
		Mesh3D(float px, float py, float pz);
		Mesh3D(engine::ModelMatrix* model_matrix);
		~Mesh3D();
		void update(engine::Shader* shader) override;
	};
}

#endif