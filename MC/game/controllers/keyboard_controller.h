#ifndef KEYBOARD_CONTROLLER_H
#define KEYBOARD_CONTROLLER_H

#include "controller.h"
#include "../camera/camera.h"

namespace game {
	class KeyboardController : public Controller {
	private:
		Camera* camera;

	public:
		KeyboardController();
		KeyboardController(GLFWwindow* window, Camera* camera);

		void updateInput(float dt);
	};
}

#endif