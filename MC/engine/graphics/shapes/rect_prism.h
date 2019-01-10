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

		void setTextureAll(Texture* texture);
		void setTextureTop(Texture* texture);
		void setTextureBottom(Texture* texture);
		void setTextureAllSides(Texture* texture);
		void setTextureSide1(Texture* texture);
		void setTextureSide2(Texture* texture);
		void setTextureSide3(Texture* texture);
		void setTextureSide4(Texture* texture);
	};
}
#endif
