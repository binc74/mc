#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <glfw3.h>

namespace game {
	class Controller {
	protected:
		GLFWwindow* window;

	public:
		Controller();
		Controller(GLFWwindow* window);

		~Controller();

		virtual void updateInput(float dt) = 0;
	};
}

#endif