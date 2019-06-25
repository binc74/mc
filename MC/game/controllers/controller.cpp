#include "controller.h"

namespace mc {
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