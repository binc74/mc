#include "main_controller.h"

namespace game {
	MainController::MainController() {
		// Default constructor
	}

	MainController::MainController(GLFWwindow* window) {
		this->window = window;

		initControllers();
	}

	MainController::~MainController() {
		for (Controller* it : controllers) {
			delete it;
		}
	}

	void MainController::initControllers() {
		controllers.push_back(new MouseController(window));
	}

	void MainController::updateInput() {
		for (Controller* it : controllers) {
			it->updateInput();
		}
	}
}