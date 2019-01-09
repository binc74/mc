#include "rect_prism.h"

namespace engine {
	RectPrism::RectPrism() {

	}

	RectPrism::RectPrism(float x, float y, float z, float length) : Mesh3D() {
		Rectangle* top = new Rectangle(x, y, z, length, glm::vec3(0));
	}

	RectPrism::~RectPrism() {
		
	}

	void RectPrism::addTextureTop(Texture* texture) {
		meshes[0]->addTexture(texture);
	}

	void RectPrism::addTextureBottom(Texture* texture) {
		meshes[5]->addTexture(texture);
	}
	
	void RectPrism::addTextureAllSides(Texture* texture) {
		meshes[1]->addTexture(texture);
		meshes[2]->addTexture(texture);
		meshes[3]->addTexture(texture);
		meshes[4]->addTexture(texture);
	}
	
	void RectPrism::addTextureSide1(Texture* texture) {
		meshes[1]->addTexture(texture);
	}
	
	void RectPrism::addTextureSide2(Texture* texture) {
		meshes[2]->addTexture(texture);
	}
	
	void RectPrism::addTextureSide3(Texture* texture) {
		meshes[3]->addTexture(texture);
	}
	
	void RectPrism::addTextureSide4(Texture* texture) {
		meshes[4]->addTexture(texture);
	}
}