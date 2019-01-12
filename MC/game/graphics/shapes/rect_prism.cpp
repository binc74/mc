#include "rect_prism.h"

namespace game {
	RectPrism::RectPrism() {

	}

	RectPrism::RectPrism(float x, float y, float z, float length) : Mesh3D(x, y, z) {
		float h_length = length / 2;

		Rectangle* front = new Rectangle(x, y, z, length, glm::vec3(0.f, 0.f, 0.f));
		Rectangle* bot = new Rectangle(x, y - h_length, z - h_length, length, glm::vec3(90.f, 0.f, 0.f));
		Rectangle* top = new Rectangle(x, y + h_length, z - h_length, length, glm::vec3(-90.f, 0.f, 0.f));
		Rectangle* left = new Rectangle(x - h_length, y, z - h_length, length, glm::vec3(0.f, -90.f, 0.f));
		Rectangle* right = new Rectangle(x + h_length, y, z - h_length, length, glm::vec3(0.f, 90.f, 0.f));
		Rectangle* back = new Rectangle(x, y, z - length, length, glm::vec3(0.f, 180.f, 0.f));

		meshes.push_back(top);
		meshes.push_back(front);
		meshes.push_back(right);
		meshes.push_back(back);
		meshes.push_back(left);
		meshes.push_back(bot);
	}

	RectPrism::~RectPrism() {
		
	}

	void RectPrism::render(Shader* shader, Material* material, vector<int>& order) {
		for (int i = 0; i < 6; ++i) {
			meshes[i]->render(shader, material, order[i]);
		}
	}
}