#include "main_controller.h"

namespace mc {
	MainController::MainController() {
		initParams();
	}

	MainController::~MainController() {
		for (Controller* it : controllers) {
			delete it;
		}
	}

	void MainController::initParams() {
		dt = 0.f;
		last_time = 0.f;
	}

	void MainController::updateTime() {
		float curr_time = (float)glfwGetTime();
		dt = curr_time - last_time;
		last_time = curr_time;
	}

	void MainController::addController(Controller* cont) {
		controllers.push_back(cont);
	}

	void MainController::updateInput() {
		glfwPollEvents();
		updateTime();

		for (Controller* it : controllers) {
			it->updateInput(dt);
		}
	}
}