#include "mouse_controller.h"

namespace mc {
	MouseController::MouseController(GLFWwindow* window, mc::Player* player) : Controller(window) {
		this->player = player;

		this->initParams();
	}

	void MouseController::initParams() {
		last_mouse_x = 0.0;
		last_mouse_y = 0.0;
		mouse_x = 0.0;
		mouse_y = 0.0;
		mouse_offset_x = 0.0;
		mouse_offset_y = 0.0;
		is_first_mouse = true;
	}

	void MouseController::updateInput(float dt) {
		glfwGetCursorPos(this->window, &mouse_x, &mouse_y);

		if (is_first_mouse) {
			last_mouse_x = mouse_x;
			last_mouse_y = mouse_y;
			is_first_mouse = false;
		}

		mouse_offset_x = mouse_x - last_mouse_x;
		mouse_offset_y = mouse_y - last_mouse_y;
		last_mouse_x = mouse_x;
		last_mouse_y = mouse_y;

		this->player->camera.updateByMouseInput(dt, mouse_offset_x, mouse_offset_y);
	}
}