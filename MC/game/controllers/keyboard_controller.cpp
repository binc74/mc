#include "keyboard_controller.h"

namespace mc {
	KeyboardController::KeyboardController(GLFWwindow* window) : Controller(window) {
	}

	KeyboardController::~KeyboardController() {
		for (auto it : commands) {
			delete it.second;
		}
	}

	void KeyboardController::addInputCommand(int key, InputCommand* command) {
		if (keys.find(key) == keys.end()) {
			keys.insert(key);
			commands[key] = command;
		}
	}

	void KeyboardController::updateInput(float dt) {
		for (int key: keys) {
			if (glfwGetKey(window, key) == GLFW_PRESS) {
				commands[key]->execute(dt);
			}			
		}
	}
}