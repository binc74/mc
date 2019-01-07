#ifndef SQUARE_H
#define SQUARE_H

#include "../mesh.h"

namespace engine {
	class Square : public Mesh {
	private:
	public:
		Square(float px, float py, float pz, 
			float width, float height, float t_width_num, float t_height_num);
		~Square();
		void setTopLeftColor(float r, float g, float b);
		void setTopRightColor(float r, float g, float b);
		void setBottomLeftColor(float r, float g, float b);
		void setBottomRightColor(float r, float g, float b);
	};
}

#endif
