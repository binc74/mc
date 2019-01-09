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
		engine::Rectangle* back = new Rectangle(x, y, z - length, length, glm::vec3(180.f, 0.f, 0.f));

		meshes.push_back(top);
		meshes.push_back(front);
		meshes.push_back(right);
		meshes.push_back(back);
		meshes.push_back(left);
		meshes.push_back(bot);
	}

	RectPrism::~RectPrism() {
		
	}

	void RectPrism::addTextureAll(Texture* texture) {
		for (auto it: meshes) {
			it->addTexture(texture);
		}
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