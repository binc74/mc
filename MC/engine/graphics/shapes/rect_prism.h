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

		void addTextureAll(Texture* texture);
		void addTextureTop(Texture* texture);
		void addTextureBottom(Texture* texture);
		void addTextureAllSides(Texture* texture);
		void addTextureSide1(Texture* texture);
		void addTextureSide2(Texture* texture);
		void addTextureSide3(Texture* texture);
		void addTextureSide4(Texture* texture);
	};
}
#endif
