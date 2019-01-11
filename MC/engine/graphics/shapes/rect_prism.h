#ifndef RECT_PRISM_H
#define RECT_PRISM_H

#include "../mesh3d.h"
#include "rectangle.h"

namespace engine {
	class RectPrism : public Mesh3D {
	public:
		RectPrism();
		RectPrism(float x, float y, float z, float length);
		~RectPrism();

		void render(engine::Shader* shader, engine::Material* material, vector<int>& order);
	};
}
#endif
