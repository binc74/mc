#ifndef CLOSE_WINDOW_COMMAND_H
#define CLOSE_WINDOW_COMMAND_H

#include <glfw3.h>

#include "input_command.h"
#include "../../window/window.h"

namespace game {
	class CloseWindowCommand : public InputCommand {
	private:
		game::Window* window;

	public:
		CloseWindowCommand() {

		}

		CloseWindowCommand(game::Window* window) {
			this->window = window;
		}

		void execute(float dt) {
			glfwSetWindowShouldClose(window, GLFW_TRUE);
		}
	};
}

#endif
