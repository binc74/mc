#ifndef RECT_PRISM_H
#define RECT_PRISM_H

#include "../mesh3d.h"
#include "rectangle.h"

namespace game {
	class RectPrism : public Mesh3D {
	public:
		RectPrism();
		RectPrism(float x, float y, float z, float length);
		~RectPrism();

		void render(Shader* shader, Material* material, vector<int>& order);
	};
}
#endif
