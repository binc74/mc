#ifndef SQUARE_H
#define SQUARE_H

#include "../mesh2d.h"

namespace engine {
	class Rectangle : public Mesh2D {
	private:
		void initIndices();

	public:
		Rectangle(glm::vec3 top_left,
			glm::vec3 bot_left, glm::vec3 bot_right, float t_width_num, float t_height_num);
		Rectangle(float px, float py, float pz, float length, glm::vec3 rotation);
		~Rectangle();
		void setTopLeftColor(float r, float g, float b);
		void setTopRightColor(float r, float g, float b);
		void setBottomLeftColor(float r, float g, float b);
		void setBottomRightColor(float r, float g, float b);
	};
}

#endif
