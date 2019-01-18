#ifndef SQUARE_H
#define SQUARE_H

#include "../mesh2d.h"

namespace game {
	class Rectangle : public Mesh2D {
	private:
		void initIndices();

	public:
		Rectangle(float px, float py, float pz, float length, glm::vec3 rotation);
		~Rectangle();
		void setTopLeftColor(float r, float g, float b);
		void setTopRightColor(float r, float g, float b);
		void setBottomLeftColor(float r, float g, float b);
		void setBottomRightColor(float r, float g, float b);

		void render(Shader* shader, Material* material, int shader_id);
	};
}

#endif
