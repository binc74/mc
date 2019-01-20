#ifndef RECT_PRISM_H
#define RECT_PRISM_H

#include "../mesh2d.h"

namespace game {
	class RectPrism : public Mesh2D {
	private:
		void initIndices();

	public:
		RectPrism();
		RectPrism(float x, float y, float z, float length);
		~RectPrism();

		void render(Shader* shader, Material* material, vector<int>& order);

		inline glm::vec3 getPos() {
			return model_matrix->position;
		}
	};
}
#endif
