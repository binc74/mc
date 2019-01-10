#include "rect_prism.h"

namespace engine {
	RectPrism::RectPrism() {

	}

	RectPrism::RectPrism(float x, float y, float z, float length) : Mesh3D(x, y, z) {
		float h_length = length / 2;

		engine::Rectangle* front = new Rectangle(x, y, z, length, glm::vec3(0.f, 0.f, 0.f));
		engine::Rectangle* bot = new Rectangle(x, y - h_length, z - h_length, length, glm::vec3(90.f, 0.f, 0.f));
		engine::Rectangle* top = new Rectangle(x, y + h_length, z - h_length, length, glm::vec3(-90.f, 0.f, 0.f));
		engine::Rectangle* left = new Rectangle(x - h_length, y, z - h_length, length, glm::vec3(0.f, -90.f, 0.f));
		engine::Rectangle* right = new Rectangle(x + h_length, y, z - h_length, length, glm::vec3(0.f, 90.f, 0.f));
		engine::Rectangle* back = new Rectangle(x, y, z - length, length, glm::vec3(0.f, 180.f, 0.f));

		meshes.push_back(top);
		meshes.push_back(front);
		meshes.push_back(right);
		meshes.push_back(back);
		meshes.push_back(left);
		meshes.push_back(bot);
	}

	RectPrism::~RectPrism() {
		
	}

	void RectPrism::setTextureAll(Texture* texture) {
		for (auto it: meshes) {
			it->setTexture(texture);
		}
	}

	void RectPrism::setTextureTop(Texture* texture) {
		meshes[0]->setTexture(texture);
	}

	void RectPrism::setTextureBottom(Texture* texture) {
		meshes[5]->setTexture(texture);
	}
	
	void RectPrism::setTextureAllSides(Texture* texture) {
		meshes[1]->setTexture(texture);
		meshes[2]->setTexture(texture);
		meshes[3]->setTexture(texture);
		meshes[4]->setTexture(texture);
	}
	
	void RectPrism::setTextureSide1(Texture* texture) {
		meshes[1]->setTexture(texture);
	}
	
	void RectPrism::setTextureSide2(Texture* texture) {
		meshes[2]->setTexture(texture);
	}
	
	void RectPrism::setTextureSide3(Texture* texture) {
		meshes[3]->setTexture(texture);
	}
	
	void RectPrism::setTextureSide4(Texture* texture) {
		meshes[4]->setTexture(texture);
	}
}