#include "controller.h"

namespace game {
	Controller::Controller() {
		// Nothing
	}

	Controller::Controller(GLFWwindow* window) {
		this->window = window;
	}

	Controller::~Controller() {
		// Nothing
	}
}