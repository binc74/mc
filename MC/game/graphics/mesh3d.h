#ifndef MESH3D_H
#define MESH3D_H

#include "mesh.h"
#include "shapes/rectangle.h"

namespace game {
	class Mesh3D : public Mesh {
	protected:
		vector<Rectangle*> meshes;
		glm::vec3 position;

		void initMesh() override;
	public:
		Mesh3D();
		Mesh3D(float px, float py, float pz);
		Mesh3D(ModelMatrix* model_matrix);
		~Mesh3D();
		void update(Shader* shader) override;
	};
}

#endif