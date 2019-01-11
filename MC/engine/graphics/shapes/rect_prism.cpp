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

	void RectPrism::render(engine::Shader* shader, engine::Material* material) {
		for (auto it : meshes) {
			//it->render(shader, material);
		}
	}

	void RectPrism::render(engine::Shader* shader, engine::Material* material, vector<int>& order) {
		for (int i = 0; i < 6; ++i) {
			meshes[i]->render(shader, material, order[i]);
		}
	}
}