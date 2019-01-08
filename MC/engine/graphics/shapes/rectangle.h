#ifndef SQUARE_H
#define SQUARE_H

#include "../mesh.h"

namespace engine {
	class Rectangle : public Mesh {
	private:
	public:
		Rectangle(glm::vec3 top_left,
			glm::vec3 bot_left, glm::vec3 bot_right, float t_width_num, float t_height_num);
		~Rectangle();
		void addTexture(engine::Texture* texture);
		void setTopLeftColor(float r, float g, float b);
		void setTopRightColor(float r, float g, float b);
		void setBottomLeftColor(float r, float g, float b);
		void setBottomRightColor(float r, float g, float b);
	};
}

#endif
