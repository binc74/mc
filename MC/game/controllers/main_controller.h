#ifndef MAIN_CONTROLLER_H
#define MAIN_CONTROLLER_H

#include <vector>

#include <glfw3.h>
#include "controller.h"
#include "mouse_controller.h"

namespace game {
	class MainController {
	private:
		GLFWwindow* window;
		std::vector<Controller*> controllers;

		void initControllers();

	public:
		MainController();
		MainController(GLFWwindow* window);

		~MainController();

		void updateInput();
	};
}

#endif