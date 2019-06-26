#ifndef CLOSE_WINDOW_COMMAND_H
#define CLOSE_WINDOW_COMMAND_H

#include <glew.h>
#include <glfw3.h>

#include "input_command.h"

namespace mc {
	class CloseWindowCommand : public InputCommand {
	private:
		GLFWwindow* window;

	public:
		CloseWindowCommand() {

		}

		CloseWindowCommand(GLFWwindow* window) {
			this->window = window;
		}

		void execute(float dt) {
			glfwSetWindowShouldClose(window, GLFW_TRUE);
		}
	};
}

#endif
