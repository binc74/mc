#ifndef CONTROLLER_H
#define CONTROLLER_H
#include <glew.h>
#include <glfw3.h>

namespace game {
	class Controller {
	protected:
		GLFWwindow* window;

	public:
		Controller();
		Controller(GLFWwindow* window);

		~Controller();

		virtual void updateInput() = 0;
	};
}

#endif